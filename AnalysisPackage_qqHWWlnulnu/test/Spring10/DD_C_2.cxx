void DD_C_2( TString nameSampleIN = "" , double MinCutValueX, double MinCutValueY){
 
 int BinX = 100;
 double MaxX = 5;
 double MinX = -5;
 
 int BinY = 100;
 double MaxY = 5;
 double MinY = 0;
 
 
 ///====================================================
 
 double pT_RECO_q1;
 double pT_RECO_q2;
 double eta_RECO_q1;
 double eta_RECO_q2;
 double eta_RECO_q1_eta_RECO_q2;
 double Deta_RECO_q12;
 double Mjj;
 int JV_20;
 int JV_30;
 int CJV_20;
 int CJV_30;
 int AnalysisStep; 
 double MLP_Jet;
 double BDT_Jet;
 double Fisher_Jet;
 double Likelihood_Jet;
 double LikelihoodD_Jet;
 
 int pdgId_RECO_l1;
 int pdgId_RECO_l2;
 double pT_RECO_l1;
 double pT_RECO_l2;
 double eta_RECO_l1;
 double eta_RECO_l2;
 double eta_RECO_l1_eta_RECO_l2;
 double Deta_RECO_l12;
 double Dphi_RECO_l12;
 double Mll;
 double charge_RECO_l1_charge_RECO_l2;
 double MLP_Lep;
 double BDT_Lep;
 double Fisher_Lep;
 double Likelihood_Lep;
 double LikelihoodD_Lep;
 
 
 
 char NameVarX[1000] = {
   "Likelihood_Lep"
/*  "pT_RECO_q1"
  "pT_RECO_q2",
  "eta_RECO_q1",
  "eta_RECO_q2",
  "eta_RECO_q1_eta_RECO_q2",
  "Deta_RECO_q12",
  "Mjj",
  "JV_20",
  "JV_30",
  "CJV_20",
  "CJV_30",
  "AnalysisStep", 
  "MLP_Jet",
  "BDT_Jet",
  "Fisher_Jet",
  "Likelihood_Jet",
  "LikelihoodD_Jet", 
  "pdgId_RECO_l1",
  "pdgId_RECO_l2",
  "pT_RECO_l1",
  "pT_RECO_l2",
  "eta_RECO_l1",
  "eta_RECO_l2",
  "eta_RECO_l1_eta_RECO_l2",
  "Deta_RECO_l12",
  "Dphi_RECO_l12",
  "Mll",
  "charge_RECO_l1_charge_RECO_l2",
  "MLP_Lep",
  "BDT_Lep",
  "Fisher_Lep",
  "Likelihood_Lep",
  "LikelihoodD_Lep"*/
 };

 
 ///====================================================
 
 double pT_RECO_q1;
 double pT_RECO_q2;
 double eta_RECO_q1;
 double eta_RECO_q2;
 double eta_RECO_q1_eta_RECO_q2;
 double Deta_RECO_q12;
 double Mjj;
 int JV_20;
 int JV_30;
 int CJV_20;
 int CJV_30;
 int AnalysisStep; 
 double MLP_Jet;
 double BDT_Jet;
 double Fisher_Jet;
 double Likelihood_Jet;
 double LikelihoodD_Jet;
 
 int pdgId_RECO_l1;
 int pdgId_RECO_l2;
 double pT_RECO_l1;
 double pT_RECO_l2;
 double eta_RECO_l1;
 double eta_RECO_l2;
 double eta_RECO_l1_eta_RECO_l2;
 double Deta_RECO_l12;
 double Dphi_RECO_l12;
 double Mll;
 double charge_RECO_l1_charge_RECO_l2;
 double MLP_Lep;
 double BDT_Lep;
 double Fisher_Lep;
 double Likelihood_Lep;
 double LikelihoodD_Lep;
 
 
 
 char NameVarY[1000] = {
//   "Likelihood_Lep"
//   "pT_RECO_q1"
//   "pT_RECO_q2",
  "abs(eta_RECO_q1)",
//   "eta_RECO_q2",
//   "eta_RECO_q1_eta_RECO_q2",
//   "Deta_RECO_q12",
//   "Mjj",
//   "JV_20",
//   "JV_30",
//   "CJV_20",
//   "CJV_30",
//   "AnalysisStep", 
//   "MLP_Jet",
//   "BDT_Jet",
//   "Fisher_Jet",
//   "Likelihood_Jet",
//   "LikelihoodD_Jet", 
//   "pdgId_RECO_l1",
//   "pdgId_RECO_l2",
//   "pT_RECO_l1",
//   "pT_RECO_l2",
// "sqrt(eta_RECO_l1*eta_RECO_l1)"
//   "eta_RECO_l2"
//   "eta_RECO_l1_eta_RECO_l2",
//   "Deta_RECO_l12",
//   "Dphi_RECO_l12",
//   "Mll",
//   "charge_RECO_l1_charge_RECO_l2",
//   "MLP_Lep",
//   "BDT_Lep",
//   "Fisher_Lep",
//   "Likelihood_Lep",
//   "LikelihoodD_Lep"
 };
 
 
 
 
 TTree *signal_background[100]; 
 double weights[100];
 
 TTree *treeEffVect[100];
 char *nameSample[1000];
 char *nameSamplePrefix[1000];
 char *nameSampleTree[1000];
 double xsection[1000];
 std::ifstream inFile("/home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/test/Spring10/samples.txt");
 std::string buffer;
 
 int totalSamples = 0;
 int iSampleSel = -1;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  //   std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   //    std::cout << "buffer.at(0) = " << buffer.at(0) << std::endl;
   if (buffer.at(0) != '#'){ ///--------------------------------------- NON FUNZIONA!!!
    std::stringstream line( buffer );       
    nameSample[totalSamples] = new char [1000];
    line >> nameSample[totalSamples]; 
    std::cout << nameSample[totalSamples] << " ";
    
    std::string nameStr = nameSample[totalSamples];
    if (nameSampleIN.Data() == nameStr){
     std::cerr << " >>> found sample ..." << std::endl;
     iSampleSel = totalSamples;
    }
     
    
    nameSamplePrefix[totalSamples] = new char [1000];
    line >> nameSamplePrefix[totalSamples];
    
    nameSampleTree[totalSamples] = new char [1000];
    line >> nameSampleTree[totalSamples];
    
    line >> xsection[totalSamples]; 
    std::cout << xsection[totalSamples] << " ";
    
    char nameFile[1000];
    sprintf(nameFile,"/home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/output_Spring10/out_FinalSelection_%s.root",nameSample[totalSamples]);  
    TFile* f = new TFile(nameFile, "READ");
    
    treeEffVect[totalSamples] = (TTree) f->Get("outTreeSelections");
    char nameTreeEff[100];
    sprintf(nameTreeEff,"treeEff_%d",totalSamples); 
    treeEffVect[totalSamples]->SetName(nameTreeEff);      
    
    double XSection;
    double eff_Channel_Filter;
    double preselection_efficiency;
    int numEntriesBefore;
    treeEffVect[totalSamples]->SetBranchAddress("XSection",&XSection);
    treeEffVect[totalSamples]->SetBranchAddress("preselection_efficiency",&preselection_efficiency);
    treeEffVect[totalSamples]->SetBranchAddress("numEntriesBefore",&numEntriesBefore);
    treeEffVect[totalSamples]->GetEntry(0);
    
    ///**********************************************************************
    weights[totalSamples] = XSection * preselection_efficiency / numEntriesBefore;
    signal_background[totalSamples] = (TTree) f->Get("outTreeJetLep");
    ///**********************************************************************
    std::cout << std::endl;
    totalSamples++;
   } 
  }
 }
 
 
 
 
 
 if (iSampleSel == -1) {
  std::cerr << "something went wrong ... " << std::endl;
  exit(0);
 }





