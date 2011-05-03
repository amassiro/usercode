#include "ConfigParser.h"
#include "ntpleUtils.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TMinuit.h"
#include "qqHWWlnulnuUtils.h"
#include "Variables.h"

#include "../test/TDRStyle.cc"
#include "../test/Read.cc"
// #include "../test/DrawTools.h"

#include "PUclass.h"





#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif

///
///
///   ___|                                       _)                           \  |   ___|         /      __ \     \  __ __|   \    
///  |       _ \   __ `__ \   __ \    _` |   __|  |   __|   _ \   __ \       |\/ |  |            /       |   |   _ \    |    _ \   
///  |      (   |  |   |   |  |   |  (   |  |     | \__ \  (   |  |   |      |   |  |           /        |   |  ___ \   |   ___ \  
/// \____| \___/  _|  _|  _|  .__/  \__,_| _|    _| ____/ \___/  _|  _|     _|  _| \____|     _/        ____/ _/    _\ _| _/    _\ 
///                          _|                                                                                                    
///
///

// std::vector<double> PUWeight;

int GetNumList(std::vector<int> &list){
 int result = 0;
 for (int it = 0; it<list.size(); it++) result += list.at(it);
 return result;
}


int main(int argc, char** argv)
{ 
 TDRStyle();
 
 gStyle->SetPadTopMargin(0.11);
 gStyle->SetPadLeftMargin(0.07);
 gStyle->SetPadRightMargin(0.23);
 gStyle->cd(); 
 
 
 std::cout << " " << std::endl;
 std::cout << " " << std::endl;
 std::cout << "   ___|                                       _)                           \\  |   ___|         /      __ \\     \\  __ __|   \\     " << std::endl;
 std::cout << "  |       _ \\   __ `__ \\   __ \\    _` |   __|  |   __|   _ \\   __ \\       |\\/ |  |            /       |   |   _ \\    |    _ \\    " << std::endl;
 std::cout << "  |      (   |  |   |   |  |   |  (   |  |     | \\__ \\  (   |  |   |      |   |  |           /        |   |  ___ \\   |   ___ \\   " << std::endl;
 std::cout << " \\____| \\___/  _|  _|  _|  .__/  \\__,_| _|    _| ____/ \\___/  _|  _|     _|  _| \\____|     _/        ____/ _/    _\\ _| _/    _\\  " << std::endl;
 std::cout << "                          _|                                                                                                     " << std::endl;
 std::cout << " " << std::endl;
 

 EColor vColor[1000] = {
  kGreen,
  //kMagenta,(EColor) (kMagenta+1),(EColor) (kMagenta+2),
  kTeal,//(EColor) (kTeal+1),
  kRed,
  kGray,
  kOrange,(EColor) (kOrange+1),
  kBlue,//(EColor)(kBlue+1),(EColor) (kBlue+2),
  (EColor) (kPink+2),//(EColor) (kPink+1),(EColor) (kPink+2),
  kViolet,
  kYellow,
  kGray,(EColor) (kGray+1),(EColor) (kViolet),(EColor) (kYellow),(EColor) (kGray)
 };
 
 
 
 
 //Check if all nedeed arguments to parse are there                                                                                                                               
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }


 // Parse the config file                                                                                                                                                          
 parseConfigFile (argv[1]) ;
 
 std::string treeName  = gConfigParser -> readStringOption("Input::treeName");
 std::string treeNameSelections = gConfigParser -> readStringOption("Input::treeNameSelections");
 std::string fileSamples = gConfigParser -> readStringOption("Input::fileSamples");
 std::string inputDirectory = gConfigParser -> readStringOption("Input::inputDirectory");
 
 double LUMI = gConfigParser -> readDoubleOption("Input::Lumi");
 
 double LumiSyst = gConfigParser -> readDoubleOption("Input::LumiSyst");
 
 double Discovery = gConfigParser -> readDoubleOption("Input::Discovery");
 
 std::vector<std::string> SignalName;
 if (Discovery == 1) SignalName = gConfigParser -> readStringListOption("Input::SignalName");
 
 std::vector<double> PUMC   = gConfigParser -> readDoubleListOption("PU::PUMC");
 std::vector<double> PUDATA = gConfigParser -> readDoubleListOption("PU::PUDATA");
 PUclass PU;
 
 for (int itVPU = 0; itVPU < PUMC.size(); itVPU++ ){
  PU.PUWeight.push_back(PUDATA.at(itVPU) / PUMC.at(itVPU));
 }

 PU.Write("autoWeight.cxx");
 gROOT->ProcessLine(".L autoWeight.cxx");
 
 TTree *treeEffVect[100];
 TTree *treeJetLepVect[100];
 

  //  [iCut][iVar]
 TString* infoString[10][30];
 TLatex *infoLatex[10][30]; 
 TCanvas* ccCanvas[10][30];
 TCanvas* ccCanvasPull[10][30];
 TH1F* histoSumMC[10][30];
 //  [iName][iCut][iVar]
 TH1F* histo[100][10][30];
 TH1F* histo_temp[100][10][30];
 
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsectionName[1000];
 
 double Normalization[1000];
 double xsection[1000];
 char nameFileIn[1000];
 sprintf(nameFileIn,"%s",fileSamples.c_str());

 int numberOfSamples = ReadFile(nameFileIn, nameSample, nameHumanReadable, xsectionName);

 
 ///==== list of variables to plot ====
 std::vector<double> vMin;
 std::vector<double> vMax;
 std::vector<int> vNBin;
 std::vector<std::string> vVarName;
 std::vector<std::string> vVarNameHR;
 std::string VarFile = gConfigParser -> readStringOption("Plot::VarFile");
 
 int numVar = ReadFileVar(VarFile,vMin,vMax,vNBin,vVarName,vVarNameHR);
  
 
 double XSection  = gConfigParser -> readDoubleOption("Plot::XSection");
 
 ///==== list of selections to perform (NOT sequential additive selections) ====
 std::string CutFile = gConfigParser -> readStringOption("Selections::CutFile");
 std::vector<std::string> vCut;
 
 std::cout << " nCuts = " << ReadFileCut(CutFile, vCut) << std::endl;
 
 ///==== output file ====
 std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << OutFileName  << std::endl;  
 
 TFile outFile(OutFileName.c_str(),"RECREATE");
 outFile.cd();
 
 
 ///==== debug flag ====
 
 bool  debug = false; 
 try {
  debug = gConfigParser -> readBoolOption("Input::debug");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }
 std::cout << ">>>>> input::debug  " << debug  << std::endl;  
 
 ///==== program ====
 
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  xsection[iSample] = atof(xsectionName[iSample]);
 }
 
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  
  char nameFile[20000];
  sprintf(nameFile,"%s/out_NtupleProducer_%s.root",inputDirectory.c_str(),nameSample[iSample]);  
  TFile* f = new TFile(nameFile, "READ");
  
  treeEffVect[iSample] = (TTree*) f->Get(treeNameSelections.c_str());
  char nameTreeEff[100];
  sprintf(nameTreeEff,"treeEff_%d",iSample); 
  treeEffVect[iSample]->SetName(nameTreeEff);      
  
  treeJetLepVect[iSample] = (TTree*) f->Get(treeName.c_str());
  char nameTreeJetLep[100];
  sprintf(nameTreeJetLep,"treeJetLep_%d",iSample); 
  treeJetLepVect[iSample]->SetName(nameTreeJetLep);
 }
 
 ///===== create map for joint sample ====
 
 std::vector<int> join_samples;
 std::vector<std::string> name_samples;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  name_samples.push_back(nameHumanReadable[iSample]);
  join_samples.push_back(-1);
 }
 
 
 std::vector<std::string> reduced_name_samples;
 std::vector<int>         reduced_name_samples_flag;
 for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
  bool flag_name = false;
  for (uint iName=0; iName<reduced_name_samples.size(); iName++){
   if (reduced_name_samples.at(iName) == name_samples.at(iSample)) flag_name = true;
  }
  if (flag_name == false) {
   reduced_name_samples.push_back(name_samples.at(iSample));
   reduced_name_samples_flag.push_back(-1);
  }
 }
 
 std::cout << " numberOfSamples = " << numberOfSamples << std::endl;
 
 for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
  double XSection;
  int numEntriesBefore;
  double preselection_efficiency;
  treeEffVect[iSample]->SetBranchAddress("XSection",&XSection);
  treeEffVect[iSample]->SetBranchAddress("numEntriesBefore",&numEntriesBefore);
  treeEffVect[iSample]->SetBranchAddress("preselection_efficiency",&preselection_efficiency);  
  treeEffVect[iSample]->GetEntry(0);
  
  std::cout << " Xsection = " << XSection << " ~~~> " << xsection[iSample] << std::endl;
  XSection = xsection[iSample];
  
  if (numEntriesBefore != 0) {
   Normalization[iSample] = LUMI * XSection * preselection_efficiency / numEntriesBefore;
  }
  else {
   Normalization[iSample] = 0; 
  }    
 }
 
 
 
 TLegend* leg = new TLegend(0.8,0.25,0.98,0.78);
 bool LegendBuilt = false;

 TString lumiName = Form("#splitline{L = %.1f pb^{-1}}{#splitline{#sqrt{s} = 7}{CMS preliminary}}", LUMI);
