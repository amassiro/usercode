/*
qqHWWlnulnuUtils
*/

#include "qqHWWlnulnuUtils.h"


///==== Pull Plot: drawing utility ====
void PullPlot(TCanvas* canvas, TH1* hDATA, TH1* hMC){
 canvas->Divide(1,2);
 int nbin = hDATA->GetNbinsX();
 double max = hDATA->GetXaxis()->GetXmax();
 double min = hDATA->GetXaxis()->GetXmin();
 std::string name1 = hDATA->GetName();
 std::string name2 = hMC->GetName();

 std::string nameNew = name1 + name2;

 TH1F* hPool = new TH1F (nameNew.c_str(),nameNew.c_str(),nbin,min,max);
 for (int iBin = 0; iBin<nbin; iBin++){
  double A = hDATA->GetBinContent(iBin);
  double B = hMC->GetBinContent(iBin);
  if (A+B != 0) {
   hPool->SetBinContent(iBin,(A-B)/(A+B)*2.);
   hPool->SetBinError(iBin,4. * B / (A+B) / (A+B) * sqrt(A));
  }
 }
 
 double maxY_DATA = hDATA->GetMaximum();
 double maxY_MC = hMC->GetMaximum();

 double minY_DATA = hDATA->GetMinimum();
 double minY_MC = hMC->GetMinimum();
 
 canvas->cd(1); 
 if (maxY_MC > maxY_DATA) {
  hMC->Draw();
  hDATA->Draw("EsameP");
 }
 else {
  hDATA->Draw("EP");
  hMC->Draw("same");  
 }
 hDATA->GetYaxis()->SetRangeUser(std::min(minY_MC,minY_DATA),std::max(maxY_MC,maxY_DATA) * 1.1);
 hMC  ->GetYaxis()->SetRangeUser(std::min(minY_MC,minY_DATA),std::max(maxY_MC,maxY_DATA) * 1.1);
 
 gPad->SetGrid();
  
 canvas->cd(2); 
 hPool->SetLineColor(kRed);
 hPool->SetLineWidth(2);
 hPool->SetMarkerColor(kRed);
 hPool->SetMarkerStyle(20);
 hPool->SetMarkerSize(1);
 hPool->Draw("EP");
 hPool->GetXaxis()->SetTitle(hMC->GetXaxis()->GetTitle()); 
 hPool->GetYaxis()->SetTitle("2(DATA-MC)/(DATA+MC)"); 
 hPool->Draw("EP");
 gPad->SetGrid();
}


void PullPlot(TCanvas* canvas, TH1* hDATA, THStack* hsMC){
  canvas->Divide(1,2);
  int nbin = hDATA->GetNbinsX();
  double max = hDATA->GetXaxis()->GetXmax();
  double min = hDATA->GetXaxis()->GetXmin();
  std::string name1 = hDATA->GetName();
  std::string name2 = hsMC->GetName();
  
  std::string nameNew = name1 + name2;
  
  TH1F* hPool = new TH1F (nameNew.c_str(),nameNew.c_str(),nbin,min,max);
  for (int iBin = 0; iBin<nbin; iBin++){
    double A = hDATA->GetBinContent(iBin);
    double B = ((TH1*)(hsMC->GetStack()->Last()))->GetBinContent(iBin);
    if (A+B != 0) {
      hPool->SetBinContent(iBin,(A-B)/(A+B)*2.);
      hPool->SetBinError(iBin,4. * B / (A+B) / (A+B) * sqrt(A));
    }
  }
  
  double maxY_DATA = hDATA->GetMaximum();
  double maxY_MC = ((TH1*)(hsMC->GetStack()->Last()))->GetMaximum();
  
  double minY_DATA = hDATA->GetMinimum();
  double minY_MC = ((TH1*)(hsMC->GetStack()->Last()))->GetMinimum();
  
  canvas->cd(1); 
  hDATA->Draw("EP");
  DrawStack(hsMC);
  hDATA->Draw("EsameP");
  gPad->SetGrid();
  
  canvas->cd(2); 
  hPool->SetLineColor(kRed);
  hPool->SetLineWidth(2);
  hPool->SetMarkerColor(kRed);
  hPool->SetMarkerStyle(20);
  hPool->SetMarkerSize(1);
  hPool->Draw("EP");
  hPool->GetXaxis()->SetTitle(hDATA->GetXaxis()->GetTitle()); 
  hPool->GetYaxis()->SetTitle("2(DATA-MC)/(DATA+MC)"); 
  hPool->Draw("EP");
  gPad->SetGrid();
}

