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

#include <iomanip>


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


using namespace std;

// vector<double> PUWeight;

int GetNumList(vector<int> &list){
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
 
 
 cout << " " << endl;
 cout << " " << endl;
 cout << "      ___|                       |                     \\  |   ___|         /      __ \\     \\  __ __|   \\          " << endl;
 cout << "     |       _ \\   |   |  __ \\   __|   _ \\   __|      |\\/ |  |            /       |   |   _ \\    |    _ \\       " << endl;
 cout << "     |      (   |  |   |  |   |  |     __/  |         |   |  |           /        |   |  ___ \\   |   ___ \\          " << endl;
 cout << "    \\____| \\___/  \\__,_| _|  _| \\__| \\___| _|        _|  _| \\____|     _/        ____/ _/    _\\ _| _/    _\\   " << endl; 
 cout << " " << endl;
 cout << " " << endl; 

 char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
 char black[] = { 0x1b, '[', '0', ';', '3', '0', 'm', 0 };
 char red[] = { 0x1b, '[', '0', ';', '3', '1', 'm', 0 };
 char green[] = { 0x1b, '[', '0', ';', '3', '2', 'm', 0 };
 char yellow[] = { 0x1b, '[', '0', ';', '3', '3', 'm', 0 };
 char blue[] = { 0x1b, '[', '0', ';', '3', '4', 'm', 0 };
 char purple[] = { 0x1b, '[', '0', ';', '3', '5', 'm', 0 };
 char cyan[] = { 0x1b, '[', '0', ';', '3', '6', 'm', 0 };
 char Lgray[] = { 0x1b, '[', '0', ';', '3', '7', 'm', 0 };
 char Dgray[] = { 0x1b, '[', '0', ';', '3', '8', 'm', 0 };
 char Bred[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
 //for bold colors, just change the 0 after the [ to a 1
 
 EColor vColor[1000] = {
  (EColor) (kRed+1),
  (EColor) (kRed+3),
  (EColor) (kGray+1),
  (EColor) (kAzure-2),
  (EColor) (kAzure-9),
  (EColor) (kYellow),
  (EColor) (kGreen+2),
//   
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
  cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << endl ;
  return 1;
 }


 // Parse the config file                                                                                                                                                          
 parseConfigFile (argv[1]) ;
 
 string treeName  = gConfigParser -> readStringOption("Input::treeName");
 string treeNameSelections = gConfigParser -> readStringOption("Input::treeNameSelections");
 string fileSamples = gConfigParser -> readStringOption("Input::fileSamples");
 string inputDirectory = gConfigParser -> readStringOption("Input::inputDirectory");
 
 double LUMI = gConfigParser -> readDoubleOption("Input::Lumi");
 
 double LumiSyst = gConfigParser -> readDoubleOption("Input::LumiSyst");
 
 double Discovery = gConfigParser -> readDoubleOption("Input::Discovery");
 
 vector<string> SignalName;
 SignalName = gConfigParser -> readStringListOption("Input::SignalName");
 
 ///==== PU reweight (begin) ====
 bool doWeightFromFile = false; 
 try {
  doWeightFromFile = gConfigParser -> readStringOption("PU::doWeightFromFile");
 }
 catch (char const* exceptionString){
  cerr << " exception = " << exceptionString << endl;
 }
 cout << ">>>>> PU::doWeightFromFile  " << doWeightFromFile  << endl;  
 
 vector<double> PUMC;
 vector<double> PUDATA;
 PUclass PU;
 double sumPUMC = 0;
 double sumPUDATA = 0;
 TH1F* hPUMC;
 TH1F* hPUDATA;
 TH1F* hPUWeight;
 
 
 string nameWeight = "weight"; 
 if (doWeightFromFile) {
  try {
   nameWeight = gConfigParser -> readStringOption("PU::nameWeight");
  }
  catch (char const* exceptionString){
   cerr << " exception = " << exceptionString << endl;
  }
  cout << ">>>>> PU::nameWeight  " << nameWeight  << endl;  
 }
 
 if (!doWeightFromFile) {
  
  PUMC   = gConfigParser -> readDoubleListOption("PU::PUMC");
  PUDATA = gConfigParser -> readDoubleListOption("PU::PUDATA");
  
  cout << " PUMC.size()   = " << PUMC.size()   << endl;
  cout << " PUDATA.size() = " << PUDATA.size() << endl;
  
  if (PUMC.size() != PUDATA.size()) {
   cerr << " ERROR " << endl;
   return 1;
  }
  
  for (int itVPU = 0; itVPU < PUMC.size(); itVPU++ ){
   sumPUMC += PUMC.at(itVPU);  
  }
  for (int itVPU = 0; itVPU < PUDATA.size(); itVPU++ ){
   sumPUDATA += PUDATA.at(itVPU);  
  } 
  
  for (int itVPU = 0; itVPU < PUMC.size(); itVPU++ ){
   PU.PUWeight.push_back(PUDATA.at(itVPU) / PUMC.at(itVPU) * sumPUMC / sumPUDATA);
  }
  
  PU.Write("autoWeight.cxx");
  gROOT->ProcessLine(".L autoWeight.cxx");
  
  ///==== save PU distribution in TH1F ====
  hPUMC   = new TH1F("hPUMC","hPUMC",PUMC.size(),0,PUMC.size());
  hPUDATA = new TH1F("hPUDATA","hPUDATA",PUDATA.size(),0,PUDATA.size());
  hPUWeight = new TH1F("hPUWeight","hPUWeight",PUDATA.size(),0,PUDATA.size());
  
  for (int itVPU = 0; itVPU < PUMC.size(); itVPU++ ){
   hPUMC     -> SetBinContent(itVPU+1,PUMC.at(itVPU) / sumPUMC);
   hPUDATA   -> SetBinContent(itVPU+1,PUDATA.at(itVPU) / sumPUDATA);
   hPUWeight -> SetBinContent(itVPU+1,PUDATA.at(itVPU) / PUMC.at(itVPU) * sumPUMC / sumPUDATA);
  }
  
 }
 
 ///==== PU reweight (end) ====

 
 
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

//  double XSection  = gConfigParser -> readDoubleOption("Plot::XSection");
 
 ///==== list of selections to perform (NOT sequential additive selections) ====
 string CutFile = gConfigParser -> readStringOption("Selections::CutFile");
 string CutHRFile = "";
 try {
  CutHRFile = gConfigParser -> readStringOption("Selections::CutHRFile");
 }
 catch (char const* exceptionString){
  cerr << " exception = " << exceptionString << endl;
 }
 
 vector<string> vCut;
 vector<string> vCutHR;
 
 cout << " nCuts   = " << ReadFileCut(CutFile, vCut) << endl;
 if (CutHRFile != "") {
  cout << " nCutsHR = " << ReadFileCutHR(CutHRFile, vCutHR) << endl;
 }
 
 if (vCutHR.size() < vCut.size()) {
  int size1 = vCut.size();
  int size2 = vCutHR.size();
  for (int i=0; i<(size1-size2+2); i++) {
   vCutHR.push_back("test");
  }
 }

 for (unsigned int iCut = 0; iCut<vCutHR.size(); iCut++){ 
  cout << " vCutHR[" << iCut << "] = " << vCutHR.at(iCut).c_str() << endl;
 }
 
 ///==== output file ====
 string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 cout << ">>>>> Output::outFileName  " << OutFileName  << endl;  
 
 TFile outFile(OutFileName.c_str(),"RECREATE");
 outFile.cd();
 
 
 ///==== Latinos flag ==== 
 bool  Latinos = false; 
 try {
  Latinos = gConfigParser -> readBoolOption("Input::Latinos");
 }
 catch (char const* exceptionString){
  cerr << " exception = " << exceptionString << endl;
 }
 cout << ">>>>> input::Latinos  " << Latinos  << endl;  
 
 
 ///==== pT Higgs reweight (begin) ====
 string nameptHWeight; 
 try {
  nameptHWeight = gConfigParser -> readStringOption("Input::nameptHWeight");
 }
 catch (char const* exceptionString){
  cerr << " exception = " << exceptionString << endl;
 }
 cout << ">>>>> input::nameptHWeight  " << nameptHWeight  << endl;  
 if (nameptHWeight != ""){
  TString toLoad;
  //   toLoad = Form("cp %s ./",nameptHWeight.c_str());
  //   gROOT->ProcessLine(toLoad.Data());
  toLoad = Form(".L %s",nameptHWeight.c_str());
  gROOT->ProcessLine(toLoad.Data());
 }
 
 string nameptHWeightSample; 
 try {
  nameptHWeight = gConfigParser -> readStringOption("Input::nameptHWeightSample");
 }
 catch (char const* exceptionString){
  cerr << " exception = " << exceptionString << endl;
 }
 cout << ">>>>> input::nameptHWeightSample  " << nameptHWeightSample  << endl;  
 
 
 ///==== pT Higgs reweight (end) ====
 
 
 ///==== debug flag ====
 
 bool  debug = false; 
 try {
  debug = gConfigParser -> readBoolOption("Input::debug");
 }
 catch (char const* exceptionString){
  cerr << " exception = " << exceptionString << endl;
 }
 cout << ">>>>> input::debug  " << debug  << endl;  
 
 ///==== program ====
 
 
 double start, end;
 start = clock();
 
 int Entries[100];
 
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
 
 vector<int> join_samples;
 vector<string> name_samples;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  name_samples.push_back(nameHumanReadable[iSample]);
  join_samples.push_back(-1);
 }
 
 
 vector<string> reduced_name_samples;
 vector<int>         reduced_name_samples_flag;
 for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
  bool flag_name = false;
  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
   if (reduced_name_samples.at(iName) == name_samples.at(iSample)) flag_name = true;
  }
  if (flag_name == false) {
   reduced_name_samples.push_back(name_samples.at(iSample));
   reduced_name_samples_flag.push_back(-1);
  }

 }

 
 cout << " numberOfSamples = " << numberOfSamples << endl;
 for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
  double XSection;
  int numEntriesBefore;
  double preselection_efficiency;
  treeEffVect[iSample]->SetBranchAddress("XSection",&XSection);
  treeEffVect[iSample]->SetBranchAddress("numEntriesBefore",&numEntriesBefore);
  treeEffVect[iSample]->SetBranchAddress("preselection_efficiency",&preselection_efficiency);  
  treeEffVect[iSample]->GetEntry(0);
  cout << " Xsection = " << XSection << " ~~~> " << xsection[iSample] << endl;
  XSection = xsection[iSample];
  if (numEntriesBefore != 0) {
   Normalization[iSample] = LUMI * XSection * preselection_efficiency / numEntriesBefore;
  }
  else {
   Normalization[iSample] = 0; 
  }    
  
  if (Latinos) Normalization[iSample] = XSection * LUMI / 1000.;
  
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
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  if (reduced_name_samples.at(iName) == "DATA") {
   numDATA = iName;
  }
 }

 if (debug) cout << " Cut size = " << vCut.size() << " ~~ " << endl;
 cout.precision (5) ;
 cout.unsetf(ios::scientific);

 
 ///==== cicle on selections ====
 for (unsigned int iCut =0; iCut<vCut.size(); iCut++){
  TString Cut = Form ("%s",vCut.at(iCut).c_str());
  if (debug) cout << " Cut[" << iCut << ":" << vCut.size() << "] = " << Cut.Data() << " ~~ " << endl;
  ///==== initialize ====
  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
   reduced_name_samples_flag.at(iName) = -1;
  }
  
  ///==== cicle on samples ====
  for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
   if (debug) cout << " Sample[" << iSample << ":" << numberOfSamples << "] = " << nameSample[iSample] << " ~~ " << endl;
   TString name_histo_temp = Form("%s_%d_temp",nameSample[iSample], iCut);
   histo_temp[iSample][iCut] = new TH1F(name_histo_temp,name_histo_temp,100,-10,10000000000);
   char toDraw[1000];
   sprintf(toDraw,"1 >> %s",name_histo_temp.Data());      
   histo_temp[iSample][iCut] -> Sumw2(); //---- così mette l'errore giusto!
   
   TString CutExtended;
   bool isData = false;
   for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
    if (name_samples.at(iSample) == reduced_name_samples.at(iName)){
     if (iName == numDATA) {
      isData = true;
     }
    }
   }  
   if (!isData) {
    if (nameptHWeight != "" && name_samples.at(iSample) == nameptHWeightSample){
     if (!doWeightFromFile) {
      CutExtended = Form ("(%s) * autoWeight(numPUMC) * ptHWeight(ptH)",Cut.Data());    
     }
     else {
      CutExtended = Form ("(%s) * ptHWeight(ptH) * (%s)",Cut.Data(),nameWeight.c_str());    
     }
    }
    else {
     if (!doWeightFromFile) {
      CutExtended = Form ("(%s) * autoWeight(numPUMC)",Cut.Data());    
     }
     else {
      CutExtended = Form ("(%s) * (%s)",Cut.Data(),nameWeight.c_str());    
     }
    }
    //      CutExtended = Form ("(%s) * autoWeight(numPUMC) * ptHWeight(ptH)",Cut.Data());    
   }
   else {
    CutExtended = Form ("(%s)",Cut.Data());    
   }
   
   treeJetLepVect[iSample]->Draw(toDraw,CutExtended,"");
   
   if (Normalization[iSample]>0) { 
    histo_temp[iSample][iCut] -> Scale(Normalization[iSample]); 
   }
   for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
    if (name_samples.at(iSample) == reduced_name_samples.at(iName)){
     if (reduced_name_samples_flag.at(iName) == -1){
      TString name_histoTot_temp = Form("%s_%d_Tot_temp",reduced_name_samples.at(iName).c_str(),iCut);
      TString name_HR_histoTot_temp = Form("cut %d",iCut);
      histo[iName][iCut] = new TH1F(name_histoTot_temp,name_HR_histoTot_temp,100,-10,10000000000);
      histo[iName][iCut] -> Sumw2(); //---- cosÃ¬ mette l'errore giusto!
      reduced_name_samples_flag.at(iName) = 1;
     }
     histo[iName][iCut] -> Add(histo_temp[iSample][iCut]);
    }
   }
   cout <<"Processing: " << blue << (((double) iCut)/vCut.size())*100. << "% "  << normal <<  " -- " <<  red << (((double) numberOfSamples - iSample)/(numberOfSamples))*100. << "% \r"  << normal << flush;   
  } ///==== end cicle on samples ====
   //cout << "Processing: " << blue << (((double) iCut)/vCut.size())*100. << "% \r"  << normal << flush;   
  } ///==== end cicle on selections ====
 
 //  [iName]
 TH1F* hTrend[100];
 THStack* hsTrend;
 //  [iCut]
 TPie* hTrendPie[100];
 
 //  [iCut]
 vector<THStack*> hs;
 
 cout << endl;
 
 ///==== cicle on selections ====
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
  TString nameStack = Form("%d_stack",iCut);
  hs.push_back(new THStack(nameStack,nameStack));
  
  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
   histo[iName][iCut]->GetXaxis()->SetTitle("eventId");
   histo[iName][iCut]->SetMarkerColor(vColor[iName]);
   histo[iName][iCut]->SetLineColor(vColor[iName]);
   histo[iName][iCut]->SetFillColor(vColor[iName]);
   histo[iName][iCut]->SetLineWidth(2);
   histo[iName][iCut]->SetFillStyle(3001);
   
   bool isSig = false;
   for (vector<string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
    if (reduced_name_samples.at(iName) == *itSig) isSig = true;
   }
   
   if (!isSig && reduced_name_samples.at(iName) != "DATA") {
    hs.at(iCut)->Add(histo[iName][iCut]);
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
   AddError(hs.at(iCut),LumiSyst);
   histoSumMC[iCut] = ((TH1F*)(hs.at(iCut)->GetStack()->Last()));

   cout << " MC / DATA[" << iCut << "] = "<< histoSumMC[iCut]->Integral() << " / " << histo[numDATA][iCut]->Integral() << " = " << (histo[numDATA][iCut]->Integral() ? histoSumMC[iCut]->Integral()/ histo[numDATA][iCut]->Integral() : 0) << endl;

 
  ///==== legend ====
  if (!LegendBuilt){
   for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
    leg->AddEntry(histo[iName][iCut],reduced_name_samples.at(iName).c_str(),"pf");    
    LegendBuilt = true;
   }
  }
 }
 cout << endl << endl;
 
 ///==== calculate number of events after each step of the analysis ====
 //  [iName][iCut]
 hsTrend = new THStack("Trend","Trend");
 
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
  TString nameTHTrendPie = Form("%d_Trend_Pie",iCut);
  hTrendPie[iCut] = new TPie (nameTHTrendPie,nameTHTrendPie,reduced_name_samples.size());
 }
 
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
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
  for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
   double error = 0;
   numEvents[iName][iCut] = histo[iName][iCut]->IntegralAndError(0,histo[iName][iCut]->GetNbinsX()+1,error);
   hTrend[iName]->SetBinContent(iCut+1,numEvents[iName][iCut]);
   hTrend[iName]->SetBinError(iCut+1,error);

   TString nameBin = Form("%d",iCut);
   hTrend[iName]->GetXaxis()->SetBinLabel(iCut+1,nameBin);
