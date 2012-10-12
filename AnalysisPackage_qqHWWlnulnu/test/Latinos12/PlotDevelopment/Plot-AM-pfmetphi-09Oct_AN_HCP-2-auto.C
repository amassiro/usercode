#include "TString.h"
#include "TH1F.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TFile.h"

  #include "PlotVHqqHggH.C"


void Plot_AM_pfmetphi_09Oct_AN_HCP_2_auto() {
 TString cutNameBefore = Form("Data/");

 //                            cut_variable 
 TString cutNameAfter  = Form("_2_14_Tot_temp");

 gROOT->LoadMacro("PlotVHqqHggH.C+");
 gInterpreter->ExecuteMacro("../Plot/LatinoStyle2.C");

 TCanvas* c1 = new TCanvas("pfmetphi","pfmetphi",500,600);
 TFile* f = new TFile("~/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/out_test_Latinos_09Oct2012_2200_Run2012ABC_8TeV_HCP_ForNote.root");


 PlotVHqqHggH* hs = new PlotVHqqHggH();

 hs->setLumi(12.103);
 hs->setLabel("#phi-PF-E_{T}^{miss}");
 hs->addLabel("    #sqrt{s} = 8 TeV");

 TString name;

 std::vector<int> vectColourBkg;        
 std::vector<double> vectSystBkg;       
 std::vector<double> vectScaleBkg;      
 std::vector<std::string> vectNameBkg;  
 std::vector<TH1F*> vectTHBkg;          

 std::vector<int> vectColourSig;      
 std::vector<double> vectSystSig;       
 std::vector<double> vectScaleSig;      
 std::vector<std::string> vectNameSig;  
 std::vector<TH1F*> vectTHSig;          

 ///==== signal (begin) ====

 name = Form("%sggH-125%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHSig.push_back ( (TH1F*) f->Get(name) );
 vectNameSig.push_back ("ggH m_{H}=125");
 vectColourSig.push_back(633);
 vectScaleSig.push_back(1.0000);

 name = Form("%sqqH-125%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHSig.push_back ( (TH1F*) f->Get(name) );
 vectNameSig.push_back ("qqH m_{H}=125");
 vectColourSig.push_back(634);
 vectScaleSig.push_back(1.0000);

 name = Form("%sVH-125%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHSig.push_back ( (TH1F*) f->Get(name) );
 vectNameSig.push_back ("VH m_{H}=125");
 vectColourSig.push_back(635);
 vectScaleSig.push_back(1.0000);

 ///==== signal (end)  ====

 name = Form("%sDATA%s",cutNameBefore.Data(),cutNameAfter.Data());
 hs->setDataHist ((TH1F*)f->Get(name));



 hs->setBlindBinSx(0);
 hs->setBlindBinDx(0);

 hs->setCutSx(-999,">");
 hs->setCutDx(-999,"<");


 ///==== background (begin)  ====
 name = Form("%sVV%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("WZ/ZZ");
 vectColourBkg.push_back(858);
 vectSystBkg.push_back(0.00);
 vectScaleBkg.push_back(1.0000);
 name = Form("%sFake%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("W+jets");
 vectColourBkg.push_back(921);
 vectSystBkg.push_back(0.36);
 vectScaleBkg.push_back(1.0000);

 name = Form("%sWg%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("W+#gamma");
 vectColourBkg.push_back(922);
 vectSystBkg.push_back(0.00);
 vectScaleBkg.push_back(1.0000);

 name = Form("%sTop%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("top");
 vectColourBkg.push_back(400);
 vectSystBkg.push_back(0.07);
 vectScaleBkg.push_back(1.0000);

 name = Form("%sDYee%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("DYee+jets");
 vectColourBkg.push_back(417);
 vectSystBkg.push_back(0.11);
 vectScaleBkg.push_back(1.00);

 name = Form("%sDYmumu%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("DY#mu#mu+jets");
 vectColourBkg.push_back(416);
 vectSystBkg.push_back(0.11);
 vectScaleBkg.push_back(1.00);

 name = Form("%sDYtautau%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("DY#tau#tau+jets");
 vectColourBkg.push_back(418);
 vectSystBkg.push_back(0.00);
 vectScaleBkg.push_back(1.000);

 name = Form("%sWW%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("WW");
 vectColourBkg.push_back(851);
 vectSystBkg.push_back(0.00);
 vectScaleBkg.push_back(1.0000);




 ///==== background (end)  ====


 hs->set_vectTHBkg     (vectTHBkg);      
 hs->set_vectNameBkg   (vectNameBkg);    
 hs->set_vectColourBkg (vectColourBkg);  
 hs->set_vectSystBkg   (vectSystBkg);    
 hs->set_vectScaleBkg  (vectScaleBkg);   

 hs->set_vectTHSig     (vectTHSig);      
 hs->set_vectNameSig   (vectNameSig);    
 hs->set_vectColourSig (vectColourSig);  
 hs->set_vectScaleSig  (vectScaleSig);   

 hs->prepare();


 ///==== draw ====



 hs->Draw(c1,1,true);

 c1->Print("09Oct_AN_HCP_2/pfmetphi.pdf");
 c1->Print("09Oct_AN_HCP_2/pfmetphi.png");

 c1->SetLogy();
 hs->Draw(c1,1,true);
 c1->Print("09Oct_AN_HCP_2/pfmetphi_logy.pdf");
 c1->Print("09Oct_AN_HCP_2/pfmetphi_logy.png");
}


