
#include "../../LatinoStyle2.C"



void CompareRinout(TString nameRootFile){
 
//  gStyle->SetPadBottomMargin(0.15);
//  gStyle->SetPadTopMargin(0.05);
//  gStyle->SetPadLeftMargin(0.15);
//  gStyle->SetPadRightMargin(0.10);
//  gStyle->SetLabelOffset(0.01, "XYZ");
//  gStyle->SetTitleYOffset(1.5);
 
 
 
 TFile* fileIn = new TFile(nameRootFile,"READ");
 
//  gStyle->SetTitleX(0.2f);
//  gStyle->SetTitleW(0.5f);
 
 LatinoStyle2();
 
 int numPointForRCalculation = 2;
 
//  int numPlot = 9; 
//  int num = 9;
//  double X[100] =    {2.5, 7.5, 12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5};
//  double errX[100] = {2.5, 2.5, 2.5,  2.5,  2.5,  2.5,  2.5,  2.5,  2.5};  
//  double XShift[100] =    {2.7, 7.7, 12.7, 17.7, 22.7, 27.7, 32.7, 37.7, 42.7};
 
//  int numPlot = 6; 
//  int num = 6;
//  double X[100] =    {2.5, 7.5, 12.5, 20.0, 32.5, 42.5};
//  double errX[100] = {2.5, 2.5, 2.5,  5.0,   7.5,  2.5};  
//  double XShift[100] =    {2.7, 7.7, 12.7, 20.2, 32.7, 42.7};

//  int numPlot = 5; 
//  int num = 5;
//  double X[100] =    {22.5, 27.5, 32.5, 37.5, 42.5};
//  double errX[100] = {2.5, 2.5, 2.5, 2.5,2.5};  
//  double XShift[100] =    {22.7, 27.7, 32.7, 37.7, 42.7};
 
//  int numPlot = 4; 
//  int num = 4;
//  double X[100] =    {22.5, 27.5, 33.5, 43.5};
//  double errX[100] = {2.5, 2.5, 3.5, 6.5};  
//  double XShift[100] =    {22.7, 27.7, 33.7, 43.7};
 
 int numPlot = 3; 
 int num = 3;
 double X[100] =    {25.0, 33.5, 43.5};
 double errX[100] = {5.0, 3.5, 6.5};  
 double XShift[100] =    {25.2, 33.7, 43.7};
 
 
 ///---- for R ----
 
 double DATA_R_ee[100];
 double DATA_R_mumu[100];
 double DATA_errR_ee[100];
 double DATA_errR_mumu[100]; 
 
 double DY_R_ee[100];
 double DY_R_mumu[100];
 double DY_errR_ee[100];
 double DY_errR_mumu[100]; 

 double DYmad_R_ee[100];
 double DYmad_R_mumu[100];
 double DYmad_errR_ee[100];
 double DYmad_errR_mumu[100]; 
 
 double all_R_ee[100];
 double all_R_mumu[100];
 double all_errR_ee[100];
 double all_errR_mumu[100]; 
 
 double DY_Rexact_ee[100];
 double DY_Rexact_mumu[100];
 double DY_errRexact_ee[100];
 double DY_errRexact_mumu[100]; 
 
 double DYmad_Rexact_ee[100];
 double DYmad_Rexact_mumu[100];
 double DYmad_errRexact_ee[100];
 double DYmad_errRexact_mumu[100]; 
 
 double DATA_standardR_ee[100];
 double DATA_standardR_mumu[100];
 double DATA_errstandardR_ee[100];
 double DATA_errstandardR_mumu[100]; 
 
 double DY_standardR_ee[100];
 double DY_standardR_mumu[100];
 double DY_errstandardR_ee[100];
 double DY_errstandardR_mumu[100]; 
 
 double DYmad_standardR_ee[100];
 double DYmad_standardR_mumu[100];
 double DYmad_errstandardR_ee[100];
 double DYmad_errstandardR_mumu[100]; 
 
 double all_standardR_ee[100];
 double all_standardR_mumu[100];
 double all_errstandardR_ee[100];
 double all_errstandardR_mumu[100]; 
 

 
 
 
 double DATA_NDY_R_A_mumu[100];
 double DATA_NDY_R_A_ee[100];
 double DATA_errNDY_R_A_mumu[100];
 double DATA_errNDY_R_A_ee[100];
 
 double DATA_NDYCorrected_R_A_mumu[100];
 double DATA_NDYCorrected_R_A_ee[100];
 double DATA_errNDYCorrected_R_A_mumu[100];
 double DATA_errNDYCorrected_R_A_ee[100];
 
 
 
 double DATA_NDY_standardR_A_mumu[100];
 double DATA_NDY_standardR_A_ee[100];
 double DATA_errNDY_standardR_A_mumu[100];
 double DATA_errNDY_standardR_A_ee[100];
 
 double DATA_NDYCorrected_standardR_A_mumu[100];
 double DATA_NDYCorrected_standardR_A_ee[100];
 double DATA_errNDYCorrected_standardR_A_mumu[100];
 double DATA_errNDYCorrected_standardR_A_ee[100];
 
 
  
 double DATA_NKB_ee[100];
 double DATA_NKB_mumu[100];
 double DATA_errNKB_ee[100];
 double DATA_errNKB_mumu[100]; 
 
 double DATA_NKBNew_ee[100];
 double DATA_NKBNew_mumu[100];
 double DATA_errNKBNew_ee[100];
 double DATA_errNKBNew_mumu[100]; 
 
 
 double DATA_NKA_ee[100];
 double DATA_NKA_mumu[100];
 double DATA_errNKA_ee[100];
 double DATA_errNKA_mumu[100]; 
 
 double DATA_NKANew_ee[100];
 double DATA_NKANew_mumu[100];
 double DATA_errNKANew_ee[100];
 double DATA_errNKANew_mumu[100]; 
 
 
 
 
 
 
 
 double DATA_NeeA[100];
 double DATA_NeeB[100];
 double DATA_NmumuA[100];
 double DATA_NmumuB[100];
 double DATA_NemuA[100];
 double DATA_NemuB[100];
 double DATA_NmueA[100];
 double DATA_NmueB[100];

 double DY_NeeA[100];
 double DY_NeeB[100];
 double DY_NmumuA[100];
 double DY_NmumuB[100];
 double DY_NemuA[100];
 double DY_NemuB[100];
 double DY_NmueA[100];
 double DY_NmueB[100];

 double DYmad_NeeA[100];
 double DYmad_NeeB[100];
 double DYmad_NmumuA[100];
 double DYmad_NmumuB[100];
 double DYmad_NemuA[100];
 double DYmad_NemuB[100];
 double DYmad_NmueA[100];
 double DYmad_NmueB[100];
 
 double other_NeeA[100];
 double other_NeeB[100];
 double other_NmumuA[100];
 double other_NmumuB[100];
 double other_NemuA[100];
 double other_NemuB[100];
 double other_NmueA[100];
 double other_NmueB[100];
 
 double all_NeeA[100];
 double all_NeeB[100];
 double all_NmumuA[100];
 double all_NmumuB[100];
 double all_NemuA[100];
 double all_NemuB[100];
 double all_NmueA[100];
 double all_NmueB[100];
 
 
 
 
 
 
 double DATA_errNeeA[100];
 double DATA_errNeeB[100];
 double DATA_errNmumuA[100];
 double DATA_errNmumuB[100];
 double DATA_errNemuA[100];
 double DATA_errNemuB[100];
 double DATA_errNmueA[100];
 double DATA_errNmueB[100];
 
 double DY_errNeeA[100];
 double DY_errNeeB[100];
 double DY_errNmumuA[100];
 double DY_errNmumuB[100];
 double DY_errNemuA[100];
 double DY_errNemuB[100];
 double DY_errNmueA[100];
 double DY_errNmueB[100];
 
 double DYmad_errNeeA[100];
 double DYmad_errNeeB[100];
 double DYmad_errNmumuA[100];
 double DYmad_errNmumuB[100];
 double DYmad_errNemuA[100];
 double DYmad_errNemuB[100];
 double DYmad_errNmueA[100];
 double DYmad_errNmueB[100];
 
 double other_errNeeA[100];
 double other_errNeeB[100];
 double other_errNmumuA[100];
 double other_errNmumuB[100];
 double other_errNemuA[100];
 double other_errNemuB[100];
 double other_errNmueA[100];
 double other_errNmueB[100];
 
 double all_errNeeA[100];
 double all_errNeeB[100];
 double all_errNmumuA[100];
 double all_errNmumuB[100];
 double all_errNemuA[100];
 double all_errNemuB[100];
 double all_errNmueA[100];
 double all_errNmueB[100];
 
 
 
 
 double NB, errNB;
 double denom;
 double numerator;
 double c1, c2, c3, c4, c5, c6, c7, c8;
 double a1,a2,a3,a4;
 
 
 TString nameHistoInRootFile;
 TH1F* h1;
 TH1F* h2; 
 TH1F* h3; 
 TH1F* h4; 
 
 ///****************************************************
 
 for (int iCut = 0; iCut <num; iCut++) {
  ///---- zone A (out) ----
  nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",iCut);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  

  nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",iCut);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  

  nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",iCut);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",iCut);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  
//   std::cout << " **** " << std::endl;
//   std::cout << " l1 e  = " << h1->GetBinContent(11) << " ---- " << " l2 e  = " << h2->GetBinContent(11) << std::endl;
//   std::cout << " l1 mu = " << h1->GetBinContent(13) << " ---- " << " l2 mu = " << h2->GetBinContent(13) << std::endl;
  
  DATA_NeeA[iCut]   = h1->GetBinContent(2);
  DATA_NmumuA[iCut] = h2->GetBinContent(2);
  DATA_NemuA[iCut]  = h3->GetBinContent(2);
  DATA_NmueA[iCut]  = h4->GetBinContent(2);
  
  DATA_errNeeA[iCut]   = h1->GetBinError(2);
  DATA_errNmumuA[iCut] = h2->GetBinError(2);
  DATA_errNemuA[iCut]  = h3->GetBinError(2);
  DATA_errNmueA[iCut]  = h4->GetBinError(2);
  
  
  
  
  nameHistoInRootFile = Form("Data/DY_%d_0_Tot_temp",iCut);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_1_Tot_temp",iCut);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_2_Tot_temp",iCut);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_3_Tot_temp",iCut);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  DY_NeeA[iCut]   = h1->GetBinContent(2);
  DY_NmumuA[iCut] = h2->GetBinContent(2);
  DY_NemuA[iCut]  = h3->GetBinContent(2);
  DY_NmueA[iCut]  = h4->GetBinContent(2);

  DY_errNeeA[iCut]   = h1->GetBinError(2);
  DY_errNmumuA[iCut] = h2->GetBinError(2);
  DY_errNemuA[iCut]  = h3->GetBinError(2);
  DY_errNmueA[iCut]  = h4->GetBinError(2);
  
  
  
  nameHistoInRootFile = Form("Data/DYmad_%d_0_Tot_temp",iCut);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DYmad_%d_1_Tot_temp",iCut);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DYmad_%d_2_Tot_temp",iCut);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DYmad_%d_3_Tot_temp",iCut);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  DYmad_NeeA[iCut]   = h1->GetBinContent(2);
  DYmad_NmumuA[iCut] = h2->GetBinContent(2);
  DYmad_NemuA[iCut]  = h3->GetBinContent(2);
  DYmad_NmueA[iCut]  = h4->GetBinContent(2);
  
  DYmad_errNeeA[iCut]   = h1->GetBinError(2);
  DYmad_errNmumuA[iCut] = h2->GetBinError(2);
  DYmad_errNemuA[iCut]  = h3->GetBinError(2);
  DYmad_errNmueA[iCut]  = h4->GetBinError(2);
  
  
  
  
  nameHistoInRootFile = Form("Data/other_%d_0_Tot_temp",iCut);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_1_Tot_temp",iCut);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_2_Tot_temp",iCut);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_3_Tot_temp",iCut);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  other_NeeA[iCut]   = h1->GetBinContent(2);
  other_NmumuA[iCut] = h2->GetBinContent(2);
  other_NemuA[iCut]  = h3->GetBinContent(2);
  other_NmueA[iCut]  = h4->GetBinContent(2);
  
  other_errNeeA[iCut]   = h1->GetBinError(2);
  other_errNmumuA[iCut] = h2->GetBinError(2);
  other_errNemuA[iCut]  = h3->GetBinError(2);
  other_errNmueA[iCut]  = h4->GetBinError(2);
  
  

  //---- all ----  
  all_NeeA[iCut]   = other_NeeA[iCut]   + DY_NeeA[iCut];
  all_NmumuA[iCut] = other_NmumuA[iCut] + DY_NmumuA[iCut];
  all_NemuA[iCut]  = other_NemuA[iCut]  + DY_NemuA[iCut];
  all_NmueA[iCut]  = other_NmueA[iCut]  + DY_NmueA[iCut];
  
  all_errNeeA[iCut]   = sqrt(other_errNeeA[iCut]*other_errNeeA[iCut]     + DY_errNeeA[iCut]*DY_errNeeA[iCut]);
  all_errNmumuA[iCut] = sqrt(other_errNmumuA[iCut]*other_errNmumuA[iCut] + DY_errNmumuA[iCut]*DY_errNmumuA[iCut]);
  all_errNemuA[iCut]  = sqrt(other_errNemuA[iCut]*other_errNemuA[iCut]   + DY_errNemuA[iCut]*DY_errNemuA[iCut]);
  all_errNmueA[iCut]  = sqrt(other_errNmueA[iCut]*other_errNmueA[iCut]   + DY_errNmueA[iCut]*DY_errNmueA[iCut]);
  
  
  
  ///---- zone B (in) ----
  nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",iCut+num);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",iCut+num);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",iCut+num);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",iCut+num);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  DATA_NeeB[iCut]   = h1->GetBinContent(2);
  DATA_NmumuB[iCut] = h2->GetBinContent(2);
  DATA_NemuB[iCut]  = h3->GetBinContent(2);
  DATA_NmueB[iCut]  = h4->GetBinContent(2);
  
  DATA_errNeeB[iCut]   = h1->GetBinError(2);
  DATA_errNmumuB[iCut] = h2->GetBinError(2);
  DATA_errNemuB[iCut]  = h3->GetBinError(2);
  DATA_errNmueB[iCut]  = h4->GetBinError(2);
  
  
  
  
  
  nameHistoInRootFile = Form("Data/DY_%d_0_Tot_temp",iCut+num);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_1_Tot_temp",iCut+num);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_2_Tot_temp",iCut+num);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_3_Tot_temp",iCut+num);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  DY_NeeB[iCut]   = h1->GetBinContent(2);
  DY_NmumuB[iCut] = h2->GetBinContent(2);
  DY_NemuB[iCut]  = h3->GetBinContent(2);
  DY_NmueB[iCut]  = h4->GetBinContent(2);
  
  DY_errNeeB[iCut]   = h1->GetBinError(2);
  DY_errNmumuB[iCut] = h2->GetBinError(2);
  DY_errNemuB[iCut]  = h3->GetBinError(2);
  DY_errNmueB[iCut]  = h4->GetBinError(2);
  
  
  
  
  nameHistoInRootFile = Form("Data/DYmad_%d_0_Tot_temp",iCut+num);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DYmad_%d_1_Tot_temp",iCut+num);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DYmad_%d_2_Tot_temp",iCut+num);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DYmad_%d_3_Tot_temp",iCut+num);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  DYmad_NeeB[iCut]   = h1->GetBinContent(2);
  DYmad_NmumuB[iCut] = h2->GetBinContent(2);
  DYmad_NemuB[iCut]  = h3->GetBinContent(2);
  DYmad_NmueB[iCut]  = h4->GetBinContent(2);
  
  DYmad_errNeeB[iCut]   = h1->GetBinError(2);
  DYmad_errNmumuB[iCut] = h2->GetBinError(2);
  DYmad_errNemuB[iCut]  = h3->GetBinError(2);
  DYmad_errNmueB[iCut]  = h4->GetBinError(2);
  
  
  
  
  nameHistoInRootFile = Form("Data/other_%d_0_Tot_temp",iCut+num);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_1_Tot_temp",iCut+num);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_2_Tot_temp",iCut+num);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_3_Tot_temp",iCut+num);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  other_NeeB[iCut]   = h1->GetBinContent(2);
  other_NmumuB[iCut] = h2->GetBinContent(2);
  other_NemuB[iCut]  = h3->GetBinContent(2);
  other_NmueB[iCut]  = h4->GetBinContent(2);
  
  other_errNeeB[iCut]   = h1->GetBinError(2);
  other_errNmumuB[iCut] = h2->GetBinError(2);
  other_errNemuB[iCut]  = h3->GetBinError(2);
  other_errNmueB[iCut]  = h4->GetBinError(2);
  
  
  //---- all ----  
  all_NeeB[iCut]   = other_NeeB[iCut]     + DY_NeeB[iCut];
  all_NmumuB[iCut] = other_NmumuB[iCut]   + DY_NmumuB[iCut];
  all_NemuB[iCut]  = other_NemuB[iCut]    + DY_NemuB[iCut];
  all_NmueB[iCut]  = other_NmueB[iCut]    + DY_NmueB[iCut];
  
  all_errNeeB[iCut]   = sqrt(other_errNeeB[iCut]*other_errNeeB[iCut]     + DY_errNeeB[iCut]*DY_errNeeB[iCut]);
  all_errNmumuB[iCut] = sqrt(other_errNmumuB[iCut]*other_errNmumuB[iCut] + DY_errNmumuB[iCut]*DY_errNmumuB[iCut]);
  all_errNemuB[iCut]  = sqrt(other_errNemuB[iCut]*other_errNemuB[iCut]   + DY_errNemuB[iCut]*DY_errNemuB[iCut]);
  all_errNmueB[iCut]  = sqrt(other_errNmueB[iCut]*other_errNmueB[iCut]   + DY_errNmueB[iCut]*DY_errNmueB[iCut]);
  
  
  
  ///==== calculation of NB and NA from "other" ====
  
  DATA_NKB_ee[iCut] = 0.5 * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut]) ;
  a1 = (DATA_errNemuB[iCut]*DATA_errNemuB[iCut] * (DATA_NeeB[iCut] / DATA_NmumuB[iCut])) ;
  a2 = (DATA_errNmueB[iCut]*DATA_errNmueB[iCut] * (DATA_NeeB[iCut] / DATA_NmumuB[iCut])) ;
  a3 = (DATA_errNeeB[iCut] * DATA_errNeeB[iCut]     * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * (1. / 4. / DATA_NmumuB[iCut] / DATA_NeeB[iCut] )  ) ;
  a4 = (DATA_errNmumuB[iCut] * DATA_errNmumuB[iCut] * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * (1. / 4. * DATA_NeeB[iCut] / DATA_NmumuB[iCut] ) / DATA_NmumuB[iCut] / DATA_NmumuB[iCut] );
  DATA_errNKB_ee[iCut] = 0.5 * sqrt( a1 + a2 + a3 + a4); 

  DATA_NKB_mumu[iCut] = 0.5 * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut]) ;
  a1 = (DATA_errNemuB[iCut]*DATA_errNemuB[iCut] * (DATA_NmumuB[iCut] / DATA_NeeB[iCut])) ;
  a2 = (DATA_errNmueB[iCut]*DATA_errNmueB[iCut] * (DATA_NmumuB[iCut] / DATA_NeeB[iCut])) ;
  a3 = (DATA_errNmumuB[iCut] * DATA_errNmumuB[iCut]     * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * (1. / 4. / DATA_NeeB[iCut] / DATA_NmumuB[iCut] )  ) ;
  a4 = (DATA_errNeeB[iCut] * DATA_errNeeB[iCut] * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * (DATA_NemuB[iCut] + DATA_NmueB[iCut]) * (1. / 4. * DATA_NmumuB[iCut] / DATA_NeeB[iCut] ) / DATA_NeeB[iCut] / DATA_NeeB[iCut] );
  DATA_errNKB_mumu[iCut] = 0.5 * sqrt( a1 + a2 + a3 + a4); 
  

  
  DATA_NKBNew_ee[iCut] = sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut] * DATA_NemuB[iCut] * DATA_NmueB[iCut]);
  a1 = DATA_errNeeB[iCut]    *  (1./2. * sqrt(DATA_NemuB[iCut]*DATA_NmueB[iCut]/DATA_NeeB[iCut]/DATA_NmumuB[iCut]))  ;
  a2 = DATA_errNmumuB[iCut]  *  (1./2. * sqrt(DATA_NemuB[iCut]*DATA_NmueB[iCut]*DATA_NeeB[iCut]/DATA_NmumuB[iCut])/DATA_NmumuB[iCut]);
  a3 = DATA_NemuB[iCut] ? (DATA_errNemuB[iCut]   *  (1./2. * sqrt(DATA_NeeB[iCut]/DATA_NmumuB[iCut]*DATA_NmueB[iCut]/DATA_NemuB[iCut]))) : 0.;
  a4 = DATA_NmueB[iCut] ? (DATA_errNmueB[iCut]   *  (1./2. * sqrt(DATA_NeeB[iCut]/DATA_NmumuB[iCut]*DATA_NemuB[iCut]/DATA_NmueB[iCut]))) : 0.;
  DATA_errNKBNew_ee[iCut] = sqrt(a1*a1 + a2*a2 + a3*a3 + a4*a4); 
  

  DATA_NKBNew_mumu[iCut] = sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut] * DATA_NmueB[iCut] * DATA_NemuB[iCut]);
  a1 = DATA_errNmumuB[iCut]    *  (1./2. * sqrt(DATA_NmueB[iCut]*DATA_NemuB[iCut]/DATA_NmumuB[iCut]/DATA_NeeB[iCut]))  ;
  a2 = DATA_errNeeB[iCut]  *  (1./2. * sqrt(DATA_NmueB[iCut]*DATA_NemuB[iCut]*DATA_NmumuB[iCut]/DATA_NeeB[iCut])/DATA_NeeB[iCut]);
  a3 = DATA_NmueB[iCut] ? (DATA_errNmueB[iCut]   *  (1./2. * sqrt(DATA_NmumuB[iCut]/DATA_NeeB[iCut]*DATA_NemuB[iCut]/DATA_NmueB[iCut]))) : 0.;
  a4 = DATA_NemuB[iCut] ? (DATA_errNemuB[iCut]   *  (1./2. * sqrt(DATA_NmumuB[iCut]/DATA_NeeB[iCut]*DATA_NmueB[iCut]/DATA_NemuB[iCut]))) : 0.;
  DATA_errNKBNew_mumu[iCut] = sqrt(a1*a1 + a2*a2 + a3*a3 + a4*a4); 
  
  
  
  
  
  DATA_NKA_ee[iCut] = 0.5 * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * sqrt(DATA_NeeA[iCut] / DATA_NmumuA[iCut]) ;
  a1 = (DATA_errNemuA[iCut]*DATA_errNemuA[iCut] * (DATA_NeeA[iCut] / DATA_NmumuA[iCut])) ;
  a2 = (DATA_errNmueA[iCut]*DATA_errNmueA[iCut] * (DATA_NeeA[iCut] / DATA_NmumuA[iCut])) ;
  a3 = (DATA_errNeeA[iCut] * DATA_errNeeA[iCut]     * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * (1. / 4. / DATA_NmumuA[iCut] / DATA_NeeA[iCut] )  ) ;
  a4 = (DATA_errNmumuA[iCut] * DATA_errNmumuA[iCut] * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * (1. / 4. * DATA_NeeA[iCut] / DATA_NmumuA[iCut] ) / DATA_NmumuA[iCut] / DATA_NmumuA[iCut] );
  DATA_errNKA_ee[iCut] = 0.5 * sqrt( a1 + a2 + a3 + a4); 
  
  DATA_NKA_mumu[iCut] = 0.5 * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * sqrt(DATA_NmumuA[iCut] / DATA_NeeA[iCut]) ;
  a1 = (DATA_errNemuA[iCut]*DATA_errNemuA[iCut] * (DATA_NmumuA[iCut] / DATA_NeeA[iCut])) ;
  a2 = (DATA_errNmueA[iCut]*DATA_errNmueA[iCut] * (DATA_NmumuA[iCut] / DATA_NeeA[iCut])) ;
  a3 = (DATA_errNmumuA[iCut] * DATA_errNmumuA[iCut]     * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * (1. / 4. / DATA_NeeA[iCut] / DATA_NmumuA[iCut] )  ) ;
  a4 = (DATA_errNeeA[iCut] * DATA_errNeeA[iCut] * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * ( 1. / 4. * DATA_NmumuA[iCut] / DATA_NeeA[iCut] ) / DATA_NeeA[iCut] / DATA_NeeA[iCut] );
  DATA_errNKA_mumu[iCut] = 0.5 * sqrt( a1 + a2 + a3 + a4); 
  
  
  
  DATA_NKANew_ee[iCut] = sqrt(DATA_NeeA[iCut] / DATA_NmumuA[iCut] * DATA_NemuA[iCut] * DATA_NmueA[iCut]);
  a1 = DATA_errNeeA[iCut]    *  (1./2. * sqrt(DATA_NemuA[iCut]*DATA_NmueA[iCut]/DATA_NeeA[iCut]/DATA_NmumuA[iCut]))  ;
  a2 = DATA_errNmumuA[iCut]  *  (1./2. * sqrt(DATA_NemuA[iCut]*DATA_NmueA[iCut]*DATA_NeeA[iCut]/DATA_NmumuA[iCut])/DATA_NmumuA[iCut]);
  a3 = DATA_NemuA[iCut] ? (DATA_errNemuA[iCut]   *  (1./2. * sqrt(DATA_NeeA[iCut]/DATA_NmumuA[iCut]*DATA_NmueA[iCut]/DATA_NemuA[iCut]))) : 0.;
  a4 = DATA_NmueA[iCut] ? (DATA_errNmueA[iCut]   *  (1./2. * sqrt(DATA_NeeA[iCut]/DATA_NmumuA[iCut]*DATA_NemuA[iCut]/DATA_NmueA[iCut]))) : 0.;
  DATA_errNKANew_ee[iCut] = sqrt(a1*a1 + a2*a2 + a3*a3 + a4*a4); 
  
  
  DATA_NKANew_mumu[iCut] = sqrt(DATA_NmumuA[iCut] / DATA_NeeA[iCut] * DATA_NmueA[iCut] * DATA_NemuA[iCut]);
  a1 = DATA_errNmumuA[iCut]    *  (1./2. * sqrt(DATA_NmueA[iCut]*DATA_NemuA[iCut]/DATA_NmumuA[iCut]/DATA_NeeA[iCut]))  ;
  a2 = DATA_errNeeA[iCut]  *  (1./2. * sqrt(DATA_NmueA[iCut]*DATA_NemuA[iCut]*DATA_NmumuA[iCut]/DATA_NeeA[iCut])/DATA_NeeA[iCut]);
  a3 = DATA_NmueA[iCut] ? (DATA_errNmueA[iCut]   *  (1./2. * sqrt(DATA_NmumuA[iCut]/DATA_NeeA[iCut]*DATA_NemuA[iCut]/DATA_NmueA[iCut]))) : 0.;
  a4 = DATA_NemuA[iCut] ? (DATA_errNemuA[iCut]   *  (1./2. * sqrt(DATA_NmumuA[iCut]/DATA_NeeA[iCut]*DATA_NmueA[iCut]/DATA_NemuA[iCut]))) : 0.;
  DATA_errNKANew_mumu[iCut] = sqrt(a1*a1 + a2*a2 + a3*a3 + a4*a4); 
  
  
  ///==== calculation of R ====
  
  ///==== MC ====
  DY_Rexact_ee[iCut] = DY_NeeA[iCut] / DY_NeeB[iCut];
  DY_errRexact_ee[iCut] = sqrt((DY_errNeeA[iCut]*DY_errNeeA[iCut] / DY_NeeB[iCut]/ DY_NeeB[iCut]) + DY_errNeeB[iCut] * DY_NeeA[iCut] / DY_NeeB[iCut]/ DY_NeeB[iCut] * DY_errNeeB[iCut] * DY_NeeA[iCut] / DY_NeeB[iCut]/ DY_NeeB[iCut]);

  DY_Rexact_mumu[iCut] = DY_NmumuA[iCut] / DY_NmumuB[iCut];
  DY_errRexact_mumu[iCut] = sqrt((DY_errNmumuA[iCut]*DY_errNmumuA[iCut] / DY_NmumuB[iCut]/ DY_NmumuB[iCut]) + DY_errNmumuB[iCut] * DY_NmumuA[iCut] / DY_NmumuB[iCut]/ DY_NmumuB[iCut] * DY_errNmumuB[iCut] * DY_NmumuA[iCut] / DY_NmumuB[iCut]/ DY_NmumuB[iCut]);

  DYmad_Rexact_ee[iCut] = DYmad_NeeA[iCut] / DYmad_NeeB[iCut];
  DYmad_errRexact_ee[iCut] = sqrt((DYmad_errNeeA[iCut]*DYmad_errNeeA[iCut] / DYmad_NeeB[iCut]/ DYmad_NeeB[iCut]) + DYmad_errNeeB[iCut] * DYmad_NeeA[iCut] / DYmad_NeeB[iCut]/ DYmad_NeeB[iCut] * DYmad_errNeeB[iCut] * DYmad_NeeA[iCut] / DYmad_NeeB[iCut]/ DYmad_NeeB[iCut]);
  
  DYmad_Rexact_mumu[iCut] = DYmad_NmumuA[iCut] / DYmad_NmumuB[iCut];
  DYmad_errRexact_mumu[iCut] = sqrt((DYmad_errNmumuA[iCut]*DYmad_errNmumuA[iCut] / DYmad_NmumuB[iCut]/ DYmad_NmumuB[iCut]) + DYmad_errNmumuB[iCut] * DYmad_NmumuA[iCut] / DYmad_NmumuB[iCut]/ DYmad_NmumuB[iCut] * DYmad_errNmumuB[iCut] * DYmad_NmumuA[iCut] / DYmad_NmumuB[iCut]/ DYmad_NmumuB[iCut]);
  
  

  numerator = all_NeeA[iCut] - sqrt(all_NeeA[iCut] / all_NmumuA[iCut] * all_NemuA[iCut] * all_NmueA[iCut]) ;
  denom =     all_NeeB[iCut] - sqrt(all_NeeB[iCut] / all_NmumuB[iCut] * all_NemuB[iCut] * all_NmueB[iCut]);
  all_R_ee[iCut] = numerator / denom;
  
  c1 = all_errNeeA[iCut]   / denom *  (1. - 1./2. * sqrt(all_NemuA[iCut]*all_NmueA[iCut]/all_NeeA[iCut]/all_NmumuA[iCut]))  ;
  c2 = all_errNmumuA[iCut] / denom *  (1./2. * sqrt(all_NemuA[iCut]*all_NmueA[iCut]*all_NeeA[iCut]/all_NmumuA[iCut])/all_NmumuA[iCut]);
  c3 = all_NemuA[iCut] ? all_errNemuA[iCut]  / denom *  (1./2. * sqrt(all_NeeA[iCut]/all_NmumuA[iCut]*all_NmueA[iCut]/all_NemuA[iCut])) : 0.;
  c4 = all_NmueA[iCut] ? all_errNmueA[iCut]  / denom *  (1./2. * sqrt(all_NeeA[iCut]/all_NmumuA[iCut]*all_NemuA[iCut]/all_NmueA[iCut])) : 0.;
  
  c5 = all_errNeeB[iCut]   * numerator / denom / denom *  (1. - 1./2. * sqrt(all_NemuB[iCut]*all_NmueB[iCut]/all_NeeB[iCut]/all_NmumuB[iCut]))  ;
  c6 = all_errNmumuB[iCut] * numerator / denom / denom *  (1./2. * sqrt(all_NemuB[iCut]*all_NmueB[iCut]*all_NeeB[iCut]/all_NmumuB[iCut])/all_NmumuB[iCut]);
  c7 = all_NemuB[iCut] ? all_errNemuB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(all_NeeB[iCut]/all_NmumuB[iCut]*all_NmueB[iCut]/all_NemuB[iCut])) : 0.;
  c8 = all_NmueB[iCut] ? all_errNmueB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(all_NeeB[iCut]/all_NmumuB[iCut]*all_NemuB[iCut]/all_NmueB[iCut])) : 0.;
  
  all_errR_ee[iCut] = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4 + c5*c5 + c6*c6 + c7*c7 + c8*c8);
  
  
  
  numerator = all_NmumuA[iCut] - sqrt(all_NmumuA[iCut] / all_NeeA[iCut] * all_NmueA[iCut] * all_NemuA[iCut]) ;
  denom =     all_NmumuB[iCut] - sqrt(all_NmumuB[iCut] / all_NeeB[iCut] * all_NmueB[iCut] * all_NemuB[iCut]);
  all_R_mumu[iCut] = numerator / denom;
  
  c1 = all_errNmumuA[iCut]   / denom *  (1. - 1./2. * sqrt(all_NmueA[iCut]*all_NemuA[iCut]/all_NmumuA[iCut]/all_NeeA[iCut]))  ;
  c2 = all_errNeeA[iCut] / denom *  (1./2. * sqrt(all_NmueA[iCut]*all_NemuA[iCut]*all_NmumuA[iCut]/all_NeeA[iCut])/all_NeeA[iCut]);
  c3 = all_NmueA[iCut]     ?   all_errNmueA[iCut]  / denom *  (1./2. * sqrt(all_NmumuA[iCut]/all_NeeA[iCut]*all_NemuA[iCut]/all_NmueA[iCut])) : 0.;
  c4 = all_NemuA[iCut]     ?   all_errNemuA[iCut]  / denom *  (1./2. * sqrt(all_NmumuA[iCut]/all_NeeA[iCut]*all_NmueA[iCut]/all_NemuA[iCut])) : 0.;
  
  c5 = all_errNmumuB[iCut]   * numerator / denom / denom *  (1. - 1./2. * sqrt(all_NmueB[iCut]*all_NemuB[iCut]/all_NmumuB[iCut]/all_NeeB[iCut]))  ;
  c6 = all_errNeeB[iCut] * numerator / denom / denom *  (1./2. * sqrt(all_NmueB[iCut]*all_NemuB[iCut]*all_NmumuB[iCut]/all_NeeB[iCut])/all_NeeB[iCut]);
  c7 = all_NmueB[iCut]  ?  all_errNmueB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(all_NmumuB[iCut]/all_NeeB[iCut]*all_NemuB[iCut]/all_NmueB[iCut])) : 0.;
  c8 = all_NemuB[iCut]  ?  all_errNemuB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(all_NmumuB[iCut]/all_NeeB[iCut]*all_NmueB[iCut]/all_NemuB[iCut])) : 0. ;
  
  all_errR_mumu[iCut] = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4 + c5*c5 + c6*c6 + c7*c7 + c8*c8);
  
  
  
  
  
  
  numerator = DY_NeeA[iCut] - sqrt(DY_NeeA[iCut] / DY_NmumuA[iCut] * DY_NemuA[iCut] * DY_NmueA[iCut]) ;
  denom =     DY_NeeB[iCut] - sqrt(DY_NeeB[iCut] / DY_NmumuB[iCut] * DY_NemuB[iCut] * DY_NmueB[iCut]);
  DY_R_ee[iCut] = numerator / denom;
  
  c1 = DY_errNeeA[iCut]   / denom *  (1. - 1./2. * sqrt(DY_NemuA[iCut]*DY_NmueA[iCut]/DY_NeeA[iCut]/DY_NmumuA[iCut]))  ;
  c2 = DY_errNmumuA[iCut] / denom *  (1./2. * sqrt(DY_NemuA[iCut]*DY_NmueA[iCut]*DY_NeeA[iCut]/DY_NmumuA[iCut])/DY_NmumuA[iCut]);
  c3 = DY_NemuA[iCut] ? DY_errNemuA[iCut]  / denom *  (1./2. * sqrt(DY_NeeA[iCut]/DY_NmumuA[iCut]*DY_NmueA[iCut]/DY_NemuA[iCut])) : 0.;
  c4 = DY_NmueA[iCut] ? DY_errNmueA[iCut]  / denom *  (1./2. * sqrt(DY_NeeA[iCut]/DY_NmumuA[iCut]*DY_NemuA[iCut]/DY_NmueA[iCut])) : 0.;
  
  c5 = DY_errNeeB[iCut]   * numerator / denom / denom *  (1. - 1./2. * sqrt(DY_NemuB[iCut]*DY_NmueB[iCut]/DY_NeeB[iCut]/DY_NmumuB[iCut]))  ;
  c6 = DY_errNmumuB[iCut] * numerator / denom / denom *  (1./2. * sqrt(DY_NemuB[iCut]*DY_NmueB[iCut]*DY_NeeB[iCut]/DY_NmumuB[iCut])/DY_NmumuB[iCut]);
  c7 = DY_NemuB[iCut] ? DY_errNemuB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(DY_NeeB[iCut]/DY_NmumuB[iCut]*DY_NmueB[iCut]/DY_NemuB[iCut])) : 0.;
  c8 = DY_NmueB[iCut] ? DY_errNmueB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(DY_NeeB[iCut]/DY_NmumuB[iCut]*DY_NemuB[iCut]/DY_NmueB[iCut])) : 0.;
  
  DY_errR_ee[iCut] = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4 + c5*c5 + c6*c6 + c7*c7 + c8*c8);
  
  
  
  numerator = DY_NmumuA[iCut] - sqrt(DY_NmumuA[iCut] / DY_NeeA[iCut] * DY_NmueA[iCut] * DY_NemuA[iCut]) ;
  denom =     DY_NmumuB[iCut] - sqrt(DY_NmumuB[iCut] / DY_NeeB[iCut] * DY_NmueB[iCut] * DY_NemuB[iCut]);
  DY_R_mumu[iCut] = numerator / denom;
  
  c1 = DY_errNmumuA[iCut]   / denom *  (1. - 1./2. * sqrt(DY_NmueA[iCut]*DY_NemuA[iCut]/DY_NmumuA[iCut]/DY_NeeA[iCut]))  ;
  c2 = DY_errNeeA[iCut] / denom *  (1./2. * sqrt(DY_NmueA[iCut]*DY_NemuA[iCut]*DY_NmumuA[iCut]/DY_NeeA[iCut])/DY_NeeA[iCut]);
  c3 = DY_NmueA[iCut]     ?   DY_errNmueA[iCut]  / denom *  (1./2. * sqrt(DY_NmumuA[iCut]/DY_NeeA[iCut]*DY_NemuA[iCut]/DY_NmueA[iCut])) : 0.;
  c4 = DY_NemuA[iCut]     ?   DY_errNemuA[iCut]  / denom *  (1./2. * sqrt(DY_NmumuA[iCut]/DY_NeeA[iCut]*DY_NmueA[iCut]/DY_NemuA[iCut])) : 0.;
  
  c5 = DY_errNmumuB[iCut]   * numerator / denom / denom *  (1. - 1./2. * sqrt(DY_NmueB[iCut]*DY_NemuB[iCut]/DY_NmumuB[iCut]/DY_NeeB[iCut]))  ;
  c6 = DY_errNeeB[iCut] * numerator / denom / denom *  (1./2. * sqrt(DY_NmueB[iCut]*DY_NemuB[iCut]*DY_NmumuB[iCut]/DY_NeeB[iCut])/DY_NeeB[iCut]);
  c7 = DY_NmueB[iCut]  ?  DY_errNmueB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(DY_NmumuB[iCut]/DY_NeeB[iCut]*DY_NemuB[iCut]/DY_NmueB[iCut])) : 0.;
  c8 = DY_NemuB[iCut]  ?  DY_errNemuB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(DY_NmumuB[iCut]/DY_NeeB[iCut]*DY_NmueB[iCut]/DY_NemuB[iCut])) : 0. ;
  
  DY_errR_mumu[iCut] = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4 + c5*c5 + c6*c6 + c7*c7 + c8*c8);
  
  ///==== Ree from data = (NeeA - keeA' * NemuA) / (NeeB - keeB' * NemuB)
  
  numerator = DATA_NeeA[iCut] - sqrt(DATA_NeeA[iCut] / DATA_NmumuA[iCut] * DATA_NemuA[iCut] * DATA_NmueA[iCut]) ;
  denom =     DATA_NeeB[iCut] - sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut] * DATA_NemuB[iCut] * DATA_NmueB[iCut]);
  DATA_R_ee[iCut] = numerator / denom;
  
  c1 = DATA_errNeeA[iCut]   / denom *  (1. - 1./2. * sqrt(DATA_NemuA[iCut]*DATA_NmueA[iCut]/DATA_NeeA[iCut]/DATA_NmumuA[iCut]))  ;
  c2 = DATA_errNmumuA[iCut] / denom *  (1./2. * sqrt(DATA_NemuA[iCut]*DATA_NmueA[iCut]*DATA_NeeA[iCut]/DATA_NmumuA[iCut])/DATA_NmumuA[iCut]);
  c3 = DATA_NemuA[iCut] ? DATA_errNemuA[iCut]  / denom *  (1./2. * sqrt(DATA_NeeA[iCut]/DATA_NmumuA[iCut]*DATA_NmueA[iCut]/DATA_NemuA[iCut])) : 0.;
  c4 = DATA_NmueA[iCut] ? DATA_errNmueA[iCut]  / denom *  (1./2. * sqrt(DATA_NeeA[iCut]/DATA_NmumuA[iCut]*DATA_NemuA[iCut]/DATA_NmueA[iCut])) : 0.;
  
  c5 = DATA_errNeeB[iCut]   * numerator / denom / denom *  (1. - 1./2. * sqrt(DATA_NemuB[iCut]*DATA_NmueB[iCut]/DATA_NeeB[iCut]/DATA_NmumuB[iCut]))  ;
  c6 = DATA_errNmumuB[iCut] * numerator / denom / denom *  (1./2. * sqrt(DATA_NemuB[iCut]*DATA_NmueB[iCut]*DATA_NeeB[iCut]/DATA_NmumuB[iCut])/DATA_NmumuB[iCut]);
  c7 = DATA_NemuB[iCut] ? DATA_errNemuB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(DATA_NeeB[iCut]/DATA_NmumuB[iCut]*DATA_NmueB[iCut]/DATA_NemuB[iCut])) : 0.;
  c8 = DATA_NmueB[iCut] ? DATA_errNmueB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(DATA_NeeB[iCut]/DATA_NmumuB[iCut]*DATA_NemuB[iCut]/DATA_NmueB[iCut])) : 0.;
  
  DATA_errR_ee[iCut] = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4 + c5*c5 + c6*c6 + c7*c7 + c8*c8);
  
  
  ///==== Rmumu from data = (NmumuA - kmumuA' * NemuA) / (NmumuB - kmumuB' * NemuB)
  
  numerator = DATA_NmumuA[iCut] - sqrt(DATA_NmumuA[iCut] / DATA_NeeA[iCut] * DATA_NmueA[iCut] * DATA_NemuA[iCut]) ;
  denom =     DATA_NmumuB[iCut] - sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut] * DATA_NmueB[iCut] * DATA_NemuB[iCut]);
  DATA_R_mumu[iCut] = numerator / denom;
  
  c1 = DATA_errNmumuA[iCut]   / denom *  (1. - 1./2. * sqrt(DATA_NmueA[iCut]*DATA_NemuA[iCut]/DATA_NmumuA[iCut]/DATA_NeeA[iCut]))  ;
  c2 = DATA_errNeeA[iCut] / denom *  (1./2. * sqrt(DATA_NmueA[iCut]*DATA_NemuA[iCut]*DATA_NmumuA[iCut]/DATA_NeeA[iCut])/DATA_NeeA[iCut]);
  c3 = DATA_NmueA[iCut]     ?   DATA_errNmueA[iCut]  / denom *  (1./2. * sqrt(DATA_NmumuA[iCut]/DATA_NeeA[iCut]*DATA_NemuA[iCut]/DATA_NmueA[iCut])) : 0.;
  c4 = DATA_NemuA[iCut]     ?   DATA_errNemuA[iCut]  / denom *  (1./2. * sqrt(DATA_NmumuA[iCut]/DATA_NeeA[iCut]*DATA_NmueA[iCut]/DATA_NemuA[iCut])) : 0.;
  
  c5 = DATA_errNmumuB[iCut]   * numerator / denom / denom *  (1. - 1./2. * sqrt(DATA_NmueB[iCut]*DATA_NemuB[iCut]/DATA_NmumuB[iCut]/DATA_NeeB[iCut]))  ;
  c6 = DATA_errNeeB[iCut] * numerator / denom / denom *  (1./2. * sqrt(DATA_NmueB[iCut]*DATA_NemuB[iCut]*DATA_NmumuB[iCut]/DATA_NeeB[iCut])/DATA_NeeB[iCut]);
  c7 = DATA_NmueB[iCut]  ?  DATA_errNmueB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(DATA_NmumuB[iCut]/DATA_NeeB[iCut]*DATA_NemuB[iCut]/DATA_NmueB[iCut])) : 0.;
  c8 = DATA_NemuB[iCut]  ?  DATA_errNemuB[iCut]  * numerator / denom / denom *  (1./2. * sqrt(DATA_NmumuB[iCut]/DATA_NeeB[iCut]*DATA_NmueB[iCut]/DATA_NemuB[iCut])) : 0. ;
  
  DATA_errR_mumu[iCut] = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4 + c5*c5 + c6*c6 + c7*c7 + c8*c8);
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  ///==== simple R method ====
  denom = (DATA_NeeB[iCut] - 1./2. * sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut]) * (DATA_NemuB[iCut]+DATA_NmueB[iCut]));
  DATA_standardR_ee[iCut] = (DATA_NeeA[iCut] - 1./2. * sqrt(DATA_NeeA[iCut] / DATA_NmumuA[iCut]) * (DATA_NemuA[iCut] + DATA_NmueA[iCut])) / (DATA_NeeB[iCut] - 1./2. * sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut]) * (DATA_NemuB[iCut]+DATA_NmueB[iCut]));
  
  c1 = 1./denom/denom * ((1 - 1./4. * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) / sqrt(DATA_NeeA[iCut]*DATA_NmumuA[iCut])) * DATA_errNeeA[iCut]) * ((1 - 1./4. * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) / sqrt(DATA_NeeA[iCut]*DATA_NmumuA[iCut])) * DATA_errNeeA[iCut]) ;
  c2 = 1./denom/denom * ((1./4. * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) / DATA_NmumuA[iCut] * sqrt(DATA_NeeA[iCut] / DATA_NmumuA[iCut])) * DATA_errNmumuA[iCut]) * ((1./4. * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) / DATA_NmumuA[iCut] * sqrt(DATA_NeeA[iCut] / DATA_NmumuA[iCut])) * DATA_errNmumuA[iCut]) ;
  c3 = 1./denom/denom * (1./2. * sqrt(DATA_NeeA[iCut] / DATA_NmumuA[iCut]) * sqrt(DATA_errNemuA[iCut]*DATA_errNemuA[iCut] + DATA_errNmueA[iCut]*DATA_errNmueA[iCut])) * (1./2. * sqrt(DATA_NeeA[iCut] / DATA_NmumuA[iCut]) * sqrt(DATA_errNemuA[iCut]*DATA_errNemuA[iCut] + DATA_errNmueA[iCut]*DATA_errNmueA[iCut])) ;
  
  c4 = 1./denom/denom/denom/denom * ((1 - 1./4. * (DATA_NemuB[iCut]+DATA_NmueB[iCut]) / sqrt(DATA_NeeB[iCut]*DATA_NmumuB[iCut])) * DATA_errNeeB[iCut]) * ((1 - 1./4. * (DATA_NemuB[iCut]+DATA_NmueB[iCut]) / sqrt(DATA_NeeB[iCut]*DATA_NmumuB[iCut])) * DATA_errNeeB[iCut]) ;
  c5 = 1./denom/denom/denom/denom * ((1./4. * (DATA_NemuB[iCut]+DATA_NmueB[iCut]) / DATA_NmumuB[iCut] * sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut])) * DATA_errNmumuB[iCut]) * ((1./4. * (DATA_NemuB[iCut]+DATA_NmueB[iCut]) / DATA_NmumuB[iCut] * sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut])) * DATA_errNmumuB[iCut]) ;
  c6 = 1./denom/denom/denom/denom * (1./2. * sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut]) * sqrt(DATA_errNemuB[iCut]*DATA_errNemuB[iCut] + DATA_errNmueB[iCut]*DATA_errNmueB[iCut])) * (1./2. * sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut]) * sqrt(DATA_errNemuB[iCut]*DATA_errNemuB[iCut] + DATA_errNmueB[iCut]*DATA_errNmueB[iCut])) ;
  
  DATA_errstandardR_ee[iCut] = sqrt(c1+c2+c3+c4+c5+c6);
  
  ///==== Rmumu from data = (NmumuA - kmumuA * NemuA) / (NmumuB - kmumuB * NemuB)
  denom = (DATA_NmumuB[iCut] - 1./2. * sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut]) * (DATA_NemuB[iCut]+DATA_NmueB[iCut]));
  DATA_standardR_mumu[iCut] = (DATA_NmumuA[iCut] - 1./2. * sqrt(DATA_NmumuA[iCut] / DATA_NeeA[iCut]) * (DATA_NemuA[iCut] + DATA_NmueA[iCut])) / (DATA_NmumuB[iCut] - 1./2. * sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut]) * (DATA_NemuB[iCut]+DATA_NmueB[iCut]));
  
  c1 = 1./denom/denom * ((1 - 1./4. * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) / sqrt(DATA_NmumuA[iCut]*DATA_NeeA[iCut])) * DATA_errNmumuA[iCut]) * ((1 - 1./4. * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) / sqrt(DATA_NmumuA[iCut]*DATA_NeeA[iCut])) * DATA_errNmumuA[iCut]) ;
  c2 = 1./denom/denom * ((1./4. * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) / DATA_NeeA[iCut] * sqrt(DATA_NmumuA[iCut] / DATA_NeeA[iCut])) * DATA_errNeeA[iCut]) * ((1./4. * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) / DATA_NeeA[iCut] * sqrt(DATA_NmumuA[iCut] / DATA_NeeA[iCut])) * DATA_errNeeA[iCut]) ;
  c3 = 1./denom/denom * (1./2. * sqrt(DATA_NmumuA[iCut] / DATA_NeeA[iCut]) * sqrt(DATA_errNemuA[iCut]*DATA_errNemuA[iCut] + DATA_errNmueA[iCut]*DATA_errNmueA[iCut])) * (1./2. * sqrt(DATA_NmumuA[iCut] / DATA_NeeA[iCut]) * sqrt(DATA_errNemuA[iCut]*DATA_errNemuA[iCut] + DATA_errNmueA[iCut]*DATA_errNmueA[iCut])) ;
  
  c4 = 1./denom/denom/denom/denom * ((1 - 1./4. * (DATA_NemuB[iCut]+DATA_NmueB[iCut]) / sqrt(DATA_NmumuB[iCut]*DATA_NeeB[iCut])) * DATA_errNmumuB[iCut]) * ((1 - 1./4. * (DATA_NemuB[iCut]+DATA_NmueB[iCut]) / sqrt(DATA_NmumuB[iCut]*DATA_NeeB[iCut])) * DATA_errNmumuB[iCut]) ;
  c5 = 1./denom/denom/denom/denom * ((1./4. * (DATA_NemuB[iCut]+DATA_NmueB[iCut]) / DATA_NeeB[iCut] * sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut])) * DATA_errNeeB[iCut]) * ((1./4. * (DATA_NemuB[iCut]+DATA_NmueB[iCut]) / DATA_NeeB[iCut] * sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut])) * DATA_errNeeB[iCut]) ;
  c6 = 1./denom/denom/denom/denom * (1./2. * sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut]) * sqrt(DATA_errNemuB[iCut]*DATA_errNemuB[iCut] + DATA_errNmueB[iCut]*DATA_errNmueB[iCut])) * (1./2. * sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut]) * sqrt(DATA_errNemuB[iCut]*DATA_errNemuB[iCut] + DATA_errNmueB[iCut]*DATA_errNmueB[iCut])) ;
  
  DATA_errstandardR_mumu[iCut] = sqrt(c1+c2+c3+c4+c5+c6);
  
  
  
  ///==== simple R method ====
  denom = (DY_NeeB[iCut] - 1./2. * sqrt(DY_NeeB[iCut] / DY_NmumuB[iCut]) * (DY_NemuB[iCut]+DY_NmueB[iCut]));
  DY_standardR_ee[iCut] = (DY_NeeA[iCut] - 1./2. * sqrt(DY_NeeA[iCut] / DY_NmumuA[iCut]) * (DY_NemuA[iCut] + DY_NmueA[iCut])) / (DY_NeeB[iCut] - 1./2. * sqrt(DY_NeeB[iCut] / DY_NmumuB[iCut]) * (DY_NemuB[iCut]+DY_NmueB[iCut]));
  
  c1 = 1./denom/denom * ((1 - 1./4. * (DY_NemuA[iCut] + DY_NmueA[iCut]) / sqrt(DY_NeeA[iCut]*DY_NmumuA[iCut])) * DY_errNeeA[iCut]) * ((1 - 1./4. * (DY_NemuA[iCut] + DY_NmueA[iCut]) / sqrt(DY_NeeA[iCut]*DY_NmumuA[iCut])) * DY_errNeeA[iCut]) ;
  c2 = 1./denom/denom * ((1./4. * (DY_NemuA[iCut] + DY_NmueA[iCut]) / DY_NmumuA[iCut] * sqrt(DY_NeeA[iCut] / DY_NmumuA[iCut])) * DY_errNmumuA[iCut]) * ((1./4. * (DY_NemuA[iCut] + DY_NmueA[iCut]) / DY_NmumuA[iCut] * sqrt(DY_NeeA[iCut] / DY_NmumuA[iCut])) * DY_errNmumuA[iCut]) ;
  c3 = 1./denom/denom * (1./2. * sqrt(DY_NeeA[iCut] / DY_NmumuA[iCut]) * sqrt(DY_errNemuA[iCut]*DY_errNemuA[iCut] + DY_errNmueA[iCut]*DY_errNmueA[iCut])) * (1./2. * sqrt(DY_NeeA[iCut] / DY_NmumuA[iCut]) * sqrt(DY_errNemuA[iCut]*DY_errNemuA[iCut] + DY_errNmueA[iCut]*DY_errNmueA[iCut])) ;
  
  c4 = 1./denom/denom/denom/denom * ((1 - 1./4. * (DY_NemuB[iCut]+DY_NmueB[iCut]) / sqrt(DY_NeeB[iCut]*DY_NmumuB[iCut])) * DY_errNeeB[iCut]) * ((1 - 1./4. * (DY_NemuB[iCut]+DY_NmueB[iCut]) / sqrt(DY_NeeB[iCut]*DY_NmumuB[iCut])) * DY_errNeeB[iCut]) ;
  c5 = 1./denom/denom/denom/denom * ((1./4. * (DY_NemuB[iCut]+DY_NmueB[iCut]) / DY_NmumuB[iCut] * sqrt(DY_NeeB[iCut] / DY_NmumuB[iCut])) * DY_errNmumuB[iCut]) * ((1./4. * (DY_NemuB[iCut]+DY_NmueB[iCut]) / DY_NmumuB[iCut] * sqrt(DY_NeeB[iCut] / DY_NmumuB[iCut])) * DY_errNmumuB[iCut]) ;
  c6 = 1./denom/denom/denom/denom * (1./2. * sqrt(DY_NeeB[iCut] / DY_NmumuB[iCut]) * sqrt(DY_errNemuB[iCut]*DY_errNemuB[iCut] + DY_errNmueB[iCut]*DY_errNmueB[iCut])) * (1./2. * sqrt(DY_NeeB[iCut] / DY_NmumuB[iCut]) * sqrt(DY_errNemuB[iCut]*DY_errNemuB[iCut] + DY_errNmueB[iCut]*DY_errNmueB[iCut])) ;
  
  DY_errstandardR_ee[iCut] = sqrt(c1+c2+c3+c4+c5+c6);
  
  ///==== Rmumu from data = (NmumuA - kmumuA * NemuA) / (NmumuB - kmumuB * NemuB)
  denom = (DY_NmumuB[iCut] - 1./2. * sqrt(DY_NmumuB[iCut] / DY_NeeB[iCut]) * (DY_NemuB[iCut]+DY_NmueB[iCut]));
  DY_standardR_mumu[iCut] = (DY_NmumuA[iCut] - 1./2. * sqrt(DY_NmumuA[iCut] / DY_NeeA[iCut]) * (DY_NemuA[iCut] + DY_NmueA[iCut])) / (DY_NmumuB[iCut] - 1./2. * sqrt(DY_NmumuB[iCut] / DY_NeeB[iCut]) * (DY_NemuB[iCut]+DY_NmueB[iCut]));
  
  c1 = 1./denom/denom * ((1 - 1./4. * (DY_NemuA[iCut] + DY_NmueA[iCut]) / sqrt(DY_NmumuA[iCut]*DY_NeeA[iCut])) * DY_errNmumuA[iCut]) * ((1 - 1./4. * (DY_NemuA[iCut] + DY_NmueA[iCut]) / sqrt(DY_NmumuA[iCut]*DY_NeeA[iCut])) * DY_errNmumuA[iCut]) ;
  c2 = 1./denom/denom * ((1./4. * (DY_NemuA[iCut] + DY_NmueA[iCut]) / DY_NeeA[iCut] * sqrt(DY_NmumuA[iCut] / DY_NeeA[iCut])) * DY_errNeeA[iCut]) * ((1./4. * (DY_NemuA[iCut] + DY_NmueA[iCut]) / DY_NeeA[iCut] * sqrt(DY_NmumuA[iCut] / DY_NeeA[iCut])) * DY_errNeeA[iCut]) ;
  c3 = 1./denom/denom * (1./2. * sqrt(DY_NmumuA[iCut] / DY_NeeA[iCut]) * sqrt(DY_errNemuA[iCut]*DY_errNemuA[iCut] + DY_errNmueA[iCut]*DY_errNmueA[iCut])) * (1./2. * sqrt(DY_NmumuA[iCut] / DY_NeeA[iCut]) * sqrt(DY_errNemuA[iCut]*DY_errNemuA[iCut] + DY_errNmueA[iCut]*DY_errNmueA[iCut])) ;
  
  c4 = 1./denom/denom/denom/denom * ((1 - 1./4. * (DY_NemuB[iCut]+DY_NmueB[iCut]) / sqrt(DY_NmumuB[iCut]*DY_NeeB[iCut])) * DY_errNmumuB[iCut]) * ((1 - 1./4. * (DY_NemuB[iCut]+DY_NmueB[iCut]) / sqrt(DY_NmumuB[iCut]*DY_NeeB[iCut])) * DY_errNmumuB[iCut]) ;
  c5 = 1./denom/denom/denom/denom * ((1./4. * (DY_NemuB[iCut]+DY_NmueB[iCut]) / DY_NeeB[iCut] * sqrt(DY_NmumuB[iCut] / DY_NeeB[iCut])) * DY_errNeeB[iCut]) * ((1./4. * (DY_NemuB[iCut]+DY_NmueB[iCut]) / DY_NeeB[iCut] * sqrt(DY_NmumuB[iCut] / DY_NeeB[iCut])) * DY_errNeeB[iCut]) ;
  c6 = 1./denom/denom/denom/denom * (1./2. * sqrt(DY_NmumuB[iCut] / DY_NeeB[iCut]) * sqrt(DY_errNemuB[iCut]*DY_errNemuB[iCut] + DY_errNmueB[iCut]*DY_errNmueB[iCut])) * (1./2. * sqrt(DY_NmumuB[iCut] / DY_NeeB[iCut]) * sqrt(DY_errNemuB[iCut]*DY_errNemuB[iCut] + DY_errNmueB[iCut]*DY_errNmueB[iCut])) ;
  
  DY_errstandardR_mumu[iCut] = sqrt(c1+c2+c3+c4+c5+c6);
  
  
  

  
  
  
  ///==== simple R method ====
  denom = (all_NeeB[iCut] - 1./2. * sqrt(all_NeeB[iCut] / all_NmumuB[iCut]) * (all_NemuB[iCut]+all_NmueB[iCut]));
  all_standardR_ee[iCut] = (all_NeeA[iCut] - 1./2. * sqrt(all_NeeA[iCut] / all_NmumuA[iCut]) * (all_NemuA[iCut] + all_NmueA[iCut])) / (all_NeeB[iCut] - 1./2. * sqrt(all_NeeB[iCut] / all_NmumuB[iCut]) * (all_NemuB[iCut]+all_NmueB[iCut]));
  
  c1 = 1./denom/denom * ((1 - 1./4. * (all_NemuA[iCut] + all_NmueA[iCut]) / sqrt(all_NeeA[iCut]*all_NmumuA[iCut])) * all_errNeeA[iCut]) * ((1 - 1./4. * (all_NemuA[iCut] + all_NmueA[iCut]) / sqrt(all_NeeA[iCut]*all_NmumuA[iCut])) * all_errNeeA[iCut]) ;
  c2 = 1./denom/denom * ((1./4. * (all_NemuA[iCut] + all_NmueA[iCut]) / all_NmumuA[iCut] * sqrt(all_NeeA[iCut] / all_NmumuA[iCut])) * all_errNmumuA[iCut]) * ((1./4. * (all_NemuA[iCut] + all_NmueA[iCut]) / all_NmumuA[iCut] * sqrt(all_NeeA[iCut] / all_NmumuA[iCut])) * all_errNmumuA[iCut]) ;
  c3 = 1./denom/denom * (1./2. * sqrt(all_NeeA[iCut] / all_NmumuA[iCut]) * sqrt(all_errNemuA[iCut]*all_errNemuA[iCut] + all_errNmueA[iCut]*all_errNmueA[iCut])) * (1./2. * sqrt(all_NeeA[iCut] / all_NmumuA[iCut]) * sqrt(all_errNemuA[iCut]*all_errNemuA[iCut] + all_errNmueA[iCut]*all_errNmueA[iCut])) ;
  
  c4 = 1./denom/denom/denom/denom * ((1 - 1./4. * (all_NemuB[iCut]+all_NmueB[iCut]) / sqrt(all_NeeB[iCut]*all_NmumuB[iCut])) * all_errNeeB[iCut]) * ((1 - 1./4. * (all_NemuB[iCut]+all_NmueB[iCut]) / sqrt(all_NeeB[iCut]*all_NmumuB[iCut])) * all_errNeeB[iCut]) ;
  c5 = 1./denom/denom/denom/denom * ((1./4. * (all_NemuB[iCut]+all_NmueB[iCut]) / all_NmumuB[iCut] * sqrt(all_NeeB[iCut] / all_NmumuB[iCut])) * all_errNmumuB[iCut]) * ((1./4. * (all_NemuB[iCut]+all_NmueB[iCut]) / all_NmumuB[iCut] * sqrt(all_NeeB[iCut] / all_NmumuB[iCut])) * all_errNmumuB[iCut]) ;
  c6 = 1./denom/denom/denom/denom * (1./2. * sqrt(all_NeeB[iCut] / all_NmumuB[iCut]) * sqrt(all_errNemuB[iCut]*all_errNemuB[iCut] + all_errNmueB[iCut]*all_errNmueB[iCut])) * (1./2. * sqrt(all_NeeB[iCut] / all_NmumuB[iCut]) * sqrt(all_errNemuB[iCut]*all_errNemuB[iCut] + all_errNmueB[iCut]*all_errNmueB[iCut])) ;
  
  all_errstandardR_ee[iCut] = sqrt(c1+c2+c3+c4+c5+c6);
  
  ///==== Rmumu from data = (NmumuA - kmumuA * NemuA) / (NmumuB - kmumuB * NemuB)
  denom = (all_NmumuB[iCut] - 1./2. * sqrt(all_NmumuB[iCut] / all_NeeB[iCut]) * (all_NemuB[iCut]+all_NmueB[iCut]));
  all_standardR_mumu[iCut] = (all_NmumuA[iCut] - 1./2. * sqrt(all_NmumuA[iCut] / all_NeeA[iCut]) * (all_NemuA[iCut] + all_NmueA[iCut])) / (all_NmumuB[iCut] - 1./2. * sqrt(all_NmumuB[iCut] / all_NeeB[iCut]) * (all_NemuB[iCut]+all_NmueB[iCut]));
  
  c1 = 1./denom/denom * ((1 - 1./4. * (all_NemuA[iCut] + all_NmueA[iCut]) / sqrt(all_NmumuA[iCut]*all_NeeA[iCut])) * all_errNmumuA[iCut]) * ((1 - 1./4. * (all_NemuA[iCut] + all_NmueA[iCut]) / sqrt(all_NmumuA[iCut]*all_NeeA[iCut])) * all_errNmumuA[iCut]) ;
  c2 = 1./denom/denom * ((1./4. * (all_NemuA[iCut] + all_NmueA[iCut]) / all_NeeA[iCut] * sqrt(all_NmumuA[iCut] / all_NeeA[iCut])) * all_errNeeA[iCut]) * ((1./4. * (all_NemuA[iCut] + all_NmueA[iCut]) / all_NeeA[iCut] * sqrt(all_NmumuA[iCut] / all_NeeA[iCut])) * all_errNeeA[iCut]) ;
  c3 = 1./denom/denom * (1./2. * sqrt(all_NmumuA[iCut] / all_NeeA[iCut]) * sqrt(all_errNemuA[iCut]*all_errNemuA[iCut] + all_errNmueA[iCut]*all_errNmueA[iCut])) * (1./2. * sqrt(all_NmumuA[iCut] / all_NeeA[iCut]) * sqrt(all_errNemuA[iCut]*all_errNemuA[iCut] + all_errNmueA[iCut]*all_errNmueA[iCut])) ;
  
  c4 = 1./denom/denom/denom/denom * ((1 - 1./4. * (all_NemuB[iCut]+all_NmueB[iCut]) / sqrt(all_NmumuB[iCut]*all_NeeB[iCut])) * all_errNmumuB[iCut]) * ((1 - 1./4. * (all_NemuB[iCut]+all_NmueB[iCut]) / sqrt(all_NmumuB[iCut]*all_NeeB[iCut])) * all_errNmumuB[iCut]) ;
  c5 = 1./denom/denom/denom/denom * ((1./4. * (all_NemuB[iCut]+all_NmueB[iCut]) / all_NeeB[iCut] * sqrt(all_NmumuB[iCut] / all_NeeB[iCut])) * all_errNeeB[iCut]) * ((1./4. * (all_NemuB[iCut]+all_NmueB[iCut]) / all_NeeB[iCut] * sqrt(all_NmumuB[iCut] / all_NeeB[iCut])) * all_errNeeB[iCut]) ;
  c6 = 1./denom/denom/denom/denom * (1./2. * sqrt(all_NmumuB[iCut] / all_NeeB[iCut]) * sqrt(all_errNemuB[iCut]*all_errNemuB[iCut] + all_errNmueB[iCut]*all_errNmueB[iCut])) * (1./2. * sqrt(all_NmumuB[iCut] / all_NeeB[iCut]) * sqrt(all_errNemuB[iCut]*all_errNemuB[iCut] + all_errNmueB[iCut]*all_errNmueB[iCut])) ;
  
  all_errstandardR_mumu[iCut] = sqrt(c1+c2+c3+c4+c5+c6);
  
  
  
  
  
  
  
  
 }
 
 
 
 for (int iCut = 0; iCut <num; iCut++) {

  ///==== Results: NDY_R_A_ee_extrapolated = (NeeB - keeB' * NemuB) * Rinout|calculated at met>0
  
  NB = DATA_NeeB[iCut] - sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut] * DATA_NemuB[iCut] * DATA_NmueB[iCut]);
  
  c1 = DATA_errNeeB[iCut]    *  (1. - 1./2. * sqrt(DATA_NemuB[iCut]*DATA_NmueB[iCut]/DATA_NeeB[iCut]/DATA_NmumuB[iCut]))  ;
  c2 = DATA_errNmumuB[iCut]  *  (1./2. * sqrt(DATA_NemuB[iCut]*DATA_NmueB[iCut]*DATA_NeeB[iCut]/DATA_NmumuB[iCut])/DATA_NmumuB[iCut]);
  c3 = DATA_NemuB[iCut] ? (DATA_errNemuB[iCut]   *  (1./2. * sqrt(DATA_NeeB[iCut]/DATA_NmumuB[iCut]*DATA_NmueB[iCut]/DATA_NemuB[iCut]))) : 0.;
  c4 = DATA_NmueB[iCut] ? (DATA_errNmueB[iCut]   *  (1./2. * sqrt(DATA_NeeB[iCut]/DATA_NmumuB[iCut]*DATA_NemuB[iCut]/DATA_NmueB[iCut]))) : 0.;
  errNB = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4); 
  
  DATA_NDY_R_A_ee[iCut]     = NB * DATA_R_ee[numPointForRCalculation]; 
  DATA_errNDY_R_A_ee[iCut]  = sqrt ((NB * DATA_errR_ee[numPointForRCalculation] * NB * DATA_errR_ee[numPointForRCalculation]) + DATA_R_ee[numPointForRCalculation] * DATA_R_ee[numPointForRCalculation] * (c4 + c5 + c6));
  
  DATA_NDYCorrected_R_A_ee[iCut]  = all_NeeA[iCut] - DY_NeeA[iCut] + DATA_NDY_R_A_ee[iCut];
  DATA_errNDYCorrected_R_A_ee[iCut] = sqrt(all_errNeeA[iCut]*all_errNeeA[iCut] + DY_errNeeA[iCut]*DY_errNeeA[iCut] + DATA_errNDY_R_A_ee[iCut]*DATA_errNDY_R_A_ee[iCut]);
  
  ///==== Results: NDY_R_A_mumu_extrapolated = (NmumuB - kmumuB' * NemuB) * Rinout|calculated at met>0
  
  NB = DATA_NmumuB[iCut] - sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut] * DATA_NmueB[iCut] * DATA_NemuB[iCut]);
  
  c1 = DATA_errNmumuB[iCut]    *  (1. - 1./2. * sqrt(DATA_NmueB[iCut]*DATA_NemuB[iCut]/DATA_NmumuB[iCut]/DATA_NeeB[iCut]))  ;
  c2 = DATA_errNeeB[iCut]  *  (1./2. * sqrt(DATA_NmueB[iCut]*DATA_NemuB[iCut]*DATA_NmumuB[iCut]/DATA_NeeB[iCut])/DATA_NeeB[iCut]);
  c3 = DATA_NmueB[iCut] ? (DATA_errNmueB[iCut]   *  (1./2. * sqrt(DATA_NmumuB[iCut]/DATA_NeeB[iCut]*DATA_NemuB[iCut]/DATA_NmueB[iCut]))) : 0.;
  c4 = DATA_NemuB[iCut] ? (DATA_errNemuB[iCut]   *  (1./2. * sqrt(DATA_NmumuB[iCut]/DATA_NeeB[iCut]*DATA_NmueB[iCut]/DATA_NemuB[iCut]))) : 0.;
  errNB = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4); 
  
  DATA_NDY_R_A_mumu[iCut]     = NB * DATA_R_mumu[numPointForRCalculation]; 
  DATA_errNDY_R_A_mumu[iCut]  = sqrt ((NB * DATA_errR_mumu[numPointForRCalculation] * NB * DATA_errR_mumu[numPointForRCalculation]) + DATA_R_mumu[numPointForRCalculation] * DATA_R_mumu[numPointForRCalculation] * (c4 + c5 + c6));
  
  DATA_NDYCorrected_R_A_mumu[iCut]  = all_NmumuA[iCut] - DY_NmumuA[iCut] + DATA_NDY_R_A_mumu[iCut];
  DATA_errNDYCorrected_R_A_mumu[iCut] = sqrt(all_errNmumuA[iCut]*all_errNmumuA[iCut] + DY_errNmumuA[iCut]*DY_errNmumuA[iCut] + DATA_errNDY_R_A_mumu[iCut]*DATA_errNDY_R_A_mumu[iCut]);
  
 }
  
  
  
  for (int iCut = 0; iCut <num; iCut++) {
   
   ///==== Results: NDY_standardR_A_ee_extrapolated = (NeeB - keeB * NemuB) * Rinout|calculated at met>0
   
   NB = DATA_NeeB[iCut] - 0.5 * sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut]) * (DATA_NemuB[iCut] + DATA_NmueB[iCut]);
   
   c1 = DATA_errNeeB[iCut]    *  (1. - 1./4. * sqrt(1./DATA_NeeB[iCut]/DATA_NmumuB[iCut]) * (DATA_NemuB[iCut] + DATA_NmueB[iCut]))  ;
   c2 = DATA_errNmumuB[iCut]  *  (1./4. * sqrt(DATA_NeeB[iCut]/DATA_NmumuB[iCut])/DATA_NmumuB[iCut] * (DATA_NemuB[iCut] + DATA_NmueB[iCut]));
   c3 = DATA_NemuB[iCut] ? (DATA_errNemuB[iCut]   *  (1./2. * sqrt(DATA_NeeB[iCut]/DATA_NmumuB[iCut]))) : 0.;
   c4 = DATA_NmueB[iCut] ? (DATA_errNmueB[iCut]   *  (1./2. * sqrt(DATA_NeeB[iCut]/DATA_NmumuB[iCut]))) : 0.;
   errNB = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4); 
   
   DATA_NDY_standardR_A_ee[iCut]     = NB * DATA_standardR_ee[numPointForRCalculation]; 
   DATA_errNDY_standardR_A_ee[iCut]  = sqrt ((NB * DATA_errstandardR_ee[numPointForRCalculation] * NB * DATA_errstandardR_ee[numPointForRCalculation]) + DATA_standardR_ee[numPointForRCalculation] * DATA_standardR_ee[numPointForRCalculation] * (c4 + c5 + c6));
   
   DATA_NDYCorrected_standardR_A_ee[iCut]  = all_NeeA[iCut] - DY_NeeA[iCut] + DATA_NDY_standardR_A_ee[iCut];
   DATA_errNDYCorrected_standardR_A_ee[iCut] = sqrt(all_errNeeA[iCut]*all_errNeeA[iCut] + DY_errNeeA[iCut]*DY_errNeeA[iCut] + DATA_errNDY_standardR_A_ee[iCut]*DATA_errNDY_standardR_A_ee[iCut]);
   
   ///==== Results: NDY_standardR_A_mumu_extrapolated = (NmumuB - kmumuB * NemuB) * Rinout|calculated at met>0
   
   NB = DATA_NmumuB[iCut] - sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut]) * (DATA_NmueB[iCut] + DATA_NemuB[iCut]);
   
   c1 = DATA_errNmumuB[iCut]    *  (1. - 1./4. * sqrt(1./DATA_NmumuB[iCut]/DATA_NeeB[iCut])* (DATA_NmueB[iCut] + DATA_NemuB[iCut]))  ;
   c2 = DATA_errNeeB[iCut]  *  (1./4. * sqrt(DATA_NmumuB[iCut]/DATA_NeeB[iCut])/DATA_NeeB[iCut]* (DATA_NmueB[iCut] + DATA_NemuB[iCut]));
   c3 = DATA_NmueB[iCut] ? (DATA_errNmueB[iCut]   *  (1./2. * sqrt(DATA_NmumuB[iCut]/DATA_NeeB[iCut]))) : 0.;
   c4 = DATA_NemuB[iCut] ? (DATA_errNemuB[iCut]   *  (1./2. * sqrt(DATA_NmumuB[iCut]/DATA_NeeB[iCut]))) : 0.;
   errNB = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4); 
   
   DATA_NDY_standardR_A_mumu[iCut]     = NB * DATA_standardR_mumu[numPointForRCalculation]; 
   DATA_errNDY_standardR_A_mumu[iCut]  = sqrt ((NB * DATA_errstandardR_mumu[numPointForRCalculation] * NB * DATA_errstandardR_mumu[numPointForRCalculation]) + DATA_standardR_mumu[numPointForRCalculation] * DATA_standardR_mumu[numPointForRCalculation] * (c4 + c5 + c6));
   
   DATA_NDYCorrected_standardR_A_mumu[iCut]  = all_NmumuA[iCut] - DY_NmumuA[iCut] + DATA_NDY_standardR_A_mumu[iCut];
   DATA_errNDYCorrected_standardR_A_mumu[iCut] = sqrt(all_errNmumuA[iCut]*all_errNmumuA[iCut] + DY_errNmumuA[iCut]*DY_errNmumuA[iCut] + DATA_errNDY_standardR_A_mumu[iCut]*DATA_errNDY_standardR_A_mumu[iCut]);
   
  }
 
 
 
 

 ///==== plot ====
 
 ///================
 ///==== A zone ====
 ///================

 ///==== occupancy plots ====
 ///==== mumu ====
 TCanvas* cNmumuA = new TCanvas("cNmumuA","cNmumuA",800,800); 
 
 TGraphErrors* grDATA_NmumuA = new TGraphErrors(numPlot,X,DATA_NmumuA,errX,DATA_errNmumuA);
 grDATA_NmumuA->SetTitle("N #mu#mu DATA A");
 grDATA_NmumuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NmumuA->GetYaxis()->SetTitle("N #mu#mu");
 grDATA_NmumuA->SetMarkerColor(kBlack);
 grDATA_NmumuA->SetFillColor(kWhite);
 grDATA_NmumuA->SetLineColor(kBlack);
 grDATA_NmumuA->SetMarkerStyle(20);
 grDATA_NmumuA->SetMarkerSize(1.5);
 grDATA_NmumuA->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NmumuA = new TGraphErrors(numPlot,X,DYmad_NmumuA,errX,DYmad_errNmumuA);
 grDYmad_NmumuA->SetTitle("N #mu#mu DYmad A");
 grDYmad_NmumuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDYmad_NmumuA->GetYaxis()->SetTitle("N #mu#mu");
 grDYmad_NmumuA->SetMarkerColor(kGreen);
 grDYmad_NmumuA->SetFillColor(kWhite);
 grDYmad_NmumuA->SetLineColor(kGreen);
 grDYmad_NmumuA->SetMarkerStyle(28);
 grDYmad_NmumuA->SetMarkerSize(1);
 grDYmad_NmumuA->SetLineWidth(2);
 
 TGraphErrors* grDY_NmumuA = new TGraphErrors(numPlot,X,DY_NmumuA,errX,DY_errNmumuA);
 grDY_NmumuA->SetTitle("N #mu#mu DY A");
 grDY_NmumuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_NmumuA->GetYaxis()->SetTitle("N #mu#mu");
 grDY_NmumuA->SetMarkerColor(kBlue);
 grDY_NmumuA->SetFillColor(kWhite);
 grDY_NmumuA->SetLineColor(kBlue);
 grDY_NmumuA->SetMarkerStyle(21);
 grDY_NmumuA->SetMarkerSize(1);
 grDY_NmumuA->SetLineWidth(2);
 
 TGraphErrors* grother_NmumuA = new TGraphErrors(numPlot,X,other_NmumuA,errX,other_errNmumuA);
 grother_NmumuA->SetTitle("N #mu#mu other A");
 grother_NmumuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grother_NmumuA->GetYaxis()->SetTitle("N #mu#mu");
 grother_NmumuA->SetMarkerColor(kGreen);
 grother_NmumuA->SetFillColor(kWhite);
 grother_NmumuA->SetLineColor(kGreen);
 grother_NmumuA->SetMarkerStyle(21);
 grother_NmumuA->SetMarkerSize(1);
 grother_NmumuA->SetLineWidth(2);
 
 TGraphErrors* grall_NmumuA = new TGraphErrors(numPlot,X,all_NmumuA,errX,all_errNmumuA);
 grall_NmumuA->SetTitle("N #mu#mu all A");
 grall_NmumuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_NmumuA->GetYaxis()->SetTitle("N #mu#mu");
 grall_NmumuA->SetMarkerColor(kRed);
 grall_NmumuA->SetFillColor(kWhite);
 grall_NmumuA->SetLineColor(kRed);
 grall_NmumuA->SetMarkerStyle(25);
 grall_NmumuA->SetMarkerSize(1);
 grall_NmumuA->SetLineWidth(2);
 
 TMultiGraph* mgr_NmumuA = new TMultiGraph(); 
 mgr_NmumuA->Add(grDATA_NmumuA);
 mgr_NmumuA->Add(grDY_NmumuA);
 mgr_NmumuA->Add(grDYmad_NmumuA);
 mgr_NmumuA->Add(grother_NmumuA);
 mgr_NmumuA->Add(grall_NmumuA);
 mgr_NmumuA->Draw("AP");
 mgr_NmumuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NmumuA->GetYaxis()->SetTitle("N #mu#mu A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== ee ====
 TCanvas* cNeeA = new TCanvas("cNeeA","cNeeA",800,800); 
 
 TGraphErrors* grDATA_NeeA = new TGraphErrors(numPlot,X,DATA_NeeA,errX,DATA_errNeeA);
 grDATA_NeeA->SetTitle("N ee DATA A");
 grDATA_NeeA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NeeA->GetYaxis()->SetTitle("N ee");
 grDATA_NeeA->SetMarkerColor(kBlack);
 grDATA_NeeA->SetFillColor(kWhite);
 grDATA_NeeA->SetLineColor(kBlack);
 grDATA_NeeA->SetMarkerStyle(20);
 grDATA_NeeA->SetMarkerSize(1.5);
 grDATA_NeeA->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NeeA = new TGraphErrors(numPlot,X,DYmad_NeeA,errX,DYmad_errNeeA);
 grDYmad_NeeA->SetTitle("N ee DYmad A");
 grDYmad_NeeA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDYmad_NeeA->GetYaxis()->SetTitle("N ee");
 grDYmad_NeeA->SetMarkerColor(kGreen);
 grDYmad_NeeA->SetFillColor(kWhite);
 grDYmad_NeeA->SetLineColor(kGreen);
 grDYmad_NeeA->SetMarkerStyle(28);
 grDYmad_NeeA->SetMarkerSize(1);
 grDYmad_NeeA->SetLineWidth(2);
 
 TGraphErrors* grDY_NeeA = new TGraphErrors(numPlot,X,DY_NeeA,errX,DY_errNeeA);
 grDY_NeeA->SetTitle("N ee DY A");
 grDY_NeeA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_NeeA->GetYaxis()->SetTitle("N ee");
 grDY_NeeA->SetMarkerColor(kBlue);
 grDY_NeeA->SetFillColor(kWhite);
 grDY_NeeA->SetLineColor(kBlue);
 grDY_NeeA->SetMarkerStyle(21);
 grDY_NeeA->SetMarkerSize(1);
 grDY_NeeA->SetLineWidth(2);
 
 TGraphErrors* grother_NeeA = new TGraphErrors(numPlot,X,other_NeeA,errX,other_errNeeA);
 grother_NeeA->SetTitle("N ee other A");
 grother_NeeA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grother_NeeA->GetYaxis()->SetTitle("N ee");
 grother_NeeA->SetMarkerColor(kGreen);
 grother_NeeA->SetFillColor(kWhite);
 grother_NeeA->SetLineColor(kGreen);
 grother_NeeA->SetMarkerStyle(21);
 grother_NeeA->SetMarkerSize(1);
 grother_NeeA->SetLineWidth(2);
 
 TGraphErrors* grall_NeeA = new TGraphErrors(numPlot,X,all_NeeA,errX,all_errNeeA);
 grall_NeeA->SetTitle("N ee all A");
 grall_NeeA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_NeeA->GetYaxis()->SetTitle("N ee");
 grall_NeeA->SetMarkerColor(kRed);
 grall_NeeA->SetFillColor(kWhite);
 grall_NeeA->SetLineColor(kRed);
 grall_NeeA->SetMarkerStyle(25);
 grall_NeeA->SetMarkerSize(1);
 grall_NeeA->SetLineWidth(2);
 
 TMultiGraph* mgr_NeeA = new TMultiGraph(); 
 mgr_NeeA->Add(grDATA_NeeA);
 mgr_NeeA->Add(grDY_NeeA);
 mgr_NeeA->Add(grDYmad_NeeA);
 mgr_NeeA->Add(grother_NeeA);
 mgr_NeeA->Add(grall_NeeA);
 mgr_NeeA->Draw("AP");
 mgr_NeeA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NeeA->GetYaxis()->SetTitle("N ee A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== emu ====
 TCanvas* cNemuA = new TCanvas("cNemuA","cNemuA",800,800); 
 
 TGraphErrors* grDATA_NemuA = new TGraphErrors(numPlot,X,DATA_NemuA,errX,DATA_errNemuA);
 grDATA_NemuA->SetTitle("N e#mu DATA A");
 grDATA_NemuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NemuA->GetYaxis()->SetTitle("N e#mu");
 grDATA_NemuA->SetMarkerColor(kBlack);
 grDATA_NemuA->SetFillColor(kWhite);
 grDATA_NemuA->SetLineColor(kBlack);
 grDATA_NemuA->SetMarkerStyle(20);
 grDATA_NemuA->SetMarkerSize(1.5);
 grDATA_NemuA->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NemuA = new TGraphErrors(numPlot,X,DYmad_NemuA,errX,DYmad_errNemuA);
 grDYmad_NemuA->SetTitle("N e#mu DYmad A");
 grDYmad_NemuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDYmad_NemuA->GetYaxis()->SetTitle("N e#mu");
 grDYmad_NemuA->SetMarkerColor(kGreen);
 grDYmad_NemuA->SetFillColor(kWhite);
 grDYmad_NemuA->SetLineColor(kGreen);
 grDYmad_NemuA->SetMarkerStyle(28);
 grDYmad_NemuA->SetMarkerSize(1);
 grDYmad_NemuA->SetLineWidth(2);
 
 TGraphErrors* grDY_NemuA = new TGraphErrors(numPlot,X,DY_NemuA,errX,DY_errNemuA);
 grDY_NemuA->SetTitle("N e#mu DY A");
 grDY_NemuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_NemuA->GetYaxis()->SetTitle("N e#mu");
 grDY_NemuA->SetMarkerColor(kBlue);
 grDY_NemuA->SetFillColor(kWhite);
 grDY_NemuA->SetLineColor(kBlue);
 grDY_NemuA->SetMarkerStyle(21);
 grDY_NemuA->SetMarkerSize(1);
 grDY_NemuA->SetLineWidth(2);
 
 TGraphErrors* grother_NemuA = new TGraphErrors(numPlot,X,other_NemuA,errX,other_errNemuA);
 grother_NemuA->SetTitle("N e#mu other A");
 grother_NemuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grother_NemuA->GetYaxis()->SetTitle("N e#mu");
 grother_NemuA->SetMarkerColor(kGreen);
 grother_NemuA->SetFillColor(kWhite);
 grother_NemuA->SetLineColor(kGreen);
 grother_NemuA->SetMarkerStyle(21);
 grother_NemuA->SetMarkerSize(1);
 grother_NemuA->SetLineWidth(2);
 
 TGraphErrors* grall_NemuA = new TGraphErrors(numPlot,X,all_NemuA,errX,all_errNemuA);
 grall_NemuA->SetTitle("N e#mu all A");
 grall_NemuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_NemuA->GetYaxis()->SetTitle("N e#mu");
 grall_NemuA->SetMarkerColor(kRed);
 grall_NemuA->SetFillColor(kWhite);
 grall_NemuA->SetLineColor(kRed);
 grall_NemuA->SetMarkerStyle(25);
 grall_NemuA->SetMarkerSize(1);
 grall_NemuA->SetLineWidth(2);
 
 TMultiGraph* mgr_NemuA = new TMultiGraph(); 
 mgr_NemuA->Add(grDATA_NemuA);
 mgr_NemuA->Add(grDY_NemuA);
 mgr_NemuA->Add(grDYmad_NemuA);
 mgr_NemuA->Add(grother_NemuA);
 mgr_NemuA->Add(grall_NemuA);
 mgr_NemuA->Draw("AP");
 mgr_NemuA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NemuA->GetYaxis()->SetTitle("N e#mu A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== mue ====
 TCanvas* cNmueA = new TCanvas("cNmueA","cNmueA",800,800); 
 
 TGraphErrors* grDATA_NmueA = new TGraphErrors(numPlot,X,DATA_NmueA,errX,DATA_errNmueA);
 grDATA_NmueA->SetTitle("N #mue DATA A");
 grDATA_NmueA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NmueA->GetYaxis()->SetTitle("N #mue");
 grDATA_NmueA->SetMarkerColor(kBlack);
 grDATA_NmueA->SetFillColor(kWhite);
 grDATA_NmueA->SetLineColor(kBlack);
 grDATA_NmueA->SetMarkerStyle(20);
 grDATA_NmueA->SetMarkerSize(1.5);
 grDATA_NmueA->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NmueA = new TGraphErrors(numPlot,X,DYmad_NmueA,errX,DYmad_errNmueA);
 grDYmad_NmueA->SetTitle("N #mue DYmad A");
 grDYmad_NmueA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDYmad_NmueA->GetYaxis()->SetTitle("N #mue");
 grDYmad_NmueA->SetMarkerColor(kGreen);
 grDYmad_NmueA->SetFillColor(kWhite);
 grDYmad_NmueA->SetLineColor(kGreen);
 grDYmad_NmueA->SetMarkerStyle(28);
 grDYmad_NmueA->SetMarkerSize(1);
 grDYmad_NmueA->SetLineWidth(2);
 
 TGraphErrors* grDY_NmueA = new TGraphErrors(numPlot,X,DY_NmueA,errX,DY_errNmueA);
 grDY_NmueA->SetTitle("N #mue DY A");
 grDY_NmueA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_NmueA->GetYaxis()->SetTitle("N #mue");
 grDY_NmueA->SetMarkerColor(kBlue);
 grDY_NmueA->SetFillColor(kWhite);
 grDY_NmueA->SetLineColor(kBlue);
 grDY_NmueA->SetMarkerStyle(21);
 grDY_NmueA->SetMarkerSize(1);
 grDY_NmueA->SetLineWidth(2);
 
 TGraphErrors* grother_NmueA = new TGraphErrors(numPlot,X,other_NmueA,errX,other_errNmueA);
 grother_NmueA->SetTitle("N #mue other A");
 grother_NmueA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grother_NmueA->GetYaxis()->SetTitle("N #mue");
 grother_NmueA->SetMarkerColor(kGreen);
 grother_NmueA->SetFillColor(kWhite);
 grother_NmueA->SetLineColor(kGreen);
 grother_NmueA->SetMarkerStyle(21);
 grother_NmueA->SetMarkerSize(1);
 grother_NmueA->SetLineWidth(2);
 
 TGraphErrors* grall_NmueA = new TGraphErrors(numPlot,X,all_NmueA,errX,all_errNmueA);
 grall_NmueA->SetTitle("N #mue all A");
 grall_NmueA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_NmueA->GetYaxis()->SetTitle("N #mue");
 grall_NmueA->SetMarkerColor(kRed);
 grall_NmueA->SetFillColor(kWhite);
 grall_NmueA->SetLineColor(kRed);
 grall_NmueA->SetMarkerStyle(25);
 grall_NmueA->SetMarkerSize(1);
 grall_NmueA->SetLineWidth(2);
 
 TMultiGraph* mgr_NmueA = new TMultiGraph(); 
 mgr_NmueA->Add(grDATA_NmueA);
 mgr_NmueA->Add(grDY_NmueA);
 mgr_NmueA->Add(grDYmad_NmueA);
 mgr_NmueA->Add(grother_NmueA);
 mgr_NmueA->Add(grall_NmueA);
 mgr_NmueA->Draw("AP");
 mgr_NmueA->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NmueA->GetYaxis()->SetTitle("N #mue A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 ///================
 ///==== B zone ====
 ///================
 
 
 ///==== mumu ====
 TCanvas* cNmumuB = new TCanvas("cNmumuB","cNmumuB",800,800); 
 
 TGraphErrors* grDATA_NmumuB = new TGraphErrors(numPlot,X,DATA_NmumuB,errX,DATA_errNmumuB);
 grDATA_NmumuB->SetTitle("N #mu#mu DATA B");
 grDATA_NmumuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NmumuB->GetYaxis()->SetTitle("N #mu#mu");
 grDATA_NmumuB->SetMarkerColor(kBlack);
 grDATA_NmumuB->SetFillColor(kWhite);
 grDATA_NmumuB->SetLineColor(kBlack);
 grDATA_NmumuB->SetMarkerStyle(20);
 grDATA_NmumuB->SetMarkerSize(1.5);
 grDATA_NmumuB->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NmumuB = new TGraphErrors(numPlot,X,DYmad_NmumuB,errX,DYmad_errNmumuB);
 grDYmad_NmumuB->SetTitle("N #mu#mu DYmad B");
 grDYmad_NmumuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDYmad_NmumuB->GetYaxis()->SetTitle("N #mu#mu");
 grDYmad_NmumuB->SetMarkerColor(kGreen);
 grDYmad_NmumuB->SetFillColor(kWhite);
 grDYmad_NmumuB->SetLineColor(kGreen);
 grDYmad_NmumuB->SetMarkerStyle(28);
 grDYmad_NmumuB->SetMarkerSize(1);
 grDYmad_NmumuB->SetLineWidth(2);
 
 TGraphErrors* grDY_NmumuB = new TGraphErrors(numPlot,X,DY_NmumuB,errX,DY_errNmumuB);
 grDY_NmumuB->SetTitle("N #mu#mu DY B");
 grDY_NmumuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_NmumuB->GetYaxis()->SetTitle("N #mu#mu");
 grDY_NmumuB->SetMarkerColor(kBlue);
 grDY_NmumuB->SetFillColor(kWhite);
 grDY_NmumuB->SetLineColor(kBlue);
 grDY_NmumuB->SetMarkerStyle(21);
 grDY_NmumuB->SetMarkerSize(1);
 grDY_NmumuB->SetLineWidth(2);
 
 TGraphErrors* grother_NmumuB = new TGraphErrors(numPlot,X,other_NmumuB,errX,other_errNmumuB);
 grother_NmumuB->SetTitle("N #mu#mu other B");
 grother_NmumuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grother_NmumuB->GetYaxis()->SetTitle("N #mu#mu");
 grother_NmumuB->SetMarkerColor(kGreen);
 grother_NmumuB->SetFillColor(kWhite);
 grother_NmumuB->SetLineColor(kGreen);
 grother_NmumuB->SetMarkerStyle(21);
 grother_NmumuB->SetMarkerSize(1);
 grother_NmumuB->SetLineWidth(2);
 
 TGraphErrors* grall_NmumuB = new TGraphErrors(numPlot,X,all_NmumuB,errX,all_errNmumuB);
 grall_NmumuB->SetTitle("N #mu#mu all B");
 grall_NmumuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_NmumuB->GetYaxis()->SetTitle("N #mu#mu");
 grall_NmumuB->SetMarkerColor(kRed);
 grall_NmumuB->SetFillColor(kWhite);
 grall_NmumuB->SetLineColor(kRed);
 grall_NmumuB->SetMarkerStyle(25);
 grall_NmumuB->SetMarkerSize(1);
 grall_NmumuB->SetLineWidth(2);
 
 TMultiGraph* mgr_NmumuB = new TMultiGraph(); 
 mgr_NmumuB->Add(grDATA_NmumuB);
 mgr_NmumuB->Add(grDY_NmumuB);
 mgr_NmumuB->Add(grDYmad_NmumuB);
 mgr_NmumuB->Add(grother_NmumuB);
 mgr_NmumuB->Add(grall_NmumuB);
 mgr_NmumuB->Draw("AP");
 mgr_NmumuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NmumuB->GetYaxis()->SetTitle("N #mu#mu B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== ee ====
 TCanvas* cNeeB = new TCanvas("cNeeB","cNeeB",800,800); 
 
 TGraphErrors* grDATA_NeeB = new TGraphErrors(numPlot,X,DATA_NeeB,errX,DATA_errNeeB);
 grDATA_NeeB->SetTitle("N ee DATA B");
 grDATA_NeeB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NeeB->GetYaxis()->SetTitle("N ee");
 grDATA_NeeB->SetMarkerColor(kBlack);
 grDATA_NeeB->SetFillColor(kWhite);
 grDATA_NeeB->SetLineColor(kBlack);
 grDATA_NeeB->SetMarkerStyle(20);
 grDATA_NeeB->SetMarkerSize(1.5);
 grDATA_NeeB->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NeeB = new TGraphErrors(numPlot,X,DYmad_NeeB,errX,DYmad_errNeeB);
 grDYmad_NeeB->SetTitle("N ee DYmad B");
 grDYmad_NeeB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDYmad_NeeB->GetYaxis()->SetTitle("N ee");
 grDYmad_NeeB->SetMarkerColor(kGreen);
 grDYmad_NeeB->SetFillColor(kWhite);
 grDYmad_NeeB->SetLineColor(kGreen);
 grDYmad_NeeB->SetMarkerStyle(28);
 grDYmad_NeeB->SetMarkerSize(1);
 grDYmad_NeeB->SetLineWidth(2);
 
 TGraphErrors* grDY_NeeB = new TGraphErrors(numPlot,X,DY_NeeB,errX,DY_errNeeB);
 grDY_NeeB->SetTitle("N ee DY B");
 grDY_NeeB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_NeeB->GetYaxis()->SetTitle("N ee");
 grDY_NeeB->SetMarkerColor(kBlue);
 grDY_NeeB->SetFillColor(kWhite);
 grDY_NeeB->SetLineColor(kBlue);
 grDY_NeeB->SetMarkerStyle(21);
 grDY_NeeB->SetMarkerSize(1);
 grDY_NeeB->SetLineWidth(2);
 
 TGraphErrors* grother_NeeB = new TGraphErrors(numPlot,X,other_NeeB,errX,other_errNeeB);
 grother_NeeB->SetTitle("N ee other B");
 grother_NeeB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grother_NeeB->GetYaxis()->SetTitle("N ee");
 grother_NeeB->SetMarkerColor(kGreen);
 grother_NeeB->SetFillColor(kWhite);
 grother_NeeB->SetLineColor(kGreen);
 grother_NeeB->SetMarkerStyle(21);
 grother_NeeB->SetMarkerSize(1);
 grother_NeeB->SetLineWidth(2);
 
 TGraphErrors* grall_NeeB = new TGraphErrors(numPlot,X,all_NeeB,errX,all_errNeeB);
 grall_NeeB->SetTitle("N ee all B");
 grall_NeeB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_NeeB->GetYaxis()->SetTitle("N ee");
 grall_NeeB->SetMarkerColor(kRed);
 grall_NeeB->SetFillColor(kWhite);
 grall_NeeB->SetLineColor(kRed);
 grall_NeeB->SetMarkerStyle(25);
 grall_NeeB->SetMarkerSize(1);
 grall_NeeB->SetLineWidth(2);
 
 TMultiGraph* mgr_NeeB = new TMultiGraph(); 
 mgr_NeeB->Add(grDATA_NeeB);
 mgr_NeeB->Add(grDY_NeeB);
 mgr_NeeB->Add(grDYmad_NeeB);
 mgr_NeeB->Add(grother_NeeB);
 mgr_NeeB->Add(grall_NeeB);
 mgr_NeeB->Draw("AP");
 mgr_NeeB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NeeB->GetYaxis()->SetTitle("N ee B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== emu ====
 TCanvas* cNemuB = new TCanvas("cNemuB","cNemuB",800,800); 
 
 TGraphErrors* grDATA_NemuB = new TGraphErrors(numPlot,X,DATA_NemuB,errX,DATA_errNemuB);
 grDATA_NemuB->SetTitle("N e#mu DATA B");
 grDATA_NemuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NemuB->GetYaxis()->SetTitle("N e#mu");
 grDATA_NemuB->SetMarkerColor(kBlack);
 grDATA_NemuB->SetFillColor(kWhite);
 grDATA_NemuB->SetLineColor(kBlack);
 grDATA_NemuB->SetMarkerStyle(20);
 grDATA_NemuB->SetMarkerSize(1.5);
 grDATA_NemuB->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NemuB = new TGraphErrors(numPlot,X,DYmad_NemuB,errX,DYmad_errNemuB);
 grDYmad_NemuB->SetTitle("N e#mu DYmad B");
 grDYmad_NemuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDYmad_NemuB->GetYaxis()->SetTitle("N e#mu");
 grDYmad_NemuB->SetMarkerColor(kGreen);
 grDYmad_NemuB->SetFillColor(kWhite);
 grDYmad_NemuB->SetLineColor(kGreen);
 grDYmad_NemuB->SetMarkerStyle(28);
 grDYmad_NemuB->SetMarkerSize(1);
 grDYmad_NemuB->SetLineWidth(2);
 
 TGraphErrors* grDY_NemuB = new TGraphErrors(numPlot,X,DY_NemuB,errX,DY_errNemuB);
 grDY_NemuB->SetTitle("N e#mu DY B");
 grDY_NemuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_NemuB->GetYaxis()->SetTitle("N e#mu");
 grDY_NemuB->SetMarkerColor(kBlue);
 grDY_NemuB->SetFillColor(kWhite);
 grDY_NemuB->SetLineColor(kBlue);
 grDY_NemuB->SetMarkerStyle(21);
 grDY_NemuB->SetMarkerSize(1);
 grDY_NemuB->SetLineWidth(2);
 
 TGraphErrors* grother_NemuB = new TGraphErrors(numPlot,X,other_NemuB,errX,other_errNemuB);
 grother_NemuB->SetTitle("N e#mu other B");
 grother_NemuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grother_NemuB->GetYaxis()->SetTitle("N e#mu");
 grother_NemuB->SetMarkerColor(kGreen);
 grother_NemuB->SetFillColor(kWhite);
 grother_NemuB->SetLineColor(kGreen);
 grother_NemuB->SetMarkerStyle(21);
 grother_NemuB->SetMarkerSize(1);
 grother_NemuB->SetLineWidth(2);
 
 TGraphErrors* grall_NemuB = new TGraphErrors(numPlot,X,all_NemuB,errX,all_errNemuB);
 grall_NemuB->SetTitle("N e#mu all B");
 grall_NemuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_NemuB->GetYaxis()->SetTitle("N e#mu");
 grall_NemuB->SetMarkerColor(kRed);
 grall_NemuB->SetFillColor(kWhite);
 grall_NemuB->SetLineColor(kRed);
 grall_NemuB->SetMarkerStyle(25);
 grall_NemuB->SetMarkerSize(1);
 grall_NemuB->SetLineWidth(2);
 
 TMultiGraph* mgr_NemuB = new TMultiGraph(); 
 mgr_NemuB->Add(grDATA_NemuB);
 mgr_NemuB->Add(grDY_NemuB);
 mgr_NemuB->Add(grDYmad_NemuB);
 mgr_NemuB->Add(grother_NemuB);
 mgr_NemuB->Add(grall_NemuB);
 mgr_NemuB->Draw("AP");
 mgr_NemuB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NemuB->GetYaxis()->SetTitle("N e#mu B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== mue ====
 TCanvas* cNmueB = new TCanvas("cNmueB","cNmueB",800,800); 
 
 TGraphErrors* grDATA_NmueB = new TGraphErrors(numPlot,X,DATA_NmueB,errX,DATA_errNmueB);
 grDATA_NmueB->SetTitle("N #mue DATA B");
 grDATA_NmueB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NmueB->GetYaxis()->SetTitle("N #mue");
 grDATA_NmueB->SetMarkerColor(kBlack);
 grDATA_NmueB->SetFillColor(kWhite);
 grDATA_NmueB->SetLineColor(kBlack);
 grDATA_NmueB->SetMarkerStyle(20);
 grDATA_NmueB->SetMarkerSize(1.5);
 grDATA_NmueB->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NmueB = new TGraphErrors(numPlot,X,DYmad_NmueB,errX,DYmad_errNmueB);
 grDYmad_NmueB->SetTitle("N #mue DYmad B");
 grDYmad_NmueB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDYmad_NmueB->GetYaxis()->SetTitle("N #mue");
 grDYmad_NmueB->SetMarkerColor(kGreen);
 grDYmad_NmueB->SetFillColor(kWhite);
 grDYmad_NmueB->SetLineColor(kGreen);
 grDYmad_NmueB->SetMarkerStyle(28);
 grDYmad_NmueB->SetMarkerSize(1);
 grDYmad_NmueB->SetLineWidth(2);
 
 TGraphErrors* grDY_NmueB = new TGraphErrors(numPlot,X,DY_NmueB,errX,DY_errNmueB);
 grDY_NmueB->SetTitle("N #mue DY B");
 grDY_NmueB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_NmueB->GetYaxis()->SetTitle("N #mue");
 grDY_NmueB->SetMarkerColor(kBlue);
 grDY_NmueB->SetFillColor(kWhite);
 grDY_NmueB->SetLineColor(kBlue);
 grDY_NmueB->SetMarkerStyle(21);
 grDY_NmueB->SetMarkerSize(1);
 grDY_NmueB->SetLineWidth(2);
 
 TGraphErrors* grother_NmueB = new TGraphErrors(numPlot,X,other_NmueB,errX,other_errNmueB);
 grother_NmueB->SetTitle("N #mue other B");
 grother_NmueB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grother_NmueB->GetYaxis()->SetTitle("N #mue");
 grother_NmueB->SetMarkerColor(kGreen);
 grother_NmueB->SetFillColor(kWhite);
 grother_NmueB->SetLineColor(kGreen);
 grother_NmueB->SetMarkerStyle(21);
 grother_NmueB->SetMarkerSize(1);
 grother_NmueB->SetLineWidth(2);
 
 TGraphErrors* grall_NmueB = new TGraphErrors(numPlot,X,all_NmueB,errX,all_errNmueB);
 grall_NmueB->SetTitle("N #mue all B");
 grall_NmueB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_NmueB->GetYaxis()->SetTitle("N #mue");
 grall_NmueB->SetMarkerColor(kRed);
 grall_NmueB->SetFillColor(kWhite);
 grall_NmueB->SetLineColor(kRed);
 grall_NmueB->SetMarkerStyle(25);
 grall_NmueB->SetMarkerSize(1);
 grall_NmueB->SetLineWidth(2);
 
 TMultiGraph* mgr_NmueB = new TMultiGraph(); 
 mgr_NmueB->Add(grDATA_NmueB);
 mgr_NmueB->Add(grDY_NmueB);
 mgr_NmueB->Add(grDYmad_NmueB);
 mgr_NmueB->Add(grother_NmueB);
 mgr_NmueB->Add(grall_NmueB);
 mgr_NmueB->Draw("AP");
 mgr_NmueB->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NmueB->GetYaxis()->SetTitle("N #mue B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 ///================================================
 ///=================== comparison =================
 ///==== R with mixed emu-mue and R traditional ====
 ///================================================
 
 
 
 
 //==== ee ====
 
 TGraphErrors* grDATA_standardR_ee = new TGraphErrors(numPlot,XShift,DATA_standardR_ee,errX,DATA_errstandardR_ee);
 grDATA_standardR_ee->SetTitle("Ree DATA Standard");
 grDATA_standardR_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_standardR_ee->GetYaxis()->SetTitle("R ee");
 grDATA_standardR_ee->SetMarkerColor(kRed);
 grDATA_standardR_ee->SetFillColor(kWhite);
 grDATA_standardR_ee->SetLineColor(kRed);
 grDATA_standardR_ee->SetMarkerStyle(24);
 grDATA_standardR_ee->SetMarkerSize(1);
 grDATA_standardR_ee->SetLineWidth(2);
 
 TGraphErrors* grDATA_R_ee = new TGraphErrors(numPlot,X,DATA_R_ee,errX,DATA_errR_ee);
 grDATA_R_ee->SetTitle("Ree DATA");
 grDATA_R_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_R_ee->GetYaxis()->SetTitle("R ee");
 grDATA_R_ee->SetMarkerColor(kRed);
 grDATA_R_ee->SetFillColor(kWhite);
 grDATA_R_ee->SetLineColor(kRed);
 grDATA_R_ee->SetMarkerStyle(20);
 grDATA_R_ee->SetMarkerSize(1);
 grDATA_R_ee->SetLineWidth(2);
 
 
 
 TGraphErrors* grall_R_ee = new TGraphErrors(numPlot,X,all_R_ee,errX,all_errR_ee);
 grall_R_ee->SetTitle("Ree MC ");
 grall_R_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_R_ee->GetYaxis()->SetTitle("R ee");
 grall_R_ee->SetMarkerColor(kBlue);
 grall_R_ee->SetFillColor(kWhite);
 grall_R_ee->SetLineColor(kBlue);
 grall_R_ee->SetMarkerStyle(21);
 grall_R_ee->SetMarkerSize(1);
 grall_R_ee->SetLineWidth(2);
 

 TGraphErrors* grall_standardR_ee = new TGraphErrors(numPlot,XShift,all_standardR_ee,errX,all_errstandardR_ee);
 grall_standardR_ee->SetTitle("Ree MC  Standard");
 grall_standardR_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_standardR_ee->GetYaxis()->SetTitle("R ee");
 grall_standardR_ee->SetMarkerColor(kBlue);
 grall_standardR_ee->SetFillColor(kWhite);
 grall_standardR_ee->SetLineColor(kBlue);
 grall_standardR_ee->SetMarkerStyle(25);
 grall_standardR_ee->SetMarkerSize(1);
 grall_standardR_ee->SetLineWidth(2);
 
 
 TGraphErrors* grDY_standardR_ee = new TGraphErrors(numPlot,XShift,DY_standardR_ee,errX,DY_errstandardR_ee);
 grDY_standardR_ee->SetTitle("Ree MC DY Standard");
 grDY_standardR_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_standardR_ee->GetYaxis()->SetTitle("R ee");
 grDY_standardR_ee->SetMarkerColor(kGreen);
 grDY_standardR_ee->SetFillColor(kWhite);
 grDY_standardR_ee->SetLineColor(kGreen);
 grDY_standardR_ee->SetMarkerStyle(26);
 grDY_standardR_ee->SetMarkerSize(1);
 grDY_standardR_ee->SetLineWidth(2);
 
 
 TGraphErrors* grDY_R_ee = new TGraphErrors(numPlot,X,DY_R_ee,errX,DY_errR_ee);
 grDY_R_ee->SetTitle("Ree MC DY");
 grDY_R_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_R_ee->GetYaxis()->SetTitle("R ee");
 grDY_R_ee->SetMarkerColor(kGreen);
 grDY_R_ee->SetFillColor(kWhite);
 grDY_R_ee->SetLineColor(kGreen);
 grDY_R_ee->SetMarkerStyle(22);
 grDY_R_ee->SetMarkerSize(1);
 grDY_R_ee->SetLineWidth(2);
 
 
 
 TGraphErrors* grDY_Rexact_ee = new TGraphErrors(numPlot,XShift,DY_Rexact_ee,errX,DY_errRexact_ee);
 grDY_Rexact_ee->SetTitle("Ree MC DY exact");
 grDY_Rexact_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_Rexact_ee->GetYaxis()->SetTitle("R ee");
 grDY_Rexact_ee->SetMarkerColor(kTeal);
 grDY_Rexact_ee->SetFillColor(kWhite);
 grDY_Rexact_ee->SetLineColor(kTeal);
 grDY_Rexact_ee->SetMarkerStyle(30);
 grDY_Rexact_ee->SetMarkerSize(1);
 grDY_Rexact_ee->SetLineWidth(2);
 
 
//  gStyle -> SetOptStat(11111);
//  gStyle -> SetOptFit(1011);
 
 TPaveStats *st[100];
 TF1* funz = new TF1("funz","[0]",X[0]-0.5,X[numPlot-1]+0.5);
 funz->SetLineStyle(2);
 
 TCanvas* c_R_ee = new TCanvas("c_R_ee","c_R_ee",800,400); 
 TMultiGraph* mgr_R_ee = new TMultiGraph(); 
 mgr_R_ee->Add(grDATA_standardR_ee);
//  mgr_R_ee->Add(grDATA_R_ee);
//  mgr_R_ee->Add(grall_standardR_ee);
//  mgr_R_ee->Add(grall_R_ee);
 mgr_R_ee->Add(grDY_standardR_ee);
//  mgr_R_ee->Add(grDY_R_ee);
//  mgr_R_ee->Add(grDY_Rexact_ee);
 mgr_R_ee->Draw("AP");
 mgr_R_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_R_ee->GetYaxis()->SetTitle("R ee");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 funz->SetLineColor(grDATA_standardR_ee->GetMarkerColor());
 grDATA_standardR_ee->Fit("funz","R");
//  std::cout << " --> " << grDATA_standardR_ee->GetListOfFunctions() << std::endl;
//  std::cout << " --> " << grDATA_standardR_ee->GetListOfFunctions()->FindObject("stats") << std::endl;
//  st[0]= (TPaveStats*)(grDATA_standardR_ee->GetListOfFunctions()->FindObject("stats"));
//  st[0]->SetY1NDC(0.85); //new x start position
//  st[0]->SetY2NDC(1.00); //new x end position
//  st[0]->SetTextColor(grDATA_standardR_ee->GetMarkerColor());
//  st[0]->Draw();
 
 funz->SetLineColor(grDY_standardR_ee->GetMarkerColor());
 grDY_standardR_ee->Fit("funz","R");
//  st[1]= (TPaveStats*)(grDY_standardR_ee->GetListOfFunctions()->FindObject("stats"));
//  st[1]->SetY1NDC(0.72); //new x start position
//  st[1]->SetY2NDC(0.85); //new x end position
//  st[1]->SetTextColor(grDY_standardR_ee->GetMarkerColor());
//  st[1]->Draw();
 
  
 
 
 
 
 
 
 //==== mumu ====
 
 TGraphErrors* grDATA_standardR_mumu = new TGraphErrors(numPlot,XShift,DATA_standardR_mumu,errX,DATA_errstandardR_mumu);
 grDATA_standardR_mumu->SetTitle("R#mu#mu DATA Standard");
 grDATA_standardR_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_standardR_mumu->GetYaxis()->SetTitle("R mumu");
 grDATA_standardR_mumu->SetMarkerColor(kRed);
 grDATA_standardR_mumu->SetFillColor(kWhite);
 grDATA_standardR_mumu->SetLineColor(kRed);
 grDATA_standardR_mumu->SetMarkerStyle(24);
 grDATA_standardR_mumu->SetMarkerSize(1);
 grDATA_standardR_mumu->SetLineWidth(2);
 
 TGraphErrors* grDATA_R_mumu = new TGraphErrors(numPlot,X,DATA_R_mumu,errX,DATA_errR_mumu);
 grDATA_R_mumu->SetTitle("R#mu#mu DATA");
 grDATA_R_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_R_mumu->GetYaxis()->SetTitle("R mumu");
 grDATA_R_mumu->SetMarkerColor(kRed);
 grDATA_R_mumu->SetFillColor(kWhite);
 grDATA_R_mumu->SetLineColor(kRed);
 grDATA_R_mumu->SetMarkerStyle(20);
 grDATA_R_mumu->SetMarkerSize(1);
 grDATA_R_mumu->SetLineWidth(2);
 
 
 
 TGraphErrors* grall_R_mumu = new TGraphErrors(numPlot,X,all_R_mumu,errX,all_errR_mumu);
 grall_R_mumu->SetTitle("R#mu#mu MC ");
 grall_R_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_R_mumu->GetYaxis()->SetTitle("R mumu");
 grall_R_mumu->SetMarkerColor(kBlue);
 grall_R_mumu->SetFillColor(kWhite);
 grall_R_mumu->SetLineColor(kBlue);
 grall_R_mumu->SetMarkerStyle(21);
 grall_R_mumu->SetMarkerSize(1);
 grall_R_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grall_standardR_mumu = new TGraphErrors(numPlot,XShift,all_standardR_mumu,errX,all_errstandardR_mumu);
 grall_standardR_mumu->SetTitle("R#mu#mu MC  standard");
 grall_standardR_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grall_standardR_mumu->GetYaxis()->SetTitle("R mumu");
 grall_standardR_mumu->SetMarkerColor(kBlue);
 grall_standardR_mumu->SetFillColor(kWhite);
 grall_standardR_mumu->SetLineColor(kBlue);
 grall_standardR_mumu->SetMarkerStyle(25);
 grall_standardR_mumu->SetMarkerSize(1);
 grall_standardR_mumu->SetLineWidth(2);
 
 
 
 TGraphErrors* grDY_standardR_mumu = new TGraphErrors(numPlot,XShift,DY_standardR_mumu,errX,DY_errstandardR_mumu);
 grDY_standardR_mumu->SetTitle("R#mu#mu MC DY standard");
 grDY_standardR_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_standardR_mumu->GetYaxis()->SetTitle("R mumu");
 grDY_standardR_mumu->SetMarkerColor(kGreen);
 grDY_standardR_mumu->SetFillColor(kWhite);
 grDY_standardR_mumu->SetLineColor(kGreen);
 grDY_standardR_mumu->SetMarkerStyle(26);
 grDY_standardR_mumu->SetMarkerSize(1);
 grDY_standardR_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grDY_R_mumu = new TGraphErrors(numPlot,X,DY_R_mumu,errX,DY_errR_mumu);
 grDY_R_mumu->SetTitle("R#mu#mu MC DY");
 grDY_R_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_R_mumu->GetYaxis()->SetTitle("R mumu");
 grDY_R_mumu->SetMarkerColor(kGreen);
 grDY_R_mumu->SetFillColor(kWhite);
 grDY_R_mumu->SetLineColor(kGreen);
 grDY_R_mumu->SetMarkerStyle(22);
 grDY_R_mumu->SetMarkerSize(1);
 grDY_R_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grDY_Rexact_mumu = new TGraphErrors(numPlot,XShift,DY_Rexact_mumu,errX,DY_errRexact_mumu);
 grDY_Rexact_mumu->SetTitle("R#mu#mu MC DY exact");
 grDY_Rexact_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDY_Rexact_mumu->GetYaxis()->SetTitle("R mumu");
 grDY_Rexact_mumu->SetMarkerColor(kTeal);
 grDY_Rexact_mumu->SetFillColor(kWhite);
 grDY_Rexact_mumu->SetLineColor(kTeal);
 grDY_Rexact_mumu->SetMarkerStyle(30);
 grDY_Rexact_mumu->SetMarkerSize(1);
 grDY_Rexact_mumu->SetLineWidth(2);
 
 
 TCanvas* c_R_mumu = new TCanvas("c_R_mumu","c_R_mumu",800,400); 
 TMultiGraph* mgr_R_mumu = new TMultiGraph(); 
 mgr_R_mumu->Add(grDATA_standardR_mumu);
//  mgr_R_mumu->Add(grDATA_R_mumu);
//  mgr_R_mumu->Add(grall_standardR_mumu);
//  mgr_R_mumu->Add(grall_R_mumu);
 mgr_R_mumu->Add(grDY_standardR_mumu);
//  mgr_R_mumu->Add(grDY_R_mumu);
//  mgr_R_mumu->Add(grDY_Rexact_mumu);
 mgr_R_mumu->Draw("AP");
 mgr_R_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_R_mumu->GetYaxis()->SetTitle("R #mu#mu");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 

 
 funz->SetLineColor(grDATA_standardR_mumu->GetMarkerColor());
 grDATA_standardR_mumu->Fit("funz","R");
 //  std::cout << " --> " << grDATA_standardR_mumu->GetListOfFunctions() << std::endl;
 //  std::cout << " --> " << grDATA_standardR_mumu->GetListOfFunctions()->FindObject("stats") << std::endl;
 //  st[0]= (TPaveStats*)(grDATA_standardR_mumu->GetListOfFunctions()->FindObject("stats"));
 //  st[0]->SetY1NDC(0.85); //new x start position
 //  st[0]->SetY2NDC(1.00); //new x end position
 //  st[0]->SetTextColor(grDATA_standardR_mumu->GetMarkerColor());
 //  st[0]->Draw();
 
 funz->SetLineColor(grDY_standardR_mumu->GetMarkerColor());
 grDY_standardR_mumu->Fit("funz","R");
 //  st[1]= (TPaveStats*)(grDY_standardR_mumu->GetListOfFunctions()->FindObject("stats"));
 //  st[1]->SetY1NDC(0.72); //new x start position
 //  st[1]->SetY2NDC(0.85); //new x end position
 //  st[1]->SetTextColor(grDY_standardR_mumu->GetMarkerColor());
 //  st[1]->Draw();
 
 
 
//  TGraphErrors* grDATA_NKB_ee = new TGraphErrors(numPlot,X,DATA_NKB_ee,errX,DATA_errNKB_ee);
//  grDATA_NKB_ee->SetTitle("N #mue * kee B");
//  grDATA_NKB_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  grDATA_NKB_ee->GetYaxis()->SetTitle("N ee other");
//  grDATA_NKB_ee->SetMarkerColor(kRed);
//  grDATA_NKB_ee->SetFillColor(kWhite);
//  grDATA_NKB_ee->SetLineColor(kRed);
//  grDATA_NKB_ee->SetMarkerStyle(25);
//  grDATA_NKB_ee->SetMarkerSize(1);
//  grDATA_NKB_ee->SetLineWidth(2);
// 
//  TGraphErrors* grDATA_NKBNew_ee = new TGraphErrors(numPlot,X,DATA_NKBNew_ee,errX,DATA_errNKBNew_ee);
//  grDATA_NKBNew_ee->SetTitle("New Nee B");
//  grDATA_NKBNew_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  grDATA_NKBNew_ee->GetYaxis()->SetTitle("N ee other");
//  grDATA_NKBNew_ee->SetMarkerColor(kBlue);
//  grDATA_NKBNew_ee->SetFillColor(kWhite);
//  grDATA_NKBNew_ee->SetLineColor(kBlue);
//  grDATA_NKBNew_ee->SetMarkerStyle(25);
//  grDATA_NKBNew_ee->SetMarkerSize(1);
//  grDATA_NKBNew_ee->SetLineWidth(2);
//  
//  
//  
//  
//  TGraphErrors* grDATA_NKB_mumu = new TGraphErrors(numPlot,X,DATA_NKB_mumu,errX,DATA_errNKB_mumu);
//  grDATA_NKB_mumu->SetTitle("N #mue * k#mu#mu B");
//  grDATA_NKB_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  grDATA_NKB_mumu->GetYaxis()->SetTitle("N #mu#mu other");
//  grDATA_NKB_mumu->SetMarkerColor(kRed);
//  grDATA_NKB_mumu->SetFillColor(kWhite);
//  grDATA_NKB_mumu->SetLineColor(kRed);
//  grDATA_NKB_mumu->SetMarkerStyle(21);
//  grDATA_NKB_mumu->SetMarkerSize(1);
//  grDATA_NKB_mumu->SetLineWidth(2);
//  
//  TGraphErrors* grDATA_NKBNew_mumu = new TGraphErrors(numPlot,X,DATA_NKBNew_mumu,errX,DATA_errNKBNew_mumu);
//  grDATA_NKBNew_mumu->SetTitle("New N#mu#mu B");
//  grDATA_NKBNew_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  grDATA_NKBNew_mumu->GetYaxis()->SetTitle("N #mu#mu other");
//  grDATA_NKBNew_mumu->SetMarkerColor(kBlue);
//  grDATA_NKBNew_mumu->SetFillColor(kWhite);
//  grDATA_NKBNew_mumu->SetLineColor(kBlue);
//  grDATA_NKBNew_mumu->SetMarkerStyle(21);
//  grDATA_NKBNew_mumu->SetMarkerSize(1);
//  grDATA_NKBNew_mumu->SetLineWidth(2);
//  
//  
//  
//  
//  
//  
//  
//  
//  TCanvas* cDATA_NK_ee = new TCanvas("cDATA_NK_ee","cDATA_NK_ee",800,800); 
//  
//  TGraphErrors* grDATA_NKA_ee = new TGraphErrors(numPlot,X,DATA_NKA_ee,errX,DATA_errNKA_ee);
//  grDATA_NKA_ee->SetTitle("N #mue * kee A");
//  grDATA_NKA_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  grDATA_NKA_ee->GetYaxis()->SetTitle("N ee other");
//  grDATA_NKA_ee->SetMarkerColor(kRed);
//  grDATA_NKA_ee->SetFillColor(kWhite);
//  grDATA_NKA_ee->SetLineColor(kRed);
//  grDATA_NKA_ee->SetMarkerStyle(26);
//  grDATA_NKA_ee->SetMarkerSize(1);
//  grDATA_NKA_ee->SetLineWidth(2);
//  
//  TGraphErrors* grDATA_NKANew_ee = new TGraphErrors(numPlot,X,DATA_NKANew_ee,errX,DATA_errNKANew_ee);
//  grDATA_NKANew_ee->SetTitle("New Nee A");
//  grDATA_NKANew_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  grDATA_NKANew_ee->GetYaxis()->SetTitle("N ee other");
//  grDATA_NKANew_ee->SetMarkerColor(kBlue);
//  grDATA_NKANew_ee->SetFillColor(kWhite);
//  grDATA_NKANew_ee->SetLineColor(kBlue);
//  grDATA_NKANew_ee->SetMarkerStyle(26);
//  grDATA_NKANew_ee->SetMarkerSize(1);
//  grDATA_NKANew_ee->SetLineWidth(2);
//  
//  TMultiGraph* mgr_DATA_NK_ee = new TMultiGraph(); 
//  mgr_DATA_NK_ee->Add(grDATA_NKA_ee);
//  mgr_DATA_NK_ee->Add(grDATA_NKANew_ee);
//  mgr_DATA_NK_ee->Add(grDATA_NKB_ee);
//  mgr_DATA_NK_ee->Add(grDATA_NKBNew_ee);
//  mgr_DATA_NK_ee->Draw("AP");
//  mgr_DATA_NK_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  mgr_DATA_NK_ee->GetYaxis()->SetTitle("N ee other");
//  
//  TLegend* leg = gPad->BuildLegend();
//  leg->SetFillColor(kWhite);
//  gPad->SetGrid();
//  
//  
//  
//  TCanvas* cDATA_NK_mumu = new TCanvas("cDATA_NK_mumu","cDATA_NK_mumu",800,800); 
//  
//  TGraphErrors* grDATA_NKA_mumu = new TGraphErrors(numPlot,X,DATA_NKA_mumu,errX,DATA_errNKA_mumu);
//  grDATA_NKA_mumu->SetTitle("N #mue * k#mu#mu A");
//  grDATA_NKA_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  grDATA_NKA_mumu->GetYaxis()->SetTitle("N #mu#mu other");
//  grDATA_NKA_mumu->SetMarkerColor(kRed);
//  grDATA_NKA_mumu->SetFillColor(kWhite);
//  grDATA_NKA_mumu->SetLineColor(kRed);
//  grDATA_NKA_mumu->SetMarkerStyle(22);
//  grDATA_NKA_mumu->SetMarkerSize(1);
//  grDATA_NKA_mumu->SetLineWidth(2);
//  
//  TGraphErrors* grDATA_NKANew_mumu = new TGraphErrors(numPlot,X,DATA_NKANew_mumu,errX,DATA_errNKANew_mumu);
//  grDATA_NKANew_mumu->SetTitle("New N#mu#mu A");
//  grDATA_NKANew_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  grDATA_NKANew_mumu->GetYaxis()->SetTitle("N #mu#mu other");
//  grDATA_NKANew_mumu->SetMarkerColor(kBlue);
//  grDATA_NKANew_mumu->SetFillColor(kWhite);
//  grDATA_NKANew_mumu->SetLineColor(kBlue);
//  grDATA_NKANew_mumu->SetMarkerStyle(22);
//  grDATA_NKANew_mumu->SetMarkerSize(1);
//  grDATA_NKANew_mumu->SetLineWidth(2);
//  
//  TMultiGraph* mgr_DATA_NK_mumu = new TMultiGraph(); 
//  mgr_DATA_NK_mumu->Add(grDATA_NKA_mumu);
//  mgr_DATA_NK_mumu->Add(grDATA_NKANew_mumu);
//  mgr_DATA_NK_mumu->Add(grDATA_NKB_mumu);
//  mgr_DATA_NK_mumu->Add(grDATA_NKBNew_mumu);
//  mgr_DATA_NK_mumu->Draw("AP");
//  mgr_DATA_NK_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
//  mgr_DATA_NK_mumu->GetYaxis()->SetTitle("N #mu#mu other");
//  
//  TLegend* leg = gPad->BuildLegend();
//  leg->SetFillColor(kWhite);
//  gPad->SetGrid();
//  
// }
//  
//  
 
 
 
 
 
 
 
 
 ///==================================================
 ///==== plot of NDY corrected: with R method and M method ====
 ///==================================================
 
 ///==============
 ///==== A zone ====
 ///==============
 
  TCanvas* cNmumuACorrected = new TCanvas("cNmumuACorrected","cNmumuACorrected",800,800); 

  TGraphErrors* grDATA_NmumuA_Corrected_standardR = new TGraphErrors(numPlot,X,DATA_NDYCorrected_standardR_A_mumu,errX,DATA_errNDYCorrected_standardR_A_mumu);
  grDATA_NmumuA_Corrected_standardR->SetTitle("N #mu#mu DATA corrected standardR");
  grDATA_NmumuA_Corrected_standardR->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
  grDATA_NmumuA_Corrected_standardR->GetYaxis()->SetTitle("N #mu#mu");
  grDATA_NmumuA_Corrected_standardR->SetMarkerColor(kBlue);
  grDATA_NmumuA_Corrected_standardR->SetFillColor(kWhite);
  grDATA_NmumuA_Corrected_standardR->SetLineColor(kBlue);
  grDATA_NmumuA_Corrected_standardR->SetMarkerStyle(20);
  grDATA_NmumuA_Corrected_standardR->SetMarkerSize(1);
  grDATA_NmumuA_Corrected_standardR->SetLineWidth(2);
  grDATA_NmumuA_Corrected_standardR->SetLineStyle(2);
  
  
 TGraphErrors* grDATA_NmumuA_Corrected_R = new TGraphErrors(numPlot,X,DATA_NDYCorrected_R_A_mumu,errX,DATA_errNDYCorrected_R_A_mumu);
 grDATA_NmumuA_Corrected_R->SetTitle("N #mu#mu DATA corrected R");
 grDATA_NmumuA_Corrected_R->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NmumuA_Corrected_R->GetYaxis()->SetTitle("N #mu#mu");
 grDATA_NmumuA_Corrected_R->SetMarkerColor(kTeal);
 grDATA_NmumuA_Corrected_R->SetFillColor(kWhite);
 grDATA_NmumuA_Corrected_R->SetLineColor(kTeal);
 grDATA_NmumuA_Corrected_R->SetMarkerStyle(20);
 grDATA_NmumuA_Corrected_R->SetMarkerSize(1);
 grDATA_NmumuA_Corrected_R->SetLineWidth(2);
 grDATA_NmumuA_Corrected_R->SetLineStyle(2);
 
 
 
 TMultiGraph* mgr_NmumuA_all = new TMultiGraph(); 
 mgr_NmumuA_all->Add(grDATA_NmumuA);
 mgr_NmumuA_all->Add(grDY_NmumuA);
//  mgr_NmumuA_all->Add(grDYmad_NmumuA);
 mgr_NmumuA_all->Add(grother_NmumuA);
 mgr_NmumuA_all->Add(grall_NmumuA);
//  mgr_NmumuA_all->Add(grDATA_NmumuA_Corrected_standardR);
 mgr_NmumuA_all->Add(grDATA_NmumuA_Corrected_R);
//  mgr_NmumuA_all->Add(grDATA_NmumuA_Corrected_M);
 mgr_NmumuA_all->Draw("AP");
 mgr_NmumuA_all->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NmumuA_all->GetYaxis()->SetTitle("N #mu#mu");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas* cNeeACorrected = new TCanvas("cNeeACorrected","cNeeACorrected",800,800); 

 TGraphErrors* grDATA_NeeA_Corrected_standardR = new TGraphErrors(numPlot,X,DATA_NDYCorrected_standardR_A_ee,errX,DATA_errNDYCorrected_standardR_A_ee);
 grDATA_NeeA_Corrected_standardR->SetTitle("N ee DATA corrected standardR");
 grDATA_NeeA_Corrected_standardR->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NeeA_Corrected_standardR->GetYaxis()->SetTitle("N ee");
 grDATA_NeeA_Corrected_standardR->SetMarkerColor(kBlue);
 grDATA_NeeA_Corrected_standardR->SetFillColor(kWhite);
 grDATA_NeeA_Corrected_standardR->SetLineColor(kBlue);
 grDATA_NeeA_Corrected_standardR->SetMarkerStyle(20);
 grDATA_NeeA_Corrected_standardR->SetMarkerSize(1);
 grDATA_NeeA_Corrected_standardR->SetLineWidth(2);
 grDATA_NeeA_Corrected_standardR->SetLineStyle(2);
 
 
 TGraphErrors* grDATA_NeeA_Corrected_R = new TGraphErrors(numPlot,X,DATA_NDYCorrected_R_A_ee,errX,DATA_errNDYCorrected_R_A_ee);
 grDATA_NeeA_Corrected_R->SetTitle("N ee DATA corrected R");
 grDATA_NeeA_Corrected_R->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grDATA_NeeA_Corrected_R->GetYaxis()->SetTitle("N ee");
 grDATA_NeeA_Corrected_R->SetMarkerColor(kTeal);
 grDATA_NeeA_Corrected_R->SetFillColor(kWhite);
 grDATA_NeeA_Corrected_R->SetLineColor(kTeal);
 grDATA_NeeA_Corrected_R->SetMarkerStyle(20);
 grDATA_NeeA_Corrected_R->SetMarkerSize(1);
 grDATA_NeeA_Corrected_R->SetLineWidth(2);
 grDATA_NeeA_Corrected_R->SetLineStyle(2);
 
 
 
 
 TMultiGraph* mgr_NeeA_all = new TMultiGraph(); 
 mgr_NeeA_all->Add(grDATA_NeeA);
 mgr_NeeA_all->Add(grDY_NeeA);
//  mgr_NeeA_all->Add(grDYmad_NeeA);
 mgr_NeeA_all->Add(grother_NeeA);
 mgr_NeeA_all->Add(grall_NeeA);
//  mgr_NeeA_all->Add(grDATA_NeeA_Corrected_standardR);
 mgr_NeeA_all->Add(grDATA_NeeA_Corrected_R);
//  mgr_NeeA_all->Add(grDATA_NeeA_Corrected_M);
 mgr_NeeA_all->Draw("AP");
 mgr_NeeA_all->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_NeeA_all->GetYaxis()->SetTitle("N ee");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 ///==== Correction coefficients as a function of met cut ====
 
 
 double CorrectionFactor_ee_standardR[100];
 double CorrectionFactor_mumu_standardR[100];
 double CorrectionFactor_ee_R[100];
 double CorrectionFactor_mumu_R[100];
 
 double errCorrectionFactor_ee_standardR[100];
 double errCorrectionFactor_mumu_standardR[100];
 double errCorrectionFactor_ee_R[100];
 double errCorrectionFactor_mumu_R[100];
 
 for (int iPoint = 0; iPoint < numPlot; iPoint++) {
  double _xU, _yU, _xD, _yD;
  double _erryU, _erryD;
  
  //---- ee
  grDATA_NeeA_Corrected_standardR->GetPoint(iPoint,_xU,_yU);
  grDY_NeeA->GetPoint(iPoint,_xD,_yD);
  _erryU = grDATA_NeeA_Corrected_standardR->GetErrorY(iPoint);
  _erryD = grDY_NeeA->GetErrorY(iPoint);  
  CorrectionFactor_ee_standardR[iPoint] = _yU / _yD;
  errCorrectionFactor_ee_standardR[iPoint] = sqrt(_erryU / _yD * _erryU / _yD + _erryD / _yD / _yD * _yU * _erryD / _yD / _yD * _yU) ;
  
  grDATA_NeeA_Corrected_R->GetPoint(iPoint,_xU,_yU);
  grDY_NeeA->GetPoint(iPoint,_xD,_yD);
  _erryU = grDATA_NeeA_Corrected_R->GetErrorY(iPoint);
  _erryD = grDY_NeeA->GetErrorY(iPoint);  
  CorrectionFactor_ee_R[iPoint] = _yU / _yD;
  errCorrectionFactor_ee_R[iPoint] = sqrt(_erryU / _yD * _erryU / _yD + _erryD / _yD / _yD * _yU * _erryD / _yD / _yD * _yU) ;
  
  //---- mumu 
  grDATA_NmumuA_Corrected_standardR->GetPoint(iPoint,_xU,_yU);
  grDY_NmumuA->GetPoint(iPoint,_xD,_yD);
  _erryU = grDATA_NmumuA_Corrected_standardR->GetErrorY(iPoint);
  _erryD = grDY_NmumuA->GetErrorY(iPoint);  
  CorrectionFactor_mumu_standardR[iPoint] = _yU / _yD;
  errCorrectionFactor_mumu_standardR[iPoint] = sqrt(_erryU / _yD * _erryU / _yD + _erryD / _yD / _yD * _yU * _erryD / _yD / _yD * _yU) ;
  
  grDATA_NmumuA_Corrected_R->GetPoint(iPoint,_xU,_yU);
  grDY_NmumuA->GetPoint(iPoint,_xD,_yD);
  _erryU = grDATA_NmumuA_Corrected_R->GetErrorY(iPoint);
  _erryD = grDY_NmumuA->GetErrorY(iPoint);  
  CorrectionFactor_mumu_R[iPoint] = _yU / _yD;
  errCorrectionFactor_mumu_R[iPoint] = sqrt(_erryU / _yD * _erryU / _yD + _erryD / _yD / _yD * _yU * _erryD / _yD / _yD * _yU) ;
  
 }
 
 
 
 
 TCanvas* cCorrectionFactor_ee = new TCanvas("cCorrectionFactor_ee","cCorrectionFactor_ee",800,800); 
 
 TGraphErrors* grCorrectionFactor_ee_standardR = new TGraphErrors(numPlot,X,CorrectionFactor_ee_standardR,errX,errCorrectionFactor_ee_standardR);
 grCorrectionFactor_ee_standardR->SetTitle("Scale factor ee standardR");
 grCorrectionFactor_ee_standardR->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grCorrectionFactor_ee_standardR->GetYaxis()->SetTitle("Scale ee");
 grCorrectionFactor_ee_standardR->SetMarkerColor(kBlue);
 grCorrectionFactor_ee_standardR->SetFillColor(kWhite);
 grCorrectionFactor_ee_standardR->SetLineColor(kBlue);
 grCorrectionFactor_ee_standardR->SetMarkerStyle(20);
 grCorrectionFactor_ee_standardR->SetMarkerSize(1);
 grCorrectionFactor_ee_standardR->SetLineWidth(2);
 grCorrectionFactor_ee_standardR->SetLineStyle(2);
 
 
 TGraphErrors* grCorrectionFactor_ee_R = new TGraphErrors(numPlot,X,CorrectionFactor_ee_R,errX,errCorrectionFactor_ee_R);
 grCorrectionFactor_ee_R->SetTitle("Scale factor ee R");
 grCorrectionFactor_ee_R->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grCorrectionFactor_ee_R->GetYaxis()->SetTitle("Scale ee");
 grCorrectionFactor_ee_R->SetMarkerColor(kBlue);
 grCorrectionFactor_ee_R->SetFillColor(kWhite);
 grCorrectionFactor_ee_R->SetLineColor(kBlue);
 grCorrectionFactor_ee_R->SetMarkerStyle(24);
 grCorrectionFactor_ee_R->SetMarkerSize(1);
 grCorrectionFactor_ee_R->SetLineWidth(2);
 grCorrectionFactor_ee_R->SetLineStyle(2);
 
 
 TMultiGraph* mgr_CorrectionFactor_ee = new TMultiGraph(); 
 mgr_CorrectionFactor_ee->Add(grCorrectionFactor_ee_standardR);
 mgr_CorrectionFactor_ee->Add(grCorrectionFactor_ee_R);
 mgr_CorrectionFactor_ee->Draw("AP");
 mgr_CorrectionFactor_ee->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_CorrectionFactor_ee->GetYaxis()->SetTitle("Scale ee");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 TCanvas* cCorrectionFactor_mumu = new TCanvas("cCorrectionFactor_mumu","cCorrectionFactor_mumu",800,800); 
 
 TGraphErrors* grCorrectionFactor_mumu_standardR = new TGraphErrors(numPlot,X,CorrectionFactor_mumu_standardR,errX,errCorrectionFactor_mumu_standardR);
 grCorrectionFactor_mumu_standardR->SetTitle("Scale factor #mu#mu standardR");
 grCorrectionFactor_mumu_standardR->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grCorrectionFactor_mumu_standardR->GetYaxis()->SetTitle("Scale #mu#mu");
 grCorrectionFactor_mumu_standardR->SetMarkerColor(kBlue);
 grCorrectionFactor_mumu_standardR->SetFillColor(kWhite);
 grCorrectionFactor_mumu_standardR->SetLineColor(kBlue);
 grCorrectionFactor_mumu_standardR->SetMarkerStyle(20);
 grCorrectionFactor_mumu_standardR->SetMarkerSize(1);
 grCorrectionFactor_mumu_standardR->SetLineWidth(2);
 grCorrectionFactor_mumu_standardR->SetLineStyle(2);
 
 
 TGraphErrors* grCorrectionFactor_mumu_R = new TGraphErrors(numPlot,X,CorrectionFactor_mumu_R,errX,errCorrectionFactor_mumu_R);
 grCorrectionFactor_mumu_R->SetTitle("Scale factor #mu#mu R");
 grCorrectionFactor_mumu_R->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 grCorrectionFactor_mumu_R->GetYaxis()->SetTitle("Scale #mu#mu");
 grCorrectionFactor_mumu_R->SetMarkerColor(kBlue);
 grCorrectionFactor_mumu_R->SetFillColor(kWhite);
 grCorrectionFactor_mumu_R->SetLineColor(kBlue);
 grCorrectionFactor_mumu_R->SetMarkerStyle(24);
 grCorrectionFactor_mumu_R->SetMarkerSize(1);
 grCorrectionFactor_mumu_R->SetLineWidth(2);
 grCorrectionFactor_mumu_R->SetLineStyle(2);
 
 
 
 TMultiGraph* mgr_CorrectionFactor_mumu = new TMultiGraph(); 
 mgr_CorrectionFactor_mumu->Add(grCorrectionFactor_mumu_standardR);
 mgr_CorrectionFactor_mumu->Add(grCorrectionFactor_mumu_R);
 mgr_CorrectionFactor_mumu->Draw("AP");
 mgr_CorrectionFactor_mumu->GetXaxis()->SetTitle("met in bin (GeV)");  // ("met > threshold (GeV)");
 mgr_CorrectionFactor_mumu->GetYaxis()->SetTitle("Scale #mu#mu");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
}


