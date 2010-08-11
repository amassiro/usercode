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
 std::vector< std::string > inputFileMC = gConfigParser -> readStringListOption("InputMC::inputFile");
 std::vector< std::string > inputSampleMC = gConfigParser -> readStringListOption("InputMC::nameSample");
 std::vector< double > xSecAndEfficiency = gConfigParser -> readDoubleListOption("InputMC::xsecEff");

 std::cout << ">>>>> InputMC::treeName  " << treeNameMC  << std::endl;
 std::cout << ">>>>> InputMC::inputFile size " << inputFileMC.size()  << std::endl;
 if (inputFileMC.size() != xSecAndEfficiency.size() || inputFileMC.size() != inputSampleMC.size()) {
     std::cerr << " >>>> Error: different number of samples and cross sections" << std::endl;
     return 0;
    }
 int nMC = inputFileMC.size();
 for (int iMC = 0; iMC < nMC; iMC++) {
    std::cout << ">>>>> InputMC::inputFile[" << iMC << "] = " << inputSampleMC.at(iMC) << " => " << inputFileMC.at(iMC)  << " : " << xSecAndEfficiency.at(iMC) << " : " << luminosity * xSecAndEfficiency.at(iMC) << std::endl;
 }


 int bin = gConfigParser -> readIntOption("Options::bin");
 double min = gConfigParser -> readDoubleOption("Options::min");
 double max = gConfigParser -> readDoubleOption("Options::max");
 std::string variable = gConfigParser -> readStringOption("Options::variable");
 std::cout << ">>>>> Options::bin      " << bin  << std::endl;
 std::cout << ">>>>> Options::min      " << min  << std::endl;
 std::cout << ">>>>> Options::max      " << max  << std::endl;
 std::cout << ">>>>> Options::variable " << variable.c_str() << std::endl;

 std::string outputFile = gConfigParser -> readStringOption("Output::outputFile");
 std::cout << ">>>>> Output::outputFile  " << outputFile  << std::endl;


 int EEEB = gConfigParser -> readIntOption("Options::EEorEB");
 std::cout << ">>>>> Options::EEEB " << EEEB << std::endl;
 TString AdditionalCut = Form("1"); ///==== no additional selection
 if (EEEB == 1) { ///==== EE
   AdditionalCut = Form("(eta > 1.5 || eta < -1.5)");
 }

 if (EEEB == 2) { ///==== EB
   AdditionalCut = Form("(eta < 1.5 && eta > -1.5)");
 }
 std::cout << ">>>>>        :: " << AdditionalCut.Data() << std::endl;
 


 EColor vColor[10] = {kBlue,kRed,kGreen,kYellow,kOrange,kGray,kTeal,kMagenta,kViolet};

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

 TTree* MyTreeDATA = (TTree*) fileInDATA->Get(treeNameDATA.c_str());
 double pT;
 double ET;
 double MT;
 double EoP;
 MyTreeDATA->SetBranchAddress("pT",&pT);
 MyTreeDATA->SetBranchAddress("ET",&ET);
 MyTreeDATA->SetBranchAddress("MT",&MT);
 MyTreeDATA->SetBranchAddress("EoP",&EoP);
 TH1F* HistoDATA = new TH1F("DATA","DATA",bin,min,max);
 TString DrawDATA = Form("%s >> DATA",variable.c_str());
 MyTreeDATA->Draw(DrawDATA.Data(),AdditionalCut.Data());
 HistoDATA->SetMarkerSize(1);
 HistoDATA->SetMarkerStyle(20); 
 HistoDATA->GetXaxis()->SetTitle(variable.c_str());
 leg->AddEntry(HistoDATA,HistoDATA->GetTitle(),"p");
 legDown->AddEntry(HistoDATA,HistoDATA->GetTitle(),"p");

 TH1F* HistoMC[nMC];
 TTree* MyTreeMC[nMC];
 THStack* hsMC = new THStack("hsMC","hsMC");
 
 double MC_Expected = 0;
 
 for (int iMC = 0; iMC < nMC; iMC++) {
// for (int iMC = nMC-1; iMC >= 0; iMC--) {
  MyTreeMC[iMC] = (TTree*) fileInMC[iMC]->Get(treeNameMC.c_str());
  MyTreeMC[iMC]->SetBranchAddress("pT",&pT);
  MyTreeMC[iMC]->SetBranchAddress("ET",&ET);
  MyTreeMC[iMC]->SetBranchAddress("MT",&MT);
  MyTreeMC[iMC]->SetBranchAddress("EoP",&EoP);
  HistoMC[iMC] = new TH1F(inputSampleMC.at(iMC).c_str(),inputSampleMC.at(iMC).c_str(),bin,min,max);
  TString Draw = Form("%s >>%s",variable.c_str(),inputSampleMC.at(iMC).c_str());
  MyTreeMC[iMC]->Draw(Draw.Data(),AdditionalCut.Data());
  std::cout << ">>>>>> " << inputSampleMC.at(iMC) << " : " << xSecAndEfficiency.at(iMC) << " : " << luminosity << " : " << HistoMC[iMC]->GetEntries() << " = " << luminosity * xSecAndEfficiency.at(iMC) * HistoMC[iMC]->GetEntries() << std::endl;
  std::cout << "    >> " << Draw.Data() << std::endl;
  MC_Expected += luminosity * xSecAndEfficiency.at(iMC) * HistoMC[iMC]->GetEntries();
  HistoMC[iMC]->Scale(luminosity * xSecAndEfficiency.at(iMC)); // / HistoMC[iMC]->GetEntries());
  SetColorAndStyleHisto(*(HistoMC[iMC]),vColor[iMC]);
  HistoMC[iMC]->SetAxisRange(0,HistoDATA->GetMaximum() * 2.5,"Y");
  HistoMC[iMC]->GetXaxis()->SetTitle(variable.c_str());
  hsMC->Add(HistoMC[iMC]);
  if (iMC == 0) hsMC->Add(HistoMC[iMC]);
  leg->AddEntry(HistoMC[iMC],HistoMC[iMC]->GetTitle(),"f");
  legDown->AddEntry(HistoMC[iMC],HistoMC[iMC]->GetTitle(),"f");
 }
  

 ///----------------------
 ///---- Plot results ----
 ///----------------------
 std::cerr << " MC expected : DATA = " << MC_Expected << " : " << HistoDATA->GetEntries() << std::endl;
 
 std::cerr << " HistoDATA->GetMaximum() = " << HistoDATA->GetMaximum() << std::endl;
 std::cerr << " HistoDATA->GetEntries() = " << HistoDATA->GetEntries() << std::endl;
 outFile->cd();
 TCanvas cResultDistro("cResultDistro","cResultDistro",800,800);
 HistoDATA->SetAxisRange(0.01,HistoDATA->GetMaximum() * 1.5,"Y");
 HistoDATA->DrawClone("E1");