///================================================================================================
 char nameStackX[100];
 sprintf(nameStackX,"stackX_%s",NameVarX); 
 THStack* hsX = new THStack(nameStackX,nameStackX);
 
 TH1F *histosX[100000];
 
 for (int iSample = 0 ; iSample < totalSamples; iSample++){
//  for (int iSample = (totalSamples-1); iSample>= 0; iSample--){
  char nameHistoX[1000];
  sprintf(nameHistoX,"%s_X",nameSample[iSample]);
  histosX[iSample] = new TH1F(nameHistoX,nameHistoX,BinX,MinX,MaxX);
  
  char toDraw[1000];
  sprintf(toDraw,"%s >> %s",NameVarX,nameHistoX);
  std::cerr << " toDraw = " << toDraw << std::endl;
  char toCut[1000];
  sprintf(toCut,"");
  signal_background[iSample]->Draw(toDraw,toCut,"");
  histosX[iSample]->Sumw2();
  histosX[iSample]->Scale(weights[iSample]);
  histosX[iSample]->SetMarkerColor(kOrange - 5 + iSample * 3);
  histosX[iSample]->SetLineColor(kOrange - 5 + iSample * 3);
  histosX[iSample]->SetFillColor(kOrange - 5 + iSample * 3);
  histosX[iSample]->SetLineWidth(1);
  histosX[iSample]->SetFillStyle(3001);
  hsX->Add(histosX[iSample]);
 }
 
 
 
 char nameStackY[100];
 sprintf(nameStackY,"stackY_%s",NameVarY); 
 THStack* hsY = new THStack(nameStackY,nameStackY);
 
 TH1F *histosY[100000];
 
 for (int iSample = 0 ; iSample < totalSamples; iSample++){
  //  for (int iSample = (totalSamples-1); iSample>= 0; iSample--){
   char nameHistoY[1000];
   sprintf(nameHistoY,"%s_Y",nameSample[iSample]);
   histosY[iSample] = new TH1F(nameHistoY,nameHistoY,BinY,MinY,MaxY);
   
   char toDraw[1000];
   sprintf(toDraw,"%s >> %s",NameVarY,nameHistoY);
   std::cerr << " toDraw = " << toDraw << std::endl;
   char toCut[1000];
   sprintf(toCut,"");
   signal_background[iSample]->Draw(toDraw,toCut,"");
   histosY[iSample]->Sumw2();
   histosY[iSample]->Scale(weights[iSample]);
   histosY[iSample]->SetMarkerColor(kOrange - 5 + iSample * 3);
   histosY[iSample]->SetLineColor(kOrange - 5 + iSample * 3);
   histosY[iSample]->SetFillColor(kOrange - 5 + iSample * 3);
   histosY[iSample]->SetLineWidth(1);
   histosY[iSample]->SetFillStyle(3001);
   hsY->Add(histosY[iSample]);
  }
  
 ///================================================================================================
 
 

 TCanvas* cc = new TCanvas("cc","cc",900,300);
 cc->Divide(3,2);
 
 signal_background[iSampleSel]->SetLineColor(kOrange - 5 + iSampleSel * 3);
 signal_background[iSampleSel]->SetMarkerColor(kOrange - 5 + iSampleSel * 3);
 signal_background[iSampleSel]->SetFillColor(kOrange - 5 + iSampleSel * 3);
 signal_background[iSampleSel]->SetFillStyle(3001);
 signal_background[iSampleSel]->SetLineWidth(1.);
 signal_background[iSampleSel]->SetMarkerStyle(20);
 signal_background[iSampleSel]->SetMarkerSize(0.1);
 
 gStyle->SetPaintTextFormat("5.2f");
