/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_MC_6 `root-config --cflags --glibs` -lGenVector TT_MC_6.cpp dict.cpp treeReader.cc
*/

#include "treeReader.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"

#include "Math/GenVector/VectorUtil.h"

#include <time.h>

int main (int argc, char ** argv)
{
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 
 treeReader reader (tr) ;
 
 TFile outFile("output/outFile.root","RECREATE");
 
 TH1F M_lept("M_lept","M_lept",1000,0,200);
 TH1F M_had("M_had","M_had",1000,0,200);
 
 TH1F M_reco_lept("M_reco_lept","M_reco_lept",1000,0,200);
 TH1F M_reco_had("M_reco_had","M_reco_had",1000,0,200);
 
 TH1F pt_Wplus("pt_Wplus","pt_Wplus",1000,0,1000);
 TH1F pt_Wminus("pt_Wminus","pt_Wminus",1000,0,1000);
 
 
 double start, end;
 
 int nentries =  tr->GetEntries ();
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
  
  
  if (mcV1_charge->at(0)>0) pt_Wplus.Fill(mcV1->at(0).Pt());
  else pt_Wminus.Fill(mcV1->at(0).Pt());
  if (mcV2_charge->at(0)>0) pt_Wplus.Fill(mcV2->at(0).Pt());
  else pt_Wminus.Fill(mcV2->at(0).Pt());
  
  
  
  if (fabs(mcF1_fromV1_pdgId->at(0)) >= 11){
   M_reco_lept.Fill((mcF1_fromV1->at(0) + mcF2_fromV1->at(0)).M());
  }
  else {
   M_reco_had.Fill((mcF1_fromV1->at(0) + mcF2_fromV1->at(0)).M());
  }
  
  if (fabs(mcF1_fromV2_pdgId->at(0)) >= 11){
   M_reco_lept.Fill((mcF1_fromV2->at(0) + mcF2_fromV2->at(0)).M());
  }
  else {
   M_reco_had.Fill((mcF1_fromV2->at(0) + mcF2_fromV2->at(0)).M());
  }
  
  ///---- W ----
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4){
   M_had.Fill(mcV1->at(0).M());
  }
  else {
   M_lept.Fill(mcV1->at(0).M());
  }
  
  if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4){
   M_had.Fill(mcV2->at(0).M());
  }
  else {
   M_lept.Fill(mcV2->at(0).M());
  }
  
 }    
 
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 
 return 0 ;
}