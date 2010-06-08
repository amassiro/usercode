{
 TFile* fileInW = new TFile("output/outW_MC.root","READ");
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 
 TFile* fileInDATA = new TFile("output/outW.root","READ");
 TTree* MyTreeDATA = fileInDATA->Get("myTree");
 
 TCanvas *cResultMT = new TCanvas("cResultMT","cResultMT",10,10,500,500);

 TH1F hDATA_MT("hDATA_MT","hDATA_MT",20,0,200);
 MyTreeDATA->Draw("MT>>hDATA_MT","abs(Eta)<1.479");
 hDATA_MT.SetMarkerColor(kRed);
 hDATA_MT.SetMarkerStyle(20);
 hDATA_MT.SetMarkerSize(1.0);
 hDATA_MT.SetLineColor(kRed);
 hDATA_MT.SetLineWidth(2.0);
 hDATA_MT.DrawClone("E");
  
}



