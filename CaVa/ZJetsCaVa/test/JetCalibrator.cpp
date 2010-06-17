///==== like this:
///==== c++ -o BuildCaVa_fromData_Iterative_testConvergence_ZJets.exe `root-config --cflags --glibs` BuildCaVa_fromData_Iterative_testConvergence_ZJets.cpp CaVa.cc


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


#include <sstream>

#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"


#include "CaVa.h"

// #include "Functions.h"

int main(int argc, char** argv){

 
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }
 
 // Parse the config file 
 parseConfigFile (argv[1]) ;
 
 std::string inputFile = gConfigParser -> readStringOption("Input::inputFile"); 
 std::cout << ">>>>> Input::inputFile " << inputFile  << std::endl;  
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

 int whatInit = gConfigParser -> readIntOption("Input::whatInit");
 std::cout << ">>>>> input::whatInit  " << whatInit  << std::endl;  
 
 int MaxIter = gConfigParser -> readIntOption("Input::MaxIter");
 std::cout << ">>>>> input::MaxIter  " << MaxIter  << std::endl;  
 
 double xResolution = gConfigParser -> readDoubleOption("Input::resolution");
 std::cout << ">>>>> input::resolution  " << xResolution  << std::endl;  
 
 
 
 ///----------------
 ///---- output ----
 std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << OutFileName  << std::endl;  
 
 TFile fileOut(OutFileName.c_str(),"RECREATE");
 fileOut.cd();
 
 
//  TH2F h2("h2","h2",2000,0,12000,200,0,2000);
//  TH1F h1RECO("h1RECO","h1RECO",200,0,2000);
 
//  TF1 *kFunction = new TF1("kFunction","pol3",0,150);
//  kFunction->SetParameters(12.1704,-0.247829,0.0150046,-6.34445e-05);
 
 TF1 *kFunction = new TF1("kFunction","pol2",0,150);
 kFunction->SetParameters(7.45879,0.172926,0.00488431);
 
 
 TCanvas cResultIter("cResultIter","cResultIter",800,800);
//  cResultIter.Divide(4,4);
 TH2F h2("h2","h2",NBinX,MinX,MaxX,NBinY,MinY,MaxY);
 tree->Draw("xMC:xRECO >> h2","","colz");
 h2.Draw("colz");
 
 std::cerr << " smratGausProfileY" << std::endl;
 smartGausProfileY(&h2,1.0);
//  h2.FitSlicesX(0,0,-1,0,"G2");
//  h2.ProfileY();
//  TH1F* h2_1 = (TH1F*) gDirectory->Get("h2_pfy");
// TH1F* h2_1 = (TH1F*) gDirectory->Get("h2_1");
TH1F* h2_1 = (TH1F*) gDirectory->Get("h2_smartGaus_Y");
 h2_1->SetLineWidth(2);
 h2_1->Write();
 
 double x[10000];
 double y[10000];
//  for (int iBin=0; iBin < h2_1->GetNbinsX(); iBin++){
 for (int iBin=(h2_1->GetNbinsX()-1); iBin >= 0; iBin--){
  x[iBin] = h2_1->GetBinCenter(iBin+1);
  y[iBin] = h2_1->GetBinContent(iBin+1);
  if (h2_1->GetBinContent(iBin+1) < 0.1) {
   y[iBin] = y[iBin+1];
  }
 }
 
 TGraph grK(h2_1->GetNbinsX(),x,y);
 grK.SetMarkerSize(1);
 grK.SetMarkerStyle(22);
 grK.SetMarkerColor(kBlue);
 grK.Draw("Psame");
 grK.Write();
 h2.Write();
 gPad->SetGrid();
 
 TGraph grKMinusOne(h2_1->GetNbinsX(),y,x);
 grKMinusOne.SetMarkerSize(1);
 grKMinusOne.SetMarkerStyle(22);
 grKMinusOne.SetMarkerColor(kBlue);
 grKMinusOne.Write();
 
 
 
