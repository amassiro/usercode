#include "treeReader.h"
#include "hFactory.h"
#include "hFunctions.h"
#include "stdHisto.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"

#include "TPie.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TMinuit.h"
#include "THStack.h"

#include "qqHWWlnulnuUtils.h"
#include "TEntryList.h"




#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif


/// 
/// 
///    ___|          | _)  |         ___|                            |       
///  \___ \   __ \   |  |  __|     \___ \    _` |  __ `__ \   __ \   |   _ \ 
///        |  |   |  |  |  |             |  (   |  |   |   |  |   |  |   __/ 
///  _____/   .__/  _| _| \__|     _____/  \__,_| _|  _|  _|  .__/  _| \___| 
///          _|                                              _|              
/// 
///    _ \                      _ \                             
///   |   |  |   |  __ \       |   |   _` |  __ \    _` |   _ \ 
///   __ <   |   |  |   |      __ <   (   |  |   |  (   |   __/ 
///  _| \_\ \__,_| _|  _|     _| \_\ \__,_| _|  _| \__, | \___| 
///                                                |___/        
/// 


// std::vector<double> PUWeight;

int GetNumList(std::vector<int> &list){
 int result = 0;
 for (int it = 0; it<list.size(); it++) result += list.at(it);
 return result;
}


int main(int argc, char** argv){ 

 std::cout << " " << std::endl;
 std::cout << " " << std::endl;
 std::cout << " " << std::endl; 
 std::cout << "     ___|          | _)  |         ___|                            |                   " << std::endl;
 std::cout << "   \\___ \\   __ \\   |  |  __|     \\___ \\    _` |  __ `__ \\   __ \\   |   _ \\     " << std::endl; 
 std::cout << "         |  |   |  |  |  |             |  (   |  |   |   |  |   |  |   __/             " << std::endl;
 std::cout << "   _____/   .__/  _| _| \\__|     _____/  \\__,_| _|  _|  _|  .__/  _| \\___|          " << std::endl;
 std::cout << "           _|                                              _|                          " << std::endl;
 std::cout << " " << std::endl;
 std::cout << " " << std::endl;
 std::cout << "    _ \\                      _ \\                                   " << std::endl;
 std::cout << "   |   |  |   |  __ \\       |   |   _` |  __ \\    _` |   _ \\      " << std::endl;
 std::cout << "   __ <   |   |  |   |      __ <   (   |  |   |  (   |   __/         " << std::endl;
 std::cout << "  _| \\_\\ \\__,_| _|  _|     _| \\_\\ \\__,_| _|  _| \\__, | \\___| " << std::endl;
 std::cout << "                                                |___/                " << std::endl;
 std::cout << " " << std::endl;
 std::cout << " " << std::endl;
 
 
 //Check if all nedeed arguments to parse are there                                                                                                                               
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }


 // Parse the config file                                                                                                                                                          
 parseConfigFile (argv[1]) ;
 
 std::string treeName  = gConfigParser -> readStringOption("Input::treeName");
 std::string inputFileName = gConfigParser -> readStringOption("Input::inputFileName");
 std::string treeNameDirectory  = gConfigParser -> readStringOption("Input::treeNameDirectory");


 std::vector<int> runRangesMin;
 try {
  runRangesMin = gConfigParser -> readIntListOption("Options::runRangesMin");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }

 std::vector<int> runRangesMax;
 try {
  runRangesMax = gConfigParser -> readIntListOption("Options::runRangesMax");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }
 
 
 int RunInterval = -1;
 try {
  RunInterval = gConfigParser -> readIntOption("Options::RunInterval");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }

 std::cout << " Options::RunInterval = " << RunInterval << std::endl;

 
 TTree *treeJetLepVect; 
 
 ///==== output file ====
 std::string outputDirectory = gConfigParser -> readStringOption("Output::outputDirectory");
 std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 
 
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
 
 
 
 
 ///==== program ====
 
 TFile* f = new TFile(inputFileName.c_str(), "READ");    
 treeJetLepVect = (TTree*) f->Get(treeName.c_str());
  
  int totalEvents = treeJetLepVect->GetEntries();
  int processedEvents = 0;
  
 int numOutputFiles;
 if (RunInterval == -1) {
  numOutputFiles = runRangesMax.size();
 }
 else {
   
   treeJetLepVect->Draw("runId","");
   TH1F* htemp = (TH1F*) gPad->GetPrimitive("htemp");
   int max = htemp->GetXaxis()->GetXmax();
   int min =  htemp->GetXaxis()->GetXmin();
   
//   int max = treeJetLepVect->GetMaximum("runId");
//   int min =  treeJetLepVect->GetMinimum("runId");
   std::cout << " min = " << min << std::endl;
   std::cout << " max = " << max << std::endl;
   
   max = max + (RunInterval+1); //----> to be safe!
   min  = min - (RunInterval+1);  //----> to be safe!
   
   numOutputFiles = (max - min) / RunInterval;
   runRangesMin.clear();
   runRangesMax.clear();
   for (int iInterval = 0; iInterval <numOutputFiles ; iInterval++) {
    runRangesMin.push_back(min + RunInterval * iInterval);
    runRangesMax.push_back(min + RunInterval * (iInterval+1));
   }
 }
   
 std::cout << " numOutputFiles = " << numOutputFiles << std::endl;
    
 for (int iOutFile = 0; iOutFile < numOutputFiles; iOutFile++) {
  std::cout << " iOutFile = " << iOutFile << " : " << numOutputFiles << std::endl;
  TString outputRootFileName = Form("%s/%s_%d.root",outputDirectory.c_str(),OutFileName.c_str(), iOutFile);   
  int countiEntry = 0;
  
  
  //==== save time if "long" upper tail in histogram runId ====
  if (processedEvents == totalEvents) break;
    
  ///==== create list for this run range ====
  TString Cut = Form ("(runId >= %d && runId < %d)", runRangesMin.at(iOutFile), runRangesMax.at(iOutFile));
  std::cout << " Cut = " << Cut.Data() << std::endl;
  treeJetLepVect->SetEntryList(0); 
  treeJetLepVect->Draw(">> myList",Cut.Data(),"entrylist");
  TEntryList *myList = (TEntryList*)gDirectory->Get("myList");
  treeJetLepVect->SetEntryList(myList); 
  std::cout << " myList -> GetN () = " << myList -> GetN () << std::endl;
  
  
  //==== create new root file only if at least 1 event! ====
  if (myList -> GetN () != 0) {
   TFile outputRootFile ( outputRootFileName.Data(), "RECREATE") ;
   outputRootFile.cd () ;
   outputRootFile.mkdir (treeNameDirectory.c_str()) ;
   outputRootFile.cd (treeNameDirectory.c_str()) ;  
  
   TTree* cloneTree = treeJetLepVect -> CloneTree (0) ;
 
  
  for ( int iEntry = 0; iEntry < myList -> GetN () ; iEntry++) { 
   if (!(iEntry%5000))  std::cout << " " << iEntry << " :: " << myList -> GetN () << std::endl;
   processedEvents++;
   countiEntry++;
   treeJetLepVect -> GetEntry (myList->Next());
   cloneTree -> Fill () ;
  }
  std::cout <<  " *** " << processedEvents << " : " << totalEvents << " ::::: " << countiEntry << " " << std::endl;
  cloneTree -> AutoSave () ;
  outputRootFile.Close () ;
  }
 }
 
}





