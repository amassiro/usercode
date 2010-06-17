///==== like this:
///==== c++ -o BuildCaVa_fromData_Iterative_testConvergence_ZJets.exe `root-config --cflags --glibs` BuildCaVa_fromData_Iterative_testConvergence_ZJets.cpp CaVa.cc

#include "ConfigParser.h"
#include "ntpleUtils.h"

#include <iostream>
#include "TF1.h"
#include "TH2.h"
#include "TH1.h"
#include "TTree.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TROOT.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TText.h"
#include <math.h>
#include "TGraph.h"

#include "TRandom.h"


#include <sstream>


int main(int argc, char** argv){

 
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }
 
 // Parse the config file 
 parseConfigFile (argv[1]) ;
  
 int numEvents = gConfigParser -> readIntOption("Input::numEvents");
 std::cout << ">>>>> Input::numEvents  " << numEvents  << std::endl;  
 
 double MinY = gConfigParser -> readDoubleOption("Input::minTrue");
 std::cout << ">>>>> Input::minTrue  " << MinY  << std::endl;  

 double MaxY = gConfigParser -> readDoubleOption("Input::maxTrue");
 std::cout << ">>>>> Input::maxTrue  " << MaxY  << std::endl;  

 double xResolution = gConfigParser -> readDoubleOption("Input::resolution");
 std::cout << ">>>>> Input::resolution  " << xResolution  << std::endl;  
 
 std::string TrueDistribution    = gConfigParser -> readStringOption("Input::TrueDistribution");
 std::cout << ">>>>> Output::TrueDistribution  " << TrueDistribution  << std::endl;  
 
 std::string TrueDistributionExpression; 
 std::ifstream inFileTrueDistribution(TrueDistribution.c_str());
 std::string buffer;
 
 while(!inFileTrueDistribution.eof()){
  getline(inFileTrueDistribution,buffer);
  std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){
    TrueDistributionExpression  = buffer;
   } 
  }
 }
 
 
 std::string kPT = gConfigParser -> readStringOption("Input::kPT");
 std::cout << ">>>>> Output::kPT  " << kPT  << std::endl;  
 
 std::string kPTExpression; 
 std::ifstream inFilekPT(kPT.c_str());
 
 while(!inFilekPT.eof()){
  getline(inFilekPT,buffer);
  std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){
    kPTExpression  = buffer;
   } 
  }
 }
 
 
 ///----------------
 ///---- output ----
 std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << OutFileName  << std::endl;  
 
 TFile fileOut(OutFileName.c_str(),"RECREATE");
 fileOut.cd();
  
 
 TTree tree("InputTree","InputTree");
 double xMC;
 double xRECO;
 
 tree.Branch("xMC",&xMC,"xMC/D");
 tree.Branch("xRECO",&xRECO,"xRECO/D");
 
 TF1 *MCDistrbution = new TF1("MCDistrbution",TrueDistributionExpression.c_str(),MinY,MaxY);
 MCDistrbution->Write();
 
 TF1 *Resolution = new TF1("Resolution","exp(-(x-1)*(x-1)/(2.*[0]*[0]))",0,10);
 Resolution->SetParameter(0,xResolution);
 Resolution->Write();
 
 TF1 *kFunction = new TF1("kFunction",kPTExpression.c_str(),MinY,MaxY);
 kFunction->Write();
 
 for (int ievt = 0; ievt<numEvents; ievt++){
  xMC = MCDistrbution->GetRandom();
  xRECO = kFunction->Eval(xMC) * Resolution->GetRandom();
  tree.Fill();
 }
 tree.Write();
 

}