///==== Draw Stack ====
void DrawStack(THStack* hs){ 
  TObjArray* histos = hs->GetStack () ;
  Int_t number = histos->GetEntries();
  TH1F* last = (TH1F*) histos->At (number-1) ;
  last->Draw () ;
  for (int i = number-2 ; i >=0 ; --i) 
  {
    TH1F * histo = (TH1F*) histos->At (i) ;
    Style_t origStyle = histo->GetFillStyle ();
    Color_t origColor = histo->GetFillColor ();
    TH1F* dummy = (TH1F*) histo->Clone () ;
    dummy->SetFillStyle (1001) ; 
    dummy->SetFillColor (10) ;        
    dummy->Draw ("same") ;
    histo->Draw ("same") ;
  }
}



///==== MC Decay Channel of VV ====
std::pair<int,int> GetMCDecayChannel(const std::vector<float>& pdgId){
 
 std::pair<int,int> result;
 result.first  = -1;
 result.second = -1;
 
 if (pdgId.size() == 4){
  ///=================   Vf
  ///== pdgId.at(0) ==> f11 
  ///== pdgId.at(1) ==> f12 (V = 1 & f = 2)
  ///== pdgId.at(2) ==> f21
  ///== pdgId.at(3) ==> f22
  
  int f11 = fabs(pdgId.at(0));
  int f12 = fabs(pdgId.at(1));
  int f21 = fabs(pdgId.at(2));
  int f22 = fabs(pdgId.at(3));
  
  
  ///==== lepton - lepton ====
  if (f11 >= 11 && f11 <= 16 && f21 >= 11 && f21 <= 16) {
   result.first  = 1;
   ///==== emu - emu ====
   if (f11 >= 11 && f11 <= 14 && f21 >= 11 && f21 <= 14) {
    result.second  = 1;
   }
   ///==== emu - tau ====
   if (f11 >= 11 && f11 <= 14 && f21 >=15 && f21 <= 16) {
    result.second  = 2;
   }
   ///==== tau - emu ====
   if (f21 >= 11 && f21 <= 14 && f11 >= 15 && f11 <= 16) {
    result.second  = 3;    
   }
   ///==== tau - tau ====
   if (f21 >= 15 && f21 <= 16 && f11 >= 15 && f11 <= 16) {
    result.second  = 4;
   }
  }
  
  ///==== lepton - quark ====
  if ((f11 >= 11 && f11 <= 16 && f21 >= 1 && f21 <= 4) || (f21 >= 11 && f21 <= 16 && f11 >= 1 && f11 <= 4)) {
   result.first  = 2;
   ///==== emu - quark ====
   if (f11 >= 11 && f11 <= 14 && f21 >= 1 && f21 <= 4){
    result.second  = 1;
   }
   ///==== quark - emu ====
   if (f21 >= 11 && f21 <= 14 && f11 >= 1 && f11 <= 4) {
    result.second  = 2;
   }
   ///==== tau - quark ====
   if (f21 >= 1 && f21 <= 4 && f11 >= 15 && f11 <= 16){
    result.second  = 3;
   }
   ///==== quark -tau ====
   if (f11 >= 1 && f11 <= 4 && f21 >=15 && f21 <= 16) {
    result.second  = 4;
   }   
  }
  
  ///==== quark - quark ====
  if (f11 >= 1 && f11 <= 4 && f21 >= 1 && f21 <= 4) {
   result.first  = 3;
   result.second  = -1;   
  }
 }
 
 return result;
}




