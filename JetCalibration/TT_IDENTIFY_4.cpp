/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_IDENTIFY_4 `root-config --cflags --glibs` -lMinuit -lGenVector TT_IDENTIFY_4.cpp dict.cpp treeReader.cc
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
  if (check(matchIt_RECO)) {
   combinations_matchIt_RECO.push_back(matchIt_RECO);
  }
}


void AddCombination(std::vector<int>& matchIt_RECO, std::vector< std::vector<int> >& combinations_matchIt_RECO,int numJet){
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
  int res1 = 0;
  int res2 = 0;
  for (int i=0; i<size; i++){
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
 std::vector< std::vector<int> > ::iterator ShorterEnd;
 ShorterEnd = unique (combinations_matchIt_RECO.begin (), combinations_matchIt_RECO.end (), combinationEqual ()) ; 
 combinations_matchIt_RECO.erase (ShorterEnd, combinations_matchIt_RECO.end());
}

 
 
 double eval_DR_bb(double DR_bb){
  double result_up = (-3.82573e-03) + (1.41472e-02) * DR_bb + (-1.71696e-02) * DR_bb * DR_bb + (9.64878e-03) * DR_bb * DR_bb * DR_bb + (-2.43159e-03) * DR_bb * DR_bb * DR_bb * DR_bb + (2.21839e-04) * DR_bb * DR_bb * DR_bb * DR_bb * DR_bb;
  double result_down = (-4.26288e-03) + (1.40067e-02) * DR_bb + (-1.39796e-02) * DR_bb * DR_bb + (6.65092e-03) * DR_bb * DR_bb * DR_bb + (-1.49731e-03) * DR_bb * DR_bb * DR_bb * DR_bb + (1.26794e-04) * DR_bb * DR_bb * DR_bb * DR_bb * DR_bb;
  double result;
  if (result_down != 0) result = fabs(result_up / result_down);
  if (DR_bb >4) result = 0;
  if (DR_bb < 0.5) result = 0;
  return result;
 }
 
 double eval_DR_qq(double DR_qq){
  double result_up = (-3.32662e-03) + (8.55567e-03) * DR_qq + (-3.75460e-03) * DR_qq * DR_qq + (-1.59952e-05) * DR_qq * DR_qq * DR_qq + (2.55905e-04) * DR_qq * DR_qq * DR_qq * DR_qq + (-3.45180e-05) * DR_qq * DR_qq * DR_qq * DR_qq * DR_qq;
  double result_down = (-3.59175e-03) + (1.37385e-02) * DR_qq + (-1.72147e-02) * DR_qq * DR_qq + (9.77301e-03) * DR_qq * DR_qq * DR_qq + (-2.45796e-03) * DR_qq * DR_qq * DR_qq * DR_qq + (2.22835e-04) * DR_qq * DR_qq * DR_qq * DR_qq * DR_qq;
  double result;
  if (result_down != 0) result = fabs(result_up / result_down);
  if (DR_qq >4) result = 0;
  if (DR_qq < 0.5) result = 0;
  return result;
 }
 
 
 double eval_q_trackCountingHighEffBJetTags(double x){ 
  double result_up = (-0.170644) * exp((-1.18821) * x) + (0.0156448) * exp(-0.5*((x-(0.956014))/(0.61802))*((x-(0.956014))/(0.61802))) + (0.165707) * exp((-1.13331) * x) + (9.34581e-05);
  double result_down = (0.49763) * exp((-1.30413) * x) + (0.00106353) * exp(-0.5*((x-(4.37409))/(-7.66343))*((x-(4.37409))/(-7.66343))) + (-0.502457) * exp((-1.35164) * x) + (0.000146039); //---- FIXME may be optimized!  
  double result;
  if (result_down != 0) result = fabs(result_up / result_down);
  if (x >40) result = 0;
  return result;
 }
 
 
 double eval_b_trackCountingHighEffBJetTags(double x){ 
  double result_up = (0.00404993) * exp((-0.123128) * x) + (-3256.96) * exp(-0.5*((x-(0.989383))/(0.000301955))*((x-(0.989383))/(0.000301955))) + (-0.00443926) * exp((-2.12971) * x) + (4.94723e-05); //---- FIXME may be optimized!  
  double result_down = (0.49516) * exp((-1.29324) * x) + (-0.00296982) * exp(-0.5*((x-(2.52131))/(0.949705))*((x-(2.52131))/(0.949705))) + (-0.504652) * exp((-1.43253) * x) + (7.77085e-05); //---- FIXME may be optimized!  
  double result;
  if (result_down != 0) result = fabs(result_up / result_down);
  if (x >40) result = 0;
  return result;
 }
 
 
 
 
 double eval_b_pT(double x){ 
  double result_up = (0.0122425) * exp((-0.0343777) * x) + (-0.0130454) * exp((-0.0876625) * x );
  double result_down = (0.0113235) * exp((-0.0327694) * x) + (-0.0247253) * exp((-0.11953) * x ); 
  double result;
  if (result_down != 0) result = fabs(result_up / result_down);
  if (x >200) result = 0;
  if (x < 10) result = 0; 
  return result;
 }
 
 double eval_q_pT(double x){ 
  double result_up = (0.0123922) * exp((-0.0401886) * x) + (-0.013578) * exp((-0.166507) * x );
  double result_down = (0.934062) * exp((-0.0433747) * x) + (-0.938336) * exp((-0.0439213) * x );
  double result;
  if (result_down != 0) result = fabs(result_up / result_down);
  if (x >200) result = 0;
  if (x < 10) result = 0; 
  return result;
 }
 
 
 
 double CalculateLikelihood(std::vector< std::vector<int> >::iterator iterator_vector,std::vector<ROOT::Math::XYZTVector>* jets, std::vector<float>* jets_trackCountingHighEffBJetTags){
  int numJet = iterator_vector->size();
  int b1 = -1;
  int b2 = -1;
  int q1 = -1;
  int q2 = -1;
  for (int ijet=0; ijet<numJet; ijet++){
   if (iterator_vector->at(ijet)==1) {
    if (b1 == -1) {
     b1 = ijet;
    }
    else {
     b2 = ijet;
    }
   }
   else if (iterator_vector->at(ijet)==2){
    if (q1 == -1) {
     q1 = ijet;
    }
    else {
     q2 = ijet;
    }
   }
  }
  
  double DR_bb = ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(b2));
  double L_DR_bb = eval_DR_bb(DR_bb);
  double DR_qq = ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(q2));
  double L_DR_qq = eval_DR_qq(DR_qq);
  double L_q_jets_trackCountingHighEffBJetTags = eval_q_trackCountingHighEffBJetTags(jets_trackCountingHighEffBJetTags->at(q1));
  L_q_jets_trackCountingHighEffBJetTags *= eval_q_trackCountingHighEffBJetTags(jets_trackCountingHighEffBJetTags->at(q2));
  double L_b_jets_trackCountingHighEffBJetTags = eval_b_trackCountingHighEffBJetTags(jets_trackCountingHighEffBJetTags->at(b1));
  L_b_jets_trackCountingHighEffBJetTags *= eval_b_trackCountingHighEffBJetTags(jets_trackCountingHighEffBJetTags->at(b2));
  double L_Pt_b = eval_b_pT(jets->at(b1).Pt());
  L_Pt_b *= eval_b_pT(jets->at(b2).Pt());
  double L_Pt_q = eval_q_pT(jets->at(q1).Pt());
  L_Pt_q *= eval_q_pT(jets->at(q2).Pt());
  
