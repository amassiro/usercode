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
 ///---- correct matchVector -> (1,3,2) => (1,2,3)
 if (matchIt.at(1) > matchIt.at(2)){
  double temp = matchIt.at(1);
  matchIt.at(1) = matchIt.at(2);
  matchIt.at(2) = temp;
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
 
 
 std::cout << ">>>>> input::entryMIN  " << entryMIN  << std::endl;  
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 // Open ntple
 TChain* chain = new TChain(treeName.c_str());
 if(!FillChain(*chain, inputFileList.c_str())) return 1;
 treeReader reader((TTree*)(chain));
 
 
 std::string outputFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << outputFileName  << std::endl;  
 
 TFile outFile(outputFileName.c_str(),"RECREATE");
 TTree outTree("outTree","outTree");
 
 
 double pT_RECO_qTau;
 int nEle;
 int nMu;
 int nLept;
 int nJet;
 double pT_RECO_JetTau;
 double minPtJet;
 double maxPtJet;
 
 outTree.Branch("pT_RECO_qTau",&pT_RECO_qTau,"pT_RECO_qTau/D");
 outTree.Branch("pT_RECO_JetTau",&pT_RECO_JetTau,"pT_RECO_JetTau/D");
 outTree.Branch("nEle",&nEle,"nEle/I");
 outTree.Branch("nMu",&nMu,"nMu/I");
 outTree.Branch("nLept",&nLept,"nLept/I");
 outTree.Branch("nJet",&nJet,"nJet/I");
 outTree.Branch("minPtJet",&minPtJet,"minPtJet/D");
 outTree.Branch("maxPtJet",&maxPtJet,"maxPtJet/D");
 
 std::cout << ">>>>> tree::entries " << chain -> GetEntries()  << std::endl;
 entryMAX = std::min (static_cast<int>(entryMAX),static_cast<int>(chain -> GetEntries()));
 
 double start, end;
 std::vector<ROOT::Math::XYZTVector>* mcF_fromVandB = new std::vector<ROOT::Math::XYZTVector>;
 std::vector<ROOT::Math::XYZTVector>* mcF_fromWlnu = new std::vector<ROOT::Math::XYZTVector>;
 
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
  
  std::vector<ROOT::Math::XYZTVector>* electrons = reader.Get4V("electrons");
  std::vector<ROOT::Math::XYZTVector>* muons = reader.Get4V("muons");
  
  std::vector<float>* mcFX_fromV1_TauJet_pfgId            = reader.GetFloat("mcFX_fromV1_TauJet_pfgId");
  std::vector<ROOT::Math::XYZTVector>* mcFX_fromV1_TauJet = reader.Get4V("mcFX_fromV1_TauJet");
  std::vector<float>* mcFX_fromV2_TauJet_pfgId            = reader.GetFloat("mcFX_fromV2_TauJet_pfgId");
  std::vector<ROOT::Math::XYZTVector>* mcFX_fromV2_TauJet = reader.Get4V("mcFX_fromV2_TauJet");
  
  ROOT::Math::XYZTVector tau;    
  
  
  ///---- find: q,q', b1, b2 ---- Pool ----
  
  int tauDecay = 0;
  mcF_fromWlnu->clear();
  mcF_fromVandB->clear();
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 16 && fabs(mcF1_fromV1_pdgId->at(0)) >=15 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 && fabs(mcF1_fromV2_pdgId->at(0)) <= 14){ //---- V1-> tau nu   V2-> lnu with l!=tau
   if (fabs(mcF1_fromV1_pdgId->at(0)) == 15){
//     mcF_fromVandB->push_back(mcF1_fromV1->at(0));
    tauDecay = 0;
    for (int iTau = 0; iTau < mcFX_fromV1_TauJet->size(); iTau++){
     tau += mcFX_fromV1_TauJet->at(iTau);
     if (fabs(mcFX_fromV1_TauJet_pfgId->at(iTau)) >= 14) tauDecay = 1;
    }
    if (tauDecay == 1) mcF_fromVandB->push_back(tau);
   }
   else {
//     mcF_fromVandB->push_back(mcF2_fromV1->at(0));
    tauDecay = 0;
    for (int iTau = 0; iTau < mcFX_fromV1_TauJet->size(); iTau++){
     tau += mcFX_fromV1_TauJet->at(iTau);
     if (fabs(mcFX_fromV1_TauJet_pfgId->at(iTau)) >= 14) tauDecay = 1;
    }
    if (tauDecay == 1) mcF_fromVandB->push_back(tau);
   }
   mcF_fromWlnu->push_back(mcF1_fromV2->at(0));
   mcF_fromWlnu->push_back(mcF2_fromV2->at(0));
  }
  else if (fabs(mcF1_fromV2_pdgId->at(0)) <= 16 && fabs(mcF1_fromV2_pdgId->at(0)) >= 15 && fabs(mcF1_fromV1_pdgId->at(0)) >= 11 && fabs(mcF1_fromV1_pdgId->at(0)) <= 14 ){ //---- V2-> tau nu   V1-> lnu with l!=tau
   if (fabs(mcF1_fromV2_pdgId->at(0)) == 15){
//     mcF_fromVandB->push_back(mcF1_fromV2->at(0));
    tauDecay = 0;
    for (int iTau = 0; iTau < mcFX_fromV2_TauJet->size(); iTau++){
     tau += mcFX_fromV2_TauJet->at(iTau);
     if (fabs(mcFX_fromV2_TauJet_pfgId->at(iTau)) >= 14) tauDecay = 1;
    }
    if (tauDecay == 1) mcF_fromVandB->push_back(tau);
   }
   else {
//     mcF_fromVandB->push_back(mcF2_fromV2->at(0));
    tauDecay = 0;
    for (int iTau = 0; iTau < mcFX_fromV2_TauJet->size(); iTau++){
     tau += mcFX_fromV2_TauJet->at(iTau);
     if (fabs(mcFX_fromV2_TauJet_pfgId->at(iTau)) >= 14) tauDecay = 1;
    }
    if (tauDecay == 1) mcF_fromVandB->push_back(tau);
   }
   mcF_fromWlnu->push_back(mcF1_fromV1->at(0));
   mcF_fromWlnu->push_back(mcF2_fromV1->at(0));
  }
  
  mcF_fromVandB->push_back(mcB1->at(0));
  mcF_fromVandB->push_back(mcB2->at(0));
  
  
  if ( mcF_fromVandB->size() == 3 ){//---- only if at MC level found bb + tau + (lnu) ----
   std::vector<int> matchIt;
   int matched = 0;
   matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromVandB,0.3,0.1,2.0,&matchIt);
   if (matched == 3){
    Correct(matchIt);
    
    int qTau = matchIt.at(0);
    int b1 = matchIt.at(1);
    int b2 = matchIt.at(2);    
    
    
    pT_RECO_qTau = jets->at(qTau).Pt();
    
    nEle  = electrons->size();
    nMu   = muons->size();
    nLept = nEle + nMu;
    nJet  = jets->size();

    pT_RECO_JetTau = tau.Pt();

    maxPtJet = -10000000;
    minPtJet = 10000000;

    for (int ij =0; ij<jets->size(); ij++){
     if (ij != b1 && ij != b2 && ij != qTau){
      if (jets->at(ij).Pt() >= maxPtJet) maxPtJet = jets->at(ij).Pt();
      if (jets->at(ij).Pt() <= minPtJet) minPtJet = jets->at(ij).Pt();
     }
    }
    
    outTree.Fill();    
   }
  }
 } //loop over the events 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 delete mcF_fromVandB;  
 delete mcF_fromWlnu;  
 
 outFile.Write();   
 
 return 0;
}



