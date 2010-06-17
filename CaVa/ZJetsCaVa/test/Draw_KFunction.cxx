{
 double MAXY = 2000;
 
 TFile* _file0 = new TFile("/home/andrea/Cern/Code/VBF/TTBar/CalibrationValley/testZJets/ZJetsCaVa/output/input_toy_ZJets.root","READ");
 
 TTree* tree = (TTree*) _file0->Get("InputTree"); 
 
 TCanvas cResult("cResult","cResult",800,400);
 cResult.Divide(2,1);
 TH2F h2("h2","h2",200,0,2000,200,0,2000);
 TH1F h1RECO("h1RECO","h1RECO",200,0,2000);
 TH1F h1MC("h1MC","h1MC",200,0,2000);
 
 cResult.cd(1);
 tree->Draw("xMC:xRECO >> h2","xRECO>400","colz");
 h2->Draw("colz");
 h2.GetXaxis()->SetTitle("RECO");
 h2.GetYaxis()->SetTitle("TRUE"); 
 
 h2.FitSlicesX();
 h2_1.SetLineWidth(2);
 
 double x[1000];
 double y[1000];
 for (int iBin=0; iBin < h2_1.GetNbinsX(); iBin++){
  y[iBin] = h2_1.GetBinCenter(iBin+1);
  x[iBin] = h2_1.GetBinContent(iBin+1);
 }
 
 TGraph gr(h2_1.GetNbinsX(),x,y);
 gr.SetMarkerSize(1);
 gr.SetMarkerStyle(22);
 gr.SetMarkerColor(kRed);
 gr.Draw("Psame");
 gPad->SetGrid();
 
 
 double xMC[1000];
 double yMC[1000];
 TF1 *kFunction = new TF1("kFunction","1.3 + 0.001 * x - exp(-x/100)",0,2000);
 for (int iBin=0; iBin < 1000; iBin++){
  yMC[iBin] = (MAXY) / 1000. * iBin;
  xMC[iBin] = kFunction.Eval(yMC[iBin]) * yMC[iBin];
 }
 
 TGraph grMC(1000,xMC,yMC);
 grMC.SetMarkerSize(0.5);
 grMC.SetMarkerStyle(20);
 grMC.SetMarkerColor(kGreen);
 grMC.Draw("Psame");
  
 
 cResult.cd(2);
 
 TGraph grInv(h2_1.GetNbinsX(),y,x);
 grInv.SetMarkerSize(1);
 grInv.SetMarkerStyle(22);
 grInv.SetMarkerColor(kRed);
 grInv.Draw("AP");
 
 
 TGraph grMCInv(1000,yMC,xMC);
 grMCInv.SetMarkerSize(0.5);
 grMCInv.SetMarkerStyle(20);
 grMCInv.SetMarkerColor(kGreen);
 grMCInv.Draw("Psame");
 
 
//  gr.Draw("AP");
//  grMC.Draw("Psame");
 
 grInv.GetXaxis()->SetTitle("TRUE");
 grInv.GetYaxis()->SetTitle("RECO"); 
 
 gPad->SetGrid();
 
 
 
}


