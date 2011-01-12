/* 
TO COMPILE:

export ROOTSYS=~/Desktop/root
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH
export DYLD_LIBRARY_PATH=$ROOTSYS/lib:$DYLD_LIBRARY_PATH 

c++ -o counter `root-config --glibs --cflags` counter.cpp

TO RUN:     

./count


*/

#include <cmath>
#include <iostream>
#include "TF1.h"
#include "TTree.h"
#include "TCut.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TROOT.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TText.h"
#include <map>
#include <vector>

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std ;

struct coll 
{
 coll (string name) : m_name (name) {} ;
 void add (const double & XS, std::pair<TTree*,TTree*> al) 
 {
  samples[XS] = al ;
 }
 
 ///=================================================
 double getEqSigma (TCut cut){
  double events = 0. ;
  for (map<double, std::pair<TTree*,TTree*> >::iterator it = samples.begin () ;  it != samples.end () ;   ++it){
   it->second.second->SetBranchAddress ("preselection_efficiency", &preselection_efficiency) ;
   it->second.second->SetBranchAddress ("numEntriesBefore", &numEntriesBefore) ;
   it->second.second->GetEntry (0) ;
   
   if (it->second.first->GetEntries () != 0) {
    events += (it->first * (1000. * it->second.first->GetEntries (cut)) * preselection_efficiency / numEntriesBefore) ;
   }
  }
  return events ;
 } ;
 ///=================================================
 double getAll () {
  double events = 0. ;
  for (map<double, std::pair<TTree*,TTree*> >::iterator it = samples.begin () ;  it != samples.end () ;   ++it){
   it->second.second->SetBranchAddress("preselection_efficiency",&preselection_efficiency);
   it->second.second->SetBranchAddress("numEntriesBefore",&numEntriesBefore);
   it->second.second->GetEntry(0);
    events += (it->first * 1000.);
  }
  return events ;
 } ;
 
 ///=================================================
 double getMC (TCut cut){
  double events = 0. ;
  for (map<double, std::pair<TTree*,TTree*> >::iterator it = samples.begin () ;  it != samples.end () ;   ++it){
    events += (it->second.first->GetEntries (cut)) ;
  }
  return events ;
 } ;
 
 ///=================================================
 map<double, std::pair<TTree*,TTree*> > samples ;
 string m_name ; 
 
 double XSection;
 double preselection_efficiency;
 int numEntriesBefore;  
} ;


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---


int main(int argc, char** argv) {
 TString fileSamples;
 if (argc>=2) fileSamples = Form("%s",argv[1]);
 else fileSamples = Form("test/samples_skimmed_counter.txt");
  
 vector<coll> samples ;
 
 TTree *treeEffVect[100];
 TTree *treeJetLepVect[100];
 
 TH1F* histo[100];
 TH1F* histo_temp[100];
 
 char *nameSample[1000];
 char *nameSampleFile[1000];
 char *joinSampleName[1000];
 
 double xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile(fileSamples.Data());
 std::string buffer;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  //   std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){
    std::stringstream line( buffer );       
    nameSample[numberOfSamples] = new char [1000];
    line >> nameSample[numberOfSamples]; 
    std::cout << nameSample[numberOfSamples] << " ";
    
    nameSampleFile[numberOfSamples] = new char [1000];
    line >> nameSampleFile[numberOfSamples]; 
    std::cout << nameSampleFile[numberOfSamples] << " ";
    
    line >> xsection[numberOfSamples]; 
    std::cout << xsection[numberOfSamples] << " ";
    std::cout << std::endl;
    
    joinSampleName[numberOfSamples] = new char [1000];
    line >> joinSampleName[numberOfSamples]; 
    std::cout << joinSampleName[numberOfSamples] << " ";
    std::cout << std::endl;
  
    numberOfSamples++;
   } 
  }
 }
 
 ///===== create map for joint sample ====
 
 
 std::vector<int> join_samples;
 std::vector<std::string> name_samples;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  name_samples.push_back(joinSampleName[iSample]);
  join_samples.push_back(-1);
 }
 
 std::vector<std::string> reduced_name_samples;
 std::vector<int>         reduced_name_samples_flag;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  bool flag_name = false;
  for (int iName=0; iName<reduced_name_samples.size(); iName++){
   if (reduced_name_samples.at(iName) == name_samples.at(iSample)) flag_name = true;
  }
  if (flag_name == false) {
   reduced_name_samples.push_back(name_samples.at(iSample));
   reduced_name_samples_flag.push_back(-1);
  }
 }
 
 ///===== cicle on reduced sample names and add to counter ====
 
 for (int iName=0; iName<reduced_name_samples.size(); iName++){
  if (reduced_name_samples.at(iName) != "DATA") {
   bool firstTime = true;
   for (int iSample=0; iSample<numberOfSamples; iSample++){
    if (name_samples.at(iSample) == reduced_name_samples.at(iName)) {
     if (firstTime) {
      firstTime = false;
      samples.push_back (coll (reduced_name_samples.at(iName))) ;
     }
     char nameFile[1000];
     sprintf(nameFile,"output/out_NtupleProducer_%s.root",nameSample[iSample]);  
     TFile* f = new TFile(nameFile, "READ");
     std::pair<TTree*, TTree*> pair_vbf_temp ((TTree*) f->Get ("outTreeJetLep"), (TTree*) f->Get ("outTreeSelections"));
     samples.back ().add (xsection[iSample], pair_vbf_temp) ;
    }
   }
  }
 } 

