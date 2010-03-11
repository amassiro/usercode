#include "treeReader.h"
#include "hFactory.h"
#include "hFunctions.h"
#include "stdHisto.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"



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
 
 
 ///----------------------
 ///---- Preselection ----
 
 double preselection_efficiency = lepton_efficiency * jet_efficiency;
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
 factory.add_h1 ("num_jets", "number of jets", 20, 0, 20, 1) ; 
 factory.add_h1 ("MVA_Response", "MVA Response", 1000, -2, 2, 1) ; 
 
 factory.add_h1 ("num_leptons", "number of leptons", 20, 0, 20, 1) ; 
 factory.add_h1 ("num_electrons", "number of electrons", 20, 0, 20, 1) ; 
 factory.add_h1 ("num_muons", "number of muons", 20, 0, 20, 1) ; 

 factory.add_h1 ("electrons_phi", "electrons phi", 100, -6.28, 6.28, 1) ; 
 factory.add_h1 ("electrons_eta", "electrons #eta", 200, -10, 10, 1) ; 
 factory.add_h1 ("electrons_pt", "electrons pt", 1000, 0, 1000, 1) ; 
 
 factory.add_h1 ("muons_phi", "muons phi", 100, -6.28, 6.28, 1) ; 
 factory.add_h1 ("muons_eta", "muons #eta", 200, -10, 10, 1) ; 
 factory.add_h1 ("muons_pt", "muons pt", 1000, 0, 1000, 1) ; 
 
 factory.add_h1 ("leptons_phi", "leptons phi", 100, -6.28, 6.28, 1) ; 
 factory.add_h1 ("leptons_eta", "leptons #eta", 200, -10, 10, 1) ; 
 factory.add_h1 ("leptons_pt", "leptons pt", 1000, 0, 1000, 1) ; 
 
 factory.add_h1 ("dr_qq", "#Delta R Wqq", 100, 0, 10, 1) ; 
 factory.add_h1 ("dr_qb", "#Delta R qb", 100, 0, 10, 1) ; 
 factory.add_h1 ("dr_bb", "#Delta R bb", 100, 0, 10, 1) ; 
 
 
 double XSection = inputXSection;
 int numEntriesBefore;
 
 TTree outTreeSelections("outTreeSelections","outTreeSelections");
 outTreeSelections.Branch("XSection",&XSection,"XSection/D");
 outTreeSelections.Branch("lepton_efficiency",&lepton_efficiency,"lepton_efficiency/D");
 outTreeSelections.Branch("jet_efficiency",&jet_efficiency,"jet_efficiency/D");
 outTreeSelections.Branch("preselection_efficiency",&preselection_efficiency,"preselection_efficiency/D");
 outTreeSelections.Branch("numEntriesBefore",&numEntriesBefore,"numEntriesBefore/I");
 
 
 double TMVA_value;
 
 Float_t pT_RECO_q1;
 Float_t pT_RECO_q2;
 Float_t pT_RECO_b1;
 Float_t pT_RECO_b2;
 
 Float_t DR_RECO_qq;
 Float_t DR_RECO_qb;
 Float_t DR_RECO_bb;
 
 Float_t jets_trackCountingHighEffBJetTags_RECO_q1;
 Float_t jets_trackCountingHighEffBJetTags_RECO_b1;
 Float_t jets_trackCountingHighPurBJetTags_RECO_q1;
 Float_t jets_trackCountingHighPurBJetTags_RECO_b1;
 Float_t jets_simpleSecondaryVertexBJetTags_RECO_q1;
 Float_t jets_simpleSecondaryVertexBJetTags_RECO_b1;
 Float_t jets_combinedSecondaryVertexBJetTags_RECO_q1;
 Float_t jets_combinedSecondaryVertexBJetTags_RECO_b1;
 Float_t jets_combinedSecondaryVertexMVABJetTags_RECO_q1;
 Float_t jets_combinedSecondaryVertexMVABJetTags_RECO_b1;
 
 Float_t jets_trackCountingHighEffBJetTags_RECO_q2;
 Float_t jets_trackCountingHighEffBJetTags_RECO_b2;
 Float_t jets_trackCountingHighPurBJetTags_RECO_q2;
 Float_t jets_trackCountingHighPurBJetTags_RECO_b2;
 Float_t jets_simpleSecondaryVertexBJetTags_RECO_q2;
 Float_t jets_simpleSecondaryVertexBJetTags_RECO_b2;
 Float_t jets_combinedSecondaryVertexBJetTags_RECO_q2;
 Float_t jets_combinedSecondaryVertexBJetTags_RECO_b2;
 Float_t jets_combinedSecondaryVertexMVABJetTags_RECO_q2;
 Float_t jets_combinedSecondaryVertexMVABJetTags_RECO_b2; 
 
 
 TMVA::Reader *TMVAreader = new TMVA::Reader( "!Color:!Silent" );
 TMVAreader->AddVariable("pT_RECO_q1",&pT_RECO_q1);
 TMVAreader->AddVariable("pT_RECO_q2",&pT_RECO_q2);
 TMVAreader->AddVariable("pT_RECO_b1",&pT_RECO_b1);
 TMVAreader->AddVariable("pT_RECO_b2",&pT_RECO_b2);
 TMVAreader->AddVariable("DR_RECO_qq",&DR_RECO_qq);
 TMVAreader->AddVariable("DR_RECO_qb",&DR_RECO_qb);
 TMVAreader->AddVariable("DR_RECO_bb",&DR_RECO_bb);
 TMVAreader->AddVariable("jets_trackCountingHighEffBJetTags_RECO_q1",&jets_trackCountingHighEffBJetTags_RECO_q1);
 TMVAreader->AddVariable("jets_trackCountingHighEffBJetTags_RECO_b1",&jets_trackCountingHighEffBJetTags_RECO_b1);
 TMVAreader->AddVariable("jets_trackCountingHighEffBJetTags_RECO_q2",&jets_trackCountingHighEffBJetTags_RECO_q2);
 TMVAreader->AddVariable("jets_trackCountingHighEffBJetTags_RECO_b2",&jets_trackCountingHighEffBJetTags_RECO_b2);
 
 
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
  
  int nJets = jets->size();
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
   
   std::vector<std::vector<int> > combinations;
   if (nJets>6) {
    nJets = 6;
   }     
   
   TMVA_value = -100000000;
   int MVACombination = -1;
   
   int buffer = Build4JetCombinations(combinations,nJets);
   int nComb = combinations.size();
   for (int iComb = 0; iComb<nComb; iComb++){
    int q1 = combinations.at(iComb).at(0);
    int q2 = combinations.at(iComb).at(1);
    int b1 = combinations.at(iComb).at(2);
    int b2 = combinations.at(iComb).at(3);    
    
    pT_RECO_q1 = jets->at(q1).Pt();
    pT_RECO_q2 = jets->at(q2).Pt();
    pT_RECO_b1 = jets->at(b1).Pt();
    pT_RECO_b2 = jets->at(b2).Pt();
    DR_RECO_qq = ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(q2));
    DR_RECO_bb = ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(b2));
    DR_RECO_qb = std::min(ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(b2)),ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(q2)));
    
    if (jets->at(q1).Pt() > jets->at(q2).Pt()) {
     jets_trackCountingHighEffBJetTags_RECO_q1 = jets_trackCountingHighEffBJetTags->at(q1);
     jets_trackCountingHighEffBJetTags_RECO_q2 = jets_trackCountingHighEffBJetTags->at(q2);  
     jets_trackCountingHighPurBJetTags_RECO_q1 = jets_trackCountingHighPurBJetTags->at(q1);
     jets_trackCountingHighPurBJetTags_RECO_q2 = jets_trackCountingHighPurBJetTags->at(q2);
     jets_simpleSecondaryVertexBJetTags_RECO_q1 = jets_simpleSecondaryVertexBJetTags->at(q1);
     jets_simpleSecondaryVertexBJetTags_RECO_q2 = jets_simpleSecondaryVertexBJetTags->at(q2);
     jets_combinedSecondaryVertexBJetTags_RECO_q1 = jets_combinedSecondaryVertexBJetTags->at(q1);
     jets_combinedSecondaryVertexBJetTags_RECO_q2 = jets_combinedSecondaryVertexBJetTags->at(q2);
     jets_combinedSecondaryVertexMVABJetTags_RECO_q1 = jets_combinedSecondaryVertexMVABJetTags->at(q1);
     jets_combinedSecondaryVertexMVABJetTags_RECO_q2 = jets_combinedSecondaryVertexMVABJetTags->at(q2);
    }
    else  {
     jets_trackCountingHighEffBJetTags_RECO_q1 = jets_trackCountingHighEffBJetTags->at(q2);
     jets_trackCountingHighEffBJetTags_RECO_q2 = jets_trackCountingHighEffBJetTags->at(q1);  
     jets_trackCountingHighPurBJetTags_RECO_q1 = jets_trackCountingHighPurBJetTags->at(q2);
     jets_trackCountingHighPurBJetTags_RECO_q2 = jets_trackCountingHighPurBJetTags->at(q1);
     jets_simpleSecondaryVertexBJetTags_RECO_q1 = jets_simpleSecondaryVertexBJetTags->at(q2);
     jets_simpleSecondaryVertexBJetTags_RECO_q2 = jets_simpleSecondaryVertexBJetTags->at(q1);
     jets_combinedSecondaryVertexBJetTags_RECO_q1 = jets_combinedSecondaryVertexBJetTags->at(q2);
     jets_combinedSecondaryVertexBJetTags_RECO_q2 = jets_combinedSecondaryVertexBJetTags->at(q1);
     jets_combinedSecondaryVertexMVABJetTags_RECO_q1 = jets_combinedSecondaryVertexMVABJetTags->at(q2);
     jets_combinedSecondaryVertexMVABJetTags_RECO_q2 = jets_combinedSecondaryVertexMVABJetTags->at(q1);
    }
    
    if (jets->at(b1).Pt() > jets->at(b2).Pt()) {
     jets_trackCountingHighEffBJetTags_RECO_b1 = jets_trackCountingHighEffBJetTags->at(b1);
     jets_trackCountingHighEffBJetTags_RECO_b2 = jets_trackCountingHighEffBJetTags->at(b2);  
     jets_trackCountingHighPurBJetTags_RECO_b1 = jets_trackCountingHighPurBJetTags->at(b1);
     jets_trackCountingHighPurBJetTags_RECO_b2 = jets_trackCountingHighPurBJetTags->at(b2);
     jets_simpleSecondaryVertexBJetTags_RECO_b1 = jets_simpleSecondaryVertexBJetTags->at(b1);
     jets_simpleSecondaryVertexBJetTags_RECO_b2 = jets_simpleSecondaryVertexBJetTags->at(b2);
     jets_combinedSecondaryVertexBJetTags_RECO_b1 = jets_combinedSecondaryVertexBJetTags->at(b1);
     jets_combinedSecondaryVertexBJetTags_RECO_b2 = jets_combinedSecondaryVertexBJetTags->at(b2);
     jets_combinedSecondaryVertexMVABJetTags_RECO_b1 = jets_combinedSecondaryVertexMVABJetTags->at(b1);
     jets_combinedSecondaryVertexMVABJetTags_RECO_b2 = jets_combinedSecondaryVertexMVABJetTags->at(b2);
    }
    else  {
     jets_trackCountingHighEffBJetTags_RECO_b1 = jets_trackCountingHighEffBJetTags->at(b2);
     jets_trackCountingHighEffBJetTags_RECO_b2 = jets_trackCountingHighEffBJetTags->at(b1);  
     jets_trackCountingHighPurBJetTags_RECO_b1 = jets_trackCountingHighPurBJetTags->at(b2);
     jets_trackCountingHighPurBJetTags_RECO_b2 = jets_trackCountingHighPurBJetTags->at(b1);
     jets_simpleSecondaryVertexBJetTags_RECO_b1 = jets_simpleSecondaryVertexBJetTags->at(b2);
     jets_simpleSecondaryVertexBJetTags_RECO_b2 = jets_simpleSecondaryVertexBJetTags->at(b1);
     jets_combinedSecondaryVertexBJetTags_RECO_b1 = jets_combinedSecondaryVertexBJetTags->at(b2);
     jets_combinedSecondaryVertexBJetTags_RECO_b2 = jets_combinedSecondaryVertexBJetTags->at(b1);
     jets_combinedSecondaryVertexMVABJetTags_RECO_b1 = jets_combinedSecondaryVertexMVABJetTags->at(b2);
     jets_combinedSecondaryVertexMVABJetTags_RECO_b2 = jets_combinedSecondaryVertexMVABJetTags->at(b1);
    }
    
    double MVA_temp = TMVAreader->EvaluateMVA(methodName);
    if (MVA_temp > TMVA_value) {
     TMVA_value = MVA_temp;
     MVACombination = iComb;
    }
   }
   
   if (MVACombination!=-1){
    int q1 = combinations.at(MVACombination).at(0);
    int q2 = combinations.at(MVACombination).at(1);
    int b1 = combinations.at(MVACombination).at(2);
    int b2 = combinations.at(MVACombination).at(3);    
    double dr_qq = ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(q2));
    double dr_bb = ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(b2));
    double dr_qb = std::min(ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(b2)),ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(q2)));    
    factory.Fill ("dr_qq",0,dr_qq);
    factory.Fill ("dr_qb",0,dr_qb);
    factory.Fill ("dr_bb",0,dr_bb);
   }   
   
   factory.Fill ("MVA_Response", 0, TMVA_value);
  }///==== end number of jets ====
 } //loop over the events 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 
 int colors[3] = {92,98,97} ;
 factory.applyToAll (setH1Colors (std::vector<int> (colors, colors + 3))) ;
 
 outFile.Write();   
 
 
 
 ///---- end selection ----
 ///-----------------------

 

 return 0;
}



