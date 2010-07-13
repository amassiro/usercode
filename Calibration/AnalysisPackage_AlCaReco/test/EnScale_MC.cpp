#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include "TFile.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TH1F.h"

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "TRandom.h"
#include "TGraph.h"
#include "TROOT.h"

#include "TF1.h"

TFile* fileInW;
TFile* outFile;

Double_t ScaleTrue = -0.03;
TCanvas* temp = new TCanvas("temp","temp",20,20);

double MinScan = -0.3;
double MaxScan = 0.3;
unsigned int iNoSteps = 1000;

int maxIter = 1000;
Int_t numEvents = 100;
int nIter = 0;

Double_t DELTA_CHI2 = 1.0;
Double_t DELTA_LL = 0.5;

std::vector<double> vET_data;

int NBINTemplate = 90.0;
double MinTemplate = 10.0;
double MaxTemplate = 100.0;
double Delta = (MaxTemplate - MinTemplate) / NBINTemplate;

TString AdditionalCut = Form("MT>30");
double minET = 30; ///==== used in generation of sample


double LLFunc(const double *xx ){
 const Double_t scale = xx[0];

 ///==== Likelihood ==== 
 fileInW->cd();
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 TString NameMC = Form("hMC_%.5f",scale);
 TH1F* hMC;
 if (!gROOT->FindObject(NameMC.Data())){
  hMC = new TH1F(NameMC,NameMC,NBINTemplate,MinTemplate,MaxTemplate);
  hMC->Reset();
  TString DrawMC = Form("(ET * (1+%f))>>%s",scale,NameMC.Data());
  MyTreeMC->Draw(DrawMC,AdditionalCut.Data());
  hMC->Scale(1./numEvents);
  outFile->cd();
  hMC->Write();
 }
 else {
//   std::cerr << " LL old " << NameMC.Data() << std::endl;
  hMC = (TH1F*) outFile->Get(NameMC.Data());
 }
 int numberDATA = vET_data.size();
 double result = 1.;
 
 for (int iEvt = 0; iEvt < numberDATA; iEvt ++){
  double ET = vET_data.at(iEvt);
  int bin = ( ET - MinTemplate ) / Delta;
  if (bin > 0 && bin < NBINTemplate){
   result *= (hMC->GetBinContent(bin));
//    if (hMC->GetBinContent(bin) == 0) {
//     std::cerr << " result = " << result << " hMC.GetBinContent(" << bin << ":" << NBINTemplate << ") = " << hMC.GetBinContent(bin) << " scale = " << scale << std::endl;
//    }
  }
 }
//  outFile->cd();
//  hMC.Write();
 
 if (result != 0) result = -log(result);
 else result = numberDATA * numEvents;
 
 ///==== end Likelihood ====    

 return result;
}








double Chi2F(const double *xx ){
 const Double_t scale = xx[0];
 fileInW->cd();
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 outFile->cd();
 TString nameDATA = Form("hDATA_%d",nIter);
 TH1F* hDATA = (TH1F*) outFile->Get(nameDATA);
 TString NameMC = Form("hMC_Chi2_%.5f",scale);
 
//  std::cerr << " NameMC = "  << NameMC.Data() << " => " << scale << std::endl;
 
 TH1F* hMC;
 if (!gROOT->FindObject(NameMC.Data())){
  hMC = new TH1F(NameMC,NameMC,numEvents,0,200);
  hMC->Reset();
  TString DrawMC = Form("(ET * (1+%f))>>%s",scale,NameMC.Data());
  MyTreeMC->Draw(DrawMC,AdditionalCut.Data());
  hMC->Sumw2();
  hMC->Scale(hDATA->GetEntries()/hMC->GetEntries());
  outFile->cd();
  hMC->Write();
 }
 else {
//   std::cerr << " KM old "  << NameMC.Data() << std::endl;
  hMC = (TH1F*) outFile->Get(NameMC.Data());
 }
 
 outFile->cd();
//  hDATA.Write();
//  hMC.Write();
//  double result = - hMC.KolmogorovTest(&hDATA);
//  double result = hMC.Chi2Test(&hDATA,"CHI2/NDF");
 double result = hMC->Chi2Test(hDATA,"CHI2");
 //double result = - hMC.Chi2Test(&hDATA,""); ///==== http://root.cern.ch/root/html/TH1.html#TH1:Chi2Test
 return result;
}


