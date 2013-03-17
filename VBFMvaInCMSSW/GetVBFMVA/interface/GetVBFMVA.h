#ifndef GetVBFMVA_h
#define GetVBFMVA_h

#include "TMVA/Reader.h"

class GetVBFMVA {

 public:
  GetVBFMVA();
  ~GetVBFMVA();

  void init(std::string methodName, std::string weightsfile);
  double getValue(double jetpt1,double jetpt2,double absjeteta1,double absjeteta2,double signjeteta1eta2,double logmjj,double detajj,double dphilljetjet);

 private:

  TMVA::Reader* theReader;

  //common variables
  float jetpt1_;
  float jetpt2_;
  float absjeteta1_;
  float absjeteta2_;
  float signjeteta1eta2_;
  float logmjj_;
  float detajj_;
  float dphilljetjet_;

  std::string methodname_;

  bool isInit;

};

#endif