std::pair<int,int> GetMCDecayChannel(float pdgId11,float pdgId12, float pdgId21, float pdgId22){
 std::vector<float> vectPdgId;
 vectPdgId.push_back(pdgId11);
 vectPdgId.push_back(pdgId12);
 vectPdgId.push_back(pdgId21);
 vectPdgId.push_back(pdgId22);
 return GetMCDecayChannel(vectPdgId);
}










///==== get GoodCombination MVA ====

std::pair<double,int> GetCombinationMVA(treeReader& reader, std::vector<std::vector<int> >& combinations,TMVA::Reader* TMVAreader, TString& methodName, Float_t* input_variables, std::vector<int>* whitelistJet){
 
 Float_t pT_RECO_q1;
 Float_t pT_RECO_q2;
 Float_t pT_RECO_b1;
 Float_t pT_RECO_b2;
 
 Float_t DR_RECO_qq;
 Float_t DR_RECO_qb;
 Float_t DR_RECO_bb;
 
 Float_t jets_trackCountingHighEffBJetTags_RECO_q1;
 Float_t jets_trackCountingHighEffBJetTags_RECO_b1;
 Float_t jets_trackCountingHighPurBJetTags_RECO_q1;
 Float_t jets_trackCountingHighPurBJetTags_RECO_b1;
 Float_t jets_simpleSecondaryVertexBJetTags_RECO_q1;
 Float_t jets_simpleSecondaryVertexBJetTags_RECO_b1;
 Float_t jets_combinedSecondaryVertexBJetTags_RECO_q1;
 Float_t jets_combinedSecondaryVertexBJetTags_RECO_b1;
 Float_t jets_combinedSecondaryVertexMVABJetTags_RECO_q1;
 Float_t jets_combinedSecondaryVertexMVABJetTags_RECO_b1;
 
 Float_t jets_trackCountingHighEffBJetTags_RECO_q2;
 Float_t jets_trackCountingHighEffBJetTags_RECO_b2;
 Float_t jets_trackCountingHighPurBJetTags_RECO_q2;
 Float_t jets_trackCountingHighPurBJetTags_RECO_b2;
 Float_t jets_simpleSecondaryVertexBJetTags_RECO_q2;
 Float_t jets_simpleSecondaryVertexBJetTags_RECO_b2;
 Float_t jets_combinedSecondaryVertexBJetTags_RECO_q2;
 Float_t jets_combinedSecondaryVertexBJetTags_RECO_b2;
 Float_t jets_combinedSecondaryVertexMVABJetTags_RECO_q2;
 Float_t jets_combinedSecondaryVertexMVABJetTags_RECO_b2; 
 
 
//  std::vector<ROOT::Math::XYZTVector>* muons = reader.Get4V("muons");
//  std::vector<ROOT::Math::XYZTVector>* electrons = reader.Get4V("electrons");
 
 std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
 std::vector<float>* jets_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags");
 std::vector<float>* jets_trackCountingHighEffBJetTagsDR = reader.GetFloat("jets_trackCountingHighEffBJetTagsDR");
 std::vector<float>* jets_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags");
 std::vector<float>* jets_simpleSecondaryVertexBJetTags = reader.GetFloat("jets_simpleSecondaryVertexBJetTags");
 std::vector<float>* jets_combinedSecondaryVertexBJetTags = reader.GetFloat("jets_combinedSecondaryVertexBJetTags");
 std::vector<float>* jets_combinedSecondaryVertexMVABJetTags = reader.GetFloat("jets_combinedSecondaryVertexMVABJetTags");
 
 double TMVA_value = -100000000;
 int MVACombination = -1;
 
 int nComb = combinations.size();
 
 for (int iComb = 0; iComb<nComb; iComb++){
  int q1 = combinations.at(iComb).at(0);
  int q2 = combinations.at(iComb).at(1);
  int b1 = combinations.at(iComb).at(2);
  int b2 = combinations.at(iComb).at(3);    
  
  if(whitelistJet != NULL)
   if( (whitelistJet -> at(q1)) != 1 || (whitelistJet -> at(q2)) != 1 || (whitelistJet -> at(b1)) != 1 || (whitelistJet -> at(b2)) != 1)
    continue;
     
  pT_RECO_q1 = jets->at(q1).Pt();
  pT_RECO_q2 = jets->at(q2).Pt();
  pT_RECO_b1 = jets->at(b1).Pt();
  pT_RECO_b2 = jets->at(b2).Pt();
  DR_RECO_qq = ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(q2));
  DR_RECO_bb = ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(b2));
  DR_RECO_qb = std::min(ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(b2)),ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(q2)));
  
  if (jets->at(q1).Pt() > jets->at(q2).Pt()) {
   jets_trackCountingHighEffBJetTags_RECO_q1 = jets_trackCountingHighEffBJetTags->at(q1);
   jets_trackCountingHighEffBJetTags_RECO_q2 = jets_trackCountingHighEffBJetTags->at(q2);  
   jets_trackCountingHighPurBJetTags_RECO_q1 = jets_trackCountingHighPurBJetTags->at(q1);
   jets_trackCountingHighPurBJetTags_RECO_q2 = jets_trackCountingHighPurBJetTags->at(q2);
   jets_simpleSecondaryVertexBJetTags_RECO_q1 = jets_simpleSecondaryVertexBJetTags->at(q1);
   jets_simpleSecondaryVertexBJetTags_RECO_q2 = jets_simpleSecondaryVertexBJetTags->at(q2);
   jets_combinedSecondaryVertexBJetTags_RECO_q1 = jets_combinedSecondaryVertexBJetTags->at(q1);
   jets_combinedSecondaryVertexBJetTags_RECO_q2 = jets_combinedSecondaryVertexBJetTags->at(q2);
   jets_combinedSecondaryVertexMVABJetTags_RECO_q1 = jets_combinedSecondaryVertexMVABJetTags->at(q1);
   jets_combinedSecondaryVertexMVABJetTags_RECO_q2 = jets_combinedSecondaryVertexMVABJetTags->at(q2);
  }
  else  {
   jets_trackCountingHighEffBJetTags_RECO_q1 = jets_trackCountingHighEffBJetTags->at(q2);
   jets_trackCountingHighEffBJetTags_RECO_q2 = jets_trackCountingHighEffBJetTags->at(q1);  
   jets_trackCountingHighPurBJetTags_RECO_q1 = jets_trackCountingHighPurBJetTags->at(q2);
   jets_trackCountingHighPurBJetTags_RECO_q2 = jets_trackCountingHighPurBJetTags->at(q1);
   jets_simpleSecondaryVertexBJetTags_RECO_q1 = jets_simpleSecondaryVertexBJetTags->at(q2);
   jets_simpleSecondaryVertexBJetTags_RECO_q2 = jets_simpleSecondaryVertexBJetTags->at(q1);
   jets_combinedSecondaryVertexBJetTags_RECO_q1 = jets_combinedSecondaryVertexBJetTags->at(q2);
   jets_combinedSecondaryVertexBJetTags_RECO_q2 = jets_combinedSecondaryVertexBJetTags->at(q1);
   jets_combinedSecondaryVertexMVABJetTags_RECO_q1 = jets_combinedSecondaryVertexMVABJetTags->at(q2);
   jets_combinedSecondaryVertexMVABJetTags_RECO_q2 = jets_combinedSecondaryVertexMVABJetTags->at(q1);
  }
  
  if (jets->at(b1).Pt() > jets->at(b2).Pt()) {
   jets_trackCountingHighEffBJetTags_RECO_b1 = jets_trackCountingHighEffBJetTags->at(b1);
   jets_trackCountingHighEffBJetTags_RECO_b2 = jets_trackCountingHighEffBJetTags->at(b2);  
   jets_trackCountingHighPurBJetTags_RECO_b1 = jets_trackCountingHighPurBJetTags->at(b1);
   jets_trackCountingHighPurBJetTags_RECO_b2 = jets_trackCountingHighPurBJetTags->at(b2);
   jets_simpleSecondaryVertexBJetTags_RECO_b1 = jets_simpleSecondaryVertexBJetTags->at(b1);
   jets_simpleSecondaryVertexBJetTags_RECO_b2 = jets_simpleSecondaryVertexBJetTags->at(b2);
   jets_combinedSecondaryVertexBJetTags_RECO_b1 = jets_combinedSecondaryVertexBJetTags->at(b1);
   jets_combinedSecondaryVertexBJetTags_RECO_b2 = jets_combinedSecondaryVertexBJetTags->at(b2);
   jets_combinedSecondaryVertexMVABJetTags_RECO_b1 = jets_combinedSecondaryVertexMVABJetTags->at(b1);
   jets_combinedSecondaryVertexMVABJetTags_RECO_b2 = jets_combinedSecondaryVertexMVABJetTags->at(b2);
  }
  else  {
   jets_trackCountingHighEffBJetTags_RECO_b1 = jets_trackCountingHighEffBJetTags->at(b2);
   jets_trackCountingHighEffBJetTags_RECO_b2 = jets_trackCountingHighEffBJetTags->at(b1);  
   jets_trackCountingHighPurBJetTags_RECO_b1 = jets_trackCountingHighPurBJetTags->at(b2);
   jets_trackCountingHighPurBJetTags_RECO_b2 = jets_trackCountingHighPurBJetTags->at(b1);
   jets_simpleSecondaryVertexBJetTags_RECO_b1 = jets_simpleSecondaryVertexBJetTags->at(b2);
   jets_simpleSecondaryVertexBJetTags_RECO_b2 = jets_simpleSecondaryVertexBJetTags->at(b1);
   jets_combinedSecondaryVertexBJetTags_RECO_b1 = jets_combinedSecondaryVertexBJetTags->at(b2);
   jets_combinedSecondaryVertexBJetTags_RECO_b2 = jets_combinedSecondaryVertexBJetTags->at(b1);
   jets_combinedSecondaryVertexMVABJetTags_RECO_b1 = jets_combinedSecondaryVertexMVABJetTags->at(b2);
   jets_combinedSecondaryVertexMVABJetTags_RECO_b2 = jets_combinedSecondaryVertexMVABJetTags->at(b1);
  }
  
  input_variables[0] = pT_RECO_q1;
  input_variables[1] = pT_RECO_q2;
  input_variables[2] = pT_RECO_b1;
  input_variables[3] = pT_RECO_b2;
  input_variables[4] = DR_RECO_qq;
  input_variables[5] = DR_RECO_qb;
  input_variables[6] = DR_RECO_bb;
  input_variables[7] = jets_trackCountingHighEffBJetTags_RECO_q1;
  input_variables[8] = jets_trackCountingHighEffBJetTags_RECO_b1;
  input_variables[9] = jets_trackCountingHighEffBJetTags_RECO_q2;
  input_variables[11] = jets_trackCountingHighEffBJetTags_RECO_b2;
  
  double MVA_temp = TMVAreader->EvaluateMVA(methodName); 
  if (MVA_temp > TMVA_value) {
   TMVA_value = MVA_temp;
   MVACombination = iComb;
  }
 }
 
 
 
 std::pair<double,int> result;
 result.first = TMVA_value;
 result.second = MVACombination;
 
 return result;
}


