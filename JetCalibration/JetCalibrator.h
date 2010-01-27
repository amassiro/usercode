/*
Class JetCalibrator
*/
#ifndef JetCalibrator_h
#define JetCalibrator_h


#include "treeReader.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"

#include "Math/GenVector/VectorUtil.h"

#include "TRandom3.h"

#include "include/Utils.h"

#include <time.h>
#include <sstream>





class JetCalibrator{
 
 protected:
  
 public:
  JetCalibrator();
  JetCalibrator(double MResonance,double PtMax,double EtaMax, double DPt, double DEta);
  ~JetCalibrator();
  
  void Update();
  void Update(int alpha);
  void Update(int alpha, int rand);
  void Update(std::vector<double>* KK_In, int alpha, int rand);
  
  void UpdateKUpdate();
  void UpdateKUpdate(std::vector<double>* KK_In);
   
  void UpdateRUL3();
  void UpdateRUL3(std::vector<double>* KK_In);
  
  void AddJetPair(std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>& InputJetPair);
  
  double getKK(double eta, double pT);
  double getKK(int num);
  
  double getPtMax();
  double getEtaMax();
  double getDPt();
  double getDEta();
  double getIntPt();
  double getIntEta();
  double getNParameter();
  double getMResonance();
  
  
 private:

  std::vector<std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> >* InputJet_;
  std::vector<double>* KK_;
  double MResonance_;
  
  double PtMax_;
  double EtaMax_;
  
  double DPt_;
  double DEta_;
  
  int intPt_;
  int intEta_;
  Int_t nParameter_;
  
  TRandom* myRand_;

};

#endif

