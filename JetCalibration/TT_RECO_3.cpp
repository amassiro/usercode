/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_RECO_3 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_3.cpp dict.cpp treeReader.cc
*/

#include "treeReader.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"

#include "Math/GenVector/VectorUtil.h"

#include "src/Utils.cc"

#include <time.h>
#include <sstream>

std::vector<std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> >* InputJet = new std::vector<std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> > ();

double PtMax = 100;
double EtaMax = 4;

double DPt = 10;
double DEta = 0.4;

int intPt = static_cast<int>(PtMax / DPt);
int intEta = static_cast<int>(EtaMax / DEta);

Int_t nParametri = intPt * intEta;

int main (int argc, char ** argv)
{
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 
 treeReader reader (tr) ;
 
 TFile outFile("output/outFile_hKK_num.root","RECREATE");
 
 TH2F hKK_num("hKK_num","hKK_num",intPt,0,PtMax,intEta,0,EtaMax); //---- correction function K(eta) x K(pT) ----
 
 std::cerr << std::endl << "*** nParametri = " << nParametri << " ***" << std::endl;
 
 
 double start, end;
 
 int nentries =  tr->GetEntries ();
 std::cerr << "nentries = " << nentries << std::endl;
 if (argc == 4) nentries = atoi(argv[3]);
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
  
  std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
  
  std::vector<ROOT::Math::XYZTVector>* mcF_fromV1 = new std::vector<ROOT::Math::XYZTVector>;
  mcF_fromV1->push_back(mcF1_fromV1->at(0));
  mcF_fromV1->push_back(mcF2_fromV1->at(0));
  std::vector<ROOT::Math::XYZTVector>* mcF_fromV2 = new std::vector<ROOT::Math::XYZTVector>;
  mcF_fromV2->push_back(mcF1_fromV2->at(0));
  mcF_fromV2->push_back(mcF2_fromV2->at(0));
  
  std::vector<int> matchIt;
  int matched = 0;
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
   matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromV1,0.3,0.1,2.0,&matchIt);
  }
  if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4 && fabs(mcF1_fromV1_pdgId->at(0)) >= 11 ){
   matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromV2,0.3,0.1,2.0,&matchIt);
  }
  double M_temp = 0;
  if (matched > 0){
   if (matched == 2){
    hKK_num.Fill(jets->at(matchIt.at(0)).Pt(),jets->at(matchIt.at(0)).Eta());
    hKK_num.Fill(jets->at(matchIt.at(1)).Pt(),jets->at(matchIt.at(1)).Eta());
   }
  }
  
  delete mcF_fromV1;
  delete mcF_fromV2;
 }
  
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 
 return 0 ;
}