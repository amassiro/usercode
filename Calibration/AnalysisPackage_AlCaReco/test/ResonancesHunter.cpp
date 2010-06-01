#include "treeReader.h"
#include "hFactory.h"
#include "hFunctions.h"
#include "stdHisto.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"
#include "Math/GenVector/VectorUtil.h"
#include "TRandom3.h"
#include <time.h>
#include <sstream>
#include "ntpleUtils.h"
#include "stdHisto.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif

int main(int argc, char** argv)
{ 
 //Check if all nedeed arguments to parse are there                                                                                                                               
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }
 
 // Parse the config file                                                                                                                                                          
 parseConfigFile (argv[1]) ;
 
 std::string treeName  = gConfigParser -> readStringOption("Input::treeName");
 std::string inputFile = gConfigParser -> readStringOption("Input::inputFile");
 
 int entryMAX = gConfigParser -> readIntOption("Input::entryMAX");
 int entryMIN = gConfigParser -> readIntOption("Input::entryMIN");
 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 
 std::cout << ">>>>> input::entryMIN  " << entryMIN  << std::endl;  
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 // Open ntple
 TChain* chain = new TChain(treeName.c_str());
 chain->Add(inputFile.c_str());
 treeReader reader((TTree*)(chain));
 
 
 
 
 ///----------------
 ///---- output ----
 std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << OutFileName  << std::endl;  

 TFile outFile(OutFileName.c_str(),"RECREATE");
 outFile.cd();
 
 TH1F hInvMass("hInvMass","hInvMass",2000,0,200);
 
 
 double start, end;
 
 if (entryMAX == -1) entryMAX = reader.GetEntries();
 else if (reader.GetEntries() < entryMAX) entryMAX = reader.GetEntries();
 
 int step = 0;
 start = clock();
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent) {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
  
  int nEles = reader.Get4V("electrons")->size();
  int nEleSel = 0;
  ROOT::Math::XYZTVector Resonance(0,0,0,0);
  std::cerr << " nEles = " << nEles << std::endl;
  if (reader.GetFloat("Calo_Energy")->size() == nEles){
   for (int iEle = 0; iEle < nEles; iEle++){    
    bool skipEle = false;
    if (reader.GetFloat("Calo_Energy")->at(iEle) < 40.0) skipEle = true;
    //    if (reader.Get4V("electrons")->at(iEle).pt() < 40.0) skipEle = true;
    
    if (!skipEle) {
     nEleSel++;
     Resonance += reader.Get4V("electrons")->at(iEle);
    }
   }
  }
  if (nEleSel==2) hInvMass.Fill(Resonance.mass());
 } //loop over the events 
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
  
 hInvMass.Write();
 outFile.Write();
  
 return 0;
}



