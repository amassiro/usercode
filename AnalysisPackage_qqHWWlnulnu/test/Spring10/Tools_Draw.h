
void DrawSB(THStack* hs,int numSignal, int numBkg, int sb_bs = 0){ 
 // sb_bs = 0 signal -> bkg
 // sb_bs = 1 bkg    -> signal
 
 TIter Iterator(hs->GetHists());
 TKey *key;
 
 TH1F *vectHist[1000];
 
 TH1F *bkgHist;
 TH1F *sigHist;
 
 TCanvas* cCompare = new TCanvas("cCompare","cCompare",800,800);
 cCompare->Divide(2,2);
 cCompare->cd(1);
 hs->Draw();
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
 double bkg_temp = 0;
 double sig_temp = 0;
 
 int numSample = 0;
 while (key = (TKey *) Iterator()){
  TString nameHisto;
  nameHisto = key->GetName();  
  TH1F* temp_h = gROOT->FindObject(nameHisto);
  vectHist[numSample] = temp_h;
  
  if (sb_bs == 0 && numSample < numSignal) {
   sig_temp += temp_h->Integral();
   std::cerr << " [" << sig_temp << "] " << " >>> sig += " << temp_h->Integral() << " ~ " << temp_h->GetEntries() << "     =>  " << nameHisto.Data() << std::endl;
   if (numSample == 0) {
    sigHist = (TH1F*) temp_h->Clone("signal");
    sigHist->SetTitle("signal");
    std::cerr << "  ====> signal = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
   }
   else sigHist -> Add (temp_h);
  }
  
  if (sb_bs == 0 && numSample >= numSignal) {
   bkg_temp += temp_h->Integral();
   std::cerr << " [" << bkg_temp << "] >>> bkg += " << temp_h->Integral() << " ~ " << temp_h->GetEntries() << "     =>  " << nameHisto.Data() << std::endl;
   if (numSample == numSignal) {
    bkgHist = (TH1F*) temp_h->Clone("background");
    bkgHist->SetTitle("background");
    std::cerr << "  ====> background = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
   }
   else bkgHist -> Add (temp_h);
  }
  
  if (sb_bs == 1 && numSample < numBkg) {
   bkg_temp += temp_h->Integral();
   std::cerr << " [" << bkg_temp << "] >>> bkg += " << temp_h->Integral() << " ~ " << temp_h->GetEntries() << "     =>  " << nameHisto.Data() << std::endl;
   if (numSample == 0) {
    bkgHist = (TH1F*) temp_h->Clone("background");
    bkgHist->SetTitle("background");
    std::cerr << "  ====> background = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
   }
   else bkgHist -> Add (temp_h);
  }
  
  if (sb_bs == 1 && numSample >= numBkg) {
   sig_temp += temp_h->Integral();
   std::cerr << " [" << sig_temp << "] " << " >>> sig += " << temp_h->Integral() << " ~ " << temp_h->GetEntries() << "     =>  " << nameHisto.Data() << std::endl;
   if (numSample == numBkg) {
    sigHist = (TH1F*) temp_h->Clone("signal");
    sigHist->SetTitle("signal");
    std::cerr << "  ====> signal = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
   }
   else sigHist -> Add (temp_h);
  }
  
  std::cerr << " numSample = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
  numSample++;
 }
 
 
 
 ///==================
 TCanvas* cCompareSum = new TCanvas("cCompareSum","cCompareSum",800,800);
 hs->Draw();
 gPad->SetLogy();
 gPad->SetGrid();
//  gPad->BuildLegend();
 ///==================
 
 TCanvas* cHistos = new TCanvas("cHistos","cHistos",600,600);
 cHistos->Divide(sqrt(numSample)+1,sqrt(numSample)+1);
 for (int iSample = 0; iSample < numSample; iSample++){
  cHistos->cd(iSample+1);
  vectHist[iSample]->DrawClone();
 }
 
 ///==================
 TCanvas* cCompareSumSB = new TCanvas("cCompareSumSB","cCompareSumSB",800,800);
 sigHist->SetLineWidth(4);
 bkgHist->SetLineWidth(4);
 sigHist->SetLineColor(kBlue);
 bkgHist->SetLineColor(kRed);
 sigHist->SetMarkerColor(kBlue);
 bkgHist->SetMarkerColor(kRed);
 sigHist->SetMarkerStyle(20);
 bkgHist->SetMarkerStyle(20);
 sigHist->SetMarkerSize(4);
 bkgHist->SetMarkerSize(4);
 sigHist->SetFillColor(0);
 bkgHist->SetFillColor(0);
 bkgHist->DrawNormalized();
 sigHist->DrawNormalized("same");
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
 ///==================
 
 cCompare->cd(2);
 sigHist->SetLineWidth(2);
 bkgHist->SetLineWidth(2);
 sigHist->SetLineColor(kBlue);
 bkgHist->SetLineColor(kRed);
 sigHist->SetMarkerColor(kBlue);
 bkgHist->SetMarkerColor(kRed);
 sigHist->SetFillColor(0);
 bkgHist->SetFillColor(0);
 bkgHist->Draw();
 sigHist->Draw("same");
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 cCompare->cd(3);
 
 
 TH1F* cumulBkg = bkgHist->Clone();
 Double_t* integBkg = bkgHist->GetIntegral();
 for (int iBin = 0; iBin < bkgHist->GetNbinsX(); iBin++){
  integBkg[iBin] = 1 - integBkg[iBin];
 }
 cumulBkg->SetContent(integBkg);
 cumulBkg->Scale(bkgHist->Integral());
 cumulBkg->Draw();
 
 std::cerr << " sig = " << sigHist->Integral() << std::endl;
 std::cerr << " bkg = " << bkgHist->Integral() << std::endl;
 std::cerr << " bkg_temp = " << bkg_temp << std::endl;
 
 TH1F* cumulSig = sigHist->Clone();
 Double_t* integSig = sigHist->GetIntegral();
 for (int iBin = 0; iBin < sigHist->GetNbinsX(); iBin++){
  integSig[iBin] = 1 - integSig[iBin];
 }
 cumulSig->SetContent(integSig);
 cumulSig->Scale(sigHist->Integral());
 cumulSig->Draw("same");
 
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
 

 
 cCompare->cd(4);
 bkgHist->DrawNormalized();
 sigHist->DrawNormalized("same");
 gPad->SetGrid();
 gPad->BuildLegend();
 
}



