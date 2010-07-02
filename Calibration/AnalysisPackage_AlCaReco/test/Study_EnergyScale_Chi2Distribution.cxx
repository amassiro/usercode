#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
TFile* fileInW;
TFile* outFile;

Double_t ScaleTrue = -0.02;
TCanvas* temp = new TCanvas("temp","temp",20,20);

double MinScan = -0.5;
double MaxScan = 0.5;
Int_t iNoSteps = 200;

int maxIter = 100;
Int_t numEvents = 100;
int nIter = 0;

Double_t DELTA = 1.0;
Double_t DELTALL = 0.5;

std::vector<double> vET_data;

int NBINTemplate = 40;
double MinTemplate = 20.0;
double MaxTemplate = 60.0;
double Delta = (MaxTemplate - MinTemplate) / NBINTemplate;





double LLFunc(const double *xx ){
 const Double_t scale = xx[0];

 ///==== Likelihood ==== 
 fileInW->cd();
 TTree* MyTreeMC = (TTree*) fileInW->Get("myTree");
 TH1F hMC("hMC","hMC",NBINTemplate,MinTemplate,MaxTemplate);
 hMC.Reset();
 TString DrawMC = Form("(ET * (1+%f))>>hMC",scale);
 MyTreeMC->Draw(DrawMC,"MT>30");
 int numberDATA = vET_data.size();
 double result = 1.;
 
 for (int iEvt = 0; iEvt < numberDATA; iEvt ++){
  double ET = vET_data.at(iEvt);
  int bin = ( ET - MinTemplate ) / Delta;
  if (bin > 0 && bin < NBINTemplate){
   result *= (hMC.GetBinContent(bin));
   if (hMC.GetBinContent(bin) == 0) {
//     std::cerr << " result = " << result << " hMC.GetBinContent(" << bin << ":" << NBINTemplate << ") = " << hMC.GetBinContent(bin) << " scale = " << scale << std::endl;
   }
  }
 }
 outFile->cd();
 hMC.Write();
 
 if (result != 0) result = -log(result);
 
 ///==== end Likelihood ====    

 return result;
}








double KM(const double *xx ){
 const Double_t scale = xx[0];
 fileInW->cd();
 TTree* MyTreeMC = fileInW->Get("myTree");
 outFile->cd();
 TString nameDATA = Form("hDATA_%d",nIter);
 TH1F hDATA = (TH1F) outFile->Get(nameDATA);
 TH1F hMC("hMC","hMC",numEvents,0,200);
 temp->cd();
 TString DrawMC = Form("(ET * (1+%f))>>hMC",scale);
 MyTreeMC->Draw(DrawMC,"MT>30");
 hMC.Sumw2();
 hDATA.Sumw2();
 hMC.Scale(hDATA.GetEntries()/hMC.GetEntries());
 outFile->cd();
//  hDATA.Write();
//  hMC.Write();
//  double result = - hMC.KolmogorovTest(&hDATA);
//  double result = hMC.Chi2Test(&hDATA,"CHI2/NDF");
 double result = hMC.Chi2Test(&hDATA,"CHI2");
 //double result = - hMC.Chi2Test(&hDATA,""); ///==== http://root.cern.ch/root/html/TH1.html#TH1:Chi2Test
 return result;
}


