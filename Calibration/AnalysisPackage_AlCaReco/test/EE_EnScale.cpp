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



// -------------------------------------------------------------

TH1D * smartGausProfileXSQRTN (TH2F * strip, double width){
 TProfile * stripProfile = strip->ProfileX () ;
 
 // (from FitSlices of TH2.h)
 
 double xmin = stripProfile->GetXaxis ()->GetXmin () ;
 double xmax = stripProfile->GetXaxis ()->GetXmax () ;
 int profileBins = stripProfile->GetNbinsX () ;
 
 std::string name = strip->GetName () ;
 name += "_smartGaus_X" ; 
 TH1D * prof = new TH1D(name.c_str (),strip->GetTitle (),profileBins,xmin,xmax) ;
 
 int cut = 0 ; // minimum number of entries per fitted bin
 int nbins = strip->GetXaxis ()->GetNbins () ;
 int binmin = 1 ;
 int ngroup = 1 ; // bins per step
 int binmax = nbins ;
 
 // loop over the strip bins
 for (int bin=binmin ; bin<=binmax ; bin += ngroup) 
 {
  TH1D *hpy = strip->ProjectionY ("_temp",bin,bin+ngroup-1,"e") ;
  if (hpy == 0) continue ;
  int nentries = Int_t (hpy->GetEntries ()) ;
  if (nentries == 0 || nentries < cut) {delete hpy ; continue ;} 
  
  Int_t biny = bin + ngroup/2 ;
  
  TF1 * gaussian = new TF1 ("gaussian","gaus", hpy->GetMean () - width * hpy->GetRMS (), hpy->GetMean () + width * hpy->GetRMS ()) ; 
  gaussian->SetParameter (1,hpy->GetMean ()) ;
  gaussian->SetParameter (2,hpy->GetRMS ()) ;
  hpy->Fit ("gaussian","RQL") ;           
  
  //       hpy->GetXaxis ()->SetRangeUser ( hpy->GetMean () - width * hpy->GetRMS (), hpy->GetMean () + width * hpy->GetRMS ()) ;         
  prof->Fill (strip->GetXaxis ()->GetBinCenter (biny), gaussian->GetParameter (1)) ;       
  prof->SetBinError (biny,gaussian->GetParameter (2) / sqrt(hpy->GetEntries())) ;
//   prof->SetBinError (biny,gaussian->GetParError (1)) ;
  
  delete gaussian ;
  delete hpy ;
 } // loop over the bins
 
 delete stripProfile ;
 return prof ;
}


// -------------------------------------------------------------

// -------------------------------------------------------------

/** Personalized
build a TGraphError starting from a TH1F
*/
TGraphErrors buildGEfromH_Personalized (const TH1D & histo) 
{
 TVectorF xV(histo.GetNbinsX());
 TVectorF yV(histo.GetNbinsX());
 TVectorF errxV(histo.GetNbinsX());
 TVectorF erryV(histo.GetNbinsX());
 for (int iBin = 0; iBin<histo.GetNbinsX(); iBin++){
  xV[iBin] = histo.GetBinCenter(iBin);
  yV[iBin] = histo.GetBinContent(iBin);
  errxV[iBin] = 0;
//   histo.GetBinWidth(iBin);
  erryV[iBin] = histo.GetBinError(iBin);
 }  
 TGraphErrors g (xV, yV, errxV, erryV) ;
 return g ;
}



