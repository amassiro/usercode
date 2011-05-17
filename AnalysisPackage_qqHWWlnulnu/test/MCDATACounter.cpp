#include "ConfigParser.h"
#include "ntpleUtils.h"

#include "TPie.h"
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
///      ___|                       |                     \  |   ___|         /      __ \     \  __ __|   \    
///     |       _ \   |   |  __ \   __|   _ \   __|      |\/ |  |            /       |   |   _ \    |    _ \   
///     |      (   |  |   |  |   |  |     __/  |         |   |  |           /        |   |  ___ \   |   ___ \  
///    \____| \___/  \__,_| _|  _| \__| \___| _|        _|  _| \____|     _/        ____/ _/    _\ _| _/    _\ 
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
 std::cout << "      ___|                       |                     \\  |   ___|         /      __ \\     \\  __ __|   \\          " << std::endl;
 std::cout << "     |       _ \\   |   |  __ \\   __|   _ \\   __|      |\\/ |  |            /       |   |   _ \\    |    _ \\       " << std::endl;
 std::cout << "     |      (   |  |   |  |   |  |     __/  |         |   |  |           /        |   |  ___ \\   |   ___ \\          " << std::endl;
 std::cout << "    \\____| \\___/  \\__,_| _|  _| \\__| \\___| _|        _|  _| \\____|     _/        ____/ _/    _\\ _| _/    _\\   " << std::endl; 
 std::cout << " " << std::endl;
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
 
 ///==== PU reweight (begin) ====
 std::vector<double> PUMC   = gConfigParser -> readDoubleListOption("PU::PUMC");
 std::vector<double> PUDATA = gConfigParser -> readDoubleListOption("PU::PUDATA");
 PUclass PU;
 
 std::cout << " PUMC.size()   = " << PUMC.size()   << std::endl;
 std::cout << " PUDATA.size() = " << PUDATA.size() << std::endl;
 
 if (PUMC.size() != PUDATA.size()) {
  std::cerr << " ERROR " << std::endl;
  return 1;
 }
 
 double sumPUMC = 0;
 for (int itVPU = 0; itVPU < PUMC.size(); itVPU++ ){
  sumPUMC += PUMC.at(itVPU);  
 }
 double sumPUDATA = 0;
 for (int itVPU = 0; itVPU < PUDATA.size(); itVPU++ ){
  sumPUDATA += PUDATA.at(itVPU);  
 } 
 
 for (int itVPU = 0; itVPU < PUMC.size(); itVPU++ ){
  PU.PUWeight.push_back(PUDATA.at(itVPU) / PUMC.at(itVPU) * sumPUMC / sumPUDATA);
 }

 PU.Write("autoWeight.cxx");
 gROOT->ProcessLine(".L autoWeight.cxx");
 ///==== PU reweight (end) ====
 
 ///==== save PU distribution in TH1F ====
 TH1F* hPUMC   = new TH1F("hPUMC","hPUMC",PUMC.size(),0,PUMC.size());
 TH1F* hPUDATA = new TH1F("hPUDATA","hPUDATA",PUDATA.size(),0,PUDATA.size());
 TH1F* hPUWeight = new TH1F("hPUWeight","hPUWeight",PUDATA.size(),0,PUDATA.size());
 
 for (int itVPU = 0; itVPU < PUMC.size(); itVPU++ ){
  hPUMC     -> SetBinContent(itVPU+1,PUMC.at(itVPU) / sumPUMC);
  hPUDATA   -> SetBinContent(itVPU+1,PUDATA.at(itVPU) / sumPUDATA);
  hPUWeight -> SetBinContent(itVPU+1,PUDATA.at(itVPU) / PUMC.at(itVPU) * sumPUMC / sumPUDATA);
 }
 
 
 
 TTree *treeEffVect[100];
 TTree *treeJetLepVect[100];
 

 
  //  [iCut] 
 TString* infoString[20];
 TLatex *infoLatex[20]; 
 TCanvas* ccCanvas[20];
 TCanvas* ccCanvasPull[20];
 TH1F* histoSumMC[20];
 //  [iName][iCut]
 TH1F* histo[100][20];
 TH1F* histo_temp[100][20];

 //  [iName][iCut]
 double numEvents[100][20];
 
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsectionName[1000];
 
 double Normalization[1000];
 double xsection[1000];
 char nameFileIn[1000];
 sprintf(nameFileIn,"%s",fileSamples.c_str());

 int numberOfSamples = ReadFile(nameFileIn, nameSample, nameHumanReadable, xsectionName);

 
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
 
 
 double start, end;
 start = clock();
 
 
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
  ///==== initialize ====
  for (uint iName=0; iName<reduced_name_samples.size(); iName++){
   reduced_name_samples_flag.at(iName) = -1;
  }
  
  ///==== cicle on samples ====
  for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
   if (debug) std::cout << " Sample[" << iSample << ":" << numberOfSamples << "] = " << nameSample[iSample] << " ~~ " << std::endl;
   TString name_histo_temp = Form("%s_%d_temp",nameSample[iSample], iCut);
   histo_temp[iSample][iCut] = new TH1F(name_histo_temp,name_histo_temp,100,-10,10000000000);
   char toDraw[1000];
   sprintf(toDraw,"eventId >> %s",name_histo_temp.Data());      
   histo_temp[iSample][iCut] -> Sumw2(); //---- così mette l'errore giusto!
   
   TString CutExtended;
   if (iSample != numDATA) {
    CutExtended = Form ("(%s) * autoWeight(numPUMC)",Cut.Data());    
   }
   else {
    CutExtended = Form ("(%s)",Cut.Data());    
   }
   treeJetLepVect[iSample]->Draw(toDraw,CutExtended,"");
   
   if (Normalization[iSample]>0) { 
    histo_temp[iSample][iCut] -> Scale(Normalization[iSample]); 
   }
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    if (name_samples.at(iSample) == reduced_name_samples.at(iName)){
     if (reduced_name_samples_flag.at(iName) == -1){
      TString name_histoTot_temp = Form("%s_%d_Tot_temp",reduced_name_samples.at(iName).c_str(),iCut);
      TString name_HR_histoTot_temp = Form("cut %d",iCut);
      histo[iName][iCut] = new TH1F(name_histoTot_temp,name_HR_histoTot_temp,100,-10,10000000000);
      histo[iName][iCut] -> Sumw2(); //---- così mette l'errore giusto!
      reduced_name_samples_flag.at(iName) = 1;
     }
     histo[iName][iCut] -> Add(histo_temp[iSample][iCut]);
    }
   }
  } ///==== end cicle on samples ====
  std::cout << "###";
 } ///==== end cicle on selections ====
 
 //  [iName]
 TH1F* hTrend[100];
 THStack* hsTrend;
 //  [iCut]
 TPie* hTrendPie[100];
 
 //  [iCut]
 THStack* hs[100];
 
 std::cout << std::endl;
 
 ///==== cicle on selections ====
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  TString nameStack = Form("%d_stack",iCut);
  hs[iCut] = new THStack(nameStack,nameStack);
  
  for (uint iName=0; iName<reduced_name_samples.size(); iName++){
   histo[iName][iCut]->GetXaxis()->SetTitle("eventId");
   histo[iName][iCut]->SetMarkerColor(vColor[iName]);
   histo[iName][iCut]->SetLineColor(vColor[iName]);
   histo[iName][iCut]->SetFillColor(vColor[iName]);
   histo[iName][iCut]->SetLineWidth(2);
   histo[iName][iCut]->SetFillStyle(3001);
   
   bool isSig = false;
   for (std::vector<std::string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
    if (reduced_name_samples.at(iName) == *itSig) isSig = true;
   }
   
   if (!isSig && reduced_name_samples.at(iName) != "DATA") {
    hs[iCut]->Add(histo[iName][iCut]);
   }
   else {
    if (!isSig) {
     histo[iName][iCut]->SetMarkerStyle(20);
     histo[iName][iCut]->SetMarkerSize(1);
     histo[iName][iCut]->SetMarkerColor(kBlack);
     histo[iName][iCut]->SetLineColor(kBlack);
     histo[iName][iCut]->SetFillColor(kBlack);
     histo[iName][iCut]->SetLineWidth(2);
     histo[iName][iCut]->SetFillStyle(3001);  
    }
    else {
     histo[iName][iCut]->SetMarkerStyle(21);
     histo[iName][iCut]->SetMarkerSize(1);
     histo[iName][iCut]->SetLineWidth(2);
     histo[iName][iCut]->SetFillStyle(3001);  
    }
   }
  }
  ///==== histo sum MC ====    
  ///==== Add systrematic error ====
  AddError(hs[iCut],LumiSyst);
  histoSumMC[iCut] = ((TH1F*)(hs[iCut]->GetStack()->Last()));

  std::cout << " MC / DATA[" << iCut << "] = "<< histoSumMC[iCut]->Integral() << " / " << histo[numDATA][iCut]->Integral() << " = " << (histo[numDATA][iCut]->Integral() ? histoSumMC[iCut]->Integral()/ histo[numDATA][iCut]->Integral() : 0) << std::endl;
  
  ///==== legend ====
  if (!LegendBuilt){
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    leg->AddEntry(histo[iName][iCut],reduced_name_samples.at(iName).c_str(),"pf");    
    LegendBuilt = true;
   }
  }
 }
 std::cout << std::endl << std::endl;
 
 ///==== calculate number of events after each step of the analysis ====
 //  [iName][iCut]
 hsTrend = new THStack("Trend","Trend");
 
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  TString nameTHTrendPie = Form("%d_Trend_Pie",iCut);
  hTrendPie[iCut] = new TPie (nameTHTrendPie,nameTHTrendPie,reduced_name_samples.size());
 }
 
 for (uint iName=0; iName<reduced_name_samples.size(); iName++){
  TString nameTHTrend = Form("%s_Trend",reduced_name_samples.at(iName).c_str());
  hTrend[iName] = new TH1F (nameTHTrend,nameTHTrend,vCut.size()+1,0,vCut.size()+1);
  hTrend[iName]->GetXaxis()->SetTitle("Selections");

  if (iName == numDATA) {
   hTrend[iName]->SetMarkerStyle(20);
   hTrend[iName]->SetMarkerSize(1);
   hTrend[iName]->SetMarkerColor(kBlack);
   hTrend[iName]->SetLineColor(kBlack);
   hTrend[iName]->SetFillColor(kBlack);
   hTrend[iName]->SetLineWidth(2);
   hTrend[iName]->SetFillStyle(3001);  
  }
  else {
   hTrend[iName]->SetMarkerColor(vColor[iName]);
   hTrend[iName]->SetLineColor(vColor[iName]);
   hTrend[iName]->SetFillColor(vColor[iName]);
   hTrend[iName]->SetLineWidth(2);
   hTrend[iName]->SetFillStyle(3001);
  }
  for (uint iCut = 0; iCut<vCut.size(); iCut++){
   double error = 0;
   numEvents[iName][iCut] = histo[iName][iCut]->IntegralAndError(0,histo[iName][iCut]->GetNbinsX()+1,error);
   hTrend[iName]->SetBinContent(iCut+1,numEvents[iName][iCut]);
   hTrend[iName]->SetBinError(iCut+1,error);

   TString nameBin = Form("%d",iCut);
   hTrend[iName]->GetXaxis()->SetBinLabel(iCut+1,nameBin);
//     IntegralAndError
//     Double_t IntegralAndError(Int_t binx1, Int_t binx2, Double_t& err, Option_t* option = "") const
   std::cout << ">>>  numEvents[" << iName << "," << reduced_name_samples.at(iName) << "][" << iCut << "] = " << numEvents[iName][iCut] << " , " << histo[iName][iCut]->GetEntries() << " , " << histo[iName][iCut]->GetEffectiveEntries() << std::endl;
   
   if (iName != numDATA) {
    hTrendPie[iCut]->SetTextSize(0.04);
    hTrendPie[iCut]->SetTextFont(12);
    hTrendPie[iCut]->SetEntryFillColor(iName,vColor[iName]);
    hTrendPie[iCut]->SetEntryFillStyle(iName,3001);
    hTrendPie[iCut]->SetEntryLabel(iName, reduced_name_samples.at(iName).c_str());
    hTrendPie[iCut]->SetEntryLineColor(iName, vColor[iName]);
    hTrendPie[iCut]->SetEntryLineStyle(iName, 2);
    hTrendPie[iCut]->SetEntryLineWidth(iName, 2);
    hTrendPie[iCut]->SetEntryRadiusOffset(iName, 0.01);
    hTrendPie[iCut]->SetEntryVal(iName,numEvents[iName][iCut]);
   }
   else {
    hTrendPie[iCut]->SetEntryLabel(iName, "");
   }
  }
  if (iName != numDATA) {
   hsTrend->Add(hTrend[iName]);
  }
 }
 AddError(hsTrend,LumiSyst);
 
 TH1F* hTrendSumMC = ((TH1F*)(hsTrend->GetStack()->Last()));
 ///==== hTrend with pull plot ====
 TH1F* hPullTrendSumMC = PullPlot(hTrend[numDATA], hTrendSumMC);
  
 LumiSyst = 0; ///---- bug fix
 
 
 
 
 TCanvas* cTrendPie[100];
 TCanvas* cTrendPieAll = new TCanvas("cTrendPieAll","cTrendPieAll",400 * vCut.size(),400);
 cTrendPieAll -> Divide (vCut.size());
 TCanvas* cTrend = new TCanvas("cTrend","cTrend",400,400);
 TCanvas* cTrendSample[100];
 
 
 for (uint iName=0; iName<reduced_name_samples.size(); iName++){
  TString nameCanvas = Form("%d_Canvas_Sample",iName);
  cTrendSample[iName] = new TCanvas(nameCanvas,nameCanvas,400,400);
  hTrend[iName] -> Draw();
  gPad->SetLogy();
  gPad->SetGrid();
 }
 
 
 
 std::cout.precision (2) ;
 std::cout.unsetf(std::ios::scientific);


 
 std::cout << std::endl;
 std::cout << " *********************************** " << std::endl;
 std::cout << std::setw (12) << "sample";
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  std::cout << " | " << std::setw (8) <<  iCut;
  std::cout << " [" << std::setw (8) <<  "XXX";
  std::cout << " ]";
 }
 std::cout << std::endl;
 for (uint iName=0; iName<reduced_name_samples.size(); iName++){
  std::cout << std::setw (12) << reduced_name_samples.at(iName) ;
  for (uint iCut = 0; iCut<vCut.size(); iCut++){
   std::cout << " | " << std::setw (8) <<  hTrend[iName]->GetBinContent(iCut+1);
   std::cout << " [" << std::setw (8) <<  hTrend[iName]->GetBinError(iCut+1);
   std::cout << " ]";
  }
  std::cout << std::endl;
 }
 
 std::cout << std::endl;
 std::cout << " *********************************** " << std::endl;
 for (uint iName=0; iName<reduced_name_samples.size(); iName++){
  std::cout << " | " << std::setw (8) << reduced_name_samples.at(iName) ;
  std::cout << " [" << std::setw (8) <<  "err";
  std::cout << " ]";
 }
 std::cout << std::endl;
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iName=0; iName<reduced_name_samples.size(); iName++){
   std::cout << " | " << std::setw (8) <<  hTrend[iName]->GetBinContent(iCut+1);
   std::cout << " [" << std::setw (8) <<  hTrend[iName]->GetBinError(iCut+1);
   std::cout << " ]";
  }
  std::cout << std::endl;
 }
 
 
 
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << " *********************************** " << std::endl;
 std::cout << " ************* 1 fb-1 ************* " << std::endl;
 std::cout << std::setw (12) << "sample";
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  std::cout << " | " << std::setw (8) <<  iCut;
  std::cout << " [" << std::setw (8) <<  "XXX";
  std::cout << " ]";
 }
 std::cout << std::endl;
 for (uint iName=0; iName<reduced_name_samples.size(); iName++){
  std::cout << std::setw (12) << reduced_name_samples.at(iName) ;
  for (uint iCut = 0; iCut<vCut.size(); iCut++){
   std::cout << " | " << std::setw (8) <<  hTrend[iName]->GetBinContent(iCut+1) / LUMI * 1000.;
   std::cout << " [" << std::setw (8) <<  hTrend[iName]->GetBinError(iCut+1) / LUMI * 1000.;
   std::cout << " ]";
  }
  std::cout << std::endl;
 }
 
 std::cout << std::endl;
 std::cout << " *********************************** " << std::endl;
 for (uint iName=0; iName<reduced_name_samples.size(); iName++){
  std::cout << " | " << std::setw (6) << reduced_name_samples.at(iName) ;
  std::cout << " [" << std::setw (6) <<  "err";
  std::cout << " ]";
 }
 std::cout << std::endl;
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iName=0; iName<reduced_name_samples.size(); iName++){
   std::cout << " | " << std::setw (6) <<  hTrend[iName]->GetBinContent(iCut+1) / LUMI * 1000.;
   std::cout << " [" << std::setw (6) <<  hTrend[iName]->GetBinError(iCut+1) / LUMI * 1000.;
   std::cout << " ]";
  }
  std::cout << std::endl;
 }
 
 
 ///==== draw trend vs cut (begin)
 cTrend->cd();
 DrawStack(hsTrend,1,LumiSyst);
 hTrend[numDATA] -> Draw("EsameP");
 gPad->SetLogy();
 gPad->SetGrid();
 leg->Draw();
 latex->Draw();
  
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  TString nameCanvas = Form("%d_Canvas_Trend",iCut);
  cTrendPie[iCut] = new TCanvas(nameCanvas,nameCanvas,400,400);
  cTrendPie[iCut]->cd();
  hTrendPie[iCut] -> Draw("3d t nol");
  hTrendPie[iCut]->SetX(.45);
  hTrendPie[iCut]->SetRadius(.22);
  leg->Draw();
  latex->Draw();
  
  cTrendPieAll->cd(iCut+1);
  hTrendPie[iCut] -> Draw("3d t nol");
  hTrendPie[iCut]->SetX(.45);
  hTrendPie[iCut]->SetRadius(.22);
  leg->Draw();
  latex->Draw();
 }
 ///==== draw trend vs cut (end)
 
 
 
 std::cerr << " ******************************************* end *******************************************" << std::endl;
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 
 
 
 ///==== save output ====
 outFile.cd();
 cTrend -> Write();
 
 outFile.mkdir("Trend");
 outFile.cd("Trend");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  cTrendPie[iCut] -> Write();
 }
 cTrendPieAll -> Write();
 
 
 outFile.cd();
 outFile.mkdir("PU");
 outFile.cd("PU");
 
 hPUMC     -> Write();
 hPUDATA   -> Write();
 hPUWeight -> Write();
 
 
 outFile.cd();
 outFile.mkdir("Sample");
 outFile.cd("Sample");
 
 for (uint iName=0; iName<reduced_name_samples.size(); iName++){
  cTrendSample[iName] ->Write();
 }  
 
 leg->Write();
 
}





