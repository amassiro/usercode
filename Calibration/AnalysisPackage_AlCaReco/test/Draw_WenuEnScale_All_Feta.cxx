{
 int nMom = 2;
 
 int iFBREM = 10;
 
//  char WHAT[1000] = "";
 char WHAT[1000] = "ESC_";
 
 // char VARIABLE[1000] = {"E5x5DIVESC"};
 // int nFBREM = 11;
 // double VALUE_MIN[100] = {0.70,0.75,0.80,0.85,0.90,0.95,0.95,0.96,0.97,0.98,0.99};
 // double VALUE_MAX[100] = {0.75,0.80,0.85,0.90,0.95,1.00,0.96,0.97,0.98,0.99,1.00};
 // double RANGE_MAX[100] = {2.20,2.00,1.80,1.60,1.40,1.20,1.20,1.20,1.20,1.20,1.20};
 
 
 
 char VARIABLE[1000] = {"eleFBrem"};
//  int nFBREM = 10;
 int nFBREM = 13;
 double VALUE_MIN[100] = {0.00,0.10,0.20,0.30,0.40,0.50,0.60,0.70,0.80,0.90,0.00,0.00,0.50};
 double VALUE_MAX[100] = {0.10,0.20,0.30,0.40,0.50,0.60,0.70,0.80,0.90,1.00,1.00,0.50,0.10};
 
 
 int NUM = 3;
 double VALUE_ETA_MIN[100] = {0.000,0.435,0.783,1.131};
 double VALUE_ETA_MAX[100] = {0.435,0.783,1.131,1.479};
    
 char* MOMENTUM[1000] = {"pOut","pIn"};
 
 
 std::string NAME_TEST = "grLL";

 //  std::string NAME_TEST = "Graph;1"; //-> KS
 //   std::string NAME_TEST = "Graph;2"; //-> Chi2
 
 ///==== EE ====
// double MIN = -0.12;
// double MAX = 0.08;
// int BIN = 120;
 
 ///==== EE- ====
 //== E5x5/ESC ==
 //  double MinScanRange[100] = {-0.08,-0.12,-0.10,-0.11,-0.11,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06};
 //  double MaxScanRange[100] = { 0.04, 0.04, 0.04, 0.03, 0.08, 0.03, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02};
//  double MinScanRange[100] = {-0.12,-0.11,-0.11,-0.11,-0.12,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06};
//  double MaxScanRange[100] = { 0.06, 0.04, 0.04, 0.03, 0.08, 0.03, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02};
 //== fbrem ==
//   double MinScanRange[100] = {-0.08,-0.08,-0.07,-0.10,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06};
//   double MaxScanRange[100] = { 0.04, 0.04, 0.04, 0.03, 0.03, 0.03, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02};
 
 ///==== EE+ ====
 //== E5x5/ESC ==
//   double MinScanRange[100] = {-0.11,-0.11,-0.11,-0.10,-0.11,-0.12,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06};
 //  double MaxScanRange[100] = { 0.04, 0.04, 0.04, 0.06, 0.06, 0.04, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02};
 //== fbrem ==
//  double MinScanRange[100] = {-0.10,-0.10,-0.10,-0.10,-0.11,-0.12,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06,-0.06};
//  double MaxScanRange[100] = { 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02};
 
 ///==== EB ====
  double MIN = -0.1;
  double MAX = 0.05;
  int BIN = 200;
 //== fbrem ==
  double MinScanRange[100] = { -0.03, -0.03, -0.04, -0.04, -0.11, -0.12, -0.06, -0.06, -0.06, -0.06, -0.06, -0.06, -0.06, -0.06, -0.06};
  double MaxScanRange[100] = { 0.02, 0.012, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02};
  
 ///=========================================================================
 
 
 EColor vColor[100] = {
  kBlue,
  kRed,
  kBlue,(EColor)(kBlue+1),(EColor) (kBlue+2),
  kRed,(EColor) (kRed+1),(EColor) (kRed+2),
  kGreen,(EColor) (kGreen+1),(EColor) (kGreen+2),
  kTeal,(EColor) (kTeal+1),
  kOrange,(EColor) (kOrange+1),
  kMagenta,(EColor) (kMagenta+1),(EColor) (kViolet),(EColor) (kYellow),(EColor) (kGray)};
  
 
 ///==== pIn and pOut ====
 TCanvas* ResultPlot[100];
 TCanvas* ResultPlotBest[100];
 TCanvas* Result[100];
 
 TGraphErrors* grResult[100];
 
 for (int iMom=0; iMom<nMom; iMom++){
  
  TString nameResultPlot = Form("ResultPlot_%s",MOMENTUM[iMom]);
  ResultPlot[iMom] = new TCanvas (nameResultPlot,nameResultPlot,800,800) ;
  ResultPlot[iMom]->Divide(sqrt(NUM)+1,sqrt(NUM)+1);
  
  TString nameResultPlotBest = Form("ResultPlotBest_%s",MOMENTUM[iMom]);
  ResultPlotBest[iMom] = new TCanvas (nameResultPlotBest,nameResultPlotBest,800,800) ;
  ResultPlotBest[iMom]->Divide(sqrt(NUM)+1,sqrt(NUM)+1);
  
  TString nameResult = Form("Result_%s",MOMENTUM[iMom]);  
  Result[iMom] = new TCanvas (nameResult,nameResult,800,800) ;
  grResult[iMom] = new TGraphErrors();
  grResult[iMom] -> SetName(MOMENTUM[iMom]);
  
  
  int iPoint = -1;
  
  
  for (int iNUM = 0; iNUM < NUM; iNUM++){
   std::cerr << " iNUM = " << iNUM << " : " << NUM << std::endl;
   
   std::ostringstream ostr_NameFile;
   ostr_NameFile << "out_" << WHAT << "WenuEnScale_EoP_eta_" << VALUE_ETA_MIN[iNUM] << "_" << VALUE_ETA_MAX[iNUM] << "_" << VARIABLE << "_" << VALUE_MIN[iFBREM] << "_" << VALUE_MAX[iFBREM] << "_" << MOMENTUM[iMom] << ".root";
   
   TString nameFile = Form("temp_EoP_10pb/%s",ostr_NameFile.str().c_str());
   std::cerr << " File = " << nameFile.Data() << std::endl;
   TFile* file = TFile::Open(nameFile.Data());
   TGraph* grLL = (TGraph*) file->Get(NAME_TEST.c_str());
   ResultPlot[iMom]->cd(iNUM+1);
   TF1* fitMinLL = new TF1("fitMinLL","pol2");
   fitMinLL->SetRange(MinScanRange[iNUM],MaxScanRange[iNUM]);
   TFitResultPtr r = grLL->Fit("fitMinLL","RMQ");
   Int_t fitStatus = r;
   grLL->Draw("APL");
   grLL->SetMarkerStyle(20);
   grLL->SetMarkerColor(kRed);
   gPad->SetGrid();
   
   std::cerr << " fitStatus = " << fitStatus << std::endl;
   if (fitStatus==4000){
    
    double ScaleTrue = -1000; ///==== default
    int Data_or_MC = 1; ///=== 1 = Data;  0 = MC; -1 = MC Fit
    int nIter = 1000000000; ///==== less than 1000000000 iterations at the end !!!
    TString nameDATA = Form("hDATA_%d_%d_%.5f",Data_or_MC,nIter,ScaleTrue);
    
    TH1F* hDATA = (TH1F*) file->Get(nameDATA.Data());
    if (hDATA->GetEntries()<20) continue;
    
    double c = fitMinLL->GetParameter(0);
    double b = fitMinLL->GetParameter(1);
    double a = fitMinLL->GetParameter(2);
    
    if (a<0) continue;
    
    if (grLL->GetN()<20) continue;
    
    std::cerr << "alpha = " << -b / (2*a) << " +/-" << 1./sqrt(2*a) << std::endl; 
    iPoint++;
    
    grResult[iMom]->SetPoint(iPoint,(VALUE_ETA_MIN[iNUM]+VALUE_ETA_MAX[iNUM])/2.,-b/(2*a));
    
    if (NAME_TEST=="Graph;2") grResult[iMom]->SetPointError(iPoint,(VALUE_ETA_MAX[iNUM]-VALUE_ETA_MIN[iNUM])/2.,1/sqrt(a));
    else grResult[iMom]->SetPointError(iPoint,(VALUE_ETA_MAX[iNUM]-VALUE_ETA_MIN[iNUM])/2.,1/sqrt(2*a));
    
    
    ResultPlotBest[iMom]->cd(iNUM+1);
    
    
    double binSel = ((MAX - MIN) / (BIN-2)) * static_cast<int>((-b/(2*a) - MIN) / ((MAX - MIN) / (BIN-2)) ) + MIN;
    
    TString NameMC_LL = Form("hMC_Chi2_%.5f",binSel);
    std::cerr << " NameMC_LL = " << NameMC_LL.Data() << " MAX = " << MAX << " MIN = " << MIN << " BIN = " << BIN << " ((MAX - MIN) / (BIN-2)) = " << ((MAX - MIN) / (BIN-2)) << std::endl;
    TH1F* hMC_LL = (TH1F*) file->Get(NameMC_LL.Data());
    if (hMC_LL == 0x0) continue;
    hMC_LL->SetLineWidth(1);
    hMC_LL->SetLineColor(kRed);
    hMC_LL->SetFillColor(kRed);
    hMC_LL->SetFillStyle(3001);
    
    hDATA->Draw("E1");
    hMC_LL->Draw("BARsame");
    hDATA->Draw("E1same");
   }
   
  }
  Result[iMom]->cd();
  grResult[iMom]->Draw("AP");
  //  grResult->GetXaxis()->SetTitle("E5x5 / E_{SC}");
  grResult[iMom]->GetXaxis()->SetTitle("#eta");
  grResult[iMom]->GetYaxis()->SetTitle("#alpha");
  grResult[iMom]->SetMarkerStyle(20);
  grResult[iMom]->SetMarkerSize(2);
  grResult[iMom]->SetMarkerColor(vColor[iMom]);
  grResult[iMom]->SetFillColor(vColor[iMom]);
  grResult[iMom]->SetLineWidth(2);
  grResult[iMom]->SetLineColor(vColor[iMom]);
  gPad->SetGrid();
  
 }
 
 ///==== Draw ====
 
 TCanvas* cAll = new TCanvas("cAll","cAll",800,800);
 TMultiGraph* mg = new TMultiGraph();
 mg->SetTitle("#alpha");
 
 
 for (int iMom=0; iMom<2; iMom++){
  mg->Add(grResult[iMom],"lp");
  
 }
 mg->Draw("a");
 mg->GetXaxis()->SetTitle("#eta");
 mg->GetYaxis()->SetTitle("#alpha");
 gPad->BuildLegend();
 gPad->SetGrid();
 
 
 }
 
 
 