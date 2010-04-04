#include "treeReader.h"
#include "hFactory.h"
#include "hFunctions.h"
#include "stdHisto.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"
#include "Math/GenVector/VectorUtil.h"
#include "TRandom3.h"
#include <time.h>
#include <sstream>
#include "qqHWWlnulnuUtils.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif

int GetNumList(std::vector<int> &list){
 int result = 0;
 for (int it = 0; it<list.size(); it++) result += list.at(it);
 return result;
}

int main(int argc, char** argv)
{ 
 //Check if all nedeed arguments to parse are there                                                                                                                               
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }
 
 // Parse the config file                                                                                                                                                          
 parseConfigFile (argv[1]) ;
 
 std::string treeName  = gConfigParser -> readStringOption("Input::treeName");
 std::string inputFile = gConfigParser -> readStringOption("Input::inputFile");
 double inputXSection  = gConfigParser -> readDoubleOption("Input::inputXSection");
 
 int entryMAX = gConfigParser -> readIntOption("Input::entryMAX");
 int entryMIN = gConfigParser -> readIntOption("Input::entryMIN");
 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 
 std::cout << ">>>>> input::entryMIN  " << entryMIN  << std::endl;  
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 // Open ntple
 TChain* chain = new TChain(treeName.c_str());
 chain->Add(inputFile.c_str());
 treeReader reader((TTree*)(chain));
 
 ///---- Efficiency preselections ---- 
 
 std::string treeNameLeptonFilter      = gConfigParser -> readStringOption("Input::treeNameLeptonFilter");
 std::string treeNameJetCounterFilter  = gConfigParser -> readStringOption("Input::treeNameJetCounterFilter");
 
 std::cout << ">>>>> Input::inputFile                 " << inputFile  << std::endl;  
 std::cout << ">>>>> Input::treeNameLeptonFilter      " << treeNameLeptonFilter  << std::endl;  
 std::cout << ">>>>> Input::treeNameJetCounterFilter  " << treeNameJetCounterFilter  << std::endl;  
 
 // Open ntples
 TFile File(inputFile.c_str()) ;
 TH1F* hLeptonFilterTotal = (TH1F*) File.Get(TString(treeNameLeptonFilter.c_str()) + "/totalEvents");
 TH1F* hLeptonFilterPassed = (TH1F*) File.Get(TString(treeNameLeptonFilter.c_str()) + "/passedEvents"); 
 
 TH1F* hJetCounterFilterTotal = (TH1F*) File.Get(TString(treeNameJetCounterFilter.c_str()) + "/totalEvents");
 TH1F* hJetCounterFilterPassed = (TH1F*) File.Get(TString(treeNameJetCounterFilter.c_str()) + "/passedEvents"); 
 
 ///----------------------
 ///---- LeptonFilter ----
 
 int nLeptonFilterTotal = hLeptonFilterTotal->GetEntries();
 int nLeptonFilterPassed = hLeptonFilterPassed->GetEntries();
 double lepton_efficiency = static_cast<double>(nLeptonFilterPassed) / static_cast<double>(nLeptonFilterTotal);
 std::cout << " Lepton Filter = " << nLeptonFilterPassed << " / " << nLeptonFilterTotal << " = " << static_cast<double>(nLeptonFilterPassed) / static_cast<double>(nLeptonFilterTotal) << std::endl;
 
 
 ///--------------------------
 ///---- JetCounterFilter ----
 
 int nJetCounterFilterTotal = hJetCounterFilterTotal->GetEntries();
 int nJetCounterFilterPassed = hJetCounterFilterPassed->GetEntries();
 double jet_efficiency = static_cast<double>(nJetCounterFilterPassed) / static_cast<double>(nJetCounterFilterTotal);
 std::cout << " JetCounter Filter = " << nJetCounterFilterPassed << " / " << nJetCounterFilterTotal << " = " << static_cast<double>(nJetCounterFilterPassed) / static_cast<double>(nJetCounterFilterTotal) << std::endl;
 
 
 ///-----------------------------------
 ///---- additional channel filter ----
 
 double eff_Channel_Filter = 1.;
 if ((TH1F*) File.Get(TString("eff_ee"))) {
  TH1F* hChannelFilter = (TH1F*) File.Get(TString("eff_ee"));
  eff_Channel_Filter = hChannelFilter->GetBinContent(1);
 }
 if ((TH1F*) File.Get(TString("eff_emu"))) {
  TH1F* hChannelFilter = (TH1F*) File.Get(TString("eff_emu"));
  eff_Channel_Filter = hChannelFilter->GetBinContent(1);
 }
 if ((TH1F*) File.Get(TString("eff_mumu"))) {
  TH1F* hChannelFilter = (TH1F*) File.Get(TString("eff_mumu"));
  eff_Channel_Filter = hChannelFilter->GetBinContent(1);
 }
 if ((TH1F*) File.Get(TString("eff_other"))) {
  TH1F* hChannelFilter = (TH1F*) File.Get(TString("eff_other"));
  eff_Channel_Filter = hChannelFilter->GetBinContent(1);
 }
 
 ///----------------------
 ///---- Preselection ----
 
 double preselection_efficiency = lepton_efficiency * jet_efficiency * eff_Channel_Filter;
 std::cout << " Preselection efficiency = " << preselection_efficiency << std::endl;
 
 
 
 ///-------------------
 ///---- selection ----
 //  std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 //  std::cout << ">>>>> Output::outFileName  " << OutFileName  << std::endl;  
 std::string OutFileNameEfficiencies    = gConfigParser -> readStringOption("Output::OutFileNameEfficiencies");
 std::cout << ">>>>> Output::OutFileNameEfficiencies  " << OutFileNameEfficiencies  << std::endl;  
 
 TFile outFile(OutFileNameEfficiencies.c_str(),"RECREATE");
 
 int nStep = 10; ///==== number of steps in the analysis
 TH1F* events = new TH1F("events", "events", nStep+1, 0., 1.*(nStep+1));
 std::map<int, int> stepEvents;
 std::map<int, std::string> stepName;
 
 outFile.mkdir("histos");
 outFile.cd("histos");
 
 stdHisto* stdHistograms = new stdHisto(nStep, "no",&reader);
 stdHistograms -> Add1("jets", nStep);
 stdHistograms -> Add1("muons", nStep);
 stdHistograms -> Add1Float("muIso", nStep,2000,0,2);
 stdHistograms -> Add1("electrons", nStep);
 stdHistograms -> Add1Float("eleIso", nStep,2000,0,2);
 stdHistograms -> Add1("met", nStep);
 stdHistograms -> Add2("JJ", nStep);
 
 outFile.cd();
 
 double analysisEfficiency; 
 double XSection = inputXSection;
 int numEntriesBefore;
 
 TTree outTreeSelections("outTreeSelections","outTreeSelections");
 outTreeSelections.Branch("XSection",&XSection,"XSection/D");
 outTreeSelections.Branch("lepton_efficiency",&lepton_efficiency,"lepton_efficiency/D");
 outTreeSelections.Branch("jet_efficiency",&jet_efficiency,"jet_efficiency/D");
 outTreeSelections.Branch("preselection_efficiency",&preselection_efficiency,"preselection_efficiency/D");
 outTreeSelections.Branch("eff_Channel_Filter",&eff_Channel_Filter,"eff_Channel_Filter/D");
 outTreeSelections.Branch("numEntriesBefore",&numEntriesBefore,"numEntriesBefore/I");
 outTreeSelections.Branch("analysisEfficiency",&analysisEfficiency,"analysisEfficiency/D");
 
 TTree outTree("outTree","outTree");
 
 double pT_RECO_q1;
 double pT_RECO_q2;
 double eta_RECO_q1;
 double eta_RECO_q2;
 double eta_RECO_q1_eta_RECO_q2;
 double Deta_RECO_q12;
 double Mjj;
 int CJV_20;
 int CJV_30;
 int AnalysisStep;
 
 outTree.Branch("pT_RECO_q1",&pT_RECO_q1,"pT_RECO_q1/D");
 outTree.Branch("pT_RECO_q2",&pT_RECO_q2,"pT_RECO_q2/D");
 outTree.Branch("eta_RECO_q1",&eta_RECO_q1,"eta_RECO_q1/D");
 outTree.Branch("eta_RECO_q2",&eta_RECO_q2,"eta_RECO_q2/D");
 outTree.Branch("eta_RECO_q1_eta_RECO_q2",&eta_RECO_q1_eta_RECO_q2,"eta_RECO_q1_eta_RECO_q2/D");
 outTree.Branch("Deta_RECO_q12",&Deta_RECO_q12,"Deta_RECO_q12/D");
 outTree.Branch("Mjj",&Mjj,"Mjj/D");
 outTree.Branch("AnalysisStep",&AnalysisStep,"AnalysisStep/I");
 outTree.Branch("CJV_20",&CJV_20,"CJV_20/I");
 outTree.Branch("CJV_30",&CJV_30,"CJV_30/I");
 
 double start, end;
 
 if (entryMAX == -1) entryMAX = reader.GetEntries();
 else if (reader.GetEntries() < entryMAX) entryMAX = reader.GetEntries();
 numEntriesBefore = entryMAX - entryMIN;
 
 std::cout << ">>>>> analysis::entryMIN " << entryMIN << " ==> entryMAX " << entryMAX << std::endl;   
 
 int step = 0;
 start = clock();
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent) {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
  
  ///==== define variables ==== 
  std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
  std::vector<ROOT::Math::XYZTVector>* muons = reader.Get4V("muons");
  std::vector<ROOT::Math::XYZTVector>* electrons = reader.Get4V("electrons");
  
  ///*******************************
  ///**** STEP 0 - Preselection ****
  step = 0;
  stepName[step] = "preselection";
  stepEvents[step] += 1;
  
  stdHistograms -> Fill1("muons","muons",step,0);
  stdHistograms -> Fill1("electrons","electrons",step,0);
  stdHistograms -> Fill1("jets","jets",step,0);
  stdHistograms -> Fill1("met","met",step,0); 
  
  
  ///==== Jet cleaning ====
  std::vector<ROOT::Math::XYZTVector> electrons_jetCleaning;   
  // build the collection of electros for jet cleaning
  for(unsigned int eleIt = 0; eleIt < (reader.Get4V("electrons")->size()); ++eleIt)
  {
   if( reader.Get4V("electrons")->at(eleIt).pt() < 5. ) continue;
   if( (reader.GetFloat("electrons_tkIso")->at(eleIt)) / reader.Get4V("electrons")->at(eleIt).pt() > 0.5 ) continue;
   if( (reader.GetFloat("electrons_IdRobustLoose")->at(eleIt)) < 1. ) continue; 
   electrons_jetCleaning.push_back( reader.Get4V("electrons")->at(eleIt) );
  }
  
  int nJets = jets->size();
  std::vector<int> whitelistJet;
  std::vector<int> blacklistJet;
  for (int iJet = 0; iJet < nJets; iJet++){
   bool skipJet = false;
   if (jets->at(iJet).Et() < 10.0) skipJet = true;
   for(unsigned int eleIt = 0; eleIt < electrons_jetCleaning.size(); eleIt++) {
    ROOT::Math::XYZTVector ele = electrons_jetCleaning.at(eleIt);
    if (ROOT::Math::VectorUtil::DeltaR(jets->at(iJet),ele) < 0.3 ) skipJet = true;
   }
   if (skipJet) {
    whitelistJet.push_back(0); ///---- reject
    blacklistJet.push_back(iJet); ///---- reject ///== black list is in a different format
   }
   else {
    whitelistJet.push_back(1); ///---- select
   }
  }
  
  ///*******************************
  ///**** STEP 1 - Jet cleaning ****
  if (GetNumList(whitelistJet) < 2) continue; ///==== at least 2 jets "isolated"
   
  step = 1;
  stepName[step] = "Jet cleaning";
  stepEvents[step] += 1;
  
  stdHistograms -> Fill1("muons","muons",step,0);
  stdHistograms -> Fill1("electrons","electrons",step,0);
  stdHistograms -> Fill1("jets","jets",step,&whitelistJet);
  stdHistograms -> Fill1("met","met",step,0);  

  
  ///*************************
  ///**** STEP 2 - Jet ID ****
  
  step = 2;
  stepName[step] = "Jet ID";
  stepEvents[step] += 1;
  
  std::vector<int> itSelJet;
  double maxPt_selected = SelectJets(itSelJet,*jets,"maxSumPt",-1.,&blacklistJet);

//   std::cerr << "============= " << jets->size() << " " << GetNumList(whitelistJet) << " => " << itSelJet.at(0) << " " << itSelJet.at(1) << " ==> " << maxPt_selected << std::endl;
//   std::cerr << "===================== ";
//   for (int i=0; i< jets->size(); i++) {
//    bool skipJet1 = false;
//    for(unsigned int kk = 0; kk < blacklistJet.size(); ++kk)
//     if(blacklistJet.at(kk) == static_cast<int>(i)) skipJet1 = true;
//      if(!skipJet1) {
//       std::cerr << " " << jets->at(i).Pt() << " " ;
//      }
//   }
//   std::cerr << std::endl;
//   std::cerr << "=============" << std::endl;
  
  
  int q1 = itSelJet.at(0);
  int q2 = itSelJet.at(1);
  ///---- check Pt order ----
  if (jets->at(q1).Pt() < jets->at(q2).Pt()) {
   int tempq = q1;
   q1 = q2;
   q2 = tempq;
  }
  
  ///---- update white/black list jets ----
  blacklistJet.clear();
  for (int iList = 0; iList < whitelistJet.size(); iList++){
   if (q1 == iList || q2 == iList) {
    whitelistJet.at(iList) = 1;
   }
   else {
    whitelistJet.at(iList) = 0;
    blacklistJet.push_back(iList);
   }
  }
   
   stdHistograms -> Fill1("muons","muons",step,0);
   stdHistograms -> Fill1("electrons","electrons",step,0);
   stdHistograms -> Fill1("jets","jets",step,&whitelistJet);
   stdHistograms -> Fill1("met","met",step,0);  
   stdHistograms -> Fill2(jets->at(q1),jets->at(q2), "JJ", step);
   
   pT_RECO_q1 = jets->at(q1).Pt();
   pT_RECO_q2 = jets->at(q2).Pt();
   eta_RECO_q1 = jets->at(q1).Eta();
   eta_RECO_q2 = jets->at(q2).Eta();
   eta_RECO_q1_eta_RECO_q2 = eta_RECO_q1 * eta_RECO_q2;
   Deta_RECO_q12 = fabs(eta_RECO_q1-eta_RECO_q2); 
   Mjj = (jets->at(q1) + jets->at(q2)).M();
   CJV_20 = getCJV(*jets,q1,q2,20.,&blacklistJet);
   CJV_30 = getCJV(*jets,q1,q2,30.,&blacklistJet);
   
   AnalysisStep = step;
   outTree.Fill();
   
  
  ///*******************************
  ///**** STEP 3 - Jet Selections ****
  
  ///==== ... to be continued in next program ... ====
  ///=================================================
  
 }
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 
 //  outFile.Write();   
 
 
 
 
 ///==== save additional information ====
 //  TFile* outputRootFile = new TFile(OutFileNameEfficiencies.c_str(), "recreate");
 //  outputRootFile -> cd();
 for(step = 0; step < nStep; ++step)
 {
  events -> SetBinContent(step+2, stepEvents[step]);
  events -> GetXaxis() -> SetBinLabel(step+2, stepName[step].c_str());
  
  if (step != 0){
   analysisEfficiency = static_cast<double>(stepEvents[step]) / static_cast<double>(stepEvents[0]); ///---- fractio => efficiency
   outTreeSelections.Fill();
  }
 } 
 events -> Write(); 
 outFile.Write();
 
 delete stdHistograms;
 
 
 
}


