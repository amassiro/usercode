{
 
 ///==== draw CalibratingCaVa for old sryle calibration procedure
 ///==== reconstructed factors are wrong for distributions versus RECO
 
 int NBINX = 100;
 int NBINY = 100;
 double MAXY = 3;
 double MAXX = 200;
 
 double MAXY_TRUE = 300;
 int NBINY_TRUE = 100;
 
//  TFile* _file0 = new TFile("/home/andrea/Cern/Code/VBF/TTBar/CalibrationValley/testZJets/ZJetsCaVa/output/input_toy_ZJets.root","READ");
 TFile* _file0 = new TFile("/home/andrea/Cern/Code/VBF/TTBar/CalibrationValley/testZJets/ZJetsCaVa/output/input_toy_ZJets_Distro_1_highResolution.root","READ");
 TTree* tree = (TTree*) _file0->Get("InputTree"); 
 
 TFile* _file2 = new TFile("/home/andrea/Cern/Code/VBF/TTBar/CalibrationValley/testZJets/ZJetsCaVa/output/input_toy_ZJets_Distro_2_highResolution.root","READ");
//  TFile* _file2 = new TFile("/home/andrea/Cern/Code/VBF/TTBar/CalibrationValley/testZJets/ZJetsCaVa/output/input_toy_ZJets_Distro_2.root","READ");
 TTree* tree2 = (TTree*) _file2->Get("InputTree"); 
 
 
 ///==== Distributions versus TRUE => correct ====
 ////////////////////////////////////////////////////////////////////////////////
 
 TCanvas cResult("cResult","cResult",800,1000);
 cResult.Divide(2,4);

 TH2F h1("h1","2D plot 1",NBINX,0,MAXX,NBINY,0,MAXY);
 TH2F h2("h2","2D plot 2",NBINX,0,MAXX,NBINY,0,MAXY);
 
 TH1F h1RECO("h1RECO","Reco distribution 1",NBINX,0,MAXX);
 TH1F h2RECO("h2RECO","Reco distribution 2",NBINX,0,MAXX);

 TH1F h1TRUE("h1TRUE","True distribution 1",NBINY_TRUE,0,MAXY_TRUE);
 TH1F h2TRUE("h2TRUE","True distribution 2",NBINY_TRUE,0,MAXY_TRUE);
 
 
 
 ///===============================================================
 cResult.cd(1);
 tree->Draw("xRECO/xMC:xMC >> h1","","colz");
 h1.Draw("colz");
 h1.FitSlicesY();
 h1_1.SetLineWidth(2);

 
 double xMC1[1000];
 double yMC1[1000];
 double erryMC1[1000];
 double errxMC1[1000];
 for (int iBin=0; iBin < h1_1.GetNbinsX(); iBin++){
  xMC1[iBin] = h1_1.GetBinCenter(iBin+1);
  yMC1[iBin] = h1_1.GetBinContent(iBin+1);
  errxMC1[iBin] = h1_1.GetBinWidth(iBin+1);
  erryMC1[iBin] = h1_1.GetBinError(iBin+1);
 }
 
 TGraphErrors grMC1(h1_1.GetNbinsX(),xMC1,yMC1,errxMC1,erryMC1);
 grMC1.SetTitle("Sample 1");
 grMC1.SetMarkerSize(1);
 grMC1.SetMarkerStyle(22);
 grMC1.SetLineColor(kRed);
 grMC1.SetMarkerColor(kRed);
 grMC1.SetFillColor(kRed);
 grMC1.Draw("Psame");

 h1.GetXaxis()->SetTitle("TRUE");
 h1.GetYaxis()->SetTitle("RECO / TRUE"); 
 gPad->SetGrid();

 
 cResult.cd(3);
 grMC1.Draw("AP");
 grMC1.GetXaxis()->SetTitle("TRUE");
 grMC1.GetYaxis()->SetTitle("RECO / TRUE"); 
 gPad->SetGrid();
 
 
 
 cResult.cd(5);
 tree->Draw("xRECO >> h1RECO","","");
 h1RECO.SetFillColor(kGreen);
 h1RECO.GetXaxis()->SetTitle("RECO");
 h1RECO.Draw();
 
 cResult.cd(7);
 tree->Draw("xMC >> h1TRUE","","");
 h1TRUE.SetFillColor(kBlue);
 h1TRUE.GetXaxis()->SetTitle("TRUE");
 h1TRUE.Draw();
 
 
 
 ///===============================================================
 cResult.cd(2);
 tree2->Draw("xRECO/xMC:xMC >> h2","","colz");
 h2.Draw("colz");
 h2.FitSlicesY();
 h2_1.SetLineWidth(2);
 
 
 double xMC2[1000];
 double yMC2[1000];
 double erryMC2[1000];
 double errxMC2[1000];
 for (int iBin=0; iBin < h2_1.GetNbinsX(); iBin++){
  xMC2[iBin] = h2_1.GetBinCenter(iBin+1);
  yMC2[iBin] = h2_1.GetBinContent(iBin+1);
  errxMC2[iBin] = h2_1.GetBinWidth(iBin+1);
  erryMC2[iBin] = h2_1.GetBinError(iBin+1);
 }
 
 TGraphErrors grMC2(h2_1.GetNbinsX(),xMC2,yMC2,errxMC2,erryMC2);
 grMC2.SetTitle("Sample 2");
 grMC2.SetMarkerSize(1);
 grMC2.SetMarkerStyle(22);
 grMC2.SetMarkerColor(kBlue);
 grMC2.SetLineColor(kBlue);
 grMC2.SetFillColor(kBlue);
 grMC2.Draw("Psame");
 
 h2.GetXaxis()->SetTitle("TRUE");
 h2.GetYaxis()->SetTitle("RECO / TRUE"); 
 gPad->SetGrid();
 
 
 cResult.cd(4);
 grMC2.Draw("AP");
 grMC2.GetXaxis()->SetTitle("TRUE");
 grMC2.GetYaxis()->SetTitle("RECO / TRUE"); 
 gPad->SetGrid();
 
 
 
 cResult.cd(6);
 tree2->Draw("xRECO >> h2RECO","","");
 h2RECO.SetFillColor(kGreen);
 h2RECO.GetXaxis()->SetTitle("RECO");
 h2RECO.Draw();
 
 cResult.cd(8);
 tree->Draw("xMC >> h2TRUE","","");
 h2TRUE.SetFillColor(kBlue);
 h2TRUE.GetXaxis()->SetTitle("TRUE");
 h2TRUE.Draw();
 
 
 
 
 ///==========================================================
 
 TCanvas cResultComparison("cResultComparison","cResultComparison",400,400);
 TMultiGraph *mg = new TMultiGraph();
 mg->Add(&grMC1);
 mg->Add(&grMC2);
 mg->Draw("APL");
 mg->GetXaxis()->SetTitle("TRUE");
 mg->GetYaxis()->SetTitle("RECO / TRUE");
 gPad->BuildLegend();
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 ///==== Distributions versus RECO => Wrong ====
 ////////////////////////////////////////////////////////////////////////////////
 
 TCanvas cResultWrong("cResultWrong","cResultWrong",800,1000);
 cResultWrong.Divide(2,4);
 
 TH2F Wrongh1("Wrongh1","2D plot 1",NBINX,0,MAXX,NBINY,0,MAXY);
 TH2F Wrongh2("Wrongh2","2D plot 2",NBINX,0,MAXX,NBINY,0,MAXY);
 
 TH1F Wrongh1RECO("Wrongh1RECO","Reco distribution 1",NBINX,0,MAXX);
 TH1F Wrongh2RECO("Wrongh2RECO","Reco distribution 2",NBINX,0,MAXX);
 
 TH1F Wrongh1TRUE("Wrongh1TRUE","True distribution 1",NBINY_TRUE,0,MAXY_TRUE);
 TH1F Wrongh2TRUE("Wrongh2TRUE","True distribution 2",NBINY_TRUE,0,MAXY_TRUE);
 
 
 
 ///===============================================================
 cResultWrong.cd(1);
 tree->Draw("xMC/xRECO:xRECO >> Wrongh1","","colz");
 Wrongh1.Draw("colz");
 Wrongh1.FitSlicesY();
 Wrongh1_1.SetLineWidth(2);
 
 
 double xMC1Wrong[1000];
 double yMC1Wrong[1000];
 double erryMC1Wrong[1000];
 double errxMC1Wrong[1000];
 for (int iBin=0; iBin < Wrongh1_1.GetNbinsX(); iBin++){
  xMC1Wrong[iBin] = Wrongh1_1.GetBinCenter(iBin+1);
  yMC1Wrong[iBin] = Wrongh1_1.GetBinContent(iBin+1);
  errxMC1Wrong[iBin] = Wrongh1_1.GetBinWidth(iBin+1);
  erryMC1Wrong[iBin] = Wrongh1_1.GetBinError(iBin+1);
 }
 
 TGraphErrors grMC1Wrong(Wrongh1_1.GetNbinsX(),xMC1Wrong,yMC1Wrong,errxMC1Wrong,erryMC1Wrong);
 grMC1Wrong.SetTitle("Sample 1");
 grMC1Wrong.SetMarkerSize(1);
 grMC1Wrong.SetMarkerStyle(22);
 grMC1Wrong.SetLineColor(kRed);
 grMC1Wrong.SetMarkerColor(kRed);
 grMC1Wrong.SetFillColor(kRed);
 grMC1Wrong.Draw("Psame");
 
 Wrongh1.GetXaxis()->SetTitle("RECO");
 Wrongh1.GetYaxis()->SetTitle("TRUE / RECO"); 
 gPad->SetGrid();
 
 
 cResultWrong.cd(3);
 grMC1Wrong.Draw("AP");
 grMC1Wrong.GetXaxis()->SetTitle("RECO");
 grMC1Wrong.GetYaxis()->SetTitle("TRUE / RECO"); 
 gPad->SetGrid();
 
 
 
 cResultWrong.cd(5);
 tree->Draw("xRECO >> Wrongh1RECO","","");
 Wrongh1RECO.SetFillColor(kGreen);
 Wrongh1RECO.GetXaxis()->SetTitle("RECO");
 Wrongh1RECO.Draw();
 
 cResultWrong.cd(7);
 tree->Draw("xMC >> Wrongh1TRUE","","");
 Wrongh1TRUE.SetFillColor(kBlue);
 Wrongh1TRUE.GetXaxis()->SetTitle("TRUE");
 Wrongh1TRUE.Draw();
 
 
 
 ///===============================================================
 cResultWrong.cd(2);
 tree2->Draw("xMC/xRECO:xRECO >> Wrongh2","","colz");
 Wrongh2.Draw("colz");
 Wrongh2.FitSlicesY();
 Wrongh2_1.SetLineWidth(2);
 
 
 double xMC2Wrong[1000];
 double yMC2Wrong[1000];
 double erryMC2Wrong[1000];
 double errxMC2Wrong[1000];
 for (int iBin=0; iBin < Wrongh2_1.GetNbinsX(); iBin++){
  xMC2Wrong[iBin] = Wrongh2_1.GetBinCenter(iBin+1);
  yMC2Wrong[iBin] = Wrongh2_1.GetBinContent(iBin+1);
  errxMC2Wrong[iBin] = Wrongh2_1.GetBinWidth(iBin+1);
  erryMC2Wrong[iBin] = Wrongh2_1.GetBinError(iBin+1);
 }
 
 TGraphErrors grMC2Wrong(Wrongh2_1.GetNbinsX(),xMC2Wrong,yMC2Wrong,errxMC2Wrong,erryMC2Wrong);
 grMC2Wrong.SetTitle("Sample 2");
 grMC2Wrong.SetMarkerSize(1);
 grMC2Wrong.SetMarkerStyle(22);
 grMC2Wrong.SetMarkerColor(kBlue);
 grMC2Wrong.SetLineColor(kBlue);
 grMC2Wrong.SetFillColor(kBlue);
 grMC2Wrong.Draw("Psame");
 
 Wrongh2.GetXaxis()->SetTitle("RECO");
 Wrongh2.GetYaxis()->SetTitle("TRUE / RECO"); 
 gPad->SetGrid();
 
 
 cResultWrong.cd(4);
 grMC2Wrong.Draw("AP");
 grMC2Wrong.GetXaxis()->SetTitle("RECO");
 grMC2Wrong.GetYaxis()->SetTitle("TRUE / RECO"); 
 gPad->SetGrid();
 
 
 
 cResultWrong.cd(6);
 tree2->Draw("xRECO >> Wrongh2RECO","","");
 Wrongh2RECO.SetFillColor(kGreen);
 Wrongh2RECO.GetXaxis()->SetTitle("RECO");
 Wrongh2RECO.Draw();
 
 cResultWrong.cd(8);
 tree->Draw("xMC >> Wrongh2TRUE","","");
 Wrongh2TRUE.SetFillColor(kBlue);
 Wrongh2TRUE.GetXaxis()->SetTitle("TRUE");
 Wrongh2TRUE.Draw();
 
 
 
 
 ///==========================================================
 
 TCanvas cResultWrongComparison("cResultWrongComparison","cResultWrongComparison",400,400);
 TMultiGraph *mgWrong = new TMultiGraph();
 mgWrong->Add(&grMC1Wrong);
 mgWrong->Add(&grMC2Wrong);
 mgWrong->Draw("APL");
 mgWrong->GetXaxis()->SetTitle("RECO");
 mgWrong->GetYaxis()->SetTitle("TRUE / RECO");
 gPad->BuildLegend();
 gPad->SetGrid();
 
}











