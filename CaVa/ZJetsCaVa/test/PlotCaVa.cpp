
///================= program to show CaVa =================

#include "treeReader.h"
#include "hFactory.h"
#include "hFunctions.h"
#include "stdHisto.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"


#include <iostream>
#include "TF1.h"
#include "TH2.h"
#include "TH1.h"
#include "TTree.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TROOT.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TText.h"
#include <math.h>
#include "TGraph.h"

#include "TRandom.h"

#include "TROOT.h"
#include "TStyle.h"
#include "TColor.h"
#include "TPolyLine.h"
#include "TLine.h"

#include <sstream>



/**
return closed contour defined by the two set of 2D points, 
expected to be two non-crossing lines,
*/
TPolyLine makePoly (std::pair<std::vector<double>, std::vector<double> > lineAbove, std::pair<std::vector<double>, std::vector<double> > lineBelow) 
{
 std::vector<double> c_x ;
 std::vector<double> c_y ;
 for (int i = 0 ; i < lineAbove.first.size () ; ++i)
 {
  c_x.push_back (lineAbove.first.at (i)) ;      
  c_y.push_back (lineAbove.second.at (i)) ;          
 }
 for (int i = lineBelow.first.size () - 1 ; i >= 0 ; --i)
 {
  c_x.push_back (lineBelow.first.at (i)) ;      
  c_y.push_back (lineBelow.second.at (i)) ;          
 }
 c_x.push_back (c_x.at (0)) ;      
 c_y.push_back (c_y.at (0)) ; 
 TPolyLine pl (c_x.size (), &c_x.at (0), &c_y.at (0)) ;
 
 return pl ; 
}


/**
SetColor/Style Histo
*/
void SetColorAndStyleHisto(TH1 & histo , EColor color){
 histo.SetFillColor (color) ;
 histo.SetLineColor (color) ;
 histo.SetMarkerColor (color) ;
 histo.SetMarkerSize (1) ;
 histo.SetMarkerStyle (20) ;
}




