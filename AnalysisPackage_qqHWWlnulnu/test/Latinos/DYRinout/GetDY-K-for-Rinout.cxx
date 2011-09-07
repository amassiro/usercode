// r00t test/Latinos/DYRinout/GetDYRinout.cxx\(\"out_test_Latinos_26July2011_1100.root\"\)

void GetDY_K_for_Rinout(TString nameRootFile){
 
 TFile* fileIn = new TFile(nameRootFile,"READ");
 
 
 gStyle->SetTitleX(0.2f);
 gStyle->SetTitleW(0.5f);
 
//  int numPointForRCalculation = 3;
 int numPointForRCalculation = 0;
//  int numPointForDYCalculation = 21;
 int numPointForDYCalculation = 1;
 
//  int numPlot = 20;
 int numPlot = 23;
 
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
 
 
  
 double DATA_KB_ee[100];
 double DATA_KB_mumu[100];
 double DATA_errKB_ee[100];
 double DATA_errKB_mumu[100]; 
 
 double DATA_KBNew_ee[100];
 double DATA_KBNew_mumu[100];
 double DATA_errKBNew_ee[100];
 double DATA_errKBNew_mumu[100]; 
 
 
 double DATA_KA_ee[100];
 double DATA_KA_mumu[100];
 double DATA_errKA_ee[100];
 double DATA_errKA_mumu[100]; 
 
 double DATA_KANew_ee[100];
 double DATA_KANew_mumu[100];
 double DATA_errKANew_ee[100];
 double DATA_errKANew_mumu[100]; 
 

 
 
 double DY_KB_ee[100];
 double DY_KB_mumu[100];
 double DY_errKB_ee[100];
 double DY_errKB_mumu[100]; 
 
 double DY_KBNew_ee[100];
 double DY_KBNew_mumu[100];
 double DY_errKBNew_ee[100];
 double DY_errKBNew_mumu[100]; 
 
 
 double DY_KA_ee[100];
 double DY_KA_mumu[100];
 double DY_errKA_ee[100];
 double DY_errKA_mumu[100]; 
 
 double DY_KANew_ee[100];
 double DY_KANew_mumu[100];
 double DY_errKANew_ee[100];
 double DY_errKANew_mumu[100]; 
 
 
 
 double other_KB_ee[100];
 double other_KB_mumu[100];
 double other_errKB_ee[100];
 double other_errKB_mumu[100]; 
 
 double other_KBNew_ee[100];
 double other_KBNew_mumu[100];
 double other_errKBNew_ee[100];
 double other_errKBNew_mumu[100]; 
 
 
 double other_KA_ee[100];
 double other_KA_mumu[100];
 double other_errKA_ee[100];
 double other_errKA_mumu[100]; 
 
 double other_KANew_ee[100];
 double other_KANew_mumu[100];
 double other_errKANew_ee[100];
 double other_errKANew_mumu[100]; 
 
 
 
 
 double all_KB_ee[100];
 double all_KB_mumu[100];
 double all_errKB_ee[100];
 double all_errKB_mumu[100]; 
 
 double all_KBNew_ee[100];
 double all_KBNew_mumu[100];
 double all_errKBNew_ee[100];
 double all_errKBNew_mumu[100]; 
 
 
 double all_KA_ee[100];
 double all_KA_mumu[100];
 double all_errKA_ee[100];
 double all_errKA_mumu[100]; 
 
 double all_KANew_ee[100];
 double all_KANew_mumu[100];
 double all_errKANew_ee[100];
 double all_errKANew_mumu[100]; 
 
 
 
 
 
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
  
  DATA_KB_ee[iCut] = 0.5 * sqrt(DATA_NeeB[iCut] / DATA_NmumuB[iCut]) ;
  a3 = (DATA_errNeeB[iCut] * DATA_errNeeB[iCut]  * (1. / 4. / DATA_NmumuB[iCut] / DATA_NeeB[iCut] )  ) ;
  a4 = (DATA_errNmumuB[iCut] * DATA_errNmumuB[iCut] * (1. / 4. * DATA_NeeB[iCut] / DATA_NmumuB[iCut] ) / DATA_NmumuB[iCut] / DATA_NmumuB[iCut] );
  DATA_errKB_ee[iCut] = 0.5 * sqrt(a3 + a4); 

  DATA_KB_mumu[iCut] = 0.5 * sqrt(DATA_NmumuB[iCut] / DATA_NeeB[iCut]) ;
  a3 = (DATA_errNmumuB[iCut] * DATA_errNmumuB[iCut]     * (1. / 4. / DATA_NeeB[iCut] / DATA_NmumuB[iCut] )  ) ;
  a4 = (DATA_errNeeB[iCut] * DATA_errNeeB[iCut] * (1. / 4. * DATA_NmumuB[iCut] / DATA_NeeB[iCut] ) / DATA_NeeB[iCut] / DATA_NeeB[iCut] );
  DATA_errKB_mumu[iCut] = 0.5 * sqrt(a3 + a4); 
  

  DATA_KA_ee[iCut] = 0.5 * sqrt(DATA_NeeA[iCut] / DATA_NmumuA[iCut]) ;
  a3 = (DATA_errNeeA[iCut] * DATA_errNeeA[iCut]     * (1. / 4. / DATA_NmumuA[iCut] / DATA_NeeA[iCut] )  ) ;
  a4 = (DATA_errNmumuA[iCut] * DATA_errNmumuA[iCut] * (1. / 4. * DATA_NeeA[iCut] / DATA_NmumuA[iCut] ) / DATA_NmumuA[iCut] / DATA_NmumuA[iCut] );
  DATA_errKA_ee[iCut] = 0.5 * sqrt(a3 + a4); 
  
  DATA_KA_mumu[iCut] = 0.5 * sqrt(DATA_NmumuA[iCut] / DATA_NeeA[iCut]) ;
  a3 = (DATA_errNmumuA[iCut] * DATA_errNmumuA[iCut]     * (1. / 4. / DATA_NeeA[iCut] / DATA_NmumuA[iCut] )  ) ;
  a4 = (DATA_errNeeA[iCut] * DATA_errNeeA[iCut] *  ( 1. / 4. * DATA_NmumuA[iCut] / DATA_NeeA[iCut] ) / DATA_NeeA[iCut] / DATA_NeeA[iCut] );
  DATA_errKA_mumu[iCut] = 0.5 * sqrt(a3 + a4); 
  
  //~~~~~
  
  other_KB_ee[iCut] = 0.5 * sqrt(other_NeeB[iCut] / other_NmumuB[iCut]) ;
  a3 = (other_errNeeB[iCut] * other_errNeeB[iCut]  * (1. / 4. / other_NmumuB[iCut] / other_NeeB[iCut] )  ) ;
  a4 = (other_errNmumuB[iCut] * other_errNmumuB[iCut] * (1. / 4. * other_NeeB[iCut] / other_NmumuB[iCut] ) / other_NmumuB[iCut] / other_NmumuB[iCut] );
  other_errKB_ee[iCut] = 0.5 * sqrt(a3 + a4); 
  
  other_KB_mumu[iCut] = 0.5 * sqrt(other_NmumuB[iCut] / other_NeeB[iCut]) ;
  a3 = (other_errNmumuB[iCut] * other_errNmumuB[iCut]     * (1. / 4. / other_NeeB[iCut] / other_NmumuB[iCut] )  ) ;
  a4 = (other_errNeeB[iCut] * other_errNeeB[iCut] * (1. / 4. * other_NmumuB[iCut] / other_NeeB[iCut] ) / other_NeeB[iCut] / other_NeeB[iCut] );
  other_errKB_mumu[iCut] = 0.5 * sqrt(a3 + a4); 
  
  
  other_KA_ee[iCut] = 0.5 * sqrt(other_NeeA[iCut] / other_NmumuA[iCut]) ;
  a3 = (other_errNeeA[iCut] * other_errNeeA[iCut]     * (1. / 4. / other_NmumuA[iCut] / other_NeeA[iCut] )  ) ;
  a4 = (other_errNmumuA[iCut] * other_errNmumuA[iCut] * (1. / 4. * other_NeeA[iCut] / other_NmumuA[iCut] ) / other_NmumuA[iCut] / other_NmumuA[iCut] );
  other_errKA_ee[iCut] = 0.5 * sqrt(a3 + a4); 
  
  other_KA_mumu[iCut] = 0.5 * sqrt(other_NmumuA[iCut] / other_NeeA[iCut]) ;
  a3 = (other_errNmumuA[iCut] * other_errNmumuA[iCut]     * (1. / 4. / other_NeeA[iCut] / other_NmumuA[iCut] )  ) ;
  a4 = (other_errNeeA[iCut] * other_errNeeA[iCut] *  ( 1. / 4. * other_NmumuA[iCut] / other_NeeA[iCut] ) / other_NeeA[iCut] / other_NeeA[iCut] );
  other_errKA_mumu[iCut] = 0.5 * sqrt(a3 + a4); 
  
  //~~~~~
  
  DY_KB_ee[iCut] = 0.5 * sqrt(DY_NeeB[iCut] / DY_NmumuB[iCut]) ;
  a3 = (DY_errNeeB[iCut] * DY_errNeeB[iCut]  * (1. / 4. / DY_NmumuB[iCut] / DY_NeeB[iCut] )  ) ;
  a4 = (DY_errNmumuB[iCut] * DY_errNmumuB[iCut] * (1. / 4. * DY_NeeB[iCut] / DY_NmumuB[iCut] ) / DY_NmumuB[iCut] / DY_NmumuB[iCut] );
  DY_errKB_ee[iCut] = 0.5 * sqrt(a3 + a4); 
  
  DY_KB_mumu[iCut] = 0.5 * sqrt(DY_NmumuB[iCut] / DY_NeeB[iCut]) ;
  a3 = (DY_errNmumuB[iCut] * DY_errNmumuB[iCut]     * (1. / 4. / DY_NeeB[iCut] / DY_NmumuB[iCut] )  ) ;
  a4 = (DY_errNeeB[iCut] * DY_errNeeB[iCut] * (1. / 4. * DY_NmumuB[iCut] / DY_NeeB[iCut] ) / DY_NeeB[iCut] / DY_NeeB[iCut] );
  DY_errKB_mumu[iCut] = 0.5 * sqrt(a3 + a4); 
  
  
  DY_KA_ee[iCut] = 0.5 * sqrt(DY_NeeA[iCut] / DY_NmumuA[iCut]) ;
  a3 = (DY_errNeeA[iCut] * DY_errNeeA[iCut]     * (1. / 4. / DY_NmumuA[iCut] / DY_NeeA[iCut] )  ) ;
  a4 = (DY_errNmumuA[iCut] * DY_errNmumuA[iCut] * (1. / 4. * DY_NeeA[iCut] / DY_NmumuA[iCut] ) / DY_NmumuA[iCut] / DY_NmumuA[iCut] );
  DY_errKA_ee[iCut] = 0.5 * sqrt(a3 + a4); 
  
  DY_KA_mumu[iCut] = 0.5 * sqrt(DY_NmumuA[iCut] / DY_NeeA[iCut]) ;
  a3 = (DY_errNmumuA[iCut] * DY_errNmumuA[iCut]     * (1. / 4. / DY_NeeA[iCut] / DY_NmumuA[iCut] )  ) ;
  a4 = (DY_errNeeA[iCut] * DY_errNeeA[iCut] *  ( 1. / 4. * DY_NmumuA[iCut] / DY_NeeA[iCut] ) / DY_NeeA[iCut] / DY_NeeA[iCut] );
  DY_errKA_mumu[iCut] = 0.5 * sqrt(a3 + a4); 
  
  
  //~~~~~
  
  all_KB_ee[iCut] = 0.5 * sqrt(all_NeeB[iCut] / all_NmumuB[iCut]) ;
  a3 = (all_errNeeB[iCut] * all_errNeeB[iCut]  * (1. / 4. / all_NmumuB[iCut] / all_NeeB[iCut] )  ) ;
  a4 = (all_errNmumuB[iCut] * all_errNmumuB[iCut] * (1. / 4. * all_NeeB[iCut] / all_NmumuB[iCut] ) / all_NmumuB[iCut] / all_NmumuB[iCut] );
  all_errKB_ee[iCut] = 0.5 * sqrt(a3 + a4); 
  
  all_KB_mumu[iCut] = 0.5 * sqrt(all_NmumuB[iCut] / all_NeeB[iCut]) ;
  a3 = (all_errNmumuB[iCut] * all_errNmumuB[iCut]     * (1. / 4. / all_NeeB[iCut] / all_NmumuB[iCut] )  ) ;
  a4 = (all_errNeeB[iCut] * all_errNeeB[iCut] * (1. / 4. * all_NmumuB[iCut] / all_NeeB[iCut] ) / all_NeeB[iCut] / all_NeeB[iCut] );
  all_errKB_mumu[iCut] = 0.5 * sqrt(a3 + a4); 
  
  
  all_KA_ee[iCut] = 0.5 * sqrt(all_NeeA[iCut] / all_NmumuA[iCut]) ;
  a3 = (all_errNeeA[iCut] * all_errNeeA[iCut]     * (1. / 4. / all_NmumuA[iCut] / all_NeeA[iCut] )  ) ;
  a4 = (all_errNmumuA[iCut] * all_errNmumuA[iCut] * (1. / 4. * all_NeeA[iCut] / all_NmumuA[iCut] ) / all_NmumuA[iCut] / all_NmumuA[iCut] );
  all_errKA_ee[iCut] = 0.5 * sqrt(a3 + a4); 
  
  all_KA_mumu[iCut] = 0.5 * sqrt(all_NmumuA[iCut] / all_NeeA[iCut]) ;
  a3 = (all_errNmumuA[iCut] * all_errNmumuA[iCut]     * (1. / 4. / all_NeeA[iCut] / all_NmumuA[iCut] )  ) ;
  a4 = (all_errNeeA[iCut] * all_errNeeA[iCut] *  ( 1. / 4. * all_NmumuA[iCut] / all_NeeA[iCut] ) / all_NeeA[iCut] / all_NeeA[iCut] );
  all_errKA_mumu[iCut] = 0.5 * sqrt(a3 + a4); 
  
  
  
  
  
  
  
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
 
 ///==== comparison two methods kaa and kmumu from "other" ====
 
 TGraphErrors* grDATA_KB_ee = new TGraphErrors(numPlot,X,DATA_KB_ee,errX,DATA_errKB_ee);
 grDATA_KB_ee->SetTitle("kee B");
 grDATA_KB_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_KB_ee->GetYaxis()->SetTitle("k ee other");
 grDATA_KB_ee->SetMarkerColor(kBlack);
 grDATA_KB_ee->SetFillColor(kWhite);
 grDATA_KB_ee->SetLineColor(kBlack);
 grDATA_KB_ee->SetMarkerStyle(25);
 grDATA_KB_ee->SetMarkerSize(1);
 grDATA_KB_ee->SetLineWidth(2);
 grDATA_KB_ee->SetLineStyle(2);
 
 
 TGraphErrors* grDATA_KB_mumu = new TGraphErrors(numPlot,X,DATA_KB_mumu,errX,DATA_errKB_mumu);
 grDATA_KB_mumu->SetTitle("k#mu#mu B");
 grDATA_KB_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_KB_mumu->GetYaxis()->SetTitle("k #mu#mu other");
 grDATA_KB_mumu->SetMarkerColor(kBlack);
 grDATA_KB_mumu->SetFillColor(kWhite);
 grDATA_KB_mumu->SetLineColor(kBlack);
 grDATA_KB_mumu->SetMarkerStyle(21);
 grDATA_KB_mumu->SetMarkerSize(1);
 grDATA_KB_mumu->SetLineWidth(2);
 grDATA_KB_mumu->SetLineStyle(2);
 
 
 
 
 
 TGraphErrors* grother_KB_ee = new TGraphErrors(numPlot,X,other_KB_ee,errX,other_errKB_ee);
 grother_KB_ee->SetTitle("kee B other");
 grother_KB_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_KB_ee->GetYaxis()->SetTitle("k ee other");
 grother_KB_ee->SetMarkerColor(kRed);
 grother_KB_ee->SetFillColor(kWhite);
 grother_KB_ee->SetLineColor(kRed);
 grother_KB_ee->SetMarkerStyle(29);
 grother_KB_ee->SetMarkerSize(2);
 grother_KB_ee->SetLineWidth(2);
 
 TGraphErrors* grother_KB_mumu = new TGraphErrors(numPlot,X,other_KB_mumu,errX,other_errKB_mumu);
 grother_KB_mumu->SetTitle("k#mu#mu B other");
 grother_KB_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_KB_mumu->GetYaxis()->SetTitle("k #mu#mu other");
 grother_KB_mumu->SetMarkerColor(kRed);
 grother_KB_mumu->SetFillColor(kWhite);
 grother_KB_mumu->SetLineColor(kRed);
 grother_KB_mumu->SetMarkerStyle(27);
 grother_KB_mumu->SetMarkerSize(2);
 grother_KB_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grDY_KB_ee = new TGraphErrors(numPlot,X,DY_KB_ee,errX,DY_errKB_ee);
 grDY_KB_ee->SetTitle("kee B DY");
 grDY_KB_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_KB_ee->GetYaxis()->SetTitle("k ee DY");
 grDY_KB_ee->SetMarkerColor(kBlue);
 grDY_KB_ee->SetFillColor(kWhite);
 grDY_KB_ee->SetLineColor(kBlue);
 grDY_KB_ee->SetMarkerStyle(29);
 grDY_KB_ee->SetMarkerSize(2);
 grDY_KB_ee->SetLineWidth(2);
 
 TGraphErrors* grDY_KB_mumu = new TGraphErrors(numPlot,X,DY_KB_mumu,errX,DY_errKB_mumu);
 grDY_KB_mumu->SetTitle("k#mu#mu B DY");
 grDY_KB_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_KB_mumu->GetYaxis()->SetTitle("k #mu#mu DY");
 grDY_KB_mumu->SetMarkerColor(kBlue);
 grDY_KB_mumu->SetFillColor(kWhite);
 grDY_KB_mumu->SetLineColor(kBlue);
 grDY_KB_mumu->SetMarkerStyle(27);
 grDY_KB_mumu->SetMarkerSize(2);
 grDY_KB_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grall_KB_ee = new TGraphErrors(numPlot,X,all_KB_ee,errX,all_errKB_ee);
 grall_KB_ee->SetTitle("kee B all");
 grall_KB_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_KB_ee->GetYaxis()->SetTitle("k ee all");
 grall_KB_ee->SetMarkerColor(kGreen);
 grall_KB_ee->SetFillColor(kWhite);
 grall_KB_ee->SetLineColor(kGreen);
 grall_KB_ee->SetMarkerStyle(29);
 grall_KB_ee->SetMarkerSize(2);
 grall_KB_ee->SetLineWidth(2);
 
 TGraphErrors* grall_KB_mumu = new TGraphErrors(numPlot,X,all_KB_mumu,errX,all_errKB_mumu);
 grall_KB_mumu->SetTitle("k#mu#mu B all");
 grall_KB_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_KB_mumu->GetYaxis()->SetTitle("k #mu#mu all");
 grall_KB_mumu->SetMarkerColor(kGreen);
 grall_KB_mumu->SetFillColor(kWhite);
 grall_KB_mumu->SetLineColor(kGreen);
 grall_KB_mumu->SetMarkerStyle(27);
 grall_KB_mumu->SetMarkerSize(2);
 grall_KB_mumu->SetLineWidth(2);
 
 
 TCanvas* cDATA_K_ee = new TCanvas("cDATA_K_ee","cDATA_K_ee",800,800); 
 
 TGraphErrors* grDATA_KA_ee = new TGraphErrors(numPlot,X,DATA_KA_ee,errX,DATA_errKA_ee);
 grDATA_KA_ee->SetTitle("kee A");
 grDATA_KA_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_KA_ee->GetYaxis()->SetTitle("k ee other");
 grDATA_KA_ee->SetMarkerColor(kBlack);
 grDATA_KA_ee->SetFillColor(kWhite);
 grDATA_KA_ee->SetLineColor(kBlack);
 grDATA_KA_ee->SetMarkerStyle(26);
 grDATA_KA_ee->SetMarkerSize(1);
 grDATA_KA_ee->SetLineWidth(2);
 grDATA_KA_ee->SetLineStyle(2);
 
 TGraphErrors* grother_KA_ee = new TGraphErrors(numPlot,X,other_KA_ee,errX,other_errKA_ee);
 grother_KA_ee->SetTitle("kee A other");
 grother_KA_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_KA_ee->GetYaxis()->SetTitle("k ee other");
 grother_KA_ee->SetMarkerColor(kRed);
 grother_KA_ee->SetFillColor(kWhite);
 grother_KA_ee->SetLineColor(kRed);
 grother_KA_ee->SetMarkerStyle(28);
 grother_KA_ee->SetMarkerSize(1);
 grother_KA_ee->SetLineWidth(2);

 TGraphErrors* grDY_KA_ee = new TGraphErrors(numPlot,X,DY_KA_ee,errX,DY_errKA_ee);
 grDY_KA_ee->SetTitle("kee A DY");
 grDY_KA_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_KA_ee->GetYaxis()->SetTitle("k ee DY");
 grDY_KA_ee->SetMarkerColor(kBlue);
 grDY_KA_ee->SetFillColor(kWhite);
 grDY_KA_ee->SetLineColor(kBlue);
 grDY_KA_ee->SetMarkerStyle(28);
 grDY_KA_ee->SetMarkerSize(1);
 grDY_KA_ee->SetLineWidth(2);
 
 TGraphErrors* grall_KA_ee = new TGraphErrors(numPlot,X,all_KA_ee,errX,all_errKA_ee);
 grall_KA_ee->SetTitle("kee A all");
 grall_KA_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_KA_ee->GetYaxis()->SetTitle("k ee all");
 grall_KA_ee->SetMarkerColor(kGreen);
 grall_KA_ee->SetFillColor(kWhite);
 grall_KA_ee->SetLineColor(kGreen);
 grall_KA_ee->SetMarkerStyle(28);
 grall_KA_ee->SetMarkerSize(1);
 grall_KA_ee->SetLineWidth(2);
 
 
 TMultiGraph* mgr_DATA_K_ee = new TMultiGraph(); 
 mgr_DATA_K_ee->Add(grDATA_KA_ee);
 mgr_DATA_K_ee->Add(grDATA_KB_ee);
 mgr_DATA_K_ee->Add(grother_KA_ee);
 mgr_DATA_K_ee->Add(grother_KB_ee);
 mgr_DATA_K_ee->Add(grDY_KA_ee);
 mgr_DATA_K_ee->Add(grDY_KB_ee);
 mgr_DATA_K_ee->Add(grall_KA_ee);
 mgr_DATA_K_ee->Add(grall_KB_ee);
 mgr_DATA_K_ee->Draw("AP");
 mgr_DATA_K_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_DATA_K_ee->GetYaxis()->SetTitle("k ee");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 
 
 TCanvas* cDATA_K_mumu = new TCanvas("cDATA_K_mumu","cDATA_K_mumu",800,800); 
 
 TGraphErrors* grDATA_KA_mumu = new TGraphErrors(numPlot,X,DATA_KA_mumu,errX,DATA_errKA_mumu);
 grDATA_KA_mumu->SetTitle("k#mu#mu A");
 grDATA_KA_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDATA_KA_mumu->GetYaxis()->SetTitle("k #mu#mu other");
 grDATA_KA_mumu->SetMarkerColor(kBlack);
 grDATA_KA_mumu->SetFillColor(kWhite);
 grDATA_KA_mumu->SetLineColor(kBlack);
 grDATA_KA_mumu->SetMarkerStyle(22);
 grDATA_KA_mumu->SetMarkerSize(1);
 grDATA_KA_mumu->SetLineWidth(2);
 grDATA_KA_mumu->SetLineStyle(2);
 
 TGraphErrors* grother_KA_mumu = new TGraphErrors(numPlot,X,other_KA_mumu,errX,other_errKA_mumu);
 grother_KA_mumu->SetTitle("k#mu#mu A other");
 grother_KA_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grother_KA_mumu->GetYaxis()->SetTitle("k #mu#mu other");
 grother_KA_mumu->SetMarkerColor(kRed);
 grother_KA_mumu->SetFillColor(kWhite);
 grother_KA_mumu->SetLineColor(kRed);
 grother_KA_mumu->SetMarkerStyle(30);
 grother_KA_mumu->SetMarkerSize(1);
 grother_KA_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grDY_KA_mumu = new TGraphErrors(numPlot,X,DY_KA_mumu,errX,DY_errKA_mumu);
 grDY_KA_mumu->SetTitle("k#mu#mu A DY");
 grDY_KA_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grDY_KA_mumu->GetYaxis()->SetTitle("k #mu#mu DY");
 grDY_KA_mumu->SetMarkerColor(kBlue);
 grDY_KA_mumu->SetFillColor(kWhite);
 grDY_KA_mumu->SetLineColor(kBlue);
 grDY_KA_mumu->SetMarkerStyle(30);
 grDY_KA_mumu->SetMarkerSize(1);
 grDY_KA_mumu->SetLineWidth(2);
 
 
 TGraphErrors* grall_KA_mumu = new TGraphErrors(numPlot,X,all_KA_mumu,errX,all_errKA_mumu);
 grall_KA_mumu->SetTitle("k#mu#mu A all");
 grall_KA_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 grall_KA_mumu->GetYaxis()->SetTitle("k #mu#mu all");
 grall_KA_mumu->SetMarkerColor(kGreen);
 grall_KA_mumu->SetFillColor(kWhite);
 grall_KA_mumu->SetLineColor(kGreen);
 grall_KA_mumu->SetMarkerStyle(30);
 grall_KA_mumu->SetMarkerSize(1);
 grall_KA_mumu->SetLineWidth(2);
 
 
 TMultiGraph* mgr_DATA_K_mumu = new TMultiGraph(); 
 mgr_DATA_K_mumu->Add(grDATA_KA_mumu);
 mgr_DATA_K_mumu->Add(grDATA_KB_mumu);
 mgr_DATA_K_mumu->Add(grother_KA_mumu);
 mgr_DATA_K_mumu->Add(grother_KB_mumu);
 mgr_DATA_K_mumu->Add(grDY_KA_mumu);
 mgr_DATA_K_mumu->Add(grDY_KB_mumu);
 mgr_DATA_K_mumu->Add(grall_KA_mumu);
 mgr_DATA_K_mumu->Add(grall_KB_mumu);
 mgr_DATA_K_mumu->Draw("AP");
 mgr_DATA_K_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_DATA_K_mumu->GetYaxis()->SetTitle("k #mu#mu");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 

}