// -------------------------------------------------------------

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


 int binX = gConfigParser -> readIntOption("Options::binX");
 double minX = gConfigParser -> readDoubleOption("Options::minX");
 double maxX = gConfigParser -> readDoubleOption("Options::maxX");
 std::string variableX = gConfigParser -> readStringOption("Options::variableX");
 std::cout << ">>>>> Options::binX      " << binX  << std::endl;
 std::cout << ">>>>> Options::minX      " << minX  << std::endl;
 std::cout << ">>>>> Options::maxX      " << maxX  << std::endl;
 std::cout << ">>>>> Options::variableX " << variableX.c_str() << std::endl;

 int binY = gConfigParser -> readIntOption("Options::binY");
 double minY = gConfigParser -> readDoubleOption("Options::minY");
 double maxY = gConfigParser -> readDoubleOption("Options::maxY");
 std::string variableY = gConfigParser -> readStringOption("Options::variableY");
 std::cout << ">>>>> Options::binY      " << binY  << std::endl;
 std::cout << ">>>>> Options::minY      " << minY  << std::endl;
 std::cout << ">>>>> Options::maxY      " << maxY  << std::endl;
 std::cout << ">>>>> Options::variableY " << variableY.c_str() << std::endl;
 
 int binRatio = gConfigParser -> readIntOption("Options::binRatio");
 double minRatio = gConfigParser -> readDoubleOption("Options::minRatio");
 double maxRatio = gConfigParser -> readDoubleOption("Options::maxRatio");
 std::cout << ">>>>> Options::minRatio      " << minRatio  << std::endl;
 std::cout << ">>>>> Options::maxRatio      " << maxRatio  << std::endl;
 
 
 std::string outputFile = gConfigParser -> readStringOption("Output::outputFile");
 std::cout << ">>>>> Output::outputFile  " << outputFile  << std::endl;


//  TString AdditionalCut = Form("eta > 1.5");// || eta < -1.5)");// && eleFBrem<0.5");
 TString AdditionalCut = Form("eta < -1.5");// || eta < -1.5)");// && eleFBrem<0.5");
