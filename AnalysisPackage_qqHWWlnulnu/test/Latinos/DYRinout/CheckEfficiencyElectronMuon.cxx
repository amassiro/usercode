///===========================================================================
///==== take electron and muon pT spectrum for lepton_1 and lepton_2
///==== calculate efficiency wrt selection pT> threshold
///==== divide efficiency electron /  efficiency muon
///==== compare results for different samples (typically DY and tt)
///===========================================================================

void CheckEfficiencyElectronMuon(TString nameRootFile, int step_e = 5, int step_mu = 6, int plot = 5){
 
 TFile* fileIn = new TFile(nameRootFile,"READ");
 
 gStyle->SetTitleX(0.2f);
 gStyle->SetTitleW(0.5f);
 
 int num = 0;
 
 double* X = new double[100];
 double* errX = new double[100];
 
//  double* DY_Ne;
//  double* DY_Nmu;
 double* DY_Ne = new double[100];
 double* DY_Nmu = new double[100];
 double* DY_effe = new double[100];
 double* DY_effmu = new double[100];
 double* DY_effemu = new double[100];
//  double* DY_errNe;
//  double* DY_errNmu;
 double* DY_errNe = new double[100];
 double* DY_errNmu = new double[100];
 double* DY_erreffe = new double[100];
 double* DY_erreffmu = new double[100];
 double* DY_erreffemu = new double[100];
 
//  double* other_Ne;
//  double* other_Nmu;
 double* other_Ne = new double[100];
 double* other_Nmu = new double[100];
 double* other_effe = new double[100];
 double* other_effmu = new double[100];
 double* other_effemu = new double[100];
//  double* other_errNe;
//  double* other_errNmu;
 double* other_errNe = new double[100];
 double* other_errNmu = new double[100];
 double* other_erreffe = new double[100];
 double* other_erreffmu = new double[100];
 double* other_erreffemu = new double[100];
 

 
 
 int nprobSum;

 TString nameHistoInRootFile;
 TH1F* he;
 TH1F* hmu; 
 
 ///****************************************************
 
 nameHistoInRootFile = Form("Data/DYpow-Summer11_%d_%d_Tot_temp",step_e,plot);  
 he = (TH1F*) fileIn->Get(nameHistoInRootFile);  
 he->DrawNormalized();
 
 nameHistoInRootFile = Form("Data/DYpow-Summer11_%d_%d_Tot_temp",step_mu,plot);  
 hmu = (TH1F*) fileIn->Get(nameHistoInRootFile);  
 
 num = he->GetNbinsX();  
//  DY_Ne  = he  -> GetIntegral();
//  DY_Nmu = hmu -> GetIntegral();
 for (int iBin = 0; iBin < num; iBin++){
  DY_errNe[iBin]  = 0.;
  DY_errNmu[iBin] = 0.;
  for (int jBin = iBin; jBin < num; jBin++){
   DY_Ne[iBin]    += he->GetBinContent(jBin+1);
   if (he->GetBinContent(jBin+1) != 0) DY_errNe[iBin] = sqrt(DY_errNe[iBin] * DY_errNe[iBin] + he->GetBinError(jBin+1) * he->GetBinError(jBin+1));  
   DY_Nmu[iBin]    += hmu->GetBinContent(jBin+1);
   if (hmu->GetBinContent(jBin+1) != 0) DY_errNmu[iBin] = sqrt(DY_errNmu[iBin] * DY_errNmu[iBin] + hmu->GetBinError(jBin+1) * hmu->GetBinError(jBin+1));  
//    if (iBin == 0) std::cout << "[" << iBin << "][" << jBin << "] = " << he->GetBinContent(jBin+1) << " +/- " << he->GetBinError(jBin+1) << " --> " << DY_Ne[iBin] << " +/- " << DY_errNe[iBin]<< std::endl;
  }
 }

 
 nameHistoInRootFile = Form("Data/other_%d_%d_Tot_temp",step_e,plot);  
 he = (TH1F*) fileIn->Get(nameHistoInRootFile);  
 he->DrawNormalized("same");
 
 nameHistoInRootFile = Form("Data/other_%d_%d_Tot_temp",step_mu,plot);  
 hmu = (TH1F*) fileIn->Get(nameHistoInRootFile);  
 
//  other_Ne  = he  -> GetIntegral();
//  other_Nmu = hmu -> GetIntegral();
 for (int iBin = 0; iBin < num; iBin++){
  other_errNe[iBin]  = 0.;
  other_errNmu[iBin] = 0.;
  for (int jBin = iBin; jBin < num; jBin++){
   other_Ne[iBin]    += he->GetBinContent(jBin+1);
   if (he->GetBinContent(jBin+1) != 0) other_errNe[iBin] = sqrt(other_errNe[iBin] * other_errNe[iBin] + he->GetBinError(jBin+1) * he->GetBinError(jBin+1));  
   other_Nmu[iBin]    += hmu->GetBinContent(jBin+1);
   if (hmu->GetBinContent(jBin+1) != 0) other_errNmu[iBin] = sqrt(other_errNmu[iBin] * other_errNmu[iBin] + hmu->GetBinError(jBin+1) * hmu->GetBinError(jBin+1));  
  }
 }
 
 
 ///==== efficiency calculation ====
 
 std::cout << " num = " << num << std::endl;
 for (int iBin = 0; iBin < num; iBin++){
  X[iBin]    = he->GetBinLowEdge(iBin+1);  
  errX[iBin] = 0.;  
  
//   DY_effe[iBin]    = 1. - DY_Ne[iBin];
//   other_effe[iBin] = 1. - other_Ne[iBin];
//   DY_effmu[iBin]    = 1. - DY_Nmu[iBin];
//   other_effmu[iBin] = 1. - other_Nmu[iBin];

  DY_effe[iBin]    = DY_Ne[iBin] / DY_Ne[0];
  other_effe[iBin] = other_Ne[iBin] / other_Ne[0];
  DY_effmu[iBin]    = DY_Nmu[iBin] / DY_Nmu[0];
  other_effmu[iBin] = other_Nmu[iBin] / other_Nmu[0];

//   DY_erreffe[iBin]       = sqrt( DY_errNe[iBin]  / DY_Ne[0] * DY_errNe[iBin] / DY_Ne[0] + DY_errNe[0] * DY_Ne[iBin] / DY_Ne[0] / DY_Ne[0] * DY_errNe[0] * DY_Ne[iBin] / DY_Ne[0] / DY_Ne[0] );
//   other_erreffe[iBin]    = sqrt( other_errNe[iBin]  / other_Ne[0] * other_errNe[iBin] / other_Ne[0] + other_errNe[0] * other_Ne[iBin] / other_Ne[0] / other_Ne[0] * other_errNe[0] * other_Ne[iBin] / other_Ne[0] / other_Ne[0] );
//   DY_erreffmu[iBin]      = sqrt( DY_errNmu[iBin]  / DY_Nmu[0] * DY_errNmu[iBin] / DY_Nmu[0] + DY_errNmu[0] * DY_Nmu[iBin] / DY_Nmu[0] / DY_Nmu[0] * DY_errNmu[0] * DY_Nmu[iBin] / DY_Nmu[0] / DY_Nmu[0] );
//   other_erreffmu[iBin]   = sqrt( other_errNmu[iBin]  / other_Nmu[0] * other_errNmu[iBin] / other_Nmu[0] + other_errNmu[0] * other_Nmu[iBin] / other_Nmu[0] / other_Nmu[0] * other_errNmu[0] * other_Nmu[iBin] / other_Nmu[0] / other_Nmu[0] );

  DY_erreffe[iBin]     = DY_errNe[iBin]  / DY_Ne[0];
  other_erreffe[iBin]  = other_errNe[iBin]  / other_Ne[0];
  DY_erreffmu[iBin]    = DY_errNmu[iBin]  / DY_Nmu[0] ;
  other_erreffmu[iBin] = other_errNmu[iBin]  / other_Nmu[0] ;
  
  
  DY_effemu[iBin]    = DY_effmu[iBin]    ? DY_effe[iBin]    / DY_effmu[iBin] : 0.;
  other_effemu[iBin] = other_effmu[iBin] ? other_effe[iBin] / other_effmu[iBin] : 0.;

  DY_erreffemu[iBin]    = DY_effmu[iBin]    ? sqrt ( DY_erreffe[iBin] / DY_effmu[iBin] * DY_erreffe[iBin] / DY_effmu[iBin] +  DY_erreffmu[iBin] * DY_effe[iBin] / DY_effmu[iBin] / DY_effmu[iBin] * DY_erreffmu[iBin] * DY_effe[iBin] / DY_effmu[iBin] / DY_effmu[iBin] ) : 0.;
  other_erreffemu[iBin]    = other_effmu[iBin]    ? sqrt ( other_erreffe[iBin] / other_effmu[iBin] * other_erreffe[iBin] / other_effmu[iBin] +  other_erreffmu[iBin] * other_effe[iBin] / other_effmu[iBin] / other_effmu[iBin] * other_erreffmu[iBin] * other_effe[iBin] / other_effmu[iBin] / other_effmu[iBin] ) : 0.;
  
//   std::cout << " DY_effemu[" << iBin <<"] = " << DY_effemu[iBin] << " ~~~ DY_effmu[" << iBin <<"] = " << DY_effmu[iBin] << " ~~~ DY_effe[" << iBin <<"] = " << DY_effe[iBin]  <<  " ~~~ DY_Ne[" << iBin <<"] = " << DY_Ne[iBin] <<  " ~~~ DY_Nmu[" << iBin <<"] = " << DY_Nmu[iBin] << " ~~~ X[" << iBin <<"] = " << X[iBin] << std::endl;
  
 }
 
 ///**************
 ///**** plot ****
 
 TCanvas* cEffemu = new TCanvas("cEffemu","cEffemu",800,800); 
 
//  TGraph* grDY_effemu = new TGraph(num,X,DY_effemu);
//  grDY_effemu->SetTitle("DY");
//  grDY_effemu->GetXaxis()->SetTitle(he->GetXaxis()->GetTitle());
//  grDY_effemu->GetYaxis()->SetTitle("efficiency e / efficiency #mu");
//  grDY_effemu->SetMarkerColor(kBlue);
//  grDY_effemu->SetFillColor(kWhite);
//  grDY_effemu->SetLineColor(kBlue);
//  grDY_effemu->SetMarkerStyle(20);
//  grDY_effemu->SetMarkerSize(1.5);
//  grDY_effemu->SetLineWidth(2);
//  
//  TGraph* grother_effemu = new TGraph(num,X,other_effemu);
//  grother_effemu->SetTitle("other");
//  grother_effemu->GetXaxis()->SetTitle(he->GetXaxis()->GetTitle());
//  grother_effemu->GetYaxis()->SetTitle("efficiency e / efficiency #mu");
//  grother_effemu->SetMarkerColor(kRed);
//  grother_effemu->SetFillColor(kWhite);
//  grother_effemu->SetLineColor(kRed);
//  grother_effemu->SetMarkerStyle(20);
//  grother_effemu->SetMarkerSize(1.5);
//  grother_effemu->SetLineWidth(2);

 TGraphErrors* grDY_effemu = new TGraphErrors(num,X,DY_effemu,errX,DY_erreffemu);
 grDY_effemu->SetTitle("DY");
 grDY_effemu->GetXaxis()->SetTitle(he->GetXaxis()->GetTitle());
 grDY_effemu->GetYaxis()->SetTitle("efficiency e / efficiency #mu");
 grDY_effemu->SetMarkerColor(kBlue);
 grDY_effemu->SetFillColor(kWhite);
 grDY_effemu->SetLineColor(kBlue);
 grDY_effemu->SetMarkerStyle(20);
 grDY_effemu->SetMarkerSize(1.5);
 grDY_effemu->SetLineWidth(2);
 
 TGraphErrors* grother_effemu = new TGraphErrors(num,X,other_effemu,errX,other_erreffemu);
 grother_effemu->SetTitle("other");
 grother_effemu->GetXaxis()->SetTitle(he->GetXaxis()->GetTitle());
 grother_effemu->GetYaxis()->SetTitle("efficiency e / efficiency #mu");
 grother_effemu->SetMarkerColor(kRed);
 grother_effemu->SetFillColor(kWhite);
 grother_effemu->SetLineColor(kRed);
 grother_effemu->SetMarkerStyle(20);
 grother_effemu->SetMarkerSize(1.5);
 grother_effemu->SetLineWidth(2);
 
 TMultiGraph* mgr_effemu = new TMultiGraph(); 
 mgr_effemu->Add(grDY_effemu);
 mgr_effemu->Add(grother_effemu);
 mgr_effemu->Draw("AP");
 mgr_effemu->GetXaxis()->SetTitle(he->GetXaxis()->GetTitle());
 mgr_effemu->GetYaxis()->SetTitle("efficiency e / efficiency #mu");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 

 TCanvas* cNe = new TCanvas("cNe","cNe",800,800); 
 
 TGraphErrors* grDY_Ne = new TGraphErrors(num,X,DY_Ne,errX,DY_errNe);
 grDY_Ne->SetTitle("DY");
 grDY_Ne->GetXaxis()->SetTitle(he->GetXaxis()->GetTitle());
 grDY_Ne->GetYaxis()->SetTitle("Ne / N#mu");
 grDY_Ne->SetMarkerColor(kBlue);
 grDY_Ne->SetFillColor(kWhite);
 grDY_Ne->SetLineColor(kBlue);
 grDY_Ne->SetMarkerStyle(20);
 grDY_Ne->SetMarkerSize(1.5);
 grDY_Ne->SetLineWidth(2);
 
 TGraphErrors* grother_Ne = new TGraphErrors(num,X,other_Ne,errX,other_errNe);
 grother_Ne->SetTitle("other");
 grother_Ne->GetXaxis()->SetTitle(he->GetXaxis()->GetTitle());
 grother_Ne->GetYaxis()->SetTitle("Ne / N#mu");
 grother_Ne->SetMarkerColor(kRed);
 grother_Ne->SetFillColor(kWhite);
 grother_Ne->SetLineColor(kRed);
 grother_Ne->SetMarkerStyle(20);
 grother_Ne->SetMarkerSize(1.5);
 grother_Ne->SetLineWidth(2);
 
 TMultiGraph* mgr_Ne = new TMultiGraph(); 
 mgr_Ne->Add(grDY_Ne);
 mgr_Ne->Add(grother_Ne);
 mgr_Ne->Draw("AP");
 mgr_Ne->GetXaxis()->SetTitle(he->GetXaxis()->GetTitle());
 mgr_Ne->GetYaxis()->SetTitle("Ne / N#mu");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
} 
  
  