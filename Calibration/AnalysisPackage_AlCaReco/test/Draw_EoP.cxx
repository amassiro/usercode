{
 TFile* fileInW = new TFile("output/outW_MC.root","READ");
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 
 TFile* fileInDATA = new TFile("output/outW.root","READ");
 TTree* MyTreeDATA = fileInDATA->Get("myTree");
 
 TCanvas *cResultEoP = new TCanvas("cResultEoP","cResultEoP",10,10,500,500);

 TH1F hDATA_EoP("hDATA_EoP","hDATA_EoP",20,0.5,5);
 
//  hDATA_EoP.SetTitle("Barrel");
 hDATA_EoP.SetTitle("EE-");
 MyTreeDATA->Draw("EoP>>hDATA_EoP","MT>30 && Eta < -1.479");
//  MyTreeDATA->Draw("EoP>>hDATA_EoP","MT>30 && abs(Eta)<1.479");
//  MyTreeMC->Draw("EoP>>hDATA_EoP","MT>30 && abs(Eta)<1.479");
 hDATA_EoP.SetMarkerColor(kRed);
 hDATA_EoP.SetMarkerStyle(20);
 hDATA_EoP.SetMarkerSize(1.0);
 hDATA_EoP.SetLineColor(kRed);
 hDATA_EoP.SetLineWidth(2.0);
 hDATA_EoP.GetXaxis()->SetTitle("E/p");
 hDATA_EoP.DrawClone("E");
 gPad->SetGrid(); 

}



