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
}
       
TGraphAsymmErrors* FilterBins(std::vector<int> binsToSelect, TGraphAsymmErrors* inputTH) {
  int numbin = binsToSelect.size();
  
  TString name = Form ("%s_new",inputTH->GetName());
  TString title = Form ("%s",inputTH->GetTitle());
  
  TGraphAsymmErrors* newTH = new TGraphAsymmErrors();
  newTH -> SetName (name);
  
  for (int i=0; i< binsToSelect.size(); i++) {

    double Y = (inputTH->GetY()) [i];
    double X = (inputTH->GetX()) [i];
    
    double errXUp      = inputTH->GetErrorXhigh(i);
    double errXDown    = inputTH->GetErrorXlow(i);
    double errYUp      = inputTH->GetErrorYhigh(i);
    double errYDown    = inputTH->GetErrorYlow(i);

    newTH->SetPoint(i, X, Y);
    newTH->SetPointError(i, errXDown, errXUp, errYDown, errYUp);
  }
}



void Plot_AM_2D_testPropaganda_Normal() {
 TString folder = Form("sig/");
 TString cutNameBefore = Form("sig/histo_");

//  TString folder = Form("bkg/");
//  TString cutNameBefore = Form("bkg/histo_");

 //                            cut_variable 
 TString cutNameAfter  = Form("");

 gROOT->LoadMacro("PlotVHqqHggH.C+");
 gInterpreter->ExecuteMacro("../Plot/LatinoStyle2.C");

 TCanvas* c1 = new TCanvas("mll","mll",500,600);
//  TFile* f = new TFile("postFitMll/mH125.root");
 TFile* f = new TFile("postFitDF0J/of0j_mH125.root");


 PlotVHqqHggH* hs = new PlotVHqqHggH();

 hs->setLumi(12.103);
//  hs->setLabel("M_{ll} [GeV]");
 hs->setLabel("unrolled");
 hs->addLabel("    #sqrt{s} = 8 TeV");

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

 ///==== signal (begin) ====

 name = Form("%sggH%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHSig.push_back ( (TH1F*) f->Get(name) );
 vectNameSig.push_back ("ggH m_{H}=125");
 vectColourSig.push_back(633);
 vectScaleSig.push_back(1.0000);
 vectNormalizationSig.push_back(0.719);

 name = Form("%svbfH%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHSig.push_back ( (TH1F*) f->Get(name) );
 vectNameSig.push_back ("qqH m_{H}=125");
 vectColourSig.push_back(634);
 vectScaleSig.push_back(1.0000);
 vectNormalizationSig.push_back(2.565);

 name = Form("%swzttH%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHSig.push_back ( (TH1F*) f->Get(name) );
 vectNameSig.push_back ("VH m_{H}=125");
 vectColourSig.push_back(635);
 vectScaleSig.push_back(1.0000);
 vectNormalizationSig.push_back(0.018);

 ///==== signal (end)  ====

 name = Form("%sData%s",cutNameBefore.Data(),cutNameAfter.Data());
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
 vectNormalizationBkg.push_back(0.281);

 name = Form("%sWJet%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("W+jets");
 vectColourBkg.push_back(921);
 vectSystBkg.push_back(0.36);
 vectScaleBkg.push_back(1.0000);
 vectNormalizationBkg.push_back(0.667);

 name = Form("%sTop%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("top");
 vectColourBkg.push_back(400);
 vectSystBkg.push_back(0.07);
 vectScaleBkg.push_back(0.5369313);
 vectNormalizationBkg.push_back(5.654);

 name = Form("%sDYTT%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("DY+jets");
 vectColourBkg.push_back(418);
 vectSystBkg.push_back(0.11);
 vectScaleBkg.push_back(1.0000);
 vectNormalizationBkg.push_back(0.377);
 name = Form("%sWW%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("WW");
 vectColourBkg.push_back(851);
 vectSystBkg.push_back(0.50);
 vectScaleBkg.push_back(2.0000);
 vectNormalizationBkg.push_back(2.256);
 name = Form("%sggWW%s",cutNameBefore.Data(),cutNameAfter.Data());
 vectTHBkg.push_back ( (TH1F*) f->Get(name) );
 vectNameBkg.push_back ("ggWW");
 vectColourBkg.push_back(853);
 vectSystBkg.push_back(0.00);
 vectScaleBkg.push_back(1.0000);
 vectNormalizationBkg.push_back(2.256);




 ///==== background (end)  ====


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


 hs->set_addSignalOnBackground(1); // 1 = signal over background , 0 = signal on its own

 hs->set_mergeSignal(0);    // 1 = merge signal in 1 bin, 0 = let different signals as it is

 hs->setMass(125); 


 name = Form("%smodel_errs",folder.Data()); 
 std::cout << " name = " << name.Data() << std::endl;  
 hs->set_ErrorBand( *((TGraphAsymmErrors*) f->Get(name) ));  

 ///==== draw ====



 hs->Draw(c1,1,true,false);

 c1->Print("15Oct_AN_HCP_VBFShape_mll_postFitLatino_2/mll.pdf");
 c1->Print("15Oct_AN_HCP_VBFShape_mll_postFitLatino_2/mll.png");

 c1->SetLogy();
 hs->Draw(c1,1,true);
 c1->Print("15Oct_AN_HCP_VBFShape_mll_postFitLatino_2/mll_logy.pdf");
 c1->Print("15Oct_AN_HCP_VBFShape_mll_postFitLatino_2/mll_logy.png");
 
 
 
 TCanvas* c2 = new TCanvas("mll_prop","mll_prop",1000,1000);
//  hs->DrawPropagandaPlot(c2,1);
//  hs->DrawPropagandaPlot(c2,1,10,"m_{ll} [GeV]",0,200,"m_{T}^{ll-E_{T}^{miss}} [GeV]",80,280);
 hs->DrawPropagandaPlot(c2,1,8,"m_{T}^{ll-E_{T}^{miss}} [GeV]",80,280,"m_{ll} [GeV]",0,200);
 
//  10,80,280,8,0,200
 
 
 c2->Print("15Oct_AN_HCP_VBFShape_mll_postFitLatino_2/mll_prop.pdf");
 c2->Print("15Oct_AN_HCP_VBFShape_mll_postFitLatino_2/mll_prop.png");        
        
}


