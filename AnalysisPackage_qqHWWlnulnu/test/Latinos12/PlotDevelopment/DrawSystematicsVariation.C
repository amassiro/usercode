#include "TString.h"
#include "TH1F.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TFile.h"

#include<vector>
#include <iostream>
#include <algorithm>
#include <utility>

#include "THStack.h"
#include "TGaxis.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TLatex.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TFrame.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TGraph2DErrors.h"
#include "TExec.h"
#include "TText.h"





void ChangeAxis(TH1F* histo, double Xedge[] ) {
 TString name = Form("edge_%s",histo->GetName());
 TH1F* tempoHisto = new TH1F(name, histo->GetTitle(), histo->GetNbinsX(), Xedge);
 for (int iBin = 0; iBin < histo->GetNbinsX(); iBin ++) {
  tempoHisto->SetBinContent (iBin+1, histo->GetBinContent(iBin+1));
  tempoHisto->SetBinError   (iBin+1, histo->GetBinError(iBin+1)  );
//   std::cout << " iBin = " << iBin << " Xedge[" << iBin << "] = " << Xedge[iBin] << std::endl;
 }
//  std::cout << " tempoHisto = " << tempoHisto->GetName() << std::endl;
 std::swap(*histo, *tempoHisto);
}



void ChangeAxis(TGraphAsymmErrors* gr, double Xedge[] ) {
 TString name = Form("edge_%s",gr->GetName());
 TGraphAsymmErrors* tempoGr = new TGraphAsymmErrors();
 for (int iBin = 0; iBin < gr->GetN(); iBin ++) {
  double xx;
  double yy;
  gr->GetPoint(iBin, xx, yy);
  double err_y_up = gr->GetErrorYhigh(iBin);
  double err_y_lo = gr->GetErrorYlow(iBin);
  xx = (Xedge[iBin] + Xedge[iBin+1] ) / 2.;
  double err_x = (Xedge[iBin+1] - Xedge[iBin] ) / 2.;
  tempoGr->SetPoint      (iBin, xx, yy);
  tempoGr->SetPointError (iBin, err_x, err_x, err_y_lo, err_y_up);
//   std::cout << " iBin = " << iBin << " eY = " << err_y_lo << " - " << err_y_up << " eX = " << err_x << " - " << err_x << std::endl;
//   std::cout << "                  Y = " << yy << std::endl;
//   std::cout << "                  X = " << xx << std::endl;
 }
 std::swap(*gr, *tempoGr);
}




//---- Filter bins ----
TH1F* FilterBins(std::vector<int> binsToSelect, TH1F* inputTH) {
 int numbin = binsToSelect.size();
 
 TString name = Form ("%s_new",inputTH->GetName());
 TString title = Form ("%s",inputTH->GetTitle());
 
 TH1F* newTH = new TH1F (name,title,numbin,0,numbin);
 for (int i=0; i< binsToSelect.size(); i++) {
  newTH->SetBinContent (i+1, inputTH->GetBinContent(binsToSelect.at(i)));
  newTH->SetBinError   (i+1, inputTH->GetBinError(binsToSelect.at(i)));
 }
 
 return newTH;
}

TGraphAsymmErrors* FilterBins(std::vector<int> binsToSelect, TGraphAsymmErrors* inputGR) {
 int numbin = binsToSelect.size();
 
 TString name = Form ("%s_new",inputGR->GetName());
 TString title = Form ("%s",inputGR->GetTitle());
 
 TGraphAsymmErrors* newGR = new TGraphAsymmErrors();
 newGR -> SetName (name);
 
 for (int i=0; i< binsToSelect.size(); i++) {
  
  double X = i+0.5;
  double Y = (inputGR->GetY()) [binsToSelect.at(i)-1];
  
  double errXUp      = inputGR->GetErrorXhigh(binsToSelect.at(i)-1);
  double errXDown    = inputGR->GetErrorXlow(binsToSelect.at(i)-1);
  double errYUp      = inputGR->GetErrorYhigh(binsToSelect.at(i)-1);
  double errYDown    = inputGR->GetErrorYlow(binsToSelect.at(i)-1);
  
  newGR->SetPoint(i, X, Y);
  newGR->SetPointError(i, errXDown, errXUp, errYDown, errYUp);
  
  //     std::cout << " i = " << i << " X = " << X << " Y = " << Y << std::endl;
 }
 
 return newGR;
}



