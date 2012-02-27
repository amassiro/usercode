void GetDY_Result_forDataCard(TString nameInFileRoot, int WorkingPoint = 1, int WorkingPointForK = 19){
 
 TFile* fileIn = new TFile(nameInFileRoot);

 double Nee_ZVsub_Result;
 double Nmumu_ZVsub_Result;
 double errNee_ZVsub_Result;
 double errNmumu_ZVsub_Result;
 
 double Nee_Result;
 double Nmumu_Result;
 double errNee_Result;
 double errNmumu_Result;
 
 
 
 double Nee_CR_A;
 double Nee_CR_B;
 double Nee_SR_A;
 double Nee_SR_B;
 
 double Nmumu_CR_A;
 double Nmumu_CR_B;
 double Nmumu_SR_A;
 double Nmumu_SR_B;
 
 double Nemu_CR_A;
 double Nemu_CR_B;
 double Nemu_SR_A;
 double Nemu_SR_B;

 double Nmue_CR_A;
 double Nmue_CR_B;
 double Nmue_SR_A;
 double Nmue_SR_B;
 
 
 double errNee_CR_A;
 double errNee_CR_B;
 double errNee_SR_A;
 double errNee_SR_B;
 
 double errNmumu_CR_A;
 double errNmumu_CR_B;
 double errNmumu_SR_A;
 double errNmumu_SR_B;
 
 double errNemu_CR_A;
 double errNemu_CR_B;
 double errNemu_SR_A;
 double errNemu_SR_B;
 
 double errNmue_CR_A;
 double errNmue_CR_B;
 double errNmue_SR_A;
 double errNmue_SR_B;
 
 
 double Nee_SR_A_DYee;
 double Nmumu_SR_A_DYmumu;
 
 double errNee_SR_A_DYee;
 double errNmumu_SR_A_DYmumu;
 
 double Nee_SR_A_DYtautau;
 double Nmumu_SR_A_DYtautau;
 double Nemu_SR_A_DYtautau;
 
 double errNee_SR_A_DYtautau;
 double errNmumu_SR_A_DYtautau;
 double errNemu_SR_A_DYtautau;
 

 
 
 double Nee_CR_A_ZV;
 double Nmumu_CR_A_ZV;
 double Nemu_CR_A_ZV;
 double Nmue_CR_A_ZV;
 double Nee_CR_B_ZV;
 double Nmumu_CR_B_ZV;
 double Nemu_CR_B_ZV;
 double Nmue_CR_B_ZV;
 
 double errNee_CR_A_ZV;
 double errNmumu_CR_A_ZV;
 double errNemu_CR_A_ZV;
 double errNmue_CR_A_ZV;
 double errNee_CR_B_ZV;
 double errNmumu_CR_B_ZV;
 double errNemu_CR_B_ZV;
 double errNmue_CR_B_ZV;
 
 double Nee_SR_B_ZV;
 double Nmumu_SR_B_ZV;
 double Nemu_SR_B_ZV;
 double Nmue_SR_B_ZV;
 
 double errNee_SR_B_ZV;
 double errNmumu_SR_B_ZV;
 double errNemu_SR_B_ZV;
 double errNmue_SR_B_ZV;
 
 
 
 ///---- for k ----
 double kB_em;
 double err_kB_em;
 double kB_me;
 double err_kB_me;
 
 double kA_em;
 double err_kA_em;
 double kA_me;
 double err_kA_me;
 
 
 double DATA_NeeA_forK;
 double DATA_NeeB_forK;
 double DATA_NmumuA_forK;
 double DATA_NmumuB_forK;

 double DATA_errNeeA_forK;
 double DATA_errNeeB_forK;
 double DATA_errNmumuA_forK;
 double DATA_errNmumuB_forK;
 
 
 ///=====================
 
 TString nameHistoInRootFile;
 TH1F* h; 
 
 ///==== MC ==== 
 
 nameHistoInRootFile = Form("Data/DYee_%d_0_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_A_DYee    = h->GetBinContent(2);
 errNee_SR_A_DYee = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYmumu_%d_1_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_A_DYmumu     = h->GetBinContent(2);
 errNmumu_SR_A_DYmumu  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYtautau_%d_0_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_A_DYtautau    = h->GetBinContent(2);
 errNee_SR_A_DYtautau = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYtautau_%d_1_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_A_DYtautau     = h->GetBinContent(2);
 errNmumu_SR_A_DYtautau  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYtautau_%d_2_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_A_DYtautau      = h->GetBinContent(2);
 errNemu_SR_A_DYtautau   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYtautau_%d_3_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_A_DYtautau      += h->GetBinContent(2);
 errNemu_SR_A_DYtautau   = sqrt (errNemu_SR_A_DYtautau*errNemu_SR_A_DYtautau + h->GetBinError(2) * h->GetBinError(2)); 
 
 
 
  nameHistoInRootFile = Form("Data/ZV_%d_0_Tot_temp",0+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nee_CR_A_ZV    = h->GetBinContent(2);
  errNee_CR_A_ZV = h->GetBinError(2);
  
  nameHistoInRootFile = Form("Data/ZV_%d_1_Tot_temp",0+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nmumu_CR_A_ZV     = h->GetBinContent(2);
  errNmumu_CR_A_ZV  = h->GetBinError(2);

  nameHistoInRootFile = Form("Data/ZV_%d_2_Tot_temp",0+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nemu_CR_A_ZV     = h->GetBinContent(2);
  errNemu_CR_A_ZV  = h->GetBinError(2);
  
  nameHistoInRootFile = Form("Data/ZV_%d_3_Tot_temp",0+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nmue_CR_A_ZV     = h->GetBinContent(2);
  errNmue_CR_A_ZV  = h->GetBinError(2);
  
  
  nameHistoInRootFile = Form("Data/ZV_%d_0_Tot_temp",1+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nee_CR_B_ZV    = h->GetBinContent(2);
  errNee_CR_B_ZV = h->GetBinError(2);
  
  nameHistoInRootFile = Form("Data/ZV_%d_1_Tot_temp",1+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nmumu_CR_B_ZV     = h->GetBinContent(2);
  errNmumu_CR_B_ZV  = h->GetBinError(2);
  
  nameHistoInRootFile = Form("Data/ZV_%d_2_Tot_temp",1+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nemu_CR_B_ZV     = h->GetBinContent(2);
  errNemu_CR_B_ZV  = h->GetBinError(2);
  
  nameHistoInRootFile = Form("Data/ZV_%d_3_Tot_temp",1+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nmue_CR_B_ZV     = h->GetBinContent(2);
  errNmue_CR_B_ZV  = h->GetBinError(2);
  
  
  nameHistoInRootFile = Form("Data/ZV_%d_0_Tot_temp",3+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nee_SR_B_ZV    = h->GetBinContent(2);
  errNee_SR_B_ZV = h->GetBinError(2);
  
  nameHistoInRootFile = Form("Data/ZV_%d_1_Tot_temp",3+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nmumu_SR_B_ZV     = h->GetBinContent(2);
  errNmumu_SR_B_ZV  = h->GetBinError(2);
  
  nameHistoInRootFile = Form("Data/ZV_%d_2_Tot_temp",3+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nemu_SR_B_ZV     = h->GetBinContent(2);
  errNemu_SR_B_ZV  = h->GetBinError(2);
  
  nameHistoInRootFile = Form("Data/ZV_%d_3_Tot_temp",3+(WorkingPoint-1)*4);
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  Nmue_SR_B_ZV     = h->GetBinContent(2);
  errNmue_SR_B_ZV  = h->GetBinError(2);
  
  
  
 
 ///==== DATA ====
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",0+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_A    = h->GetBinContent(2);
 errNee_CR_A = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",0+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_A     = h->GetBinContent(2);
 errNmumu_CR_A  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",0+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_A      = h->GetBinContent(2);
 errNemu_CR_A   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",0+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_A      = h->GetBinContent(2);
 errNmue_CR_A   = h->GetBinError(2); 
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",1+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_B    = h->GetBinContent(2);
 errNee_CR_B = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",1+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_B     = h->GetBinContent(2);
 errNmumu_CR_B  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",1+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_B      = h->GetBinContent(2);
 errNemu_CR_B   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",1+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_B      = h->GetBinContent(2);
 errNmue_CR_B   = h->GetBinError(2); 
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_A    = h->GetBinContent(2);
 errNee_SR_A = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_A     = h->GetBinContent(2);
 errNmumu_SR_A  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_A      = h->GetBinContent(2);
 errNemu_SR_A   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",2+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_SR_A      = h->GetBinContent(2);
 errNmue_SR_A   = h->GetBinError(2); 
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",3+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_B    = h->GetBinContent(2);
 errNee_SR_B = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",3+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_B     = h->GetBinContent(2);
 errNmumu_SR_B  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",3+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_B      = h->GetBinContent(2);
 errNemu_SR_B   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",3+(WorkingPoint-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_SR_B      = h->GetBinContent(2);
 errNmue_SR_B   = h->GetBinError(2); 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 //---- for k calculation ----
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",0+(WorkingPointForK-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 DATA_NeeA_forK    = h->GetBinContent(2);
 DATA_errNeeA_forK = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",0+(WorkingPointForK-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 DATA_NmumuA_forK     = h->GetBinContent(2);
 DATA_errNmumuA_forK  = h->GetBinError(2);
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",1+(WorkingPointForK-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 DATA_NeeB_forK    = h->GetBinContent(2);
 DATA_errNeeB_forK = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",1+(WorkingPointForK-1)*4);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 DATA_NmumuB_forK     = h->GetBinContent(2);
 DATA_errNmumuB_forK  = h->GetBinError(2);
  
 
 
 
 
 
 
 ///==== calculate result ====
 
 Nee_Result = (Nee_SR_B - sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B)) * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 Nmumu_Result = (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 
 
 double e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12;
 e1 = errNee_SR_B *   (1. - 0.5 * sqrt(1. / Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))    * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e2 = errNmumu_SR_B * (0.5 / Nmumu_SR_B * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B)) * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B / Nmue_SR_B))              * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B / Nemu_SR_B * Nmue_SR_B))              * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 

 e5 = errNee_CR_B *   (1. - 0.5 * sqrt(1. / Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))    * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e6 = errNmumu_CR_B * (0.5 / Nmumu_CR_B * sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e7 = !Nmue_CR_B ? 0 : errNemu_CR_B *  (0.5 * sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B / Nmue_CR_B))              * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e8 = !Nemu_CR_B ? 0 : errNmue_CR_B *  (0.5 * sqrt(Nee_CR_B / Nmumu_CR_B / Nemu_CR_B * Nmue_CR_B))              * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 
 e9  = errNee_CR_A *   (1. - 0.5 * sqrt(1. / Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A))    / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e10 = errNmumu_CR_A * (0.5 / Nmumu_CR_A * sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e11 = !Nmue_CR_A ? 0 : errNemu_CR_A *  (0.5 * sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A / Nmue_CR_A))              / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e12 = !Nemu_CR_A ? 0 : errNmue_CR_A *  (0.5 * sqrt(Nee_CR_A / Nmumu_CR_A / Nemu_CR_A * Nmue_CR_A))              / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
  
 errNee_Result = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4 + e5*e5 + e6*e6 + e7*e7 + e8*e8 + e9*e9 + e10*e10 + e11*e11 + e12*e12) ; 
 
 
 
 e1 = errNmumu_SR_B *   (1. - 0.5 * sqrt(1. / Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B))    * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e2 = errNee_SR_B * (0.5 / Nee_SR_B * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B / Nmue_SR_B))              * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B / Nemu_SR_B * Nmue_SR_B))              * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 
 e5 = errNmumu_CR_B *   (1. - 0.5 * sqrt(1. / Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))    * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e6 = errNee_CR_B * (0.5 / Nee_CR_B * sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e7 = !Nmue_CR_B ? 0 : errNemu_CR_B *  (0.5 * sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B / Nmue_CR_B))              * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e8 = !Nemu_CR_B ? 0 : errNmue_CR_B *  (0.5 * sqrt(Nmumu_CR_B / Nee_CR_B / Nemu_CR_B * Nmue_CR_B))              * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 
 e9  = errNmumu_CR_A *   (1. - 0.5 * sqrt(1. / Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A))    / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e10 = errNee_CR_A * (0.5 / Nee_CR_A * sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e11 = !Nmue_CR_A ? 0 : errNemu_CR_A *  (0.5 * sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A / Nmue_CR_A))              / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 e12 = !Nemu_CR_A ? 0 : errNmue_CR_A *  (0.5 * sqrt(Nmumu_CR_A / Nee_CR_A / Nemu_CR_A * Nmue_CR_A))              / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
 
 errNmumu_Result = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4 + e5*e5 + e6*e6 + e7*e7 + e8*e8 + e9*e9 + e10*e10 + e11*e11 + e12*e12) ; 
 
 
 
 
 
 
 
 
 std::cout << " ****************************** " << std::endl;
// // // // // // // //  std::cout << " >>> input <<< " << std::endl;
// // // // // // // //  std::cout << " Nee_SR_B   = " << Nee_SR_B   << " +/- " << errNee_SR_B   << std::endl;
// // // // // // // //  std::cout << " Nmumu_SR_B = " << Nmumu_SR_B << " +/- " << errNmumu_SR_B << std::endl;
// // // // // // // //  std::cout << " Nemu_SR_B  = " << Nemu_SR_B  << " +/- " << errNemu_SR_B  << std::endl;
// // // // // // // //  std::cout << " Nmue_SR_B  = " << Nmue_SR_B  << " +/- " << errNmue_SR_B  << std::endl;
// // // // // // // //  
// // // // // // // //  std::cout << " Nee_CR_B   = " << Nee_CR_B   << " +/- " << errNee_CR_B   << std::endl;
// // // // // // // //  std::cout << " Nmumu_CR_B = " << Nmumu_CR_B << " +/- " << errNmumu_CR_B << std::endl;
// // // // // // // //  std::cout << " Nemu_CR_B  = " << Nemu_CR_B  << " +/- " << errNemu_CR_B  << std::endl;
// // // // // // // //  std::cout << " Nmue_CR_B  = " << Nmue_CR_B  << " +/- " << errNmue_CR_B  << std::endl;
// // // // // // // //  
// // // // // // // //  std::cout << " Nee_CR_A   = " << Nee_CR_A   << " +/- " << errNee_CR_A   << std::endl;
// // // // // // // //  std::cout << " Nmumu_CR_A = " << Nmumu_CR_A << " +/- " << errNmumu_CR_A << std::endl;
// // // // // // // //  std::cout << " Nemu_CR_A  = " << Nemu_CR_A  << " +/- " << errNemu_CR_A  << std::endl;
// // // // // // // //  std::cout << " Nmue_CR_A  = " << Nmue_CR_A  << " +/- " << errNmue_CR_A  << std::endl;
// // // // // // // //  
// // // // // // // //  std::cout << " >>> R <<< " << std::endl;
// // // // // // // //  std::cout << " Ree    = " << (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))      << std::endl;
// // // // // // // //  std::cout << " Rmumu  = " << (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))  << std::endl; 
// // // // // // // //  std::cout << " >>> DY B CR <<< " << std::endl;
// // // // // // // //  std::cout << " ee   = " << (Nee_SR_B - sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))   << std::endl;
// // // // // // // //  std::cout << " mumu = " << (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) << std::endl; 
// // // // // // // //  
// // // // // // // //  std::cout << " >>> result <<< " << std::endl;
// // // // // // // //  std::cout << " Nee   = " << Nee_Result   << " +/- " << errNee_Result   << " ==> " << (!Nee_Result ? 0 : errNee_Result   / Nee_Result) << " == datacard ==> " << 1 + (!Nee_Result ? 0 : errNee_Result   / Nee_Result)   << std::endl;
// // // // // // // //  std::cout << " Nmumu = " << Nmumu_Result << " +/- " << errNmumu_Result << " ==> " << (!Nmumu_Result ? 0 : errNmumu_Result / Nmumu_Result ) << " == datacard ==> " << 1 + (!Nmumu_Result ? 0 : errNmumu_Result / Nmumu_Result ) << std::endl;
// // // // // // // //  std::cout << " >>> total <<< " << std::endl;
// // // // // // // //  std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) << " ==> " << (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
// // // // // // // //  std::cout << std::endl;
// // // // // // // //  std::cout << " WorkingPoint = " << WorkingPoint << std::endl;
// // // // // // // // 
// // // // // // // //  std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) << " ==> " << (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
// // // // // // // // //  std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) << " ==> " << (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
// // // // // // // //  
 std::cout << " ****************************** " << std::endl;
 
// // // // // // // //  double N_ee_DYDD_SR_B   = (Nee_SR_B   - sqrt(Nee_SR_B   / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B));
// // // // // // // //  e1 = errNee_SR_B *   (1. - 0.5 * sqrt(1. / Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))    ; 
// // // // // // // //  e2 = errNmumu_SR_B * (0.5 / Nmumu_SR_B * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B)) ; 
// // // // // // // //  e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B / Nmue_SR_B)) ; 
// // // // // // // //  e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B / Nemu_SR_B * Nmue_SR_B)) ; 
// // // // // // // //  double errN_ee_DYDD_SR_B = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4) ; 
// // // // // // // //  std::cout << " N (DY DD B) ee     = " << N_ee_DYDD_SR_B << " +/- " << errN_ee_DYDD_SR_B << std::endl; 
// // // // // // // //  
// // // // // // // //  double N_mumu_DYDD_SR_B = (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B));
// // // // // // // //  e1 = errNmumu_SR_B *   (1. - 0.5 * sqrt(1. / Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B))    ; 
// // // // // // // //  e2 = errNee_SR_B * (0.5 / Nee_SR_B * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) ; 
// // // // // // // //  e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B / Nmue_SR_B)) ; 
// // // // // // // //  e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B / Nemu_SR_B * Nmue_SR_B)) ; 
// // // // // // // //  double errN_mumu_DYDD_SR_B = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4) ; 
// // // // // // // //  std::cout << " N (DY DD B) mumu     = " << N_mumu_DYDD_SR_B << " +/- " << errN_mumu_DYDD_SR_B << std::endl; 
// // // // // // // //  std::cout << " Ree    = " << (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))      << std::endl;
// // // // // // // //  std::cout << " Rmumu  = " << (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))  << std::endl; 
// // // // // // // //  
// // // // // // // //  
// // // // // // // //  
// // // // // // // //  
// // // // // // // //  
// // // // // // // //  std::cout << std::endl;
// // // // // // // //  std::cout << " >>> MC <<< " << std::endl;
// // // // // // // //  std::cout << " Nee_SR_A_DYee       = " << Nee_SR_A_DYee     << " +/- " << errNee_SR_A_DYee      << std::endl;
// // // // // // // //  std::cout << " Nmumu_SR_A_DYmumu   = " << Nmumu_SR_A_DYmumu << " +/- " << errNmumu_SR_A_DYmumu  << std::endl;
// // // // // // // //  std::cout << std::endl;
// // // // // // // //  std::cout << " Nee_SR_A_DYtautau   = " << Nee_SR_A_DYtautau     << " +/- " << errNee_SR_A_DYtautau     << std::endl;
// // // // // // // //  std::cout << " Nmumu_SR_A_DYtautau = " << Nmumu_SR_A_DYtautau   << " +/- " << errNmumu_SR_A_DYtautau   << std::endl;
// // // // // // // //  std::cout << " Nemu_SR_A_DYtautau  = " << Nemu_SR_A_DYtautau    << " +/- " << errNemu_SR_A_DYtautau    << std::endl;
// // // // // // // //  
 
 
 
 
 
 
 ///==== calculate result with ZV subtraction ====
 Nee_CR_B    = Nee_CR_B   - Nee_CR_B_ZV;
 Nmumu_CR_B  = Nmumu_CR_B - Nmumu_CR_B_ZV;
 Nemu_CR_B   = Nemu_CR_B  - Nemu_CR_B_ZV;
 Nmue_CR_B   = Nmue_CR_B  - Nmue_CR_B_ZV;
 
 Nee_CR_A    = Nee_CR_A   - Nee_CR_A_ZV;
 Nmumu_CR_A  = Nmumu_CR_A - Nmumu_CR_A_ZV;
 Nemu_CR_A   = Nemu_CR_A  - Nemu_CR_A_ZV;
 Nmue_CR_A   = Nmue_CR_A  - Nmue_CR_A_ZV;
 
 Nee_SR_B    = Nee_SR_B   - Nee_SR_B_ZV;
 Nmumu_SR_B  = Nmumu_SR_B - Nmumu_SR_B_ZV;
 Nemu_SR_B   = Nemu_SR_B  - Nemu_SR_B_ZV;
 Nmue_SR_B   = Nmue_SR_B  - Nmue_SR_B_ZV;
 
 std::cout << " >>> input Corrected by ZV subtraction <<< " << std::endl;
 std::cout << " Nee_SR_B   = " << Nee_SR_B   << " +/- " << errNee_SR_B   << std::endl;
 std::cout << " Nmumu_SR_B = " << Nmumu_SR_B << " +/- " << errNmumu_SR_B << std::endl;
 std::cout << " Nemu_SR_B  = " << Nemu_SR_B  << " +/- " << errNemu_SR_B  << std::endl;
 std::cout << " Nmue_SR_B  = " << Nmue_SR_B  << " +/- " << errNmue_SR_B  << std::endl;
 
 std::cout << " Nee_CR_B   = " << Nee_CR_B   << " +/- " << errNee_CR_B   << std::endl;
 std::cout << " Nmumu_CR_B = " << Nmumu_CR_B << " +/- " << errNmumu_CR_B << std::endl;
 std::cout << " Nemu_CR_B  = " << Nemu_CR_B  << " +/- " << errNemu_CR_B  << std::endl;
 std::cout << " Nmue_CR_B  = " << Nmue_CR_B  << " +/- " << errNmue_CR_B  << std::endl;
 
 std::cout << " Nee_CR_A   = " << Nee_CR_A   << " +/- " << errNee_CR_A   << std::endl;
 std::cout << " Nmumu_CR_A = " << Nmumu_CR_A << " +/- " << errNmumu_CR_A << std::endl;
 std::cout << " Nemu_CR_A  = " << Nemu_CR_A  << " +/- " << errNemu_CR_A  << std::endl;
 std::cout << " Nmue_CR_A  = " << Nmue_CR_A  << " +/- " << errNmue_CR_A  << std::endl;
 
 if (Nee_CR_B<0)   Nee_CR_B = 0;
 if (Nmumu_CR_B<0) Nmumu_CR_B = 0;
 if (Nemu_CR_B<0)  Nemu_CR_B = 0;
 if (Nmue_CR_B<0)  Nmue_CR_B = 0;

 if (Nee_CR_A<0)   Nee_CR_A = 0;
 if (Nmumu_CR_A<0) Nmumu_CR_A = 0;
 if (Nemu_CR_A<0)  Nemu_CR_A = 0;
 if (Nmue_CR_A<0)  Nmue_CR_A = 0;
 
 if (Nee_SR_B<0)   Nee_SR_B = 0;
 if (Nmumu_SR_B<0) Nmumu_SR_B = 0;
 if (Nemu_SR_B<0)  Nemu_SR_B = 0;
 if (Nmue_SR_B<0)  Nmue_SR_B = 0;
 
 
 
 
 
 ///===========================================
 
 
 kB_em = sqrt (DATA_NeeB_forK / DATA_NmumuB_forK) ;
 err_kB_em = kB_em * 1. / 2. * sqrt(DATA_errNeeB_forK * DATA_errNeeB_forK * 1./(2. * DATA_NeeB_forK)/(2. * DATA_NeeB_forK) + DATA_errNmumuB_forK * DATA_errNmumuB_forK * 1./(2. * DATA_NmumuB_forK)/(2. * DATA_NmumuB_forK)) ;
 
 kB_me = 1. / kB_em ;
 err_kB_me = err_kB_em / kB_em / kB_em ;
 
 kA_em = sqrt (DATA_NeeA_forK / DATA_NmumuA_forK) ;
 err_kA_em = kA_em * 1. / 2. * sqrt(DATA_errNeeA_forK * DATA_errNeeA_forK * 1./(2. * DATA_NeeA_forK)/(2. * DATA_NeeA_forK) + DATA_errNmumuA_forK * DATA_errNmumuA_forK * 1./(2. * DATA_NmumuA_forK)/(2. * DATA_NmumuA_forK)) ;
 
 kA_me = 1. / kA_em ;
 err_kA_me = err_kA_em / kA_em / kA_em ;
 
 
 
//  double k_eu = sqrt (Nee_CR_B / Nmumu_CR_B) ;
//  double err_k_eu = sqrt (  0.25 * errNee_CR_B * errNee_CR_B / (Nee_CR_B * Nmumu_CR_B) +  0.25 * errNmumu_CR_B * errNmumu_CR_B * Nee_CR_B / (Nmumu_CR_B * Nmumu_CR_B)  ) ;
 
 double P1_ee = (Nee_SR_B - 0.5 * kB_em * (Nemu_SR_B + Nmue_SR_B)) ;
 double P2_ee = (Nee_CR_A - 0.5 * kA_em * (Nemu_CR_A + Nmue_CR_A)) ;
 double P3_ee = (Nee_CR_B - 0.5 * kB_em * (Nemu_CR_B + Nmue_CR_B)) ;
 
 if (P1_ee<0)   P1_ee = 0;
 if (P2_ee<0)   P2_ee = 0;
 if (P3_ee<0)   P3_ee = 0;
 
 Nee_Result = -1;
 if (P3_ee != 0) Nee_Result = P1_ee * P2_ee / P3_ee ;
 
 std::cout << " kB_em = " << kB_em << std::endl;
 std::cout << " kA_em = " << kA_em << std::endl;
 std::cout << " P2_ee = " << P2_ee << " = ( " << Nee_CR_A << " - 0.5 * " << kA_em << " * ( " << Nemu_CR_A << " + " << Nmue_CR_A << "))"  << std::endl;
 std::cout << " Nee_Result = " <<  Nee_Result << " = " <<  P1_ee << " * " << P2_ee << " / " << P3_ee << std::endl;
 
 double Esq_P1_ee = (errNee_SR_B * errNee_SR_B + 0.25 * err_kB_em * (Nemu_SR_B + Nmue_SR_B) * err_kB_em * (Nemu_SR_B + Nmue_SR_B) + 0.25 * kB_em * (errNemu_SR_B + errNmue_SR_B) * kB_em * (errNemu_SR_B + errNmue_SR_B)) ;
 double Esq_P2_ee = (errNee_CR_A * errNee_CR_A + 0.25 * err_kA_em * (Nemu_CR_A + Nmue_CR_A) * err_kA_em * (Nemu_CR_A + Nmue_CR_A) + 0.25 * kA_em * (errNemu_CR_A + errNmue_CR_A) * kA_em * (errNemu_CR_A + errNmue_CR_A)) ;
 double Esq_P3_ee = (errNee_CR_A * errNee_CR_B + 0.25 * err_kB_em * (Nemu_CR_B + Nmue_CR_B) * err_kB_em * (Nemu_CR_B + Nmue_CR_B) + 0.25 * kB_em * (errNemu_CR_B + errNmue_CR_B) * kB_em * (errNemu_CR_B + errNmue_CR_B)) ;
 
 errNee_Result = -1;
 if (P3_ee != 0) errNee_Result = sqrt (Esq_P1_ee * P2_ee / P3_ee + Esq_P2_ee * P1_ee / P3_ee + Esq_P3_ee * P1_ee * P2_ee / (P3_ee * P3_ee)) ;
 
 
 ///---- no R error propagation : + 20% at the end added
 errNee_Result = -1;
 if (P3_ee != 0) errNee_Result = sqrt (Esq_P1_ee * P2_ee / P3_ee) ;
 
 
 double P1_mumu = (Nmumu_SR_B - 0.5 * kB_me * (Nemu_SR_B + Nmue_SR_B)) ;
 double P2_mumu = (Nmumu_CR_A - 0.5 * kA_me * (Nemu_CR_A + Nmue_CR_A)) ;
 double P3_mumu = (Nmumu_CR_B - 0.5 * kB_me * (Nemu_CR_B + Nmue_CR_B)) ;
 
 if (P1_mumu<0)   P1_mumu = 0;
 if (P2_mumu<0)   P2_mumu = 0;
 if (P3_mumu<0)   P3_mumu = 0;
 
 Nmumu_Result = -1;
 if (P3_mumu != 0) Nmumu_Result = P1_mumu * P2_mumu / P3_mumu ;
 
 std::cout << " kB_em = " << kB_em << std::endl;
 std::cout << " kA_em = " << kA_em << std::endl;
 std::cout << " P2_mumu = " << P2_mumu << " = ( " << Nmumu_CR_A << " - 0.5 * " << kA_em << " * ( " << Nemu_CR_A << " + " << Nmue_CR_A << "))"  << std::endl;
 std::cout << " Nmumu_Result = " <<  Nmumu_Result << " = " <<  P1_mumu << " * " << P2_mumu << " / " << P3_mumu << std::endl;
 
 double Esq_P1_mumu = (errNmumu_SR_B * errNmumu_SR_B + 0.25 * err_kB_me * (Nemu_SR_B + Nmue_SR_B) * err_kB_me * (Nemu_SR_B + Nmue_SR_B) + 0.25 * kB_me * (errNemu_SR_B + errNmue_SR_B) * kB_me * (errNemu_SR_B + errNmue_SR_B)) ;
 double Esq_P2_mumu = (errNmumu_CR_A * errNmumu_CR_A + 0.25 * err_kA_me * (Nemu_CR_A + Nmue_CR_A) * err_kA_me * (Nemu_CR_A + Nmue_CR_A) + 0.25 * kA_me * (errNemu_CR_A + errNmue_CR_A) * kA_me * (errNemu_CR_A + errNmue_CR_A)) ;
 double Esq_P3_mumu = (errNmumu_CR_A * errNmumu_CR_B + 0.25 * err_kB_me * (Nemu_CR_B + Nmue_CR_B) * err_kB_me * (Nemu_CR_B + Nmue_CR_B) + 0.25 * kB_me * (errNemu_CR_B + errNmue_CR_B) * kB_me * (errNemu_CR_B + errNmue_CR_B)) ;
 
 errNmumu_Result = -1;
 if (P3_mumu != 0) errNmumu_Result = sqrt (Esq_P1_mumu * P2_mumu / P3_mumu + Esq_P2_mumu * P1_mumu / P3_mumu + Esq_P3_mumu * P1_mumu * P2_mumu / (P3_mumu * P3_mumu)) ;
 
 ///---- no R error propagation : + 20% at the end added
 errNmumu_Result = -1;
 if (P3_mumu != 0) errNmumu_Result = sqrt (Esq_P1_mumu * P2_mumu / P3_mumu ) ;
 
 
 
 double NmumuUnderPeak = (Nmumu_SR_B - 0.5 * kB_me * (Nemu_SR_B + Nmue_SR_B));
 double errNmumuUnderPeak = sqrt(Esq_P1_mumu);
 
 ///===========================================
  
 
 
 
//  
//  
//  Nee_Result = (Nee_SR_B - sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B)) * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  Nmumu_Result = (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  
//  
//  double e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12;
//  e1 = errNee_SR_B *   (1. - 0.5 * sqrt(1. / Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))    * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e2 = errNmumu_SR_B * (0.5 / Nmumu_SR_B * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B)) * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B / Nmue_SR_B))              * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B / Nemu_SR_B * Nmue_SR_B))              * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  
//  e5 = errNee_CR_B *   (1. - 0.5 * sqrt(1. / Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))    * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e6 = errNmumu_CR_B * (0.5 / Nmumu_CR_B * sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e7 = !Nmue_CR_B ? 0 : errNemu_CR_B *  (0.5 * sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B / Nmue_CR_B))              * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e8 = !Nemu_CR_B ? 0 : errNmue_CR_B *  (0.5 * sqrt(Nee_CR_B / Nmumu_CR_B / Nemu_CR_B * Nmue_CR_B))              * (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  
//  e9  = errNee_CR_A *   (1. - 0.5 * sqrt(1. / Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A))    / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e10 = errNmumu_CR_A * (0.5 / Nmumu_CR_A * sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e11 = !Nmue_CR_A ? 0 : errNemu_CR_A *  (0.5 * sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A / Nmue_CR_A))              / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e12 = !Nemu_CR_A ? 0 : errNmue_CR_A *  (0.5 * sqrt(Nee_CR_A / Nmumu_CR_A / Nemu_CR_A * Nmue_CR_A))              / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  
//  errNee_Result = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4 + e5*e5 + e6*e6 + e7*e7 + e8*e8 + e9*e9 + e10*e10 + e11*e11 + e12*e12) ; 
//  
//  
//  
//  e1 = errNmumu_SR_B *   (1. - 0.5 * sqrt(1. / Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B))    * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e2 = errNee_SR_B * (0.5 / Nee_SR_B * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B / Nmue_SR_B))              * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B / Nemu_SR_B * Nmue_SR_B))              * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  
//  e5 = errNmumu_CR_B *   (1. - 0.5 * sqrt(1. / Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))    * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e6 = errNee_CR_B * (0.5 / Nee_CR_B * sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e7 = !Nmue_CR_B ? 0 : errNemu_CR_B *  (0.5 * sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B / Nmue_CR_B))              * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e8 = !Nemu_CR_B ? 0 : errNmue_CR_B *  (0.5 * sqrt(Nmumu_CR_B / Nee_CR_B / Nemu_CR_B * Nmue_CR_B))              * (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  
//  e9  = errNmumu_CR_A *   (1. - 0.5 * sqrt(1. / Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A))    / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e10 = errNee_CR_A * (0.5 / Nee_CR_A * sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e11 = !Nmue_CR_A ? 0 : errNemu_CR_A *  (0.5 * sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A / Nmue_CR_A))              / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  e12 = !Nemu_CR_A ? 0 : errNmue_CR_A *  (0.5 * sqrt(Nmumu_CR_A / Nee_CR_A / Nemu_CR_A * Nmue_CR_A))              / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B)) ; 
//  
//  errNmumu_Result = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4 + e5*e5 + e6*e6 + e7*e7 + e8*e8 + e9*e9 + e10*e10 + e11*e11 + e12*e12) ; 
 
 
 
 
 
 std::cout << " ****************************** " << std::endl;
 std::cout << std::endl;
 std::cout << " >>> input <<< " << std::endl;
 std::cout << " Nee_SR_B_ZV   = " << Nee_SR_B_ZV   << " +/- " << errNee_SR_B_ZV   << std::endl;
 std::cout << " Nmumu_SR_B_ZV = " << Nmumu_SR_B_ZV << " +/- " << errNmumu_SR_B_ZV << std::endl;
 std::cout << " Nemu_SR_B_ZV  = " << Nemu_SR_B_ZV  << " +/- " << errNemu_SR_B_ZV  << std::endl;
 std::cout << " Nmue_SR_B_ZV  = " << Nmue_SR_B_ZV  << " +/- " << errNmue_SR_B_ZV  << std::endl;
 
 std::cout << " Nee_CR_B_ZV   = " << Nee_CR_B_ZV   << " +/- " << errNee_CR_B_ZV   << std::endl;
 std::cout << " Nmumu_CR_B_ZV = " << Nmumu_CR_B_ZV << " +/- " << errNmumu_CR_B_ZV << std::endl;
 std::cout << " Nemu_CR_B_ZV  = " << Nemu_CR_B_ZV  << " +/- " << errNemu_CR_B_ZV  << std::endl;
 std::cout << " Nmue_CR_B_ZV  = " << Nmue_CR_B_ZV  << " +/- " << errNmue_CR_B_ZV  << std::endl;
 
 std::cout << " Nee_CR_A_ZV   = " << Nee_CR_A_ZV   << " +/- " << errNee_CR_A_ZV   << std::endl;
 std::cout << " Nmumu_CR_A_ZV = " << Nmumu_CR_A_ZV << " +/- " << errNmumu_CR_A_ZV << std::endl;
 std::cout << " Nemu_CR_A_ZV  = " << Nemu_CR_A_ZV  << " +/- " << errNemu_CR_A_ZV  << std::endl;
 std::cout << " Nmue_CR_A_ZV  = " << Nmue_CR_A_ZV  << " +/- " << errNmue_CR_A_ZV  << std::endl;
 
//  std::cout << " >>> R <<< " << std::endl;
//  std::cout << " Ree    = " << (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))      << std::endl;
//  std::cout << " Rmumu  = " << (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))  << std::endl; 
//  std::cout << " >>> DY B CR <<< " << std::endl;
//  std::cout << " ee   = " << (Nee_SR_B - sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))   << std::endl;
//  std::cout << " mumu = " << (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) << std::endl; 
 
 std::cout << " >>> result <<< " << std::endl;
 std::cout << " Nee   = " << Nee_Result   << " +/- " << errNee_Result   ;
 std::cout << " ==> " << (Nee_Result==0 ?   0 : errNee_Result   / Nee_Result   ) << " == datacard ==> " << 1 + (Nee_Result==0 ?   0 : errNee_Result   / Nee_Result   ) << std::endl;
 std::cout << " Nmumu = " << Nmumu_Result << " +/- " << errNmumu_Result ;
 std::cout << " ==> " << (Nmumu_Result==0 ? 0 : errNmumu_Result / Nmumu_Result ) << " == datacard ==> " << 1 + (Nmumu_Result==0 ? 0 : errNmumu_Result / Nmumu_Result ) << std::endl;
 std::cout << " >>> total <<< " << std::endl;
 std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) << " ==> " << ((Nmumu_Result + Nee_Result)==0 ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + ((Nmumu_Result + Nee_Result)==0 ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
//  std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) << " ==> " << (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
 std::cout << std::endl;
 std::cout << " WorkingPoint = " << WorkingPoint << std::endl;
 
 std::cout << " ****************************** " << std::endl;
 
// // // // //  N_ee_DYDD_SR_B   = (Nee_SR_B   - sqrt(Nee_SR_B   / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B));
// // // // //  e1 = errNee_SR_B *   (1. - 0.5 * sqrt(1. / Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))    ; 
// // // // //  e2 = errNmumu_SR_B * (0.5 / Nmumu_SR_B * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B)) ; 
// // // // //  e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B / Nmue_SR_B)) ; 
// // // // //  e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B / Nemu_SR_B * Nmue_SR_B)) ; 
// // // // //  errN_ee_DYDD_SR_B = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4) ; 
// // // // //  std::cout << " N (DY DD B) ee     = " << N_ee_DYDD_SR_B << " +/- " << errN_ee_DYDD_SR_B << std::endl; 
// // // // //  
// // // // //  N_mumu_DYDD_SR_B = (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B));
// // // // //  e1 = errNmumu_SR_B *   (1. - 0.5 * sqrt(1. / Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B))    ; 
// // // // //  e2 = errNee_SR_B * (0.5 / Nee_SR_B * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) ; 
// // // // //  e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B / Nmue_SR_B)) ; 
// // // // //  e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B / Nemu_SR_B * Nmue_SR_B)) ; 
// // // // //  errN_mumu_DYDD_SR_B = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4) ; 
// // // // //  std::cout << " N (DY DD B) mumu     = " << N_mumu_DYDD_SR_B << " +/- " << errN_mumu_DYDD_SR_B << std::endl; 
// // // // //  std::cout << " Ree    = " << (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))      << std::endl;
// // // // //  std::cout << " Rmumu  = " << (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))  << std::endl; 
// // // // //  
// // // // //  std::cout << " ****************************** " << std::endl;
 std::cout << std::endl;
 
 
 
//  std::cout << " **************************************************** " << std::endl;
//  std::cout << " **************************************************** " << std::endl;
//  std::cout << " ********* Scale Factor DATA/MC ********************* " << std::endl;
 
//  if (Nee_SR_A_DYee != 0 && Nmumu_SR_A_DYmumu != 0) {
//   std::cout << std::endl;
//   std::cout << " >>> MC <<< " << std::endl;
//   std::cout << " Nall  DATA / MC     = " << (Nmumu_Result + Nee_Result) / (Nmumu_SR_A_DYmumu + Nee_SR_A_DYee) << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_SR_A_DYmumu + Nee_SR_A_DYee) << " = " << (Nmumu_Result + Nee_Result)     << " / " << (Nmumu_SR_A_DYmumu + Nee_SR_A_DYee)      << std::endl;
//   std::cout << " ee    DATA / MC     = " << (               Nee_Result) / (                    Nee_SR_A_DYee) << " +/- " << sqrt(                                errNee_Result*errNee_Result) / (                    Nee_SR_A_DYee) << " = " << (               Nee_Result)     << " / " << (                    Nee_SR_A_DYee)      << std::endl;
//   std::cout << " Nmumu DATA / MC     = " << (Nmumu_Result             ) / (Nmumu_SR_A_DYmumu                ) << " +/- " << sqrt(errNmumu_Result*errNmumu_Result                            ) / (Nmumu_SR_A_DYmumu                ) << " = " << (Nmumu_Result             )     << " / " << (Nmumu_SR_A_DYmumu                )      << std::endl;
//  }
//  std::cout << std::endl;
//  std::cout << std::endl;
 
 
 
 
 ///---- variation of R between SR and CR ----
 
 double P4_ee;
 double P4_mumu;
 
 P1_ee = (Nee_SR_B - 0.5 * kB_em * (Nemu_SR_B + Nmue_SR_B)) ;
 P2_ee = (Nee_SR_A - 0.5 * kA_em * (Nemu_SR_A + Nmue_SR_A)) ;
 P3_ee = (Nee_CR_B - 0.5 * kB_em * (Nemu_CR_B + Nmue_CR_B)) ;
 P4_ee = (Nee_CR_A - 0.5 * kA_em * (Nemu_CR_A + Nmue_CR_A)) ;
 
 double ee_R_variation = (P1_ee!=0 && P2_ee!=0 && P3_ee!=0 && P4_ee!=0) ? ( P2_ee / P1_ee - P4_ee / P3_ee )  /  (P2_ee / P1_ee + P4_ee / P3_ee) * 2 : 0;
//  double ee_R_variation = (P1_ee!=0 && P2_ee!=0 && P3_ee!=0) ? ( P2_ee / P1_ee - P4_ee / P3_ee )  /  (P2_ee / P1_ee + P4_ee / P3_ee) * 2 : 0;
 //  double ee_R_variation = (P1_ee!=0 && P2_ee!=0 && P3_ee!=0) ? ( P2_ee / P1_ee - P4_ee / P3_ee )  /  (P2_ee / P1_ee) : 0;
//  double ee_R_variation = (P1_ee!=0 && P2_ee!=0 && P3_ee!=0 && P4_ee!=0) ? ( P2_ee / P1_ee - P4_ee / P3_ee )  /  (P4_ee / P3_ee) : 0;
 
 P1_mumu = (Nmumu_SR_B - 0.5 * kB_me * (Nemu_SR_B + Nmue_SR_B)) ;
 P2_mumu = (Nmumu_SR_A - 0.5 * kA_me * (Nemu_SR_A + Nmue_SR_A)) ;
 P3_mumu = (Nmumu_CR_B - 0.5 * kB_me * (Nemu_CR_B + Nmue_CR_B)) ;
 P4_mumu = (Nmumu_CR_A - 0.5 * kA_me * (Nemu_CR_A + Nmue_CR_A)) ;
 
 double mumu_R_variation = (P1_mumu!=0 && P2_mumu!=0 && P3_mumu!=0 && P4_mumu!=0) ? ( P2_mumu / P1_mumu - P4_mumu / P3_mumu )  /  ( P2_mumu / P1_mumu + P4_mumu / P3_mumu) * 2 : 0;
//  double mumu_R_variation = (P1_mumu!=0 && P2_mumu!=0 && P3_mumu!=0) ? ( P2_mumu / P1_mumu - P4_mumu / P3_mumu )  /  ( P2_mumu / P1_mumu + P4_mumu / P3_mumu) * 2 : 0;
//  double mumu_R_variation = (P1_mumu!=0 && P2_mumu!=0 && P3_mumu!=0) ? ( P2_mumu / P1_mumu - P4_mumu / P3_mumu )  /  (P2_mumu / P1_mumu) : 0;
//  double mumu_R_variation = (P1_mumu!=0 && P2_mumu!=0 && P3_mumu!=0 && P4_mumu!=0) ? ( P2_mumu / P1_mumu - P4_mumu / P3_mumu )  /  (P4_mumu / P3_mumu) : 0;
 
 
 ///---- half the error! ----
 ee_R_variation   /= 2.;
 mumu_R_variation /= 2.;
 
 
 std::cout << " **************************************************** " << std::endl;
 std::cout << " ee_R_variation   = " << ee_R_variation*100   << " % " << std::endl;
 std::cout << " mumu_R_variation = " << mumu_R_variation*100 << " % " << std::endl;
 std::cout << " **************************************************** " << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 
 
 
 
 
 std::ofstream myfileValue; 
 myfileValue.open ("test/Latinos/DYRinout/result-value.txt",std::fstream::app);
 myfileValue << (Nmumu_Result + Nee_Result) << std::endl;
 myfileValue.close();
 
 std::ofstream myfileSyst; 
 myfileSyst.open ("test/Latinos/DYRinout/result-syst.txt",std::fstream::app);
//  myfileSyst << (1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) )) << std::endl;
 double meanRsyst = 0;
 if (ee_R_variation != 0 && mumu_R_variation != 0) meanRsyst = (ee_R_variation+mumu_R_variation)/2.;
 else if (ee_R_variation != 0)   meanRsyst = ee_R_variation;
 else if (mumu_R_variation != 0) meanRsyst = mumu_R_variation;

 double statErr = 0;
 if ((Nmumu_Result + Nee_Result) != 0) statErr = sqrt(errNmumu_Result*errNmumu_Result  +  errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result);
 
//  myfileSyst << (1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result  +  errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result)        +     (ee_R_variation+mumu_R_variation)/2.*(ee_R_variation+mumu_R_variation)/2.   )) << std::endl;
//  myfileSyst << (1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(   statErr*statErr + meanRsyst*meanRsyst   ))) << std::endl;
 myfileSyst << (1 + sqrt(   statErr*statErr + meanRsyst*meanRsyst   )) << std::endl;
 
 myfileSyst.close();
 
 
 
 std::cout << " meanRsyst = " << meanRsyst << std::endl;
 std::cout << " statErr   = " << statErr   << " = " << errNmumu_Result << " (+) " << errNee_Result << " / ( " << Nmumu_Result << " + " << Nee_Result << " )" << std::endl;
 
 std::cout << " Global (for DC) = " <<  sqrt( statErr*statErr + meanRsyst*meanRsyst ) << " = " << statErr << " (+) " << meanRsyst << std::endl;
 

 
 
 std::ofstream myfileValueMuMuForDYtautau; 
 myfileValue.open ("test/Latinos/DYtautau/numDataDYmumu-2jet.txt",std::fstream::app);
 myfileValue << NmumuUnderPeak << "     " << errNmumuUnderPeak << std::endl;
 myfileValue.close();
 
 
 
 
 gApplication->Terminate(0);
 
}






