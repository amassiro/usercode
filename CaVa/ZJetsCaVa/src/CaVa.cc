/*
Class CaVa
*/

#include "CaVa.h"

///=====================
///==== Constructor ====

CaVa::CaVa(std::vector<double>& xRECO2IN, std::vector<double>& xRECO2MC,TF1& kFunction, TF1& Resolution){
 myRand_ = new TRandom(0); // Creates a random number generator object with seed 0
 h1RECO_DATA_ =  new TH1F("h1RECO_DATA","h1RECO_DATA",200,0,2000);
 numParameters_ = xRECO2MC.size();
 xRECO2MC_ = xRECO2MC;
 xRECO2IN_ = xRECO2IN;
 
 Resolution_ = new TF1;
 kFunction_ = new TF1;
 
 kFunction_ = &kFunction;
 Resolution_ = &Resolution;
 resolution_ = Resolution_->GetParameter(0);
 Step_ = 1;
 Delta_ = 10;
 //---- Fill trees ----
 
 for (int iBin = 0; iBin < 10000; iBin++){
  tempHgrK_[iBin] = NULL;
  tempHgrKExpected_[iBin] = NULL;
 }
 
 h2ToyCaVa_         = NULL;
 h2ToyCaVaFromReco_ = NULL;
 h2RealCaVa_        = NULL;
 
 h1MCDistrib_ = NULL; 
 
 tempMaxGrK_ = NULL;
 tempMinGrK_ = NULL;
 
 grResol_     = NULL;
 kFunctionGr_ = NULL;
 
 do_Resol_ = 0;
}


CaVa::CaVa(std::vector<double>& xRECO2IN, std::vector<double>& xRECO2MC,TGraph& kFunction, TF1& Resolution){
 myRand_ = new TRandom(0); // Creates a random number generator object with seed 0
 h1RECO_DATA_ =  new TH1F("h1RECO_DATA","h1RECO_DATA",200,0,2000);
 numParameters_ = xRECO2MC.size();
 xRECO2MC_ = xRECO2MC;
 xRECO2IN_ = xRECO2IN;
 
 Resolution_ = new TF1;
 kFunctionGr_ = new TGraph;
 
 kFunctionGr_ = &kFunction;
 Resolution_ = &Resolution;
 resolution_ = Resolution_->GetParameter(0);
 
 Step_ = 1;
 Delta_ = 10;
 //---- Fill trees ----
 
 for (int iBin = 0; iBin < 10000; iBin++){
  tempHgrK_[iBin] = NULL;
  tempHgrKExpected_[iBin] = NULL;
 }
 
 h2ToyCaVa_         = NULL;
 h2ToyCaVaFromReco_ = NULL;
 h2RealCaVa_        = NULL;
 
 h1MCDistrib_ = NULL; 
 
 tempMaxGrK_ = NULL;
 tempMinGrK_ = NULL;
 
 grResol_     = NULL;
 kFunction_ = NULL;
 
 do_Resol_ = 0;
}


///====================
///==== Destructor ====
CaVa::~CaVa(){
 //---- destroy everything ----
 delete myRand_;
 delete h1RECO_DATA_;
 delete h1RECO_IN_;
 if (tempHgrK_ != NULL) {
  int nBins = 2000. / Delta_;
  for (int iBin = 0; iBin < nBins; iBin++){
   if (tempHgrK_[iBin] != NULL)         delete tempHgrK_[iBin];
   if (tempHgrKExpected_[iBin] != NULL) delete tempHgrKExpected_[iBin];
  }
  if (tempMaxGrK_ != NULL) delete tempMaxGrK_;
  if (tempMinGrK_ != NULL) delete tempMinGrK_;
 }
 if (h2ToyCaVa_ != NULL)   delete h2ToyCaVa_;
 if (h2ToyCaVaFromReco_ != NULL)   delete h2ToyCaVaFromReco_;
 if (h2RealCaVa_ != NULL)  {
  delete h2RealCaVa_;
  for (int iBinX = 0; iBinX < NBinX_; iBinX++){
   if (h1RecoMCDistrib_[iBinX] != NULL) delete h1RecoMCDistrib_[iBinX];
  }
 }
 if (h1MCDistrib_ != NULL)   delete h1MCDistrib_;
 if (h1RECODistrib_ != NULL) delete h1RECODistrib_;
 if (grResol_ != NULL) delete grResol_;
}



///=================
///==== Methods ====


void CaVa::DoResolFree(int what){
 do_Resol_ = what; ///== 0 = no, 1 = yes
}