void Study_EnergyScale_Chi2Distribution(){
 ///==== Draw Distributions ====
 
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 ///===================================
 
 
 ///==== W ====
 fileInW = new TFile("output/outW_MC.root","READ");

 ///===================================
 outFile = new TFile("output/outStudyEnergyScale_Chi2Distribution_New.root","RECREATE");
 
 ///===================================
 
 outFile->cd();
 
 TTree myTreeChi2("myTreeChi2","myTreeChi2");
 double Alpha;
 double Chi2;
 double LL;
 myTreeChi2.Branch("Alpha",&Alpha,"Alpha/D");
 myTreeChi2.Branch("Chi2",&Chi2,"Chi2/D");
 myTreeChi2.Branch("LL",&LL,"LL/D");
 
 TTree myTreeChi2_Result("myTreeChi2_Result","myTreeChi2_Result");
 double AlphaMean;
 double AlphaMinus;
 double AlphaPlus;
 myTreeChi2_Result.Branch("AlphaMean",&AlphaMean,"AlphaMean/D");
 myTreeChi2_Result.Branch("AlphaMinus",&AlphaMinus,"AlphaMinus/D");
 myTreeChi2_Result.Branch("AlphaPlus",&AlphaPlus,"AlphaPlus/D");
 
 TTree myTreeLL_Result("myTreeLL_Result","myTreeLL_Result");
 myTreeLL_Result.Branch("AlphaMean",&AlphaMean,"AlphaMean/D");
 myTreeLL_Result.Branch("AlphaMinus",&AlphaMinus,"AlphaMinus/D");
 myTreeLL_Result.Branch("AlphaPlus",&AlphaPlus,"AlphaPlus/D");
 
 
 TCanvas *cResult = new TCanvas("cResult","cResult",10,10,800,800);
 
 
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
   if (MT > 30){
    hDATA.Fill(ET * (1+ScaleTrue));
    vET_data.push_back(ET * (1+ScaleTrue));
   }
   else {
    iEvt --;
   }
  }
  
  
  ROOT::Math::Minimizer* minuit = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
  ROOT::Math::Functor functor(&KM,1); 
  minuit->SetFunction(functor);
  
  double step[1] = {0.001};
  double variable[1] = {0.0};
  minuit->SetLimitedVariable(0,"Scale" , variable[0]  , step[0] , MinScan  , MaxScan );
  
  std::cerr << "... I'm minimizing ..." << std::endl;
  std::cerr << ">>>>>>> numEvents = " << numEvents << std::endl;
  
  ///===== Chi2 ====
  Int_t iPar_NoBG = 0;
  TGraph * gr = new TGraph(iNoSteps);
  minuit->Scan(iPar_NoBG,iNoSteps,gr->GetX(),gr->GetY(),MinScan,MaxScan);
  gr->Draw("AL");
  outFile->cd();
  gr->Write();
  minuit->PrintResults();
  ///===== end Chi2 ====
  const double *outParameters = minuit->X();
  const double *errParameters = minuit->Errors();
  double min = gr->Eval(outParameters[0]);
  
  
  ///==== likelihood ====
  ROOT::Math::Functor functorLL(&LLFunc,1); 
  minuit->SetFunction(functorLL);
  TGraph * grLL = new TGraph(iNoSteps);
  minuit->Scan(iPar_NoBG,iNoSteps,grLL->GetX(),grLL->GetY(),MinScan,MaxScan);
  grLL->Draw("AL");
  outFile->cd();
  grLL->Write();
  minuit->PrintResults();
  ///==== end likelihood ====
  const double *outParametersLL = minuit->X();
  const double *errParametersLL = minuit->Errors();
  double minLL = grLL->Eval(outParametersLL[0]);
  
  
  
  std::cerr << "... minimized ..." << std::endl;
 
  std::cerr << " numEvents = " << numEvents << " Scale = " << outParametersLL[0] << " +/- " << errParametersLL[0] << std::endl;
  
  for (int ii=0; ii < iNoSteps; ii++){
   double X_ii = (MaxScan - MinScan) / iNoSteps * ii + MinScan;
   Alpha = X_ii;
   Chi2 = gr->Eval(X_ii);;
   LL = grLL->Eval(X_ii);;
   myTreeChi2.Fill();
  }
  
  
  ///===== Chi2 ====
  std::cerr << "==== min Scan = " << min << std::endl;
  double errX_low = -9999;
  double errX_up = 9999;
  int err_low = 0;
  int err_up = 0;
  for (int ii=0; ii < iNoSteps; ii++){
   double X_ii = (MaxScan - MinScan) / iNoSteps * ii + MinScan;
   double here = gr->Eval(X_ii);
   if (err_low == 0){
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
  
  AlphaMean = outParameters[0];
  AlphaMinus = errX_low;
  AlphaPlus = errX_up;
  myTreeChi2_Result.Fill();
   
  std::cerr << ">>>> errX_low:errX_up = " << errX_low << " : " << errX_up << std::endl;
  std::cerr << ">>>> Scale = " << outParameters[0] << " +/- " << errParameters[0] << std::endl;
  
  
  ///===== LogLikelihood ====
  std::cerr << "==== min Scan = " << minLL << std::endl;
  errX_low = -9999;
  errX_up = 9999;
  err_low = 0;
  err_up = 0;
  for (int ii=0; ii < iNoSteps; ii++){
   double X_ii = (MaxScan - MinScan) / iNoSteps * ii + MinScan;
   double here = grLL->Eval(X_ii);
   if (err_low == 0){
    if (here < (minLL + DELTALL)){
     errX_low = X_ii;
     err_low = 1;
    }
   }
   else if (err_up == 0 && here > (minLL + DELTALL) && X_ii > outParametersLL[0]){
    errX_up = X_ii; 
    err_up = 1;
   }
  }
  
  AlphaMean = outParametersLL[0];
  AlphaMinus = errX_low;
  AlphaPlus = errX_up;
  myTreeLL_Result.Fill();
  
  std::cerr << ">>>> errX_low:errX_up = " << errX_low << " : " << errX_up << std::endl;
  std::cerr << ">>>> Scale = " << outParametersLL[0] << " +/- " << errParametersLL[0] << std::endl;
  
  
  
  
  

 }
 
  ///----------------------
  ///---- Plot results ----
  ///----------------------
  outFile->cd();
  myTreeChi2.Write();
  myTreeLL_Result.Write();
  myTreeChi2_Result.Write();
  
  cResult->cd();
  myTreeChi2.Draw("Chi2:Alpha","","colz"); 
  gPad->SetGrid();
 
}