void DrawSystematicsVariation() {
 
 TString label = Form ("m_{T}^{ll-E_{T}^{miss}} [GeV]");
  
 gInterpreter->ExecuteMacro("../Plot/LatinoStyle2.C");
 
 TString date = Form ("of_1j_19.47");
 TFile* f0 = new TFile("SystematicsPlot/hww-19.47fb.mH125.of_1j_shape.root");
 
 
 std::string NameFolders[] = {"sig","bkg","init"};
 std::vector<std::string> vNameFolders (NameFolders, NameFolders + sizeof(NameFolders) / sizeof(std::string) );
 
 std::string NameSamples[] = {"model","WW","Vg","VgS","WJet","Top","ggWW","DYLL","VV","DYTT","ggH","vbfH","wzttH"};
 std::vector<std::string> vNameSamples (NameSamples, NameSamples + sizeof(NameSamples) / sizeof(std::string) );
 
 std::string NameSystematics[] = {"all", "CMS_eff_e", "CMS_eff_m", "CMS_hww_FakeRate",                 "CMS_hww_FakeRate_e",               "CMS_hww_FakeRate_m",               "CMS_norm_DYTT",                    "CMS_norm_DYof",                    "CMS_norm_Vg",                      "CMS_norm_WW",                      "QCDscale_VH",                      "QCDscale_VV",                      "QCDscale_VgS",                     "QCDscale_ggH",                     "QCDscale_ggH1in",                  "QCDscale_ggH_ACCEPT",              "QCDscale_ggWW",                    "QCDscale_qqH",                     "QCDscale_qqH_ACCEPT",              "UEPS",        "interf_ggH",  "lumi",        "pdf_gg",      "pdf_qqbar",   "CMS_hww_vbfH_of_0j_stat_bin1",       "CMS_hww_ggH_of_0j_stat_bin1",        "CMS_hww_wzttH_of_0j_stat_bin1",      "CMS_hww_VgS_of_0j_stat_bin1",        "CMS_hww_Vg_of_0j_stat_bin1",         "CMS_hww_WJet_of_0j_stat_bin1",       "CMS_hww_DYLL_of_0j_stat_bin1",       "CMS_hww_VV_of_0j_stat_bin1",         "CMS_hww_DYTT_of_0j_stat_bin1",       "CMS_hww_WW_extr",                  "CMS_hww_WW_0j_stat",               "CMS_hww_WW_0j_extr_corr",           "CMS_hww_WW_of_0j_extr_uncorr",     "CMS_hww_Top_0j_extr",              "CMS_hww_Top_0j_stat",              "CMS_hww_Top_0j_extr_corr",           "CMS_hww_Top_of_0j_extr_uncorr",      "Gen_nlo_WW", "Gen_scale_WW", "CMS_eff_l",    "CMS_hww_DYLL_template_shape",  "CMS_hww_DYTT_of_0j_stat_shape",    "CMS_hww_Top_ctrlTT",               "CMS_hww_Top_fTW",                  "CMS_hww_Top_of_0j_stat_shape",     "CMS_hww_VV_of_0j_stat_shape",      "CMS_hww_VgS_of_0j_stat_shape",     "CMS_hww_Vg_of_0j_stat_shape",      "CMS_hww_WJet_FakeRate_e_shape",    "CMS_hww_WJet_FakeRate_m_shape",    "CMS_hww_WJet_ctrlSS_shape",        "CMS_hww_WJet_of_0j_stat_shape",    "CMS_hww_WW_of_0j_stat_shape",      "CMS_hww_ggH_of_0j_stat_shape",     "CMS_hww_ggWW_of_0j_stat_shape",    "CMS_hww_vbfH_of_0j_stat_shape",    "CMS_hww_wzttH_of_0j_stat_shape",   "CMS_met", "CMS_p_res_e",   "CMS_p_scale_e", "CMS_p_scale_j",   "CMS_p_scale_m"};
 std::vector<std::string> vNameSystematics (NameSystematics, NameSystematics + sizeof(NameSystematics) / sizeof(std::string) );
 

 //  double vedges[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
 double vedges[] = {12,30,45,60,75,100,125,150,175,200};
//  std::vector<double> vEdges (vedges, vedges + sizeof(vedges) / sizeof(double) );


 
 std::vector<int> binsToSelect; 

 //  x Moriond 2013
 int NMAXX = 14;  
 int NMAXY = 9;  

 
 //---- nice subregion ----
 int minNY = 0;
 int minNX = 2;
 
 
 int NX = 7;
 
 
 //---- all ----
//  int NX = NMAXX;
 int NY = NMAXY;
 
 
 for (int iX=minNX; iX<NX; iX++){
  binsToSelect.clear();
  for (int iY=minNY; iY<NY; iY++){
   binsToSelect.push_back (iX*NMAXY+iY+1);
//    std::cout << " iX*NY+iY+1 = " << iX*NY+iY+1 << std::endl;
  }
 }
 
 
 //  TString name = Form ("%s/WW_errs_CMS_p_res_e",sample.Data());
 
 TCanvas* cc = new TCanvas("cc","cc",500,500);
 gStyle->SetOptStat(0);
 
 
 for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
  
  TString CommandToExec = Form("rm -r %s_%s",date.Data(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("mkdir %s_%s",date.Data(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("cp index.php %s_%s",date.Data(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  

  for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {
   
   
   TString CommandToExec = Form("rm -r %s_%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameSystematics.at(iSystematics).c_str());
   gSystem->Exec(CommandToExec);  
   
   CommandToExec = Form("mkdir %s_%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameSystematics.at(iSystematics).c_str());
   gSystem->Exec(CommandToExec);  
   
   CommandToExec = Form("cp index.php %s_%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameSystematics.at(iSystematics).c_str());
   gSystem->Exec(CommandToExec);  
   
   for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {
    std::cout << "vNameSamples.at(" << iSample << ") = " << vNameSamples.at(iSample) << std::endl;
    
    TString nameHisto = Form ("%s/hist_%s",vNameFolders.at(iFolder).c_str(),vNameSamples.at(iSample).c_str());
    if (f0->Get(nameHisto)) {
     TH1F* histo = (TH1F*) FilterBins(binsToSelect, (TH1F*) f0->Get(nameHisto));     
     ChangeAxis(histo, vedges);
     std::cout << " histo =  " << histo->GetName() << std::endl;
     
     TString name = Form ("%s/%s/%s_errs_%s",vNameFolders.at(iFolder).c_str(),vNameSamples.at(iSample).c_str(),vNameSamples.at(iSample).c_str(), vNameSystematics.at(iSystematics).c_str());
     
     if (f0->Get(name)) {
      TGraphAsymmErrors* gr = (TGraphAsymmErrors*) FilterBins(binsToSelect, (TGraphAsymmErrors*) f0->Get(name));  
      ChangeAxis(gr, vedges);
      
      gr->SetLineWidth(2);
      gr->SetLineColor(kRed);
      gr->SetFillColor(kRed);
      gr->SetFillStyle(3001);
      
      TString nameCanvas = Form ("%s_%s",vNameSamples.at(iSample).c_str(), vNameSystematics.at(iSystematics).c_str());
      //      TCanvas* cc = new TCanvas(nameCanvas.Data(),nameCanvas.Data(),500,500);
      //      gStyle->SetOptStat(0);
      
      histo->SetTitle("");
      histo->SetLineWidth(2);
      histo->SetLineColor(kBlack);
      histo->Draw();
      histo->GetXaxis()->SetTitle(label.Data());
      histo->GetYaxis()->SetRangeUser(0,1.5*histo->GetMaximum());   
      gr->Draw("2");
      
      TString SavePlot;
      SavePlot = Form("%s_%s/%s/cc_%s.png",date.Data(),vNameFolders.at(iFolder).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
      cc->SaveAs(SavePlot.Data());
      SavePlot = Form("%s_%s/%s/cc_%s.pdf",date.Data(),vNameFolders.at(iFolder).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
      cc->SaveAs(SavePlot.Data());
      SavePlot = Form("%s_%s/%s/cc_%s.eps",date.Data(),vNameFolders.at(iFolder).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
      cc->SaveAs(SavePlot.Data());
     }
    }
   }
  }
 }  
 
 
}


