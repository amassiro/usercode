/*
Class CaVa
*/

#include "CaVa.h"

///=====================
///==== Constructor ====

CaVa::CaVa(TTree* inputTree, double Mass_W){
 myRand_ = new TRandom(0); // Creates a random number generator object with seed 0
 
 inputTree_ = inputTree->CloneTree(0);
 inputTree_->CopyEntries(inputTree); 
 
 numParameters_ = inputTree_->GetEntries();
 
 inputTree_->SetBranchAddress("xRECO_1",&xRECO_1_);
 inputTree_->SetBranchAddress("xRECO_2",&xRECO_2_);
 inputTree_->SetBranchAddress("xMassRECO",&xMassRECO_);
 
 outputTree_ = new TTree("outTree","outTree");
 outputTree_->Branch("xTRUE_1",&xTRUE_1_,"xTRUE_1/D");
 outputTree_->Branch("xRECO_1",&xRECO_1_,"xRECO_1/D");
 outputTree_->Branch("xTRUE_2",&xTRUE_2_,"xTRUE_2/D");
 outputTree_->Branch("xRECO_2",&xRECO_2_,"xRECO_2/D");
 outputTree_->Branch("xMassTRUE",&xMassTRUE_,"xMassTRUE/D");
 outputTree_->Branch("xMassRECO",&xMassRECO_,"xMassRECO/D");
 
 outputTree_temp_ = new TTree("outputTree_temp","outputTree_temp");
 outputTree_temp_->Branch("xTRUE_1",&xTRUE_1_,"xTRUE_1/D");
 outputTree_temp_->Branch("xRECO_1",&xRECO_1_,"xRECO_1/D");
 outputTree_temp_->Branch("xTRUE_2",&xTRUE_2_,"xTRUE_2/D");
 outputTree_temp_->Branch("xRECO_2",&xRECO_2_,"xRECO_2/D");
 outputTree_temp_->Branch("xMassTRUE",&xMassTRUE_,"xMassTRUE/D");
 outputTree_temp_->Branch("xMassRECO",&xMassRECO_,"xMassRECO/D");
 
//  for (int iEvt = 0; iEvt < numParameters_; iEvt++){ 
//   inputTree_->GetEntry(iEvt);
//   std::cerr << " Entries = " << xRECO_1_ << " " << xRECO_2_ << " " << xMassRECO_ << " => " << iEvt << " : " << numParameters_ << std::endl;
//   Mass_TRUE = Mass_RECO;
//   xTRUE_1_ = -1;
//   xTRUE_2_ = -1;
//   outputTree_->Fill();
//  }
 
 Mass_W_ = Mass_W;
 
 kFunctionGr_ = NULL;
 Resolution_  = NULL;
 grResol_     = NULL;
 
 //---- temporary definition of resolution for calculation speed up ----
 Resolution_ = new TF1("Resolution_","exp(-(x-1)*(x-1)/(2.*[0]*[0]))",0,10); 
 //  h1Resol_ = new TH1F("h1Resol","h1Resol",1000,0.0,2.0);
 
 h1TrueDistrib_ = NULL;
 h1RECODistrib_ = NULL;
 
}


///====================
///==== Destructor ====
CaVa::~CaVa(){
 //---- destroy everything ----
 delete myRand_;
 delete Resolution_;
 if (kFunctionGr_ != NULL) delete kFunctionGr_;
 if (grResol_ != NULL) delete grResol_;
 if (h1TrueDistrib_ != NULL) delete h1TrueDistrib_;
 if (h1RECODistrib_ != NULL) delete h1RECODistrib_; 
 delete outputTree_;
 delete outputTree_temp_;
 delete inputTree_;
}



///=================
///==== Methods ====

///==== Print ====
void CaVa::Print(){
 std::cerr << "Mass_W = " << Mass_W_ << std::endl;
 std::cerr << "numParameters = " << numParameters_ << std::endl;
}