//  TString AdditionalCut = Form("(eta > 1.5 || eta < -1.5)");// && abs(eleFBrem)<1");
 
 
 
 EColor vColor[100] = {
  kBlue,(EColor)(kBlue+1),(EColor) (kBlue+2),
  kRed,(EColor) (kRed+1),(EColor) (kRed+2),
  kGreen,(EColor) (kGreen+1),(EColor) (kGreen+2),
  kTeal,(EColor) (kTeal+1),
  kOrange,(EColor) (kOrange+1),
  kMagenta,(EColor) (kMagenta+1),(EColor) (kViolet),(EColor) (kYellow),(EColor) (kGray)};
 
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
 int initialNumber;
 TH2F* HistoDATA = new TH2F("DATA","DATA",binX,minX,maxX,binY,minY,maxY);
 TH1F* HistoRatioDATA = new TH1F("RatioDATA","RatioDATA",binRatio,minRatio,maxRatio);
 TString DrawDATA = Form("%s:%s >> DATA",variableY.c_str(),variableX.c_str());
 MyTreeDATA->Draw(DrawDATA.Data(),AdditionalCut.Data());
 HistoDATA->SetMarkerSize(1);
 HistoDATA->SetMarkerStyle(20); 
 HistoDATA->GetXaxis()->SetTitle(variableX.c_str());
 HistoDATA->GetYaxis()->SetTitle(variableY.c_str());
 leg->AddEntry(HistoDATA,HistoDATA->GetTitle(),"p");
 legDown->AddEntry(HistoDATA,HistoDATA->GetTitle(),"p");

 DrawDATA = Form("(%s) / (%s) >> RatioDATA",variableY.c_str(),variableX.c_str());
 MyTreeDATA->Draw(DrawDATA.Data(),AdditionalCut.Data());
 HistoRatioDATA->SetMarkerSize(1);
 HistoRatioDATA->SetMarkerStyle(20); 
 HistoRatioDATA->GetXaxis()->SetTitle(Form("(%s)/(%s)",variableY.c_str(),variableX.c_str()));
 
 TH2F* HistoMC[nMC];
 TH1F* HistoRatioMC[nMC];

 TH2F* HistoMC_SUM = new TH2F("HistoMC_SUM","HistoMC_SUM",binX,minX,maxX,binY,minY,maxY);
 TH1F* HistoRatioMC_SUM = new TH1F("HistoRatioMC_SUM","HistoRatioMC_SUM",binRatio,minRatio,maxRatio);
 
 SetColorAndStyleHisto(*(HistoRatioMC_SUM),kBlue); 
 
 TTree* MyTreeMC[nMC];
 THStack* hsMC = new THStack("hsMC","hsMC");
 
 double MC_Expected = 0;
 
 for (int iMC = 0; iMC < nMC; iMC++) {
// for (int iMC = nMC-1; iMC >= 0; iMC--) {
  MyTreeMC[iMC] = (TTree*) fileInMC[iMC]->Get(treeNameMC.c_str());
  MyTreeMC[iMC]->SetBranchAddress("initialNumber",&initialNumber);
  MyTreeMC[iMC]->GetEntry(0);
  xSecAndEfficiency.at(iMC) = xSecAndEfficiency.at(iMC) / initialNumber; ///==== normalize to initial number of events
  HistoMC[iMC] = new TH2F(inputSampleMC.at(iMC).c_str(),inputSampleMC.at(iMC).c_str(),binX,minX,maxX,binY,minY,maxY);
  HistoRatioMC[iMC] = new TH1F(Form("%s_Ratio",inputSampleMC.at(iMC).c_str()),Form("%s_Ratio",inputSampleMC.at(iMC).c_str()),binRatio,minRatio,maxRatio);
  
  TString Draw = Form("%s:%s >> %s",variableY.c_str(),variableX.c_str(),inputSampleMC.at(iMC).c_str());
  MyTreeMC[iMC]->Draw(Draw.Data(),AdditionalCut.Data());

  Draw = Form("(%s) / (%s) >> %s",variableY.c_str(),variableX.c_str(),Form("%s_Ratio",inputSampleMC.at(iMC).c_str()));
  MyTreeMC[iMC]->Draw(Draw.Data(),AdditionalCut.Data());  
  HistoRatioMC[iMC]->GetXaxis()->SetTitle(Form("(%s)/(%s)",variableY.c_str(),variableX.c_str()));
  
  std::cout << ">>>>>> " << inputSampleMC.at(iMC) << " : " << xSecAndEfficiency.at(iMC) << " : " << luminosity << " : " << HistoMC[iMC]->GetEntries() << " = " << luminosity * xSecAndEfficiency.at(iMC) * HistoMC[iMC]->GetEntries() << std::endl;
  std::cout << "    >> " << Draw.Data() << std::endl;
  std::cout << "    >> " << HistoMC[iMC]->GetEntries() << " Entries" << std::endl;
 
  MC_Expected += luminosity * xSecAndEfficiency.at(iMC) * HistoMC[iMC]->GetEntries();
  
  HistoMC[iMC]->Scale(luminosity * xSecAndEfficiency.at(iMC)); // / HistoMC[iMC]->GetEntries());
  HistoRatioMC[iMC]->Scale(luminosity * xSecAndEfficiency.at(iMC)); // / HistoMC[iMC]->GetEntries());
  
  SetColorAndStyleHisto(*(HistoMC[iMC]),vColor[iMC]);
  SetColorAndStyleHisto(*(HistoRatioMC[iMC]),vColor[iMC]);
  
  HistoMC[iMC]->GetXaxis()->SetTitle(variableX.c_str());
  HistoMC[iMC]->GetYaxis()->SetTitle(variableY.c_str());
  
  HistoMC_SUM->Add(HistoMC[iMC]);
  HistoMC_SUM->GetXaxis()->SetTitle(variableX.c_str());
  HistoMC_SUM->GetYaxis()->SetTitle(variableY.c_str());
  
  HistoRatioMC_SUM->Add(HistoRatioMC[iMC]);
  HistoRatioMC_SUM->GetXaxis()->SetTitle(Form("(%s)/(%s)",variableY.c_str(),variableX.c_str()));
  
  hsMC->Add(HistoMC[iMC]);
  if (iMC == 0) hsMC->Add(HistoMC[iMC]);
  leg->AddEntry(HistoMC[iMC],HistoMC[iMC]->GetTitle(),"f");
  legDown->AddEntry(HistoMC[iMC],HistoMC[iMC]->GetTitle(),"f");
 }
  
  
 ///==== make fit ====
 
 TH1D* htemp_prof = smartGausProfileXSQRTN(HistoDATA,2);  
 TGraphErrors grH = buildGEfromH_Personalized(*htemp_prof);
 grH.SetMarkerStyle(22);
 grH.SetMarkerSize(0.7);
 grH.SetMarkerColor(kBlue);
 grH.SetFillColor(kBlue);
 grH.SetFillStyle(3335);
 grH.SetLineWidth(1);
 grH.SetLineColor(kBlue);
 grH.GetXaxis()->SetTitle(variableX.c_str());
 grH.GetYaxis()->SetTitle(variableY.c_str());
 

 ///----------------------
 ///---- Plot results ----
 ///----------------------
 std::cerr << " MC expected : DATA = " << MC_Expected << " : " << HistoDATA->GetEntries() << std::endl;
 
 std::cerr << " HistoDATA->GetMaximum() = " << HistoDATA->GetMaximum() << std::endl;
 std::cerr << " HistoDATA->GetEntries() = " << HistoDATA->GetEntries() << std::endl;
 outFile->cd();
 
 TCanvas cResultDistro("cResultDistro","cResultDistro",900,900);
 cResultDistro.Divide(2,2);
 cResultDistro.cd(1);
 HistoDATA->DrawClone("colz");
 gPad->SetGrid();
 TString tLumiName = Form("#int L = %.4f pb^{-1}",luminosity);
 TLatex tLumi(1.5 * HistoDATA->GetMean(1),0.2 * HistoDATA->GetMaximum(),tLumiName.Data());
 tLumi.DrawClone();
 
 
 cResultDistro.cd(2);
 HistoRatioMC_SUM->Draw();
 HistoRatioDATA->Draw("E1same");
 TString tEleName = Form("%d electrons",(int) HistoDATA->GetEntries());
 TLatex tEle(2.0 * HistoRatioDATA->GetMean(1),0.3 * HistoRatioDATA->GetMaximum(),tEleName.Data());
 tEle.DrawClone();
 gPad->SetGrid();

 
 cResultDistro.cd(3);
 grH.Draw("APL");
 double minFit = gConfigParser -> readDoubleOption("Options::minFit");
 double maxFit = gConfigParser -> readDoubleOption("Options::maxFit");
 std::cout << ">>>>> Options::minFit      " << minFit  << std::endl;
 std::cout << ">>>>> Options::maxFit      " << maxFit  << std::endl;
 
 TF1* funz = new TF1 ("funz","pol1",minFit,maxFit);