void DrawSB2D(THStack* hs,int numSignal, int numBkg, int sb_bs = 0){ 
 // sb_bs = 0 signal -> bkg
 // sb_bs = 1 bkg    -> signal
 
 TIter Iterator(hs->GetHists());
 TKey *key;
 
 TH2F *vectHist[1000];
 
 TH2F *bkgHist;
 TH2F *sigHist;
 
 TCanvas* cCompare = new TCanvas("cCompare","cCompare",800,800);
 cCompare->Divide(2,3);
 cCompare->cd(1);
 hs->Draw("lego");
 gPad->SetLogz();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 int numSample = 0;
 while (key = (TKey *) Iterator()){
  TString nameHisto;
  nameHisto = key->GetName();  
  std::cerr << " numSample = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
  TH2F* temp_h = gROOT->FindObject(nameHisto);
  vectHist[numSample] = temp_h;
  
  if (sb_bs == 0 && numSample < numSignal) {
   if (numSample == 0) {
    sigHist = (TH2F*) temp_h->Clone("signal");
    sigHist->SetTitle("signal");
    std::cerr << "  ====> signal = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
   }
   else sigHist -> Add (temp_h);
  }
  
  if (sb_bs == 0 && numSample >= numSignal) {
   if (numSample == numSignal) {
    bkgHist = (TH2F*) temp_h->Clone("background");
    bkgHist->SetTitle("background");
    std::cerr << "  ====> background = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
   }
   else bkgHist -> Add (temp_h);
  }
  
  if (sb_bs == 1 && numSample < numBkg) {
   if (numSample == 0) {
    bkgHist = (TH2F*) temp_h->Clone("background");
    bkgHist->SetTitle("background");
    std::cerr << "  ====> background = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
   }
   else bkgHist -> Add (temp_h);
  }
  
  if (sb_bs == 1 && numSample >= numBkg) {
   if (numSample == numBkg) {
    sigHist = (TH2F*) temp_h->Clone("signal");
    sigHist->SetTitle("signal");
    std::cerr << "  ====> signal = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
   }
   else sigHist -> Add (temp_h);
  }
  
  numSample++;
 }
 
 TCanvas* cHistos = new TCanvas("cHistos","cHistos",600,600);
 cHistos->Divide(sqrt(numSample)+1,sqrt(numSample)+1);
 for (int iSample = 0; iSample < numSample; iSample++){
  cHistos->cd(iSample+1);
  vectHist[iSample]->DrawClone("colz");
 }
 
 cCompare->cd(2);
 sigHist->SetLineWidth(1);
 bkgHist->SetLineWidth(1);
//  sigHist->SetFillColor(kBlue);
//  bkgHist->SetFillColor(kRed);
 sigHist->SetLineColor(kBlue);
 bkgHist->SetLineColor(kRed);
 sigHist->SetMarkerColor(kBlue);
 bkgHist->SetMarkerColor(kRed);
 bkgHist->Draw("LEGO");
 sigHist->Draw("LEGOsame");
 //  gPad->SetLogz();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 cCompare->cd(3);
 //  bkgHist->Draw("scat");
 //  sigHist->Draw("scatsame");
 sigHist->Draw("LEGO");
 gPad->SetLogz();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 cCompare->cd(4);
//  bkgHist->Draw("BOX");
//  sigHist->Draw("BOXsame");
 
 bkgHist->SetContour (5);
 sigHist->SetContour (5);
 bkgHist->Draw("cont3");
 sigHist->Draw("cont3same");
 //  gPad->SetLogz();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 cCompare->cd(5); 
 THStack* hs2D = new THStack("stack2D","stack2D");
 hs2D->Add(bkgHist);
 hs2D->Add(sigHist);
 hs2D->Draw();
 gPad->SetLogz();
 gPad->SetGrid();
 
 cCompare->cd(6); 
 bkgHist->Draw("LEGO");
 gPad->SetLogz();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 
}