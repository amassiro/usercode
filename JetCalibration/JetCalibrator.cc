/*
Class JetCalibrator
*/

#include "JetCalibrator.h"


///--- Constructor ---
JetCalibrator::JetCalibrator(){ 
 JetCalibrator(80.0,100,4,2.5,0.4);
}


JetCalibrator::JetCalibrator(double MResonance,double PtMax,double EtaMax, double DPt, double DEta){
 
 myRand_ = new TRandom(0); // Creates a random number generator object with seed 0
 InputJet_ = new std::vector<std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> >;
 
 MResonance_ = MResonance;
 PtMax_ = PtMax;
 EtaMax_ = EtaMax;
 DPt_ = DPt;
 DEta_ = DEta;
 
 intPt_ = static_cast<int>(PtMax_ / DPt_);
 intEta_ = static_cast<int>(EtaMax_ / DEta_);
 nParameter_ = intPt_ * intEta_;
 
 KK_ = new std::vector<double>;
 for (int ii=0; ii< nParameter_; ii++) {
  KK_->push_back(1.);
 }
}

///--- Destructor ---
JetCalibrator::~JetCalibrator(){
 //---- destroy everything ----
 delete KK_;
 delete InputJet_;
 delete myRand_;
}


///---- Add ----

void JetCalibrator::AddJetPair(std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>& InputJetPair){
 int iPt1 = static_cast<int>(InputJetPair.first.Pt() / DPt_ );
 int iEta1 = static_cast<int>(fabs(InputJetPair.first.Eta() / DEta_));
 
 int iPt2 = static_cast<int>(InputJetPair.second.Pt() / DPt_ );
 int iEta2 = static_cast<int>(fabs(InputJetPair.second.Eta() / DEta_));
 
 if ((iPt1 < intPt_) && (iPt2 < intPt_) && (iEta1 < intEta_) && (iEta2 < intEta_)){
  InputJet_->push_back(InputJetPair);
 }
}


///---- Update ----
void JetCalibrator::Update(){
 Update(KK_,1,0);
}

void JetCalibrator::Update(int alpha){
 Update(KK_,alpha,0);
}

void JetCalibrator::Update(int alpha, int rand){
 Update(KK_,alpha, rand);
}


void JetCalibrator::Update(std::vector<double>* KK_In, int alpha, int rand){ //---- rand = 0 No Rand, rand = 1 Yes Rand ----
std::vector<double>* Up = new std::vector<double>;
std::vector<double>* Down = new std::vector<double>;
for (int i=0; i<nParameter_; i++){
 Up->push_back(0.);
 Down->push_back(0.);
}
int n = InputJet_->size();
std::cerr << "n = " << n << std::endl;
for (int i=0; i<n; i++){
 //---- previous position ----
 int iPt1 = static_cast<int>(InputJet_->at(i).first.Pt() / DPt_);
 int iEta1 = static_cast<int>(fabs(InputJet_->at(i).first.Eta() / DEta_));
 
 int iPt2 = static_cast<int>(InputJet_->at(i).second.Pt() / DPt_);
 int iEta2 = static_cast<int>(fabs(InputJet_->at(i).second.Eta() / DEta_));
 
 double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
 
 double Up_temp = 80.0 * 80.0 / (M_temp * M_temp * KK_In->at(iPt1 * intEta_ + iEta1)* KK_In->at(iPt2 * intEta_ + iEta2));
 Up_temp = sqrt (Up_temp);
 double newUp = Up_temp;
 for (int ll=1; ll< alpha; ll++) {
  Up_temp = Up_temp * newUp;
 }
 
 double Down_temp = KK_In->at(iPt1 * intEta_ + iEta1)* KK_In->at(iPt2 * intEta_ + iEta2);
 double newDown = Down_temp;
 Down_temp = 1;
 
 for (int ll=1; ll< (alpha/2); ll++) {
  Down_temp = Down_temp * newDown;
 }
 
 Up->at(iPt1 * intEta_ + iEta1) = (Up->at(iPt1 * intEta_ + iEta1) + Up_temp);
 Down->at(iPt1 * intEta_ + iEta1) = (Down->at(iPt1 * intEta_ + iEta1) + Down_temp);
 
 Up->at(iPt2 * intEta_ + iEta2) = (Up->at(iPt2 * intEta_ + iEta2) + Up_temp);
 Down->at(iPt2 * intEta_ + iEta2) = (Down->at(iPt2 * intEta_ + iEta2) + Down_temp);
}

for (int i=0; i<nParameter_; i++){ 
 if (Down->at(i) > 0){
  float test = 1;
  if (rand==1) {
   test = myRand_->Uniform(-1.0, 1.0);
  }
  if (test>0) {
   KK_In->at(i) = (Up->at(i) / Down->at(i)) * KK_In->at(i);
  }
 }
 
}

delete Up;
delete Down; 
}



void JetCalibrator::UpdateRUL3(){
 UpdateRUL3(KK_);
}
 
