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

#include "../test/TDRStyle.cc"
#include "../test/Read.cc"
// #include "../test/DrawTools.h"

#include "PUclass.h"





#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif


///
///      ___|  _)      |        |                        |     _ |  __ \          
///    \___ \   |   _` |   _ \  __ \    _` |  __ \    _` |       |  |   |         
///          |  |  (   |   __/  |   |  (   |  |   |  (   |       |  |   |         
///    _____/  _| \__,_| \___| _.__/  \__,_| _|  _| \__,_|      _| ____/          
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
 std::cout << "      ___|  _)      |        |                        |     _ |  __ \\          " << std::endl;
 std::cout << "    \\___ \\   |   _` |   _ \\  __ \\    _` |  __ \\    _` |       |  |   |     " << std::endl;         
 std::cout << "          |  |  (   |   __/  |   |  (   |  |   |  (   |       |  |   |          " << std::endl;    
 std::cout << "    _____/  _| \\__,_| \\___| _.__/  \\__,_| _|  _| \\__,_|      _| ____/       " << std::endl;        
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
 
 
 
 TTree *treeEffVect[100];
 TTree *treeJetLepVect[100];
 
 
  //  [iCut][iRegion] 
 TString* infoString[10][30];
 TLatex *infoLatex[10][30]; 
 TCanvas* ccCanvas[10][30];
 TCanvas* ccCanvasPull[10][30];
 TH1F* histoSumMC[10][30];
 //  [iName][iCut][iRegion]
 TH1F* histo[100][10][30];
 TH1F* histo_temp[100][10][30];
 
 //  [iName][iCut]
 TH1F* histoRegions[100][20];
 TH1F* histoRegions_temp[100][20];
 TH1F* histoRegionsSumMC[20];
 
 
 //  [iName][iCut][iRegion]
 double numEvents[100][10][10];
 
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

 
 ///==== Definition of the Regions A and B  ====
 /// ___________
 ///      |
 ///   A  |  B
 /// _____|_____
 ///
 std::string CutFileAB = gConfigParser -> readStringOption("Selections::CutFileAB");
 std::vector<std::string> vCutAB;
 std::cout << " nCutsAB = " << ReadFileCut(CutFileAB, vCutAB) << std::endl;
 
 if (vCutAB.size() != 2 ) {
  std::cout << " No Good definition of A and B regions. " << std::endl;
  return 1;
 }
 
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
 
 outFile.cd();
 TH1F* histoDebug = new TH1F("histoDebug","histoDebug",100,-10,100000000);
 histoDebug->Sumw2();
 
 
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

  ///==== calculate Data Driven A/B ratio (begin) ====
  ///==== A_DATA = A_MC / B_MC * B_DATA
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   
   ///==== initialize ====
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    reduced_name_samples_flag.at(iName) = -1;
   } 
   ///==== cicle on samples ====
   for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
    if (debug) std::cout << " Sample[" << iSample << ":" << numberOfSamples << "] = " << nameSample[iSample] << " ~~ " << std::endl;
    TString name_histo_temp = Form("%s_%d_%d_temp",nameSample[iSample], iCut, iRegion);
    histo_temp[iSample][iCut][iRegion] = new TH1F(name_histo_temp,name_histo_temp,vCutAB.size()+1,0,vCutAB.size()+1);
    histo_temp[iSample][iCut][iRegion] -> Sumw2(); //---- cos� mette l'errore giusto!
    
    if (iRegion == 0) {
     TString name_histoRegions_temp = Form("%s_%d_HistoRegions_temp",nameSample[iSample], iCut);
     histoRegions_temp[iSample][iCut] = new TH1F(name_histoRegions_temp,name_histoRegions_temp,vCutAB.size()+1,0,vCutAB.size()+1);
     histoRegions_temp[iSample][iCut] -> Sumw2(); //---- cos� mette l'errore giusto!
    }
    
    TString CutExtended;
    if (iSample != numDATA) {
     CutExtended = Form ("(%s && %s) * autoWeight(numPUMC)",vCutAB.at(iRegion).c_str(),Cut.Data());    
    }
    else {
     CutExtended = Form ("(%s && %s)",vCutAB.at(iRegion).c_str(),Cut.Data());    
    }
    
    if (debug) std::cout << " CutExtended = " << CutExtended.Data() << std::endl;
    
    treeJetLepVect[iSample] -> Draw("eventId >> histoDebug",CutExtended,"goff");
    
