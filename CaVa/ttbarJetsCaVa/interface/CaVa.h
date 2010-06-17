/*
Class CaVa
*/
#ifndef CaVa_h
#define CaVa_h

#include "TTree.h"
#include "TF1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"
#include "TGraph.h"

#include "TMath.h"

#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include "Math/GenVector/VectorUtil.h"

#include "TRandom3.h"

#include <time.h>
#include <sstream>

// #include "CLHEP/Matrix/Matrix.h"
// #include "CLHEP/Matrix/Vector.h"

#include "TROOT.h"

class CaVa{
 
 protected:
  
 public:
  
  CaVa(TTree* inputTree, double Mass_W);
  
  ~CaVa();
  
  void SetParameters(int NBinX, int NBinY, double MinX, double MinY, double MaxX, double MaxY, double Delta);   
  void Print();
  
  void InitializeWithDelta();
  void CalculateK(); ///---- calculate K function from RealCaVa
  void BuildToyCaVa(); ///---- build Toy CaVa with many events
  void CalculateRecoDistroWithDelta(); ///---- Calculate Reco distributions (x fixed slices)
  void BuildRealCaVaWithMass(); ///---- build "real" CaVa using Reco distributions and Invariant mass constraint
  void CalculateTrueDistibution();  ///---- calculate "true" jet distribution -> projection Y axis of CaVa
  
  void SmoothVector(double* y, double* rmsy);
  
  void FillCaVa();  ///---- Fill CaVa using vectors Reco and True available
  
  TTree* getResult();
  
  
 private:
   
  double Mass_W_;
  int numParameters_;
  TRandom* myRand_;
  
  
  int NBinX_;
  int NBinY_;
  double MinX_;
  double MinY_;
  double MaxX_;
  double MaxY_;
  double Delta_X_;
  double Delta_Y_;
  
  double Delta_Init_;
  int NBinX_Init_;
  TH2F* h2InitCaVa_;
  TH2F* h2ToyCaVa_;
  TH2F* h2RealCaVa_;
  
  TGraph* kFunctionGr_;
  TF1* Resolution_;
  TGraph* grResol_;
  
  TTree* inputTree_;
  TTree* outputTree_;
  TTree* outputTree_temp_;
  
  double xRECO_1_;
  double xRECO_2_;
  double xTRUE_1_;
  double xTRUE_2_;
  double xMassRECO_;
  double xMassTRUE_; 

  TH1F* tempHXFixed_[10000];
  TH1F* tempHXFixed_Init_[10000];
  
  TH1F* tempHYFixed_[10000];
  
  TH1F* h1TrueDistrib_;
  TH1F* h1RECODistrib_;
//   TH1F* h1Resol_;
  
  
};

#endif

