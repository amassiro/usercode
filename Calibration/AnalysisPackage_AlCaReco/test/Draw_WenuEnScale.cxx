{

 int NUM = 8;
 std::string NAME = "EoP_EB_mod1";
//  std::string NAME = "EoP_EEPlus_ES";
//  std::string NAME = "EoP_EEMinus_ES";
 
//   char* VAR[100] = {"fbrem0002","fbrem0204","fbrem0406","fbrem0608"};
//   double VALUE[100] = {0.1,0.3,0.5,0.7};
//   double ERR[100] = {0.1,0.1,0.1,0.1};
 
 char* VAR[100] = {"fbrem0001","fbrem0102","fbrem0203","fbrem0304","fbrem0405","fbrem0506","fbrem0607","fbrem0708"};
 double VALUE[100] = {0.05,0.15,0.25,0.35,0.45,0.55,0.65,0.75};
 double ERR[100] = {0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05};

//  char* VAR[100] = {"fbrem000001","fbrem000002","fbrem000003","fbrem000004","fbrem000005","fbrem000006","fbrem000007","fbrem000008","fbrem000009","fbrem000010","fbrem000011","fbrem000012","fbrem000013","fbrem000014","fbrem000015","fbrem000016","fbrem000017","fbrem000018","fbrem000019","fbrem000020","fbrem000021","fbrem000022","fbrem000023","fbrem000024","fbrem000025","fbrem000026","fbrem000027","fbrem000028","fbrem000029","fbrem000030"};
//  double VALUE[100] = {0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.10,0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18,0.19,0.20,0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.29,0.30};
//  double ERR[100] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
//  double MinScanRange[100] = {-0.04,-0.08,-0.08,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04,-0.04};
//  double MaxScanRange[100] = { 0.02, 0.02, 0.03,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02};
//  
 
std::string NAME_TEST = "grLL";
//  std::string NAME_TEST = "Graph;1"; //-> KS
//   std::string NAME_TEST = "Graph;2"; //-> Chi2

///==== EE ====
//  double MIN = -0.12;
//  double MAX = 0.08;
//  int BIN = 120;
 double MinScanRange[100] = {-0.10,-0.08,-0.08,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10,-0.10};
 double MaxScanRange[100] = { 0.041, 0.041, 0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041,0.041};
 
///==== EB ====
 double MIN = -0.1;
 double MAX = 0.05;
 int BIN = 200;


//  double MinScanRange = -0.04;
//  double MaxScanRange = 0.01;

// //  double MinScanRange[100] = {-0.05,-0.1,-0.1,-0.1,-0.1,-0.1,-0.1};
//  double MaxScanRange[100] = {0.02,0.04,0.04,0.04,0.04,0.04,0.05};
 
//  double MinScanRange[100] = {-0.05,-0.1,-0.1,-0.1,-0.1,-0.1,-0.1};
//  double MaxScanRange[100] = {0.02,0.04,0.04,0.04,0.04,0.04,0.05};
 
//  double MinScanRange[100] = {-0.03,-0.03,-0.08,-0.1,-0.1,-0.1,-0.1};
//  double MaxScanRange[100] = { 0.01, 0.02, 0.00,0.04,0.04,0.04,0.05};
 
 ///=========================================================================
 
 
 
 
 
 TCanvas* ResultPlot = new TCanvas ("ResultPlot","ResultPlot",800,800) ;
 ResultPlot.Divide(sqrt(NUM)+1,sqrt(NUM)+1);

 TCanvas* ResultPlotBest = new TCanvas ("ResultPlotBest","ResultPlotBest",800,800) ;
 ResultPlotBest.Divide(sqrt(NUM)+1,sqrt(NUM)+1);
 
 TCanvas* Result = new TCanvas ("Result","Result",800,800) ;
 TGraphErrors* grResult = new TGraphErrors();
 int iPoint = -1;
 for (int iNUM = 0; iNUM < NUM; iNUM++){
  std::cerr << " iNUM = " << iNUM << " : " << NUM << std::endl;
  std::cerr << " NAME = " << NAME.c_str() << " VAR[" << iNUM << "] = " << VAR[iNUM] << std::endl;
  TString nameFile = Form("temp/out_WenuEnScale_%s_%s.root",NAME.c_str(),VAR[iNUM]);
  std::cerr << " File = " << nameFile.Data() << std::endl;
  TFile* file = TFile::Open(nameFile.Data());
  TGraph* grLL = (TGraph*) file->Get(NAME_TEST.c_str());
  ResultPlot.cd(iNUM+1);
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
   
   grResult->SetPoint(iPoint,VALUE[iNUM],-b/(2*a));
  
   if (NAME_TEST=="Graph;2") grResult->SetPointError(iPoint,ERR[iNUM],1/sqrt(a));
   else grResult->SetPointError(iPoint,ERR[iNUM],1/sqrt(2*a));
   
   
   
   ResultPlotBest->cd(iNUM+1);
   
    
   double binSel = ((MAX - MIN) / (BIN-2)) * static_cast<int>((-b/(2*a) - MIN) / ((MAX - MIN) / (BIN-2)) ) + MIN;
   
   TString NameMC_LL = Form("hMC_Chi2_%.5f",binSel);
   std::cerr << " NameMC_LL = " << NameMC_LL.Data() << std::endl;
   TH1F* hMC_LL = (TH1F*) file->Get(NameMC_LL.Data());
   hMC_LL->SetLineWidth(1);
   hMC_LL->SetLineColor(kRed);
   hMC_LL->SetFillColor(kRed);
   hMC_LL->SetFillStyle(3001);
   
   hDATA->Draw("E1");
   hMC_LL->Draw("BARsame");
   hDATA->Draw("E1same");
  }
  
 }

 Result.cd();
 grResult->Draw("AP");
 grResult->GetXaxis()->SetTitle("f_{brem}");
 grResult->GetYaxis()->SetTitle("#alpha");
 grResult->SetMarkerStyle(20);
 grResult->SetMarkerSize(2);
 grResult->SetMarkerColor(kRed);
 grResult->SetLineWidth(2);
 grResult->SetLineColor(kRed);
 gPad->SetGrid();
 
 
 
}



