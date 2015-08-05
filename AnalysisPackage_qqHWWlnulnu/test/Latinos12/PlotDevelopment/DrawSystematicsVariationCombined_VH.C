#include "TString.h"
#include "TH1F.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TFile.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

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

#include "RooArgList.h"
#include "RooRealVar.h"



std::string ForLatex(std::string input) {
 std::string output = input;
 std::replace( output.begin(), output.end(), '_', '-'); 
 return output;
}

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
 delete tempoHisto;
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


///---- divide two TGraphAsymmErrors ----
TGraphAsymmErrors* Divide(TGraphAsymmErrors* num, TGraphAsymmErrors* den) {
 TString name = Form("ratio_%s",num->GetName());
 TGraphAsymmErrors* tempoGr = new TGraphAsymmErrors();
 for (int iBin = 0; iBin < num->GetN(); iBin ++) {
  double num_xx;
  double num_yy;
  num->GetPoint(iBin, num_xx, num_yy);
  double err_num_y_up = num->GetErrorYhigh(iBin);
  double err_num_y_lo = num->GetErrorYlow(iBin);
  double err_num_x_up = num->GetErrorXhigh(iBin);
  double err_num_x_lo = num->GetErrorXlow(iBin);
  

  double den_xx;
  double den_yy;
  den->GetPoint(iBin, den_xx, den_yy);
  double err_den_y_up = den->GetErrorYhigh(iBin);
  double err_den_y_lo = den->GetErrorYlow(iBin);
  double err_den_x_up = den->GetErrorXhigh(iBin);
  double err_den_x_lo = den->GetErrorXlow(iBin);
  

  double alpha = 0;
  if (den_yy != 0) {
   alpha = 1. / den_yy;
  }
  

  tempoGr->SetMarkerSize(1);
  tempoGr->SetMarkerStyle(20);
  tempoGr->SetMarkerColor(num->GetLineColor());
  
  tempoGr->SetLineWidth(num->GetLineWidth());
  tempoGr->SetLineColor(num->GetLineColor());
  tempoGr->SetFillColor(num->GetFillColor());
  tempoGr->SetFillStyle(num->GetFillStyle());
  
  tempoGr->SetPoint      (iBin, num_xx, num_yy*alpha);
  tempoGr->SetPointError (iBin, err_num_x_lo, err_num_x_up, err_num_y_lo*alpha, err_num_y_up*alpha);
 }
 
 return tempoGr;
}



///---- subtract two TGraphAsymmErrors ----
TGraphAsymmErrors* Subtract(TGraphAsymmErrors* num, TGraphAsymmErrors* den) {
 TString name = Form("subtract_%s",num->GetName());
 TGraphAsymmErrors* tempoGr = new TGraphAsymmErrors();
 for (int iBin = 0; iBin < num->GetN(); iBin ++) {
  double num_xx;
  double num_yy;
  num->GetPoint(iBin, num_xx, num_yy);
  double err_num_y_up = num->GetErrorYhigh(iBin);
  double err_num_y_lo = num->GetErrorYlow(iBin);
  double err_num_x_up = num->GetErrorXhigh(iBin);
  double err_num_x_lo = num->GetErrorXlow(iBin);
  
  
  double den_xx;
  double den_yy;
  den->GetPoint(iBin, den_xx, den_yy);
  double err_den_y_up = den->GetErrorYhigh(iBin);
  double err_den_y_lo = den->GetErrorYlow(iBin);
  double err_den_x_up = den->GetErrorXhigh(iBin);
  double err_den_x_lo = den->GetErrorXlow(iBin);
  
  
  double alpha = 0;
  if (den_yy != 0) {
   alpha = -den_yy;
  }
  
  
  tempoGr->SetMarkerSize(1);
  tempoGr->SetMarkerStyle(20);
  tempoGr->SetMarkerColor(num->GetLineColor());
  
  tempoGr->SetLineWidth(num->GetLineWidth());
  tempoGr->SetLineColor(num->GetLineColor());
  tempoGr->SetFillColor(num->GetFillColor());
  tempoGr->SetFillStyle(num->GetFillStyle());
  
  tempoGr->SetPoint      (iBin, num_xx, num_yy+alpha);
  tempoGr->SetPointError (iBin, err_num_x_lo, err_num_x_up, err_num_y_lo, err_num_y_up);
 }
 
 return tempoGr;
}



///---- normalize two TGraphAsymmErrors ----
TGraphAsymmErrors* Normalize(TGraphAsymmErrors* num) {
 TString name = Form("normalized_%s",num->GetName());
 double integral = 0;
 for (int iBin = 0; iBin < num->GetN(); iBin ++) {
  double num_xx;
  double num_yy;
  num->GetPoint(iBin, num_xx, num_yy);
  double err_num_x_up = num->GetErrorXhigh(iBin);
  double err_num_x_lo = num->GetErrorXlow(iBin);
  
  integral += num_yy; 
//   integral += num_yy * (err_num_x_lo+err_num_x_up);
//   std::cout << "    >> " << err_num_x_lo << " -- " << err_num_x_up << " ---> * " << num_yy << std::endl;
 }

 TGraphAsymmErrors* tempoGr = new TGraphAsymmErrors();
 
//  std::cout << " integral = " << integral << std::endl;
 
 for (int iBin = 0; iBin < num->GetN(); iBin ++) {
  double num_xx;
  double num_yy;
  num->GetPoint(iBin, num_xx, num_yy);
  double err_num_y_up = num->GetErrorYhigh(iBin);
  double err_num_y_lo = num->GetErrorYlow(iBin);
  double err_num_x_up = num->GetErrorXhigh(iBin);
  double err_num_x_lo = num->GetErrorXlow(iBin);
  
  double alpha = 1;
  if (integral != 0) alpha = 1. / integral;

  tempoGr->SetMarkerSize(1);
  tempoGr->SetMarkerStyle(20);
  tempoGr->SetMarkerColor(num->GetLineColor());
  
  tempoGr->SetLineWidth(num->GetLineWidth());
  tempoGr->SetLineColor(num->GetLineColor());
  tempoGr->SetFillColor(num->GetFillColor());
  tempoGr->SetFillStyle(num->GetFillStyle());
  
  tempoGr->SetPoint      (iBin, num_xx, num_yy*alpha);
  tempoGr->SetPointError (iBin, err_num_x_lo, err_num_x_up, err_num_y_lo*alpha, err_num_y_up*alpha);
 }
 
 return tempoGr;
}


///---- normalize TGraphAsymmErrors ----
double Max(TGraphAsymmErrors* num) {
 double max = 0;
 for (int iBin = 0; iBin < num->GetN(); iBin ++) {
  double num_xx;
  double num_yy;
  num->GetPoint(iBin, num_xx, num_yy);
  double err_num_y_up = num->GetErrorYhigh(iBin);
  if (max < (num_yy + err_num_y_up) ) max =  (num_yy + err_num_y_up);
 }
 return max;
}
 
 
 ///---- calculate Upper integral of TGraphAsymmErrors ----
 double UpIntegral(TGraphAsymmErrors* num) {
  double integral = 0;
  for (int iBin = 0; iBin < num->GetN(); iBin ++) {
   double num_xx;
   double num_yy;
   num->GetPoint(iBin, num_xx, num_yy);
   double err_num_y_up = num->GetErrorYhigh(iBin);
   
   integral += (num_yy+err_num_y_up); 
  }
  return integral;
 }
 
 
 ///---- calculate Lower integral of TGraphAsymmErrors ----
 double LoIntegral(TGraphAsymmErrors* num) {
  double integral = 0;
  for (int iBin = 0; iBin < num->GetN(); iBin ++) {
   double num_xx;
   double num_yy;
   num->GetPoint(iBin, num_xx, num_yy);
   double err_num_y_lo = num->GetErrorYlow(iBin);
   
   integral += (num_yy-err_num_y_lo); 
  }
  return integral;
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
  
//   std::cout << " i = " << i << " X = " << X << " Y = " << Y << std::endl;
 }
 
 return newGR;
}




///==== macro ====

// #include "TError.h"

