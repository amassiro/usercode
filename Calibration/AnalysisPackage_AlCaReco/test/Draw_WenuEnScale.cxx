{

 int NUM = 1;
 char NAME = {"EoP_EB_mod1"};
 char* VAR = {"fbrem0203"};

 double MIN = -0.2;
 double MAX = 0.2;
 int BIN = 200;
//  double MinScanRange = -0.04;
//  double MaxScanRange = 0.01;

 double MinScanRange = -0.1;
 double MaxScanRange = 0.04;
 
 TCanvas* ResultPlot = new TCanvas ("ResultPlot","ResultPlot",800,800) ;
 ResultPlot.Divide(sqrt(NUM),sqrt(NUM)+1);

 TCanvas* Result = new TCanvas ("Result","Result",800,800) ;

 for (int iNUM = 0; iNUM < NUM; iNUM++){
  TString nameFile = Form("output/out_WenuEnScale_%s_%s.root",NAME,VAR[iNUM]);
  std::cerr << " File = " << nameFile.Data() << std::endl;
  TFile* file = TFile::Open(nameFile.Data());
  TGraph* grLL = (TGraph*) file->Get("grLL");
  ResultPlot.cd(iNUM+1);
  TF1* fitMinLL = new TF1("fitMinLL","pol2");
  fitMinLL->SetRange(MinScanRange,MaxScanRange);
  grLL->Fit("fitMinLL","RMQ");
  grLL->Draw("APL");
  gPad->SetGrid();

  double c = fitMinLL->GetParameter(0);
  double b = fitMinLL->GetParameter(1);
  double a = fitMinLL->GetParameter(2);
  std::cerr << "alpha = " << -b / (2*a) << " +/-" << 1./sqrt(2*a) << std::endl; 
 
 }


///==== Plot LL ====

 TCanvas* cLL_1;
 TCanvas* cLL_2;
 TCanvas* cLL_3;
if (PLOT){
 cLL_1 = new TCanvas("cLL_1","cLL_1",800,800);
 cLL_2 = new TCanvas("cLL_2","cLL_2",800,800);
 cLL_3 = new TCanvas("cLL_3","cLL_3",800,800);
 }

 TF1* fitMinLL = new TF1("fitMinLL","pol2");
 fitMinLL->SetRange(MinScanRange,MaxScanRange);
 grLL->Fit("fitMinLL","RMQ");
//  std::cerr << " alpha LL = " << -fitMinLL->GetParameter(1) / 2. / fitMinLL->GetParameter(2) << std::endl;


 TCanvas cLL("cLL","cLL",1200,1200);
 cLL.Divide(2,2);
 
 cLL.cd(1);
 hLL->SetTitle("LogLikelihood: - LL");
 hLL->GetYaxis()->SetTitle("- LL");
 hLL->GetXaxis()->SetTitle("#alpha");
//  hLL->Draw("colz");
  
 if (PLOT){
  cLL_1->cd();
//  hLL->Draw("colz");
//  grLL->Draw("P");
 grLL->Draw("ALP");
 gPad->SetGrid();
 }
 
 cLL.cd(3);
 hLL_Min_Fit->SetTitle("LL test: toy experiments");
 hLL_Min_Fit->GetXaxis()->SetTitle("#alpha");
 hLL_Min_Fit->Draw();
 gPad->SetGrid();
 fitGaus->SetParameter(0,hLL_Min_Fit->GetEntries());
 fitGaus->SetParameter(1,hLL_Min_Fit->GetMean());
 fitGaus->SetParameter(2,hLL_Min_Fit->GetRMS());
 hLL_Min_Fit->Fit("fitGaus","RMQ"); 

 if (PLOT){
  cLL_2->cd();
  hLL_Min_Fit->Draw();
  gPad->SetGrid();
  hLL_Min_Fit->Fit("fitGaus","RMQ"); 
 }
 
 cLL.cd(2);
 TString NameMC_LL = Form("hMC_Chi2_%.5f",AlphaMean_LL);
 TH1F* hMC_LL = (TH1F*) _file0->Get(NameMC_LL.Data());
 hMC_LL->SetLineWidth(1);
 hMC_LL->SetLineColor(kRed);
 hMC_LL->SetFillColor(kRed);
 hMC_LL->SetFillStyle(3001);

 hDATA->Draw("E1");
 hMC_LL->Draw("BARsame");
 hDATA->Draw("E1same");
 TString Result_LL = Form("#alpha = %.4f #pm %.4f",AlphaMean_LL_Fit,hLL_Min_Fit->GetRMS());
//  TString Result_LL = Form("#alpha = %.4f #pm %.4f",AlphaMean_LL_Fit,fitGaus->GetParameter(2));
 TLatex lResult_LL(hDATA->GetMean(),9,Result_LL);
 lResult_LL->Draw();

 if (PLOT){
  cLL_3->cd();
  hDATA->Draw("E1");
  hMC_LL->Draw("BARsame");
  hDATA->Draw("E1same");
  lResult_LL->Draw();
 }
 
 
}