double myChi2(TH1F* hMC, TH1F* hDATA){
 double result = 0;
 int numBin = hMC->GetNbinsX();
 for (int iBin=0; iBin<numBin; iBin++){
  double mc = hMC->GetBinContent(iBin+1);
  double data = hDATA->GetBinContent(iBin+1);
  if (mc!=0) result += ((mc - data) * (mc - data) / mc);
 }
 return result;
}


double NewChi2Func(const double *xx ){
 const Double_t scale = xx[0];
 fileInW->cd();
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 outFile->cd();
 TString nameDATA = Form("hDATA_%d",nIter);
 TH1F* hDATA = (TH1F*) outFile->Get(nameDATA);
 
 TString NameMC = Form("hMC_Chi2_%.5f",scale);
 TH1F* hMC;
 if (!gROOT->FindObject(NameMC.Data())){
  hMC = new TH1F(NameMC,NameMC,numEvents,0,200);
  hMC->Reset();
  TString DrawMC = Form("(ET * (1+%f))>>%s",scale,NameMC.Data());
  MyTreeMC->Draw(DrawMC,AdditionalCut.Data());
  hMC->Sumw2();
  hMC->Scale(hDATA->GetEntries()/hMC->GetEntries());
  outFile->cd();
  hMC->Write();
 } 
 else {
//   std::cerr << " NewChi2 old " << NameMC.Data() << std::endl;
  hMC = (TH1F*) outFile->Get(NameMC.Data());
 }
 
 double result = myChi2(hMC,hDATA);
 return result;
}


