#include <string>
#include <map>
#include "TObject.h"
#include "TF1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TFile.h"


/// --===-- --===-- --===-- --===-- --===-- --===-- --===-- --===-- --===--


double integrate (TH1F & h1, double min, double max)
{
 double step = (h1.GetXaxis ()->GetXmax () - h1.GetXaxis ()->GetXmin ()) /
 static_cast<double> (h1.GetXaxis ()->GetNbins ()) ;
 
 int b_min = static_cast<int> (
 (min - h1.GetXaxis ()->GetXmin ()) / step 
 ) + 1 ;
 if (b_min < 1) b_min = 1 ;
 int b_max = static_cast<int> (
 (max - h1.GetXaxis ()->GetXmin ()) / step 
 ) ;
 if (b_max > h1.GetXaxis ()->GetNbins ()) b_min = h1.GetXaxis ()->GetNbins () ;
 return h1.Integral (b_min, b_max) / h1.Integral () ;
}


/// --===-- --===-- --===-- --===-- --===-- --===-- --===-- --===-- --===--


std::vector<double>
getSigmaBands (TH1 & histo)
{
 ///==== AM Get quantiles, median, +/- 1 sigma ====
 
 std::vector<double> result (3, 0.) ;
 
 Double_t xq[5];  // position where to compute the quantiles in [0,1]
 Double_t yq[5];  // array to contain the quantiles
 
 xq[0] = 0.159; // -1 sigma
 xq[1] = 0.500; // median
 xq[2] = 0.841; // +1 sigma
 
 histo.GetQuantiles(5,yq,xq);
 
 //  int nbinsX = histo->GetNbinsX();
 //  Double_t minX = histo->GetXaxis()->GetXmin();
 //  Double_t maxX = histo->GetXaxis()->GetXmax();
 //  int bin = 0;
 //  for (int i=0; i<3; i++){
  //   bin = (yq[i]-minX) / (maxX - minX) * nbinsX + 1;
  //   intSX[i] = HSX->Integral(bin,nbinsSX)/HSX->Integral(1,nbinsSX);
  //  }
  
  for (int i=0; i<3; i++){
   result.at(i) = xq[i];
  }  
  return result ;
}

/// --===-- --===-- --===-- --===-- --===-- --===-- --===-- --===-- --===--

double
findMedian (TH1 & h1)
{
 int integral = 0 ;
 double threshold = h1.Integral () / 2. ;
 for (int i = 1 ; i < h1.GetXaxis ()->GetNbins () ; ++i)
 {
  integral += h1.GetBinContent (i) ;
  if (integral > threshold) return h1.GetBinCenter (i) ;
 }
 return h1.GetBinCenter (1) ;
}