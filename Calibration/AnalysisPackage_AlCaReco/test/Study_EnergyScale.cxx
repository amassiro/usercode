#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
TFile* fileInW;
TFile* outFile;

Double_t ScaleTrue = -0.02;
Int_t numEvents = 100;
Double_t DELTA = 1.0;
TCanvas* temp = new TCanvas("temp","temp",20,20);

double KM(const double *xx ){
 const Double_t scale = xx[0];
 fileInW->cd();
 TTree* MyTreeMC = fileInW->Get("myTree");
 outFile->cd();
 TString nameDATA = Form("hDATA_%d",numEvents);
 TH1F hDATA = (TH1F) outFile->Get(nameDATA);
 TH1F hMC("hMC","hMC",numEvents,0,200);
 temp->cd();
 TString DrawMC = Form("(ET * (1+%f))>>hMC",scale);
 MyTreeMC->Draw(DrawMC,"MT>30");
//  hMC.Sumw2();
 hDATA.Sumw2();
 hMC.Scale(1./hMC.GetEntries());
 hDATA.Scale(1./hDATA.GetEntries());
 outFile->cd();
//  hDATA.Write();
//  hMC.Write();
//  double result = - hMC.KolmogorovTest(&hDATA);
//  double result = hMC.Chi2Test(&hDATA,"CHI2/NDF");
 double result = hMC.Chi2Test(&hDATA,"CHI2");
 //double result = - hMC.Chi2Test(&hDATA,""); ///==== http://root.cern.ch/root/html/TH1.html#TH1:Chi2Test
 return result;
}


