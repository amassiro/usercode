// r00t test/Latinos/DYRinout/GetDYRinout.cxx\(\"out_test_Latinos_26July2011_1100.root\"\)

void CompareRinoutM(TString nameRootFile){
 
 TFile* fileIn = new TFile(nameRootFile,"READ");
 
 gStyle->SetTitleX(0.2f);
 gStyle->SetTitleW(0.5f);
 
//  int numPointForRCalculation = 3;
 int numPointForRCalculation = 0;
//  int numPointForDYCalculation = 21;
//  int numPointForDYCalculation = 1;
 
 int numPlot = 23;
//  int numPlot = 23;
 
 int num = 23;
 double X[100] =    {0, 1, 5, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 35, 36, 37, 38, 39, 40, 45 };
 double errX[100] = {0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 , 0 , 0 , 0  };  
 double XShift[100] =    {0.2, 1.2.2, 5.2, 10.2, 12.2, 14.2, 16.2, 18.2, 20.2, 22.2, 24.2, 26.2, 28.2, 30.2, 32.2, 34.2, 35.2, 36.2, 37.2, 38.2, 39.2, 40.2, 45 };
 

 int numPointForMCalculation; // = 22;
 int numPlotM = 26;
 int numM = 26;
 double XM[100] =    {0, 1, 5, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 35, 36, 37, 38, 39, 40, 45, 50, 55, 60 };
 double errXM[100] = {0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 , 0 , 0 , 0 , 0 ,  0,  0 };  
 double XMShift[100] =    {0.2, 1.2.2, 5.2, 10.2, 12.2, 14.2, 16.2, 18.2, 20.2, 22.2, 24.2, 26.2, 28.2, 30.2, 32.2, 34.2, 35.2, 36.2, 37.2, 38.2, 39.2, 40.2, 45.2, 50.2, 55.2, 60.2 };
 double errXMShift[100] = {0, 0 , 0 ,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 , 0 , 0 , 0 ,0 ,0 ,0  };  
 
//  double XM[100] =    {0, 10, 15, 20, 25, 30, 35, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55 };
//  double errXM[100] = {0, 0 , 0 ,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 , 0 , 0 , 0  };  
//  double XMShift[100] = {0.1, 10.1, 15.1, 20.1, 25.1, 30.1, 35.1, 40.1, 41.1, 42.1, 43.1, 44.1, 45.1, 46.1, 47.1, 48.1, 49.1, 50.1, 51.1, 52.1, 53.1, 54.1, 55.1 };
//  double errXMShift[100] = {0, 0 , 0 ,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 , 0 , 0 , 0  };  
 
 
 ///---- for M ----

 double DATA_meanMeeemuA[100];
 double DATA_meanMmumuemuA[100];
 double DATA_errmeanMeeemuA[100];
 double DATA_errmeanMmumuemuA[100];
 
 double DATA_meanMeeemuB[100];
 double DATA_meanMmumuemuB[100];
 double DATA_errmeanMeeemuB[100];
 double DATA_errmeanMmumuemuB[100];
 
 double DATA_MeeemuA[100];
 double DATA_MeemueA[100];
 double DATA_MmumuemuA[100];
 double DATA_MmumumueA[100];
 double DATA_errMeeemuA[100];
 double DATA_errMeemueA[100];
 double DATA_errMmumuemuA[100];
 double DATA_errMmumumueA[100];

 double DATA_MeeemuB[100];
 double DATA_MeemueB[100];
 double DATA_MmumuemuB[100];
 double DATA_MmumumueB[100];
 double DATA_errMeeemuB[100];
 double DATA_errMeemueB[100];
 double DATA_errMmumuemuB[100];
 double DATA_errMmumumueB[100];
 
 double DATA_MeeA[100];
 double DATA_MmueA[100];
 double DATA_MemuA[100];
 double DATA_MmumuA[100];
 double DATA_errMeeA[100];
 double DATA_errMmueA[100];
 double DATA_errMemuA[100];
 double DATA_errMmumuA[100];
 
 double DATA_MeeB[100];
 double DATA_MmueB[100];
 double DATA_MemuB[100];
 double DATA_MmumuB[100];
 double DATA_errMeeB[100];
 double DATA_errMmueB[100];
 double DATA_errMemuB[100];
 double DATA_errMmumuB[100];
 
 
 
 
 double other_meanMeeemuA[100];
 double other_meanMmumuemuA[100];
 double other_errmeanMeeemuA[100];
 double other_errmeanMmumuemuA[100];
 
 double other_meanMeeemuB[100];
 double other_meanMmumuemuB[100];
 double other_errmeanMeeemuB[100];
 double other_errmeanMmumuemuB[100];
 
 double other_MeeemuA[100];
 double other_MeemueA[100];
 double other_MmumuemuA[100];
 double other_MmumumueA[100];
 double other_errMeeemuA[100];
 double other_errMeemueA[100];
 double other_errMmumuemuA[100];
 double other_errMmumumueA[100];
 
 double other_MeeemuB[100];
 double other_MeemueB[100];
 double other_MmumuemuB[100];
 double other_MmumumueB[100];
 double other_errMeeemuB[100];
 double other_errMeemueB[100];
 double other_errMmumuemuB[100];
 double other_errMmumumueB[100];
 
 double other_MeeA[100];
 double other_MmueA[100];
 double other_MemuA[100];
 double other_MmumuA[100];
 double other_errMeeA[100];
 double other_errMmueA[100];
 double other_errMemuA[100];
 double other_errMmumuA[100];
 
 double other_MeeB[100];
 double other_MmueB[100];
 double other_MemuB[100];
 double other_MmumuB[100];
 double other_errMeeB[100];
 double other_errMmueB[100];
 double other_errMemuB[100];
 double other_errMmumuB[100];
 
 
 double DY_meanMeeemuA[100];
 double DY_meanMmumuemuA[100];
 double DY_errmeanMeeemuA[100];
 double DY_errmeanMmumuemuA[100];
 
 double DY_meanMeeemuB[100];
 double DY_meanMmumuemuB[100];
 double DY_errmeanMeeemuB[100];
 double DY_errmeanMmumuemuB[100];
 
 double DY_MeeemuA[100];
 double DY_MeemueA[100];
 double DY_MmumuemuA[100];
 double DY_MmumumueA[100];
 double DY_errMeeemuA[100];
 double DY_errMeemueA[100];
 double DY_errMmumuemuA[100];
 double DY_errMmumumueA[100];
 
 double DY_MeeemuB[100];
 double DY_MeemueB[100];
 double DY_MmumuemuB[100];
 double DY_MmumumueB[100];
 double DY_errMeeemuB[100];
 double DY_errMeemueB[100];
 double DY_errMmumuemuB[100];
 double DY_errMmumumueB[100];
 
 double DY_MeeA[100];
 double DY_MmueA[100];
 double DY_MemuA[100];
 double DY_MmumuA[100];
 double DY_errMeeA[100];
 double DY_errMmueA[100];
 double DY_errMemuA[100];
 double DY_errMmumuA[100];
 
 double DY_MeeB[100];
 double DY_MmueB[100];
 double DY_MemuB[100];
 double DY_MmumuB[100];
 double DY_errMeeB[100];
 double DY_errMmueB[100];
 double DY_errMemuB[100];
 double DY_errMmumuB[100];
 
 
 
 double all_meanMeeemuA[100];
 double all_meanMmumuemuA[100];
 double all_errmeanMeeemuA[100];
 double all_errmeanMmumuemuA[100];
 
 double all_meanMeeemuB[100];
 double all_meanMmumuemuB[100];
 double all_errmeanMeeemuB[100];
 double all_errmeanMmumuemuB[100];
 
 double all_MeeemuA[100];
 double all_MeemueA[100];
 double all_MmumuemuA[100];
 double all_MmumumueA[100];
 double all_errMeeemuA[100];
 double all_errMeemueA[100];
 double all_errMmumuemuA[100];
 double all_errMmumumueA[100];
 
 double all_MeeemuB[100];
 double all_MeemueB[100];
 double all_MmumuemuB[100];
 double all_MmumumueB[100];
 double all_errMeeemuB[100];
 double all_errMeemueB[100];
 double all_errMmumuemuB[100];
 double all_errMmumumueB[100];
 
 double all_MeeA[100];
 double all_MmueA[100];
 double all_MemuA[100];
 double all_MmumuA[100];
 double all_errMeeA[100];
 double all_errMmueA[100];
 double all_errMemuA[100];
 double all_errMmumuA[100];
 
 double all_MeeB[100];
 double all_MmueB[100];
 double all_MemuB[100];
 double all_MmumuB[100];
 
 double all_errMeeB[100];
 double all_errMmueB[100];
 double all_errMemuB[100];
 double all_errMmumuB[100];
 
 
 
 
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
 
 
 
 double DATA_NDY_M_A_mumu[100];
 double DATA_NDY_M_A_ee[100];
 double DATA_errNDY_M_A_mumu[100];
 double DATA_errNDY_M_A_ee[100];
 
 double DATA_NDYCorrected_M_A_mumu[100];
 double DATA_NDYCorrected_M_A_ee[100];
 double DATA_errNDYCorrected_M_A_mumu[100];
 double DATA_errNDYCorrected_M_A_ee[100];
 
 
  
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
 
 
 
 ///==== M ====
 
 for (int iCut = 0; iCut <numM; iCut++) {
  double eNum;
  double eDen;
  double eDen1;
  double eDen2;
  
  ///---- zone A (out) ----  
  nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",iCut+num*2);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",iCut+num*2);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",iCut+num*2);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",iCut+num*2);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  
  DATA_MeeA[iCut]   = h1->GetBinContent(2);
  DATA_MmumuA[iCut] = h2->GetBinContent(2);
  DATA_MemuA[iCut]  = h3->GetBinContent(2);
  DATA_MmueA[iCut]  = h4->GetBinContent(2);
  
  DATA_errMeeA[iCut]   = h1->GetBinError(2);
  DATA_errMmumuA[iCut] = h2->GetBinError(2);
  DATA_errMemuA[iCut]  = h3->GetBinError(2);
  DATA_errMmueA[iCut]  = h4->GetBinError(2);
  
  
  
  nameHistoInRootFile = Form("Data/DY_%d_0_Tot_temp",iCut+num*2);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_1_Tot_temp",iCut+num*2);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_2_Tot_temp",iCut+num*2);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_3_Tot_temp",iCut+num*2);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  
  DY_MeeA[iCut]   = h1->GetBinContent(2);
  DY_MmumuA[iCut] = h2->GetBinContent(2);
  DY_MemuA[iCut]  = h3->GetBinContent(2);
  DY_MmueA[iCut]  = h4->GetBinContent(2);
  
  DY_errMeeA[iCut]   = h1->GetBinError(2);
  DY_errMmumuA[iCut] = h2->GetBinError(2);
  DY_errMemuA[iCut]  = h3->GetBinError(2);
  DY_errMmueA[iCut]  = h4->GetBinError(2);
  
  
  
  nameHistoInRootFile = Form("Data/other_%d_0_Tot_temp",iCut+num*2);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_1_Tot_temp",iCut+num*2);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_2_Tot_temp",iCut+num*2);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_3_Tot_temp",iCut+num*2);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  
  other_MeeA[iCut]   = h1->GetBinContent(2);
  other_MmumuA[iCut] = h2->GetBinContent(2);
  other_MemuA[iCut]  = h3->GetBinContent(2);
  other_MmueA[iCut]  = h4->GetBinContent(2);
  
  other_errMeeA[iCut]   = h1->GetBinError(2);
  other_errMmumuA[iCut] = h2->GetBinError(2);
  other_errMemuA[iCut]  = h3->GetBinError(2);
  other_errMmueA[iCut]  = h4->GetBinError(2);
  
  
  
  all_MeeA[iCut]   = other_MeeA[iCut]   + DY_MeeA[iCut];
  all_MmumuA[iCut] = other_MmumuA[iCut] + DY_MmumuA[iCut];
  all_MemuA[iCut]  = other_MemuA[iCut]  + DY_MemuA[iCut];
  all_MmueA[iCut]  = other_MmueA[iCut]  + DY_MmueA[iCut];
  
  all_errMeeA[iCut]   = sqrt(other_errMeeA[iCut]*other_errMeeA[iCut] + DY_errMeeA[iCut]*DY_errMeeA[iCut]);
  all_errMmumuA[iCut] = sqrt(other_errMmumuA[iCut]*other_errMmumuA[iCut] + DY_errMmumuA[iCut]*DY_errMmumuA[iCut]);
  all_errMemuA[iCut]  = sqrt(other_errMemuA[iCut]*other_errMemuA[iCut] + DY_errMemuA[iCut]*DY_errMemuA[iCut]);
  all_errMmueA[iCut]  = sqrt(other_errMmueA[iCut]*other_errMmueA[iCut] + DY_errMmueA[iCut]*DY_errMmueA[iCut]);
  
  
  
  ///==== Mllll ====

  DATA_MeeemuA[iCut]   = DATA_MeeA[iCut]   / DATA_MemuA[iCut];
  DATA_MeemueA[iCut]   = DATA_MeeA[iCut]   / DATA_MmueA[iCut];
  DATA_MmumuemuA[iCut] = DATA_MmumuA[iCut] / DATA_MemuA[iCut];
  DATA_MmumumueA[iCut] = DATA_MmumuA[iCut] / DATA_MmueA[iCut];
  
  eNum = DATA_errMeeA[iCut] / DATA_MemuA[iCut];
  eDen = DATA_errMemuA[iCut] / DATA_MemuA[iCut] * DATA_MeeA[iCut] / DATA_MemuA[iCut];
  DATA_errMeeemuA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DATA_errMeeA[iCut] / DATA_MmueA[iCut];
  eDen = DATA_errMmueA[iCut] / DATA_MmueA[iCut] * DATA_MeeA[iCut] / DATA_MmueA[iCut];
  DATA_errMeemueA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DATA_errMmumuA[iCut] / DATA_MemuA[iCut];
  eDen = DATA_errMemuA[iCut] / DATA_MemuA[iCut] * DATA_MmumuA[iCut] / DATA_MemuA[iCut];
  DATA_errMmumuemuA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DATA_errMmumuA[iCut] / DATA_MmueA[iCut];
  eDen = DATA_errMmueA[iCut] / DATA_MmueA[iCut] * DATA_MmumuA[iCut] / DATA_MmueA[iCut];
  DATA_errMmumumueA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  
  DATA_meanMeeemuA[iCut]   = DATA_MeeA[iCut]   / (DATA_MemuA[iCut] + DATA_MmueA[iCut]);
  DATA_meanMmumuemuA[iCut] = DATA_MmumuA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]);
  
  eNum = DATA_errMeeA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]);
  eDen1 = DATA_errMemuA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]) * DATA_MeeA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]) ;
  eDen2 = DATA_errMmueA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]) * DATA_MeeA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]) ;
  DATA_errmeanMeeemuA[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  eNum = DATA_errMmumuA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]);
  eDen1 = DATA_errMemuA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]) * DATA_MmumuA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]);
  eDen2 = DATA_errMmueA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]) * DATA_MmumuA[iCut] / (DATA_MemuA[iCut] + DATA_MmueA[iCut]);
  DATA_errmeanMmumuemuA[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  
  
  
  DY_MeeemuA[iCut]   = DY_MeeA[iCut]   / DY_MemuA[iCut];
  DY_MeemueA[iCut]   = DY_MeeA[iCut]   / DY_MmueA[iCut];
  DY_MmumuemuA[iCut] = DY_MmumuA[iCut] / DY_MemuA[iCut];
  DY_MmumumueA[iCut] = DY_MmumuA[iCut] / DY_MmueA[iCut];
  
  eNum = DY_errMeeA[iCut] / DY_MemuA[iCut];
  eDen = DY_errMemuA[iCut] / DY_MemuA[iCut] * DY_MeeA[iCut] / DY_MemuA[iCut];
  DY_errMeeemuA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DY_errMeeA[iCut] / DY_MmueA[iCut];
  eDen = DY_errMmueA[iCut] / DY_MmueA[iCut] * DY_MeeA[iCut] / DY_MmueA[iCut];
  DY_errMeemueA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DY_errMmumuA[iCut] / DY_MemuA[iCut];
  eDen = DY_errMemuA[iCut] / DY_MemuA[iCut] * DY_MmumuA[iCut] / DY_MemuA[iCut];
  DY_errMmumuemuA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DY_errMmumuA[iCut] / DY_MmueA[iCut];
  eDen = DY_errMmueA[iCut] / DY_MmueA[iCut] * DY_MmumuA[iCut] / DY_MmueA[iCut];
  DY_errMmumumueA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  
  DY_meanMeeemuA[iCut]   = DY_MeeA[iCut]   / (DY_MemuA[iCut] + DY_MmueA[iCut]);
  DY_meanMmumuemuA[iCut] = DY_MmumuA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]);
  
  eNum = DY_errMeeA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]);
  eDen1 = DY_errMemuA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]) * DY_MeeA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]) ;
  eDen2 = DY_errMmueA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]) * DY_MeeA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]) ;
  DY_errmeanMeeemuA[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  eNum = DY_errMmumuA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]);
  eDen1 = DY_errMemuA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]) * DY_MmumuA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]);
  eDen2 = DY_errMmueA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]) * DY_MmumuA[iCut] / (DY_MemuA[iCut] + DY_MmueA[iCut]);
  DY_errmeanMmumuemuA[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  
  
  
  
  other_MeeemuA[iCut]   = other_MeeA[iCut]   / other_MemuA[iCut];
  other_MeemueA[iCut]   = other_MeeA[iCut]   / other_MmueA[iCut];
  other_MmumuemuA[iCut] = other_MmumuA[iCut] / other_MemuA[iCut];
  other_MmumumueA[iCut] = other_MmumuA[iCut] / other_MmueA[iCut];
  
  eNum = other_errMeeA[iCut] / other_MemuA[iCut];
  eDen = other_errMemuA[iCut] / other_MemuA[iCut] * other_MeeA[iCut] / other_MemuA[iCut];
  other_errMeeemuA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = other_errMeeA[iCut] / other_MmueA[iCut];
  eDen = other_errMmueA[iCut] / other_MmueA[iCut] * other_MeeA[iCut] / other_MmueA[iCut];
  other_errMeemueA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = other_errMmumuA[iCut] / other_MemuA[iCut];
  eDen = other_errMemuA[iCut] / other_MemuA[iCut] * other_MmumuA[iCut] / other_MemuA[iCut];
  other_errMmumuemuA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = other_errMmumuA[iCut] / other_MmueA[iCut];
  eDen = other_errMmueA[iCut] / other_MmueA[iCut] * other_MmumuA[iCut] / other_MmueA[iCut];
  other_errMmumumueA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  
  
  other_meanMeeemuA[iCut]   = other_MeeA[iCut]   / (other_MemuA[iCut] + other_MmueA[iCut]);
  other_meanMmumuemuA[iCut] = other_MmumuA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]);
  
  eNum = other_errMeeA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]);
  eDen1 = other_errMemuA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]) * other_MeeA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]) ;
  eDen2 = other_errMmueA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]) * other_MeeA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]) ;
  other_errmeanMeeemuA[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  eNum = other_errMmumuA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]);
  eDen1 = other_errMemuA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]) * other_MmumuA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]);
  eDen2 = other_errMmueA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]) * other_MmumuA[iCut] / (other_MemuA[iCut] + other_MmueA[iCut]);
  other_errmeanMmumuemuA[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  
  
  
  all_MeeemuA[iCut]   = all_MeeA[iCut]   / all_MemuA[iCut];
  all_MeemueA[iCut]   = all_MeeA[iCut]   / all_MmueA[iCut];
  all_MmumuemuA[iCut] = all_MmumuA[iCut] / all_MemuA[iCut];
  all_MmumumueA[iCut] = all_MmumuA[iCut] / all_MmueA[iCut];
  
  eNum = all_errMeeA[iCut] / all_MemuA[iCut];
  eDen = all_errMemuA[iCut] / all_MemuA[iCut] * all_MeeA[iCut] / all_MemuA[iCut];
  all_errMeeemuA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = all_errMeeA[iCut] / all_MmueA[iCut];
  eDen = all_errMmueA[iCut] / all_MmueA[iCut] * all_MeeA[iCut] / all_MmueA[iCut];
  all_errMeemueA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = all_errMmumuA[iCut] / all_MemuA[iCut];
  eDen = all_errMemuA[iCut] / all_MemuA[iCut] * all_MmumuA[iCut] / all_MemuA[iCut];
  all_errMmumuemuA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = all_errMmumuA[iCut] / all_MmueA[iCut];
  eDen = all_errMmueA[iCut] / all_MmueA[iCut] * all_MmumuA[iCut] / all_MmueA[iCut];
  all_errMmumumueA[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  
  
  all_meanMeeemuA[iCut]   = all_MeeA[iCut]   / (all_MemuA[iCut] + all_MmueA[iCut]);
  all_meanMmumuemuA[iCut] = all_MmumuA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]);
  
  eNum = all_errMeeA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]);
  eDen1 = all_errMemuA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]) * all_MeeA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]) ;
  eDen2 = all_errMmueA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]) * all_MeeA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]) ;
  all_errmeanMeeemuA[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  eNum = all_errMmumuA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]);
  eDen1 = all_errMemuA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]) * all_MmumuA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]);
  eDen2 = all_errMmueA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]) * all_MmumuA[iCut] / (all_MemuA[iCut] + all_MmueA[iCut]);
  all_errmeanMmumuemuA[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  
  
  
   ///---- zone B (in) ----  
  nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",iCut+numM+num*2);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",iCut+numM+num*2);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",iCut+numM+num*2);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",iCut+numM+num*2);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  
  DATA_MeeB[iCut]   = h1->GetBinContent(2);
  DATA_MmumuB[iCut] = h2->GetBinContent(2);
  DATA_MemuB[iCut]  = h3->GetBinContent(2);
  DATA_MmueB[iCut]  = h4->GetBinContent(2);
  
  DATA_errMeeB[iCut]   = h1->GetBinError(2);
  DATA_errMmumuB[iCut] = h2->GetBinError(2);
  DATA_errMemuB[iCut]  = h3->GetBinError(2);
  DATA_errMmueB[iCut]  = h4->GetBinError(2);
  
  
  
  nameHistoInRootFile = Form("Data/DY_%d_0_Tot_temp",iCut+numM+num*2);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_1_Tot_temp",iCut+numM+num*2);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_2_Tot_temp",iCut+numM+num*2);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/DY_%d_3_Tot_temp",iCut+numM+num*2);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  
  DY_MeeB[iCut]   = h1->GetBinContent(2);
  DY_MmumuB[iCut] = h2->GetBinContent(2);
  DY_MemuB[iCut]  = h3->GetBinContent(2);
  DY_MmueB[iCut]  = h4->GetBinContent(2);
  
  DY_errMeeB[iCut]   = h1->GetBinError(2);
  DY_errMmumuB[iCut] = h2->GetBinError(2);
  DY_errMemuB[iCut]  = h3->GetBinError(2);
  DY_errMmueB[iCut]  = h4->GetBinError(2);
  
  
  
  nameHistoInRootFile = Form("Data/other_%d_0_Tot_temp",iCut+numM+num*2);  
  h1 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_1_Tot_temp",iCut+numM+num*2);  
  h2 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_2_Tot_temp",iCut+numM+num*2);  
  h3 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  nameHistoInRootFile = Form("Data/other_%d_3_Tot_temp",iCut+numM+num*2);  
  h4 = (TH1F*) fileIn->Get(nameHistoInRootFile);  
  
  
  other_MeeB[iCut]   = h1->GetBinContent(2);
  other_MmumuB[iCut] = h2->GetBinContent(2);
  other_MemuB[iCut]  = h3->GetBinContent(2);
  other_MmueB[iCut]  = h4->GetBinContent(2);
  
  other_errMeeB[iCut]   = h1->GetBinError(2);
  other_errMmumuB[iCut] = h2->GetBinError(2);
  other_errMemuB[iCut]  = h3->GetBinError(2);
  other_errMmueB[iCut]  = h4->GetBinError(2);
  
  
  
  all_MeeB[iCut]   = other_MeeB[iCut]   + DY_MeeB[iCut];
  all_MmumuB[iCut] = other_MmumuB[iCut] + DY_MmumuB[iCut];
  all_MemuB[iCut]  = other_MemuB[iCut]  + DY_MemuB[iCut];
  all_MmueB[iCut]  = other_MmueB[iCut]  + DY_MmueB[iCut];
  
  all_errMeeB[iCut]   = sqrt(other_errMeeB[iCut]*other_errMeeB[iCut] + DY_errMeeB[iCut]*DY_errMeeB[iCut]);
  all_errMmumuB[iCut] = sqrt(other_errMmumuB[iCut]*other_errMmumuB[iCut] + DY_errMmumuB[iCut]*DY_errMmumuB[iCut]);
  all_errMemuB[iCut]  = sqrt(other_errMemuB[iCut]*other_errMemuB[iCut] + DY_errMemuB[iCut]*DY_errMemuB[iCut]);
  all_errMmueB[iCut]  = sqrt(other_errMmueB[iCut]*other_errMmueB[iCut] + DY_errMmueB[iCut]*DY_errMmueB[iCut]);
  
  
  
  ///==== Mllll ====

  DATA_MeeemuB[iCut]   = DATA_MeeB[iCut]   / DATA_MemuB[iCut];
  DATA_MeemueB[iCut]   = DATA_MeeB[iCut]   / DATA_MmueB[iCut];
  DATA_MmumuemuB[iCut] = DATA_MmumuB[iCut] / DATA_MemuB[iCut];
  DATA_MmumumueB[iCut] = DATA_MmumuB[iCut] / DATA_MmueB[iCut];
  
  eNum = DATA_errMeeB[iCut] / DATA_MemuB[iCut];
  eDen = DATA_errMemuB[iCut] / DATA_MemuB[iCut] * DATA_MeeB[iCut] / DATA_MemuB[iCut];
  DATA_errMeeemuB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DATA_errMeeB[iCut] / DATA_MmueB[iCut];
  eDen = DATA_errMmueB[iCut] / DATA_MmueB[iCut] * DATA_MeeB[iCut] / DATA_MmueB[iCut];
  DATA_errMeemueB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DATA_errMmumuB[iCut] / DATA_MemuB[iCut];
  eDen = DATA_errMemuB[iCut] / DATA_MemuB[iCut] * DATA_MmumuB[iCut] / DATA_MemuB[iCut];
  DATA_errMmumuemuB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DATA_errMmumuB[iCut] / DATA_MmueB[iCut];
  eDen = DATA_errMmueB[iCut] / DATA_MmueB[iCut] * DATA_MmumuB[iCut] / DATA_MmueB[iCut];
  DATA_errMmumumueB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  
  
  DATA_meanMeeemuB[iCut]   = DATA_MeeB[iCut]   / (DATA_MemuB[iCut] + DATA_MmueB[iCut]);
  DATA_meanMmumuemuB[iCut] = DATA_MmumuB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]);
  
  eNum = DATA_errMeeB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]);
  eDen1 = DATA_errMemuB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]) * DATA_MeeB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]) ;
  eDen2 = DATA_errMmueB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]) * DATA_MeeB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]) ;
  DATA_errmeanMeeemuB[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  eNum = DATA_errMmumuB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]);
  eDen1 = DATA_errMemuB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]) * DATA_MmumuB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]);
  eDen2 = DATA_errMmueB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]) * DATA_MmumuB[iCut] / (DATA_MemuB[iCut] + DATA_MmueB[iCut]);
  DATA_errmeanMmumuemuB[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  
  
  
  
  
  DY_MeeemuB[iCut]   = DY_MeeB[iCut]   / DY_MemuB[iCut];
  DY_MeemueB[iCut]   = DY_MeeB[iCut]   / DY_MmueB[iCut];
  DY_MmumuemuB[iCut] = DY_MmumuB[iCut] / DY_MemuB[iCut];
  DY_MmumumueB[iCut] = DY_MmumuB[iCut] / DY_MmueB[iCut];
  
  eNum = DY_errMeeB[iCut] / DY_MemuB[iCut];
  eDen = DY_errMemuB[iCut] / DY_MemuB[iCut] * DY_MeeB[iCut] / DY_MemuB[iCut];
  DY_errMeeemuB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DY_errMeeB[iCut] / DY_MmueB[iCut];
  eDen = DY_errMmueB[iCut] / DY_MmueB[iCut] * DY_MeeB[iCut] / DY_MmueB[iCut];
  DY_errMeemueB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DY_errMmumuB[iCut] / DY_MemuB[iCut];
  eDen = DY_errMemuB[iCut] / DY_MemuB[iCut] * DY_MmumuB[iCut] / DY_MemuB[iCut];
  DY_errMmumuemuB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = DY_errMmumuB[iCut] / DY_MmueB[iCut];
  eDen = DY_errMmueB[iCut] / DY_MmueB[iCut] * DY_MmumuB[iCut] / DY_MmueB[iCut];
  DY_errMmumumueB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  
  DY_meanMeeemuB[iCut]   = DY_MeeB[iCut]   / (DY_MemuB[iCut] + DY_MmueB[iCut]);
  DY_meanMmumuemuB[iCut] = DY_MmumuB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]);
  
  eNum = DY_errMeeB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]);
  eDen1 = DY_errMemuB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]) * DY_MeeB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]) ;
  eDen2 = DY_errMmueB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]) * DY_MeeB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]) ;
  DY_errmeanMeeemuB[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  eNum = DY_errMmumuB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]);
  eDen1 = DY_errMemuB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]) * DY_MmumuB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]);
  eDen2 = DY_errMmueB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]) * DY_MmumuB[iCut] / (DY_MemuB[iCut] + DY_MmueB[iCut]);
  DY_errmeanMmumuemuB[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  
  
  other_MeeemuB[iCut]   = other_MeeB[iCut]   / other_MemuB[iCut];
  other_MeemueB[iCut]   = other_MeeB[iCut]   / other_MmueB[iCut];
  other_MmumuemuB[iCut] = other_MmumuB[iCut] / other_MemuB[iCut];
  other_MmumumueB[iCut] = other_MmumuB[iCut] / other_MmueB[iCut];
  
  eNum = other_errMeeB[iCut] / other_MemuB[iCut];
  eDen = other_errMemuB[iCut] / other_MemuB[iCut] * other_MeeB[iCut] / other_MemuB[iCut];
  other_errMeeemuB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = other_errMeeB[iCut] / other_MmueB[iCut];
  eDen = other_errMmueB[iCut] / other_MmueB[iCut] * other_MeeB[iCut] / other_MmueB[iCut];
  other_errMeemueB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = other_errMmumuB[iCut] / other_MemuB[iCut];
  eDen = other_errMemuB[iCut] / other_MemuB[iCut] * other_MmumuB[iCut] / other_MemuB[iCut];
  other_errMmumuemuB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = other_errMmumuB[iCut] / other_MmueB[iCut];
  eDen = other_errMmueB[iCut] / other_MmueB[iCut] * other_MmumuB[iCut] / other_MmueB[iCut];
  other_errMmumumueB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  
  other_meanMeeemuB[iCut]   = other_MeeB[iCut]   / (other_MemuB[iCut] + other_MmueB[iCut]);
  other_meanMmumuemuB[iCut] = other_MmumuB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]);
  
  eNum = other_errMeeB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]);
  eDen1 = other_errMemuB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]) * other_MeeB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]) ;
  eDen2 = other_errMmueB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]) * other_MeeB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]) ;
  other_errmeanMeeemuB[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  eNum = other_errMmumuB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]);
  eDen1 = other_errMemuB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]) * other_MmumuB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]);
  eDen2 = other_errMmueB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]) * other_MmumuB[iCut] / (other_MemuB[iCut] + other_MmueB[iCut]);
  other_errmeanMmumuemuB[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  
  
  all_MeeemuB[iCut]   = all_MeeB[iCut]   / all_MemuB[iCut];
  all_MeemueB[iCut]   = all_MeeB[iCut]   / all_MmueB[iCut];
  all_MmumuemuB[iCut] = all_MmumuB[iCut] / all_MemuB[iCut];
  all_MmumumueB[iCut] = all_MmumuB[iCut] / all_MmueB[iCut];
  
  
  eNum = all_errMeeB[iCut] / all_MemuB[iCut];
  eDen = all_errMemuB[iCut] / all_MemuB[iCut] * all_MeeB[iCut] / all_MemuB[iCut];
  all_errMeeemuB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = all_errMeeB[iCut] / all_MmueB[iCut];
  eDen = all_errMmueB[iCut] / all_MmueB[iCut] * all_MeeB[iCut] / all_MmueB[iCut];
  all_errMeemueB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = all_errMmumuB[iCut] / all_MemuB[iCut];
  eDen = all_errMemuB[iCut] / all_MemuB[iCut] * all_MmumuB[iCut] / all_MemuB[iCut];
  all_errMmumuemuB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  eNum = all_errMmumuB[iCut] / all_MmueB[iCut];
  eDen = all_errMmueB[iCut] / all_MmueB[iCut] * all_MmumuB[iCut] / all_MmueB[iCut];
  all_errMmumumueB[iCut]   = sqrt(eNum*eNum + eDen*eDen);
  
  all_meanMeeemuB[iCut]   = all_MeeB[iCut]   / (all_MemuB[iCut] + all_MmueB[iCut]);
  all_meanMmumuemuB[iCut] = all_MmumuB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]);
  
  eNum = all_errMeeB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]);
  eDen1 = all_errMemuB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]) * all_MeeB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]) ;
  eDen2 = all_errMmueB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]) * all_MeeB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]) ;
  all_errmeanMeeemuB[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  eNum = all_errMmumuB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]);
  eDen1 = all_errMemuB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]) * all_MmumuB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]);
  eDen2 = all_errMmueB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]) * all_MmumuB[iCut] / (all_MemuB[iCut] + all_MmueB[iCut]);
  all_errmeanMmumuemuB[iCut]   = sqrt(eNum*eNum + eDen1*eDen1 + eDen2*eDen2);
  
  
  
  
  
  
  
  
  
  
  numPointForMCalculation = iCut;
  
  
  
  
   ///==== Results: NDY_M_A_ee_extrapolated = (NeeA - MeeemuA'* NemuA)      with M calculated with top enriched sample 
  
  DATA_NDY_M_A_ee[iCut]     = DATA_NeeA[iCut] - (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * DATA_meanMeeemuA[numPointForMCalculation]; 
  DATA_errNDY_M_A_ee[iCut]  = sqrt (DATA_errNeeA[iCut] * DATA_errNeeA[iCut] + DATA_errNemuA[iCut] * DATA_errNemuA[iCut] * DATA_meanMeeemuA[numPointForMCalculation] * DATA_meanMeeemuA[numPointForMCalculation] + DATA_errNmueA[iCut] * DATA_errNmueA[iCut] * DATA_meanMeeemuA[numPointForMCalculation] * DATA_meanMeeemuA[numPointForMCalculation] + DATA_errMeeemuA[numPointForMCalculation] * DATA_errMeeemuA[numPointForMCalculation] * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * (DATA_NemuA[iCut] + DATA_NmueA[iCut]));
   
  DATA_NDYCorrected_M_A_ee[iCut]  = all_NeeA[iCut] - DY_NeeA[iCut] + DATA_NDY_M_A_ee[iCut];
  DATA_errNDYCorrected_M_A_ee[iCut] = sqrt(all_errNeeA[iCut]*all_errNeeA[iCut] + DY_errNeeA[iCut]*DY_errNeeA[iCut] + DATA_errNDY_M_A_ee[iCut]*DATA_errNDY_M_A_ee[iCut]);
  
  ///==== Results: NDY_M_A_mumu_extrapolated = (NmumuA - MmumuemuA'* NemuA)      with M calculated with top enriched sample 
  
  DATA_NDY_M_A_mumu[iCut]     = DATA_NmumuA[iCut] - (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * DATA_meanMmumuemuA[numPointForMCalculation]; 
  DATA_errNDY_M_A_mumu[iCut]  = sqrt (DATA_errNmumuA[iCut] * DATA_errNmumuA[iCut] + DATA_errNemuA[iCut] * DATA_errNemuA[iCut] * DATA_meanMmumuemuA[numPointForMCalculation] * DATA_meanMmumuemuA[numPointForMCalculation] + DATA_errNmueA[iCut] * DATA_errNmueA[iCut] * DATA_meanMmumuemuA[numPointForMCalculation] * DATA_meanMmumuemuA[numPointForMCalculation] + DATA_errMmumuemuA[numPointForMCalculation] * DATA_errMmumuemuA[numPointForMCalculation] * (DATA_NemuA[iCut] + DATA_NmueA[iCut]) * (DATA_NemuA[iCut] + DATA_NmueA[iCut]));
   
  DATA_NDYCorrected_M_A_mumu[iCut]  = all_NmumuA[iCut] - DY_NmumuA[iCut] + DATA_NDY_M_A_mumu[iCut];
  DATA_errNDYCorrected_M_A_mumu[iCut] = sqrt(all_errNmumuA[iCut]*all_errNmumuA[iCut] + DY_errNmumuA[iCut]*DY_errNmumuA[iCut] + DATA_errNDY_M_A_mumu[iCut]*DATA_errNDY_M_A_mumu[iCut]);
 
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
 grDATA_NmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NmumuA->GetYaxis()->SetTitle("N #mu#mu");
 grDATA_NmumuA->SetMarkerColor(kBlack);
 grDATA_NmumuA->SetFillColor(kWhite);
 grDATA_NmumuA->SetLineColor(kBlack);
 grDATA_NmumuA->SetMarkerStyle(20);
 grDATA_NmumuA->SetMarkerSize(1.5);
 grDATA_NmumuA->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NmumuA = new TGraphErrors(numPlot,X,DYmad_NmumuA,errX,DYmad_errNmumuA);
 grDYmad_NmumuA->SetTitle("N #mu#mu DYmad A");
 grDYmad_NmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_NmumuA->GetYaxis()->SetTitle("N #mu#mu");
 grDYmad_NmumuA->SetMarkerColor(kGreen);
 grDYmad_NmumuA->SetFillColor(kWhite);
 grDYmad_NmumuA->SetLineColor(kGreen);
 grDYmad_NmumuA->SetMarkerStyle(28);
 grDYmad_NmumuA->SetMarkerSize(1);
 grDYmad_NmumuA->SetLineWidth(2);
 
 TGraphErrors* grDY_NmumuA = new TGraphErrors(numPlot,X,DY_NmumuA,errX,DY_errNmumuA);
 grDY_NmumuA->SetTitle("N #mu#mu DY A");
 grDY_NmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_NmumuA->GetYaxis()->SetTitle("N #mu#mu");
 grDY_NmumuA->SetMarkerColor(kBlue);
 grDY_NmumuA->SetFillColor(kWhite);
 grDY_NmumuA->SetLineColor(kBlue);
 grDY_NmumuA->SetMarkerStyle(21);
 grDY_NmumuA->SetMarkerSize(1);
 grDY_NmumuA->SetLineWidth(2);
 
 TGraphErrors* grother_NmumuA = new TGraphErrors(numPlot,X,other_NmumuA,errX,other_errNmumuA);
 grother_NmumuA->SetTitle("N #mu#mu other A");
 grother_NmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NmumuA->GetYaxis()->SetTitle("N #mu#mu");
 grother_NmumuA->SetMarkerColor(kGreen);
 grother_NmumuA->SetFillColor(kWhite);
 grother_NmumuA->SetLineColor(kGreen);
 grother_NmumuA->SetMarkerStyle(21);
 grother_NmumuA->SetMarkerSize(1);
 grother_NmumuA->SetLineWidth(2);
 
 TGraphErrors* grall_NmumuA = new TGraphErrors(numPlot,X,all_NmumuA,errX,all_errNmumuA);
 grall_NmumuA->SetTitle("N #mu#mu all A");
 grall_NmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 mgr_NmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_NmumuA->GetYaxis()->SetTitle("N #mu#mu A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== ee ====
 TCanvas* cNeeA = new TCanvas("cNeeA","cNeeA",800,800); 
 
 TGraphErrors* grDATA_NeeA = new TGraphErrors(numPlot,X,DATA_NeeA,errX,DATA_errNeeA);
 grDATA_NeeA->SetTitle("N ee DATA A");
 grDATA_NeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NeeA->GetYaxis()->SetTitle("N ee");
 grDATA_NeeA->SetMarkerColor(kBlack);
 grDATA_NeeA->SetFillColor(kWhite);
 grDATA_NeeA->SetLineColor(kBlack);
 grDATA_NeeA->SetMarkerStyle(20);
 grDATA_NeeA->SetMarkerSize(1.5);
 grDATA_NeeA->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NeeA = new TGraphErrors(numPlot,X,DYmad_NeeA,errX,DYmad_errNeeA);
 grDYmad_NeeA->SetTitle("N ee DYmad A");
 grDYmad_NeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_NeeA->GetYaxis()->SetTitle("N ee");
 grDYmad_NeeA->SetMarkerColor(kGreen);
 grDYmad_NeeA->SetFillColor(kWhite);
 grDYmad_NeeA->SetLineColor(kGreen);
 grDYmad_NeeA->SetMarkerStyle(28);
 grDYmad_NeeA->SetMarkerSize(1);
 grDYmad_NeeA->SetLineWidth(2);
 
 TGraphErrors* grDY_NeeA = new TGraphErrors(numPlot,X,DY_NeeA,errX,DY_errNeeA);
 grDY_NeeA->SetTitle("N ee DY A");
 grDY_NeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_NeeA->GetYaxis()->SetTitle("N ee");
 grDY_NeeA->SetMarkerColor(kBlue);
 grDY_NeeA->SetFillColor(kWhite);
 grDY_NeeA->SetLineColor(kBlue);
 grDY_NeeA->SetMarkerStyle(21);
 grDY_NeeA->SetMarkerSize(1);
 grDY_NeeA->SetLineWidth(2);
 
 TGraphErrors* grother_NeeA = new TGraphErrors(numPlot,X,other_NeeA,errX,other_errNeeA);
 grother_NeeA->SetTitle("N ee other A");
 grother_NeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NeeA->GetYaxis()->SetTitle("N ee");
 grother_NeeA->SetMarkerColor(kGreen);
 grother_NeeA->SetFillColor(kWhite);
 grother_NeeA->SetLineColor(kGreen);
 grother_NeeA->SetMarkerStyle(21);
 grother_NeeA->SetMarkerSize(1);
 grother_NeeA->SetLineWidth(2);
 
 TGraphErrors* grall_NeeA = new TGraphErrors(numPlot,X,all_NeeA,errX,all_errNeeA);
 grall_NeeA->SetTitle("N ee all A");
 grall_NeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 mgr_NeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_NeeA->GetYaxis()->SetTitle("N ee A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== emu ====
 TCanvas* cNemuA = new TCanvas("cNemuA","cNemuA",800,800); 
 
 TGraphErrors* grDATA_NemuA = new TGraphErrors(numPlot,X,DATA_NemuA,errX,DATA_errNemuA);
 grDATA_NemuA->SetTitle("N e#mu DATA A");
 grDATA_NemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NemuA->GetYaxis()->SetTitle("N e#mu");
 grDATA_NemuA->SetMarkerColor(kBlack);
 grDATA_NemuA->SetFillColor(kWhite);
 grDATA_NemuA->SetLineColor(kBlack);
 grDATA_NemuA->SetMarkerStyle(20);
 grDATA_NemuA->SetMarkerSize(1.5);
 grDATA_NemuA->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NemuA = new TGraphErrors(numPlot,X,DYmad_NemuA,errX,DYmad_errNemuA);
 grDYmad_NemuA->SetTitle("N e#mu DYmad A");
 grDYmad_NemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_NemuA->GetYaxis()->SetTitle("N e#mu");
 grDYmad_NemuA->SetMarkerColor(kGreen);
 grDYmad_NemuA->SetFillColor(kWhite);
 grDYmad_NemuA->SetLineColor(kGreen);
 grDYmad_NemuA->SetMarkerStyle(28);
 grDYmad_NemuA->SetMarkerSize(1);
 grDYmad_NemuA->SetLineWidth(2);
 
 TGraphErrors* grDY_NemuA = new TGraphErrors(numPlot,X,DY_NemuA,errX,DY_errNemuA);
 grDY_NemuA->SetTitle("N e#mu DY A");
 grDY_NemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_NemuA->GetYaxis()->SetTitle("N e#mu");
 grDY_NemuA->SetMarkerColor(kBlue);
 grDY_NemuA->SetFillColor(kWhite);
 grDY_NemuA->SetLineColor(kBlue);
 grDY_NemuA->SetMarkerStyle(21);
 grDY_NemuA->SetMarkerSize(1);
 grDY_NemuA->SetLineWidth(2);
 
 TGraphErrors* grother_NemuA = new TGraphErrors(numPlot,X,other_NemuA,errX,other_errNemuA);
 grother_NemuA->SetTitle("N e#mu other A");
 grother_NemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NemuA->GetYaxis()->SetTitle("N e#mu");
 grother_NemuA->SetMarkerColor(kGreen);
 grother_NemuA->SetFillColor(kWhite);
 grother_NemuA->SetLineColor(kGreen);
 grother_NemuA->SetMarkerStyle(21);
 grother_NemuA->SetMarkerSize(1);
 grother_NemuA->SetLineWidth(2);
 
 TGraphErrors* grall_NemuA = new TGraphErrors(numPlot,X,all_NemuA,errX,all_errNemuA);
 grall_NemuA->SetTitle("N e#mu all A");
 grall_NemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 mgr_NemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_NemuA->GetYaxis()->SetTitle("N e#mu A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== mue ====
 TCanvas* cNmueA = new TCanvas("cNmueA","cNmueA",800,800); 
 
 TGraphErrors* grDATA_NmueA = new TGraphErrors(numPlot,X,DATA_NmueA,errX,DATA_errNmueA);
 grDATA_NmueA->SetTitle("N #mue DATA A");
 grDATA_NmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NmueA->GetYaxis()->SetTitle("N #mue");
 grDATA_NmueA->SetMarkerColor(kBlack);
 grDATA_NmueA->SetFillColor(kWhite);
 grDATA_NmueA->SetLineColor(kBlack);
 grDATA_NmueA->SetMarkerStyle(20);
 grDATA_NmueA->SetMarkerSize(1.5);
 grDATA_NmueA->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NmueA = new TGraphErrors(numPlot,X,DYmad_NmueA,errX,DYmad_errNmueA);
 grDYmad_NmueA->SetTitle("N #mue DYmad A");
 grDYmad_NmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_NmueA->GetYaxis()->SetTitle("N #mue");
 grDYmad_NmueA->SetMarkerColor(kGreen);
 grDYmad_NmueA->SetFillColor(kWhite);
 grDYmad_NmueA->SetLineColor(kGreen);
 grDYmad_NmueA->SetMarkerStyle(28);
 grDYmad_NmueA->SetMarkerSize(1);
 grDYmad_NmueA->SetLineWidth(2);
 
 TGraphErrors* grDY_NmueA = new TGraphErrors(numPlot,X,DY_NmueA,errX,DY_errNmueA);
 grDY_NmueA->SetTitle("N #mue DY A");
 grDY_NmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_NmueA->GetYaxis()->SetTitle("N #mue");
 grDY_NmueA->SetMarkerColor(kBlue);
 grDY_NmueA->SetFillColor(kWhite);
 grDY_NmueA->SetLineColor(kBlue);
 grDY_NmueA->SetMarkerStyle(21);
 grDY_NmueA->SetMarkerSize(1);
 grDY_NmueA->SetLineWidth(2);
 
 TGraphErrors* grother_NmueA = new TGraphErrors(numPlot,X,other_NmueA,errX,other_errNmueA);
 grother_NmueA->SetTitle("N #mue other A");
 grother_NmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NmueA->GetYaxis()->SetTitle("N #mue");
 grother_NmueA->SetMarkerColor(kGreen);
 grother_NmueA->SetFillColor(kWhite);
 grother_NmueA->SetLineColor(kGreen);
 grother_NmueA->SetMarkerStyle(21);
 grother_NmueA->SetMarkerSize(1);
 grother_NmueA->SetLineWidth(2);
 
 TGraphErrors* grall_NmueA = new TGraphErrors(numPlot,X,all_NmueA,errX,all_errNmueA);
 grall_NmueA->SetTitle("N #mue all A");
 grall_NmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 mgr_NmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 grDATA_NmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NmumuB->GetYaxis()->SetTitle("N #mu#mu");
 grDATA_NmumuB->SetMarkerColor(kBlack);
 grDATA_NmumuB->SetFillColor(kWhite);
 grDATA_NmumuB->SetLineColor(kBlack);
 grDATA_NmumuB->SetMarkerStyle(20);
 grDATA_NmumuB->SetMarkerSize(1.5);
 grDATA_NmumuB->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NmumuB = new TGraphErrors(numPlot,X,DYmad_NmumuB,errX,DYmad_errNmumuB);
 grDYmad_NmumuB->SetTitle("N #mu#mu DYmad B");
 grDYmad_NmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_NmumuB->GetYaxis()->SetTitle("N #mu#mu");
 grDYmad_NmumuB->SetMarkerColor(kGreen);
 grDYmad_NmumuB->SetFillColor(kWhite);
 grDYmad_NmumuB->SetLineColor(kGreen);
 grDYmad_NmumuB->SetMarkerStyle(28);
 grDYmad_NmumuB->SetMarkerSize(1);
 grDYmad_NmumuB->SetLineWidth(2);
 
 TGraphErrors* grDY_NmumuB = new TGraphErrors(numPlot,X,DY_NmumuB,errX,DY_errNmumuB);
 grDY_NmumuB->SetTitle("N #mu#mu DY B");
 grDY_NmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_NmumuB->GetYaxis()->SetTitle("N #mu#mu");
 grDY_NmumuB->SetMarkerColor(kBlue);
 grDY_NmumuB->SetFillColor(kWhite);
 grDY_NmumuB->SetLineColor(kBlue);
 grDY_NmumuB->SetMarkerStyle(21);
 grDY_NmumuB->SetMarkerSize(1);
 grDY_NmumuB->SetLineWidth(2);
 
 TGraphErrors* grother_NmumuB = new TGraphErrors(numPlot,X,other_NmumuB,errX,other_errNmumuB);
 grother_NmumuB->SetTitle("N #mu#mu other B");
 grother_NmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NmumuB->GetYaxis()->SetTitle("N #mu#mu");
 grother_NmumuB->SetMarkerColor(kGreen);
 grother_NmumuB->SetFillColor(kWhite);
 grother_NmumuB->SetLineColor(kGreen);
 grother_NmumuB->SetMarkerStyle(21);
 grother_NmumuB->SetMarkerSize(1);
 grother_NmumuB->SetLineWidth(2);
 
 TGraphErrors* grall_NmumuB = new TGraphErrors(numPlot,X,all_NmumuB,errX,all_errNmumuB);
 grall_NmumuB->SetTitle("N #mu#mu all B");
 grall_NmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 mgr_NmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_NmumuB->GetYaxis()->SetTitle("N #mu#mu B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== ee ====
 TCanvas* cNeeB = new TCanvas("cNeeB","cNeeB",800,800); 
 
 TGraphErrors* grDATA_NeeB = new TGraphErrors(numPlot,X,DATA_NeeB,errX,DATA_errNeeB);
 grDATA_NeeB->SetTitle("N ee DATA B");
 grDATA_NeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NeeB->GetYaxis()->SetTitle("N ee");
 grDATA_NeeB->SetMarkerColor(kBlack);
 grDATA_NeeB->SetFillColor(kWhite);
 grDATA_NeeB->SetLineColor(kBlack);
 grDATA_NeeB->SetMarkerStyle(20);
 grDATA_NeeB->SetMarkerSize(1.5);
 grDATA_NeeB->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NeeB = new TGraphErrors(numPlot,X,DYmad_NeeB,errX,DYmad_errNeeB);
 grDYmad_NeeB->SetTitle("N ee DYmad B");
 grDYmad_NeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_NeeB->GetYaxis()->SetTitle("N ee");
 grDYmad_NeeB->SetMarkerColor(kGreen);
 grDYmad_NeeB->SetFillColor(kWhite);
 grDYmad_NeeB->SetLineColor(kGreen);
 grDYmad_NeeB->SetMarkerStyle(28);
 grDYmad_NeeB->SetMarkerSize(1);
 grDYmad_NeeB->SetLineWidth(2);
 
 TGraphErrors* grDY_NeeB = new TGraphErrors(numPlot,X,DY_NeeB,errX,DY_errNeeB);
 grDY_NeeB->SetTitle("N ee DY B");
 grDY_NeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_NeeB->GetYaxis()->SetTitle("N ee");
 grDY_NeeB->SetMarkerColor(kBlue);
 grDY_NeeB->SetFillColor(kWhite);
 grDY_NeeB->SetLineColor(kBlue);
 grDY_NeeB->SetMarkerStyle(21);
 grDY_NeeB->SetMarkerSize(1);
 grDY_NeeB->SetLineWidth(2);
 
 TGraphErrors* grother_NeeB = new TGraphErrors(numPlot,X,other_NeeB,errX,other_errNeeB);
 grother_NeeB->SetTitle("N ee other B");
 grother_NeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NeeB->GetYaxis()->SetTitle("N ee");
 grother_NeeB->SetMarkerColor(kGreen);
 grother_NeeB->SetFillColor(kWhite);
 grother_NeeB->SetLineColor(kGreen);
 grother_NeeB->SetMarkerStyle(21);
 grother_NeeB->SetMarkerSize(1);
 grother_NeeB->SetLineWidth(2);
 
 TGraphErrors* grall_NeeB = new TGraphErrors(numPlot,X,all_NeeB,errX,all_errNeeB);
 grall_NeeB->SetTitle("N ee all B");
 grall_NeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 mgr_NeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_NeeB->GetYaxis()->SetTitle("N ee B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== emu ====
 TCanvas* cNemuB = new TCanvas("cNemuB","cNemuB",800,800); 
 
 TGraphErrors* grDATA_NemuB = new TGraphErrors(numPlot,X,DATA_NemuB,errX,DATA_errNemuB);
 grDATA_NemuB->SetTitle("N e#mu DATA B");
 grDATA_NemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NemuB->GetYaxis()->SetTitle("N e#mu");
 grDATA_NemuB->SetMarkerColor(kBlack);
 grDATA_NemuB->SetFillColor(kWhite);
 grDATA_NemuB->SetLineColor(kBlack);
 grDATA_NemuB->SetMarkerStyle(20);
 grDATA_NemuB->SetMarkerSize(1.5);
 grDATA_NemuB->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NemuB = new TGraphErrors(numPlot,X,DYmad_NemuB,errX,DYmad_errNemuB);
 grDYmad_NemuB->SetTitle("N e#mu DYmad B");
 grDYmad_NemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_NemuB->GetYaxis()->SetTitle("N e#mu");
 grDYmad_NemuB->SetMarkerColor(kGreen);
 grDYmad_NemuB->SetFillColor(kWhite);
 grDYmad_NemuB->SetLineColor(kGreen);
 grDYmad_NemuB->SetMarkerStyle(28);
 grDYmad_NemuB->SetMarkerSize(1);
 grDYmad_NemuB->SetLineWidth(2);
 
 TGraphErrors* grDY_NemuB = new TGraphErrors(numPlot,X,DY_NemuB,errX,DY_errNemuB);
 grDY_NemuB->SetTitle("N e#mu DY B");
 grDY_NemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_NemuB->GetYaxis()->SetTitle("N e#mu");
 grDY_NemuB->SetMarkerColor(kBlue);
 grDY_NemuB->SetFillColor(kWhite);
 grDY_NemuB->SetLineColor(kBlue);
 grDY_NemuB->SetMarkerStyle(21);
 grDY_NemuB->SetMarkerSize(1);
 grDY_NemuB->SetLineWidth(2);
 
 TGraphErrors* grother_NemuB = new TGraphErrors(numPlot,X,other_NemuB,errX,other_errNemuB);
 grother_NemuB->SetTitle("N e#mu other B");
 grother_NemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NemuB->GetYaxis()->SetTitle("N e#mu");
 grother_NemuB->SetMarkerColor(kGreen);
 grother_NemuB->SetFillColor(kWhite);
 grother_NemuB->SetLineColor(kGreen);
 grother_NemuB->SetMarkerStyle(21);
 grother_NemuB->SetMarkerSize(1);
 grother_NemuB->SetLineWidth(2);
 
 TGraphErrors* grall_NemuB = new TGraphErrors(numPlot,X,all_NemuB,errX,all_errNemuB);
 grall_NemuB->SetTitle("N e#mu all B");
 grall_NemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 mgr_NemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_NemuB->GetYaxis()->SetTitle("N e#mu B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== mue ====
 TCanvas* cNmueB = new TCanvas("cNmueB","cNmueB",800,800); 
 
 TGraphErrors* grDATA_NmueB = new TGraphErrors(numPlot,X,DATA_NmueB,errX,DATA_errNmueB);
 grDATA_NmueB->SetTitle("N #mue DATA B");
 grDATA_NmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NmueB->GetYaxis()->SetTitle("N #mue");
 grDATA_NmueB->SetMarkerColor(kBlack);
 grDATA_NmueB->SetFillColor(kWhite);
 grDATA_NmueB->SetLineColor(kBlack);
 grDATA_NmueB->SetMarkerStyle(20);
 grDATA_NmueB->SetMarkerSize(1.5);
 grDATA_NmueB->SetLineWidth(2);
 
 TGraphErrors* grDYmad_NmueB = new TGraphErrors(numPlot,X,DYmad_NmueB,errX,DYmad_errNmueB);
 grDYmad_NmueB->SetTitle("N #mue DYmad B");
 grDYmad_NmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_NmueB->GetYaxis()->SetTitle("N #mue");
 grDYmad_NmueB->SetMarkerColor(kGreen);
 grDYmad_NmueB->SetFillColor(kWhite);
 grDYmad_NmueB->SetLineColor(kGreen);
 grDYmad_NmueB->SetMarkerStyle(28);
 grDYmad_NmueB->SetMarkerSize(1);
 grDYmad_NmueB->SetLineWidth(2);
 
 TGraphErrors* grDY_NmueB = new TGraphErrors(numPlot,X,DY_NmueB,errX,DY_errNmueB);
 grDY_NmueB->SetTitle("N #mue DY B");
 grDY_NmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_NmueB->GetYaxis()->SetTitle("N #mue");
 grDY_NmueB->SetMarkerColor(kBlue);
 grDY_NmueB->SetFillColor(kWhite);
 grDY_NmueB->SetLineColor(kBlue);
 grDY_NmueB->SetMarkerStyle(21);
 grDY_NmueB->SetMarkerSize(1);
 grDY_NmueB->SetLineWidth(2);
 
 TGraphErrors* grother_NmueB = new TGraphErrors(numPlot,X,other_NmueB,errX,other_errNmueB);
 grother_NmueB->SetTitle("N #mue other B");
 grother_NmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NmueB->GetYaxis()->SetTitle("N #mue");
 grother_NmueB->SetMarkerColor(kGreen);
 grother_NmueB->SetFillColor(kWhite);
 grother_NmueB->SetLineColor(kGreen);
 grother_NmueB->SetMarkerStyle(21);
 grother_NmueB->SetMarkerSize(1);
 grother_NmueB->SetLineWidth(2);
 
 TGraphErrors* grall_NmueB = new TGraphErrors(numPlot,X,all_NmueB,errX,all_errNmueB);
 grall_NmueB->SetTitle("N #mue all B");
 grall_NmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 mgr_NmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 grDATA_standardR_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_standardR_ee->GetYaxis()->SetTitle("R ee");
 grDATA_standardR_ee->SetMarkerColor(kRed);
 grDATA_standardR_ee->SetFillColor(kWhite);
 grDATA_standardR_ee->SetLineColor(kRed);
 grDATA_standardR_ee->SetMarkerStyle(24);
 grDATA_standardR_ee->SetMarkerSize(1);
 grDATA_standardR_ee->SetLineWidth(2);
 
 TGraphErrors* grDATA_R_ee = new TGraphErrors(numPlot,X,DATA_R_ee,errX,DATA_errR_ee);
 grDATA_R_ee->SetTitle("Ree DATA");
 grDATA_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_R_ee->GetYaxis()->SetTitle("R ee");
 grDATA_R_ee->SetMarkerColor(kRed);
 grDATA_R_ee->SetFillColor(kWhite);
 grDATA_R_ee->SetLineColor(kRed);
 grDATA_R_ee->SetMarkerStyle(20);
 grDATA_R_ee->SetMarkerSize(1);
 grDATA_R_ee->SetLineWidth(2);
 
 
 
 TGraphErrors* grall_R_ee = new TGraphErrors(numPlot,X,all_R_ee,errX,all_errR_ee);
 grall_R_ee->SetTitle("Ree MC ");
 grall_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_R_ee->GetYaxis()->SetTitle("R ee");
 grall_R_ee->SetMarkerColor(kBlue);
 grall_R_ee->SetFillColor(kWhite);
 grall_R_ee->SetLineColor(kBlue);
 grall_R_ee->SetMarkerStyle(21);
 grall_R_ee->SetMarkerSize(1);
 grall_R_ee->SetLineWidth(2);
 

 TGraphErrors* grall_standardR_ee = new TGraphErrors(numPlot,XShift,all_standardR_ee,errX,all_errstandardR_ee);
 grall_standardR_ee->SetTitle("Ree MC  Standard");
 grall_standardR_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_standardR_ee->GetYaxis()->SetTitle("R ee");
 grall_standardR_ee->SetMarkerColor(kBlue);
 grall_standardR_ee->SetFillColor(kWhite);
 grall_standardR_ee->SetLineColor(kBlue);
 grall_standardR_ee->SetMarkerStyle(25);
 grall_standardR_ee->SetMarkerSize(1);
 grall_standardR_ee->SetLineWidth(2);
 
 
 TGraphErrors* grDY_standardR_ee = new TGraphErrors(numPlot,XShift,DY_standardR_ee,errX,DY_errstandardR_ee);
 grDY_standardR_ee->SetTitle("Ree MC DY Standard");
 grDY_standardR_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_standardR_ee->GetYaxis()->SetTitle("R ee");
 grDY_standardR_ee->SetMarkerColor(kGreen);
 grDY_standardR_ee->SetFillColor(kWhite);
 grDY_standardR_ee->SetLineColor(kGreen);
 grDY_standardR_ee->SetMarkerStyle(26);
 grDY_standardR_ee->SetMarkerSize(1);
 grDY_standardR_ee->SetLineWidth(2);
 
 
 TGraphErrors* grDY_R_ee = new TGraphErrors(numPlot,X,DY_R_ee,errX,DY_errR_ee);
 grDY_R_ee->SetTitle("Ree MC DY");
 grDY_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_R_ee->GetYaxis()->SetTitle("R ee");
 grDY_R_ee->SetMarkerColor(kGreen);
 grDY_R_ee->SetFillColor(kWhite);
 grDY_R_ee->SetLineColor(kGreen);
 grDY_R_ee->SetMarkerStyle(22);
 grDY_R_ee->SetMarkerSize(1);
 grDY_R_ee->SetLineWidth(2);
 
 
 
 TGraphErrors* grDY_Rexact_ee = new TGraphErrors(numPlot,XShift,DY_Rexact_ee,errX,DY_errRexact_ee);
 grDY_Rexact_ee->SetTitle("Ree MC DY exact");
 grDY_Rexact_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_Rexact_ee->GetYaxis()->SetTitle("R ee");
 grDY_Rexact_ee->SetMarkerColor(kTeal);
 grDY_Rexact_ee->SetFillColor(kWhite);
 grDY_Rexact_ee->SetLineColor(kTeal);
 grDY_Rexact_ee->SetMarkerStyle(30);
 grDY_Rexact_ee->SetMarkerSize(1);
 grDY_Rexact_ee->SetLineWidth(2);
 
 
 TCanvas* c_R_ee = new TCanvas("c_R_ee","c_R_ee",800,800); 
 TMultiGraph* mgr_R_ee = new TMultiGraph(); 
 mgr_R_ee->Add(grDATA_standardR_ee);
 mgr_R_ee->Add(grDATA_R_ee);
//  mgr_R_ee->Add(grall_standardR_ee);
//  mgr_R_ee->Add(grall_R_ee);
//  mgr_R_ee->Add(grDY_standardR_ee);
//  mgr_R_ee->Add(grDY_R_ee);
//  mgr_R_ee->Add(grDY_Rexact_ee);
 mgr_R_ee->Draw("AP");
 mgr_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_R_ee->GetYaxis()->SetTitle("R ee");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 
 //==== mumu ====
 
 TGraphErrors* grDATA_standardR_mumu = new TGraphErrors(numPlot,XShift,DATA_standardR_mumu,errX,DATA_errstandardR_mumu);
 grDATA_standardR_mumu->SetTitle("R#mu#mu DATA Standard");
 grDATA_standardR_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_standardR_mumu->GetYaxis()->SetTitle("R mumu");
 grDATA_standardR_mumu->SetMarkerColor(kRed);
 grDATA_standardR_mumu->SetFillColor(kWhite);
 grDATA_standardR_mumu->SetLineColor(kRed);
 grDATA_standardR_mumu->SetMarkerStyle(24);
 grDATA_standardR_mumu->SetMarkerSize(1);
 grDATA_standardR_mumu->SetLineWidth(2);
 
 TGraphErrors* grDATA_R_mumu = new TGraphErrors(numPlot,X,DATA_R_mumu,errX,DATA_errR_mumu);
 grDATA_R_mumu->SetTitle("R#mu#mu DATA");
 grDATA_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_R_mumu->GetYaxis()->SetTitle("R mumu");
 grDATA_R_mumu->SetMarkerColor(kRed);
 grDATA_R_mumu->SetFillColor(kWhite);
 grDATA_R_mumu->SetLineColor(kRed);
 grDATA_R_mumu->SetMarkerStyle(20);
 grDATA_R_mumu->SetMarkerSize(1);
 grDATA_R_mumu->SetLineWidth(2);
 
 
 
 TGraphErrors* grall_R_mumu = new TGraphErrors(numPlot,X,all_R_mumu,errX,all_errR_mumu);
 grall_R_mumu->SetTitle("R#mu#mu MC ");
 grall_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_R_mumu->GetYaxis()->SetTitle("R mumu");
 grall_R_mumu->SetMarkerColor(kBlue);
 grall_R_mumu->SetFillColor(kWhite);
 grall_R_mumu->SetLineColor(kBlue);
 grall_R_mumu->SetMarkerStyle(21);
 grall_R_mumu->SetMarkerSize(1);
 grall_R_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grall_standardR_mumu = new TGraphErrors(numPlot,XShift,all_standardR_mumu,errX,all_errstandardR_mumu);
 grall_standardR_mumu->SetTitle("R#mu#mu MC  standard");
 grall_standardR_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_standardR_mumu->GetYaxis()->SetTitle("R mumu");
 grall_standardR_mumu->SetMarkerColor(kBlue);
 grall_standardR_mumu->SetFillColor(kWhite);
 grall_standardR_mumu->SetLineColor(kBlue);
 grall_standardR_mumu->SetMarkerStyle(25);
 grall_standardR_mumu->SetMarkerSize(1);
 grall_standardR_mumu->SetLineWidth(2);
 
 
 
 TGraphErrors* grDY_standardR_mumu = new TGraphErrors(numPlot,XShift,DY_standardR_mumu,errX,DY_errstandardR_mumu);
 grDY_standardR_mumu->SetTitle("R#mu#mu MC DY standard");
 grDY_standardR_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_standardR_mumu->GetYaxis()->SetTitle("R mumu");
 grDY_standardR_mumu->SetMarkerColor(kGreen);
 grDY_standardR_mumu->SetFillColor(kWhite);
 grDY_standardR_mumu->SetLineColor(kGreen);
 grDY_standardR_mumu->SetMarkerStyle(26);
 grDY_standardR_mumu->SetMarkerSize(1);
 grDY_standardR_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grDY_R_mumu = new TGraphErrors(numPlot,X,DY_R_mumu,errX,DY_errR_mumu);
 grDY_R_mumu->SetTitle("R#mu#mu MC DY");
 grDY_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_R_mumu->GetYaxis()->SetTitle("R mumu");
 grDY_R_mumu->SetMarkerColor(kGreen);
 grDY_R_mumu->SetFillColor(kWhite);
 grDY_R_mumu->SetLineColor(kGreen);
 grDY_R_mumu->SetMarkerStyle(22);
 grDY_R_mumu->SetMarkerSize(1);
 grDY_R_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grDY_Rexact_mumu = new TGraphErrors(numPlot,XShift,DY_Rexact_mumu,errX,DY_errRexact_mumu);
 grDY_Rexact_mumu->SetTitle("R#mu#mu MC DY exact");
 grDY_Rexact_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_Rexact_mumu->GetYaxis()->SetTitle("R mumu");
 grDY_Rexact_mumu->SetMarkerColor(kTeal);
 grDY_Rexact_mumu->SetFillColor(kWhite);
 grDY_Rexact_mumu->SetLineColor(kTeal);
 grDY_Rexact_mumu->SetMarkerStyle(30);
 grDY_Rexact_mumu->SetMarkerSize(1);
 grDY_Rexact_mumu->SetLineWidth(2);
 
 
 TCanvas* c_R_mumu = new TCanvas("c_R_mumu","c_R_mumu",800,800); 
 TMultiGraph* mgr_R_mumu = new TMultiGraph(); 
 mgr_R_mumu->Add(grDATA_standardR_mumu);
 mgr_R_mumu->Add(grDATA_R_mumu);
//  mgr_R_mumu->Add(grall_standardR_mumu);
//  mgr_R_mumu->Add(grall_R_mumu);
//  mgr_R_mumu->Add(grDY_standardR_mumu);
//  mgr_R_mumu->Add(grDY_R_mumu);
//  mgr_R_mumu->Add(grDY_Rexact_mumu);
 mgr_R_mumu->Draw("AP");
 mgr_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_R_mumu->GetYaxis()->SetTitle("R #mu#mu");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
  
 
 
 
 
 
 
 
//  TGraphErrors* grDATA_NKB_ee = new TGraphErrors(numPlot,X,DATA_NKB_ee,errX,DATA_errNKB_ee);
//  grDATA_NKB_ee->SetTitle("N #mue * kee B");
//  grDATA_NKB_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
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
//  grDATA_NKBNew_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
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
//  grDATA_NKB_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
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
//  grDATA_NKBNew_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
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
//  grDATA_NKA_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
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
//  grDATA_NKANew_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
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
//  mgr_DATA_NK_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
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
//  grDATA_NKA_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
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
//  grDATA_NKANew_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
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
//  mgr_DATA_NK_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
//  mgr_DATA_NK_mumu->GetYaxis()->SetTitle("N #mu#mu other");
//  
//  TLegend* leg = gPad->BuildLegend();
//  leg->SetFillColor(kWhite);
//  gPad->SetGrid();
//  
// }
//  
//  
 
 ///================
 ///==== plot of M ====
 ///================
 
 ///================
 ///==== plot to see if M is independent wrt met selection: calculate it with tight met cut
 ///==== to be DY free -> then apply back in normal phase space ====
 ///==== compare DATA and MC -> "other" MC to be used -> check if it is flat wrt met !
 ///================
 
 ///======================
 ///==== A and B zone ====
 ///======================
 
 
 
 TGraphErrors* grDATA_MmumuA = new TGraphErrors(numPlotM,XM,DATA_MmumuA,errXM,DATA_errMmumuA);
 grDATA_MmumuA->SetTitle("M#mu#mu DATA A");
 grDATA_MmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MmumuA->GetYaxis()->SetTitle("M#mu#mu A");
 grDATA_MmumuA->SetMarkerColor(kBlack);
 grDATA_MmumuA->SetFillColor(kWhite);
 grDATA_MmumuA->SetLineColor(kBlack);
 grDATA_MmumuA->SetMarkerStyle(25);
 grDATA_MmumuA->SetMarkerSize(1);
 grDATA_MmumuA->SetLineWidth(2);
 
 TGraphErrors* grDATA_MeeA = new TGraphErrors(numPlotM,XM,DATA_MeeA,errXM,DATA_errMeeA);
 grDATA_MeeA->SetTitle("Mee DATA A");
 grDATA_MeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MeeA->GetYaxis()->SetTitle("Mee A");
 grDATA_MeeA->SetMarkerColor(kBlack);
 grDATA_MeeA->SetFillColor(kWhite);
 grDATA_MeeA->SetLineColor(kBlack);
 grDATA_MeeA->SetMarkerStyle(25);
 grDATA_MeeA->SetMarkerSize(1);
 grDATA_MeeA->SetLineWidth(2);
 
 TGraphErrors* grDATA_MemuA = new TGraphErrors(numPlotM,XM,DATA_MemuA,errXM,DATA_errMemuA);
 grDATA_MemuA->SetTitle("M#mu#mu DATA A");
 grDATA_MemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MemuA->GetYaxis()->SetTitle("M#mu#mu A");
 grDATA_MemuA->SetMarkerColor(kBlack);
 grDATA_MemuA->SetFillColor(kWhite);
 grDATA_MemuA->SetLineColor(kBlack);
 grDATA_MemuA->SetMarkerStyle(25);
 grDATA_MemuA->SetMarkerSize(1);
 grDATA_MemuA->SetLineWidth(2);
 
 TGraphErrors* grDATA_MmueA = new TGraphErrors(numPlotM,XM,DATA_MmueA,errXM,DATA_errMmueA);
 grDATA_MmueA->SetTitle("M#mue DATA A");
 grDATA_MmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MmueA->GetYaxis()->SetTitle("M#mue A");
 grDATA_MmueA->SetMarkerColor(kBlack);
 grDATA_MmueA->SetFillColor(kWhite);
 grDATA_MmueA->SetLineColor(kBlack);
 grDATA_MmueA->SetMarkerStyle(25);
 grDATA_MmueA->SetMarkerSize(1);
 grDATA_MmueA->SetLineWidth(2);
 
 
 
 
 TGraphErrors* grother_MmumuA = new TGraphErrors(numPlotM,XM,other_MmumuA,errXM,other_errMmumuA);
 grother_MmumuA->SetTitle("M#mu#mu other A");
 grother_MmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MmumuA->GetYaxis()->SetTitle("M#mu#mu A");
 grother_MmumuA->SetMarkerColor(kBlue);
 grother_MmumuA->SetFillColor(kWhite);
 grother_MmumuA->SetLineColor(kBlue);
 grother_MmumuA->SetMarkerStyle(25);
 grother_MmumuA->SetMarkerSize(1);
 grother_MmumuA->SetLineWidth(2);
 
 TGraphErrors* grother_MeeA = new TGraphErrors(numPlotM,XM,other_MeeA,errXM,other_errMeeA);
 grother_MeeA->SetTitle("Mee other A");
 grother_MeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MeeA->GetYaxis()->SetTitle("Mee A");
 grother_MeeA->SetMarkerColor(kBlue);
 grother_MeeA->SetFillColor(kWhite);
 grother_MeeA->SetLineColor(kBlue);
 grother_MeeA->SetMarkerStyle(25);
 grother_MeeA->SetMarkerSize(1);
 grother_MeeA->SetLineWidth(2);
 
 TGraphErrors* grother_MemuA = new TGraphErrors(numPlotM,XM,other_MemuA,errXM,other_errMemuA);
 grother_MemuA->SetTitle("M#mu#mu other A");
 grother_MemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MemuA->GetYaxis()->SetTitle("M#mu#mu A");
 grother_MemuA->SetMarkerColor(kBlue);
 grother_MemuA->SetFillColor(kWhite);
 grother_MemuA->SetLineColor(kBlue);
 grother_MemuA->SetMarkerStyle(25);
 grother_MemuA->SetMarkerSize(1);
 grother_MemuA->SetLineWidth(2);
 
 TGraphErrors* grother_MmueA = new TGraphErrors(numPlotM,XM,other_MmueA,errXM,other_errMmueA);
 grother_MmueA->SetTitle("M#mue other A");
 grother_MmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MmueA->GetYaxis()->SetTitle("M#mue A");
 grother_MmueA->SetMarkerColor(kBlue);
 grother_MmueA->SetFillColor(kWhite);
 grother_MmueA->SetLineColor(kBlue);
 grother_MmueA->SetMarkerStyle(25);
 grother_MmueA->SetMarkerSize(1);
 grother_MmueA->SetLineWidth(2);
 
 
 
 TGraphErrors* grall_MmumuA = new TGraphErrors(numPlotM,XM,all_MmumuA,errXM,all_errMmumuA);
 grall_MmumuA->SetTitle("M#mu#mu all A");
 grall_MmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MmumuA->GetYaxis()->SetTitle("M#mu#mu A");
 grall_MmumuA->SetMarkerColor(kRed);
 grall_MmumuA->SetFillColor(kWhite);
 grall_MmumuA->SetLineColor(kRed);
 grall_MmumuA->SetMarkerStyle(25);
 grall_MmumuA->SetMarkerSize(1);
 grall_MmumuA->SetLineWidth(2);
 
 TGraphErrors* grall_MeeA = new TGraphErrors(numPlotM,XM,all_MeeA,errXM,all_errMeeA);
 grall_MeeA->SetTitle("Mee all A");
 grall_MeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MeeA->GetYaxis()->SetTitle("Mee A");
 grall_MeeA->SetMarkerColor(kRed);
 grall_MeeA->SetFillColor(kWhite);
 grall_MeeA->SetLineColor(kRed);
 grall_MeeA->SetMarkerStyle(25);
 grall_MeeA->SetMarkerSize(1);
 grall_MeeA->SetLineWidth(2);
 
 TGraphErrors* grall_MemuA = new TGraphErrors(numPlotM,XM,all_MemuA,errXM,all_errMemuA);
 grall_MemuA->SetTitle("Me#mu all A");
 grall_MemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MemuA->GetYaxis()->SetTitle("Me#mu A");
 grall_MemuA->SetMarkerColor(kRed);
 grall_MemuA->SetFillColor(kWhite);
 grall_MemuA->SetLineColor(kRed);
 grall_MemuA->SetMarkerStyle(25);
 grall_MemuA->SetMarkerSize(1);
 grall_MemuA->SetLineWidth(2);
 
 TGraphErrors* grall_MmueA = new TGraphErrors(numPlotM,XM,all_MmueA,errXM,all_errMmueA);
 grall_MmueA->SetTitle("M#mue all A");
 grall_MmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MmueA->GetYaxis()->SetTitle("M#mue A");
 grall_MmueA->SetMarkerColor(kRed);
 grall_MmueA->SetFillColor(kWhite);
 grall_MmueA->SetLineColor(kRed);
 grall_MmueA->SetMarkerStyle(25);
 grall_MmueA->SetMarkerSize(1);
 grall_MmueA->SetLineWidth(2);
 
 
 
 
 
 TCanvas* cMA = new TCanvas("cMA","cMA",800,800); 
 cMA->Divide(2,2);
 
 cMA->cd(1);
 TMultiGraph* mgr_MeeA = new TMultiGraph(); 
 mgr_MeeA->Add(grall_MeeA);
 mgr_MeeA->Add(grother_MeeA);
 mgr_MeeA->Add(grDATA_MeeA);
 mgr_MeeA->Draw("AP");
 mgr_MeeA->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_MeeA->GetYaxis()->SetTitle("M ee"); 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite); 
 gPad->SetGrid();
 
 cMA->cd(2);
 TMultiGraph* mgr_MmumuA = new TMultiGraph(); 
 mgr_MmumuA->Add(grall_MmumuA);
 mgr_MmumuA->Add(grother_MmumuA);
 mgr_MmumuA->Add(grDATA_MmumuA);
 mgr_MmumuA->Draw("AP");
 mgr_MmumuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_MmumuA->GetYaxis()->SetTitle("M mumu"); 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite); 
 gPad->SetGrid();
 
 cMA->cd(3);
 TMultiGraph* mgr_MemuA = new TMultiGraph(); 
 mgr_MemuA->Add(grall_MemuA);
 mgr_MemuA->Add(grother_MemuA);
 mgr_MemuA->Add(grDATA_MemuA);
 mgr_MemuA->Draw("AP");
 mgr_MemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_MemuA->GetYaxis()->SetTitle("M emu"); 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite); 
 gPad->SetGrid();
 
 cMA->cd(4);
 TMultiGraph* mgr_MmueA = new TMultiGraph(); 
 mgr_MmueA->Add(grall_MmueA);
 mgr_MmueA->Add(grother_MmueA);
 mgr_MmueA->Add(grDATA_MmueA);
 mgr_MmueA->Draw("AP");
 mgr_MmueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_MmueA->GetYaxis()->SetTitle("M mue"); 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite); 
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 TGraphErrors* grDATA_MmumuB = new TGraphErrors(numPlotM,XM,DATA_MmumuB,errXM,DATA_errMmumuB);
 grDATA_MmumuB->SetTitle("M#mu#mu DATA B");
 grDATA_MmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MmumuB->GetYaxis()->SetTitle("M#mu#mu B");
 grDATA_MmumuB->SetMarkerColor(kBlack);
 grDATA_MmumuB->SetFillColor(kWhite);
 grDATA_MmumuB->SetLineColor(kBlack);
 grDATA_MmumuB->SetMarkerStyle(25);
 grDATA_MmumuB->SetMarkerSize(1);
 grDATA_MmumuB->SetLineWidth(2);
 
 TGraphErrors* grDATA_MeeB = new TGraphErrors(numPlotM,XM,DATA_MeeB,errXM,DATA_errMeeB);
 grDATA_MeeB->SetTitle("Mee DATA B");
 grDATA_MeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MeeB->GetYaxis()->SetTitle("Mee B");
 grDATA_MeeB->SetMarkerColor(kBlack);
 grDATA_MeeB->SetFillColor(kWhite);
 grDATA_MeeB->SetLineColor(kBlack);
 grDATA_MeeB->SetMarkerStyle(25);
 grDATA_MeeB->SetMarkerSize(1);
 grDATA_MeeB->SetLineWidth(2);
 
 TGraphErrors* grDATA_MemuB = new TGraphErrors(numPlotM,XM,DATA_MemuB,errXM,DATA_errMemuB);
 grDATA_MemuB->SetTitle("Me#mu DATA B");
 grDATA_MemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MemuB->GetYaxis()->SetTitle("Me#mu B");
 grDATA_MemuB->SetMarkerColor(kBlack);
 grDATA_MemuB->SetFillColor(kWhite);
 grDATA_MemuB->SetLineColor(kBlack);
 grDATA_MemuB->SetMarkerStyle(25);
 grDATA_MemuB->SetMarkerSize(1);
 grDATA_MemuB->SetLineWidth(2);
 
 TGraphErrors* grDATA_MmueB = new TGraphErrors(numPlotM,XM,DATA_MmueB,errXM,DATA_errMmueB);
 grDATA_MmueB->SetTitle("M#mue DATA B");
 grDATA_MmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MmueB->GetYaxis()->SetTitle("M#mue B");
 grDATA_MmueB->SetMarkerColor(kBlack);
 grDATA_MmueB->SetFillColor(kWhite);
 grDATA_MmueB->SetLineColor(kBlack);
 grDATA_MmueB->SetMarkerStyle(25);
 grDATA_MmueB->SetMarkerSize(1);
 grDATA_MmueB->SetLineWidth(2);
 
 
 
 
 TGraphErrors* grother_MmumuB = new TGraphErrors(numPlotM,XM,other_MmumuB,errXM,other_errMmumuB);
 grother_MmumuB->SetTitle("M#mu#mu other B");
 grother_MmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MmumuB->GetYaxis()->SetTitle("M#mu#mu B");
 grother_MmumuB->SetMarkerColor(kBlue);
 grother_MmumuB->SetFillColor(kWhite);
 grother_MmumuB->SetLineColor(kBlue);
 grother_MmumuB->SetMarkerStyle(25);
 grother_MmumuB->SetMarkerSize(1);
 grother_MmumuB->SetLineWidth(2);
 
 TGraphErrors* grother_MeeB = new TGraphErrors(numPlotM,XM,other_MeeB,errXM,other_errMeeB);
 grother_MeeB->SetTitle("Mee other B");
 grother_MeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MeeB->GetYaxis()->SetTitle("Mee B");
 grother_MeeB->SetMarkerColor(kBlue);
 grother_MeeB->SetFillColor(kWhite);
 grother_MeeB->SetLineColor(kBlue);
 grother_MeeB->SetMarkerStyle(25);
 grother_MeeB->SetMarkerSize(1);
 grother_MeeB->SetLineWidth(2);
 
 TGraphErrors* grother_MemuB = new TGraphErrors(numPlotM,XM,other_MemuB,errXM,other_errMemuB);
 grother_MemuB->SetTitle("M#mu#mu other B");
 grother_MemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MemuB->GetYaxis()->SetTitle("M#mu#mu B");
 grother_MemuB->SetMarkerColor(kBlue);
 grother_MemuB->SetFillColor(kWhite);
 grother_MemuB->SetLineColor(kBlue);
 grother_MemuB->SetMarkerStyle(25);
 grother_MemuB->SetMarkerSize(1);
 grother_MemuB->SetLineWidth(2);
 
 TGraphErrors* grother_MmueB = new TGraphErrors(numPlotM,XM,other_MmueB,errXM,other_errMmueB);
 grother_MmueB->SetTitle("M#mue other B");
 grother_MmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MmueB->GetYaxis()->SetTitle("M#mue B");
 grother_MmueB->SetMarkerColor(kBlue);
 grother_MmueB->SetFillColor(kWhite);
 grother_MmueB->SetLineColor(kBlue);
 grother_MmueB->SetMarkerStyle(25);
 grother_MmueB->SetMarkerSize(1);
 grother_MmueB->SetLineWidth(2);
 
 
 
 TGraphErrors* grall_MmumuB = new TGraphErrors(numPlotM,XM,all_MmumuB,errXM,all_errMmumuB);
 grall_MmumuB->SetTitle("M#mu#mu all B");
 grall_MmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MmumuB->GetYaxis()->SetTitle("M#mu#mu B");
 grall_MmumuB->SetMarkerColor(kRed);
 grall_MmumuB->SetFillColor(kWhite);
 grall_MmumuB->SetLineColor(kRed);
 grall_MmumuB->SetMarkerStyle(25);
 grall_MmumuB->SetMarkerSize(1);
 grall_MmumuB->SetLineWidth(2);
 
 TGraphErrors* grall_MeeB = new TGraphErrors(numPlotM,XM,all_MeeB,errXM,all_errMeeB);
 grall_MeeB->SetTitle("Mee all B");
 grall_MeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MeeB->GetYaxis()->SetTitle("Mee B");
 grall_MeeB->SetMarkerColor(kRed);
 grall_MeeB->SetFillColor(kWhite);
 grall_MeeB->SetLineColor(kRed);
 grall_MeeB->SetMarkerStyle(25);
 grall_MeeB->SetMarkerSize(1);
 grall_MeeB->SetLineWidth(2);
 
 TGraphErrors* grall_MemuB = new TGraphErrors(numPlotM,XM,all_MemuB,errXM,all_errMemuB);
 grall_MemuB->SetTitle("M#mu#mu all B");
 grall_MemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MemuB->GetYaxis()->SetTitle("M#mu#mu B");
 grall_MemuB->SetMarkerColor(kRed);
 grall_MemuB->SetFillColor(kWhite);
 grall_MemuB->SetLineColor(kRed);
 grall_MemuB->SetMarkerStyle(25);
 grall_MemuB->SetMarkerSize(1);
 grall_MemuB->SetLineWidth(2);
 
 TGraphErrors* grall_MmueB = new TGraphErrors(numPlotM,XM,all_MmueB,errXM,all_errMmueB);
 grall_MmueB->SetTitle("M#mue all B");
 grall_MmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MmueB->GetYaxis()->SetTitle("M#mue B");
 grall_MmueB->SetMarkerColor(kRed);
 grall_MmueB->SetFillColor(kWhite);
 grall_MmueB->SetLineColor(kRed);
 grall_MmueB->SetMarkerStyle(25);
 grall_MmueB->SetMarkerSize(1);
 grall_MmueB->SetLineWidth(2);
 
 
 
 
 
 TCanvas* cMA = new TCanvas("cMB","cMB",800,800); 
 cMA->Divide(2,2);
 
 cMA->cd(1);
 TMultiGraph* mgr_MeeB = new TMultiGraph(); 
 mgr_MeeB->Add(grall_MeeB);
 mgr_MeeB->Add(grother_MeeB);
 mgr_MeeB->Add(grDATA_MeeB);
 mgr_MeeB->Draw("AP");
 mgr_MeeB->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_MeeB->GetYaxis()->SetTitle("M ee"); 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite); 
 gPad->SetGrid();
 
 cMA->cd(2);
 TMultiGraph* mgr_MmumuB = new TMultiGraph(); 
 mgr_MmumuB->Add(grall_MmumuB);
 mgr_MmumuB->Add(grother_MmumuB);
 mgr_MmumuB->Add(grDATA_MmumuB);
 mgr_MmumuB->Draw("AP");
 mgr_MmumuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_MmumuB->GetYaxis()->SetTitle("M mumu"); 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite); 
 gPad->SetGrid();
 
 cMA->cd(3);
 TMultiGraph* mgr_MemuB = new TMultiGraph(); 
 mgr_MemuB->Add(grall_MemuB);
 mgr_MemuB->Add(grother_MemuB);
 mgr_MemuB->Add(grDATA_MemuB);
 mgr_MemuB->Draw("AP");
 mgr_MemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_MemuB->GetYaxis()->SetTitle("M emu"); 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite); 
 gPad->SetGrid();
 
 cMA->cd(4);
 TMultiGraph* mgr_MmueB = new TMultiGraph(); 
 mgr_MmueB->Add(grall_MmueB);
 mgr_MmueB->Add(grother_MmueB);
 mgr_MmueB->Add(grDATA_MmueB);
 mgr_MmueB->Draw("AP");
 mgr_MmueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_MmueB->GetYaxis()->SetTitle("M mue"); 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite); 
 gPad->SetGrid();
 
 
 
 
 
 ///==== M_ijkm ==== 
 TGraphErrors* grDATA_MeeemuA = new TGraphErrors(numPlotM,XM,DATA_MeeemuA,errXM,DATA_errMeeemuA);
 grDATA_MeeemuA->SetTitle("Mee/e#mu DATA A");
 grDATA_MeeemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MeeemuA->GetYaxis()->SetTitle("Mee/e#mu A");
 grDATA_MeeemuA->SetMarkerColor(kBlack);
 grDATA_MeeemuA->SetFillColor(kWhite);
 grDATA_MeeemuA->SetLineColor(kBlack);
 grDATA_MeeemuA->SetMarkerStyle(25);
 grDATA_MeeemuA->SetMarkerSize(1);
 grDATA_MeeemuA->SetLineWidth(2);
 
 TGraphErrors* grDATA_MmumuemuA = new TGraphErrors(numPlotM,XM,DATA_MmumuemuA,errXM,DATA_errMmumuemuA);
 grDATA_MmumuemuA->SetTitle("M#mu#mu/e#mu DATA A");
 grDATA_MmumuemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MmumuemuA->GetYaxis()->SetTitle("M#mu#mu/e#mu A");
 grDATA_MmumuemuA->SetMarkerColor(kBlack);
 grDATA_MmumuemuA->SetFillColor(kWhite);
 grDATA_MmumuemuA->SetLineColor(kBlack);
 grDATA_MmumuemuA->SetMarkerStyle(25);
 grDATA_MmumuemuA->SetMarkerSize(1);
 grDATA_MmumuemuA->SetLineWidth(2);
 
 TGraphErrors* grDATA_MeemueA = new TGraphErrors(numPlotM,XM,DATA_MeemueA,errXM,DATA_errMeemueA);
 grDATA_MeemueA->SetTitle("Mee/#mue DATA A");
 grDATA_MeemueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MeemueA->GetYaxis()->SetTitle("Mee/#mue A");
 grDATA_MeemueA->SetMarkerColor(kBlack);
 grDATA_MeemueA->SetFillColor(kWhite);
 grDATA_MeemueA->SetLineColor(kBlack);
 grDATA_MeemueA->SetMarkerStyle(25);
 grDATA_MeemueA->SetMarkerSize(1);
 grDATA_MeemueA->SetLineWidth(2);
 
 TGraphErrors* grDATA_MmumumueA = new TGraphErrors(numPlotM,XM,DATA_MmumumueA,errXM,DATA_errMmumumueA);
 grDATA_MmumumueA->SetTitle("M#mu#mu/#mue DATA A");
 grDATA_MmumumueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MmumumueA->GetYaxis()->SetTitle("M#mu#mu/#mue A");
 grDATA_MmumumueA->SetMarkerColor(kBlack);
 grDATA_MmumumueA->SetFillColor(kWhite);
 grDATA_MmumumueA->SetLineColor(kBlack);
 grDATA_MmumumueA->SetMarkerStyle(25);
 grDATA_MmumumueA->SetMarkerSize(1);
 grDATA_MmumumueA->SetLineWidth(2);
 
 
 
 
 
 
 
 
 TGraphErrors* grDATA_MeeemuB = new TGraphErrors(numPlotM,XMShift,DATA_MeeemuB,errXMShift,DATA_errMeeemuB);
 grDATA_MeeemuB->SetTitle("Mee/e#mu DATA B");
 grDATA_MeeemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MeeemuB->GetYaxis()->SetTitle("Mee/e#mu B");
 grDATA_MeeemuB->SetMarkerColor(kBlack);
 grDATA_MeeemuB->SetFillColor(kWhite);
 grDATA_MeeemuB->SetLineColor(kBlack);
 grDATA_MeeemuB->SetMarkerStyle(21);
 grDATA_MeeemuB->SetMarkerSize(1);
 grDATA_MeeemuB->SetLineWidth(2);
 grDATA_MeeemuB->SetLineStyle(2);
 
 TGraphErrors* grDATA_MmumuemuB = new TGraphErrors(numPlotM,XMShift,DATA_MmumuemuB,errXMShift,DATA_errMmumuemuB);
 grDATA_MmumuemuB->SetTitle("M#mu#mu/e#mu DATA B");
 grDATA_MmumuemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MmumuemuB->GetYaxis()->SetTitle("M#mu#mu/e#mu B");
 grDATA_MmumuemuB->SetMarkerColor(kBlack);
 grDATA_MmumuemuB->SetFillColor(kWhite);
 grDATA_MmumuemuB->SetLineColor(kBlack);
 grDATA_MmumuemuB->SetMarkerStyle(21);
 grDATA_MmumuemuB->SetMarkerSize(1);
 grDATA_MmumuemuB->SetLineWidth(2);
 grDATA_MmumuemuB->SetLineStyle(2);
 
 TGraphErrors* grDATA_MeemueB = new TGraphErrors(numPlotM,XMShift,DATA_MeemueB,errXMShift,DATA_errMeemueB);
 grDATA_MeemueB->SetTitle("Mee/#mue DATA B");
 grDATA_MeemueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MeemueB->GetYaxis()->SetTitle("Mee/#mue B");
 grDATA_MeemueB->SetMarkerColor(kBlack);
 grDATA_MeemueB->SetFillColor(kWhite);
 grDATA_MeemueB->SetLineColor(kBlack);
 grDATA_MeemueB->SetMarkerStyle(21);
 grDATA_MeemueB->SetMarkerSize(1);
 grDATA_MeemueB->SetLineWidth(2);
 grDATA_MeemueB->SetLineStyle(2);
 
 TGraphErrors* grDATA_MmumumueB = new TGraphErrors(numPlotM,XMShift,DATA_MmumumueB,errXMShift,DATA_errMmumumueB);
 grDATA_MmumumueB->SetTitle("M#mu#mu/#mue DATA B");
 grDATA_MmumumueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_MmumumueB->GetYaxis()->SetTitle("M#mu#mu/#mue B");
 grDATA_MmumumueB->SetMarkerColor(kBlack);
 grDATA_MmumumueB->SetFillColor(kWhite);
 grDATA_MmumumueB->SetLineColor(kBlack);
 grDATA_MmumumueB->SetMarkerStyle(21);
 grDATA_MmumumueB->SetMarkerSize(1);
 grDATA_MmumumueB->SetLineWidth(2);
 grDATA_MmumumueB->SetLineStyle(2);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 TGraphErrors* grother_MeeemuA = new TGraphErrors(numPlotM,XM,other_MeeemuA,errXM,other_errMeeemuA);
 grother_MeeemuA->SetTitle("Mee/e#mu other A");
 grother_MeeemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MeeemuA->GetYaxis()->SetTitle("Mee/e#mu A");
 grother_MeeemuA->SetMarkerColor(kBlue);
 grother_MeeemuA->SetFillColor(kWhite);
 grother_MeeemuA->SetLineColor(kBlue);
 grother_MeeemuA->SetMarkerStyle(25);
 grother_MeeemuA->SetMarkerSize(1);
 grother_MeeemuA->SetLineWidth(2);
 
 TGraphErrors* grother_MmumuemuA = new TGraphErrors(numPlotM,XM,other_MmumuemuA,errXM,other_errMmumuemuA);
 grother_MmumuemuA->SetTitle("M#mu#mu/e#mu other A");
 grother_MmumuemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MmumuemuA->GetYaxis()->SetTitle("M#mu#mu/e#mu A");
 grother_MmumuemuA->SetMarkerColor(kBlue);
 grother_MmumuemuA->SetFillColor(kWhite);
 grother_MmumuemuA->SetLineColor(kBlue);
 grother_MmumuemuA->SetMarkerStyle(25);
 grother_MmumuemuA->SetMarkerSize(1);
 grother_MmumuemuA->SetLineWidth(2);
 
 TGraphErrors* grother_MeemueA = new TGraphErrors(numPlotM,XM,other_MeemueA,errXM,other_errMeemueA);
 grother_MeemueA->SetTitle("Mee/#mue other A");
 grother_MeemueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MeemueA->GetYaxis()->SetTitle("Mee/#mue A");
 grother_MeemueA->SetMarkerColor(kBlue);
 grother_MeemueA->SetFillColor(kWhite);
 grother_MeemueA->SetLineColor(kBlue);
 grother_MeemueA->SetMarkerStyle(25);
 grother_MeemueA->SetMarkerSize(1);
 grother_MeemueA->SetLineWidth(2);
 
 TGraphErrors* grother_MmumumueA = new TGraphErrors(numPlotM,XM,other_MmumumueA,errXM,other_errMmumumueA);
 grother_MmumumueA->SetTitle("M#mu#mu/#mue other A");
 grother_MmumumueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MmumumueA->GetYaxis()->SetTitle("M#mu#mu/#mue A");
 grother_MmumumueA->SetMarkerColor(kBlue);
 grother_MmumumueA->SetFillColor(kWhite);
 grother_MmumumueA->SetLineColor(kBlue);
 grother_MmumumueA->SetMarkerStyle(25);
 grother_MmumumueA->SetMarkerSize(1);
 grother_MmumumueA->SetLineWidth(2);
 
 
 
 
 
 
 
 
 TGraphErrors* grother_MeeemuB = new TGraphErrors(numPlotM,XMShift,other_MeeemuB,errXMShift,other_errMeeemuB);
 grother_MeeemuB->SetTitle("Mee/e#mu other B");
 grother_MeeemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MeeemuB->GetYaxis()->SetTitle("Mee/e#mu B");
 grother_MeeemuB->SetMarkerColor(kBlue);
 grother_MeeemuB->SetFillColor(kWhite);
 grother_MeeemuB->SetLineColor(kBlue);
 grother_MeeemuB->SetMarkerStyle(21);
 grother_MeeemuB->SetMarkerSize(1);
 grother_MeeemuB->SetLineWidth(2);
 grother_MeeemuB->SetLineStyle(2);
 
 TGraphErrors* grother_MmumuemuB = new TGraphErrors(numPlotM,XMShift,other_MmumuemuB,errXMShift,other_errMmumuemuB);
 grother_MmumuemuB->SetTitle("M#mu#mu/e#mu other B");
 grother_MmumuemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MmumuemuB->GetYaxis()->SetTitle("M#mu#mu/e#mu B");
 grother_MmumuemuB->SetMarkerColor(kBlue);
 grother_MmumuemuB->SetFillColor(kWhite);
 grother_MmumuemuB->SetLineColor(kBlue);
 grother_MmumuemuB->SetMarkerStyle(21);
 grother_MmumuemuB->SetMarkerSize(1);
 grother_MmumuemuB->SetLineWidth(2);
 grother_MmumuemuB->SetLineStyle(2);
 
 TGraphErrors* grother_MeemueB = new TGraphErrors(numPlotM,XMShift,other_MeemueB,errXMShift,other_errMeemueB);
 grother_MeemueB->SetTitle("Mee/#mue other B");
 grother_MeemueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MeemueB->GetYaxis()->SetTitle("Mee/#mue B");
 grother_MeemueB->SetMarkerColor(kBlue);
 grother_MeemueB->SetFillColor(kWhite);
 grother_MeemueB->SetLineColor(kBlue);
 grother_MeemueB->SetMarkerStyle(21);
 grother_MeemueB->SetMarkerSize(1);
 grother_MeemueB->SetLineWidth(2);
 grother_MeemueB->SetLineStyle(2);
 
 TGraphErrors* grother_MmumumueB = new TGraphErrors(numPlotM,XMShift,other_MmumumueB,errXMShift,other_errMmumumueB);
 grother_MmumumueB->SetTitle("M#mu#mu/#mue other B");
 grother_MmumumueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_MmumumueB->GetYaxis()->SetTitle("M#mu#mu/#mue B");
 grother_MmumumueB->SetMarkerColor(kBlue);
 grother_MmumumueB->SetFillColor(kWhite);
 grother_MmumumueB->SetLineColor(kBlue);
 grother_MmumumueB->SetMarkerStyle(21);
 grother_MmumumueB->SetMarkerSize(1);
 grother_MmumumueB->SetLineWidth(2);
 grother_MmumumueB->SetLineStyle(2);
 
 
 
 
 
 
 TGraphErrors* grall_MeeemuA = new TGraphErrors(numPlotM,XM,all_MeeemuA,errXM,all_errMeeemuA);
 grall_MeeemuA->SetTitle("Mee/e#mu all A");
 grall_MeeemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MeeemuA->GetYaxis()->SetTitle("Mee/e#mu A");
 grall_MeeemuA->SetMarkerColor(kRed);
 grall_MeeemuA->SetFillColor(kWhite);
 grall_MeeemuA->SetLineColor(kRed);
 grall_MeeemuA->SetMarkerStyle(25);
 grall_MeeemuA->SetMarkerSize(1);
 grall_MeeemuA->SetLineWidth(2);
 
 TGraphErrors* grall_MmumuemuA = new TGraphErrors(numPlotM,XM,all_MmumuemuA,errXM,all_errMmumuemuA);
 grall_MmumuemuA->SetTitle("M#mu#mu/e#mu all A");
 grall_MmumuemuA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MmumuemuA->GetYaxis()->SetTitle("M#mu#mu/e#mu A");
 grall_MmumuemuA->SetMarkerColor(kRed);
 grall_MmumuemuA->SetFillColor(kWhite);
 grall_MmumuemuA->SetLineColor(kRed);
 grall_MmumuemuA->SetMarkerStyle(25);
 grall_MmumuemuA->SetMarkerSize(1);
 grall_MmumuemuA->SetLineWidth(2);
 
 TGraphErrors* grall_MeemueA = new TGraphErrors(numPlotM,XM,all_MeemueA,errXM,all_errMeemueA);
 grall_MeemueA->SetTitle("Mee/#mue all A");
 grall_MeemueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MeemueA->GetYaxis()->SetTitle("Mee/#mue A");
 grall_MeemueA->SetMarkerColor(kRed);
 grall_MeemueA->SetFillColor(kWhite);
 grall_MeemueA->SetLineColor(kRed);
 grall_MeemueA->SetMarkerStyle(25);
 grall_MeemueA->SetMarkerSize(1);
 grall_MeemueA->SetLineWidth(2);
 
 TGraphErrors* grall_MmumumueA = new TGraphErrors(numPlotM,XM,all_MmumumueA,errXM,all_errMmumumueA);
 grall_MmumumueA->SetTitle("M#mu#mu/#mue all A");
 grall_MmumumueA->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MmumumueA->GetYaxis()->SetTitle("M#mu#mu/#mue A");
 grall_MmumumueA->SetMarkerColor(kRed);
 grall_MmumumueA->SetFillColor(kWhite);
 grall_MmumumueA->SetLineColor(kRed);
 grall_MmumumueA->SetMarkerStyle(25);
 grall_MmumumueA->SetMarkerSize(1);
 grall_MmumumueA->SetLineWidth(2);
 
 
 
 
 
 
 
 
 TGraphErrors* grall_MeeemuB = new TGraphErrors(numPlotM,XMShift,all_MeeemuB,errXMShift,all_errMeeemuB);
 grall_MeeemuB->SetTitle("Mee/e#mu all B");
 grall_MeeemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MeeemuB->GetYaxis()->SetTitle("Mee/e#mu B");
 grall_MeeemuB->SetMarkerColor(kRed);
 grall_MeeemuB->SetFillColor(kWhite);
 grall_MeeemuB->SetLineColor(kRed);
 grall_MeeemuB->SetMarkerStyle(21);
 grall_MeeemuB->SetMarkerSize(1);
 grall_MeeemuB->SetLineWidth(2);
 grall_MeeemuB->SetLineStyle(2);
 
 TGraphErrors* grall_MmumuemuB = new TGraphErrors(numPlotM,XMShift,all_MmumuemuB,errXMShift,all_errMmumuemuB);
 grall_MmumuemuB->SetTitle("M#mu#mu/e#mu all B");
 grall_MmumuemuB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MmumuemuB->GetYaxis()->SetTitle("M#mu#mu/e#mu B");
 grall_MmumuemuB->SetMarkerColor(kRed);
 grall_MmumuemuB->SetFillColor(kWhite);
 grall_MmumuemuB->SetLineColor(kRed);
 grall_MmumuemuB->SetMarkerStyle(21);
 grall_MmumuemuB->SetMarkerSize(1);
 grall_MmumuemuB->SetLineWidth(2);
 grall_MmumuemuB->SetLineStyle(2);
 
 TGraphErrors* grall_MeemueB = new TGraphErrors(numPlotM,XMShift,all_MeemueB,errXMShift,all_errMeemueB);
 grall_MeemueB->SetTitle("Mee/#mue all B");
 grall_MeemueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MeemueB->GetYaxis()->SetTitle("Mee/#mue B");
 grall_MeemueB->SetMarkerColor(kRed);
 grall_MeemueB->SetFillColor(kWhite);
 grall_MeemueB->SetLineColor(kRed);
 grall_MeemueB->SetMarkerStyle(21);
 grall_MeemueB->SetMarkerSize(1);
 grall_MeemueB->SetLineWidth(2);
 grall_MeemueB->SetLineStyle(2);
 
 TGraphErrors* grall_MmumumueB = new TGraphErrors(numPlotM,XMShift,all_MmumumueB,errXMShift,all_errMmumumueB);
 grall_MmumumueB->SetTitle("M#mu#mu/#mue all B");
 grall_MmumumueB->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_MmumumueB->GetYaxis()->SetTitle("M#mu#mu/#mue B");
 grall_MmumumueB->SetMarkerColor(kRed);
 grall_MmumumueB->SetFillColor(kWhite);
 grall_MmumumueB->SetLineColor(kRed);
 grall_MmumumueB->SetMarkerStyle(21);
 grall_MmumumueB->SetMarkerSize(1);
 grall_MmumumueB->SetLineWidth(2);
 grall_MmumumueB->SetLineStyle(2);
 
 
 
 ///==== Plot canvas ====
 
 TCanvas* cDATA_Meeemu = new TCanvas("cDATA_Meeemu","cDATA_Meeemu",700,700); 
 TMultiGraph* mgr_Meeemu = new TMultiGraph(); 
 mgr_Meeemu->Add(grall_MeeemuA);
 mgr_Meeemu->Add(grother_MeeemuA);
 mgr_Meeemu->Add(grDATA_MeeemuA);
 mgr_Meeemu->Add(grall_MeeemuB);
 mgr_Meeemu->Add(grother_MeeemuB);
 mgr_Meeemu->Add(grDATA_MeeemuB);
 mgr_Meeemu->Draw("AP");
 mgr_Meeemu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_Meeemu->GetYaxis()->SetTitle("M ee/e#mu");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas* cDATA_Meemue = new TCanvas("cDATA_Meemue","cDATA_Meemue",700,700); 
 TMultiGraph* mgr_Meemue = new TMultiGraph(); 
 mgr_Meemue->Add(grall_MeemueA);
 mgr_Meemue->Add(grother_MeemueA);
 mgr_Meemue->Add(grDATA_MeemueA);
 mgr_Meemue->Add(grall_MeemueB);
 mgr_Meemue->Add(grother_MeemueB);
 mgr_Meemue->Add(grDATA_MeemueB);
 mgr_Meemue->Draw("AP");
 mgr_Meemue->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_Meemue->GetYaxis()->SetTitle("M ee/#mue");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 TCanvas* cDATA_Mmumuemu = new TCanvas("cDATA_Mmumuemu","cDATA_Mmumuemu",700,700); 
 TMultiGraph* mgr_Mmumuemu = new TMultiGraph(); 
 mgr_Mmumuemu->Add(grall_MmumuemuA);
 mgr_Mmumuemu->Add(grother_MmumuemuA);
 mgr_Mmumuemu->Add(grDATA_MmumuemuA);
 mgr_Mmumuemu->Add(grall_MmumuemuB);
 mgr_Mmumuemu->Add(grother_MmumuemuB);
 mgr_Mmumuemu->Add(grDATA_MmumuemuB);
 mgr_Mmumuemu->Draw("AP");
 mgr_Mmumuemu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_Mmumuemu->GetYaxis()->SetTitle("M #mu#mu/e#mu");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 TCanvas* cDATA_Mmumumue = new TCanvas("cDATA_Mmumumue","cDATA_Mmumumue",700,700); 
 TMultiGraph* mgr_Mmumumue = new TMultiGraph(); 
 mgr_Mmumumue->Add(grall_MmumumueA);
 mgr_Mmumumue->Add(grother_MmumumueA);
 mgr_Mmumumue->Add(grDATA_MmumumueA);
 mgr_Mmumumue->Add(grall_MmumumueB);
 mgr_Mmumumue->Add(grother_MmumumueB);
 mgr_Mmumumue->Add(grDATA_MmumumueB);
 mgr_Mmumumue->Draw("AP");
 mgr_Mmumumue->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_Mmumumue->GetYaxis()->SetTitle("M #mu#mu/#mue");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 ///==================================================
 ///==== plot of NDY corrected: with R method and M method ====
 ///==================================================
 
 ///==============
 ///==== A zone ====
 ///==============
 
  TCanvas* cNmumuACorrected = new TCanvas("cNmumuACorrected","cNmumuACorrected",800,800); 

  TGraphErrors* grDATA_NmumuA_Corrected_standardR = new TGraphErrors(numPlot,X,DATA_NDYCorrected_standardR_A_mumu,errX,DATA_errNDYCorrected_standardR_A_mumu);
  grDATA_NmumuA_Corrected_standardR->SetTitle("N #mu#mu DATA corrected standardR");
  grDATA_NmumuA_Corrected_standardR->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 grDATA_NmumuA_Corrected_R->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NmumuA_Corrected_R->GetYaxis()->SetTitle("N #mu#mu");
 grDATA_NmumuA_Corrected_R->SetMarkerColor(kTeal);
 grDATA_NmumuA_Corrected_R->SetFillColor(kWhite);
 grDATA_NmumuA_Corrected_R->SetLineColor(kTeal);
 grDATA_NmumuA_Corrected_R->SetMarkerStyle(20);
 grDATA_NmumuA_Corrected_R->SetMarkerSize(1);
 grDATA_NmumuA_Corrected_R->SetLineWidth(2);
 grDATA_NmumuA_Corrected_R->SetLineStyle(2);
 
 
 TGraphErrors* grDATA_NmumuA_Corrected_M = new TGraphErrors(numPlot,X,DATA_NDYCorrected_M_A_mumu,errX,DATA_errNDYCorrected_M_A_mumu);
 grDATA_NmumuA_Corrected_M->SetTitle("N #mu#mu DATA corrected M");
 grDATA_NmumuA_Corrected_M->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NmumuA_Corrected_M->GetYaxis()->SetTitle("N #mu#mu");
 grDATA_NmumuA_Corrected_M->SetMarkerColor(kMagenta);
 grDATA_NmumuA_Corrected_M->SetFillColor(kWhite);
 grDATA_NmumuA_Corrected_M->SetLineColor(kMagenta);
 grDATA_NmumuA_Corrected_M->SetMarkerStyle(20);
 grDATA_NmumuA_Corrected_M->SetMarkerSize(1);
 grDATA_NmumuA_Corrected_M->SetLineWidth(2);
 grDATA_NmumuA_Corrected_M->SetLineStyle(2);
 
 
 TMultiGraph* mgr_NmumuA_all = new TMultiGraph(); 
 mgr_NmumuA_all->Add(grDATA_NmumuA);
 mgr_NmumuA_all->Add(grDY_NmumuA);
