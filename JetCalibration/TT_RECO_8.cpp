/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_RECO_8 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_8.cpp dict.cpp treeReader.cc
*/

#include "treeReader.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"
#include "TF1.h"
#include "TRandom3.h"

#include "Math/GenVector/VectorUtil.h"

#include "src/Utils.cc"

#include <time.h>
#include <sstream>

std::vector<std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> >* InputJet = new std::vector<std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> > ();

double PtMax = 100;
double EtaMax = 4;

double DPt = 2.5;
double DEta = 0.4;

int intPt = static_cast<int>(PtMax / DPt);
int intEta = static_cast<int>(EtaMax / DEta);

Int_t nParametri = intPt * intEta;

TRandom myRand (0); // Creates a random number generator object with seed 0


void Update(std::vector<double>* KK_In){
 
 std::vector<TH1F>* CorrH = new std::vector<TH1F>;
 
 for (int i=0; i<nParametri; i++){
  std::ostringstream oss;
  oss << "h_" << i;
  std::string nameHisto(oss.str());
  TH1F h_tmp(nameHisto.c_str(),nameHisto.c_str(),1200,0,160); //---- invariant mass spectrum ----
  CorrH->push_back(h_tmp);
 }
 
 std::vector<std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> > InputJet_In = *InputJet;
 int n = InputJet_In.size();
 
 std::cerr << "n = " << n << std::endl;
 
 for (int i=0; i<n; i++){
  
  //---- previous position ----
  int iPt1 = static_cast<int>(InputJet_In.at(i).first.Pt() / DPt );
  int iEta1 = static_cast<int>(fabs(InputJet_In.at(i).first.Eta() / DEta));
  
  int iPt2 = static_cast<int>(InputJet_In.at(i).second.Pt() / DPt );
  int iEta2 = static_cast<int>(fabs(InputJet_In.at(i).second.Eta() / DEta));
  
  
  if (!(n%1000)) std::cerr << "  i = " << i << " : " << n << std::endl;
  
  
  if ((iPt1 >= intPt) || (iPt2 >= intPt) || (iEta1 >= intEta) || (iEta2 >= intEta)) continue; //---- data not used, out of range for KK!
   
   double M_temp = ((InputJet_In.at(i).first) + (InputJet_In.at(i).second)).M();
  double M2_temp = M_temp * M_temp * KK_In->at(iPt1 * intEta + iEta1)* KK_In->at(iPt2 * intEta + iEta2);
  
  CorrH->at(iPt1 * intEta + iEta1).Fill(sqrt(M2_temp));
  CorrH->at(iPt2 * intEta + iEta2).Fill(sqrt(M2_temp));
 }
 
 TF1 *gfit = new TF1("Gaussian","gaus",0,160); // Create the fit function
 
 for (int i=0; i<nParametri; i++){
  if (CorrH->at(i).GetEntries() > 10){
   gfit->SetParameter(0,CorrH->at(i).GetEntries()/160.);   
   gfit->SetParameter(1,80.0);
   gfit->SetParameter(2,15.0);   
   
   gfit->SetParLimits(1,20,140);   
   gfit->SetParLimits(2,0.1,30.);   
   
   CorrH->at(i).Fit("Gaussian");
   Double_t mean = gfit->GetParameter(1); //value of 1st parameter
   
   double chisq=gfit->GetChisquare();
   double ndf=gfit->GetNDF();
   double chisqdf=chisq/ndf;
   
   if (chisqdf < 5) { 
    float test = myRand.Uniform(-1.0, 1.0);
    if (test>0) {
     KK_In->at(i) = (80.0 / mean) * (80.0 / mean) * KK_In->at(i);
    }
   }
  }
 }
 
 delete gfit;
 delete CorrH;
}