//  TString lumiName = Form("#sqrt{s}=7 TeV   L=%.1f pb^{-1}", LUMI);
 TLatex *latex = new TLatex(0.80, 0.90, lumiName); 
 latex->SetTextAlign(12);
 latex->SetNDC();
 latex->SetTextFont(42);
 latex->SetTextSize(0.03);
  
 ///==== get number in sample list that correspond to DATA ====
 int numDATA = -1;
 for (uint iName=0; iName<reduced_name_samples.size(); iName++){
  if (reduced_name_samples.at(iName) == "DATA") {
   numDATA = iName;
  }
 }
 
 
 if (debug) std::cout << " Cut size = " << vCut.size() << " ~~ " << std::endl;
 
 ///==== cicle on selections ====
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  TString Cut = Form ("%s",vCut.at(iCut).c_str());
  if (debug) std::cout << " Cut[" << iCut << ":" << vCut.size() << "] = " << Cut.Data() << " ~~ " << std::endl;
  ///==== cicle on variables to plot ====
  for (uint iVar = 0; iVar<vVarName.size(); iVar++){
   if (debug) std::cout << " Var[" << iVar << ":" << vVarName.size() << "] = " << vVarName.at(iVar) << " ~~ " << std::endl;
   ///==== initialize ====
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    reduced_name_samples_flag.at(iName) = -1;
   }
   
   ///==== cicle on samples ====
   for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
    if (debug) std::cout << " Sample[" << iSample << ":" << numberOfSamples << "] = " << nameSample[iSample] << " ~~ " << std::endl;
    TString name_histo_temp = Form("%s_%d_%d_temp",nameSample[iSample], iCut, iVar);
    histo_temp[iSample][iCut][iVar] = new TH1F(name_histo_temp,name_histo_temp,vNBin.at(iVar),vMin.at(iVar), vMax.at(iVar));
    char toDraw[1000];
    sprintf(toDraw,"%s >> %s",vVarName.at(iVar).c_str(),name_histo_temp.Data());      

    