//     IntegralAndError
//     Double_t IntegralAndError(Int_t binx1, Int_t binx2, Double_t& err, Option_t* option = "") const
   cout << ">>>  numEvents[" << iName << "," << reduced_name_samples.at(iName) << "][" << iCut << "] = " << numEvents[iName][iCut] << " , " << histo[iName][iCut]->GetEntries() << " , " << histo[iName][iCut]->GetEffectiveEntries()<<" , "<<" error: "<<sqrt(numEvents[iName][iCut])<<endl;
   if(iCut!=0)  
   cout<<  ">>> CutEfficiency[" <<iName<<"," <<  reduced_name_samples.at(iName) << "][" << iCut << "] = " <<numEvents[iName][iCut]/(numEvents[iName][iCut-1]) << " , " << histo[iName][iCut]->GetEntries()/(histo[iName][iCut-1]->GetEntries()) << " , "<< histo[iName][iCut]->GetEffectiveEntries()/(histo[iName][iCut-1]->GetEffectiveEntries())<<" error: "<<sqrt(numEvents[iName][iCut])/(numEvents[iName][iCut-1])<<endl; 
   cout<<endl;
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
 
 
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  TString nameCanvas = Form("%d_Canvas_Sample",iName);
  cTrendSample[iName] = new TCanvas(nameCanvas,nameCanvas,400,400);
  hTrend[iName] -> Draw();
  gPad->SetLogy();
  gPad->SetGrid();
 }
 
 
 
 
 
 
 ///~~~~ for efficiency calculation ~~~~
 
 vector<double> numEntriesFirstStep_reduced_samples;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  numEntriesFirstStep_reduced_samples.push_back(0);
  for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
   if (name_samples.at(iSample) == reduced_name_samples.at(iName)){
//     numEntriesFirstStep_reduced_samples.at(iName) += (Normalization[iSample] ? (1. / Normalization[iSample] * LUMI * xsection[iSample] * LUMI * xsection[iSample]) : -1);    
//     if (Latinos) numEntriesFirstStep_reduced_samples.at(iName) += ((xsection[iSample] * LUMI / 1000.);
    if (Latinos) numEntriesFirstStep_reduced_samples.at(iName) += hTrend[iName]->GetBinContent(1);
    else numEntriesFirstStep_reduced_samples.at(iName) += (Normalization[iSample] ? (1. / Normalization[iSample] * LUMI * xsection[iSample] * LUMI * xsection[iSample]) : -1);
    
   }
  }
 }