///==== return the value of the Min Chi2 and the corresponding number in the combinations ====
std::pair<double,int> GetCombinationChi2(treeReader& reader, std::vector<std::vector<int> >& combinations,std::vector<int>* whitelistJet,const ROOT::Math::XYZTVector& lepton, const ROOT::Math::XYZTVector& MET){
 
 double Chi2 = -1;
 double Chi2Combination = -1;
 
 std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
 std::vector<float>* jets_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags");
 std::vector<float>* jets_trackCountingHighEffBJetTagsDR = reader.GetFloat("jets_trackCountingHighEffBJetTagsDR");
 std::vector<float>* jets_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags");
 std::vector<float>* jets_simpleSecondaryVertexBJetTags = reader.GetFloat("jets_simpleSecondaryVertexBJetTags");
 std::vector<float>* jets_combinedSecondaryVertexBJetTags = reader.GetFloat("jets_combinedSecondaryVertexBJetTags");
 std::vector<float>* jets_combinedSecondaryVertexMVABJetTags = reader.GetFloat("jets_combinedSecondaryVertexMVABJetTags");
 
 
 int nComb = combinations.size();
 
 for (int iComb = 0; iComb<nComb; iComb++){
  int q1 = combinations.at(iComb).at(0);
  int q2 = combinations.at(iComb).at(1);
  int b1 = combinations.at(iComb).at(2); //---> in this analysis this is the bjet that couple with qq
  int b2 = combinations.at(iComb).at(3);    
  
  if(whitelistJet != NULL)
   if( (whitelistJet -> at(q1)) != 1 || (whitelistJet -> at(q2)) != 1 || (whitelistJet -> at(b1)) != 1 || (whitelistJet -> at(b2)) != 1)
    continue;
  
  double sigma1 = 1;
  double sigma2 = 1;
  double sigma3 = 1;
  
  double massW = 80.398;
  double massTop = 170; //--------- ??????????????????????????????????????????????????
  ROOT::Math::XYZTVector neutrino; // = GetNeutrino(MET,lepton,massW);
  
  double Chi2_temp = 0;
  Chi2_temp += ((jets->at(q1) + jets->at(q2)).M() - massW) * ((jets->at(q1) + jets->at(q2)).M() - massW)  / sigma1 / sigma1; 
  
  Chi2_temp += ((jets->at(q1) + jets->at(q2) + jets->at(b1)).M() - massTop) * ((jets->at(q1) + jets->at(q2)).M() - massTop)  / sigma1 / sigma1; 
  
  Chi2_temp += ((jets->at(b2) + lepton + neutrino).M() - massTop) * ((jets->at(q1) + jets->at(q2)).M() - massTop)  / sigma1 / sigma1; 
    
  if (Chi2_temp < Chi2 || Chi2 == -1) {
   Chi2 = Chi2_temp;
   Chi2Combination = iComb;
  }
 }
 
 std::pair<double,int> result;
 result.first = Chi2;
 result.second = Chi2Combination;
 return result;
}