//     TString CutExtended = Form ("Weight(q1_pT)");
    
//     std::cout << " PUclass = " << PU.getPUWeight(1) << std::endl;
    
//     TString CutExtended = Form ("PU.getPUWeight(1)");
//     TString CutExtended = Form ("abs(q1_pT)");

    TString CutExtended = Form ("(%s) * autoWeight(1)",Cut.Data());    
//     TString CutExtended = Form ("autoWeight(1)");    
    
//     TString CutExtended = Form ("q1_pT");
    
//     TString CutExtended = Form ("(%s) * myweight(q1_pT)",Cut.Data());    
//     treeJetLepVect[iSample]->Draw(toDraw,Cut,"");
    treeJetLepVect[iSample]->Draw(toDraw,CutExtended,"");
    
    if (Normalization[iSample]>0) { 
     histo_temp[iSample][iCut][iVar] -> Sumw2();
     histo_temp[iSample][iCut][iVar] -> Scale(Normalization[iSample]); 
    }
    for (uint iName=0; iName<reduced_name_samples.size(); iName++){
     if (name_samples.at(iSample) == reduced_name_samples.at(iName)){
      if (reduced_name_samples_flag.at(iName) == -1){
       TString name_histoTot_temp = Form("%s_%d_%d_Tot_temp",reduced_name_samples.at(iName).c_str(),iCut, iVar);
       TString name_HR_histoTot_temp = Form("%s %d",vVarNameHR.at(iVar).c_str(), iCut);
//        TString name_HR_histoTot_temp = Form("%s %d %s",vVarNameHR.at(iVar).c_str(), iCut, reduced_name_samples.at(iName).c_str());
       histo[iName][iCut][iVar] = new TH1F(name_histoTot_temp,name_HR_histoTot_temp,vNBin.at(iVar),vMin.at(iVar), vMax.at(iVar));
       reduced_name_samples_flag.at(iName) = 1;
      }
      histo[iName][iCut][iVar] -> Add(histo_temp[iSample][iCut][iVar]);
     }
    }
   } ///==== end cicle on samples ====
  } ///==== end cicle on variables to plot ====
 } ///==== end cicle on selections ====
 
 
 
 THStack* hs[100][100];
 TH1F* hPull[100][100];
 
 ///==== cicle on selections ====
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  ///==== cicle on variables to plot ====
  for (uint iVar = 0; iVar<vVarName.size(); iVar++){
   TString nameStack = Form("%d_%d_stack",iCut,iVar);
   hs[iCut][iVar] = new THStack(nameStack,nameStack);
   
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    histo[iName][iCut][iVar]->GetXaxis()->SetTitle(vVarNameHR.at(iVar).c_str());
    histo[iName][iCut][iVar]->SetMarkerColor(vColor[iName]);
    histo[iName][iCut][iVar]->SetLineColor(vColor[iName]);
    histo[iName][iCut][iVar]->SetFillColor(vColor[iName]);
    histo[iName][iCut][iVar]->SetLineWidth(2);
    histo[iName][iCut][iVar]->SetFillStyle(3001);
    
    bool isSig = false;
    for (std::vector<std::string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
     if (reduced_name_samples.at(iName) == *itSig) isSig = true;
    }
    
    if (!isSig && reduced_name_samples.at(iName) != "DATA") {
     hs[iCut][iVar]->Add(histo[iName][iCut][iVar]);
    }
    else {
     if (!isSig) {
      histo[iName][iCut][iVar]->SetMarkerStyle(20);
      histo[iName][iCut][iVar]->SetMarkerSize(1);
      histo[iName][iCut][iVar]->SetMarkerColor(kBlack);
      histo[iName][iCut][iVar]->SetLineColor(kBlack);
      histo[iName][iCut][iVar]->SetFillColor(kBlack);
      histo[iName][iCut][iVar]->SetLineWidth(2);
      histo[iName][iCut][iVar]->SetFillStyle(3001);  
     }
     else {
      histo[iName][iCut][iVar]->SetMarkerStyle(21);
      histo[iName][iCut][iVar]->SetMarkerSize(1);
      histo[iName][iCut][iVar]->SetLineWidth(2);
      histo[iName][iCut][iVar]->SetFillStyle(3001);  
     }
    }
   }
   ///==== histo sum MC ====    
   ///==== Add systrematic error ====
   AddError(hs[iCut][iVar],LumiSyst);
   histoSumMC[iCut][iVar] = ((TH1F*)(hs[iCut][iVar]->GetStack()->Last()));
   ///==== histo with pull plot ====
   hPull[iCut][iVar] = PullPlot(histo[numDATA][iCut][iVar], histoSumMC[iCut][iVar]);
   
   ///==== legend ====
   if (!LegendBuilt){
    for (uint iName=0; iName<reduced_name_samples.size(); iName++){
     leg->AddEntry(histo[iName][iCut][iVar],reduced_name_samples.at(iName).c_str(),"pf");    
     LegendBuilt = true;
    }
   }
  }
 }
 
 
 
 ///==== calculate agreement data-MC: Kolmogorov-Smirnov test ==== 
 ///==== cicle on selections ====
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  ///==== cicle on variables to plot ====
  for (uint iVar = 0; iVar<vVarName.size(); iVar++){
   double KS = -1;
   double Chi2 = -1;
   if (histo[numDATA][iCut][iVar]->GetEntries() != 0 && histoSumMC[iCut][iVar]->GetEntries() != 0) {
    KS = histo[numDATA][iCut][iVar]->KolmogorovTest(histoSumMC[iCut][iVar],"M");
    Chi2 = histo[numDATA][iCut][iVar]->Chi2Test(histoSumMC[iCut][iVar],"UW");
   }
   std::cout << " KS[" << iCut << "][" << iVar << "] = " << KS << std::endl;
   infoString[iCut][iVar] = new TString(Form("#splitline{KS prob = %.4f}{#chi^{2} prob = %.4f}",KS,Chi2));
   infoLatex[iCut][iVar] = new TLatex(0.80, 0.10, *(infoString[iCut][iVar])); 
   infoLatex[iCut][iVar]->SetTextAlign(12);
   infoLatex[iCut][iVar]->SetNDC();
   infoLatex[iCut][iVar]->SetTextFont(42);
   infoLatex[iCut][iVar]->SetTextSize(0.03);
  }
 }
 
 
 LumiSyst = 0; ///---- bug fix
 
 
 
 
 
 
 
 TCanvas* cCompareCutPull[100];
 TCanvas* cCompareVarPull[100];
 
 TCanvas* cCompareCut[100];
 TCanvas* cCompareVar[100];
 
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  TString nameCanvas = Form("%d_Cut_Canvas",iCut);
  cCompareCut[iCut] = new TCanvas(nameCanvas,nameCanvas,400 * vVarName.size(),400);
  cCompareCut[iCut] -> Divide (vVarName.size(),1);
  TString nameCanvasPull = Form("%d_Cut_Canvas_Pull",iCut);
  cCompareCutPull[iCut] = new TCanvas(nameCanvasPull,nameCanvasPull,400 * vVarName.size(),400*2);
  cCompareCutPull[iCut] -> Divide (vVarName.size(),2);
 }
 
 for (uint iVar = 0; iVar<vVarName.size(); iVar++){ ///==== cicle on variables to plot ====
   TString nameCanvas = Form("%d_Var_Canvas",iVar);
   cCompareVar[iVar] = new TCanvas(nameCanvas,nameCanvas,400,400 * vCut.size());
   cCompareVar[iVar] -> Divide (1,vCut.size());
   TString nameCanvasPull = Form("%d_Var_Canvas_Pull",iVar);
   cCompareVarPull[iVar] = new TCanvas(nameCanvasPull,nameCanvasPull,400*2,400 * vCut.size());
   cCompareVarPull[iVar] -> Divide (2,vCut.size());
 }
 
 
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iVar = 0; iVar<vVarName.size(); iVar++){
   TString nameCanvas = Form("%d_%d_Canvas",iCut,iVar);
   ccCanvas[iCut][iVar] = new TCanvas(nameCanvas,nameCanvas,400,400);
   TString nameCanvasPull = Form("%d_%d_CanvasPull",iCut,iVar);
   ccCanvasPull[iCut][iVar] = new TCanvas(nameCanvasPull,nameCanvasPull,400,400);
  }
 } 
 
 ///==== cicle on selections ====
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  ///==== cicle on variables to plot ====
  for (uint iVar = 0; iVar<vVarName.size(); iVar++){
   ///==== draw in canvas ====
   cCompareCut[iCut] -> cd(iVar+1);
   DrawStack(hs[iCut][iVar],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iVar]->Draw();
   
   cCompareVar[iVar] -> cd(iCut+1);
   DrawStack(hs[iCut][iVar],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iVar]->Draw();
   
   
   cCompareCutPull[iCut] -> cd(iVar+1);
   DrawStack(hs[iCut][iVar],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iVar]->Draw();
   
   cCompareVarPull[iVar] -> cd(iCut*2+1);
   DrawStack(hs[iCut][iVar],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iVar]->Draw();
   
   
   
   cCompareCutPull[iCut] -> cd(iVar+1+vVarName.size());
   hPull[iCut][iVar]->Draw("EP");
   gPad->SetGrid();
   gPad->SetLeftMargin(0.17);
   gPad->SetRightMargin(0.07);
   
   cCompareVarPull[iVar] -> cd(iCut*2+2);
   hPull[iCut][iVar]->Draw("EP");
   gPad->SetGrid();
   gPad->SetLeftMargin(0.17);
   gPad->SetRightMargin(0.07);
   
   
   ccCanvas[iCut][iVar]-> cd();
   DrawStack(hs[iCut][iVar],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iVar]->Draw();
   
   ccCanvasPull[iCut][iVar]-> cd();
   hPull[iCut][iVar]->Draw("EP");
   gPad->SetGrid();
   gPad->SetLeftMargin(0.17);
   gPad->SetRightMargin(0.07);
   
   
   
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    
    bool isSig = false;
    for (std::vector<std::string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
     if (reduced_name_samples.at(iName) == *itSig) isSig = true;
    }
    
    if (isSig || reduced_name_samples.at(iName) == "DATA") {
     cCompareCut[iCut] -> cd(iVar+1);
     histo[iName][iCut][iVar]->Draw("EsameB");
     
     cCompareVar[iVar] -> cd(iCut+1);
     histo[iName][iCut][iVar]->Draw("EsameB");
     
     cCompareCutPull[iCut] -> cd(iVar+1);
     histo[iName][iCut][iVar]->Draw("EsameB");

     cCompareVarPull[iVar] -> cd(iCut*2+1);
     histo[iName][iCut][iVar]->Draw("EsameB");
     
     ccCanvas[iCut][iVar]-> cd();
     histo[iName][iCut][iVar]->Draw("EsameB");
    }
   }
   
   cCompareCut[iCut] -> cd(iVar+1);
   leg->Draw();
   cCompareVar[iVar] -> cd(iCut+1);
   leg->Draw();
   cCompareCutPull[iCut] -> cd(iVar+1);
   leg->Draw();
   cCompareVarPull[iVar] -> cd(iCut*2+1);
   leg->Draw();
   ccCanvas[iCut][iVar]-> cd();
   leg->Draw();
   
  } ///==== end cicle on variables to plot ====
 } ///==== end cicle on selections ====
 
 std::cerr << " ******************************************* end *******************************************" << std::endl;
 
 
 
 ///==== save output ====
 outFile.cd();
 outFile.mkdir("Cut");
 outFile.cd("Cut");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  cCompareCut[iCut] -> Write();
  cCompareCutPull[iCut] -> Write();
 }
 
 outFile.cd();
 outFile.mkdir("Var");
 outFile.cd("Var");
 for (uint iVar = 0; iVar<vVarName.size(); iVar++){
  cCompareVar[iVar] -> Write();
  cCompareVarPull[iVar] -> Write();
 }
 
 outFile.cd();
 TDirectory* cdAll = (TDirectory*) outFile.mkdir("All");
 cdAll->mkdir("Var");
 cdAll->mkdir("Pull");
 outFile.cd("All/Var");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iVar = 0; iVar<vVarName.size(); iVar++){
   ccCanvas[iCut][iVar]-> Write();
  }
 }
 
 outFile.cd();
 outFile.cd("All/Pull");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iVar = 0; iVar<vVarName.size(); iVar++){
   ccCanvasPull[iCut][iVar]-> Write();
  }
 }
 
 outFile.cd();
 outFile.mkdir("Data");
 outFile.cd("Data");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iVar = 0; iVar<vVarName.size(); iVar++){
   hs[iCut][iVar] -> Write() ;
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    if (reduced_name_samples.at(iName) == "DATA") {
     histo[iName][iCut][iVar] -> Write();
    }
   }
  }
 }
 
 leg->Write();
 
}





