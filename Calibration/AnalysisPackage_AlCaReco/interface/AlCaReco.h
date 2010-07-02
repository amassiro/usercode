#include <string>
#include <map>
#include "TObject.h"
#include "TF1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TFile.h"


/** to integrate a function in a user defined range*/
double integrate (TH1F & h1, double min, double max) ;

/** get the sigmas around the centre, same area in the periphals*/
std::vector<double> getSigmaBands (TH1 & histo) ;

/** find the x coordinate that divides into two the area*/
double findMedian (TH1 & h1) ;