//   Normalization[iSample] = LUMI * XSection * preselection_efficiency / numEntriesBefore;
//   1. / Normalization[iSample] = numEntriesBefore / preselection_efficiency / LUMI / XSection;
//   1. / Normalization[iSample] * LUMI * xsection[iSample] = numEntriesBefore / preselection_efficiency;
//   1. / Normalization[iSample] * LUMI * xsection[iSample] * LUMI * xsection[iSample] = numEntriesBefore / preselection_efficiency * LUMI * xsection[iSample];

 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cout << "[" << reduced_name_samples.at(iName) << "] = " << numEntriesFirstStep_reduced_samples.at(iName) << endl;
 }
 
 cout.precision (5) ;
 cout.unsetf(ios::scientific);


 
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout << " *********************************** " << endl;
 cout << " **** samples Y : selections X  **** " << endl;
 cout << " *********************************** " << endl;
 cout << setw (12) << "sample";
 cout << " | " << setw (10) <<  -1;
 cout << " [" << setw (10) <<  "XXX";
 cout << " ]";
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
  cout << " | " << setw (10) <<  vCutHR.at(iCut).c_str();  
//   cout << " | " << setw (10) <<  iCut << "::" << vCut.size();
  cout << " [" << setw (10) <<  "XXX";
  cout << " ]";
 }
 cout << " pappappero!!!" << endl;
 cout << endl;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cout << setw (12) << reduced_name_samples.at(iName) ;
  cout << " | " << cyan << setw (10) <<  numEntriesFirstStep_reduced_samples.at(iName);
  cout << normal << " [" << setw (10) <<  "XXX";
  cout << " ]";
  for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
   cout << " | " << blue << setw (10) <<  hTrend[iName]->GetBinContent(iCut+1);
   cout << normal << " [" << setw (10) <<  hTrend[iName]->GetBinError(iCut+1);
   cout << " ]";
  }
  cout << endl;
 }

 //PG latex format
 //PG --- --- --- --- --- --- --- --- ---  
 //PG header
 cout << endl;
 cout << "LATEX " << " \\hline\n" ;
 cout << "LATEX " << setw (12) << "sample"
      << " & " << setw (10) <<  -1
      << " (" << setw (10) <<  "XXX"
      << " )";
 for (unsigned int iCut = 0; iCut < vCut.size () ; iCut++)
   {
     cout << " & " << setw (10) <<  vCutHR.at(iCut).c_str() 
          << " (" << setw (10) <<  "$\\varepsilon$"
          << " )" ;
   }
 cout << " \\\\" << endl;
 cout << "LATEX " << " \\hline\n" ;
 //PG samples list
 for (unsigned int iName = 0; iName < reduced_name_samples.size () ; iName++)
   {
     cout << "LATEX " << setw (12) << reduced_name_samples.at(iName) 
          << " & " << setw (10) <<  numEntriesFirstStep_reduced_samples.at(iName)
          << " (" << setw (10) <<  "XXX"
          << " )";
     for (unsigned int iCut = 0 ; iCut < vCut.size () ; iCut++)
       {
         cout << " & " << setw (10) <<  hTrend[iName]->GetBinContent(iCut+1)
              << " (" << setw (10) <<  hTrend[iName]->GetBinError(iCut+1)
              << " )";
       }
     cout << " \\\\" << endl;
   }
 cout << "LATEX " << " \\hline\n" ;
 cout << endl;

 cout << " *********************************** " << endl;
 cout << " **** selections Y : samples X  **** " << endl;
 cout << " *********************************** " << endl;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cout << setw (10) <<  "cut";
  cout << " | " << setw (10) << reduced_name_samples.at(iName) ;
  cout << " [" << setw (10) <<  "err";
  cout << " ]";
 }
 cout << endl;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cout << setw (10) <<  "cut";
  cout << " | " << cyan << setw (10) <<  numEntriesFirstStep_reduced_samples.at(iName);
  cout << normal << " [" << setw (10) <<  "XXX";
  cout << " ]";
 }
 cout << endl;
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
  cout << setw (10) <<  vCutHR.at(iCut).c_str();
  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
   cout << " | " << blue << setw (10) <<  hTrend[iName]->GetBinContent(iCut+1);
   cout << normal << " [" << setw (10) <<  hTrend[iName]->GetBinError(iCut+1);
   cout << " ]";
  }
  cout << endl;
 }
 
 
 
 cout << endl;
 cout << endl;
 cout << endl;
 cout << " *********************************** " << endl;
 cout << " ************* 1 fb-1 ************* " << endl;
 cout << setw (12) << "sample";
 cout << " | " << setw (10) <<  -1;
 cout << " [" << setw (10) <<  "XXX";
 cout << " ]";
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
  cout << " | " << setw (10) <<  iCut;
  cout << " [" << setw (10) <<  "XXX";
  cout << " ]";
 }
 cout << endl;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cout << setw (12) << reduced_name_samples.at(iName) ;
  cout << " | " << purple << setw (9) <<  1000 / LUMI * numEntriesFirstStep_reduced_samples.at(iName);
  cout << normal << " [" << setw (9) <<  "XXX";
  cout << " ]";
  for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
   cout << " | " << red << setw (9) <<  hTrend[iName]->GetBinContent(iCut+1) / LUMI * 1000.;
   cout << normal << " [" << setw (9) <<  hTrend[iName]->GetBinError(iCut+1) / LUMI * 1000.;
   cout << " ]";
  }
  cout << endl;
 }
 
 cout << endl;
 cout << " *********************************** " << endl;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cout << " | " << red << setw (10) << reduced_name_samples.at(iName) ;
  cout << normal << " [" << setw (10) <<  "err";
  cout << " ]";
 }
 cout << endl;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cout << " | " << purple << setw (10) <<  1000 / LUMI * numEntriesFirstStep_reduced_samples.at(iName);
  cout << normal << " [" << setw (10) <<  "XXX";
  cout << " ]";
 }
 cout << endl;
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
   cout << " | " << red << setw (10) <<  hTrend[iName]->GetBinContent(iCut+1) / LUMI * 1000.;
   cout << normal << " [" << setw (10) <<  hTrend[iName]->GetBinError(iCut+1) / LUMI * 1000.;
   cout << " ]";
  }
  cout << endl;
 }
 
  
 cout << endl;
 cout << endl;
 cout << endl;
 cout << " **************************************** " << endl;
 cout << " ************* efficiency *************** " << endl;
 cout << setw (12) << "sample";
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
  cout << " | " << setw (10) <<  iCut;
  cout << " [" << setw (10) <<  "XXX";
  cout << " ]";
 }
 cout << endl;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cout << setw (12) << reduced_name_samples.at(iName) ;
  for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
   cout << " | " << yellow << setw (10) <<  hTrend[iName]->GetBinContent(iCut+1) / numEntriesFirstStep_reduced_samples.at(iName);
   cout << normal << " [" << setw (10) <<  hTrend[iName]->GetBinError(iCut+1) / numEntriesFirstStep_reduced_samples.at(iName);
