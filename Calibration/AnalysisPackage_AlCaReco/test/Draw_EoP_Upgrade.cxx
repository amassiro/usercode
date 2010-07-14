{
 #include "myStack.C"
 #include "tdrstyle.C"
 
 setTDRStyle();
 //  tdrStyle->SetOptTitle(1);
 
 
 double globalScale = 1.;
 
// double Lumi = 9.02659e-3; // + 3.42e-3;
 double Lumi = 51.870299e-3; // + 3.42e-3; 

 int NBIN = 20;
 double MIN = 0;
 double MAX = 2;
 
 // TString nameCut = Form("EoP<3");// && abs(Eta)<1.479");// && EoP<3");
 TString nameCut = Form("MT>30 && EoP<2 && ET>18");// && abs(Eta)<1.479");// && EoP<3");
 bool DoScale = true;
 bool DoZee = false;
 ///=========================================
 
 TFile* fileInW = new TFile("output/out_MC_Wenu.root","READ");
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 TH1F* hEfficiencyW = (TH1F*) fileInW->Get("efficiency");
 hEfficiencyW->Draw();
 double EffW = hEfficiencyW->GetBinContent(1);
 double XsecW = 10312 * 0.779 * 72.68 / 100.;
// double XsecW = 7899 * 0.779 * 72.68 / 100.;
 double EffLastW = static_cast<double>(MyTreeMC->GetEntries(nameCut.Data())) / MyTreeMC->GetEntries();
 double expectedW = Lumi * XsecW * EffW * EffLastW;
 std::cerr << " ==== W ====" << std::endl; 
 std::cerr << " num@end   = " << MyTreeMC->GetEntries(nameCut.Data()) << std::endl;
 std::cerr << " num@begin = " << MyTreeMC->GetEntries() * 100. / 72.68 / EffW << std::endl;
 std::cerr << " EffW      = " << EffW << std::endl;
 std::cerr << " EffLastW  = " << EffLastW << std::endl;
 std::cerr << " EffLastW * EffW = " << EffLastW*EffW << std::endl;
 std::cerr << " MyTreeMC->GetEntries()      = " << MyTreeMC->GetEntries() << std::endl;
 std::cerr << " Expected = " << expectedW << " = " << Lumi << " * " << XsecW << " * " << EffW << " * " << EffLastW << std::endl; 
 std::cerr << " ===========" << std::endl; 
 
 ///=========================================
 TFile* fileInZee = new TFile("output/outW_MC_Zee.root","READ");
 TTree* MyTreeMCZee = (TTree*) fileInZee->Get("myTree");
 TH1F* hEfficiencyZee = (TH1F*) fileInZee->Get("efficiency");
 double EffZee = hEfficiencyZee->GetBinContent(1);
 double XsecZee = 1300 * 48.97 * 3.5889 / 100.;
 double EffLastZee = static_cast<double>(MyTreeMCZee->GetEntries(nameCut.Data())) / MyTreeMCZee->GetEntries();
 double expectedZee = Lumi * XsecZee * EffZee * EffLastZee;
 std::cerr << " ==== Zee ====" << std::endl; 
 std::cerr << " Expected = " << expectedZee << " = " << Lumi << " * " << XsecZee << " * " << EffZee << " * " << EffLastZee << std::endl; 
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
 
 
//  TFile* fileInDATA = new TFile("output/outW_Summed.root","READ");
// TFile* fileInDATA = new TFile("output/outW.root","READ");
 TFile* fileInDATA = new TFile("output/outW_DATA_Run2010A-EcalCalElectron-v4.root","READ"); ////////////////////============= NUOVO !!!

    
 TTree* MyTreeDATA = fileInDATA->Get("myTree");
 TH1F* hEfficiencyDATA = (TH1F*) fileInDATA->Get("efficiency");
 double EffDATA = hEfficiencyDATA->GetBinContent(1);
 
 
 TH1F hDATA_EoP_temp("hDATA_EoP_temp","hDATA_EoP_temp",NBIN,MIN,MAX);
 hDATA_EoP_temp.GetXaxis()->SetTitle("E/p");
 TString AxisY = Form("events/%.0f",(MAX-MIN)/NBIN);
 hDATA_EoP_temp.GetYaxis()->SetTitle(AxisY.Data());
 
 TH1F hDATA_EoP("hDATA_EoP","hDATA_EoP",NBIN,MIN,MAX);
 hDATA_EoP.SetTitle("E/p");
 MyTreeDATA->Draw("EoP>>hDATA_EoP",nameCut.Data());
 
 hDATA_EoP.SetMarkerColor(kBlack);
 hDATA_EoP.SetMarkerStyle(20);
 hDATA_EoP.SetMarkerSize(2.0);
 hDATA_EoP.SetLineColor(kBlack);
 hDATA_EoP.SetLineWidth(2.0);
 hDATA_EoP.GetXaxis()->SetTitle("E/p");
 hDATA_EoP.GetYaxis()->SetTitle(AxisY.Data());
 
 
 ///===============================================
 TH1F hMC_EoP("hMC_EoP","hMC_EoP",NBIN,MIN,MAX);
 hMC_EoP.SetTitle("We#nu");
 MyTreeMC->Draw("EoP>>hMC_EoP",nameCut.Data());
 hMC_EoP.SetMarkerColor(kBlue);
 hMC_EoP.SetMarkerStyle(20);
 hMC_EoP.SetMarkerSize(1.0);
 hMC_EoP.SetLineColor(kBlue);
 hMC_EoP.SetFillColor(kBlue);
 hMC_EoP.SetFillStyle(3005);
 hMC_EoP.SetLineWidth(2.0);
 hMC_EoP.GetXaxis()->SetTitle("E/p");
 TString EoPY = Form("events/%.1f",static_cast<double>(MAX-MIN)/NBIN);
 hMC_EoP.GetYaxis()->SetTitle(EoPY.Data());
 hMC_EoP.Sumw2();
 hMC_EoP.Scale(expectedW/hMC_EoP.GetEffectiveEntries());
 
 ///===============================================
 TH1F hMC_EoP_Zee("hMC_EoP_Zee","hMC_EoP_Zee",NBIN,MIN,MAX);
 hMC_EoP_Zee.SetTitle("Zee");
 MyTreeMCZee->Draw("EoP>>hMC_EoP_Zee",nameCut.Data());
 hMC_EoP_Zee.SetMarkerColor(kTeal);
 hMC_EoP_Zee.SetMarkerStyle(20);
 hMC_EoP_Zee.SetMarkerSize(1.0);
 hMC_EoP_Zee.SetLineColor(kTeal);
 hMC_EoP_Zee.SetFillColor(kTeal);
 hMC_EoP_Zee.SetFillStyle(3005);
 hMC_EoP_Zee.SetLineWidth(2.0);
 hMC_EoP_Zee.GetXaxis()->SetTitle("E/p");
 hMC_EoP_Zee.Sumw2();
 hMC_EoP_Zee.Scale(expectedZee/hMC_EoP_Zee.GetEffectiveEntries());

 ///===============================================
 TH1F hMC_EoP_QCDEM2030("hMC_EoP_QCDEM2030","hMC_EoP_QCDEM2030",NBIN,MIN,MAX);
 hMC_EoP_QCDEM2030.SetTitle("QCD EM 20 - 30");
 MyTreeMCQCDEM2030->Draw("EoP>>hMC_EoP_QCDEM2030",nameCut.Data());
 hMC_EoP_QCDEM2030.SetMarkerColor(kGreen);
 hMC_EoP_QCDEM2030.SetMarkerStyle(20);
 hMC_EoP_QCDEM2030.SetMarkerSize(1.0);
 hMC_EoP_QCDEM2030.SetLineColor(kGreen);
 hMC_EoP_QCDEM2030.SetFillColor(kGreen);
 hMC_EoP_QCDEM2030.SetFillStyle(3005);
 hMC_EoP_QCDEM2030.SetLineWidth(2.0);
 hMC_EoP_QCDEM2030.GetXaxis()->SetTitle("E/p");
 hMC_EoP_QCDEM2030.Sumw2();
 hMC_EoP_QCDEM2030.Scale(expectedQCDEM2030/hMC_EoP_QCDEM2030.GetEffectiveEntries());
 
 ///===============================================
 TH1F hMC_EoP_QCDEM3080("hMC_EoP_QCDEM3080","hMC_EoP_QCDEM3080",NBIN,MIN,MAX);
 hMC_EoP_QCDEM3080.SetTitle("QCD EM 30 - 80");
 MyTreeMCQCDEM3080->Draw("EoP>>hMC_EoP_QCDEM3080",nameCut.Data());
 hMC_EoP_QCDEM3080.SetMarkerColor(kCyan);
 hMC_EoP_QCDEM3080.SetMarkerStyle(20);
 hMC_EoP_QCDEM3080.SetMarkerSize(1.0);
 hMC_EoP_QCDEM3080.SetLineColor(kCyan);
 hMC_EoP_QCDEM3080.SetFillColor(kCyan);
 hMC_EoP_QCDEM3080.SetFillStyle(3006);
 hMC_EoP_QCDEM3080.SetLineWidth(2.0);
 // hMC_EoP_QCDEM3080.Draw();
 hMC_EoP_QCDEM3080.GetXaxis()->SetTitle("E/p");
 hMC_EoP_QCDEM3080.Sumw2();
 hMC_EoP_QCDEM3080.Scale(expectedQCDEM3080/hMC_EoP_QCDEM3080.GetEffectiveEntries());
 
 ///===============================================
 TH1F hMC_EoP_QCDBCtoE2030("hMC_EoP_QCDBCtoE2030","hMC_EoP_QCDBCtoE2030",NBIN,MIN,MAX);
 hMC_EoP_QCDBCtoE2030.SetTitle("QCD BCtoE 20 - 30");
 MyTreeMCQCDBCtoE2030->Draw("EoP>>hMC_EoP_QCDBCtoE2030",nameCut.Data());
 hMC_EoP_QCDBCtoE2030.SetMarkerColor(kYellow);
 hMC_EoP_QCDBCtoE2030.SetMarkerStyle(20);
 hMC_EoP_QCDBCtoE2030.SetMarkerSize(1.0);
 hMC_EoP_QCDBCtoE2030.SetLineColor(kYellow);
 hMC_EoP_QCDBCtoE2030.SetFillColor(kYellow);
 hMC_EoP_QCDBCtoE2030.SetFillStyle(3007);
 hMC_EoP_QCDBCtoE2030.SetLineWidth(2.0);
 hMC_EoP_QCDBCtoE2030.GetXaxis()->SetTitle("E/p");
 hMC_EoP_QCDBCtoE2030.Sumw2();
 hMC_EoP_QCDBCtoE2030.Scale(expectedQCDBCtoE2030/hMC_EoP_QCDBCtoE2030.GetEffectiveEntries());
 
 ///===============================================
 TH1F hMC_EoP_QCDBCtoE3080("hMC_EoP_QCDBCtoE3080","hMC_EoP_QCDBCtoE3080",NBIN,MIN,MAX);
 hMC_EoP_QCDBCtoE3080.SetTitle("QCD BCtoE 30 - 80");
 MyTreeMCQCDBCtoE3080->Draw("EoP>>hMC_EoP_QCDBCtoE3080",nameCut.Data());
 hMC_EoP_QCDBCtoE3080.SetMarkerColor(kOrange);
 hMC_EoP_QCDBCtoE3080.SetMarkerStyle(20);
 hMC_EoP_QCDBCtoE3080.SetMarkerSize(1.0);
 hMC_EoP_QCDBCtoE3080.SetLineColor(kOrange);
 hMC_EoP_QCDBCtoE3080.SetFillColor(kOrange);
 hMC_EoP_QCDBCtoE3080.SetFillStyle(3004);
 hMC_EoP_QCDBCtoE3080.SetLineWidth(2.0);
 // hMC_EoP_QCDBCtoE3080.Draw();
 hMC_EoP_QCDBCtoE3080.GetXaxis()->SetTitle("E/p");
 hMC_EoP_QCDBCtoE3080.Sumw2();
 hMC_EoP_QCDBCtoE3080.Scale(expectedQCDBCtoE3080/hMC_EoP_QCDBCtoE3080.GetEffectiveEntries());
 
 ///===============================================
 
 TH1F hSumMC("hSumMC","hSumMC",NBIN,MIN,MAX);
 TH1F hSumQCD("hSumQCD","hSumQCD",NBIN,MIN,MAX);
 
 if (DoZee) globalScale = hDATA_EoP.GetEffectiveEntries() / (hMC_EoP_Zee.Integral() + hMC_EoP_QCDEM2030.Integral() + hMC_EoP_QCDEM3080.Integral() + hMC_EoP_QCDBCtoE2030.Integral() + hMC_EoP_QCDBCtoE3080.Integral() + hMC_EoP.Integral());
 else globalScale = hDATA_EoP.GetEffectiveEntries() / (hMC_EoP_QCDEM2030.Integral() + hMC_EoP_QCDEM3080.Integral() + hMC_EoP_QCDBCtoE2030.Integral() + hMC_EoP_QCDBCtoE3080.Integral() + hMC_EoP.Integral());

 if (DoScale) {
  hMC_EoP_Zee.Scale(globalScale);
  hMC_EoP_QCDEM2030.Scale(globalScale);
  hMC_EoP_QCDEM3080.Scale(globalScale);
  hMC_EoP_QCDBCtoE2030.Scale(globalScale);
  hMC_EoP_QCDBCtoE3080.Scale(globalScale);
  hMC_EoP.Scale(globalScale);
 }

 if (DoZee) hSumMC.Add(&hMC_EoP_Zee); 
 hSumMC.Add(&hMC_EoP_QCDEM2030);
 hSumMC.Add(&hMC_EoP_QCDEM3080);
 hSumMC.Add(&hMC_EoP_QCDBCtoE2030);
 hSumMC.Add(&hMC_EoP_QCDBCtoE3080);
 hSumMC.Add(&hMC_EoP);
 
 
 hSumQCD.Add(&hMC_EoP_QCDEM2030);
 hSumQCD.Add(&hMC_EoP_QCDEM3080);
 hSumQCD.Add(&hMC_EoP_QCDBCtoE2030);
 hSumQCD.Add(&hMC_EoP_QCDBCtoE3080);

 hSumQCD.SetTitle("QCD");
 hSumQCD.SetMarkerColor(kRed);
 hSumQCD.SetMarkerStyle(20);
 hSumQCD.SetMarkerSize(1.0);
 hSumQCD.SetLineColor(kRed);
 hSumQCD.SetFillColor(kRed);
 hSumQCD.SetFillStyle(3004);
 hSumQCD.SetLineWidth(2.0);
 
 
 TCanvas *cResultEoPStack = new TCanvas("cResultEoPStack","cResultEoPStack",10,10,500,500);
 THStack* hs = new THStack("stack","stack");
 hs->SetTitle("M_T (GeV)");
 if (DoZee) hs->Add(&hMC_EoP_Zee);
 hs->Add(&hMC_EoP_QCDEM2030);
 hs->Add(&hMC_EoP_QCDEM3080);
 hs->Add(&hMC_EoP_QCDBCtoE2030);
 hs->Add(&hMC_EoP_QCDBCtoE3080);
 hs->Add(&hMC_EoP);
 
 // hDATA_EoP.DrawClone("same");
 hDATA_EoP_temp.Draw();
 // hs->DrawClone();
 DrawStack(hs);
 hDATA_EoP.DrawClone("Esame");
 // hDATA_EoP.DrawClone("Esame");
 // hs->GetHistogram()->GetXaxis ()->SetTitle ("E/p") ;
 gPad->SetGrid(); 
 TLegend* leg = new TLegend(0.1,0.7,0.48,0.9);
 if (DoZee) leg->AddEntry(&hMC_EoP_Zee,hMC_EoP_Zee->GetTitle(),"f");
 leg->AddEntry(&hMC_EoP_QCDEM2030,hMC_EoP_QCDEM2030->GetTitle(),"f");
 leg->AddEntry(&hMC_EoP_QCDEM3080,hMC_EoP_QCDEM3080->GetTitle(),"f");
 leg->AddEntry(&hMC_EoP_QCDBCtoE2030,hMC_EoP_QCDBCtoE2030->GetTitle(),"f");
 leg->AddEntry(&hMC_EoP_QCDBCtoE3080,hMC_EoP_QCDBCtoE3080->GetTitle(),"f");
 leg->AddEntry(&hMC_EoP,hMC_EoP->GetTitle(),"f");
 leg->AddEntry(&hDATA_EoP,"Data","flp");
 leg->Draw();
 
 
 // gPad->BuildLegend();
 
 
 ///===========================================
 TCanvas *cResultEoP = new TCanvas("cResultEoP","cResultEoP",10,10,500,500);
 
 hMC_EoP.DrawClone("BAR");
 hDATA_EoP.DrawClone("Esame");
 
 gPad->SetGrid(); 
 gPad->BuildLegend();
 
 std::cerr << " Kolmogorov = " << hSumMC.KolmogorovTest(&hDATA_EoP,"X") << std::endl;
 std::cerr << " Chi2       = " << hSumMC.Chi2Test(&hDATA_EoP,"CHI2") << " => " << hSumMC.Chi2Test(&hDATA_EoP,"WU") << std::endl;
 
 std::cerr << " Kolmogorov = " << hDATA_EoP.KolmogorovTest(&hSumMC,"X") << std::endl;
 std::cerr << " Chi2       = " << hDATA_EoP.Chi2Test(&hSumMC,"CHI2") << " => " << hDATA_EoP.Chi2Test(&hSumMC,"UW") << std::endl;

 std::cerr << " Chi2 NORM  = " << hDATA_EoP.Chi2Test(&hSumMC,"CHI2") << " => " << hDATA_EoP.Chi2Test(&hSumMC,"NORM") << std::endl; 
 std::cerr << " globalScale = " << globalScale << std::endl;
 std::cerr << " data measured = " << hDATA_EoP.GetEffectiveEntries() << std::endl;
 
 
 std::cerr << " num MC" << std::endl;
 std::cerr << " " << hMC_EoP.GetTitle() << " = " << hMC_EoP.GetEffectiveEntries() << std::endl;
 std::cerr << " " << hMC_EoP_Zee.GetTitle() << " = " << hMC_EoP_Zee.GetEffectiveEntries() << std::endl;
 std::cerr << " " << hMC_EoP_QCDEM2030.GetTitle() << " = " << hMC_EoP_QCDEM2030.GetEffectiveEntries() << std::endl;
 std::cerr << " " << hMC_EoP_QCDEM3080.GetTitle() << " = " << hMC_EoP_QCDEM3080.GetEffectiveEntries() << std::endl;
 std::cerr << " " << hMC_EoP_QCDBCtoE2030.GetTitle() << " = " << hMC_EoP_QCDBCtoE2030.GetEffectiveEntries() << std::endl;
 std::cerr << " " << hMC_EoP_QCDBCtoE3080.GetTitle() << " = " << hMC_EoP_QCDBCtoE3080.GetEffectiveEntries() << std::endl;
 
 std::cerr << "==============================================" << std::endl;
 std::cerr << " MC expected" << std::endl;
 std::cerr << " " << hMC_EoP.GetTitle() << " = " << hMC_EoP.Integral() << std::endl;
 std::cerr << " " << hMC_EoP_Zee.GetTitle() << " = " << hMC_EoP_Zee.Integral() << std::endl;
 std::cerr << " " << hMC_EoP_QCDEM2030.GetTitle() << " = " << hMC_EoP_QCDEM2030.Integral() << std::endl;
 std::cerr << " " << hMC_EoP_QCDEM3080.GetTitle() << " = " << hMC_EoP_QCDEM3080.Integral() << std::endl;
 std::cerr << " " << hMC_EoP_QCDBCtoE2030.GetTitle() << " = " << hMC_EoP_QCDBCtoE2030.Integral() << std::endl;
 std::cerr << " " << hMC_EoP_QCDBCtoE3080.GetTitle() << " = " << hMC_EoP_QCDBCtoE3080.Integral() << std::endl;
 
 
 
 ///===========================================
 
 TCanvas *cResultEoPStackQCDSummed = new TCanvas("cResultEoPStackQCDSummed","cResultEoPStackQCDSummed",10,10,500,500);
 cResultEoPStackQCDSummed->cd(1);
 THStack* hsQCDSummed = new THStack("hsQCDSummed","hsQCDSummed");
 hsQCDSummed->SetTitle("E_T (GeV)");
 if (DoZee) hsQCDSummed->Add(&hMC_EoP_Zee);
 hsQCDSummed->Add(&hSumQCD);
 hsQCDSummed->Add(&hMC_EoP);
 
//  hDATA_EoP_temp.Draw();
 DrawStack(hsQCDSummed);
 hDATA_EoP.DrawClone("Esame");
 
 gPad->SetGrid(); 
 
 TLegend* legQCDSummed = new TLegend(0.1,0.7,0.48,0.9);
 legQCDSummed->SetFillColor(0);
 if (DoZee) legQCDSummed->AddEntry(&hMC_EoP_Zee,hMC_EoP_Zee->GetTitle(),"f");
 legQCDSummed->AddEntry(&hSumQCD,hSumQCD->GetTitle(),"f");
 legQCDSummed->AddEntry(&hMC_EoP,hMC_EoP->GetTitle(),"f");
 legQCDSummed->AddEntry(&hDATA_EoP,"Data","flp");
 legQCDSummed->Draw();
 
 
  TPaveText *pt = new TPaveText(1.2,20,2.0,40,"br");
   pt->SetFillColor(19);
   pt->SetBorderSize(1);
   pt->SetFillStyle(0);
   TText *text = pt->AddText("CMS Preliminary");
   pt->Draw();

   cResultEoPStackQCDSummed->Modified();
   cResultEoPStackQCDSummed->cd();
}