///==== get Selected Lepton: electron or muon ====
int SelectLeptonTTBar(std::vector<ROOT::Math::XYZTVector>& leptons,const std::string& method,const double& ptMin,const double& etaMax,int& numLeptons,const std::vector<int>* blacklist){
 //---- initialize variable with result
 int it = -1;
 numLeptons = 0;
 // initialize the selection variable
 double maxPt = -999999.;
 double tempPt = 0.;
 //---- loop over leptons
 for(unsigned int i = 0; i < leptons.size(); ++i){
  if( sqrt(leptons.at(i).Perp2()) < ptMin ) continue;
  if( fabs(leptons.at(i).eta()) > etaMax ) continue;
  bool skipLep = false;
  if(blacklist){
   for(unsigned int kk = 0; kk < blacklist -> size(); ++kk){
    if(blacklist -> at(kk) == static_cast<int>(i)) skipLep = true;
   }
  }
  if(skipLep) continue;
  numLeptons ++; ///---- number of leptons that survive selections ----
  //---- select leptons with different techniques
  if(method == "maxPt")
  {
   tempPt = sqrt(leptons.at(i).perp2());
   if(tempPt > maxPt)
   {
    maxPt = tempPt;
    it = i;
   }
  }
  //-------------------------------------
 }//---- loop over leptons 
 if(method == "maxPt")
  return it;
 else return -1;
}


