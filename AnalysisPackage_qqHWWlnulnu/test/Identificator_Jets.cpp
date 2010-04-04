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



int CalculateMatch(std::vector<int> &matchIt,std::vector<int> & combination){
 int Match4 = 0;
 int q1 = combination.at(0);
 int q2 = combination.at(1);
 if (q1 == (matchIt.at(0)) || q1 == (matchIt.at(1))){
  Match4 ++;
 }
 if (q2 == (matchIt.at(0)) || q2 == (matchIt.at(1))){
  Match4 ++;
 }
 return Match4;
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
 
 std::string treeName      = gConfigParser -> readStringOption("Input::treeName");
 std::string inputFileList = gConfigParser -> readStringOption("Input::inputFileList");
 
 int entryMAX = gConfigParser -> readIntOption("Input::entryMAX");
 int entryMIN = gConfigParser -> readIntOption("Input::entryMIN");
 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 std::cout << ">>>>> input::entryMIN  " << entryMIN  << std::endl;  
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 // Open ntple
 TChain* chain = new TChain(treeName.c_str());
 if(!FillChain(*chain, inputFileList.c_str())) return 1;
 treeReader reader((TTree*)(chain));

 if (entryMAX > reader.GetEntries()) entryMAX = reader.GetEntries();
 if (entryMAX == -1) entryMAX = reader.GetEntries();
 
 std::cout << ">>>>> Identificator::Entries = " << reader.GetEntries()  << std::endl;  
 
 
 
 int creator = gConfigParser -> readIntOption("Identificator::creator");
 std::cout << ">>>>> Identificator::creator  " << creator  << std::endl;  
 
 TRandom3 myrand;
 
 if (creator == 1){
  ///----------------------------------------
  ///---- Tree producer for MVA training ----
  
  std::string outputFileName    = gConfigParser -> readStringOption("Creator::outFileName");
  std::cout << ">>>>> Creator::outFileName  " << outputFileName  << std::endl;  
  
  TFile outFile(outputFileName.c_str(),"RECREATE");
  TTree outTree("outTree","outTree");
  
  double pT_RECO_q1;
  double pT_RECO_q2;
  
  double eta_RECO_q1;
  double eta_RECO_q2;
  
  double eta_RECO_q1_eta_RECO_q2;
  double Deta_RECO_q12;

  double Mjj;
  
  int Match4;
  
  outTree.Branch("pT_RECO_q1",&pT_RECO_q1,"pT_RECO_q1/D");
  outTree.Branch("pT_RECO_q2",&pT_RECO_q2,"pT_RECO_q2/D");
  
  outTree.Branch("eta_RECO_q1",&eta_RECO_q1,"eta_RECO_q1/D");
  outTree.Branch("eta_RECO_q2",&eta_RECO_q2,"eta_RECO_q2/D");

  outTree.Branch("eta_RECO_q1_eta_RECO_q2",&eta_RECO_q1_eta_RECO_q2,"eta_RECO_q1_eta_RECO_q2/D");
  outTree.Branch("Deta_RECO_q12",&Deta_RECO_q12,"Deta_RECO_q12/D");
  outTree.Branch("Mjj",&Mjj,"Mjj/D");
  
  outTree.Branch("Match4",&Match4,"Match4/I");
  
  std::cout << ">>>>> tree::entries " << chain -> GetEntries()  << std::endl;
  entryMAX = std::min (static_cast<int>(entryMAX),static_cast<int>(chain -> GetEntries()));
  
  double start, end;
  std::vector<ROOT::Math::XYZTVector>* mcQ_tag = new std::vector<ROOT::Math::XYZTVector>;
  
  start = clock();
  
  ///==================================
  ///==== Filling JetIdentificator ====
  
  for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent)
  {
   reader.GetEntry(iEvent);
   if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
   
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
   std::vector<ROOT::Math::XYZTVector> jets; 
   // clean jets
   for(unsigned int jetIt = 0; jetIt < (reader.Get4V("jets")->size()); ++jetIt)
   {
    ROOT::Math::XYZTVector jet = reader.Get4V("jets")->at(jetIt);
    if( jet.Et() < 10 ) continue;
    bool skipJet = false;
    for(unsigned int eleIt = 0; eleIt < electrons_jetCleaning.size(); ++eleIt)
    {
     ROOT::Math::XYZTVector ele = electrons_jetCleaning.at(eleIt);
     if(ROOT::Math::VectorUtil::DeltaR(jet,ele) < 0.3 ) skipJet = true;
    }
    if(skipJet == true) continue;
    jets.push_back( reader.Get4V("jets")->at(jetIt) );
   }
   ///========
   
   std::vector<ROOT::Math::XYZTVector>* mcQ1_tag = reader.Get4V("mcQ1_tag");
   std::vector<ROOT::Math::XYZTVector>* mcQ2_tag = reader.Get4V("mcQ2_tag");
   
//    std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
   
   std::vector<ROOT::Math::XYZTVector>* mcV1 = reader.Get4V("mcV1");
   std::vector<ROOT::Math::XYZTVector>* mcV2 = reader.Get4V("mcV2");
   
   std::vector<float>* mcV1_charge = reader.GetFloat("mcV1_charge");
   std::vector<float>* mcV2_charge = reader.GetFloat("mcV2_charge");
   
   std::vector<ROOT::Math::XYZTVector>* mcF1_fromV1 = reader.Get4V("mcF1_fromV1");
   std::vector<ROOT::Math::XYZTVector>* mcF1_fromV2 = reader.Get4V("mcF1_fromV2");
   std::vector<ROOT::Math::XYZTVector>* mcF2_fromV1 = reader.Get4V("mcF2_fromV1");
   std::vector<ROOT::Math::XYZTVector>* mcF2_fromV2 = reader.Get4V("mcF2_fromV2");
   
   std::vector<float>* mcF1_fromV1_pdgId = reader.GetFloat("mcF1_fromV1_pdgId");
   std::vector<float>* mcF1_fromV2_pdgId = reader.GetFloat("mcF1_fromV2_pdgId");
   std::vector<float>* mcF2_fromV1_pdgId = reader.GetFloat("mcF2_fromV1_pdgId");
   std::vector<float>* mcF2_fromV2_pdgId = reader.GetFloat("mcF2_fromV2_pdgId");
   
   ///---- find: q,q' ---- Pool ----
   
   mcQ_tag->clear();
   
   if (fabs(mcF1_fromV1_pdgId->at(0)) >= 11 && fabs(mcF1_fromV1_pdgId->at(0)) <= 14 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 && fabs(mcF1_fromV2_pdgId->at(0)) <= 14){//---- no tau considered!
    
    mcQ_tag->push_back(mcQ1_tag->at(0));
    mcQ_tag->push_back(mcQ2_tag->at(0));
    
    std::vector<int> matchIt;
    int matched = 0;
    matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(jets,*mcQ_tag,0.3,0.1,2.0,&matchIt);
    if (matched == 2){
     
     std::vector<std::vector<int> > combinations;
     int nJets = jets.size();
     if (nJets>5) {
      nJets = 5;
     }
     
     int buffer = Build2JetCombinations(combinations,nJets);
     
     int nComb = combinations.size();
     int numSelectedCombination = myrand.Uniform(0,nComb);
     
     for (int iComb = 0; iComb<nComb; iComb++){
      
      Match4 = CalculateMatch(matchIt,combinations.at(iComb));
      
      int q1 = combinations.at(iComb).at(0);
      int q2 = combinations.at(iComb).at(1);
      
      if (jets.at(q1).Pt() < jets.at(q2).Pt()) {
       int tempq = q1;
       q1 = q2;
       q2 = tempq;
      }
      
      pT_RECO_q1 = jets.at(q1).Pt();
      pT_RECO_q2 = jets.at(q2).Pt();
      
      eta_RECO_q1 = jets.at(q1).Eta();
      eta_RECO_q2 = jets.at(q2).Eta();
      
      eta_RECO_q1_eta_RECO_q2 = eta_RECO_q1 * eta_RECO_q2;
      Deta_RECO_q12 = fabs(eta_RECO_q1-eta_RECO_q2);
      
      Mjj = (jets.at(q1) + jets.at(q2)).M();
      
      //       DR_RECO_qq = ROOT::Math::VectorUtil::DeltaR(jets.at(q1),jets.at(q2));
      
      /// 1 one jet combination       
      if (numSelectedCombination == iComb) outTree.Fill();
     }   
    }
   }
  } //loop over the events 
  end = clock();
  std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
  ///==== end Filling JetIdentificator ====
  ///======================================
  
  delete mcQ_tag;
  outFile.Write();   
  
  ///---- end Tree producer for MVA training ----
  ///--------------------------------------------
 }
 else if (creator == 0){
  ///------------------------------
  ///---- test Identification -----
  std::string OutFileName    = gConfigParser -> readStringOption("Tester::outFileName");
 std::cout << ">>>>> Tester::outFileName  " << OutFileName  << std::endl;  
 TFile outFile(OutFileName.c_str(),"RECREATE");
 int kindAlgo = gConfigParser -> readIntOption("Tester::kindAlgo");
 std::cout << ">>>>> Tester::kindAlgo  " << kindAlgo  << std::endl;  
 ///----- kindAlgo == 0 ==> MVA
 ///----- kindAlgo == 1 ==> CUT
 
 if (kindAlgo == 0){
  ///------------------
  ///---- test MVA ----
  std::string additionalInputFileName    = gConfigParser -> readStringOption("Tester::additionalInputFileName");
  std::cout << ">>>>> Tester::additionalInputFileName  " << additionalInputFileName  << std::endl;  
  
  TTree outTree("outTree","outTree");
  int n_matched;
  int n_jets;
  outTree.Branch("n_matched",&n_matched,"n_matched/I");
  outTree.Branch("n_jets",&n_jets,"n_jets/I");
  
  Float_t input_variables[1000];
  
  Float_t pT_RECO_q1;
  Float_t pT_RECO_q2;
  Float_t eta_RECO_q1;
  Float_t eta_RECO_q2;
  Float_t eta_RECO_q1_eta_RECO_q2;
  Float_t Deta_RECO_q12;
  Float_t Mjj;
  
  TMVA::Reader *TMVAreader = new TMVA::Reader( "!Color:!Silent" );
  TMVAreader->AddVariable("pT_RECO_q1",&input_variables[0]);
  TMVAreader->AddVariable("pT_RECO_q2",&input_variables[1]);
  TMVAreader->AddVariable("eta_RECO_q1",&input_variables[2]);
  TMVAreader->AddVariable("eta_RECO_q2",&input_variables[3]);
  TMVAreader->AddVariable("eta_RECO_q1_eta_RECO_q2",&input_variables[4]);
  TMVAreader->AddVariable("Deta_RECO_q12",&input_variables[5]);
  TMVAreader->AddVariable("Mjj",&input_variables[6]);
  
  std::string stdstrMethod    = gConfigParser -> readStringOption("Tester::Method");
  std::cout << ">>>>> Tester::Method  " << stdstrMethod  << std::endl;  
  
  TString methodName = stdstrMethod + " method";
  TString weightfile = Form(additionalInputFileName.c_str());
  
  TMVAreader->BookMVA( methodName, weightfile );
  
  int Match4;
  std::vector<ROOT::Math::XYZTVector>* mcQ_tag = new std::vector<ROOT::Math::XYZTVector>;
  
  for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent)
  {
   reader.GetEntry(iEvent);
   if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
   
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
   std::vector<ROOT::Math::XYZTVector> jets; 
   // clean jets
   for(unsigned int jetIt = 0; jetIt < (reader.Get4V("jets")->size()); ++jetIt)
   {
    ROOT::Math::XYZTVector jet = reader.Get4V("jets")->at(jetIt);
    if( jet.Et() < 10 ) continue;
    bool skipJet = false;
    for(unsigned int eleIt = 0; eleIt < electrons_jetCleaning.size(); ++eleIt)
    {
     ROOT::Math::XYZTVector ele = electrons_jetCleaning.at(eleIt);
     if(ROOT::Math::VectorUtil::DeltaR(jet,ele) < 0.3 ) skipJet = true;
    }
    if(skipJet == true) continue;
    jets.push_back( reader.Get4V("jets")->at(jetIt) );
   }
   ///========
   
   std::vector<ROOT::Math::XYZTVector>* mcQ1_tag = reader.Get4V("mcQ1_tag");
   std::vector<ROOT::Math::XYZTVector>* mcQ2_tag = reader.Get4V("mcQ2_tag");
   
//    std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
   
   std::vector<ROOT::Math::XYZTVector>* mcV1 = reader.Get4V("mcV1");
   std::vector<ROOT::Math::XYZTVector>* mcV2 = reader.Get4V("mcV2");
   
   std::vector<float>* mcV1_charge = reader.GetFloat("mcV1_charge");
   std::vector<float>* mcV2_charge = reader.GetFloat("mcV2_charge");
   
   std::vector<ROOT::Math::XYZTVector>* mcF1_fromV1 = reader.Get4V("mcF1_fromV1");
   std::vector<ROOT::Math::XYZTVector>* mcF1_fromV2 = reader.Get4V("mcF1_fromV2");
   std::vector<ROOT::Math::XYZTVector>* mcF2_fromV1 = reader.Get4V("mcF2_fromV1");
   std::vector<ROOT::Math::XYZTVector>* mcF2_fromV2 = reader.Get4V("mcF2_fromV2");
   
   std::vector<float>* mcF1_fromV1_pdgId = reader.GetFloat("mcF1_fromV1_pdgId");
   std::vector<float>* mcF1_fromV2_pdgId = reader.GetFloat("mcF1_fromV2_pdgId");
   std::vector<float>* mcF2_fromV1_pdgId = reader.GetFloat("mcF2_fromV1_pdgId");
   std::vector<float>* mcF2_fromV2_pdgId = reader.GetFloat("mcF2_fromV2_pdgId");
   
   ///---- find: q,q' ---- Pool ----
   
   
   mcQ_tag->clear();
   
   if (fabs(mcF1_fromV1_pdgId->at(0)) >= 11 && fabs(mcF1_fromV1_pdgId->at(0)) <= 14 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 && fabs(mcF1_fromV2_pdgId->at(0)) <= 14){//---- no tau considered!
    
    mcQ_tag->push_back(mcQ1_tag->at(0));
    mcQ_tag->push_back(mcQ2_tag->at(0));
    
    std::vector<int> matchIt;
    int matched = 0;
    matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(jets,*mcQ_tag,0.3,0.1,2.0,&matchIt);
    if (matched == 2){
     
     int nJets = jets.size();
     std::vector<int> whitelistJet;
     for (int iJet = 0; iJet < nJets; iJet++){
      if (jets.at(iJet).Pt() > 10) { ///==== selections on jets
       whitelistJet.push_back(1);
     }
     else {
      whitelistJet.push_back(0);
     }
    }
    
    int nJets_preferred = getNumJets(whitelistJet);  
    if ( nJets_preferred >= 2 ){
     if (jets.at(matchIt.at(0)).Pt() > 10 && jets.at(matchIt.at(1)).Pt() > 10) { //---- only if the MC datasample has matched jets with pT > 30
      
      std::vector<std::vector<int> > combinations;
      if (nJets>5) {
       nJets = 5;
      }
      
      int buffer = Build2JetCombinations(combinations,nJets);
      std::pair<double,int> bestCombination = GetCombination_Jets_ID_MVA(jets,combinations,TMVAreader,methodName,input_variables,&whitelistJet);
      
      double TMVA_value = bestCombination.first;
      int MVACombination = bestCombination.second;
      
      n_matched = CalculateMatch(matchIt,combinations.at(MVACombination));
//       n_jets = jets.size();
      n_jets = nJets_preferred;
      
      outTree.Fill();     
     }
    }
    }
  }
 }
 delete mcQ_tag;
 outFile.Write();   
 ///---- end test MVA ----
 ///----------------------
 }
 else if (kindAlgo == 1){
  ///------------------
  ///---- test CUT ----
  std::string additionalInputFileName    = gConfigParser -> readStringOption("Tester::additionalInputFileName");
  std::cout << ">>>>> Tester::additionalInputFileName  " << additionalInputFileName  << std::endl;  
  
  TTree outTree("outTree","outTree");
  int n_matched;
  int n_jets;
  outTree.Branch("n_matched",&n_matched,"n_matched/I");
  outTree.Branch("n_jets",&n_jets,"n_jets/I");
  
  Float_t input_variables[1000];
  
  Float_t pT_RECO_q1;
  Float_t pT_RECO_q2;
  Float_t eta_RECO_q1;
  Float_t eta_RECO_q2;
  Float_t eta_RECO_q1_eta_RECO_q2;
  Float_t Deta_RECO_q12;
  Float_t Mjj;
  
  TMVA::Reader *TMVAreader = new TMVA::Reader( "!Color:!Silent" );
  TMVAreader->AddVariable("pT_RECO_q1",&input_variables[0]);
  TMVAreader->AddVariable("pT_RECO_q2",&input_variables[1]);
  TMVAreader->AddVariable("eta_RECO_q1",&input_variables[2]);
  TMVAreader->AddVariable("eta_RECO_q2",&input_variables[3]);
  TMVAreader->AddVariable("eta_RECO_q1_eta_RECO_q2",&input_variables[4]);
  TMVAreader->AddVariable("Deta_RECO_q12",&input_variables[5]);
  TMVAreader->AddVariable("Mjj",&input_variables[6]);
  
  std::string stdstrMethod    = gConfigParser -> readStringOption("Tester::Method");
  std::cout << ">>>>> Tester::Method  " << stdstrMethod  << std::endl;  
  
  TString methodName = stdstrMethod + " method";
  TString weightfile = Form(additionalInputFileName.c_str());
  
  TMVAreader->BookMVA( methodName, weightfile );
  
  int Match4;
  std::vector<ROOT::Math::XYZTVector>* mcQ_tag = new std::vector<ROOT::Math::XYZTVector>;
  
  std::cerr << ">>> " << entryMIN << " = " << entryMAX << " <<<" << std::endl;
  
  for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent)
  {
   reader.GetEntry(iEvent);
   if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
   
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
   std::vector<ROOT::Math::XYZTVector> jets; 
   // clean jets
   for(unsigned int jetIt = 0; jetIt < (reader.Get4V("jets")->size()); ++jetIt)
   {
    ROOT::Math::XYZTVector jet = reader.Get4V("jets")->at(jetIt);
    if( jet.Et() < 10 ) continue;
    bool skipJet = false;
    for(unsigned int eleIt = 0; eleIt < electrons_jetCleaning.size(); ++eleIt)
    {
     ROOT::Math::XYZTVector ele = electrons_jetCleaning.at(eleIt);
     if(ROOT::Math::VectorUtil::DeltaR(jet,ele) < 0.3 ) skipJet = true;
    }
    if(skipJet == true) continue;
    jets.push_back( reader.Get4V("jets")->at(jetIt) );
   }
   ///========
   
   std::vector<ROOT::Math::XYZTVector>* mcQ1_tag = reader.Get4V("mcQ1_tag");
   std::vector<ROOT::Math::XYZTVector>* mcQ2_tag = reader.Get4V("mcQ2_tag");
   
//    std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
   
   std::vector<ROOT::Math::XYZTVector>* mcV1 = reader.Get4V("mcV1");
   std::vector<ROOT::Math::XYZTVector>* mcV2 = reader.Get4V("mcV2");
   
   std::vector<float>* mcV1_charge = reader.GetFloat("mcV1_charge");
   std::vector<float>* mcV2_charge = reader.GetFloat("mcV2_charge");
   
   std::vector<ROOT::Math::XYZTVector>* mcF1_fromV1 = reader.Get4V("mcF1_fromV1");
   std::vector<ROOT::Math::XYZTVector>* mcF1_fromV2 = reader.Get4V("mcF1_fromV2");
   std::vector<ROOT::Math::XYZTVector>* mcF2_fromV1 = reader.Get4V("mcF2_fromV1");
   std::vector<ROOT::Math::XYZTVector>* mcF2_fromV2 = reader.Get4V("mcF2_fromV2");
   
   std::vector<float>* mcF1_fromV1_pdgId = reader.GetFloat("mcF1_fromV1_pdgId");
   std::vector<float>* mcF1_fromV2_pdgId = reader.GetFloat("mcF1_fromV2_pdgId");
   std::vector<float>* mcF2_fromV1_pdgId = reader.GetFloat("mcF2_fromV1_pdgId");
   std::vector<float>* mcF2_fromV2_pdgId = reader.GetFloat("mcF2_fromV2_pdgId");
   
   ///---- find: q,q' ---- Pool ----
   
   
   mcQ_tag->clear();
   
   if (fabs(mcF1_fromV1_pdgId->at(0)) >= 11 && fabs(mcF1_fromV1_pdgId->at(0)) <= 14 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 && fabs(mcF1_fromV2_pdgId->at(0)) <= 14){//---- no tau considered!
    
    mcQ_tag->push_back(mcQ1_tag->at(0));
    mcQ_tag->push_back(mcQ2_tag->at(0));
    
    std::vector<int> matchIt;
    int matched = 0;
    matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(jets,*mcQ_tag,0.5,0.1,2.0,&matchIt);
    if (matched == 2){
     
     int nJets = jets.size();
     std::vector<int> blacklistJet;
     std::vector<int> whitelistJet;
     for (int iJet = 0; iJet < nJets; iJet++){
      if (jets.at(iJet).Pt() > 10) { ///==== selections on jets
       whitelistJet.push_back(1);
      }
      else {
       whitelistJet.push_back(0);
       blacklistJet.push_back(iJet);
      }
     }
     int nJets_preferred = getNumJets(whitelistJet);  
     if ( nJets_preferred >= 2 ){
      
      if (jets.at(matchIt.at(0)).Pt() > 10 && jets.at(matchIt.at(1)).Pt() > 10) { //---- only if the MC datasample has matched jets with pT > 10
       
       
       
       
       std::vector<int> it;
       double maxPt_selected = SelectJets(it,jets,"maxSumPt",0,&blacklistJet); ///== Et > 0    
       n_matched = CalculateMatch(matchIt,it);
       
//              std::cerr << "it[0] = " << it.at(0) << " = " << jets.at(it.at(0)).Pt();
//              std::cerr << "  it[1] = " << it.at(1) << " = " << jets.at(it.at(1)).Pt();
//              std::cerr << "  matchIt[0] = " << matchIt.at(0) << " = " << jets.at(matchIt.at(0)).Pt();;
//              std::cerr << "  matchIt[1] = " << matchIt.at(1) << " = " << jets.at(matchIt.at(1)).Pt();
// 	     std::cerr << " nJets = " << nJets;
	     std::cerr << " n_matched = " << n_matched << std::endl; 
       
       n_jets = nJets_preferred;
//        n_jets = jets.size();
       outTree.Fill();     
      }
     }
    }
   }
  }
  delete mcQ_tag;
  outFile.Write();   
  
  ///---- end test CUT ----
  ///----------------------
 }
 ///---- end test Identification -----
 ///----------------------------------
 }
 
 return 0;
}

