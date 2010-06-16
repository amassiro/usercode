void DD_C_1( TString nameSampleIN = "" , double MinCutValueX, double MinCutValueY, TCut extCut = ""){
 
 int BinX = 1000;
 double MaxX = 5;
 double MinX = -5;
 
 int BinY = 10;
 double MaxY = 10;
 double MinY = 0;
 
//  int BinY = 100;
//  double MaxY = 4;
//  double MinY = 0;
 
 ///====================================================
 
 std::cerr << " extCut = " << extCut.Print() << std::endl;
 
 TCut totalCut = extCut;
 
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
// "NBjets_trackCountingHighPurBJetTags"
// "NBjets_combinedSecondaryVertexMVABJetTags"
// "min(abs(phi_RECO_q1-phi_RECO_q2),abs(6.283185307179586 - abs(phi_RECO_q1-phi_RECO_q2)))"
// "abs(phi_RECO_q1-phi_RECO_q2)",
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
//   "Z_01_30",
// "Z_03_30"
//   "Z_05_30",
//   "Z_07_30",
  "Z_09_30"
// "Z_10_30",
//   "Z_12_30",
//   "Z_14_30",
//   "Z_01_20",
//   "Z_03_20",
//   "Z_05_20",
//   "Z_07_20",
//   "Z_09_20",
//   "Z_10_20",
//   "Z_12_20",
//   "Z_14_20"
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
  totalCut = extCut + toCut;
  signal_background[iSample]->Draw(toDraw,totalCut,"");
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
   totalCut = extCut + toCut;
   signal_background[iSample]->Draw(toDraw,totalCut,"");
   histosY[iSample]->Sumw2();
   histosY[iSample]->Scale(weights[iSample]);
   histosY[iSample]->SetMarkerColor(kOrange - 5 + iSample * 3);
   histosY[iSample]->SetLineColor(kOrange - 5 + iSample * 3);
   histosY[iSample]->SetFillColor(kOrange - 5 + iSample * 3);
   
   if (iSample == iSampleSel){
    histosY[iSample]->SetMarkerColor(kGreen);
    histosY[iSample]->SetLineColor(kGreen);
    histosY[iSample]->SetFillColor(kGreen);
   }
   
   histosY[iSample]->SetLineWidth(1);
   histosY[iSample]->SetFillStyle(3001);
   hsY->Add(histosY[iSample]);
  }
  
 ///================================================================================================
 
 

 TCanvas* cc = new TCanvas("cc","cc",900,600);
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
 totalCut = extCut + toCut;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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
 totalCut = extCut + toCut;
 std::cerr << " toCut = " << totalCut.Print() << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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
 totalCut = extCut + toCut;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
 std::cerr << " toCut = " << totalCut.Print() << std::endl;
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
 TLegend* leg = gPad->BuildLegend();
 
 cc->cd(5);
 
 sprintf(toDraw,"%s",NameVarY);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"");
 totalCut = extCut + toCut;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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
 totalCut = extCut + toCut;
 std::cerr << " toCut = " << totalCut.Print() << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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
 totalCut = extCut + toCut;
 std::cerr << " toCut = " << totalCut.Print() << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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
 totalCut = extCut;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
 
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
 totalCut = extCut + toCut;
 std::cerr << " toCut = " << totalCut.Print() << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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
 sprintf(toCut,"%s < %f && %s >= %f",NameVarX,MinCutValueX,NameVarY,MinCutValueY);
 totalCut = extCut + toCut;
 std::cerr << " toCut = " << totalCut.Print() << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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
 sprintf(toCut,"%s >= %f && %s >= %f",NameVarX,MinCutValueX,NameVarY,MinCutValueY);
 totalCut = extCut + toCut;
 std::cerr << " toCut = " << totalCut.Print() << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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
 sprintf(toCut,"%s >= %f && %s < %f",NameVarX,MinCutValueX,NameVarY,MinCutValueY);
 totalCut = extCut + toCut;
 std::cerr << " toCut = " << totalCut.Print() << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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
 totalCut = extCut + toCut;
 std::cerr << " toCut = " << totalCut.Print() << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,totalCut,"");
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


 double nA = htemp_A_2D->Integral();
 double nB = htemp_B_2D->Integral();
 double nC = htemp_C_2D->Integral();
 double nD = htemp_D_2D->Integral();
 
 std::cerr << std::endl;
 std::cerr << "  A   |   B   " << std::endl;
 std::cerr << " ------------ " << std::endl;
 std::cerr << "  D   |   C   " << std::endl;
 std::cerr << std::endl;
 
 std::cerr << " A = " << nA << std::endl;
 std::cerr << " B = " << nB << std::endl;
 std::cerr << " C = " << nC << std::endl;
 std::cerr << " D = " << nD << std::endl;
 
 std::cerr << "========================================================" << std::endl;
 std:cerr << " weights[iSampleSel] = " << weights[iSampleSel] << std::endl;
 std::cerr << " lumi available = " << 1. / weights[iSampleSel] << std::endl;
 
 std::cerr << std::endl;
 
 std::cerr << " A/B = " << nA / nB << " +/- " << sqrt((nA * nB + nA * nA) / (nB * nB * nB)) << std::endl;
 std::cerr << " D/C = " << nD / nC << " +/- " << sqrt((nD * nC + nD * nD) / (nC * nC * nC)) << std::endl;
 
 
 
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
 
 
 
 ///=====================
 ///==== Draw legend ====
 
 TCanvas* cLegend = new TCanvas("cLegend","cLegend",600,800);
 TLegend* newleg = leg->Clone();
 newleg->SetTextSize(0.02);
 newleg->SetFillColor(0);
 newleg->SetX1(0);
 newleg->SetX2(1);
 newleg->SetY1(0);
 newleg->SetY2(1);
 newleg->Draw();
 
}



