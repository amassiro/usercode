#include "TString.h"
#include "TRandom3.h"
#include "TLorentzVector.h"
#include "math.h" 

float M_PI = 3.14159265;

//---------------------------------------------------

float min (float v1, float v2){
 return (v1<v2) ? v1 : v2;
}

//---------------------------------------------------

float DeltaPhi (float phi1, float phi2){
 float deltaphi = fabs(phi1 - phi2);
 if (deltaphi > 2*M_PI) deltaphi -= (2*M_PI);
 if (deltaphi > M_PI) deltaphi = (2*M_PI) - deltaphi;
 return deltaphi;
}

//---------------------------------------------------

int ReadFileCut(std::string CutFile, std::vector<std::string>& vCut){
 std::ifstream inFile(CutFile.c_str());
 std::string buffer; 
 while(!inFile.eof()){
  getline(inFile,buffer);
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){ 
    vCut.push_back(buffer);
    std::cout << " cut = " << buffer << std::endl;
   } 
  }
 }
 return vCut.size();
}

//---------------------------------------------------
//---------------------------------------------------
//---------------------------------------------------


void DYTauTauDD(TString nameSample, TString nameTree, TString globalCutFile, double mpmet_threshold_sameFlav, double mpmet_threshold_diffFlav, double pt_ele1_threshold, double pt_ele2_threshold, double pt_mu1_threshold, double pt_mu2_threshold){
 
 std::cout << " nameSample = " << nameSample.Data() << std::endl;
 std::cout << " nameTree   = " << nameTree.Data()   << std::endl;
 
 int nToy = 1000;
 std::cout << " nToy       = " << nToy   << std::endl;
 
 
 TFile* f = new TFile(nameSample, "READ");
 TTree* tree = (TTree*) f->Get(nameTree);
 
 std::vector<std::string> vCut;
 int nCut = ReadFileCut(globalCutFile.Data(), vCut);
 
 for (int iCut = 0; iCut < nCut; iCut++) {
  std::cout << " vCut[" << iCut << "] = " << vCut.at(iCut) << std::endl;
 }
//  TString globalCut = "njet==2 && detajj>3.5 && ((!sameflav && mpmet > 20) || (sameflav && mpmet > 40))";

 TString globalCut = vCut.at(0).c_str();
 
//  
//  channel == 0 -> mumu
//  channel == 1 -> ee
//  

 tree -> SetEntryList(0); 
 tree -> Draw(">> myList",globalCut.Data(),"entrylist");
 TEntryList *myList = (TEntryList*) gDirectory->Get("myList");
 tree -> SetEntryList(myList); 
 
 std::cout << " tot = " << myList->GetN() << " = " << tree -> GetEntries () << std::endl;
 
 float channel;
 
 float eta1;
 float eta2;
 
 float phi1;
 float phi2;
 
 float pt1;
 float pt2;
 
 float pfmetphi;
 float chmetphi;
 
 float pfmet;
 float chmet;

 float mpmet;
 
 tree -> SetBranchAddress("channel", &channel);
 tree -> SetBranchAddress("eta1", &eta1);
 tree -> SetBranchAddress("eta2", &eta2);
 tree -> SetBranchAddress("phi1", &phi1);
 tree -> SetBranchAddress("phi2", &phi2);
 tree -> SetBranchAddress("pt1", &pt1);
 tree -> SetBranchAddress("pt2", &pt2);
 tree -> SetBranchAddress("pfmetphi", &pfmetphi);
 tree -> SetBranchAddress("chmetphi", &chmetphi);
 tree -> SetBranchAddress("pfmet", &pfmet);
 tree -> SetBranchAddress("chmet", &chmet);
 tree -> SetBranchAddress("mpmet", &mpmet);
 
 TRandom3 rand;
 TF1 *pdf = new TF1("pdf","x^2 * (3-2*x)",0,3./2.);
 
 float m_tau = 1.77684 ; // GeV
//  float m_ele = 0.000511; // GeV
//  float m_mu  = 0.106   ; // GeV
 
 double ee_gen_factor   = 1. / 64.;
 double emu_gen_factor  = 1. / 64.;
 double mue_gen_factor  = 1. / 64.;
 double mumu_gen_factor = 1. / 64.;
 
 double ratio_mumu_mumu = 0.;
 double ratio_ee_mumu = 0.;
 double ratio_emu_mumu = 0.;
 double ratio_mue_mumu = 0.;
 
 double ratio_mumu_ee = 0.;
 double ratio_ee_ee = 0.;
 double ratio_emu_ee = 0.;
 double ratio_mue_ee = 0.;
 
 int total_ee   = 0;
 int total_mumu = 0;
 
 for (int iEntry = 0; iEntry < myList -> GetN () ; iEntry++) { //---- loop on events (begin) ----
  if (!(iEntry%100)) std::cout << " iEntry = " << iEntry << " :: " << myList -> GetN () << std::endl;
  tree -> GetEntry (myList->Next());
  
  ///-----------------------------------------
  ///---- dG / dcostheta /dx = x^2 (3-2x)
  ///---- x = 2 E_l/m_tau
  ///-----------------------------------------
  
  float costheta;
  float theta;
  float phi;
  float x;
  float El;
  
  for (int iToy = 0; iToy<nToy; iToy++){ //---- loop toy (begin) ----


   double e1 = pt1 / sin (2 * atan(exp(-eta1))) ;
   e1 = sqrt(e1*e1 + m_tau*m_tau);
   double e2 = pt2 / sin (2 * atan(exp(-eta2))) ;
   e2 = sqrt(e2*e2 + m_tau*m_tau);
   
   TLorentzVector old_lepton1;
   old_lepton1.SetPtEtaPhiE(pt1,eta1,phi1,e1);
   TLorentzVector old_lepton2;
   old_lepton2.SetPtEtaPhiE(pt2,eta2,phi2,e2);
   
   
   //---- first lepton ----
   costheta = rand.Uniform(-1.0,1.0);
   theta = acos (costheta);
   phi = rand.Uniform(0.0,M_PI);
   x = pdf->GetRandom();
   El = m_tau / 2. * x;
   
   
   TLorentzVector new_lepton1;
   new_lepton1.SetPtEtaPhiE(El*sin(theta), - TMath::Log (TMath::Tan (theta/2.)), phi, El);
   
   TVector3 boost;
//    boost.SetPtEtaPhi(pt1, eta1, phi1);
   boost = old_lepton1.BoostVector(); 
   
   //---- now boost
   new_lepton1.Boost(boost);
   //---- now the "new_lepton1" is boosted!
   
   
   
   //---- second lepton ----
   costheta = rand.Uniform(-1.0,1.0);
   theta = acos (costheta);
   phi = rand.Uniform(0.0,M_PI);
   x = pdf->GetRandom();
   El = m_tau / 2. * x;
   
   TLorentzVector new_lepton2;
   new_lepton2.SetPtEtaPhiE(El*sin(theta), - TMath::Log (TMath::Tan (theta/2.)), phi, El);
   
//    std::cout << "  pt2 = " << pt2 << " eta2 = " << eta2 << " phi2 = " << phi2 << std::endl;
   
   boost = old_lepton2.BoostVector(); 
   
//    boost.SetPtEtaPhi(pt2, eta2, phi2);

//    boost.Print();
   //    new_lepton2.Print();tau
   //---- now boost
   new_lepton2.Boost(boost);
   //---- now the "new_lepton2" is boosted!
//    new_lepton2.Print();

   
   TVector2 v_pfmet (pfmet*cos(pfmetphi), pfmet*sin(pfmetphi));
   TVector2 v_chmet (chmet*cos(chmetphi), pfmet*sin(chmetphi));
   
   TVector2 v_old_lepton1 (pt1*cos(phi1), pt1*sin(phi1));
   TVector2 v_old_lepton2 (pt2*cos(phi2), pt2*sin(phi2));
   
   TVector2 v_new_lepton1 (new_lepton1.X(), new_lepton1.Y());
   TVector2 v_new_lepton2 (new_lepton2.X(), new_lepton2.Y());
   
   float v_new_lepton1_pt = v_new_lepton1.Mod();
   float v_new_lepton2_pt = v_new_lepton2.Mod();
   
   if (v_new_lepton2_pt > v_new_lepton1_pt) {
    double temp_pt = v_new_lepton1_pt;
    v_new_lepton1_pt = v_new_lepton2_pt;
    v_new_lepton2_pt = temp_pt;
   }
   
   
   v_pfmet = v_pfmet + v_old_lepton1 - v_new_lepton1 + v_old_lepton2 - v_new_lepton2;
   v_chmet = v_chmet + v_old_lepton1 - v_new_lepton1 + v_old_lepton2 - v_new_lepton2;
   
   float new_ppfmet = v_pfmet.Mod();
   float new_pchmet = v_chmet.Mod();
   float dphi1, dphi2, dphi;
   
   dphi1 = DeltaPhi(v_pfmet.Phi(),new_lepton1.Phi());
   dphi2 = DeltaPhi(v_pfmet.Phi(),new_lepton2.Phi());
   dphi = min(dphi1, dphi2);
   if (dphi < (M_PI / 2.)) new_ppfmet = new_ppfmet * ( sin(dphi) );
   
   
   dphi1 = DeltaPhi(v_chmet.Phi(),new_lepton1.Phi());
   dphi2 = DeltaPhi(v_chmet.Phi(),new_lepton2.Phi());
   dphi = min(dphi1, dphi2);
   if (dphi < ( M_PI/2.)) new_pchmet = new_pchmet * ( sin(dphi) );
   
   float new_mpmet = min(new_ppfmet,new_pchmet);
   
   
   
   //---- mumu ----
   if (channel == 0) {
    
    if (mpmet > mpmet_threshold_sameFlav && pt1 > pt_mu1_threshold && pt2 > pt_mu2_threshold){
     total_mumu++;
    }
    
    //---- same flav ----
    if (new_mpmet > mpmet_threshold_sameFlav) {
     //---- mumu ----
     if ( (v_new_lepton1_pt > pt_mu1_threshold && v_new_lepton2_pt > pt_mu2_threshold) ) {
      ratio_mumu_mumu += mumu_gen_factor / nToy;      
     }
     //---- ee ----
     if ( (v_new_lepton1_pt > pt_ele1_threshold && v_new_lepton2_pt > pt_ele2_threshold) ) {
      ratio_ee_mumu += ee_gen_factor / nToy;      
     }
    }
    //---- diff flav ----
    if (new_mpmet > mpmet_threshold_diffFlav) {
     //---- emu ----
     if ( (v_new_lepton1_pt > pt_ele1_threshold && v_new_lepton2_pt > pt_mu2_threshold) ) {
      ratio_emu_mumu += emu_gen_factor / nToy;      
     }
     //---- mue ----
     if ( (v_new_lepton1_pt > pt_mu1_threshold && v_new_lepton2_pt > pt_ele2_threshold) ) {
      ratio_mue_mumu += mue_gen_factor / nToy;      
     }
    }
   }
   
   //---- ee ----
   if (channel == 1) {    
    if (mpmet > mpmet_threshold_sameFlav && pt1 > pt_ele1_threshold && pt2 > pt_ele2_threshold){
     total_ee++;
    }
    //---- same flav ----
    if (new_mpmet > mpmet_threshold_sameFlav) {
     //---- mumu ----
     if ( (v_new_lepton1_pt > pt_mu1_threshold && v_new_lepton2_pt > pt_mu2_threshold) ) {
      ratio_mumu_ee += ee_gen_factor / nToy;      
     }
     //---- ee ----
     if ( (v_new_lepton1_pt > pt_ele1_threshold && v_new_lepton2_pt > pt_ele2_threshold) ) {
      ratio_ee_ee += ee_gen_factor / nToy;      
     }
    }
    //---- diff flav ----
    if (new_mpmet > mpmet_threshold_diffFlav) {
     //---- emu ----
     if ( (v_new_lepton1_pt > pt_ele1_threshold && v_new_lepton2_pt > pt_mu2_threshold) ) {
      ratio_emu_ee += emu_gen_factor / nToy;      
     }
     //---- mue ----
     if ( (v_new_lepton1_pt > pt_mu1_threshold && v_new_lepton2_pt > pt_ele2_threshold) ) {
      ratio_mue_ee += mue_gen_factor / nToy;      
     }
    }
   }   
   
  } //---- loop toy (end) ----
 } //---- loop on events (end) ----
 
 
 //---- rescale for normalization ----
 ratio_mumu_ee /= total_ee;
 ratio_ee_ee   /= total_ee;
 ratio_mue_ee  /= total_ee;
 ratio_emu_ee  /= total_ee;
 
 ratio_mumu_mumu /= total_mumu;
 ratio_mumu_mumu /= total_mumu;
 ratio_mue_mumu  /= total_mumu;
 ratio_emu_mumu  /= total_mumu;
 
 std::cout << " ******************** " << std::endl;
 std::cout << " ******************** " << std::endl;
 std::cout << " ratio_mumu_ee = " << ratio_mumu_ee << std::endl;
 std::cout << " ratio_ee_ee   = " << ratio_ee_ee   << std::endl;
 std::cout << " ratio_mue_ee  = " << ratio_mue_ee  << std::endl;
 std::cout << " ratio_emu_ee  = " << ratio_emu_ee  << std::endl;
 
 std::cout << " ******************** " << std::endl;
 std::cout << " ratio_mumu_mumu = " << ratio_mumu_mumu << std::endl;
 std::cout << " ratio_mumu_mumu   = " << ratio_mumu_mumu   << std::endl;
 std::cout << " ratio_mue_mumu  = " << ratio_mue_mumu  << std::endl;
 std::cout << " ratio_emu_mumu  = " << ratio_emu_mumu  << std::endl;
 
 std::cout << " ******************** " << std::endl;
 std::cout << " ******************** " << std::endl;
 
 
 
}