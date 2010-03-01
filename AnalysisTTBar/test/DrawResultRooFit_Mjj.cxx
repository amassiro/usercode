{
 
 gROOT->ProcessLine(".x ./test/Style.cxx") ;
 
 TFile *_file1 = TFile::Open("output/out_TT_General_Calibrator_New.root");
 TTree* outTree1 = (TTree*) _file1->Get("outTree"); 
 
 TCanvas c_After("c_After","c_After",800,600);
 
 RooRealVar t_Cycle_num("t_Cycle_num","t_Cycle_num",0,1) ;
 RooRealVar t_Indip("t_Indip","t_Indip",0,1) ;
 RooRealVar t_M_Reco("t_M_Reco","M_{jj}",20,140,"GeV/c^{2}") ;
 RooDataSet ds("ds","ds",RooArgSet(t_Cycle_num,t_Indip,t_M_Reco),RooFit::Import(*outTree1)) ;
 
 RooPlot* frame_t_M_Reco = t_M_Reco.frame(RooFit::Title("Unbinned t_M_Reco")) ;
 t_Indip.setRange("before",-0.1,0.1);
 t_Cycle_num.setRange("before",-0.1,0.1);
 t_Indip.setRange("after",-0.1,0.1);
 t_Cycle_num.setRange("after",0.9,1.1);
 
 t_M_Reco.setRange("reduce",40,120);
  
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
 
}