void CaVa::SetParameters(int NBinX, int NBinY, double MinX, double MinY, double MaxX, double MaxY, double Delta){
 std::cerr << " SetParameters" << std::endl;
 std::cerr << " NBinX = " << NBinX << std::endl;
 std::cerr << " NBinY = " << NBinY << std::endl;
 std::cerr << " MinX  = " << MinX << std::endl;
 std::cerr << " MinY  = " << MinY << std::endl;
 std::cerr << " MaxX  = " << MaxX << std::endl;
 std::cerr << " MaxY  = " << MaxY << std::endl;
 std::cerr << " Delta = " << Delta << std::endl;
 Delta_Init_ = Delta;
 NBinX_ = NBinX;
 NBinY_ = NBinY;
 if (NBinX_ > 10000){
  std::cerr << " Error: too many bins ..." << std::endl;
  exit(0);
 }
 MaxX_ = MaxX;
 MaxY_ = MaxY;
 Delta_X_ = (MaxX-MinX) / NBinX;
 Delta_Y_ = (MaxY-MinY) / NBinY;
 
 NBinX_Init_ = ((MaxX_-MinX_) / Delta_Init_);
 h2InitCaVa_ = new TH2F("h2InitCaVa","h2InitCaVa",NBinX_Init_,MinX_,MaxX_,NBinY_,MinY_,MaxY_);
 for (int iBinX = 0; iBinX < NBinX_Init_; iBinX++){
  char name[100];
  sprintf (name,"tempHXFixed_Init_%d",iBinX);
  tempHXFixed_Init_[iBinX] = new TH1F(name,name,NBinY_,MinY_,MaxY_);
 } 
 
 h2ToyCaVa_ = new TH2F("h2ToyCaVa","h2ToyCaVa",NBinX_,MinX_,MaxX_,NBinY_,MinY_,MaxY_);
 h2RealCaVa_ = new TH2F("h2RealCaVa","h2RealCaVa",NBinX_,MinX_,MaxX_,NBinY_,MinY_,MaxY_);
 
 for (int iBinX = 0; iBinX < NBinX_; iBinX++){
  char name[100];
  sprintf (name,"tempHXFixed_%d",iBinX);
  tempHXFixed_[iBinX] = new TH1F(name,name,NBinY_,MinY_,MaxY_);
 }
 
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  char name[100];
  sprintf (name,"tempHYFixed_%d",iBinY);
  tempHYFixed_[iBinY] = new TH1F(name,name,NBinX_,MinX_,MaxX_);
 }
 
 h1TrueDistrib_ = new TH1F("h1TrueDistrib","h1TrueDistrib",NBinY_,MinY_,MaxY_);
 h1RECODistrib_ = new TH1F("h1RECODistrib","h1RECODistrib",NBinX_,MinX_,MaxX_);
}



///==== Initialization with Delta ====
///==== only data within "Delta" are considered ====
void CaVa::InitializeWithDelta(){
 std::cerr << ">>> InitializeWithDelta" << std::endl;
 std::cerr << " numParameters = " << numParameters_ << std::endl;
 outputTree_->Reset();
 outputTree_temp_->Reset();
 for (int iEvt = 0; iEvt < numParameters_; iEvt++){  
  inputTree_->GetEntry(iEvt);
//   std::cerr << " Entries = " << xRECO_1_ << " " << xRECO_2_ << " " << xMassRECO_ << " => " << iEvt << " : " << numParameters_ << std::endl;
  xTRUE_1_ = -1;
  xTRUE_2_ = -1;
  xMassTRUE_ = -1;
//   std::cerr << " iEvt = " << iEvt << " : " << numParameters_ << " : " << inputTree_->GetEntries() << std::endl;
  if (fabs(xRECO_1_ - xRECO_2_) < Delta_Init_){
   xTRUE_1_ = Mass_W_ / xMassRECO_ * xRECO_1_;
   xTRUE_2_ = Mass_W_ / xMassRECO_ * xRECO_2_;
   xMassTRUE_ = Mass_W_; ///==> obvious! I imposed it!
   int totBin = h2InitCaVa_->Fill(xRECO_1_,xTRUE_1_);
   int iBinX;
   int iBinY;
   int iBinZ;
   h2InitCaVa_->GetBinXYZ(totBin,iBinX,iBinY,iBinZ);  
//    std::cerr << " here ... 1 " << std::endl;
   if (iBinX != -1) tempHXFixed_Init_[iBinX-1]->Fill(xTRUE_1_); ///---- check "-1"
   if (iBinY != -1) tempHYFixed_[iBinY-1]->Fill(xRECO_1_); ///---- check "-1"
     
//    std::cerr << " here ... 2 " << std::endl;
   
   totBin = h2InitCaVa_->Fill(xRECO_2_,xTRUE_2_);
   h2InitCaVa_->GetBinXYZ(totBin,iBinX,iBinY,iBinZ);  
   if (iBinX != -1) tempHXFixed_Init_[iBinX-1]->Fill(xTRUE_2_); ///---- check "-1"
   if (iBinY != -1) tempHYFixed_[iBinY-1]->Fill(xRECO_2_); ///---- check "-1"
    
//    std::cerr << " here ... 3 " << std::endl;
  }
  else {
   xTRUE_1_ = -1;
   xTRUE_2_ = -1;
  }
  outputTree_->Fill();
  outputTree_temp_->Fill();
 }
 
 std::cerr << ">>>>>>> CalculateTrueDistibution Initialization" << std::endl;
 h1TrueDistrib_->Reset();
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  for (int iBinX = 0; iBinX < NBinX_Init_; iBinX++){  
   h1TrueDistrib_->Fill(MinY_ + (iBinY+0.5) * Delta_Y_,h2InitCaVa_->GetBinContent(iBinX+1,iBinY+1));
  }
 }
 
 h1TrueDistrib_->Smooth(3);
 
 //  CalculateK();
}





