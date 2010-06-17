{
 int nIter = 20;
 int NBIN = 50;
 double MAX = 1000;

//  int nIter = 10;
//  int NBIN = 50;
//  double MAX = 150;
 
 
 double Kolmogorov[1000];
 double Kolmogorov_1[1000];
 double vIter[1000];

 TCanvas cProfile("cProfile","cProfile",1600,800);
 cProfile.Divide(2,1);
 
 TCanvas cEvolution("cEvolution","cEvolution",1600,800);
 cEvolution.Divide(2,1);
 
 TCanvas cResult("cResult","cResult",800,800);
 
 TTree* tree = ((TTree*) _file0->Get("myTree")); 
 
 nIter = tree->GetMaximum("IterNumber");
 cResult.Divide(nIter,3);
 cResult.cd(0);
 
 TCanvas cReal("cReal","cReal",800,800);
 
 TH2F* h2 = new TH2F("h2","h2",NBIN,0,MAX,NBIN,0,MAX);
 TString drawH2 = Form("xMC:xRECO >> h2");
 tree->Draw(drawH2,"IterNumber==0","colz");
 h2->GetXaxis()->SetTitle("RECO p_{T}");
 h2->GetYaxis()->SetTitle("TRUE p_{T}");
 h2->Draw("colz");
 gPad->SetGrid();
 
 h2.ProfileX();
 h2_pfx.SetMarkerStyle(20);
 h2_pfx.SetMarkerSize(0.5);
 h2_pfx.SetMarkerColor(kBlue);
 h2_pfx.SetLineWidth(2);
 h2_pfx.SetLineColor(kBlue);
 h2_pfx.GetXaxis()->SetTitle("RECO p_{T}");
 h2_pfx.GetYaxis()->SetTitle("TRUE p_{T}");
 
 h2.FitSlicesY(0,0,-1,0,"G2");
 h2_1.SetMarkerStyle(20);
 h2_1.SetMarkerSize(0.5);
 h2_1.SetMarkerColor(kBlue);
 h2_1.SetLineWidth(2);
 h2_1.SetLineColor(kBlue);
 h2_1->GetXaxis()->SetTitle("RECO p_{T}");
 h2_1->GetYaxis()->SetTitle("TRUE p_{T}");
 
 cEvolution.cd(1);
 h2->Draw("colz");
 gPad->SetGrid();
 
  
 for (int iIter = 0; iIter < nIter; iIter++){
  
  std::cerr << "iIter = " << iIter << std::endl;
  vIter[iIter] = iIter;
  
  cResult.cd(1+iIter);
  
  TString cutH2 = Form("IterNumber == %d",iIter);
  
  TString nameH2b = Form("nameH2b_%d",iIter);
  TH2F* h2b = new TH2F(nameH2b.Data(),nameH2b.Data(),NBIN,0,MAX,NBIN,0,MAX);
  TString drawH2b = Form("xRECOMC:xRECO >> nameH2b_%d",iIter);
  tree->Draw(drawH2b,cutH2,"colz");
  h2b->GetXaxis()->SetTitle("RECO p_{T}");
  h2b->GetYaxis()->SetTitle("TRUE p_{T}");
  h2b->Draw("colz");
  gPad->SetGrid();
  
  cEvolution.cd(1);
  h2->Draw("colz");
  gPad->SetGrid();
  
  cEvolution.cd(2);
  h2b->Draw("colz");
  gPad->SetGrid();
  
//   gPad->Update();
  
  if (iIter==0) {
   cEvolution->SaveAs("test/plot/Evolution.gif");
  }
  else {
   cEvolution->SaveAs("test/plot/Evolution.gif+");
  }
  
  TString nameCanvasCaVa = Form("test/plot/Evolution_%d.gif",iIter);
  cEvolution->SaveAs(nameCanvasCaVa);
  
  
  
  
  
  cResult.cd(1+nIter+iIter);
   
  h2b.FitSlicesY(0,0,-1,0,"G2");
  TString nameH2b_1 = Form("nameH2b_%d_1",iIter);
  TH1F* h2b_1 = gDirectory->Get(nameH2b_1);
  h2b_1.SetMarkerStyle(20);
  h2b_1.SetMarkerSize(0.5);
  h2b_1.SetMarkerColor(kRed);
  h2b_1.SetLineWidth(2);
  h2b_1.SetLineColor(kRed);
  h2b_1->GetXaxis()->SetTitle("RECO p_{T}");
  h2b_1->GetYaxis()->SetTitle("TRUE p_{T}");
  
  h2_1.Draw("E");
  h2b_1.Draw("Esame");
  gPad->BuildLegend();
  gPad->SetGrid();
  
  
  cResult.cd(1+nIter*2+iIter);
   
  h2b.ProfileX();
  TString nameH2b_pfx = Form("nameH2b_%d_pfx",iIter);
  TH1F* h2b_pfx = gDirectory->Get(nameH2b_pfx);
  h2b_pfx.SetMarkerStyle(20);
  h2b_pfx.SetMarkerSize(0.5);
  h2b_pfx.SetMarkerColor(kRed);
  h2b_pfx.SetLineWidth(2);
  h2b_pfx.SetLineColor(kRed);
  h2b_pfx.GetXaxis()->SetTitle("RECO p_{T}");
  h2b_pfx.GetYaxis()->SetTitle("TRUE p_{T}");
  
  
  h2_pfx.Draw("E");
  h2b_pfx.Draw("Esame");
    
  Kolmogorov[iIter] = h2_pfx->KolmogorovTest(h2b_pfx);
  Kolmogorov_1[iIter] = h2_1->KolmogorovTest(h2b_1);
  
  gPad->BuildLegend();
  gPad->SetGrid();
  
  
  
  cProfile.cd(1);
  h2_1.Draw("E");
  h2b_1.Draw("Esame");
  gPad->BuildLegend();
  gPad->SetGrid();
  
  cProfile.cd(2);
  h2_pfx.Draw("E");
  h2b_pfx.Draw("Esame");
//   gPad->BuildLegend();
  gPad->SetGrid();
  gPad->Update();
  if (iIter==0) {
   cProfile->SaveAs("test/plot/EvolutionProfile.gif");
  }
  else {
   cProfile->SaveAs("test/plot/EvolutionProfile.gif+");  
  }
  TString nameCanvasProfile = Form("test/plot/EvolutionProfile_%d.gif",iIter);
  cProfile->SaveAs(nameCanvasProfile);
  
  
 }
 
 
 TCanvas* ccKM = new TCanvas("ccKM","ccKM",1000,500);
 ccKM->Divide(2,1);
 
 for (int iIter = 0; iIter < nIter; iIter++){
  std::cerr << " " << nIter << " " << vIter[iIter] << " " << Kolmogorov[iIter] << " " << Kolmogorov_1[iIter] << std::endl;
 }
 
 
 TGraph* gKM = new TGraph(nIter,vIter,Kolmogorov);
 gKM->SetMarkerStyle(20);
 gKM->SetMarkerColor(kRed);
 TGraph* gKM_1 = new TGraph(nIter,vIter,Kolmogorov_1);
 gKM_1->SetMarkerStyle(20);
 gKM_1->SetMarkerColor(kBlue);
 
 ccKM->cd(1);
 gKM->Draw("AP");
 gPad->SetGrid();
 
 
 ccKM->cd(2);
 gKM_1->Draw("AP");
 gPad->SetGrid();
 
 
}


