{
 
 #include "tdrstyle.C"
 
 setTDRStyle();
 //  tdrStyle->SetOptTitle(1);
 
 
 double globalScale = 1.;
 
 double Lumi = 9.02659e-3;
 
 int NBIN = 40;
 double MIN = 20;
 double MAX = 200;
 
 TString nameCut = Form("MT>30 && abs(Eta)<1.479");// && EoP<3");
 ///=========================================
 
 TFile* fileInW = new TFile("output/out_MC_Wenu.root","READ");
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 TH1F* hEfficiencyW = (TH1F*) fileInW->Get("efficiency");
 hEfficiencyW->Draw();
 double EffW = hEfficiencyW->GetBinContent(1);
 double XsecW = 7899 * 72.68 / 100.;
 double EffLastW = static_cast<double>(MyTreeMC->GetEntries(nameCut.Data())) / MyTreeMC->GetEntries();
 double expectedW = Lumi * XsecW * EffW * EffLastW;
 std::cerr << " ==== W ====" << std::endl; 
 std::cerr << " Expected = " << expectedW << " = " << Lumi << " * " << XsecW << " * " << EffW << " * " << EffLastW << std::endl; 
 std::cerr << " ===========" << std::endl; 
 
 ///=========================================
 TFile* fileInQCDEM2030 = new TFile("output/outW_MC_QCD_EMEnriched_Pt20to30.root","READ");
 TTree* MyTreeMCQCDEM2030 = (TTree*) fileInQCDEM2030->Get("myTree");
 TH1F* hEfficiencyQCDEM2030 = (TH1F*) fileInQCDEM2030->Get("efficiency");
 double EffQCDEM2030 = hEfficiencyQCDEM2030->GetBinContent(1);
 double XsecQCDEM2030 = 0.2355e9 * 0.0073 * 3.5889 / 100.;
 double EffLastQCDEM2030 = static_cast<double>(MyTreeMCQCDEM2030->GetEntries(nameCut.Data())) / MyTreeMCQCDEM2030->GetEntries();
 double expectedQCDEM2030 = Lumi * XsecQCDEM2030 * EffQCDEM2030 * EffLastQCDEM2030;
 std::cerr << " ==== QCDEM2030 ====" << std::endl; 
 std::cerr << " Expected = " << expectedQCDEM2030 << " = " << Lumi << " * " << XsecQCDEM2030 << " * " << EffQCDEM2030 << " * " << EffLastQCDEM2030 << std::endl; 
 std::cerr << " ===========" << std::endl; 
 
 ///=========================================
 TFile* fileInQCDEM3080 = new TFile("output/outW_MC_QCD_EMEnriched_Pt30to80.root","READ");
 TTree* MyTreeMCQCDEM3080 = (TTree*) fileInQCDEM3080->Get("myTree");
 TH1F* hEfficiencyQCDEM3080 = (TH1F*) fileInQCDEM3080->Get("efficiency");
 double EffQCDEM3080 = hEfficiencyQCDEM3080->GetBinContent(1);
 double XsecQCDEM3080 = 0.0593e9 * 0.059 * 8.64 / 100.;
 double EffLastQCDEM3080 = static_cast<double>(MyTreeMCQCDEM3080->GetEntries(nameCut.Data())) / MyTreeMCQCDEM3080->GetEntries();
 double expectedQCDEM3080 = Lumi * XsecQCDEM3080 * EffQCDEM3080 * EffLastQCDEM3080;
 std::cerr << " ==== QCDEM3080 ====" << std::endl; 
 std::cerr << " Expected = " << expectedQCDEM3080 << " = " << Lumi << " * " << XsecQCDEM3080 << " * " << EffQCDEM3080 << " * " << EffLastQCDEM3080 << std::endl; 
 std::cerr << " ===========" << std::endl; 
 
 ///=========================================
 TFile* fileInQCDBCtoE2030 = new TFile("output/outW_MC_QCD_BCtoE_Pt20to30.root","READ");
 TTree* MyTreeMCQCDBCtoE2030 = (TTree*) fileInQCDBCtoE2030->Get("myTree");
 TH1F* hEfficiencyQCDBCtoE2030 = (TH1F*) fileInQCDBCtoE2030->Get("efficiency");
 double EffQCDBCtoE2030 = hEfficiencyQCDBCtoE2030->GetBinContent(1);
 double XsecQCDBCtoE2030 = 0.2355e9 * 0.00046 * (1484. / 40901.);
 double EffLastQCDBCtoE2030 = static_cast<double>(MyTreeMCQCDBCtoE2030->GetEntries(nameCut.Data())) / MyTreeMCQCDBCtoE2030->GetEntries();
 double expectedQCDBCtoE2030 = Lumi * XsecQCDBCtoE2030 * EffQCDBCtoE2030 * EffLastQCDBCtoE2030;
 std::cerr << " ==== QCDBCtoE2030 ====" << std::endl; 
 std::cerr << " Expected = " << expectedQCDBCtoE2030 << " = " << Lumi << " * " << XsecQCDBCtoE2030 << " * " << EffQCDBCtoE2030 << " * " << EffLastQCDBCtoE2030 << std::endl; 
 std::cerr << " ===========" << std::endl; 
 
 ///=========================================
 TFile* fileInQCDBCtoE3080 = new TFile("output/outW_MC_QCD_BCtoE_Pt30to80.root","READ");
 TTree* MyTreeMCQCDBCtoE3080 = (TTree*) fileInQCDBCtoE3080->Get("myTree");
 TH1F* hEfficiencyQCDBCtoE3080 = (TH1F*) fileInQCDBCtoE3080->Get("efficiency");
 double EffQCDBCtoE3080 = hEfficiencyQCDBCtoE3080->GetBinContent(1);
 double XsecQCDBCtoE3080 = 0.0593e9 * 0.00234 * ( 8310. / 50000.);
 double EffLastQCDBCtoE3080 = static_cast<double>(MyTreeMCQCDBCtoE3080->GetEntries(nameCut.Data())) / MyTreeMCQCDBCtoE3080->GetEntries();
 double expectedQCDBCtoE3080 = Lumi * XsecQCDBCtoE3080 * EffQCDBCtoE3080 * EffLastQCDBCtoE3080;
 std::cerr << " ==== QCDBCtoE3080 ====" << std::endl; 
 std::cerr << " Expected = " << expectedQCDBCtoE3080 << " = " << Lumi << " * " << XsecQCDBCtoE3080 << " * " << EffQCDBCtoE3080 << " * " << EffLastQCDBCtoE3080 << std::endl; 
 std::cerr << " ===========" << std::endl; 
 
 ///=========================================
 
 
 TFile* fileInDATA = new TFile("output/outW.root","READ");
 TTree* MyTreeDATA = fileInDATA->Get("myTree");
 TH1F* hEfficiencyDATA = (TH1F*) fileInDATA->Get("efficiency");
 double EffDATA = hEfficiencyDATA->GetBinContent(1);
 
 
 TH1F hDATA_ET("hDATA_ET","hDATA_ET",NBIN,MIN,MAX);
 hDATA_ET.SetTitle("E_{T} (GeV)");
 MyTreeDATA->Draw("ET>>hDATA_ET",nameCut.Data());
 
 hDATA_ET.SetMarkerColor(kRed);
 hDATA_ET.SetMarkerStyle(20);
 hDATA_ET.SetMarkerSize(1.0);
 hDATA_ET.SetLineColor(kRed);
 hDATA_ET.SetLineWidth(2.0);
 hDATA_ET.GetXaxis()->SetTitle("E_{T} (GeV)");
 
 
 ///===============================================
 TH1F hMC_ET("hMC_ET","hMC_ET",NBIN,MIN,MAX);
 hMC_ET.SetTitle("We#nu");
 MyTreeMC->Draw("ET>>hMC_ET",nameCut.Data());
 hMC_ET.SetMarkerColor(kBlue);
 hMC_ET.SetMarkerStyle(20);
 hMC_ET.SetMarkerSize(1.0);
 hMC_ET.SetLineColor(kBlue);
 hMC_ET.SetFillColor(kBlue);
 hMC_ET.SetFillStyle(3001);
 hMC_ET.SetLineWidth(2.0);
 hMC_ET.GetXaxis()->SetTitle("E_{T}");
 // hMC_ET.Sumw2();
//  hMC_ET.Scale(expectedW/hMC_ET.GetEffectiveEntries());
 
 ///===============================================
 TH1F hMC_ET_QCDEM2030("hMC_ET_QCDEM2030","hMC_ET_QCDEM2030",NBIN,MIN,MAX);
 hMC_ET_QCDEM2030.SetTitle("QCD EM 20 - 30");
 MyTreeMCQCDEM2030->Draw("ET>>hMC_ET_QCDEM2030",nameCut.Data());
 hMC_ET_QCDEM2030.SetMarkerColor(kGreen);
 hMC_ET_QCDEM2030.SetMarkerStyle(20);
 hMC_ET_QCDEM2030.SetMarkerSize(1.0);
 hMC_ET_QCDEM2030.SetLineColor(kGreen);
 hMC_ET_QCDEM2030.SetFillColor(kGreen);
 hMC_ET_QCDEM2030.SetFillStyle(3001);
 hMC_ET_QCDEM2030.SetLineWidth(2.0);
 hMC_ET_QCDEM2030.GetXaxis()->SetTitle("E_{T}");
 // hMC_ET_QCDEM2030.Sumw2();
 hMC_ET_QCDEM2030.Scale(expectedQCDEM2030/hMC_ET_QCDEM2030.GetEffectiveEntries());
 
 ///===============================================
 TH1F hMC_ET_QCDEM3080("hMC_ET_QCDEM3080","hMC_ET_QCDEM3080",NBIN,MIN,MAX);
 hMC_ET_QCDEM3080.SetTitle("QCD EM 30 - 80");
 MyTreeMCQCDEM3080->Draw("ET>>hMC_ET_QCDEM3080",nameCut.Data());
 hMC_ET_QCDEM3080.SetMarkerColor(kCyan);
 hMC_ET_QCDEM3080.SetMarkerStyle(20);
 hMC_ET_QCDEM3080.SetMarkerSize(1.0);
 hMC_ET_QCDEM3080.SetLineColor(kCyan);
 hMC_ET_QCDEM3080.SetFillColor(kCyan);
 hMC_ET_QCDEM3080.SetFillStyle(3001);
 hMC_ET_QCDEM3080.SetLineWidth(2.0);
 // hMC_ET_QCDEM3080.Draw();
 hMC_ET_QCDEM3080.GetXaxis()->SetTitle("E_{T}");
 // hMC_ET_QCDEM3080.Sumw2();
 hMC_ET_QCDEM3080.Scale(expectedQCDEM3080/hMC_ET_QCDEM3080.GetEffectiveEntries());
 
 ///===============================================
 TH1F hMC_ET_QCDBCtoE2030("hMC_ET_QCDBCtoE2030","hMC_ET_QCDBCtoE2030",NBIN,MIN,MAX);
 hMC_ET_QCDBCtoE2030.SetTitle("QCD BCtoE 20 - 30");
 MyTreeMCQCDBCtoE2030->Draw("ET>>hMC_ET_QCDBCtoE2030",nameCut.Data());
 hMC_ET_QCDBCtoE2030.SetMarkerColor(kYellow);
 hMC_ET_QCDBCtoE2030.SetMarkerStyle(20);
 hMC_ET_QCDBCtoE2030.SetMarkerSize(1.0);
 hMC_ET_QCDBCtoE2030.SetLineColor(kYellow);
 hMC_ET_QCDBCtoE2030.SetFillColor(kYellow);
 hMC_ET_QCDBCtoE2030.SetFillStyle(3001);
 hMC_ET_QCDBCtoE2030.SetLineWidth(2.0);
 hMC_ET_QCDBCtoE2030.GetXaxis()->SetTitle("E_{T}");
 // hMC_ET_QCDBCtoE2030.Sumw2();
 hMC_ET_QCDBCtoE2030.Scale(expectedQCDBCtoE2030/hMC_ET_QCDBCtoE2030.GetEffectiveEntries());
 
 ///===============================================
 TH1F hMC_ET_QCDBCtoE3080("hMC_ET_QCDBCtoE3080","hMC_ET_QCDBCtoE3080",NBIN,MIN,MAX);
 hMC_ET_QCDBCtoE3080.SetTitle("QCD BCtoE 30 - 80");
 MyTreeMCQCDBCtoE3080->Draw("ET>>hMC_ET_QCDBCtoE3080",nameCut.Data());
 hMC_ET_QCDBCtoE3080.SetMarkerColor(kOrange);
 hMC_ET_QCDBCtoE3080.SetMarkerStyle(20);
 hMC_ET_QCDBCtoE3080.SetMarkerSize(1.0);
 hMC_ET_QCDBCtoE3080.SetLineColor(kOrange);
 hMC_ET_QCDBCtoE3080.SetFillColor(kOrange);
 hMC_ET_QCDBCtoE3080.SetFillStyle(3001);
 hMC_ET_QCDBCtoE3080.SetLineWidth(2.0);
 // hMC_ET_QCDBCtoE3080.Draw();
 hMC_ET_QCDBCtoE3080.GetXaxis()->SetTitle("E_{T}");
 // hMC_ET_QCDBCtoE3080.Sumw2();
 hMC_ET_QCDBCtoE3080.Scale(expectedQCDBCtoE3080/hMC_ET_QCDBCtoE3080.GetEffectiveEntries());
 
 ///===============================================
 
 TH1F hSumMC("hSumMC","hSumMC",NBIN,MIN,MAX);
 
 
 globalScale = hDATA_ET.GetEntries() / (hMC_ET_QCDEM2030.Integral() + hMC_ET_QCDEM3080.Integral() + hMC_ET_QCDBCtoE2030.Integral() + hMC_ET_QCDBCtoE3080.Integral() + hMC_ET.Integral());
 hMC_ET_QCDEM2030.Scale(globalScale);
 hMC_ET_QCDEM3080.Scale(globalScale);
 hMC_ET_QCDBCtoE2030.Scale(globalScale);
 hMC_ET_QCDBCtoE3080.Scale(globalScale);
 hMC_ET.Scale(globalScale);
 
 hSumMC.Add(&hMC_ET_QCDEM2030);
 hSumMC.Add(&hMC_ET_QCDEM3080);
 hSumMC.Add(&hMC_ET_QCDBCtoE2030);
 hSumMC.Add(&hMC_ET_QCDBCtoE3080);
 hSumMC.Add(&hMC_ET);
 
 TCanvas *cResultETStack = new TCanvas("cResultETStack","cResultETStack",10,10,500,500);
 THStack* hs = new THStack("stack","stack");
 hs->SetTitle("E_T (GeV)");
 hs->Add(&hMC_ET_QCDEM2030);
 hs->Add(&hMC_ET_QCDEM3080);
 hs->Add(&hMC_ET_QCDBCtoE2030);
 hs->Add(&hMC_ET_QCDBCtoE3080);
 hs->Add(&hMC_ET);
 
 hDATA_ET.DrawClone("E");
 hs->Draw("same");
 // hs->GetHistogram()->GetXaxis ()->SetTitle ("M_{T}") ;
 gPad->SetGrid(); 
 TLegend* leg = new TLegend(0.1,0.7,0.48,0.9);
 leg->AddEntry(&hMC_ET_QCDEM2030,hMC_ET_QCDEM2030->GetTitle(),"f");
 leg->AddEntry(&hMC_ET_QCDEM3080,hMC_ET_QCDEM3080->GetTitle(),"f");
 leg->AddEntry(&hMC_ET_QCDBCtoE2030,hMC_ET_QCDBCtoE2030->GetTitle(),"f");
 leg->AddEntry(&hMC_ET_QCDBCtoE3080,hMC_ET_QCDBCtoE3080->GetTitle(),"f");
 leg->AddEntry(&hMC_ET,hMC_ET->GetTitle(),"f");
 leg->AddEntry(&hDATA_ET,"Data","flp");
 leg->Draw();
 
 
 // gPad->BuildLegend();
 
 
 ///===========================================
 TCanvas *cResultET = new TCanvas("cResultET","cResultET",10,10,500,500);
 
 hMC_ET.DrawClone("BAR");
 hDATA_ET.DrawClone("Esame");
 
 gPad->SetGrid(); 
 gPad->BuildLegend();
 
 std::cerr << " Kolmogorov = " << hSumMC.KolmogorovTest(&hDATA_ET) << std::endl;
 std::cerr << " globalScale = " << globalScale << std::endl;
 
}