//     std::cout << " histoDebug->GetEntries() = " << histoDebug->GetEntries() << std::endl;
//     std::cout << " histoDebug->GetEffectiveEntries() = " << histoDebug->GetEffectiveEntries() << std::endl;
//     std::cout << " treeJetLepVect[iSample] -> GetEntries(CutExtended) = " << treeJetLepVect[iSample] -> GetEntries(CutExtended) << std::endl;
    
    double error = 0;
    int num = histoDebug->IntegralAndError(0,histoDebug->GetNbinsX()+1,error);
     
    histoDebug -> Reset();
    
//     int num = treeJetLepVect[iSample] -> GetEntries(CutExtended);
    histo_temp[iSample][iCut][iRegion] -> SetBinContent(iRegion+1,num);
    histo_temp[iSample][iCut][iRegion] -> SetBinError(iRegion+1,error);
  
    if (debug) std::cout << " num[" << iSample << "][" << iCut << "][" << iRegion << "::" << vCutAB.size() << "] = " << num << std::endl;
    
    if (Normalization[iSample]>0) { 
     histo_temp[iSample][iCut][iRegion] -> Scale(Normalization[iSample]); 
    }
    
    histoRegions_temp[iSample][iCut] -> Add(histo_temp[iSample][iCut][iRegion]);
    
    for (uint iName=0; iName<reduced_name_samples.size(); iName++){
     if (name_samples.at(iSample) == reduced_name_samples.at(iName)){
      if (reduced_name_samples_flag.at(iName) == -1){
       TString name_histoTot_temp = Form("%s_%d_%d_Tot_temp",reduced_name_samples.at(iName).c_str(),iCut, iRegion);
       TString name_HR_histoTot_temp = Form("%d %d",iRegion, iCut);
       histo[iName][iCut][iRegion] = new TH1F(name_histoTot_temp,name_HR_histoTot_temp,vCutAB.size()+1,0,vCutAB.size()+1);
       histo[iName][iCut][iRegion] -> Sumw2(); //---- cos� mette l'errore giusto!
       if (iRegion == 0) {
	TString name_histoRegions = Form("%s_%d_HistoRegions",reduced_name_samples.at(iName).c_str(), iCut);
	histoRegions[iName][iCut] = new TH1F(name_histoRegions,name_histoRegions,vCutAB.size()+1,0,vCutAB.size()+1);
	histoRegions[iName][iCut] -> Sumw2(); //---- cos� mette l'errore giusto!
       }
       reduced_name_samples_flag.at(iName) = 1;
      }
      histo[iName][iCut][iRegion] -> Add(histo_temp[iSample][iCut][iRegion]);
      histoRegions[iName][iCut] -> Add(histoRegions_temp[iSample][iCut]);
      if (debug) std::cout << " histoRegions[" << iName << "][" << iCut << "] = " << histoRegions[iName][iCut] -> GetEntries() << std::endl;
      if (debug) std::cout << " histoRegions_temp[" << iSample << "][" << iCut << "] = " << histoRegions_temp[iSample][iCut] -> GetEntries() << std::endl;
     }
    }
   } ///==== end cicle on samples ====
  } ///==== calculate Data Driven A/B ratio (end) ====
 } ///==== end cicle on selections ====
 

