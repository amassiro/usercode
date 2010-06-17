/*
Class CaVa
*/
#ifndef CaVa_h
#define CaVa_h

#include "TF1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"
#include "TGraph.h"
// 
#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include "Math/GenVector/VectorUtil.h"

#include "TRandom3.h"

#include <time.h>
#include <sstream>

#include "CLHEP/Matrix/Matrix.h"
#include "CLHEP/Matrix/Vector.h"

#include "TROOT.h"

class CaVa{
 
 protected:
  
 public:

  
  CaVa(std::vector<double>& xRECO2IN, std::vector<double>& xRECO2MC, TF1& kFunction, TF1& Resolution);
  CaVa(std::vector<double>& xRECO2IN, std::vector<double>& xRECO2MC, TGraph& kFunction, TF1& Resolution);
  ///---- xRECO2MC are the initialization variables ----
  ~CaVa();
  
  void Print();
  
  std::vector<double> getResults();
  
  void FillCaVa(); ///---- Fill CaVa using infos from vectors
  
  void DoResolFree(int what); ///---- enable resolution estimation from data
  void SetParameters(int NBinX, int NBinY, double MinX, double MinY, double MaxX, double MaxY);   
  void CalculateTrueDistibution(); ///---- calculate "true" jet distribution
  void BuildToyCaVa(); ///---- build Toy CaVa with many events
  void BuildToyCaVaFromReco(); ///---- build Toy CaVa with many events using Reco distribution
  void CalculateRecoDistroWithDelta(); ///---- Calculate Reco distributions (x fixed slices)
  void BuildRealCaVa(); ///---- build "real" CaVa using Reco distributions
  void CalculateTrueDistibutionWithToyCava(); ///---- Reconstruct True distribution using Toy CaVa from Reco
  
  void CalculateResolution(); ///---- calculate resolution (k(pT) (x) resolution) from data
  
 private:

  int do_Resol_;
  
  int NBinX_;
  int NBinY_;
  double MinX_;
  double MinY_;
  double MaxX_;
  double MaxY_;
  double Delta_X_;
  double Delta_Y_;
  
  TH2F* h2ToyCaVa_;
  TH2F* h2ToyCaVaFromReco_;
  TH2F* h2RealCaVa_;
  
  TH1F* h1MCDistrib_;
  TH1F* h1RECODistrib_;
  
  TH1F* h1RecoMCDistrib_[10000];
  
  
  double Step_;
  double Delta_;
  TH1F* tempHgrK_[10000];
  TH1F* tempHgrKExpected_[10000];
  double *tempMaxGrK_;
  double *tempMinGrK_;
  
  int numParameters_;
  TRandom* myRand_;
  TH1F* h1RECO_DATA_;
  TH1F* h1RECO_IN_;
  std::vector<double> xRECO2MC_;
  std::vector<double> xRECO2IN_;
  
  TF1* Resolution_;
  TF1* kFunction_;
  TGraph* kFunctionGr_;
  TGraph* grResol_;
  double resolution_;
  
  TH1F* tempHYFixed_[10000];
  
};

#endif