//    cout << " | " << yellow << setw (10) <<  hTrend[iName]->GetBinContent(iCut+1) << " / " << numEntriesFirstStep_reduced_samples.at(iName);
//    cout << normal << " [" << setw (10) <<  hTrend[iName]->GetBinError(iCut+1) << " / " << numEntriesFirstStep_reduced_samples.at(iName);
   cout << " ]";
  }
  cout << endl;
 }
 
 //PG latex-like output
 //PG --- --- --- --- --- --- --- ---
 
 
 cout << endl;
 cout << "LATEX " << " \\hline\n" ;
 cout << "LATEX " << setw (12) << "sample";
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++)
  {
    cout << " & " << setw (10) << vCutHR.at(iCut).c_str() 
         << " (" << setw (10) <<  "$\\varepsilon$"
         << " )";
  }
 cout << " \\\\" << endl;
 cout << "LATEX " << " \\hline\n" ;
 
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++)
   {
     cout << "LATEX " << setw (12) << reduced_name_samples.at(iName) ;
     for (unsigned int iCut = 0; iCut<vCut.size(); iCut++)
      {
        cout << " & " << setw (10) << setprecision (2) <<  hTrend[iName]->GetBinContent(iCut+1) / numEntriesFirstStep_reduced_samples.at(iName)
             << " (" << setw (10) << setprecision (2) <<  hTrend[iName]->GetBinError(iCut+1) / numEntriesFirstStep_reduced_samples.at(iName)
             << " )";
      }
     cout << " \\\\" << endl;
   }
 cout << "LATEX " << " \\hline\n" ;
 
 cout << endl;
 cout << " *********************************** " << endl;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cout << " | " << setw (10) << reduced_name_samples.at(iName) ;
  cout << " [" << setw (10) <<  "err";
  cout << " ]";
 }
 cout << endl;
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
   cout << " | " << yellow << setw (10) <<  hTrend[iName]->GetBinContent(iCut+1) / numEntriesFirstStep_reduced_samples.at(iName);
   cout << normal << " [" << setw (10) <<  hTrend[iName]->GetBinError(iCut+1) / numEntriesFirstStep_reduced_samples.at(iName);
   cout << " ]";
  }
  cout << endl;
 }
 
 
 
 
 
 
 
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout << " ****************************************************************** " << endl;
 cout << " ****************************************************************** " << endl;
 cout << " *********************** for Lands datacard *********************** " << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 
 
 
 string mass = "160";
 try {
  mass = gConfigParser -> readStringOption("Input::mass");
 }
 catch (char const* exceptionString){
  cerr << " exception = " << exceptionString << endl;
 }
 cout << ">>>>> input::mass  " << mass << endl;  
 
 ofstream myfile;
 string nameOutDataCard = "dataCard." + mass + ".txt";
 
 ///==== output - txt file name ====
 try {
  nameOutDataCard = gConfigParser -> readStringOption("Output::DataCard");
 }
 catch (char const* exceptionString){
  cerr << " exception = " << exceptionString << endl;
 }
 
 myfile.open (nameOutDataCard.c_str());
 cout << "Writing to: " << nameOutDataCard << endl;
 cout << endl;
 
 
 
 myfile << "Limit" << endl;
 myfile << "imax 1 number of channels" << endl;
 myfile << "jmax "<< (reduced_name_samples.size() - 2) << " number of background" << endl;
