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



void Plot_AM_2D_7plus8TeV_projectionY_testPropaganda() {
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
 
 
 bool do7and8TeV = true;
//  bool do7and8TeV = false;
 
  TFile* f1 = new TFile("postFitDF01J-78TeV/mH125_4.94fb_of_0j.root");
//  TFile* f1 = new TFile("postFitDF01J-78TeV/mH125_4.94fb_of_1j.root");
  TFile* f0 = new TFile("postFitDF01J-78TeV/mH125_19.47fb_of_0j.root");
//  TFile* f0 = new TFile("postFitDF01J-78TeV/mH125_19.47fb_of_1j.root");
 
  
 //  TFile* f0 = new TFile("postFitDF0J-7TeV-old/mH125.root");
 //  TFile* f1 = new TFile("postFitDF0J-8TeV-old/mH125.root");
 
 
 
 PlotVHqqHggH* hs = new PlotVHqqHggH();
 
 //  hs->setLumi(12.103);
 if (do7and8TeV) {
  hs->setLumi(19.5+4.9);
 }
 else {
  hs->setLumi(19.5);
 }
 //  hs->setLabel("M_{ll} [GeV]");
 hs->setLabel("m_{ll} [GeV]");
 hs->addLabel("0 jet  #sqrt{s} = 8 TeV");
 
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
 
 //  x Moriond 2013
 int NMAXX = 14;  
 int NMAXY = 9;  
 // int NX = 8;
 
 //---- nice subregion ----
 // int NX = 6;
 // int NX = 9;
 // int NY = 5;
 // int NX = 8;
//  int NX = 6;
//  int NY = 4;
 
 
 int minNX = 2;
 int NX = 7;
 
 
 //---- all ----
//  int NX = NMAXX;
 int NY = NMAXY;
 
 
 ///---- project along Y : sum over X
 for (int iX=minNX; iX<NX; iX++){
  binsToSelect.clear();
  for (int iY=0; iY<NY; iY++){
   binsToSelect.push_back (iX*NMAXY+iY+1);
   std::cout << " iX*NY+iY+1 = " << iX*NY+iY+1 << std::endl;
  }
  
  
  ///==== signal (begin) ====
  
  //---- second file :: 0 jet bin
  name = Form("%sggH%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameSig.push_back ("ggH m_{H}=125");
  vectColourSig.push_back(633);
  vectScaleSig.push_back(1.0000);
  vectNormalizationSig.push_back(0.719);
  
  name = Form("%svbfH%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameSig.push_back ("qqH m_{H}=125");
  vectColourSig.push_back(634);
  vectScaleSig.push_back(1.0000);
  vectNormalizationSig.push_back(2.565);
  
  name = Form("%swzttH%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameSig.push_back ("VH m_{H}=125");
  vectColourSig.push_back(635);
  vectScaleSig.push_back(1.0000);
  vectNormalizationSig.push_back(0.018);
  
  ///==== signal (end)  ====
  
  name = Form("%sData%s",cutNameBefore.Data(),cutNameAfter.Data());
  hs->setDataHist (FilterBins(binsToSelect, (TH1F*) f0->Get(name)));
  
  ///==== background (begin)  ====
  
  //---- second file :: 0 jet bin
  
  name = Form("%sVV%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("WZ/ZZ");
  vectColourBkg.push_back(858);
  vectSystBkg.push_back(0.00);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(0.281);
  
  name = Form("%sWJet%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("W+jets");
  vectColourBkg.push_back(921);
  vectSystBkg.push_back(0.36);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(0.667);
  
  name = Form("%sVg%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("V+#gamma");
  vectColourBkg.push_back(616+1);
  vectSystBkg.push_back(0.00);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(1.000);
  
  name = Form("%sVgS%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("V+#gamma*");
  vectColourBkg.push_back(616+2);
  vectSystBkg.push_back(0.00);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(1.000);
  
  
  name = Form("%sTop%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("top");
  vectColourBkg.push_back(400);
  vectSystBkg.push_back(0.07);
  vectScaleBkg.push_back(0.5369313);
  vectNormalizationBkg.push_back(5.654);
  
  name = Form("%sDYTT%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("DY+jets");
  vectColourBkg.push_back(418);
  vectSystBkg.push_back(0.11);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(0.377);
  name = Form("%sWW%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("WW");
  vectColourBkg.push_back(851);
  vectSystBkg.push_back(0.50);
  vectScaleBkg.push_back(2.0000);
  vectNormalizationBkg.push_back(2.256);
  name = Form("%sggWW%s",cutNameBefore.Data(),cutNameAfter.Data());
  vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f0->Get(name)) );
  vectNameBkg.push_back ("ggWW");
  vectColourBkg.push_back(853);
  vectSystBkg.push_back(0.00);
  vectScaleBkg.push_back(1.0000);
  vectNormalizationBkg.push_back(2.256);
  
  ///==== background (end)  ====
  
  
  
  if (do7and8TeV) {
   
   
   ///==== signal (begin) ====
   
   //---- second file :: 0 jet bin
   name = Form("%sggH%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameSig.push_back ("ggH m_{H}=125");
   vectColourSig.push_back(633);
   vectScaleSig.push_back(1.0000);
   vectNormalizationSig.push_back(0.719);
   
   name = Form("%svbfH%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameSig.push_back ("qqH m_{H}=125");
   vectColourSig.push_back(634);
   vectScaleSig.push_back(1.0000);
   vectNormalizationSig.push_back(2.565);
   
   name = Form("%swzttH%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameSig.push_back ("VH m_{H}=125");
   vectColourSig.push_back(635);
   vectScaleSig.push_back(1.0000);
   vectNormalizationSig.push_back(0.018);
   
   ///==== signal (end)  ====
   
   name = Form("%sData%s",cutNameBefore.Data(),cutNameAfter.Data());
   hs->setDataHist (FilterBins(binsToSelect, (TH1F*) f1->Get(name)));
   
   ///==== background (begin)  ====
   
   //---- second file :: 0 jet bin
   
   name = Form("%sVV%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("WZ/ZZ");
   vectColourBkg.push_back(858);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.281);
   
   name = Form("%sWJet%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.36);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);
   
   name = Form("%sVg%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("V+#gamma");
   vectColourBkg.push_back(616+1);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   name = Form("%sVgS%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("V+#gamma*");
   vectColourBkg.push_back(616+2);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   
   name = Form("%sTop%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("top");
   vectColourBkg.push_back(400);
   vectSystBkg.push_back(0.07);
   vectScaleBkg.push_back(0.5369313);
   vectNormalizationBkg.push_back(5.654);
   
   name = Form("%sDYTT%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("DY+jets");
   vectColourBkg.push_back(418);
   vectSystBkg.push_back(0.11);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.377);
   name = Form("%sWW%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
   vectNameBkg.push_back ("WW");
   vectColourBkg.push_back(851);
   vectSystBkg.push_back(0.50);
   vectScaleBkg.push_back(2.0000);
   vectNormalizationBkg.push_back(2.256);
   name = Form("%sggWW%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f1->Get(name)) );
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
  
  
  name = Form("%smodel_errs",folder.Data()); 
  std::cout << " name = " << name.Data() << std::endl;  
  
  
  hs->set_ErrorBand( *(FilterBins(binsToSelect, (TGraphAsymmErrors*) f0->Get(name))) );  
  
  if (do7and8TeV) {
    hs->set_ErrorBand( *(FilterBins(binsToSelect, (TGraphAsymmErrors*) f1->Get(name))) );  
  }
  
 }
 
 hs->set_vectTHBkg     (vectTHBkg);      
 hs->set_vectNameBkg   (vectNameBkg);    
 hs->set_vectColourBkg (vectColourBkg);  
 hs->set_vectSystBkg   (vectSystBkg);    
 // hs->set_vectScaleBkg  (vectScaleBkg);   
 
 hs->set_vectTHSig     (vectTHSig);      
 hs->set_vectNameSig   (vectNameSig);    
 hs->set_vectColourSig (vectColourSig);  
 // hs->set_vectScaleSig  (vectScaleSig);   
 
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
 
 double vedges[] = {12,30,45,60,75,100,125,150,175,200};
 std::vector<double> vEdges (vedges, vedges + sizeof(vedges) / sizeof(double) );
 hs->set_vectEdges(vEdges);
 
 //----  canvas, rebin, div, shadow, background subtracted canvas ----
 hs->Draw(c1,1,true,true,c1bis);
 
 c1->Print("mll.pdf");
 c1->Print("mll.png");
 c1->Print("mll.eps");
 
 c1bis->Print("bkgSub_mll.pdf");
 c1bis->Print("bkgSub_mll.png");
 c1bis->Print("bkgSub_mll.eps");
 
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


