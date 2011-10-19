#include "TString.h"
#include "TRandom3.h"
#include "TLorentzVector.h"
#include "math.h" 

float M_PI = 3.14159265;

//---------------------------------------------------

float wmean (float v1, float v2, float errv1, float errv2){
 return (v1/errv1/errv1+v2/errv2/errv2)/(1./errv1/errv1+1./errv2/errv2);
}

//---------------------------------------------------

float wmeanerr (float v1, float v2, float errv1, float errv2){
 return sqrt(1./(1./errv1/errv1+1./errv2/errv2));
}

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


void DYTauTauDD_Scan(int WP, double Rmumuinout, double Reeinout, double numDYmumuBDD,  double numDYeeBDD, double errnumDYmumuBDD,  double errnumDYeeBDD, TString nameSample, TString nameTree, TString globalCutFile, double mpmet_threshold_sameFlav_min, int numScan, double DeltaMpmet, double mpmet_threshold_diffFlav, double pt_ele1_threshold, double pt_ele2_threshold, double pt_mu1_threshold, double pt_mu2_threshold){
 
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

 float mll;
 
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
 tree -> SetBranchAddress("mll", &mll);
 
 
 Double_t new_mll[1000000];
 Double_t old_mll[1000000];
 
 
 TRandom3 rand;
 TF1 *pdf = new TF1("pdf","x^2 * (3-2*x)",0,3./2.);
 
 float m_tau = 1.77684 ; // GeV
//  float m_ele = 0.000511; // GeV
//  float m_mu  = 0.106   ; // GeV
 
 double mpmet_threshold_sameFlav;
 
 double ee_gen_factor   = 1. / 64.;
 double emu_gen_factor  = 1. / 64.;
 double mue_gen_factor  = 1. / 64.;
 double mumu_gen_factor = 1. / 64.;
 
 Double_t ratio_mumu_mumu[1000];
 Double_t ratio_ee_mumu[1000];
 Double_t ratio_emu_mumu[1000];
 Double_t ratio_mue_mumu[1000];
 
 Double_t ratio_mumu_ee[1000];
 Double_t ratio_ee_ee[1000];
 Double_t ratio_emu_ee[1000];
 Double_t ratio_mue_ee[1000];
 
 int total_ee  [1000];
 int total_mumu[1000];
 
 for (int iScan = 0; iScan < numScan; iScan++) {
  ratio_mumu_mumu[iScan] = 0.;
  ratio_ee_mumu[iScan] = 0.;
  ratio_emu_mumu[iScan] = 0.;
  ratio_mue_mumu[iScan] = 0.;
  
  ratio_mumu_ee[iScan] = 0.;
  ratio_ee_ee[iScan] = 0.;
  ratio_emu_ee[iScan] = 0.;
  ratio_mue_ee[iScan] = 0.;
  
  total_ee  [iScan] = 0.;
  total_mumu[iScan] = 0.;
 }
  
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

   
   new_mll[iToy+iEntry*nToy] = ( new_lepton2 + new_lepton1 ).Mag();
   old_mll[iToy+iEntry*nToy] = mll;
   
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
   
   
   
   
   for (int iScan = 0; iScan < numScan; iScan++) { //---- loop on met scan (begin) ----
    mpmet_threshold_sameFlav = mpmet_threshold_sameFlav_min + DeltaMpmet * iScan;
    
    //---- mumu ----
    if (channel == 0) {
     
     if (mpmet > mpmet_threshold_sameFlav && pt1 > pt_mu1_threshold && pt2 > pt_mu2_threshold){
      total_mumu[iScan]++;
     }
     
     //---- same flav ----
     if (new_mpmet > mpmet_threshold_sameFlav) {
      //---- mumu ----
      if ( (v_new_lepton1_pt > pt_mu1_threshold && v_new_lepton2_pt > pt_mu2_threshold) ) {
//        ratio_mumu_mumu[iScan] += mumu_gen_factor / nToy;      
       ratio_mumu_mumu[iScan] += mumu_gen_factor;      
      }
      //---- ee ----
      if ( (v_new_lepton1_pt > pt_ele1_threshold && v_new_lepton2_pt > pt_ele2_threshold) ) {
//        ratio_ee_mumu[iScan] += ee_gen_factor / nToy;      
       ratio_ee_mumu[iScan] += ee_gen_factor;      
      }
     }
     //---- diff flav ----
     if (new_mpmet > mpmet_threshold_diffFlav) {
      //---- emu ----
      if ( (v_new_lepton1_pt > pt_ele1_threshold && v_new_lepton2_pt > pt_mu2_threshold) ) {
//        ratio_emu_mumu[iScan] += emu_gen_factor / nToy;      
       ratio_emu_mumu[iScan] += emu_gen_factor;      
      }
      //---- mue ----
      if ( (v_new_lepton1_pt > pt_mu1_threshold && v_new_lepton2_pt > pt_ele2_threshold) ) {
//        ratio_mue_mumu[iScan] += mue_gen_factor / nToy;
       ratio_mue_mumu[iScan] += mue_gen_factor ;      
      }
     }
    }
    
    //---- ee ----
    if (channel == 1) {    
     if (mpmet > mpmet_threshold_sameFlav && pt1 > pt_ele1_threshold && pt2 > pt_ele2_threshold){
      total_ee[iScan]++;
     }
     //---- same flav ----
     if (new_mpmet > mpmet_threshold_sameFlav) {
      //---- mumu ----
      if ( (v_new_lepton1_pt > pt_mu1_threshold && v_new_lepton2_pt > pt_mu2_threshold) ) {
//        ratio_mumu_ee[iScan] += ee_gen_factor / nToy;
       ratio_mumu_ee[iScan] += ee_gen_factor ;      
      }
      //---- ee ----
      if ( (v_new_lepton1_pt > pt_ele1_threshold && v_new_lepton2_pt > pt_ele2_threshold) ) {
//        ratio_ee_ee[iScan] += ee_gen_factor / nToy;
       ratio_ee_ee[iScan] += ee_gen_factor ;      
      }
     }
     //---- diff flav ----
     if (new_mpmet > mpmet_threshold_diffFlav) {
      //---- emu ----
      if ( (v_new_lepton1_pt > pt_ele1_threshold && v_new_lepton2_pt > pt_mu2_threshold) ) {
//        ratio_emu_ee[iScan] += emu_gen_factor / nToy;
       ratio_emu_ee[iScan] += emu_gen_factor ;      
      }
      //---- mue ----
      if ( (v_new_lepton1_pt > pt_mu1_threshold && v_new_lepton2_pt > pt_ele2_threshold) ) {
//        ratio_mue_ee[iScan] += mue_gen_factor / nToy;      
       ratio_mue_ee[iScan] += mue_gen_factor ;      
      }
     }
    }
   } //---- loop on met scan (end) ----
   
  } //---- loop toy (end) ----
 } //---- loop on events (end) ----
 
 
 //---- rescale for normalization ----
 
 TGraph* gr_ratio_mumu_ee = new TGraph();
 TGraph* gr_ratio_ee_ee = new TGraph();
 TGraph* gr_ratio_emu_ee = new TGraph();
 TGraph* gr_ratio_mue_ee = new TGraph();
 
 TGraph* gr_ratio_mumu_mumu = new TGraph();
 TGraph* gr_ratio_ee_mumu = new TGraph();
 TGraph* gr_ratio_emu_mumu = new TGraph();
 TGraph* gr_ratio_mue_mumu = new TGraph();
 
 gr_ratio_mumu_ee->SetTitle("#rho #mu#mu/ee");
 gr_ratio_ee_ee->SetTitle("#rho ee/ee");
 gr_ratio_emu_ee->SetTitle("#rho e#mu/ee");
 gr_ratio_mue_ee->SetTitle("#rho #mu e/ee");
 
 gr_ratio_mumu_mumu->SetTitle("#rho #mu#mu/#mu#mu");
 gr_ratio_ee_mumu->SetTitle("#rho ee/#mu#mu");
 gr_ratio_emu_mumu->SetTitle("#rho e#mu/#mu#mu");
 gr_ratio_mue_mumu->SetTitle("#rho #mu e/#mu#mu");
 
 gr_ratio_mumu_ee -> SetMarkerColor(kRed);
 gr_ratio_ee_ee   -> SetMarkerColor(kBlue);
 gr_ratio_emu_ee  -> SetMarkerColor(kGreen);
 gr_ratio_mue_ee  -> SetMarkerColor(kMagenta);
 
 gr_ratio_mumu_mumu -> SetMarkerColor(kRed+2);
 gr_ratio_ee_mumu   -> SetMarkerColor(kBlue+2);
 gr_ratio_emu_mumu  -> SetMarkerColor(kGreen+2);
 gr_ratio_mue_mumu  -> SetMarkerColor(kMagenta+2);
 
 gr_ratio_mumu_ee -> SetLineColor(kRed);
 gr_ratio_ee_ee   -> SetLineColor(kBlue);
 gr_ratio_emu_ee  -> SetLineColor(kGreen);
 gr_ratio_mue_ee  -> SetLineColor(kMagenta);
 
 gr_ratio_mumu_mumu -> SetLineColor(kRed+2);
 gr_ratio_ee_mumu   -> SetLineColor(kBlue+2);
 gr_ratio_emu_mumu  -> SetLineColor(kGreen+2);
 gr_ratio_mue_mumu  -> SetLineColor(kMagenta+2);
 
 gr_ratio_mumu_ee -> SetMarkerStyle(20);
 gr_ratio_ee_ee   -> SetMarkerStyle(21);
 gr_ratio_emu_ee  -> SetMarkerStyle(22);
 gr_ratio_mue_ee  -> SetMarkerStyle(23);
 
 gr_ratio_mumu_mumu -> SetMarkerStyle(24);
 gr_ratio_ee_mumu   -> SetMarkerStyle(25);
 gr_ratio_emu_mumu  -> SetMarkerStyle(26);
 gr_ratio_mue_mumu  -> SetMarkerStyle(27);

 gr_ratio_mumu_ee -> SetMarkerSize(1);
 gr_ratio_ee_ee   -> SetMarkerSize(1);
 gr_ratio_emu_ee  -> SetMarkerSize(1);
 gr_ratio_mue_ee  -> SetMarkerSize(1);
 
 gr_ratio_mumu_mumu -> SetMarkerSize(1);
 gr_ratio_ee_mumu   -> SetMarkerSize(1);
 gr_ratio_emu_mumu  -> SetMarkerSize(1);
 gr_ratio_mue_mumu  -> SetMarkerSize(1);
 
 gr_ratio_mumu_ee -> SetFillColor(0);
 gr_ratio_ee_ee   -> SetFillColor(0);
 gr_ratio_emu_ee  -> SetFillColor(0);
 gr_ratio_mue_ee  -> SetFillColor(0);
 
 gr_ratio_mumu_mumu -> SetFillColor(0);
 gr_ratio_ee_mumu   -> SetFillColor(0);
 gr_ratio_emu_mumu  -> SetFillColor(0);
 gr_ratio_mue_mumu  -> SetFillColor(0);
 
 for (Int_t iScan = 0; iScan < numScan; iScan++) {
  ratio_mumu_ee[iScan] /= total_ee[iScan];
  ratio_ee_ee[iScan]   /= total_ee[iScan];
  ratio_mue_ee[iScan]  /= total_ee[iScan];
  ratio_emu_ee[iScan]  /= total_ee[iScan];
  
  ratio_mumu_mumu[iScan] /= total_mumu[iScan];
  ratio_ee_mumu[iScan]   /= total_mumu[iScan];
  ratio_mue_mumu[iScan]  /= total_mumu[iScan];
  ratio_emu_mumu[iScan]  /= total_mumu[iScan];
  
  mpmet_threshold_sameFlav = mpmet_threshold_sameFlav_min + DeltaMpmet * iScan;
  
  gr_ratio_mumu_ee -> SetPoint(iScan, (Double_t) mpmet_threshold_sameFlav, (Double_t) ratio_mumu_ee[iScan]  );
  gr_ratio_ee_ee   -> SetPoint(iScan, (Double_t) mpmet_threshold_sameFlav, (Double_t) ratio_ee_ee[iScan]    );
  gr_ratio_emu_ee  -> SetPoint(iScan, (Double_t) mpmet_threshold_sameFlav, (Double_t) ratio_emu_ee[iScan]);
  gr_ratio_mue_ee  -> SetPoint(iScan, (Double_t) mpmet_threshold_sameFlav, (Double_t) ratio_mue_ee[iScan]);
  
  gr_ratio_mumu_mumu -> SetPoint(iScan, (Double_t) mpmet_threshold_sameFlav, (Double_t) ratio_mumu_mumu[iScan]  );
  gr_ratio_ee_mumu   -> SetPoint(iScan, (Double_t) mpmet_threshold_sameFlav, (Double_t) ratio_ee_mumu[iScan]    );
  gr_ratio_emu_mumu  -> SetPoint(iScan, (Double_t) mpmet_threshold_sameFlav, (Double_t) ratio_emu_mumu[iScan]);
  gr_ratio_mue_mumu  -> SetPoint(iScan, (Double_t) mpmet_threshold_sameFlav, (Double_t) ratio_mue_mumu[iScan]);
  
//   std::cout << " ******************** " << std::endl;
//   std::cout << " ******************** " << std::endl;
//   std::cout << " ratio_mumu_ee[" << iScan << "] = " << ratio_mumu_ee[iScan] << std::endl;
//   std::cout << " ratio_ee_ee[" << iScan << "]   = " << ratio_ee_ee[iScan]   << std::endl;
//   std::cout << " ratio_mue_ee[" << iScan << "]  = " << ratio_mue_ee[iScan]  << std::endl;
//   std::cout << " ratio_emu_ee[" << iScan << "]  = " << ratio_emu_ee[iScan]  << std::endl;
//   
//   std::cout << " ******************** " << std::endl;
//   std::cout << " ratio_mumu_mumu[" << iScan << "] = " << ratio_mumu_mumu[iScan] << std::endl;
//   std::cout << " ratio_mumu_mumu[" << iScan << "]   = " << ratio_mumu_mumu[iScan]   << std::endl;
//   std::cout << " ratio_mue_mumu[" << iScan << "]  = " << ratio_mue_mumu[iScan]  << std::endl;
//   std::cout << " ratio_emu_mumu[" << iScan << "]  = " << ratio_emu_mumu[iScan]  << std::endl;
//   
//   std::cout << " ******************** " << std::endl;
//   std::cout << " ******************** " << std::endl;
  
 }
 
 
 std::cout << " nToy       = " << nToy    << std::endl;
 std::cout << " numScan    = " << numScan << std::endl;
 
 
 TMultiGraph* mgr = new TMultiGraph();
 mgr-> Add (gr_ratio_mumu_ee);
 mgr-> Add (gr_ratio_ee_ee);
 mgr-> Add (gr_ratio_emu_ee);
 mgr-> Add (gr_ratio_mue_ee);
 
 mgr-> Add (gr_ratio_mumu_mumu);
 mgr-> Add (gr_ratio_ee_mumu);
 mgr-> Add (gr_ratio_emu_mumu);
 mgr-> Add (gr_ratio_mue_mumu);
 
 mgr->Draw("APL");
 mgr->GetXaxis()->SetTitle("met (same flavour) > threshold (GeV)");
 mgr->GetYaxis()->SetTitle("#rho");
 
 gPad->SetGrid();
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 TCanvas* cc = new TCanvas();
 
 TGraph* gr_Mll = new TGraph();
 gr_Mll -> SetTitle("Mll");
 gr_Mll -> SetMarkerColor(kRed);
