#include "treeReader.h"
#include "hFactory.h"
#include "hFunctions.h"
#include "stdHisto.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"

#include "TTBarUtils.h"

#include "JetCalibrator.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"
#include "Math/GenVector/VectorUtil.h"
#include "TRandom3.h"
#include <time.h>
#include <sstream>
#include "ntpleUtils.h"
#include "stdHisto.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif

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
 if ((TH1F*) File.Get(TString("eff_e"))) {
  TH1F* hChannelFilter = (TH1F*) File.Get(TString("eff_e"));
  eff_Channel_Filter = hChannelFilter->GetBinContent(1);
 }
 if ((TH1F*) File.Get(TString("eff_mu"))) {
  TH1F* hChannelFilter = (TH1F*) File.Get(TString("eff_mu"));
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
 
 
 //  hFactory factory (OutFileName.c_str(), true) ;
 
 int nStep = 10; ///==== number of steps in the analysis
 TH1F* events = new TH1F("events", "events", nStep, 0., 1.*nStep);
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
 stdHistograms -> Add1Float("bTagging", nStep,1000,-100,30);
 stdHistograms -> Add1Float("MVAResponse", nStep,1000,-2,2); 
 stdHistograms -> Add2("WJJ", nStep);
 
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
 
 TTree outTreeJets("outTreeJets","outTreeJets");
 
 int stepAnalysis;
 ROOT::Math::XYZTVector* q_1;
 ROOT::Math::XYZTVector* q_2;
 ROOT::Math::XYZTVector* b_1;
 ROOT::Math::XYZTVector* b_2;
 outTreeJets.Branch("stepAnalysis",&stepAnalysis,"stepAnalysis/I");
 outTreeJets.Branch("q_1","ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >",&q_1);
 outTreeJets.Branch("q_2","ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >",&q_2);
 outTreeJets.Branch("b_1","ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >",&b_1);
 outTreeJets.Branch("b_2","ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >",&b_2);
 
 
 
 
 double TMVA_value;
 int MVACombination;
 
 TMVA::Reader *TMVAreader = new TMVA::Reader( "!Color:!Silent" );
 
 Float_t input_variables[1000];
 
 TMVAreader->AddVariable("pT_RECO_q1",&input_variables[0]);
 TMVAreader->AddVariable("pT_RECO_q2",&input_variables[1]);
 TMVAreader->AddVariable("pT_RECO_b1",&input_variables[2]);
 TMVAreader->AddVariable("pT_RECO_b2",&input_variables[3]);
 TMVAreader->AddVariable("DR_RECO_qq",&input_variables[4]);
 TMVAreader->AddVariable("DR_RECO_qb",&input_variables[5]);
 TMVAreader->AddVariable("DR_RECO_bb",&input_variables[6]);
 TMVAreader->AddVariable("jets_trackCountingHighEffBJetTags_RECO_q1",&input_variables[7]);
 TMVAreader->AddVariable("jets_trackCountingHighEffBJetTags_RECO_b1",&input_variables[8]);
 TMVAreader->AddVariable("jets_trackCountingHighEffBJetTags_RECO_q2",&input_variables[9]);
 TMVAreader->AddVariable("jets_trackCountingHighEffBJetTags_RECO_b2",&input_variables[10]);
 
 std::string stdstrMethod = gConfigParser -> readStringOption("Selector::Method");
 std::cout << ">>>>> Selector::Method  " << stdstrMethod  << std::endl;  
 std::string additionalInputFileName = gConfigParser -> readStringOption("Selector::additionalInputFileName");
 std::cout << ">>>>> Selector::additionalInputFileName  " << additionalInputFileName  << std::endl;  
 
 TString dir    = "weights/";
 TString prefix = "TMVAnalysis";
 TString methodName = stdstrMethod + " method";
 TString weightfile = Form(additionalInputFileName.c_str());
 
 
 TMVAreader->BookMVA( methodName, weightfile );
 
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
  std::vector<ROOT::Math::XYZTVector>* muons = reader.Get4V("muons");
  std::vector<ROOT::Math::XYZTVector>* electrons = reader.Get4V("electrons");
  std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
  std::vector<float>* jets_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags");
  std::vector<float>* jets_trackCountingHighEffBJetTagsDR = reader.GetFloat("jets_trackCountingHighEffBJetTagsDR");
  std::vector<float>* jets_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags");
  std::vector<float>* jets_simpleSecondaryVertexBJetTags = reader.GetFloat("jets_simpleSecondaryVertexBJetTags");
  std::vector<float>* jets_combinedSecondaryVertexBJetTags = reader.GetFloat("jets_combinedSecondaryVertexBJetTags");
  std::vector<float>* jets_combinedSecondaryVertexMVABJetTags = reader.GetFloat("jets_combinedSecondaryVertexMVABJetTags");
  
  std::vector<float>* muons_tkIsoR03  = reader.GetFloat("muons_tkIsoR03");
  std::vector<float>* muons_emIsoR03  = reader.GetFloat("muons_emIsoR03");
  std::vector<float>* muons_hadIsoR03 = reader.GetFloat("muons_hadIsoR03");
  
  std::vector<float>* electrons_tkIso    = reader.GetFloat("electrons_tkIso");
  std::vector<float>* electrons_emIso    = reader.GetFloat("electrons_emIso");
  std::vector<float>* electrons_hadIso_1 = reader.GetFloat("electrons_hadIso_1");
  std::vector<float>* electrons_hadIso_2 = reader.GetFloat("electrons_hadIso_2");
  std::vector<float>* electrons_IdLoose       = reader.GetFloat("electrons_IdLoose");
  std::vector<float>* electrons_IdTight       = reader.GetFloat("electrons_IdTight");
  std::vector<float>* electrons_IdRobustLoose = reader.GetFloat("electrons_IdRobustLoose");
  std::vector<float>* electrons_IdRobustTight = reader.GetFloat("electrons_IdRobustTight");
  std::vector<float>* electrons_track_d0 = reader.GetFloat("electrons_track_d0");
  
  std::vector<ROOT::Math::XYZTVector>* met    = reader.Get4V("met");
  
  
  
  
  ///*******************************
  ///**** STEP 1 - Preselection ****
  step = 1;
  stepName[step] = "preselection";
  stepEvents[step] += 1;
  
  stdHistograms -> Fill1("muons","muons",step,0);
  stdHistograms -> Fill1("electrons","electrons",step,0);
  stdHistograms -> Fill1("jets","jets",step,0);
  stdHistograms -> Fill1("met","met",step,0); 
  
  ///**********************************
  ///**** STEP 2 - at least 4 jets ****
  int nJets = jets->size();
  if ( nJets >= 4 ){
   step = 2;
   stepName[step] = "4 jets";
   stepEvents[step] += 1;
   
   stdHistograms -> Fill1("muons","muons",step,0);
   stdHistograms -> Fill1("electrons","electrons",step,0);
   stdHistograms -> Fill1("jets","jets",step,0);
   stdHistograms -> Fill1("met","met",step,0);
   
   ///***************************************
   ///**** STEP 3 - loose jets selection ****
   
   std::vector<int> whitelistJet;
   for (int iJet = 0; iJet < nJets; iJet++){
    if (fabs(jets->at(iJet).Eta()) < 5.0 && jets->at(iJet).Pt() > 10) { ///==== selections on jets
     //if (fabs(jets->at(iJet).Eta()) < 2.4 && jets->at(iJet).Pt() > 10) { ///==== selections on jets
     whitelistJet.push_back(1);
    }
    else {
     whitelistJet.push_back(0);
    }
   }
   int nJets_preferred = getNumJets(whitelistJet);
   if ( nJets_preferred >= 4 ){
    
    step = 3;
    stepName[step] = "4 jets loose selections";
    stepEvents[step] += 1;
    
    stdHistograms -> Fill1("muons","muons",step,0);
    stdHistograms -> Fill1("electrons","electrons",step,0);
    stdHistograms -> Fill1("jets","jets",step,&whitelistJet);
    stdHistograms -> Fill1("met","met",step,0);
    
    
    ///************************************
    ///**** STEP 4 - lepton selections ****
    step = 4;
    stepName[step] = "1 lepton";
    
    std::string method = "maxPt";
    std::vector<int>* blacklist = 0;
    int numMuonsSurvived = 0;  
    int nSelMu = SelectMuonTTBar(*muons,*muons_tkIsoR03,*muons_emIsoR03,*muons_hadIsoR03,method,20,2.1,0.05,numMuonsSurvived,blacklist);
    
    int numElectronsSurvived = 0;
    int nSelEle = SelectElectronTTBar(*electrons,*electrons_tkIso,*electrons_emIso,*electrons_hadIso_1,*electrons_IdRobustTight,*electrons_track_d0,method,30,2.5,0.1,0.2,numElectronsSurvived,blacklist);
    
    
    if ( (numMuonsSurvived == 1) ^ (numElectronsSurvived == 1)){///==== number of electrons == 1 xor number of muons == 1 ====
     std::vector<int>* whitelistElectron = 0;
     std::vector<int>* whitelistMuon = 0;
     std::vector<int>* blacklistElectron = 0;
     std::vector<int>* blacklistMuon = 0;
     
     int WhichChannel = -1;
     
     //      std::cerr << " step " << step << " => " << stepName[step] << std::endl;
     
     if (numElectronsSurvived == 1 && numMuonsSurvived == 0){ ///==== electron channel ==== no muons!
      whitelistElectron = new std::vector<int>;
      for (int iele = 0; iele< electrons->size(); iele++){
       if (iele != nSelEle) whitelistElectron->push_back(0);
       else whitelistElectron->push_back(1);
      }
      blacklistElectron = new std::vector<int>;
      blacklistElectron->push_back(nSelEle);
      
      int numElectronsSurvived_more = 0;
      int temp_moreEle = SelectElectronTTBar(*electrons,*electrons_tkIso,*electrons_emIso,*electrons_hadIso_1,*electrons_IdTight,*electrons_track_d0,method,20,2.5,0.25,0.2,numElectronsSurvived_more,blacklistElectron);
      if (numElectronsSurvived_more == 0) {///==== no other electrons! -> Z Veto
       WhichChannel = 0;
      }
      stdHistograms -> Fill1("electrons","electrons",step,whitelistElectron);
      stdHistograms -> Fill1Float("eleIso",(electrons_tkIso->at(nSelEle) + electrons_emIso->at(nSelEle) + electrons_hadIso_1->at(nSelEle)) / (electrons->at(nSelEle).Pt()),step);
      delete blacklistElectron;
     }
     
     if (numElectronsSurvived == 0 && numMuonsSurvived == 1){ ///==== muon channel ==== no electrons!
      WhichChannel = 1;
      std::vector<int>* whitelistMuon = new std::vector<int>;
      for (int imu = 0; imu< muons->size(); imu++){
       if (imu != nSelMu) whitelistMuon->push_back(0);
       else whitelistMuon->push_back(1);
      }
      blacklistMuon = new std::vector<int>;
      blacklistMuon->push_back(nSelMu);
      stdHistograms -> Fill1("muons","muons",step,whitelistMuon);
      stdHistograms -> Fill1Float("muIso",(muons_tkIsoR03->at(nSelMu) + muons_emIsoR03->at(nSelMu) + muons_hadIsoR03->at(nSelMu)) / (muons->at(nSelMu).Pt()),step);
      delete blacklistMuon;
     }
     
     if (WhichChannel != 0) delete whitelistElectron;
     if (WhichChannel != 1) delete whitelistMuon;
     
     if (WhichChannel == 0 || WhichChannel == 1){
      stepEvents[step] += 1;
      stdHistograms -> Fill1("jets","jets",step,&whitelistJet);
      stdHistograms -> Fill1("met","met",step,0);
      
      ///*************************************
      ///**** STEP 5 - jet identification ****
      std::vector<std::vector<int> > combinations;
      if (nJets>7) {
       nJets = 7;
      }     
      
      int buffer = Build4JetCombinations(combinations,nJets);
      std::pair<double,int> bestCombination = GetCombinationMVA(reader,combinations,TMVAreader,methodName,input_variables,&whitelistJet);
      
      TMVA_value = bestCombination.first;
      MVACombination = bestCombination.second;
      
      if (MVACombination!=-1){
       step = 5;
       stepName[step] = "jet identification";
       stepEvents[step] += 1;
       
       int q1 = combinations.at(MVACombination).at(0);
       int q2 = combinations.at(MVACombination).at(1);
       int b1 = combinations.at(MVACombination).at(2);
       int b2 = combinations.at(MVACombination).at(3);    
       
       stdHistograms -> Fill1Float("bTagging",std::min(jets_trackCountingHighEffBJetTags->at(b1),jets_trackCountingHighEffBJetTags->at(b2)),step);
       stdHistograms -> Fill1Float("MVAResponse",TMVA_value,step);
       stdHistograms -> Fill2(jets->at(q1),jets->at(q2), "WJJ", step);
       stdHistograms -> Fill1("jets","jets",step,&whitelistJet);
       stdHistograms -> Fill1("met","met",step,0);
       if (WhichChannel == 0){
	stdHistograms -> Fill1("electrons","electrons",step,whitelistElectron);
	stdHistograms -> Fill1Float("eleIso",(electrons_tkIso->at(nSelEle) + electrons_emIso->at(nSelEle) + electrons_hadIso_1->at(nSelEle)) / (electrons->at(nSelEle).Pt()),step);
       }
       if (WhichChannel == 1){
	stdHistograms -> Fill1("muons","muons",step,whitelistMuon);
	stdHistograms -> Fill1Float("muIso",(muons_tkIsoR03->at(nSelMu) + muons_emIsoR03->at(nSelMu) + muons_hadIsoR03->at(nSelMu)) / (muons->at(nSelMu).Pt()),step);
       }
       
       q_1 = &(jets->at(q1));
       q_2 = &(jets->at(q2));
       b_1 = &(jets->at(b1));
       b_2 = &(jets->at(b2));
       stepAnalysis = 5;
       outTreeJets.Fill();
       
       
       ///********************************
       ///**** STEP 6 - jet selection ****
       if (TMVA_value > -0.12){
	step = 6;
	stepName[step] = "jet selection";
	stepEvents[step] += 1;
	
	stdHistograms -> Fill1Float("bTagging",std::min(jets_trackCountingHighEffBJetTags->at(b1),jets_trackCountingHighEffBJetTags->at(b2)),step);
	stdHistograms -> Fill1Float("MVAResponse",TMVA_value,step);
	stdHistograms -> Fill2(jets->at(q1),jets->at(q2), "WJJ", step);
	stdHistograms -> Fill1("jets","jets",step,&whitelistJet);
	stdHistograms -> Fill1("met","met",step,0);
	if (WhichChannel == 0){
	 stdHistograms -> Fill1("electrons","electrons",step,whitelistElectron);
	 stdHistograms -> Fill1Float("eleIso",(electrons_tkIso->at(nSelEle) + electrons_emIso->at(nSelEle) + electrons_hadIso_1->at(nSelEle)) / (electrons->at(nSelEle).Pt()),step);
	}
	if (WhichChannel == 1){
	 stdHistograms -> Fill1("muons","muons",step,whitelistMuon);
	 stdHistograms -> Fill1Float("muIso",(muons_tkIsoR03->at(nSelMu) + muons_emIsoR03->at(nSelMu) + muons_hadIsoR03->at(nSelMu)) / (muons->at(nSelMu).Pt()),step);
	}
	
	stepAnalysis = 6;
	outTreeJets.Fill();	
       }///---- step 6
       else {
	delete whitelistElectron;
	delete whitelistMuon;
       }
      }///---- step 5
      else {
       delete whitelistElectron;
       delete whitelistMuon;
      }
     }///---- step 4
    }///---- step 4 -> support
   }///---- step 3
  }///---- step 2
  
  
  
  
 } //loop over the events 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 
 //  outFile.Write();   
 
 
 
 
 ///==== save additional information ====
 //  TFile* outputRootFile = new TFile(OutFileNameEfficiencies.c_str(), "recreate");
 //  outputRootFile -> cd();
 for(step = 0; step < nStep; ++step)
 {
  events -> SetBinContent(step+1, stepEvents[step]);
  events -> GetXaxis() -> SetBinLabel(step+1, stepName[step].c_str());
  
  if (step != 0){
   analysisEfficiency = static_cast<double>(stepEvents[step]) / static_cast<double>(stepEvents[1]); ///---- fractio => efficiency
   outTreeSelections.Fill();
  }
 } 
 events -> Write(); 
 outFile.Write();
 
 delete stdHistograms;
 
 
 
 ///---- end selection ----
 ///-----------------------
 
 
 
 return 0;
}



