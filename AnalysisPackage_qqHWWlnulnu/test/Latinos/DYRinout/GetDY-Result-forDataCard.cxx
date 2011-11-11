void GetDY_Result_forDataCard(TString nameInFileRoot, int WorkingPoint = 1){
 
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
 
 
 ///=====================
 
 TString nameHistoInRootFile;
 TH1F* h; 
 
 ///==== MC ==== 
 
//  nameHistoInRootFile = Form("Data/DYee_%d_0_Tot_temp",2+(WorkingPoint-1)*4);
//  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
//  Nee_SR_A_DYee    = h->GetBinContent(2);
//  errNee_SR_A_DYee = h->GetBinError(2);
//  
//  nameHistoInRootFile = Form("Data/DYmumu_%d_1_Tot_temp",2+(WorkingPoint-1)*4);
//  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
//  Nmumu_SR_A_DYmumu     = h->GetBinContent(2);
//  errNmumu_SR_A_DYmumu  = h->GetBinError(2);
//  
//  nameHistoInRootFile = Form("Data/DYtautau_%d_0_Tot_temp",2+(WorkingPoint-1)*4);
//  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
//  Nee_SR_A_DYtautau    = h->GetBinContent(2);
//  errNee_SR_A_DYtautau = h->GetBinError(2);
//  
//  nameHistoInRootFile = Form("Data/DYtautau_%d_1_Tot_temp",2+(WorkingPoint-1)*4);
//  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
//  Nmumu_SR_A_DYtautau     = h->GetBinContent(2);
//  errNmumu_SR_A_DYtautau  = h->GetBinError(2);
//  
//  nameHistoInRootFile = Form("Data/DYtautau_%d_2_Tot_temp",2+(WorkingPoint-1)*4);
//  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
//  Nemu_SR_A_DYtautau      = h->GetBinContent(2);
//  errNemu_SR_A_DYtautau   = h->GetBinError(2);
//  
//  nameHistoInRootFile = Form("Data/DYtautau_%d_3_Tot_temp",2+(WorkingPoint-1)*4);
//  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
//  Nemu_SR_A_DYtautau      += h->GetBinContent(2);
//  errNemu_SR_A_DYtautau   = sqrt (errNemu_SR_A_DYtautau*errNemu_SR_A_DYtautau + h->GetBinError(2) * h->GetBinError(2)); 
 
 
 
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
 std::cout << " >>> input <<< " << std::endl;
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
 
 std::cout << " >>> R <<< " << std::endl;
 std::cout << " Ree    = " << (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))      << std::endl;
 std::cout << " Rmumu  = " << (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))  << std::endl; 
 std::cout << " >>> DY B CR <<< " << std::endl;
 std::cout << " ee   = " << (Nee_SR_B - sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))   << std::endl;
 std::cout << " mumu = " << (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) << std::endl; 
 
 std::cout << " >>> result <<< " << std::endl;
 std::cout << " Nee   = " << Nee_Result   << " +/- " << errNee_Result   << " ==> " << (!Nee_Result ? 0 : errNee_Result   / Nee_Result) << " == datacard ==> " << 1 + (!Nee_Result ? 0 : errNee_Result   / Nee_Result)   << std::endl;
 std::cout << " Nmumu = " << Nmumu_Result << " +/- " << errNmumu_Result << " ==> " << (!Nmumu_Result ? 0 : errNmumu_Result / Nmumu_Result ) << " == datacard ==> " << 1 + (!Nmumu_Result ? 0 : errNmumu_Result / Nmumu_Result ) << std::endl;
 std::cout << " >>> total <<< " << std::endl;
 std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) << " ==> " << (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
 std::cout << std::endl;
 std::cout << " WorkingPoint = " << WorkingPoint << std::endl;

 std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) << " ==> " << (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
//  std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) << " ==> " << (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
 
 std::cout << " ****************************** " << std::endl;
 
 double N_ee_DYDD_SR_B   = (Nee_SR_B   - sqrt(Nee_SR_B   / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B));
 e1 = errNee_SR_B *   (1. - 0.5 * sqrt(1. / Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))    ; 
 e2 = errNmumu_SR_B * (0.5 / Nmumu_SR_B * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B)) ; 
 e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B / Nmue_SR_B)) ; 
 e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B / Nemu_SR_B * Nmue_SR_B)) ; 
 double errN_ee_DYDD_SR_B = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4) ; 
 std::cout << " N (DY DD B) ee     = " << N_ee_DYDD_SR_B << " +/- " << errN_ee_DYDD_SR_B << std::endl; 
 
 double N_mumu_DYDD_SR_B = (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B));
 e1 = errNmumu_SR_B *   (1. - 0.5 * sqrt(1. / Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B))    ; 
 e2 = errNee_SR_B * (0.5 / Nee_SR_B * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) ; 
 e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B / Nmue_SR_B)) ; 
 e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B / Nemu_SR_B * Nmue_SR_B)) ; 
 double errN_mumu_DYDD_SR_B = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4) ; 
 std::cout << " N (DY DD B) mumu     = " << N_mumu_DYDD_SR_B << " +/- " << errN_mumu_DYDD_SR_B << std::endl; 
 std::cout << " Ree    = " << (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))      << std::endl;
 std::cout << " Rmumu  = " << (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))  << std::endl; 
 
 
 
 
 
 std::cout << std::endl;
 std::cout << " >>> MC <<< " << std::endl;
 std::cout << " Nee_SR_A_DYee       = " << Nee_SR_A_DYee     << " +/- " << errNee_SR_A_DYee      << std::endl;
 std::cout << " Nmumu_SR_A_DYmumu   = " << Nmumu_SR_A_DYmumu << " +/- " << errNmumu_SR_A_DYmumu  << std::endl;
 std::cout << std::endl;
 std::cout << " Nee_SR_A_DYtautau   = " << Nee_SR_A_DYtautau     << " +/- " << errNee_SR_A_DYtautau     << std::endl;
 std::cout << " Nmumu_SR_A_DYtautau = " << Nmumu_SR_A_DYtautau   << " +/- " << errNmumu_SR_A_DYtautau   << std::endl;
 std::cout << " Nemu_SR_A_DYtautau  = " << Nemu_SR_A_DYtautau    << " +/- " << errNemu_SR_A_DYtautau    << std::endl;
 
 
 
 
 
 
 
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
 
 std::cout << " >>> R <<< " << std::endl;
 std::cout << " Ree    = " << (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))      << std::endl;
 std::cout << " Rmumu  = " << (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))  << std::endl; 
 std::cout << " >>> DY B CR <<< " << std::endl;
 std::cout << " ee   = " << (Nee_SR_B - sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))   << std::endl;
 std::cout << " mumu = " << (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) << std::endl; 
 
 std::cout << " >>> result <<< " << std::endl;
 std::cout << " Nee   = " << Nee_Result   << " +/- " << errNee_Result   << " ==> " << (!Nee_Result ? 0 : errNee_Result   / Nee_Result) << " == datacard ==> " << 1 + (!Nee_Result ? 0 : errNee_Result   / Nee_Result)   << std::endl;
 std::cout << " Nmumu = " << Nmumu_Result << " +/- " << errNmumu_Result << " ==> " << (!Nmumu_Result ? 0 : errNmumu_Result / Nmumu_Result ) << " == datacard ==> " << 1 + (!Nmumu_Result ? 0 : errNmumu_Result / Nmumu_Result ) << std::endl;
 std::cout << " >>> total <<< " << std::endl;
 std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) << " ==> " << (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
//  std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) << " ==> " << (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result - Nmumu_Result - Nee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
 std::cout << std::endl;
 std::cout << " WorkingPoint = " << WorkingPoint << std::endl;
 
 std::cout << " ****************************** " << std::endl;
 
 N_ee_DYDD_SR_B   = (Nee_SR_B   - sqrt(Nee_SR_B   / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B));
 e1 = errNee_SR_B *   (1. - 0.5 * sqrt(1. / Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B))    ; 
 e2 = errNmumu_SR_B * (0.5 / Nmumu_SR_B * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B * Nmue_SR_B)) ; 
 e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B * Nemu_SR_B / Nmue_SR_B)) ; 
 e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nee_SR_B / Nmumu_SR_B / Nemu_SR_B * Nmue_SR_B)) ; 
 errN_ee_DYDD_SR_B = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4) ; 
 std::cout << " N (DY DD B) ee     = " << N_ee_DYDD_SR_B << " +/- " << errN_ee_DYDD_SR_B << std::endl; 
 
 N_mumu_DYDD_SR_B = (Nmumu_SR_B - sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B));
 e1 = errNmumu_SR_B *   (1. - 0.5 * sqrt(1. / Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B))    ; 
 e2 = errNee_SR_B * (0.5 / Nee_SR_B * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B * Nmue_SR_B)) ; 
 e3 = !Nmue_SR_B ? 0 : errNemu_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B * Nemu_SR_B / Nmue_SR_B)) ; 
 e4 = !Nemu_SR_B ? 0 : errNmue_SR_B *  (0.5 * sqrt(Nmumu_SR_B / Nee_SR_B / Nemu_SR_B * Nmue_SR_B)) ; 
 errN_mumu_DYDD_SR_B = sqrt(e1*e1 + e2*e2 + e3*e3 + e4*e4) ; 
 std::cout << " N (DY DD B) mumu     = " << N_mumu_DYDD_SR_B << " +/- " << errN_mumu_DYDD_SR_B << std::endl; 
 std::cout << " Ree    = " << (Nee_CR_A - sqrt(Nee_CR_A / Nmumu_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nee_CR_B - sqrt(Nee_CR_B / Nmumu_CR_B * Nemu_CR_B * Nmue_CR_B))      << std::endl;
 std::cout << " Rmumu  = " << (Nmumu_CR_A - sqrt(Nmumu_CR_A / Nee_CR_A * Nemu_CR_A * Nmue_CR_A)) / (Nmumu_CR_B - sqrt(Nmumu_CR_B / Nee_CR_B * Nemu_CR_B * Nmue_CR_B))  << std::endl; 
 
 std::cout << " ****************************** " << std::endl;
 std::cout << std::endl;
 
 
 std::ofstream myfileValue; 
 myfileValue.open ("test/Latinos/DYRinout/result-value.txt",std::fstream::app);
 myfileValue << (Nmumu_Result + Nee_Result) << std::endl;
 myfileValue.close();
 
 std::ofstream myfileSyst; 
 myfileSyst.open ("test/Latinos/DYRinout/result-syst.txt",std::fstream::app);
 myfileSyst << (1 + (!(Nmumu_Result + Nee_Result) ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) )) << std::endl;
 myfileSyst.close();
 
 gApplication->Terminate(0);
 
}






