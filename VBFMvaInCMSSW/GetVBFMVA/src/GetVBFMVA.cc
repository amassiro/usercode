#include "VBFMvaInCMSSW/GetVBFMVA/interface/GetVBFMVA.h"

GetVBFMVA::GetVBFMVA():isInit(false){
 init(
   "BDT",
   getenv("CMSSW_BASE")+std::string("/src/VBFMvaInCMSSW/GetVBFMVA/data/TMVA_2j_BDT.weights.xml")
  );
}

GetVBFMVA::~GetVBFMVA(){
  delete theReader;
}

void GetVBFMVA::init(std::string methodName, std::string weightsfile){

  if (isInit) return;

  theReader = new TMVA::Reader();

  theReader->AddVariable( "jetpt1"                     , &jetpt1_           );
  theReader->AddVariable( "jetpt2"                     , &jetpt2_           );
  theReader->AddVariable( "abs(jeteta1)"               , &absjeteta1_       );
  theReader->AddVariable( "abs(jeteta2)"               , &absjeteta2_       );
  theReader->AddVariable( "sign(jeteta1*jeteta2)"      , &signjeteta1eta2_  );
  theReader->AddVariable( "log(mjj)"                   , &logmjj_              );
  theReader->AddVariable( "detajj"                     , &detajj_           );
  theReader->AddVariable( "dphilljetjet"               , &dphilljetjet_     );

  theReader->BookMVA(methodName,weightsfile);

  methodname_ = methodName;
  isInit = true;
}


double GetVBFMVA::getValue(
   double jetpt1,
   double jetpt2,
   double absjeteta1,
   double absjeteta2,
   double signjeteta1eta2,
   double logmjj,
   double detajj,
   double dphilljetjet
                          ){

  if (!isInit) {
   std::cerr << "MVA reader not initialized!" << std::endl;
   return -999.;
  }

  jetpt1_ = jetpt1;
  jetpt2_ = jetpt2;
  absjeteta1_ = absjeteta1;
  absjeteta2_ = absjeteta2;
  signjeteta1eta2_ = signjeteta1eta2;
  logmjj_ = logmjj;
  detajj_ = detajj;
  dphilljetjet_ = dphilljetjet;

  return theReader->EvaluateMVA( methodname_ );

}