vector<TCut> selections ;


///==== cut based ====
///*  -  */ selections.push_back ("") ;
///* VBF */ selections.push_back ("pT_RECO_q1>20&&pT_RECO_q2>20&&abs(eta_RECO_q1)>0.1&&abs(eta_RECO_q2)>0.1&&Deta_RECO_q12>2.0&&Mjj>350") ;
///* CJV */ selections.push_back ("CJV_30<1") ;
///* LEP */ selections.push_back ("pT_RECO_l1>30&&pT_RECO_l2>10&&abs(eta_RECO_l1)<2.5&&abs(eta_RECO_l2)<2.5&&Deta_RECO_l12<3.8&&Dphi_RECO_l12<1.5&&charge_RECO_l1_charge_RECO_l2==-1&&abs(Z_ll)<0.5") ;
///* Z_V */ selections.push_back ("((Mll<70&&Mll>20&&pdgId_RECO_l1==pdgId_RECO_l2)||(pdgId_RECO_l1!=pdgId_RECO_l2))") ;
///* MET */ selections.push_back ("MET>30");
///* Btag */ selections.push_back ("bTag_trackCountingHighPurBJetTags_q2<1.0&&bTag_trackCountingHighPurBJetTags_q1<1.0");



///==== MVA ====
/*  -  */ selections.push_back ("") ;
/* VBF */ selections.push_back ("pT_RECO_q1>20&&pT_RECO_q2>20&&abs(eta_RECO_q1)>0.1&&abs(eta_RECO_q2)>0.1&&Deta_RECO_q12>0.0&&Mjj>200") ;
/* CJV */ selections.push_back ("CJV_30<1") ;
/* LEP */ selections.push_back ("pT_RECO_l1>30&&pT_RECO_l2>10&&abs(eta_RECO_l1)<2.5&&abs(eta_RECO_l2)<2.5&&charge_RECO_l1_charge_RECO_l2==-1") ;
/* Z_V */ selections.push_back ("((Mll<70&&Mll>20&&pdgId_RECO_l1==pdgId_RECO_l2)||(pdgId_RECO_l1!=pdgId_RECO_l2))") ;
/* MET */ selections.push_back ("MET>30");
/* Btag */ selections.push_back ("bTag_trackCountingHighPurBJetTags_q2<1.0&&bTag_trackCountingHighPurBJetTags_q1<1.0");
///*MVA Jet*/ selections.push_back ("BDT_Jet>0.1");
///*MVA Lep*/ selections.push_back ("BDT_Lep>-0.2");

std::cout.precision (2) ;
std::cout.unsetf(ios::scientific);