void CaVa::SetParameters(int NBinX, int NBinY, double MinX, double MinY, double MaxX, double MaxY){
 std::cerr << " SetParameters" << std::endl;
 std::cerr << " NBinX = " << NBinX << std::endl;
 std::cerr << " NBinY = " << NBinY << std::endl;
 std::cerr << " MinX = " << MinX << std::endl;
 std::cerr << " MinY = " << MinY << std::endl;
 std::cerr << " MaxX = " << MaxX << std::endl;
 std::cerr << " MaxY = " << MaxY << std::endl;
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
 h2ToyCaVa_ = new TH2F("h2ToyCaVa","h2ToyCaVa",NBinX_,MinX_,MaxX_,NBinY_,MinY_,MaxY_);
 h2ToyCaVaFromReco_ = new TH2F("h2ToyCaVaFromReco","h2ToyCaVaFromReco",NBinX_,MinX_,MaxX_,NBinY_,MinY_,MaxY_);
 h2RealCaVa_ = new TH2F("h2RealCaVa","h2RealCaVa",NBinX_,MinX_,MaxX_,NBinY_,MinY_,MaxY_);
 h1RECO_IN_ =  new TH1F("h1RECO_IN","h1RECO_IN",NBinX_,MinX_,MaxX_);
 h1MCDistrib_ = new TH1F("h1MCDistrib","h1MCDistrib",NBinY_,MinY_,MaxY_);
 h1RECODistrib_ = new TH1F("h1RECODistrib","h1RECODistrib",NBinX_,MinX_,MaxX_);
 for (int iEvt = 0; iEvt < numParameters_; iEvt++){
  h1RECO_IN_->Fill(xRECO2IN_.at(iEvt));
 }
 for (int iBinX = 0; iBinX < NBinX_; iBinX++){
  char name[100];
  sprintf (name,"h1RecoMCDistrib_%d",iBinX);
  h1RecoMCDistrib_[iBinX] = new TH1F(name,name,NBinY_,MinY_,MaxY_);
 }
 
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  char name[100];
  sprintf (name,"tempHYFixed_%d",iBinY);
  tempHYFixed_[iBinY] = new TH1F(name,name,NBinX_,MinX_,MaxX_);
 }
 
 double* True = new double [NBinY_];
 double* Ris = new double [NBinY_];
 std::cerr << " resolution_ = " << resolution_ << std::endl;
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  True[iBinY] = MinY_ + Delta_Y_ * (iBinY+0.5);
  Ris[iBinY] = resolution_;
 }
 grResol_ = new TGraph(NBinY_,True,Ris);
 
}

///=================================================

void CaVa::FillCaVa(){
 std::cerr << ">>> FillCaVa " << std::endl;
 h2RealCaVa_->Reset();
 for (int iEvt = 0; iEvt < numParameters_; iEvt++){  
  h2RealCaVa_->Fill(xRECO2IN_.at(iEvt),xRECO2MC_.at(iEvt));
 }
}

///=================================================

void CaVa::CalculateTrueDistibution(){
 std::cerr << ">>> CalculateTrueDistibution " << std::endl;
 h1MCDistrib_->Reset();
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  for (int iBinX = 0; iBinX < NBinX_; iBinX++){  
   h1MCDistrib_->Fill(MinY_ + (iBinY+0.5) * Delta_Y_,h2RealCaVa_->GetBinContent(iBinX+1,iBinY+1));
  }
 }
 h1MCDistrib_->Smooth(3);
}

///=================================================

void CaVa::CalculateTrueDistibutionWithToyCava(){
 std::cerr << ">>> CalculateTrueDistibutionWithToyCava " << std::endl;
 h1MCDistrib_->Reset();
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  for (int iBinX = 0; iBinX < NBinX_; iBinX++){  
   h1MCDistrib_->Fill(MinY_ + (iBinY+0.5) * Delta_Y_,h2ToyCaVaFromReco_->GetBinContent(iBinX+1,iBinY+1));
  }
 }
 h1MCDistrib_->Smooth(3);
}

///=================================================

void CaVa::BuildToyCaVaFromReco(){
 std::cerr << ">>> BuildToyCaVaFromReco " << std::endl;
 h2ToyCaVaFromReco_->Reset();
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  tempHYFixed_[iBinY]->Reset();
 }
 int numToy = 10 * numParameters_; 
 h1RECODistrib_->Reset();
 for (int iToy = 0; iToy < numToy; iToy++){
  double randomRECO = h1RECO_IN_->GetRandom();
  double randomTRUE = -1;
  int iBinX = h1RECODistrib_->Fill(randomRECO);
  if (iBinX != -1){   
   if (h1RecoMCDistrib_[iBinX-1]->GetEffectiveEntries() > 3) {
    randomTRUE = h1RecoMCDistrib_[iBinX-1]->GetRandom();
   }
  }
  int totBin = h2ToyCaVaFromReco_->Fill(randomRECO,randomTRUE);
  int iBinY;
  int iBinZ;
  h2ToyCaVaFromReco_->GetBinXYZ(totBin,iBinX,iBinY,iBinZ);  
  if (iBinY == 0) std::cerr << " iBinY == " << iBinY << " iBinX  = " << iBinX << " =>> " << h1RecoMCDistrib_[iBinX-1]->GetEffectiveEntries()<< " => " << NBinX_ << ":" << MinX_ << " - " << MaxX_<< "... randomRECO = " << randomRECO << " and randomTRUE = " << randomTRUE << " h1RECODistrib_ Range = " << h1RECODistrib_->GetXaxis()->GetXmin() << " <=< " << h1RECODistrib_->GetXaxis()->GetXmax() << " : " << h1RECODistrib_->GetXaxis()->GetNbins() << std::endl;
  if (iBinY != -1 && iBinY != 0) tempHYFixed_[iBinY-1]->Fill(randomRECO); ///---- check "-1" => it should be always true
 }
}

