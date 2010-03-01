/*
Class JetCalibrator
*/

#include "JetCalibrator.h"

///=====================
///==== Constructor ====

JetCalibrator::JetCalibrator(){ 
 JetCalibrator(80.0,0,100,4,2.5,0.4); //---- default values ----
}

JetCalibrator::JetCalibrator(double MResonance,double PtMin,double PtMax,double EtaMax, double DPt, double DEta){
 myRand_ = new TRandom(0); // Creates a random number generator object with seed 0
 InputJet_ = new std::vector<std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> >;
 MResonance_ = MResonance;
 PtMin_ = PtMin;
 PtMax_ = PtMax;
 EtaMax_ = EtaMax;
 DPt_ = DPt;
 DEta_ = DEta;
 intPt_ = static_cast<int>((PtMax_-PtMin_) / DPt_);
 intEta_ = static_cast<int>(EtaMax_ / DEta_);
 nParameter_ = intPt_ * intEta_;
 
 //---- correct ptMax & etaMax --> DPt * intPt_ + PtMin- == PtMax_ --> trunk range!
 PtMax_ = PtMin_ + intPt_ * DPt_;
 EtaMax_ = intEta_ * DEta_;
 
 KK_ = new std::vector<double>;
 for (int ii=0; ii< nParameter_; ii++) {
  KK_->push_back(1.0);
 }
 sKK_ = new std::vector<double>; //---- squared ----
 for (int ii=0; ii< nParameter_; ii++) {
  sKK_->push_back(1.0); 
 }
 
 JMat_ = new CLHEP::HepMatrix(nParameter_,nParameter_);
 Chi2Vector_  = new CLHEP::HepVector(nParameter_);
}


///====================
///==== Destructor ====
JetCalibrator::~JetCalibrator(){
 //---- destroy everything ----
 delete sKK_;
 delete KK_;
 delete InputJet_;
 delete myRand_;
}


///=============
///==== Add ====

bool JetCalibrator::AddJetPair(std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>& InputJetPair){
 int iPt1 = GetIntPt(InputJetPair.first.Pt());
 int iEta1 = GetIntEta(InputJetPair.first.Eta());
 
 int iPt2 = GetIntPt(InputJetPair.second.Pt());
 int iEta2 = GetIntEta(InputJetPair.second.Eta());
 
 if ((iPt1 != -1) && (iPt2 != -1) && (iEta1 != -1) && (iEta2 != -1)){ //---- add jet only if in the correct range ----
  InputJet_->push_back(InputJetPair);
  return true;
 }
 else return false;
}


///================
///==== Update ====
void JetCalibrator::Update(){
 Update(KK_,1,0);
}

void JetCalibrator::Update(int alpha){
 Update(KK_,alpha,0);
}

void JetCalibrator::Update(int alpha, int rand){
 Update(KK_,alpha, rand);
}