std::cout << setw (8) << " sample ";
std::cout << "  |" << setw (8) << "  No sel  ";
std::cout << "  |  " << setw (8) << "2j+2l";
std::cout << "  |  " << setw (17) << "  VBF ";
std::cout << "  |  " << setw (17) << "  CJV ";
std::cout << "  |  " << setw (17) << "  LEP ";
std::cout << "  |  " << setw (17) << "Z veto ";
std::cout << "  |  " << setw (17) << " MET   ";
std::cout << "  |  " << setw (17) << " BTag ";
// std::cout << "  |  " << setw (17) << " MVA Jet ";
// std::cout << "  |  " << setw (17) << " MVA Lep";
std::cout << std::endl;
cout << "----------+------------+------------+---------------------+---------------------+---------------------+---------------------+---------------------+---------------------+---------------------+---------------------+\n" ;

for (int iSample = 0 ; iSample < samples.size () ; ++iSample)
{
 //PG efficiencies of the full chain wrt beginning 
 //      std::cout << "        " ;
 std::cout << setw (8) << samples.at (iSample).m_name ;
 std::cout << " | " << setw (8) << samples.at (iSample).getAll () ;
 std::cout << " | " << setw (8) << samples.at (iSample).getEqSigma (selections.at (0)) ;
 TCut total_cut = selections.at (0) ;
 for (int iSel = 1 ; iSel < selections.size () ; ++iSel) 
 {
  total_cut = total_cut && selections.at (iSel) ;
  cout << " | " << setw (8) << samples.at (iSample).getEqSigma (total_cut) ;
//   cout  << " (" << setw (6) << samples.at (iSample).getEqSigma (total_cut) / 
//   samples.at (iSample).getAll () << ")";
  std::cout << "[" <<samples.at (iSample). getMC(total_cut) << "]" ;
  //                                       samples.at (iSample).getEqSigma (selections.at (0)) << ")" ;
 }
 std::cout << " | absolute " << endl ;            
 
 //PG efficiencies of the full chain wrt previous cut
 //      std::cout << "        " ;
//  std::cout << setw (8) << samples.at (iSample).m_name ;
//  std::cout << " | " << setw (8) << samples.at (iSample).getAll () ;
//  std::cout << " | " << setw (8) << samples.at (iSample).getEqSigma (selections.at (0)) ;
//  total_cut = selections.at (0) ;
/* TCut previous_cut = selections.at (0) ;
 for (int iSel = 1 ; iSel < selections.size () ; ++iSel) 
 {
  previous_cut = total_cut ;
  total_cut = total_cut && selections.at (iSel) ;
  cout << " | " << setw (8) << samples.at (iSample).getEqSigma (total_cut) ;
//   cout  << " (" << setw (6) << samples.at (iSample).getEqSigma (total_cut) / 
//   samples.at (iSample).getEqSigma (previous_cut) << ")" ;
 }
 std::cout << " | relative " << endl ;            
 
 //PG efficiencies of single selections wrt no cuts
 std::cout << setw (8) << samples.at (iSample).m_name ;
 std::cout << " | " << setw (8) << samples.at (iSample).getAll () ;
 std::cout << " | " << setw (8) << samples.at (iSample).getEqSigma (selections.at (0)) ;
 for (int iSel = 1 ; iSel < selections.size () ; ++iSel) 
 {
  cout << " | " << setw (8) << samples.at (iSample).getEqSigma (selections.at (iSel)) ;
  //          cout  << " (" << setw (6) << samples.at (iSample).getEqSigma (selections.at (iSel)) / samples.at (iSample).getEqSigma (selections.at (iSel-1)) << ")" ;
//   cout  << " (" << setw (6) << samples.at (iSample).getEqSigma (selections.at (iSel)) / 
//   samples.at (iSample).getAll () << ")" ;
  //                                       samples.at (iSample).getEqSigma (selections.at (0)) << ")" ;
 }
 std::cout << " | indip " << endl ;    */        
 
 
} 

 return 0 ;
 
}