///=================================================

void CaVa::BuildToyCaVa(){
 std::cerr << ">>> BuildToyCaVa " << std::endl;
 h2ToyCaVa_->Reset();
 int numToy = 10 * 2 * numParameters_; 
//   int numToy = 2 * numParameters_; 
 
 for (int iBinX = 0; iBinX < NBinX_; iBinX++){  
  tempHXFixed_[iBinX]-> Reset();
 }
 
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  tempHYFixed_[iBinY]->Reset();
 }
 
 for (int iToy = 0; iToy < numToy; iToy++){
  if (!(iToy%5000)) std::cerr << " iToy = " << iToy << " : " << numToy << std::endl;
  
  double randomMC = h1TrueDistrib_->GetRandom();
  //   Resolution_->SetParameter(0,grResol_->Eval(randomMC));
  Resolution_->SetParameter(0,std::max(grResol_->Eval(randomMC),0.05));
  double randomRECO = -1;
  bool wrongRegion = true;
  if (randomMC > MinY_ && randomMC < MaxY_){
   while (wrongRegion){
    //    std::cerr << " randomMC = " << randomMC << std::endl;
    randomRECO = kFunctionGr_->Eval(randomMC) * Resolution_->GetRandom();
    if (randomRECO > MinX_ && randomRECO < MaxX_) wrongRegion = false;
   }
   int totBin = h2ToyCaVa_->Fill(randomRECO,randomMC);
   int iBinX;
   int iBinY;
   int iBinZ;
   h2ToyCaVa_->GetBinXYZ(totBin,iBinX,iBinY,iBinZ);  
   if (iBinY != -1) tempHYFixed_[iBinY-1]->Fill(randomRECO); ///---- check "-1"
    if (iBinX != -1) tempHXFixed_[iBinX-1]->Fill(randomMC); ///---- check "-1"
  }
  else {
   iToy--;
  }
 }
}

///=================================================


