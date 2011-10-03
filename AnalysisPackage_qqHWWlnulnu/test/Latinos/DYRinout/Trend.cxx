#include "plotUtils.C"

void Trend(TString name, TString file, int join = 1){
 
 TFile* inFile = new TFile(file,"OPEN");

 TTree* ntu = (TTree*) inFile -> Get ("ntu");

 drawTracePlotUpdate(name,join);

/*
 double varValues;
 ntu -> SetBranchAddress(name,&varValues);
 
 int nbin = ntu->GetEntries() / join;
 double* varTrend = new double [nbin];
 double* x_ = new double [nbin];
  
 for(int iEntry = 0; iEntry < ntu->GetEntries(); iEntry++){
  ntu->GetEntry(iEntry);
  for(int iJoin = 0; iJoin < join; iJoin++){
   varTrend[iEntry / join] += varValues;
   x_[iEntry / join] = iEntry / join;
   iEntry++;
   if (iEntry == ntu->GetEntries()) break;
  }
 }
 
 TGraph* graph = new TGraph (nbin,x_,varTrend);
 graph->SetMarkerStyle(20);
 graph->SetMarkerColor(kRed);
 graph->SetLineColor(kGreen);
 graph->Draw("APL");
*/ 
}