// DrawStack(hsMC);
 hsMC->DrawClone("same");
 hsMC->DrawClone("BARsame");

// HistoMC[0]->Draw("BAR");
// HistoMC[1]->Draw("same");
 // std::cerr << " HistoMC[0]->GetEntries() = " << HistoMC[0]->GetEntries() << std::endl;
 leg->Draw();
 gPad->SetGrid();
 TString tLumiName = Form("#int L = %.4f pb^{-1}",luminosity);
 TLatex tLumi(1.5 * HistoDATA->GetMean(1),0.1 * HistoDATA->GetMaximum(),tLumiName.Data());
 tLumi.DrawClone();
 TString nameImage = Form("%s_%d.png",variable.c_str(),EEEB);
 cResultDistro.SaveAs(nameImage.Data());

 TString nameImageRoot = Form("%s_%d.root",variable.c_str(),EEEB);
 cResultDistro.SaveAs(nameImageRoot.Data());


 TCanvas cResultDistroLog("cResultDistroLog","cResultDistroLog",800,800);
 HistoDATA->DrawClone("E1");
 DrawStack(hsMC);
// hsMC->DrawClone("same");
// hsMC->DrawClone("BARsame");
 HistoDATA->DrawClone("E1same");
 legDown->Draw();
 gPad->SetGrid();
 gPad->SetLogy();
 TString nameImageLog = Form("%s_%d_log.png",variable.c_str(),EEEB);
 tLumi.Draw();
 cResultDistroLog.SaveAs(nameImageLog.Data());
  
}