//  funz->FixParameter(0,0);
 funz->SetParameter(0,0);
 funz->SetParameter(1,1);
 grH.Fit("funz","RMQ");
 std::cerr << " Y = [0] + [1] * X " << std::endl;
 std::cerr << " [0] = " << funz->GetParameter(0) << " +/- " << funz->GetParError(0) << std::endl;
 std::cerr << " [1] = " << funz->GetParameter(1) << " +/- " << funz->GetParError(1) << std::endl;
 double coeffDATA = funz->GetParameter(1);
 double errCoeffDATA = funz->GetParError(1);
 
 gPad->SetGrid();
 
 
 cResultDistro.cd(4);
 HistoRatioMC_SUM->Draw();
 HistoRatioDATA->Draw("E1same");
 tEle.DrawClone();
 gPad->SetGrid();
 gPad->SetLogy();
 
 
 TString nameImage = Form("%s_%s_%d.png",variableY.c_str(),variableX.c_str(),1);
 cResultDistro.SaveAs(nameImage.Data());
 TString nameImageRoot = Form("%s_%s_%d.root",variableY.c_str(),variableX.c_str(),1);
 cResultDistro.SaveAs(nameImageRoot.Data());

 
 
 TCanvas cResultDistroMC("cResultDistroMC","cResultDistroMC",800,800);
 cResultDistroMC.Divide(2,2);
 
 //  cResultDistroMC.Divide(2,nMC);