void JetCalibrator::UpdateRUL3(std::vector<double>* KK_In){
 std::vector<double>* Up = new std::vector<double>;
 std::vector<double>* Down = new std::vector<double>;
 for (int i=0; i<nParameter_; i++){
  Up->push_back(0.);
  Down->push_back(0.);
 }
 int n = InputJet_->size();
 std::cerr << "n = " << n << std::endl;
 for (int i=0; i<n; i++){
  //---- previous position ----
  int iPt1 = static_cast<int>(InputJet_->at(i).first.Pt() / DPt_);
  int iEta1 = static_cast<int>(fabs(InputJet_->at(i).first.Eta() / DEta_));
  
  int iPt2 = static_cast<int>(InputJet_->at(i).second.Pt() / DPt_);
  int iEta2 = static_cast<int>(fabs(InputJet_->at(i).second.Eta() / DEta_));
  
  double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
 
  
  double Up_temp = 80.0 * 80.0 / (M_temp * M_temp * KK_In->at(iPt1 * intEta_ + iEta1)* KK_In->at(iPt2 * intEta_ + iEta2));
  double Down_temp = 1.;
  
  Up->at(iPt1 * intEta_ + iEta1) = (Up->at(iPt1 * intEta_ + iEta1) + Up_temp);
  Down->at(iPt1 * intEta_ + iEta1) = (Down->at(iPt1 * intEta_ + iEta1) + Down_temp);
  
  Up->at(iPt2 * intEta_ + iEta2) = (Up->at(iPt2 * intEta_ + iEta2) + Up_temp);
  Down->at(iPt2 * intEta_ + iEta2) = (Down->at(iPt2 * intEta_ + iEta2) + Down_temp);
 }
 
 for (int i=0; i<nParameter_; i++){
  float test = 1;
  if (Down->at(i) > 0){
   test = myRand_->Uniform(-1.0, 1.0);
   if (test>0) KK_In->at(i) = (Up->at(i) / Down->at(i)) * KK_In->at(i);
  }
 }
 delete Up;
 delete Down; 
}


void JetCalibrator::UpdateKUpdate(){
 UpdateKUpdate(KK_);
}

void JetCalibrator::UpdateKUpdate(std::vector<double>* KK_In){
 std::vector<double>* Up = new std::vector<double>;
 std::vector<double>* Down = new std::vector<double>;
 for (int i=0; i<nParameter_; i++){
  Up->push_back(0.);
  Down->push_back(0.);
 }
 int n = InputJet_->size();
 std::cerr << "n = " << n << std::endl;
 for (int i=0; i<n; i++){
  //---- previous position ----
  int iPt1 = static_cast<int>(InputJet_->at(i).first.Pt() / DPt_);
  int iEta1 = static_cast<int>(fabs(InputJet_->at(i).first.Eta() / DEta_));
  
  int iPt2 = static_cast<int>(InputJet_->at(i).second.Pt() / DPt_);
  int iEta2 = static_cast<int>(fabs(InputJet_->at(i).second.Eta() / DEta_));
  
  
  double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
  
  double Up_temp = M_temp * M_temp * KK_In->at(iPt1 * intEta_ + iEta1);
  double Down_temp = Up_temp * Up_temp;
  
  Up->at(iPt1 * intEta_ + iEta1) = (Up->at(iPt1 * intEta_ + iEta1) + Up_temp);
  Down->at(iPt1 * intEta_ + iEta1) = (Down->at(iPt1 * intEta_ + iEta1) + Down_temp);
  
  if ((iPt2 * intEta_ + iEta2) == (iPt1 * intEta_ + iEta1)) continue; //---- if the same, use one time!
   
   Up_temp = M_temp * M_temp * KK_In->at(iPt2 * intEta_ + iEta2);
  Down_temp = Up_temp * Up_temp;
  
  Up->at(iPt2 * intEta_ + iEta2) = (Up->at(iPt2 * intEta_ + iEta2) + Up_temp);
  Down->at(iPt2 * intEta_ + iEta2) = (Down->at(iPt2 * intEta_ + iEta2) + Down_temp);
 }
 
 for (int i=0; i<nParameter_; i++){ 
  
  if (Down->at(i) > 0){
   KK_In->at(i) = MResonance_ * MResonance_ * (Up->at(i) / Down->at(i)) ; //* KK_In->at(i);
  }
 }
 delete Up;
 delete Down;  
}



///---- retrieve ----

double JetCalibrator::getKK(double eta, double pT){
 
 int iPt = static_cast<int>(pT / DPt_);
 int iEta = static_cast<int>(eta / DEta_);
 
 if ((iPt < intPt_) && (iEta < intEta_)){
  return KK_->at(iPt * intEta_ + iEta);
 }
 else return 1;
}


double JetCalibrator::getKK(int num){
 if (num < nParameter_){
  return KK_->at(num);
 }
 else return 1;
}


double JetCalibrator::getPtMax(){ return PtMax_;}
double JetCalibrator::getEtaMax() { return EtaMax_;}
double JetCalibrator::getDPt() { return DPt_;}
double JetCalibrator::getDEta() { return DEta_;}
double JetCalibrator::getIntPt() { return intPt_;}
double JetCalibrator::getIntEta() { return intEta_;}
double JetCalibrator::getNParameter() { return nParameter_;}
double JetCalibrator::getMResonance() { return MResonance_;}



