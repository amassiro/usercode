{
 
 int NBIN = 10;
 double MIN = 20;
 double MAX = 50;
 
 TFile* fileInW = new TFile("output/outW_MC.root","READ");
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 
 TFile* fileInDATA = new TFile("output/outW.root","READ");
 TTree* MyTreeDATA = fileInDATA->Get("myTree");
 
 TCanvas *cResultEoP = new TCanvas("cResultEoP","cResultEoP",10,10,500,500);

 TH1F hDATA_ET("hDATA_ET","hDATA_ET",NBIN,MIN,MAX);
 hDATA_ET.SetTitle("EB");
 MyTreeDATA->Draw("ET>>hDATA_ET","MT>30 && abs(Eta)<1.479");
  
 hDATA_ET.SetMarkerColor(kRed);
 hDATA_ET.SetMarkerStyle(20);
 hDATA_ET.SetMarkerSize(1.0);
 hDATA_ET.SetLineColor(kRed);
 hDATA_ET.SetLineWidth(2.0);
 hDATA_ET.GetXaxis()->SetTitle("E_{T}");
 
 
 
 TH1F hMC_ET("hMC_ET","hMC_ET",NBIN,MIN,MAX);
 MyTreeMC->Draw("ET>>hMC_ET","MT>30 && abs(Eta)<1.479");
 hMC_ET.SetMarkerColor(kBlue);
 hMC_ET.SetMarkerStyle(20);
 hMC_ET.SetMarkerSize(1.0);
 hMC_ET.SetLineColor(kBlue);
 hMC_ET.SetLineWidth(2.0);
 hMC_ET.GetXaxis()->SetTitle("E_{T}");
 hMC_ET.Sumw2();
 hMC_ET.Scale(hDATA_ET.GetEntries()/hMC_ET.GetEntries());

 hDATA_ET.DrawClone("E");
 hMC_ET.DrawClone("Esame");
 
 gPad->SetGrid(); 
 gPad->BuildLegend();
 
 std::cerr << " Komogorov = " << hMC_ET.KolmogorovTest(&hDATA_ET) << std::endl;
}