//  TH1F* h1Distro = new TH1F("h1Distro","h1Distro",BinX,MinX,MaxX);
 
 cc->cd(1);
 hsX->Draw();
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 cc->cd(2);
 
 char toDraw[1000];
 sprintf(toDraw,"%s",NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 char toCut[1000];
 sprintf(toCut,"");
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 gPad->SetGrid();
 TH1F *htempTotalX = ((TH1F*)gPad->GetPrimitive("htemp"))->Clone();
 htempTotalX->SetName("htempTotalX");
 TH1F *htempLeftX = ((TH1F*)gPad->GetPrimitive("htemp"))->Clone();
 htempLeftX->SetName("htempLeftX");
 TH1F *htempRightX = ((TH1F*)gPad->GetPrimitive("htemp"))->Clone();
 htempRightX->SetName("htempRightX");
 htempTotalX->Sumw2();
 htempTotalX->Scale(weights[iSampleSel]);
 htempTotalX->Draw();
 
 
 
 
 cc->cd(3);
 sprintf(toDraw,"%s >> htempLeftX",NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s < %f",NameVarX,MinCutValueX);
 std::cerr << " toCut = " << toCut << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 htempLeftX->Sumw2();
 htempLeftX->Scale(weights[iSampleSel]);
 htempLeftX->SetLineColor(kGreen);
 htempLeftX->SetMarkerColor(kGreen);
 htempLeftX->SetFillColor(kGreen);
 htempLeftX->SetFillStyle(3001);
 htempLeftX->SetLineWidth(1.);
 htempLeftX->SetMarkerStyle(20);
 htempLeftX->SetMarkerSize(0.1);
 
 
 sprintf(toDraw,"%s >> htempRightX",NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s >= %f",NameVarX,MinCutValueX);
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 std::cerr << " toCut = " << toCut << std::endl;
 htempRightX->Sumw2();
 htempRightX->Scale(weights[iSampleSel]);
 htempRightX->SetLineColor(kBlue);
 htempRightX->SetMarkerColor(kBlue);
 htempRightX->SetFillColor(kBlue);
 htempRightX->SetFillStyle(3001);
 htempRightX->SetLineWidth(1.);
 htempRightX->SetMarkerStyle(20);
 htempRightX->SetMarkerSize(0.1);
 
 htempLeftX->Draw();
 htempRightX->Draw("same");
 gPad->SetGrid();
 
 
 std:cerr << " MinCutValueX = " << MinCutValueX << std::endl;
 
//  htempTotalX->Smooth(1);
//  htempLeftX->Smooth(1);
//  htempRightX->Smooth(1);
 
 
 std::cerr << " Less than Cut = " << htempLeftX->Integral() << std::endl;
 std::cerr << " More than Cut = " << htempRightX->Integral() << std::endl;
 std::cerr << "               = " << htempTotalX->Integral() << std::endl;
 
 std::cerr << "      Fraction = " << htempRightX->Integral() / htempLeftX->Integral() << std::endl;
 
 double CorrectionCoefficientX = htempRightX->Integral() / htempLeftX->Integral();
 
 
 ///==============================================================================
 
 
 cc->cd(4);
 hsY->Draw();
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 cc->cd(5);
 
 sprintf(toDraw,"%s",NameVarY);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"");
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 gPad->SetGrid();
 TH1F *htempTotalY = ((TH1F*)gPad->GetPrimitive("htemp"))->Clone();
 htempTotalY->SetName("htempTotalY");
 TH1F *htempLeftY = ((TH1F*)gPad->GetPrimitive("htemp"))->Clone();
 htempLeftY->SetName("htempLeftY");
 TH1F *htempRightY = ((TH1F*)gPad->GetPrimitive("htemp"))->Clone();
 htempRightY->SetName("htempRightY");
 htempTotalY->Sumw2();
 htempTotalY->Scale(weights[iSampleSel]);
 htempTotalY->Draw();
 
 
 
 
 cc->cd(6);
 sprintf(toDraw,"%s >> htempLeftY",NameVarY);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s < %f",NameVarY,MinCutValueY);
 std::cerr << " toCut = " << toCut << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 htempLeftY->Sumw2();
 htempLeftY->Scale(weights[iSampleSel]);
 htempLeftY->SetLineColor(kGreen);
 htempLeftY->SetMarkerColor(kGreen);
 htempLeftY->SetFillColor(kGreen);
 htempLeftY->SetFillStyle(3001);
 htempLeftY->SetLineWidth(1.);
 htempLeftY->SetMarkerStyle(20);
 htempLeftY->SetMarkerSize(0.1);
 
 
 sprintf(toDraw,"%s >> htempRightY",NameVarY);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s >= %f",NameVarY,MinCutValueY);
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 std::cerr << " toCut = " << toCut << std::endl;
 htempRightY->Sumw2();
 htempRightY->Scale(weights[iSampleSel]);
 htempRightY->SetLineColor(kBlue);
 htempRightY->SetMarkerColor(kBlue);
 htempRightY->SetFillColor(kBlue);
 htempRightY->SetFillStyle(3001);
 htempRightY->SetLineWidth(1.);
 htempRightY->SetMarkerStyle(20);
 htempRightY->SetMarkerSize(0.1);
 
 htempLeftY->Draw();
 htempRightY->Draw("same");
 gPad->SetGrid();
 
 
 std:cerr << " MinCutValueY = " << MinCutValueY << std::endl;
 
 //  htempTotalY->Smooth(1);
 //  htempLeftY->Smooth(1);
 //  htempRightY->Smooth(1);
 
 
 std::cerr << " Less than Cut = " << htempLeftY->Integral() << std::endl;
 std::cerr << " More than Cut = " << htempRightY->Integral() << std::endl;
 std::cerr << "               = " << htempTotalY->Integral() << std::endl;
 
 std::cerr << "      Fraction = " << htempRightY->Integral() / htempLeftY->Integral() << std::endl;
 
 double CorrectionCoefficientY = htempRightY->Integral() / htempLeftY->Integral();
 
 
 ///==============================================================================
 ///==== 2D distributions ====
 
 TCanvas *cc2D = new TCanvas("cc2D","cc2D",1000,500);
 cc2D->Divide(2,1);
 
 cc2D->cd(1);
 
 TH2F* h2Distro = new TH2F("h2Distro","h2Distro",BinX,MinX,MaxX,BinY,MinY,MaxY);

 sprintf(toDraw,"%s:%s >> h2Distro",NameVarY,NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,"","");
 
 h2Distro->Draw("colz");
 h2Distro->GetXaxis()->SetTitle(NameVarX);
 h2Distro->GetYaxis()->SetTitle(NameVarY);
  
 TLine* lOriz = new TLine(MinX,MinCutValueY,MaxX,MinCutValueY);
 lOriz->SetLineColor(kRed);
 lOriz->SetLineWidth(4);
 lOriz->SetLineStyle(5);
 lOriz->Draw();
 
 TLine* lVert = new TLine(MinCutValueX,MinY,MinCutValueX,MaxY);
 lVert->SetLineColor(kRed);
 lVert->SetLineWidth(4);
 lVert->SetLineStyle(5);
 lVert->Draw();
 
 gPad->SetGrid();
 
 
 
 
 ///================================================================================================
 
 cc2D->cd(2);
 sprintf(toDraw,"%s:%s",NameVarY,NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"");
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 TH2F *htempTotal2D = ((TH2F*)gPad->GetPrimitive("htemp"))->Clone();
 htempTotal2D->SetName("htempTotal2D");
 TH2F *htemp_A_2D = ((TH2F*)gPad->GetPrimitive("htemp"))->Clone();
 htemp_A_2D->SetName("htemp_A_2D");
 TH2F *htemp_B_2D = ((TH2F*)gPad->GetPrimitive("htemp"))->Clone();
 htemp_B_2D->SetName("htemp_B_2D");
 TH2F *htemp_C_2D = ((TH2F*)gPad->GetPrimitive("htemp"))->Clone();
 htemp_C_2D->SetName("htemp_C_2D");
 TH2F *htemp_D_2D = ((TH2F*)gPad->GetPrimitive("htemp"))->Clone();
 htemp_D_2D->SetName("htemp_D_2D");
 sprintf(toDraw,"%s:%s >> htempLeft2D",NameVarY,NameVarX);
 
 
 sprintf(toDraw,"%s:%s >> htemp_A_2D",NameVarY,NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s < %f && %s > %f",NameVarX,MinCutValueX,NameVarY,MinCutValueY);
 std::cerr << " toCut = " << toCut << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
//  htemp_A_2D->Scale(weights[iSampleSel]);
 htemp_A_2D->SetLineColor(kRed);
 htemp_A_2D->SetMarkerColor(kRed);
 htemp_A_2D->SetFillColor(kRed);
 htemp_A_2D->SetFillStyle(3001);
 htemp_A_2D->SetLineWidth(1.);
 htemp_A_2D->SetMarkerStyle(20);
 htemp_A_2D->SetMarkerSize(0.1);
 
 
 sprintf(toDraw,"%s:%s >> htemp_B_2D",NameVarY,NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s > %f && %s > %f",NameVarX,MinCutValueX,NameVarY,MinCutValueY);
 std::cerr << " toCut = " << toCut << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
//  htemp_B_2D->Scale(weights[iSampleSel]);
htemp_B_2D->SetLineColor(kBlue);
 htemp_B_2D->SetMarkerColor(kBlue);
 htemp_B_2D->SetFillColor(kBlue);
 htemp_B_2D->SetFillStyle(3001);
 htemp_B_2D->SetLineWidth(1.);
 htemp_B_2D->SetMarkerStyle(20);
 htemp_B_2D->SetMarkerSize(0.1);
 
 
 sprintf(toDraw,"%s:%s >> htemp_C_2D",NameVarY,NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s > %f && %s < %f",NameVarX,MinCutValueX,NameVarY,MinCutValueY);
 std::cerr << " toCut = " << toCut << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
//  htemp_C_2D->Scale(weights[iSampleSel]);
 htemp_C_2D->SetLineColor(kOrange);
 htemp_C_2D->SetMarkerColor(kOrange);
 htemp_C_2D->SetFillColor(kOrange);
 htemp_C_2D->SetFillStyle(3001);
 htemp_C_2D->SetLineWidth(1.);
 htemp_C_2D->SetMarkerStyle(20);
 htemp_C_2D->SetMarkerSize(0.1);
 
 
 sprintf(toDraw,"%s:%s >> htemp_D_2D",NameVarY,NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s < %f && %s < %f",NameVarX,MinCutValueX,NameVarY,MinCutValueY);
 std::cerr << " toCut = " << toCut << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
//  htemp_D_2D->Scale(weights[iSampleSel]);
 htemp_D_2D->SetLineColor(kGreen);
 htemp_D_2D->SetMarkerColor(kGreen);
 htemp_D_2D->SetFillColor(kGreen);
 htemp_D_2D->SetFillStyle(3001);
 htemp_D_2D->SetLineWidth(1.);
 htemp_D_2D->SetMarkerStyle(20);
 htemp_D_2D->SetMarkerSize(0.1);
 
 
 htemp_A_2D->Draw();
 htemp_B_2D->Draw("same");
 htemp_C_2D->Draw("same");
 htemp_D_2D->Draw("same");
 
 
//  TPaveText *ptA = new TPaveText(MinX,MinY,MinCutValueX,MinCutValueY,"br");
//  TPaveText *ptA = new TPaveText(-1.300318,-1.921913,-0.4803715,-0.7415254,"br");
//  ptA->SetTextColor(3);
//  text = pt->AddText("A");
//  ptA->Draw();
 
 
 lOriz->Draw();
 lVert->Draw();


 double nA0 = htemp_A_2D->Integral();
 double nB0 = htemp_B_2D->Integral();
 double nC0 = htemp_C_2D->Integral();
 double nD0 = htemp_D_2D->Integral();
 
 std::cerr << std::endl;
 std::cerr << "  A   |   B   " << std::endl;
 std::cerr << " ------------ " << std::endl;
 std::cerr << "  D   |   C   " << std::endl;
 std::cerr << std::endl;
 
 std::cerr << " A = " << nA0 << std::endl;
 std::cerr << " B = " << nB0 << std::endl;
 std::cerr << " C = " << nC0 << std::endl;
 std::cerr << " D = " << nD0 << std::endl;
 
 std::cerr << std::endl;
 
 std::cerr << " A/B = " << nA0 / nB0 << " +/- " << sqrt((nA0 * nB0 + nA0 * nA0) / (nB0 * nB0 * nB0)) << std::endl;
 std::cerr << " D/C = " << nD0 / nC0 << " +/- " << sqrt((nD0 * nC0 + nD0 * nD0) / (nC0 * nC0 * nC0)) << std::endl;
 
 std::cerr << " (A/B) / (D/C) = " << (nA0 / nB0) / (nD0 / nC0) << std::endl;
 
 
 ///================================
 ///==== 2D to 1D distributions ====
 
 TH1D *htemp_A_2D_X = htemp_A_2D->ProjectionX();
 TH1D *htemp_B_2D_X = htemp_B_2D->ProjectionX();
 TH1D *htemp_C_2D_X = htemp_C_2D->ProjectionX();
 TH1D *htemp_D_2D_X = htemp_D_2D->ProjectionX();
 
 TH1D *htemp_A_2D_Y = htemp_A_2D->ProjectionY();
 TH1D *htemp_B_2D_Y = htemp_B_2D->ProjectionY();
 TH1D *htemp_C_2D_Y = htemp_C_2D->ProjectionY();
 TH1D *htemp_D_2D_Y = htemp_D_2D->ProjectionY();
 
 htemp_A_2D_X->Sumw2();
 htemp_B_2D_X->Sumw2();
 htemp_C_2D_X->Sumw2();
 htemp_D_2D_X->Sumw2();
 htemp_A_2D_Y->Sumw2();
 htemp_B_2D_Y->Sumw2();
 htemp_C_2D_Y->Sumw2();
 htemp_D_2D_Y->Sumw2();
 
 TCanvas *cc1D = new TCanvas("cc1D","cc1D",1000,1000);
 cc1D->Divide(2,2);
 
 cc1D->cd(1);
 htemp_A_2D_X->DrawNormalized("E");
 htemp_D_2D_X->DrawNormalized("Esame");
 gPad->SetGrid();
 
 cc1D->cd(2);
 htemp_B_2D_X->DrawNormalized("E");
 htemp_C_2D_X->DrawNormalized("Esame");
 gPad->SetGrid();
 
 cc1D->cd(3);
 htemp_A_2D_Y->DrawNormalized("E");
 htemp_B_2D_Y->DrawNormalized("Esame");
 gPad->SetGrid();
 
 cc1D->cd(4);
 htemp_D_2D_Y->DrawNormalized("E");
 htemp_C_2D_Y->DrawNormalized("Esame");
 gPad->SetGrid();
 
 
 
 
 
 ///==============================================================================
 
 
 int nLumi = 13;
 int nTest = 1000;
 double deltaLumi = 10;
 
 TCanvas* ccLumi = new TCanvas("ccLumi","ccLumi",800,800);
 ccLumi->Divide(sqrt(nLumi)+1,sqrt(nLumi)+1);
 
 sprintf(toDraw,"%s:%s >> htempTotal2D",NameVarY,NameVarX);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"");
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 
 std::cerr << " max MC simulation = " << htempTotal2D->GetEntries() << std::endl;
 
 TH1F* hRatio[1000];
 
 int* nA = new int [nLumi];
 int* nB = new int [nLumi];
 int* nC = new int [nLumi];
 int* nD = new int [nLumi];
 double* xLumi = new double [nLumi];
 double* yRatio = new double [nLumi];
 double* errxLumi = new double [nLumi];
 double* erryRatio = new double [nLumi];
 
 for (int iLumi = 0; iLumi < nLumi; iLumi++){
  ccLumi->cd(iLumi+1);
  char nameHisto[1000];
  sprintf(nameHisto,"Histo_%d",iLumi);
  nA[iLumi] = 0;
  nB[iLumi] = 0;
  nC[iLumi] = 0;
  nD[iLumi] = 0;
  double numLumi = pow(2,iLumi+1);// (iLumi+1) * deltaLumi;
  int numEvents = (weights[iSampleSel] * numLumi * htempTotal2D->GetEntries());

  int numBins = numEvents / 10;
  if (500 > numBins) numBins = 500;
  hRatio[iLumi] = new TH1F(nameHisto,nameHisto,numBins,0.,100.);
  
  
  for (int iTest = 0; iTest < nTest; iTest++){
   yRatio[iLumi] = 0;
   for (int iEvt = 0; iEvt < (numEvents); iEvt++){
    double Xtemp;
    double Ytemp;
    htempTotal2D->GetRandom2(Xtemp,Ytemp);  
    if (Xtemp < MinCutValueX && Ytemp > MinCutValueY) {
     nA[iLumi] ++;
    }
    if (Xtemp > MinCutValueX && Ytemp > MinCutValueY) {
     nB[iLumi] ++;
    }
    if (Xtemp > MinCutValueX && Ytemp < MinCutValueY) {
     nC[iLumi] ++;
    }
    if (Xtemp < MinCutValueX && Ytemp < MinCutValueY) {
     nD[iLumi] ++;
    }
   }
   if (nA[iLumi] != 0 && nB[iLumi] != 0 && nC[iLumi] != 0 && nD[iLumi] != 0)  {
    yRatio[iLumi] = (static_cast<double>(nA[iLumi]) / static_cast<double>(nB[iLumi])) / (static_cast<double>(nD[iLumi]) / static_cast<double>(nC[iLumi]));
   }
   else {
    yRatio[iLumi] = 0;
   }
   hRatio[iLumi]->Fill(yRatio[iLumi]);
  }
  yRatio[iLumi] = hRatio[iLumi]->GetMean();
  erryRatio[iLumi] = hRatio[iLumi]->GetRMS();
  xLumi[iLumi] = numLumi; //(weights[iSampleSel] * (iLumi+1) * deltaLumi) * htempTotal->GetEntries();
  errxLumi[iLumi] = 0;
//   if (!(iLumi%10)){
 std::cerr << "weights[" << iSampleSel << "] = " << weights[iSampleSel] << " numLumi: " << numLumi << " htempTotal2D->GetEntries() = " << htempTotal2D->GetEntries() << " numEvents : " << numEvents << " -> yRatio[" << iLumi << "] = " << yRatio[iLumi] << " +/-" << erryRatio[iLumi] << " : " << xLumi[iLumi] << std::endl;
//   }
  hRatio[iLumi]->SetLineColor(kYellow+iLumi);
  hRatio[iLumi]->SetFillColor(kYellow+iLumi);
  hRatio[iLumi]->SetFillStyle(3001);
  hRatio[iLumi]->SetLineWidth(1.);
  hRatio[iLumi]->Draw();
 }
 
 
 TCanvas* ccLumiResult = new TCanvas("ccLumiResult","ccLumiResult",800,800);
 ccLumiResult->cd();
 
 TGraphErrors* grRatioVsLumi = new TGraphErrors(nLumi,xLumi,yRatio,errxLumi,erryRatio);
 grRatioVsLumi->SetLineColor(kBlue);
 grRatioVsLumi->SetMarkerColor(kBlue);
 grRatioVsLumi->SetFillColor(kBlue);
 grRatioVsLumi->SetFillStyle(3001);
 grRatioVsLumi->SetLineWidth(1.);
 grRatioVsLumi->SetMarkerStyle(20);
 grRatioVsLumi->SetMarkerSize(0.5);
 grRatioVsLumi->Draw("AP");
 gPad->SetGrid();
 
  
 TLine* lOriz2 = new TLine(0,1,xLumi[nLumi-1],1);
 lOriz2->SetLineColor(kRed);
 lOriz2->SetLineWidth(4);
 lOriz2->SetLineStyle(5);
 lOriz2->Draw();
 
 
 
}



