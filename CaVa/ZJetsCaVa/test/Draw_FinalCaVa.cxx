{
 int nIter = 20;
 int NBINX = 70;
 int NBINY = 70;
 double MAXX = 600;
 double MAXY = 500;
 
 
 TTree* tree = ((TTree*) _file0->Get("myTree"));  
 nIter = tree->GetMaximum("IterNumber");
 std::cerr << "nIter = " << nIter << std::endl;
 
//  nIter = 15;
 
 TCanvas cResult("cResult","cResult",800,1200);
 cResult.Divide(2,3);
 
 
 ///==== MC information ====
 cResult.cd(1);
 TH2F* h2 = new TH2F("h2","h2",NBINX,0,MAXX,NBINY,0,MAXY);
 TString drawH2 = Form("xMC:xRECO >> h2");
 tree->Draw(drawH2,"IterNumber==0","colz");
 h2->GetXaxis()->SetTitle("Q^{R}");
 h2->GetYaxis()->SetTitle("Q^{T}");
 h2->Draw("colz");
 gPad->SetGrid();
 
 h2.ProfileX();
 h2_pfx.SetMarkerStyle(20);
 h2_pfx.SetMarkerSize(0.5);
 h2_pfx.SetMarkerColor(kBlue);
 h2_pfx.SetLineWidth(2);
 h2_pfx.SetFillColor(kBlue);
 h2_pfx.SetLineColor(kBlue);
 h2_pfx.GetXaxis()->SetTitle("Q^{R}");
 h2_pfx.GetYaxis()->SetTitle("Q^{T}");
 
 h2.FitSlicesY(0,0,-1,0,"G2");
 h2_1.SetMarkerStyle(20);
 h2_1.SetMarkerSize(0.5);
 h2_1.SetMarkerColor(kBlue);
 h2_1.SetFillColor(kBlue);
 h2_1.SetLineWidth(2);
 h2_1.SetLineColor(kBlue);
 h2_1->GetXaxis()->SetTitle("Q^{R}");
 h2_1->GetYaxis()->SetTitle("Q^{T}");
 
 
 ///==== DATA information ====
 cResult.cd(2);
 TString cutH2 = Form("IterNumber == %d",nIter);
 TString nameH2b = Form("nameH2b_%d",nIter);
 TH2F* h2b = new TH2F(nameH2b.Data(),nameH2b.Data(),NBINX,0,MAXX,NBINY,0,MAXY);
 TString drawH2b = Form("xRECOMC:xRECO >> nameH2b_%d",nIter);
 tree->Draw(drawH2b,cutH2,"colz");
 h2b->GetXaxis()->SetTitle("Q^{R}");
 h2b->GetYaxis()->SetTitle("Q^{T}");
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
 h2b_1->GetXaxis()->SetTitle("Q^{R}");
 h2b_1->GetYaxis()->SetTitle("Q^{T}");
 
   
 h2b.ProfileX();
 TString nameH2b_pfx = Form("nameH2b_%d_pfx",nIter);
 TH1F* h2b_pfx = gDirectory->Get(nameH2b_pfx);
 h2b_pfx.SetMarkerStyle(22);
 h2b_pfx.SetMarkerSize(0.5);
 h2b_pfx.SetMarkerColor(kRed);
 h2b_pfx.SetFillColor(kRed);
 h2b_pfx.SetLineWidth(2);
 h2b_pfx.SetLineColor(kRed);
 h2b_pfx.GetXaxis()->SetTitle("Q^{R}");
 h2b_pfx.GetYaxis()->SetTitle("Q^{T}");
  

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
 
 
 TLegend* leg = new TLegend(0.1,0.7,0.48,0.9);
 leg->AddEntry(h2b_pfx,"DATA","fl");
 leg->AddEntry(h2_pfx,"MC","fl");
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
 leg->Draw();
 gPad->SetGrid();
 
 cResultCombined.cd(3);
 h2b_1.Draw("E");
 h2_1.Draw("Esame");
 leg->Draw();
 gPad->SetGrid();
 

 
 
}


