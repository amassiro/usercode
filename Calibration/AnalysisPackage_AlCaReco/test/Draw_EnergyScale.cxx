#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
TFile* fileInW;
TFile* fileInDATA;
TFile* outFile;
Double_t DELTA = 1.0;
Int_t NBIN = 40;

double KM(const double *xx ){
 const Double_t scale = xx[0];
 fileInW->cd();
 TTree* MyTreeMC = fileInW->Get("myTree");
 fileInDATA->cd();
 TTree* MyTreeDATA = fileInDATA->Get("myTree");
//  int numDATA = (MyTreeDATA->GetEntries("MT>30"));
 int numDATA = (NBIN);
 TH1F hMC("hMC","hMC",numDATA,0,200);
 TH1F hDATA("hDATA","hDATA",numDATA,0,200);
 TString DrawMC = Form("(ET * (1+%f))>>hMC",scale);
 MyTreeMC->Draw(DrawMC,"MT>30 && abs(Eta)<1.479");
 MyTreeDATA->Draw("ET>>hDATA","MT>30 && abs(Eta)<1.479");
//  hMC.Sumw2();
 hDATA.Sumw2();
 hMC.Scale(1./hMC.GetEntries());
 hDATA.Scale(1./hDATA.GetEntries());
 outFile->cd();
 hDATA.Write();
 hMC.Write();
//  double result = - hMC.KolmogorovTest(&hDATA);
//  double result = hMC.Chi2Test(&hDATA,"CHI2/NDF");
 double result = hMC.Chi2Test(&hDATA,"CHI2");
 //double result = - hMC.Chi2Test(&hDATA,""); ///==== http://root.cern.ch/root/html/TH1.html#TH1:Chi2Test
 return result;
}


