{
 int nIter = 20;
 int NBINX = 70;
 int NBINY = 70;
 double MAXX = 300;
 double MAXY = 600;
 
 
 TTree* tree = ((TTree*) _file0->Get("myTree"));  
 nIter = tree->GetMaximum("IterNumber");
 std::cerr << "nIter = " << nIter << std::endl;
 
//  nIter = 15;
 
 TCanvas cResult("cResult","cResult",800,1200);
 cResult.Divide(2,3);
 
 
 ///==== MC information ====
 cResult.cd(1);
 TH2F* h2 = new TH2F("h2","h2",NBINX,0,MAXX,NBINY,0,MAXY);
 TString drawH2 = Form("xRECO_1:xMC_1 >> h2");
 tree->Draw(drawH2,"IterNumber==0","colz");
 
 TH2F* h2temp = new TH2F("h2temp","h2temp",NBINX,0,MAXX,NBINY,0,MAXY);
 TString drawH2temp = Form("xRECO_2:xMC_2 >> h2temp");
 tree->Draw(drawH2temp,"IterNumber==0","colz");
 h2->Add(h2temp); 
 
 
 
 h2->GetXaxis()->SetTitle("Q^{T}");
 h2->GetYaxis()->SetTitle("Q^{R}");
 h2->Draw("colz");
 gPad->SetGrid();
 
 h2.ProfileX();
 h2_pfx.SetMarkerStyle(20);
 h2_pfx.SetMarkerSize(0.5);
 h2_pfx.SetMarkerColor(kBlue);
 h2_pfx.SetLineWidth(2);
 h2_pfx.SetFillColor(kBlue);
 h2_pfx.SetLineColor(kBlue);
 h2_pfx.GetXaxis()->SetTitle("Q^{T}");
 h2_pfx.GetYaxis()->SetTitle("Q^{R}");
 
 h2.FitSlicesY(0,0,-1,0,"G2");
 h2_1.SetMarkerStyle(20);
 h2_1.SetMarkerSize(0.5);
 h2_1.SetMarkerColor(kBlue);
 h2_1.SetFillColor(kBlue);
 h2_1.SetLineWidth(2);
 h2_1.SetLineColor(kBlue);
 h2_1->GetXaxis()->SetTitle("Q^{T}");
 h2_1->GetYaxis()->SetTitle("Q^{R}");
 
 
 ///==== DATA information ====
 cResult.cd(2);
 TString cutH2 = Form("IterNumber == %d",nIter);
 TString nameH2b = Form("nameH2b_%d",nIter);
 TH2F* h2b = new TH2F(nameH2b.Data(),nameH2b.Data(),NBINX,0,MAXX,NBINY,0,MAXY);
 TString drawH2b = Form("xRECO_1:xRECOMC_1 >> nameH2b_%d",nIter);
 tree->Draw(drawH2b,cutH2,"colz");
 
 TH2F* h2btemp = new TH2F("h2btemp","h2btemp",NBINX,0,MAXX,NBINY,0,MAXY);
 TString drawH2btemp = Form("xRECO_2:xRECOMC_2 >> h2btemp");
 tree->Draw(drawH2btemp,cutH2,"colz");
 h2b->Add(h2btemp); 
 
 
 h2b->GetXaxis()->SetTitle("Q^{T}");
 h2b->GetYaxis()->SetTitle("Q^{R}");
 h2b->Draw("colz");
 gPad->SetGrid();
 
 h2b.FitSlicesY(0,0,-1,0,"G2");
 TString nameH2b_1 = Form("nameH2b_%d_1",nIter);
 TH1F* h2b_1 = gDirectory->Get(nameH2b_1);
 h2b_1.SetMarkerStyle(22);
 h2b_1.SetMarkerSize(0.5);
 h2b_1.SetMarkerColor(kRed);
 h2b_1.SetFillColor(kRed);
 h2b_1.SetLineWidth(2);
 h2b_1.SetLineColor(kRed);
 h2b_1->GetXaxis()->SetTitle("Q^{T}");
 h2b_1->GetYaxis()->SetTitle("Q^{R}");
 
   
 h2b.ProfileX();
 TString nameH2b_pfx = Form("nameH2b_%d_pfx",nIter);
 TH1F* h2b_pfx = gDirectory->Get(nameH2b_pfx);
 h2b_pfx.SetMarkerStyle(22);
 h2b_pfx.SetMarkerSize(0.5);
 h2b_pfx.SetMarkerColor(kRed);
 h2b_pfx.SetFillColor(kRed);
 h2b_pfx.SetLineWidth(2);
 h2b_pfx.SetLineColor(kRed);
 h2b_pfx.GetXaxis()->SetTitle("Q^{T}");
 h2b_pfx.GetYaxis()->SetTitle("Q^{R}");
  

 ///==== Combined information ====
 
 cResult.cd(1);
 h2->Draw("colz");
 
 cResult.cd(2);
 h2b->Draw("colz");
 
 cResult.cd(3);
 h2_pfx.Draw("E");
 
 cResult.cd(4);
 h2b_pfx.Draw("E");
 
 cResult.cd(5);
 h2_1.Draw("E");
 
 cResult.cd(6);
 h2b_1.Draw("E");
 
 
 ///==== Combined information Plus ====
 
 double xMC[1000];
 double yMC[1000];
 TF1 *kFunction = new TF1("kFunction","1.3 + 0.001 * x - exp(-x/100)",0,2000);
 for (int iBin=0; iBin < 1000; iBin++){
  xMC[iBin] = (MAXX) / 1000. * iBin;
  yMC[iBin] = kFunction.Eval(xMC[iBin]) * xMC[iBin];
 }
 
 TGraph grMC(1000,xMC,yMC);
 grMC.SetMarkerSize(0.2);
 grMC.SetMarkerStyle(20);
 grMC.SetMarkerColor(kGreen);
 grMC.SetFillColor(kGreen);
 grMC.SetLineColor(kGreen);
 
 
 TLegend* leg = new TLegend(0.1,0.7,0.48,0.9);
 leg->AddEntry(h2b_pfx,"DATA CaVa","fl");
 leg->AddEntry(h2_pfx,"MC CaVa","fl");
 leg->AddEntry(&grMC,"MC k function","fl");
 leg->SetFillColor(0);
 
 TCanvas cResultCombined("cResultCombined","cResultCombined",400,1200);
 cResultCombined.Divide(1,3);
  
 cResultCombined.cd(1);
 h2b->Draw("colz");
 h2->SetMarkerColor(kViolet);
 h2->SetLineColor(kViolet);
 h2->Draw("BOXsame");
 gPad->SetGrid();
 
 cResultCombined.cd(2);
 h2b_pfx.Draw("E");
 h2_pfx.Draw("Esame");
 grMC.Draw("Psame");
 leg->Draw();
 gPad->SetGrid();
 
 cResultCombined.cd(3);
 h2b_1.Draw("E");
 h2_1.Draw("Esame");
 grMC.Draw("Psame");
 leg->Draw();
 gPad->SetGrid();
  
}


