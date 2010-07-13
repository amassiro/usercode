{
 #include "Utilities.h"
 
 ///==== multi-program macro ====
 
 int NBINPLOT = 200;
 
 int numEvents[100] = {20,30,40,50,60,70,80,90,100,110,120,130,140,150,200,250,500,750,1000,1500,2000,3000,10000};
 int NUM = 19;
  for (int i=0; i<NUM; i++){
    std::cout << "====================================================" << std::endl;
    std::cout << "===================== " << i << " : " << NUM << " =====================" << std::endl;
    std::cout << "====================================================" << std::endl;
    TString CommandToExec = Form("./bin/EnScale_MC.exe %d 200",numEvents[i]);
    std::cout << " CommandToExec = " << CommandToExec.Data() << std::endl;
    gSystem->Exec(CommandToExec);  
   }
  
  double DIVISION = 4.;
  
  TH2F* resultTH2F_LL = new TH2F("resultTH2F_LL","resultTH2F_LL",(numEvents[NUM]+5)/DIVISION,0,numEvents[NUM]+5,NBINPLOT,-0.3,0.3);
  TH2F* resultTH2F_Chi2 = new TH2F("resultTH2F_Chi2","resultTH2F_Chi2",(numEvents[NUM]+5)/DIVISION,0,numEvents[NUM]+5,NBINPLOT,-0.3,0.3);
  TH2F* resultTH2F_NewChi2 = new TH2F("resultTH2F_NewChi2","resultTH2F_NewChi2",(numEvents[NUM]+5)/DIVISION,0,numEvents[NUM]+5,NBINPLOT,-0.3,0.3);
  
  TFile* fileInMC[100];
  
  TH1F* AlphaLL[NUM];
  TH1F* AlphaChi2[NUM];
  TH1F* AlphaNewChi2[NUM];

  double AlphaMeanLL_Minus[NUM];
  double AlphaMeanChi2_Minus[NUM];
  double AlphaMeanNewChi2_Minus[NUM];
  double AlphaMeanLL_Plus[NUM];
  double AlphaMeanChi2_Plus[NUM];
  double AlphaMeanNewChi2_Plus[NUM];
  
  double AlphaMeanLL[NUM];
  double AlphaMeanChi2[NUM];
  double AlphaMeanNewChi2[NUM];
  double numEventsD[NUM];
  double numEventsDL[NUM];
  double numEventsDH[NUM];
  
  TCanvas *cResult = new TCanvas("cResult","cResult",10,10,800,800);
  cResult->Divide(3,NUM);
  for (int i=0; i<NUM; i++){
   numEventsD[i] = numEvents[i];
   numEventsDL[i] = 0.;
   numEventsDH[i] = 0.;
//    TString nameInFile = Form("output/outStudyEnergyScale_Chi2Distribution_%d_Events.root",numEvents[i]); 
   TString nameInFile = Form("output/out_EnScale_MC_%d_Events.root",numEvents[i]); 
   
   fileInMC[i] = new TFile(nameInFile.Data(),"READ");
   
   TTree* myTreeLL_Result = (TTree*) fileInMC[i]->Get("myTreeLL_Result");
   TTree* myTreeChi2_Result = (TTree*) fileInMC[i]->Get("myTreeChi2_Result");
   TTree* myTreeNewChi2_Result = (TTree*) fileInMC[i]->Get("myTreeNewChi2_Result");
   
   cResult.cd(i*3+1);
   TString namehAlphaLL = Form("hAlphaLL_%d",numEvents[i]); 
   AlphaLL[i] = new TH1F(namehAlphaLL.Data(),namehAlphaLL.Data(),NBINPLOT,-0.3,0.3);
   TString DrawhAlphaLL = Form("AlphaMean >> %s",namehAlphaLL.Data()); 
   myTreeLL_Result->Draw(DrawhAlphaLL);
   AlphaLL[i]->SetFillColor(kBlue);
   
   cResult.cd(i*3+2);
   TString namehAlphaChi2 = Form("hAlphaChi2_%d",numEvents[i]); 
   AlphaChi2[i] = new TH1F(namehAlphaChi2.Data(),namehAlphaChi2.Data(),NBINPLOT,-0.3,0.3);
   TString DrawhAlphaChi2 = Form("AlphaMean >> %s",namehAlphaChi2.Data()); 
   myTreeChi2_Result->Draw(DrawhAlphaChi2);
   AlphaChi2[i]->SetFillColor(kRed);
   
   cResult.cd(i*3+3);
   TString namehAlphaNewChi2 = Form("hAlphaNewChi2_%d",numEvents[i]); 
   AlphaNewChi2[i] = new TH1F(namehAlphaNewChi2.Data(),namehAlphaNewChi2.Data(),NBINPLOT,-0.3,0.3);
   TString DrawhAlphaNewChi2 = Form("AlphaMean >> %s",namehAlphaNewChi2.Data()); 
   myTreeNewChi2_Result->Draw(DrawhAlphaNewChi2);
   AlphaNewChi2[i]->SetFillColor(kOrange);
   
   
   for (int iBin=0; iBin<NBINPLOT; iBin++) {
    resultTH2F_LL.Fill(numEvents[i],AlphaLL[i]->GetBinCenter(iBin),AlphaLL[i]->GetBinContent(iBin));
    resultTH2F_Chi2.Fill(numEvents[i],AlphaChi2[i]->GetBinCenter(iBin),AlphaChi2[i]->GetBinContent(iBin));
    resultTH2F_NewChi2.Fill(numEvents[i],AlphaNewChi2[i]->GetBinCenter(iBin),AlphaNewChi2[i]->GetBinContent(iBin));
   }
   
   
//    std::vector<double> LL = getSigmaBands (*(AlphaLL[i]));
   
   AlphaMeanLL[i] = AlphaLL[i]->GetMean();
   AlphaMeanChi2[i] = AlphaChi2[i]->GetMean();
   AlphaMeanNewChi2[i] = AlphaNewChi2[i]->GetMean();
   
   AlphaMeanLL_Minus[i] = AlphaLL[i]->GetRMS();
   AlphaMeanChi2_Minus[i] = AlphaChi2[i]->GetRMS();
   AlphaMeanNewChi2_Minus[i] = AlphaNewChi2[i]->GetRMS();
   
   AlphaMeanLL_Plus[i] = AlphaLL[i]->GetRMS();
   AlphaMeanChi2_Plus[i] = AlphaChi2[i]->GetRMS();
   AlphaMeanNewChi2_Plus[i] = AlphaNewChi2[i]->GetRMS();
   
   
   
   
   
   
   //   TTree* myTreeChi2 = (TTree*) fileInMC[i]->Get("myTreeChi2");
   //   double Alpha;
   //   double Chi2;
   //   double NewChi2;
   //   double LL;
   //   myTreeChi2.SetBranchAddress("Alpha",&Alpha);
   //   myTreeChi2.SetBranchAddress("Chi2",&Chi2);
   //   myTreeChi2.SetBranchAddress("NewChi2",&NewChi2);
   //   myTreeChi2.SetBranchAddress("LL",&LL);
   
  }
  
  TLine* lOriz = new TLine(0,-0.03,numEvents[NUM],-0.03);
  lOriz->SetLineColor(kRed);
  lOriz->SetLineWidth(2);
  lOriz->SetLineStyle(5);
  
  
  TCanvas *cGraph = new TCanvas("cGraph","cGraph",10,10,800,800);
   
  TGraphAsymmErrors* grLL = new TGraphAsymmErrors(NUM,numEventsD,AlphaMeanLL,numEventsDL,numEventsDH,AlphaMeanLL_Minus,AlphaMeanLL_Plus);
  TGraphAsymmErrors* grChi2 = new TGraphAsymmErrors(NUM,numEventsD,AlphaMeanChi2,numEventsDL,numEventsDH,AlphaMeanChi2_Minus,AlphaMeanChi2_Plus);
  TGraphAsymmErrors* grNewChi2 = new TGraphAsymmErrors(NUM,numEventsD,AlphaMeanNewChi2,numEventsDL,numEventsDH,AlphaMeanNewChi2_Minus,AlphaMeanNewChi2_Plus);
  
  grLL->SetLineColor(kBlue);
  grLL->SetMarkerColor(kBlue);
  grLL->SetFillColor(kBlue);
  grLL->SetMarkerStyle(21);
  grLL->SetTitle("LL");
  grChi2->SetLineColor(kRed);
  grChi2->SetMarkerColor(kRed);
  grChi2->SetFillColor(kRed);
  grChi2->SetMarkerStyle(20);
  grChi2->SetTitle("#chi^{2}");
  grNewChi2->SetLineColor(kOrange);
  grNewChi2->SetMarkerColor(kOrange);
  grNewChi2->SetFillColor(kOrange);
  grNewChi2->SetMarkerStyle(21);
  grNewChi2->SetTitle("New #chi^{2}");
  
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(grLL);
  mg->Add(grChi2);
  mg->Add(grNewChi2);
  mg->Draw("APL");
  mg->GetXaxis()->SetTitle("Number of events");
  mg->GetYaxis()->SetTitle("#alpha");
  gPad->BuildLegend();
  gPad->SetGrid();
  lOriz->Draw();
  
  
  TCanvas *cTH2F = new TCanvas("cTH2F","cTH2F",10,10,300,900);
  cTH2F->Divide(1,3);
  
  cTH2F->cd(1);
  resultTH2F_LL->Draw("colz");
  lOriz->Draw();
  gPad->SetGrid();
  
  cTH2F->cd(2);
  resultTH2F_Chi2->Draw("colz");
  lOriz->Draw();
  gPad->SetGrid();
  
  cTH2F->cd(3);
  resultTH2F_NewChi2->Draw("colz");
  lOriz->Draw();
  gPad->SetGrid();
  
}


