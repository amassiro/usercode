{

 int nCuts = 7;
 
 int* Cuts[100] = {
  50,
  100,
  200,
  300,
  400,
  700,
  1000
 };
 
 TGraph* h1[1000];
 TF1* kFunction;
//  out_CalibratingCaVa_100.root
 
 int NBINX = 100;
 double MINX = 0;
 double MAXX = 1000;
 
 TCanvas* cResults = new TCanvas("cResults","cResults",800,800);
 cResults.Divide(nCuts,2);
 for (int iCut = 0 ; iCut < nCuts; iCut++){
  std::cout << " iCut = " << iCut << " : " << nCuts << std::endl;
  cResults->cd(iCut*2+1);
  TString nameFile = Form("../output/out_CalibratingCaVa_%d.root",Cuts[iCut]);
  TFile* file = new TFile(nameFile,"READ");
  TString nameHisto = Form("CalibratingCaVa_%d",Cuts[iCut]);
  h1[iCut] = (TGraph*) (file->Get("Meas_kFunction"))->Clone();
  h1[iCut]->SetName(nameHisto);
  h1[iCut]->SetMarkerColor(kRed-5*iCut);
  h1[iCut]->SetFillColor(kRed-5*iCut);
  h1[iCut]->SetMarkerStyle(20);
  h1[iCut]->SetMarkerSize(1);
  TString titleHisto = Form("RECO > %d",Cuts[iCut]);
  h1[iCut]->SetTitle(titleHisto);
  if (iCut == 0) kFunction = (TF1*) ((TF1*) file->Get("kFunction"))->Clone();
  
  kFunction->Draw();
  h1[iCut]->Draw("Psame");
 
  gPad->SetGrid();
  gPad->BuildLegend();
  
  
  cResults->cd(iCut*2+2);
  (file->Get("h2Inv"))->Draw("colz");
  kFunction->Draw("same");
  
 }
 
 TCanvas* cResultsAll = new TCanvas("cResultsAll","cResultsAll",800,800);
 kFunction->Draw();
 for (int iCut = 0 ; iCut < nCuts; iCut++){
  h1[iCut]->Draw("Psame");
 }
 gPad->SetGrid();
 gPad->BuildLegend();
 
 
 
}
