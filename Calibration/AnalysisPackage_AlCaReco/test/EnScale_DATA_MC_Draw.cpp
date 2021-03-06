#include "ConfigParser.h"
#include "ntpleUtils.h"

#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include "TFile.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TH1F.h"

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "TRandom.h"
#include "TGraph.h"
#include "TROOT.h"

#include "TLegend.h"

#include "THStack.h"
#include "myStack.C"

#include "TF1.h"

#include "TStyle.h"
#include "TColor.h"

#include "TLatex.h"

#include "AlCaReco.h"


void CorrectString(std::string &inString){
 int pos = 1;
 while (pos!=std::string::npos){
  pos = inString.find("PHL");
  if (pos!=std::string::npos) inString.replace(pos,3,"(");
 }
 pos = 1;
 while (pos!=std::string::npos){
  pos = inString.find("PHR");
  if (pos!=std::string::npos) inString.replace(pos,3,")");
 }
 pos = 1;
 while (pos!=std::string::npos){
  pos = inString.find("DIV");
  if (pos!=std::string::npos) inString.replace(pos,3,"/");
 }
 pos = 1;
 while (pos!=std::string::npos){
  pos = inString.find("MIN");
  if (pos!=std::string::npos) inString.replace(pos,3,"<");
 }
 pos = 1;
 while (pos!=std::string::npos){
  pos = inString.find("MAJ");
  if (pos!=std::string::npos) inString.replace(pos,3,">");
 }
 pos = 1;
 while (pos!=std::string::npos){
  pos = inString.find("AND");
  if (pos!=std::string::npos) inString.replace(pos,3,"&&");
 }
 pos = 1;
 while (pos!=std::string::npos){
  pos = inString.find("OR");
  if (pos!=std::string::npos) inString.replace(pos,2,"||");
 }
 pos = 1;
 while (pos!=std::string::npos){
  pos = inString.find("PLUS");
  if (pos!=std::string::npos) inString.replace(pos,4,"+");
 }
 pos = 1;
 while (pos!=std::string::npos){
  pos = inString.find("NOT");
  if (pos!=std::string::npos) inString.replace(pos,3,"!");
 }
}


/**
SetColor/Style Histo
*/
void SetColorAndStyleHisto(TH1 & histo , EColor color){
 histo.SetFillStyle (3001) ;
 histo.SetFillColor (color) ;
 histo.SetLineColor (color) ;
 histo.SetLineWidth (1) ;
 histo.SetMarkerColor (color) ;
 histo.SetMarkerSize (1) ;
 histo.SetMarkerStyle (20) ;
}