///=================================================

void CaVa::BuildToyCaVa(){
 std::cerr << ">>> BuildToyCaVa " << std::endl;
 h2ToyCaVa_->Reset();
 int numToy = 10 * numParameters_; 
 int maxIterations = numToy;
 for (int iBinX = 0; iBinX < NBinX_; iBinX++){  
  h1RecoMCDistrib_[iBinX]-> Reset();
 }
 for (int iToy = 0; iToy < numToy; iToy++){
  if (!(iToy%1000)) std::cerr << " iToy = " << iToy << " : " << numToy << std::endl;
  double randomMC = h1MCDistrib_->GetRandom();
  double randomRECO = -1;
  bool wrongRegion = true;
  int nIterations = 0;
//   std::cerr << " grResol_ = " << grResol_ << std::endl;
  while (wrongRegion){
   nIterations ++;
   if (nIterations > maxIterations) {
    randomMC = h1MCDistrib_->GetRandom(); ///==> reset True value ... ==> FIXME Bias?
//     std::cerr << " randomMC = " << randomMC << std::endl;
    nIterations = 0;
   }
//    std::cerr << " grResol_->Eval(" << randomMC << ") = " << grResol_->Eval(randomMC) << std::endl;
// std::cerr << "  iToy  = " << iToy << " Resolution_->GetRandom() = " << Resolution_->GetRandom() << " randomMC = " << randomMC << std::endl;

   if (do_Resol_) Resolution_->SetParameter(0,std::min(grResol_->Eval(randomMC),0.1));   
   if (kFunctionGr_ != NULL) randomRECO = kFunctionGr_->Eval(randomMC) * Resolution_->GetRandom();
   if (kFunction_ != NULL) randomRECO = kFunction_->Eval(randomMC) * Resolution_->GetRandom();
   if (randomRECO > MinX_ && randomRECO < MaxX_) wrongRegion = false;
  }
  int totBin = h2ToyCaVa_->Fill(randomRECO,randomMC);
  int iBinX;
  int iBinY;
  int iBinZ;
  h2ToyCaVa_->GetBinXYZ(totBin,iBinX,iBinY,iBinZ);  
  if (iBinX != -1) h1RecoMCDistrib_[iBinX-1]->Fill(randomMC); ///---- check "-1"
 }
//  h2ToyCaVa_->Write();
//  if (kFunction_ != NULL) kFunction_->Write();
//  if (kFunctionGr_ != NULL) kFunctionGr_->Write();
}

///=================================================

void CaVa::CalculateRecoDistroWithDelta(){
 std::cerr << ">>> CalculateRecoDistroWithDelta " << std::endl;
 h1RECODistrib_->Reset();
 for (int iEvt = 0; iEvt < numParameters_; iEvt++){  
  int iBinX = h1RECODistrib_->Fill(xRECO2IN_.at(iEvt));
  if (iBinX != -1){
   double randomY = xRECO2MC_.at(iEvt);
   if (h1RecoMCDistrib_[iBinX-1]->GetEffectiveEntries() > 3) {
    randomY = h1RecoMCDistrib_[iBinX-1]->GetRandom();
    xRECO2MC_.at(iEvt) = randomY;
   }
  }
 }
}

///=================================================

void CaVa::BuildRealCaVa(){
 std::cerr << ">>> BuildRealCaVa " << std::endl;
 FillCaVa();
}



///=================================================

void CaVa::CalculateResolution(){
 std::cerr << ">>> CalculateResolution " << std::endl;
 double x[10000];
 double y[10000];
 double rmsy[10000];
 for (int iBinY = 0; iBinY < NBinY_; iBinY++){
  y[iBinY] = tempHYFixed_[iBinY]->GetMean();
  if (y[iBinY] == 0){
   if (iBinY != 0) y[iBinY] = y[iBinY-1];
  }
  if (y[iBinY] != 0) rmsy[iBinY] = tempHYFixed_[iBinY]->GetRMS() / y[iBinY];
  else rmsy[iBinY] = grResol_->Eval(MinY_ + Delta_Y_ * (iBinY+0.5)); 
  x[iBinY] = MinY_ + Delta_Y_ * (iBinY+0.5);
 }
 
 if (grResol_ != NULL) delete grResol_;
 grResol_ = new TGraph(NBinY_,x,rmsy); 
}



///=================================================
///=================================================
///=================================================
///=================================================



///==== Print ====
void CaVa::Print(){
 std::cerr << "Step = " << Step_ << std::endl;
 std::cerr << "NBinX = " << NBinX_ << std::endl;
 std::cerr << "NBinY = " << NBinY_ << std::endl;
 std::cerr << "MinX = " << MinX_ << std::endl;
 std::cerr << "MinY = " << MinY_ << std::endl;
 std::cerr << "MaxX = " << MaxX_ << std::endl;
 std::cerr << "MaxY = " << MaxY_ << std::endl;
}

///==== getResults ====
std::vector<double> CaVa::getResults(){
 return xRECO2MC_;
}

