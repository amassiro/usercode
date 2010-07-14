 TH1F* etaDistMC;
 TH1F* energyMC;
 TH1F* ESCoPMC;
 TH1F* HitsOeMC;
 
 TH1F* SwissCrossDistDATA;
 TH1F* etaDistDATA;
 TH1F* energyDATA;
 TH1F* ESCoPDATA;
 TH1F* HitsOeDATA;
 
 TH1F* SwissCrossDistDATA2;
 TH1F* etaDistDATA2;
 TH1F* energyDATA2;
 TH1F* ESCoPDATA2;
 TH1F* HitsOeDATA2;
 
 
void Draw_SwissCross(){
 ///==== Validator ====
 int NBINeta = 50;
 int NBINenergy = 100;
 int NBINESCoP = 80;
 int NBINHits = 50;
 int NBINSwissCross = 50;
 
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 
 
 ///==== MC ====
 TFile* fileInMC = new TFile("/home/andrea/Cern/Code/WeCalib/AnalysisPackage_AlCaReco/output/out_PlotAsValidation_MinBias_TuneD6T_7TeV_pythia6.root","READ");
 TString nameMC = "MC_MinBias";
 
 ///==== DATA ====
 
 TFile* fileInDATA = new TFile("/home/andrea/Cern/Code/WeCalib/AnalysisPackage_AlCaReco/output/out_PlotAsValidation_Run2010A-EcalCalElectron-Jun9thReReco_v1.root","READ");
 TString nameData = "Run2010A-EcalCalElectron-Jun9thReReco_v1";
 
 
 TFile* fileInDATA2 = new TFile("/home/andrea/Cern/Code/WeCalib/AnalysisPackage_AlCaReco/output/out_PlotAsValidation_Run2010A-EcalCalElectron-May27thReReco_v1.root","READ");
 TString nameData2 = "Run2010A-EcalCalElectron-May27thReReco_v1";
 
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 

 etaDistMC = new TH1F("etaDistMC","etaDistMC",NBINeta,-3,3);
 energyMC = new TH1F("energyMC","energyMC",NBINenergy,0,800);
 ESCoPMC = new TH1F("ESCoPMC","ESCoPMC",NBINESCoP,0,20);
 HitsOeMC = new TH1F("HitsOeMC","HitsOeMC",NBINHits,0,1.02);
 
 etaDistMC->Sumw2();
 energyMC->Sumw2();
 ESCoPMC->Sumw2();
 HitsOeMC->Sumw2();
 
 TTree* m_tree = (TTree*) fileInMC->Get("m_tree");
 m_tree->SetName("MC");
 m_tree->Draw("eta>>etaDistMC");
 m_tree->Draw("energy>>energyMC");
 m_tree->Draw("ESCoP>>ESCoPMC");
 m_tree->Draw("recHits/energy>>HitsOeMC");
 


 
 SwissCrossDistDATA = new TH1F("SwissCrossDistDATA","SwissCrossDistDATA",NBINSwissCross,0,1.5); 
 etaDistDATA = new TH1F("etaDistDATA","etaDistDATA",NBINeta,-3,3);
 energyDATA = new TH1F("energyDATA","energyDATA",NBINenergy,0,1000);
 ESCoPDATA = new TH1F("ESCoPDATA","ESCoPDATA",NBINESCoP,0,20);
 HitsOeDATA = new TH1F("HitsOeDATA","HitsOeDATA",NBINHits,0,1.02);
 
 SwissCrossDistDATA->Sumw2();
 etaDistDATA->Sumw2();
 energyDATA->Sumw2();
 ESCoPDATA->Sumw2();
 HitsOeDATA->Sumw2();
 
 TTree* m_treeDATA = (TTree*) fileInDATA->Get("m_tree");
 m_treeDATA->SetName("DATA");
 m_treeDATA->Draw("(1-SwissE4/MaxEnergy)>>SwissCrossDistDATA");
 m_treeDATA->Draw("eta>>etaDistDATA");
 m_treeDATA->Draw("energy>>energyDATA");
 m_treeDATA->Draw("ESCoP>>ESCoPDATA");
 m_treeDATA->Draw("recHits/energy>>HitsOeDATA");
 
 SwissCrossDistDATA2 = new TH1F("SwissCrossDistDATA2","SwissCrossDistDATA2",NBINSwissCross,0,1.5); 
 etaDistDATA2 = new TH1F("etaDistDATA2","etaDistDATA2",NBINeta,-3,3);
 energyDATA2 = new TH1F("energyDATA2","energyDATA2",NBINenergy,0,1000);
 ESCoPDATA2 = new TH1F("ESCoPDATA2","ESCoPDATA2",NBINESCoP,0,20);
 HitsOeDATA2 = new TH1F("HitsOeDATA2","HitsOeDATA2",NBINHits,0,1.02);
 
 SwissCrossDistDATA2->Sumw2();
 etaDistDATA2->Sumw2();
 energyDATA2->Sumw2();
 ESCoPDATA2->Sumw2();
 HitsOeDATA2->Sumw2();
 
 TTree* m_treeDATA2 = (TTree*) fileInDATA2->Get("m_tree");
 m_treeDATA2->SetName("DATA2");
 m_treeDATA2->Draw("(1-SwissE4/MaxEnergy)>>SwissCrossDistDATA2");
 m_treeDATA2->Draw("eta>>etaDistDATA2");
 m_treeDATA2->Draw("energy>>energyDATA2");
 m_treeDATA2->Draw("ESCoP>>ESCoPDATA2");
 m_treeDATA2->Draw("recHits/energy>>HitsOeDATA2");

 
 ///==== Comparator ====
 
 gStyle->SetOptStat(0);
 gStyle->SetOptTitle(0);

 etaDistMC->Scale(1. / etaDistMC->GetEntries() * etaDistDATA->GetEntries());
 energyMC->Scale(1. / energyMC->GetEntries() * energyDATA->GetEntries());
 ESCoPMC->Scale(1. / ESCoPMC->GetEntries() * ESCoPDATA->GetEntries());
 HitsOeMC->Scale(1. / HitsOeMC->GetEntries() * HitsOeDATA->GetEntries());
 
//  SwissCrossDistDATA2->Scale(1. / etaDistDATA2->GetEntries() * etaDistDATA->GetEntries());
 etaDistDATA2->Scale(1. / etaDistDATA2->GetEntries() * etaDistDATA->GetEntries());
 energyDATA2->Scale(1. / energyDATA2->GetEntries() * energyDATA->GetEntries());
 ESCoPDATA2->Scale(1. / ESCoPDATA2->GetEntries() * ESCoPDATA->GetEntries());
 HitsOeDATA2->Scale(1. / HitsOeDATA2->GetEntries() * HitsOeDATA->GetEntries());
 

 etaDistMC->SetTitle(nameMC);
 energyMC->SetTitle(nameMC);
 ESCoPMC->SetTitle(nameMC);
 HitsOeMC->SetTitle(nameMC);
 
 SwissCrossDistDATA->SetTitle(nameData);
 etaDistDATA->SetTitle(nameData);
 energyDATA->SetTitle(nameData);
 ESCoPDATA->SetTitle(nameData);
 HitsOeDATA->SetTitle(nameData);

 SwissCrossDistDATA2->SetTitle(nameData2);
 etaDistDATA2->SetTitle(nameData2);
 energyDATA2->SetTitle(nameData2);
 ESCoPDATA2->SetTitle(nameData2);
 HitsOeDATA2->SetTitle(nameData2);


 etaDistMC->SetFillStyle(3001);
 energyMC->SetFillStyle(3001);
 ESCoPMC->SetFillStyle(3001);
 HitsOeMC->SetFillStyle(3001);
 etaDistMC->SetFillColor(kGreen);
 energyMC->SetFillColor(kGreen);
 ESCoPMC->SetFillColor(kGreen);
 HitsOeMC->SetFillColor(kGreen);


 etaDistMC->SetMarkerStyle(20);
 energyMC->SetMarkerStyle(20);
 ESCoPMC->SetMarkerStyle(20);
 HitsOeMC->SetMarkerStyle(20);
 SwissCrossDistDATA->SetMarkerStyle(20);
 etaDistDATA->SetMarkerStyle(20);
 energyDATA->SetMarkerStyle(20);
 ESCoPDATA->SetMarkerStyle(20);
 HitsOeDATA->SetMarkerStyle(20);
 SwissCrossDistDATA2->SetMarkerStyle(20);
 etaDistDATA2->SetMarkerStyle(20);
 energyDATA2->SetMarkerStyle(20);
 ESCoPDATA2->SetMarkerStyle(20);
 HitsOeDATA2->SetMarkerStyle(20);


 etaDistMC->SetMarkerSize(1.0);
 energyMC->SetMarkerSize(1.0);
 ESCoPMC->SetMarkerSize(1.0);
 HitsOeMC->SetMarkerSize(1.0);
 SwissCrossDistDATA->SetMarkerSize(1.0);
 etaDistDATA->SetMarkerSize(1.0);
 energyDATA->SetMarkerSize(1.0);
 ESCoPDATA->SetMarkerSize(1.0);
 HitsOeDATA->SetMarkerSize(1.0);
 SwissCrossDistDATA2->SetMarkerSize(1.0);
 etaDistDATA2->SetMarkerSize(1.0);
 energyDATA2->SetMarkerSize(1.0);
 ESCoPDATA2->SetMarkerSize(1.0);
 HitsOeDATA2->SetMarkerSize(1.0);

 
 etaDistMC->SetLineColor(kGreen);
 energyMC->SetLineColor(kGreen);
 ESCoPMC->SetLineColor(kGreen);
 HitsOeMC->SetLineColor(kGreen);
 
 SwissCrossDistDATA->SetLineColor(kBlue);
 etaDistDATA->SetLineColor(kBlue);
 energyDATA->SetLineColor(kBlue);
 ESCoPDATA->SetLineColor(kBlue);
 HitsOeDATA->SetLineColor(kBlue);
 SwissCrossDistDATA2->SetLineColor(kRed);
 etaDistDATA2->SetLineColor(kRed);
 energyDATA2->SetLineColor(kRed);
 ESCoPDATA2->SetLineColor(kRed);
 HitsOeDATA2->SetLineColor(kRed);
 
 etaDistMC->SetMarkerColor(kGreen);
 energyMC->SetMarkerColor(kGreen);
 ESCoPMC->SetMarkerColor(kGreen);
 HitsOeMC->SetMarkerColor(kGreen);
 
 SwissCrossDistDATA->SetMarkerColor(kBlue);
 etaDistDATA->SetMarkerColor(kBlue);
 energyDATA->SetMarkerColor(kBlue);
 ESCoPDATA->SetMarkerColor(kBlue);
 HitsOeDATA->SetMarkerColor(kBlue);
 SwissCrossDistDATA2->SetMarkerColor(kRed);
 etaDistDATA2->SetMarkerColor(kRed);
 energyDATA2->SetMarkerColor(kRed);
 ESCoPDATA2->SetMarkerColor(kRed);
 HitsOeDATA2->SetMarkerColor(kRed);
 

 TLegend* leg = new TLegend(0.1,0.7,0.48,0.9);
 leg->AddEntry(etaDistDATA,"","l");
 leg->AddEntry(etaDistDATA2,"","l");
 leg->AddEntry(etaDistMC,"","lf");
 
 TLegend* legMiddle = new TLegend(0.3333333,0.190678,0.7140805,0.3898305);
 legMiddle->AddEntry(etaDistDATA,"","l");
 legMiddle->AddEntry(etaDistDATA2,"","l");
 legMiddle->AddEntry(etaDistMC,"","lf");
 
 TCanvas* ccetaDist = new TCanvas("ccetaDist","ccetaDist");
 etaDistMC->Draw("BAR");
 etaDistMC->GetXaxis()->SetTitle("#eta");
 etaDistDATA->Draw("Esame");
 etaDistDATA2->GetXaxis()->SetTitle("#eta");
 etaDistDATA2->Draw("Esame");
 ccetaDist->SetLogy();
 legMiddle->Draw();
 ccetaDist->SetGrid();
 ccetaDist->SaveAs("./SAMPLE_etaDist.gif");
 
 TCanvas* ccenergy = new TCanvas("ccenergy","ccenergy");
 energyMC->Draw("BAR");
 energyMC->GetXaxis()->SetTitle("Energy [GeV]");
 energyDATA->Draw("Esame");
 energyDATA2->GetXaxis()->SetTitle("Energy [GeV]");
 energyDATA2->Draw("Esame");
 ccenergy->SetLogy();
 ccenergy->BuildLegend();
 ccenergy->SetGrid();
 ccenergy->SaveAs("./SAMPLE_energy_dist.gif");
 
 TCanvas* ccESCoP = new TCanvas("ccESCoP","ccESCoP");
 ESCoPMC->Draw("BAR");
 ESCoPMC->GetXaxis()->SetTitle("E_{SC}/p");
 ESCoPDATA->Draw("Esame");
 ESCoPDATA2->GetXaxis()->SetTitle("E_{SC}/p");
 ESCoPDATA2->Draw("same");
 ccESCoP->SetLogy();
 ccESCoP->BuildLegend();
 ccESCoP->SetGrid();
 ccESCoP->SaveAs("./SAMPLE_ESCoP_dist.gif");
 
 TCanvas* ccHitsOe = new TCanvas("ccHitsOe","ccHitsOe");
 HitsOeMC->Draw("BAR");
 HitsOeMC->GetXaxis()->SetTitle("#frac{#sum Hits}{energy}");
 HitsOeDATA->Draw("Esame");
 HitsOeDATA2->GetXaxis()->SetTitle("#frac{#sum Hits}{energy}");
 HitsOeDATA2->Draw("same");
 ccHitsOe->SetLogy();
 //  ccHitsOe->BuildLegend();
 leg->Draw();
 ccHitsOe->SetGrid(); 
 ccHitsOe->SaveAs("./SAMPLE_HitsOe.gif");
  
 
 TCanvas* ccSwissCross = new TCanvas("ccSwissCross","ccSwissCross");
 SwissCrossDistDATA->Draw("E");
 SwissCrossDistDATA->GetXaxis()->SetTitle("1-#frac{E4}{E1}");
 SwissCrossDistDATA2->Draw("Esame");
 SwissCrossDistDATA2->GetXaxis()->SetTitle("1-#frac{E4}{E1}");
 ccSwissCross->SetLogy();
 ccSwissCross->BuildLegend();
 ccSwissCross->SetGrid(); 
 ccSwissCross->SaveAs("./SAMPLE_ccSwissCross.gif");
}