//  [iName]
 TH1F* hTrend[100];
 THStack* hsTrend;
 //  [iCut][iRegion]
 TPie* hTrendPie[100][10];
 
 
 //  [iCut][iRegion]
 THStack* hs[100][100];
 TH1F* hPull[100][100];
 
 
 //  [iCut]
 THStack* hsRegions[100];
 TH1F* hPullRegions[100];
 
 
 
 ///==== cicle on selections ====
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  ///==== cicle on Data Driven A/B ratio ====
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   TString nameStack = Form("%d_%d_stack",iCut,iRegion);
   hs[iCut][iRegion] = new THStack(nameStack,nameStack);
   
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    histo[iName][iCut][iRegion]->GetXaxis()->SetTitle("regions");
    histo[iName][iCut][iRegion]->SetMarkerColor(vColor[iName]);
    histo[iName][iCut][iRegion]->SetLineColor(vColor[iName]);
    histo[iName][iCut][iRegion]->SetFillColor(vColor[iName]);
    histo[iName][iCut][iRegion]->SetLineWidth(2);
    histo[iName][iCut][iRegion]->SetFillStyle(3001);
    
    bool isSig = false;
    for (std::vector<std::string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
     if (reduced_name_samples.at(iName) == *itSig) isSig = true;
    }
    
    if (!isSig && reduced_name_samples.at(iName) != "DATA") {
     hs[iCut][iRegion]->Add(histo[iName][iCut][iRegion]);
    }
    else {
     if (!isSig) {
      histo[iName][iCut][iRegion]->SetMarkerStyle(20);
      histo[iName][iCut][iRegion]->SetMarkerSize(1);
      histo[iName][iCut][iRegion]->SetMarkerColor(kBlack);
      histo[iName][iCut][iRegion]->SetLineColor(kBlack);
      histo[iName][iCut][iRegion]->SetFillColor(kBlack);
      histo[iName][iCut][iRegion]->SetLineWidth(2);
      histo[iName][iCut][iRegion]->SetFillStyle(3001);  
     }
     else {
      histo[iName][iCut][iRegion]->SetMarkerStyle(21);
      histo[iName][iCut][iRegion]->SetMarkerSize(1);
      histo[iName][iCut][iRegion]->SetLineWidth(2);
      histo[iName][iCut][iRegion]->SetFillStyle(3001);  
     }
    }
   }
   ///==== histo sum MC ====    
   ///==== Add systrematic error ====
   AddError(hs[iCut][iRegion],LumiSyst);
   histoSumMC[iCut][iRegion] = ((TH1F*)(hs[iCut][iRegion]->GetStack()->Last()));
   ///==== histo with pull plot ====
   hPull[iCut][iRegion] = PullPlot(histo[numDATA][iCut][iRegion], histoSumMC[iCut][iRegion]);
   
   ///==== legend ====
   if (!LegendBuilt){
    for (uint iName=0; iName<reduced_name_samples.size(); iName++){
     leg->AddEntry(histo[iName][iCut][iRegion],reduced_name_samples.at(iName).c_str(),"pf");    
     LegendBuilt = true;
    }
   }
  }
 }
 
 
 
 
 ///==== cicle on selections ====
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  TString nameStack = Form("%d_stack_Regions",iCut);
  hsRegions[iCut] = new THStack(nameStack,nameStack);
  
  for (uint iName=0; iName<reduced_name_samples.size(); iName++){
   histoRegions[iName][iCut]->GetXaxis()->SetTitle("regions");
   histoRegions[iName][iCut]->SetMarkerColor(vColor[iName]);
   histoRegions[iName][iCut]->SetLineColor(vColor[iName]);
   histoRegions[iName][iCut]->SetFillColor(vColor[iName]);
   histoRegions[iName][iCut]->SetLineWidth(2);
   histoRegions[iName][iCut]->SetFillStyle(3001);
   
   bool isSig = false;
   for (std::vector<std::string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
    if (reduced_name_samples.at(iName) == *itSig) isSig = true;
   }
   
   if (!isSig && reduced_name_samples.at(iName) != "DATA") {
    hsRegions[iCut]->Add(histoRegions[iName][iCut]);
   }
   else {
    if (!isSig) {
     histoRegions[iName][iCut]->SetMarkerStyle(20);
     histoRegions[iName][iCut]->SetMarkerSize(1);
     histoRegions[iName][iCut]->SetMarkerColor(kBlack);
     histoRegions[iName][iCut]->SetLineColor(kBlack);
     histoRegions[iName][iCut]->SetFillColor(kBlack);
     histoRegions[iName][iCut]->SetLineWidth(2);
     histoRegions[iName][iCut]->SetFillStyle(3001);  
    }
    else {
     histoRegions[iName][iCut]->SetMarkerStyle(21);
     histoRegions[iName][iCut]->SetMarkerSize(1);
     histoRegions[iName][iCut]->SetLineWidth(2);
     histoRegions[iName][iCut]->SetFillStyle(3001);  
    }
   }
  }
  ///==== histo sum MC ====    
  ///==== Add systrematic error ====
  AddError(hsRegions[iCut],LumiSyst);
  histoRegionsSumMC[iCut] = ((TH1F*)(hsRegions[iCut]->GetStack()->Last()));
  if (debug) std::cout << " histoRegionsSumMC[" << iCut << ":" << vCut.size() << "] integral = " << histoRegionsSumMC[iCut]->Integral() << std::endl;
  ///==== histo with pull plot ====
  hPullRegions[iCut] = PullPlot(histoRegions[numDATA][iCut], histoRegionsSumMC[iCut]);
 }
 
 
 ///==== calculate number of events after each step of the analysis ====
 //  [iName][iCut]
 hsTrend = new THStack("Trend","Trend");
 
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   TString nameTHTrendPie = Form("%d_%d_Trend_Pie",iCut,iRegion);
   hTrendPie[iCut][iRegion] = new TPie (nameTHTrendPie,nameTHTrendPie,reduced_name_samples.size());
  }
 }
 
 for (uint iName=0; iName<reduced_name_samples.size(); iName++){
  TString nameTHTrend = Form("%d_Trend",iName);
  hTrend[iName] = new TH1F (nameTHTrend,nameTHTrend,vCut.size(),0,vCut.size());
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
   double tot = 0;
   for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
    numEvents[iName][iCut][iRegion] = histo[iName][iCut][iRegion]->Integral(); //--- consider each population
    tot += numEvents[iName][iCut][iRegion];
    if (debug) std::cout << ">>> >>>  numEvents[" << iName << "," << reduced_name_samples.at(iName) << "][" << iCut << "][" << iRegion << "] = " << numEvents[iName][iCut][iRegion] << " , " << histo[iName][iCut][iRegion]->GetEntries() << " , " << histo[iName][iCut][iRegion]->GetEffectiveEntries() << std::endl;
   }
   hTrend[iName]->SetBinContent(iCut+1,tot);
