{
	
 
 double MIN = -0.2;
 double MAX = 0.2;
 int BIN = 200;
 //  double MinScanRange = -0.04;
 //  double MaxScanRange = 0.01;
 
 double MinScanRange = -0.06;
 double MaxScanRange = 0.04; 
 
 TF1* fitGaus = new TF1("fitGaus","gaus");
 fitGaus->SetRange(-0.1,0.03);

 TTree* myTreeChi2 = (TTree*) _file0->Get("myTreeChi2");
 
 ///==== DATA
 TH2F* hChi2 = new TH2F ("hChi2","hChi2",BIN,MIN,MAX,1000,-2,2);
 myTreeChi2->Draw("Chi2:Alpha >> hChi2","Data_or_MC==1");
 
 TH2F* hNewChi2 = new TH2F ("hNewChi2","hNewChi2",BIN,MIN,MAX,1000,0,200);
 myTreeChi2->Draw("NewChi2:Alpha >> hNewChi2","Data_or_MC==1");
 
 TH2F* hLL = new TH2F ("hLL","hLL",BIN,MIN,MAX,1000,-200,0);
 myTreeChi2->Draw("LL:Alpha >> hLL","Data_or_MC==1");
 
 ///==== MC
 TH2F* hChi2_MC = new TH2F ("hChi2_MC","hChi2_MC",BIN,MIN,MAX,1000,-2,2);
 myTreeChi2->Draw("Chi2:Alpha >> hChi2_MC","Data_or_MC==0");
 
 TH2F* hNewChi2_MC = new TH2F ("hNewChi2_MC","hNewChi2_MC",BIN,MIN,MAX,1000,0,200);
 myTreeChi2->Draw("NewChi2:Alpha >> hNewChi2_MC","Data_or_MC==0");
 
 TH2F* hLL_MC = new TH2F ("hLL_MC","hLL_MC",BIN,MIN,MAX,1000,-200,0);
 myTreeChi2->Draw("LL:Alpha >> hLL_MC","Data_or_MC==0");

 ///==== MC FIT
 TH2F* hChi2_MC_Fit = new TH2F ("hChi2_MC_Fit","hChi2_MC_Fit",BIN,MIN,MAX,1000,-2,2);
 myTreeChi2->Draw("Chi2:Alpha >> hChi2_MC_Fit","Data_or_MC==-1");
 
 TH2F* hNewChi2_MC_Fit = new TH2F ("hNewChi2_MC_Fit","hNewChi2_MC_Fit",BIN,MIN,MAX,1000,0,200);
 myTreeChi2->Draw("NewChi2:Alpha >> hNewChi2_MC_Fit","Data_or_MC==-1");
 
 TH2F* hLL_MC_Fit = new TH2F ("hLL_MC_Fit","hLL_MC_Fit",BIN,MIN,MAX,1000,-200,0);
 myTreeChi2->Draw("LL:Alpha >> hLL_MC_Fit","Data_or_MC==-1");


 double AlphaPlus_Chi2; 
 double AlphaMinus_Chi2; 
 double AlphaPlus_LL; 
 double AlphaMinus_LL; 
 double AlphaPlus_NewChi2; 
 double AlphaMinus_NewChi2; 

 double AlphaPlus_Chi2_Fit; 
 double AlphaMinus_Chi2_Fit; 
 double AlphaPlus_LL_Fit; 
 double AlphaMinus_LL_Fit; 
 double AlphaPlus_NewChi2_Fit; 
 double AlphaMinus_NewChi2_Fit; 


 double AlphaMean_Chi2;
 double AlphaMean_Chi2_Fit; 
 double AlphaMean_NewChi2;
 double AlphaMean_NewChi2_Fit; 
 double AlphaMean_LL;
 double AlphaMean_LL_Fit; 


 double AlphaPlus;
 double AlphaMinus;
 double AlphaMean;
 double AlphaPlus_Fit;
 double AlphaMinus_Fit;
 double AlphaMean_Fit;
 int Data_or_MC;
 
 ///==== CHI2 ====
 TH1F* hChi2_Min = new TH1F ("hChi2_Min","hChi2_Min",BIN,MIN,MAX);
 TH1F* hChi2_Min_Fit = new TH1F ("hChi2_Min_Fit","hChi2_Min_Fit",BIN,MIN,MAX);
 TTree* myTreeChi2_Result = (TTree*) _file0->Get("myTreeChi2_Result");
 myTreeChi2_Result->SetBranchAddress("AlphaMinus",&AlphaMinus);
 myTreeChi2_Result->SetBranchAddress("AlphaPlus",&AlphaPlus);
 myTreeChi2_Result->SetBranchAddress("AlphaMean",&AlphaMean);
 myTreeChi2_Result->SetBranchAddress("AlphaMinus_Fit",&AlphaMinus_Fit);
 myTreeChi2_Result->SetBranchAddress("AlphaPlus_Fit",&AlphaPlus_Fit);
 myTreeChi2_Result->SetBranchAddress("AlphaMean_Fit",&AlphaMean_Fit);
 myTreeChi2_Result->SetBranchAddress("Data_or_MC",&Data_or_MC);
 for (int iEntry = 0; myTreeChi2_Result->GetEntries(); iEntry++){
	 myTreeChi2_Result->GetEntry(iEntry);
	 if (Data_or_MC == 1) {
		 std::cerr << " AlphaMean = " << AlphaMean << "     AlphaMean_Fit = " << AlphaMean_Fit << std::endl;
		 TString Title = Form("Chi2 %f",AlphaMean);
		 hChi2_Min->SetTitle(Title.Data());
		 TString Title_Fit = Form("Chi2 %f",AlphaMean_Fit);
		 hChi2_Min_Fit->SetTitle(Title_Fit.Data());
                 AlphaMean_Chi2 = AlphaMean;
 		 AlphaMean_Chi2_Fit = AlphaMean_Fit; 
                 AlphaMinus_Chi2 = AlphaMinus;
                 AlphaPlus_Chi2 = AlphaPlus;
                 AlphaMinus_Chi2_Fit = AlphaMinus_Fit;
                 AlphaPlus_Chi2_Fit = AlphaPlus_Fit;
		 break;
	  }
	 }
 myTreeChi2_Result->Draw("AlphaMean >> hChi2_Min","Data_or_MC==0");
 hChi2_Min->SetFillColor(kRed);
 hChi2_Min->SetFillStyle(3001);

 myTreeChi2_Result->Draw("AlphaMean_Fit >> hChi2_Min_Fit","Data_or_MC==-1");
 hChi2_Min_Fit->SetFillColor(kRed);
 hChi2_Min_Fit->SetFillStyle(3001);


 ///==== NewChi2 ====
 TH1F* hNewChi2_Min = new TH1F ("hNewChi2_Min","hNewChi2_Min",BIN,MIN,MAX);
 TH1F* hNewChi2_Min_Fit = new TH1F ("hNewChi2_Min_Fit","hNewChi2_Min_Fit",BIN,MIN,MAX);
 TTree* myTreeNewChi2_Result = (TTree*) _file0->Get("myTreeNewChi2_Result");
 myTreeNewChi2_Result->SetBranchAddress("AlphaMinus",&AlphaMinus);
 myTreeNewChi2_Result->SetBranchAddress("AlphaPlus",&AlphaPlus);
 myTreeNewChi2_Result->SetBranchAddress("AlphaMean",&AlphaMean);
 myTreeNewChi2_Result->SetBranchAddress("AlphaMinus_Fit",&AlphaMinus_Fit);
 myTreeNewChi2_Result->SetBranchAddress("AlphaPlus_Fit",&AlphaPlus_Fit);
 myTreeNewChi2_Result->SetBranchAddress("AlphaMean_Fit",&AlphaMean_Fit);
 myTreeNewChi2_Result->SetBranchAddress("Data_or_MC",&Data_or_MC);
 for (int iEntry = 0; myTreeNewChi2_Result->GetEntries(); iEntry++){
	 myTreeNewChi2_Result->GetEntry(iEntry);
	 if (Data_or_MC == 1) {
		 std::cerr << " AlphaMean = " << AlphaMean << "     AlphaMean_Fit = " << AlphaMean_Fit << std::endl;
		 TString Title = Form("NewChi2 %f",AlphaMean);
		 hNewChi2_Min->SetTitle(Title.Data());
		 TString Title_Fit = Form("NewChi2 %f",AlphaMean_Fit);
		 hNewChi2_Min_Fit->SetTitle(Title_Fit.Data());
                 AlphaMean_NewChi2 = AlphaMean;
 		 AlphaMean_NewChi2_Fit = AlphaMean_Fit; 
                 AlphaMinus_NewChi2 = AlphaMinus;
                 AlphaPlus_NewChi2 = AlphaPlus;
                 AlphaMinus_NewChi2_Fit = AlphaMinus_Fit;
                 AlphaPlus_NewChi2_Fit = AlphaPlus_Fit;
		 break;
	  }
	 }
 myTreeNewChi2_Result->Draw("AlphaMean >> hNewChi2_Min","Data_or_MC==0");
 hNewChi2_Min->SetFillColor(kRed);
 hNewChi2_Min->SetFillStyle(3001);

 myTreeNewChi2_Result->Draw("AlphaMean_Fit >> hNewChi2_Min_Fit","Data_or_MC==-1");
 hNewChi2_Min_Fit->SetFillColor(kRed);
 hNewChi2_Min_Fit->SetFillStyle(3001);

 ///==== LL ====
 TH1F* hLL_Min = new TH1F ("hLL_Min","hLL_Min",BIN,MIN,MAX);
 TH1F* hLL_Min_Fit = new TH1F ("hLL_Min_Fit","hLL_Min_Fit",BIN,MIN,MAX);
 TTree* myTreeLL_Result = (TTree*) _file0->Get("myTreeLL_Result");
 myTreeLL_Result->SetBranchAddress("AlphaMinus",&AlphaMinus);
 myTreeLL_Result->SetBranchAddress("AlphaPlus",&AlphaPlus);
 myTreeLL_Result->SetBranchAddress("AlphaMean",&AlphaMean);
 myTreeLL_Result->SetBranchAddress("AlphaMinus_Fit",&AlphaMinus_Fit);
 myTreeLL_Result->SetBranchAddress("AlphaPlus_Fit",&AlphaPlus_Fit);
 myTreeLL_Result->SetBranchAddress("AlphaMean_Fit",&AlphaMean_Fit);
 myTreeLL_Result->SetBranchAddress("Data_or_MC",&Data_or_MC);
 for (int iEntry = 0; myTreeLL_Result->GetEntries(); iEntry++){
	 myTreeLL_Result->GetEntry(iEntry);
	 if (Data_or_MC == 1) {
		 std::cerr << " AlphaMean = " << AlphaMean << "     AlphaMean_Fit = " << AlphaMean_Fit << std::endl;
		 TString Title = Form("LL %f",AlphaMean);
		 hLL_Min->SetTitle(Title.Data());
		 TString Title_Fit = Form("LL %f",AlphaMean_Fit);
		 hLL_Min_Fit->SetTitle(Title_Fit.Data());
                 AlphaMean_LL = AlphaMean;
 		 AlphaMean_LL_Fit = AlphaMean_Fit; 
                 AlphaMinus_LL = AlphaMinus;
                 AlphaPlus_LL = AlphaPlus;
                 AlphaMinus_LL_Fit = AlphaMinus_Fit;
                 AlphaPlus_LL_Fit = AlphaPlus_Fit;
		 break;
	  }
	 }
 myTreeLL_Result->Draw("AlphaMean >> hLL_Min","Data_or_MC==0");
 hLL_Min->SetFillColor(kRed);
 hLL_Min->SetFillStyle(3001);

 myTreeLL_Result->Draw("AlphaMean_Fit >> hLL_Min_Fit","Data_or_MC==-1");
 hLL_Min_Fit->SetFillColor(kRed);
 hLL_Min_Fit->SetFillStyle(3001);

 TGraph* grChi2 = (TGraph*) _file0->Get("Graph;1");
 TGraph* grLL = (TGraph*) _file0->Get("grLL");
 TGraph* grNewChi2 = (TGraph*) _file0->Get("Graph;2");
 
 ///==== Plot KS ====
 TCanvas cKS("cKS","cKS",1200,1200);
 cKS.Divide(2,2);
 
 cKS.cd(1);
 hChi2->SetTitle("KS test: KS");
 hChi2->GetYaxis()->SetTitle("D_{n}");
 hChi2->GetXaxis()->SetTitle("#alpha");
 hChi2->Draw("colz");
 grChi2->Draw("P");
 gPad->SetGrid();
 
 cKS.cd(3);
 hChi2_Min->SetTitle("KS test: toy experiments");
 hChi2_Min->GetXaxis()->SetTitle("#alpha");
 hChi2_Min->Draw();
 gPad->SetGrid();
 

 hChi2_Min->Fit("fitGaus","RMQ");

 cKS.cd(2);
 
 double ScaleTrue = -1000; ///==== default
 int Data_or_MC = 1; ///=== 1 = Data;  0 = MC; -1 = MC Fit
 int nIter = 1000000000; ///==== less than 1000000000 iterations at the end !!!
 TString nameDATA = Form("hDATA_%d_%d_%.5f",Data_or_MC,nIter,ScaleTrue);
 TH1F* hDATA = (TH1F*) _file0->Get(nameDATA.Data());
 hDATA->SetTitle("E_{T} distribution");
 hDATA->GetXaxis()->SetTitle("E_{T}");
 hDATA->SetMarkerSize(1);
 hDATA->SetMarkerStyle(20);

 TString NameMC_Chi2 = Form("hMC_Chi2_%.5f",AlphaMean_Chi2);
 TH1F* hMC_Chi2 = (TH1F*) _file0->Get(NameMC_Chi2.Data());
 hMC_Chi2->SetLineWidth(1);
 hMC_Chi2->SetLineColor(kRed);
 hMC_Chi2->SetFillColor(kRed);
 hMC_Chi2->SetFillStyle(3001);

 hDATA->Draw("E1");
 hMC_Chi2->Draw("BARsame");
 hDATA->Draw("E1same");
 
// TString Result_Chi2 = Form("#alpha = %.4f #pm %.4f",AlphaMean_Chi2,hChi2_Min->GetRMS());
 TString Result_Chi2 = Form("#alpha = %.4f #pm %.4f",AlphaMean_Chi2,fitGaus->GetParameter(2));
 TLatex lResult_Chi2(hDATA->GetMean(),9,Result_Chi2);
 lResult_Chi2->Draw();

 
///==== Plot LL ====
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
 hLL->Draw("colz");
 grLL->Draw("P");
 gPad->SetGrid();
 
 cLL.cd(3);
 hLL_Min_Fit->SetTitle("LL test: toy experiments");
 hLL_Min_Fit->GetXaxis()->SetTitle("#alpha");
 hLL_Min_Fit->Draw();
 gPad->SetGrid();
 hLL_Min_Fit->Fit("fitGaus","RMQ"); 

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
 //TString Result_LL = Form("#alpha = %.4f #pm %.4f",AlphaMean_LL_Fit,hLL_Min_Fit->GetRMS());
 TString Result_LL = Form("#alpha = %.4f #pm %.4f",AlphaMean_LL_Fit,fitGaus->GetParameter(2));
 TLatex lResult_LL(hDATA->GetMean(),9,Result_LL);
 lResult_LL->Draw();

 

///==== Plot Chi2 ====
 TF1* fitMinNewChi2 = new TF1("fitMinNewChi2","pol2");
 fitMinNewChi2->SetRange(MinScanRange,MaxScanRange);
 grNewChi2->Fit("fitMinNewChi2","RMQ");
 std::cerr << " alpha NewChi2 = " << -fitMinNewChi2->GetParameter(1) / 2. / fitMinNewChi2->GetParameter(2) << std::endl;


 TCanvas cNewChi2("cNewChi2","cNewChi2",1200,1200);
 cNewChi2.Divide(2,2);
 
 cNewChi2.cd(1);
 hNewChi2->SetTitle("#chi^{2}");
 hNewChi2->GetYaxis()->SetTitle("#chi^{2}");
 hNewChi2->GetXaxis()->SetTitle("#alpha");
 hNewChi2->Draw("colz");
 grNewChi2->Draw("P");
 gPad->SetGrid();
 
 cNewChi2.cd(3);
 hNewChi2_Min_Fit->SetTitle("#chi^{2} test: toy experiments");
 hNewChi2_Min_Fit->GetXaxis()->SetTitle("#alpha");
 hNewChi2_Min_Fit->Draw();
 gPad->SetGrid();
 hNewChi2_Min_Fit->Fit("fitGaus","RMQ"); 

 cNewChi2.cd(2);
 
 TString NameMC_NewChi2 = Form("hMC_Chi2_%.5f",AlphaMean_NewChi2);
 TH1F* hMC_NewChi2 = (TH1F*) _file0->Get(NameMC_NewChi2.Data());
 hMC_NewChi2->SetLineWidth(1);
 hMC_NewChi2->SetLineColor(kRed);
 hMC_NewChi2->SetFillColor(kRed);
 hMC_NewChi2->SetFillStyle(3001);

 hDATA->Draw("E1");
 hMC_NewChi2->Draw("BARsame");
 hDATA->Draw("E1same");
 TString Result_NewChi2 = Form("#alpha = %.4f #pm %.4f",AlphaMean_NewChi2_Fit,fitGaus->GetParameter(2));
// TString Result_NewChi2 = Form("#alpha = %.4f #pm %.4f",AlphaMean_NewChi2_Fit,hNewChi2_Min_Fit->GetRMS());
 TLatex lResult_NewChi2(hDATA->GetMean(),9,Result_NewChi2);
 lResult_NewChi2->Draw();

}



