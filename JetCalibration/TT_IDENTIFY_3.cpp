/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_IDENTIFY_3 `root-config --cflags --glibs` -lMinuit -lGenVector TT_IDENTIFY_3.cpp dict.cpp treeReader.cc
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
#include <algorithm>

#include "include/Utils.h"

struct Pt : public std::binary_function<ROOT::Math::XYZTVector, ROOT::Math::XYZTVector, bool> 
{
 bool operator() (ROOT::Math::XYZTVector jet1, ROOT::Math::XYZTVector jet2) 
 { 
  return (jet1.Pt () >= jet2.Pt ());
 };
};


double add(int iBBQQ){
 if (iBBQQ<2) return 1; //---- b
  else if (iBBQQ<4) return 2; //---- q
   else return 0; //---- out
};


bool check(const std::vector<int>& matchIt_RECO){
 int num = matchIt_RECO.size();
 int numb = 0;
 int numq = 0;
 for (int i=0; i<num; i++){
  if (matchIt_RECO.at(i) == 1) numq++;
  if (matchIt_RECO.at(i) == 2) numb++;
 }
return ((numq == 2) && (numb == 2));
}


void fillCombination(const std::vector<int>& matchIt_RECO, std::vector< std::vector<int> >& combinations_matchIt_RECO){
//  for (int i=0; i< matchIt_RECO.size();i++){
//   std::cerr << "  " << matchIt_RECO.at(i);
//  }
//  std::cerr << std::endl;
 if (check(matchIt_RECO)) {
  combinations_matchIt_RECO.push_back(matchIt_RECO);
//   std::cerr << "    found combination!!!" << std::endl;
 }
}


void AddCombination(std::vector<int>& matchIt_RECO, std::vector< std::vector<int> >& combinations_matchIt_RECO,int numJet){
//  std::cerr << "   num = " << numJet << std::endl;
 if (numJet > 0){ //---- numJet = max number of jets to deal with ----
  numJet -= 1; 
  for (int iBBQQ=0; iBBQQ<5; iBBQQ++){//---- 5 = b, b, q, q, out ---- 5 possibilities
   matchIt_RECO.push_back(add(iBBQQ));
   AddCombination(matchIt_RECO,combinations_matchIt_RECO,numJet);
   if (numJet==0) fillCombination(matchIt_RECO,combinations_matchIt_RECO); //---- last turn ----
   matchIt_RECO.pop_back();
  }
  numJet +=1;
 }
}
 
 
 
 struct combinationSorting : public std::binary_function<std::vector<int>, std::vector<int>, bool> 
 {
  bool operator() (std::vector<int> comb1, std::vector<int> comb2) 
  { 
   int size = comb1.size(); //---- conversione base 3: b, q, out --> base 3!
   int size_temp = comb2.size(); 
   if (size != size_temp) std::cerr << " AAAAAH !!! size = " << size << " size_temp = " << size_temp << std::endl;
   int res1 = 0;
   int res2 = 0;
   for (int i=0; i<size; i++){
//     std::cerr << "error is here ..." << i << ":" << size << std::endl;
    int power = 1;
    for (int j=0; j<i; j++) power *= 3;
    res1 += (comb1.at(i) * power);
    res2 += (comb2.at(i) * power);
   }
   return (res1 >= res2);
  };
 };
 
 struct combinationEqual : public std::binary_function<std::vector<int>, std::vector<int>, bool> 
 {
  bool operator() (std::vector<int> comb1, std::vector<int> comb2) 
  { 
   int size = comb1.size(); //---- conversione base 3: b, q, out --> base 3!
   int size_temp = comb2.size(); 
   if (size != size_temp) std::cerr << " AAAAAH Equal !!! size = " << size << " size_temp = " << size_temp << std::endl;
   int res1 = 0;
   int res2 = 0;
   for (int i=0; i<size; i++){
    int power = 1;
    for (int j=0; j<i; j++) power *= 3;
    res1 += (comb1.at(i) * power);
    res2 += (comb2.at(i) * power);
   }
   return (res1 == res2) ; 
  }
 };
 
 
void ClearCombination(std::vector< std::vector<int> >& combinations_matchIt_RECO){
//  std::cerr << " ClearCombination" << std::endl;
//  std::cerr << "   Combination" << std::endl;
//  sort (combinations_matchIt_RECO.begin (), combinations_matchIt_RECO.end (), combinationSorting ()) ; 
  std::vector< std::vector<int> > ::iterator ShorterEnd;
//  std::cerr << "   Unique" << std::endl;
 ShorterEnd = unique (combinations_matchIt_RECO.begin (), combinations_matchIt_RECO.end (), combinationEqual ()) ; 
//  std::cerr << "   Erase" << std::endl;
 combinations_matchIt_RECO.erase (ShorterEnd, combinations_matchIt_RECO.end());
//  std::cerr << "   Erased" << std::endl;
 
//  sort (combinations_matchIt_RECO.begin (), combinations_matchIt_RECO.end (), combinationSorting ()) ; 
//  std::cerr << "   Unique" << std::endl;
//  ShorterEnd = unique (combinations_matchIt_RECO.begin (), combinations_matchIt_RECO.end (), combinationEqual ()) ; 
//  std::cerr << "   Erase" << std::endl;
//  combinations_matchIt_RECO.erase (ShorterEnd, combinations_matchIt_RECO.end());
//  std::cerr << "   Erased" << std::endl;
}
 
 

int main (int argc, char ** argv)
{
 
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 treeReader reader (tr) ;
 
 TFile outFile(argv[3],"RECREATE");
 
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
    std::vector<std::vector<int> > combinations_matchIt_RECO;
    std::vector<int> matchIt_RECO;  
    int numJet = std::max(static_cast<int>(4),static_cast<int>(jets->size())); 
    std::cerr << " numJet = " << numJet << std::endl;
    if (numJet>=4) {
     AddCombination(matchIt_RECO,combinations_matchIt_RECO,numJet);
     std::cerr << " num combination = " <<  combinations_matchIt_RECO.size() << std::endl;
     ClearCombination(combinations_matchIt_RECO);
     std::cerr << " num combination = " <<  combinations_matchIt_RECO.size() << std::endl;
    }
   }
   delete mcF_fromVandB;
 }
 
 
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 return 0 ;
}