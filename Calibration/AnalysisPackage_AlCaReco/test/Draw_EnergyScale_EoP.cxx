#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
TFile* fileInW;
TFile* fileInDATA;
TFile* outFile;
Double_t DELTA = 0.5;
Int_t NBIN = 40;

double pT;
double ET;
double MT;
double EoP;


double MinScan = -0.1;
double MaxScan = 0.8;
Int_t iNoSteps = 1000;


int NBINTemplate = 100;
double MinTemplate = 0.5;
double MaxTemplate = 5;
double Delta = (MaxTemplate - MinTemplate) / NBINTemplate;
// TH1F* hMC;

double KM(const double *xx ){
 const Double_t scale = xx[0];
 fileInW->cd();
 TTree* MyTreeMC = fileInW->Get("myTree");
 fileInDATA->cd();
 TTree* MyTreeDATA = fileInDATA->Get("myTree");
 int numDATA = (NBIN);
 TH1F hMC("hMC","hMC",numDATA,0,4);
 TH1F hDATA("hDATA","hDATA",numDATA,0,4);
 TString DrawMC = Form("(EoP * (1+%f))>>hMC",scale);
 MyTreeMC->Draw(DrawMC,"MT>30 && abs(Eta)>1.479");
 MyTreeDATA->Draw("EoP>>hDATA","MT>30 && abs(Eta)>1.479");
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

 
 
 ///==== Likelihood ====
 /*

 fileInW->cd();
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 
 fileInDATA->cd();
 TTree* MyTreeDATA = (TTree*) fileInDATA->Get("myTree");
 MyTreeDATA->SetBranchAddress("pT",&pT);
 MyTreeDATA->SetBranchAddress("ET",&ET);
 MyTreeDATA->SetBranchAddress("MT",&MT);
 MyTreeDATA->SetBranchAddress("EoP",&EoP);
 
 
//  outFile->cd();
 TH1F hMC("hMC","hMC",NBINTemplate,MinTemplate,MaxTemplate);
//  TH1F* hMC = (TH1F*) gDirectory->Get("hMC");
 hMC.Reset();
 TString DrawMC = Form("(EoP * (1+%f))>>hMC",scale);
 MyTreeMC->Draw(DrawMC,"MT>30 && abs(Eta)>1.479");
//  hMC.Scale(1./MyTreeMC->GetEntries("MT>30 && abs(Eta)<1.47"));
 int numberDATA = (MyTreeDATA->GetEntries("MT>30 && abs(Eta)>1.479"));
 double result = 1.;
 for (int iEvt = 0; iEvt < numberDATA; iEvt ++){
  MyTreeDATA->GetEntry(iEvt);
  if (MT > 30){
   int bin = ( EoP - MinTemplate ) / Delta;
   if (bin > 0 && bin < NBINTemplate){
//     if (hMC.GetBinContent(bin) != 0) 
     result *= (hMC.GetBinContent(bin));
    if (hMC.GetBinContent(bin) == 0) {
     std::cerr << " result = " << result << " hMC.GetBinContent(" << bin << ":" << NBINTemplate << ") = " << hMC.GetBinContent(bin) << " scale = " << scale << std::endl;
    }
   }
  }
 }
 outFile->cd();
 hMC.Write();
 
 if (result != 0) result = -log(result);*/
 
 ///==== end Likelihood ====
 
//  std::cerr << " result = " << result << " scale = " << scale << std::endl;
 
 return result;
}


void Draw_EnergyScale_EoP(){
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
 outFile->cd();
//  hMC->Write();
 
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
  
  minuit->SetLimitedVariable(0,"Scale" , variable[0]  , step[0] , MinScan  , MaxScan);
 
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
 TGraph * gr = new TGraph(iNoSteps);
 minuit->Scan(iPar_NoBG,iNoSteps,gr->GetX(),gr->GetY(),MinScan,MaxScan);
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
  double X_ii = (MaxScan - MinScan) / iNoSteps * ii + MinScan;
  double here = gr->Eval(X_ii);
  if (err_low == 0){
   //     std::cerr << " => " << here << " < " << min+DELTA << std::endl;
   if (here < (min + DELTA)){
    errX_low = X_ii;
    err_low = 1;
   }
  }
  else if (err_up == 0 && here > (min + DELTA) && X_ii > outParameters[0]){
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
 TH1F hMC_BEST("hMC_BEST","hMC_BEST",numDATA,0,4);
 TH1F hDATA_BEST("hDATA_BEST","hDATA_BEST",numDATA,0,4);
 TString DrawMC = Form("(EoP * (1+%f))>>hMC_BEST",outParameters[0]);
 MyTreeMC->Draw(DrawMC,"MT>30 && abs(Eta)>1.479");
 MyTreeDATA->Draw("EoP>>hDATA_BEST","MT>30 && abs(Eta)>1.479");
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
 hDATA_BEST.GetXaxis()->SetTitle("E SC / P");
 hMC_BEST.DrawClone("BARsame");
 gPad->BuildLegend();
 
 
 ///==== scam plot ====
 TLine* lOriz = new TLine(MinScan,min + DELTA,MaxScan,min + DELTA);
 lOriz->SetLineColor(kRed);
 lOriz->SetLineWidth(4);
 lOriz->SetLineStyle(5);
 
 TLine* lVertLow = new TLine(errX_low,min-100,errX_low,min+100);
 lVertLow->SetLineColor(kRed);
 lVertLow->SetLineWidth(4);
 lVertLow->SetLineStyle(5);
 
 TLine* lVertUp = new TLine(errX_up,min-100,errX_up,min+100);
 lVertUp->SetLineColor(kRed);
 lVertUp->SetLineWidth(4);
 lVertUp->SetLineStyle(5);
 
 cResult->cd(4);
 TString TitleGr = Form("#alpha = %f - %f + %f",outParameters[0],outParameters[0]-errX_low,errX_up-outParameters[0]);
 gr->SetTitle(TitleGr);
 gr->Draw("AL"); 
 lOriz->Draw();
 lVertLow->Draw();
 lVertUp->Draw();
 
 std::cerr << "End ... " << std::endl;
}