//---- rand = 0 No Rand, rand = 1 Yes Rand ----
void JetCalibrator::Update(std::vector<double>* KK_In, int alpha, int rand){
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
  int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
  
  int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
  
  double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
  
  double Up_temp = 80.0 * 80.0 / (M_temp * M_temp * KK_In->at(GetInt(iPt1,iEta1))* KK_In->at(GetInt(iPt2,iEta2)));
  Up_temp = sqrt (Up_temp);
  double newUp = Up_temp;
  for (int ll=1; ll< alpha; ll++) {
   Up_temp = Up_temp * newUp;
  }
  
  double Down_temp = KK_In->at(GetInt(iPt1,iEta1))* KK_In->at(GetInt(iPt2,iEta2));
  double newDown = Down_temp;
  Down_temp = 1;
  
  for (int ll=1; ll< (alpha/2); ll++) {
   Down_temp = Down_temp * newDown;
  }
  
  Up->at(GetInt(iPt1,iEta1)) = (Up->at(GetInt(iPt1,iEta1)) + Up_temp);
  Down->at(GetInt(iPt1,iEta1)) = (Down->at(GetInt(iPt1,iEta1)) + Down_temp);
  
  Up->at(GetInt(iPt2,iEta2)) = (Up->at(GetInt(iPt2,iEta2)) + Up_temp);
  Down->at(GetInt(iPt2,iEta2)) = (Down->at(GetInt(iPt2,iEta2)) + Down_temp);
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


///================
///==== Minuit ====

// void JetCalibrator::Chi2Minuit(Int_t& npar, Double_t* d, Double_t& r, Double_t par[], Int_t flag){
//  int n = InputJet_->size();
//  double result = 0.0;
//  for (int ijet=0; ijet<n; ijet++){
//   int iPt1 = GetIntPt(InputJet_->at(ijet).first.Pt());
//   int iEta1 = GetIntEta(InputJet_->at(ijet).first.Eta());
//   int iPt2 = GetIntPt(InputJet_->at(ijet).second.Pt());
//   int iEta2 = GetIntEta(InputJet_->at(ijet).second.Eta());
//   int iK = GetInt(iPt1,iEta1);
//   int jK = GetInt(iPt2,iEta2);  
//   double M_temp = ((InputJet_->at(ijet).first) + (InputJet_->at(ijet).second)).M();
//   result += ((par[iK] * par[jK] * M_temp - MResonance_) * (par[iK] * par[jK] * M_temp - MResonance_));
//  }
// }


double JetCalibrator::Chi2Minuit(const double * sKK_In){
  int n = InputJet_->size();
  double result = 0.0;
  for (int ijet=0; ijet<n; ijet++){
  int iPt1 = GetIntPt(InputJet_->at(ijet).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(ijet).first.Eta());
  int iPt2 = GetIntPt(InputJet_->at(ijet).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(ijet).second.Eta());
  int iK = GetInt(iPt1,iEta1);
  int jK = GetInt(iPt2,iEta2);  
  double M_temp = ((InputJet_->at(ijet).first) + (InputJet_->at(ijet).second)).M();
//   result += ((sKK_In[iK] * sKK_In[jK] * M_temp - MResonance_) * (sKK_In[iK] * sKK_In[jK] * M_temp - MResonance_));
  result += ((sKK_In[iK] * sKK_In[jK] * M_temp - MResonance_) * (sKK_In[iK] * sKK_In[jK] * M_temp - MResonance_) / (sKK_In[iK] * sKK_In[jK] * sKK_In[iK] * sKK_In[jK]));
  //   result += fabs((sKK_In[iK] * sKK_In[jK] * M_temp / MResonance_ - 1));
 }
 return result;
}

void JetCalibrator::UpdateMIB(){
 for (int i=0; i<nParameter_; i++){ 
  sKK_->at(i) = sqrt(KK_->at(i));
 }
 
 ROOT::Math::Minimizer* minuit = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
 
//  ROOT::Math::MinuitMinimizer minuit( ROOT::Math::kVectorBFGS );
 minuit->SetMaxFunctionCalls(1000000);
 minuit->SetMaxIterations(100000);
 minuit->SetTolerance(0.001);
 
 ROOT::Math::Functor functor(this,&JetCalibrator::Chi2Minuit,nParameter_); 
 minuit->SetFunction(functor);
 
 double par[nParameter_];
 double stepSize[nParameter_];
 double minVal[nParameter_];
 double maxVal[nParameter_];
 std::string parName[nParameter_];
 
 for (int ii=0; ii< nParameter_; ii++) {
  par[ii] = sKK_->at(ii);
  stepSize[ii] = 0.0001;
  minVal[ii] = 0.1;
  maxVal[ii] = 3.5;
  std::ostringstream oss;
  oss << ii;
  std::string s_temp(oss.str());
  parName[ii] = s_temp;
 }
 
 for (int i=0; i<nParameter_; i++){
  minuit->SetLimitedVariable(i,parName[i].c_str(),par[i],stepSize[i],minVal[i],maxVal[i]);
 }
 
 ///------------------
 minuit->Minimize(); 
 ///------------------
 
 const double *outParameters = minuit->X();
 const double *errParameters = minuit->Errors();
 for (int ii=0; ii< nParameter_; ii++) {
  sKK_->at(ii) = outParameters[ii];
  KK_->at(ii) = outParameters[ii] * outParameters[ii];
 }
 
}

///=========================
///==== MatrixInversion ====

void JetCalibrator::InitializeMatrix(){
 for (int i=0; i<nParameter_; i++){ 
  for (int j=0; j<nParameter_; j++){ 
   (*JMat_)[i][j] = 0.0;
  }
 }
 for (int i=0; i<nParameter_; i++){ 
  sKK_->at(i) = sqrt(KK_->at(i));
 }
}


void JetCalibrator::FillMatrix(){
 for (int i=0; i<nParameter_; i++){ 
  for (int j=0; j<nParameter_; j++){ 
   (*JMat_)[i][j] = DDChi2(sKK_,i,j);
   std::cerr << "    JMat_[" << i << "][" << j << "] = " << (*JMat_)[i][j] << std::endl;
  }
 }
}



void JetCalibrator::FillVector(){
 for (int i=0; i<nParameter_; i++){ 
  (*Chi2Vector_)[i] = - DChi2(sKK_,i);
  std::cerr << "    Chi2Vector_[" << i << "] = " << (*Chi2Vector_)[i] << std::endl;
 }
}



void JetCalibrator::InvertMatrix(){
 FillVector();
 CLHEP::HepVector dsKK = CLHEP::solve (*JMat_,*Chi2Vector_) ;
 for (int i=0; i<nParameter_; i++){ 
  sKK_->at(i) = sKK_->at(i) + dsKK[i];
  if (dsKK[i]>=0) KK_->at(i) = KK_->at(i) + (dsKK[i] * dsKK[i]);
  else KK_->at(i) = KK_->at(i) - (dsKK[i] * dsKK[i]);
  std::cerr << "    dsKK[" << i << "] = " << dsKK[i] << " -> KK[" << i << "] = " << KK_->at(i) << std::endl;
 }
}

void JetCalibrator::UpdateMatrixInversion(){
 std::cerr << "*** UpdateMatrixInversion ***" << std::endl;
 InitializeMatrix();
 std::cerr << "*** *** Initialized ***" << std::endl; 
 FillMatrix();
 std::cerr << "*** *** Filled ***" << std::endl;
 InvertMatrix();
 std::cerr << "*** *** Inverted ***" << std::endl;
}

double JetCalibrator::Chi2(std::vector<double>* sKK_In){
 double result = 0;
 int n = InputJet_->size();
 for (int ijet=0; ijet<n; ijet++){
  int iPt1 = GetIntPt(InputJet_->at(ijet).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(ijet).first.Eta());
  int iPt2 = GetIntPt(InputJet_->at(ijet).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(ijet).second.Eta());
  int iK = GetInt(iPt1,iEta1);
  int jK = GetInt(iPt2,iEta2);  
  double M_temp = ((InputJet_->at(ijet).first) + (InputJet_->at(ijet).second)).M();
//   result += ((KK_In->at(iK) * KK_In->at(jK) * M_temp * M_temp - MResonance_ * MResonance_) * (KK_In->at(iK) * KK_In->at(jK) * M_temp * M_temp - MResonance_ * MResonance_));    
  result += ((sKK_In->at(iK) * sKK_In->at(jK) * M_temp - MResonance_) * (sKK_In->at(iK) * sKK_In->at(jK) * M_temp - MResonance_) / (sKK_In->at(iK) * sKK_In->at(jK) * sKK_In->at(iK) * sKK_In->at(jK))); 
 }
 return result;
}

double JetCalibrator::DChi2(std::vector<double>* KK_In, int i){
 double result = 0;
 int n = InputJet_->size();
 for (int ijet=0; ijet<n; ijet++){
  int iPt1 = GetIntPt(InputJet_->at(ijet).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(ijet).first.Eta());
  int iPt2 = GetIntPt(InputJet_->at(ijet).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(ijet).second.Eta());
 
  int iK = GetInt(iPt1,iEta1);
  int jK = GetInt(iPt2,iEta2);  
  if (iK == i || jK == i) { //---- right position --- one on the two jets
   if (iK == i && jK == i){ //---- same position
    double M_temp = ((InputJet_->at(ijet).first) + (InputJet_->at(ijet).second)).M();
//     result += (2. * (KK_In->at(iK) * KK_In->at(iK) * M_temp * M_temp - MResonance_ * MResonance_) * 2. * M_temp * M_temp * KK_In->at(iK));    
//     result += (2. * (KK_In->at(iK) * KK_In->at(iK) * M_temp - MResonance_) * 2. * M_temp * KK_In->at(iK));    
result += (4. * MResonance_ * (KK_In->at(iK) * KK_In->at(iK) * M_temp - MResonance_) / (KK_In->at(iK) * KK_In->at(iK) * KK_In->at(iK) * KK_In->at(iK) * KK_In->at(iK)));
//     if ((2. * (KK_In->at(iK) * KK_In->at(iK) * M_temp - MResonance_) * 2. * M_temp * KK_In->at(iK)) < 0 ) std::cerr << " ciao = " << (2. * (KK_In->at(iK) * KK_In->at(iK) * M_temp - MResonance_) * 2. * M_temp * KK_In->at(iK)) << std::endl;
   }
   else { //---- different position
    if (iK == i){ //---- iK == i && jK != i
     double M_temp = ((InputJet_->at(ijet).first) + (InputJet_->at(ijet).second)).M();
//      result += (2. * (KK_In->at(iK) * KK_In->at(jK) * M_temp * M_temp - MResonance_ * MResonance_) * M_temp * M_temp * KK_In->at(jK)); 
//      result += (2. * (KK_In->at(iK) * KK_In->at(jK) * M_temp - MResonance_) * M_temp * KK_In->at(jK)); 
result += (2. * MResonance_ * (KK_In->at(iK) * KK_In->at(jK) * M_temp - MResonance_) / ( KK_In->at(jK) * KK_In->at(jK) * KK_In->at(iK) * KK_In->at(iK) * KK_In->at(iK))); 
     
    }
    else if (jK == i) { //---- iK != i && jK == i
     double M_temp = ((InputJet_->at(ijet).first) + (InputJet_->at(ijet).second)).M();
//      result += (2. * (KK_In->at(iK) * KK_In->at(jK) * M_temp * M_temp - MResonance_ * MResonance_) * M_temp * M_temp * KK_In->at(iK));
     result += (2. * M_temp * (KK_In->at(iK) * KK_In->at(jK) * M_temp - MResonance_) / ( KK_In->at(iK) * KK_In->at(iK) * KK_In->at(jK) * KK_In->at(jK) * KK_In->at(jK))); 
    }
   }
  }
 }
//  if (result < 0) std::cerr << " negativo!" << std::endl;
 return result;
}

double JetCalibrator::DDChi2(std::vector<double>* KK_In, int iK, int jK){
 double result = 0;
 if (iK != jK){ //---- off diagonal element
  int n = InputJet_->size();
  for (int i=0; i<n; i++){
   int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
   int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
   int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
   int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
   if ((((GetInt(iPt1,iEta1)) == iK) && ((GetInt(iPt2,iEta2)) == jK)) || (((GetInt(iPt1,iEta1)) == jK) && ((GetInt(iPt2,iEta2)) == iK))){ //---- right position
    double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
//     result += (2. * (2. * KK_In->at(iK) * KK_In->at(jK) * M_temp * M_temp * M_temp * M_temp - M_temp * M_temp * MResonance_ * MResonance_));
//     result += (2. * (2. * KK_In->at(iK) * KK_In->at(jK) * M_temp * M_temp - M_temp * MResonance_));
    result += (2. * MResonance_ / (KK_In->at(iK) * KK_In->at(iK) * KK_In->at(iK) * KK_In->at(jK) * KK_In->at(jK) * KK_In->at(jK)) * (2. * MResonance_ - M_temp * KK_In->at(iK) * KK_In->at(jK)));
   }
  }
 }
 else { //---- diagonal element ---- iK == jK ----
  int n = InputJet_->size();
  for (int i=0; i<n; i++){
   int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
   int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
   int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
   int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
   if (((GetInt(iPt1,iEta1)) == iK) && ((GetInt(iPt2,iEta2)) == iK)){ //---- right position
    double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
//     result += (4. * (3. * KK_In->at(iK) * KK_In->at(iK) * M_temp * M_temp * M_temp * M_temp - M_temp * M_temp * MResonance_ * MResonance_));
//     result += (4. * (3. * KK_In->at(iK) * KK_In->at(iK) * M_temp * M_temp - M_temp * MResonance_));
    result += (4. * MResonance_ * (- 3. * KK_In->at(iK) * KK_In->at(iK) * M_temp + 5. * MResonance_) / (KK_In->at(iK) * KK_In->at(iK) * KK_In->at(iK) * KK_In->at(iK) * KK_In->at(iK) * KK_In->at(iK)));
   }
   else if ((GetInt(iPt1,iEta1)) == iK){
    double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
//     result += (2. * KK_In->at(GetInt(iPt2,iEta2)) * KK_In->at(GetInt(iPt2,iEta2)) * M_temp * M_temp * M_temp * M_temp);
//     result += (2. * KK_In->at(GetInt(iPt2,iEta2)) * KK_In->at(GetInt(iPt2,iEta2)) * M_temp * M_temp);
   result += (2. * MResonance_ / (KK_In->at(GetInt(iPt2,iEta2)) * KK_In->at(GetInt(iPt2,iEta2))) * (2. * KK_In->at(GetInt(iPt2,iEta2)) * KK_In->at(GetInt(iPt1,iEta1)) * M_temp - 3. * MResonance_) / (KK_In->at(GetInt(iPt1,iEta1)) * KK_In->at(GetInt(iPt1,iEta1)) * KK_In->at(GetInt(iPt1,iEta1)) * KK_In->at(GetInt(iPt1,iEta1))));
   }
   else if ((GetInt(iPt2,iEta2)) == iK){
    double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
//     result += (2. * KK_In->at(GetInt(iPt1,iEta1)) * KK_In->at(GetInt(iPt1,iEta1)) * M_temp * M_temp * M_temp * M_temp);
//     result += (2. * KK_In->at(GetInt(iPt1,iEta1)) * KK_In->at(GetInt(iPt1,iEta1)) * M_temp * M_temp);
    result += (2. * MResonance_ / (KK_In->at(GetInt(iPt1,iEta1)) * KK_In->at(GetInt(iPt1,iEta1))) * (2. * KK_In->at(GetInt(iPt1,iEta1)) * KK_In->at(GetInt(iPt2,iEta2)) * M_temp - 3. * MResonance_) / (KK_In->at(GetInt(iPt2,iEta2)) * KK_In->at(GetInt(iPt2,iEta2)) * KK_In->at(GetInt(iPt2,iEta2)) * KK_In->at(GetInt(iPt2,iEta2))));
   }
  }
 }
 return result;
}


///==============
///==== SFit ====

void JetCalibrator::UpdateSFit(){
 UpdateSFit(KK_);
}


void JetCalibrator::UpdateSFit(std::vector<double>* KK_In){
 std::vector<TH1F>* CorrH = new std::vector<TH1F>;
 for (int i=0; i<nParameter_; i++){
  std::ostringstream oss;
  oss << "h_" << i;
  std::string nameHisto(oss.str());
  TH1F h_tmp(nameHisto.c_str(),nameHisto.c_str(),1200,0,MResonance_*2); //---- invariant mass spectrum ----
  CorrH->push_back(h_tmp);
 }
 int n = InputJet_->size();
 std::cerr << "n = " << n << std::endl;
 for (int i=0; i<n; i++){
  //---- previous position ----
  int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
  int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
  double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
  double M2_temp = M_temp * M_temp * KK_In->at(GetInt(iPt1,iEta1))* KK_In->at(GetInt(iPt2,iEta2));
  CorrH->at(GetInt(iPt1,iEta1)).Fill(sqrt(M2_temp));
  CorrH->at(GetInt(iPt2,iEta2)).Fill(sqrt(M2_temp));
 }
 TF1 *gfit = new TF1("Gaussian","gaus",0,MResonance_*2); // Create the fit function
 for (int i=0; i<nParameter_; i++){
  if (CorrH->at(i).GetEntries() > 10){
   gfit->SetParameter(0,CorrH->at(i).GetEntries()/(MResonance_*2));  
   gfit->SetParameter(1,MResonance_);
   gfit->SetParameter(2,MResonance_/10);   
   gfit->SetParLimits(1,20,140);   
   gfit->SetParLimits(2,0.1,30.);   
   CorrH->at(i).Fit("Gaussian");
   Double_t mean = gfit->GetParameter(1); //value of 1st parameter
   double chisq=gfit->GetChisquare();
   double ndf=gfit->GetNDF();
   double chisqdf=chisq/ndf;
   if (chisqdf < 5) { 
    KK_In->at(i) = (MResonance_ / mean) * KK_In->at(i);
   }
  }
 }
 delete gfit;
 CorrH->clear();
 delete CorrH;
}



void JetCalibrator::UpdateSRooFit(){
 UpdateSRooFit(KK_);
}


void JetCalibrator::UpdateSRooFit(std::vector<double>* KK_In){
 RooRealVar Mass("Mass","Mass",MResonance_,0,MResonance_*2);
 RooRealVar Iter("Iter","Iter",0,nParameter_);
 RooDataSet DataSet("DataSet","DataSet",RooArgSet(Mass,Iter)); 
 int n = InputJet_->size();
 std::cerr << "n = " << n << std::endl;
 for (int i=0; i<n; i++){
  //---- previous position ----
  int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
  int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
  int Iter1 = -1;
  if (iPt1!= -1 && iEta1 != -1) Iter1 = GetInt(iPt1,iEta1);
  int Iter2 = -1;
  if (iPt2!= -1 && iEta2 != -1) Iter2 = GetInt(iPt2,iEta2);
  if (Iter1!= -1 && Iter2!= -1){
   Mass = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M() * sqrt(KK_In->at(Iter1)* KK_In->at(Iter2));
   Iter = Iter1;
   DataSet.add(RooArgSet(Mass,Iter));
   Iter = Iter2;
   DataSet.add(RooArgSet(Mass,Iter));
  }
 }
 
 for (int iPar=0; iPar<nParameter_; iPar++){
  RooRealVar Mean_Fit("Mean_Fit","Mean Fit",0,MResonance_*2);
  RooRealVar Sigma_Fit("Sigma_Fit","Sigma Fit",10.0,0.1,100);
  RooGaussian gauss("gauss","gaussian PDF",Mass,Mean_Fit,Sigma_Fit);
//   RooRealVar a0("a0","a0",0,-0.1,0.1);
//   RooRealVar a1("a1","a1",0,-0.1,0.1);
//   RooRealVar frac("frac","frac",1,0,2);
//   RooPolynomial poly("poly","poly",Mass,RooArgList(a0,a1));
//   RooAddPdf pdfSum("pdfSum","gauss+poly",RooArgList(gauss,poly),RooArgList(frac));
  Iter.setRange("toAnalyse",iPar-0.1,iPar+0.9);
//   RooFitResult * result = 
  gauss.fitTo(DataSet,RooFit::Range("toAnalyse"),RooFit::Save(0),RooFit::PrintLevel(-1)); 
//   TCanvas c1;
  RooPlot* Massframe = Mass.frame(0,2*MResonance_,n / nParameter_ / 10);  
  DataSet.plotOn(Massframe, RooFit::Name("DataSet_1")); //, RooFit::MarkerColor(kBlack)); 
  gauss.plotOn(Massframe, RooFit::Name("gauss_1"),RooFit::LineColor(kRed));//, RooFit::MarkerColor(kBlack)); 
  Massframe->Draw () ;
  
//   std::ostringstream oss;
//   oss << "plot/gif_DataSet_" << iPar << ".gif";
//   std::string nameGif(oss.str());
//   c1.Print (nameGif.c_str(),"gif") ;
  //   poly.plotOn(Massframe, RooFit::LineColor(kBlack), RooFit::LineStyle(kDashed)); 
  Double_t chi2 = Massframe->chiSquare("gauss_1","DataSet_1", 2);
  std::cerr << ">>> chi2         = " << Massframe->chiSquare("gauss_1","DataSet_1") << std::endl;
  std::cerr << ">>> chi2 reduced = " << chi2 << std::endl;
  //   double Mll=result->minNll();
  if (chi2 < 5) { 
   KK_In->at(iPar) = (MResonance_ / Mean_Fit.getVal()) * KK_In->at(iPar);
  }
 }


 
//  RooRealVar Mass("Mass","Mass",MResonance_,0,MResonance_*2);
//  std::vector<RooDataSet> vectDataSet;
//  for (int iPar=0; iPar<nParameter_; iPar++){
//   std::ostringstream oss;
//   oss << "DataSet_" << iPar;
//   std::string nameDataSet(oss.str());
//   RooDataSet DataSet_temp(nameDataSet.c_str(),nameDataSet.c_str(),RooArgSet(Mass));
//   vectDataSet.push_back(DataSet_temp);
//  }
//  int n = InputJet_->size();
//  std::cerr << "n = " << n << std::endl;
//  for (int i=0; i<n; i++){
//   //---- previous position ----
//   int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
//   int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
//   int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
//   int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
//   int Iter1 = -1;
//   if (iPt1!= -1 && iEta1 != -1) Iter1 = GetInt(iPt1,iEta1);
//   int Iter2 = -1;
//   if (iPt2!= -1 && iEta2 != -1) Iter2 = GetInt(iPt2,iEta2);
//   Mass = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
//   if (Iter1!= -1) vectDataSet.at(Iter1).add(RooArgSet(Mass));
//   if (Iter2!= -1) vectDataSet.at(Iter2).add(RooArgSet(Mass));
//  }
//  
//  for (int iPar=0; iPar<nParameter_; iPar++){
//   RooRealVar Mean_Fit("Mean_Fit","Mean Fit",0,MResonance_*2);
//   RooRealVar Sigma_Fit("Sigma_Fit","Sigma Fit",1.0);
//   RooGaussian gauss("gauss","gaussian PDF",Mass,Mean_Fit,Sigma_Fit);
//   RooRealVar a0("a0","a0",0);
//   RooRealVar a1("a1","a1",1);
//   RooRealVar frac("frac","frac",1);
//   RooPolynomial poly("poly","poly",Mass,RooArgList(a0,a1));
//   RooAddPdf pdfSum("pdfSum","gauss+poly",RooArgList(gauss,poly),frac);
//   RooFitResult* result = pdfSum.fitTo(vectDataSet.at(iPar));
//   result->Print();
//   std::cerr << "Mean =========> " << Mean_Fit.getVal() << std::endl;
//  }
//  
 
//  RooRealVar  Pt1("Pt1","Pt1", 0, intPt_);
//  RooRealVar  Eta1("Eta1","Eta1", 0, intEta_);  
//  RooRealVar  Pt2("Pt2","Pt2", 0, intPt_);
//  RooRealVar  Eta2("Eta2","Eta2", 0, intEta_);  
//  RooRealVar  Mass("Mass","Mass",0,MResonance_*2);
//  RooRealVar  Iter1("Iter1","Iter1", 0, nParameter_);
//  RooRealVar  Iter2("Iter2","Iter2", 0, nParameter_);
//  
//  RooDataSet DataSet("DataSet","DataSet",RooArgSet(Iter1,Iter2,Mass));
// //  RooDataSet DataSet("DataSet","DataSet",RooArgSet(Pt1,Eta1,Pt2,Eta2,Mass));
//  int n = InputJet_->size();
//  std::cerr << "n = " << n << std::endl;
//  for (int i=0; i<n; i++){
//   //---- previous position ----
//   int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
//   int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
//   int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
//   int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
//   Iter1 = GetInt(iPt1,iEta1);
//   Iter2 = GetInt(iPt2,iEta2);
//   Mass = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
//   DataSet.add(RooArgSet(Iter1,Iter2,Mass));
//  }
//  
//  for (int iPar=0; iPar<nParameter_; iPar++){
//   RooRealVar Mass_Fit("Mass_Fit","Mass Fit",0,MResonance_*2);
//   RooRealVar Mean_Fit("Mean_Fit","Mean Fit",0,MResonance_*2);
//   RooRealVar Sigma_Fit("Sigma_Fit","Sigma Fit",1.0);
//   Iter1.setRange("signal1",iPar,iPar+1);
//   Iter2.setRange("signal2",iPar,iPar+1);
//   RooGaussian gauss("gauss","gaussian PDF",Mass_Fit,Mean_Fit,Sigma_Fit) ;  
//   RooFitResult* result = gauss.fitTo(DataSet,RooFit::Range("signal1,signal2"),RooFit::Save());
//   result->Print();
//  }
}




///===============
///==== RUFit ====

void JetCalibrator::UpdateRUFit(){
 UpdateRUFit(KK_);
}


void JetCalibrator::UpdateRUFit(std::vector<double>* KK_In){
 std::vector<TH1F>* CorrH = new std::vector<TH1F>;
 for (int i=0; i<nParameter_; i++){
  std::ostringstream oss;
  oss << "h_" << i;
  std::string nameHisto(oss.str());
  TH1F h_tmp(nameHisto.c_str(),nameHisto.c_str(),1200,0,MResonance_*2); //---- invariant mass spectrum ----
  CorrH->push_back(h_tmp);
 }
 int n = InputJet_->size();
 std::cerr << "n = " << n << std::endl;
 for (int i=0; i<n; i++){
  //---- previous position ----
  int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
  int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
  double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
  double M2_temp = M_temp * M_temp * KK_In->at(GetInt(iPt1,iEta1))* KK_In->at(GetInt(iPt2,iEta2));
  CorrH->at(GetInt(iPt1,iEta1)).Fill(sqrt(M2_temp));
  CorrH->at(GetInt(iPt2,iEta2)).Fill(sqrt(M2_temp));
 }
 TF1 *gfit = new TF1("Gaussian","gaus",0,MResonance_*2); // Create the fit function
 for (int i=0; i<nParameter_; i++){
  if (CorrH->at(i).GetEntries() > 10){
   float test = 1;
   test = myRand_->Uniform(-1.0, 1.0);
   if (test>0) {
    gfit->SetParameter(0,CorrH->at(i).GetEntries()/(MResonance_*2));  
    gfit->SetParameter(1,MResonance_);
    gfit->SetParameter(2,MResonance_/10);   
    gfit->SetParLimits(1,20,140);   
    gfit->SetParLimits(2,0.1,30.);   
    CorrH->at(i).Fit("Gaussian");
    Double_t mean = gfit->GetParameter(1); //value of 1st parameter
    double chisq=gfit->GetChisquare();
    double ndf=gfit->GetNDF();
    double chisqdf=chisq/ndf;
    if (chisqdf < 5) { 
     KK_In->at(i) = (MResonance_ / mean) * (MResonance_ / mean) * KK_In->at(i);
    }
   }
  }
 }
 delete gfit;
 CorrH->clear();
 delete CorrH;
}


///============
///==== L3 ====

void JetCalibrator::UpdateL3(){
 UpdateL3(KK_);
}

void JetCalibrator::UpdateL3(std::vector<double>* KK_In){
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
  int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
  int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
  double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
  double Up_temp = 80.0 * 80.0 / (M_temp * M_temp * KK_In->at(GetInt(iPt1,iEta1))* KK_In->at(GetInt(iPt2,iEta2)));
  double Down_temp = 1.;
  
  Up->at(GetInt(iPt1,iEta1)) = (Up->at(GetInt(iPt1,iEta1)) + Up_temp);
  Down->at(GetInt(iPt1,iEta1)) = (Down->at(GetInt(iPt1,iEta1)) + Down_temp);
  
  Up->at(GetInt(iPt2,iEta2)) = (Up->at(GetInt(iPt2,iEta2)) + Up_temp);
  Down->at(GetInt(iPt2,iEta2)) = (Down->at(GetInt(iPt2,iEta2)) + Down_temp);
 }
 
 for (int i=0; i<nParameter_; i++){
  if (Down->at(i) > 0){
   KK_In->at(i) = (Up->at(i) / Down->at(i)) * KK_In->at(i);
  }
 }
 delete Up;
 delete Down; 
}


