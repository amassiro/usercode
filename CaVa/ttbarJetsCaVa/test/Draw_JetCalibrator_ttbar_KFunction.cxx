{
//  int nIter = 20;
//  int NBIN = 100;
//  double MAX = 2000;

 int nIter = 10;
 int NBIN = 40;
 double MAX = 1000;
 
 TFile* _file0 = new TFile("/home/andrea/Cern/Code/VBF/TTBar/CalibrationValley/testZJets/ttbarJetsCaVa/output/out_2Jet_Calibration_TTBar_NewCaVa.root","READ");
 
 
 double xMC[1000];
 double yMC[1000];
 TF1 *kFunction = new TF1("kFunction","1.3 + 0.001 * x - exp(-x/100)",0,2000);
 for (int iBin=0; iBin < 1000; iBin++){
  yMC[iBin] = (MAX) / 1000. * iBin;
  xMC[iBin] = kFunction.Eval(yMC[iBin]) * yMC[iBin];
 }
 
 TGraph grInv(1000,yMC,xMC);
 grInv.SetMarkerSize(0.5);
 grInv.SetMarkerStyle(20);
 grInv.SetMarkerColor(kGreen);
 grInv.SetFillColor(kGreen);
 
 
 double Kolmogorov[1000];
 double Kolmogorov_1[1000];
 double vIter[1000];

 TH1F* h1Mass = new TH1F("h1Mass","h1Mass",160,0,160);
 
 TCanvas* ccMass = new TCanvas("ccMass","ccMass",400,400);
 
 
 TCanvas cProfile("cProfile","cProfile",1600,800);
 cProfile.Divide(2,1);
 
 TCanvas cEvolution("cEvolution","cEvolution",1600,800);
 cEvolution.Divide(2,1);
 
 TCanvas cResult("cResult","cResult",800,800);
 
 TTree* tree = ((TTree*) _file0->Get("myTree")); 
 
 nIter = tree->GetMaximum("IterNumber");
 cResult.Divide(nIter,3);
 
 TCanvas cReal("cReal","cReal",800,800);
 
 TH2F* h2 = new TH2F("h2","h2",NBIN,0,MAX,NBIN,0,MAX);
 TH2F* h2temp = new TH2F("h2temp","h2temp",NBIN,0,MAX,NBIN,0,MAX);
 TString drawH2 = Form("xMC_1:xRECO_1 >> h2");
 TString cutH2MC = Form("IterNumber==%d",nIter);
 tree->Draw(drawH2,cutH2MC,"colz");
 TString drawH2temp = Form("xMC_2:xRECO_2 >> h2temp");
 TString cutH2MCtemp = Form("IterNumber==%d",nIter);
 tree->Draw(drawH2temp,cutH2MCtemp,"colz");
 h2->Add(h2temp); 
 h2->GetXaxis()->SetTitle("RECO p_{T}");
 h2->GetYaxis()->SetTitle("TRUE p_{T}");
 h2->Draw("colz");
 gPad->SetGrid();
 
 
 ///==== True Fixed ====
 h2.ProfileY();
 h2_pfy.SetMarkerStyle(20);
 h2_pfy.SetMarkerSize(0.5);
 h2_pfy.SetMarkerColor(kBlue);
 h2_pfy.SetLineWidth(2);
 h2_pfy.SetLineColor(kBlue);
 h2_pfy.GetXaxis()->SetTitle("TRUE p_{T}");
 h2_pfy.GetYaxis()->SetTitle("RECO p_{T}");
 
 h2.FitSlicesX(0,0,-1,0,"G5");
 h2_1.SetMarkerStyle(20);
 h2_1.SetMarkerSize(0.5);
 h2_1.SetMarkerColor(kBlue);
 h2_1.SetLineWidth(2);
 h2_1.SetLineColor(kBlue);
 h2_1->GetXaxis()->SetTitle("TRUE p_{T}");
 h2_1->GetYaxis()->SetTitle("RECO p_{T}");
 
 
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
  TString drawH2b = Form("xRECOMC_1:xRECO_1 >> nameH2b_%d",iIter);
  tree->Draw(drawH2b,cutH2,"colz");
  
  TString nameH2btemp = Form("nameH2btemp_%d",iIter);
  TH2F* h2btemp = new TH2F(nameH2btemp.Data(),nameH2btemp.Data(),NBIN,0,MAX,NBIN,0,MAX);
  TString drawH2btemp = Form("xRECOMC_2:xRECO_2 >> nameH2btemp_%d",iIter);
  tree->Draw(drawH2btemp,cutH2,"colz");
  
  std::cerr << " =========================== " << h2b->GetEntries() << std::endl;
  h2b->Add(h2btemp);
  std::cerr << " =========================== " << h2b->GetEntries() << std::endl;
  
  h2b->GetXaxis()->SetTitle("RECO p_{T}");
  h2b->GetYaxis()->SetTitle("TRUE p_{T}");
  h2b->Draw("colz");
  gPad->SetGrid();
  
  cEvolution.cd(2);
  h2b->Draw("colz");
  gPad->SetGrid();
  
  gPad->Update();
  
  if (iIter==0) {
   cEvolution->SaveAs("test/plot/EvolutionK.gif");
  }
  else {
   cEvolution->SaveAs("test/plot/EvolutionK.gif+");
  }
  
  TString nameCanvasCaVa = Form("test/plot/EvolutionK_%d.gif",iIter);
  cEvolution->SaveAs(nameCanvasCaVa);
  
 
  cResult.cd(1+nIter+iIter);
   
  h2b.FitSlicesX(0,0,-1,0,"G5");
  TString nameH2b_1 = Form("nameH2b_%d_1",iIter);
  TH1F* h2b_1 = gDirectory->Get(nameH2b_1);
  h2b_1.SetMarkerStyle(20);
  h2b_1.SetMarkerSize(0.5);
  h2b_1.SetMarkerColor(kRed);
  h2b_1.SetLineWidth(2);
  h2b_1.SetLineColor(kRed);
  h2b_1->GetXaxis()->SetTitle("TRUE p_{T}");
  h2b_1->GetYaxis()->SetTitle("RECO p_{T}");
  
  h2_1.Draw("E");
  h2b_1.Draw("Esame");
  gPad->BuildLegend();
  gPad->SetGrid();
  
  
  cResult.cd(1+nIter*2+iIter);
   
  h2b.ProfileY();
  TString nameH2b_pfy = Form("nameH2b_%d_pfy",iIter);
  TH1F* h2b_pfy = gDirectory->Get(nameH2b_pfy);
  h2b_pfy.SetMarkerStyle(20);
  h2b_pfy.SetMarkerSize(0.5);
  h2b_pfy.SetMarkerColor(kRed);
  h2b_pfy.SetLineWidth(2);
  h2b_pfy.SetLineColor(kRed);
  h2b_pfy.GetXaxis()->SetTitle("TRUE p_{T}");
  h2b_pfy.GetYaxis()->SetTitle("RECO p_{T}");
  
  
  h2_pfy.Draw("E");
  h2b_pfy.Draw("Esame");
    
  Kolmogorov[iIter] = h2_pfy->KolmogorovTest(h2b_pfy);
  Kolmogorov_1[iIter] = h2_1->KolmogorovTest(h2b_1);
  
  gPad->BuildLegend();
  gPad->SetGrid();
  
  
  
  cProfile.cd(1);
  h2_1.Draw("E");
  h2b_1.Draw("Esame");
  grInv.Draw("Psame");
  gPad->BuildLegend();
  gPad->SetGrid();
  
  cProfile.cd(2);
  h2_pfy.Draw("E");
  h2b_pfy.Draw("Esame");
  grInv.Draw("Psame");
  gPad->BuildLegend();
  gPad->SetGrid();
  gPad->Update();
  if (iIter==0) {
   cProfile->SaveAs("test/plot/EvolutionProfileK.gif");
  }
  else {
   cProfile->SaveAs("test/plot/EvolutionProfileK.gif+");  
  }
  TString nameCanvasProfile = Form("test/plot/EvolutionProfileK_%d.gif",iIter);
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


