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
 std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << OutFileName  << std::endl;  
 std::string OutFileNameEfficiencies    = gConfigParser -> readStringOption("Output::OutFileNameEfficiencies");
 std::cout << ">>>>> Output::OutFileNameEfficiencies  " << OutFileNameEfficiencies  << std::endl;  
 
 TFile outFile(OutFileNameEfficiencies.c_str(),"RECREATE");
 
 
 //  hFactory factory (OutFileName.c_str(), true) ;
 hFactory factory ("no", true) ;
 
 factory.add_h1 ("jets_eta", "jet #eta", 200, -10, 10, 1) ; 
 factory.add_h1 ("jets_pt", "jet pt", 1000, 0, 1000, 1) ; 
 factory.add_h1 ("jets_phi", "jet phi", 100, -6.28, 6.28, 1) ; 
 factory.add_h1 ("num_jets", "number of jets", 20, 0, 20, 2) ; 
 factory.add_h1 ("MVA_Response", "MVA Response", 1000, -2, 2, 1) ; 
 
 factory.add_h1 ("num_leptons", "number of leptons", 20, 0, 20, 1) ; 
 factory.add_h1 ("num_electrons", "number of electrons", 20, 0, 20, 1) ; 
 factory.add_h1 ("num_muons", "number of muons", 20, 0, 20, 1) ; 
 
 factory.add_h1 ("electrons_phi", "electrons phi", 100, -6.28, 6.28, 4) ; 
 factory.add_h1 ("electrons_eta", "electrons #eta", 200, -10, 10, 4) ; 
 factory.add_h1 ("electrons_pt", "electrons pt", 1000, 0, 1000, 4) ; 
 factory.add_h1 ("electrons_iso", "electrons isolation", 1000, 0, 2, 4) ; 
 
 factory.add_h1 ("muons_phi", "muons phi", 100, -6.28, 6.28, 4) ; 
 factory.add_h1 ("muons_eta", "muons #eta", 200, -10, 10, 4) ; 
 factory.add_h1 ("muons_pt", "muons pt", 1000, 0, 1000, 4) ; 
 factory.add_h1 ("muons_iso", "muons isolation", 1000, 0, 2, 4) ; 
 
 factory.add_h1 ("leptons_phi", "leptons phi", 100, -6.28, 6.28, 1) ; 
 factory.add_h1 ("leptons_eta", "leptons #eta", 200, -10, 10, 1) ; 
 factory.add_h1 ("leptons_pt", "leptons pt", 1000, 0, 1000, 1) ; 
 
 factory.add_h1 ("dr_qq", "#Delta R Wqq", 100, 0, 10, 1) ; 
 factory.add_h1 ("dr_qb", "#Delta R qb", 100, 0, 10, 1) ; 
 factory.add_h1 ("dr_bb", "#Delta R bb", 100, 0, 10, 1) ; 

 factory.add_h1 ("Mjj_qq", "Mjj Wqq", 100, 40, 140, 7) ; 
 factory.add_h1 ("MET", "MET", 1000, 0, 200, 7) ; 
 factory.add_h1 ("jets_trackCountingHighEffBJetTags", "jets_trackCountingHighEffBJetTags", 1100, -100, 1000, 7) ; 
 
 
 
 double XSection = inputXSection;
 int numEntriesBefore;
 
 TTree outTreeSelections("outTreeSelections","outTreeSelections");
 outTreeSelections.Branch("XSection",&XSection,"XSection/D");
 outTreeSelections.Branch("lepton_efficiency",&lepton_efficiency,"lepton_efficiency/D");
 outTreeSelections.Branch("jet_efficiency",&jet_efficiency,"jet_efficiency/D");
 outTreeSelections.Branch("preselection_efficiency",&preselection_efficiency,"preselection_efficiency/D");
 outTreeSelections.Branch("numEntriesBefore",&numEntriesBefore,"numEntriesBefore/I");
 
 
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
 outTreeSelections.Fill();
 
 
 start = clock();
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent) {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
  
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
  
  int nJets = jets->size();
  
  std::vector<int> whitelistJet;
  for (int iJet = 0; iJet < nJets; iJet++){
   if (fabs(jets->at(iJet).Eta()) < 2.4 && jets->at(iJet).Pt() > 15) { ///==== selections on jets
    whitelistJet.push_back(1);
   }
   else {
    whitelistJet.push_back(0);
   }
  }
  
  if ( nJets >= 4 ){///==== number of jets ====  //---- number of jets >= 4
   factory.Fill ("num_jets", 0, nJets) ;   
   factory.Fill ("num_leptons", 0, muons->size() +  electrons->size()) ;   
   factory.Fill ("num_electrons", 0, electrons->size()) ;   
   factory.Fill ("num_muons", 0, muons->size()) ;   
   
   for (int iMu=0; iMu<muons->size(); iMu++){
    factory.Fill ("muons_eta", 0, muons->at(iMu).Eta());    
    factory.Fill ("muons_phi", 0, muons->at(iMu).Phi());
    factory.Fill ("muons_pt", 0, muons->at(iMu).Pt());
    factory.Fill ("leptons_eta", 0, muons->at(iMu).Eta());    
    factory.Fill ("leptons_phi", 0, muons->at(iMu).Phi());
    factory.Fill ("leptons_pt", 0, muons->at(iMu).Pt());
   }
   
   for (int iEle=0; iEle<electrons->size(); iEle++){
    factory.Fill ("electrons_eta", 0, electrons->at(iEle).Eta());    
    factory.Fill ("electrons_phi", 0, electrons->at(iEle).Phi());
    factory.Fill ("electrons_pt", 0, electrons->at(iEle).Pt());
    factory.Fill ("leptons_eta", 0, electrons->at(iEle).Eta());    
    factory.Fill ("leptons_phi", 0, electrons->at(iEle).Phi());
    factory.Fill ("leptons_pt", 0, electrons->at(iEle).Pt());
   }
   
   for (int iJet=0; iJet<nJets; iJet++){
    factory.Fill ("jets_eta", 0, jets->at(iJet).Eta());
    factory.Fill ("jets_phi", 0, jets->at(iJet).Phi());
    factory.Fill ("jets_pt", 0, jets->at(iJet).Pt());
   }
  
  
  
  
  int nJets_preferred = getNumJets(whitelistJet);
  if ( nJets_preferred >= 4 ){///==== number of selected jets ====  //---- number of selected jets >= 4
  
   factory.Fill ("num_jets", 1, nJets_preferred) ;   
   
  
   std::string method = "maxPt";
   std::vector<int>* blacklist = 0;
   int numMuonsSurvived = 0;  
   int nSelMu = SelectMuonTTBar(*muons,*muons_tkIsoR03,*muons_emIsoR03,*muons_hadIsoR03,method,20,2.1,0.05,numMuonsSurvived,blacklist);
  

   int numElectronsSurvived = 0;
   int nSelEle = SelectElectronTTBar(*electrons,*electrons_tkIso,*electrons_emIso,*electrons_hadIso_1,*electrons_IdRobustTight,*electrons_track_d0,method,30,2.5,0.1,0.2,numElectronsSurvived,blacklist);
   
   if ( numMuonsSurvived == 1 || numElectronsSurvived == 1){///==== number of electrons == 1 || number of muons == 1 ====
   
//     std::cerr << "numElectronsSurvived = " << numElectronsSurvived << std::endl;
//     std::cerr << "nSelEle = " << nSelEle << std::endl;
//     std::cerr << "numMuonsSurvived = " << numMuonsSurvived << std::endl;
//     std::cerr << "nSelMu = " << nSelMu << std::endl;
    
    if (numElectronsSurvived == 1){ ///==== electron channel ====     
     if (numMuonsSurvived != 0) continue; ///==== no muons!
     std::vector<int>* blacklistEle = new std::vector<int>;
     blacklistEle->push_back(nSelEle);
     int numElectronsSurvived_more = 0;
     int temp_moreEle = SelectElectronTTBar(*electrons,*electrons_tkIso,*electrons_emIso,*electrons_hadIso_1,*electrons_IdTight,*electrons_track_d0,method,20,2.5,0.25,0.2,numElectronsSurvived_more,blacklistEle);
     if (numElectronsSurvived_more != 0) {
      delete blacklistEle;
      continue; ///==== no other electrons! -> Z Veto
     }
     delete blacklistEle;
      
      
     factory.Fill ("electrons_eta", 1, electrons->at(nSelEle).Eta());    
     factory.Fill ("electrons_phi", 1, electrons->at(nSelEle).Phi());
     factory.Fill ("electrons_pt", 1, electrons->at(nSelEle).Pt());
     factory.Fill ("electrons_iso", 1, (electrons_tkIso->at(nSelEle) + electrons_emIso->at(nSelEle) + electrons_hadIso_1->at(nSelEle)) / (electrons->at(nSelEle).Pt()));
    }
    
    if (numMuonsSurvived == 1){ ///==== muon channel ====
     if (numElectronsSurvived != 0) continue; ///==== no electrons!  
//      int numElectronsSurvived_more = 0;
//      int temp_moreEle = SelectElectronTTBar(*electrons,*electrons_tkIso,*electrons_emIso,*electrons_hadIso_1,*electrons_IdRobustTight,*electrons_track_d0,method,20,10,0.2,0.2,numElectronsSurvived_more,blacklist);
//      if (numElectronsSurvived_more != 0) continue; ///==== no electrons!
// 
//      int numElectronsSurvived_more_loose = 0;
//      int temp_moreEle_loose = SelectElectronTTBar(*electrons,*electrons_tkIso,*electrons_emIso,*electrons_hadIso_1,*electrons_IdRobustTight,*electrons_track_d0,method,15,10,0.2,0.2,numElectronsSurvived_more_loose,blacklist);
//      if (numElectronsSurvived_more_loose != 0) continue; ///==== no electrons Loose!
//           
//      int numMuonsSurvived_more = 0;
//      int temp_moreMu = SelectMuonTTBar(*muons,*muons_tkIsoR03,*muons_emIsoR03,*muons_hadIsoR03,method,10,10,0.2,numMuonsSurvived_more,blacklist);
//      if (numMuonsSurvived_more != 1) continue; ///==== no other muons!

     factory.Fill ("muons_eta", 1, muons->at(nSelMu).Eta());    
     factory.Fill ("muons_phi", 1, muons->at(nSelMu).Phi());
     factory.Fill ("muons_pt", 1, muons->at(nSelMu).Pt());     
     factory.Fill ("muons_iso", 1, (muons_tkIsoR03->at(nSelMu) + muons_emIsoR03->at(nSelMu) + muons_hadIsoR03->at(nSelMu)) / (muons->at(nSelMu).Pt()));
    }
   
   std::vector<std::vector<int> > combinations;
   if (nJets>6) {
    nJets = 6;
   }     
   
   int buffer = Build4JetCombinations(combinations,nJets);
   std::pair<double,int> bestCombination = GetCombinationMVA(reader,combinations,TMVAreader,methodName,input_variables);
   
   TMVA_value = bestCombination.first;
   MVACombination = bestCombination.second;
   
   if (MVACombination!=-1){
    int q1 = combinations.at(MVACombination).at(0);
    int q2 = combinations.at(MVACombination).at(1);
    int b1 = combinations.at(MVACombination).at(2);
    int b2 = combinations.at(MVACombination).at(3);    
    double dr_qq = ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(q2));
    double dr_bb = ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(b2));
    double dr_qb = std::min(ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(b2)),ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(q2)));    
    double Mjj = (jets->at(q1) + jets->at(q2)).M();
    factory.Fill ("dr_qq",0,dr_qq);
    factory.Fill ("dr_qb",0,dr_qb);
    factory.Fill ("dr_bb",0,dr_bb);
    factory.Fill ("Mjj_qq",0,Mjj);    
    factory.Fill ("MET",3,met->at(0).Pt());    
    factory.Fill ("jets_trackCountingHighEffBJetTags",0,std::min(jets_trackCountingHighEffBJetTags->at(b1),jets_trackCountingHighEffBJetTags->at(b2)));
    
    
    if (TMVA_value > -0.25) {
     factory.Fill ("Mjj_qq",1,Mjj);    
     factory.Fill ("MET",0,met->at(0).Pt());
     if (numMuonsSurvived == 1 && numElectronsSurvived == 0) {
      factory.Fill ("Mjj_qq",4,Mjj); ///---- muon
      factory.Fill ("muons_eta", 2, muons->at(nSelMu).Eta());    
      factory.Fill ("muons_phi", 2, muons->at(nSelMu).Phi());
      factory.Fill ("muons_pt", 2, muons->at(nSelMu).Pt());     
      factory.Fill ("muons_iso", 2, (muons_tkIsoR03->at(nSelMu) + muons_emIsoR03->at(nSelMu) + muons_hadIsoR03->at(nSelMu)) / (muons->at(nSelMu).Pt()));
      factory.Fill ("MET",1,met->at(0).Pt());
     }
     if (numMuonsSurvived == 0 && numElectronsSurvived == 1) {
      factory.Fill ("Mjj_qq",5,Mjj); ///---- electron
      factory.Fill ("electrons_eta", 2, electrons->at(nSelEle).Eta());    
      factory.Fill ("electrons_phi", 2, electrons->at(nSelEle).Phi());
      factory.Fill ("electrons_pt", 2, electrons->at(nSelEle).Pt());
      factory.Fill ("electrons_iso", 2, (electrons_tkIso->at(nSelEle) + electrons_emIso->at(nSelEle) + electrons_hadIso_1->at(nSelEle)) / (electrons->at(nSelEle).Pt()));
      factory.Fill ("MET",2,met->at(0).Pt());
     }
    }
    if (numMuonsSurvived == 1 && numElectronsSurvived == 0) factory.Fill ("Mjj_qq",2,Mjj); ///---- muon
    if (numMuonsSurvived == 0 && numElectronsSurvived == 1) factory.Fill ("Mjj_qq",3,Mjj); ///---- electron
    if (TMVA_value > -0.2) factory.Fill ("Mjj_qq",6,Mjj);
   }   
   
   
   factory.Fill ("MVA_Response", 0, TMVA_value);
   }///==== end number of leptons ====
  }///==== end number of selected jets ====
  }///==== end number of jets ====
 } //loop over the events 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 
 int colors[11] = {92,98,97,96,95,94,93,92,91,90,89} ;
 factory.applyToAll (setH1Colors (std::vector<int> (colors, colors + 11))) ;
 
 outFile.Write();   
 
 
 
 ///---- end selection ----
 ///-----------------------
 
 
 
 return 0;
}



