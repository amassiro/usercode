/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o W_MC_1 `root-config --cflags --glibs` -lGenVector W_MC_1.cpp dict.cpp treeReader.cc
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
 
 TH2F p_pdgId("p_pdgId","p_pdgId",1000,0,1000,400,-100,100);
 
 TH1F pdgId("pdgId","pdgId",400,-100,100);
 
 TH2F pt_12("pt_12","pt_12",1000,0,1000,1000,0,1000);
 
 double start, end;
 
 int nentries =  tr->GetEntries ();
 std::cerr << "nentries = " << nentries << std::endl;
 start = clock();
 for (int iEvent = 0 ; iEvent < nentries ; ++iEvent)
 {
  reader.GetEntry (iEvent) ;
  std::vector<ROOT::Math::XYZTVector>* mcV = reader.Get4V("mcV");
  
  std::vector<ROOT::Math::XYZTVector>* mcF1_fromV = reader.Get4V("mcF1_fromV");
  std::vector<ROOT::Math::XYZTVector>* mcF2_fromV = reader.Get4V("mcF2_fromV");
  
  std::vector<float>* mcF1_fromV_pdgId = reader.GetFloat("mcF1_fromV_pdgId");
  std::vector<float>* mcF2_fromV_pdgId = reader.GetFloat("mcF2_fromV_pdgId");
  
  
  
  
  if (fabs(mcF1_fromV_pdgId->at(0)) >= 11){
   M_reco_lept.Fill((mcF1_fromV->at(0) + mcF2_fromV->at(0)).M());
  }
  else {
   M_reco_had.Fill((mcF1_fromV->at(0) + mcF2_fromV->at(0)).M());
  }
  
  ///---- W ----
  if (fabs(mcF1_fromV_pdgId->at(0)) <= 4){
   M_had.Fill(mcV->at(0).M());
  }
  else {
   M_lept.Fill(mcV->at(0).M());
  }
  
  p_pdgId.Fill(mcF1_fromV->at(0).P(),mcF1_fromV_pdgId->at(0));
  p_pdgId.Fill(mcF2_fromV->at(0).P(),mcF2_fromV_pdgId->at(0));
  
  pdgId.Fill(mcF1_fromV_pdgId->at(0));
  pdgId.Fill(mcF2_fromV_pdgId->at(0));
  
  pt_12.Fill(mcF1_fromV->at(0).Pt(),mcF2_fromV->at(0).Pt());
  
  
 }    
 
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 
 return 0 ;
}