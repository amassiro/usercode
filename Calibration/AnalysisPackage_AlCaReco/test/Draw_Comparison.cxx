TH1F* ETMC;
TH1F* etaDistMC;
TH1F* energyMC;
TH1F* ESCoPMC;
TH1F* HitsOeMC;

TH1F* ETDATA;
TH1F* etaDistDATA;
TH1F* energyDATA;
TH1F* ESCoPDATA;
TH1F* HitsOeDATA;

TH1F* ETDATA2;
TH1F* etaDistDATA2;
TH1F* energyDATA2;
TH1F* ESCoPDATA2;
TH1F* HitsOeDATA2;

TH2F* EtPtTMC;
TH2F* EtPtTDATA;
 
#include "tdrstyle.C"
 
bool DoSecond = false;
 
void Draw_Comparison(){
 setTDRStyle();
 
 ///==== Validator ====
 int NBINeta = 25;
 int NBINenergy = 50;
 int NBINESCoP = 80;
 int NBINHits = 50;
 int NBINET = 100;
 
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 
 ///==== MC ====
 TFile* fileInMC = new TFile("../output/out_PlotAsValidation_MinBias_TuneD6T_7TeV_pythia6.root","READ");
//  TFile* fileInMC = new TFile("../output/NAMEOUTPUT_MC.root","READ");
 TString nameMC = "MinBias";
 
 ///==== DATA ====
 
 
 
 TFile* fileInDATA = new TFile("../output/out_PlotAsValidation_Commissioning10-EcalCalElectron-May27thReReco_v1.root","READ");
//  TFile* fileInDATA = new TFile("../output/out_PlotAsValidation_May27_JSON.root","READ");
//  TString nameData = "May27th_AlCaReco";
 TString nameData = "data";
 
 
 TFile* fileInDATA2 = new TFile("../output/out_PlotAsValidation_May27thReReco_JSON_PreProduction_v1_JSON.root","READ");
 TString nameData2 = "May27th_JSON_361_p3";
 
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 


 TString ETY = Form("events/%.1f GeV",200./NBINET);
 TString EtaY = Form("events/%.1f",6./NBINeta);
 TString energyY = Form("events/%.0f GeV",800./NBINenergy);
 TString ESCoPY = Form("events/%.1f",20./NBINESCoP);
 TString OeY = Form("events/%.1f",1.02./NBINHits);

 ETMC = new TH1F("ETMC","ETMC",NBINET,0,200);
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
 m_tree->Draw("ET_SC>>ETMC");
//  m_tree->Draw("energy * sin(2 * atan(exp(-eta)))>>ETMC");
 m_tree->Draw("eta>>etaDistMC");
 m_tree->Draw("energy>>energyMC");
 m_tree->Draw("ESCoP>>ESCoPMC");
 m_tree->Draw("recHits/energy>>HitsOeMC");
 


 ETDATA = new TH1F("ETDATA","ETDATA",NBINET,0,200);
 etaDistDATA = new TH1F("etaDistDATA","etaDistDATA",NBINeta,-3,3);
 energyDATA = new TH1F("energyDATA","energyDATA",NBINenergy,0,800.);
 ESCoPDATA = new TH1F("ESCoPDATA","ESCoPDATA",NBINESCoP,0,20);
 HitsOeDATA = new TH1F("HitsOeDATA","HitsOeDATA",NBINHits,0,1.02);
 
 ETDATA->Sumw2();
 etaDistDATA->Sumw2();
 energyDATA->Sumw2();
 ESCoPDATA->Sumw2();
 HitsOeDATA->Sumw2();
 
 TTree* m_treeDATA = (TTree*) fileInDATA->Get("m_tree");
 m_treeDATA->SetName("DATA");
 m_treeDATA->Draw("ET_SC>>ETDATA");
//  m_treeDATA->Draw("energy * sin(2 * atan(exp(-eta)))>>ETDATA");
 m_treeDATA->Draw("eta>>etaDistDATA");
 m_treeDATA->Draw("energy>>energyDATA");
 m_treeDATA->Draw("ESCoP>>ESCoPDATA");
 m_treeDATA->Draw("recHits/energy>>HitsOeDATA");
 
 
 ETDATA2 = new TH1F("ETDATA2","ETDATA2",NBINET,0,200);
 etaDistDATA2 = new TH1F("etaDistDATA2","etaDistDATA2",NBINeta,-3,3);
 energyDATA2 = new TH1F("energyDATA2","energyDATA2",NBINenergy,0,800.);
 ESCoPDATA2 = new TH1F("ESCoPDATA2","ESCoPDATA2",NBINESCoP,0,20);
 HitsOeDATA2 = new TH1F("HitsOeDATA2","HitsOeDATA2",NBINHits,0,1.02);
 
 ETDATA2->Sumw2();
 etaDistDATA2->Sumw2();
 energyDATA2->Sumw2();
 ESCoPDATA2->Sumw2();
 HitsOeDATA2->Sumw2();
 
 TTree* m_treeDATA2 = (TTree*) fileInDATA2->Get("m_tree");
 m_treeDATA2->SetName("DATA2");
 m_treeDATA2->Draw("ET_SC>>ETDATA2");
//  m_treeDATA2->Draw("energy * sin(2 * atan(exp(-eta)))>>ETDATA2");
 m_treeDATA2->Draw("eta>>etaDistDATA2");
 m_treeDATA2->Draw("energy>>energyDATA2");
 m_treeDATA2->Draw("ESCoP>>ESCoPDATA2");
 m_treeDATA2->Draw("recHits/energy>>HitsOeDATA2");

 
 ///==== Comparator ====
 
 gStyle->SetOptStat(0);
 gStyle->SetOptTitle(0);

 std::cerr << " " << nameMC.Data() << " = " << etaDistMC->GetEntries() << std::endl;
 std::cerr << " " << nameData.Data() << " = " << etaDistDATA->GetEntries() << std::endl;
 std::cerr << " " << nameData2.Data() << " = " << etaDistDATA2->GetEntries() << std::endl;
 
 ETMC->Scale(1. / ETMC->GetEntries() * ETDATA->GetEntries());
 etaDistMC->Scale(1. / etaDistMC->GetEntries() * etaDistDATA->GetEntries());
 energyMC->Scale(1. / energyMC->GetEntries() * energyDATA->GetEntries());
 ESCoPMC->Scale(1. / ESCoPMC->GetEntries() * ESCoPDATA->GetEntries());
 HitsOeMC->Scale(1. / HitsOeMC->GetEntries() * HitsOeDATA->GetEntries());
 
 ETDATA2->Scale(1. / ETDATA2->GetEntries() * ETDATA->GetEntries());
 etaDistDATA2->Scale(1. / etaDistDATA2->GetEntries() * etaDistDATA->GetEntries());
 energyDATA2->Scale(1. / energyDATA2->GetEntries() * energyDATA->GetEntries());
 ESCoPDATA2->Scale(1. / ESCoPDATA2->GetEntries() * ESCoPDATA->GetEntries());
 HitsOeDATA2->Scale(1. / HitsOeDATA2->GetEntries() * HitsOeDATA->GetEntries());
 

 ETMC->SetTitle(nameMC);
 etaDistMC->SetTitle(nameMC);
 energyMC->SetTitle(nameMC);
 ESCoPMC->SetTitle(nameMC);
 HitsOeMC->SetTitle(nameMC);
 
 ETDATA->SetTitle(nameData);
 etaDistDATA->SetTitle(nameData);
 energyDATA->SetTitle(nameData);
 ESCoPDATA->SetTitle(nameData);
 HitsOeDATA->SetTitle(nameData);

 ETDATA2->SetTitle(nameData2);
 etaDistDATA2->SetTitle(nameData2);
 energyDATA2->SetTitle(nameData2);
 ESCoPDATA2->SetTitle(nameData2);
 HitsOeDATA2->SetTitle(nameData2);


 ETMC->SetFillStyle(3001);
 etaDistMC->SetFillStyle(3001);
 energyMC->SetFillStyle(3001);
 ESCoPMC->SetFillStyle(3001);
 HitsOeMC->SetFillStyle(3001);
 ETMC->SetFillColor(kGreen);
 etaDistMC->SetFillColor(kGreen);
 energyMC->SetFillColor(kGreen);
 ESCoPMC->SetFillColor(kGreen);
 HitsOeMC->SetFillColor(kGreen);


 ETMC->SetMarkerStyle(20);
 etaDistMC->SetMarkerStyle(20);
 energyMC->SetMarkerStyle(20);
 ESCoPMC->SetMarkerStyle(20);
 HitsOeMC->SetMarkerStyle(20);
 ETDATA->SetMarkerStyle(20);
 etaDistDATA->SetMarkerStyle(20);
 energyDATA->SetMarkerStyle(20);
 ESCoPDATA->SetMarkerStyle(20);
 HitsOeDATA->SetMarkerStyle(20);
 ETDATA2->SetMarkerStyle(20);
 etaDistDATA2->SetMarkerStyle(20);
 energyDATA2->SetMarkerStyle(20);
 ESCoPDATA2->SetMarkerStyle(20);
 HitsOeDATA2->SetMarkerStyle(20);


 ETMC->SetMarkerSize(1.0);
 etaDistMC->SetMarkerSize(1.0);
 energyMC->SetMarkerSize(1.0);
 ESCoPMC->SetMarkerSize(1.0);
 HitsOeMC->SetMarkerSize(1.0);
 ETDATA->SetMarkerSize(1.0);
 etaDistDATA->SetMarkerSize(1.0);
 energyDATA->SetMarkerSize(1.0);
 ESCoPDATA->SetMarkerSize(1.0);
 HitsOeDATA->SetMarkerSize(1.0);
 ETDATA2->SetMarkerSize(1.0);
 etaDistDATA2->SetMarkerSize(1.0);
 energyDATA2->SetMarkerSize(1.0);
 ESCoPDATA2->SetMarkerSize(1.0);
 HitsOeDATA2->SetMarkerSize(1.0);

 
 ETMC->SetLineColor(kGreen);
 etaDistMC->SetLineColor(kGreen);
 energyMC->SetLineColor(kGreen);
 ESCoPMC->SetLineColor(kGreen);
 HitsOeMC->SetLineColor(kGreen);
 
 ETDATA->SetLineColor(kBlue);
 etaDistDATA->SetLineColor(kBlue);
 energyDATA->SetLineColor(kBlue);
 ESCoPDATA->SetLineColor(kBlue);
 HitsOeDATA->SetLineColor(kBlue);
 ETDATA2->SetLineColor(kRed);
 etaDistDATA2->SetLineColor(kRed);
 energyDATA2->SetLineColor(kRed);
 ESCoPDATA2->SetLineColor(kRed);
 HitsOeDATA2->SetLineColor(kRed);
 
 ETMC->SetMarkerColor(kGreen);
 etaDistMC->SetMarkerColor(kGreen);
 energyMC->SetMarkerColor(kGreen);
 ESCoPMC->SetMarkerColor(kGreen);
 HitsOeMC->SetMarkerColor(kGreen);
 
 ETDATA->SetMarkerColor(kBlue);
 etaDistDATA->SetMarkerColor(kBlue);
 energyDATA->SetMarkerColor(kBlue);
 ESCoPDATA->SetMarkerColor(kBlue);
 HitsOeDATA->SetMarkerColor(kBlue);
 ETDATA2->SetMarkerColor(kRed);
 etaDistDATA2->SetMarkerColor(kRed);
 energyDATA2->SetMarkerColor(kRed);
 ESCoPDATA2->SetMarkerColor(kRed);
 HitsOeDATA2->SetMarkerColor(kRed);
 

 TLegend* leg = new TLegend(0.1,0.7,0.48,0.9);
 leg->AddEntry(etaDistDATA,"","l");
 if (DoSecond) leg->AddEntry(etaDistDATA2,"","l");
 leg->AddEntry(etaDistMC,"","lf");
 
 TLegend* legMiddle = new TLegend(0.3333333,0.190678,0.7140805,0.3898305);
 legMiddle->AddEntry(etaDistDATA,"","l");
 if (DoSecond) legMiddle->AddEntry(etaDistDATA2,"","l");
 legMiddle->AddEntry(etaDistMC,"","lf");
 
 TCanvas* ccET = new TCanvas("ccET","ccET");
 ETMC->Draw("EBAR");
 ETMC->GetXaxis()->SetTitle("E_{T} (GeV)");
 ETMC->GetYaxis()->SetTitle(ETY.Data());
 ETDATA->Draw("Esame");
 ETDATA2->GetXaxis()->SetTitle("E_{T} (GeV)");
 if (DoSecond) ETDATA2->Draw("Esame");
 ccET->SetLogy();
 ccET->BuildLegend();
 ccET->SetGrid();
 ccET->SaveAs("./SAMPLE_ET.gif");
 
 TCanvas* ccetaDist = new TCanvas("ccetaDist","ccetaDist");
 etaDistMC->Draw("EBAR");
 etaDistMC->GetXaxis()->SetTitle("#eta");
 etaDistMC->GetYaxis()->SetTitle(EtaY.Data());
 etaDistDATA->Draw("Esame");
 etaDistDATA2->GetXaxis()->SetTitle("#eta");
 if (DoSecond) etaDistDATA2->Draw("Esame");
 ccetaDist->SetLogy();
 legMiddle->Draw();
 ccetaDist->SetGrid();
 ccetaDist->SaveAs("./SAMPLE_etaDist.gif");
 
 TCanvas* ccenergy = new TCanvas("ccenergy","ccenergy");
 energyMC->Draw("EBAR");
 energyMC->GetXaxis()->SetTitle("Energy [GeV]");
 energyMC->GetYaxis()->SetTitle(energyY.Data());
 energyDATA->Draw("Esame");
 energyDATA2->GetXaxis()->SetTitle("Energy [GeV]");
 if (DoSecond) energyDATA2->Draw("Esame");
 ccenergy->SetLogy();
 ccenergy->BuildLegend();
 ccenergy->SetGrid();
 ccenergy->SaveAs("./SAMPLE_energy_dist.gif");
 
 TCanvas* ccESCoP = new TCanvas("ccESCoP","ccESCoP");
 ESCoPMC->Draw("EBAR");
 ESCoPMC->GetXaxis()->SetTitle("E_{SC}/p");
 ESCoPMC->GetYaxis()->SetTitle(ESCoPY.Data());
 ESCoPDATA->Draw("Esame");
 ESCoPDATA2->GetXaxis()->SetTitle("E_{SC}/p");
 if (DoSecond) ESCoPDATA2->Draw("same");
 ccESCoP->SetLogy();
 ccESCoP->BuildLegend();
 ccESCoP->SetGrid();
 ccESCoP->SaveAs("./SAMPLE_ESCoP_dist.gif");
 
 TCanvas* ccHitsOe = new TCanvas("ccHitsOe","ccHitsOe");
 HitsOeMC->Draw("EBAR");
 HitsOeMC->GetXaxis()->SetTitle("#frac{#sum Hits}{energy}");
 HitsOeMC->GetYaxis()->SetTitle(OeY.Data());
 HitsOeDATA->Draw("Esame");
 HitsOeDATA2->GetXaxis()->SetTitle("#frac{#sum Hits}{energy}");
 if (DoSecond) HitsOeDATA2->Draw("same");
 ccHitsOe->SetLogy();
 //  ccHitsOe->BuildLegend();
 leg->Draw();
 ccHitsOe->SetGrid(); 
 ccHitsOe->SaveAs("./SAMPLE_HitsOe.gif");
  

 
 TCanvas* ccPtEt2D = new TCanvas("ccPtEt2D","ccPtEt2D",800,400);
 ccPtEt2D->Divide(2,1);

 TH2F* EtPtTMC;
 TH2F* EtPtTDATA;

 EtPtTMC = new TH2F("EtPtTMC","EtPtTMC",NBINET,0,200,NBINET,0,200);
 EtPtTDATA = new TH2F("EtPtTDATA","EtPtTDATA",NBINET,0,200,NBINET,0,200);
 
 ccPtEt2D->cd(1);
 m_tree->Draw("(energy * sin(2 * atan(exp(-eta)))) : pT >> EtPtTMC");
 m_treeDATA->Draw("(energy * sin(2 * atan(exp(-eta)))) : pT >> EtPtTDATA");
 
 
 ccPtEt2D->cd(1);
 EtPtTMC->Draw("colz");
 EtPtTMC->GetXaxis()->SetTitle("p_{T}  (GeV/c)");
 EtPtTMC->GetYaxis()->SetTitle("E_{T} (GeV)");
 gPad->SetGrid();
 
 ccPtEt2D->cd(2);
 EtPtTDATA->Draw("colz");
 EtPtTDATA->GetXaxis()->SetTitle("p_{T}  (GeV/c)");
 EtPtTDATA->GetYaxis()->SetTitle("E_{T} (GeV)");
 gPad->SetGrid(); 
 
}
