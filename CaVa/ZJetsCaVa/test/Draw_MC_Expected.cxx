{
 int NBINX = 100;
 int NBINY = 30;
 double MAXY = 200;
 double MAXX = 200;
 
 TTree* tree = (TTree*) _file0->Get("outTree"); 
 
 ////////////////////////////////////////////////////////////////////////////////
 
 TCanvas cResult("cResult","cResult",800,1000);
 cResult.Divide(2,4);

 TH2F h2("h2","CaVa pT balance",NBINX,0,MAXX,NBINY,0,MAXY);
 TH2F h2MC("h2MC","CaVa MC",NBINX,0,MAXX,NBINY,0,MAXY);
 
 TH1F h1("h1","k function pT balance",NBINX,0,MAXX);
 TH1F h1MC("h1MC","k function MC",NBINX,0,MAXX);
 

 cResult.cd(1);
 tree->Draw("xMC:xRECO  >> h2MC","","colz");
 h2MC->Draw("colz");
 h2MC.FitSlicesX();
 h2MC_1.SetLineWidth(2);

 double yRMSMC[1000];
 double erryRMSMC[1000];
 double xMC[1000];
 double yMC[1000];
 double erryMC[1000];
 double errxMC[1000];
 for (int iBin=0; iBin < h2MC_1.GetNbinsX(); iBin++){
  yMC[iBin] = h2MC_1.GetBinCenter(iBin+1);
  xMC[iBin] = h2MC_1.GetBinContent(iBin+1);
  erryMC[iBin] = h2MC_1.GetBinWidth(iBin+1);
  errxMC[iBin] = h2MC_1.GetBinError(iBin+1);
  yRMSMC[iBin] = h2MC_2.GetBinCenter(iBin+1);
  erryRMSMC[iBin] = h2MC_2.GetBinError(iBin+1);
 }
 
 TGraph grMC(h2MC_1.GetNbinsX(),xMC,yMC);
 grMC.SetMarkerSize(1);
 grMC.SetMarkerStyle(22);
 grMC.SetMarkerColor(kRed);
 grMC.Draw("Psame");
 
 h2MC.GetXaxis()->SetTitle("RECO p_{T}");
 h2MC.GetYaxis()->SetTitle("TRUE p_{T}");
 
 gPad->SetGrid();
 
 cResult.cd(2);
 tree->Draw("xMCEXP:xRECO  >> h2","","colz");
 h2->Draw("colz");
 h2.FitSlicesX();
 h2_1.SetLineWidth(2);
 
 double yRMS[1000];
 double erryRMS[1000];
 double x[1000];
 double y[1000];
 double errx[1000];
 double erry[1000];
 for (int iBin=0; iBin < h2_1.GetNbinsX(); iBin++){
  y[iBin] = h2_1.GetBinCenter(iBin+1);
  x[iBin] = h2_1.GetBinContent(iBin+1);
  erry[iBin] = h2_1.GetBinWidth(iBin+1);
  errx[iBin] = h2_1.GetBinError(iBin+1);
  yRMS[iBin] = h2_2.GetBinCenter(iBin+1);
  erryRMS[iBin] = h2_2.GetBinError(iBin+1);
 }
 
 TGraph gr(h2_1.GetNbinsX(),x,y);
 gr.SetMarkerSize(1);
 gr.SetMarkerStyle(22);
 gr.SetMarkerColor(kBlue);
 gr.Draw("Psame");
 
 h2.GetXaxis()->SetTitle("RECO p_{T}");
 h2.GetYaxis()->SetTitle("TRUE p_{T}");
 
 gPad->SetGrid();
 
 ///====================================================================
 
 cResult.cd(3);
 gr.SetTitle("pT balance");
 grMC.SetTitle("MC");
 grMC.Draw("AP");
 gr.Draw("Psame");
 grMC.GetXaxis()->SetTitle("RECO p_{T}");
 grMC.GetYaxis()->SetTitle("TRUE p_{T}");
 gPad->SetGrid();
 gPad->BuildLegend();
 
 ///====================================================================
 
 cResult.cd(4); 
 
 h2.ProfileY();
 TH1F* h2_pfy = gDirectory->Get("h2_pfy");
 h2_pfy.SetMarkerStyle(20);
 h2_pfy.SetMarkerSize(0.5);
 h2_pfy.SetMarkerColor(kBlue);
 h2_pfy.SetLineWidth(2);
 h2_pfy.SetLineColor(kBlue); 

 h2MC.ProfileY();
 TH1F* h2MC_pfy = gDirectory->Get("h2MC_pfy");
 h2MC_pfy.SetMarkerStyle(20);
 h2MC_pfy.SetMarkerSize(0.5);
 h2MC_pfy.SetMarkerColor(kRed);
 h2MC_pfy.SetLineWidth(2);
 h2MC_pfy.SetLineColor(kRed);
 
 h2_pfy.SetTitle("CaVa pT balance ProfileY");
 h2MC_pfy.SetTitle("CaVa MC ProfileY");
 h2_pfy.Draw("E");
 h2_pfy.GetXaxis()->SetTitle("TRUE p_{T}");
 h2_pfy.GetYaxis()->SetTitle("RECO p_{T}");
 
 h2MC_pfy.Draw("Esame");
 gPad->SetGrid();
 gPad->BuildLegend();
 
 ///====================================================================
 
 cResult.cd(5); 
 
 TGraphErrors grMC_K(h2MC_1.GetNbinsX(),yMC,xMC,erryMC,errxMC);
 grMC_K.SetTitle("MC");
 grMC_K.SetMarkerSize(1);
 grMC_K.SetMarkerStyle(20);
 grMC_K.SetMarkerColor(kRed);
 grMC_K.Draw("AP");
 grMC_K.GetXaxis()->SetTitle("TRUE p_{T}");
 grMC_K.GetYaxis()->SetTitle("RECO p_{T}");
 
 TGraphErrors gr_K(h2_1.GetNbinsX(),y,x,erry,errx);
 gr_K.SetTitle("pT balance");
 gr_K.SetMarkerSize(1);
 gr_K.SetMarkerStyle(20);
 gr_K.SetMarkerColor(kBlue);
 gr_K.Draw("Psame");
 gPad->SetGrid();
 gPad->BuildLegend();
 

 ///====================================================================
 
 cResult.cd(6); 
 
 h2MC_chi2.SetTitle("Chi2 MC");
 h2MC_chi2.SetMarkerSize(1);
 h2MC_chi2.SetMarkerStyle(20);
 h2MC_chi2.SetMarkerColor(kRed);
 h2MC_chi2.Draw("P");
 h2MC_chi2.GetXaxis()->SetTitle("TRUE p_{T}");
 h2MC_chi2.GetYaxis()->SetTitle("RECO p_{T}");
 
 h2_chi2.SetTitle("Chi2 pT balance");
 h2_chi2.SetMarkerSize(1);
 h2_chi2.SetMarkerStyle(20);
 h2_chi2.SetMarkerColor(kBlue);
 h2_chi2.Draw("Psame");
 gPad->SetGrid();
 gPad->BuildLegend();
 
 
 ///====================================================================
 
 cResult.cd(7); 
 
 TGraphErrors grMC_KRMS(h2MC_2.GetNbinsX(),yRMSMC,xMC,erryRMSMC,errxMC);
 grMC_KRMS.SetTitle("MC");
 grMC_KRMS.SetMarkerSize(1);
 grMC_KRMS.SetMarkerStyle(20);
 grMC_KRMS.SetMarkerColor(kRed);
 grMC_KRMS.Draw("AP");
 grMC_KRMS.GetXaxis()->SetTitle("TRUE p_{T}");
 grMC_KRMS.GetYaxis()->SetTitle("RECO p_{T}");
 
 TGraphErrors gr_KRMS(h2_2.GetNbinsX(),yRMS,x,erryRMS,errx);
 gr_KRMS.SetTitle("pT balance");
 gr_KRMS.SetMarkerSize(1);
 gr_KRMS.SetMarkerStyle(20);
 gr_KRMS.SetMarkerColor(kBlue);
 gr_KRMS.Draw("Psame");
 gPad->SetGrid();
 gPad->BuildLegend();
 
}