///==============
///==== RUL3 ====

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
  int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
  int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
  double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
 
  double Up_temp = 80.0 * 80.0 / (M_temp * M_temp * KK_In->at(GetInt(iPt1,iEta1))* KK_In->at(GetInt(iPt2,iEta2)));
  double Down_temp = 1.;
  
  Up->at(GetInt(iPt1,iEta1)) = (Up->at(GetInt(iPt1,iEta1)) + Up_temp);
  Down->at(GetInt(iPt1,iEta1)) = (Down->at(GetInt(iPt1,iEta1)) + Down_temp);
  
  Up->at(GetInt(iPt2,iEta2)) = (Up->at(GetInt(iPt2,iEta2)) + Up_temp);
  Down->at(GetInt(iPt2,iEta2)) = (Down->at(GetInt(iPt2,iEta2)) + Down_temp);
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



///=================
///==== kUpdate ====

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
  int iPt1 = GetIntPt(InputJet_->at(i).first.Pt());
  int iEta1 = GetIntEta(InputJet_->at(i).first.Eta());
  int iPt2 = GetIntPt(InputJet_->at(i).second.Pt());
  int iEta2 = GetIntEta(InputJet_->at(i).second.Eta());
  
  double M_temp = ((InputJet_->at(i).first) + (InputJet_->at(i).second)).M();
  double Up_temp = M_temp * M_temp * KK_In->at(GetInt(iPt1,iEta1));
  double Down_temp = Up_temp * Up_temp;
  
  Up->at(GetInt(iPt1,iEta1)) = (Up->at(GetInt(iPt1,iEta1)) + Up_temp);
  Down->at(GetInt(iPt1,iEta1)) = (Down->at(GetInt(iPt1,iEta1)) + Down_temp);
  
  if ((GetInt(iPt2,iEta2)) == (GetInt(iPt1,iEta1))) continue; //---- if the same, use one time!
   
   Up_temp = M_temp * M_temp * KK_In->at(GetInt(iPt2,iEta2));
  Down_temp = Up_temp * Up_temp;
  
  Up->at(GetInt(iPt2,iEta2)) = (Up->at(GetInt(iPt2,iEta2)) + Up_temp);
  Down->at(GetInt(iPt2,iEta2)) = (Down->at(GetInt(iPt2,iEta2)) + Down_temp);
 }
 
 for (int i=0; i<nParameter_; i++){ 
  
  if (Down->at(i) > 0){
   KK_In->at(i) = MResonance_ * MResonance_ * (Up->at(i) / Down->at(i)) ; //* KK_In->at(i);
  }
 }
 delete Up;
 delete Down;  
}



