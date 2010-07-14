{
 TFile* fileInW = new TFile("output/outW_MC.root","READ");
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 
 TFile* fileInDATA = new TFile("output/outW.root","READ");
 TTree* MyTreeDATA = fileInDATA->Get("myTree");
 
 TCanvas *cResultEoP = new TCanvas("cResultEoP","cResultEoP",10,10,500,500);

 TH1F hDATA_Eta("hDATA_Eta","hDATA_Eta",20,-3,3);
 
 hDATA_Eta.SetTitle("EE-");
//  MyTreeDATA->Draw("Eta>>hDATA_Eta","MT>30");
  MyTreeMC->Draw("Eta>>hDATA_Eta","MT>30");
 hDATA_Eta.SetMarkerColor(kRed);
 hDATA_Eta.SetMarkerStyle(20);
 hDATA_Eta.SetMarkerSize(1.0);
 hDATA_Eta.SetLineColor(kRed);
 hDATA_Eta.SetLineWidth(2.0);
 hDATA_Eta.GetXaxis()->SetTitle("#eta");
 hDATA_Eta.DrawClone("E");
 gPad->SetGrid(); 

}



