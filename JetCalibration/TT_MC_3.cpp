/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_MC_3 `root-config --cflags --glibs` -lGenVector TT_MC_3.cpp dict.cpp treeReader.cc
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
 TH2F p_pdgId("p_pdgId","p_pdgId",1000,0,1000,400,-100,100);

 TH1F pdgId("pdgId","pdgId",400,-100,100);
 
 
 double start, end;
 
 int nentries =  tr->GetEntries ();
 std::cerr << "nentries = " << nentries << std::endl;
 start = clock();
 for (int iEvent = 0 ; iEvent < nentries ; ++iEvent)
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
  
  
  p_pdgId.Fill(mcF1_fromV1->at(0).P(),mcF1_fromV1_pdgId->at(0));
  p_pdgId.Fill(mcF1_fromV2->at(0).P(),mcF1_fromV2_pdgId->at(0));
  p_pdgId.Fill(mcF2_fromV1->at(0).P(),mcF2_fromV1_pdgId->at(0));
  p_pdgId.Fill(mcF2_fromV2->at(0).P(),mcF2_fromV2_pdgId->at(0));
  
  pdgId.Fill(mcF1_fromV1_pdgId->at(0));
  pdgId.Fill(mcF1_fromV2_pdgId->at(0));
  pdgId.Fill(mcF2_fromV1_pdgId->at(0));
  pdgId.Fill(mcF2_fromV2_pdgId->at(0));
 
 }      
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 
 return 0 ;
}