void DrawSystematicsVariationCombined_VH() {
 
//  gErrorIgnoreLevel = 0;
  
 TH1::AddDirectory(kFALSE);

 TString label = Form ("m_{ll} [GeV]");
  
 gInterpreter->ExecuteMacro("../Plot/LatinoStyle2.C");
 
//  TString date = Form ("of_2j_vh_8TeV_plot");
//  TFile* f0 = new TFile("postFit2J-VH/mH125-error.root");

//  TString date = Form ("of_2j_vh_8TeV_noBanana_plot");
//  TFile* f0 = new TFile("postFit2J-VH-noBanana/mH125-error.root");
 
//  TString date = Form ("of_2j_vh_8TeV_plot_COMBINED_sfof_AN2013_084");
//  TFile* f0 = new TFile("postFit-Moriond-VH-AN2013-084/mH125-sfof-error.root");
//  std::string NameDC[] = {"ll2jVH2012SF"};
//  std::string NameDC[] = {"ll2jVH2012SF","ll2jVH2012OF"};
 
 
//  [cmsmi4] /data2/amassiro/VBF/Summer12/28Jan2013/Shape/playground/vhMllDF > mkAutopsy.py datacards/hww-19.47fb.mH125.of_vh2j_shape.txt --dump=postFit/mH125-error-Mode-mllDF.root --errormode=rawerrors
 
//  TString date = Form ("sf_2j_vh_8TeV_plot_AN2013_084_noBBB");
//  TFile* f0 = new TFile("postFit-Moriond-VH-AN2013-084/mH125-error-Mode-mllSF.root");
//  std::string NameDC[] = {"sf_vh2j"};
 
 //  double vedges[] = {12,32,52,72,92,112,132,152,172,192,212,232};
//  double vedges[] = {0,1};
//  std::vector<double> vEdges (vedges, vedges + sizeof(vedges) / sizeof(double) );
 
 
 
//  TString date = Form ("of_2j_vh_8TeV_plot_AN2013_084_noBBB");
//  TFile* f0 = new TFile("postFit-Moriond-VH-AN2013-084/mH125-error-Mode-mllDF.root");
//  std::string NameDC[] = {"of_vh2j"};
 
//  TString date = Form ("of_2j_vh_8TeV_plot_AN2013_084_noBBB_errorModeOFF");
//  TFile* f0 = new TFile("postFit-Moriond-VH-AN2013-084/mH125-error-Mode-OFF-mllDF.root");
//  std::string NameDC[] = {"of_vh2j"};
 
 
//  TString date = Form ("of_2j_vh_8TeV_plot_AN2013_084_BBB");
//  TFile* f0 = new TFile("postFit-Moriond-VH-AN2013-084/mH125-mllDF-BBB.root");
//  std::string NameDC[] = {"of_vh2j"};

 TString date = Form ("of_2j_vh_8TeV_plot_AN2013_084_BBB_errorModeOFF");
 TFile* f0 = new TFile("postFit-Moriond-VH-AN2013-084/mH125-mllDF-BBB-error-Mode-OFF.root");
 std::string NameDC[] = {"of_vh2j"};
 
 
 double vedges[] = {12,30,45,60,75,100,125,150,175,200};
 std::vector<double> vEdges (vedges, vedges + sizeof(vedges) / sizeof(double) );
 
 
 
//  TString date = Form ("of_2j_vh_8TeV_noBanana_plot_AN2013_084");
//  TFile* f0 = new TFile("postFit-Moriond-VH-AN2013-084/mH125-error.root");
//  std::string NameDC[] = {"of_vh2j"};
 
//  TString date = Form ("of_2j_vh_8TeV_noBanana_plot_AN2013_084_mH145");
//  TFile* f0 = new TFile("postFit-Moriond-VH-AN2013-084/mH145-error.root");
 
//  TString date = Form ("of_2j_vh_8TeV_noBanana_plot_AN2013_084_mH150");
//  TFile* f0 = new TFile("postFit-Moriond-VH-AN2013-084/mH150-error.root");
 
 int vFillStyle[100] = {3003, 3004, 3005};
 EColor vColor[100] = { (EColor) (kGreen+1), (EColor) (kRed), (EColor) (kBlue)};
 std::string NameFolders[] = {"init","sig","bkg"};
 std::vector<std::string> vNameFolders (NameFolders, NameFolders + sizeof(NameFolders) / sizeof(std::string) );
 
//  std::string NameDC[] = {"of_vh2j"};
 std::vector<std::string> vNameDC (NameDC, NameDC + sizeof(NameDC) / sizeof(std::string) );
 
//  std::string NameSamples[] = {"model","WW","Vg","VgS","WJet","Top","ggWW","DYLL","VV","DYTT","VVV","ggH","vbfH","wH","zH"};
//  std::string NameSamples[] = {"model","WW","Vg",      "WJet","Top","ggWW",              "VV","DYTT","VVV","ggH","vbfH","wH","zH"};

 
 std::string NameSamples[] = {"model","WW","Vg",      "WJet","Top","ggWW",              "VV","DYTT","VVV","ggH", "qqH","WH","ZH"};
//  std::string NameSamples[] = {"model","WW","Vg",      "WJet","Top","ggWW",              "VV","DYee","DYmm","VVV","ggH", "qqH","WH","ZH"};
 
 
 
 //  std::string NameSamples[] =    {"model","WW","Vg",      "WJet","Top","ggWW","DYee","DYmm","VV","DYTT","VVV","ggH","vbfH","wH","zH"};
//  std::string NameSamples[] =    {"model","WW","Vg",      "WJet","Top","ggWW","DYee","DYmm","VV","VVV",        "ggH","vbfH","wH","zH"};
 std::vector<std::string> vNameSamples (NameSamples, NameSamples + sizeof(NameSamples) / sizeof(std::string) );
 
//  std::string NameSystematics[] = {"all", "r", "CMS_8TeV_eff_e","CMS_8TeV_eff_m","CMS_8TeV_hww_FakeRate","CMS_8TeV_norm_DYTT","CMS_8TeV_norm_DYof","CMS_8TeV_norm_Vg","CMS_hww_FakeRate_e","CMS_hww_FakeRate_m","QCDscale_VH","QCDscale_VV","QCDscale_VgS","QCDscale_WW2in","QCDscale_ggH2in_vh","QCDscale_ggH_ACCEPT","QCDscale_ggWW","QCDscale_qqH","QCDscale_qqH_ACCEPT","UEPS","interf_ggH","lumi_8TeV","pdf_gg","pdf_qqbar","CMS_8TeV_hww_vbfH_of_vh2j_stat_bin1","CMS_8TeV_hww_ggH_of_vh2j_stat_bin1","CMS_8TeV_hww_wH_of_vh2j_stat_bin1","CMS_8TeV_hww_zH_of_vh2j_stat_bin1","CMS_8TeV_hww_ggWW_of_vh2j_stat_bin1","CMS_8TeV_hww_VgS_of_vh2j_stat_bin1","CMS_8TeV_hww_Vg_of_vh2j_stat_bin1","CMS_8TeV_hww_WJet_of_vh2j_stat_bin1","CMS_8TeV_hww_WW_of_vh2j_stat_bin1","CMS_8TeV_hww_VV_of_vh2j_stat_bin1","CMS_8TeV_hww_DYTT_of_vh2j_stat_bin1","CMS_8TeV_hww_Top_2j_of_vh2j_extr","CMS_8TeV_hww_Top_2j_of_vh2j_stat","CMS_8TeV_eff_l","CMS_8TeV_hww_DYTT_of_vh2j_stat_shape","CMS_8TeV_hww_Top_of_vh2j_stat_shape","CMS_8TeV_hww_VV_of_vh2j_stat_shape","CMS_8TeV_hww_VgS_of_vh2j_stat_shape","CMS_8TeV_hww_Vg_of_vh2j_stat_shape","CMS_8TeV_hww_WJet_of_vh2j_stat_shape","CMS_8TeV_hww_WW_of_vh2j_stat_shape","CMS_8TeV_hww_ggH_of_vh2j_stat_shape","CMS_8TeV_hww_ggWW_of_vh2j_stat_shape","CMS_8TeV_hww_ttH_of_vh2j_stat_shape","CMS_8TeV_hww_vbfH_of_vh2j_stat_shape","CMS_8TeV_hww_wH_of_vh2j_stat_shape","CMS_8TeV_hww_zH_of_vh2j_stat_shape","CMS_8TeV_met","CMS_8TeV_p_res_e","CMS_8TeV_p_scale_e","CMS_8TeV_p_scale_j","CMS_8TeV_p_scale_m"};
//  std::string NameSystematics[] = {"all", "r", "CMS_8TeV_eff_e","CMS_8TeV_eff_m","CMS_8TeV_hww_FakeRate","CMS_8TeV_met","CMS_8TeV_norm_DYTT","CMS_8TeV_norm_DYof","CMS_8TeV_norm_Vg","CMS_8TeV_p_scale_e","CMS_8TeV_p_scale_j","CMS_8TeV_p_scale_m","CMS_hww_FakeRate_e","CMS_hww_FakeRate_m","CMS_norm_","QCDscale_VH","QCDscale_VV","QCDscale_VgS","QCDscale_WW2in","QCDscale_ggH2in_vh","QCDscale_ggH_ACCEPT","QCDscale_ggWW","QCDscale_qqH","QCDscale_qqH_ACCEPT","UEPS","interf_ggH","lumi_8TeV","pdf_gg","pdf_qqbar","CMS_8TeV_hww_vbfH_of_vh2j_stat_bin1","CMS_8TeV_hww_ggH_of_vh2j_stat_bin1","CMS_8TeV_hww_wH_of_vh2j_stat_bin1","CMS_8TeV_hww_zH_of_vh2j_stat_bin1","CMS_8TeV_hww_ggWW_of_vh2j_stat_bin1","CMS_8TeV_hww_VgS_of_vh2j_stat_bin1","CMS_8TeV_hww_Vg_of_vh2j_stat_bin1","CMS_8TeV_hww_WJet_of_vh2j_stat_bin1","CMS_8TeV_hww_WW_of_vh2j_stat_bin1","CMS_8TeV_hww_VV_of_vh2j_stat_bin1","CMS_8TeV_hww_DYTT_of_vh2j_stat_bin1","CMS_8TeV_hww_Top_2j_extr","CMS_8TeV_hww_Top_2j_stat","CMS_8TeV_hww_Top_2j_extr_corr","CMS_hww_DYTT_of_vh2j_stat_shape","CMS_hww_Top_of_vh2j_stat_shape","CMS_hww_VV_of_vh2j_stat_shape","CMS_hww_VgS_of_vh2j_stat_shape","CMS_hww_Vg_of_vh2j_stat_shape","CMS_hww_WJet_of_vh2j_stat_shape","CMS_hww_WW_of_vh2j_stat_shape","CMS_hww_ggH_of_vh2j_stat_shape","CMS_hww_ggWW_of_vh2j_stat_shape","CMS_hww_ttH_of_vh2j_stat_shape","CMS_hww_vbfH_of_vh2j_stat_shape","CMS_hww_wH_of_vh2j_stat_shape","CMS_hww_zH_of_vh2j_stat_shape","CMS_met","CMS_p_scale_e","CMS_p_scale_j","CMS_p_scale_m"};
//  std::string NameSystematics[]    = {"all", "r", "CMS_8TeV_eff_e","CMS_8TeV_eff_m","CMS_8TeV_hww_FakeRate","CMS_8TeV_met","CMS_8TeV_norm_DYTT",                     "CMS_8TeV_norm_Vg","CMS_8TeV_p_scale_e","CMS_8TeV_p_scale_j","CMS_8TeV_p_scale_m","CMS_hww_FakeRate_e","CMS_hww_FakeRate_m",            "QCDscale_VH","QCDscale_VV","QCDscale_VgS","QCDscale_WW2in","QCDscale_ggH2in_vh","QCDscale_ggH_ACCEPT","QCDscale_ggWW","QCDscale_qqH","QCDscale_qqH_ACCEPT","UEPS","interf_ggH","lumi_8TeV","pdf_gg","pdf_qqbar","CMS_8TeV_hww_vbfH_of_vh2j_stat_bin1","CMS_8TeV_hww_ggH_of_vh2j_stat_bin1","CMS_8TeV_hww_wH_of_vh2j_stat_bin1","CMS_8TeV_hww_zH_of_vh2j_stat_bin1","CMS_8TeV_hww_ggWW_of_vh2j_stat_bin1","CMS_8TeV_hww_VgS_of_vh2j_stat_bin1","CMS_8TeV_hww_Vg_of_vh2j_stat_bin1","CMS_8TeV_hww_WJet_of_vh2j_stat_bin1","CMS_8TeV_hww_WW_of_vh2j_stat_bin1","CMS_8TeV_hww_VV_of_vh2j_stat_bin1","CMS_8TeV_hww_DYTT_of_vh2j_stat_bin1","CMS_8TeV_hww_Top_2j_extr","CMS_8TeV_hww_Top_2j_stat","CMS_8TeV_hww_Top_2j_extr_corr","CMS_hww_DYTT_of_vh2j_stat_shape","CMS_hww_Top_of_vh2j_stat_shape","CMS_hww_VV_of_vh2j_stat_shape","CMS_hww_VgS_of_vh2j_stat_shape","CMS_hww_Vg_of_vh2j_stat_shape","CMS_hww_WJet_of_vh2j_stat_shape","CMS_hww_WW_of_vh2j_stat_shape","CMS_hww_ggH_of_vh2j_stat_shape","CMS_hww_ggWW_of_vh2j_stat_shape","CMS_hww_ttH_of_vh2j_stat_shape","CMS_hww_vbfH_of_vh2j_stat_shape","CMS_hww_wH_of_vh2j_stat_shape","CMS_hww_zH_of_vh2j_stat_shape","CMS_met","CMS_p_scale_e","CMS_p_scale_j","CMS_p_scale_m"};
//  std::vector<std::string> vNameSystematics (NameSystematics, NameSystematics + sizeof(NameSystematics) / sizeof(std::string) );
 
 
 std::vector<std::string> vNameSystematics;
//  TDirectory* dir = (TDirectory*) f0->Get("info");
//  TDirectory* dir2 = (TDirectory*) dir->Get("nuisances");
//  gROOT->ProcessLine("dir2->Print(); > tmp.txt");
// //  dir2->Print(); > tmp.txt
//  
//  std::ifstream fileTmp ("tmp.txt"); 
//  std::string buffer;
//  std::string tempString; 
//  if(!fileTmp.is_open()) {
//   std::cerr << "** ERROR: Can't open '" << "tmp.txt" << "' for input" << std::endl;
//   return;
//  }
//  getline(fileTmp,buffer);///---- skip first line
// 
//  
//  
//  while(!fileTmp.eof()) {
//   getline(fileTmp,buffer);
//   std::cout << "buffer = " << buffer << std::endl;
//   if (buffer != ""){ ///---> save from empty line at the end!
//    std::stringstream line( buffer );      
//    line >> tempString; 
//    line >> tempString; 
//    line >> tempString; 
//    vNameSystematics.push_back(tempString);
//    std::cout << tempString << " ";
//   } 
//  }

 
 vNameSystematics.push_back("all");
 vNameSystematics.push_back("r");
 
 TObjArray* obj =  (TObjArray*) f0->Get("info/nuisances");
 TIter iter = TIter(obj);
 TObjString* ostr;
 while ( ostr = (TObjString*) iter.Next() ){
  std::cout << ostr->GetString().Data() << std::endl;
  vNameSystematics.push_back(std::string(ostr->GetString().Data()));
 }
 
 
 
 
 
  
 
 ///---- map over "Folder"
 ///----       folder               datacard                         sample     systematics    integral
 std::map < std::string, std::map < std::string , std::map < std::pair <std::string, std::string>, double > > > m_integral;     ///---- nominal
 std::map < std::string, std::map < std::string , std::map < std::pair <std::string, std::string>, double > > > m_integral_up;  ///---- up
 std::map < std::string, std::map < std::string , std::map < std::pair <std::string, std::string>, double > > > m_integral_lo;  ///---- low
 
 
 ///----       folder                 systematics              value      error
 std::map < std::string,   std::map < std::string , std::pair <double , double > > > vNuisances;  ///---- nuisances
 
 
 
 std::vector<int> binsToSelect; 

 
 //  x Moriond 2013
//  int NMAXX = 11;  
 int NMAXX = sizeof(vedges) / sizeof(double) - 1;
 int NMAXY = 1;  
 // int NX = 8;
 
 //---- nice subregion ----

 int minNY = 0;
 int minNX = 0;
 
 //  int NY = 3;
 
 
 
 //---- all ----
 int NX = NMAXX;
 int NY = NMAXY;
  
//  for (int iX=minNX; iX<NX; iX++){
//   binsToSelect.clear();
//   for (int iY=minNY; iY<NY; iY++){
//    binsToSelect.push_back (iX*NMAXY+iY+1);
// //    std::cout << " iX*NY+iY+1 = " << iX*NY+iY+1 << std::endl;
//   }
//  }

//  for (int iY=NY; iY<NY+1; iY++){
 for (int iY=0; iY<NY; iY++){   
  for (int iX=minNX; iX<NX; iX++){
   binsToSelect.push_back (iX*NMAXY+iY+1);
  }
 }
 
 
 //  TString name = Form ("%s/WW_errs_CMS_p_res_e",sample.Data());
 
 TCanvas* ccNormalize = new TCanvas("ccNormalize","ccNormalize",600,400);
 gStyle->SetOptStat(0);
 TCanvas* ccSubtract = new TCanvas("ccSubtract","ccSubtract",600,400);
 gStyle->SetOptStat(0);
 TCanvas* ccRatio = new TCanvas("ccRatio","ccRatio",600,400);
 gStyle->SetOptStat(0);
 TCanvas* cc = new TCanvas("cc","cc",600,600);
 gStyle->SetOptStat(0);
 
 TString CommandToExec;
 
 
 ///---- to plot all ----
 
 for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
  
  CommandToExec = Form("rm -r %s_%s",date.Data(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("mkdir %s_%s",date.Data(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("cp index.php %s_%s",date.Data(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
  
  for (int iDC = 0; iDC < vNameDC.size(); iDC++) {
   
   CommandToExec = Form("rm -r %s_%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str());
   gSystem->Exec(CommandToExec);  
   
   CommandToExec = Form("mkdir %s_%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str());
   gSystem->Exec(CommandToExec);  
   
   CommandToExec = Form("cp index.php %s_%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str());
   gSystem->Exec(CommandToExec);  
   
   
   
   
   for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {
    
    
    CommandToExec = Form("rm -r %s_%s/%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("mkdir %s_%s/%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("cp index.php %s_%s/%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
    
    bool somethingHere = false;
    for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {
//      std::cout << "vNameSamples.at(" << iSample << ") = " << vNameSamples.at(iSample) << std::endl;

     TString nameHisto = Form ("%s/%s/histo_%s",vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str());
//      std::cout << " nameHisto = " << nameHisto.Data() << std::endl;
     if (f0->Get(nameHisto)) {
      TH1F* histo = (TH1F*) FilterBins(binsToSelect, (TH1F*) f0->Get(nameHisto));  
      ChangeAxis(histo, vedges);
//       std::cout << "                          >>>  histo =  " << histo->GetName() << std::endl;
      
      TString name = Form ("%s/%s/%s/%s_errs_%s",vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str(),vNameSamples.at(iSample).c_str(), vNameSystematics.at(iSystematics).c_str());
      
//       std::cout << " >>>>   name err = " << name.Data() << std::endl;
      if (f0->Get(name)) {
       TGraphAsymmErrors* gr = (TGraphAsymmErrors*) FilterBins(binsToSelect, (TGraphAsymmErrors*) f0->Get(name));  
       ChangeAxis(gr, vedges);
       
       gr->SetLineWidth(2);
       gr->SetLineColor(vColor[iFolder]);
       gr->SetFillColor(vColor[iFolder]);
       gr->SetFillStyle(3001);
       
//        TString nameCanvas = Form ("%s_%s",vNameSamples.at(iSample).c_str(), vNameSystematics.at(iSystematics).c_str());
       //      TCanvas* cc = new TCanvas(nameCanvas.Data(),nameCanvas.Data(),500,500);
       //      gStyle->SetOptStat(0);
       
       histo->SetTitle("");
       histo->SetLineWidth(2);
       histo->SetLineColor(vColor[iFolder]);
       histo->Draw();
       histo->GetXaxis()->SetTitle(label.Data());
       histo->GetYaxis()->SetRangeUser(0,1.5*histo->GetMaximum());   
       gr->Draw("2");
       
       TString SavePlot;
       SavePlot = Form("%s_%s/%s/%s/cc_%s.png",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
       cc->SaveAs(SavePlot.Data());
//        SavePlot = Form("%s_%s/%s/%s/cc_%s.pdf",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
//        cc->SaveAs(SavePlot.Data());
//        SavePlot = Form("%s_%s/%s/%s/cc_%s.eps",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
//        cc->SaveAs(SavePlot.Data());
       
       somethingHere = true;
      }
     }
    }
    
    if (somethingHere == false) {
     ///---- if no plots then remove filder!
     CommandToExec = Form("rm -r %s_%s/%s/%s",date.Data(),vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str());
     gSystem->Exec(CommandToExec);  
    }
    
   }
  }
 }  
 

 
 
 
 
 ///---- to compare before and after ----
 
 CommandToExec = Form("rm -r %s_all",date.Data());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("mkdir %s_all",date.Data());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("cp index.php %s_all",date.Data());
 gSystem->Exec(CommandToExec);  
 
 for (int iDC = 0; iDC < vNameDC.size(); iDC++) {
  
  CommandToExec = Form("rm -r %s_all/%s",date.Data(), vNameDC.at(iDC).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("mkdir %s_all/%s",date.Data(), vNameDC.at(iDC).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("cp index.php %s_all/%s",date.Data(), vNameDC.at(iDC).c_str());
  gSystem->Exec(CommandToExec);  
  
  
  for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {
   
   
   CommandToExec = Form("rm -r %s_all/%s/%s",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str());
   gSystem->Exec(CommandToExec);  
   
   CommandToExec = Form("mkdir %s_all/%s/%s",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str());
   gSystem->Exec(CommandToExec);  
   
   CommandToExec = Form("cp index.php %s_all/%s/%s",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str());
   gSystem->Exec(CommandToExec);  
   
   bool somethingHere = false;
   
   for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {
    //      std::cout << "vNameSamples.at(" << iSample << ") = " << vNameSamples.at(iSample) << std::endl;
    
    TLegend* leg = new TLegend(0.50,0.75,0.90,0.90);
    
    bool something = false;
    
    TGraphAsymmErrors* grReferenceRatio;
    TGraphAsymmErrors* grReferenceSubtract;
    
    std::pair <std::string, std::string> sample_syst (vNameSamples.at(iSample), vNameSystematics.at(iSystematics) );
    
    for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
     
     
     TString nameHisto = Form ("%s/%s/histo_%s",vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str());
     if (f0->Get(nameHisto)) {
      TH1F* histo = (TH1F*) FilterBins(binsToSelect, (TH1F*) f0->Get(nameHisto));     
      ChangeAxis(histo, vedges);
//       std::cout << " histo =  " << histo->GetName() << std::endl;
      
//       std::map < std::string, std::map < std::pair <std::string, std::string>, double > > m_integral; ///---- nominal
      ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] = histo->Integral();
//       std::cout << " histo =  " << histo->GetName() << " [" << nameHisto.Data() << " :: " <<  histo->Integral() << std::endl;
      
      TString name = Form ("%s/%s/%s/%s_errs_%s",vNameFolders.at(iFolder).c_str(), vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str(),vNameSamples.at(iSample).c_str(), vNameSystematics.at(iSystematics).c_str());
      
      if (f0->Get(name)) {
       something = true;
       TGraphAsymmErrors* gr = (TGraphAsymmErrors*) FilterBins(binsToSelect, (TGraphAsymmErrors*) f0->Get(name));  
       ChangeAxis(gr, vedges);
       
       gr->SetLineWidth(2);
       gr->SetLineColor(vColor[iFolder]);
       gr->SetFillColor(vColor[iFolder]);
       gr->SetFillStyle(vFillStyle[iFolder]);

       
       ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] = UpIntegral(gr);
       ((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] = LoIntegral(gr);
       
       ccRatio->cd();
       if (iFolder == 0) {
        grReferenceRatio = (TGraphAsymmErrors*) gr->Clone();
        TGraphAsymmErrors* gr_temp = (TGraphAsymmErrors*) gr->Clone();
        TGraphAsymmErrors* gr_ratio_temp = Divide(gr_temp,grReferenceRatio);
        gr_ratio_temp->Draw("A2P");
//         gr_ratio_temp->Draw("histo");
        gr_ratio_temp->GetXaxis()->SetTitle(label.Data());
        gr_ratio_temp->GetYaxis()->SetTitle("fit / init");
        gr_ratio_temp->GetYaxis()->SetRangeUser(0,2);
        TLine *line = new TLine(vEdges.at(0), 1.0, vEdges.at(vEdges.size()-1), 1.0);
        line->SetLineColor(kBlack);
        line->SetLineWidth(1);
        line->SetLineStyle(1);
        line->Draw("SAME");         
       } 
       else {
        TGraphAsymmErrors* gr_temp = (TGraphAsymmErrors*) gr->Clone();
        TGraphAsymmErrors* gr_ratio_temp = Divide(gr_temp,grReferenceRatio);
        gr_ratio_temp->Draw("2P");
//         gr_ratio_temp->Draw("histo");
       }
       
       
       
       
       ccSubtract->cd();
       if (iFolder == 0) {
        grReferenceSubtract = (TGraphAsymmErrors*) gr->Clone();
        TGraphAsymmErrors* gr_temp = (TGraphAsymmErrors*) gr->Clone();
        TGraphAsymmErrors* gr_subtract_temp = Subtract(gr_temp,grReferenceSubtract);
        gr_subtract_temp->Draw("A2P");
        //         gr_subtract_temp->Draw("histo");
        gr_subtract_temp->GetXaxis()->SetTitle(label.Data());
        gr_subtract_temp->GetYaxis()->SetTitle("fit - init");
        double max = 5;
        gr_subtract_temp->GetYaxis()->SetRangeUser(-max,max);
        TLine *line = new TLine(vEdges.at(0), 0.0, vEdges.at(vEdges.size()-1), 0.0);
        line->SetLineColor(kBlack);
        line->SetLineWidth(1);
        line->SetLineStyle(1);
        line->Draw("SAME"); 
       } 
       else {
        TGraphAsymmErrors* gr_temp = (TGraphAsymmErrors*) gr->Clone();
        TGraphAsymmErrors* gr_subtract_temp = Subtract(gr_temp,grReferenceSubtract);
        gr_subtract_temp->Draw("2P");
        //         gr_subtract_temp->Draw("histo");
       }
              
       
       
       
       ccNormalize->cd();
       if (iFolder == 0) {
        TGraphAsymmErrors* gr_temp = (TGraphAsymmErrors*) gr->Clone();
        TGraphAsymmErrors* gr_normalize_temp = Normalize(gr_temp);
        gr_normalize_temp->Draw("A2P");
        gr_normalize_temp->GetXaxis()->SetTitle(label.Data());
        gr_normalize_temp->GetYaxis()->SetTitle("a.u.");
//         std::cout << " [0] = " << gr_normalize_temp->GetY() [0] << std::endl;
//         std::cout << " max = " << Max(gr_normalize_temp) << std::endl;
        //         gr_normalize_temp->GetYaxis()->SetRangeUser(0,std::max(1.0, 1.2*gr_normalize_temp->GetMaximum()));
        gr_normalize_temp->GetYaxis()->SetRangeUser(0,Max(gr_normalize_temp));
       } 
       else {
        TGraphAsymmErrors* gr_temp = (TGraphAsymmErrors*) gr->Clone();
        TGraphAsymmErrors* gr_normalize_temp = Normalize(gr_temp);
        gr_normalize_temp->Draw("2P");
       }
       
       
       
       
       histo->SetTitle("");
       histo->SetLineWidth(2);
       histo->SetLineColor(vColor[iFolder]);
       
       cc->cd();
       if (iFolder == 0) {
        histo->Draw();
        histo->GetXaxis()->SetTitle(label.Data());
        histo->GetYaxis()->SetRangeUser(0,2.5*histo->GetMaximum());   
       }
       else histo->Draw("same");
       
       leg->AddEntry(gr,vNameFolders.at(iFolder).c_str(),"f");      
       
       gr->Draw("2");
       
       
      }
     }     
    }
    
    leg->SetFillColor(kWhite);
    
    ccNormalize->cd();
    leg->Draw();
    
    ccSubtract->cd();
    leg->Draw();
    
    ccRatio->cd();
    leg->Draw();

    cc->cd();
    leg->Draw();
    
    TString SavePlot;
    if (something) {
     
     SavePlot = Form("%s_all/%s/%s/cc_%s.png",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
     cc->SaveAs(SavePlot.Data());
     //     SavePlot = Form("%s_all/%s/%s/cc_%s.pdf",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
     //     cc->SaveAs(SavePlot.Data());
     //     SavePlot = Form("%s_all/%s/%s/cc_%s.eps",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
     //     cc->SaveAs(SavePlot.Data());
     
     
     SavePlot = Form("%s_all/%s/%s/cc_ratio_%s.png",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
     ccRatio->SaveAs(SavePlot.Data());
     
     SavePlot = Form("%s_all/%s/%s/cc_subtract_%s.png",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
     ccSubtract->SaveAs(SavePlot.Data());
     
     SavePlot = Form("%s_all/%s/%s/cc_normalize_%s.png",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str(), vNameSamples.at(iSample).c_str());
     ccNormalize->SaveAs(SavePlot.Data());
     
     
     somethingHere = true;
    }
    
   }
   
   if (somethingHere == false) {
    ///---- if no plots then remove filder!
    CommandToExec = Form("rm -r %s_all/%s/%s",date.Data(), vNameDC.at(iDC).c_str(), vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
   }
   
  }
 }
 

 
 ///---- summary table
 
 std::cout << " ---> write table <---- " << std::endl;
 
 for (int iDC = 0; iDC < vNameDC.size(); iDC++) {
  std::ofstream myfile_summary[1000];
  bool   myfile_summary_something_happened[1000];
  
  for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {  
   TString nameOutputFile = Form ("%s_all/%s/table_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),vNameSystematics.at(iSystematics).c_str());
   myfile_summary[iSystematics].open (nameOutputFile.Data());
   myfile_summary_something_happened[iSystematics] = false;
   std::cout << std::endl;
   std::cout << "Writing to: " << nameOutputFile << std::endl;
   std::cout << std::endl;
   
   myfile_summary[iSystematics] <<  "\\documentclass[a4paper]{article}" << std::endl;
   myfile_summary[iSystematics] <<  "\\usepackage[landscape]{geometry}" << std::endl;
   myfile_summary[iSystematics] <<  "\\begin{document}" << std::endl;
   myfile_summary[iSystematics] <<  "\\pagestyle{empty}" << std::endl;
   myfile_summary[iSystematics] <<  "\\begin{table}[h!] \\begin{center}" << std::endl;
   myfile_summary[iSystematics] <<  "\\caption{Summary table:: " << ForLatex(vNameSystematics.at(iSystematics)) << "}" << std::endl;
   myfile_summary[iSystematics] <<  "\\begin{tabular}{|l|";
   for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
    myfile_summary[iSystematics] <<  "c|";   
   }
   myfile_summary[iSystematics] <<  "}" << std::endl;
   myfile_summary[iSystematics] <<  " \\hline" << std::endl;
   myfile_summary[iSystematics] <<  "\\footnotesize" << std::endl;
   
   myfile_summary[iSystematics]  <<  std::setw (40) <<  "sample ";
   for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
    myfile_summary[iSystematics] << " & " <<  std::setw (7) << vNameFolders.at(iFolder);   
   }
   myfile_summary[iSystematics] <<  "\\\\";
   myfile_summary[iSystematics] <<  " \\hline" << std::endl;
   
   myfile_summary[iSystematics].precision (3);
   myfile_summary[iSystematics] <<  std::endl;
  }
  
  
  
  
  
  for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {  
   for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {
    myfile_summary[iSystematics] << "  "  <<  std::setw (40) << ForLatex(vNameSamples.at(iSample)) << "";
    std::pair <std::string, std::string> sample_syst (vNameSamples.at(iSample), vNameSystematics.at(iSystematics) );
    for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
     if (
      (m_integral_up.find(vNameFolders.at(iFolder)) != m_integral_up.end())
      &&  
      ((m_integral_up[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_up[vNameFolders.at(iFolder)]).end())
      &&  
      (((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
      &&
      (m_integral.find(vNameFolders.at(iFolder)) != m_integral.end())
      &&  
      ((m_integral[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral[vNameFolders.at(iFolder)]).end())
      &&  
      (((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
      &&
      (m_integral_lo.find(vNameFolders.at(iFolder)) != m_integral_lo.end())
      &&  
      ((m_integral_lo[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_lo[vNameFolders.at(iFolder)]).end())
      &&  
      (((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
     ) {
      
      std::cout << " Read: " << vNameFolders.at(iFolder) << " :: " << vNameDC.at(iDC) << " :: " << vNameSamples.at(iSample) << " :: " << vNameSystematics.at(iSystematics) << std::endl;
      myfile_summary[iSystematics] << " & " << std::setw (7) << ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst];   
      myfile_summary[iSystematics] << "   $  ";
      myfile_summary[iSystematics] << " ^{ " << std::setw (7) << ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] << "}";   
      myfile_summary[iSystematics] << " _{ " << std::setw (7) << ((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] << "}";   
      myfile_summary[iSystematics] << " $   ";
      myfile_summary_something_happened[iSystematics] = true;
      
      //      std::cout << " Folder = " << vNameFolders.at(iFolder);
      //      std::cout << " Sample = " << sample_syst.first;
      //      std::cout << " Syst   = " << sample_syst.second;
      //      std::cout << " Intgrl = " << (m_integral_up[vNameFolders.at(iFolder)])[sample_syst];   
      //      std::cout << std::endl;
     }
     else {
      myfile_summary[iSystematics] << " & " << std::setw (7) << "-";   
     }
    }
    myfile_summary[iSystematics] << " \\\\ ";
    myfile_summary[iSystematics] << std::endl;
   }
   myfile_summary[iSystematics] <<  " \\hline" << std::endl;
  }

  CommandToExec = Form("rm -r %s_all/%s/tables/",date.Data(),vNameDC.at(iDC).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("mkdir %s_all/%s/tables/",date.Data(),vNameDC.at(iDC).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("cp index.php %s_all/%s/tables/",date.Data(),vNameDC.at(iDC).c_str());
  gSystem->Exec(CommandToExec);  
  
  
  for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {  
   myfile_summary[iSystematics] <<  " \\hline" << std::endl;
   
   myfile_summary[iSystematics] <<  " \\hline" << std::endl;
   myfile_summary[iSystematics] <<  "\\end{tabular}" << std::endl;
   myfile_summary[iSystematics] <<  "\\end{center}" << std::endl;
   myfile_summary[iSystematics] <<  "\\end{table}" << std::endl;
   myfile_summary[iSystematics] <<  "\\end{document}" << std::endl;
   
   myfile_summary[iSystematics] << std::endl; 
   myfile_summary[iSystematics].close();  
   
   if (myfile_summary_something_happened[iSystematics]) {
    CommandToExec = Form("pdflatex --output-directory %s_all/%s/tables/ %s_all/%s/table_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("pdfcrop %s_all/%s/tables/table_%s.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("convert -density 200x200 %s_all/%s/tables/table_%s-crop.pdf   %s_all/%s/tables/table_%s-crop.png",date.Data(),vNameDC.at(iDC).c_str(),vNameSystematics.at(iSystematics).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("rm %s_all/%s/tables/table_%s.*",date.Data(),vNameDC.at(iDC).c_str(),vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("rm %s_all/%s/tables/table_%s-crop.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
   }
   else {
    CommandToExec = Form("rm %s_all/%s/table_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),vNameSystematics.at(iSystematics).c_str());
    gSystem->Exec(CommandToExec);  
   }
  }
  

 
 //  typedef std::map < std::pair <std::string, std::string>, double >::iterator it_type;
 //  for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
  //   for(it_type iterator = (m_integral_up[vNameFolders.at(iFolder)]).begin(); iterator != (m_integral_up[vNameFolders.at(iFolder)]).end(); iterator++) { 
   //    std::cout << " Folder = " << vNameFolders.at(iFolder);
   //    std::cout << " Sample = " << iterator->first.first;
   //    std::cout << " Syst   = " << iterator->first.second;
   //    std::cout << " Intgrl = " << iterator->second;
   //    std::cout << std::endl;  
   //   }
   //  }
   
   

   
   ///---- summary_samples table over samples
   
   std::cout << " ---> write table <---- " << std::endl;
   std::ofstream myfile_summary_samples[1000];
   
   for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {  
    TString nameOutputFile = Form ("%s_all/%s/table_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str());
    myfile_summary_samples[iSample].open (nameOutputFile.Data());
    std::cout << std::endl;
    std::cout << "Writing to: " << nameOutputFile << std::endl;
    std::cout << std::endl;
    
    myfile_summary_samples[iSample] <<  "\\documentclass[a4paper]{article}" << std::endl;
    myfile_summary_samples[iSample] <<  "\\usepackage[landscape]{geometry}" << std::endl;
    myfile_summary_samples[iSample] <<  "\\begin{document}" << std::endl;
    myfile_summary_samples[iSample] <<  "\\pagestyle{empty}" << std::endl;
    myfile_summary_samples[iSample] <<  "\\begin{table}[h!] \\begin{center}" << std::endl;
    myfile_summary_samples[iSample] <<  "\\caption{Summary table:: " << ForLatex(vNameSamples.at(iSample)) << "}" << std::endl;
    myfile_summary_samples[iSample] <<  "\\begin{tabular}{|l|";
    for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
     myfile_summary_samples[iSample] <<  "c|";   
    }
    myfile_summary_samples[iSample] <<  "}" << std::endl;
    myfile_summary_samples[iSample] <<  " \\hline" << std::endl;
    myfile_summary_samples[iSample] <<  "\\footnotesize" << std::endl;
    
    myfile_summary_samples[iSample]  <<  std::setw (40) <<  "Nuisance";
    for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
     myfile_summary_samples[iSample] << " & " <<  std::setw (7) << vNameFolders.at(iFolder);   
    }
    myfile_summary_samples[iSample] <<  "\\\\";
    myfile_summary_samples[iSample] <<  " \\hline" << std::endl;
    
    myfile_summary_samples[iSample].precision (3);
    myfile_summary_samples[iSample] <<  std::endl;
   }
   
   
   
   
   
   for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {
    bool isFirstTime = true;
    for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {  
     std::pair <std::string, std::string> sample_syst (vNameSamples.at(iSample), vNameSystematics.at(iSystematics) );
     
     bool istheresomething = false;
     for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
      if (
       (m_integral_up.find(vNameFolders.at(iFolder)) != m_integral_up.end())
       &&  
       ((m_integral_up[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_up[vNameFolders.at(iFolder)]).end())
       &&  
       (((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
       &&
       (m_integral.find(vNameFolders.at(iFolder)) != m_integral.end())
       &&  
       ((m_integral[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral[vNameFolders.at(iFolder)]).end())
       &&  
       (((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
       &&
       (m_integral_lo.find(vNameFolders.at(iFolder)) != m_integral_lo.end())
       &&  
       ((m_integral_lo[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_lo[vNameFolders.at(iFolder)]).end())
       &&  
       (((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
      ) {
       istheresomething = true;
      }
     }

     if (istheresomething) {
      
      if (isFirstTime) {
       isFirstTime = false;
       myfile_summary_samples[iSample] << "  "  <<  std::setw (40) << "events" << "";
       for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
        if (
         (m_integral.find(vNameFolders.at(iFolder)) != m_integral.end())
         &&  
         ((m_integral[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral[vNameFolders.at(iFolder)]).end())
         &&  
         (((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
        ) {
         
         std::cout << "Samples:  Read: " << vNameFolders.at(iFolder) << " :: " << vNameDC.at(iDC) << " :: " << vNameSamples.at(iSample) << " :: " << vNameSystematics.at(iSystematics) << std::endl;
         myfile_summary_samples[iSample] << " & " << std::setw (7*2+19) << ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst];   
        }
        else {
         myfile_summary_samples[iSample] << " & " << std::setw (7) << "-";   
        }
       }
       myfile_summary_samples[iSample] << " \\\\ ";
       myfile_summary_samples[iSample] <<  " \\hline " << " \\hline" << std::endl;
       myfile_summary_samples[iSample] << std::endl;
      }
      
      myfile_summary_samples[iSample] << "  "  <<  std::setw (40) << ForLatex(vNameSystematics.at(iSystematics)) << "";
      for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
       if (
        (m_integral_up.find(vNameFolders.at(iFolder)) != m_integral_up.end())
        &&  
        ((m_integral_up[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_up[vNameFolders.at(iFolder)]).end())
        &&  
        (((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
        &&
        (m_integral.find(vNameFolders.at(iFolder)) != m_integral.end())
        &&  
        ((m_integral[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral[vNameFolders.at(iFolder)]).end())
        &&  
        (((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
        &&
        (m_integral_lo.find(vNameFolders.at(iFolder)) != m_integral_lo.end())
        &&  
        ((m_integral_lo[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_lo[vNameFolders.at(iFolder)]).end())
        &&  
        (((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
       ) {
        
        std::cout << "Samples:  Read: " << vNameFolders.at(iFolder) << " :: " << vNameDC.at(iDC) << " :: " << vNameSamples.at(iSample) << " :: " << vNameSystematics.at(iSystematics) << std::endl;
//         myfile_summary_samples[iSample] << " & " << std::setw (7) << ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst];   
//         myfile_summary_samples[iSample] << "   $  ";
//         myfile_summary_samples[iSample] << " ^{ " << std::setw (7) << ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] << "}";   
//         myfile_summary_samples[iSample] << " _{ " << std::setw (7) << ((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] << "}";   
//         myfile_summary_samples[iSample] << " $   ";

        myfile_summary_samples[iSample] << " &  ";
        myfile_summary_samples[iSample] << " [ " << std::setw (7) << ((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] << "";   
        myfile_summary_samples[iSample] << " , "   << std::setw (7) << ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] << "]";   
        if (((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst]) {
         myfile_summary[iSample].precision (2);
         myfile_summary_samples[iSample] << " :: ";
         myfile_summary_samples[iSample] << "[ " << std::setw (7) << -(((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] * 100. << "\\%";   
         myfile_summary_samples[iSample] << " , "   << std::setw (7) << (((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst])     /((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] * 100. << "\\%]";   
         myfile_summary[iSample].precision (3);
        }        
       }
       else {
        myfile_summary_samples[iSample] << " & " << std::setw (7) << "-";   
       }
      }
      myfile_summary_samples[iSample] << " \\\\ ";
      myfile_summary_samples[iSample] << std::endl;
     }
    }
    myfile_summary_samples[iSample] <<  " \\hline" << std::endl;
   }
   
   
   CommandToExec = Form("rm -r %s_all/%s/tables-samples/",date.Data(),vNameDC.at(iDC).c_str());
   gSystem->Exec(CommandToExec);  
   
   CommandToExec = Form("mkdir %s_all/%s/tables-samples/",date.Data(),vNameDC.at(iDC).c_str());
   gSystem->Exec(CommandToExec);  
   
   CommandToExec = Form("cp index.php %s_all/%s/tables-samples/",date.Data(),vNameDC.at(iDC).c_str());
   gSystem->Exec(CommandToExec);  
   
   
   for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {
    myfile_summary_samples[iSample] <<  " \\hline" << std::endl;
    
    myfile_summary_samples[iSample] <<  " \\hline" << std::endl;
    myfile_summary_samples[iSample] <<  "\\end{tabular}" << std::endl;
    myfile_summary_samples[iSample] <<  "\\end{center}" << std::endl;
    myfile_summary_samples[iSample] <<  "\\end{table}" << std::endl;
    myfile_summary_samples[iSample] <<  "\\end{document}" << std::endl;
    
    myfile_summary_samples[iSample] << std::endl; 
    myfile_summary_samples[iSample].close(); 
    
    CommandToExec = Form("pdflatex --output-directory %s_all/%s/tables-samples/ %s_all/%s/table_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("pdfcrop %s_all/%s/tables-samples/table_%s.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("convert -density 200x200 %s_all/%s/tables-samples/table_%s-crop.pdf   %s_all/%s/tables-samples/table_%s-crop.png",date.Data(),vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("rm %s_all/%s/tables-samples/table_%s.*",date.Data(),vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str());
    gSystem->Exec(CommandToExec);  
    
    CommandToExec = Form("rm %s_all/%s/tables-samples/table_%s-crop.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameSamples.at(iSample).c_str());
    gSystem->Exec(CommandToExec);  
    
   } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 ///---- summary_samples_systematics all in one
 ///---- with errors symmetrized +/- 
 ///---- with errors expressed in %
 ///----      
 ///----                 | samples | | | | | |
 ///----   systematics   |   10%  |  5% | - 
 ///----                 |    -   |  5% | 1% 
 ///----                 |   20%  |  -  | - 
 ///----                 |      
 ///----      
 
 
 
 ///---- to compare before and after ----
 
 std::cout << " ---> write table <---- " << std::endl;
 std::ofstream myfile_summary_global[1000];
 
 for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
  TString nameOutputFile = Form ("%s_all/%s/table_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  myfile_summary_global[iFolder].open (nameOutputFile.Data());
  std::cout << std::endl;
  std::cout << "Writing to: " << nameOutputFile << std::endl;
  std::cout << std::endl;
  
  myfile_summary_global[iFolder] <<  "\\documentclass[a4paper]{article}" << std::endl;
  myfile_summary_global[iFolder] <<  "\\usepackage[landscape]{geometry}" << std::endl;
  myfile_summary_global[iFolder] <<  "\\begin{document}" << std::endl;
  myfile_summary_global[iFolder] <<  "\\pagestyle{empty}" << std::endl;
  myfile_summary_global[iFolder] <<  "\\begin{table}[h!] \\begin{center}" << std::endl;
  myfile_summary_global[iFolder] <<  "\\caption{Summary table:: " << ForLatex(vNameFolders.at(iFolder)) << "}" << std::endl;
  myfile_summary_global[iFolder] <<  "\\begin{tabular}{|l|";
  
  for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {  
   myfile_summary_global[iFolder] <<  "c|";   
  }
  myfile_summary_global[iFolder] <<  "}" << std::endl;
  myfile_summary_global[iFolder] <<  " \\hline" << std::endl;
  myfile_summary_global[iFolder] <<  "\\footnotesize" << std::endl;
  
  myfile_summary_global[iFolder]  <<  std::setw (40) <<  "Nuisance";
  for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {  
   myfile_summary_global[iFolder] << " & " <<  std::setw (7) << vNameSamples.at(iSample);   
  }
  myfile_summary_global[iFolder] <<  "\\\\";
  myfile_summary_global[iFolder] <<  " \\hline" << std::endl;
  
  myfile_summary_global[iFolder].precision (2);
  myfile_summary_global[iFolder] <<  std::endl;
  
  bool isFirstTime = true;
  for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {  
   
   myfile_summary_global[iFolder] << "  "  <<  std::setw (40) << ForLatex(vNameSystematics.at(iSystematics)) << "";
   
   for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {  
    std::pair <std::string, std::string> sample_syst (vNameSamples.at(iSample), vNameSystematics.at(iSystematics) );
    if (
     (m_integral_up.find(vNameFolders.at(iFolder)) != m_integral_up.end())
     &&  
     ((m_integral_up[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_up[vNameFolders.at(iFolder)]).end())
     &&  
     (((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
     &&
     (m_integral.find(vNameFolders.at(iFolder)) != m_integral.end())
     &&  
     ((m_integral[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral[vNameFolders.at(iFolder)]).end())
     &&  
     (((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
     &&
     (m_integral_lo.find(vNameFolders.at(iFolder)) != m_integral_lo.end())
     &&  
     ((m_integral_lo[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_lo[vNameFolders.at(iFolder)]).end())
     &&  
     (((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
    ) {
     
     if (((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst]) {
      myfile_summary[iSample].precision (2);
      myfile_summary_global[iFolder] << " & " << std::setw (7) << fabs(((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] * 100. / 2. << "\\% ";   
//       myfile_summary_global[iFolder] << " & [ " << std::setw (7) << -(((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] * 100. << "\\%";   
//       myfile_summary_global[iFolder] << " , "   << std::setw (7) << (((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst])     /((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] * 100. << "\\%]";   
//       myfile_summary[iSample].precision (3);
     }        
    }
    else {
     myfile_summary_global[iFolder] << " & " << std::setw (7) << "-";   
    }
   }
   myfile_summary_global[iFolder] << " \\\\ ";
   myfile_summary_global[iFolder] << std::endl;
  }
  myfile_summary_global[iFolder] <<  " \\hline" << std::endl;
 }
 
 
 CommandToExec = Form("rm -r %s_all/%s/tables-syst-samples/",date.Data(),vNameDC.at(iDC).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("mkdir %s_all/%s/tables-syst-samples/",date.Data(),vNameDC.at(iDC).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("cp index.php %s_all/%s/tables-syst-samples/",date.Data(),vNameDC.at(iDC).c_str());
 gSystem->Exec(CommandToExec);  
 
 
 for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {
//   myfile_summary_global[iFolder] <<  " \\hline" << std::endl;
//   myfile_summary_global[iFolder] <<  " \\hline" << std::endl;
  myfile_summary_global[iFolder] <<  "\\end{tabular}" << std::endl;
  myfile_summary_global[iFolder] <<  "\\end{center}" << std::endl;
  myfile_summary_global[iFolder] <<  "\\end{table}" << std::endl;
  myfile_summary_global[iFolder] <<  "\\end{document}" << std::endl;
  
  myfile_summary_global[iFolder] << std::endl; 
  myfile_summary_global[iFolder].close(); 
  
  CommandToExec = Form("pdflatex --output-directory %s_all/%s/tables-syst-samples/ %s_all/%s/table_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("pdfcrop %s_all/%s/tables-syst-samples/table_%s.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("convert -density 200x200 %s_all/%s/tables-syst-samples/table_%s-crop.pdf   %s_all/%s/tables-syst-samples/table_%s-crop.png",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("rm %s_all/%s/tables-syst-samples/table_%s.*",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  

  
  CommandToExec = Form("mv %s_all/%s/table_%s.tex %s_all/%s/tables-syst-samples/",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("rm %s_all/%s/tables-syst-samples/table_%s-crop.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  gSystem->Exec(CommandToExec);  
  
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 ///---- summary_samples_systematics all in one
 ///---- with errors symmetrized +/- 
 ///---- with errors expressed in %
 ///----      to look for pull plot of the errors
 ///----      variation of the error between prefit and postfit (with signal)
 ///----      
 ///----                 | samples | | | | | |
 ///----   systematics   |   10%  |  5% | - 
 ///----                 |    -   |  5% | 1% 
 ///----                 |   20%  |  -  | - 
 ///----                 |      
 ///----      
 
 
 
 ///---- to compare before and after ----
 
 std::cout << " ---> write table <---- " << std::endl;
 std::ofstream myfile_summary_global_pull      [1000];
 std::ofstream myfile_summary_global_pull_plot [1000];
 std::ofstream myfile_summary_global_all       [1000];
 std::ofstream myfile_summary_global_all_plot  [1000];
 
 for (int iFolder = 1; iFolder < vNameFolders.size(); iFolder++) { ///---- skip number 1, because it is "init"
  TString nameOutputFile = Form ("%s_all/%s/table_Compare_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  myfile_summary_global_all[iFolder].open (nameOutputFile.Data());
  TString nameOutputFilePlot = Form ("%s_all/%s/table_Compare_%s.cxx",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  myfile_summary_global_all_plot[iFolder].open (nameOutputFilePlot.Data());
  TString nameOutputFilePull = Form ("%s_all/%s/table_pull_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  myfile_summary_global_pull[iFolder].open (nameOutputFilePull.Data()); 
  TString nameOutputFilePullPlot = Form ("%s_all/%s/table_pull_%s.cxx",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
  myfile_summary_global_pull_plot[iFolder].open (nameOutputFilePullPlot.Data()); 
  
  std::cout << std::endl;
  std::cout << "Writing to: " << nameOutputFile << std::endl;
  std::cout << std::endl;
  
  myfile_summary_global_pull_plot[iFolder] <<  "{" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << std::endl;
  
  myfile_summary_global_pull_plot[iFolder] << "TGaxis::SetMaxDigits(3); " << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle->SetPadLeftMargin  (0.45);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle->SetPadRightMargin (0.12);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle->SetOptTitle(0);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle->SetOptStat       (   0);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle->SetStatBorderSize(   0);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle->SetStatColor     (  10);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle->SetStatFont      (  42);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle->SetStatX         (0.94);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle->SetStatY         (0.91);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << "gStyle -> cd(); " << std::endl;
  
  myfile_summary_global_pull_plot[iFolder] << "TCanvas ccpull (\"ccpull\",\"\",450,700);" << std::endl;
  myfile_summary_global_pull_plot[iFolder] << std::endl;
  
  myfile_summary_global_pull_plot[iFolder] << "TH1F histo (\"histo\",\"\"," <<
  vNameSamples.size()-1   << ",0," << vNameSamples.size()-1     << "); " << std::endl;
  
  
  
  
  
  myfile_summary_global_all_plot[iFolder] <<  "{" << std::endl;
  myfile_summary_global_all_plot[iFolder] << std::endl;
  
  myfile_summary_global_all_plot[iFolder] << "TGaxis::SetMaxDigits(3); " << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle->SetPadLeftMargin  (0.45);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle->SetPadRightMargin (0.12);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle->SetOptTitle(0);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle->SetOptStat       (   0);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle->SetStatBorderSize(   0);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle->SetStatColor     (  10);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle->SetStatFont      (  42);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle->SetStatX         (0.94);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle->SetStatY         (0.91);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << "gStyle -> cd(); " << std::endl;
  
  myfile_summary_global_all_plot[iFolder] << "TCanvas cc (\"cc\",\"\",450,700);" << std::endl;
  myfile_summary_global_all_plot[iFolder] << std::endl;
  
  myfile_summary_global_all_plot[iFolder] << "TH2F histo (\"histo\",\"\"," <<
        vNameSamples.size()-1   << ",0," << vNameSamples.size()-1     << ", " <<
        vNameSystematics.size() << ",0," << vNameSystematics.size() << ");" << std::endl;
  
  myfile_summary_global_all[iFolder] <<  "\\documentclass[a4paper]{article}" << std::endl;
  myfile_summary_global_all[iFolder] <<  "\\usepackage[landscape]{geometry}" << std::endl;
  myfile_summary_global_all[iFolder] <<  "\\begin{document}" << std::endl;
  myfile_summary_global_all[iFolder] <<  "\\pagestyle{empty}" << std::endl;
  myfile_summary_global_all[iFolder] <<  "\\begin{table}[h!] \\begin{center}" << std::endl;
  myfile_summary_global_all[iFolder] <<  "\\caption{Summary table:: pull comparison " << ForLatex(vNameFolders.at(iFolder)) << "}" << std::endl;
  myfile_summary_global_all[iFolder] <<  "\\begin{tabular}{|l|";
  
  myfile_summary_global_pull[iFolder] <<  "\\documentclass[a4paper]{article}" << std::endl;
  myfile_summary_global_pull[iFolder] <<  "\\usepackage[landscape]{geometry}" << std::endl;
  myfile_summary_global_pull[iFolder] <<  "\\begin{document}" << std::endl;
  myfile_summary_global_pull[iFolder] <<  "\\pagestyle{empty}" << std::endl;
  myfile_summary_global_pull[iFolder] <<  "\\begin{table}[h!] \\begin{center}" << std::endl;
  myfile_summary_global_pull[iFolder] <<  "\\caption{Summary table:: pull " << ForLatex(vNameFolders.at(iFolder)) << "}" << std::endl;
  myfile_summary_global_pull[iFolder] <<  "\\begin{tabular}{|l|c|}";
  myfile_summary_global_pull[iFolder] <<  " \\hline" << std::endl;
  myfile_summary_global_pull[iFolder] <<  "\\footnotesize" << std::endl;
  
  myfile_summary_global_pull[iFolder].precision (2);
  
  myfile_summary_global_pull[iFolder] <<  std::endl;
  myfile_summary_global_pull[iFolder] << "  "  <<  std::setw (20) << "sample" << " & ";
  myfile_summary_global_pull[iFolder] << "  "  <<  std::setw (20) << "number of $\\sigma$" << " \\\\" << std::endl;
  myfile_summary_global_pull[iFolder] <<  std::endl;
  myfile_summary_global_pull[iFolder] <<  " \\hline" << std::endl;
  
  
  
  for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {  
   myfile_summary_global_all[iFolder] <<  "c|";   
  }
  myfile_summary_global_all[iFolder] <<  "}" << std::endl;
  myfile_summary_global_all[iFolder] <<  " \\hline" << std::endl;
  myfile_summary_global_all[iFolder] <<  "\\footnotesize" << std::endl;
  
  myfile_summary_global_all[iFolder]  <<  std::setw (40) <<  "Nuisance";
  for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {  
   myfile_summary_global_all[iFolder] << " & " <<  std::setw (7) << vNameSamples.at(iSample);   
  }
  myfile_summary_global_all[iFolder] <<  "\\\\";
  myfile_summary_global_all[iFolder] <<  " \\hline" << std::endl;
  
  myfile_summary_global_all[iFolder].precision (2);
  myfile_summary_global_all[iFolder] <<  std::endl;
  
  bool isFirstTime = true;
  for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {  
   myfile_summary_global_all[iFolder] << "  "  <<  std::setw (40) << ForLatex(vNameSystematics.at(iSystematics)) << "";
   
   for (int iSample = 0; iSample < vNameSamples.size(); iSample++) {  
    
    if (iSystematics == 0) {///---- only "all" ----
     myfile_summary_global_pull[iFolder] << "  "  <<  std::setw (20) << ForLatex(vNameSamples.at(iSample)) << " ";
    }
   
    
    
    std::pair <std::string, std::string> sample_syst (vNameSamples.at(iSample), vNameSystematics.at(iSystematics) );
    if (
     (m_integral_up.find(vNameFolders.at(iFolder)) != m_integral_up.end())
     &&  
     ((m_integral_up[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_up[vNameFolders.at(iFolder)]).end())
     &&  
     (((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
     &&
     (m_integral.find(vNameFolders.at(iFolder)) != m_integral.end())
     &&  
     ((m_integral[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral[vNameFolders.at(iFolder)]).end())
     &&  
     (((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())
     &&
     (m_integral_lo.find(vNameFolders.at(iFolder)) != m_integral_lo.end())
     &&  
     ((m_integral_lo[vNameFolders.at(iFolder)]).find(vNameDC.at(iDC)) != (m_integral_lo[vNameFolders.at(iFolder)]).end())
     &&  
     (((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)]).end())

     &&
     
     (m_integral_up.find(vNameFolders.at(0)) != m_integral_up.end())
     &&  
     ((m_integral_up[vNameFolders.at(0)]).find(vNameDC.at(iDC)) != (m_integral_up[vNameFolders.at(0)]).end())
     &&  
     (((m_integral_up[vNameFolders.at(0)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_up[vNameFolders.at(0)])[vNameDC.at(iDC)]).end())
     &&
     (m_integral.find(vNameFolders.at(0)) != m_integral.end())
     &&  
     ((m_integral[vNameFolders.at(0)]).find(vNameDC.at(iDC)) != (m_integral[vNameFolders.at(0)]).end())
     &&  
     (((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)]).end())
     &&
     (m_integral_lo.find(vNameFolders.at(0)) != m_integral_lo.end())
     &&  
     ((m_integral_lo[vNameFolders.at(0)]).find(vNameDC.at(iDC)) != (m_integral_lo[vNameFolders.at(0)]).end())
     &&  
     (((m_integral_lo[vNameFolders.at(0)])[vNameDC.at(iDC)]).find(sample_syst) != ((m_integral_lo[vNameFolders.at(0)])[vNameDC.at(iDC)]).end())
     
    ) {
     
     if (
      ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] != 0
      &&
      ((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] != 0
      &&
      (fabs(((m_integral_lo[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_up[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst]) != 0
     ) {
      myfile_summary[iSample].precision (2);

      //---- (error - error_init) / error_init
      myfile_summary_global_all[iFolder] << " & " << std::setw (7) << 
      (
       (fabs(((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst])
      - 
       (fabs(((m_integral_lo[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_up[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])
      )
      /
      (
       (fabs(((m_integral_lo[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_up[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])
      ) 
      << "\\% ";   
  
      if (iSystematics == 0) {///---- only "all" ----
       //---- (postfit - init) / error_init
       double value =  (
        ((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] 
        - 
        ((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] 
       ) 
       /
       (
        fabs( ((m_integral_up[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_lo[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] ) / 2.
       ); 
       
       myfile_summary_global_pull[iFolder] << " & " << std::setw (7) << value;
       myfile_summary_global_pull[iFolder] << " \\\\ ";
       myfile_summary_global_pull[iFolder] << std::endl;
       
       myfile_summary_global_pull_plot[iFolder] << " histo.Fill(";
       myfile_summary_global_pull_plot[iFolder] << iSample-1; //---- -1 perchè tolgo "model"
       myfile_summary_global_pull_plot[iFolder] << ",";
       myfile_summary_global_pull_plot[iFolder] << value;
       myfile_summary_global_pull_plot[iFolder] << ");" << std::endl; 
       
      }
      
      
      if ((iSample != 0) && ((fabs(((m_integral_lo[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_up[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])) != 0) {
       //---- (error - error_init) / error_init
       
       double value = (
        (fabs(((m_integral_lo[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_up[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(iFolder)])[vNameDC.at(iDC)])[sample_syst])
        - 
        (fabs(((m_integral_lo[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_up[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])
       )
       /
       (
        (fabs(((m_integral_lo[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst] - ((m_integral_up[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])/((m_integral[vNameFolders.at(0)])[vNameDC.at(iDC)])[sample_syst])
       );
       
       myfile_summary_global_all_plot[iFolder] << " histo.Fill(";
       myfile_summary_global_all_plot[iFolder] << iSystematics;
       myfile_summary_global_all_plot[iFolder] << ",";
       myfile_summary_global_all_plot[iFolder] << iSample-1; //---- -1 perchè tolgo "model"
       myfile_summary_global_all_plot[iFolder] << ",";
       myfile_summary_global_all_plot[iFolder] << value;
       myfile_summary_global_all_plot[iFolder] << ");" << std::endl; 

       
      }
      
      
     }        
    }
    else {
     myfile_summary_global_all[iFolder]  << " & " << std::setw (7) << "-";   
     if (iSystematics == 0) {///---- only "all" ----
      myfile_summary_global_pull[iFolder] << " & " << std::setw (7) << "-";   
      myfile_summary_global_pull[iFolder] << " \\\\ ";
      myfile_summary_global_pull[iFolder] << std::endl;
     }
    }
  
   }
   
   
   myfile_summary_global_all[iFolder] << " \\\\ ";
   myfile_summary_global_all[iFolder] << std::endl;
  }
  myfile_summary_global_all[iFolder] <<  " \\hline" << std::endl;
  
  
  
  myfile_summary_global_pull_plot[iFolder] << std::endl;
  for (int iSample = 1; iSample < vNameSamples.size(); iSample++) {      
   myfile_summary_global_pull_plot[iFolder] << " histo.GetXaxis()->SetBinLabel(";
   myfile_summary_global_pull_plot[iFolder] << iSample;
   myfile_summary_global_pull_plot[iFolder] << ",\"";
   myfile_summary_global_pull_plot[iFolder] << ForLatex(vNameSamples.at(iSample));
   myfile_summary_global_pull_plot[iFolder] << "\");";
   myfile_summary_global_pull_plot[iFolder] << std::endl;
  }
  myfile_summary_global_pull_plot[iFolder] << " histo.SetMarkerSize(2);";
  myfile_summary_global_pull_plot[iFolder] << " histo.SetMarkerStyle(20);";
  myfile_summary_global_pull_plot[iFolder] << " histo.Draw(\"P\");";
  myfile_summary_global_pull_plot[iFolder] << std::endl;
  myfile_summary_global_pull_plot[iFolder] << std::endl; 
  myfile_summary_global_pull_plot[iFolder] <<  "}" << std::endl;
  myfile_summary_global_pull_plot[iFolder].close(); 
  
  
  
  

  for (int iSample = 1; iSample < vNameSamples.size(); iSample++) {      
   myfile_summary_global_all_plot[iFolder] << " histo.GetXaxis()->SetBinLabel(";
   myfile_summary_global_all_plot[iFolder] << iSample;
   myfile_summary_global_all_plot[iFolder] << ",\"";
   myfile_summary_global_all_plot[iFolder] << ForLatex(vNameSamples.at(iSample));
   myfile_summary_global_all_plot[iFolder] << "\");";
   myfile_summary_global_all_plot[iFolder] << std::endl; 
  }
  
  for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {  
   myfile_summary_global_all_plot[iFolder] << " histo.GetYaxis()->SetBinLabel(";
   myfile_summary_global_all_plot[iFolder] << iSystematics+1;
   myfile_summary_global_all_plot[iFolder] << ",\"";
   myfile_summary_global_all_plot[iFolder] << ForLatex(vNameSystematics.at(iSystematics));
   myfile_summary_global_all_plot[iFolder] << "\");";
   myfile_summary_global_all_plot[iFolder] << std::endl;
  }
  
  myfile_summary_global_all_plot[iFolder] << " histo.Draw(\"colz\");";
  myfile_summary_global_all_plot[iFolder] << std::endl;
  myfile_summary_global_all_plot[iFolder] << std::endl; 
  myfile_summary_global_all_plot[iFolder] <<  "}" << std::endl;
  myfile_summary_global_all_plot[iFolder].close(); 
  
 }
 
 
 for (int iFolder = 1; iFolder < vNameFolders.size(); iFolder++) { ///---- skip number 1, because it is "init"
  //   myfile_summary_global_all[iFolder] <<  " \\hline" << std::endl;
 //   myfile_summary_global_all[iFolder] <<  " \\hline" << std::endl;
 myfile_summary_global_all[iFolder] <<  "\\end{tabular}" << std::endl;
 myfile_summary_global_all[iFolder] <<  "\\end{center}" << std::endl;
 myfile_summary_global_all[iFolder] <<  "\\end{table}" << std::endl;
 myfile_summary_global_all[iFolder] <<  "\\end{document}" << std::endl;
 
 myfile_summary_global_all[iFolder] << std::endl; 
 myfile_summary_global_all[iFolder].close(); 

 
 
 myfile_summary_global_pull[iFolder] <<  "\\end{tabular}" << std::endl;
 myfile_summary_global_pull[iFolder] <<  "\\end{center}" << std::endl;
 myfile_summary_global_pull[iFolder] <<  "\\end{table}" << std::endl;
 myfile_summary_global_pull[iFolder] <<  "\\end{document}" << std::endl;
 
 myfile_summary_global_pull[iFolder] << std::endl; 
 myfile_summary_global_pull[iFolder].close(); 
 
 
 
 
 CommandToExec = Form("pdflatex --output-directory %s_all/%s/tables-syst-samples/ %s_all/%s/table_Compare_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("pdfcrop %s_all/%s/tables-syst-samples/table_Compare_%s.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("convert -density 200x200 %s_all/%s/tables-syst-samples/table_Compare_%s-crop.pdf   %s_all/%s/tables-syst-samples/table_Compare_%s-crop.png",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("rm %s_all/%s/tables-syst-samples/table_Compare_%s.*",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 
 CommandToExec = Form("mv %s_all/%s/table_Compare_%s.tex %s_all/%s/tables-syst-samples/",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("rm %s_all/%s/tables-syst-samples/table_Compare_%s-crop.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 
 
 
 CommandToExec = Form("pdflatex --output-directory %s_all/%s/tables-syst-samples/ %s_all/%s/table_pull_%s.tex",date.Data(),vNameDC.at(iDC).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("pdfcrop %s_all/%s/tables-syst-samples/table_pull_%s.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("convert -density 200x200 %s_all/%s/tables-syst-samples/table_pull_%s-crop.pdf   %s_all/%s/tables-syst-samples/table_pull_%s-crop.png",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("rm %s_all/%s/tables-syst-samples/table_pull_%s.*",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 
 CommandToExec = Form("mv %s_all/%s/table_pull_%s.tex %s_all/%s/tables-syst-samples/",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str(),date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("rm %s_all/%s/tables-syst-samples/table_pull_%s-crop.pdf",date.Data(),vNameDC.at(iDC).c_str(),vNameFolders.at(iFolder).c_str());
 gSystem->Exec(CommandToExec);
 
 } 
 
 
 
 }    
 
 
 
 
 ///---- pull plot for systematics ----
 
 ///----       folder                 systematics              value      error
//  std::map < std::string,   std::map < std::string , std::pair <double , double > > > vNuisances;  ///---- nuisances
 
 for (int iFolder = 0; iFolder < vNameFolders.size(); iFolder++) {  
  TString nameList = Form ("%s/info/parameters",vNameFolders.at(iFolder).c_str());
  RooArgList * list = ((RooArgList*) (f0->Get(nameList.Data())) );
  
  for (int iSystematics = 0; iSystematics < list->getSize(); iSystematics++) {
   RooRealVar* tempVar = (RooRealVar*) (list->at(iSystematics));
   
   double value    = tempVar->getVal();
   double errvalue = tempVar->getError();
   
   std::pair <double, double> value_and_error (value, errvalue) ;
   std::string nameSyst = tempVar->GetName();
//    std::cout << " nameSyst[" << iSystematics << "," << nameSyst << "] = " << value << " +/- " << errvalue << std::endl;
   (vNuisances[vNameFolders.at(iFolder)])[nameSyst] = value_and_error;
  }
 }
 
 std::ofstream myfile_summary_global_pull_systematics      [1000];
 std::ofstream myfile_summary_global_pull_systematics_plot [1000];

 CommandToExec = Form("rm -r %s_all/nuisances",date.Data());
 gSystem->Exec(CommandToExec);  
 
 CommandToExec = Form("mkdir %s_all/nuisances",date.Data());
 gSystem->Exec(CommandToExec);  
 
 for (int iFolder = 1; iFolder < vNameFolders.size(); iFolder++) { ///---- skip number 1, because it is "init"
  
  TString nameOutputFile_pull_systematics_plot = Form ("%s_all/nuisances/Nuisance_pull_%s.cxx",date.Data(),vNameFolders.at(iFolder).c_str());
  myfile_summary_global_pull_systematics_plot[iFolder].open (nameOutputFile_pull_systematics_plot.Data());
  
  
  myfile_summary_global_pull_systematics_plot[iFolder] <<  "{" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << std::endl;
  
  myfile_summary_global_pull_systematics_plot[iFolder] << "TGaxis::SetMaxDigits(3); " << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetPadBottomMargin(0.50);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetPadLeftMargin  (0.10);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetPadRightMargin (0.01);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetOptTitle(0);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetOptStat       (   0);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetStatBorderSize(   0);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetStatColor     (  10);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetStatFont      (  42);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetStatX         (0.94);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle->SetStatY         (0.91);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << "gStyle -> cd(); " << std::endl;
  
  myfile_summary_global_pull_systematics_plot[iFolder] << "TCanvas cc (\"cc" << vNameFolders.at(iFolder) << "\",\"\"," << 18*vNameSystematics.size() << ",600);" << std::endl;
  myfile_summary_global_pull_systematics_plot[iFolder] << std::endl;
  
  int START = 2;
  myfile_summary_global_pull_systematics_plot[iFolder] << "TH1F histo (\"histo\",\"\"," <<
  vNameSystematics.size()-START << ",0," << vNameSystematics.size()-START << ");" << std::endl;
  
//   for (int iSystematics = 0; iSystematics < vNameSystematics.size(); iSystematics++) {  
  for (int iSystematics = START; iSystematics < vNameSystematics.size(); iSystematics++) { //--> first two are "all" and "r"
    
    double value    = ((vNuisances[vNameFolders.at(iFolder)])[vNameSystematics.at(iSystematics)]).first;
    double errvalue = ((vNuisances[vNameFolders.at(iFolder)])[vNameSystematics.at(iSystematics)]).second;
    
    
    if (((vNuisances[vNameFolders.at(0)])[vNameSystematics.at(iSystematics)]).first == 0) {
     myfile_summary_global_pull_systematics_plot[iFolder] <<  " histo.SetBinContent(";
     myfile_summary_global_pull_systematics_plot[iFolder] <<  iSystematics+1-START;
     myfile_summary_global_pull_systematics_plot[iFolder] << ",";
     myfile_summary_global_pull_systematics_plot[iFolder] << value;
     myfile_summary_global_pull_systematics_plot[iFolder] << ");" << std::endl; 
     myfile_summary_global_pull_systematics_plot[iFolder] <<  " histo.SetBinError(";
     myfile_summary_global_pull_systematics_plot[iFolder] <<  iSystematics+1-START;
     myfile_summary_global_pull_systematics_plot[iFolder] << ",";
     myfile_summary_global_pull_systematics_plot[iFolder] << errvalue;
     myfile_summary_global_pull_systematics_plot[iFolder] << ");" << std::endl; 
    }
    else {
     std::cout << " iSystematics = " << iSystematics << " :: not zero?" << std::endl;

//      e.g.
//      nameSyst[6,CMS_8TeV_hww_DYee_sf_vh2j_sf_vh2j_stat] = 56 +/- 0    
//      nameSyst[6,CMS_8TeV_hww_DYee_sf_vh2j_sf_vh2j_stat] = 54.6283 +/- 7.2977
//      nameSyst[6,CMS_8TeV_hww_DYee_sf_vh2j_sf_vh2j_stat] = 54.8437 +/- 7.32189
//      
//      value    = (54.6283-56)/56 = 54.6283/56 -1
//      errvalue = (7.2977)/sqrt(56)
     
     myfile_summary_global_pull_systematics_plot[iFolder] <<  " histo.SetBinContent(";
     myfile_summary_global_pull_systematics_plot[iFolder] <<  iSystematics+1-START;
     myfile_summary_global_pull_systematics_plot[iFolder] << ",";
     myfile_summary_global_pull_systematics_plot[iFolder] << value / ((vNuisances[vNameFolders.at(0)])[vNameSystematics.at(iSystematics)]).first -1 ;
     myfile_summary_global_pull_systematics_plot[iFolder] << ");" << std::endl; 
     myfile_summary_global_pull_systematics_plot[iFolder] <<  " histo.SetBinError(";
     myfile_summary_global_pull_systematics_plot[iFolder] <<  iSystematics+1-START;
     myfile_summary_global_pull_systematics_plot[iFolder] << ",";
     myfile_summary_global_pull_systematics_plot[iFolder] << errvalue / sqrt(((vNuisances[vNameFolders.at(0)])[vNameSystematics.at(iSystematics)]).first);
     myfile_summary_global_pull_systematics_plot[iFolder] << ");" << std::endl; 
     
//      std::cout << " errvalue    = "  << errvalue;
//      std::cout << " errvalue[0] = "  << ((vNuisances[vNameFolders.at(0)])[vNameSystematics.at(iSystematics)]).second;
//      std::cout << std::endl;
//      std::cout << " value    = "  << value;
//      std::cout << " value[0] = "  << ((vNuisances[vNameFolders.at(0)])[vNameSystematics.at(iSystematics)]).first;
//      std::cout << std::endl;
     
    }
   }
   
   
   for (int iSystematics = START; iSystematics < vNameSystematics.size(); iSystematics++) {  
    myfile_summary_global_pull_systematics_plot[iFolder] << " histo.GetXaxis()->SetBinLabel(";
    myfile_summary_global_pull_systematics_plot[iFolder] << iSystematics+1-START;
    myfile_summary_global_pull_systematics_plot[iFolder] << ",\"";
    myfile_summary_global_pull_systematics_plot[iFolder] << ForLatex(vNameSystematics.at(iSystematics));
    myfile_summary_global_pull_systematics_plot[iFolder] << "\");";
    myfile_summary_global_pull_systematics_plot[iFolder] << std::endl;
   }
   
   myfile_summary_global_pull_systematics_plot[iFolder] << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " gPad->SetGrid();" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo.GetYaxis()->SetRangeUser(-2,2);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo.GetYaxis()->SetTitle(\"#sigma\");" << std::endl;
   
   
   myfile_summary_global_pull_systematics_plot[iFolder] << " TH1F histo2 = (TH1F) histo.Clone(\"band\");" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo2.GetYaxis()->SetLabelFont(42);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo2.GetXaxis()->SetLabelFont(42);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo2.GetXaxis()->SetLabelSize(0.035);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo2.GetYaxis()->SetTitle(\"#sigma\");" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " for (int iBin = 0 ; iBin < histo2->GetNbinsX() ; iBin++) {" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << "  histo2->SetBinError (iBin+1, 1.);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " }" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo2.SetFillColor (kOrange);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo2.SetFillStyle (3001);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo2.Draw(\"e2\");" << std::endl;
   
   
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo.SetMarkerSize(1);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo.SetMarkerStyle(20);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo.SetLineWidth(2);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " histo.Draw(\"EPsame\");" << std::endl;
   
   myfile_summary_global_pull_systematics_plot[iFolder] << " // TImage *img = TImage::Create();" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // TPad* pad = cc->cd();" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // img->FromPad(pad);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // img->Flip(-90);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // cc->cd();" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // img->Draw(\"NXZ\");" << std::endl;
   
   myfile_summary_global_pull_systematics_plot[iFolder] << " // TF1 line1 (\"line1\",\"1\",0," << vNameSystematics.size() << ");" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // line1.SetLineColor(kRed);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // line1.Draw(\"Lsame\");" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // TF1 line_m1 (\"line_m1\",\"-1\",0," << vNameSystematics.size() << ");" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // line_m1.SetLineColor(kRed);" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // line_m1.Draw(\"Lsame\");" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << " // histo.Draw(\"EPsame\");" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder] << std::endl; 
   myfile_summary_global_pull_systematics_plot[iFolder] <<  "}" << std::endl;
   myfile_summary_global_pull_systematics_plot[iFolder].close(); 
   
  }
  
}