//  gr_Mll -> SetLineColor(kRed);
//  gr_Mll -> SetMarkerStyle(20);
//  gr_Mll -> SetMarkerSize(1);
 gr_Mll -> SetFillColor(0);
 
 for (int iEntry = 0; iEntry < myList -> GetN () ; iEntry++) {
  for (int iToy = 0; iToy<nToy; iToy++){
   gr_Mll -> SetPoint(iToy+iEntry*nToy,old_mll[iToy+iEntry*nToy],new_mll[iToy+iEntry*nToy]);
  }
 }
 gr_Mll->Draw("AP");
 gr_Mll->GetXaxis()->SetTitle("m_{#tau#tau} ");
 gr_Mll->GetYaxis()->SetTitle("m_{ll}");
 
 
 
 
 
 
 ///---- results for datacard ----
 
 double tautau_ee_ee   = ratio_ee_ee[WP]   * numDYeeBDD;
 double tautau_emu_ee  = ratio_emu_ee[WP]  * numDYeeBDD;
 double tautau_mue_ee  = ratio_mue_ee[WP]  * numDYeeBDD;
 double tautau_mumu_ee = ratio_mumu_ee[WP] * numDYeeBDD;
 
 double tautau_ee_mumu   = ratio_ee_mumu[WP]   * numDYmumuBDD;
 double tautau_emu_mumu  = ratio_emu_mumu[WP]  * numDYmumuBDD;
 double tautau_mue_mumu  = ratio_mue_mumu[WP]  * numDYmumuBDD;
 double tautau_mumu_mumu = ratio_mumu_mumu[WP] * numDYmumuBDD;

 double errtautau_ee_ee   = ratio_ee_ee[WP]   * errnumDYeeBDD;
 double errtautau_emu_ee  = ratio_emu_ee[WP]  * errnumDYeeBDD;
 double errtautau_mue_ee  = ratio_mue_ee[WP]  * errnumDYeeBDD;
 double errtautau_mumu_ee = ratio_mumu_ee[WP] * errnumDYeeBDD;
 
 double errtautau_ee_mumu   = ratio_ee_mumu[WP]   * errnumDYmumuBDD;
 double errtautau_emu_mumu  = ratio_emu_mumu[WP]  * errnumDYmumuBDD;
 double errtautau_mue_mumu  = ratio_mue_mumu[WP]  * errnumDYmumuBDD;
 double errtautau_mumu_mumu = ratio_mumu_mumu[WP] * errnumDYmumuBDD;
 
 std::cout << " ******************** " << std::endl;
 
 std::cout << " tautau_ee_ee   = " << tautau_ee_ee   << " +/- " << errtautau_ee_ee   << std::endl;
 std::cout << " tautau_emu_ee  = " << tautau_emu_ee  << " +/- " << errtautau_emu_ee  << std::endl;
 std::cout << " tautau_mue_ee  = " << tautau_mue_ee  << " +/- " << errtautau_mue_ee  << std::endl;
 std::cout << " tautau_mumu_ee = " << tautau_mumu_ee << " +/- " << errtautau_mumu_ee << std::endl;
 std::cout << " ******************** " << std::endl;
 std::cout << " tautau_ee_mumu   = " << tautau_ee_mumu   << " +/- " << errtautau_ee_mumu   << std::endl;
 std::cout << " tautau_emu_mumu  = " << tautau_emu_mumu  << " +/- " << errtautau_emu_mumu  << std::endl;
 std::cout << " tautau_mue_mumu  = " << tautau_mue_mumu  << " +/- " << errtautau_mue_mumu  << std::endl;
 std::cout << " tautau_mumu_mumu = " << tautau_mumu_mumu << " +/- " << errtautau_mumu_mumu << std::endl;
 std::cout << " ******************** " << std::endl;
 
 
 std::cout << " ******************** " << std::endl;
 std::cout << " ******************** " << std::endl;
 std::cout << " ******************** " << std::endl;
 std::cout << " tautau_ee   = " << tautau_ee_mumu   << " ~ " << tautau_ee_ee   << " = " << (tautau_ee_mumu+tautau_ee_ee)/2. << " +/- " << (tautau_ee_mumu - tautau_ee_ee) / 2. << std::endl;
 std::cout << " tautau_emu  = " << tautau_emu_mumu  << " ~ " << tautau_emu_ee  << " = " << (tautau_emu_mumu+tautau_emu_ee)/2. << " +/- " << (tautau_emu_mumu - tautau_emu_ee) / 2. << std::endl;
 std::cout << " tautau_mue  = " << tautau_mue_mumu  << " ~ " << tautau_mue_ee  << " = " << (tautau_mue_mumu+tautau_mue_ee)/2. << " +/- " << (tautau_mue_mumu - tautau_mue_ee) / 2. << std::endl;
 std::cout << " tautau_mumu = " << tautau_mumu_mumu << " ~ " << tautau_mumu_ee << " = " << (tautau_mumu_mumu+tautau_mumu_ee)/2. << " +/- " << (tautau_mumu_mumu - tautau_mumu_ee) / 2. << std::endl;
 std::cout << " ******************** " << std::endl;
 std::cout << " tautau   = " << (tautau_ee_mumu+tautau_ee_ee)/2. + (tautau_emu_mumu+tautau_emu_ee)/2. + (tautau_mue_mumu+tautau_mue_ee)/2. + (tautau_mumu_mumu+tautau_mumu_ee)/2. << " +/- " << 1./2. * sqrt((tautau_ee_mumu - tautau_ee_ee)*(tautau_ee_mumu - tautau_ee_ee) + (tautau_emu_mumu - tautau_emu_ee)*(tautau_emu_mumu - tautau_emu_ee) + (tautau_mue_mumu - tautau_mue_ee)*(tautau_mue_mumu - tautau_mue_ee) + (tautau_mumu_mumu - tautau_mumu_ee)*(tautau_mumu_mumu - tautau_mumu_ee) ) << std::endl;
 std::cout << " ******************** " << std::endl;
 
 std::cout << " ******************** " << std::endl;
 std::cout << " tautau_ee   = " << wmean(tautau_ee_mumu,tautau_ee_ee,errtautau_ee_mumu,errtautau_ee_ee) << " +/- " <<  wmeanerr(tautau_ee_mumu,tautau_ee_ee,errtautau_ee_mumu,errtautau_ee_ee) << std::endl;
 std::cout << " tautau_emu  = " << wmean(tautau_emu_mumu,tautau_emu_ee,errtautau_emu_mumu,errtautau_emu_ee) << " +/- " <<  wmeanerr(tautau_emu_mumu,tautau_emu_ee,errtautau_emu_mumu,errtautau_emu_ee) << std::endl;
 std::cout << " tautau_mue  = " << wmean(tautau_mue_mumu,tautau_mue_ee,errtautau_mue_mumu,errtautau_mue_ee) << " +/- " <<  wmeanerr(tautau_mue_mumu,tautau_mue_ee,errtautau_mue_mumu,errtautau_mue_ee) << std::endl;
 std::cout << " tautau_mumu = " << wmean(tautau_mumu_mumu,tautau_mumu_ee,errtautau_mumu_mumu,errtautau_mumu_ee) << " +/- " <<  wmeanerr(tautau_mumu_mumu,tautau_mumu_ee,errtautau_mumu_mumu,errtautau_mumu_ee) << std::endl;
 std::cout << " ******************** " << std::endl;
 double tautau =  wmean(tautau_ee_mumu,tautau_ee_ee,errtautau_ee_mumu,errtautau_ee_ee) + 
                                wmean(tautau_emu_mumu,tautau_emu_ee,errtautau_emu_mumu,errtautau_emu_ee) + 
				wmean(tautau_mue_mumu,tautau_mue_ee,errtautau_mue_mumu,errtautau_mue_ee) +
				wmean(tautau_mumu_mumu,tautau_mumu_ee,errtautau_mumu_mumu,errtautau_mumu_ee);
 double errtautau = sqrt(  wmeanerr(tautau_ee_mumu,tautau_ee_ee,errtautau_ee_mumu,errtautau_ee_ee)*wmeanerr(tautau_ee_mumu,tautau_ee_ee,errtautau_ee_mumu,errtautau_ee_ee) + 
				wmeanerr(tautau_emu_mumu,tautau_emu_ee,errtautau_emu_mumu,errtautau_emu_ee)*wmeanerr(tautau_emu_mumu,tautau_emu_ee,errtautau_emu_mumu,errtautau_emu_ee) + 
				wmeanerr(tautau_mue_mumu,tautau_mue_ee,errtautau_mue_mumu,errtautau_mue_ee)*wmeanerr(tautau_mue_mumu,tautau_mue_ee,errtautau_mue_mumu,errtautau_mue_ee) +
				wmeanerr(tautau_mumu_mumu,tautau_mumu_ee,errtautau_mumu_mumu,errtautau_mumu_ee)*wmeanerr(tautau_mumu_mumu,tautau_mumu_ee,errtautau_mumu_mumu,errtautau_mumu_ee));
 std::cout << " tautau   = " << tautau ;
 std::cout << " +/- " << errtautau ;
 std::cout << " ---> " << 1+errtautau/tautau;
 std::cout << std::endl;
 std::cout << " ******************** " << std::endl;
 
 double tautau_ee = (1. + Reeinout) * ( tautau_ee_ee + tautau_emu_ee + tautau_mue_ee + tautau_mumu_ee);
 double errtautau_ee = (1. + Reeinout) * sqrt(errtautau_ee_ee*errtautau_ee_ee + errtautau_emu_ee*errtautau_emu_ee + errtautau_mue_ee*errtautau_mue_ee + errtautau_mumu_ee*errtautau_mumu_ee);
 double tautau_mumu = (1. + Rmumuinout) * ( tautau_ee_mumu + tautau_emu_mumu + tautau_mue_mumu + tautau_mumu_mumu);
 double errtautau_mumu =  (1.+ Rmumuinout) * sqrt(errtautau_ee_mumu*errtautau_ee_mumu + errtautau_emu_mumu*errtautau_emu_mumu + errtautau_mue_mumu*errtautau_mue_mumu + errtautau_mumu_mumu*errtautau_mumu_mumu);
 std::cout << " tautau (Rinout corrected)  = " << wmean(tautau_ee,tautau_mumu,errtautau_ee,errtautau_mumu) ; 
 std::cout << " +/- " << wmeanerr(tautau_ee,tautau_mumu,errtautau_ee,errtautau_mumu) ;
 std::cout << " ---> " << 1.+wmeanerr(tautau_ee,tautau_mumu,errtautau_ee,errtautau_mumu)/wmean(tautau_ee,tautau_mumu,errtautau_ee,errtautau_mumu);
 std::cout << std::endl;
 std::cout << " ******************** " << std::endl;
 
 tautau_ee = (Reeinout) * ( tautau_ee_ee + tautau_emu_ee + tautau_mue_ee + tautau_mumu_ee);
 errtautau_ee = (Reeinout) * sqrt(errtautau_ee_ee*errtautau_ee_ee + errtautau_emu_ee*errtautau_emu_ee + errtautau_mue_ee*errtautau_mue_ee + errtautau_mumu_ee*errtautau_mumu_ee);
 tautau_mumu = (Rmumuinout) * ( tautau_ee_mumu + tautau_emu_mumu + tautau_mue_mumu + tautau_mumu_mumu);
 errtautau_mumu =  (Rmumuinout) * sqrt(errtautau_ee_mumu*errtautau_ee_mumu + errtautau_emu_mumu*errtautau_emu_mumu + errtautau_mue_mumu*errtautau_mue_mumu + errtautau_mumu_mumu*errtautau_mumu_mumu);
 std::cout << " tautau (Only A region :: Rinout corrected)  = " << wmean(tautau_ee,tautau_mumu,errtautau_ee,errtautau_mumu) ; 
 std::cout << " +/- " << wmeanerr(tautau_ee,tautau_mumu,errtautau_ee,errtautau_mumu) ;
 std::cout << " ---> " << 1.+wmeanerr(tautau_ee,tautau_mumu,errtautau_ee,errtautau_mumu)/wmean(tautau_ee,tautau_mumu,errtautau_ee,errtautau_mumu);
 std::cout << std::endl;
 std::cout << " ******************** " << std::endl;
 
 std::cout << " met sameflav threshold = " << mpmet_threshold_sameFlav_min + DeltaMpmet * WP << std::endl;
 std::cout << " met diffflav threshold = " << mpmet_threshold_diffFlav << std::endl;
 std::cout << " ******************** " << std::endl;
 
 
 
}


