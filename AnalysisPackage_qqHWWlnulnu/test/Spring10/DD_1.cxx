void DD_1( TString nameSampleIN = "" , double MinCutValue){
 
 int BinX = 100;
 double MaxX = 5;
 double MinX = -5;
 
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
 
 
 
 char NameVar[1000] = {
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
 char nameStack[100];
 sprintf(nameStack,"stack_%s",NameVar); 
 THStack* hs = new THStack(nameStack,nameStack);
 
 TH1F *histos[100000];
 
 for (int iSample = 0 ; iSample < totalSamples; iSample++){
//  for (int iSample = (totalSamples-1); iSample>= 0; iSample--){
  histos[iSample] = new TH1F(nameSample[iSample],nameSample[iSample],BinX,MinX,MaxX);
  
  char toDraw[1000];
  sprintf(toDraw,"%s >> %s",NameVar,nameSample[iSample]);
  std::cerr << " toDraw = " << toDraw << std::endl;
  char toCut[1000];
  sprintf(toCut,"");
  signal_background[iSample]->Draw(toDraw,toCut,"");
//   sprintf(toDraw,"%s >> %s",WhatToPlot.Data(),nameSample[iSample]); 
  histos[iSample]->Scale(weights[iSample]);
  histos[iSample]->SetMarkerColor(kOrange - 5 + iSample * 3);
  histos[iSample]->SetLineColor(kOrange - 5 + iSample * 3);
  histos[iSample]->SetFillColor(kOrange - 5 + iSample * 3);
  histos[iSample]->SetLineWidth(1);
  histos[iSample]->SetFillStyle(3001);
//   histos[iSample]->SetFillStyle(0);
  hs->Add(histos[iSample]);
 }
 
 
 ///================================================================================================
 
 

 TCanvas* cc = new TCanvas("cc","cc",800,800);
 cc->Divide(2,2);
 
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
 hs->Draw();
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 cc->cd(2);
 
 char toDraw[1000];
 sprintf(toDraw,"%s",NameVar);
 std::cerr << " toDraw = " << toDraw << std::endl;
 char toCut[1000];
 sprintf(toCut,"");
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 gPad->SetGrid();
 TH1F *htempTotal = ((TH1F*)gPad->GetPrimitive("htemp"))->Clone();
 htempTotal->SetName("htempTotal");
 TH1F *htempLeft = ((TH1F*)gPad->GetPrimitive("htemp"))->Clone();
 htempLeft->SetName("htempLeft");
 TH1F *htempRight = ((TH1F*)gPad->GetPrimitive("htemp"))->Clone();
 htempRight->SetName("htempRight");
 htempTotal->Scale(weights[iSampleSel]);
 htempTotal->Draw();
 
 
 cc->cd(3);
 sprintf(toDraw,"%s >> htempLeft",NameVar);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s < %f",NameVar,MinCutValue);
 std::cerr << " toCut = " << toCut << std::endl;
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 htempLeft->Scale(weights[iSampleSel]);
 htempLeft->SetLineColor(kGreen);
 htempLeft->SetMarkerColor(kGreen);
 htempLeft->SetFillColor(kGreen);
 htempLeft->SetFillStyle(3001);
 htempLeft->SetLineWidth(1.);
 htempLeft->SetMarkerStyle(20);
 htempLeft->SetMarkerSize(0.1);
 
 
 sprintf(toDraw,"%s >> htempRight",NameVar);
 std::cerr << " toDraw = " << toDraw << std::endl;
 sprintf(toCut,"%s >= %f",NameVar,MinCutValue);
 signal_background[iSampleSel]->Draw(toDraw,toCut,"");
 std::cerr << " toCut = " << toCut << std::endl;
 htempRight->Scale(weights[iSampleSel]);
 htempRight->SetLineColor(kBlue);
 htempRight->SetMarkerColor(kBlue);
 htempRight->SetFillColor(kBlue);
 htempRight->SetFillStyle(3001);
 htempRight->SetLineWidth(1.);
 htempRight->SetMarkerStyle(20);
 htempRight->SetMarkerSize(0.1);
 
 htempLeft->Draw();
 htempRight->Draw("same");
 gPad->SetGrid();
 
 
 std:cerr << " MinCutValue = " << MinCutValue << std::endl;
 
 
 
 
 
//  htempTotal->Smooth(1);
//  htempLeft->Smooth(1);
//  htempRight->Smooth(1);
 
 
 std::cerr << " Less than Cut = " << htempLeft->Integral() << std::endl;
 std::cerr << " More than Cut = " << htempRight->Integral() << std::endl;
 std::cerr << "               = " << htempTotal->Integral() << std::endl;
 
 std::cerr << "      Fraction = " << htempRight->Integral() / htempLeft->Integral() << std::endl;
 
 double CorrectionCoefficient = htempRight->Integral() / htempLeft->Integral();
 
 
 ///==============================================================================
 
 
 int nLumi = 15;
 int nTest = 1000;
 double deltaLumi = 10;
 
 TCanvas* ccLumi = new TCanvas("ccLumi","ccLumi",800,800);
 ccLumi->Divide(sqrt(nLumi)+1,sqrt(nLumi)+1);

 TH1F* hRatio[1000];

 int* nLeft = new int [nLumi];
 int* nRight = new int [nLumi];
 double* xLumi = new double [nLumi];
 double* yRatio = new double [nLumi];
 double* errxLumi = new double [nLumi];
 double* erryRatio = new double [nLumi];
 
 for (int iLumi = 0; iLumi < nLumi; iLumi++){
  ccLumi->cd(iLumi+1);
  char nameHisto[1000];
  sprintf(nameHisto,"Histo_%d",iLumi);
  int numBins = (weights[iSampleSel] * (iLumi+1) * deltaLumi * htempTotal->GetEntries()) / 10;
  if (500 > numBins) numBins = 500;
  hRatio[iLumi] = new TH1F(nameHisto,nameHisto,numBins,0,CorrectionCoefficient * 3);
  nLeft[iLumi] = 0;
  nRight[iLumi] = 0;  
  double numLumi = pow(2,iLumi+1);// (iLumi+1) * deltaLumi;
  int numEvents = (weights[iSampleSel] * numLumi * htempTotal->GetEntries());
  for (int iTest = 0; iTest < nTest; iTest++){
   yRatio[iLumi] = 0;
   for (int iEvt = 0; iEvt < (numEvents); iEvt++){
    double varTemp = htempTotal->GetRandom();  
    //    std:cerr << "varTemp = " << varTemp << std::endl;
    if (varTemp < MinCutValue) {
     nLeft[iLumi] ++;
    }
    else {
     nRight[iLumi] ++;
    }
   }
   if (nLeft[iLumi] != 0) {
    yRatio[iLumi] = static_cast<double>(nRight[iLumi]) / static_cast<double>(nLeft[iLumi]);
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
  if (!(iLumi%10)){
   std::cerr << "yRatio[" << iLumi << "] = " << yRatio[iLumi] << " +/-" << erryRatio[iLumi] << " : " << xLumi[iLumi] << std::endl;
  }
  hRatio[iLumi]->SetLineColor(kYellow+iLumi);
  hRatio[iLumi]->SetFillColor(kYellow+iLumi);
  hRatio[iLumi]->SetFillStyle(3001);
  hRatio[iLumi]->SetLineWidth(1.);
  hRatio[iLumi]->Draw();
 }
 
 TGraphErrors* grRatioVsLumi = new TGraphErrors(nLumi,xLumi,yRatio,errxLumi,erryRatio);
 cc->cd(4);
 grRatioVsLumi->SetLineColor(kBlue);
 grRatioVsLumi->SetMarkerColor(kBlue);
 grRatioVsLumi->SetFillColor(kBlue);
 grRatioVsLumi->SetFillStyle(3001);
 grRatioVsLumi->SetLineWidth(1.);
 grRatioVsLumi->SetMarkerStyle(20);
 grRatioVsLumi->SetMarkerSize(0.5);
 grRatioVsLumi->Draw("AP");
 gPad->SetGrid();
 
 TLine* lOriz = new TLine(0,CorrectionCoefficient,xLumi[nLumi-1],CorrectionCoefficient);
 lOriz->SetLineColor(kRed);
 lOriz->SetLineWidth(4);
 lOriz->SetLineStyle(5);
 lOriz->Draw();
 
 
 
}