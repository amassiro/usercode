{
 ///==== Draw Distributions ====
 
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 
 ///==== W ====
 TFile* fileInW = new TFile("output/ValidAlCaTest_WenuMC.root","READ");
//  TFile* fileInW = new TFile("output/ValidAlCaMinBias_Spring10-START3X_V26A_356ReReco-v1_GEN-SIM-RECO_356.root","READ");

 ///==== MinBias ====
 TFile* fileInMinBias = new TFile("output/ValidAlCaMinBias_Spring10-START3X_V26A_356ReReco-v1_GEN-SIM-RECO_356.root","READ"); 
//  TFile* fileInMinBias = new TFile("output/ValidAlCaTestQCD_EMEnriched_Pt20to30.root","READ"); 
 
 ///==== DATA ====
 
 TFile* fileInDATA = new TFile("output/ValidAlCaTestCommissioning10-EcalCalElectron-May27thReReco_v1.root","READ");
 TString nameData = "May27th";
 
 ///===================================
 ///===================================

 TTree* MyTree = (TTree*) fileInW->Get("AlCaValidationTEST/SimpleNtple");
 MyTree->Draw("(met.Et()/sumEt):met.Et()","","colz");

 TTree* MyTreeMinBias = (TTree*) fileInMinBias->Get("AlCaValidationTEST/SimpleNtple");
 MyTreeMinBias->Draw("(met.Et()/sumEt):met.Et()","","boxsame");
 
 
 //  TF1 funzMu_New("funzMu_New","(x<25) * (0.53 * x - 5.33) + (x>=25) * (8)",0,200);
 //  funzMu_New.SetLineWidth(4);
 //  funzMu_New.SetLineColor(kBlue);
 //  funzMu_New.Draw("same");
 
 TF1 funzMu_New("funzMu_New","(-0.07 * x + 3.5) * ((-0.07 * x + 3.5) < 0.4) + (0.4)*((-0.07 * x + 3.5) > 0.4)",0,200);
   funzMu_New.SetLineWidth(4);
   funzMu_New.SetLineColor(kRed);
   funzMu_New.Draw("same");
 
}
