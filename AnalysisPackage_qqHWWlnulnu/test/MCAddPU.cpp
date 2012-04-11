#include "ConfigParser.h"
#include "ntpleUtils.h"

#include "../test/Read.cc"

#include <cstdlib>
#include <iostream> 
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"




///     
///        \  |   ___|         \         |      |       _ \   |   | 
///       |\/ |  |            _ \     _` |   _` |      |   |  |   | 
///       |   |  |           ___ \   (   |  (   |      ___/   |   | 
///      _|  _| \____|     _/    _\ \__,_| \__,_|     _|     \___/  
///                                                                 



int main(int argc, char** argv) {
 
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }


std::cout << "          " << std::endl;  
std::cout << "          " << std::endl;       
std::cout << "              \\  |   ___|         \\         |      |       _ \\   |   |       " << std::endl;
std::cout << "             |\\/ |  |            _ \\     _` |   _` |      |   |  |   |       " << std::endl;
std::cout << "             |   |  |           ___ \\   (   |  (   |      ___/   |   |       " << std::endl;
std::cout << "            _|  _| \\____|     _/    _\\ \\__,_| \\__,_|     _|     \\___/        " << std::endl;
std::cout << "                                                                             " << std::endl;
std::cout << "          " << std::endl;
std::cout << "          " << std::endl;

 // Parse the config file                                                                                                                                                          
 parseConfigFile (argv[1]) ;
 
 std::string treeName  = gConfigParser -> readStringOption("Input::treeName");
 std::string fileSamples = gConfigParser -> readStringOption("Input::fileSamples");
 std::string inputDirectory = gConfigParser -> readStringOption("Input::inputDirectory");
 
 std::string inputBeginningFile = "out_NtupleProducer_"; 
 try {
  inputBeginningFile = gConfigParser -> readStringOption("Input::inputBeginningFile");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }
 std::cout << ">>>>> Input::inputBeginningFile  " << inputBeginningFile  << std::endl;  
 

 std::string outputDirectory = gConfigParser -> readStringOption("Output::outputDirectory");
 
 
 
 
 
 ///==== debug flag (begin) ==== 
 bool  debug = false; 
 try {
  debug = gConfigParser -> readBoolOption("Input::debug");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }
 std::cout << ">>>>> input::debug  " << debug  << std::endl;  
 ///==== debug flag (end) ==== 
 
 
 ///==== weight file ==== 
 ///  A
 ///  B
 ///  AB
 ///
 
 std::string WeightFile              = gConfigParser -> readStringOption    ("Options::WeightFile");
 std::vector<std::string> WeightName = gConfigParser -> readStringListOption("Options::WeightName");
 
 float nvtx;
 
 
 ///---- trees ----
 TFile* outputRootFile[500];
 TTree* cloneTreeJetLepVect[500];
 
 
 TTree *treeJetLepVect[500];
 TFile* file[500];
 
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsectionName[1000];
 
 char nameFileIn[1000];
 sprintf(nameFileIn,"%s",fileSamples.c_str());
 
 int numberOfSamples = ReadFile(nameFileIn, nameSample, nameHumanReadable, xsectionName);
 
 for (int iSample=0; iSample<numberOfSamples; iSample++){ 
  char nameFile[20000];
  sprintf(nameFile,"%s/%s%s.root",inputDirectory.c_str(),inputBeginningFile.c_str(),nameSample[iSample]);  
  
  file[iSample] = new TFile(nameFile, "READ");
  
  treeJetLepVect[iSample] = (TTree*) file[iSample]->Get(treeName.c_str());
  char nameTreeJetLep[100];
  sprintf(nameTreeJetLep,"treeJetLep_%d",iSample); 
  treeJetLepVect[iSample]->SetName(nameTreeJetLep);  
  treeJetLepVect[iSample] -> SetBranchAddress ("nxtv",&nvtx);
  
  sprintf(nameFile,"%s/%s%s.root",outputDirectory.c_str(),inputBeginningFile.c_str(),nameSample[iSample]);    
  outputRootFile[iSample] = new TFile ( nameFile, "RECREATE") ;
  outputRootFile[iSample] -> cd () ;
  cloneTreeJetLepVect[iSample] = treeJetLepVect[iSample] -> CloneTree (0) ;
 }
 
 
 ///---- dump in new trees in new root file ----
 for (int iSample=0; iSample<numberOfSamples; iSample++){ 
  file[iSample] -> cd();
  ///==== loop ====
  Long64_t nentries = treeJetLepVect[iSample]->GetEntries();
  for (Long64_t iEntry = 0; iEntry < nentries; iEntry++){
   treeJetLepVect[iSample]->GetEntry(iEntry);
   cloneTreeJetLepVect[iSample] -> Fill () ; 
  }
 }
 
 ///---- add new weights ----
 for (int iSample=0; iSample<numberOfSamples; iSample++){ 
  std::cout << " iSample = " << iSample << " :: " << numberOfSamples << std::endl;
  file[iSample] -> cd();
  
  std::cout << " >>>>> GetEntries " << treeJetLepVect[iSample]->GetEntries() << std::endl;     
  double weight[100];
  TBranch* newBranch[100];
  
  int nWeightName = WeightName.size();
  for (int iWeightName = 0; iWeightName<nWeightName; iWeightName++) {
   TString namePU        = Form ("%s",WeightName.at(iWeightName).c_str());
   TString namePUforRoot = Form ("%s/F",WeightName.at(iWeightName).c_str());
   newBranch[iWeightName] = cloneTreeJetLepVect[iSample]->Branch(namePU,&(weight[iWeightName]),namePUforRoot);
  }
  
  ///==== loop ====
  Long64_t nentries = treeJetLepVect[iSample]->GetEntries();
  
  for (Long64_t iEntry = 0; iEntry < nentries; iEntry++){
   if((iEntry%1000) == 0) std::cout << ">>>>> analysis::GetEntry " << iEntry << " : " << nentries << std::endl;      
   treeJetLepVect[iSample]->GetEntry(iEntry);  
   for (int iWeightName = 0; iWeightName<nWeightName; iWeightName++) {
    weight[iWeightName] = 10;
    newBranch[iWeightName] -> Fill();
   }
  }
 }
 
 
 ///---- save in output files ---- 
 for (int iSample=0; iSample<numberOfSamples; iSample++){ 
  outputRootFile[iSample]->cd();
  cloneTreeJetLepVect[iSample] -> SetName (treeName.c_str());
  cloneTreeJetLepVect[iSample]->Write(treeName.c_str(),TObject::kOverwrite);
  outputRootFile[iSample] -> Close () ;
 }
 
 
}



