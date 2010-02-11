/*
Class JetCalibrator
*/
#ifndef JetCalibrator_h
#define JetCalibrator_h


#include "treeReader.h"
#include "TF1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"

#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include "Math/GenVector/VectorUtil.h"

#include "TRandom3.h"

#include "ntpleUtils.h"

#include <time.h>
#include <sstream>

#include "CLHEP/Matrix/Matrix.h"
#include "CLHEP/Matrix/Vector.h"

#include "TROOT.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooPolynomial.h"
#include "RooAddPdf.h"
#include "RooConstVar.h"
#include "RooCategory.h"
#include "RooFitResult.h"
#include "RooPlot.h"


class JetCalibrator{
 
 protected:
  
 public:
  JetCalibrator();
  JetCalibrator(double MResonance,double PtMin,double PtMax,double EtaMax, double DPt, double DEta);
  ~JetCalibrator();
   
  void Update();
  void Update(int alpha);
  void Update(int alpha, int rand);
  void Update(std::vector<double>* KK_In, int alpha, int rand);
  
  void UpdateMIB();
  double Chi2Minuit(const double * sKK_In);
 
  void UpdateKUpdate();
  void UpdateKUpdate(std::vector<double>* KK_In);
   
  void UpdateL3();
  void UpdateL3(std::vector<double>* KK_In);
  
  void UpdateRUL3();
  void UpdateRUL3(std::vector<double>* KK_In);
  
  void UpdateRUFit();
  void UpdateRUFit(std::vector<double>* KK_In);

  void UpdateSFit();
  void UpdateSFit(std::vector<double>* KK_In);
  
  void UpdateSRooFit();
  void UpdateSRooFit(std::vector<double>* KK_In);
  
  void UpdateMatrixInversion();
  void InitializeMatrix();
  void FillVector();
  void FillMatrix();
  void InvertMatrix();
  double Chi2(std::vector<double>* KK_In);
  double DChi2(std::vector<double>* KK_In,int i);
  double DDChi2(std::vector<double>* KK_In,int iK, int jK);
  
  bool AddJetPair(std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>& InputJetPair);
  
  double getKK(double eta, double pT);
  double getKK(int num);
 
  int GetIntPt(double Pt);
  int GetIntEta(double Eta);
  int GetInt(int iPt, int iEta);
  
  double getPtMin();
  double getPtMax();
  double getEtaMax();
  double getDPt();
  double getDEta();
  double getIntPt();
  double getIntEta();
  double getNParameter();
  double getMResonance();
  double getChi2();
  
  
 private:

  std::vector<std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> >* InputJet_;
  std::vector<double>* KK_;
  std::vector<double>* sKK_;
  double MResonance_;
  
  double PtMin_;
  double PtMax_;
  double EtaMax_;
  
  double DPt_;
  double DEta_;
  
  int intPt_;
  int intEta_;
  Int_t nParameter_;
  
  TRandom* myRand_;

  CLHEP::HepMatrix* JMat_;
  CLHEP::HepVector* Chi2Vector_;
    
};

#endif

