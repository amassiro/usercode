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

#include <sstream>

int main(int argc, char** argv){
 ///==== ROOT Style ====
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
 ///==== ROOT Style ====
 
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }
 
 // Parse the config file 
 parseConfigFile (argv[1]) ;
 
 std::string inputFile = gConfigParser -> readStringOption("Input::inputFile"); 
 std::cout << ">>>>> Input::inputFile" << inputFile  << std::endl;  
 TFile *_file1 = TFile::Open(inputFile.c_str());
 
 std::string treeName  = gConfigParser -> readStringOption("Input::treeName"); 
 std::cout << ">>>>> input::treeName  " << treeName  << std::endl;  
 TTree* tree = (TTree*) _file1->Get(treeName.c_str()); 
 
 int numEntries = gConfigParser -> readIntOption("Input::numEntries");
 std::cout << ">>>>> input::numEntries  " << numEntries  << std::endl;  
 
 int NBinX = gConfigParser -> readIntOption("Input::NBinX");
 std::cout << ">>>>> input::NBinX  " << NBinX  << std::endl;  

 int NBinY = gConfigParser -> readIntOption("Input::NBinY");
 std::cout << ">>>>> input::NBinY  " << NBinY  << std::endl;  

 double MinX = gConfigParser -> readDoubleOption("Input::minReco");
 std::cout << ">>>>> input::minReco  " << MinX  << std::endl;  
 
 double MinY = gConfigParser -> readDoubleOption("Input::minTrue");
 std::cout << ">>>>> input::minTrue  " << MinY  << std::endl;  
 
 double MaxX = gConfigParser -> readDoubleOption("Input::maxReco");
 std::cout << ">>>>> input::maxReco  " << MaxX  << std::endl;  
 
 double MaxY = gConfigParser -> readDoubleOption("Input::maxTrue");
 std::cout << ">>>>> input::maxTrue  " << MaxY  << std::endl;  

 double lowReco = gConfigParser -> readDoubleOption("Input::lowReco");
 std::cout << ">>>>> input::lowReco  " << lowReco  << std::endl;  
 
 ///----------------
 ///---- output ----
 std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << OutFileName  << std::endl;  

 std::string outFileNameImage    = gConfigParser -> readStringOption("Output::outFileNameImage");
 std::cout << ">>>>> Output::outFileNameImage  " << outFileNameImage  << std::endl;  
 
 TFile fileOut(OutFileName.c_str(),"RECREATE");
 fileOut.cd();
 
 TCanvas cResultCaVa("cResultCaVa","cResultCaVa",800,800);
 TH2F h2("h2","h2",NBinX,MinX,MaxX,NBinY,MinY,MaxY);
 TString cut = Form("xRECO > %f",lowReco);
 tree->Draw("xMC:xRECO >> h2",cut,"colz");
 
 TH2F h2Inv("h2Inv","h2Inv",NBinY,MinY,MaxY,NBinX,MinX,MaxX);
 tree->Draw("xRECO:xMC >> h2Inv",cut,"colz");
 h2Inv.Write();
 
 smartGausProfileY(&h2,1.0);
 TH1F* h2_1 = (TH1F*) gDirectory->Get("h2_smartGaus_Y");
 h2_1->SetLineWidth(2);
 h2_1->Write();
 
 double x[10000];
 double y[10000];
 double rmsy[10000];
 double rmsyOy[10000];
 
 for (int iBin=(h2_1->GetNbinsX()-1); iBin >= 0; iBin--){
  x[iBin] = h2_1->GetBinCenter(iBin+1);
  y[iBin] = h2_1->GetBinContent(iBin+1);
  rmsy[iBin] = h2_1->GetBinError(iBin+1);
  if (y[iBin] != 0) rmsyOy[iBin] = rmsy[iBin] / y[iBin];
  else rmsyOy[iBin] = 1.0; ///=> arbitrario!!!
 }
 
 TGraph grK(h2_1->GetNbinsX(),x,y);
 grK.SetMarkerSize(1);
 grK.SetMarkerStyle(22);
 grK.SetMarkerColor(kBlue);
 grK.SetName("Meas_kFunction");
 grK.Write();
 
 TGraph grKminusOne(h2_1->GetNbinsX(),y,x);
 grKminusOne.SetMarkerSize(1);
 grKminusOne.SetMarkerStyle(22);
 grKminusOne.SetMarkerColor(kRed);
 grKminusOne.Write();
 
 h2.Draw("colz"); 
 grKminusOne.Draw("Psame");
 gPad->SetGrid();
 cResultCaVa.SaveAs(outFileNameImage.c_str());
 cResultCaVa.Write();
 TCanvas cResultK("cResultK","cResultK",800,800);

 
 TF1* kFunction = (TF1*) _file1->Get("kFunction");
 grK.Draw("AP"); 
 kFunction->Draw("APsame");
 gPad->SetGrid();
 cResultK.Write();
 
 kFunction->Write();
 
 
 TGraph grResolution(h2_1->GetNbinsX(),x,rmsyOy);
 grResolution.SetMarkerSize(1);
 grResolution.SetMarkerStyle(22);
 grResolution.SetMarkerColor(kBlue);
 TCanvas cResultResol("cResultResol","cResultResol",800,800);
 grResolution.Draw("AP");
 grResolution.Write();
 gPad->SetGrid();
 
 cResultResol.Write();
}