// //  myfile << "jmax "<< (reduced_name_samples.size() - SignalName.size() - 1) << " number of background" << endl;
 //---- -1 to take into account "DATA"
 myfile << "kmax "<< 15 << " number of nuisance parameters" << endl;
 
 double totalSig = 0;
 double totalBkg = 0;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  if (iName != numDATA) {
   bool isSig = false;
   for (vector<string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
    if (reduced_name_samples.at(iName) == *itSig) isSig = true;
   }
   if (isSig) {
    totalSig += hTrend[iName]->GetBinContent(vCut.size());   ///---- last cut!
   }
   else {
    totalBkg += hTrend[iName]->GetBinContent(vCut.size());   ///---- last cut!
   }
  }
 }
 myfile << "-------------------------------------------------" << endl;
 myfile << "bin             ll2j   " << endl;
 //  myfile << "Observation   " << ((Discovery==1) ? (int) (totalBkg+totalSig) : (int) (totalBkg)) << endl;
 myfile << "observation   " << hTrend[numDATA]->GetBinContent(vCut.size()) << endl;
 //# 1 = discovery, 0 = exclusion
 myfile << "-------------------------------------------------" << endl;
 
 
 myfile << setw (22) << "bin                ";
//  myfile << setw (12) << " bin  " << setw (10) << "ll2j" << "  ";
//  for (int i=0; i < (reduced_name_samples.size() - SignalName.size() - 1); i++){
//   myfile << setw (10) << "ll2j" << "  ";
//  }
 for (int i=0; i < (reduced_name_samples.size() -1 ); i++){
  myfile << setw (10) << "ll2j" << "  ";
 }
 myfile << endl;
 