//  for (int iMC = 0; iMC < nMC; iMC++) {
//   cResultDistroMC.cd(2*iMC+1);
//   HistoMC[iMC]->DrawClone("colz");
//   HistoDATA->DrawClone("BOXsame");
//   cResultDistroMC.cd(2*iMC+2);
//   HistoRatioMC[iMC]->DrawNormalized("");
//   HistoRatioDATA->DrawNormalized("E1same");  
//  }

 cResultDistroMC.cd(1);
 HistoMC_SUM->DrawClone("colz");
 HistoDATA->DrawClone("BOXsame");
 gPad->SetGrid();
 
 ///==== make fit ====
 
 cResultDistroMC.cd(3);
 
 TH1D* MChtemp_prof = smartGausProfileXSQRTN(HistoMC_SUM,2);  
 TGraphErrors MCgrH = buildGEfromH_Personalized(*MChtemp_prof);
 MCgrH.SetMarkerStyle(22);
 MCgrH.SetMarkerSize(0.7);
 MCgrH.SetMarkerColor(kRed);
 MCgrH.SetFillColor(kRed);
 MCgrH.SetFillStyle(3335);
 MCgrH.SetLineWidth(1);
 MCgrH.SetLineColor(kRed);
 MCgrH.GetXaxis()->SetTitle(variableX.c_str());
 MCgrH.GetYaxis()->SetTitle(variableY.c_str());
 
 funz->SetParameter(0,0);
 funz->SetParameter(1,1);
 MCgrH.Fit("funz","RMQ");
 
 std::cerr << " ================= " << std::endl;
 std::cerr << " ======= MC ====== " << std::endl;
 std::cerr << " Y = [0] + [1] * X " << std::endl;
 std::cerr << " [0] = " << funz->GetParameter(0) << " +/- " << funz->GetParError(0) << std::endl;
 std::cerr << " [1] = " << funz->GetParameter(1) << " +/- " << funz->GetParError(1) << std::endl;
 double coeffMC = funz->GetParameter(1);
 double errCoeffMC = funz->GetParError(1);
 
 MCgrH.Draw("APL");
 gPad->SetGrid();
 
 
 cResultDistroMC.cd(4);
 MCgrH.Draw("APL");
 grH.Draw("PLSAME");
 gPad->SetGrid();
 
 
 TString nameImageLog = Form("%s_%s_%d_MC.png",variableY.c_str(),variableX.c_str(),1);
 cResultDistroMC.SaveAs(nameImageLog.Data());
  
 
 std::cerr << " 1 - alpha = " << coeffDATA / coeffMC 
           << " +/- " << sqrt( (errCoeffDATA/coeffMC)*(errCoeffDATA/coeffMC) + (errCoeffMC*coeffDATA/coeffMC/coeffMC)*(errCoeffMC*coeffDATA/coeffMC/coeffMC) )
           << std::endl;


 std::cerr << " alpha = " << 1-coeffDATA / coeffMC 
	   << " +/- " << sqrt( (errCoeffDATA/coeffMC)*(errCoeffDATA/coeffMC) + (errCoeffMC*coeffDATA/coeffMC/coeffMC)*(errCoeffMC*coeffDATA/coeffMC/coeffMC) )
	   << std::endl;
   
   

//  TCanvas cResultDistro_1("cResultDistro_1","cResultDistro_1",800,800);
//  HistoRatioMC_SUM->Draw();
//  HistoRatioDATA->Draw("E1same");
//  tEle.DrawClone();
//  gPad->SetGrid();
//  gPad->SetLogy();
   
}



