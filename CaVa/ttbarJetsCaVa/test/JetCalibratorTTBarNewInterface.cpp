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
 
 int MaxIter = gConfigParser -> readIntOption("Input::MaxIter");
 std::cout << ">>>>> input::MaxIter  " << MaxIter  << std::endl;  
 
 double Delta = gConfigParser -> readDoubleOption("Input::Delta");
 std::cout << ">>>>> input::Delta  " << Delta  << std::endl;  
 
 double Mass_Resonance = gConfigParser -> readDoubleOption("Input::MassResonance");
 std::cout << ">>>>> input::MassResonance  " << Mass_Resonance  << std::endl;  
 
 
 
 
 
 ///----------------
 ///---- output ----
 std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << OutFileName  << std::endl;  
 
 TFile fileOut(OutFileName.c_str(),"RECREATE");
 fileOut.cd();

 std::vector<double> vectMassMC;
 
 double xRECO_1;
 double xRECO_2;
 double xMC_1;
 double xMC_2;
 double Mass_RECO;
 double Mass_MC;
 
 int numParameters = 0;
 std::vector<double> xRECO2MC_1;
 std::vector<double> xRECO2MC_2;
 std::vector<double> xRECOIN_1;
 std::vector<double> xRECOIN_2;

 std::vector<double> vMC_1;
 std::vector<double> vMC_2;
 
 
 std::vector<int> xOK;
 
 tree->SetBranchAddress("xRECO_1",&xRECO_1);
 tree->SetBranchAddress("xMC_1",&xMC_1);
 tree->SetBranchAddress("xRECO_2",&xRECO_2);
 tree->SetBranchAddress("xMC_2",&xMC_2);
 tree->SetBranchAddress("Mass_RECO",&Mass_RECO);
 tree->SetBranchAddress("Mass_MC",&Mass_MC);
 
 if (numEntries == -1) numEntries = tree->GetEntries();
 std::cerr << " numEntries = " << numEntries << " : " << tree->GetEntries() << std::endl;
 
 double xMassRECO;
 TTree InTree("InTree","InTree"); 
 InTree.Branch("xRECO_2",&xRECO_2,"xRECO_2/D");
 InTree.Branch("xRECO_1",&xRECO_1,"xRECO_1/D");
 InTree.Branch("xMassRECO",&xMassRECO,"xMassRECO/D");
 
 for (int iEvt = 0; iEvt< numEntries; iEvt++){
  tree->GetEntry(iEvt);
  if ((xRECO_1 > MinX && xRECO_1 < MaxX) && (xRECO_2 > MinX && xRECO_2 < MaxX)){
   xOK.push_back(1);
   std::cerr << " xRECO_2 = " << xRECO_2 << " xRECO_1 = " << xRECO_1 << std::endl;
   vectMassMC.push_back(Mass_MC);
   vMC_1.push_back(xMC_1);
   vMC_2.push_back(xMC_2);
   xMassRECO = Mass_RECO;
   InTree.Fill();
   numParameters++;
  }
  else {
   xOK.push_back(0);
  }
 }
 
 
 std::cerr << " Start ... " << std::endl;
 std::cerr << " numParameters = " << numParameters << std::endl;
 
 CaVa myCaVa(&InTree,Mass_Resonance);
 myCaVa.Print();
 
 myCaVa.SetParameters(NBinX,NBinY,MinX,MinY,MaxX,MaxY,Delta);
 myCaVa.InitializeWithDelta(); ///==== Initialization of CaVa using same energy jets ==== 
 
 TTree* tree_Result = myCaVa.getResult();

 TTree* tree_Iterative = new TTree ("myTree","myTree"); 
 double xRECOMC_1;
 double xRECOMC_2;
 double Mass_RECO_After;
 int IterNumber = 0;
 
 tree_Iterative->Branch("IterNumber",&IterNumber,"IterNumber/I");
 tree_Iterative->Branch("xMC_1",&xMC_1,"xMC_1/D");
 tree_Iterative->Branch("xMC_2",&xMC_2,"xMC_2/D");
 tree_Iterative->Branch("xRECO_1",&xRECO_1,"xRECO_1/D");
 tree_Iterative->Branch("xRECO_2",&xRECO_2,"xRECO_2/D");
 tree_Iterative->Branch("xRECOMC_1",&xRECOMC_1,"xRECOMC_1/D");
 tree_Iterative->Branch("xRECOMC_2",&xRECOMC_2,"xRECOMC_2/D");
 tree_Iterative->Branch("Mass_RECO",&Mass_RECO,"Mass_RECO/D");
 tree_Iterative->Branch("Mass_RECO_After",&Mass_RECO_After,"Mass_RECO_After/D");
 tree_Iterative->Branch("Mass_MC",&Mass_MC,"Mass_MC/D"); 
 
 int iAnalyzed = 0;
 
 ///=======================================
 ///==== new "minimizer" -> 'homemade' ====
 double xTRUE_1;
 double xTRUE_2;
 double xMassTRUE; 
 double xMassMC; 
 
 for (int iter=0; iter<MaxIter; iter++){
  std::cerr << ">>> iter = " << iter << " : " << MaxIter << std::endl;
  iAnalyzed = 0;
  IterNumber = iter;
  delete tree_Result;
  tree_Result = myCaVa.getResult();
  tree_Result->SetBranchAddress("xTRUE_1",&xTRUE_1);
  tree_Result->SetBranchAddress("xRECO_1",&xRECO_1);
  tree_Result->SetBranchAddress("xTRUE_2",&xTRUE_2);
  tree_Result->SetBranchAddress("xRECO_2",&xRECO_2);
  tree_Result->SetBranchAddress("xMassTRUE",&xMassTRUE);
  tree_Result->SetBranchAddress("xMassRECO",&xMassRECO);
  
  for (int iEvt = 0; iEvt< tree_Result->GetEntries(); iEvt++){
   tree_Result->GetEntry(iEvt);
   xRECOMC_1 = xTRUE_1;
   xRECOMC_2 = xTRUE_2;
   Mass_RECO_After = xMassTRUE;
   Mass_RECO = xMassRECO;
   Mass_MC = vectMassMC.at(iEvt);
   xMC_1 = vMC_1.at(iEvt);
   xMC_2 = vMC_2.at(iEvt);
//    std::cerr << " vectMassMC.at(iEvt) = " << vectMassMC.at(iEvt) << std::endl;
   tree_Iterative->Fill();
  }
  myCaVa.CalculateK(); ///---- calculate K function from RealCaVa
  myCaVa.BuildToyCaVa(); ///---- build Toy CaVa with many events
  ///myCaVa.CalculateRecoDistroWithDelta(); ///---- Calculate Reco distributions (x fixed slices)
  myCaVa.BuildRealCaVaWithMass(); ///---- build "real" CaVa using Reco distributions and Invariant mass constraint
  myCaVa.CalculateTrueDistibution(); ///---- calculate "true" jet distribution -> projection Y axis of CaVa
 }
 
 delete tree_Result;
 tree_Result = myCaVa.getResult();
 tree_Result->SetBranchAddress("xTRUE_1",&xTRUE_1);
 tree_Result->SetBranchAddress("xRECO_1",&xRECO_1);
 tree_Result->SetBranchAddress("xTRUE_2",&xTRUE_2);
 tree_Result->SetBranchAddress("xRECO_2",&xRECO_2);
 tree_Result->SetBranchAddress("xMassTRUE",&xMassTRUE);
 tree_Result->SetBranchAddress("xMassRECO",&xMassRECO);
 
 IterNumber = MaxIter;
 for (int iEvt = 0; iEvt< tree_Result->GetEntries(); iEvt++){
//   std::cerr << " iEvt = " << iEvt << " : " << tree_Result->GetEntries() << std::endl;
  tree_Result->GetEntry(iEvt);
  xRECOMC_1 = xTRUE_1;
  xRECOMC_2 = xTRUE_2;
  Mass_RECO_After = xMassTRUE;
  Mass_RECO = xMassRECO;
  Mass_MC = vectMassMC.at(iEvt);
  xMC_1 = vMC_1.at(iEvt);
  xMC_2 = vMC_2.at(iEvt);
  
//   std::cerr << " vectMassMC.at(iEvt) = " << vectMassMC.at(iEvt) << std::endl;
  tree_Iterative->Fill();
 }
 
 ///======================================= 
 
 
 tree_Iterative->Write();
 
}