//  mgr_NmumuA_all->Add(grDYmad_NmumuA);
 mgr_NmumuA_all->Add(grother_NmumuA);
 mgr_NmumuA_all->Add(grall_NmumuA);
//  mgr_NmumuA_all->Add(grDATA_NmumuA_Corrected_standardR);
 mgr_NmumuA_all->Add(grDATA_NmumuA_Corrected_R);
 mgr_NmumuA_all->Add(grDATA_NmumuA_Corrected_M);
 mgr_NmumuA_all->Draw("AP");
 mgr_NmumuA_all->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_NmumuA_all->GetYaxis()->SetTitle("N #mu#mu");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas* cNeeACorrected = new TCanvas("cNeeACorrected","cNeeACorrected",800,800); 

 TGraphErrors* grDATA_NeeA_Corrected_standardR = new TGraphErrors(numPlot,X,DATA_NDYCorrected_standardR_A_ee,errX,DATA_errNDYCorrected_standardR_A_ee);
 grDATA_NeeA_Corrected_standardR->SetTitle("N ee DATA corrected standardR");
 grDATA_NeeA_Corrected_standardR->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 grDATA_NeeA_Corrected_R->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NeeA_Corrected_R->GetYaxis()->SetTitle("N ee");
 grDATA_NeeA_Corrected_R->SetMarkerColor(kTeal);
 grDATA_NeeA_Corrected_R->SetFillColor(kWhite);
 grDATA_NeeA_Corrected_R->SetLineColor(kTeal);
 grDATA_NeeA_Corrected_R->SetMarkerStyle(20);
 grDATA_NeeA_Corrected_R->SetMarkerSize(1);
 grDATA_NeeA_Corrected_R->SetLineWidth(2);
 grDATA_NeeA_Corrected_R->SetLineStyle(2);
 
 
 TGraphErrors* grDATA_NeeA_Corrected_M = new TGraphErrors(numPlot,X,DATA_NDYCorrected_M_A_ee,errX,DATA_errNDYCorrected_M_A_ee);
 grDATA_NeeA_Corrected_M->SetTitle("N ee DATA corrected M");
 grDATA_NeeA_Corrected_M->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NeeA_Corrected_M->GetYaxis()->SetTitle("N ee");
 grDATA_NeeA_Corrected_M->SetMarkerColor(kMagenta);
 grDATA_NeeA_Corrected_M->SetFillColor(kWhite);
 grDATA_NeeA_Corrected_M->SetLineColor(kMagenta);
 grDATA_NeeA_Corrected_M->SetMarkerStyle(20);
 grDATA_NeeA_Corrected_M->SetMarkerSize(1);
 grDATA_NeeA_Corrected_M->SetLineWidth(2);
 grDATA_NeeA_Corrected_M->SetLineStyle(2);
 
 
 TMultiGraph* mgr_NeeA_all = new TMultiGraph(); 
 mgr_NeeA_all->Add(grDATA_NeeA);
 mgr_NeeA_all->Add(grDY_NeeA);
