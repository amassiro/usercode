/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_MC `root-config --cflags --glibs` -lGenVector TT_MC.cpp dict.cpp treeReader.cc
*/

#include "treeReader.h"
#include "TH1F.h"
#include "TFile.h"

int main (int argc, char ** argv)
{
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 
 treeReader reader (tr) ;
 
 TFile outFile("data/outFile.root","RECREATE");
 TH1F pt_lept("pt_lept","pt_lept",1000,0,1000);
 TH1F pt_ele("pt_ele","pt_ele",1000,0,1000);
 TH1F pt_mu("pt_mu","pt_mu",1000,0,1000);
 TH1F pt_nu("pt_nu","pt_nu",1000,0,1000);
 TH1F pt_had("pt_had","pt_had",1000,0,1000);
 
 
 for (int iEvent = 0 ; iEvent < tr->GetEntries () ; ++iEvent)
 {
  reader.GetEntry (iEvent) ;
  std::vector<ROOT::Math::XYZTVector>* mcF1_fromV1 = reader.Get4V("mcF1_fromV1");
  std::vector<ROOT::Math::XYZTVector>* mcF1_fromV2 = reader.Get4V("mcF1_fromV2");
  std::vector<ROOT::Math::XYZTVector>* mcF2_fromV1 = reader.Get4V("mcF2_fromV1");
  std::vector<ROOT::Math::XYZTVector>* mcF2_fromV2 = reader.Get4V("mcF2_fromV2");
  
  std::vector<float>* mcF1_fromV1_pdgId = reader.GetFloat("mcF1_fromV1_pdgId");
  std::vector<float>* mcF1_fromV2_pdgId = reader.GetFloat("mcF1_fromV2_pdgId");
  std::vector<float>* mcF2_fromV1_pdgId = reader.GetFloat("mcF2_fromV1_pdgId");
  std::vector<float>* mcF2_fromV2_pdgId = reader.GetFloat("mcF2_fromV2_pdgId");
  
  
  ///---- ele ----
  if (fabs(mcF1_fromV1_pdgId->at(0)) == 11){
   pt_lept.Fill(mcF1_fromV1->at(0).Pt());
   pt_ele.Fill(mcF1_fromV1->at(0).Pt());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) == 11){
   pt_lept.Fill(mcF1_fromV2->at(0).Pt());
   pt_ele.Fill(mcF1_fromV2->at(0).Pt());
  }
  if (fabs(mcF2_fromV1_pdgId->at(0)) == 11){
   pt_lept.Fill(mcF2_fromV1->at(0).Pt());
   pt_ele.Fill(mcF2_fromV1->at(0).Pt());
  }
  if (fabs(mcF2_fromV2_pdgId->at(0)) == 11){
   pt_lept.Fill(mcF2_fromV2->at(0).Pt());
   pt_ele.Fill(mcF2_fromV2->at(0).Pt());
  }
  
  ///---- mu ----
  if (fabs(mcF1_fromV1_pdgId->at(0)) == 13){
   pt_lept.Fill(mcF1_fromV1->at(0).Pt());
   pt_mu.Fill(mcF1_fromV1->at(0).Pt());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) == 13){
   pt_lept.Fill(mcF1_fromV2->at(0).Pt());
   pt_mu.Fill(mcF1_fromV2->at(0).Pt());
  }
  if (fabs(mcF2_fromV1_pdgId->at(0)) == 13){
   pt_lept.Fill(mcF2_fromV1->at(0).Pt());
   pt_mu.Fill(mcF2_fromV1->at(0).Pt());
  }
  if (fabs(mcF2_fromV2_pdgId->at(0)) == 13){
   pt_lept.Fill(mcF2_fromV2->at(0).Pt());
   pt_mu.Fill(mcF2_fromV2->at(0).Pt());
  }
  
  ///---- nu ----
  if (fabs(mcF1_fromV1_pdgId->at(0)) == 12 || fabs(mcF1_fromV1_pdgId->at(0)) == 14){
   pt_lept.Fill(mcF1_fromV1->at(0).Pt());
   pt_nu.Fill(mcF1_fromV1->at(0).Pt());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) == 12 || fabs(mcF1_fromV2_pdgId->at(0)) == 14){
   pt_lept.Fill(mcF1_fromV2->at(0).Pt());
   pt_nu.Fill(mcF1_fromV2->at(0).Pt());
  }
  if (fabs(mcF2_fromV1_pdgId->at(0)) == 12 || fabs(mcF2_fromV1_pdgId->at(0)) == 14){
   pt_lept.Fill(mcF2_fromV1->at(0).Pt());
   pt_nu.Fill(mcF2_fromV1->at(0).Pt());
  }
  if (fabs(mcF2_fromV2_pdgId->at(0)) == 12 || fabs(mcF2_fromV2_pdgId->at(0)) == 14){
   pt_lept.Fill(mcF2_fromV2->at(0).Pt());
   pt_nu.Fill(mcF2_fromV2->at(0).Pt());
  }
  
  ///---- had ----
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4){
   pt_had.Fill(mcF1_fromV1->at(0).Pt());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4){
   pt_had.Fill(mcF1_fromV2->at(0).Pt());
  }
  if (fabs(mcF2_fromV1_pdgId->at(0)) <= 4){
   pt_had.Fill(mcF1_fromV2->at(0).Pt());
  }
  if (fabs(mcF2_fromV2_pdgId->at(0)) <= 4){
   pt_had.Fill(mcF1_fromV2->at(0).Pt());
  }
 }      
 outFile.Write();   
 
 return 0 ;
}