// r00t test/Latinos/DYRinout/GetDYRinout.cxx\(\"out_test_Latinos_26July2011_1100.root\"\)

void GetDYRinout(TString nameRootFile){
 
 TFile* fileIn = new TFile(nameRootFile,"READ");
 
 
 gStyle->SetTitleX(0.2f);
 gStyle->SetTitleW(0.5f);
 
 int numPointForRCalculation = 3;
//  int numPointForRCalculation = 10;
//  int numPointForDYCalculation = 21;
 int numPointForDYCalculation = 20;
 
 int numPlot = 20;
//  int numPlot = 23;
 
 int num = 23;
 double X[100] =    {0, 1, 5, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 35, 36, 37, 38, 39, 40, 45 };
 double errX[100] = {0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 , 0 , 0 , 0  };  
 double XShift[100] =    {0.1, 1.1.1, 5.1, 10.1, 12.1, 14.1, 16.1, 18.1, 20.1, 22.1, 24.1, 26.1, 28.1, 30.1, 32.1, 34.1, 35.1, 36.1, 37.1, 38.1, 39.1, 40.1, 45 };
 
 
 
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
 

 
 
 double DY_NKB_ee[100];
 double DY_NKB_mumu[100];
 double DY_errNKB_ee[100];
 double DY_errNKB_mumu[100]; 
 
 double DY_NKBNew_ee[100];
 double DY_NKBNew_mumu[100];
 double DY_errNKBNew_ee[100];
 double DY_errNKBNew_mumu[100]; 
 
 
 double DY_NKA_ee[100];
 double DY_NKA_mumu[100];
 double DY_errNKA_ee[100];
 double DY_errNKA_mumu[100]; 
 
 double DY_NKANew_ee[100];
 double DY_NKANew_mumu[100];
 double DY_errNKANew_ee[100];
 double DY_errNKANew_mumu[100]; 
 
 
 
 double other_NKB_ee[100];
 double other_NKB_mumu[100];
 double other_errNKB_ee[100];
 double other_errNKB_mumu[100]; 
 
 double other_NKBNew_ee[100];
 double other_NKBNew_mumu[100];
 double other_errNKBNew_ee[100];
 double other_errNKBNew_mumu[100]; 
 
 
 double other_NKA_ee[100];
 double other_NKA_mumu[100];
 double other_errNKA_ee[100];
 double other_errNKA_mumu[100]; 
 
 double other_NKANew_ee[100];
 double other_NKANew_mumu[100];
 double other_errNKANew_ee[100];
 double other_errNKANew_mumu[100]; 
 
 
 
 
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
  
  
  
  
  
  
  
 
  
  //~~~~~
  
  
  other_NKB_ee[iCut] = 0.5 * (other_NemuB[iCut] + other_NmueB[iCut]) * sqrt(other_NeeB[iCut] / other_NmumuB[iCut]) ;
  a1 = (other_errNemuB[iCut]*other_errNemuB[iCut] * (other_NeeB[iCut] / other_NmumuB[iCut])) ;
  a2 = (other_errNmueB[iCut]*other_errNmueB[iCut] * (other_NeeB[iCut] / other_NmumuB[iCut])) ;
  a3 = (other_errNeeB[iCut] * other_errNeeB[iCut]     * (other_NemuB[iCut] + other_NmueB[iCut]) * (other_NemuB[iCut] + other_NmueB[iCut]) * (1. / 4. / other_NmumuB[iCut] / other_NeeB[iCut] )  ) ;
  a4 = (other_errNmumuB[iCut] * other_errNmumuB[iCut] * (other_NemuB[iCut] + other_NmueB[iCut]) * (other_NemuB[iCut] + other_NmueB[iCut]) * (1. / 4. * other_NeeB[iCut] / other_NmumuB[iCut] ) / other_NmumuB[iCut] / other_NmumuB[iCut] );
  other_errNKB_ee[iCut] = 0.5 * sqrt( a1 + a2 + a3 + a4); 
  
  other_NKB_mumu[iCut] = 0.5 * (other_NemuB[iCut] + other_NmueB[iCut]) * sqrt(other_NmumuB[iCut] / other_NeeB[iCut]) ;
  a1 = (other_errNemuB[iCut]*other_errNemuB[iCut] * (other_NmumuB[iCut] / other_NeeB[iCut])) ;
  a2 = (other_errNmueB[iCut]*other_errNmueB[iCut] * (other_NmumuB[iCut] / other_NeeB[iCut])) ;
  a3 = (other_errNmumuB[iCut] * other_errNmumuB[iCut]     * (other_NemuB[iCut] + other_NmueB[iCut]) * (other_NemuB[iCut] + other_NmueB[iCut]) * (1. / 4. / other_NeeB[iCut] / other_NmumuB[iCut] )  ) ;
  a4 = (other_errNeeB[iCut] * other_errNeeB[iCut] * (other_NemuB[iCut] + other_NmueB[iCut]) * (other_NemuB[iCut] + other_NmueB[iCut]) * (1. / 4. * other_NmumuB[iCut] / other_NeeB[iCut] ) / other_NeeB[iCut] / other_NeeB[iCut] );
  other_errNKB_mumu[iCut] = 0.5 * sqrt( a1 + a2 + a3 + a4); 
  
  
  
  other_NKBNew_ee[iCut] = sqrt(other_NeeB[iCut] / other_NmumuB[iCut] * other_NemuB[iCut] * other_NmueB[iCut]);
  a1 = other_errNeeB[iCut]    *  (1./2. * sqrt(other_NemuB[iCut]*other_NmueB[iCut]/other_NeeB[iCut]/other_NmumuB[iCut]))  ;
  a2 = other_errNmumuB[iCut]  *  (1./2. * sqrt(other_NemuB[iCut]*other_NmueB[iCut]*other_NeeB[iCut]/other_NmumuB[iCut])/other_NmumuB[iCut]);
  a3 = other_NemuB[iCut] ? (other_errNemuB[iCut]   *  (1./2. * sqrt(other_NeeB[iCut]/other_NmumuB[iCut]*other_NmueB[iCut]/other_NemuB[iCut]))) : 0.;
  a4 = other_NmueB[iCut] ? (other_errNmueB[iCut]   *  (1./2. * sqrt(other_NeeB[iCut]/other_NmumuB[iCut]*other_NemuB[iCut]/other_NmueB[iCut]))) : 0.;
  other_errNKBNew_ee[iCut] = sqrt(a1*a1 + a2*a2 + a3*a3 + a4*a4); 
  
  
  other_NKBNew_mumu[iCut] = sqrt(other_NmumuB[iCut] / other_NeeB[iCut] * other_NmueB[iCut] * other_NemuB[iCut]);
  a1 = other_errNmumuB[iCut]    *  (1./2. * sqrt(other_NmueB[iCut]*other_NemuB[iCut]/other_NmumuB[iCut]/other_NeeB[iCut]))  ;
  a2 = other_errNeeB[iCut]  *  (1./2. * sqrt(other_NmueB[iCut]*other_NemuB[iCut]*other_NmumuB[iCut]/other_NeeB[iCut])/other_NeeB[iCut]);
  a3 = other_NmueB[iCut] ? (other_errNmueB[iCut]   *  (1./2. * sqrt(other_NmumuB[iCut]/other_NeeB[iCut]*other_NemuB[iCut]/other_NmueB[iCut]))) : 0.;
  a4 = other_NemuB[iCut] ? (other_errNemuB[iCut]   *  (1./2. * sqrt(other_NmumuB[iCut]/other_NeeB[iCut]*other_NmueB[iCut]/other_NemuB[iCut]))) : 0.;
  other_errNKBNew_mumu[iCut] = sqrt(a1*a1 + a2*a2 + a3*a3 + a4*a4); 
  
  
  
  
  
  other_NKA_ee[iCut] = 0.5 * (other_NemuA[iCut] + other_NmueA[iCut]) * sqrt(other_NeeA[iCut] / other_NmumuA[iCut]) ;
  a1 = (other_errNemuA[iCut]*other_errNemuA[iCut] * (other_NeeA[iCut] / other_NmumuA[iCut])) ;
  a2 = (other_errNmueA[iCut]*other_errNmueA[iCut] * (other_NeeA[iCut] / other_NmumuA[iCut])) ;
  a3 = (other_errNeeA[iCut] * other_errNeeA[iCut]     * (other_NemuA[iCut] + other_NmueA[iCut]) * (other_NemuA[iCut] + other_NmueA[iCut]) * (1. / 4. / other_NmumuA[iCut] / other_NeeA[iCut] )  ) ;
  a4 = (other_errNmumuA[iCut] * other_errNmumuA[iCut] * (other_NemuA[iCut] + other_NmueA[iCut]) * (other_NemuA[iCut] + other_NmueA[iCut]) * (1. / 4. * other_NeeA[iCut] / other_NmumuA[iCut] ) / other_NmumuA[iCut] / other_NmumuA[iCut] );
  other_errNKA_ee[iCut] = 0.5 * sqrt( a1 + a2 + a3 + a4); 
  
  other_NKA_mumu[iCut] = 0.5 * (other_NemuA[iCut] + other_NmueA[iCut]) * sqrt(other_NmumuA[iCut] / other_NeeA[iCut]) ;
  a1 = (other_errNemuA[iCut]*other_errNemuA[iCut] * (other_NmumuA[iCut] / other_NeeA[iCut])) ;
  a2 = (other_errNmueA[iCut]*other_errNmueA[iCut] * (other_NmumuA[iCut] / other_NeeA[iCut])) ;
  a3 = (other_errNmumuA[iCut] * other_errNmumuA[iCut]     * (other_NemuA[iCut] + other_NmueA[iCut]) * (other_NemuA[iCut] + other_NmueA[iCut]) * (1. / 4. / other_NeeA[iCut] / other_NmumuA[iCut] )  ) ;
  a4 = (other_errNeeA[iCut] * other_errNeeA[iCut] * (other_NemuA[iCut] + other_NmueA[iCut]) * (other_NemuA[iCut] + other_NmueA[iCut]) * ( 1. / 4. * other_NmumuA[iCut] / other_NeeA[iCut] ) / other_NeeA[iCut] / other_NeeA[iCut] );
  other_errNKA_mumu[iCut] = 0.5 * sqrt( a1 + a2 + a3 + a4); 
  
  
  
  other_NKANew_ee[iCut] = sqrt(other_NeeA[iCut] / other_NmumuA[iCut] * other_NemuA[iCut] * other_NmueA[iCut]);
  a1 = other_errNeeA[iCut]    *  (1./2. * sqrt(other_NemuA[iCut]*other_NmueA[iCut]/other_NeeA[iCut]/other_NmumuA[iCut]))  ;
  a2 = other_errNmumuA[iCut]  *  (1./2. * sqrt(other_NemuA[iCut]*other_NmueA[iCut]*other_NeeA[iCut]/other_NmumuA[iCut])/other_NmumuA[iCut]);
  a3 = other_NemuA[iCut] ? (other_errNemuA[iCut]   *  (1./2. * sqrt(other_NeeA[iCut]/other_NmumuA[iCut]*other_NmueA[iCut]/other_NemuA[iCut]))) : 0.;
  a4 = other_NmueA[iCut] ? (other_errNmueA[iCut]   *  (1./2. * sqrt(other_NeeA[iCut]/other_NmumuA[iCut]*other_NemuA[iCut]/other_NmueA[iCut]))) : 0.;
  other_errNKANew_ee[iCut] = sqrt(a1*a1 + a2*a2 + a3*a3 + a4*a4); 
  
  
  other_NKANew_mumu[iCut] = sqrt(other_NmumuA[iCut] / other_NeeA[iCut] * other_NmueA[iCut] * other_NemuA[iCut]);
  a1 = other_errNmumuA[iCut]    *  (1./2. * sqrt(other_NmueA[iCut]*other_NemuA[iCut]/other_NmumuA[iCut]/other_NeeA[iCut]))  ;
  a2 = other_errNeeA[iCut]  *  (1./2. * sqrt(other_NmueA[iCut]*other_NemuA[iCut]*other_NmumuA[iCut]/other_NeeA[iCut])/other_NeeA[iCut]);
  a3 = other_NmueA[iCut] ? (other_errNmueA[iCut]   *  (1./2. * sqrt(other_NmumuA[iCut]/other_NeeA[iCut]*other_NemuA[iCut]/other_NmueA[iCut]))) : 0.;
  a4 = other_NemuA[iCut] ? (other_errNemuA[iCut]   *  (1./2. * sqrt(other_NmumuA[iCut]/other_NeeA[iCut]*other_NmueA[iCut]/other_NemuA[iCut]))) : 0.;
  other_errNKANew_mumu[iCut] = sqrt(a1*a1 + a2*a2 + a3*a3 + a4*a4); 
  
  
  
  
  
  
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
 
 
 
 
 
 
 TGraphErrors* grother_NKB_ee = new TGraphErrors(numPlot,X,other_NKB_ee,errX,other_errNKB_ee);
 grother_NKB_ee->SetTitle("N #mue * kee B other");
 grother_NKB_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NKB_ee->GetYaxis()->SetTitle("N ee other");
 grother_NKB_ee->SetMarkerColor(kRed);
 grother_NKB_ee->SetFillColor(kWhite);
 grother_NKB_ee->SetLineColor(kRed);
 grother_NKB_ee->SetMarkerStyle(29);
 grother_NKB_ee->SetMarkerSize(2);
 grother_NKB_ee->SetLineWidth(2);
 
 TGraphErrors* grother_NKBNew_ee = new TGraphErrors(numPlot,X,other_NKBNew_ee,errX,other_errNKBNew_ee);
 grother_NKBNew_ee->SetTitle("New Nee B other");
 grother_NKBNew_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NKBNew_ee->GetYaxis()->SetTitle("N ee other");
 grother_NKBNew_ee->SetMarkerColor(kBlue);
 grother_NKBNew_ee->SetFillColor(kWhite);
 grother_NKBNew_ee->SetLineColor(kBlue);
 grother_NKBNew_ee->SetMarkerStyle(29);
 grother_NKBNew_ee->SetMarkerSize(2);
 grother_NKBNew_ee->SetLineWidth(2);
 
 
 
 
 TGraphErrors* grother_NKB_mumu = new TGraphErrors(numPlot,X,other_NKB_mumu,errX,other_errNKB_mumu);
 grother_NKB_mumu->SetTitle("N #mue * k#mu#mu B other");
 grother_NKB_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NKB_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 grother_NKB_mumu->SetMarkerColor(kRed);
 grother_NKB_mumu->SetFillColor(kWhite);
 grother_NKB_mumu->SetLineColor(kRed);
 grother_NKB_mumu->SetMarkerStyle(27);
 grother_NKB_mumu->SetMarkerSize(2);
 grother_NKB_mumu->SetLineWidth(2);
 
 TGraphErrors* grother_NKBNew_mumu = new TGraphErrors(numPlot,X,other_NKBNew_mumu,errX,other_errNKBNew_mumu);
 grother_NKBNew_mumu->SetTitle("New N#mu#mu B other");
 grother_NKBNew_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NKBNew_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 grother_NKBNew_mumu->SetMarkerColor(kBlue);
 grother_NKBNew_mumu->SetFillColor(kWhite);
 grother_NKBNew_mumu->SetLineColor(kBlue);
 grother_NKBNew_mumu->SetMarkerStyle(27);
 grother_NKBNew_mumu->SetMarkerSize(2);
 grother_NKBNew_mumu->SetLineWidth(2);
 
 
 
 
 
 
 
 
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
 
 TGraphErrors* grother_NKA_ee = new TGraphErrors(numPlot,X,other_NKA_ee,errX,other_errNKA_ee);
 grother_NKA_ee->SetTitle("N #mue * kee A other");
 grother_NKA_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NKA_ee->GetYaxis()->SetTitle("N ee other");
 grother_NKA_ee->SetMarkerColor(kRed);
 grother_NKA_ee->SetFillColor(kWhite);
 grother_NKA_ee->SetLineColor(kRed);
 grother_NKA_ee->SetMarkerStyle(28);
 grother_NKA_ee->SetMarkerSize(1);
 grother_NKA_ee->SetLineWidth(2);
 
 TGraphErrors* grother_NKANew_ee = new TGraphErrors(numPlot,X,other_NKANew_ee,errX,other_errNKANew_ee);
 grother_NKANew_ee->SetTitle("New Nee A other");
 grother_NKANew_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NKANew_ee->GetYaxis()->SetTitle("N ee other");
 grother_NKANew_ee->SetMarkerColor(kBlue);
 grother_NKANew_ee->SetFillColor(kWhite);
 grother_NKANew_ee->SetLineColor(kBlue);
 grother_NKANew_ee->SetMarkerStyle(28);
 grother_NKANew_ee->SetMarkerSize(1);
 grother_NKANew_ee->SetLineWidth(2);
 
 TMultiGraph* mgr_DATA_NK_ee = new TMultiGraph(); 
 mgr_DATA_NK_ee->Add(grDATA_NKA_ee);
 mgr_DATA_NK_ee->Add(grDATA_NKANew_ee);
 mgr_DATA_NK_ee->Add(grDATA_NKB_ee);
 mgr_DATA_NK_ee->Add(grDATA_NKBNew_ee);
 mgr_DATA_NK_ee->Add(grother_NKA_ee);
 mgr_DATA_NK_ee->Add(grother_NKANew_ee);
 mgr_DATA_NK_ee->Add(grother_NKB_ee);
 mgr_DATA_NK_ee->Add(grother_NKBNew_ee);
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
 
 
 
  TGraphErrors* grother_NKA_mumu = new TGraphErrors(numPlot,X,other_NKA_mumu,errX,other_errNKA_mumu);
 grother_NKA_mumu->SetTitle("N #mue * k#mu#mu A");
 grother_NKA_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NKA_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 grother_NKA_mumu->SetMarkerColor(kRed);
 grother_NKA_mumu->SetFillColor(kWhite);
 grother_NKA_mumu->SetLineColor(kRed);
 grother_NKA_mumu->SetMarkerStyle(30);
 grother_NKA_mumu->SetMarkerSize(1);
 grother_NKA_mumu->SetLineWidth(2);
 
 TGraphErrors* grother_NKANew_mumu = new TGraphErrors(numPlot,X,other_NKANew_mumu,errX,other_errNKANew_mumu);
 grother_NKANew_mumu->SetTitle("New N#mu#mu A");
 grother_NKANew_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_NKANew_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 grother_NKANew_mumu->SetMarkerColor(kBlue);
 grother_NKANew_mumu->SetFillColor(kWhite);
 grother_NKANew_mumu->SetLineColor(kBlue);
 grother_NKANew_mumu->SetMarkerStyle(30);
 grother_NKANew_mumu->SetMarkerSize(1);
 grother_NKANew_mumu->SetLineWidth(2);
 
 
 
 TMultiGraph* mgr_DATA_NK_mumu = new TMultiGraph(); 
 mgr_DATA_NK_mumu->Add(grDATA_NKA_mumu);
 mgr_DATA_NK_mumu->Add(grDATA_NKANew_mumu);
 mgr_DATA_NK_mumu->Add(grDATA_NKB_mumu);
 mgr_DATA_NK_mumu->Add(grDATA_NKBNew_mumu);
 mgr_DATA_NK_mumu->Add(grother_NKA_mumu);
 mgr_DATA_NK_mumu->Add(grother_NKANew_mumu);
 mgr_DATA_NK_mumu->Add(grother_NKB_mumu);
 mgr_DATA_NK_mumu->Add(grother_NKBNew_mumu);
 mgr_DATA_NK_mumu->Draw("AP");
 mgr_DATA_NK_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_DATA_NK_mumu->GetYaxis()->SetTitle("N #mu#mu other");
 
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
 
 
 /*
 //**** old method ***
 
 double denom;
 double c1,c2,c3,c4,c5,c6;
 
 denom = (DATA_NeeB[numPointForRCalculation] - 1./2. * sqrt(DATA_NeeB[numPointForRCalculation] / DATA_NmumuB[numPointForRCalculation]) * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]));
 DATA_R_ee[numPointForRCalculation] = (DATA_NeeA[numPointForRCalculation] - 1./2. * sqrt(DATA_NeeA[numPointForRCalculation] / DATA_NmumuA[numPointForRCalculation]) * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation])) / (DATA_NeeB[numPointForRCalculation] - 1./2. * sqrt(DATA_NeeB[numPointForRCalculation] / DATA_NmumuB[numPointForRCalculation]) * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]));
 
 c1 = 1./denom/denom * ((1 - 1./4. * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation]) / sqrt(DATA_NeeA[numPointForRCalculation]*DATA_NmumuA[numPointForRCalculation])) * DATA_errNeeA[numPointForRCalculation]) * ((1 - 1./4. * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation]) / sqrt(DATA_NeeA[numPointForRCalculation]*DATA_NmumuA[numPointForRCalculation])) * DATA_errNeeA[numPointForRCalculation]) ;
 c2 = 1./denom/denom * ((1./4. * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation]) / DATA_NmumuA[numPointForRCalculation] * sqrt(DATA_NeeA[numPointForRCalculation] / DATA_NmumuA[numPointForRCalculation])) * DATA_errNmumuA[numPointForRCalculation]) * ((1./4. * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation]) / DATA_NmumuA[numPointForRCalculation] * sqrt(DATA_NeeA[numPointForRCalculation] / DATA_NmumuA[numPointForRCalculation])) * DATA_errNmumuA[numPointForRCalculation]) ;
 c3 = 1./denom/denom * (1./2. * sqrt(DATA_NeeA[numPointForRCalculation] / DATA_NmumuA[numPointForRCalculation]) * sqrt(DATA_errNemuA[numPointForRCalculation]*DATA_errNemuA[numPointForRCalculation] + DATA_errNmueA[numPointForRCalculation]*DATA_errNmueA[numPointForRCalculation])) * (1./2. * sqrt(DATA_NeeA[numPointForRCalculation] / DATA_NmumuA[numPointForRCalculation]) * sqrt(DATA_errNemuA[numPointForRCalculation]*DATA_errNemuA[numPointForRCalculation] + DATA_errNmueA[numPointForRCalculation]*DATA_errNmueA[numPointForRCalculation])) ;
 
 c4 = 1./denom/denom/denom/denom * ((1 - 1./4. * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]) / sqrt(DATA_NeeB[numPointForRCalculation]*DATA_NmumuB[numPointForRCalculation])) * DATA_errNeeB[numPointForRCalculation]) * ((1 - 1./4. * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]) / sqrt(DATA_NeeB[numPointForRCalculation]*DATA_NmumuB[numPointForRCalculation])) * DATA_errNeeB[numPointForRCalculation]) ;
 c5 = 1./denom/denom/denom/denom * ((1./4. * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]) / DATA_NmumuB[numPointForRCalculation] * sqrt(DATA_NeeB[numPointForRCalculation] / DATA_NmumuB[numPointForRCalculation])) * DATA_errNmumuB[numPointForRCalculation]) * ((1./4. * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]) / DATA_NmumuB[numPointForRCalculation] * sqrt(DATA_NeeB[numPointForRCalculation] / DATA_NmumuB[numPointForRCalculation])) * DATA_errNmumuB[numPointForRCalculation]) ;
 c6 = 1./denom/denom/denom/denom * (1./2. * sqrt(DATA_NeeB[numPointForRCalculation] / DATA_NmumuB[numPointForRCalculation]) * sqrt(DATA_errNemuB[numPointForRCalculation]*DATA_errNemuB[numPointForRCalculation] + DATA_errNmueB[numPointForRCalculation]*DATA_errNmueB[numPointForRCalculation])) * (1./2. * sqrt(DATA_NeeB[numPointForRCalculation] / DATA_NmumuB[numPointForRCalculation]) * sqrt(DATA_errNemuB[numPointForRCalculation]*DATA_errNemuB[numPointForRCalculation] + DATA_errNmueB[numPointForRCalculation]*DATA_errNmueB[numPointForRCalculation])) ;
 
 DATA_errR_ee[numPointForRCalculation] = sqrt(c1+c2+c3+c4+c5+c6);
 
 ///==== Rmumu from data = (NmumuA - kmumuA * NemuA) / (NmumuB - kmumuB * NemuB)
 denom = (DATA_NmumuB[numPointForRCalculation] - 1./2. * sqrt(DATA_NmumuB[numPointForRCalculation] / DATA_NeeB[numPointForRCalculation]) * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]));
 DATA_R_mumu[numPointForRCalculation] = (DATA_NmumuA[numPointForRCalculation] - 1./2. * sqrt(DATA_NmumuA[numPointForRCalculation] / DATA_NeeA[numPointForRCalculation]) * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation])) / (DATA_NmumuB[numPointForRCalculation] - 1./2. * sqrt(DATA_NmumuB[numPointForRCalculation] / DATA_NeeB[numPointForRCalculation]) * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]));
 
 c1 = 1./denom/denom * ((1 - 1./4. * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation]) / sqrt(DATA_NmumuA[numPointForRCalculation]*DATA_NeeA[numPointForRCalculation])) * DATA_errNmumuA[numPointForRCalculation]) * ((1 - 1./4. * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation]) / sqrt(DATA_NmumuA[numPointForRCalculation]*DATA_NeeA[numPointForRCalculation])) * DATA_errNmumuA[numPointForRCalculation]) ;
 c2 = 1./denom/denom * ((1./4. * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation]) / DATA_NeeA[numPointForRCalculation] * sqrt(DATA_NmumuA[numPointForRCalculation] / DATA_NeeA[numPointForRCalculation])) * DATA_errNeeA[numPointForRCalculation]) * ((1./4. * (DATA_NemuA[numPointForRCalculation] + DATA_NmueA[numPointForRCalculation]) / DATA_NeeA[numPointForRCalculation] * sqrt(DATA_NmumuA[numPointForRCalculation] / DATA_NeeA[numPointForRCalculation])) * DATA_errNeeA[numPointForRCalculation]) ;
 c3 = 1./denom/denom * (1./2. * sqrt(DATA_NmumuA[numPointForRCalculation] / DATA_NeeA[numPointForRCalculation]) * sqrt(DATA_errNemuA[numPointForRCalculation]*DATA_errNemuA[numPointForRCalculation] + DATA_errNmueA[numPointForRCalculation]*DATA_errNmueA[numPointForRCalculation])) * (1./2. * sqrt(DATA_NmumuA[numPointForRCalculation] / DATA_NeeA[numPointForRCalculation]) * sqrt(DATA_errNemuA[numPointForRCalculation]*DATA_errNemuA[numPointForRCalculation] + DATA_errNmueA[numPointForRCalculation]*DATA_errNmueA[numPointForRCalculation])) ;
 
 c4 = 1./denom/denom/denom/denom * ((1 - 1./4. * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]) / sqrt(DATA_NmumuB[numPointForRCalculation]*DATA_NeeB[numPointForRCalculation])) * DATA_errNmumuB[numPointForRCalculation]) * ((1 - 1./4. * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]) / sqrt(DATA_NmumuB[numPointForRCalculation]*DATA_NeeB[numPointForRCalculation])) * DATA_errNmumuB[numPointForRCalculation]) ;
 c5 = 1./denom/denom/denom/denom * ((1./4. * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]) / DATA_NeeB[numPointForRCalculation] * sqrt(DATA_NmumuB[numPointForRCalculation] / DATA_NeeB[numPointForRCalculation])) * DATA_errNeeB[numPointForRCalculation]) * ((1./4. * (DATA_NemuB[numPointForRCalculation]+DATA_NmueB[numPointForRCalculation]) / DATA_NeeB[numPointForRCalculation] * sqrt(DATA_NmumuB[numPointForRCalculation] / DATA_NeeB[numPointForRCalculation])) * DATA_errNeeB[numPointForRCalculation]) ;
 c6 = 1./denom/denom/denom/denom * (1./2. * sqrt(DATA_NmumuB[numPointForRCalculation] / DATA_NeeB[numPointForRCalculation]) * sqrt(DATA_errNemuB[numPointForRCalculation]*DATA_errNemuB[numPointForRCalculation] + DATA_errNmueB[numPointForRCalculation]*DATA_errNmueB[numPointForRCalculation])) * (1./2. * sqrt(DATA_NmumuB[numPointForRCalculation] / DATA_NeeB[numPointForRCalculation]) * sqrt(DATA_errNemuB[numPointForRCalculation]*DATA_errNemuB[numPointForRCalculation] + DATA_errNmueB[numPointForRCalculation]*DATA_errNmueB[numPointForRCalculation])) ;
 
 DATA_errR_mumu[numPointForRCalculation] = sqrt(c1+c2+c3+c4+c5+c6);
 
 ///==== Results: NDY_A_ee_extrapolated = (NeeB - keeB * NemuB) * Rinout|calculated at met>16
 
 double NB, errNB, denom, c4, c5, c6;
 NB = (DATA_NeeB[numPointForDYCalculation] - 1./2. * sqrt(DATA_NeeB[numPointForDYCalculation] / DATA_NmumuB[numPointForDYCalculation]) * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]));  
 c4 =  ((1 - 1./4. * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]) / sqrt(DATA_NmumuB[numPointForDYCalculation]*DATA_NeeB[numPointForDYCalculation])) * DATA_errNmumuB[numPointForDYCalculation]) * ((1 - 1./4. * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]) / sqrt(DATA_NmumuB[numPointForDYCalculation]*DATA_NeeB[numPointForDYCalculation])) * DATA_errNmumuB[numPointForDYCalculation]) ;
 c5 =  ((1./4. * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]) / DATA_NeeB[numPointForDYCalculation] * sqrt(DATA_NmumuB[numPointForDYCalculation] / DATA_NeeB[numPointForDYCalculation])) * DATA_errNeeB[numPointForDYCalculation]) * ((1./4. * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]) / DATA_NeeB[numPointForDYCalculation] * sqrt(DATA_NmumuB[numPointForDYCalculation] / DATA_NeeB[numPointForDYCalculation])) * DATA_errNeeB[numPointForDYCalculation]) ;
 c6 =  (1./2. * sqrt(DATA_NmumuB[numPointForDYCalculation] / DATA_NeeB[numPointForDYCalculation]) * sqrt(DATA_errNemuB[numPointForDYCalculation]*DATA_errNemuB[numPointForDYCalculation] + DATA_errNmueB[numPointForDYCalculation]*DATA_errNmueB[numPointForDYCalculation])) * (1./2. * sqrt(DATA_NmumuB[numPointForDYCalculation] / DATA_NeeB[numPointForDYCalculation]) * sqrt(DATA_errNemuB[numPointForDYCalculation]*DATA_errNemuB[numPointForDYCalculation] + DATA_errNmueB[numPointForDYCalculation]*DATA_errNmueB[numPointForDYCalculation])) ;
 errNB = sqrt(c4 + c5 + c6); 
 DATA_NDY_A_ee[numPointForDYCalculation]     = NB * DATA_R_ee[numPointForRCalculation]; 
 DATA_errNDY_A_ee[numPointForDYCalculation]  = sqrt ((NB * DATA_errR_ee[numPointForRCalculation] * NB * DATA_errR_ee[numPointForRCalculation]) + DATA_R_ee[numPointForRCalculation] * DATA_R_ee[numPointForRCalculation] * (c4 + c5 + c6));
 
 
 
 DATA_NDYCorrected_A_ee[numPointForDYCalculation]  = all_NeeA[numPointForDYCalculation] - DY_NeeA[numPointForDYCalculation] + DATA_NDY_A_ee[numPointForDYCalculation];
 DATA_errNDYCorrected_A_ee[numPointForDYCalculation] = sqrt(all_errNeeA[numPointForDYCalculation]*all_errNeeA[numPointForDYCalculation] + DY_errNeeA[numPointForDYCalculation]*DY_errNeeA[numPointForDYCalculation] + DATA_errNDY_A_ee[numPointForDYCalculation]*DATA_errNDY_A_ee[numPointForDYCalculation]);
 
 ///==== Results: NDY_A_mumu_extrapolated = (NmumuB - kmumuB * NemuB) * Rinout|calculated at met>16
 NB = (DATA_NmumuB[numPointForDYCalculation] - 1./2. * sqrt(DATA_NmumuB[numPointForDYCalculation] / DATA_NeeB[numPointForDYCalculation]) * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]));  
 c4 =  ((1 - 1./4. * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]) / sqrt(DATA_NeeB[numPointForDYCalculation]*DATA_NmumuB[numPointForDYCalculation])) * DATA_errNeeB[numPointForDYCalculation]) * ((1 - 1./4. * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]) / sqrt(DATA_NeeB[numPointForDYCalculation]*DATA_NmumuB[numPointForDYCalculation])) * DATA_errNeeB[numPointForDYCalculation]) ;
 c5 =  ((1./4. * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]) / DATA_NmumuB[numPointForDYCalculation] * sqrt(DATA_NeeB[numPointForDYCalculation] / DATA_NmumuB[numPointForDYCalculation])) * DATA_errNmumuB[numPointForDYCalculation]) * ((1./4. * (DATA_NemuB[numPointForDYCalculation]+DATA_NmueB[numPointForDYCalculation]) / DATA_NmumuB[numPointForDYCalculation] * sqrt(DATA_NeeB[numPointForDYCalculation] / DATA_NmumuB[numPointForDYCalculation])) * DATA_errNmumuB[numPointForDYCalculation]) ;
 c6 =  (1./2. * sqrt(DATA_NeeB[numPointForDYCalculation] / DATA_NmumuB[numPointForDYCalculation]) * sqrt(DATA_errNemuB[numPointForDYCalculation]*DATA_errNemuB[numPointForDYCalculation] + DATA_errNmueB[numPointForDYCalculation]*DATA_errNmueB[numPointForDYCalculation])) * (1./2. * sqrt(DATA_NeeB[numPointForDYCalculation] / DATA_NmumuB[numPointForDYCalculation]) * sqrt(DATA_errNemuB[numPointForDYCalculation]*DATA_errNemuB[numPointForDYCalculation] + DATA_errNmueB[numPointForDYCalculation]*DATA_errNmueB[numPointForDYCalculation])) ;
 errNB = sqrt(c4 + c5 + c6); 
 DATA_NDY_A_mumu[numPointForDYCalculation]     = NB * DATA_R_mumu[numPointForRCalculation]; 
 DATA_errNDY_A_mumu[numPointForDYCalculation]  = sqrt ((NB * DATA_errR_mumu[numPointForRCalculation] * NB * DATA_errR_mumu[numPointForRCalculation]) + DATA_R_mumu[numPointForRCalculation] * DATA_R_mumu[numPointForRCalculation] * (c4 + c5 + c6));
 
 
 
 DATA_NDYCorrected_A_mumu[numPointForDYCalculation]  = all_NmumuA[numPointForDYCalculation] - DY_NmumuA[numPointForDYCalculation] + DATA_NDY_A_mumu[numPointForDYCalculation];
 DATA_errNDYCorrected_A_mumu[numPointForDYCalculation] = sqrt(all_errNmumuA[numPointForDYCalculation]*all_errNmumuA[numPointForDYCalculation] + DY_errNmumuA[numPointForDYCalculation]*DY_errNmumuA[numPointForDYCalculation] + DATA_errNDY_A_mumu[numPointForDYCalculation]*DATA_errNDY_A_mumu[numPointForDYCalculation]);
 
 */
 
 
 
 
 /*
 
 ///==== Ree from data = (NeeA - keeA' * NemuA) / (NeeB - keeB' * NemuB)
 
 numerator = DATA_NeeA[numPointForRCalculation] - sqrt(DATA_NeeA[numPointForRCalculation] / DATA_NmumuA[numPointForRCalculation] * DATA_NemuA[numPointForRCalculation] * DATA_NmueA[numPointForRCalculation] ) ;
 denom = (DATA_NeeB[numPointForRCalculation] - sqrt(DATA_NeeB[numPointForRCalculation] / DATA_NmumuB[numPointForRCalculation] * DATA_NemuB[numPointForRCalculation] * DATA_NmueB[numPointForRCalculation]));
 DATA_R_ee[numPointForRCalculation] = num / denom;

 c1 = DATA_errNeeA[numPointForRCalculation]   / denom *  (1. - 1./2. * sqrt(DATA_NemuA[numPointForRCalculation]*DATA_NmueA[numPointForRCalculation]/DATA_NeeA[numPointForRCalculation]/DATA_NmumuA[numPointForRCalculation]))  ;
 c2 = DATA_errNmumuA[numPointForRCalculation] / denom *  (1./2. * sqrt(DATA_NemuA[numPointForRCalculation]*DATA_NmueA[numPointForRCalculation]*DATA_NeeA[numPointForRCalculation]/DATA_NmumuA[numPointForRCalculation])/DATA_NmumuA[numPointForRCalculation]);
 c3 = DATA_errNemuA[numPointForRCalculation]  / denom *  (1./2. * sqrt(DATA_NeeA[numPointForRCalculation]*DATA_NmumuA[numPointForRCalculation]*DATA_NmueA[numPointForRCalculation]/DATA_NemuA[numPointForRCalculation]));
 c4 = DATA_errNmueA[numPointForRCalculation]  / denom *  (1./2. * sqrt(DATA_NeeA[numPointForRCalculation]*DATA_NmumuA[numPointForRCalculation]*DATA_NemuA[numPointForRCalculation]/DATA_NmueA[numPointForRCalculation]));
 
 c5 = DATA_errNeeB[numPointForRCalculation]   * num / denom / denom *  (1. - 1./2. * sqrt(DATA_NemuB[numPointForRCalculation]*DATA_NmueB[numPointForRCalculation]/DATA_NeeB[numPointForRCalculation]/DATA_NmumuB[numPointForRCalculation]))  ;
 c6 = DATA_errNmumuB[numPointForRCalculation] * num / denom / denom *  (1./2. * sqrt(DATA_NemuB[numPointForRCalculation]*DATA_NmueB[numPointForRCalculation]*DATA_NeeB[numPointForRCalculation]/DATA_NmumuB[numPointForRCalculation])/DATA_NmumuB[numPointForRCalculation]);
 c7 = DATA_errNemuB[numPointForRCalculation]  * num / denom / denom *  (1./2. * sqrt(DATA_NeeB[numPointForRCalculation]*DATA_NmumuB[numPointForRCalculation]*DATA_NmueB[numPointForRCalculation]/DATA_NemuB[numPointForRCalculation]));
 c8 = DATA_errNmueB[numPointForRCalculation]  * num / denom / denom *  (1./2. * sqrt(DATA_NeeB[numPointForRCalculation]*DATA_NmumuB[numPointForRCalculation]*DATA_NemuB[numPointForRCalculation]/DATA_NmueB[numPointForRCalculation]));
  
 DATA_errR_ee[numPointForRCalculation] = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4 + c5*c5 + c6*c6);

 
 ///==== Rmumu from data = (NmumuA - kmumuA' * NemuA) / (NmumuB - kmumuB' * NemuB)
 
 numerator = DATA_NmumuA[numPointForRCalculation] - sqrt(DATA_NmumuA[numPointForRCalculation] / DATA_NeeA[numPointForRCalculation] * DATA_NmueA[numPointForRCalculation] * DATA_NemuA[numPointForRCalculation] ) ;
 denom = (DATA_NmumuB[numPointForRCalculation] - sqrt(DATA_NmumuB[numPointForRCalculation] / DATA_NeeB[numPointForRCalculation] * DATA_NmueB[numPointForRCalculation] * DATA_NemuB[numPointForRCalculation]));
 DATA_R_mumu[numPointForRCalculation] = num / denom;
 
 c1 = DATA_errNmumuA[numPointForRCalculation]   / denom *  (1. - 1./2. * sqrt(DATA_NmueA[numPointForRCalculation]*DATA_NemuA[numPointForRCalculation]/DATA_NmumuA[numPointForRCalculation]/DATA_NeeA[numPointForRCalculation]))  ;
 c2 = DATA_errNeeA[numPointForRCalculation] / denom *  (1./2. * sqrt(DATA_NmueA[numPointForRCalculation]*DATA_NemuA[numPointForRCalculation]*DATA_NmumuA[numPointForRCalculation]/DATA_NeeA[numPointForRCalculation])/DATA_NeeA[numPointForRCalculation]);
 c3 = DATA_errNmueA[numPointForRCalculation]  / denom *  (1./2. * sqrt(DATA_NmumuA[numPointForRCalculation]*DATA_NeeA[numPointForRCalculation]*DATA_NemuA[numPointForRCalculation]/DATA_NmueA[numPointForRCalculation]));
 c4 = DATA_errNemuA[numPointForRCalculation]  / denom *  (1./2. * sqrt(DATA_NmumuA[numPointForRCalculation]*DATA_NeeA[numPointForRCalculation]*DATA_NmueA[numPointForRCalculation]/DATA_NemuA[numPointForRCalculation]));
 
 c5 = DATA_errNmumuB[numPointForRCalculation]   * num / denom / denom *  (1. - 1./2. * sqrt(DATA_NmueB[numPointForRCalculation]*DATA_NemuB[numPointForRCalculation]/DATA_NmumuB[numPointForRCalculation]/DATA_NeeB[numPointForRCalculation]))  ;
 c6 = DATA_errNeeB[numPointForRCalculation] * num / denom / denom *  (1./2. * sqrt(DATA_NmueB[numPointForRCalculation]*DATA_NemuB[numPointForRCalculation]*DATA_NmumuB[numPointForRCalculation]/DATA_NeeB[numPointForRCalculation])/DATA_NeeB[numPointForRCalculation]);
 c7 = DATA_errNmueB[numPointForRCalculation]  * num / denom / denom *  (1./2. * sqrt(DATA_NmumuB[numPointForRCalculation]*DATA_NeeB[numPointForRCalculation]*DATA_NemuB[numPointForRCalculation]/DATA_NmueB[numPointForRCalculation]));
 c8 = DATA_errNemuB[numPointForRCalculation]  * num / denom / denom *  (1./2. * sqrt(DATA_NmumuB[numPointForRCalculation]*DATA_NeeB[numPointForRCalculation]*DATA_NmueB[numPointForRCalculation]/DATA_NemuB[numPointForRCalculation]));
 
 DATA_errR_mumu[numPointForRCalculation] = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4 + c5*c5 + c6*c6);
 
 
 
 ///==== Results: NDY_A_ee_extrapolated = (NeeB - keeB' * NemuB) * Rinout|calculated at met>0
 
 NB = DATA_NeeB[numPointForDYCalculation] - sqrt(DATA_NeeB[numPointForDYCalculation] / DATA_NmumuB[numPointForDYCalculation] * DATA_NemuB[numPointForDYCalculation] * DATA_NmueB[numPointForDYCalculation]);
 
 c1 = DATA_errNeeB[numPointForDYCalculation]    *  (1. - 1./2. * sqrt(DATA_NemuB[numPointForDYCalculation]*DATA_NmueB[numPointForDYCalculation]/DATA_NeeB[numPointForDYCalculation]/DATA_NmumuB[numPointForDYCalculation]))  ;
 c2 = DATA_errNmumuB[numPointForDYCalculation]  *  (1./2. * sqrt(DATA_NemuB[numPointForDYCalculation]*DATA_NmueB[numPointForDYCalculation]*DATA_NeeB[numPointForDYCalculation]/DATA_NmumuB[numPointForDYCalculation])/DATA_NmumuB[numPointForDYCalculation]);
 c3 = DATA_NemuB[numPointForDYCalculation] ? (DATA_errNemuB[numPointForDYCalculation]   *  (1./2. * sqrt(DATA_NeeB[numPointForDYCalculation]*DATA_NmumuB[numPointForDYCalculation]*DATA_NmueB[numPointForDYCalculation]/DATA_NemuB[numPointForDYCalculation]))) : 0.;
 c4 = DATA_NmueB[numPointForDYCalculation] ? (DATA_errNmueB[numPointForDYCalculation]   *  (1./2. * sqrt(DATA_NeeB[numPointForDYCalculation]*DATA_NmumuB[numPointForDYCalculation]*DATA_NemuB[numPointForDYCalculation]/DATA_NmueB[numPointForDYCalculation]))) : 0.;
 errNB = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4); 
 
 DATA_NDY_A_ee[numPointForDYCalculation]     = NB * DATA_R_ee[numPointForRCalculation]; 
 DATA_errNDY_A_ee[numPointForDYCalculation]  = sqrt ((NB * DATA_errR_ee[numPointForRCalculation] * NB * DATA_errR_ee[numPointForRCalculation]) + DATA_R_ee[numPointForRCalculation] * DATA_R_ee[numPointForRCalculation] * (c4 + c5 + c6));
 
 DATA_NDYCorrected_A_ee[numPointForDYCalculation]  = all_NeeA[numPointForDYCalculation] - DY_NeeA[numPointForDYCalculation] + DATA_NDY_A_ee[numPointForDYCalculation];
 DATA_errNDYCorrected_A_ee[numPointForDYCalculation] = sqrt(all_errNeeA[numPointForDYCalculation]*all_errNeeA[numPointForDYCalculation] + DY_errNeeA[numPointForDYCalculation]*DY_errNeeA[numPointForDYCalculation] + DATA_errNDY_A_ee[numPointForDYCalculation]*DATA_errNDY_A_ee[numPointForDYCalculation]);
 
 ///==== Results: NDY_A_mumu_extrapolated = (NmumuB - kmumuB' * NemuB) * Rinout|calculated at met>0
 
 NB = DATA_NmumuB[numPointForDYCalculation] - sqrt(DATA_NmumuB[numPointForDYCalculation] / DATA_NeeB[numPointForDYCalculation] * DATA_NmueB[numPointForDYCalculation] * DATA_NemuB[numPointForDYCalculation]);
 
 c1 = DATA_errNmumuB[numPointForDYCalculation]    *  (1. - 1./2. * sqrt(DATA_NmueB[numPointForDYCalculation]*DATA_NemuB[numPointForDYCalculation]/DATA_NmumuB[numPointForDYCalculation]/DATA_NeeB[numPointForDYCalculation]))  ;
 c2 = DATA_errNeeB[numPointForDYCalculation]  *  (1./2. * sqrt(DATA_NmueB[numPointForDYCalculation]*DATA_NemuB[numPointForDYCalculation]*DATA_NmumuB[numPointForDYCalculation]/DATA_NeeB[numPointForDYCalculation])/DATA_NeeB[numPointForDYCalculation]);
 c3 = DATA_NmueB[numPointForDYCalculation] ? (DATA_errNmueB[numPointForDYCalculation]   *  (1./2. * sqrt(DATA_NmumuB[numPointForDYCalculation]*DATA_NeeB[numPointForDYCalculation]*DATA_NemuB[numPointForDYCalculation]/DATA_NmueB[numPointForDYCalculation]))) : 0.;
 c4 = DATA_NemuB[numPointForDYCalculation] ? (DATA_errNemuB[numPointForDYCalculation]   *  (1./2. * sqrt(DATA_NmumuB[numPointForDYCalculation]*DATA_NeeB[numPointForDYCalculation]*DATA_NmueB[numPointForDYCalculation]/DATA_NemuB[numPointForDYCalculation]))) : 0.;
 errNB = sqrt(c1*c1 + c2*c2 + c3*c3 + c4*c4); 
 
 DATA_NDY_A_mumu[numPointForDYCalculation]     = NB * DATA_R_mumu[numPointForRCalculation]; 
 DATA_errNDY_A_mumu[numPointForDYCalculation]  = sqrt ((NB * DATA_errR_mumu[numPointForRCalculation] * NB * DATA_errR_mumu[numPointForRCalculation]) + DATA_R_mumu[numPointForRCalculation] * DATA_R_mumu[numPointForRCalculation] * (c4 + c5 + c6));
 
 DATA_NDYCorrected_A_mumu[numPointForDYCalculation]  = all_NmumuA[numPointForDYCalculation] - DY_NmumuA[numPointForDYCalculation] + DATA_NDY_A_mumu[numPointForDYCalculation];
 DATA_errNDYCorrected_A_mumu[numPointForDYCalculation] = sqrt(all_errNmumuA[numPointForDYCalculation]*all_errNmumuA[numPointForDYCalculation] + DY_errNmumuA[numPointForDYCalculation]*DY_errNmumuA[numPointForDYCalculation] + DATA_errNDY_A_mumu[numPointForDYCalculation]*DATA_errNDY_A_mumu[numPointForDYCalculation]);
 
 */
 
 
 
 
 
 
 
 
 
 
 
 
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