void CaVa::CalculateK(){
 std::cerr << ">>> CalculateK " << std::endl;
 double x[10000];
 double y[10000];
 double rmsy[10000];
 //  h1Resol_->Reset();
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  y[iBinY] = tempHYFixed_[iBinY]->GetMean();
  if (y[iBinY] == 0){
   if (iBinY != 0) y[iBinY] = y[iBinY-1];
  }
  if (y[iBinY] != 0) rmsy[iBinY] = tempHYFixed_[iBinY]->GetRMS() / y[iBinY]; ///// FIXME possible c / 0 !
   else rmsy[iBinY] = 1; 
   if (rmsy[iBinY] < 0.01){
    if (iBinY != 0) rmsy[iBinY] = rmsy[iBinY-1];
   }
   x[iBinY] = MinY_ + Delta_Y_ * (iBinY+0.5);
 }
 
 double ytemp[10000];
 double rmsytemp[10000];
 
 ///==== extended ====
 for (int iBinY = 0; iBinY < (NBinY_+2); iBinY++){
  if (iBinY != 0) {
   if (iBinY != (NBinY_+1)){
    ytemp[iBinY] = y[iBinY-1];
    rmsytemp[iBinY] = rmsy[iBinY-1];
   }
   else {
    ytemp[iBinY] = y[iBinY-2];
    rmsytemp[iBinY] = rmsy[iBinY-2];
   }
  }
  else {
   ytemp[iBinY] = y[0];
   rmsytemp[iBinY] = rmsy[0];
  }
 }
 
 for (int iBinY = 0; iBinY < (NBinY_+2); iBinY++){
  y[iBinY] = ytemp[iBinY];
  rmsy[iBinY] = rmsytemp[iBinY];
  x[iBinY] = MinY_ + Delta_Y_ * (iBinY-0.5);
 }
 
 ///==== smoothing ====
 
 SmoothVector(y,rmsy);
//  SmoothVector(y,rmsy);
//  SmoothVector(y,rmsy);
//  SmoothVector(y,rmsy);
 
 ///==== mean with previous values ====
 if (kFunctionGr_ != NULL){
  for (int iBinY = 0; iBinY < (NBinY_+2); iBinY++){
   y[iBinY] = (y[iBinY] + kFunctionGr_->Eval(MinY_ + Delta_Y_ * (iBinY-0.5))) / 2.;   
   rmsy[iBinY] = (rmsy[iBinY] + grResol_->Eval(MinY_ + Delta_Y_ * (iBinY-0.5))) / 2.;   
  }
 }
 
 if (grResol_ != NULL) delete grResol_;
 grResol_ = new TGraph(NBinY_+2,x,rmsy);
 
 if (kFunctionGr_ != NULL) delete kFunctionGr_;
 kFunctionGr_ = new TGraph(NBinY_+2,x,y);
 kFunctionGr_->Write();
 grResol_->Write();
 
}


///=================================================

void CaVa::SmoothVector(double *y, double* rmsy){
 std::cerr << " >>>>>>>> SmoothVector " << std::endl;
 double ySmooth[10000];
 double rmsySmooth[10000];
 for (int iBinY = 0; iBinY < (NBinY_+2); iBinY++){
  if (iBinY != 0 && iBinY != (NBinY_+1)) {
   if (y[iBinY] == 0){
    y[iBinY] = y[iBinY+1];
   }    
   ySmooth[iBinY] = (y[iBinY-1] + y[iBinY] + y[iBinY+1]) / 3.;
   rmsySmooth[iBinY] = (rmsy[iBinY-1] + rmsy[iBinY] + rmsy[iBinY+1]) / 3.;
  }
  else {
   ySmooth[iBinY] = y[iBinY];
   rmsySmooth[iBinY] = rmsy[iBinY];
  }
 }
 
 for (int iBinY = 0; iBinY < (NBinY_+2); iBinY++){
  y[iBinY] = ySmooth[iBinY];
  rmsy[iBinY] = rmsySmooth[iBinY];
 }
}

///=================================================

void CaVa::CalculateRecoDistroWithDelta(){
 std::cerr << ">>> CalculateRecoDistroWithDelta " << std::endl;
//  h1RECODistrib_->Reset();
//  outputTree_->Reset();
//  for (int iEvt = 0; iEvt < numParameters_; iEvt++){  
//   inputTree_->GetEntry(iEvt);
//   //   std::cerr << " iEvt = " << iEvt << " : " << numParameters_ << std::endl; 
//   int iBinX = h1RECODistrib_->Fill(xRECO_1_);
//   if (iBinX != -1){
//    double randomY = xTRUE_1_;
//    if (tempHXFixed_[iBinX-1]->GetEffectiveEntries() > 3) {
//     randomY = tempHXFixed_[iBinX-1]->GetRandom();
//     xTRUE_1_ = randomY;
//    }
//   }
//   iBinX = h1RECODistrib_->Fill(xRECO_2_);
//   if (iBinX != -1){
//    double randomY = xTRUE_2_;
//    if (tempHXFixed_[iBinX-1]->GetEffectiveEntries() > 3) {
//     randomY = tempHXFixed_[iBinX-1]->GetRandom();
//     xTRUE_2_ = randomY;
//    }
//   }
//   outputTree_->Fill();
//  }
}


