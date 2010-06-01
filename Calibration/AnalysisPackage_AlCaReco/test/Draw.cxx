{
 ///==== Validator ====
 int NBINeta = 100;
 int NBINenergy = 100;
 int NBINESCoP = 80;
 int NBINHits = 50;
 
 ///==== MC ====
//  TFile fileInMC ("../output/NAMEOUTPUT_MC.root","READ");

 TFile fileInMC ("../output/EcalCalElectron_Summed.root","READ");
 TString nameMC = "May6th";
// TString nameMC = "/MinimumBias/Commissioning10-May6thReReco_EcalCalElectron-v1/ALCARECO";

// TFile fileInMC ("../output/EcalCalElectron_Summed.root","READ");
// TString nameMC = "May6thReReco_NO_JSON";

// TFile fileInMC ("../output/out_PlotAsValidation_May27_JSON.root","READ");
// TString nameMC = "May27th_JSON";
 

 TH1F etaDistMC ("etaDistMC","etaDistMC",NBINeta,-3,3);
 TH1F energyMC ("energyMC","energyMC",NBINenergy,0,1000);
 TH1F ESCoPMC ("ESCoPMC","ESCoPMC",NBINESCoP,0,20);
 TH1F HitsOeMC ("HitsOeMC","HitsOeMC",NBINHits,0,1.02);
 
 etaDistMC.Sumw2();
 energyMC.Sumw2();
 ESCoPMC.Sumw2();
 HitsOeMC.Sumw2();
 
 TTree* m_tree = (TTree*) fileInMC.Get("m_tree");
 m_tree->SetName("MC");
 m_tree->Draw("eta>>etaDistMC");
 m_tree->Draw("energy>>energyMC");
 m_tree->Draw("ESCoP>>ESCoPMC");
 m_tree->Draw("recHits/energy>>HitsOeMC");
 
 ///==== DATA ====
//  TFile fileInDATA ("../output/EcalCalElectron_Summed.root","READ");

//TFile fileInDATA ("../output/out_PlotAsValidation.root","READ");
//TString nameData = "/EG/Run2010A-EcalCalElectron-v2/ALCARECO ";

// TFile fileInDATA ("../output/out_PlotAsValidation_MinimumBias_Commissioning10_May6thReReco_EcalCalElectron_v1_ALCARECO_JSON.root","READ");
// TString nameData = "May6thReReco_JSON";

 TFile fileInDATA ("../output/out_PlotAsValidation_May27_NOJSON.root","READ");
 TString nameData = "May27th";




 TH1F etaDistDATA ("etaDistDATA","etaDistDATA",NBINeta,-3,3);
 TH1F energyDATA ("energyDATA","energyDATA",NBINenergy,0,1000);
 TH1F ESCoPDATA ("ESCoPDATA","ESCoPDATA",NBINESCoP,0,20);
 TH1F HitsOeDATA ("HitsOeDATA","HitsOeDATA",NBINHits,0,1.02);
 
 etaDistDATA.Sumw2();
 energyDATA.Sumw2();
 ESCoPDATA.Sumw2();
 HitsOeDATA.Sumw2();
 
 TTree* m_treeDATA = (TTree*) fileInDATA.Get("m_tree");
 m_treeDATA->SetName("DATA");
 m_treeDATA->Draw("eta>>etaDistDATA");
 m_treeDATA->Draw("energy>>energyDATA");
 m_treeDATA->Draw("ESCoP>>ESCoPDATA");
 m_treeDATA->Draw("recHits/energy>>HitsOeDATA");
 
 
 
 ///==== Comparator ====
 
 gStyle->SetOptStat(0);
 gStyle->SetOptTitle(0);
 gStyle->SetMarkerStyle(20);
 gStyle->SetMarkerSize(1.0);

 etaDistMC.Scale(1. / etaDistMC.GetEntries() * etaDistDATA.GetEntries());
 energyMC.Scale(1. / energyMC.GetEntries() * energyDATA.GetEntries());
 ESCoPMC.Scale(1. / ESCoPMC.GetEntries() * ESCoPDATA.GetEntries());
 HitsOeMC.Scale(1. / HitsOeMC.GetEntries() * HitsOeDATA.GetEntries());
 
 etaDistMC.SetTitle(nameMC);
 energyMC.SetTitle(nameMC);
 ESCoPMC.SetTitle(nameMC);
 HitsOeMC.SetTitle(nameMC);
 
 etaDistDATA.SetTitle(nameData);
 energyDATA.SetTitle(nameData);
 ESCoPDATA.SetTitle(nameData);
 HitsOeDATA.SetTitle(nameData);

 etaDistMC.SetMarkerStyle(20);
 energyMC.SetMarkerStyle(20);
 ESCoPMC.SetMarkerStyle(20);
 HitsOeMC.SetMarkerStyle(20);
 etaDistDATA.SetMarkerStyle(20);
 energyDATA.SetMarkerStyle(20);
 ESCoPDATA.SetMarkerStyle(20);
 HitsOeDATA.SetMarkerStyle(20);

 etaDistMC.SetMarkerSize(1.0);
 energyMC.SetMarkerSize(1.0);
 ESCoPMC.SetMarkerSize(1.0);
 HitsOeMC.SetMarkerSize(1.0);
 etaDistDATA.SetMarkerSize(1.0);
 energyDATA.SetMarkerSize(1.0);
 ESCoPDATA.SetMarkerSize(1.0);
 HitsOeDATA.SetMarkerSize(1.0);

 
 etaDistMC.SetLineColor(kRed);
 energyMC.SetLineColor(kRed);
 ESCoPMC.SetLineColor(kRed);
 HitsOeMC.SetLineColor(kRed);
 
 etaDistDATA.SetLineColor(kBlue);
 energyDATA.SetLineColor(kBlue);
 ESCoPDATA.SetLineColor(kBlue);
 HitsOeDATA.SetLineColor(kBlue);
 
 etaDistMC.SetMarkerColor(kRed);
 energyMC.SetMarkerColor(kRed);
 ESCoPMC.SetMarkerColor(kRed);
 HitsOeMC.SetMarkerColor(kRed);
 
 etaDistDATA.SetMarkerColor(kBlue);
 energyDATA.SetMarkerColor(kBlue);
 ESCoPDATA.SetMarkerColor(kBlue);
 HitsOeDATA.SetMarkerColor(kBlue);
 

 TLegend* leg = new TLegend(0.1,0.7,0.48,0.9);
 leg->AddEntry(&etaDistDATA,"","l");
 leg->AddEntry(&etaDistMC,"","l");
 
 TLegend* legMiddle = new TLegend(0.3333333,0.190678,0.7140805,0.3898305);
 legMiddle->AddEntry(&etaDistDATA,"","l");
 legMiddle->AddEntry(&etaDistMC,"","l");
 
 TCanvas ccetaDist("ccetaDist","ccetaDist");
 etaDistDATA.GetXaxis().SetTitle("#eta");
 etaDistDATA.Draw("E");
 etaDistMC.Draw("same");
 ccetaDist.SetLogy();
 legMiddle->Draw();
 ccetaDist.SetGrid();
 ccetaDist.SaveAs("./SAMPLE_etaDist.gif");
 
 TCanvas ccenergy("ccenergy","ccenergy");
 energyDATA.GetXaxis()->SetTitle("Energy [GeV]");
 energyDATA.Draw("E");
 energyMC.Draw("same");
 ccenergy.SetLogy();
 ccenergy.BuildLegend();
 ccenergy.SetGrid();
 ccenergy.SaveAs("./SAMPLE_energy_dist.gif");
 
 TCanvas ccESCoP("ccESCoP","ccESCoP");
 ESCoPDATA.GetXaxis()->SetTitle("E_{SC}/p");
 ESCoPDATA.Draw("E");
 ESCoPMC.Draw("same");
 ccESCoP.SetLogy();
 ccESCoP.BuildLegend();
 ccESCoP.SetGrid();
 ccESCoP.SaveAs("./SAMPLE_ESCoP_dist.gif");
 
 TCanvas ccHitsOe("ccHitsOe","ccHitsOe");
 HitsOeDATA.GetXaxis()->SetTitle("#frac{#sum Hits}{energy}");
 HitsOeDATA.Draw("E");
 HitsOeMC.Draw("same");
 ccHitsOe.SetLogy();
 //  ccHitsOe.BuildLegend();
 leg->Draw();
 ccHitsOe.SetGrid(); 
 ccHitsOe.SaveAs("./SAMPLE_HitsOe.gif");
  
}