void Study_EnergyScale(){
 ///==== Draw Distributions ====
 
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 
 
 ///==== W ====
 fileInW = new TFile("output/outW_MC.root","READ");

 ///===================================
 outFile = new TFile("output/outStudyEnergyScale.root","RECREATE");

 ///===================================

//  TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
//  TTree* MyTreeDATA = (TTree*) fileInDATA->Get("myTree");
  
 int maxEvt = 10;
 TCanvas *cResult = new TCanvas("cResult","cResult",10,10,800,800);
 cResult->Divide(2,maxEvt);
 
 Double_t *Xevts = new Double_t[maxEvt];
 Double_t *YUPevts = new Double_t[maxEvt];
 Double_t *YMEANevts = new Double_t[maxEvt];
 Double_t *YLOWevts = new Double_t[maxEvt];
 
 
 for (int nEvt = 0; nEvt<maxEvt; nEvt++){
  std::cerr << ">>> nEvt = " << nEvt << " : " << maxEvt << std::endl;
  ROOT::Math::Minimizer* minuit = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
  ROOT::Math::Functor functor(&KM,1); 
  minuit->SetFunction(functor);
  
  double step[1] = {0.001};
  double variable[1] = {0.0};
  
  minuit->SetLimitedVariable(0,"Scale" , variable[0]  , step[0] , -0.5  , 0.5 );
  std::cerr << "... I'm minimizing ..." << std::endl;
  
//   numEvents = 20 * ( nEvt +1 );
  numEvents = 20 + pow(2.,nEvt+1.);
  Xevts[nEvt] = numEvents;
  
  std::cerr << ">>>>>>> numEvents = " << numEvents << std::endl;
  
  
  fileInW->cd();
  TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
  double pT;
  double ET;
  double MT;
  MyTreeMC->SetBranchAddress("pT",&pT);
  MyTreeMC->SetBranchAddress("ET",&ET);
  MyTreeMC->SetBranchAddress("MT",&MT);
  outFile->cd();
  TString nameDATA = Form("hDATA_%d",numEvents);
  TH1F hDATA(nameDATA,nameDATA,numEvents,0,200);
  for (int iEvt = 0; iEvt < numEvents; iEvt ++){
   MyTreeMC->GetEntry(gRandom->Uniform(0,MyTreeMC->GetEntries()));
   if (MT > 30){
    hDATA.Fill(ET * (1+ScaleTrue));
   }
   else {
    iEvt --;
   }
  }
  
  ///=====================================================
  Int_t iPar_NoBG = 0;
  Int_t iNoSteps = 1000;
  TGraph * gr = new TGraph(iNoSteps);
  minuit->Scan(iPar_NoBG,iNoSteps,gr->GetX(),gr->GetY(),-0.5,0.5);
  gr->Draw("AL");
  outFile->cd();
  gr->Write();
  minuit->PrintResults();
  ///=====================================================
  
  ///------------------
  minuit->Minimize(); 
  ///------------------
  std::cerr << "... minimized ..." << std::endl;
 
  const double *outParameters = minuit->X();
  const double *errParameters = minuit->Errors();
  std::cerr << " numEvents = " << numEvents << " Scale = " << outParameters[0] << " +/- " << errParameters[0] << std::endl;
  
  YMEANevts[nEvt] = outParameters[0];
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
   else if (err_up == 0 && here > (min + DELTA) && X_ii > YMEANevts[nEvt]){
    errX_up = X_ii; 
    err_up = 1;
   }
  }
  std::cerr << " errX_low:errX_up = " << errX_low << " : " << errX_up << std::endl;
  
  YLOWevts[nEvt] = errX_low;
  YUPevts[nEvt] = errX_up;
  
  ///----------------------
  ///---- Plot results ----
  ///----------------------
 
  cResult->cd(nEvt * 2 + 1);
 
  cResult->cd(nEvt * 2 + 2);
  TString nameMC = Form("hMC_BEST_%d",nEvt);
  TH1F hMC_BEST(nameMC,nameMC,numEvents,0,200);
  TString DrawMC = Form("(ET * (1+%f)) >> %s",outParameters[0],nameMC.Data());
  std::cerr << " DrawMC = " << DrawMC.Data() << std::endl;
//   fileInW->cd();
  MyTreeMC->Draw(DrawMC,"MT>30");
  
  hMC_BEST.Sumw2();
  hDATA.Sumw2();
  hMC_BEST.Scale(hDATA.GetEntries()/hMC_BEST.GetEntries());
  
  hMC_BEST.SetMarkerColor(kBlue);
  hMC_BEST.SetMarkerStyle(20);
  hMC_BEST.SetMarkerSize(1.0);
  hMC_BEST.SetLineColor(kBlue);
  hMC_BEST.SetLineWidth(2.0);
 
  hDATA.SetMarkerColor(kRed);
  hDATA.SetMarkerStyle(20);
  hDATA.SetMarkerSize(1.0);
  hDATA.SetLineColor(kRed);
  hDATA.SetLineWidth(2.0);
 
  outFile->cd();
  hDATA.Write();
  hMC_BEST.Write();
  
  cResult->cd(nEvt * 2 + 1);
  gr->DrawClone("AL");
  gPad->SetGrid();
  gPad->SetLogy();
  cResult->cd(nEvt * 2 + 2);
  hDATA.DrawClone("E");
  hMC_BEST.DrawClone("Esame");
  gPad->BuildLegend();
  std::cerr << "... new Loop ready ..." << std::endl;
 }
 
 TGraph * grUP = new TGraph(maxEvt,Xevts,YUPevts);
 TGraph * grMEAN = new TGraph(maxEvt,Xevts,YMEANevts);
 TGraph * grLOW = new TGraph(maxEvt,Xevts,YLOWevts);
 
 grUP->SetMarkerColor(kBlue);
 grUP->SetMarkerStyle(21);

 grMEAN->SetMarkerColor(kRed);
 grMEAN->SetMarkerStyle(20);
 
 grLOW->SetMarkerColor(kBlue);
 grLOW->SetMarkerStyle(21);
 
 TCanvas *cResultSummed = new TCanvas("cResultSummed","cResultSummed",10,10,800,800);
 
 TMultiGraph *mg = new TMultiGraph();
 mg->Add(grUP);
 mg->Add(grMEAN);
 mg->Add(grLOW);
 mg->Draw("APL");
 mg->GetXaxis()->SetTitle("Number of events");
 mg->GetYaxis()->SetTitle("#alpha");
 
 TLine* lOriz = new TLine(0,ScaleTrue,Xevts[maxEvt-1],ScaleTrue);
 lOriz->SetLineColor(kGreen);
 lOriz->SetLineWidth(4);
 lOriz->SetLineStyle(5);
 lOriz->Draw();
 
 gPad->SetGrid();
 
 
}



