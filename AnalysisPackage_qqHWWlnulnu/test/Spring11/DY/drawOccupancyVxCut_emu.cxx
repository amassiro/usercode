{
 
 ///=========================================================
 ///==== preselections - powherg & madgraph -eumu @reco ==== 
 ///=========================================================
 
 double X[100] =    {0, 1, 5, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 45 };
 double errX[100] = {0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 };
 
 
//  double Ypow_A[100] =    { 69.01 ,    68.65 ,    66.75 ,    59.95 ,    57.32 ,    53.96 ,    50.25 ,    46.82 ,    43.17 ,    39.76 ,    37.69 ,    34.26 ,    31.36 ,    28.36 ,       26 ,    24.93 ,    22.68 ,    20.33 ,    18.59};
//  double errYpow_A[100] = {  3.977 ,     3.96 ,    3.912 ,    3.689 ,     3.59 ,    3.455 ,    3.339 ,    3.227 ,    3.081 ,    2.948 ,    2.864 ,    2.733 ,    2.599 ,    2.472 ,    2.368 ,    2.319 ,    2.215 ,    2.098 ,    2.008}; 
//  
//  double Ymad_A[100] =    {73.54 ,    73.54 ,    69.67 ,     57.4 ,    53.75 ,    47.92 ,    42.53 ,    38.07 ,    34.38 ,    31.44 ,    28.81 ,    27.19 ,    25.06 ,    22.84 ,    21.76 ,    19.25 ,    17.31 ,    15.94 ,     13.3};
//  double errYmad_A[100] = {4.904 ,    4.904 ,    4.763 ,    4.307 ,    4.158 ,    3.925 ,    3.686 ,    3.449 ,    3.289 ,    3.158 ,    3.034 ,    2.949 ,    2.849 ,    2.723 ,     2.66 ,    2.497 ,    2.369 ,    2.269 ,    2.034}; 
//  
//  double Ypowmumu_A[100] =    { 9.901 ,     9.54 ,    8.921 ,    6.624 ,    5.701 ,    4.484 ,    4.416 ,    4.416 ,    3.551 ,    2.495 ,    1.918 ,    1.918 ,    1.159 ,    1.159 ,    1.159 ,    1.159 ,    1.051 ,    1.051 ,    1.024};
//  double errYpowmumu_A[100] = {   1.776 ,    1.738 ,    1.707 ,    1.478 ,    1.354 ,    1.157 ,    1.155 ,    1.155 ,    1.003 ,   0.8425 ,   0.7375 ,   0.7375 ,   0.5335 ,   0.5335 ,   0.5335 ,   0.5335 ,   0.5225 ,   0.5225 ,   0.5218}; 
//  
//  double Ypowtautau_A[100] =    { 60.01 ,    60.01 ,    58.85 ,    53.77 ,       52 ,    49.73 ,    46.48 ,    43.47 ,    40.19 ,     38.3 ,    36.13 ,    32.24 ,    30.61 ,    27.39 ,    26.24 ,    25.23 ,    22.78 ,    20.88 ,    19.13};
//  double errYpowtautau_A[100] = {  4.381 ,    4.381 ,    4.346 ,    4.146 ,    4.076 ,    3.986 ,    3.855 ,    3.729 ,    3.575 ,     3.49 ,    3.375 ,    3.173 ,    3.108 ,    2.948 ,    2.905 ,     2.86 ,    2.718 ,    2.615 ,    2.521}; 
//  
//  
//  
//  double Ypow_B[100] =    {  17.34 ,    17.34 ,    15.66 ,    12.02 ,    9.925 ,    8.065 ,    6.282 ,     4.89 ,    4.458 ,    4.208 ,    3.678 ,    3.159 ,    2.442 ,    2.013 ,    1.799 ,    1.799 ,    1.585 ,    1.305 ,    1.305};
//  double errYpow_B[100] = { 2.075 ,    2.075 ,     1.98 ,    1.719 ,    1.586 ,    1.437 ,    1.235 ,    1.126 ,    1.102 ,     1.08 ,   0.9761 ,   0.9333 ,   0.7844 ,   0.7236 ,   0.6912 ,   0.6912 ,   0.6572 ,   0.6134 ,   0.6134}; 
//  
//  double Ymad_B[100] =    { 19.88 ,    19.88 ,    17.22 ,    13.97 ,    11.46 ,    10.03 ,    8.298 ,    7.104 ,      6.2 ,    4.716 ,    3.567 ,    3.459 ,    3.385 ,    2.428 ,    1.987 ,    1.539 ,    1.539 ,    1.539 ,     1.47};
//  double errYmad_B[100] = {  2.552 ,    2.552 ,    2.343 ,    2.101 ,    1.926 ,    1.803 ,    1.624 ,    1.522 ,    1.406 ,    1.203 ,    1.042 ,    1.036 ,    1.033 ,   0.9006 ,    0.847 ,    0.719 ,    0.719 ,    0.719 ,   0.7157}; 
//  
//  double Ypowmumu_B[100] =    {  10.7 ,     10.7 ,    9.452 ,     6.88 ,    5.428 ,    5.067 ,    3.712 ,    2.963 ,     2.53 ,    2.494 ,    1.965 ,    1.446 ,   0.9424 ,   0.9424 ,   0.9424 ,   0.9424 ,   0.9424 ,   0.6621 ,   0.6621};
//  double errYpowmumu_B[100] = {   1.698 ,    1.698 ,    1.609 ,    1.361 ,    1.246 ,    1.193 ,   0.9873 ,   0.9247 ,    0.895 ,   0.8943 ,   0.7654 ,     0.71 ,   0.5425 ,   0.5425 ,   0.5425 ,   0.5425 ,   0.5425 ,   0.4886 ,   0.4886}; 
//  
//  double Ypowtautau_B[100] =    {  5.499 ,    5.499 ,    5.429 ,    4.173 ,    3.521 ,    2.563 ,    2.359 ,    1.525 ,    1.525 ,    1.453 ,    1.453 ,    1.453 ,    1.381 ,    0.996 ,   0.7668 ,   0.7668 ,   0.6948 ,   0.6948 ,   0.6948};
//  double errYpowtautau_B[100] = { 1.266 ,    1.266 ,    1.265 ,    1.098 ,    1.014 ,   0.8962 ,   0.8795 ,   0.6616 ,   0.6616 ,   0.6577 ,   0.6577 ,   0.6577 ,   0.6537 ,   0.5457 ,   0.4952 ,   0.4952 ,     0.49 ,     0.49 ,     0.49}; 
//  
 
 
 
 
 ///=== require Nlepton_10 == 0
 
 double Ypow_A[100] =    { 69.01 ,    68.65 ,    66.75 ,    59.95 ,    57.32 ,    53.96 ,    50.25 ,    46.82 ,    43.17 ,    39.76 ,    37.69 ,    34.26 ,    31.36 ,    28.36 ,       26 ,    24.93 ,    22.68 ,    20.33 ,    18.59};
 double errYpow_A[100] = {  3.977 ,     3.96 ,    3.912 ,    3.689 ,     3.59 ,    3.455 ,    3.339 ,    3.227 ,    3.081 ,    2.948 ,    2.864 ,    2.733 ,    2.599 ,    2.472 ,    2.368 ,    2.319 ,    2.215 ,    2.098 ,    2.008}; 
 
 double Ymad_A[100] =    {73.54 ,    73.54 ,    69.67 ,     57.4 ,    53.75 ,    47.92 ,    42.53 ,    38.07 ,    34.38 ,    31.44 ,    28.81 ,    27.19 ,    25.06 ,    22.84 ,    21.76 ,    19.25 ,    17.31 ,    15.94 ,     13.3};
 double errYmad_A[100] = {4.904 ,    4.904 ,    4.763 ,    4.307 ,    4.158 ,    3.925 ,    3.686 ,    3.449 ,    3.289 ,    3.158 ,    3.034 ,    2.949 ,    2.849 ,    2.723 ,     2.66 ,    2.497 ,    2.369 ,    2.269 ,    2.034}; 
 
 double Ypowmumu_A[100] =    { 9.901 ,     9.54 ,    8.921 ,    6.624 ,    5.701 ,    4.484 ,    4.416 ,    4.416 ,    3.551 ,    2.495 ,    1.918 ,    1.918 ,    1.159 ,    1.159 ,    1.159 ,    1.159 ,    1.051 ,    1.051 ,    1.024};
 double errYpowmumu_A[100] = {   1.776 ,    1.738 ,    1.707 ,    1.478 ,    1.354 ,    1.157 ,    1.155 ,    1.155 ,    1.003 ,   0.8425 ,   0.7375 ,   0.7375 ,   0.5335 ,   0.5335 ,   0.5335 ,   0.5335 ,   0.5225 ,   0.5225 ,   0.5218}; 
 
 double Ypowtautau_A[100] =    { 60.01 ,    60.01 ,    58.85 ,    53.77 ,       52 ,    49.73 ,    46.48 ,    43.47 ,    40.19 ,     38.3 ,    36.13 ,    32.24 ,    30.61 ,    27.39 ,    26.24 ,    25.23 ,    22.78 ,    20.88 ,    19.13};
 double errYpowtautau_A[100] = {  4.381 ,    4.381 ,    4.346 ,    4.146 ,    4.076 ,    3.986 ,    3.855 ,    3.729 ,    3.575 ,     3.49 ,    3.375 ,    3.173 ,    3.108 ,    2.948 ,    2.905 ,     2.86 ,    2.718 ,    2.615 ,    2.521}; 
 
 
 
 double Ypow_B[100] =    {  17.34 ,    17.34 ,    15.66 ,    12.02 ,    9.925 ,    8.065 ,    6.282 ,     4.89 ,    4.458 ,    4.208 ,    3.678 ,    3.159 ,    2.442 ,    2.013 ,    1.799 ,    1.799 ,    1.585 ,    1.305 ,    1.305};
 double errYpow_B[100] = { 2.075 ,    2.075 ,     1.98 ,    1.719 ,    1.586 ,    1.437 ,    1.235 ,    1.126 ,    1.102 ,     1.08 ,   0.9761 ,   0.9333 ,   0.7844 ,   0.7236 ,   0.6912 ,   0.6912 ,   0.6572 ,   0.6134 ,   0.6134}; 
 
 double Ymad_B[100] =    { 19.88 ,    19.88 ,    17.22 ,    13.97 ,    11.46 ,    10.03 ,    8.298 ,    7.104 ,      6.2 ,    4.716 ,    3.567 ,    3.459 ,    3.385 ,    2.428 ,    1.987 ,    1.539 ,    1.539 ,    1.539 ,     1.47};
 double errYmad_B[100] = {  2.552 ,    2.552 ,    2.343 ,    2.101 ,    1.926 ,    1.803 ,    1.624 ,    1.522 ,    1.406 ,    1.203 ,    1.042 ,    1.036 ,    1.033 ,   0.9006 ,    0.847 ,    0.719 ,    0.719 ,    0.719 ,   0.7157}; 
 
 double Ypowmumu_B[100] =    {  10.7 ,     10.7 ,    9.452 ,     6.88 ,    5.428 ,    5.067 ,    3.712 ,    2.963 ,     2.53 ,    2.494 ,    1.965 ,    1.446 ,   0.9424 ,   0.9424 ,   0.9424 ,   0.9424 ,   0.9424 ,   0.6621 ,   0.6621};
 double errYpowmumu_B[100] = {   1.698 ,    1.698 ,    1.609 ,    1.361 ,    1.246 ,    1.193 ,   0.9873 ,   0.9247 ,    0.895 ,   0.8943 ,   0.7654 ,     0.71 ,   0.5425 ,   0.5425 ,   0.5425 ,   0.5425 ,   0.5425 ,   0.4886 ,   0.4886}; 
 
 double Ypowtautau_B[100] =    {  5.499 ,    5.499 ,    5.429 ,    4.173 ,    3.521 ,    2.563 ,    2.359 ,    1.525 ,    1.525 ,    1.453 ,    1.453 ,    1.453 ,    1.381 ,    0.996 ,   0.7668 ,   0.7668 ,   0.6948 ,   0.6948 ,   0.6948};
 double errYpowtautau_B[100] = { 1.266 ,    1.266 ,    1.265 ,    1.098 ,    1.014 ,   0.8962 ,   0.8795 ,   0.6616 ,   0.6616 ,   0.6577 ,   0.6577 ,   0.6577 ,   0.6537 ,   0.5457 ,   0.4952 ,   0.4952 ,     0.49 ,     0.49 ,     0.49}; 
 
 
 
 
 int num = 19; // 16
 
 TGraphErrors* grpow_A = new TGraphErrors(num,X,Ypow_A,errX,errYpow_A);
 grpow_A->SetTitle("DY powheg A");
 grpow_A->GetXaxis()->SetTitle("met threshold (GeV)");
 grpow_A->GetYaxis()->SetTitle("occupancy");
 grpow_A->SetMarkerColor(kRed);
 grpow_A->SetFillColor(kRed);
 grpow_A->SetLineColor(kRed);
 grpow_A->SetMarkerStyle(20);
 grpow_A->SetMarkerSize(1);
 grpow_A->SetLineWidth(1);
 
 TGraphErrors* grpow_B = new TGraphErrors(num,X,Ypow_B,errX,errYpow_B);
 grpow_B->SetTitle("DY powheg B");
 grpow_B->GetXaxis()->SetTitle("met threshold (GeV)");
 grpow_B->GetYaxis()->SetTitle("occupancy");
 grpow_B->SetMarkerColor(kRed+2);
 grpow_B->SetFillColor(kRed+2);
 grpow_B->SetLineColor(kRed+2);
 grpow_B->SetMarkerStyle(20);
 grpow_B->SetMarkerSize(1);
 grpow_B->SetLineWidth(1);
 
 TGraphErrors* grmad_A = new TGraphErrors(num,X,Ymad_A,errX,errYmad_A);
 grmad_A->SetTitle("DY madgraph A");
 grmad_A->GetXaxis()->SetTitle("met threshold (GeV)");
 grmad_A->GetYaxis()->SetTitle("occupancy");
 grmad_A->SetMarkerColor(kBlue);
 grmad_A->SetFillColor(kBlue);
 grmad_A->SetLineColor(kBlue);
 grmad_A->SetMarkerStyle(21);
 grmad_A->SetMarkerSize(1);
 grmad_A->SetLineWidth(1);
 
 TGraphErrors* grmad_B = new TGraphErrors(num,X,Ymad_B,errX,errYmad_B);
 grmad_B->SetTitle("DY madgraph B");
 grmad_B->GetXaxis()->SetTitle("met threshold (GeV)");
 grmad_B->GetYaxis()->SetTitle("occupancy");
 grmad_B->SetMarkerColor(kBlue+2);
 grmad_B->SetFillColor(kBlue+2);
 grmad_B->SetLineColor(kBlue+2);
 grmad_B->SetMarkerStyle(21);
 grmad_B->SetMarkerSize(1);
 grmad_B->SetLineWidth(1);
 
 
 TGraphErrors* grpowmumu_A = new TGraphErrors(num,X,Ypowmumu_A,errX,errYpowmumu_A);
 grpowmumu_A->SetTitle("DY powheg #mu#mu A");
 grpowmumu_A->GetXaxis()->SetTitle("met threshold (GeV)");
 grpowmumu_A->GetYaxis()->SetTitle("occupancy");
 grpowmumu_A->SetMarkerColor(kGreen);
 grpowmumu_A->SetFillColor(kGreen);
 grpowmumu_A->SetLineColor(kGreen);
 grpowmumu_A->SetMarkerStyle(22);
 grpowmumu_A->SetMarkerSize(1);
 grpowmumu_A->SetLineWidth(1);
 
 TGraphErrors* grpowmumu_B = new TGraphErrors(num,X,Ypowmumu_B,errX,errYpowmumu_B);
 grpowmumu_B->SetTitle("DY powheg #mu#mu B");
 grpowmumu_B->GetXaxis()->SetTitle("met threshold (GeV)");
 grpowmumu_B->GetYaxis()->SetTitle("occupancy");
 grpowmumu_B->SetMarkerColor(kGreen+2);
 grpowmumu_B->SetFillColor(kGreen+2);
 grpowmumu_B->SetLineColor(kGreen+2);
 grpowmumu_B->SetMarkerStyle(22);
 grpowmumu_B->SetMarkerSize(1);
 grpowmumu_B->SetLineWidth(1); 
 
 
 TGraphErrors* grpowtautau_A = new TGraphErrors(num,X,Ypowtautau_A,errX,errYpowtautau_A);
 grpowtautau_A->SetTitle("DY powheg #tau#tau A");
 grpowtautau_A->GetXaxis()->SetTitle("met threshold (GeV)");
 grpowtautau_A->GetYaxis()->SetTitle("occupancy");
 grpowtautau_A->SetMarkerColor(kYellow);
 grpowtautau_A->SetFillColor(kYellow);
 grpowtautau_A->SetLineColor(kYellow);
 grpowtautau_A->SetMarkerStyle(23);
 grpowtautau_A->SetMarkerSize(1);
 grpowtautau_A->SetLineWidth(1);

 TGraphErrors* grpowtautau_B = new TGraphErrors(num,X,Ypowtautau_B,errX,errYpowtautau_B);
 grpowtautau_B->SetTitle("DY powheg #tau#tau B");
 grpowtautau_B->GetXaxis()->SetTitle("met threshold (GeV)");
 grpowtautau_B->GetYaxis()->SetTitle("occupancy");
 grpowtautau_B->SetMarkerColor(kYellow);
 grpowtautau_B->SetFillColor(kYellow);
 grpowtautau_B->SetLineColor(kYellow);
 grpowtautau_B->SetMarkerStyle(23);
 grpowtautau_B->SetMarkerSize(1);
 grpowtautau_B->SetLineWidth(1);
 
 
 TCanvas cc;
 TMultiGraph* mgr = new TMultiGraph();
 
 mgr->Add(grpowmumu_A);
 mgr->Add(grpowmumu_B);
 mgr->Add(grpowtautau_A);
 mgr->Add(grpowtautau_B);
 mgr->Add(grpow_A);
 mgr->Add(grpow_B);
//  mgr->Add(grmad_A);
//  mgr->Add(grmad_B);
 mgr->Draw("AP");
 
 gPad->BuildLegend();
 gPad->SetGrid();
 
 
 
 TCanvas cc_A;
 TMultiGraph* mgr_A = new TMultiGraph();
 
 mgr_A->Add(grpowmumu_A);
 mgr_A->Add(grpowtautau_A);
 mgr_A->Add(grpow_A);
//  mgr_A->Add(grmad_A);
 mgr_A->Draw("AP");
 
 gPad->BuildLegend();
 gPad->SetGrid();
 
 
 TCanvas cc_B;
 TMultiGraph* mgr_B = new TMultiGraph();
 
 mgr_B->Add(grpowmumu_B);
 mgr_B->Add(grpowtautau_B);
 mgr_B->Add(grpow_B);
//  mgr_B->Add(grmad_B);
 mgr_B->Draw("AP");
 
 gPad->BuildLegend();
 gPad->SetGrid();
 
 
}