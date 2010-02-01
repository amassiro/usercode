/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_IDENTIFY_2 `root-config --cflags --glibs` -lMinuit -lGenVector TT_IDENTIFY_2.cpp dict.cpp treeReader.cc
*/

///---- Identification method of correct jets in a ttbar sample ----

#include "treeReader.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"

#include "Math/GenVector/VectorUtil.h"

#include "TRandom3.h"

#include "src/Utils.cc"

#include <time.h>
#include <sstream>

#include "include/Utils.h"

struct Pt : public std::binary_function<ROOT::Math::XYZTVector, ROOT::Math::XYZTVector, bool> 
{
 bool operator() (ROOT::Math::XYZTVector jet1, ROOT::Math::XYZTVector jet2) 
 { 
  return (jet1.Pt () >= jet2.Pt ());
 };
};

int main (int argc, char ** argv)
{
 
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 treeReader reader (tr) ;
 
 TFile outFile(argv[3],"RECREATE");

 TH1F FracNJetsAll("FracNJetsAll","FracNJetsAll",20,0,20);
 TH1F FracNJetsB("FracNJetsB","FracNJetsB",20,0,20);
 TH1F FracNJetsQ("FracNJetsQ","FracNJetsQ",20,0,20);
 
 double start, end;
 
 int nentries =  tr->GetEntries ();
 std::cerr << "nentries = " << nentries << std::endl;
 if (argc >= 5) nentries = atoi(argv[4]);
 std::cerr << "nentries = " << nentries << std::endl;
 
 std::cerr << std::endl << "*** Fill Data ***" << std::endl;
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
  
  std::vector<ROOT::Math::XYZTVector>* mcB1 = reader.Get4V("mcB1");
  std::vector<ROOT::Math::XYZTVector>* mcB2 = reader.Get4V("mcB2");
  
  std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
  
//   sort (jets->begin (), jets->end (), Pt ()) ;  //---- to test pt sorting of jets
//   for (int jj=0; jj<jets->size();jj++){
//    std::cout << " " << jets->at(jj).Pt() << std::endl;
//   }
  
  std::vector<float>* jets_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags");
  std::vector<float>* jets_trackCountingHighEffBJetTagsDR = reader.GetFloat("jets_trackCountingHighEffBJetTagsDR");
  std::vector<float>* jets_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags");
  std::vector<float>* jets_simpleSecondaryVertexBJetTags = reader.GetFloat("jets_simpleSecondaryVertexBJetTags");
  std::vector<float>* jets_combinedSecondaryVertexBJetTags = reader.GetFloat("jets_combinedSecondaryVertexBJetTags");
  std::vector<float>* jets_combinedSecondaryVertexMVABJetTags = reader.GetFloat("jets_combinedSecondaryVertexMVABJetTags");
  
  
  ///---- find: q,q', b1, b2 ---- Pool ----
  
  std::vector<ROOT::Math::XYZTVector>* mcF_fromVandB = new std::vector<ROOT::Math::XYZTVector>;
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
   mcF_fromVandB->push_back(mcF1_fromV1->at(0));
   mcF_fromVandB->push_back(mcF2_fromV1->at(0));
  } else if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4 && fabs(mcF1_fromV1_pdgId->at(0)) >= 11 ){
   mcF_fromVandB->push_back(mcF1_fromV2->at(0));
   mcF_fromVandB->push_back(mcF2_fromV2->at(0));
  }
  
  mcF_fromVandB->push_back(mcB1->at(0));
  mcF_fromVandB->push_back(mcB2->at(0));
  
  if ( mcF_fromVandB->size() != 4 ) continue; //---- only if at MC level found bb + qq' + (lnu) ----
   
  std::vector<int> matchIt;
  int matched = 0;
  matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromVandB,0.3,0.1,2.0,&matchIt);
  
  if (matched == 4){
  
   int maxAllJet;
   maxAllJet = std::max(matchIt.at(0),matchIt.at(1));
   maxAllJet = std::max(maxAllJet,matchIt.at(2));
   maxAllJet = std::max(maxAllJet,matchIt.at(3));
   FracNJetsAll.Fill(maxAllJet+1); //---- + 1 for "graphical" issue
   
   int maxQJet;
   maxQJet = std::max(matchIt.at(0),matchIt.at(1));
   FracNJetsQ.Fill(maxQJet+1);
   
   int maxBJet;
   maxBJet = std::max(matchIt.at(2),matchIt.at(3));
   FracNJetsB.Fill(maxBJet+1);
  
  }
  delete mcF_fromVandB;
 }
 
 
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 return 0 ;
}