///==== get Selected Muon ====
int SelectMuonTTBar(std::vector<ROOT::Math::XYZTVector>& leptons,
		    std::vector<float>& tkIso,
		    std::vector<float>& emIso,
		    std::vector<float>& hadIso,
		    const std::string& method,
		    const double& ptMin,
		    const double& etaMax,
		    const double& isoMax,
		    int& numLeptons,
		    const std::vector<int>* blacklist
		    ){
 //---- initialize variable with result
 int it = -1;
 numLeptons = 0;
 // initialize the selection variable
 double maxPt = -999999.;
 double tempPt = 0.;
 //---- loop over leptons
 for(unsigned int i = 0; i < leptons.size(); ++i){
  if( sqrt(leptons.at(i).Perp2()) < ptMin ) continue;
  if( fabs(leptons.at(i).eta()) > etaMax ) continue;
  if( (tkIso.at(i) + emIso.at(i) + hadIso.at(i)) / sqrt(leptons.at(i).Perp2()) > isoMax ) continue; 
//   if( mud0.at(i) > d0Max ) continue; 
  bool skipLep = false;
  if(blacklist){
   for(unsigned int kk = 0; kk < blacklist -> size(); ++kk){
    if(blacklist -> at(kk) == static_cast<int>(i)) skipLep = true;
   }
  }
  if(skipLep) continue;
  numLeptons ++; ///---- number of leptons that survive selections ----
  //---- select leptons with different techniques
  if(method == "maxPt")
  {
   tempPt = sqrt(leptons.at(i).perp2());
   if(tempPt > maxPt)
   {
    maxPt = tempPt;
    it = i;
   }
  }
  //-------------------------------------
 }//---- loop over leptons 
 if(method == "maxPt")
  return it;
 else return -1;
}