//  double xMCGr[10000];
//  double yMCGr[10000];
//  for (int iBin=0; iBin < 10000; iBin++){
//   yMCGr[iBin] = (MaxY-MinY) / 10000. * iBin + MinY;
//   xMCGr[iBin] = kFunction->Eval(yMCGr[iBin]);
//  }
//  
//  TGraph grMC(10000,xMCGr,yMCGr);
//  grMC.SetMarkerSize(0.5);
//  grMC.SetMarkerStyle(20);
//  grMC.SetMarkerColor(kGreen);
//  grMC.Write();
 
 double xRECO;
 double xMC;
//  double xMCEXP;
 
 int numParameters = 0;
 std::vector<double> xRECO2MC;
 std::vector<double> xRECOIN;

 std::vector<int> xOK;
 
 ///==== not used right now ... maybe later ... to constrain the movement
 std::vector<double> xRECO2MC_delta_per_cent; ///==== range [-10,+10] => -1000% + 1000% => - x10 / + x10
					      ///==== but it may change
  
 tree->SetBranchAddress("xRECO",&xRECO);
 tree->SetBranchAddress("xMC",&xMC);
//  tree->SetBranchAddress("xMCEXP",&xMCEXP);
 
 TH1F h1RecoDistrib("h1RecoDistrib","h1RecoDistrib",200,0,2000);
 h1RecoDistrib.SetLineColor(kRed);
 tree->Draw("xRECO >> h1RecoDistrib","","E");
 h1RecoDistrib.GetXaxis()->SetTitle("RECO p_{T}");
 h1RecoDistrib.SetMarkerStyle(20);
 h1RecoDistrib.SetMarkerSize(0.5);
 h1RecoDistrib.SetMarkerColor(kBlue);
 h1RecoDistrib.SetLineWidth(2);
 h1RecoDistrib.SetLineColor(kBlue);
 h1RecoDistrib.Draw("E");
 h1RecoDistrib.Write();
 
//  TF1 *MCDistrbution = new TF1("MCDistrbution","exp(-x/200.)* (1.2 + x)",20,2000);
 TF1 simpleDistrib("simpleDistrib","[4] * exp( - x / [2] ) * ([0] + [1] * x) + [3]",0,2000);
 simpleDistrib.SetParameters(83.0435,0.262693,364.396,515.155,132.232);
//  83,0.3,360.,515,133);
//  h1RecoDistrib.Fit("simpleDistrib");
 simpleDistrib.Write();
 double meanReco = h1RecoDistrib.GetMean();
 std::cerr << "meanReco = " << meanReco << std::endl;
 
 if (numEntries == -1) numEntries = tree->GetEntries();
 std::cerr << " numEntries = " << numEntries << std::endl;
 
 TF1 *Resolution = new TF1("Resolution","exp(-(x-1)*(x-1)/(2.*[0]*[0]))",0,10);
 Resolution->SetParameter(0,xResolution);
 std::cerr << " whatInit = " << whatInit << std::endl;
 
 
 for (int iEvt = 0; iEvt< numEntries; iEvt++){
  tree->GetEntry(iEvt);
  
  if (xRECO > MinX && xRECO < MaxX){
   xOK.push_back(1);
   xRECOIN.push_back(xRECO);
   
   if (whatInit == 0) xRECO2MC.push_back(grKMinusOne.Eval(xRECO) * Resolution->GetRandom()); ///=== > k-1 (+) resolution
   if (whatInit == 1) xRECO2MC.push_back(grKMinusOne.Eval(xRECO)); ///=== > all on a line
     
//    if (whatInit == 0) xRECO2MC.push_back(grMC.Eval(xRECO) * Resolution->GetRandom()); ///=== > k-1 (+) resolution
//    if (whatInit == 1) xRECO2MC.push_back(grMC.Eval(xRECO)); ///=== > all on a line
   if (whatInit == 2) xRECO2MC.push_back(gRandom->Uniform(0,MaxY)); ///=== > flat distribution
      
   xRECO2MC_delta_per_cent.push_back(0);
   numParameters++;
  }
  else {
   xOK.push_back(0);
  }
 }
 
 
 std::cerr << " Start ... " << std::endl;
 std::cerr << " numParameters = " << numParameters << std::endl;
 