//  myfile << setw (12) << " process  " << setw (10) << "sig" << "  ";
//  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
//   if (iName != numDATA) {
//    bool isSig = false;
//    for (vector<string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
//     if (reduced_name_samples.at(iName) == *itSig) isSig = true;
//    }
//    if (!isSig) {
//     myfile << setw (10) << reduced_name_samples.at(iName) << "  ";
//    }
//   }
//  }
//  myfile << endl;

 myfile << setw (22) << "process                ";
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  if (iName != numDATA) {
   myfile << setw (10) << reduced_name_samples.at(iName) << "  ";
  }
 }
 myfile << endl;

 int cSig = -1;
 int cBkg = 1;
 myfile << setw (22) << "process                ";
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  if (iName != numDATA) {
   bool isSig = false;
   for (vector<string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
    if (reduced_name_samples.at(iName) == *itSig) isSig = true;
   }
   if (!isSig) {
    myfile << setw (10) << cBkg << "  ";
    cBkg++;
   }
   else {
    myfile << setw (10) << cSig << "  ";
    cSig++;
   }
  }
 }
 myfile << endl;
 
//  myfile << setw (12) << " process  " << setw (10) << 0 << "  ";
//  for (int i=0; i < (reduced_name_samples.size() - SignalName.size() - 1); i++){
//   myfile << setw (10) << i+1 << "  ";
//  }
//  myfile << endl;
 
