/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_GEN_1 `root-config --cflags --glibs` -lGenVector TT_GEN_1.cpp dict.cpp treeReader.cc
*/

#include "treeReader.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"

#include "Math/GenVector/VectorUtil.h"

#include "include/Utils.cc"

#include <time.h>

int main (int argc, char ** argv)
{
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 
 treeReader reader (tr) ;
 
 TFile outFile("output/outFile_GEN_1.root","RECREATE");
 
 TH1F M_MC("M_MC","M_MC",1000,0,200);
 TH1F M_GEN("M_GEN","M_GEN",1000,0,200);

 TH1F PtOverPt_GENMC("PtOverPt_GENMC","PtOverPt_GENMC",1000,0,4);
 
 
 double start, end;
 
 int nentries =  tr->GetEntries ();
 std::cerr << "nentries = " << nentries << std::endl;
 if (argc == 4) nentries = atoi(argv[3]);
 std::cerr << "nentries = " << nentries << std::endl;
 
 start = clock();
 for (int iEvent = 0 ; iEvent < nentries ; ++iEvent)
 {
  reader.GetEntry (iEvent) ;
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
  
  std::vector<ROOT::Math::XYZTVector>* GenJets = reader.Get4V("genJets");
  
  std::vector<ROOT::Math::XYZTVector>* mcF_fromV1 = new std::vector<ROOT::Math::XYZTVector>;
  mcF_fromV1->push_back(mcF1_fromV1->at(0));
  mcF_fromV1->push_back(mcF2_fromV1->at(0));
  std::vector<ROOT::Math::XYZTVector>* mcF_fromV2 = new std::vector<ROOT::Math::XYZTVector>;
  mcF_fromV2->push_back(mcF1_fromV2->at(0));
  mcF_fromV2->push_back(mcF2_fromV2->at(0));
  
  std::vector<int> matchIt;
  int matched = 0;
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
   matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*GenJets,*mcF_fromV1,0.3,0.1,2.0,&matchIt);
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4 && fabs(mcF1_fromV1_pdgId->at(0)) >= 11 ){
   matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*GenJets,*mcF_fromV2,0.3,0.1,2.0,&matchIt);
  }
  
  if (matched > 0){
   if (matched == 2){
    M_GEN.Fill((GenJets->at(matchIt.at(0)) + GenJets->at(matchIt.at(1))).M());
    if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
     PtOverPt_GENMC.Fill(GenJets->at(matchIt.at(0)).Pt() / mcF_fromV1->at(0).Pt() );
     PtOverPt_GENMC.Fill(GenJets->at(matchIt.at(1)).Pt() / mcF_fromV1->at(1).Pt() );
    }
    else {
     PtOverPt_GENMC.Fill(GenJets->at(matchIt.at(0)).Pt() / mcF_fromV2->at(0).Pt() );
     PtOverPt_GENMC.Fill(GenJets->at(matchIt.at(1)).Pt() / mcF_fromV2->at(1).Pt() );
    }
   }
  }
  
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
   M_MC.Fill((mcF1_fromV2->at(0) + mcF2_fromV2->at(0)).M());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4 && fabs(mcF1_fromV1_pdgId->at(0)) >= 11 ){
   M_MC.Fill((mcF1_fromV1->at(0) + mcF2_fromV1->at(0)).M());
  }
  
  delete mcF_fromV1;
  delete mcF_fromV2;
 }    
 
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 
 return 0 ;
}