void Draw_EnergyScale(){
 ///==== Draw Distributions ====
 
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 
 ///==== W ====
 fileInW = new TFile("output/outW_MC.root","READ");

 ///==== DATA ==== 
 fileInDATA = new TFile("output/outW.root","READ");
 
 ///===================================
 outFile = new TFile("output/outEnergyScale.root","RECREATE");
 
 ///===================================

//  TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
//  TTree* MyTreeDATA = (TTree*) fileInDATA->Get("myTree");
 
//  ROOT::Math::Minimizer* minuit = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
// ROOT::Math::Minimizer* minuit = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Combined");
ROOT::Math::Minimizer* minuit = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Scan");

 ROOT::Math::Functor functor(&KM,1); 
 
 minuit->SetFunction(functor);
 
 minuit->SetMaxFunctionCalls(1000000);
 minuit->SetMaxIterations(100000);
 minuit->SetTolerance(0.0001);
 
 double step[1] = {0.001};
 double variable[1] = {0.0};
 
 // Set the free variables to be minimized!
//  minuit->SetVariable(0,"Scale",variable[0], step[0]);
  
 minuit->SetLimitedVariable(0,"Scale" , variable[0]  , step[0] , -0.5  , 0.5 );
 
 std::cerr << "... I'm minimizing ..." << std::endl;
 ///------------------
 minuit->Minimize(); 
 ///------------------
 std::cerr << "... minimized ..." << std::endl;
 
 const double *outParameters = minuit->X();
 const double *errParameters = minuit->Errors();

 minuit->PrintResults();
 
 std::cerr << ">> Scale = " << outParameters[0] << " +/- " << errParameters[0] << std::endl;
 
// /*/* TMinuit *Minuit = new TMinuit(1);  //initialize TMinuit with a maximum of 1 param  
//  Minuit->SetFCN(KM);
//  
//  double par[1];
//  double stepSize[1] = {0.000001};
//  double minVal[1] = {0.5};
//  double maxVal[1] = {1.5};
//  
//  Int_t ierflg = 0;
//  
//  Minuit->mnparm(0,"Scale",par[0],stepSize[0],minVal[0],maxVal[0],ierflg);
//  
//  ///------------------
//  Minuit->Migrad();
//  ///------------------
//  
//  double outParameter;
//  double errParameter;
//  
//  Minuit->GetParameter(0,outParameter,errParameter);
// //  std::cerr << " Scale = " << outParameters << " +/- " << errParameters << std::endl;
//  */*/
 
 ///----------------------
 ///---- Plot results ----
 ///----------------------
 
 TCanvas *cResult = new TCanvas("cResult","cResult",10,10,800,800);
 cResult->Divide(2,2);
  
 cResult->cd(4);

 Int_t iPar_NoBG = 0;
 Int_t iNoSteps = 1000;
 TGraph * gr = new TGraph(iNoSteps);
 minuit->Scan(iPar_NoBG,iNoSteps,gr->GetX(),gr->GetY(),-0.5,0.5);
 gr->Draw("AL");
 outFile->cd();
 gr->Write();
 
 outParameters = minuit->X();
 errParameters = minuit->Errors();
 minuit->PrintResults();
 std::cerr << ">> Scale = " << outParameters[0] << " +/- " << errParameters[0] << std::endl;
 
 
 double min = gr->Eval(outParameters[0]);
 std::cerr << "==== min Scan = " << min << std::endl;
 double errX_low = -9999;
 double errX_up = 9999;
 int err_low = 0;
 int err_up = 0;
 for (int ii=0; ii < iNoSteps; ii++){
  double X_ii = (0.5+0.5) / iNoSteps * ii - 0.5;
  double here = gr->Eval(X_ii);
  if (err_low == 0){
   //     std::cerr << " => " << here << " < " << min+DELTA << std::endl;
   if (here < (min + DELTA)){
    errX_low = X_ii;
    err_low = 1;
   }
  }
  else if (err_up == 0 && here > (min + DELTA)){
   errX_up = X_ii; 
   err_up = 1;
  }
 }
 std::cerr << ">>>> errX_low:errX_up = " << errX_low << " : " << errX_up << std::endl;
 std::cerr << ">>>> Scale = " << outParameters[0] << " +/- " << errParameters[0] << std::endl;
 
 
 minuit->PrintResults();
 
//  minuit->Scan();
//  TGraph *gr = (TGraph*) minuit->GetPlot();
//  gr->Draw("al");
 
 
 cResult->cd(3);
 
 fileInW->cd();
 TTree* MyTreeMC = fileInW->Get("myTree");
 fileInDATA->cd();
 TTree* MyTreeDATA = fileInDATA->Get("myTree");
//  int numDATA = (MyTreeDATA->GetEntries("MT>30"));
 int numDATA = (NBIN);
 TH1F hMC_BEST("hMC_BEST","hMC_BEST",numDATA,0,200);
 TH1F hDATA_BEST("hDATA_BEST","hDATA_BEST",numDATA,0,200);
 TString DrawMC = Form("(ET * (1+%f))>>hMC_BEST",outParameters[0]);
 MyTreeMC->Draw(DrawMC,"MT>30 && abs(Eta)<1.479");
 MyTreeDATA->Draw("ET>>hDATA_BEST","MT>30 && abs(Eta)<1.479");
 hMC_BEST.Sumw2();
 hDATA_BEST.Sumw2();
 hMC_BEST.Scale(hDATA_BEST.GetEntries()/hMC_BEST.GetEntries());

 hMC_BEST.SetMarkerColor(kBlue);
 hMC_BEST.SetMarkerStyle(20);
 hMC_BEST.SetMarkerSize(1.0);
 hMC_BEST.SetLineColor(kBlue);
 hMC_BEST.SetLineWidth(2.0);
 hMC_BEST.SetFillColor(kBlue);
 hMC_BEST.SetFillStyle(3001);
 
 hDATA_BEST.SetMarkerColor(kRed);
 hDATA_BEST.SetMarkerStyle(20);
 hDATA_BEST.SetMarkerSize(1.0);
 hDATA_BEST.SetLineColor(kRed);
 hDATA_BEST.SetLineWidth(2.0);
 
 
 outFile->cd();
 hDATA_BEST.Write();
 hMC_BEST.Write();
 
 hDATA_BEST.DrawClone("E");
 hDATA_BEST.GetXaxis()->SetTitle("E_{T} GeV");
 hMC_BEST.DrawClone("BARsame");
 gPad->BuildLegend();
 
 
 ///==== scam plot ====
 TLine* lOriz = new TLine(-0.5,min + DELTA,0.5,min + DELTA);
 lOriz->SetLineColor(kRed);
 lOriz->SetLineWidth(4);
 lOriz->SetLineStyle(5);
 
 TLine* lVertLow = new TLine(errX_low,0,errX_low,100);
 lVertLow->SetLineColor(kRed);
 lVertLow->SetLineWidth(4);
 lVertLow->SetLineStyle(5);
 
 TLine* lVertUp = new TLine(errX_up,0,errX_up,100);
 lVertUp->SetLineColor(kRed);
 lVertUp->SetLineWidth(4);
 lVertUp->SetLineStyle(5);
 
 cResult->cd(4);
 gr->Draw("AL"); 
 gr->GetXaxis()->SetTitle("#alpha");
 gr->GetYaxis()->SetTitle("#chi^{2}");
 
 lOriz->Draw();
 lVertLow->Draw();
 lVertUp->Draw();
 
 
 
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