//     IntegralAndError
//     Double_t IntegralAndError(Int_t binx1, Int_t binx2, Double_t& err, Option_t* option = "") const
   if (debug) std::cout << ">>>  numEvents[" << iName << "," << reduced_name_samples.at(iName) << "][" << iCut << "] = " << tot << std::endl;
   
   for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
    if (iName != numDATA) {
     hTrendPie[iCut][iRegion]->SetTextSize(0.04);
     hTrendPie[iCut][iRegion]->SetTextFont(12);
     hTrendPie[iCut][iRegion]->SetEntryFillColor(iName,vColor[iName]);
     hTrendPie[iCut][iRegion]->SetEntryFillStyle(iName,3001);
     hTrendPie[iCut][iRegion]->SetEntryLabel(iName, reduced_name_samples.at(iName).c_str());
     hTrendPie[iCut][iRegion]->SetEntryLineColor(iName, vColor[iName]);
     hTrendPie[iCut][iRegion]->SetEntryLineStyle(iName, 2);
     hTrendPie[iCut][iRegion]->SetEntryLineWidth(iName, 2);
     hTrendPie[iCut][iRegion]->SetEntryRadiusOffset(iName, 0.01);
     hTrendPie[iCut][iRegion]->SetEntryVal(iName,numEvents[iName][iCut][iRegion]);
    }
    else {
     hTrendPie[iCut][iRegion]->SetEntryLabel(iName, "");
     //     hTrendPie[iCut]->SetEntryVal(iName,10e-1);
    }
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
 
 ///==== calculate agreement data-MC: Kolmogorov-Smirnov test ==== 
 ///==== cicle on selections ====
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  ///==== cicle on Data Driven A/B ratio ====
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   double KS = -1;
   double Chi2 = -1;
   if (histo[numDATA][iCut][iRegion]->GetEntries() != 0 && histoSumMC[iCut][iRegion]->GetEntries() != 0) {
    KS = histo[numDATA][iCut][iRegion]->KolmogorovTest(histoSumMC[iCut][iRegion],"M");
    Chi2 = histo[numDATA][iCut][iRegion]->Chi2Test(histoSumMC[iCut][iRegion],"UW");
   }
   std::cout << " KS[" << iCut << "][" << iRegion << "] = " << KS << std::endl;
   infoString[iCut][iRegion] = new TString(Form("#splitline{KS prob = %.4f}{#chi^{2} prob = %.4f}",KS,Chi2));
   infoLatex[iCut][iRegion] = new TLatex(0.80, 0.10, *(infoString[iCut][iRegion])); 
   infoLatex[iCut][iRegion]->SetTextAlign(12);
   infoLatex[iCut][iRegion]->SetNDC();
   infoLatex[iCut][iRegion]->SetTextFont(42);
   infoLatex[iCut][iRegion]->SetTextSize(0.03);
  }
 }
 
 
 LumiSyst = 0; ///---- bug fix
 
 
 
  
 //      [iCut][iRegion] 
 TCanvas* cTrendPie[100][10];
 TCanvas* cTrendPieAll = new TCanvas("cTrendPieAll","cTrendPieAll",400 * vCut.size(),400*vCutAB.size());
 cTrendPieAll -> Divide (vCut.size(),vCutAB.size());
 TCanvas* cTrend = new TCanvas("cTrend","cTrend",400,400);
 TCanvas* cTrendPull = new TCanvas("cTrendPull","cTrendPull",400,800);

 TCanvas* cCompareRegionsCut[100];
 TCanvas* cCompareRegionsCutPull[100];
 
 TCanvas* cCompareCutPull[100];
 TCanvas* cCompareRegionPull[100];
 
 TCanvas* cCompareCut[100];
 TCanvas* cCompareRegion[100];
 
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  TString nameCanvas = Form("%d_Cut_Canvas",iCut);
  cCompareCut[iCut] = new TCanvas(nameCanvas,nameCanvas,400 * vCutAB.size(),400);
  cCompareCut[iCut] -> Divide (vCutAB.size(),1);
  TString nameCanvasPull = Form("%d_Cut_Canvas_Pull",iCut);
  cCompareCutPull[iCut] = new TCanvas(nameCanvasPull,nameCanvasPull,400 * vCutAB.size(),400*2);
  cCompareCutPull[iCut] -> Divide (vCutAB.size(),2);
  
  nameCanvas = Form("%d_Cut_Canvas_Regions",iCut);
  cCompareRegionsCut[iCut] = new TCanvas(nameCanvas,nameCanvas,400,400);
  nameCanvasPull = Form("%d_Cut_Canvas_Pull_Regions",iCut);
  cCompareRegionsCutPull[iCut] = new TCanvas(nameCanvasPull,nameCanvasPull,400,400*2);
  cCompareRegionsCutPull[iCut] -> Divide(1,2);
 }
 
 ///==== cicle on Data Driven A/B ratio ====
 for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
  TString nameCanvas = Form("%d_Region_Canvas",iRegion);
  cCompareRegion[iRegion] = new TCanvas(nameCanvas,nameCanvas,400,400 * vCut.size());
  cCompareRegion[iRegion] -> Divide (1,vCut.size());
  TString nameCanvasPull = Form("%d_Region_Canvas_Pull",iRegion);
  cCompareRegionPull[iRegion] = new TCanvas(nameCanvasPull,nameCanvasPull,400*2,400 * vCut.size());
  cCompareRegionPull[iRegion] -> Divide (2,vCut.size());
 }
 
 
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   TString nameCanvas = Form("%d_%d_Canvas",iCut,iRegion);
   ccCanvas[iCut][iRegion] = new TCanvas(nameCanvas,nameCanvas,400,400);
   TString nameCanvasPull = Form("%d_%d_CanvasPull",iCut,iRegion);
   ccCanvasPull[iCut][iRegion] = new TCanvas(nameCanvasPull,nameCanvasPull,400,400);
  }
 } 
 
 
 ///==== draw trend vs cut (begin)
 cTrend->cd();
 DrawStack(hsTrend,1,LumiSyst);
 hTrend[numDATA] -> Draw("EsameP");
 gPad->SetLogy();
 gPad->SetGrid();
 leg->Draw();
 latex->Draw();
 
 cTrendPull->Divide(1,2);
 cTrendPull->cd(1);
 DrawStack(hsTrend,1,LumiSyst);
 hTrend[numDATA] -> Draw("EsameP");
 gPad->SetLogy();
 gPad->SetGrid();
 leg->Draw();
 latex->Draw();
 cTrendPull->cd(2);
 hPullTrendSumMC->Draw("EP");
 gPad->SetGrid();
 
 
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   TString nameCanvas = Form("%d_%d_Canvas_Trend",iCut,iRegion);
   cTrendPie[iCut][iRegion] = new TCanvas(nameCanvas,nameCanvas,400,400);
   cTrendPie[iCut][iRegion]->cd();
   hTrendPie[iCut][iRegion] -> Draw("3d t nol");
   hTrendPie[iCut][iRegion]->SetX(.45);
   hTrendPie[iCut][iRegion]->SetRadius(.22);
   leg->Draw();
   latex->Draw();
   
   cTrendPieAll->cd(iCut+1+vCut.size()*iRegion);
   hTrendPie[iCut][iRegion] -> Draw("3d t nol");
   hTrendPie[iCut][iRegion]->SetX(.45);
   hTrendPie[iCut][iRegion]->SetRadius(.22);
   leg->Draw();
   latex->Draw();
  }
 }
 ///==== draw trend vs cut (end)
 
 
 ///==== cicle on selections ====
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  
  cCompareRegionsCut[iCut] -> cd();
  DrawStack(hsRegions[iCut],1,LumiSyst);
  gPad->SetLogy();
  gPad->SetGrid();
  leg->Draw();
  latex->Draw();
  
  cCompareRegionsCutPull[iCut] -> cd(1);
  DrawStack(hsRegions[iCut],1,LumiSyst);
  gPad->SetLogy();
  gPad->SetGrid();
  leg->Draw();
  latex->Draw();
  
  cCompareRegionsCutPull[iCut] -> cd(2);
  hPullRegions[iCut]->Draw("EP");
  gPad->SetGrid();
   
  cCompareRegionsCut[iCut] -> cd();
  histoRegions[numDATA][iCut]->Draw("EsameB");
  
  cCompareRegionsCutPull[iCut] -> cd(1);
  histoRegions[numDATA][iCut]->Draw("EsameB");
  
  
  ///==== cicle on Data Driven A/B ratio ====
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   ///==== draw in canvas ====
   cCompareCut[iCut] -> cd(iRegion+1);
   DrawStack(hs[iCut][iRegion],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iRegion]->Draw();
   
   cCompareRegion[iRegion] -> cd(iCut+1);
   DrawStack(hs[iCut][iRegion],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iRegion]->Draw();
   
   
   cCompareCutPull[iCut] -> cd(iRegion+1);
   DrawStack(hs[iCut][iRegion],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iRegion]->Draw();
   
   cCompareRegionPull[iRegion] -> cd(iCut*2+1);
   DrawStack(hs[iCut][iRegion],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iRegion]->Draw();
   
   
   
   cCompareCutPull[iCut] -> cd(iRegion+1+vCutAB.size());
   hPull[iCut][iRegion]->Draw("EP");
   gPad->SetGrid();
   gPad->SetLeftMargin(0.17);
   gPad->SetRightMargin(0.07);
   
   cCompareRegionPull[iRegion] -> cd(iCut*2+2);
   hPull[iCut][iRegion]->Draw("EP");
   gPad->SetGrid();
   gPad->SetLeftMargin(0.17);
   gPad->SetRightMargin(0.07);
   
   
   ccCanvas[iCut][iRegion]-> cd();
   DrawStack(hs[iCut][iRegion],1,LumiSyst);
   gPad->SetLogy();
   gPad->SetGrid();
   leg->Draw();
   latex->Draw();
   infoLatex[iCut][iRegion]->Draw();
   
   ccCanvasPull[iCut][iRegion]-> cd();
   hPull[iCut][iRegion]->Draw("EP");
   gPad->SetGrid();
   gPad->SetLeftMargin(0.17);
   gPad->SetRightMargin(0.07);
   
   
   
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    
    bool isSig = false;
    for (std::vector<std::string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
     if (reduced_name_samples.at(iName) == *itSig) isSig = true;
    }
    
    if (isSig || reduced_name_samples.at(iName) == "DATA") {
     cCompareCut[iCut] -> cd(iRegion+1);
     histo[iName][iCut][iRegion]->Draw("EsameB");
     
     cCompareRegion[iRegion] -> cd(iCut+1);
     histo[iName][iCut][iRegion]->Draw("EsameB");
     
     cCompareCutPull[iCut] -> cd(iRegion+1);
     histo[iName][iCut][iRegion]->Draw("EsameB");

     cCompareRegionPull[iRegion] -> cd(iCut*2+1);
     histo[iName][iCut][iRegion]->Draw("EsameB");
     
     ccCanvas[iCut][iRegion]-> cd();
     histo[iName][iCut][iRegion]->Draw("EsameB");
    }
   }
   
   cCompareCut[iCut] -> cd(iRegion+1);
   leg->Draw();
   cCompareRegion[iRegion] -> cd(iCut+1);
   leg->Draw();
   cCompareCutPull[iCut] -> cd(iRegion+1);
   leg->Draw();
   cCompareRegionPull[iRegion] -> cd(iCut*2+1);
   leg->Draw();
   ccCanvas[iCut][iRegion]-> cd();
   leg->Draw();
   
  }  ///==== end cicle on Data Driven A/B ratio ====
 } ///==== end cicle on selections ====
 
 std::cerr << " ******************************************* end *******************************************" << std::endl;
 
 
 
 ///==== save output ====
 outFile.cd();
 cTrend -> Write();
 cTrendPull -> Write();
 
 outFile.mkdir("Trend");
 outFile.cd("Trend");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   cTrendPie[iCut][iRegion] -> Write();
  }
 }
 cTrendPieAll -> Write();
 
 outFile.cd();
 outFile.mkdir("Cut");
 outFile.cd("Cut");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  cCompareCut[iCut] -> Write();
  cCompareCutPull[iCut] -> Write();
 }
 
 
 outFile.cd();
 outFile.mkdir("CutRegions");
 outFile.cd("CutRegions");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  cCompareRegionsCut[iCut] -> Write();
  cCompareRegionsCutPull[iCut] -> Write();
 }
 
 
 outFile.cd();
 outFile.mkdir("Region");
 outFile.cd("Region");
 ///==== cicle on Data Driven A/B ratio ====
 for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
  cCompareRegion[iRegion] -> Write();
  cCompareRegionPull[iRegion] -> Write();
 }
 
 outFile.cd();
 TDirectory* cdAll = (TDirectory*) outFile.mkdir("All");
 cdAll->mkdir("Region");
 cdAll->mkdir("Pull");
 outFile.cd("All/Region");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   ccCanvas[iCut][iRegion]-> Write();
  }
 }
 
 outFile.cd();
 outFile.cd("All/Pull");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   ccCanvasPull[iCut][iRegion]-> Write();
  }
 }
 
 outFile.cd();
 outFile.mkdir("Data");
 outFile.cd("Data");
 for (uint iCut = 0; iCut<vCut.size(); iCut++){
  for (uint iRegion = 0; iRegion<vCutAB.size(); iRegion++){
   hs[iCut][iRegion] -> Write() ;
   for (uint iName=0; iName<reduced_name_samples.size(); iName++){
    if (reduced_name_samples.at(iName) == "DATA") {
     histo[iName][iCut][iRegion] -> Write();
    }
   }
  }
 }
 
 leg->Write();
 
}




