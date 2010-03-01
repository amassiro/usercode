{
 
 gROOT->ProcessLine(".x ./test/Style.cxx") ;
 
 TFile *_file1 = TFile::Open("output/out_TT_General_Calibrator_New_L5L7.root");
 TTree* outTree1 = (TTree*) _file1->Get("outTree"); 
 
 TCanvas c_After("c_After","c_After",800,600);
 
 RooRealVar t_Cycle_num("t_Cycle_num","t_Cycle_num",0,1) ;
 RooRealVar t_Indip("t_Indip","t_Indip",0,1) ;
 RooRealVar t_M_Reco("t_M_Reco","M_{jj}",20,140,"GeV/c^{2}") ;
 RooDataSet ds("ds","ds",RooArgSet(t_Cycle_num,t_Indip,t_M_Reco),RooFit::Import(*outTree1)) ;
 
 RooPlot* frame_t_M_Reco = t_M_Reco.frame(RooFit::Title("Unbinned t_M_Reco")) ;
 t_Indip.setRange("before",0.9,1.1);
 t_Cycle_num.setRange("before",-0.1,0.1);
 t_Indip.setRange("after",0.9,1.1);
 t_Cycle_num.setRange("after",0.9,1.1);
 
 t_M_Reco.setRange("reduce",40,120);
 
 /*
 ds.plotOn(frame_t_M_Reco,RooFit::CutRange("after"),RooFit::MarkerColor(kGreen),RooFit::LineColor(kGreen)) ;
 */
 /*RooRealVar Mean_Fit("Mean_Fit","Mean Fit",0,200);
 RooRealVar Sigma_Fit("Sigma_Fit","Sigma Fit",10.0,0.1,100);
 RooGaussian gauss("gauss","gaussian PDF",t_M_Reco,Mean_Fit,Sigma_Fit);
 gauss.fitTo(ds,RooFit::Range("before"),RooFit::Save(0),RooFit::PrintLevel(1)); 
//  gauss.fitTo(ds,RooFit::Save(0),RooFit::PrintLevel(1)); 
 RooDataSet* ds_before = (RooDataSet*) ds.reduce(RooFit::CutRange("before")) ;
 ds_before.plotOn(frame_t_M_Reco,RooFit::MarkerColor(kRed),RooFit::LineColor(kRed)) ;
//  ds.plotOn(frame_t_M_Reco,RooFit::MarkerColor(kRed),RooFit::LineColor(kRed)) ;
gauss.plotOn(frame_t_M_Reco, RooFit::Name("gauss_before"),RooFit::LineColor(kRed));
// gauss.plotOn(frame_t_M_Reco, RooFit::Name("gauss_before"),RooFit::LineColor(kRed),RooFit::Normalization(1000.0));
//  gauss.plotOn(frame_t_M_Reco, RooFit::Name("gauss"),RooFit::LineColor(kRed));
 /* gauss.fitTo(ds,RooFit::Range("after"),RooFit::Save(0),RooFit::PrintLevel(-1)); 
 gauss.plotOn(frame_t_M_Reco, RooFit::Name("gauss_after"),RooFit::LineColor(kGreen));*/

 
 
 RooRealVar Mean_Fit("Mean_Fit","Mean Fit",0,200,"Gev/c^{2}");
 RooRealVar Sigma_Fit("Sigma_Fit","Sigma Fit",3.0,0.1,100);
 
 RooRealVar Mean_SimpleGauss_Fit("Mean_SimpleGauss_Fit","Mean Mean_SimpleGauss_Fit",0);//1.0,0.9,1.1);
 RooRealVar Sigma_SimpleGauss_Fit("Sigma_SimpleGauss_Fit","Sigma Sigma_SimpleGauss_Fit",1.0,0.001,30.0);
 RooGaussModel simplegauss("simplegauss","gaussian PDF",t_M_Reco,Mean_SimpleGauss_Fit,Sigma_SimpleGauss_Fit);
 RooBreitWigner BW("BW","BW PDF",t_M_Reco,Mean_Fit,Sigma_Fit);
//  RooFFTConvPdf gauss("gauss","BW (X) gauss",t_M_Reco,BW,simplegauss);
 
  RooGaussian gauss("gauss","gaussian PDF",t_M_Reco,Mean_Fit,Sigma_Fit);
 // RooBreitWigner gauss("gauss","gaussian PDF",t_M_Reco,Mean_Fit,Sigma_Fit);
 
 RooRealVar a0("a0","a0",0.9,-1,1);
 RooRealVar a1("a1","a1",0.1,-1,1);
 RooRealVar a2("a2","a2",-0.1,-1,1);
 
 RooRealVar nsig("nsig","signal fraction",1000,0.,10000.) ;
 RooRealVar nbkg("nbkg","background fraction",0,0.,10000.) ;
 
 RooChebychev poly("poly","poly",t_M_Reco,RooArgList(a0,a1,a2));
 RooAddPdf pdfSum("pdfSum","gauss+poly",RooArgList(gauss,poly),RooArgList(nsig,nbkg));
 
 
 t_M_Reco.setRange("toAnalyse",20,140);
 
 
 RooDataSet* ds_before = (RooDataSet*) ds.reduce(RooFit::CutRange("before")) ;
 gauss.fitTo(*ds_before,RooFit::Save(0),RooFit::PrintLevel(-1),RooFit::Hesse (1)); 
 ds_before->plotOn(frame_t_M_Reco,RooFit::MarkerColor(kRed),RooFit::LineColor(kRed)) ;
 gauss.plotOn(frame_t_M_Reco, RooFit::Name("gauss_before"),RooFit::LineColor(kRed));
 gauss.paramOn(frame_t_M_Reco);
 
 RooDataSet* ds_after = (RooDataSet*) ds.reduce(RooFit::CutRange("after")) ;
 gauss.fitTo(*ds_after,RooFit::Save(0),RooFit::PrintLevel(-1)); 
 ds_after->plotOn(frame_t_M_Reco,RooFit::MarkerColor(kGreen),RooFit::LineColor(kGreen)) ;
 gauss.plotOn(frame_t_M_Reco, RooFit::Name("gauss_after"),RooFit::LineColor(kGreen));
 gauss.paramOn(frame_t_M_Reco);
 
 ds_before->statOn(frame_t_M_Reco);
 
 frame_t_M_Reco->Draw() ;

 gPad->SetGrid();
 
 
 /* 
 TH1F htemp0("htemp0","Before",1000,0,200);
 TH1F htemp1("htemp1","After",1000,0,200);
 
 outTree1->Draw("t_M_Reco >> htemp0","t_Cycle_num==0 && t_Indip==0");
 outTree1->Draw("t_M_Reco >> htemp1","t_Cycle_num==1 && t_Indip==0");
 
 htemp0.SetLineColor(kBlue);
 htemp0.SetFillColor(kBlue);
 htemp0.SetFillStyle(3002);
 htemp1.SetLineColor(kRed);
 
 gPad->SetGrid();
 
 TF1 funzPeak("funzPeak","gaus(0)",20,140);
 TF1 funzBkg("funzBkg","pol2(0)",20,140);
 TF1 funz("funz","gaus(0)+pol2(3)",20,140);
 funz.SetParameter(0,10);
 funz.SetParameter(1,80);
 funz.SetParameter(2,10);
 funz.SetParName(1,"Mass");
 funz.SetParName(2,"#sigma");
 htemp0.Fit("funz","RME");
 htemp1.Fit("funz","RME");
 
 funzPeak.SetParameter(0,funz.GetParameter(0));
 funzPeak.SetParameter(1,funz.GetParameter(1));
 funzPeak.SetParameter(2,funz.GetParameter(2));
 funzPeak.SetLineColor(kGreen);
 funzPeak.Draw("same");
 
 gPad->BuildLegend();
 
 
 
 htemp1.Draw();
 htemp0.Draw("same");
 funz.Draw("same");
 funzPeak.Draw("same");
 
 gPad->BuildLegend();
 
 
 
 ///----------------------------------------------------------
 
 TCanvas c_Num("c_Num","c_Num",800,600);
 
 TH2F* hKK_num = (TH2F*) _file1->Get("hKK_num"); 
 hKK_num->Draw("colz");
 
 
 ///----------------------------------------------------------
 
 TCanvas c_Pt("c_Pt","c_Pt",800,600);
 
 
 TH1F htemp0_Pt("htemp0_Pt","Before Pt",1000,0,4);
 TH1F htemp1_Pt("htemp1_Pt","After Pt",1000,0,4);
 
 outTree1->Draw("(t_pT_Reco / t_pT_MC) >> htemp0_Pt","t_Cycle_num==0 && t_Indip==0");
 outTree1->Draw("(t_pT_Reco / t_pT_MC) >> htemp1_Pt","t_Cycle_num==1 && t_Indip==0");
 
 htemp0_Pt.SetLineColor(kBlue);
 htemp0_Pt.SetFillColor(kBlue);
 htemp0_Pt.SetFillStyle(3002);
 htemp1_Pt.SetLineColor(kRed);
 
 gPad->SetGrid();
 
 htemp1_Pt.Draw();
 htemp0_Pt.Draw("same"); 
 gPad->BuildLegend();*/
 
 
}