//  CaVa myCaVa(xRECOIN,xRECO2MC,*kFunction,*Resolution);
 CaVa myCaVa(xRECOIN,xRECO2MC,grK,*Resolution);
 
 
 
 TTree* tree_Iterative_Before = new TTree ("myTree_Before","myTree_Before"); 
 double xRECOMC;
 
 tree_Iterative_Before->Branch("xMC",&xMC,"xMC/D");
//  tree_Iterative_Before->Branch("xMCEXP",&xMCEXP,"xMCEXP/D");
 tree_Iterative_Before->Branch("xRECO",&xRECO,"xRECO/D");
 tree_Iterative_Before->Branch("xRECOMC",&xRECOMC,"xRECOMC/D");

 
 std::cerr << " Before ... " << std::endl;
 
 int iAnalyzed = 0;
 for (int iEvt = 0; iEvt< numEntries; iEvt++){
  tree->GetEntry(iEvt);
  if (xOK.at(iEvt) == 1){
   xRECOMC = xRECO2MC.at(iAnalyzed);
   tree_Iterative_Before->Fill();
   iAnalyzed ++;
  }
 }
 tree_Iterative_Before->Write();
 
  
 myCaVa.Print();
 
 myCaVa.SetParameters(NBinX,NBinY,MinX,MinY,MaxX,MaxY);
 myCaVa.FillCaVa(); ///---- Fill CaVa using infos from vectors
 
 
 TTree* tree_Iterative = new TTree ("myTree","myTree"); 
 int IterNumber = 0;
 tree_Iterative->Branch("IterNumber",&IterNumber,"IterNumber/I");
 tree_Iterative->Branch("xMC",&xMC,"xMC/D");
//  tree_Iterative->Branch("xMCEXP",&xMCEXP,"xMCEXP/D");
 tree_Iterative->Branch("xRECO",&xRECO,"xRECO/D");
 tree_Iterative->Branch("xRECOMC",&xRECOMC,"xRECOMC/D");
 
 
 ///=======================================
 ///==== new "minimizer" -> 'homemade' ====
 myCaVa.CalculateTrueDistibution(); ///---- calculate "true" jet distribution => at the beginning using RealCaVa
 for (int iter=0; iter<MaxIter; iter++){
  std::cerr << ">>> iter = " << iter << " : " << MaxIter << std::endl;
  iAnalyzed = 0;
  IterNumber = iter;
  xRECO2MC = myCaVa.getResults();
  for (int iEvt = 0; iEvt< numEntries; iEvt++){
   tree->GetEntry(iEvt);
   if (xOK.at(iEvt) == 1){
    xRECOMC = xRECO2MC.at(iAnalyzed);
    tree_Iterative->Fill();
    iAnalyzed++;
   }
  }
  myCaVa.BuildToyCaVa(); ///---- build Toy CaVa with many events
  myCaVa.CalculateRecoDistroWithDelta(); ///---- Calculate Reco distributions (x fixed slices)
  myCaVa.BuildRealCaVa(); ///---- build "real" CaVa using Reco distributions
  myCaVa.BuildToyCaVaFromReco(); ///---- build Toy CaVa with many events using Reco distribution
  
  ///=== do this only after "some" iterations ...
  //if (iter == 10) myCaVa.DoResolFree(1); ///---- enable resolution estimation from data
  //if (iter > 10) myCaVa.CalculateResolution();  ///---- calculate resolution (k(pT) (x) resolution) from data
   
  myCaVa.CalculateTrueDistibutionWithToyCava(); ///---- Reconstruct True distribution using Toy CaVa from Reco
  
  tree_Iterative->AutoSave();
 }
 ///======================================= 
 
 
 tree_Iterative->Write();

}