//  mgr_NeeA_all->Add(grDYmad_NeeA);
 mgr_NeeA_all->Add(grother_NeeA);
 mgr_NeeA_all->Add(grall_NeeA);
//  mgr_NeeA_all->Add(grDATA_NeeA_Corrected_standardR);
 mgr_NeeA_all->Add(grDATA_NeeA_Corrected_R);
 mgr_NeeA_all->Add(grDATA_NeeA_Corrected_M);
 mgr_NeeA_all->Draw("AP");
 mgr_NeeA_all->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_NeeA_all->GetYaxis()->SetTitle("N ee");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 ///==== Correction coefficients as a function of met cut ====
 
 
 double CorrectionFactor_ee_standardR[100];
 double CorrectionFactor_mumu_standardR[100];
 double CorrectionFactor_ee_R[100];
 double CorrectionFactor_mumu_R[100];
 double CorrectionFactor_ee_M[100];
 double CorrectionFactor_mumu_M[100];
 
 double errCorrectionFactor_ee_standardR[100];
 double errCorrectionFactor_mumu_standardR[100];
 double errCorrectionFactor_ee_R[100];
 double errCorrectionFactor_mumu_R[100];
 double errCorrectionFactor_ee_M[100];
 double errCorrectionFactor_mumu_M[100];
 
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
  
  grDATA_NeeA_Corrected_M->GetPoint(iPoint,_xU,_yU);
  grDY_NeeA->GetPoint(iPoint,_xD,_yD);
  _erryU = grDATA_NeeA_Corrected_M->GetErrorY(iPoint);
  _erryD = grDY_NeeA->GetErrorY(iPoint);  
  CorrectionFactor_ee_M[iPoint] = _yU / _yD;
  errCorrectionFactor_ee_M[iPoint] = sqrt(_erryU / _yD * _erryU / _yD + _erryD / _yD / _yD * _yU * _erryD / _yD / _yD * _yU) ;
  
  
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
  
  grDATA_NmumuA_Corrected_M->GetPoint(iPoint,_xU,_yU);
  grDY_NmumuA->GetPoint(iPoint,_xD,_yD);
  _erryU = grDATA_NmumuA_Corrected_M->GetErrorY(iPoint);
  _erryD = grDY_NmumuA->GetErrorY(iPoint);  
  CorrectionFactor_mumu_M[iPoint] = _yU / _yD;
  errCorrectionFactor_mumu_M[iPoint] = sqrt(_erryU / _yD * _erryU / _yD + _erryD / _yD / _yD * _yU * _erryD / _yD / _yD * _yU) ;
   
 }
 
 
 
 
 TCanvas* cCorrectionFactor_ee = new TCanvas("cCorrectionFactor_ee","cCorrectionFactor_ee",800,800); 
 
 TGraphErrors* grCorrectionFactor_ee_standardR = new TGraphErrors(numPlot,X,CorrectionFactor_ee_standardR,errX,errCorrectionFactor_ee_standardR);
 grCorrectionFactor_ee_standardR->SetTitle("Scale factor ee standardR");
 grCorrectionFactor_ee_standardR->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 grCorrectionFactor_ee_R->GetXaxis()->SetTitle("met > threshold (GeV)");
 grCorrectionFactor_ee_R->GetYaxis()->SetTitle("Scale ee");
 grCorrectionFactor_ee_R->SetMarkerColor(kBlue);
 grCorrectionFactor_ee_R->SetFillColor(kWhite);
 grCorrectionFactor_ee_R->SetLineColor(kBlue);
 grCorrectionFactor_ee_R->SetMarkerStyle(24);
 grCorrectionFactor_ee_R->SetMarkerSize(1);
 grCorrectionFactor_ee_R->SetLineWidth(2);
 grCorrectionFactor_ee_R->SetLineStyle(2);
 
 
 TGraphErrors* grCorrectionFactor_ee_M = new TGraphErrors(numPlot,X,CorrectionFactor_ee_M,errX,errCorrectionFactor_ee_M);
 grCorrectionFactor_ee_M->SetTitle("Scale factor ee M");
 grCorrectionFactor_ee_M->GetXaxis()->SetTitle("met > threshold (GeV)");
 grCorrectionFactor_ee_M->GetYaxis()->SetTitle("Scale ee");
 grCorrectionFactor_ee_M->SetMarkerColor(kBlue);
 grCorrectionFactor_ee_M->SetFillColor(kWhite);
 grCorrectionFactor_ee_M->SetLineColor(kBlue);
 grCorrectionFactor_ee_M->SetMarkerStyle(26);
 grCorrectionFactor_ee_M->SetMarkerSize(1);
 grCorrectionFactor_ee_M->SetLineWidth(2);
 grCorrectionFactor_ee_M->SetLineStyle(2);
 
 
 TMultiGraph* mgr_CorrectionFactor_ee = new TMultiGraph(); 
 mgr_CorrectionFactor_ee->Add(grCorrectionFactor_ee_standardR);
 mgr_CorrectionFactor_ee->Add(grCorrectionFactor_ee_R);
 mgr_CorrectionFactor_ee->Add(grCorrectionFactor_ee_M);
 mgr_CorrectionFactor_ee->Draw("AP");
 mgr_CorrectionFactor_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_CorrectionFactor_ee->GetYaxis()->SetTitle("Scale ee");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 TCanvas* cCorrectionFactor_mumu = new TCanvas("cCorrectionFactor_mumu","cCorrectionFactor_mumu",800,800); 
 
 TGraphErrors* grCorrectionFactor_mumu_standardR = new TGraphErrors(numPlot,X,CorrectionFactor_mumu_standardR,errX,errCorrectionFactor_mumu_standardR);
 grCorrectionFactor_mumu_standardR->SetTitle("Scale factor #mu#mu standardR");
 grCorrectionFactor_mumu_standardR->GetXaxis()->SetTitle("met > threshold (GeV)");
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
 grCorrectionFactor_mumu_R->GetXaxis()->SetTitle("met > threshold (GeV)");
 grCorrectionFactor_mumu_R->GetYaxis()->SetTitle("Scale #mu#mu");
 grCorrectionFactor_mumu_R->SetMarkerColor(kBlue);
 grCorrectionFactor_mumu_R->SetFillColor(kWhite);
 grCorrectionFactor_mumu_R->SetLineColor(kBlue);
 grCorrectionFactor_mumu_R->SetMarkerStyle(24);
 grCorrectionFactor_mumu_R->SetMarkerSize(1);
 grCorrectionFactor_mumu_R->SetLineWidth(2);
 grCorrectionFactor_mumu_R->SetLineStyle(2);
 
 
 TGraphErrors* grCorrectionFactor_mumu_M = new TGraphErrors(numPlot,X,CorrectionFactor_mumu_M,errX,errCorrectionFactor_mumu_M);
 grCorrectionFactor_mumu_M->SetTitle("Scale factor #mu#mu M");
 grCorrectionFactor_mumu_M->GetXaxis()->SetTitle("met > threshold (GeV)");
 grCorrectionFactor_mumu_M->GetYaxis()->SetTitle("Scale #mu#mu");
 grCorrectionFactor_mumu_M->SetMarkerColor(kBlue);
 grCorrectionFactor_mumu_M->SetFillColor(kWhite);
 grCorrectionFactor_mumu_M->SetLineColor(kBlue);
 grCorrectionFactor_mumu_M->SetMarkerStyle(26);
 grCorrectionFactor_mumu_M->SetMarkerSize(1);
 grCorrectionFactor_mumu_M->SetLineWidth(2);
 grCorrectionFactor_mumu_M->SetLineStyle(2);
 
 
 TMultiGraph* mgr_CorrectionFactor_mumu = new TMultiGraph(); 
 mgr_CorrectionFactor_mumu->Add(grCorrectionFactor_mumu_standardR);
 mgr_CorrectionFactor_mumu->Add(grCorrectionFactor_mumu_R);
 mgr_CorrectionFactor_mumu->Add(grCorrectionFactor_mumu_M);
 mgr_CorrectionFactor_mumu->Draw("AP");
 mgr_CorrectionFactor_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_CorrectionFactor_mumu->GetYaxis()->SetTitle("Scale #mu#mu");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 
 
 
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  ///==== plot of R ====
//  
//  TCanvas* cDATA_R = new TCanvas("cDATA_R","cDATA_R",800,800); 
//  
//  TGraphErrors* grDATA_R_ee = new TGraphErrors(numPlot,X,DATA_R_ee,errX,DATA_errR_ee);
//  grDATA_R_ee->SetTitle("Ree");
//  grDATA_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
//  grDATA_R_ee->GetYaxis()->SetTitle("Ree");
//  grDATA_R_ee->SetMarkerColor(kRed);
//  grDATA_R_ee->SetFillColor(kWhite);
//  grDATA_R_ee->SetLineColor(kRed);
//  grDATA_R_ee->SetMarkerStyle(25);
//  grDATA_R_ee->SetMarkerSize(1);
//  grDATA_R_ee->SetLineWidth(2);
//  
//  
//  TGraphErrors* grDATA_R_mumu = new TGraphErrors(numPlot,X,DATA_R_mumu,errX,DATA_errR_mumu);
//  grDATA_R_mumu->SetTitle("R #mu#mu");
//  grDATA_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
//  grDATA_R_mumu->GetYaxis()->SetTitle("R #mu#mu");
//  grDATA_R_mumu->SetMarkerColor(kBlue);
//  grDATA_R_mumu->SetFillColor(kWhite);
//  grDATA_R_mumu->SetLineColor(kBlue);
//  grDATA_R_mumu->SetMarkerStyle(26);
//  grDATA_R_mumu->SetMarkerSize(1);
//  grDATA_R_mumu->SetLineWidth(2);
//  
// 
//  TGraphErrors* grDY_R_ee = new TGraphErrors(numPlot,X,DY_R_ee,errX,DY_errR_ee);
//  grDY_R_ee->SetTitle("Ree DY");
//  grDY_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
//  grDY_R_ee->GetYaxis()->SetTitle("Ree DY");
//  grDY_R_ee->SetMarkerColor(kRed);
//  grDY_R_ee->SetFillColor(kWhite);
//  grDY_R_ee->SetLineColor(kRed);
//  grDY_R_ee->SetMarkerStyle(21);
//  grDY_R_ee->SetMarkerSize(1);
//  grDY_R_ee->SetLineWidth(2);
//  
//  
//  TGraphErrors* grDY_R_mumu = new TGraphErrors(numPlot,X,DY_R_mumu,errX,DY_errR_mumu);
//  grDY_R_mumu->SetTitle("R #mu#mu DY");
//  grDY_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
//  grDY_R_mumu->GetYaxis()->SetTitle("R #mu#mu DY");
//  grDY_R_mumu->SetMarkerColor(kBlue);
//  grDY_R_mumu->SetFillColor(kWhite);
//  grDY_R_mumu->SetLineColor(kBlue);
//  grDY_R_mumu->SetMarkerStyle(22);
//  grDY_R_mumu->SetMarkerSize(1);
//  grDY_R_mumu->SetLineWidth(2);
//  
//  
//  
//  TGraphErrors* grDYmad_R_ee = new TGraphErrors(numPlot,X,DYmad_R_ee,errX,DYmad_errR_ee);
//  grDYmad_R_ee->SetTitle("Ree DYmad");
//  grDYmad_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
//  grDYmad_R_ee->GetYaxis()->SetTitle("Ree DYmad");
//  grDYmad_R_ee->SetMarkerColor(kRed);
//  grDYmad_R_ee->SetFillColor(kWhite);
//  grDYmad_R_ee->SetLineColor(kRed);
//  grDYmad_R_ee->SetMarkerStyle(23);
//  grDYmad_R_ee->SetMarkerSize(1);
//  grDYmad_R_ee->SetLineWidth(2);
//  
//  
//  TGraphErrors* grDYmad_R_mumu = new TGraphErrors(numPlot,X,DYmad_R_mumu,errX,DYmad_errR_mumu);
//  grDYmad_R_mumu->SetTitle("R #mu#mu DYmad");
//  grDYmad_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
//  grDYmad_R_mumu->GetYaxis()->SetTitle("R #mu#mu DYmad");
//  grDYmad_R_mumu->SetMarkerColor(kBlue);
//  grDYmad_R_mumu->SetFillColor(kWhite);
//  grDYmad_R_mumu->SetLineColor(kBlue);
//  grDYmad_R_mumu->SetMarkerStyle(29);
//  grDYmad_R_mumu->SetMarkerSize(1);
//  grDYmad_R_mumu->SetLineWidth(2);
//  
//  
//   
//  TMultiGraph* mgr_DATA_R = new TMultiGraph(); 
//  mgr_DATA_R->Add(grDATA_R_ee);
//  mgr_DATA_R->Add(grDATA_R_mumu);
//  mgr_DATA_R->Add(grDY_R_ee);
//  mgr_DATA_R->Add(grDY_R_mumu); 
//  mgr_DATA_R->Add(grDYmad_R_ee);
//  mgr_DATA_R->Add(grDYmad_R_mumu); 
//  mgr_DATA_R->Draw("AP");
//  mgr_DATA_R->GetXaxis()->SetTitle("met > threshold (GeV)");
//  mgr_DATA_R->GetYaxis()->SetTitle("R");
//  
//  TLegend* leg = gPad->BuildLegend();
//  leg->SetFillColor(kWhite);
//  gPad->SetGrid();
//  
//  
//  
//  
//  
//  
//  
//  
//  std::cout << " # ******************************** " << std::endl;
//  std::cout << " # **** for Bayesian inference **** " << std::endl;
//  std::cout << " # ******************************** " << std::endl;
//  std::cout << " # ******************************** " << std::endl;
//  std::cout << " # ************** R *************** " << std::endl;
//  std::cout << " # ******************************** " << std::endl;
//  std::cout << std::endl;
//  std::cout << " NeeA <-         " <<  DATA_NeeA[numPointForRCalculation]   << std::endl;
//  std::cout << " NeeB <-         " <<  DATA_NeeB[numPointForRCalculation]   << std::endl;
//  std::cout << std::endl;
//  std::cout << " NmumuA <-       " <<  DATA_NmumuA[numPointForRCalculation] << std::endl;
//  std::cout << " NmumuB <-       " <<  DATA_NmumuB[numPointForRCalculation] << std::endl;
//  std::cout << std::endl;
//  std::cout << " NemuA <-        " <<  DATA_NemuA[numPointForRCalculation]  << std::endl;
//  std::cout << " NemuB <-        " <<  DATA_NemuB[numPointForRCalculation]  << std::endl;
//  std::cout << std::endl;
//  std::cout << " NmueA <-        " <<  DATA_NmueA[numPointForRCalculation]  << std::endl;
//  std::cout << " NmueB <-        " <<  DATA_NmueB[numPointForRCalculation]  << std::endl;
//  std::cout << std::endl;
//  std::cout << std::endl;
//  std::cout << std::endl;
//  std::cout << std::endl;
//  std::cout << " NallMCA <-      " <<  all_NeeA[numPointForRCalculation] + all_NemuA[numPointForRCalculation] + all_NmueA[numPointForRCalculation] + all_NmumuA[numPointForRCalculation]  << std::endl;
//  std::cout << " NallMCB <-      " <<  all_NeeB[numPointForRCalculation] + all_NemuB[numPointForRCalculation] + all_NmueB[numPointForRCalculation] + all_NmumuB[numPointForRCalculation]  << std::endl;
//  std::cout << " NDYMCA <-       " <<  DY_NeeA[numPointForRCalculation] + DY_NemuA[numPointForRCalculation] + DY_NmueA[numPointForRCalculation] + DY_NmumuA[numPointForRCalculation]  << std::endl;
//  std::cout << " NDYMCB <-       " <<  DY_NeeB[numPointForRCalculation] + DY_NemuB[numPointForRCalculation] + DY_NmueB[numPointForRCalculation] + DY_NmumuB[numPointForRCalculation]  << std::endl;
//  std::cout << " NotherMCA <-    " <<  other_NeeA[numPointForRCalculation] + other_NemuA[numPointForRCalculation] + other_NmueA[numPointForRCalculation] + other_NmumuA[numPointForRCalculation]  << std::endl;
//  std::cout << " NotherMCB <-    " <<  other_NeeB[numPointForRCalculation] + other_NemuB[numPointForRCalculation] + other_NmueB[numPointForRCalculation] + other_NmumuB[numPointForRCalculation]  << std::endl;
//  std::cout << std::endl;
//  std::cout << " errNallMCA <-      " <<  sqrt(all_errNeeA[numPointForRCalculation]*all_errNeeA[numPointForRCalculation] + all_errNemuA[numPointForRCalculation]*all_errNemuA[numPointForRCalculation] + all_errNmueA[numPointForRCalculation]*all_errNmueA[numPointForRCalculation] + all_errNmumuA[numPointForRCalculation]*all_errNmumuA[numPointForRCalculation])  << std::endl;
//  std::cout << " errNallMCB <-      " <<  sqrt(all_errNeeB[numPointForRCalculation]*all_errNeeB[numPointForRCalculation] + all_errNemuB[numPointForRCalculation]*all_errNemuB[numPointForRCalculation] + all_errNmueB[numPointForRCalculation]*all_errNmueB[numPointForRCalculation] + all_errNmumuB[numPointForRCalculation]*all_errNmumuB[numPointForRCalculation])  << std::endl;
//  std::cout << " errNDYMCA <-       " <<  sqrt(DY_errNeeA[numPointForRCalculation]*DY_errNeeA[numPointForRCalculation] + DY_errNemuA[numPointForRCalculation]*DY_errNemuA[numPointForRCalculation] + DY_errNmueA[numPointForRCalculation]*DY_errNmueA[numPointForRCalculation] + DY_errNmumuA[numPointForRCalculation]*DY_errNmumuA[numPointForRCalculation])  << std::endl;
//  std::cout << " errNDYMCB <-       " <<  sqrt(DY_errNeeB[numPointForRCalculation]*DY_errNeeB[numPointForRCalculation] + DY_errNemuB[numPointForRCalculation]*DY_errNemuB[numPointForRCalculation] + DY_errNmueB[numPointForRCalculation]*DY_errNmueB[numPointForRCalculation] + DY_errNmumuB[numPointForRCalculation]*DY_errNmumuB[numPointForRCalculation])  << std::endl;
//  std::cout << " errNotherMCA <-    " <<  sqrt(other_errNeeA[numPointForRCalculation]*other_errNeeA[numPointForRCalculation] + other_errNemuA[numPointForRCalculation]*other_errNemuA[numPointForRCalculation] + other_errNmueA[numPointForRCalculation]*other_errNmueA[numPointForRCalculation] + other_errNmumuA[numPointForRCalculation]*other_errNmumuA[numPointForRCalculation])  << std::endl;
//  std::cout << " errNotherMCB <-    " <<  sqrt(other_errNeeB[numPointForRCalculation]*other_errNeeB[numPointForRCalculation] + other_errNemuB[numPointForRCalculation]*other_errNemuB[numPointForRCalculation] + other_errNmueB[numPointForRCalculation]*other_errNmueB[numPointForRCalculation] + other_errNmumuB[numPointForRCalculation]*other_errNmumuB[numPointForRCalculation])  << std::endl; 
//  std::cout << std::endl;
//  std::cout << " # ****************************** " << std::endl;
//  std::cout << " # ****************************** " << std::endl;
//  
//  
//  std::cout << " # ******************************** " << std::endl;
//  std::cout << " # **** for Bayesian inference **** " << std::endl;
//  std::cout << " # ******************************** " << std::endl;
//  std::cout << " # ******************************** " << std::endl;
//  std::cout << " # ************** DY ************** " << std::endl;
//  std::cout << " # ******************************** " << std::endl;
//  std::cout << std::endl;
//  std::cout << " NeeAmet <-         " <<  DATA_NeeA[numPointForDYCalculation]   << std::endl;
//  std::cout << " NeeBmet <-         " <<  DATA_NeeB[numPointForDYCalculation]   << std::endl;
//  std::cout << std::endl;
//  std::cout << " NmumuAmet <-       " <<  DATA_NmumuA[numPointForDYCalculation] << std::endl;
//  std::cout << " NmumuBmet <-       " <<  DATA_NmumuB[numPointForDYCalculation] << std::endl;
//  std::cout << std::endl;
//  std::cout << " NemuAmet <-        " <<  DATA_NemuA[numPointForDYCalculation]  << std::endl;
//  std::cout << " NemuBmet <-        " <<  DATA_NemuB[numPointForDYCalculation]  << std::endl;
//  std::cout << std::endl;
//  std::cout << " NmueAmet <-        " <<  DATA_NmueA[numPointForDYCalculation]  << std::endl;
//  std::cout << " NmueBmet <-        " <<  DATA_NmueB[numPointForDYCalculation]  << std::endl;
//  std::cout << std::endl;
//  std::cout << std::endl;
//  std::cout << std::endl;
//  std::cout << " NallMCAmet <-      " <<  all_NeeA[numPointForDYCalculation] + all_NemuA[numPointForDYCalculation] + all_NmueA[numPointForDYCalculation] + all_NmumuA[numPointForDYCalculation]  << std::endl;
//  std::cout << " NallMCBmet <-      " <<  all_NeeB[numPointForDYCalculation] + all_NemuB[numPointForDYCalculation] + all_NmueB[numPointForDYCalculation] + all_NmumuB[numPointForDYCalculation]  << std::endl;
//  std::cout << " NDYMCAmet <-       " <<  DY_NeeA[numPointForDYCalculation] + DY_NemuA[numPointForDYCalculation] + DY_NmueA[numPointForDYCalculation] + DY_NmumuA[numPointForDYCalculation]  << std::endl;
//  std::cout << " NDYMCBmet <-       " <<  DY_NeeB[numPointForDYCalculation] + DY_NemuB[numPointForDYCalculation] + DY_NmueB[numPointForDYCalculation] + DY_NmumuB[numPointForDYCalculation]  << std::endl;
//  std::cout << " NotherMCAmet <-    " <<  other_NeeA[numPointForDYCalculation] + other_NemuA[numPointForDYCalculation] + other_NmueA[numPointForDYCalculation] + other_NmumuA[numPointForDYCalculation]  << std::endl;
//  std::cout << " NotherMCBmet <-    " <<  other_NeeB[numPointForDYCalculation] + other_NemuB[numPointForDYCalculation] + other_NmueB[numPointForDYCalculation] + other_NmumuB[numPointForDYCalculation]  << std::endl;
//  std::cout << std::endl;
//  std::cout << " errNallMCAmet <-      " <<  sqrt(all_errNeeA[numPointForDYCalculation]*all_errNeeA[numPointForDYCalculation] + all_errNemuA[numPointForDYCalculation]*all_errNemuA[numPointForDYCalculation] + all_errNmueA[numPointForDYCalculation]*all_errNmueA[numPointForDYCalculation] + all_errNmumuA[numPointForDYCalculation]*all_errNmumuA[numPointForDYCalculation])  << std::endl;
//  std::cout << " errNallMCBmet <-      " <<  sqrt(all_errNeeB[numPointForDYCalculation]*all_errNeeB[numPointForDYCalculation] + all_errNemuB[numPointForDYCalculation]*all_errNemuB[numPointForDYCalculation] + all_errNmueB[numPointForDYCalculation]*all_errNmueB[numPointForDYCalculation] + all_errNmumuB[numPointForDYCalculation]*all_errNmumuB[numPointForDYCalculation])  << std::endl;
//  std::cout << " errNDYMCAmet <-       " <<  sqrt(DY_errNeeA[numPointForDYCalculation]*DY_errNeeA[numPointForDYCalculation] + DY_errNemuA[numPointForDYCalculation]*DY_errNemuA[numPointForDYCalculation] + DY_errNmueA[numPointForDYCalculation]*DY_errNmueA[numPointForDYCalculation] + DY_errNmumuA[numPointForDYCalculation]*DY_errNmumuA[numPointForDYCalculation])  << std::endl;
//  std::cout << " errNDYMCBmet <-       " <<  sqrt(DY_errNeeB[numPointForDYCalculation]*DY_errNeeB[numPointForDYCalculation] + DY_errNemuB[numPointForDYCalculation]*DY_errNemuB[numPointForDYCalculation] + DY_errNmueB[numPointForDYCalculation]*DY_errNmueB[numPointForDYCalculation] + DY_errNmumuB[numPointForDYCalculation]*DY_errNmumuB[numPointForDYCalculation])  << std::endl;
//  std::cout << " errNotherMCAmet <-    " <<  sqrt(other_errNeeA[numPointForDYCalculation]*other_errNeeA[numPointForDYCalculation] + other_errNemuA[numPointForDYCalculation]*other_errNemuA[numPointForDYCalculation] + other_errNmueA[numPointForDYCalculation]*other_errNmueA[numPointForDYCalculation] + other_errNmumuA[numPointForDYCalculation]*other_errNmumuA[numPointForDYCalculation])  << std::endl;
//  std::cout << " errNotherMCBmet <-    " <<  sqrt(other_errNeeB[numPointForDYCalculation]*other_errNeeB[numPointForDYCalculation] + other_errNemuB[numPointForDYCalculation]*other_errNemuB[numPointForDYCalculation] + other_errNmueB[numPointForDYCalculation]*other_errNmueB[numPointForDYCalculation] + other_errNmumuB[numPointForDYCalculation]*other_errNmumuB[numPointForDYCalculation])  << std::endl; 
//  std::cout << std::endl;
//  std::cout << " ****************************** " << std::endl;
//  std::cout << " ****************************** " << std::endl;
//  
//  
//  std::cout << " ***************************** " << std::endl;
//  std::cout << " **** Standard estimation **** " << std::endl;
//  std::cout << " ***************************** " << std::endl;
//  std::cout << " ***************************** " << std::endl;
//  std::cout << " ************ DY ************* " << std::endl;
//  std::cout << " ***************************** " << std::endl;
//  std::cout << std::endl;
//  
//  
//  
//  
//  
//  std::cout << " ****************************** " << std::endl;
//  std::cout << " ****************************** " << std::endl;
//  std::cout << std::endl;
//  std::cout << std::endl;
//  std::cout << " R (ee) =         " <<  DATA_R_ee[numPointForRCalculation]   << " +/- " <<  DATA_errR_ee[numPointForRCalculation]   << std::endl;
//  std::cout << " R (mumu) =       " <<  DATA_R_mumu[numPointForRCalculation] << " +/- " <<  DATA_errR_mumu[numPointForRCalculation] << std::endl;
//  std::cout << std::endl;
//  std::cout << " DY (ee) =        " <<  DATA_NDY_R_A_ee[numPointForDYCalculation]   << " +/- " <<  DATA_errNDY_R_A_ee[numPointForDYCalculation]   << std::endl;
//  std::cout << " DY (mumu) =      " <<  DATA_NDY_R_A_mumu[numPointForDYCalculation] << " +/- " <<  DATA_errNDY_R_A_mumu[numPointForDYCalculation] << std::endl; 
//  std::cout << std::endl;
//  std::cout << " ****************************** " << std::endl;
//  std::cout << " ****************************** " << std::endl;
 
 
 
}