///=================================================

void CaVa::CalculateTrueDistibution(){
 std::cerr << ">>> CalculateTrueDistibution " << std::endl;
 h1TrueDistrib_->Reset();
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  for (int iBinX = 0; iBinX < NBinX_; iBinX++){  
   //    std::cerr << " Fill = " << MinY_ + (iBinY+0.5) * Delta_Y_ << " : " << h2RealCaVa_->GetBinContent(iBinX+1,iBinY+1);
   h1TrueDistrib_->Fill(MinY_ + (iBinY+0.5) * Delta_Y_,h2RealCaVa_->GetBinContent(iBinX+1,iBinY+1));
  }
 }
 h1TrueDistrib_->Smooth(3);
 h1TrueDistrib_->Write();
}


///=================================================

void CaVa::BuildRealCaVaWithMass(){
 std::cerr << ">>> BuildRealCaVaWithMass " << std::endl;
 int numToy = 10000; 
 outputTree_->Reset();
 for (int iEvt = 0; iEvt < numParameters_; iEvt++){  
  outputTree_temp_->GetEntry(iEvt);
  int iBinX_1 = h1RECODistrib_->Fill(xRECO_1_);
  int iBinX_2 = h1RECODistrib_->Fill(xRECO_2_);
  if (iBinX_1 != -1 && iBinX_2 != -1){
   double tempDMassResonance = 999999.;
   for (int iToy=0; iToy<numToy; iToy++){
    if (tempHXFixed_[iBinX_1-1]->GetEffectiveEntries() > 3 && tempHXFixed_[iBinX_2-1]->GetEffectiveEntries() > 3){
     double randomY_1 = tempHXFixed_[iBinX_1-1]->GetRandom();
     double randomY_2 = tempHXFixed_[iBinX_2-1]->GetRandom();
     double tempMassResonance = xMassRECO_ * sqrt (1. / xRECO_1_ * randomY_1 / xRECO_2_ * randomY_2);
     if (fabs(tempMassResonance - Mass_W_) < tempDMassResonance){
      xTRUE_1_ = randomY_1;
      xTRUE_2_ = randomY_2;
      tempDMassResonance = fabs(tempMassResonance - Mass_W_);
      xMassTRUE_ = tempMassResonance;
     }
    }
   }
   h2RealCaVa_->Fill(xRECO_1_,xTRUE_1_);
   h2RealCaVa_->Fill(xRECO_2_,xTRUE_2_);
  }
  outputTree_->Fill();
 }
 outputTree_temp_->Reset();
 for (int iEvt = 0; iEvt < numParameters_; iEvt++){  
  outputTree_->GetEntry(iEvt);
  outputTree_temp_->Fill();
 }
}

///=================================================

void CaVa::FillCaVa(){
 std::cerr << ">>> FillCaVa " << std::endl;
 h2RealCaVa_->Reset();
 for (int iEvt = 0; iEvt < numParameters_; iEvt++){ 
  outputTree_->GetEntry(iEvt);
  h2RealCaVa_->Fill(xRECO_1_,xTRUE_1_);
  h2RealCaVa_->Fill(xRECO_2_,xTRUE_2_);
 }
}


///=================================================

///==== getResults ====
TTree* CaVa::getResult(){
//  std::cerr << ">>> GetResult <<<" << std::endl;
 TTree* newTree = outputTree_->CloneTree(0);
 newTree->CopyEntries(outputTree_); 
//  for (int iEvt = 0; iEvt < newTree->GetEntries(); iEvt++){  
//   newTree->GetEntry(iEvt);
//   std::cerr << " Entries = " << xRECO_1_ << " " << xRECO_2_ << " " << xMassRECO_ << " => " << iEvt << " : " <<  newTree->GetEntries() << std::endl;
//  }
 return (newTree);
}