int main (int argc, char ** argv)
{
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 
 treeReader reader (tr) ;
 
 TFile outFile("output/outFile_KK_8.root","RECREATE");
 
 TTree outTree("outTree","outTree");
 double t_M_Reco;
 std::vector<double>* t_pT_Reco = new std::vector<double>;
 std::vector<double>* t_pT_MC = new std::vector<double>;
 std::vector<double>* t_Eta_Reco = new std::vector<double>;
 int t_Cycle_num; //---- 0 = Before, 1 = After
 int t_Indip; //---- 0 = No Indip, 1 = Indip
 
 outTree.Branch("t_pT_Reco","std::vector<double>",&t_pT_Reco);
 outTree.Branch("t_pT_MC","std::vector<double>",&t_pT_MC);
 outTree.Branch("t_Eta_Reco","std::vector<double>",&t_Eta_Reco);
 outTree.Branch("t_M_Reco",&t_M_Reco,"t_M_Reco/D");
 outTree.Branch("t_Cycle_num",&t_Cycle_num,"t_Cycle_num/I");
 outTree.Branch("t_Indip",&t_Indip,"t_Indip/I");
 
 
 TH1F M_MC("M_MC","M_MC",1000,0,200);
 TH1F M_RECO("M_RECO","M_RECO",1000,0,200);
 TH1F M_RECO_AFTER("M_RECO_AFTER","M_RECO_AFTER",1000,0,200);
 
 TH1F PtOverPt_RECOMC("PtOverPt_RECOMC","PtOverPt_RECOMC",1000,0,4);
 TH1F PtOverPt_RECOMC_AFTER("PtOverPt_RECOMC_AFTER","PtOverPt_RECOMC_AFTER",1000,0,4);
 
 TH1F M_RECO_INDIP("M_RECO_INDIP","M_RECO_INDIP",1000,0,200);
 TH1F M_RECO_INDIP_AFTER("M_RECO_INDIP_AFTER","M_RECO_INDIP_AFTER",1000,0,200);
 TH1F PtOverPt_RECOMC_INDIP("PtOverPt_RECOMC_INDIP","PtOverPt_RECOMC_INDIP",1000,0,4);
 TH1F PtOverPt_RECOMC_INDIP_AFTER("PtOverPt_RECOMC_INDIP_AFTER","PtOverPt_RECOMC_INDIP_AFTER",1000,0,4);
 
 
 TH2F hKK_num("hKK_num","hKK_num",intPt,0,PtMax,intEta,0,EtaMax); //---- correction function K(eta) x K(pT) ----
 
 TH2F hKK("hKK","hKK",intPt,0,PtMax,intEta,0,EtaMax); //---- correction function K(eta) x K(pT) ----
 
 std::vector<TH2F> hKK_vect;
 
 
 std::vector<double>* KK = new std::vector<double>;
 for (int ii=0; ii< nParametri; ii++) {
  KK->push_back(1.);
 }
 
 std::cerr << std::endl << "*** nParametri = " << nParametri << " ***" << std::endl;
 
 
 double start, end;
 
 int nentries =  tr->GetEntries ();
 std::cerr << "nentries = " << nentries << std::endl;
 if (argc >= 4) nentries = atoi(argv[3]);
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
    std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> InputJetPair(jets->at(matchIt.at(0)),jets->at(matchIt.at(1)));
    InputJet->push_back(InputJetPair);
    
    double M_temp = (jets->at(matchIt.at(0)) + jets->at(matchIt.at(1))).M();
    M_RECO.Fill(M_temp) ;
    t_M_Reco = M_temp;    
    t_Eta_Reco->push_back(jets->at(matchIt.at(0)).Eta());
    t_Eta_Reco->push_back(jets->at(matchIt.at(1)).Eta());
    t_pT_Reco->push_back(jets->at(matchIt.at(0)).Pt());
    t_pT_Reco->push_back(jets->at(matchIt.at(1)).Pt()); 
    
    if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
     PtOverPt_RECOMC.Fill(jets->at(matchIt.at(0)).Pt() / mcF_fromV1->at(0).Pt() );
     PtOverPt_RECOMC.Fill(jets->at(matchIt.at(1)).Pt() / mcF_fromV1->at(1).Pt() );
     t_pT_MC->push_back(mcF_fromV1->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV1->at(1).Pt());
    }
    else {
     PtOverPt_RECOMC.Fill(jets->at(matchIt.at(0)).Pt() / mcF_fromV2->at(0).Pt() );
     PtOverPt_RECOMC.Fill(jets->at(matchIt.at(1)).Pt() / mcF_fromV2->at(1).Pt() );
     t_pT_MC->push_back(mcF_fromV2->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV2->at(1).Pt());
    }
    
    hKK_num.Fill(jets->at(matchIt.at(0)).Pt(),jets->at(matchIt.at(0)).Eta());
    hKK_num.Fill(jets->at(matchIt.at(1)).Pt(),jets->at(matchIt.at(1)).Eta());
    t_Cycle_num = 0; //---- before
    t_Indip = 0; //---- No Indip
    outTree.Fill();
    t_pT_MC->clear();
    t_pT_Reco->clear();
    t_Eta_Reco->clear();
    
   }
  }
  
  delete mcF_fromV1;
  delete mcF_fromV2;
 }
 
 int nCycle = 1;
 if (argc == 5) nCycle = atoi(argv[4]);
 std::cerr << "nCycle = " << nCycle << std::endl;
 
 for (int iCycle=0; iCycle< nCycle; iCycle++) { 
  std::ostringstream oss;
  oss << "hKK_" << iCycle;
  std::string nameHisto(oss.str());
  TH2F hKK_tmp(nameHisto.c_str(),nameHisto.c_str(),intPt,0,PtMax,intEta,0,EtaMax); //---- correction function K(eta) x K(pT) ----
  for (int iEta=0; iEta<intEta; iEta++){
   for (int iPt=0; iPt<intPt; iPt++){
    hKK_tmp.SetBinContent(iPt+1,iEta+1,KK->at(iPt * intEta + iEta));
    std::cerr << "KK[" << iPt << "][" << iEta << "] = " << KK->at(iPt * intEta + iEta) << std::endl;
   }
  }
  hKK_vect.push_back(hKK_tmp);  
  
  std::cerr << "Cycle = " << iCycle << std::endl;
  Update(KK);
  
 }
 
 for (int iEta=0; iEta<intEta; iEta++){
  for (int iPt=0; iPt<intPt; iPt++){
   hKK.SetBinContent(iPt+1,iEta+1,KK->at(iPt * intEta + iEta));
  }  
 }
 
 ///---- test Minimization ----
 
 
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
    int iPt1 = static_cast<int>(jets->at(matchIt.at(0)).Pt() / DPt);
    int iEta1 = static_cast<int>(fabs(jets->at(matchIt.at(0)).Eta() / DEta));
    
    int iPt2 = static_cast<int>(jets->at(matchIt.at(1)).Pt() / DPt);
    int iEta2 = static_cast<int>(fabs(jets->at(matchIt.at(0)).Eta() / DEta));
    
    double M_temp = (jets->at(matchIt.at(0)) + jets->at(matchIt.at(1))).M();
    
    if ((iPt1 >= intPt) || (iPt2 >= intPt) || (iEta1 >= intEta) || (iEta2 >= intEta)) continue; //---- data not used, out of range for KK!
     
     M_temp = M_temp * sqrt(KK->at(iPt1 * intEta + iEta1) * KK->at(iPt2 * intEta + iEta2));    
    M_RECO_AFTER.Fill(M_temp) ;
    t_M_Reco = M_temp;    
    t_Eta_Reco->push_back(jets->at(matchIt.at(0)).Eta());
    t_Eta_Reco->push_back(jets->at(matchIt.at(1)).Eta());
    t_pT_Reco->push_back(jets->at(matchIt.at(0)).Pt() * KK->at(iPt1 * intEta + iEta1));
    t_pT_Reco->push_back(jets->at(matchIt.at(1)).Pt() * KK->at(iPt2 * intEta + iEta2)); 
    
    if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
     PtOverPt_RECOMC_AFTER.Fill(jets->at(matchIt.at(0)).Pt() / mcF_fromV1->at(0).Pt() * KK->at(iPt1 * intEta + iEta1) );
     PtOverPt_RECOMC_AFTER.Fill(jets->at(matchIt.at(1)).Pt() / mcF_fromV1->at(1).Pt() * KK->at(iPt2 * intEta + iEta2) );
     t_pT_MC->push_back(mcF_fromV1->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV1->at(1).Pt());
    }
    else {
     PtOverPt_RECOMC_AFTER.Fill(jets->at(matchIt.at(0)).Pt() / mcF_fromV2->at(0).Pt() * KK->at(iPt1 * intEta + iEta1));
     PtOverPt_RECOMC_AFTER.Fill(jets->at(matchIt.at(1)).Pt() / mcF_fromV2->at(1).Pt() * KK->at(iPt2 * intEta + iEta2));
     t_pT_MC->push_back(mcF_fromV2->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV2->at(1).Pt());
    }
    t_Cycle_num = 1; //---- after
    t_Indip = 0; //---- No Indip
    outTree.Fill();
    t_pT_MC->clear();
    t_pT_Reco->clear();
    t_Eta_Reco->clear();
   }
  }
  
  delete mcF_fromV1;
  delete mcF_fromV2;
 }
 
 int nentriesTOT =  tr->GetEntries ();
 std::cerr << "nentriesTOT = " << nentriesTOT << std::endl;
 
 for (int iEvent = nentries ; iEvent < nentriesTOT ; ++iEvent)
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
    int iPt1 = static_cast<int>(jets->at(matchIt.at(0)).Pt() / DPt);
    int iEta1 = static_cast<int>(fabs(jets->at(matchIt.at(0)).Eta() / DEta));
    
    int iPt2 = static_cast<int>(jets->at(matchIt.at(1)).Pt() / DPt);
    int iEta2 = static_cast<int>(fabs(jets->at(matchIt.at(0)).Eta() / DEta));
    
    double M_temp = (jets->at(matchIt.at(0)) + jets->at(matchIt.at(1))).M();
    
    if ((iPt1 >= intPt) || (iPt2 >= intPt) || (iEta1 >= intEta) || (iEta2 >= intEta)) continue; //---- data not used, out of range for KK!
     
     M_RECO_INDIP.Fill(M_temp) ;
    double M_temp_Before = M_temp;    
    M_temp = M_temp * sqrt(KK->at(iPt1 * intEta + iEta1) * KK->at(iPt2 * intEta + iEta2));    
    M_RECO_INDIP_AFTER.Fill(M_temp) ;
    double M_temp_After = M_temp;    
    t_Eta_Reco->push_back(jets->at(matchIt.at(0)).Eta());
    t_Eta_Reco->push_back(jets->at(matchIt.at(1)).Eta());    
    if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
     PtOverPt_RECOMC_INDIP_AFTER.Fill(jets->at(matchIt.at(0)).Pt() / mcF_fromV1->at(0).Pt() * KK->at(iPt1 * intEta + iEta1) );
     PtOverPt_RECOMC_INDIP_AFTER.Fill(jets->at(matchIt.at(1)).Pt() / mcF_fromV1->at(1).Pt() * KK->at(iPt2 * intEta + iEta2) );
     PtOverPt_RECOMC_INDIP.Fill(jets->at(matchIt.at(0)).Pt() / mcF_fromV1->at(0).Pt());
     PtOverPt_RECOMC_INDIP.Fill(jets->at(matchIt.at(1)).Pt() / mcF_fromV1->at(1).Pt());
     t_pT_MC->push_back(mcF_fromV1->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV1->at(1).Pt());     
    }
    else {
     PtOverPt_RECOMC_INDIP_AFTER.Fill(jets->at(matchIt.at(0)).Pt() / mcF_fromV2->at(0).Pt() * KK->at(iPt1 * intEta + iEta1));
     PtOverPt_RECOMC_INDIP_AFTER.Fill(jets->at(matchIt.at(1)).Pt() / mcF_fromV2->at(1).Pt() * KK->at(iPt2 * intEta + iEta2));
     PtOverPt_RECOMC_INDIP_AFTER.Fill(jets->at(matchIt.at(0)).Pt() / mcF_fromV2->at(0).Pt());
     PtOverPt_RECOMC_INDIP_AFTER.Fill(jets->at(matchIt.at(1)).Pt() / mcF_fromV2->at(1).Pt());
     t_pT_MC->push_back(mcF_fromV2->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV2->at(1).Pt());     
    }
    t_Cycle_num = 0; //---- before
    t_Indip = 1; //---- Indep
    t_pT_Reco->push_back(jets->at(matchIt.at(0)).Pt());
    t_pT_Reco->push_back(jets->at(matchIt.at(1)).Pt()); 
    t_M_Reco = M_temp_Before;    
    outTree.Fill();
    t_pT_Reco->clear();
    t_Cycle_num = 1; //---- after
    t_pT_Reco->push_back(jets->at(matchIt.at(0)).Pt() * KK->at(iPt1 * intEta + iEta1));
    t_pT_Reco->push_back(jets->at(matchIt.at(1)).Pt() * KK->at(iPt2 * intEta + iEta2));
    t_M_Reco = M_temp_After;    
    outTree.Fill();
    t_pT_MC->clear();
    t_pT_Reco->clear();
    t_Eta_Reco->clear();
   }
  }
  
  delete mcF_fromV1;
  delete mcF_fromV2;
 }
 
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 delete t_pT_Reco;
 delete t_pT_MC;
 delete t_Eta_Reco;
 
 return 0 ;
}