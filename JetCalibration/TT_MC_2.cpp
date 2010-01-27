/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_MC_2 `root-config --cflags --glibs` -lGenVector TT_MC_2.cpp dict.cpp treeReader.cc
*/

#include "treeReader.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"

#include "Math/GenVector/VectorUtil.h"

#include <time.h>

int main (int argc, char ** argv)
{
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 
 treeReader reader (tr) ;
 
 TFile outFile("output/outFile.root","RECREATE");
 TH2F p_eta_lept("p_eta_lept","p_eta_lept",1000,0,1000,100,0,10);
 TH2F pt_eta_lept("pt_eta_lept","pt_eta_lept",1000,0,1000,100,0,10);
 
 TH1F p_lept("p_lept","p_lept",1000,0,1000);
 TH1F p_ele("p_ele","p_ele",1000,0,1000);
 TH1F p_mu("p_mu","p_mu",1000,0,1000);
 TH1F p_nu("p_nu","p_nu",1000,0,1000);
 TH1F p_had("p_had","p_had",1000,0,1000);
 
 TH1F pt_lept("pt_lept","pt_lept",1000,0,1000);
 TH1F pt_ele("pt_ele","pt_ele",1000,0,1000);
 TH1F pt_mu("pt_mu","pt_mu",1000,0,1000);
 TH1F pt_nu("pt_nu","pt_nu",1000,0,1000);
 TH1F pt_had("pt_had","pt_had",1000,0,1000);
 TH1F pt_W_had("pt_W_had","pt_W_had",1000,0,1000);
 TH1F pt_W_lept("pt_W_lept","pt_W_lept",1000,0,1000);

 TH1F DPhi_had("DPhi_had","DPhi_had",1000,0,10);
 TH1F DPhi_lept("DPhi_lept","DPhi_lept",1000,0,10);
 TH1F DEta_had("DEta_had","DEta_had",1000,0,10);
 TH1F DEta_lept("DEta_lept","DEta_lept",1000,0,10);
 
 TH1F Eta_had("Eta_had","Eta_had",1000,0,10);
 TH1F Eta_lept("Eta_lept","Eta_lept",1000,0,10);
 
 double start, end;
 
 int nentries =  tr->GetEntries ();
 std::cerr << "nentries = " << nentries << std::endl;
 start = clock();
 for (int iEvent = 0 ; iEvent < nentries ; ++iEvent)
 {
  reader.GetEntry (iEvent) ;
  std::vector<ROOT::Math::XYZTVector>* mcV1 = reader.Get4V("mcV1");
  std::vector<ROOT::Math::XYZTVector>* mcV2 = reader.Get4V("mcV2");

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
   p_lept.Fill(mcF1_fromV1->at(0).P());
   p_ele.Fill(mcF1_fromV1->at(0).P());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) == 11){
   pt_lept.Fill(mcF1_fromV2->at(0).Pt());
   pt_ele.Fill(mcF1_fromV2->at(0).Pt());
   p_lept.Fill(mcF1_fromV2->at(0).P());
   p_ele.Fill(mcF1_fromV2->at(0).P());
  }
  if (fabs(mcF2_fromV1_pdgId->at(0)) == 11){
   pt_lept.Fill(mcF2_fromV1->at(0).Pt());
   pt_ele.Fill(mcF2_fromV1->at(0).Pt());
   p_lept.Fill(mcF2_fromV1->at(0).P());
   p_ele.Fill(mcF2_fromV1->at(0).P());
  }
  if (fabs(mcF2_fromV2_pdgId->at(0)) == 11){
   pt_lept.Fill(mcF2_fromV2->at(0).Pt());
   pt_ele.Fill(mcF2_fromV2->at(0).Pt());
   p_lept.Fill(mcF2_fromV2->at(0).P());
   p_ele.Fill(mcF2_fromV2->at(0).P());
  }
  
  ///---- mu ----
  if (fabs(mcF1_fromV1_pdgId->at(0)) == 13){
   pt_lept.Fill(mcF1_fromV1->at(0).Pt());
   pt_mu.Fill(mcF1_fromV1->at(0).Pt());
   p_lept.Fill(mcF1_fromV1->at(0).P());
   p_mu.Fill(mcF1_fromV1->at(0).P());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) == 13){
   pt_lept.Fill(mcF1_fromV2->at(0).Pt());
   pt_mu.Fill(mcF1_fromV2->at(0).Pt());
   p_lept.Fill(mcF1_fromV2->at(0).P());
   p_mu.Fill(mcF1_fromV2->at(0).P());
  }
  if (fabs(mcF2_fromV1_pdgId->at(0)) == 13){
   pt_lept.Fill(mcF2_fromV1->at(0).Pt());
   pt_mu.Fill(mcF2_fromV1->at(0).Pt());
   p_lept.Fill(mcF2_fromV1->at(0).P());
   p_mu.Fill(mcF2_fromV1->at(0).P());
  }
  if (fabs(mcF2_fromV2_pdgId->at(0)) == 13){
   pt_lept.Fill(mcF2_fromV2->at(0).Pt());
   pt_mu.Fill(mcF2_fromV2->at(0).Pt());
   p_lept.Fill(mcF2_fromV2->at(0).P());
   p_mu.Fill(mcF2_fromV2->at(0).P());
  }
  
  ///---- nu ----
  if (fabs(mcF1_fromV1_pdgId->at(0)) == 12 || fabs(mcF1_fromV1_pdgId->at(0)) == 14){
   pt_lept.Fill(mcF1_fromV1->at(0).Pt());
   pt_nu.Fill(mcF1_fromV1->at(0).Pt());
   p_lept.Fill(mcF1_fromV1->at(0).P());
   p_nu.Fill(mcF1_fromV1->at(0).P());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) == 12 || fabs(mcF1_fromV2_pdgId->at(0)) == 14){
   pt_lept.Fill(mcF1_fromV2->at(0).Pt());
   pt_nu.Fill(mcF1_fromV2->at(0).Pt());
   p_lept.Fill(mcF1_fromV2->at(0).P());
   p_nu.Fill(mcF1_fromV2->at(0).P());
  }
  if (fabs(mcF2_fromV1_pdgId->at(0)) == 12 || fabs(mcF2_fromV1_pdgId->at(0)) == 14){
   pt_lept.Fill(mcF2_fromV1->at(0).Pt());
   pt_nu.Fill(mcF2_fromV1->at(0).Pt());
   p_lept.Fill(mcF2_fromV1->at(0).P());
   p_nu.Fill(mcF2_fromV1->at(0).P());
  }
  if (fabs(mcF2_fromV2_pdgId->at(0)) == 12 || fabs(mcF2_fromV2_pdgId->at(0)) == 14){
   pt_lept.Fill(mcF2_fromV2->at(0).Pt());
   pt_nu.Fill(mcF2_fromV2->at(0).Pt());
   p_lept.Fill(mcF2_fromV2->at(0).P());
   p_nu.Fill(mcF2_fromV2->at(0).P());
  }
  
  ///---- had ----
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4){
   pt_had.Fill(mcF1_fromV1->at(0).Pt());
   p_had.Fill(mcF1_fromV1->at(0).P());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4){
   pt_had.Fill(mcF1_fromV2->at(0).Pt());
   p_had.Fill(mcF1_fromV2->at(0).P());
  }
  if (fabs(mcF2_fromV1_pdgId->at(0)) <= 4){
   pt_had.Fill(mcF2_fromV1->at(0).Pt());
   p_had.Fill(mcF2_fromV1->at(0).P());
  }
  if (fabs(mcF2_fromV2_pdgId->at(0)) <= 4){
   pt_had.Fill(mcF2_fromV2->at(0).Pt());
   p_had.Fill(mcF2_fromV2->at(0).P());
  }
  
  
  ///---- W ----
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4){
   pt_W_had.Fill(mcV1->at(0).Pt());
  }
  else {
   pt_W_lept.Fill(mcV1->at(0).Pt());
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4){
   pt_W_had.Fill(mcV2->at(0).Pt());
  }
  else {
   pt_W_lept.Fill(mcV2->at(0).Pt());
  }
  
  ///---- DeltaEta & DeltaPhi----
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4){
   DPhi_had.Fill(ROOT::Math::VectorUtil::DeltaPhi<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(mcF2_fromV1->at(0),mcF1_fromV1->at(0)));
   DEta_had.Fill(fabs(mcF2_fromV1->at(0).eta() - mcF1_fromV1->at(0).eta()));
   Eta_had.Fill(mcF2_fromV1->at(0).eta());
   Eta_had.Fill(mcF1_fromV1->at(0).eta());
  }
  else {
   DPhi_lept.Fill(ROOT::Math::VectorUtil::DeltaPhi<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(mcF2_fromV1->at(0),mcF1_fromV1->at(0)));
   DEta_lept.Fill(fabs(mcF2_fromV1->at(0).eta() - mcF1_fromV1->at(0).eta()));
   Eta_lept.Fill(mcF2_fromV1->at(0).eta());
   Eta_lept.Fill(mcF1_fromV1->at(0).eta());
   p_eta_lept.Fill(mcF1_fromV2->at(0).P(),mcF2_fromV1->at(0).eta());
   p_eta_lept.Fill(mcF1_fromV1->at(0).P(),mcF1_fromV1->at(0).eta());
  
   pt_eta_lept.Fill(mcF1_fromV2->at(0).Pt(),mcF2_fromV1->at(0).eta());
   pt_eta_lept.Fill(mcF1_fromV1->at(0).Pt(),mcF1_fromV1->at(0).eta());
   
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4){
   DPhi_had.Fill(ROOT::Math::VectorUtil::DeltaPhi<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(mcF2_fromV2->at(0),mcF1_fromV2->at(0)));
   DEta_had.Fill(fabs(mcF2_fromV2->at(0).eta() - mcF1_fromV2->at(0).eta()));
   Eta_had.Fill(mcF2_fromV2->at(0).eta());
   Eta_had.Fill(mcF1_fromV2->at(0).eta());
  }
  else {
   DPhi_lept.Fill(ROOT::Math::VectorUtil::DeltaPhi<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(mcF2_fromV2->at(0),mcF1_fromV2->at(0)));
   DEta_lept.Fill(fabs(mcF2_fromV2->at(0).eta() - mcF1_fromV2->at(0).eta()));
   Eta_lept.Fill(mcF2_fromV2->at(0).eta());
   Eta_lept.Fill(mcF1_fromV2->at(0).eta());
   p_eta_lept.Fill(mcF2_fromV2->at(0).P(),mcF2_fromV2->at(0).eta());
   p_eta_lept.Fill(mcF1_fromV2->at(0).P(),mcF1_fromV2->at(0).eta());
  
   pt_eta_lept.Fill(mcF2_fromV2->at(0).Pt(),mcF2_fromV2->at(0).eta());
   pt_eta_lept.Fill(mcF1_fromV2->at(0).Pt(),mcF1_fromV2->at(0).eta());
  }  
  
  
 }      
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 
 return 0 ;
}