///============================
///==== retrieve functions ====

double JetCalibrator::getKK(double eta, double pT){
 int iPt = GetIntPt(pT);
 int iEta = GetIntEta(eta); 
 if ((iPt != -1) && (iEta != -1)){
  return KK_->at(GetInt(iPt,iEta));
 }
 else return 1;
}


double JetCalibrator::getKK(int num){
 if (num < nParameter_){
  return KK_->at(num);
 }
 else return 1;
}


int JetCalibrator::GetInt(int iPt,int iEta){
 return (iPt * intEta_ + iEta);
}

int JetCalibrator::GetIntPt(double Pt){
 if (Pt >= PtMin_ && Pt < PtMax_){ //---- [min, max) ----
  int iPt = static_cast<int>((Pt - PtMin_) / DPt_ );
  return iPt;
 }
 else return -1; //---- -1 == error! ----
}

int JetCalibrator::GetIntEta(double Eta){
 if (Eta < EtaMax_){//---- [min, max) ----
  int iEta = static_cast<int>(fabs(Eta / DEta_));
  return iEta;
 }
 else return -1; //---- -1 == error! ----
}


double JetCalibrator::getPtMin(){ return PtMin_;}
double JetCalibrator::getPtMax(){ return PtMax_;}
double JetCalibrator::getEtaMax() { return EtaMax_;}
double JetCalibrator::getDPt() { return DPt_;}
double JetCalibrator::getDEta() { return DEta_;}
double JetCalibrator::getIntPt() { return intPt_;}
double JetCalibrator::getIntEta() { return intEta_;}
double JetCalibrator::getNParameter() { return nParameter_;}
double JetCalibrator::getMResonance() { return MResonance_;}
double JetCalibrator::getChi2(){ return Chi2(KK_);}

 