int main(int argc, char** argv){

 ///==================================================
 ///==== Draw Distribution with and without scale ====
 ///==================================================

 ///===============================================================================
 gROOT->Reset();
 gROOT->SetStyle("Plain");
 gStyle->SetPalette(1);
 gStyle->SetOptStat(0);
 gStyle->SetOptFit(0);

 const Int_t __NRGBs = 5;
 const Int_t __NCont = 76;
 Double_t __stops[__NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
 Double_t __red[__NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
 Double_t __green[__NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
 Double_t __blue[__NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };

 TColor::CreateGradientColorTable(__NRGBs, __stops, __red, __green, __blue, __NCont);
 gStyle->SetNumberContours(__NCont);
 ///===============================================================================
 

 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }

 // Parse the config file
 parseConfigFile (argv[1]) ;

 std::string treeNameDATA  = gConfigParser -> readStringOption("InputDATA::treeName");
 std::string inputFileDATA = gConfigParser -> readStringOption("InputDATA::inputFile");
 double luminosity = gConfigParser -> readDoubleOption("InputDATA::luminosity");
 std::cout << ">>>>> InputDATA::treeName   " << treeNameDATA  << std::endl;
 std::cout << ">>>>> InputDATA::inputFile  " << inputFileDATA  << std::endl;
 std::cout << ">>>>> InputDATA::luminosity " << luminosity  << std::endl;

 std::string treeNameMC  = gConfigParser -> readStringOption("InputMC::treeName");
 
 
 std::vector< std::string > inputFileMC;
 std::vector< std::string > inputSampleMC;
 std::vector< double > xSecAndEfficiency;
 std::vector< int > join;
 std::vector< std::string > nameJoin;
 
 try {
  inputFileMC = gConfigParser -> readStringListOption("InputMC::inputFile");
 }
 catch (char const* exceptionString){
  std::cerr << " InputMC :: " << exceptionString << std::endl;
  return 0;}
 
 try {
  inputSampleMC = gConfigParser -> readStringListOption("InputMC::nameSample");
 }
 catch (char const* exceptionString){
  std::cerr << " InputMC :: " << exceptionString << std::endl;
  return 0;
 }
 
 try {
  xSecAndEfficiency = gConfigParser -> readDoubleListOption("InputMC::xsecEff");
 }
 catch (char const* exceptionString){
  std::cerr << " InputMC :: " << exceptionString << std::endl;
  return 0;
 }
 
 try {
  join = gConfigParser -> readIntListOption("InputMC::join");
 }
 catch (char const* exceptionString){
  std::cerr << " InputMC :: " << exceptionString << std::endl;
  for (int iMC = 0; iMC < inputFileMC.size(); iMC++) { 
   join.push_back(iMC);
  }
 }
 
 try {
  nameJoin = gConfigParser -> readStringListOption("InputMC::nameJoin");
 }
 catch (char const* exceptionString){
  std::cerr << " InputMC :: " << exceptionString << std::endl;
  nameJoin = inputSampleMC;
 }
 
 
 
 std::cout << ">>>>> InputMC::treeName  " << treeNameMC  << std::endl;
 std::cout << ">>>>> InputMC::inputFile size " << inputFileMC.size()  << std::endl;
 if (inputFileMC.size() != xSecAndEfficiency.size() || inputFileMC.size() != inputSampleMC.size()) {
     std::cerr << " >>>> Error: different number of samples and cross sections" << std::endl;
     return 0;
    }
 int nMC = inputFileMC.size();
 std::cout << " nMC = " << nMC << std::endl;
 
 for (int iMC = 0; iMC < nMC; iMC++) {
    std::cout << ">>>>> InputMC::inputFile[" << iMC << "] = " << inputSampleMC.at(iMC) << " => " << inputFileMC.at(iMC)  << " : " << xSecAndEfficiency.at(iMC) << " : " << luminosity * xSecAndEfficiency.at(iMC) << std::endl;
 }

 int Dimension = gConfigParser -> readIntOption("Options::Dimension");
 std::cout << ">>>>> Options::Dimension     " << Dimension  << std::endl;
 
 int bin = gConfigParser -> readIntOption("Options::bin");
 double min = gConfigParser -> readDoubleOption("Options::min");
 double max = gConfigParser -> readDoubleOption("Options::max");
 std::string variable = gConfigParser -> readStringOption("Options::variable");
 std::cout << ">>>>> Options::bin      " << bin  << std::endl;
 std::cout << ">>>>> Options::min      " << min  << std::endl;
 std::cout << ">>>>> Options::max      " << max  << std::endl;
 std::cout << ">>>>> Options::variable " << variable.c_str() << std::endl;

 std::string variableNameFile = variable;
 CorrectString(variable);
 std::cout << ">>>>> Options::variable After " << variable.c_str() << std::endl;
 
 
 int binY;
 double minY;
 double maxY;
 std::string variableY;
 std::string variableNameFileY;
 
 if (Dimension == 2) {
	binY = gConfigParser -> readIntOption("Options::binY");
	minY = gConfigParser -> readDoubleOption("Options::minY");
	maxY = gConfigParser -> readDoubleOption("Options::maxY");
	variableY = gConfigParser -> readStringOption("Options::variableY");
	std::cout << ">>>>> Options::binY      " << binY  << std::endl;
	std::cout << ">>>>> Options::minY      " << minY  << std::endl;
	std::cout << ">>>>> Options::maxY      " << maxY  << std::endl;
	std::cout << ">>>>> Options::variableY " << variableY.c_str() << std::endl;
	variableNameFileY = variableY;
	CorrectString(variableY);
	std::cout << ">>>>> Options::variableY After " << variableY.c_str() << std::endl;
 }
 
 
 std::string outputFile = gConfigParser -> readStringOption("Output::outputFile");
 std::cout << ">>>>> Output::outputFile  " << outputFile  << std::endl;

 std::string cut;
 try {
  cut = gConfigParser -> readStringOption("Options::cut");
  std::cout << ">>>>> Output::cut  " << cut  << std::endl;
  CorrectString(cut);
  std::cout << ">>>>> Output::cut  " << cut  << std::endl;
  
 }
 catch (char const* exceptionString){
  std::cerr << " cut :: " << exceptionString << std::endl;
  cut = "1";
 }
 std::cout << ">>>>> Option::cut  " << cut  << std::endl;  
 
 
 
 
 
 
 int EEEB = gConfigParser -> readIntOption("Options::EEorEB");
 std::cout << ">>>>> Options::EEEB " << EEEB << std::endl;
 TString AdditionalCut = Form("%s",cut.c_str());
 if (EEEB == 1) { ///==== EE
  AdditionalCut = Form("%s && (eta > 1.5 || eta < -1.5)",AdditionalCut.Data());
 }
 if (EEEB == 2) { ///==== EB
  AdditionalCut = Form("%s && (eta < 1.5 && eta > -1.5)",AdditionalCut.Data());
 }
 if (EEEB == 3) { ///==== EE+
  AdditionalCut = Form("%s && (eta > 1.5)",AdditionalCut.Data());
 }
 if (EEEB == 4) { ///==== EE-
  AdditionalCut = Form("%s && (eta < -1.5)",AdditionalCut.Data());
 }
 if (EEEB == 5) { ///==== EB mod 1
  AdditionalCut = Form("%s && (abs(eta) < 0.435)",AdditionalCut.Data());
 }
 if (EEEB == 6) { ///==== EB mod 2
  AdditionalCut = Form("%s && (abs(eta) < 0.783 && abs(eta) > 0.435)",AdditionalCut.Data());
 }
 if (EEEB == 7) { ///==== EB mod 3
  AdditionalCut = Form("%s && (abs(eta) < 1.131 && abs(eta) > 0.783)",AdditionalCut.Data());
 }
 if (EEEB == 8) { ///==== EB mod 4
  AdditionalCut = Form("%s && (abs(eta) < 1.479 && abs(eta) > 1.131)",AdditionalCut.Data());
 }
 if (EEEB == 9) { ///==== EE No ES
  AdditionalCut = Form("%s && (abs(eta) > 2.5)",AdditionalCut.Data());
 }
 if (EEEB == 10) { ///==== EE + ES
  AdditionalCut = Form("%s && (abs(eta) < 2.5 && abs(eta) > 1.5)",AdditionalCut.Data());
 }
 if (EEEB == 11) { ///==== EE- + ES
  AdditionalCut = Form("%s && (eta > -2.5 && eta < -1.5)",AdditionalCut.Data());
 }
 if (EEEB == 12) { ///==== EE+ + ES
  AdditionalCut = Form("%s && (eta < 2.5 && eta > 1.5)",AdditionalCut.Data());
 }
 
 std::cout << ">>>>>        :: " << AdditionalCut.Data() << std::endl;
 
 
 ///==== 0 = Normalize to lumi (default)
 ///==== 1 = Normalize to data
 int Normalize = 0;
 try {
  Normalize = gConfigParser -> readIntOption("Options::Normalize");
 }
 catch (char const* exceptionString){
  std::cerr << " Normalize :: " << exceptionString << std::endl;
  Normalize = 0;
 }
 std::cout << ">>>>> Options::Normalize  " << Normalize  << std::endl;  
 
 
 
 
 ///==== HLT cut added ====
//  AdditionalCut += Form(" && HLT_Ele15_LW_L1R==1");
 
 
 
 EColor vColor[100] = {
  kGreen,(EColor)(kGreen+1),(EColor) (kGreen+2),
  kRed,(EColor) (kRed+1),(EColor) (kRed+2),
  kGreen,(EColor) (kGreen+1),
  //kMagenta,(EColor) (kMagenta+1),(EColor) (kMagenta+2),
  kTeal,(EColor) (kTeal+1),
  kOrange,(EColor) (kOrange+1),
  kBlue,(EColor) (kBlue+1),(EColor) (kViolet),(EColor) (kYellow),(EColor) (kGray)};
 
 ///==== DATA ====
 TFile* fileInDATA = new TFile(inputFileDATA.c_str(),"READ");

 ///==== W ====
 TFile* fileInMC[nMC];
 for (int iMC = 0; iMC < nMC; iMC++) {
    fileInMC[iMC] = new TFile(inputFileMC.at(iMC).c_str(),"READ");
 }

 ///==== output ====
 TFile* outFile = new TFile(outputFile.c_str(),"RECREATE");
 outFile->cd();


 ///==== Prepare input trees ====
 TLegend* leg = new TLegend(0.55,0.7,0.95,0.95);
 leg->SetFillColor(0);

 TLegend* legDown = new TLegend(0.55,0.1,0.95,0.35);
 legDown->SetFillColor(0);

 if (Dimension == 1){
  int initialNumber;
  TTree* MyTreeDATA = (TTree*) fileInDATA->Get(treeNameDATA.c_str());
  TH1F* HistoDATA = new TH1F("DATA","DATA",bin,min,max);
  TString DrawDATA = Form("%s >> DATA",variable.c_str());
  MyTreeDATA->Draw(DrawDATA.Data(),AdditionalCut.Data());
  HistoDATA->SetMarkerSize(1);
  HistoDATA->SetMarkerStyle(20); 
  HistoDATA->GetXaxis()->SetTitle(variable.c_str());
  leg->AddEntry(HistoDATA,HistoDATA->GetTitle(),"p");
  legDown->AddEntry(HistoDATA,HistoDATA->GetTitle(),"p");
   
  int numEntriesData = HistoDATA->GetEffectiveEntries();
  std::cerr << " numEntriesData = " << numEntriesData << std::endl;
  
  TH1F* HistoMC[nMC];
  TTree* MyTreeMC[nMC];
  THStack* hsMC = new THStack("hsMC","hsMC");
 
  double MC_Expected = 0;
  double MC_Expected_effective = 0;
  
  for (int iMC = 0; iMC < nMC; iMC++) {
   // for (int iMC = nMC-1; iMC >= 0; iMC--) {
    MyTreeMC[iMC] = (TTree*) fileInMC[iMC]->Get(treeNameMC.c_str());
    MyTreeMC[iMC]->SetBranchAddress("initialNumber",&initialNumber);
    MyTreeMC[iMC]->GetEntry(0);
    xSecAndEfficiency.at(iMC) = xSecAndEfficiency.at(iMC) / initialNumber; ///==== normalize to initial number of events
    HistoMC[iMC] = new TH1F(inputSampleMC.at(iMC).c_str(),inputSampleMC.at(iMC).c_str(),bin,min,max);
    TString Draw = Form("%s >>%s",variable.c_str(),inputSampleMC.at(iMC).c_str());
    MyTreeMC[iMC]->Draw(Draw.Data(),AdditionalCut.Data());
    std::cout << ">>>>>> " << inputSampleMC.at(iMC) << " : " << xSecAndEfficiency.at(iMC) << " : " << luminosity << " : " << HistoMC[iMC]->GetEntries() << " = " << luminosity * xSecAndEfficiency.at(iMC) * HistoMC[iMC]->GetEntries() << std::endl;
    std::cout << "    >> " << Draw.Data() << std::endl;
    MC_Expected += luminosity * xSecAndEfficiency.at(iMC) * HistoMC[iMC]->GetEntries();
    MC_Expected_effective += luminosity * xSecAndEfficiency.at(iMC) * HistoMC[iMC]->GetEffectiveEntries();
    HistoMC[iMC]->Scale(luminosity * xSecAndEfficiency.at(iMC));
   }
  
  
  ///==== join sample ====
   std::vector < int > used;
   for (int iMC = 0; iMC < nMC; iMC++) { 
    used.push_back(0);
   }
   
   for (int iMC = 0; iMC < nMC; iMC++) {
    if (used.at(iMC) != 1){
     for (int iMCJoin = 0; iMCJoin < nMC; iMCJoin++) {
      if ((iMC != iMCJoin) && (join.at(iMC) == join.at(iMCJoin))) {
       HistoMC[iMC]->Add(HistoMC[iMCJoin]);
       used.at(iMCJoin) = 1;
       std::cout << " used iMC = " << iMC << " : iMCJoin " << iMCJoin << std::endl;
      }
     }
    }
   }
   ///==== end sample ==== 
   
   
   for (int iMC = 0; iMC < nMC; iMC++) {
    if (Normalize == 1) {
     HistoMC[iMC]->Scale(numEntriesData/MC_Expected_effective);
     std::cout << " DATA: MC = " << numEntriesData << " : " << MC_Expected_effective << std::endl;
    }
    SetColorAndStyleHisto(*(HistoMC[iMC]),vColor[iMC]);
    HistoMC[iMC]->SetAxisRange(0,HistoDATA->GetMaximum() * 2.5,"Y");
    HistoMC[iMC]->GetXaxis()->SetTitle(variable.c_str());
    if (used.at(iMC) != 1) {
     hsMC->Add(HistoMC[iMC]);
     leg->AddEntry(HistoMC[iMC],nameJoin.at(iMC).c_str(),"f");
     legDown->AddEntry(HistoMC[iMC],nameJoin.at(iMC).c_str(),"f");
    }
   }
   
   
 ///----------------------
 ///---- Plot results ----
 ///----------------------
  std::cerr << " MC expected : DATA = " << MC_Expected << " : " << HistoDATA->GetEntries() << std::endl;
 
  std::cerr << " HistoDATA->GetMaximum() = " << HistoDATA->GetMaximum() << std::endl;
  std::cerr << " HistoDATA->GetEntries() = " << HistoDATA->GetEntries() << std::endl;
  outFile->cd();
  TCanvas cResultDistro("cResultDistro","cResultDistro",800,800);
  HistoDATA->SetAxisRange(0.01,HistoDATA->GetMaximum() * 2.5,"Y");
  HistoDATA->DrawClone("A");
  DrawStack(hsMC);
 //  hsMC->DrawClone("same");
//   hsMC->DrawClone("BARsame");
  HistoDATA->DrawClone("E1same");

 // HistoMC[0]->Draw("BAR");
 // HistoMC[1]->Draw("same");
  // std::cerr << " HistoMC[0]->GetEntries() = " << HistoMC[0]->GetEntries() << std::endl;
  leg->Draw();
  gPad->SetGrid();
  TString tLumiName = Form("#int L = %.2f pb^{-1}",luminosity);
  TLatex tLumi(1.5 * HistoDATA->GetMean(1),0.1 * HistoDATA->GetMaximum(),tLumiName.Data());
  tLumi.DrawClone();

  TString tEleName = Form("%d electrons",(int) HistoDATA->GetEntries());
  TLatex tEle(1.5 * HistoDATA->GetMean(1),0.3 * HistoDATA->GetMaximum(),tEleName.Data());
  tEle.DrawClone();
 
  TString nameImage = Form("%s_%d_%d.png",variableNameFile.c_str(),EEEB,Normalize);
  cResultDistro.SaveAs(nameImage.Data());

  TString nameImageRoot = Form("%s_%d_%d.root",variableNameFile.c_str(),EEEB,Normalize);
  TFile outFile(nameImageRoot,"RECREATE");
  for (int iMC = 0; iMC < nMC; iMC++) {
   HistoMC[iMC]->Write();
  }
  hsMC->Write();
  HistoDATA->Write();
  cResultDistro.Write();

  TCanvas cResultDistroLog("cResultDistroLog","cResultDistroLog",800,800);
  HistoDATA->DrawClone("E1");
  DrawStack(hsMC);
 // hsMC->DrawClone("same");
//   hsMC->DrawClone("BARsame");
  HistoDATA->DrawClone("E1same");
  legDown->Draw();
  gPad->SetGrid();
  gPad->SetLogy();
  TString nameImageLog = Form("%s_%d_%d_log.png",variableNameFile.c_str(),EEEB,Normalize);
  tLumi.Draw();
  cResultDistroLog.SaveAs(nameImageLog.Data());
  }
  
  
  
  
  
  
  
  
  
  ///==== 2D ====
  
   if (Dimension == 2){
  int initialNumber;
  TTree* MyTreeDATA = (TTree*) fileInDATA->Get(treeNameDATA.c_str());
  TH2F* HistoDATA = new TH2F("DATA","DATA",bin,min,max,binY,minY,maxY);
  TString DrawDATA = Form("%s:%s >> DATA",variableY.c_str(),variable.c_str());
  MyTreeDATA->Draw(DrawDATA.Data(),AdditionalCut.Data());
  HistoDATA->SetMarkerSize(1);
  HistoDATA->SetMarkerStyle(20); 
  HistoDATA->GetXaxis()->SetTitle(variable.c_str());
  HistoDATA->GetYaxis()->SetTitle(variableY.c_str());
  leg->AddEntry(HistoDATA,HistoDATA->GetTitle(),"p");
  legDown->AddEntry(HistoDATA,HistoDATA->GetTitle(),"p");

  TH2F* HistoMC[nMC];
  TTree* MyTreeMC[nMC];
  TH2F* hsMC = new TH2F("MC","MC",bin,min,max,binY,minY,maxY);
  TH2F* hsMC_Unscaled = new TH2F("MC_Unscaled","MC_Unscaled",bin,min,max,binY,minY,maxY);
  
  double MC_Expected = 0;
 
  for (int iMC = 0; iMC < nMC; iMC++) {
 // for (int iMC = nMC-1; iMC >= 0; iMC--) {
  MyTreeMC[iMC] = (TTree*) fileInMC[iMC]->Get(treeNameMC.c_str());
  MyTreeMC[iMC]->SetBranchAddress("initialNumber",&initialNumber);
  MyTreeMC[iMC]->GetEntry(0);
  xSecAndEfficiency.at(iMC) = xSecAndEfficiency.at(iMC) / initialNumber; ///==== normalize to initial number of events
  HistoMC[iMC] = new TH2F(inputSampleMC.at(iMC).c_str(),inputSampleMC.at(iMC).c_str(),bin,min,max,binY,minY,maxY);
  TString Draw = Form("%s:%s >>%s",variableY.c_str(),variable.c_str(),inputSampleMC.at(iMC).c_str());
  MyTreeMC[iMC]->Draw(Draw.Data(),AdditionalCut.Data());
  std::cout << ">>>>>> " << inputSampleMC.at(iMC) << " : " << xSecAndEfficiency.at(iMC) << " : " << luminosity << " : " << HistoMC[iMC]->GetEntries() << " = " << luminosity * xSecAndEfficiency.at(iMC) * HistoMC[iMC]->GetEntries() << std::endl;
  std::cout << "    >> " << Draw.Data() << std::endl;
  MC_Expected += luminosity * xSecAndEfficiency.at(iMC) * HistoMC[iMC]->GetEntries();
  hsMC_Unscaled->Add(HistoMC[iMC],1.);
  HistoMC[iMC]->Scale(luminosity * xSecAndEfficiency.at(iMC)); // / HistoMC[iMC]->GetEntries());
  SetColorAndStyleHisto(*(HistoMC[iMC]),vColor[iMC]);
  HistoMC[iMC]->GetXaxis()->SetTitle(variable.c_str()); 
  HistoMC[iMC]->GetYaxis()->SetTitle(variableY.c_str());
  hsMC->Add(HistoMC[iMC],1.);
  leg->AddEntry(HistoMC[iMC],HistoMC[iMC]->GetTitle(),"f");
  legDown->AddEntry(HistoMC[iMC],HistoMC[iMC]->GetTitle(),"f");
 }
 hsMC->GetXaxis()->SetTitle(variable.c_str()); 
 hsMC->GetYaxis()->SetTitle(variableY.c_str());
  
 ///----------------------
 ///---- Plot results ----
 ///----------------------
  std::cerr << " MC expected : DATA = " << MC_Expected << " : " << HistoDATA->GetEntries() << std::endl;
  std::cerr << " HistoDATA->GetEntries() = " << HistoDATA->GetEntries() << std::endl;
  outFile->cd();
  TCanvas cResultDistro("cResultDistro","cResultDistro",800,800);
   hsMC->DrawClone("COLZ");
   HistoDATA->DrawClone("boxSAME");
  
   gPad->SetGrid();
   TString tLumiName = Form("#int L = %.2f pb^{-1}",luminosity);
   TLatex tLumi(1.5 * (max+min)/2. ,0.2 * (maxY+minY)/2.,tLumiName.Data());
   tLumi.DrawClone();
  
   TString tEleName = Form("%d electrons",(int) HistoDATA->GetEntries());
   TLatex tEle(1.5 * (max+min)/2. ,0.4 * (maxY+minY)/2.,tEleName.Data());
   tEle.DrawClone();
   
   TString nameImage = Form("%s_%s_%d.png",variableNameFile.c_str(),variableNameFileY.c_str(),EEEB);
   std::cerr << "nameImage = " << nameImage.Data() << std::endl;
   cResultDistro.SaveAs(nameImage.Data());
  
   TString nameImageRoot = Form("%s_%s_%d.root",variableNameFile.c_str(),variableNameFileY.c_str(),EEEB);
   cResultDistro.SaveAs(nameImageRoot.Data());
  
   TCanvas cResultDistroLog("cResultDistroLog","cResultDistroLog",800,800);
   hsMC->DrawClone("COLZ");
   HistoDATA->DrawClone("boxSAME");
   gPad->SetGrid();
   gPad->SetLogz();
   TString nameImageLog = Form("%s_%s_%d_log.png",variableNameFile.c_str(),variableNameFileY.c_str(),EEEB);
   tLumi.Draw();
   cResultDistroLog.SaveAs(nameImageLog.Data());
   
   
   TCanvas cResultDistroSlices("cResultDistroSlices","cResultDistroSlices",800,800);  
   TH1D* hsMCProfile = smartGausProfileX_sqrtN (hsMC_Unscaled,3);
   TH1D* hsDATAProfile = smartGausProfileX_sqrtN (HistoDATA,3);

   hsMCProfile->SetTitle("MC");
   hsDATAProfile->SetTitle("data");
   
   SetColorAndStyleHisto(*hsMCProfile,kRed);
   SetColorAndStyleHisto(*hsDATAProfile,kBlue);

//    hsMC->DrawClone("COLZ");

   TLegend* legProfile = new TLegend(0.65,0.2,0.85,0.35);
   legProfile->SetFillColor(0);
   legProfile->AddEntry(hsMCProfile,hsMCProfile->GetTitle(),"p");
   legProfile->AddEntry(hsDATAProfile,hsDATAProfile->GetTitle(),"p");
   
   
   hsMCProfile->GetXaxis()->SetTitle(variable.c_str()); 
   hsMCProfile->GetYaxis()->SetTitle(variableY.c_str());
   hsMCProfile->SetAxisRange(minY,maxY,"Y");
   
   hsMCProfile->Draw("E");
   hsDATAProfile->Draw("Esame");
   legProfile->Draw();
   gPad->SetGrid();
   TString nameImageProfile = Form("%s_%s_%d_profile.png",variableNameFile.c_str(),variableNameFileY.c_str(),EEEB);
   cResultDistroSlices.SaveAs(nameImageProfile.Data());
   
   }
}



