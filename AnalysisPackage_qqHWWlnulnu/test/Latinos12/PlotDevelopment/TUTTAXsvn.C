#include "TString.h"
#include "TH1F.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TFile.h"

#include "PlotVHqqHggH.C"


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



void TUTTAXsvn() {
 
 float SCALEMU = 1.0/0.8;
 
 TString folder = Form("sig/");
 TString cutNameBefore = Form("sig/histo_");
 
 //  TString folder = Form("init/");
 //  TString cutNameBefore = Form("init/histo_");
 
 //  TString folder = Form("bkg/");
 //  TString cutNameBefore = Form("bkg/histo_");
 
 //                            cut_variable 
 TString cutNameAfter  = Form("");
 
 gROOT->LoadMacro("PlotVHqqHggH.C+");
 gInterpreter->ExecuteMacro("../Plot/LatinoStyle2.C");
 
 TCanvas* c1 = new TCanvas("mll","mll",500,600);
 //  TFile* f = new TFile("postFitMll/mH125.root");
 //  TFile* f = new TFile("postFitDF0J/of0j_mH125.root");
 
 
 
//  bool do7and8TeV = true;
 bool do7and8TeV = true;
//  TFile* f0 = new TFile("postFit0J-SS/mH125-0j-SS.root");
 
 
 
 TFile* f1 = new TFile("mH125-error-SVN.root");
 TFile* f2 = new TFile("mH125-error-SVN.root");
 TFile* f0 = new TFile("mH125-error-SVN.root");
 TFile* f3 = new TFile("mH125-error-SVN.root");
 
 TString cutNameBeforeBIN0 = Form ("hwwof0j7TeV/histo_");
 TString cutNameBeforeBIN1 = Form ("hwwof1j7TeV/histo_");
 TString cutNameBeforeBIN2 = Form ("hwwof0j8TeV/histo_");
 TString cutNameBeforeBIN3 = Form ("hwwof1j8TeV/histo_");

 TString folderError0 = Form ("hwwof0j7TeV/");
 TString folderError1 = Form ("hwwof1j7TeV/");
 TString folderError2 = Form ("hwwof0j8TeV/");
 TString folderError3 = Form ("hwwof1j8TeV/");
 
 
 PlotVHqqHggH* hs = new PlotVHqqHggH();
 
//  hs->setLumi(12.103);
 if (do7and8TeV) {
  hs->setLumi(19.5+4.9);
 }
 else {
  hs->setLumi(19.5);
 }
 //  hs->setLabel("M_{ll} [GeV]");
 hs->setLabel("m_{T}^{ll-E_{T}^{miss}}");
 hs->setUnits("GeV");
 hs->addLabel("0+1 jet  #sqrt{s} = 7+8 TeV");
 
 TString name;
 
 std::vector<int> vectColourBkg;        
 std::vector<double> vectSystBkg;       
 std::vector<double> vectScaleBkg;      
 std::vector<std::string> vectNameBkg;  
 std::vector<double> vectNormalizationBkg; 
 std::vector<TH1F*> vectTHBkg;          
 
 std::vector<int> vectColourSig;      
 std::vector<double> vectSystSig;       
 std::vector<double> vectScaleSig;      
 std::vector<std::string> vectNameSig;  
 std::vector<double> vectNormalizationSig; 
 std::vector<TH1F*> vectTHSig;          
 
 
 std::vector<int> binsToSelect; 
 
 //  x HCP 2012
 //   int NMAXX = 10;  
 //   int NMAXY = 8;  
 //   int NX = 4;
 //   int NY = 4;
 
 
 //---- nice subregion ----
 // int NX = 6;
 // int NX = 9;
//  int NY = 5;
 // int NX = 8;
//   int NX = 6;
//   int NY = 4;
//   int NY = 3;

 
//  //  x Moriond 2013
//  int NMAXX = 14;  
//  int NMAXY = 9;  
//  // int NX = 8;
//  
//  int minNY = 0;
//  int NY = 3;
//  
//  //---- all ----
//  int NX = NMAXX;
// //  int NY = NMAXY;
//  
//  
 
 
 
 
 //  x Moriond 2013 : all 2D plane: weighted approach
 int NMAXX = 14;  
 int NMAXY = 9;  
 // int NX = 8;
 
 int NX = NMAXX;
 int minNY = 0;
 int NY = NMAXY;
 
 
 
 
 
 
 ///---- project along X : sum over Y
 for (int iY=minNY; iY<NY; iY++){
  binsToSelect.clear();
  for (int iX=0; iX<NX; iX++){
   binsToSelect.push_back (iX*NMAXY+iY+1);
   std::cout << " iX*NY+iY+1 = " << iX*NY+iY+1 << std::endl;
  }
  
  
  ///==== signal (begin) ====
  
  TString cutNameBeforeUpdated = Form ("%s%s",folder.Data(),cutNameBeforeBIN0.Data());
  
  //---- second file :: 0 jet bin
  name = Form("%sggH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameSig.push_back ("ggH m_{H}=125");
  vectColourSig.push_back(633);
  vectScaleSig.push_back(SCALEMU*1.0000);
  vectNormalizationSig.push_back(0.719);
  
  name = Form("%sqqH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameSig.push_back ("qqH m_{H}=125");
  vectColourSig.push_back(634);
  vectScaleSig.push_back(SCALEMU*1.0000);
  vectNormalizationSig.push_back(2.565);
  
//   name = Form("%sZH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
//   std::cout << " name = " << name.Data() << std::endl;
//   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
//   vectNameSig.push_back ("VH m_{H}=125");
//   vectColourSig.push_back(635);
//   vectScaleSig.push_back(SCALEMU*1.0000);
//   vectNormalizationSig.push_back(0.018);
// 
//   name = Form("%sWH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
//   std::cout << " name = " << name.Data() << std::endl;
//   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
//   vectNameSig.push_back ("VH m_{H}=125");
//   vectColourSig.push_back(635);
//   vectScaleSig.push_back(SCALEMU*1.0000);
//   vectNormalizationSig.push_back(0.018);
  
  ///==== signal (end)  ====
  
  name = Form("%sData%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  hs->setDataHist (FilterBins(binsToSelect, (TH1F*) f0->Get(name)));
  
  ///==== background (begin)  ====
  
  //---- second file :: 0 jet bin
  
  name = Form("%sVV%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("WZ/ZZ");
  vectColourBkg.push_back(858);
  vectSystBkg.push_back(0.00);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(0.281);
  
  name = Form("%sWjetsE%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("W+jets");
  vectColourBkg.push_back(921);
  vectSystBkg.push_back(0.36);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(0.667);

  name = Form("%sWjetsM%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("W+jets");
  vectColourBkg.push_back(921);
  vectSystBkg.push_back(0.36);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(0.667);
  
  name = Form("%sWgamma%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("V+#gamma");
  vectColourBkg.push_back(616+1);
  vectSystBkg.push_back(0.00);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(1.000);
  
  name = Form("%sWg3l%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("V+#gamma*");
  vectColourBkg.push_back(616+2);
  vectSystBkg.push_back(0.00);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(1.000);
  
  
  name = Form("%sTop%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("top");
  vectColourBkg.push_back(400);
  vectSystBkg.push_back(0.07);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(5.654);
  
  name = Form("%sZjets%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("DY+jets");
  vectColourBkg.push_back(418);
  vectSystBkg.push_back(0.11);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(0.377);
 
  name = Form("%sqqWW%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("WW");
  vectColourBkg.push_back(851);
  vectSystBkg.push_back(0.50);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(2.256);
  name = Form("%sggWW%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
  std::cout << " name = " << name.Data() << std::endl;
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("ggWW");
  vectColourBkg.push_back(853);
  vectSystBkg.push_back(0.00);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(2.256);
  
  ///==== background (end)  ====
  
  
  
  if (do7and8TeV) {
   ///==== signal (begin) ====
   cutNameBeforeUpdated = Form ("%s%s",folder.Data(),cutNameBeforeBIN1.Data());
   
   //---- second file :: 0 jet bin
   name = Form("%sggH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameSig.push_back ("ggH m_{H}=125");
   vectColourSig.push_back(633);
   vectScaleSig.push_back(SCALEMU*1.0000);
   vectNormalizationSig.push_back(0.719);
   
   name = Form("%sqqH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameSig.push_back ("qqH m_{H}=125");
   vectColourSig.push_back(634);
   vectScaleSig.push_back(SCALEMU*1.0000);
   vectNormalizationSig.push_back(2.565);
   
//    name = Form("%sZH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
//    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
//    vectNameSig.push_back ("VH m_{H}=125");
//    vectColourSig.push_back(635);
//    vectScaleSig.push_back(SCALEMU*1.0000);
//    vectNormalizationSig.push_back(0.018);
// 
//    name = Form("%sWH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
//    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
//    vectNameSig.push_back ("VH m_{H}=125");
//    vectColourSig.push_back(635);
//    vectScaleSig.push_back(SCALEMU*1.0000);
//    vectNormalizationSig.push_back(0.018);
   
   ///==== signal (end)  ====
   
   name = Form("%sData%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   hs->setDataHist (FilterBins(binsToSelect, (TH1F*) f1->Get(name)));
   
   ///==== background (begin)  ====
   
   //---- second file :: 0 jet bin
   
   name = Form("%sVV%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("WZ/ZZ");
   vectColourBkg.push_back(858);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.281);
   
   name = Form("%sWjetsE%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.36);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);

   name = Form("%sWjetsM%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.36);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);
   
   name = Form("%sWgamma%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("V+#gamma");
   vectColourBkg.push_back(616+1);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   name = Form("%sWg3l%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("V+#gamma*");
   vectColourBkg.push_back(616+2);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   
   name = Form("%sTop%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("top");
   vectColourBkg.push_back(400);
   vectSystBkg.push_back(0.07);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(5.654);
   
   name = Form("%sZjets%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("DY+jets");
   vectColourBkg.push_back(418);
   vectSystBkg.push_back(0.11);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.377);
 
   name = Form("%sqqWW%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("WW");
   vectColourBkg.push_back(851);
   vectSystBkg.push_back(0.50);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.256);
   
   name = Form("%sggWW%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("ggWW");
   vectColourBkg.push_back(853);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.256);
   
   ///==== background (end)  ====
   
   
   
   
   
   ///==== signal (begin) ====
   cutNameBeforeUpdated = Form ("%s%s",folder.Data(),cutNameBeforeBIN2.Data());
   
   //---- second file :: 0 jet bin
   name = Form("%sggH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameSig.push_back ("ggH m_{H}=125");
   vectColourSig.push_back(633);
   vectScaleSig.push_back(SCALEMU*1.0000);
   vectNormalizationSig.push_back(0.719);
   
   name = Form("%sqqH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameSig.push_back ("qqH m_{H}=125");
   vectColourSig.push_back(634);
   vectScaleSig.push_back(SCALEMU*1.0000);
   vectNormalizationSig.push_back(2.565);
   
//    name = Form("%sZH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
//    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
//    vectNameSig.push_back ("VH m_{H}=125");
//    vectColourSig.push_back(635);
//    vectScaleSig.push_back(SCALEMU*1.0000);
//    vectNormalizationSig.push_back(0.018);
//    
//    name = Form("%sWH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
//    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
//    vectNameSig.push_back ("VH m_{H}=125");
//    vectColourSig.push_back(635);
//    vectScaleSig.push_back(SCALEMU*1.0000);
//    vectNormalizationSig.push_back(0.018);
   
   ///==== signal (end)  ====
   
   name = Form("%sData%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   hs->setDataHist (FilterBins(binsToSelect, (TH1F*) f2->Get(name)));
   
   ///==== background (begin)  ====
   
   //---- second file :: 0 jet bin
   
   name = Form("%sVV%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameBkg.push_back ("WZ/ZZ");
   vectColourBkg.push_back(858);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.281);
   
   name = Form("%sWjetsE%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.36);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);
   
   name = Form("%sWjetsM%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.36);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);
   
   name = Form("%sWgamma%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameBkg.push_back ("V+#gamma");
   vectColourBkg.push_back(616+1);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   name = Form("%sWg3l%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameBkg.push_back ("V+#gamma*");
   vectColourBkg.push_back(616+2);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   
   name = Form("%sTop%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameBkg.push_back ("top");
   vectColourBkg.push_back(400);
   vectSystBkg.push_back(0.07);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(5.654);
   
   name = Form("%sZtt%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameBkg.push_back ("DY+jets");
   vectColourBkg.push_back(418);
   vectSystBkg.push_back(0.11);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.377);
   name = Form("%sqqWW%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameBkg.push_back ("WW");
   vectColourBkg.push_back(851);
   vectSystBkg.push_back(0.50);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.256);
   name = Form("%sggWW%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f2->Get(name)) );
   vectNameBkg.push_back ("ggWW");
   vectColourBkg.push_back(853);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.256);
   
   ///==== background (end)  ====
   
   
   
   
   
   
   
   
   
   
   
   
   
   ///==== signal (begin) ====
   cutNameBeforeUpdated = Form ("%s%s",folder.Data(),cutNameBeforeBIN3.Data());
   
   //---- second file :: 0 jet bin
   name = Form("%sggH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameSig.push_back ("ggH m_{H}=125");
   vectColourSig.push_back(633);
   vectScaleSig.push_back(SCALEMU*1.0000);
   vectNormalizationSig.push_back(0.719);
   
   name = Form("%sqqH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameSig.push_back ("qqH m_{H}=125");
   vectColourSig.push_back(634);
   vectScaleSig.push_back(SCALEMU*1.0000);
   vectNormalizationSig.push_back(2.565);
   
//    name = Form("%sZH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
//    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
//    vectNameSig.push_back ("VH m_{H}=125");
//    vectColourSig.push_back(635);
//    vectScaleSig.push_back(SCALEMU*1.0000);
//    vectNormalizationSig.push_back(0.018);
//    
//    name = Form("%sWH%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
//    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
//    vectNameSig.push_back ("VH m_{H}=125");
//    vectColourSig.push_back(635);
//    vectScaleSig.push_back(SCALEMU*1.0000);
//    vectNormalizationSig.push_back(0.018);
   
   ///==== signal (end)  ====
   
   name = Form("%sData%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   hs->setDataHist (FilterBins(binsToSelect, (TH1F*) f3->Get(name)));
   
   ///==== background (begin)  ====
   
   //---- second file :: 0 jet bin
   
   name = Form("%sVV%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameBkg.push_back ("WZ/ZZ");
   vectColourBkg.push_back(858);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.281);
   
   name = Form("%sWjetsE%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.36);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);
   
   name = Form("%sWjetsM%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.36);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);
   
   name = Form("%sWgamma%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameBkg.push_back ("V+#gamma");
   vectColourBkg.push_back(616+1);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   name = Form("%sWg3l%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameBkg.push_back ("V+#gamma*");
   vectColourBkg.push_back(616+2);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   
   name = Form("%sTop%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameBkg.push_back ("top");
   vectColourBkg.push_back(400);
   vectSystBkg.push_back(0.07);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(5.654);
   
   name = Form("%sZtt%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameBkg.push_back ("DY+jets");
   vectColourBkg.push_back(418);
   vectSystBkg.push_back(0.11);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.377);
   name = Form("%sqqWW%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameBkg.push_back ("WW");
   vectColourBkg.push_back(851);
   vectSystBkg.push_back(0.50);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.256);
   name = Form("%sggWW%s",cutNameBeforeUpdated.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f3->Get(name)) );
   vectNameBkg.push_back ("ggWW");
   vectColourBkg.push_back(853);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.256);
   
   ///==== background (end)  ====
  }
  
  hs->setBlindBinSx(0);
  hs->setBlindBinDx(0);
  
  hs->setCutSx(-999,">");
  hs->setCutDx(-999,"<");
  
  
  name = Form("%s%smodel_errs",folder.Data(),folderError0.Data()); 
  std::cout << " name = " << name.Data() << std::endl;  
  
  hs->set_ErrorBand( *(FilterBins(binsToSelect, (TGraphAsymmErrors*) f0->Get(name))) , 1.0);  

  if (do7and8TeV) {
   name = Form("%s%smodel_errs",folder.Data(),folderError1.Data()); 
   hs->set_ErrorBand( *(FilterBins(binsToSelect, (TGraphAsymmErrors*) f1->Get(name))), 1.0 );  
   name = Form("%s%smodel_errs",folder.Data(),folderError2.Data()); 
   hs->set_ErrorBand( *(FilterBins(binsToSelect, (TGraphAsymmErrors*) f2->Get(name))), 1.0 );  
   name = Form("%s%smodel_errs",folder.Data(),folderError3.Data()); 
   hs->set_ErrorBand( *(FilterBins(binsToSelect, (TGraphAsymmErrors*) f3->Get(name))), 1.0 );  
  }
  
 }
 
 hs->set_vectTHBkg     (vectTHBkg);      
 hs->set_vectNameBkg   (vectNameBkg);    
 hs->set_vectColourBkg (vectColourBkg);  
 hs->set_vectSystBkg   (vectSystBkg);    
 hs->set_vectScaleBkg  (vectScaleBkg);   
 
 hs->set_vectTHSig     (vectTHSig);      
 hs->set_vectNameSig   (vectNameSig);    
 hs->set_vectColourSig (vectColourSig);  
 hs->set_vectScaleSig  (vectScaleSig);   
 
 
 hs->addWeight(NY-minNY); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
 
 hs->prepare();
 
 hs->mergeSamples(); //---- merge trees with the same name! ---- to be called after "prepare" !
 
 hs->set_addSignalOnBackground(1); // 1 = signal over background , 0 = signal on its own
 
 hs->set_mergeSignal(1);    // 1 = merge signal in 1 bin, 0 = let different signals as it is
 
 hs->setMass(125); 
 
 
 //  hs->set_doLabelNumber ( true ) ;
 hs->set_doLabelNumber ( false ) ;
 
 ///==== draw ====
 
 
 TCanvas* c1bis = new TCanvas("bkgSub","bkgSub",500,500);
 
 //  hs->Draw(c1,1,true,false);
 
 double vedges[] = {60,70,80,90,100,110,120,140,160,180,200,220,240,260,280};
 std::vector<double> vEdges (vedges, vedges + sizeof(vedges) / sizeof(double) );
 hs->set_vectEdges(vEdges);
 
 //----  canvas, rebin, div, shadow, background subtracted canvas ----
//  hs->Draw(c1,1,true,true,c1bis);
 hs->Draw(c1,1,true,true,c1bis, 416.8369, 1); //--- last 1 = scaleEvenData
 
 
 
//  wwof0j8TeV  hwwof0j7TeV   hwwof1j8TeV  hwwof1j7TeV  
//  ZH           qqH          WH           ggH          qqWW         WjetsE       Wgamma       Top          WH_SM        WjetsM       ggWW         ZH_SM        VV           Wg3l         qqH_SM       Ztt          Zjets        ggH_SM       ZH           qqH          WH           ggH          qqWW         WjetsE       Wgamma       Top          WH_SM        WjetsM       ggWW         ZH_SM        VV           Wg3l         qqH_SM       Ztt          Zjets        ggH_SM       ZH           qqH          WH           ggH          qqWW         WjetsE       Wgamma       Top          WH_SM        WjetsM       ggWW         ZH_SM        VV           Wg3l         qqH_SM       Ztt          Zjets        ggH_SM       ZH           qqH          WH           ggH          qqWW         WjetsE       Wgamma       Top          WH_SM        WjetsM       ggWW         ZH_SM        VV           Wg3l         qqH_SM       Ztt          Zjets        ggH_SM     
//  1.6890       2.9300       5.7010       228.1320     3981.6900    284.7300     115.5780     499.3620     0.0000       332.2130     211.2640     0.0000       132.6090     130.6960     0.0000       45.9960      0.0000       0.0000       0.0000       0.4419       0.0000       50.3398      828.8020     88.2650      19.7200      91.2240      0.0000       62.7310      40.7510      0.0000       17.7360      36.4310      0.0000       0.0000       4.9230       0.0000       1.9230       11.1300      6.8780       88.5170      1203.1000    130.4020     29.0790      1436.8000    0.0000       153.0200     69.0100      0.0000       116.5920     19.9750      0.0000       76.7570      0.0000       0.0000       0.0000       2.0871       0.0000       17.0681      246.2790     34.3560      3.5800       226.6520     0.0000       26.1930      13.9840      0.0000       18.1110      4.8070       0.0000       0.0000       8.3280       0.0000    
// 
//all signals =   1.6890  +     2.9300   +    5.7010     +  228.1320 +  0.0 +   0.4419  +     0.0000  +     50.3398 + 1.9230     +  11.1300  +    6.8780  +     88.5170 +  0.0000      + 2.0871  +     0.0000  +     17.0681
//            = 416.8369     
 
 
 c1->Print("mth.pdf");
 c1->Print("mth.png");
 c1->Print("mth.eps");
 
 c1bis->Print("bkgSub_mth.pdf");
 c1bis->Print("bkgSub_mth.png");
 c1bis->Print("bkgSub_mth.eps");
 
 //  c1->SetLogy();
 //  hs->Draw(c1,1,true);
 //  c1->Print("15Oct_AN_HCP_VBFShape_mll_postFitLatino_2/mll_logy.pdf");
 //  c1->Print("15Oct_AN_HCP_VBFShape_mll_postFitLatino_2/mll_logy.png");
 
 
 //  return ([60,70,80,90,100,110,120,140,160,180,200,220,240,260,280],[12,30,45,60,75,100,125,150,175,200])
 //                       mth                                                   mll
 
 //  TCanvas* c2 = new TCanvas("mll_prop","mll_prop",1000,1000);
 //  double maxX = 10*NX+60;
 //  //  double maxY = 15*NY+12;
 //  double maxY = 15*NY+15;
 //  std::cout << " maxX = " << maxX << std::endl;
 //  std::cout << " maxY = " << maxY << std::endl;
 //  std::cout << " NY   = " << NY   << std::endl;
 //  hs->DrawPropagandaPlot(c2,1,NY,"m_{T}^{ll-E_{T}^{miss}} [GeV]",60,maxX,"m_{ll} [GeV]",12,maxY);
 //  
 //  
 //  //---------------------------------------
 //  // // // //  x HCP 2012 // // // // 
 //  //   TCanvas* c2 = new TCanvas("mll_prop","mll_prop",1000,1000);
 //  //   double maxX = (280-80)/10*NX+80;
 //  //   double maxY = (200-0)/8*NY+0;
 //  //   std::cout << " maxX = " << maxX << std::endl;
 //  //   std::cout << " maxY = " << maxY << std::endl;
 //  //   std::cout << " NY   = " << NY   << std::endl;
 //  //   hs->DrawPropagandaPlot(c2,1,NY,"m_{T}^{ll-E_{T}^{miss}} [GeV]",80,maxX,"m_{ll} [GeV]",0,maxY);
 //  
 //  c2->Print("mll_prop.pdf");
 //  c2->Print("mll_prop.png");        
 //  c2->Print("mll_prop.eps");
 
}