int main(int argc, char** argv){
 
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 
 
 ///==== W ====
 fileInW = new TFile("output/outW_MC.root","READ");

 ///===================================
 
 if (argc>=2) numEvents = atoi(argv[1]);

 TString nameOutFile = Form("output/out_EnScale_MC_%d_Events.root",numEvents);
 outFile = new TFile(nameOutFile.Data(),"RECREATE");

 std::cerr << " numEvents = " << numEvents << std::endl;
 std::cerr << " nameOutFile = " << nameOutFile.Data() << std::endl;
 
 if (argc>=3) maxIter = atoi(argv[2]); 
 ///===================================
 
 outFile->cd();
 
 TTree myTreeChi2("myTreeChi2","myTreeChi2");
 double Alpha;
 double Chi2;
 double NewChi2;
 double LL;
 myTreeChi2.Branch("Alpha",&Alpha,"Alpha/D");
 myTreeChi2.Branch("Chi2",&Chi2,"Chi2/D");
 myTreeChi2.Branch("NewChi2",&NewChi2,"NewChi2/D");
 myTreeChi2.Branch("LL",&LL,"LL/D");
 
 TTree myTreeChi2_Result("myTreeChi2_Result","myTreeChi2_Result");
 double AlphaMean;
 double AlphaMinus;
 double AlphaPlus;
 double AlphaMean_Fit;
 double AlphaMinus_Fit;
 double AlphaPlus_Fit;
 
 myTreeChi2_Result.Branch("AlphaMean",&AlphaMean,"AlphaMean/D");
 myTreeChi2_Result.Branch("AlphaMinus",&AlphaMinus,"AlphaMinus/D");
 myTreeChi2_Result.Branch("AlphaPlus",&AlphaPlus,"AlphaPlus/D");
 myTreeChi2_Result.Branch("AlphaMean_Fit",&AlphaMean_Fit,"AlphaMean_Fit/D");
 myTreeChi2_Result.Branch("AlphaMinus_Fit",&AlphaMinus_Fit,"AlphaMinus_Fit/D");
 myTreeChi2_Result.Branch("AlphaPlus_Fit",&AlphaPlus_Fit,"AlphaPlus_Fit/D");
 
 TTree myTreeLL_Result("myTreeLL_Result","myTreeLL_Result");
 myTreeLL_Result.Branch("AlphaMean",&AlphaMean,"AlphaMean/D");
 myTreeLL_Result.Branch("AlphaMinus",&AlphaMinus,"AlphaMinus/D");
 myTreeLL_Result.Branch("AlphaPlus",&AlphaPlus,"AlphaPlus/D");
 myTreeLL_Result.Branch("AlphaMean_Fit",&AlphaMean_Fit,"AlphaMean_Fit/D");
 myTreeLL_Result.Branch("AlphaMinus_Fit",&AlphaMinus_Fit,"AlphaMinus_Fit/D");
 myTreeLL_Result.Branch("AlphaPlus_Fit",&AlphaPlus_Fit,"AlphaPlus_Fit/D");
 
 TTree myTreeNewChi2_Result("myTreeNewChi2_Result","myTreeNewChi2_Result");
 myTreeNewChi2_Result.Branch("AlphaMean",&AlphaMean,"AlphaMean/D");
 myTreeNewChi2_Result.Branch("AlphaMinus",&AlphaMinus,"AlphaMinus/D");
 myTreeNewChi2_Result.Branch("AlphaPlus",&AlphaPlus,"AlphaPlus/D");
 myTreeNewChi2_Result.Branch("AlphaMean_Fit",&AlphaMean_Fit,"AlphaMean_Fit/D");
 myTreeNewChi2_Result.Branch("AlphaMinus_Fit",&AlphaMinus_Fit,"AlphaMinus_Fit/D");
 myTreeNewChi2_Result.Branch("AlphaPlus_Fit",&AlphaPlus_Fit,"AlphaPlus_Fit/D");
 
 TCanvas *cResult = new TCanvas("cResult","cResult",10,10,800,800);
 
 
 
 
 TF1* fitMin = new TF1("fitMin","pol2");
 fitMin->SetRange(MinScan,MaxScan); 
 
 ROOT::Math::Minimizer* minuit = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
 ROOT::Math::Functor functorChi2(&Chi2F,1); 
 ROOT::Math::Functor functorLL(&LLFunc,1); 
 ROOT::Math::Functor functorNewChi2(&NewChi2Func,1); 
 
 ///==== cycle on number of Toy MC experiments ====
 for (nIter = 0; nIter<maxIter; nIter++){
  std::cerr << ">>> nIter = " << nIter << " : " << maxIter << std::endl;
 
  vET_data.clear();
  fileInW->cd();
  TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
  double pT;
  double ET;
  double MT;
  MyTreeMC->SetBranchAddress("pT",&pT);
  MyTreeMC->SetBranchAddress("ET",&ET);
  MyTreeMC->SetBranchAddress("MT",&MT);
  outFile->cd();
  TString nameDATA = Form("hDATA_%d",nIter);
  TH1F hDATA(nameDATA,nameDATA,numEvents,0,200);
  for (int iEvt = 0; iEvt < numEvents; iEvt ++){
   MyTreeMC->GetEntry(gRandom->Uniform(0,MyTreeMC->GetEntries()));
   if (MT > minET){
    hDATA.Fill(ET * (1+ScaleTrue));
    vET_data.push_back(ET * (1+ScaleTrue));
   }
   else {
    iEvt --;
   }
  }
  
  
  
  double step[1] = {0.001};
  double variable[1] = {0.0};
  minuit->SetLimitedVariable(0,"Scale" , variable[0]  , step[0] , MinScan  , MaxScan );
  
  std::cerr << "... I'm minimizing ..." << std::endl;
  std::cerr << ">>>>>>> numEvents = " << numEvents << std::endl;
  
  ///===== Chi2 ====
  std::cerr << " === Chi2 === " << std::endl;
  minuit->SetFunction(functorChi2);
  unsigned int iPar_NoBG = 0;
  TGraph * grChi2 = new TGraph(iNoSteps);
  minuit->Scan(iPar_NoBG,iNoSteps,grChi2->GetX(),grChi2->GetY(),MinScan,MaxScan);
  grChi2->Draw("AL");
  outFile->cd();
  minuit->PrintResults();

  const double *outParametersTemp = minuit->X();
  const double *errParametersTemp = minuit->Errors();
  
  double *outParameters = new double;
  double *errParameters = new double;
  outParameters[0] = outParametersTemp[0];
  errParameters[0] = errParametersTemp[0];
  
  double minChi2 = grChi2->Eval(outParameters[0]);
  std::cerr << " numEvents = " << numEvents << " Scale = " << outParameters[0] << " +/- " << errParameters[0] << std::endl;
  ///===== end Chi2 ====
  
  
  
  ///==== likelihood ====
  std::cerr << " === LL === " << std::endl;
  minuit->SetFunction(functorLL);
  TGraph * grLL = new TGraph(iNoSteps);
  minuit->Scan(iPar_NoBG,iNoSteps,grLL->GetX(),grLL->GetY(),MinScan,MaxScan);
  grLL->Draw("AL");
  outFile->cd();
  minuit->PrintResults();
  const double *outParametersTemp2 = minuit->X();
  const double *errParametersTemp2 = minuit->Errors();
  
  double *outParametersLL = new double;
  double *errParametersLL = new double;
  outParametersLL[0] = outParametersTemp2[0];
  errParametersLL[0] = errParametersTemp2[0];
  
  double minLL = grLL->Eval(outParametersLL[0]);
  std::cerr << " numEvents = " << numEvents << " Scale = " << outParametersLL[0] << " +/- " << errParametersLL[0] << std::endl;
  ///==== end likelihood ====
  
  
  ///==== newChi2 ====
  std::cerr << " === newChi2 === " << std::endl;
   minuit->SetFunction(functorNewChi2);
  TGraph * grNewChi2 = new TGraph(iNoSteps);
  minuit->Scan(iPar_NoBG,iNoSteps,grNewChi2->GetX(),grNewChi2->GetY(),MinScan,MaxScan);
  grNewChi2->Draw("AL");
  outFile->cd();
  minuit->PrintResults();
  const double *outParametersNewChi2 = minuit->X();
  const double *errParametersNewChi2 = minuit->Errors();
  double minNewChi2 = grNewChi2->Eval(outParametersNewChi2[0]);
  std::cerr << " numEvents = " << numEvents << " Scale = " << outParametersNewChi2[0] << " +/- " << errParametersNewChi2[0] << std::endl;
  ///==== end likelihood ====
  
  
  
  std::cerr << "... Minimized with all methods ..." << std::endl;
 
  ///==== Save the whole shape of LL/Chi2 ====
  for (int ii=0; ii < iNoSteps; ii++){
   double X_ii = (MaxScan - MinScan) / iNoSteps * ii + MinScan;
   
   Alpha   = X_ii;
   Chi2    = grChi2->Eval(X_ii);
   LL      = grLL->Eval(X_ii);
   NewChi2 = grNewChi2->Eval(X_ii);
   
//    if (!(ii%100)) std::cerr << "Alpha = " << Alpha << ":: Chi2 = " << Chi2 << " LL = " << LL << " NewChi2 = " << NewChi2 << std::endl;
   myTreeChi2.Fill();
  }
  

  ///===== Look for minima =====
  double a;
  double b;
  double c;
  
  ///===== Chi2 ====
  std::cerr << " === Chi2 === " << std::endl;
  std::cerr << "==== min Scan = " << minChi2 << std::endl;
  double errX_low = -9999;
  double errX_up = 9999;
  int err_low = 0;
  int err_up = 0;
  for (int ii=0; ii < iNoSteps; ii++){
   double X_ii = (MaxScan - MinScan) / iNoSteps * ii + MinScan;
   double here = grChi2->Eval(X_ii);
   if (err_low == 0){
    if (here < (minChi2 + DELTA_CHI2)){
     errX_low = X_ii;
     err_low = 1;
    }
   }
   else if (err_up == 0 && here > (minChi2 + DELTA_CHI2) && X_ii > outParameters[0]){
    errX_up = X_ii; 
    err_up = 1;
   }
  }
  
  AlphaMean = outParameters[0];
  AlphaMinus = errX_low;
  AlphaPlus = errX_up;
 
  grChi2->Fit("fitMin","RMQ");
  c = fitMin->GetParameter(0);
  b = fitMin->GetParameter(1);
  a = fitMin->GetParameter(2);
  AlphaMean_Fit  = -b / (2*a);
  AlphaMinus_Fit = (-b + 2 * sqrt(a)) / (2*a);  ///==== delta Chi2 = 1 
  AlphaPlus_Fit  = (-b - 2 * sqrt(a)) / (2*a);  ///==== delta Chi2 = 1   

  myTreeChi2_Result.Fill();
   
  
  ///===== LogLikelihood ====
  std::cerr << " === LL === " << std::endl;
  std::cerr << "==== min Scan = " << minLL << std::endl;
  errX_low = -9999;
  errX_up = 9999;
  err_low = 0;
  err_up = 0;
  for (int ii=0; ii < iNoSteps; ii++){
   double X_ii = (MaxScan - MinScan) / iNoSteps * ii + MinScan;
   double here = grLL->Eval(X_ii);
   if (err_low == 0){
    if (here < (minLL + DELTA_LL)){
     errX_low = X_ii;
     err_low = 1;
    }
   }
   else if (err_up == 0 && here > (minLL + DELTA_LL) && X_ii > outParametersLL[0]){
    errX_up = X_ii; 
    err_up = 1;
   }
  }
  
  AlphaMean = outParametersLL[0];
  AlphaMinus = errX_low;
  AlphaPlus = errX_up;
 
  grLL->Fit("fitMin","RMQ");
  c = fitMin->GetParameter(0);
  b = fitMin->GetParameter(1);
  a = fitMin->GetParameter(2);
  AlphaMean_Fit  = -b / (2*a);
  AlphaMinus_Fit = (-b + sqrt(2*a)) / (2*a);  ///==== delta LL = 0.5
  AlphaPlus_Fit  = (-b - sqrt(2*a)) / (2*a);  ///==== delta LL = 0.5   
  
  myTreeLL_Result.Fill();
  
  
  
  ///===== NewChi2 ====
  std::cerr << " === NewChi2 === " << std::endl;
  std::cerr << "==== min Scan = " << minNewChi2 << std::endl;
  errX_low = -9999;
  errX_up = 9999;
  err_low = 0;
  err_up = 0;
  for (int ii=0; ii < iNoSteps; ii++){
   double X_ii = (MaxScan - MinScan) / iNoSteps * ii + MinScan;
   double here = grNewChi2->Eval(X_ii);
   if (err_low == 0){
    if (here < (minNewChi2 + DELTA_CHI2)){
     errX_low = X_ii;
     err_low = 1;
    }
   }
   else if (err_up == 0 && here > (minNewChi2 + DELTA_CHI2) && X_ii > outParametersNewChi2[0]){
    errX_up = X_ii; 
    err_up = 1;
   }
  }
  
  AlphaMean = outParametersNewChi2[0];
  AlphaMinus = errX_low;
  AlphaPlus = errX_up;
  
  
  grNewChi2->Fit("fitMin","RMQ");
  c = fitMin->GetParameter(0);
  b = fitMin->GetParameter(1);
  a = fitMin->GetParameter(2);
  AlphaMean_Fit  = -b / (2*a);
  AlphaMinus_Fit = (-b + 2 * sqrt(a)) / (2*a);  ///==== delta Chi2 = 1 
  AlphaPlus_Fit  = (-b - 2 * sqrt(a)) / (2*a);  ///==== delta Chi2 = 1   
  
  myTreeNewChi2_Result.Fill();
  
  
  std::cerr << " ======================================================================== " << std::endl;
  
  
  

 }
 
  ///----------------------
  ///---- Plot results ----
  ///----------------------
  outFile->cd();
  myTreeChi2.Write();
  myTreeLL_Result.Write();
  myTreeChi2_Result.Write();
  myTreeNewChi2_Result.Write();
  delete fitMin;
  
}