//   double Ltot = L_DR_bb * L_DR_qq * L_q_jets_trackCountingHighEffBJetTags * L_b_jets_trackCountingHighEffBJetTags * L_Pt_b * L_Pt_q;  
  double Ltot = L_DR_bb * L_DR_qq * L_b_jets_trackCountingHighEffBJetTags * L_Pt_b * L_Pt_q;  
  return Ltot;
 }
 

void FindRECOCombination(std::vector<int>& selected_matchIt_RECO, std::vector< std::vector<int> >& combinations_matchIt_RECO,  std::vector<ROOT::Math::XYZTVector>* jets,std::vector<float>* jets_trackCountingHighEffBJetTags){
 std::vector< std::vector<int> >::iterator selected_it = combinations_matchIt_RECO.begin();
 double selected_it_likelihood = CalculateLikelihood(selected_it,jets,jets_trackCountingHighEffBJetTags);
 for (std::vector< std::vector<int> >::iterator it = ((combinations_matchIt_RECO.begin()) + 1); it != combinations_matchIt_RECO.end(); it++){
  double temp_selected_it_likelihood = CalculateLikelihood(it,jets,jets_trackCountingHighEffBJetTags);
  if (temp_selected_it_likelihood >= selected_it_likelihood) {
   selected_it_likelihood = temp_selected_it_likelihood;
   selected_it = it;
  }
 }
 selected_matchIt_RECO = (*selected_it);
}



void FindMCCombination(std::vector<int>& selected_matchIt_MC,std::vector<int>& matchIt,int numJet){
 std::vector<int> selected_matchIt_MC_temp;
 for (int i=0; i<numJet; i++){
  if ((matchIt.at(0) == i) || (matchIt.at(1) == i)) selected_matchIt_MC_temp.push_back(1); //---- b
   else if ((matchIt.at(2) == i) || (matchIt.at(3) == i)) selected_matchIt_MC_temp.push_back(2); //---- q
    else selected_matchIt_MC_temp.push_back(0); //---- out
 }
 selected_matchIt_MC = selected_matchIt_MC_temp;
}



int main (int argc, char ** argv)
{
 
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 treeReader reader (tr) ;
 
 TFile outFile(argv[3],"RECREATE");
 
 TTree outTree("outTree","outTree");
 int n_matched;
 int n_jets;
 outTree.Branch("n_matched",&n_matched,"n_matched/I");
 outTree.Branch("n_jets",&n_jets,"n_jets/I");
 
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
    std::vector<int> selected_matchIt_RECO;  
    std::vector<int> selected_matchIt_MC;  
    
//     int numJet = std::max(static_cast<int>(4),static_cast<int>(jets->size())); 
    int numJet = static_cast<int>(jets->size()); 
    if (numJet>=4) {
     AddCombination(matchIt_RECO,combinations_matchIt_RECO,numJet);
//      std::cerr << " num combination = " <<  combinations_matchIt_RECO.size() << std::endl;
     ClearCombination(combinations_matchIt_RECO);
//      std::cerr << " num combination = " <<  combinations_matchIt_RECO.size() << std::endl;

     ///---- select RECO right combination ----     
     FindRECOCombination(selected_matchIt_RECO,combinations_matchIt_RECO,jets,jets_trackCountingHighEffBJetTags);
     
     ///---- select MC right combination -----
     FindMCCombination(selected_matchIt_MC,matchIt,numJet);
     
     if (selected_matchIt_MC == selected_matchIt_RECO) n_matched = 1;
     else n_matched = 0;
   
     n_jets = numJet;
       
     outTree.Fill();
     
    }
   }
   delete mcF_fromVandB;
 }
 
 
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 return 0 ;
}