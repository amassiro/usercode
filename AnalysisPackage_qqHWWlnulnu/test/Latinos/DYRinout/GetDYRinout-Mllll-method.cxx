// r00t test/Latinos/DYRinout/GetDYRinout.cxx\(\"out_test_Latinos_26July2011_1100.root\"\)

void GetDYRinout_Mllll_method(TString nameRootFile){
 
 TFile* fileIn = new TFile(nameRootFile,"READ");
 
 bool Rplot = false;
 
 
 gStyle->SetTitleX(0.2f);
 gStyle->SetTitleW(0.5f);
 
//  int numPointForRCalculation = 3;
 int numPointForRCalculation = 0;
//  int numPointForDYCalculation = 21;
 int numPointForDYCalculation = 1;
 
 int numPlot = 20;
//  int numPlot = 23;
 
 int num = 23;
 double X[100] =    {0, 1, 5, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 35, 36, 37, 38, 39, 40, 45 };
 double errX[100] = {0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 , 0 , 0 , 0  };  
 double XShift[100] =    {0.1, 1.1.1, 5.1, 10.1, 12.1, 14.1, 16.1, 18.1, 20.1, 22.1, 24.1, 26.1, 28.1, 30.1, 32.1, 34.1, 35.1, 36.1, 37.1, 38.1, 39.1, 40.1, 45 };
 

 int numPlotM = 23;
 int numM = 23;
 double XM[100] =    {0, 10, 15, 20, 25, 30, 35, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55 };
 double errXM[100] = {0, 0 , 0 ,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 , 0 , 0 , 0  };  
 double XMShift[100] = {0.1, 10.1, 15.1, 20.1, 25.1, 30.1, 35.1, 40.1, 41.1, 42.1, 43.1, 44.1, 45.1, 46.1, 47.1, 48.1, 49.1, 50.1, 51.1, 52.1, 53.1, 54.1, 55.1 };
 double errXMShift[100] = {0, 0 , 0 ,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 , 0 , 0 , 0  };  
 
 
 ///---- for M ----
 
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
 
 
 
 
 double DATA_NDY_A_mumu[100];
 double DATA_NDY_A_ee[100];
 double DATA_errNDY_A_mumu[100];
 double DATA_errNDY_A_ee[100];
 
 double DATA_NDYCorrected_A_mumu[100];
 double DATA_NDYCorrected_A_ee[100];
 double DATA_errNDYCorrected_A_mumu[100];
 double DATA_errNDYCorrected_A_ee[100];
 
 
  
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
  all_NeeB[iCut]   = other_NeeB[iCut]   + DY_NeeB[iCut];
  all_NmumuB[iCut] = other_NmumuB[iCut] + DY_NmumuB[iCut];
  all_NemuB[iCut]  = other_NemuB[iCut]  + DY_NemuB[iCut];
  all_NmueB[iCut]  = other_NmueB[iCut]  + DY_NmueB[iCut];
  
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
  DY_R_ee[iCut] = DY_NeeA[iCut] / DY_NeeB[iCut];
  DY_errR_ee[iCut] = sqrt((DY_errNeeA[iCut]*DY_errNeeA[iCut] / DY_NeeB[iCut]/ DY_NeeB[iCut]) + DY_errNeeB[iCut] * DY_NeeA[iCut] / DY_NeeB[iCut]/ DY_NeeB[iCut] * DY_errNeeB[iCut] * DY_NeeA[iCut] / DY_NeeB[iCut]/ DY_NeeB[iCut]);

  DY_R_mumu[iCut] = DY_NmumuA[iCut] / DY_NmumuB[iCut];
  DY_errR_mumu[iCut] = sqrt((DY_errNmumuA[iCut]*DY_errNmumuA[iCut] / DY_NmumuB[iCut]/ DY_NmumuB[iCut]) + DY_errNmumuB[iCut] * DY_NmumuA[iCut] / DY_NmumuB[iCut]/ DY_NmumuB[iCut] * DY_errNmumuB[iCut] * DY_NmumuA[iCut] / DY_NmumuB[iCut]/ DY_NmumuB[iCut]);

  DYmad_R_ee[iCut] = DYmad_NeeA[iCut] / DYmad_NeeB[iCut];
  DYmad_errR_ee[iCut] = sqrt((DYmad_errNeeA[iCut]*DYmad_errNeeA[iCut] / DYmad_NeeB[iCut]/ DYmad_NeeB[iCut]) + DYmad_errNeeB[iCut] * DYmad_NeeA[iCut] / DYmad_NeeB[iCut]/ DYmad_NeeB[iCut] * DYmad_errNeeB[iCut] * DYmad_NeeA[iCut] / DYmad_NeeB[iCut]/ DYmad_NeeB[iCut]);
  
  DYmad_R_mumu[iCut] = DYmad_NmumuA[iCut] / DYmad_NmumuB[iCut];
  DYmad_errR_mumu[iCut] = sqrt((DYmad_errNmumuA[iCut]*DYmad_errNmumuA[iCut] / DYmad_NmumuB[iCut]/ DYmad_NmumuB[iCut]) + DYmad_errNmumuB[iCut] * DYmad_NmumuA[iCut] / DYmad_NmumuB[iCut]/ DYmad_NmumuB[iCut] * DYmad_errNmumuB[iCut] * DYmad_NmumuA[iCut] / DYmad_NmumuB[iCut]/ DYmad_NmumuB[iCut]);
  
  
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
  
 }
 
 
 
 for (int iCut = 0; iCut <num; iCut++) {

  ///==== Results: NDY_A_ee_extrapolated = (NeeB - keeB' * NemuB) * Rinout|calculated at met>0
  
  NB = DATA_NeeB[iCut] - sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut] * DATA_NemuB[iCut] * DATA_NmueB[iCut]);
  
  c1 = DATA_errNeeB[iCut]    *  (1. - 1./2. * sqrt(DATA_NemuB[iCut]*DATA_NmueB[iCut]/DATA_NeeB[iCut]/DATA_NmumuB[iCut]))  ;
  c2 = DATA_errNmumuB[iCut]  *  (1./2. * sqrt(DATA_NemuB[iCut]*DATA_NmueB[iCut]*DATA_NeeB[iCut]/DATA_NmumuB[iCut])/DATA_NmumuB[iCut]);
  c3 = DATA_NemuB[iCut] ? (DATA_errNemuB[iCut]   *  (1./2. * sqrt(DATA_NeeB[iCut]*DATA_NmumuB[iCut]*DATA_NmueB[iCut]/DATA_NemuB[iCut]))) : 0.;
  c4 = DATA_NmueB[iCut] ? (DATA_errNmueB[iCut]   *  (1./2. * sqrt(DATA_NeeB[iCut]*DATA_NmumuB[iCut]*DATA_NemuB[iCut]/DATA_NmueB[iCut]))) : 0.;
  errNB = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4); 
  
  DATA_NDY_A_ee[iCut]     = NB * DATA_R_ee[numPointForRCalculation]; 
  DATA_errNDY_A_ee[iCut]  = sqrt ((NB * DATA_errR_ee[numPointForRCalculation] * NB * DATA_errR_ee[numPointForRCalculation]) + DATA_R_ee[numPointForRCalculation] * DATA_R_ee[numPointForRCalculation] * (c4 + c5 + c6));
  
  DATA_NDYCorrected_A_ee[iCut]  = all_NeeA[iCut] - DY_NeeA[iCut] + DATA_NDY_A_ee[iCut];
  DATA_errNDYCorrected_A_ee[iCut] = sqrt(all_errNeeA[iCut]*all_errNeeA[iCut] + DY_errNeeA[iCut]*DY_errNeeA[iCut] + DATA_errNDY_A_ee[iCut]*DATA_errNDY_A_ee[iCut]);
  
  ///==== Results: NDY_A_mumu_extrapolated = (NmumuB - kmumuB' * NemuB) * Rinout|calculated at met>0
  
  NB = DATA_NmumuB[iCut] - sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut] * DATA_NmueB[iCut] * DATA_NemuB[iCut]);
  
  c1 = DATA_errNmumuB[iCut]    *  (1. - 1./2. * sqrt(DATA_NmueB[iCut]*DATA_NemuB[iCut]/DATA_NmumuB[iCut]/DATA_NeeB[iCut]))  ;
  c2 = DATA_errNeeB[iCut]  *  (1./2. * sqrt(DATA_NmueB[iCut]*DATA_NemuB[iCut]*DATA_NmumuB[iCut]/DATA_NeeB[iCut])/DATA_NeeB[iCut]);
  c3 = DATA_NmueB[iCut] ? (DATA_errNmueB[iCut]   *  (1./2. * sqrt(DATA_NmumuB[iCut]*DATA_NeeB[iCut]*DATA_NemuB[iCut]/DATA_NmueB[iCut]))) : 0.;
  c4 = DATA_NemuB[iCut] ? (DATA_errNemuB[iCut]   *  (1./2. * sqrt(DATA_NmumuB[iCut]*DATA_NeeB[iCut]*DATA_NmueB[iCut]/DATA_NemuB[iCut]))) : 0.;
  errNB = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4); 
  
  DATA_NDY_A_mumu[iCut]     = NB * DATA_R_mumu[numPointForRCalculation]; 
  DATA_errNDY_A_mumu[iCut]  = sqrt ((NB * DATA_errR_mumu[numPointForRCalculation] * NB * DATA_errR_mumu[numPointForRCalculation]) + DATA_R_mumu[numPointForRCalculation] * DATA_R_mumu[numPointForRCalculation] * (c4 + c5 + c6));
  
  DATA_NDYCorrected_A_mumu[iCut]  = all_NmumuA[iCut] - DY_NmumuA[iCut] + DATA_NDY_A_mumu[iCut];
  DATA_errNDYCorrected_A_mumu[iCut] = sqrt(all_errNmumuA[iCut]*all_errNmumuA[iCut] + DY_errNmumuA[iCut]*DY_errNmumuA[iCut] + DATA_errNDY_A_mumu[iCut]*DATA_errNDY_A_mumu[iCut]);
  
 }
  
 
 
 
 ///==== M ====
 
 for (int iCut = 0; iCut <numM; iCut++) {
  double eNum;
  double eDen;
  
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
  
  
  
  
 
 
 }
 
 
 
 
 
 
 if (Rplot)
 {
 
 
 ///==== plot ====
 
 ///================
 ///==== A zone ====
 ///================

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
 grDYmad_NmumuA->SetMarkerStyle(21);
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
 grother_NmumuA->SetMarkerColor(kTeal);
 grother_NmumuA->SetFillColor(kWhite);
 grother_NmumuA->SetLineColor(kTeal);
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
 grDYmad_NeeA->SetMarkerStyle(21);
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
 grother_NeeA->SetMarkerColor(kTeal);
 grother_NeeA->SetFillColor(kWhite);
 grother_NeeA->SetLineColor(kTeal);
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
 grDYmad_NemuA->SetMarkerStyle(21);
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
 grother_NemuA->SetMarkerColor(kTeal);
 grother_NemuA->SetFillColor(kWhite);
 grother_NemuA->SetLineColor(kTeal);
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
 grDYmad_NmueA->SetMarkerStyle(21);
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
 grother_NmueA->SetMarkerColor(kTeal);
 grother_NmueA->SetFillColor(kWhite);
 grother_NmueA->SetLineColor(kTeal);
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
 grDYmad_NmumuB->SetMarkerStyle(21);
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
 grother_NmumuB->SetMarkerColor(kTeal);
 grother_NmumuB->SetFillColor(kWhite);
 grother_NmumuB->SetLineColor(kTeal);
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
 grDYmad_NeeB->SetMarkerStyle(21);
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
 grother_NeeB->SetMarkerColor(kTeal);
 grother_NeeB->SetFillColor(kWhite);
 grother_NeeB->SetLineColor(kTeal);
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
 grDYmad_NemuB->SetMarkerStyle(21);
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
 grother_NemuB->SetMarkerColor(kTeal);
 grother_NemuB->SetFillColor(kWhite);
 grother_NemuB->SetLineColor(kTeal);
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
 grDYmad_NmueB->SetMarkerStyle(21);
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
 grother_NmueB->SetMarkerColor(kTeal);
 grother_NmueB->SetFillColor(kWhite);
 grother_NmueB->SetLineColor(kTeal);
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
 
 
 
 
 
 ///==== comparison two methods NB and NA from "other" ====
 
 TGraphErrors* grDATA_NKB_ee = new TGraphErrors(numPlot,X,DATA_NKB_ee,errX,DATA_errNKB_ee);
 grDATA_NKB_ee->SetTitle("N #mue * kee B");
 grDATA_NKB_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NKB_ee->GetYaxis()->SetTitle("N ee other");
 grDATA_NKB_ee->SetMarkerColor(kRed);
 grDATA_NKB_ee->SetFillColor(kWhite);
 grDATA_NKB_ee->SetLineColor(kRed);
 grDATA_NKB_ee->SetMarkerStyle(25);
 grDATA_NKB_ee->SetMarkerSize(1);
 grDATA_NKB_ee->SetLineWidth(2);

 TGraphErrors* grDATA_NKBNew_ee = new TGraphErrors(numPlot,X,DATA_NKBNew_ee,errX,DATA_errNKBNew_ee);
 grDATA_NKBNew_ee->SetTitle("New Nee B");
 grDATA_NKBNew_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NKBNew_ee->GetYaxis()->SetTitle("N ee other");
 grDATA_NKBNew_ee->SetMarkerColor(kBlue);
 grDATA_NKBNew_ee->SetFillColor(kWhite);
 grDATA_NKBNew_ee->SetLineColor(kBlue);
 grDATA_NKBNew_ee->SetMarkerStyle(25);
 grDATA_NKBNew_ee->SetMarkerSize(1);
 grDATA_NKBNew_ee->SetLineWidth(2);
 
 
 
 
 TGraphErrors* grDATA_NKB_mumu = new TGraphErrors(numPlot,X,DATA_NKB_mumu,errX,DATA_errNKB_mumu);
 grDATA_NKB_mumu->SetTitle("N #mue * k#mu#mu B");
 grDATA_NKB_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NKB_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 grDATA_NKB_mumu->SetMarkerColor(kRed);
 grDATA_NKB_mumu->SetFillColor(kWhite);
 grDATA_NKB_mumu->SetLineColor(kRed);
 grDATA_NKB_mumu->SetMarkerStyle(21);
 grDATA_NKB_mumu->SetMarkerSize(1);
 grDATA_NKB_mumu->SetLineWidth(2);
 
 TGraphErrors* grDATA_NKBNew_mumu = new TGraphErrors(numPlot,X,DATA_NKBNew_mumu,errX,DATA_errNKBNew_mumu);
 grDATA_NKBNew_mumu->SetTitle("New N#mu#mu B");
 grDATA_NKBNew_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NKBNew_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 grDATA_NKBNew_mumu->SetMarkerColor(kBlue);
 grDATA_NKBNew_mumu->SetFillColor(kWhite);
 grDATA_NKBNew_mumu->SetLineColor(kBlue);
 grDATA_NKBNew_mumu->SetMarkerStyle(21);
 grDATA_NKBNew_mumu->SetMarkerSize(1);
 grDATA_NKBNew_mumu->SetLineWidth(2);
 
 
 
 
 
 
 
 
 TCanvas* cDATA_NK_ee = new TCanvas("cDATA_NK_ee","cDATA_NK_ee",800,800); 
 
 TGraphErrors* grDATA_NKA_ee = new TGraphErrors(numPlot,X,DATA_NKA_ee,errX,DATA_errNKA_ee);
 grDATA_NKA_ee->SetTitle("N #mue * kee A");
 grDATA_NKA_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NKA_ee->GetYaxis()->SetTitle("N ee other");
 grDATA_NKA_ee->SetMarkerColor(kRed);
 grDATA_NKA_ee->SetFillColor(kWhite);
 grDATA_NKA_ee->SetLineColor(kRed);
 grDATA_NKA_ee->SetMarkerStyle(26);
 grDATA_NKA_ee->SetMarkerSize(1);
 grDATA_NKA_ee->SetLineWidth(2);
 
 TGraphErrors* grDATA_NKANew_ee = new TGraphErrors(numPlot,X,DATA_NKANew_ee,errX,DATA_errNKANew_ee);
 grDATA_NKANew_ee->SetTitle("New Nee A");
 grDATA_NKANew_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NKANew_ee->GetYaxis()->SetTitle("N ee other");
 grDATA_NKANew_ee->SetMarkerColor(kBlue);
 grDATA_NKANew_ee->SetFillColor(kWhite);
 grDATA_NKANew_ee->SetLineColor(kBlue);
 grDATA_NKANew_ee->SetMarkerStyle(26);
 grDATA_NKANew_ee->SetMarkerSize(1);
 grDATA_NKANew_ee->SetLineWidth(2);
 
 TMultiGraph* mgr_DATA_NK_ee = new TMultiGraph(); 
 mgr_DATA_NK_ee->Add(grDATA_NKA_ee);
 mgr_DATA_NK_ee->Add(grDATA_NKANew_ee);
 mgr_DATA_NK_ee->Add(grDATA_NKB_ee);
 mgr_DATA_NK_ee->Add(grDATA_NKBNew_ee);
 mgr_DATA_NK_ee->Draw("AP");
 mgr_DATA_NK_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_DATA_NK_ee->GetYaxis()->SetTitle("N ee other");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas* cDATA_NK_mumu = new TCanvas("cDATA_NK_mumu","cDATA_NK_mumu",800,800); 
 
 TGraphErrors* grDATA_NKA_mumu = new TGraphErrors(numPlot,X,DATA_NKA_mumu,errX,DATA_errNKA_mumu);
 grDATA_NKA_mumu->SetTitle("N #mue * k#mu#mu A");
 grDATA_NKA_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NKA_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 grDATA_NKA_mumu->SetMarkerColor(kRed);
 grDATA_NKA_mumu->SetFillColor(kWhite);
 grDATA_NKA_mumu->SetLineColor(kRed);
 grDATA_NKA_mumu->SetMarkerStyle(22);
 grDATA_NKA_mumu->SetMarkerSize(1);
 grDATA_NKA_mumu->SetLineWidth(2);
 
 TGraphErrors* grDATA_NKANew_mumu = new TGraphErrors(numPlot,X,DATA_NKANew_mumu,errX,DATA_errNKANew_mumu);
 grDATA_NKANew_mumu->SetTitle("New N#mu#mu A");
 grDATA_NKANew_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_NKANew_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 grDATA_NKANew_mumu->SetMarkerColor(kBlue);
 grDATA_NKANew_mumu->SetFillColor(kWhite);
 grDATA_NKANew_mumu->SetLineColor(kBlue);
 grDATA_NKANew_mumu->SetMarkerStyle(22);
 grDATA_NKANew_mumu->SetMarkerSize(1);
 grDATA_NKANew_mumu->SetLineWidth(2);
 
 TMultiGraph* mgr_DATA_NK_mumu = new TMultiGraph(); 
 mgr_DATA_NK_mumu->Add(grDATA_NKA_mumu);
 mgr_DATA_NK_mumu->Add(grDATA_NKANew_mumu);
 mgr_DATA_NK_mumu->Add(grDATA_NKB_mumu);
 mgr_DATA_NK_mumu->Add(grDATA_NKBNew_mumu);
 mgr_DATA_NK_mumu->Draw("AP");
 mgr_DATA_NK_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_DATA_NK_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
}
 
 
 ///==== plot of M ====
 
 ///======================
 ///==== A and B zone ====
 ///======================
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 ///==== plot of R ====
 
 TCanvas* cDATA_R = new TCanvas("cDATA_R","cDATA_R",800,800); 
 
 TGraphErrors* grDATA_R_ee = new TGraphErrors(numPlot,X,DATA_R_ee,errX,DATA_errR_ee);
 grDATA_R_ee->SetTitle("Ree");
 grDATA_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_R_ee->GetYaxis()->SetTitle("Ree");
 grDATA_R_ee->SetMarkerColor(kRed);
 grDATA_R_ee->SetFillColor(kWhite);
 grDATA_R_ee->SetLineColor(kRed);
 grDATA_R_ee->SetMarkerStyle(25);
 grDATA_R_ee->SetMarkerSize(1);
 grDATA_R_ee->SetLineWidth(2);
 
 
 TGraphErrors* grDATA_R_mumu = new TGraphErrors(numPlot,X,DATA_R_mumu,errX,DATA_errR_mumu);
 grDATA_R_mumu->SetTitle("R #mu#mu");
 grDATA_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_R_mumu->GetYaxis()->SetTitle("R #mu#mu");
 grDATA_R_mumu->SetMarkerColor(kBlue);
 grDATA_R_mumu->SetFillColor(kWhite);
 grDATA_R_mumu->SetLineColor(kBlue);
 grDATA_R_mumu->SetMarkerStyle(26);
 grDATA_R_mumu->SetMarkerSize(1);
 grDATA_R_mumu->SetLineWidth(2);
 

 TGraphErrors* grDY_R_ee = new TGraphErrors(numPlot,X,DY_R_ee,errX,DY_errR_ee);
 grDY_R_ee->SetTitle("Ree DY");
 grDY_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_R_ee->GetYaxis()->SetTitle("Ree DY");
 grDY_R_ee->SetMarkerColor(kRed);
 grDY_R_ee->SetFillColor(kWhite);
 grDY_R_ee->SetLineColor(kRed);
 grDY_R_ee->SetMarkerStyle(21);
 grDY_R_ee->SetMarkerSize(1);
 grDY_R_ee->SetLineWidth(2);
 
 
 TGraphErrors* grDY_R_mumu = new TGraphErrors(numPlot,X,DY_R_mumu,errX,DY_errR_mumu);
 grDY_R_mumu->SetTitle("R #mu#mu DY");
 grDY_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_R_mumu->GetYaxis()->SetTitle("R #mu#mu DY");
 grDY_R_mumu->SetMarkerColor(kBlue);
 grDY_R_mumu->SetFillColor(kWhite);
 grDY_R_mumu->SetLineColor(kBlue);
 grDY_R_mumu->SetMarkerStyle(22);
 grDY_R_mumu->SetMarkerSize(1);
 grDY_R_mumu->SetLineWidth(2);
 
 
 
 TGraphErrors* grDYmad_R_ee = new TGraphErrors(numPlot,X,DYmad_R_ee,errX,DYmad_errR_ee);
 grDYmad_R_ee->SetTitle("Ree DYmad");
 grDYmad_R_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_R_ee->GetYaxis()->SetTitle("Ree DYmad");
 grDYmad_R_ee->SetMarkerColor(kRed);
 grDYmad_R_ee->SetFillColor(kWhite);
 grDYmad_R_ee->SetLineColor(kRed);
 grDYmad_R_ee->SetMarkerStyle(23);
 grDYmad_R_ee->SetMarkerSize(1);
 grDYmad_R_ee->SetLineWidth(2);
 
 
 TGraphErrors* grDYmad_R_mumu = new TGraphErrors(numPlot,X,DYmad_R_mumu,errX,DYmad_errR_mumu);
 grDYmad_R_mumu->SetTitle("R #mu#mu DYmad");
 grDYmad_R_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDYmad_R_mumu->GetYaxis()->SetTitle("R #mu#mu DYmad");
 grDYmad_R_mumu->SetMarkerColor(kBlue);
 grDYmad_R_mumu->SetFillColor(kWhite);
 grDYmad_R_mumu->SetLineColor(kBlue);
 grDYmad_R_mumu->SetMarkerStyle(29);
 grDYmad_R_mumu->SetMarkerSize(1);
 grDYmad_R_mumu->SetLineWidth(2);
 
 
  
 TMultiGraph* mgr_DATA_R = new TMultiGraph(); 
 mgr_DATA_R->Add(grDATA_R_ee);
 mgr_DATA_R->Add(grDATA_R_mumu);
 mgr_DATA_R->Add(grDY_R_ee);
 mgr_DATA_R->Add(grDY_R_mumu); 
 mgr_DATA_R->Add(grDYmad_R_ee);
 mgr_DATA_R->Add(grDYmad_R_mumu); 
 mgr_DATA_R->Draw("AP");
 mgr_DATA_R->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_DATA_R->GetYaxis()->SetTitle("R");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 std::cout << " # ******************************** " << std::endl;
 std::cout << " # **** for Bayesian inference **** " << std::endl;
 std::cout << " # ******************************** " << std::endl;
 std::cout << " # ******************************** " << std::endl;
 std::cout << " # ************** R *************** " << std::endl;
 std::cout << " # ******************************** " << std::endl;
 std::cout << std::endl;
 std::cout << " NeeA <-         " <<  DATA_NeeA[numPointForRCalculation]   << std::endl;
 std::cout << " NeeB <-         " <<  DATA_NeeB[numPointForRCalculation]   << std::endl;
 std::cout << std::endl;
 std::cout << " NmumuA <-       " <<  DATA_NmumuA[numPointForRCalculation] << std::endl;
 std::cout << " NmumuB <-       " <<  DATA_NmumuB[numPointForRCalculation] << std::endl;
 std::cout << std::endl;
 std::cout << " NemuA <-        " <<  DATA_NemuA[numPointForRCalculation]  << std::endl;
 std::cout << " NemuB <-        " <<  DATA_NemuB[numPointForRCalculation]  << std::endl;
 std::cout << std::endl;
 std::cout << " NmueA <-        " <<  DATA_NmueA[numPointForRCalculation]  << std::endl;
 std::cout << " NmueB <-        " <<  DATA_NmueB[numPointForRCalculation]  << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << " NallMCA <-      " <<  all_NeeA[numPointForRCalculation] + all_NemuA[numPointForRCalculation] + all_NmueA[numPointForRCalculation] + all_NmumuA[numPointForRCalculation]  << std::endl;
 std::cout << " NallMCB <-      " <<  all_NeeB[numPointForRCalculation] + all_NemuB[numPointForRCalculation] + all_NmueB[numPointForRCalculation] + all_NmumuB[numPointForRCalculation]  << std::endl;
 std::cout << " NDYMCA <-       " <<  DY_NeeA[numPointForRCalculation] + DY_NemuA[numPointForRCalculation] + DY_NmueA[numPointForRCalculation] + DY_NmumuA[numPointForRCalculation]  << std::endl;
 std::cout << " NDYMCB <-       " <<  DY_NeeB[numPointForRCalculation] + DY_NemuB[numPointForRCalculation] + DY_NmueB[numPointForRCalculation] + DY_NmumuB[numPointForRCalculation]  << std::endl;
 std::cout << " NotherMCA <-    " <<  other_NeeA[numPointForRCalculation] + other_NemuA[numPointForRCalculation] + other_NmueA[numPointForRCalculation] + other_NmumuA[numPointForRCalculation]  << std::endl;
 std::cout << " NotherMCB <-    " <<  other_NeeB[numPointForRCalculation] + other_NemuB[numPointForRCalculation] + other_NmueB[numPointForRCalculation] + other_NmumuB[numPointForRCalculation]  << std::endl;
 std::cout << std::endl;
 std::cout << " errNallMCA <-      " <<  sqrt(all_errNeeA[numPointForRCalculation]*all_errNeeA[numPointForRCalculation] + all_errNemuA[numPointForRCalculation]*all_errNemuA[numPointForRCalculation] + all_errNmueA[numPointForRCalculation]*all_errNmueA[numPointForRCalculation] + all_errNmumuA[numPointForRCalculation]*all_errNmumuA[numPointForRCalculation])  << std::endl;
 std::cout << " errNallMCB <-      " <<  sqrt(all_errNeeB[numPointForRCalculation]*all_errNeeB[numPointForRCalculation] + all_errNemuB[numPointForRCalculation]*all_errNemuB[numPointForRCalculation] + all_errNmueB[numPointForRCalculation]*all_errNmueB[numPointForRCalculation] + all_errNmumuB[numPointForRCalculation]*all_errNmumuB[numPointForRCalculation])  << std::endl;
 std::cout << " errNDYMCA <-       " <<  sqrt(DY_errNeeA[numPointForRCalculation]*DY_errNeeA[numPointForRCalculation] + DY_errNemuA[numPointForRCalculation]*DY_errNemuA[numPointForRCalculation] + DY_errNmueA[numPointForRCalculation]*DY_errNmueA[numPointForRCalculation] + DY_errNmumuA[numPointForRCalculation]*DY_errNmumuA[numPointForRCalculation])  << std::endl;
 std::cout << " errNDYMCB <-       " <<  sqrt(DY_errNeeB[numPointForRCalculation]*DY_errNeeB[numPointForRCalculation] + DY_errNemuB[numPointForRCalculation]*DY_errNemuB[numPointForRCalculation] + DY_errNmueB[numPointForRCalculation]*DY_errNmueB[numPointForRCalculation] + DY_errNmumuB[numPointForRCalculation]*DY_errNmumuB[numPointForRCalculation])  << std::endl;
 std::cout << " errNotherMCA <-    " <<  sqrt(other_errNeeA[numPointForRCalculation]*other_errNeeA[numPointForRCalculation] + other_errNemuA[numPointForRCalculation]*other_errNemuA[numPointForRCalculation] + other_errNmueA[numPointForRCalculation]*other_errNmueA[numPointForRCalculation] + other_errNmumuA[numPointForRCalculation]*other_errNmumuA[numPointForRCalculation])  << std::endl;
 std::cout << " errNotherMCB <-    " <<  sqrt(other_errNeeB[numPointForRCalculation]*other_errNeeB[numPointForRCalculation] + other_errNemuB[numPointForRCalculation]*other_errNemuB[numPointForRCalculation] + other_errNmueB[numPointForRCalculation]*other_errNmueB[numPointForRCalculation] + other_errNmumuB[numPointForRCalculation]*other_errNmumuB[numPointForRCalculation])  << std::endl; 
 std::cout << std::endl;
 std::cout << " # ****************************** " << std::endl;
 std::cout << " # ****************************** " << std::endl;
 
 
 std::cout << " # ******************************** " << std::endl;
 std::cout << " # **** for Bayesian inference **** " << std::endl;
 std::cout << " # ******************************** " << std::endl;
 std::cout << " # ******************************** " << std::endl;
 std::cout << " # ************** DY ************** " << std::endl;
 std::cout << " # ******************************** " << std::endl;
 std::cout << std::endl;
 std::cout << " NeeAmet <-         " <<  DATA_NeeA[numPointForDYCalculation]   << std::endl;
 std::cout << " NeeBmet <-         " <<  DATA_NeeB[numPointForDYCalculation]   << std::endl;
 std::cout << std::endl;
 std::cout << " NmumuAmet <-       " <<  DATA_NmumuA[numPointForDYCalculation] << std::endl;
 std::cout << " NmumuBmet <-       " <<  DATA_NmumuB[numPointForDYCalculation] << std::endl;
 std::cout << std::endl;
 std::cout << " NemuAmet <-        " <<  DATA_NemuA[numPointForDYCalculation]  << std::endl;
 std::cout << " NemuBmet <-        " <<  DATA_NemuB[numPointForDYCalculation]  << std::endl;
 std::cout << std::endl;
 std::cout << " NmueAmet <-        " <<  DATA_NmueA[numPointForDYCalculation]  << std::endl;
 std::cout << " NmueBmet <-        " <<  DATA_NmueB[numPointForDYCalculation]  << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << " NallMCAmet <-      " <<  all_NeeA[numPointForDYCalculation] + all_NemuA[numPointForDYCalculation] + all_NmueA[numPointForDYCalculation] + all_NmumuA[numPointForDYCalculation]  << std::endl;
 std::cout << " NallMCBmet <-      " <<  all_NeeB[numPointForDYCalculation] + all_NemuB[numPointForDYCalculation] + all_NmueB[numPointForDYCalculation] + all_NmumuB[numPointForDYCalculation]  << std::endl;
 std::cout << " NDYMCAmet <-       " <<  DY_NeeA[numPointForDYCalculation] + DY_NemuA[numPointForDYCalculation] + DY_NmueA[numPointForDYCalculation] + DY_NmumuA[numPointForDYCalculation]  << std::endl;
 std::cout << " NDYMCBmet <-       " <<  DY_NeeB[numPointForDYCalculation] + DY_NemuB[numPointForDYCalculation] + DY_NmueB[numPointForDYCalculation] + DY_NmumuB[numPointForDYCalculation]  << std::endl;
 std::cout << " NotherMCAmet <-    " <<  other_NeeA[numPointForDYCalculation] + other_NemuA[numPointForDYCalculation] + other_NmueA[numPointForDYCalculation] + other_NmumuA[numPointForDYCalculation]  << std::endl;
 std::cout << " NotherMCBmet <-    " <<  other_NeeB[numPointForDYCalculation] + other_NemuB[numPointForDYCalculation] + other_NmueB[numPointForDYCalculation] + other_NmumuB[numPointForDYCalculation]  << std::endl;
 std::cout << std::endl;
 std::cout << " errNallMCAmet <-      " <<  sqrt(all_errNeeA[numPointForDYCalculation]*all_errNeeA[numPointForDYCalculation] + all_errNemuA[numPointForDYCalculation]*all_errNemuA[numPointForDYCalculation] + all_errNmueA[numPointForDYCalculation]*all_errNmueA[numPointForDYCalculation] + all_errNmumuA[numPointForDYCalculation]*all_errNmumuA[numPointForDYCalculation])  << std::endl;
 std::cout << " errNallMCBmet <-      " <<  sqrt(all_errNeeB[numPointForDYCalculation]*all_errNeeB[numPointForDYCalculation] + all_errNemuB[numPointForDYCalculation]*all_errNemuB[numPointForDYCalculation] + all_errNmueB[numPointForDYCalculation]*all_errNmueB[numPointForDYCalculation] + all_errNmumuB[numPointForDYCalculation]*all_errNmumuB[numPointForDYCalculation])  << std::endl;
 std::cout << " errNDYMCAmet <-       " <<  sqrt(DY_errNeeA[numPointForDYCalculation]*DY_errNeeA[numPointForDYCalculation] + DY_errNemuA[numPointForDYCalculation]*DY_errNemuA[numPointForDYCalculation] + DY_errNmueA[numPointForDYCalculation]*DY_errNmueA[numPointForDYCalculation] + DY_errNmumuA[numPointForDYCalculation]*DY_errNmumuA[numPointForDYCalculation])  << std::endl;
 std::cout << " errNDYMCBmet <-       " <<  sqrt(DY_errNeeB[numPointForDYCalculation]*DY_errNeeB[numPointForDYCalculation] + DY_errNemuB[numPointForDYCalculation]*DY_errNemuB[numPointForDYCalculation] + DY_errNmueB[numPointForDYCalculation]*DY_errNmueB[numPointForDYCalculation] + DY_errNmumuB[numPointForDYCalculation]*DY_errNmumuB[numPointForDYCalculation])  << std::endl;
 std::cout << " errNotherMCAmet <-    " <<  sqrt(other_errNeeA[numPointForDYCalculation]*other_errNeeA[numPointForDYCalculation] + other_errNemuA[numPointForDYCalculation]*other_errNemuA[numPointForDYCalculation] + other_errNmueA[numPointForDYCalculation]*other_errNmueA[numPointForDYCalculation] + other_errNmumuA[numPointForDYCalculation]*other_errNmumuA[numPointForDYCalculation])  << std::endl;
 std::cout << " errNotherMCBmet <-    " <<  sqrt(other_errNeeB[numPointForDYCalculation]*other_errNeeB[numPointForDYCalculation] + other_errNemuB[numPointForDYCalculation]*other_errNemuB[numPointForDYCalculation] + other_errNmueB[numPointForDYCalculation]*other_errNmueB[numPointForDYCalculation] + other_errNmumuB[numPointForDYCalculation]*other_errNmumuB[numPointForDYCalculation])  << std::endl; 
 std::cout << std::endl;
 std::cout << " ****************************** " << std::endl;
 std::cout << " ****************************** " << std::endl;
 
 
 std::cout << " ***************************** " << std::endl;
 std::cout << " **** Standard estimation **** " << std::endl;
 std::cout << " ***************************** " << std::endl;
 std::cout << " ***************************** " << std::endl;
 std::cout << " ************ DY ************* " << std::endl;
 std::cout << " ***************************** " << std::endl;
 std::cout << std::endl;
 
 
 
 
 
 std::cout << " ****************************** " << std::endl;
 std::cout << " ****************************** " << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << " R (ee) =         " <<  DATA_R_ee[numPointForRCalculation]   << " +/- " <<  DATA_errR_ee[numPointForRCalculation]   << std::endl;
 std::cout << " R (mumu) =       " <<  DATA_R_mumu[numPointForRCalculation] << " +/- " <<  DATA_errR_mumu[numPointForRCalculation] << std::endl;
 std::cout << std::endl;
 std::cout << " DY (ee) =        " <<  DATA_NDY_A_ee[numPointForDYCalculation]   << " +/- " <<  DATA_errNDY_A_ee[numPointForDYCalculation]   << std::endl;
 std::cout << " DY (mumu) =      " <<  DATA_NDY_A_mumu[numPointForDYCalculation] << " +/- " <<  DATA_errNDY_A_mumu[numPointForDYCalculation] << std::endl; 
 std::cout << std::endl;
 std::cout << " ****************************** " << std::endl;
 std::cout << " ****************************** " << std::endl;
 
 
 
}