//  cout << " numDATA = " << numDATA << " reduced_name_samples.size() = " << reduced_name_samples.size() << endl;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
//   cout << " name[" << iName << "] = " << reduced_name_samples.at(iName) << endl;
 }
 myfile << setw (23) << "rate                 " ;
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  if (iName != numDATA) {
//    cout << " iName = " << iName << " -- > " <<  hTrend[iName]->GetBinContent(vCut.size())  << endl;
//    bool isSig = false;
//    for (vector<string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
//     if (reduced_name_samples.at(iName) == *itSig) isSig = true;
//    }
//    if (!isSig) {
    myfile << setw (10) << hTrend[iName]->GetBinContent(vCut.size()) << "  ";
//    }
  }
 }
 myfile << endl;
 
 
 
 myfile << "-------------------------------------------------" << endl;
 
 myfile << "CMS_eff_e                    lnN       1.020    1.020    1.020      1.020     1.020      -         1.020       -      " << endl; //               electron efficiency      " << endl;
 myfile << "CMS_eff_m                    lnN       1.040    1.040    1.040      1.040     1.040      -         1.040       -      " << endl; //               muon efficiency          " << endl;
 
 myfile << "PU                           lnN       1.03     1.03       -        1.04      1.04       -         1.04        -      " << endl; //               Pile Up +/- 1" << endl;
 
 myfile << "CMS_p_scale_j                lnN       1.05     1.05       -        1.10      1.10       -         1.10        -      " << endl; //               JES" << endl;
 myfile << "CMS_p_scale_m                lnN       1.002    1.002      -          -         -        -            -        -      " << endl; //               Muon momentum" << endl;
 myfile << "CMS_p_scale_e                lnN       1.002    1.002      -          -         -        -            -        -      " << endl; //               Electron scale" << endl;
 myfile << "MC_statistics                lnN         -      1.03       -        1.35      1.10       -         2.00        -      " << endl; //               MET +/- 10%" << endl;
 
 myfile << "QCDscale_ggH                 lnN         -      1.160      -          -         -        -            -        -      " << endl; //               Theory on Higgs" << endl;
 myfile << "QCDscale_ggH1in              lnN         -      1.160      -          -         -        -            -        -      " << endl; //               Theory on Higgs" << endl;
 myfile << "QCDscale_ggVV                lnN         -        -        -        1.160       -        -            -        -      " << endl; //               Theory on Higgs" << endl;
 
 myfile << "lumi                         lnN       1.060    1.060    1.060      1.060    1.060       -        1.060        -      " << endl; //              Luminosity     " << endl;
 myfile << "pdf_gg                       lnN         -      1.080      -        1.080       -        -            -        -      " << endl; //              pdfgg        " << endl;
 myfile << "pdf_qqbar                    lnN       1.050      -        -          -       1.030      -        1.060        -      " << endl; //              pdfqq        " << endl;
 
 //  myfile << "pdf_gg                       lnN    1.040    1.040     1.040      -         -                     -         Luminosity     " << endl;
 //  myfile << "pdf_qqbar                    lnN    1.01    2.00    2.00    2.00     2.00     -               -                  MC statistics" << endl;
 myfile << "CMS_ww_Top2j                 lnN         -        -        -          -         -      1.1            -       -     " << endl; //              TTbar data driven" << endl;
 myfile << "CMS_ww_DY2j                  lnN         -        -        -          -         -        -            -      1.1     " << endl; //              DY data driven   " << endl;
 myfile << endl; 
 
 myfile.close(); 
 
 
 
 
 ///==== plot on the screen ====
 