///==== get Selected Electron ====
int SelectElectronTTBar(std::vector<ROOT::Math::XYZTVector>& leptons,
		    std::vector<float>& tkIso,
		    std::vector<float>& emIso,
		    std::vector<float>& hadIso,
		    std::vector<float>& eleId,
		    std::vector<float>& eled0,
		    const std::string& method,
		    const double& ptMin,
		    const double& etaMax,
		    const double& isoMax,
		    const double& d0Max,
		    int& numLeptons,
		    const std::vector<int>* blacklist
		    ){
 //---- initialize variable with result
 int it = -1;
 numLeptons = 0;
 // initialize the selection variable
 double maxPt = -999999.;
 double tempPt = 0.;
 //---- loop over leptons
 for(unsigned int i = 0; i < leptons.size(); ++i){
  if( sqrt(leptons.at(i).Perp2()) < ptMin ) continue;
  if( fabs(leptons.at(i).eta()) > etaMax ) continue;
  
  ///---- H-like isolation ----
  if (((tkIso.at(i) + emIso.at(i) + hadIso.at(i)) < 8.) && (sqrt(leptons.at(i).Perp2()) < (10. + 15./8.*(tkIso.at(i) + emIso.at(i) + hadIso.at(i))))) continue;
  if ((tkIso.at(i) + emIso.at(i) + hadIso.at(i)) > 8.) continue;
  
//   if( (tkIso.at(i) + emIso.at(i) + hadIso.at(i)) / sqrt(leptons.at(i).Perp2()) > isoMax ) continue; 
  
  if( eleId.at(i) == 0 ) continue;
  if( eled0.at(i) > d0Max ) continue; 
  bool skipLep = false;
  if(blacklist){
   for(unsigned int kk = 0; kk < blacklist -> size(); ++kk){
    if(blacklist -> at(kk) == static_cast<int>(i)) skipLep = true;
   }
  }
  if(skipLep) continue;
  numLeptons ++; ///---- number of leptons that survive selections ----
  //---- select leptons with different techniques
  if(method == "maxPt")
  {
   tempPt = sqrt(leptons.at(i).perp2());
   if(tempPt > maxPt)
   {
    maxPt = tempPt;
    it = i;
   }
  }
  //-------------------------------------
 }//---- loop over leptons 
 if(method == "maxPt")
  return it;
 else return -1;
}