int main(int argc, char** argv){
 
 
 ///===============================================================================
 gROOT->Reset();
 gROOT->SetStyle("Plain");
 gStyle->SetPalette(1);
 gStyle->SetOptStat(1111);
 gStyle->SetOptFit(111);

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
 
 std::string inputFile = gConfigParser -> readStringOption("Input::inputFile"); 
 std::cout << ">>>>> Input::inputFile " << inputFile  << std::endl;  
 TFile *_file0 = TFile::Open(inputFile.c_str());
 
 double minReco = gConfigParser -> readDoubleOption("Options::minReco"); 
 std::cout << ">>>>> Options::minReco " << minReco  << std::endl;  
 TString Selection = Form("xRECO>%f",minReco);
 std::cout << ">>>>> Selection =  " << Selection.Data()  << std::endl;  
 
 double maxTrue = gConfigParser -> readDoubleOption("Options::maxTrue"); 
 std::cout << ">>>>> Options::maxTrue " << maxTrue  << std::endl;  
 
 double maxReco = gConfigParser -> readDoubleOption("Options::maxReco"); 
 std::cout << ">>>>> Options::maxReco " << maxReco  << std::endl;  
 
 int binTrue = gConfigParser -> readIntOption("Options::binTrue"); 
 std::cout << ">>>>> Options::binTrue " << binTrue  << std::endl;  
 
 int binReco = gConfigParser -> readIntOption("Options::binReco"); 
 std::cout << ">>>>> Options::binReco " << binReco  << std::endl;  
 
 
 TTree* tree = (TTree*) _file0->Get("InputTree"); 
 
 TCanvas cResult("cResult","cResult",800,400);
 cResult.Divide(2,1);
 TH2F h2("h2","h2",binReco,0,maxReco,binTrue,0,maxTrue);
 TH1F h1RECO("h1RECO","h1RECO",binReco,0,maxReco);
 TH1F h1MC("h1MC","h1MC",binTrue,0,maxTrue);
 
 cResult.cd(1);
 tree->Draw("xMC:xRECO >> h2",Selection.Data(),"colz");
 h2.Draw("colz");
 h2.GetXaxis()->SetTitle("RECO");
 h2.GetYaxis()->SetTitle("TRUE"); 
 
 h2.FitSlicesX();
 TH1F* h2_1_X = (TH1F*) gDirectory->Get("h2_1");
 h2_1_X->SetName("h2_1_X");
 h2_1_X->SetLineWidth(2);
 
 double x[1000];
 double y[1000];
 for (int iBin=0; iBin < h2_1_X->GetNbinsX(); iBin++){
  y[iBin] = h2_1_X->GetBinCenter(iBin+1);
  x[iBin] = h2_1_X->GetBinContent(iBin+1);
 }
 
 TGraph gr(h2_1_X->GetNbinsX(),x,y);
 gr.SetMarkerSize(1);
 gr.SetMarkerStyle(22);
 gr.SetMarkerColor(kRed);
 gr.Draw("Psame");
 gPad->SetGrid();
 
 
 double xMC[1000];
 double yMC[1000];
 TF1 *kFunction = new TF1("kFunction","1.3 + 0.001 * x - exp(-x/100)",0,2000);
 for (int iBin=0; iBin < 1000; iBin++){
  yMC[iBin] = (maxTrue) / 1000. * iBin;
  xMC[iBin] = kFunction->Eval(yMC[iBin]) * yMC[iBin];
 }
 
 TGraph grMC(1000,xMC,yMC);
 grMC.SetMarkerSize(0.5);
 grMC.SetMarkerStyle(20);
 grMC.SetMarkerColor(kGreen);
 grMC.Draw("Psame");
  
 
 cResult.cd(2);
 
 TGraph grInv(h2_1_X->GetNbinsX(),y,x);
 grInv.SetMarkerSize(1);
 grInv.SetMarkerStyle(22);
 grInv.SetMarkerColor(kRed);
 grInv.Draw("AP");
 
 
 TGraph grMCInv(1000,yMC,xMC);
 grMCInv.SetMarkerSize(0.5);
 grMCInv.SetMarkerStyle(20);
 grMCInv.SetMarkerColor(kGreen);
 grMCInv.Draw("Psame");
 
 
//  gr.Draw("AP");
//  grMC.Draw("Psame");
 
 grInv.GetXaxis()->SetTitle("TRUE");
 grInv.GetYaxis()->SetTitle("RECO"); 
 
 gPad->SetGrid();
 
 cResult.SaveAs("PlotCaVa.png");
 
 
 
 
 TCanvas cResultWhy("cResultWhy","cResultWhy",800,400);
 cResultWhy.Divide(2,1);
 
  
 ///======================================== slices x-fixed ========================================
 //PG build bands with getBand and same Tails along x
 //PG ---- ---- ---- ---- ---- ---- ---- ---- ---- --
 
 h2.FitSlicesY();
 TH1F* h2_1_Y = (TH1F*) gDirectory->Get("h2_1");
 h2_1_Y->SetName("h2_1_Y");
 h2_1_Y->SetLineWidth(2);
 
 std::cout << "getBand_integrY : getLimit_sameTails " << std::endl;
 std::vector<std::vector<double> > out_sameTails_x = getBand_integrY (h2, getLimit_sameTails ()) ;
 
 std::pair<std::vector<double>, std::vector<double> > x_lineAbove_sameTails ;
 x_lineAbove_sameTails.first = out_sameTails_x.at (0) ;
 x_lineAbove_sameTails.second = out_sameTails_x.at (2) ;
 std::pair<std::vector<double>, std::vector<double> > x_lineBelow_sameTails ;
 x_lineBelow_sameTails.first = out_sameTails_x.at (0) ;
 x_lineBelow_sameTails.second = out_sameTails_x.at (1) ;
 
 TPolyLine x_cont_sameTails = makePoly (x_lineAbove_sameTails, x_lineBelow_sameTails) ;
 x_cont_sameTails.SetLineWidth (2.5) ;
 x_cont_sameTails.SetFillColor (kGreen) ;
 x_cont_sameTails.SetLineColor (kGreen) ;
 
 
 
 //PG build bands with getBand and Neyman intervals along x
 //PG ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---
 
 std::cout << "getBand_integrY : getLimit_FC " << std::endl;
 std::vector<std::vector<double> > out_Neyman_x = getBand_integrY (h2, getLimit_FC ()) ;
 
 std::pair<std::vector<double>, std::vector<double> > x_lineAbove_Neyman ;
 x_lineAbove_Neyman.first = out_Neyman_x.at (0) ;
 x_lineAbove_Neyman.second = out_Neyman_x.at (2) ;
 std::pair<std::vector<double>, std::vector<double> > x_lineBelow_Neyman ;
 x_lineBelow_Neyman.first = out_Neyman_x.at (0) ;
 x_lineBelow_Neyman.second = out_Neyman_x.at (1) ;
 
 TPolyLine x_cont_Neyman = makePoly (x_lineAbove_Neyman, x_lineBelow_Neyman) ;
 x_cont_Neyman.SetLineWidth (2.5) ;
 x_cont_Neyman.SetFillColor (kYellow) ;
 x_cont_Neyman.SetLineColor (kYellow) ;
 
 ///======================================== slices y-fixed ========================================
 //PG build bands with getBand and same Tails along y
 //PG ---- ---- ---- ---- ---- ---- ---- ---- ---- --
 
 double xYFixed[1000];
 double yYFixed[1000];
 for (int iBin=0; iBin < h2_1_Y->GetNbinsX(); iBin++){
  xYFixed[iBin] = h2_1_Y->GetBinCenter(iBin+1);
  yYFixed[iBin] = h2_1_Y->GetBinContent(iBin+1);
 }
 
 TGraph grYFixed(h2_1_Y->GetNbinsX(),xYFixed,yYFixed);
 grYFixed.SetMarkerSize(1);
 grYFixed.SetMarkerStyle(22);
 grYFixed.SetMarkerColor(kRed);
 
 
 std::cout << "getBand_integrX : getLimit_sameTails " << std::endl;
 std::vector<std::vector<double> > out_sameTails_y = getBand_integrX (h2, getLimit_sameTails ()) ;
 
 std::pair<std::vector<double>, std::vector<double> > y_lineAbove_sameTails ;
 y_lineAbove_sameTails.first = out_sameTails_y.at (2) ;
 y_lineAbove_sameTails.second = out_sameTails_y.at (0) ;
 std::pair<std::vector<double>, std::vector<double> > y_lineBelow_sameTails ;
 y_lineBelow_sameTails.first = out_sameTails_y.at (1) ;
 y_lineBelow_sameTails.second = out_sameTails_y.at (0) ;
 
 TPolyLine y_cont_sameTails = makePoly (y_lineAbove_sameTails, y_lineBelow_sameTails) ;
 y_cont_sameTails.SetLineWidth (2.5) ;
 y_cont_sameTails.SetFillColor (kGreen) ;
 y_cont_sameTails.SetLineColor (kGreen) ;
 
 
 
 //PG build bands with getBand and Neyman intervals along y
 //PG ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---
 std::cout << "getBand_integrX : getLimit_FC " << std::endl;
 
 std::vector<std::vector<double> > out_Neyman_y = getBand_integrX (h2, getLimit_FC ()) ;
 
 std::pair<std::vector<double>, std::vector<double> > y_lineAbove_Neyman ;
 y_lineAbove_Neyman.first = out_Neyman_y.at (2) ;
 y_lineAbove_Neyman.second = out_Neyman_y.at (0) ;
 std::pair<std::vector<double>, std::vector<double> > y_lineBelow_Neyman ;
 y_lineBelow_Neyman.first = out_Neyman_y.at (1) ;
 y_lineBelow_Neyman.second = out_Neyman_y.at (0) ;
 
 TPolyLine y_cont_Neyman = makePoly (y_lineAbove_Neyman, y_lineBelow_Neyman) ;
 y_cont_Neyman.SetLineWidth (2.5) ;
 y_cont_Neyman.SetFillColor (kYellow) ;
 y_cont_Neyman.SetLineColor (kYellow) ;
 
 
 ///======================================== plot ========================================
 
 
 
 
 
 gROOT->Reset();
 gROOT->SetStyle("Plain");
 
 UInt_t Number = 5;
 Double_t Red[5]   = { 0.00, 0.09, 0.18, 0.09, 0.00 };
 Double_t Green[5] = { 0.01, 0.02, 0.39, 0.68, 0.97 };
 Double_t Blue[5]  = { 0.17, 0.39, 0.62, 0.79, 0.97 };
 
 Double_t Length[5] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
 TColor::CreateGradientColorTable(Number,Length,Red,Green,Blue,999);
 
//  gStyle->SetPalette(20);
 
 
 
 cResultWhy.cd(1);
 
 h2.Draw ("colz") ;
 h2_1_Y->SetMarkerColor(kRed);
 h2_1_Y->Draw("Esame");
 x_cont_sameTails.Draw () ;
 x_cont_Neyman.Draw () ;
 gPad->SetGrid();
 gPad->SetLogz();
 
 
 cResultWhy.cd(2);
 h2.Draw ("colz") ;
 grYFixed.Draw("Psame");
 y_cont_sameTails.Draw () ;
 y_cont_Neyman.Draw () ;
 gPad->SetGrid();
 gPad->SetLogz();
 
 
 cResultWhy.SaveAs("CaVaXY.png") ;
 cResultWhy.SaveAs("CaVaXY.root") ;
 
 
 
 TCanvas cResultWhyDivided("cResultWhyDivided","cResultWhyDivided",800,800);
 cResultWhyDivided.Divide(2,2);
 
 cResultWhyDivided.cd(1);
 h2.Draw ("colz") ;
 h2_1_Y->Draw("Esame");
 x_cont_Neyman.Draw () ;
 gPad->SetGrid();
 gPad->SetLogz();
 
 cResultWhyDivided.cd(2);
 h2.Draw ("colz") ;
 grYFixed.Draw("Psame");
 y_cont_sameTails.Draw () ;
 gPad->SetGrid();
 gPad->SetLogz();
 
 cResultWhyDivided.cd(3);
 h2.Draw ("colz") ;
 h2_1_Y->Draw("Esame");
 x_cont_sameTails.Draw () ;
 gPad->SetGrid();
 gPad->SetLogz();
 
 cResultWhyDivided.cd(4);
 h2.Draw ("colz") ;
 grYFixed.Draw("Psame");
 y_cont_Neyman.Draw () ;
 gPad->SetGrid();
 gPad->SetLogz();
 
 cResultWhyDivided.SaveAs("CaVaXYDivided.png") ;
 cResultWhyDivided.SaveAs("CaVaXYDivided.root") ;
 
 
 
 
 TH1D * h1_ProjY = h2.ProjectionY ("h2_tempY", binTrue / 3, binTrue / 3 , "e") ;
 TH1D * h1_ProjX = h2.ProjectionX ("h2_tempX", binReco / 3, binReco / 3 , "e") ;
 
 TCanvas cProjection("cProjection","cProjection",800,400);
 cProjection.Divide(2,1);
 
 cProjection.cd(1);
 SetColorAndStyleHisto(*h1_ProjX,kGreen);
 h1_ProjX->Draw();
 
 std::vector<double> band_ProjX = getSigmaBands_FeldmanCousins (*h1_ProjX) ;
 
 TLine* lVert_ProjX_Left95 = new TLine(band_ProjX.at(0),0,band_ProjX.at(0),1000);
 lVert_ProjX_Left95->SetLineColor(kBlue);
 lVert_ProjX_Left95->SetLineWidth(2);
//  lVert_ProjX_Left95->SetLineStyle(5);
 
 TLine* lVert_ProjX_Left68 = new TLine(band_ProjX.at(1),0,band_ProjX.at(1),1000);
 lVert_ProjX_Left68->SetLineColor(kMagenta);
 lVert_ProjX_Left68->SetLineWidth(2);
//  lVert_ProjX_Left68->SetLineStyle(5);
 
 TLine* lVert_ProjX_Middle = new TLine(band_ProjX.at(2),0,band_ProjX.at(2),1000);
 lVert_ProjX_Middle->SetLineColor(kGreen);
 lVert_ProjX_Middle->SetLineWidth(2);
//  lVert_ProjX_Middle->SetLineStyle(5);
 
 TLine* lVert_ProjX_Right68 = new TLine(band_ProjX.at(3),0,band_ProjX.at(3),1000);
 lVert_ProjX_Right68->SetLineColor(kMagenta);
 lVert_ProjX_Right68->SetLineWidth(2);
//  lVert_ProjX_Right68->SetLineStyle(5);
 
 TLine* lVert_ProjX_Right95 = new TLine(band_ProjX.at(4),0,band_ProjX.at(4),1000);
 lVert_ProjX_Right95->SetLineColor(kBlue);
 lVert_ProjX_Right95->SetLineWidth(2);
//  lVert_ProjX_Right95->SetLineStyle(5);
 
 lVert_ProjX_Left95->Draw();
 lVert_ProjX_Left68->Draw();
 lVert_ProjX_Middle->Draw();
 lVert_ProjX_Right68->Draw();
 lVert_ProjX_Right95->Draw();
 
 gPad->SetGrid();
 
 cProjection.cd(2);
 SetColorAndStyleHisto(*h1_ProjY,kRed);
 h1_ProjY->Draw();
 
 std::vector<double> band_ProjY = getSigmaBands_FeldmanCousins (*h1_ProjY) ;
 
 TLine* lVert_ProjY_Left95 = new TLine(band_ProjY.at(0),0,band_ProjY.at(0),1000);
 lVert_ProjY_Left95->SetLineColor(kBlue);
 lVert_ProjY_Left95->SetLineWidth(2);
//  lVert_ProjY_Left95->SetLineStyle(5);
 
 TLine* lVert_ProjY_Left68 = new TLine(band_ProjY.at(1),0,band_ProjY.at(1),1000);
 lVert_ProjY_Left68->SetLineColor(kMagenta);
 lVert_ProjY_Left68->SetLineWidth(2);
//  lVert_ProjY_Left68->SetLineStyle(5);
 
 TLine* lVert_ProjY_Middle = new TLine(band_ProjY.at(2),0,band_ProjY.at(2),1000);
 lVert_ProjY_Middle->SetLineColor(kGreen);
 lVert_ProjY_Middle->SetLineWidth(2);
//  lVert_ProjY_Middle->SetLineStyle(5);
 
 TLine* lVert_ProjY_Right68 = new TLine(band_ProjY.at(3),0,band_ProjY.at(3),1000);
 lVert_ProjY_Right68->SetLineColor(kMagenta);
 lVert_ProjY_Right68->SetLineWidth(2);
//  lVert_ProjY_Right68->SetLineStyle(5);
 
 TLine* lVert_ProjY_Right95 = new TLine(band_ProjY.at(4),0,band_ProjY.at(4),1000);
 lVert_ProjY_Right95->SetLineColor(kBlue);
 lVert_ProjY_Right95->SetLineWidth(2);
//  lVert_ProjY_Right95->SetLineStyle(5);
 
 lVert_ProjY_Left95->Draw();
 lVert_ProjY_Left68->Draw();
 lVert_ProjY_Middle->Draw();
 lVert_ProjY_Right68->Draw();
 lVert_ProjY_Right95->Draw();
 
 gPad->SetGrid();
 
 cProjection.SaveAs("CaVaXYProjection.png") ;
 cProjection.SaveAs("CaVaXYProjection.root") ;
 cProjection.SaveAs("CaVaXYProjection.eps") ;
 
 
 
 
 
 
 TCanvas cProjection2D("cProjection2D","cProjection2D",800,1200);
 TPad oneC ("oneC","oneC",0.0,0.5,0.5,1.0);
 oneC.Draw();
 oneC.cd();
 h1_ProjX->Draw();
 gPad->SetGrid();
 
 cProjection2D.cd();
 TPad twoC ("twoC","twoC",0.5,0.5,1.0,1.0);
 twoC.Draw();
 twoC.cd();
 h1_ProjY->Draw();
 gPad->SetGrid();

 cProjection2D.cd();
 TPad threefourC ("threefourC","threefourC",0.0,0.0,1.0,0.5);
 threefourC.Draw();
 threefourC.cd();
 h2.Draw ("colz") ;
 
 cProjection2D.SaveAs("CaVaXYProjection2D.png") ;
 cProjection2D.SaveAs("CaVaXYProjection2D.root") ;
 cProjection2D.SaveAs("CaVaXYProjection2D.eps") ;
 
 
 
}