// //  cout << "Limit" << endl;
// //  cout << "imax 1 number of channels" << endl;
// //  cout << "jmax "<< (reduced_name_samples.size() - SignalName.size() - 1) << " number of background" << endl;
// //  //---- -1 to take into account "DATA"
// //  cout << "kmax "<< 0 << " number of nuisance parameters" << endl;
// //  
// //  totalSig = 0;
// //  totalBkg = 0;
// //  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
// //   if (iName != numDATA) {
// //    bool isSig = false;
// //    for (vector<string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
// //     if (reduced_name_samples.at(iName) == *itSig) isSig = true;
// //    }
// //    if (isSig) {
// //     totalSig += hTrend[iName]->GetBinContent(vCut.size());   ///---- last cut!
// //    }
// //    else {
// //     totalBkg += hTrend[iName]->GetBinContent(vCut.size());   ///---- last cut!
// //    }
// //   }
// //  }
// //  cout << "-------------------------------------------------" << endl;
// // //  cout << "Observation   " << ((Discovery==1) ? (int) (totalBkg+totalSig) : (int) (totalBkg)) << endl;
// //  cout << "Observation   " << hTrend[numDATA]->GetBinContent(vCut.size()) << endl;
// //  //# 1 = discovery, 0 = exclusion
// //  cout << "-------------------------------------------------" << endl;
// //  
// //  
// //  cout << setw (12) << " bin  " << setw (10) << 1 << "  ";
// //  for (int i=0; i < (reduced_name_samples.size() - SignalName.size() - 1); i++){
// //   cout << setw (10) << 1 << "  ";
// //  }
// //  cout << endl;
// //  
// //  cout << setw (12) << " process  " << setw (10) << "sig" << "  ";
// //  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
// //   if (iName != numDATA) {
// //    bool isSig = false;
// //    for (vector<string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
// //     if (reduced_name_samples.at(iName) == *itSig) isSig = true;
// //    }
// //    if (!isSig) {
// //     cout << setw (10) << reduced_name_samples.at(iName) << "  ";
// //    }
// //   }
// //  }
// //  cout << endl;
// //  
// //  cout << setw (12) << " process  " << setw (10) << 0 << "  ";
// //  for (int i=0; i < (reduced_name_samples.size() - SignalName.size() - 1); i++){
// //   cout << setw (10) << i+1 << "  ";
// //  }
// //  cout << endl;
// //  
// //  cout << setw (12) << " rate  " << setw (10) << totalSig << "  ";
// //  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
// //   if (iName != numDATA) {
// //    bool isSig = false;
// //    for (vector<string>::const_iterator itSig = SignalName.begin(); itSig != SignalName.end(); itSig++){
// //     if (reduced_name_samples.at(iName) == *itSig) isSig = true;
// //    }
// //    if (!isSig) {
// //     cout << setw (10) << hTrend[iName]->GetBinContent(vCut.size()) << "  ";
// //    }
// //   }
// //  }
// //  cout << endl;
// //  
// //  
// //  cout << "-------------------------------------------------" << endl;
// //  
 
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 
 
 
 
 
 
 ///==== draw trend vs cut (begin)
 cTrend->cd();
 DrawStack(hsTrend,1,LumiSyst);
 hTrend[numDATA] -> Draw("EsameP");
 gPad->SetLogy();
 gPad->SetGrid();
 leg->Draw();
 latex->Draw();
  
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
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
 
 
 
 cerr << " ******************************************* end *******************************************" << endl;
 end = clock();
 cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << endl;  
 
 
 
 ///==== save output ====
 outFile.cd();
 cTrend -> Write();
 
 outFile.mkdir("Trend");
 outFile.cd("Trend");
 for (unsigned int iCut = 0; iCut<vCut.size(); iCut++){
  cTrendPie[iCut] -> Write();
 }
 cTrendPieAll -> Write();
 
 
 outFile.cd();
 outFile.mkdir("PU");
 outFile.cd("PU");
 
 if (!doWeightFromFile) { 
  hPUMC     -> Write();
  hPUDATA   -> Write();
  hPUWeight -> Write();
 }
 
 outFile.cd();
 outFile.mkdir("Sample");
 outFile.cd("Sample");
 
 for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
  cTrendSample[iName] ->Write();
 }  
 
 leg->Write();

}