///==== get num Jets ====
int getNumJets(const std::vector<int>& whitelist){
 int result = 0;
 for (int i=0; i<whitelist.size(); i++) {
  result += whitelist.at(i);
 }
 return result;
}



///==== CopyTree ====
void CopyTree(){
  
}








///==== get Jet Energy Correction ====
double getJEC(const ROOT::Math::XYZTVector& Jet){
 double pT = Jet.Pt();
 double result = exp(-3.32898e-01  -2.34368e-02 * pT) + 7.40976e-01;
//  expo(3) is a substitute for exp([3]+[4]*x)
 return result;
}














///=================================== VBF =======================================

///==== get best Combination Jet ID with MVA ====

std::pair<double,int> GetCombination_Jets_ID_MVA(std::vector<ROOT::Math::XYZTVector> &jets, std::vector<std::vector<int> >& combinations,TMVA::Reader* TMVAreader, TString& methodName, Float_t* input_variables, std::vector<int>* whitelistJet){
 
 Float_t pT_RECO_q1;
 Float_t pT_RECO_q2;
 Float_t eta_RECO_q1;
 Float_t eta_RECO_q2;
 Float_t eta_RECO_q1_eta_RECO_q2;
 Float_t Deta_RECO_q12;
 Float_t Mjj;
 
//  std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
  
 double TMVA_value = -100000000;
 int MVACombination = -1;
 
 int nComb = combinations.size();
 
 for (int iComb = 0; iComb<nComb; iComb++){
  int q1 = combinations.at(iComb).at(0);
  int q2 = combinations.at(iComb).at(1);
  
  if(whitelistJet != NULL)
   if((whitelistJet -> at(q1)) != 1 || (whitelistJet -> at(q2)) != 1) continue;
   
   if (jets.at(q1).Pt() < jets.at(q2).Pt()) {
    int tempq = q1;
    q1 = q2;
    q2 = tempq;
   }
   
   pT_RECO_q1 = jets.at(q1).Pt();
  pT_RECO_q2 = jets.at(q2).Pt();
  
  eta_RECO_q1 = jets.at(q1).Eta();
  eta_RECO_q2 = jets.at(q2).Eta();
  
  eta_RECO_q1_eta_RECO_q2 = eta_RECO_q1 * eta_RECO_q2;
  Deta_RECO_q12 = fabs(eta_RECO_q1-eta_RECO_q2);
  
  Mjj = (jets.at(q1) + jets.at(q2)).M();
  
  
  input_variables[0] = pT_RECO_q1;
  input_variables[1] = pT_RECO_q2;
  input_variables[2] = eta_RECO_q1;
  input_variables[3] = eta_RECO_q2;
  input_variables[4] = eta_RECO_q1_eta_RECO_q2;
  input_variables[5] = Deta_RECO_q12;
  input_variables[6] = Mjj;
  
  double MVA_temp = TMVAreader->EvaluateMVA(methodName); 
  if (MVA_temp > TMVA_value) {
   TMVA_value = MVA_temp;
   MVACombination = iComb;
  }
 }
 
 std::pair<double,int> result;
 result.first = TMVA_value;
 result.second = MVACombination;
 
 return result;
}
