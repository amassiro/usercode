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


void Correct(std::vector<int> &matchIt){
 ///---- correct matchVector -> (1,2,4,3) => (1,2,3,4)
 if (matchIt.at(0) > matchIt.at(1)){
  double temp = matchIt.at(0);
  matchIt.at(0) = matchIt.at(1);
  matchIt.at(1) = temp;
 }
 if (matchIt.at(2) > matchIt.at(3)){
  double temp = matchIt.at(2);
  matchIt.at(2) = matchIt.at(3);
  matchIt.at(3) = temp;
 }
}

int CalculateMatch(std::vector<int> &matchIt,std::vector<int> & combination){
 int Match4 = 0;
 int q1 = combination.at(0);
 int q2 = combination.at(1);
 int b1 = combination.at(2);
 int b2 = combination.at(3);
 if (q1 == (matchIt.at(0)) || q1 == (matchIt.at(1))){
  Match4 ++;
 }
 if (q2 == (matchIt.at(0)) || q2 == (matchIt.at(1))){
  Match4 ++;
 }
 if (b1 == (matchIt.at(2)) || b1 == (matchIt.at(3))){
  Match4 ++;
 }
 if (b2 == (matchIt.at(2)) || b2 == (matchIt.at(3))){
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
 
 
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 std::string outputFileName    = gConfigParser -> readStringOption("Output::fileName");
 std::cout << ">>>>> output::fileName  " << outputFileName  << std::endl;  
 
 
 // Open ntple
 TChain* chain = new TChain(treeName.c_str());
 if(!FillChain(*chain, inputFileList.c_str())) return 1;
 treeReader reader((TTree*)(chain));
 
 int creator = gConfigParser -> readIntOption("Identificator::creator");
 std::cout << ">>>>> Identificator::creator  " << creator  << std::endl;  
 int algo = gConfigParser -> readIntOption("Identificator::algo");
 std::cout << ">>>>> Identificator::algo  " << algo  << std::endl;  
 
 TRandom3 myrand;
 
 if (creator == 1){
  ///----------------------------------------
  ///---- Tree producer for MVA training ----
  
  TFile outFile(outputFileName.c_str(),"RECREATE");
  TTree outTree("outTree","outTree");
  
  
  double pT_RECO_q1;
  double pT_RECO_q2;
  double pT_RECO_b1;
  double pT_RECO_b2;
  
  double DR_RECO_qq;
  double DR_RECO_qb;
  double DR_RECO_bb;
  
  double jets_trackCountingHighEffBJetTags_RECO_q1;
  double jets_trackCountingHighEffBJetTags_RECO_b1;
  double jets_trackCountingHighPurBJetTags_RECO_q1;
  double jets_trackCountingHighPurBJetTags_RECO_b1;
  double jets_simpleSecondaryVertexBJetTags_RECO_q1;
  double jets_simpleSecondaryVertexBJetTags_RECO_b1;
  double jets_combinedSecondaryVertexBJetTags_RECO_q1;
  double jets_combinedSecondaryVertexBJetTags_RECO_b1;
  double jets_combinedSecondaryVertexMVABJetTags_RECO_q1;
  double jets_combinedSecondaryVertexMVABJetTags_RECO_b1;
  
  double jets_trackCountingHighEffBJetTags_RECO_q2;
  double jets_trackCountingHighEffBJetTags_RECO_b2;
  double jets_trackCountingHighPurBJetTags_RECO_q2;
  double jets_trackCountingHighPurBJetTags_RECO_b2;
  double jets_simpleSecondaryVertexBJetTags_RECO_q2;
  double jets_simpleSecondaryVertexBJetTags_RECO_b2;
  double jets_combinedSecondaryVertexBJetTags_RECO_q2;
  double jets_combinedSecondaryVertexBJetTags_RECO_b2;
  double jets_combinedSecondaryVertexMVABJetTags_RECO_q2;
  double jets_combinedSecondaryVertexMVABJetTags_RECO_b2; 
  
  int Match4;
  
  outTree.Branch("pT_RECO_q1",&pT_RECO_q1,"pT_RECO_q1/D");
  outTree.Branch("pT_RECO_b1",&pT_RECO_b1,"pT_RECO_b1/D");
  outTree.Branch("pT_RECO_q2",&pT_RECO_q2,"pT_RECO_q2/D");
  outTree.Branch("pT_RECO_b2",&pT_RECO_b2,"pT_RECO_b2/D");
  outTree.Branch("DR_RECO_qq",&DR_RECO_qq,"DR_RECO_qq/D");
  outTree.Branch("DR_RECO_qb",&DR_RECO_qb,"DR_RECO_qb/D");
  outTree.Branch("DR_RECO_bb",&DR_RECO_bb,"DR_RECO_bb/D");
  
  outTree.Branch("jets_trackCountingHighEffBJetTags_RECO_q1",&jets_trackCountingHighEffBJetTags_RECO_q1,"jets_trackCountingHighEffBJetTags_RECO_q1/D");
  outTree.Branch("jets_trackCountingHighEffBJetTags_RECO_b1",&jets_trackCountingHighEffBJetTags_RECO_b1,"jets_trackCountingHighEffBJetTags_RECO_b1/D");
  outTree.Branch("jets_trackCountingHighPurBJetTags_RECO_q1",&jets_trackCountingHighPurBJetTags_RECO_q1,"jets_trackCountingHighPurBJetTags_RECO_q1/D");
  outTree.Branch("jets_trackCountingHighPurBJetTags_RECO_b1",&jets_trackCountingHighPurBJetTags_RECO_b1,"jets_trackCountingHighPurBJetTags_RECO_b1/D");
  outTree.Branch("jets_simpleSecondaryVertexBJetTags_RECO_q1",&jets_simpleSecondaryVertexBJetTags_RECO_q1,"jets_simpleSecondaryVertexBJetTags_RECO_q1/D");
  outTree.Branch("jets_simpleSecondaryVertexBJetTags_RECO_b1",&jets_simpleSecondaryVertexBJetTags_RECO_b1,"jets_simpleSecondaryVertexBJetTags_RECO_b1/D");
  
  outTree.Branch("jets_combinedSecondaryVertexBJetTags_RECO_q1",&jets_combinedSecondaryVertexBJetTags_RECO_q1,"jets_combinedSecondaryVertexBJetTags_RECO_q1/D");
  outTree.Branch("jets_combinedSecondaryVertexBJetTags_RECO_b1",&jets_combinedSecondaryVertexBJetTags_RECO_b1,"jets_combinedSecondaryVertexBJetTags_RECO_b1/D");
  outTree.Branch("jets_combinedSecondaryVertexMVABJetTags_RECO_q1",&jets_combinedSecondaryVertexMVABJetTags_RECO_q1,"jets_combinedSecondaryVertexMVABJetTags_RECO_q1/D");
  outTree.Branch("jets_combinedSecondaryVertexMVABJetTags_RECO_b1",&jets_combinedSecondaryVertexMVABJetTags_RECO_b1,"jets_combinedSecondaryVertexMVABJetTags_RECO_b1/D");
  
  outTree.Branch("jets_trackCountingHighEffBJetTags_RECO_q2",&jets_trackCountingHighEffBJetTags_RECO_q2,"jets_trackCountingHighEffBJetTags_RECO_q2/D");
  outTree.Branch("jets_trackCountingHighEffBJetTags_RECO_b2",&jets_trackCountingHighEffBJetTags_RECO_b2,"jets_trackCountingHighEffBJetTags_RECO_b2/D");
  outTree.Branch("jets_trackCountingHighPurBJetTags_RECO_q2",&jets_trackCountingHighPurBJetTags_RECO_q2,"jets_trackCountingHighPurBJetTags_RECO_q2/D");
  outTree.Branch("jets_trackCountingHighPurBJetTags_RECO_b2",&jets_trackCountingHighPurBJetTags_RECO_b2,"jets_trackCountingHighPurBJetTags_RECO_b2/D");
  outTree.Branch("jets_simpleSecondaryVertexBJetTags_RECO_q2",&jets_simpleSecondaryVertexBJetTags_RECO_q2,"jets_simpleSecondaryVertexBJetTags_RECO_q2/D");
  outTree.Branch("jets_simpleSecondaryVertexBJetTags_RECO_b2",&jets_simpleSecondaryVertexBJetTags_RECO_b2,"jets_simpleSecondaryVertexBJetTags_RECO_b2/D");
  
  outTree.Branch("jets_combinedSecondaryVertexBJetTags_RECO_q2",&jets_combinedSecondaryVertexBJetTags_RECO_q2,"jets_combinedSecondaryVertexBJetTags_RECO_q2/D");
  outTree.Branch("jets_combinedSecondaryVertexBJetTags_RECO_b2",&jets_combinedSecondaryVertexBJetTags_RECO_b2,"jets_combinedSecondaryVertexBJetTags_RECO_b2/D");
  outTree.Branch("jets_combinedSecondaryVertexMVABJetTags_RECO_q2",&jets_combinedSecondaryVertexMVABJetTags_RECO_q2,"jets_combinedSecondaryVertexMVABJetTags_RECO_q2/D");
  outTree.Branch("jets_combinedSecondaryVertexMVABJetTags_RECO_b2",&jets_combinedSecondaryVertexMVABJetTags_RECO_b2,"jets_combinedSecondaryVertexMVABJetTags_RECO_b2/D");
  
  outTree.Branch("Match4",&Match4,"Match4/I");
  
  std::cout << ">>>>> tree::entries " << chain -> GetEntries()  << std::endl;
  entryMAX = std::min (static_cast<int>(entryMAX),static_cast<int>(chain -> GetEntries()));
  
  double start, end;
  std::vector<ROOT::Math::XYZTVector>* mcF_fromVandB = new std::vector<ROOT::Math::XYZTVector>;
  
  start = clock();
  
  ///==================================
  ///==== Filling JetIdentificator ====
  
  for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent)
  {
   reader.GetEntry(iEvent);
   if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
   
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
   
   std::vector<ROOT::Math::XYZTVector>* mcB1 = reader.Get4V("mcB1");
   std::vector<ROOT::Math::XYZTVector>* mcB2 = reader.Get4V("mcB2");
   
   std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
   std::vector<float>* jets_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags");
   std::vector<float>* jets_trackCountingHighEffBJetTagsDR = reader.GetFloat("jets_trackCountingHighEffBJetTagsDR");
   std::vector<float>* jets_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags");
   std::vector<float>* jets_simpleSecondaryVertexBJetTags = reader.GetFloat("jets_simpleSecondaryVertexBJetTags");
   std::vector<float>* jets_combinedSecondaryVertexBJetTags = reader.GetFloat("jets_combinedSecondaryVertexBJetTags");
   std::vector<float>* jets_combinedSecondaryVertexMVABJetTags = reader.GetFloat("jets_combinedSecondaryVertexMVABJetTags");
   
   
   ///---- find: q,q', b1, b2 ---- Pool ----
   
   mcF_fromVandB->clear();
   if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
    mcF_fromVandB->push_back(mcF1_fromV1->at(0));
    mcF_fromVandB->push_back(mcF2_fromV1->at(0));
   } else if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4 && fabs(mcF1_fromV1_pdgId->at(0)) >= 11 ){
    mcF_fromVandB->push_back(mcF1_fromV2->at(0));
    mcF_fromVandB->push_back(mcF2_fromV2->at(0));
   }
   
   mcF_fromVandB->push_back(mcB1->at(0));
   mcF_fromVandB->push_back(mcB2->at(0));
   
   if ( mcF_fromVandB->size() == 4 ){//---- only if at MC level found bb + qq' + (lnu) ----
    std::vector<int> matchIt;
    int matched = 0;
    matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromVandB,0.3,0.1,2.0,&matchIt);
    if (matched == 4){
     int doSig_doBkg = myrand.Uniform(-1,1); // <0 == bkg, >=0 == sig    
     
     ///---- correct matchVector -> (1,2,4,3) => (1,2,3,4)
     Correct(matchIt);
     
     std::vector<std::vector<int> > combinations;
     int nJets = jets->size();
     int buffer = Build4JetCombinations(combinations,nJets);
     std::cerr << " buffer = " << buffer << std::endl;
     /// combinations[i] ==> (0,1,2,3)
     /// combinations[i] ==> (0,1,2,4)
     /// combinations[i] ==> (0,1,2,5) 
     /// combinations[i] ==> ... and so on ...
     int nComb = combinations.size();
     std::cerr << " nJets = " << nJets << " ==> nComb = " << nComb << std::endl; 
     int numSelectedCombination = myrand.Uniform(0,nComb);
     
     for (int iComb = 0; iComb<nComb; iComb++){
      
      Match4 = CalculateMatch(matchIt,combinations.at(iComb));
      
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
      
      if (algo == 0){
       /// 0 all jet combinations
       outTree.Fill();
      }
      
      if (algo == 1){
       /// 1 one jet combination       
       if (numSelectedCombination == iComb) outTree.Fill();
      }
      
      if (algo == 2){
       /// 2 random signal/background then all combinations
       if (doSig_doBkg>=0){//---- Sig
	if (Match4==4) outTree.Fill();
       }
       else if (doSig_doBkg<0){ //---- Bkg
	if (Match4!=4) outTree.Fill();
       }
      }
      
      if (algo == 3){
       /// 3 random signal/background then one combination
       if (doSig_doBkg>=0){//---- Sig
	if (Match4==4) outTree.Fill();
       }
       else if (doSig_doBkg<0){ //---- Bkg
	if (Match4!=4 && numSelectedCombination == iComb) outTree.Fill(); ///---- NB: you are rejecting ONE bkg event if _numSelectedCombination_ is the signal combination ---> who cares! ~ Nothing changes! 
       }
      }
     }   
    }
   }
  } //loop over the events 
  end = clock();
  std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
  ///==== end Filling JetIdentificator ====
  ///======================================
  
  delete mcF_fromVandB;
  outFile.Write();   
  
  ///---- end Tree producer for MVA training ----
  ///--------------------------------------------
 }
 else if (creator == 0){
  ///------------------
  ///---- test MVA ----
  std::string OutFileName    = gConfigParser -> readStringOption("Identificator::OutFileName");
  std::cout << ">>>>> Identificator::OutFileName  " << OutFileName  << std::endl;  
  TFile outFile(OutFileName.c_str(),"RECREATE");
  
  TTree outTree("outTree","outTree");
  int n_matched;
  int n_jets;
  outTree.Branch("n_matched",&n_matched,"n_matched/I");
  outTree.Branch("n_jets",&n_jets,"n_jets/I");
  
  std::vector<std::string> theInputVars;
  theInputVars.push_back("pT_RECO_q1");
  theInputVars.push_back("pT_RECO_q2");
  theInputVars.push_back("pT_RECO_b1");
  theInputVars.push_back("pT_RECO_b2");
  theInputVars.push_back("DR_RECO_qq");
  theInputVars.push_back("DR_RECO_qb");
  theInputVars.push_back("DR_RECO_bb");
  theInputVars.push_back("jets_trackCountingHighEffBJetTags_RECO_q1");
  theInputVars.push_back("jets_trackCountingHighEffBJetTags_RECO_b1");
  theInputVars.push_back("jets_trackCountingHighEffBJetTags_RECO_q2");
  theInputVars.push_back("jets_trackCountingHighEffBJetTags_RECO_b2");
  
//   TMVA::Reader *TMVAreader = new TMVA::Reader( "!Color:!Silent" );
//   ReadBDT* TMVAreader = new ReadBDT(theInputVars);
  
  double pT_RECO_q1;
  double pT_RECO_q2;
  double pT_RECO_b1;
  double pT_RECO_b2;
  
  double DR_RECO_qq;
  double DR_RECO_qb;
  double DR_RECO_bb;
  
  double jets_trackCountingHighEffBJetTags_RECO_q1;
  double jets_trackCountingHighEffBJetTags_RECO_b1;
  double jets_trackCountingHighPurBJetTags_RECO_q1;
  double jets_trackCountingHighPurBJetTags_RECO_b1;
  double jets_simpleSecondaryVertexBJetTags_RECO_q1;
  double jets_simpleSecondaryVertexBJetTags_RECO_b1;
  double jets_combinedSecondaryVertexBJetTags_RECO_q1;
  double jets_combinedSecondaryVertexBJetTags_RECO_b1;
  double jets_combinedSecondaryVertexMVABJetTags_RECO_q1;
  double jets_combinedSecondaryVertexMVABJetTags_RECO_b1;
  
  double jets_trackCountingHighEffBJetTags_RECO_q2;
  double jets_trackCountingHighEffBJetTags_RECO_b2;
  double jets_trackCountingHighPurBJetTags_RECO_q2;
  double jets_trackCountingHighPurBJetTags_RECO_b2;
  double jets_simpleSecondaryVertexBJetTags_RECO_q2;
  double jets_simpleSecondaryVertexBJetTags_RECO_b2;
  double jets_combinedSecondaryVertexBJetTags_RECO_q2;
  double jets_combinedSecondaryVertexBJetTags_RECO_b2;
  double jets_combinedSecondaryVertexMVABJetTags_RECO_q2;
  double jets_combinedSecondaryVertexMVABJetTags_RECO_b2; 
  
  
  double start, end;
  std::vector<ROOT::Math::XYZTVector>* mcF_fromVandB = new std::vector<ROOT::Math::XYZTVector>;
  
  start = clock();
  for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent)
  {
   reader.GetEntry(iEvent);
   if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
   
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
   
   std::vector<ROOT::Math::XYZTVector>* mcB1 = reader.Get4V("mcB1");
   std::vector<ROOT::Math::XYZTVector>* mcB2 = reader.Get4V("mcB2");
   
   std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
   std::vector<float>* jets_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags");
   std::vector<float>* jets_trackCountingHighEffBJetTagsDR = reader.GetFloat("jets_trackCountingHighEffBJetTagsDR");
   std::vector<float>* jets_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags");
   std::vector<float>* jets_simpleSecondaryVertexBJetTags = reader.GetFloat("jets_simpleSecondaryVertexBJetTags");
   std::vector<float>* jets_combinedSecondaryVertexBJetTags = reader.GetFloat("jets_combinedSecondaryVertexBJetTags");
   std::vector<float>* jets_combinedSecondaryVertexMVABJetTags = reader.GetFloat("jets_combinedSecondaryVertexMVABJetTags");
   
   
   ///---- find: q,q', b1, b2 ---- Pool ----
   
   mcF_fromVandB->clear();
   if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
    mcF_fromVandB->push_back(mcF1_fromV1->at(0));
    mcF_fromVandB->push_back(mcF2_fromV1->at(0));
   } else if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4 && fabs(mcF1_fromV1_pdgId->at(0)) >= 11 ){
    mcF_fromVandB->push_back(mcF1_fromV2->at(0));
    mcF_fromVandB->push_back(mcF2_fromV2->at(0));
   }
   
   mcF_fromVandB->push_back(mcB1->at(0));
   mcF_fromVandB->push_back(mcB2->at(0));
   
   if ( mcF_fromVandB->size() == 4 ){//---- only if at MC level found bb + qq' + (lnu) ----
    double TMVA_value = -100000000;
    int MVACombination = -1;
    
    std::vector<int> matchIt;
    int matched = 0;
    matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromVandB,0.3,0.1,2.0,&matchIt);
    if (matched == 4){
     int doSig_doBkg = myrand.Uniform(-1,1); // <0 == bkg, >=0 == sig    
     Correct(matchIt);
     
     std::vector<std::vector<int> > combinations;
     int nJets = jets->size();
     int buffer = Build4JetCombinations(combinations,nJets);
     std::cerr << " buffer = " << buffer << std::endl;
     int nComb = combinations.size();
     std::cerr << " nJets = " << nJets << " ==> nComb = " << nComb << std::endl; 
     int numSelectedCombination = myrand.Uniform(0,nComb);
     
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
      
      std::vector<double> inputValues;
      inputValues.push_back(pT_RECO_q1);
      inputValues.push_back(pT_RECO_q2);
      inputValues.push_back(pT_RECO_b1);
      inputValues.push_back(pT_RECO_b2);
      inputValues.push_back(DR_RECO_qq);
      inputValues.push_back(DR_RECO_qb);
      inputValues.push_back(DR_RECO_bb);
      inputValues.push_back(jets_trackCountingHighEffBJetTags_RECO_q1);
      inputValues.push_back(jets_trackCountingHighEffBJetTags_RECO_b1);
      inputValues.push_back(jets_trackCountingHighEffBJetTags_RECO_q2);
      inputValues.push_back(jets_trackCountingHighEffBJetTags_RECO_b2);
      
//       double MVA_temp = TMVAreader->GetMvaValue(inputValues) ;
//       if (MVA_temp > TMVA_value) {
//        TMVA_value = MVA_temp;
//        MVACombination = iComb;
//       }



     }

     n_matched = CalculateMatch(matchIt,combinations.at(MVACombination));
     n_jets = jets->size();
     outTree.Fill();     
    }
   }
  } //loop over the events 
  end = clock();
  std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
  delete mcF_fromVandB;  
  ///---- end test MVA ----
  ///----------------------
 }
 
 return 0;
}



