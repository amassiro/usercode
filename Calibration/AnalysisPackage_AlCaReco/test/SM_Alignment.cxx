{
 double R = 1.290;
 
//  TF1* BarrelDEta = new TF1("BarrelDEta","-1./R*(cos(THETA)*[0]-sin(THETA)*[1])");
 
 TString genCut = Form("(eleFBrem<0.8 && eleCharge>0)");
 
 int NBIN_ETA = 30;
//  double MINETA = 0.00;
 double MINETA = -1.50;
 double MAXETA =  1.50;

 double MINPHI = -3.14159265;
 double MAXPHI =  3.14159265;
 
 int NBIN_PHI = 100;
 int NBIN_DETA = 200;
 int NBIN_DPHI = 200;
 
 double MINDETA = -0.01;
 double MAXDETA = +0.01;

 double MINDPHI = -0.05;
 double MAXDPHI = +0.05;

 TString nameFunctionBarrelDEta = Form("-1./%f*(cos(2*atan(exp(-x)))*[0]-sin(2*atan(exp(-x)))*[1])",R);
 TF1* BarrelDEta = new TF1("BarrelDEta",nameFunctionBarrelDEta,MINETA,MAXETA);
 
 TString nameFunctionBarrelDPhi = Form("-1./%f*(sin(x)*[0]-cos(x)*[1])",R);
 TF1* BarrelDPhi = new TF1("BarrelDPhi",nameFunctionBarrelDPhi,MINPHI,MAXPHI);
 
//  TFile* FileIn = new TFile("output_Ntuple/AlCaReco_Result.root","READ");
//  TFile* FileIn = new TFile("output_Ntuple/AlCaReco_Results_new.root","READ");
//  TFile* FileIn = new TFile("output_Ntuple/AlCaReco_Results_new_NoMETCut.root","READ");
 TFile* FileIn = new TFile("output_Ntuple/AlCaReco_Results_iSM_iSC.root","READ");
 
 TTree* myTree = (TTree*) FileIn->Get("myTree");
 
 TCanvas* cSummed = new TCanvas ("cSummed","cSummed",400,800);
 cSummed->Divide(1,2);
 
 cSummed->cd(1);
 TH2F* DEtaVsPhi_Plus = new TH2F("DEtaVsPhi_Plus","DEtaVsPhi_Plus",NBIN_PHI,-3.14159265-3.14159265/18.,3.14159265-3.14159265/18.,NBIN_DETA,MINDETA,MAXDETA);
 TString genCut_EBPlus = Form("%s && etaSC>0 && abs(etaSC)<1.5",genCut.Data());
 myTree->Draw("DeltaEtaIn:(phiSC)>>DEtaVsPhi_Plus",genCut_EBPlus,"colz");
 DEtaVsPhi_Plus->Draw("colz");
 TProfile * profile_Plus = DEtaVsPhi_Plus->ProfileX ("_Plus") ;
 profile_Plus->SetMarkerColor(kRed);
 profile_Plus->SetLineColor(kRed);
 profile_Plus->SetMarkerStyle(20);
 profile_Plus->SetMarkerSize(1);
 profile_Plus->SetLineWidth(1);
 profile_Plus->Draw("same");
 gPad->SetGrid();

 
 cSummed->cd(2);
 TH2F* DEtaVsPhi_Minus = new TH2F("DEtaVsPhi_Minus","DEtaVsPhi_Minus",NBIN_PHI,-3.14159265-3.14159265/18.,3.14159265-3.14159265/18.,NBIN_DETA,MINDETA,MAXDETA);
 TString genCut_EBMinus = Form("%s && etaSC<0 && abs(etaSC)<1.5",genCut.Data());
 myTree->Draw("DeltaEtaIn:(phiSC)>>DEtaVsPhi_Minus",genCut_EBMinus,"colz");
 DEtaVsPhi_Minus->Draw("colz");
 TProfile * profile_Minus = DEtaVsPhi_Minus->ProfileX ("_Minus") ;
 profile_Minus->SetMarkerColor(kRed);
 profile_Minus->SetLineColor(kRed);
 profile_Minus->SetMarkerStyle(20);
 profile_Minus->SetMarkerSize(1);
 profile_Minus->SetLineWidth(1);
 profile_Minus->Draw("same");
 gPad->SetGrid();
 
 
 ///============================================================
 ///==== Build variables ====
 double Phi_SM_Mean[36];
 double Phi_SM_RMS[36];
 for (int iSM = 0; iSM<36; iSM++){
  if (iSM<18) Phi_SM_Mean[iSM] = (2*3.14159265*(iSM+0.5)/18.-3.14159265/18.);
  else Phi_SM_Mean[iSM] = (2*3.14159265*(iSM-18+0.5)/18.-3.14159265/18.);
  Phi_SM_RMS[iSM] = 2*3.14159265 / 18. / 2.;
 }
 TCanvas* cGr_DPHI_DETA_vs_PHI = new TCanvas ("cGr_DPHI_DETA_vs_PHI","cGr_DPHI_DETA_vs_PHI",800,800);
 cGr_DPHI_DETA_vs_PHI->Divide(2,2);
 
 ///=============================================================
 
 TCanvas* cSM = new TCanvas ("cSM","cSM",1000,400);
 cSM->Divide(18,2);
 
 double numEntries_Mean[36];
 double numEntries_RMS[36];
 double DEta_SM_Mean[36];
 double DEta_SM_RMS[36];
 double phi_Mean[36];
 double phi_RMS[36];

 double DEta_EBPlus_Mean[18];
 double DEta_EBPlus_RMS[18];
 double DEta_EBMinus_Mean[18];
 double DEta_EBMinus_RMS[18];
 
 
 TH1F* DEta[36];
 
 for (int iSM = 0; iSM<36; iSM++){
  if (iSM<18) phi_Mean[iSM] = iSM+1;
  else phi_Mean[iSM] = -(iSM-17);
  phi_RMS[iSM] = 0.0;
  cSM->cd(iSM+1);
  TString name;
  if (iSM<18) name = Form("DEta_SM_%d",iSM+1);
  else name = Form("DEta_SM_-%d",iSM-17);
  DEta[iSM] = new TH1F(name,name,NBIN_DETA,MINDETA,MAXDETA);
  TString draw = Form("DeltaEtaIn>>%s",name.Data());
  TString cut;
  if (iSM<18) {
   if (iSM<9) cut = Form("%s && etaSC>0 && abs(etaSC)<1.5 && phiSC>(3.14159265*%d/9.-3.14159265/18.) && phiSC<(3.14159265*(%d+1)/9.-3.14159265/18.)",genCut.Data(),iSM,iSM);
   else if (iSM == 9) cut = Form("%s && etaSC>0 && abs(etaSC)<1.5 && (phiSC>(3.14159265-3.14159265/18.) || phiSC<(3.14159265/18.-3.14159265))",genCut.Data());
   else cut = Form("%s && etaSC>0 && abs(etaSC)<1.5 && phiSC>(3.14159265*%d/9.-3.14159265/18.-2*3.14159265) && phiSC<(3.14159265*(%d+1)/9.-3.14159265/18.-2*3.14159265)",genCut.Data(),iSM,iSM);
  }
  else {
   if (iSM<27) cut = Form("%s && etaSC<0 && abs(etaSC)<1.5 && phiSC>(3.14159265*%d/9.-3.14159265/18.) && phiSC<(3.14159265*(%d+1)/9.-3.14159265/18.)",genCut.Data(),iSM-18,iSM-18);
   else if (iSM == 27) cut = Form("%s && etaSC<0 && abs(etaSC)<1.5 && (phiSC>(3.14159265-3.14159265/18.) || phiSC<(3.14159265/18.-3.14159265))",genCut.Data());
   else cut = Form("%s && etaSC<0 && abs(etaSC)<1.5 && phiSC>(3.14159265*%d/9.-3.14159265/18.-2*3.14159265) && phiSC<(3.14159265*(%d+1)/9.-3.14159265/18.-2*3.14159265)",genCut.Data(),iSM-18,iSM-18);
  }
  std::cout << " draw:cut = " << draw.Data() << "  :  " << cut.Data() << std::endl;
  myTree->Draw(draw,cut);
  DEta_SM_Mean[iSM] = DEta[iSM]->GetMean();
  DEta_SM_RMS[iSM] = DEta[iSM]->GetRMS() / sqrt(DEta[iSM]->GetEffectiveEntries());
  
  if (iSM<18) DEta_EBPlus_Mean[iSM] = DEta_SM_Mean[iSM];
  else  DEta_EBMinus_Mean[iSM-18] = DEta_SM_Mean[iSM];
  if (iSM<18) DEta_EBPlus_RMS[iSM] = DEta_SM_RMS[iSM];
  else  DEta_EBMinus_RMS[iSM-18] = DEta_SM_RMS[iSM];
  
  numEntries_Mean[iSM] = DEta[iSM]->GetEffectiveEntries();
  numEntries_RMS[iSM] = 0.0;
  DEta[iSM]->SetFillColor(kRed);
  DEta[iSM]->Draw();
 }

 TCanvas* cGr = new TCanvas ("cGr","cGr",800,1200);
 cGr->Divide(1,3);
 
 cGr->cd(1);
 TGraphErrors* grNum = new TGraphErrors(36,phi_Mean,numEntries_Mean,phi_RMS,numEntries_RMS);
 grNum->SetMarkerColor(kBlue);
 grNum->SetLineColor(kBlue);
 grNum->SetMarkerStyle(20);
 grNum->SetMarkerSize(1);
 grNum->SetLineWidth(1);
 grNum->GetXaxis()->SetTitle("SM");
 grNum->GetYaxis()->SetTitle("number of electrons");
 grNum->Draw("AP");
 gPad->SetGrid();
 
 cGr->cd(2);
 TGraphErrors* gr = new TGraphErrors(36,phi_Mean,DEta_SM_Mean,phi_RMS,DEta_SM_RMS);
 gr->SetMarkerColor(kRed);
 gr->SetLineColor(kRed);
 gr->SetMarkerStyle(20);
 gr->SetMarkerSize(1);
 gr->SetLineWidth(1);
 gr->GetXaxis()->SetTitle("SM");
 gr->GetYaxis()->SetTitle("#Delta#eta");
 gr->Draw("AP");
 gPad->SetGrid();
 
 
 
 gPad->Update();
 cGr_DPHI_DETA_vs_PHI->cd(1);
 TGraphErrors* gr_EBPlus_DETA_vs_PHI = new TGraphErrors(18,Phi_SM_Mean,DEta_EBPlus_Mean,Phi_SM_RMS,DEta_EBPlus_RMS);
 gr_EBPlus_DETA_vs_PHI->SetTitle("EB+ #Delta#eta");
 gr_EBPlus_DETA_vs_PHI->SetMarkerColor(kRed);
 gr_EBPlus_DETA_vs_PHI->SetLineColor(kRed);
 gr_EBPlus_DETA_vs_PHI->SetMarkerStyle(20);
 gr_EBPlus_DETA_vs_PHI->SetMarkerSize(1);
 gr_EBPlus_DETA_vs_PHI->SetLineWidth(1);
 gr_EBPlus_DETA_vs_PHI->GetXaxis()->SetTitle("#phi");
 gr_EBPlus_DETA_vs_PHI->GetYaxis()->SetTitle("#Delta#eta");
 gr_EBPlus_DETA_vs_PHI->Draw("AP");
 gPad->SetGrid();

 gPad->Update();
 cGr_DPHI_DETA_vs_PHI->cd(2);
 TGraphErrors* gr_EBMinus_DETA_vs_PHI = new TGraphErrors(18,Phi_SM_Mean,DEta_EBMinus_Mean,Phi_SM_RMS,DEta_EBMinus_RMS);
 gr_EBMinus_DETA_vs_PHI->SetTitle("EB- #Delta#eta");
 gr_EBMinus_DETA_vs_PHI->SetMarkerColor(kRed);
 gr_EBMinus_DETA_vs_PHI->SetLineColor(kRed);
 gr_EBMinus_DETA_vs_PHI->SetMarkerStyle(20);
 gr_EBMinus_DETA_vs_PHI->SetMarkerSize(1);
 gr_EBMinus_DETA_vs_PHI->SetLineWidth(1);
 gr_EBMinus_DETA_vs_PHI->GetXaxis()->SetTitle("#phi");
 gr_EBMinus_DETA_vs_PHI->GetYaxis()->SetTitle("#Delta#eta");
 gr_EBMinus_DETA_vs_PHI->Draw("AP");
 gPad->SetGrid();
 gPad->Update();
 
 ///=============================================================
 
 TCanvas* cSM_eta_contourPlot = new TCanvas ("cSM_eta_contourPlot","cSM_eta_contourPlot",2000,800);
 cSM_eta_contourPlot->Divide(9,4);
 
 TCanvas* cSM_eta = new TCanvas ("cSM_eta","cSM_eta",2000,800);
 cSM_eta->Divide(9,4);
 
 TCanvas* cSM_phi = new TCanvas ("cSM_phi","cSM_phi",2000,800);
 cSM_phi->Divide(9,4);
 
 
 TH2F* DEtaVsEta[36];
 TProfile * profile_DEta[36];
 TGraphErrors* grDEta_vs_eta[36];
 
 TH2F* DPhiVsPhi[36];
 TProfile * profile_DPhi[36];
 TGraphErrors* grDPhi_vs_phi[36];
 
 double DPhi_EBPlus_Mean[36];
 double DPhi_EBPlus_RMS[36];
 double DPhi_EBMinus_Mean[36];
 double DPhi_EBMinus_RMS[36];
 
 double DPhi_SM_Mean[36];
 double DPhi_SM_RMS[36];
 double DR_SM_Mean[36];
 double DR_SM_RMS[36];
 double DZ_SM_Mean[36];
 double DZ_SM_RMS[36];
 double iSM_SM_Mean[36];
 double iSM_SM_RMS[36];
 double DX_SM_Mean[36];
 double DX_SM_RMS[36];
 double DY_SM_Mean[36];
 double DY_SM_RMS[36];
 
 TCanvas* cSM_DPhi = new TCanvas ("cSM_DPhi","cSM_DPhi",200,200);
 cSM_DPhi->Divide(18,2);
 TH1F* DPhi[36];
 
 for (int iSM = 0; iSM<36; iSM++){
  cSM_DPhi->cd(iSM+1);
  TString nameDPhi;
  if (iSM<18) nameDPhi = Form("DPhi_SM_%d",iSM+1);
  else nameDPhi = Form("DPhi_SM_-%d",iSM-17);
  DPhi[iSM] = new TH1F(nameDPhi,nameDPhi,NBIN_DPHI,MINDPHI,MAXDPHI);
  TString drawDPhi = Form("DeltaPhiIn>>%s",nameDPhi.Data());
  TString cut;
  if (iSM<18) {
   if (iSM<9) cut = Form("%s && etaSC>0 && abs(etaSC)<1.5 && phiSC>(3.14159265*%d/9.-3.14159265/18.) && phiSC<(3.14159265*(%d+1)/9.-3.14159265/18.)",genCut.Data(),iSM,iSM);
   else if (iSM == 9) cut = Form("%s && etaSC>0 && abs(etaSC)<1.5 && (phiSC>(3.14159265-3.14159265/18.) || phiSC<(3.14159265/18.-3.14159265))",genCut.Data());
   else cut = Form("%s && etaSC>0 && abs(etaSC)<1.5 && phiSC>(3.14159265*%d/9.-3.14159265/18.-2*3.14159265) && phiSC<(3.14159265*(%d+1)/9.-3.14159265/18.-2*3.14159265)",genCut.Data(),iSM,iSM);
  }
  else {
   if (iSM<27) cut = Form("%s && etaSC<0 && abs(etaSC)<1.5 && phiSC>(3.14159265*%d/9.-3.14159265/18.) && phiSC<(3.14159265*(%d+1)/9.-3.14159265/18.)",genCut.Data(),iSM-18,iSM-18);
   else if (iSM == 27) cut = Form("%s && etaSC<0 && abs(etaSC)<1.5 && (phiSC>(3.14159265-3.14159265/18.) || phiSC<(3.14159265/18.-3.14159265))",genCut.Data());
   else cut = Form("%s && etaSC<0 && abs(etaSC)<1.5 && phiSC>(3.14159265*%d/9.-3.14159265/18.-2*3.14159265) && phiSC<(3.14159265*(%d+1)/9.-3.14159265/18.-2*3.14159265)",genCut.Data(),iSM-18,iSM-18);
  }
  std::cout << " drawDPhi:cut = " << drawDPhi.Data() << "  :  " << cut.Data() << std::endl;
  myTree->Draw(drawDPhi,cut);
  DPhi_SM_Mean[iSM] = DPhi[iSM]->GetMean();
  DPhi_SM_RMS[iSM] = DPhi[iSM]->GetRMS() /  sqrt(DPhi[iSM]->GetEffectiveEntries());
  
  if (iSM<18) DPhi_EBPlus_Mean[iSM] = DPhi_SM_Mean[iSM];
  else  DPhi_EBMinus_Mean[iSM-18] = DPhi_SM_Mean[iSM];
  if (iSM<18) DPhi_EBPlus_RMS[iSM] = DPhi_SM_RMS[iSM];
  else  DPhi_EBMinus_RMS[iSM-18] = DPhi_SM_RMS[iSM];
  
  DPhi[iSM]->SetFillColor(kBlue);
  DPhi[iSM]->Draw();
  
//   Phi_SM_Mean[iSM] = (2*3.14159265*(iSM+0.5)/18.-3.14159265/18.);
  
  
  cSM_eta->cd(iSM+1);
  TString name;
  if (iSM<18) name = Form("DEtaVsEta_SM_%d",iSM+1);
  else name = Form("DEtaVsEta_SM_-%d",iSM-17);
  DEtaVsEta[iSM] = new TH2F(name,name,NBIN_ETA,MINETA,MAXETA,NBIN_DETA,MINDETA,MAXDETA);
//   TString draw = Form("DeltaEtaIn:abs(etaSC)>>%s",name.Data());
  TString draw = Form("DeltaEtaIn:etaSC>>%s",name.Data());
  
  std::cout << " draw:cut = " << draw.Data() << "  :  " << cut.Data() << std::endl;
  myTree->Draw(draw,cut);
  DEtaVsEta[iSM]->Draw("colz");

  TString nameProfile;
  if (iSM<18) nameProfile = Form("Profile_DEtaVsEta_SM_%d",iSM+1);
  else nameProfile = Form("Profile_DEtaVsEta_SM_-%d",iSM-17);
  
  profile_DEta[iSM] = DEtaVsEta[iSM]->ProfileX (nameProfile) ;
  profile_DEta[iSM]->SetMarkerColor(kRed);
  profile_DEta[iSM]->SetLineColor(kRed);
  profile_DEta[iSM]->SetMarkerStyle(20);
  profile_DEta[iSM]->SetMarkerSize(1);
  profile_DEta[iSM]->SetLineWidth(1);
  profile_DEta[iSM]->Draw("same");
  BarrelDEta->SetParameter(0,0);
  BarrelDEta->SetParameter(1,0);
  
  
  cSM_phi->cd(iSM+1);
  TString namePhi;
  if (iSM<18) namePhi = Form("DPhiVsPhi_SM_%d",iSM+1);
  else namePhi = Form("DPhiVsPhi_SM_-%d",iSM-17);
  DPhiVsPhi[iSM] = new TH2F(namePhi,namePhi,NBIN_PHI,MINPHI,MAXPHI,NBIN_DPHI,MINDPHI,MAXDPHI);
  TString drawPhi = Form("DeltaPhiIn:phiSC>>%s",namePhi.Data());
  
  std::cout << " drawPhi:cut = " << drawPhi.Data() << "  :  " << cut.Data() << std::endl;
  myTree->Draw(drawPhi,cut);
  DPhiVsPhi[iSM]->Draw("colz");
  
  TString nameProfilePhi;
  if (iSM<18) nameProfilePhi = Form("Profile_DPhiVsPhi_SM_%d",iSM+1);
  else nameProfilePhi = Form("Profile_DPhiVsPhi_SM_-%d",iSM-17);
  
  profile_DPhi[iSM] = DPhiVsPhi[iSM]->ProfileX (nameProfilePhi) ;
  profile_DPhi[iSM]->SetMarkerColor(kRed);
  profile_DPhi[iSM]->SetLineColor(kRed);
  profile_DPhi[iSM]->SetMarkerStyle(20);
  profile_DPhi[iSM]->SetMarkerSize(1);
  profile_DPhi[iSM]->SetLineWidth(1);
  profile_DPhi[iSM]->Draw("same");
  
  
//   profile_DEta[iSM]->Fit("BarrelDEta");
  
  
  
  ///==== unbinned fit DEta ====
  myTree->SetEntryList(0); 
  myTree->Draw(">> mylist",cut,"entrylist");
  TEntryList *mylist = (TEntryList*)gDirectory->Get("mylist");
  myTree->SetEntryList(mylist);
//   draw = Form(">>%s",name.Data());
//   myTree->Draw("DeltaEtaIn:abs(etaSC):E5x5",cut,"goff");
  myTree->Draw("DeltaEtaIn:etaSC:E5x5",cut,"goff");
  Double_t *vDEta = myTree->GetV1();
  Double_t *vEta = myTree->GetV2();
  Double_t *vEnergy = myTree->GetV3();
  
  Double_t *vErrEta = new Double_t[mylist->GetN()];
  Double_t *vErrDEta = new Double_t[mylist->GetN()];
  
  for (int iEvt = 0; iEvt< mylist->GetN(); iEvt++){
//    std::cout << " vEnergy[" << iEvt << "] = " << vEnergy[iEvt] <<  " vEta[" << iEvt << "] = " << vEta[iEvt] <<  " vDEta[" << iEvt << "] = " << vDEta[iEvt] << " : " << mylist->GetN() << std::endl;
   vErrEta[iEvt] = 0.0;
   vErrDEta[iEvt] = (sqrt(3.6 / sqrt(vEnergy[iEvt]) * 3.6 / sqrt(vEnergy[iEvt]) + 12. / vEnergy[iEvt] * 12. / vEnergy[iEvt] + 0.54*0.54)) / 1000.; ///===> /1000 perchè è in "mm" -> "m"
  }
  grDEta_vs_eta[iSM] = new TGraphErrors(mylist->GetN(),vEta,vDEta,vErrEta,vErrDEta);
  grDEta_vs_eta[iSM] -> Fit("BarrelDEta","QM","",MINETA,MAXETA);
  grDEta_vs_eta[iSM]->SetMarkerColor(kGreen);
  grDEta_vs_eta[iSM]->SetMarkerSize(1);
  grDEta_vs_eta[iSM]->SetMarkerStyle(20);
  grDEta_vs_eta[iSM]->SetLineColor(kGreen);
  myTree->SetEntryList(0); 
  ///==== end unbinned fit DEta ====
  
  cSM_eta->cd(iSM+1);
  gPad->Update();
  DEtaVsEta[iSM]->Draw("colz");
  profile_DEta[iSM]->Draw("same");
  BarrelDEta->DrawClone("same");
    
//   myTree->UnbinnedFit("BarrelDEta","DeltaPhiIn",cut.Data());
   
  std::cout << " iSM = " << iSM << " DR = " << BarrelDEta->GetParameter(0) << " +/- " << BarrelDEta->GetParError(0) << std::endl;
  std::cout << " iSM = " << iSM << " DZ = " << BarrelDEta->GetParameter(1) << " +/- " << BarrelDEta->GetParError(1) << std::endl;
  std::cout << " ===================================================== " << std::endl;
  
  
  gPad->SetGrid();
  gPad->Update();
  
    cSM_eta_contourPlot->cd(iSM+1);
    gPad->Update();
    gMinuit->SetErrorDef(2);
    TGraph *gr2 = (TGraph*)gMinuit->Contour(80,0,1);
    gr2->SetFillColor(42);
    gr2->DrawClone("alf");
    gMinuit->SetErrorDef(1);
    TGraph *gr1 = (TGraph*)gMinuit->Contour(80,0,1);
    gr1->SetFillColor(38);
    gr1->DrawClone("lf");
    gPad->SetGrid();
  
  
  ///==== unbinned fit DPhi ====
  BarrelDPhi->SetParameter(0,0);
  BarrelDPhi->SetParameter(1,0);
  myTree->SetEntryList(0); 
  myTree->Draw(">> mylist",cut,"entrylist");
  TEntryList *mylist = (TEntryList*)gDirectory->Get("mylist");
  myTree->SetEntryList(mylist);
  myTree->Draw("DeltaPhiIn:phiSC:E5x5",cut,"goff");
  Double_t *vDPhi = myTree->GetV1();
  Double_t *vPhi = myTree->GetV2();
  Double_t *vEnergyPhi = myTree->GetV3();
  
  Double_t *vErrPhi = new Double_t[mylist->GetN()];
  Double_t *vErrDPhi = new Double_t[mylist->GetN()];
  
  for (int iEvt = 0; iEvt< mylist->GetN(); iEvt++){
   vErrPhi[iEvt] = 0.0;
   vErrDPhi[iEvt] = (sqrt(3.6 / sqrt(vEnergyPhi[iEvt]) * 3.6 / sqrt(vEnergyPhi[iEvt]) + 12. / vEnergyPhi[iEvt] * 12. / vEnergyPhi[iEvt] + 0.54*0.54)) / 1000.; ///===> /1000 perchè è in "mm" -> "m"
  }
  grDPhi_vs_phi[iSM] = new TGraphErrors(mylist->GetN(),vPhi,vDPhi,vErrPhi,vErrDPhi);
  grDPhi_vs_phi[iSM] -> Fit("BarrelDPhi","QM","",MINPHI,MAXPHI);
  grDPhi_vs_phi[iSM]->SetMarkerColor(kGreen);
  grDPhi_vs_phi[iSM]->SetMarkerSize(1);
  grDPhi_vs_phi[iSM]->SetMarkerStyle(20);
  grDPhi_vs_phi[iSM]->SetLineColor(kGreen);
  myTree->SetEntryList(0); 
  ///==== end unbinned fit DPhi ====
  
  cSM_phi->cd(iSM+1);
  gPad->Update();
  DPhiVsPhi[iSM]->Draw("colz");
  profile_DPhi[iSM]->Draw("same");
  BarrelDPhi->DrawClone("same");
  
  std::cout << " iSM = " << iSM << " DX = " << BarrelDPhi->GetParameter(0) << " +/- " << BarrelDPhi->GetParError(0) << std::endl;
  std::cout << " iSM = " << iSM << " DY = " << BarrelDPhi->GetParameter(1) << " +/- " << BarrelDPhi->GetParError(1) << std::endl;
  std::cout << " ===================================================== " << std::endl;
  
  
  
  if (iSM<18) iSM_SM_Mean[iSM] = iSM+1;
  else iSM_SM_Mean[iSM] = -(iSM-17);
  iSM_SM_RMS[iSM] = 0;
  DR_SM_Mean[iSM] = BarrelDEta->GetParameter(0);
  DR_SM_RMS[iSM] = BarrelDEta->GetParError(0);
  if (iSM<18) DZ_SM_Mean[iSM] = BarrelDEta->GetParameter(1);
  else DZ_SM_Mean[iSM] = BarrelDEta->GetParameter(1);
  DZ_SM_RMS[iSM] = BarrelDEta->GetParError(1);

  
  DX_SM_Mean[iSM] = (cos(Phi_SM_Mean[iSM]) * DR_SM_Mean[iSM] - R * sin(Phi_SM_Mean[iSM]) * DPhi_SM_Mean[iSM]);
  DX_SM_RMS[iSM] = sqrt(cos(Phi_SM_Mean[iSM]) * DR_SM_Mean[iSM] * cos(Phi_SM_Mean[iSM]) * DR_SM_Mean[iSM] + R * sin(Phi_SM_Mean[iSM]) * DPhi_SM_Mean[iSM] * R * sin(Phi_SM_Mean[iSM]) * DPhi_SM_Mean[iSM]);
  DY_SM_Mean[iSM] = (sin(Phi_SM_Mean[iSM]) * DR_SM_Mean[iSM] + R * cos(Phi_SM_Mean[iSM]) * DPhi_SM_Mean[iSM]);
  DY_SM_RMS[iSM] = sqrt(sin(Phi_SM_Mean[iSM]) * DR_SM_Mean[iSM] * sin(Phi_SM_Mean[iSM]) * DR_SM_Mean[iSM] + R * cos(Phi_SM_Mean[iSM]) * DPhi_SM_Mean[iSM] * R * cos(Phi_SM_Mean[iSM]) * DPhi_SM_Mean[iSM]);

  
  std::cout << " iSM = " << iSM << " DX = " << BarrelDPhi->GetParameter(0) << " +/- " << BarrelDPhi->GetParError(0) << " ==== " << DX_SM_Mean[iSM] << " +/- " << DX_SM_RMS[iSM] << std::endl;
  std::cout << " iSM = " << iSM << " DY = " << BarrelDPhi->GetParameter(1) << " +/- " << BarrelDPhi->GetParError(1) << " ==== " << DY_SM_Mean[iSM] << " +/- " << DY_SM_RMS[iSM] << std::endl;  std::cout << " ===================================================== " << std::endl;
  
  
//   DX_SM_Mean[iSM] = BarrelDPhi->GetParameter(0);
//   DX_SM_RMS[iSM] = BarrelDPhi->GetParError(0);
//   DY_SM_Mean[iSM] = BarrelDPhi->GetParameter(1);
//   DY_SM_RMS[iSM] = BarrelDPhi->GetParError(1);
  
//   DX_SM_Mean[iSM] = (DX_SM_Mean[iSM]/DX_SM_RMS[iSM]/DX_SM_RMS[iSM] + BarrelDPhi->GetParameter(0) / BarrelDPhi->GetParError(0) / BarrelDPhi->GetParError(0))/(1./DX_SM_RMS[iSM]/DX_SM_RMS[iSM] + 1. / BarrelDPhi->GetParError(0) / BarrelDPhi->GetParError(0)); 
//   DX_SM_RMS[iSM] = 1./sqrt(1./DX_SM_RMS[iSM]/DX_SM_RMS[iSM] + 1. / BarrelDPhi->GetParError(0) / BarrelDPhi->GetParError(0));
  
//   DY_SM_Mean[iSM] = (DY_SM_Mean[iSM]/DY_SM_RMS[iSM]/DY_SM_RMS[iSM] + BarrelDPhi->GetParameter(1) / BarrelDPhi->GetParError(1) / BarrelDPhi->GetParError(1))/(1./DY_SM_RMS[iSM]/DY_SM_RMS[iSM] + 1. / BarrelDPhi->GetParError(1) / BarrelDPhi->GetParError(1));
//   DY_SM_RMS[iSM] = 1./sqrt(1./DY_SM_RMS[iSM]/DY_SM_RMS[iSM] + 1. / BarrelDPhi->GetParError(1) / BarrelDPhi->GetParError(1));
  

//   grDEta_vs_eta[iSM]->Draw("Psame");
  gPad->SetGrid();
  gPad->Update();
  
//   cSM_eta_contourPlot->cd(iSM+1);
//   gPad->Update();
//   gMinuit->SetErrorDef(2);
//   TGraph *gr2 = (TGraph*)gMinuit->Contour(80,0,1);
//   gr2->SetFillColor(42);
//   gr2->DrawClone("alf");
//   gMinuit->SetErrorDef(1);
//   TGraph *gr1 = (TGraph*)gMinuit->Contour(80,0,1);
//   gr1->SetFillColor(38);
//   gr1->DrawClone("lf");
//   gPad->SetGrid();
  
 }
 
 cGr->cd(3);
 TGraphErrors* grPhi = new TGraphErrors(36,phi_Mean,DPhi_SM_Mean,phi_RMS,DPhi_SM_RMS);
 grPhi->SetMarkerColor(kGreen);
 grPhi->SetLineColor(kGreen);
 grPhi->SetMarkerStyle(20);
 grPhi->SetMarkerSize(1);
 grPhi->SetLineWidth(1);
 grPhi->GetXaxis()->SetTitle("SM");
 grPhi->GetYaxis()->SetTitle("#Delta#phi");
 grPhi->Draw("AP");
 gPad->SetGrid();
 
 
 gPad->Update();
 cGr_DPHI_DETA_vs_PHI->cd(3);
 TGraphErrors* gr_EBPlus_DPHI_vs_PHI = new TGraphErrors(18,Phi_SM_Mean,DPhi_EBPlus_Mean,Phi_SM_RMS,DPhi_EBPlus_RMS);
 gr_EBPlus_DPHI_vs_PHI->SetTitle("EB+ #Delta#phi");
 gr_EBPlus_DPHI_vs_PHI->SetMarkerColor(kGreen);
 gr_EBPlus_DPHI_vs_PHI->SetLineColor(kGreen);
 gr_EBPlus_DPHI_vs_PHI->SetMarkerStyle(20);
 gr_EBPlus_DPHI_vs_PHI->SetMarkerSize(1);
 gr_EBPlus_DPHI_vs_PHI->SetLineWidth(1);
 gr_EBPlus_DPHI_vs_PHI->GetXaxis()->SetTitle("#phi");
 gr_EBPlus_DPHI_vs_PHI->GetYaxis()->SetTitle("#Delta#phi");
 gr_EBPlus_DPHI_vs_PHI->Draw("AP");
 gPad->SetGrid();
 
 gPad->Update();
 cGr_DPHI_DETA_vs_PHI->cd(4);
 TGraphErrors* gr_EBMinus_DPHI_vs_PHI = new TGraphErrors(18,Phi_SM_Mean,DPhi_EBMinus_Mean,Phi_SM_RMS,DPhi_EBMinus_RMS);
 gr_EBMinus_DPHI_vs_PHI->SetTitle("EB- #Delta#phi");
 gr_EBMinus_DPHI_vs_PHI->SetMarkerColor(kGreen);
 gr_EBMinus_DPHI_vs_PHI->SetLineColor(kGreen);
 gr_EBMinus_DPHI_vs_PHI->SetMarkerStyle(20);
 gr_EBMinus_DPHI_vs_PHI->SetMarkerSize(1);
 gr_EBMinus_DPHI_vs_PHI->SetLineWidth(1);
 gr_EBMinus_DPHI_vs_PHI->GetXaxis()->SetTitle("#phi");
 gr_EBMinus_DPHI_vs_PHI->GetYaxis()->SetTitle("#Delta#phi");
 gr_EBMinus_DPHI_vs_PHI->Draw("AP");
 gPad->SetGrid();
 gPad->Update();
 
 
 
 TCanvas* cSM_DZ_DR = new TCanvas ("cSM_DZ_DR","cSM_DZ_DR",600,800);
 cSM_DZ_DR->Divide(1,4);
 cSM_DZ_DR->cd(1);
 TGraphErrors* grDR = new TGraphErrors(36,iSM_SM_Mean,DR_SM_Mean,iSM_SM_RMS,DR_SM_RMS);
 grDR->SetMarkerColor(kBlue);
 grDR->SetLineColor(kBlue);
 grDR->SetMarkerStyle(20);
 grDR->SetMarkerSize(1);
 grDR->SetLineWidth(1);
 grDR->GetXaxis()->SetTitle("SM");
 grDR->GetYaxis()->SetTitle("#DeltaR");
 grDR->Draw("AP");
 gPad->SetGrid();

 cSM_DZ_DR->cd(2);
 TGraphErrors* grDZ = new TGraphErrors(36,iSM_SM_Mean,DZ_SM_Mean,iSM_SM_RMS,DZ_SM_RMS);
 grDZ->SetMarkerColor(kRed);
 grDZ->SetLineColor(kRed);
 grDZ->SetMarkerStyle(20);
 grDZ->SetMarkerSize(1);
 grDZ->SetLineWidth(1);
 grDZ->GetXaxis()->SetTitle("SM");
 grDZ->GetYaxis()->SetTitle("#DeltaZ");
 grDZ->Draw("AP");
 gPad->SetGrid();
 
 cSM_DZ_DR->cd(3); 
 TGraphErrors* grDX = new TGraphErrors(36,iSM_SM_Mean,DX_SM_Mean,iSM_SM_RMS,DX_SM_RMS);
 grDX->SetMarkerColor(kGreen);
 grDX->SetLineColor(kGreen);
 grDX->SetMarkerStyle(20);
 grDX->SetMarkerSize(1);
 grDX->SetLineWidth(1);
 grDX->GetXaxis()->SetTitle("SM");
 grDX->GetYaxis()->SetTitle("#DeltaX");
 grDX->Draw("AP");
 gPad->SetGrid();
 
 cSM_DZ_DR->cd(4); 
 TGraphErrors* grDY = new TGraphErrors(36,iSM_SM_Mean,DY_SM_Mean,iSM_SM_RMS,DY_SM_RMS);
 grDY->SetMarkerColor(kMagenta);
 grDY->SetLineColor(kMagenta);
 grDY->SetMarkerStyle(20);
 grDY->SetMarkerSize(1);
 grDY->SetLineWidth(1);
 grDY->GetXaxis()->SetTitle("SM");
 grDY->GetYaxis()->SetTitle("#DeltaY");
 grDY->Draw("AP");
 gPad->SetGrid();
 
 ///======================================================================
 
 
 
 
 std::ifstream file ("test/Survey.txt"); 
 char name_temp[1000];
 double DX_SM_Survey[36];
 double DY_SM_Survey[36];
 double DZ_SM_Survey[36];
 
 std::string buffer;
 if (!file.is_open()){
  std::cerr << "noooo" << std::endl;
 }
 int iSM_survey = 0;
 while(!file.eof()){
  getline(file,buffer);
  std::cout << "buffer = " << buffer; // << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){
    std::stringstream line( buffer );       
    line >> name_temp;
    line >> name_temp;
    line >> DX_SM_Survey[iSM_survey];
    line >> DY_SM_Survey[iSM_survey];
    line >> DZ_SM_Survey[iSM_survey];

    DX_SM_Survey[iSM_survey] += 0.1475;
    DY_SM_Survey[iSM_survey] += -0.3782;
    DZ_SM_Survey[iSM_survey] += -0.4847;
    
    DX_SM_Survey[iSM_survey] /= 1000; std::cout << " " << DX_SM_Survey[iSM_survey];
    DY_SM_Survey[iSM_survey] /= 1000; std::cout << " " << DY_SM_Survey[iSM_survey];
    DZ_SM_Survey[iSM_survey] /= 1000; std::cout << " " << DZ_SM_Survey[iSM_survey];
    std::cout << std::endl;
    
    iSM_survey++;
   } 
  }
 }
 
 
 cSM_DZ_DR->cd(2);
 TGraphErrors* grDZ_Survey = new TGraphErrors(36,iSM_SM_Mean,DZ_SM_Survey,iSM_SM_RMS,iSM_SM_RMS);
 grDZ_Survey->SetMarkerColor(kGray);
 grDZ_Survey->SetLineColor(kGray);
 grDZ_Survey->SetMarkerStyle(21);
 grDZ_Survey->SetMarkerSize(1);
 grDZ_Survey->SetLineWidth(1);
 grDZ_Survey->GetXaxis()->SetTitle("SM");
 grDZ_Survey->GetYaxis()->SetTitle("#DeltaZ");
 grDZ_Survey->Draw("P");
 gPad->SetGrid();
 
 cSM_DZ_DR->cd(3); 
 TGraphErrors* grDX_Survey = new TGraphErrors(36,iSM_SM_Mean,DX_SM_Survey,iSM_SM_RMS,iSM_SM_RMS);
 grDX_Survey->SetMarkerColor(kGray);
 grDX_Survey->SetLineColor(kGray);
 grDX_Survey->SetMarkerStyle(21);
 grDX_Survey->SetMarkerSize(1);
 grDX_Survey->SetLineWidth(1);
 grDX_Survey->GetXaxis()->SetTitle("SM");
 grDX_Survey->GetYaxis()->SetTitle("#DeltaX");
 grDX_Survey->Draw("P");
 gPad->SetGrid();
 
 cSM_DZ_DR->cd(4); 
 TGraphErrors* grDY_Survey = new TGraphErrors(36,iSM_SM_Mean,DY_SM_Survey,iSM_SM_RMS,iSM_SM_RMS);
 grDY_Survey->SetMarkerColor(kGray);
 grDY_Survey->SetLineColor(kGray);
 grDY_Survey->SetMarkerStyle(21);
 grDY_Survey->SetMarkerSize(1);
 grDY_Survey->SetLineWidth(1);
 grDY_Survey->GetXaxis()->SetTitle("SM");
 grDY_Survey->GetYaxis()->SetTitle("#DeltaY");
 grDY_Survey->Draw("P");
 gPad->SetGrid();
 
 
 ///==== dump results ====
 
 #include "iomanip"
 
 ofstream outFile;
 outFile.open ("test/AlignmentElectron.txt");
 outFile << "#SM   id   dx   errdx   dy   errdy   dz   errdz    numEle" << std::endl;
 for (int iSM = 0; iSM<36; iSM++){
  if (iSM<18) outFile << "EB+ " << iSM+1;
  else outFile << "EB- " << iSM-18;
  outFile << " " 
	  << setfill(' ') << setw(10) << setprecision(5) << Phi_SM_Mean[iSM] << " "
	  << setfill(' ') << setw(10) << setprecision(5) << 1000*DX_SM_Mean[iSM] << " "
	  << setfill(' ') << setw(10) << setprecision(5) << 1000*DX_SM_RMS[iSM] << " " 
	  << setfill(' ') << setw(10) << setprecision(5) << 1000*DY_SM_Mean[iSM] << " "
	  << setfill(' ') << setw(10) << setprecision(5) << 1000*DY_SM_RMS[iSM] << " "
	  << setfill(' ') << setw(10) << setprecision(5) << 1000*DZ_SM_Mean[iSM] << " "
	  << setfill(' ') << setw(10) << setprecision(5) << 1000*DZ_SM_RMS[iSM] << " "
	  << setfill(' ') << setw(10) << setprecision(5) << DEta_SM_Mean[iSM] << " "
	  << setfill(' ') << setw(10) << setprecision(5) << DEta_SM_RMS[iSM] << " "
	  << setfill(' ') << setw(10) << setprecision(5) << DPhi_SM_Mean[iSM] << " "
	  << setfill(' ') << setw(10) << setprecision(5) << DPhi_SM_RMS[iSM] << " " 
	  << setfill(' ') << setw(10) << setprecision(5) << numEntries_Mean[iSM] << " " 
	  << std::endl;
 }
 outFile.close(); 
 
}



