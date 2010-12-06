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

#include "Variables.h"
#include "AnalysisTTBar.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif

int GetNumList(std::vector<int> &list){
 int result = 0;
 for (int it = 0; it<list.size(); it++) result += list.at(it);
 return result;
}

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
 double inputXSection  = gConfigParser -> readDoubleOption("Input::inputXSection");
 
 int entryMAX = gConfigParser -> readIntOption("Input::entryMAX");
 int entryMIN = gConfigParser -> readIntOption("Input::entryMIN");
 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 std::cout << ">>>>> input::entryMIN  " << entryMIN  << std::endl;  
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 
 int dataFlag = 0;
 if (inputXSection == -1) dataFlag = 1; //==== it's a data sample!!!
  // define map with events
  std::map<std::pair<int,std::pair<int,int> >,int> eventsMap;  
 
 
 int nStepToDo = 1000;
 try {
  nStepToDo = gConfigParser -> readIntOption("Input::nStepToDo");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
  nStepToDo = 1000;
 }
 std::cout << ">>>>> input::nStepToDo  " << nStepToDo  << std::endl;  
 
 
 // Open ntple
 TChain* chain = new TChain(treeName.c_str());
 chain->Add(inputFile.c_str());
 treeReader reader((TTree*)(chain));
 
 bool  debug = false; 
 try {
  debug = gConfigParser -> readBoolOption("Input::debug");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
  nStepToDo = 1000;
 }
 std::cout << ">>>>> input::debug  " << debug  << std::endl;  
 
 
 ///---- Efficiency preselections ---- 
 
 std::string histoNameEvents      = gConfigParser -> readStringOption("Input::histoNameEvents"); 
 std::cout << ">>>>> Input::inputFile                 " << inputFile  << std::endl;  
 std::cout << ">>>>> Input::inputXSection             " << inputXSection  << std::endl;  
 std::cout << ">>>>> Input::histoNameEvents      " << histoNameEvents  << std::endl;  
 
 // Open ntples
 TFile File(inputFile.c_str()) ; 
 TH1F* histoEvents = (TH1F*) File.Get(TString(histoNameEvents.c_str()));
 
 ///=================================
 
 double lepton_efficiency = 1;
 double jet_efficiency = 1;
 double eff_Channel_Filter = 1;
 double preselection_efficiency = 1.;

 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
 ///-------------------
 ///---- selection ----
 std::string outFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << outFileName  << std::endl;  
 
 int nStep = 10; ///==== number of steps in the analysis
 
 int numEntriesBefore;
 
 // define variable container
 Variables vars;
 InitializeTree(vars, outFileName);
 vars.XSection = inputXSection;
 vars.dataFlag = dataFlag;  ///~~~~ 0 = MC       1 = DATA
 
 if (entryMAX == -1) entryMAX = reader.GetEntries();
 else if (reader.GetEntries() < entryMAX) entryMAX = reader.GetEntries();
 numEntriesBefore = entryMAX - entryMIN;
 
 if (histoEvents) preselection_efficiency = numEntriesBefore / (1. * histoEvents->GetBinContent(1));
 else preselection_efficiency = 1;
 
 vars.numEntriesBefore = numEntriesBefore;
 vars.preselection_efficiency = preselection_efficiency;
 
 FillEfficiencyTree(vars);
 
 
 ///*************************************
 ///**** definition of electron ID ****
  std::vector<double> BarrelSelections;
  std::vector<double> EndCapSelections;
  
  BarrelSelections.push_back(0.15); ///==== iso Tk
  BarrelSelections.push_back(2.00); ///==== iso em
  BarrelSelections.push_back(0.12); ///==== iso had
  BarrelSelections.push_back(0.15); ///==== iso combined
  BarrelSelections.push_back(0.015); ///==== hOe
  BarrelSelections.push_back(0.01); ///==== sigmaIetaIeta
  BarrelSelections.push_back(0.8); ///==== dPhi
  BarrelSelections.push_back(0.007); ///==== dEta
  
  EndCapSelections.push_back(0.08); ///==== iso Tk
  EndCapSelections.push_back(0.06); ///==== iso em
  EndCapSelections.push_back(0.05); ///==== iso had
  EndCapSelections.push_back(0.10); ///==== iso combined
  EndCapSelections.push_back(0.07); ///==== hOe
  EndCapSelections.push_back(0.03); ///==== sigmaIetaIeta
  EndCapSelections.push_back(0.7); ///==== dPhi
  EndCapSelections.push_back(0.01); ///==== dEta
  
  
  ///***********************************
  ///**** definition of muon ID ****
  std::vector<double> Selections;
  Selections.push_back(0.15); ///==== iso Combined
  Selections.push_back(10); ///==== Chi2/ndof
  Selections.push_back(10); ///==== n ValidTrackerHits
  Selections.push_back(0); ///==== n ValidMuonHits
  Selections.push_back(1); ///==== tracker
  Selections.push_back(1); ///==== standalone
  Selections.push_back(1); ///==== global
  //Selections.push_back(1); ///==== goodMuon
  
  
  ///********************************************************
  ///**** map for jet combination speed enhance ****
//   std::mapstd::vector<std::vector<int> > combinations_map;
  
  
 ///*********************************************************************************************
 ///*********************************************************************************************
  double start, end;
 std::cout << ">>>>> analysis::entryMIN " << entryMIN << " ==> entryMAX " << entryMAX << ":" << reader.GetEntries() << std::endl;   
 
 int step = 0;
 start = clock();
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent) {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << " : " << entryMAX - entryMIN << std::endl;   
  
  
  ///**************************************************
  ///**** STEP -1 - Check no copies in DATA ****
  ///**************************************************
  if (debug) std::cout << " STEP -1 " << std::endl;
  
  if( dataFlag == 1 )
  {
   std::pair<int,int> eventLSandID(reader.GetInt("lumiId")->at(0), reader.GetInt("eventId")->at(0));
   std::pair<int,std::pair<int,int> > eventRUNandLSandID(reader.GetInt("runId")->at(0), eventLSandID);
   
   if( eventsMap[eventRUNandLSandID] == 1 ) continue;
   else eventsMap[eventRUNandLSandID] = 1;
  }
  
  ///****************************
  ///**** STEP 0 - Ntuplizer ****
  ///************* no additional selections applied 
  step = 0;  
  if (step > nStepToDo) {
   FillTree(vars);
   continue;
  }
   
   if (debug) std::cout << " STEP 0 " << std::endl;
   
  ///*********************************************
  ///**** STEP 1 - Jet cleaning + min pT ****
  ///************* it's performed another time here to make sure that the cleaning worked well
  ///************* Jet - electrons (pT > 5)
  ///************* Jet - muons     (pT > 5)
  ///************ In addition only jets with pT > 15 are considered from now on!
  ///**** Require at least 4 jets of this kind and at most 10 (!!!) ****
  
    
  step = 1;
  if (step > nStepToDo) {
   FillTree(vars); 
   continue;
  }
    
    if (debug) std::cout << " STEP 1 " << std::endl;
    
    std::vector<ROOT::Math::XYZTVector> leptons_jetCleaning;   
  // build the collection of electros for jet cleaning
  ///==== CLEANING WITH ELECTRONS ====
  if (debug) std::cout << " STEP 1 :: cleaning with electrons " << std::endl;
  for(unsigned int iEle = 0; iEle < (reader.Get4V("electrons")->size()); ++iEle)
  {
   if( reader.Get4V("electrons")->at(iEle).pt() < 5. ) continue;
   bool flag =  IsEleIsolatedID(reader,BarrelSelections,EndCapSelections,iEle);
   if (!flag) continue;
   
   leptons_jetCleaning.push_back( reader.Get4V("electrons")->at(iEle) );
  }
  
  
  ///==== CLEANING WITH MUONS ====
  if (debug) std::cout << " STEP 1 :: cleaning with muons " << std::endl;
  for (int iMu = 0; iMu < reader.Get4V("muons")->size(); iMu++){    
   if (reader.Get4V("muons")->at(iMu).pt() < 5.0) continue;
   if (fabs(reader.Get4V("muons")->at(iMu).Eta()) > 2.5) continue;
   bool flag =  IsMuIsolatedID(reader,Selections,iMu);
   if (!flag) continue;
   
   leptons_jetCleaning.push_back( reader.Get4V("muons")->at(iMu) );
  }
   
  ///==== now clean jet collection ====
  
  int nJets = reader.Get4V("jets")->size();
  std::vector<int> whitelistJet; ///~~~~ all jets, 0 if rejected, 1 if accepted
  std::vector<int> blacklistJet; ///~~~~ list of numbers of jets that are "rejected"
  for (int iJet = 0; iJet < nJets; iJet++){
   bool skipJet = false;
   if (reader.Get4V("jets")->at(iJet).Et() < 15.0) skipJet = true;
   for(unsigned int iLep = 0; iLep < leptons_jetCleaning.size(); ++iLep) {
    ROOT::Math::XYZTVector lep = leptons_jetCleaning.at(iLep);
    if (ROOT::Math::VectorUtil::DeltaR(reader.Get4V("jets")->at(iJet),lep) < 0.3 ) skipJet = true;
   }
   if (skipJet) {
    whitelistJet.push_back(0); ///---- reject
    blacklistJet.push_back(iJet); ///---- reject ///== black list is in a different format
   }
   else {
    whitelistJet.push_back(1); ///---- select
   }
  }
  
  if (GetNumList(whitelistJet) < 4) continue; ///==== at least 4 jets "isolated"
  if (GetNumList(whitelistJet) > 10) continue; ///==== no more than 6 jets!!!
  
  ///*************************************************************
  ///**** STEP 2 - lepton selections and identification ****
  ///************* electrons and muons selections (ID + pT > 5)
  ///**** Required ONLY one lepton
  ///************* maxPt of the leptons is selected for next step
  
  step = 2;
  if (step > nStepToDo) {
   FillTree(vars);
   continue;
  }
  
  if (debug) std::cout << " STEP 2 " << std::endl;
  
  std::vector<int> whitelistElectron; ///~~~~ all electrons, 0 if rejected, 1 if accepted
  std::vector<int> blacklistElectron; ///~~~~ list of numbers of electrons that are "rejected"

  ///~~~ electrons ~~~
  for(unsigned int iEle = 0; iEle < (reader.Get4V("electrons")->size()); ++iEle) {
   bool skipEle = false;
   if(!skipEle && reader.Get4V("electrons")->at(iEle).pt() < 5. ) skipEle = true;
   skipEle = (skipEle ||  IsEleIsolatedID(reader,BarrelSelections,EndCapSelections,iEle));
   
   if (skipEle) {
    whitelistElectron.push_back(0); ///---- reject
    blacklistElectron.push_back(iEle); ///---- reject ///== black list is in a different format
   }
   else {
    whitelistElectron.push_back(1); ///---- select
   }
  }
 
 
 ///~~~ muons ~~~
 std::vector<int> whitelistMuon; ///~~~~ all muons, 0 if rejected, 1 if accepted
 std::vector<int> blacklistMuon; ///~~~~ list of numbers of muons that are "rejected"
 
 for (int iMu = 0; iMu < reader.Get4V("muons")->size(); ++iMu){    
  bool skipMu = false;
  if(!skipMu && reader.Get4V("muons")->at(iMu).pt() < 5. ) skipMu = true;
  skipMu = (skipMu ||  IsMuIsolatedID(reader,Selections,iMu));
  
  if (skipMu) {
   whitelistMuon.push_back(0); ///---- reject
   blacklistMuon.push_back(iMu); ///---- reject ///== black list is in a different format
  }
  else {
   whitelistMuon.push_back(1); ///---- select
  }
 }
 
  std::string method = "maxPt";
 
  int totalEle = GetNumList(whitelistElectron);
  int totalMu = GetNumList(whitelistMuon);
  
  ///~~~~ require ONLY one lepton ~~~~
  if (!((totalEle == 1) ^ (totalMu == 1))) continue;  ///==== !  ( number of electrons == 1 xor number of muons == 1 ) ====
     
   if (debug) std::cout << " STEP 2 :: Select electrons and muons " << std::endl;
   ///~~~~ select lepton with highest pT ~~~~
   int nSelEle =   SelectObject(*(reader.Get4V("electrons")), method, 5, &blacklistElectron);
   int nSelMu =   SelectObject(*(reader.Get4V("muons")), method, 5, &blacklistMuon);

  if (debug) std::cout << " STEP 2 :: electrons and muons selected" << std::endl;
  
   if (nSelEle != -1 && !(nSelMu != -1)){ ///====  electron channel ==== no muons
    SetLeptonEleVariables(vars, reader,nSelEle);
   }
   if (debug) std::cout << " STEP 2 :: muons set" << std::endl;
   
   if (nSelMu != -1 && !(nSelEle != -1)){ ///==== muon channel ==== no electrons
    SetLeptonMuVariables(vars, reader,nSelMu);
   }
   if (debug) std::cout << " STEP 2 :: electrons set" << std::endl;
   
   SetMetVariables(vars, reader, "PFMet");
   if (debug) std::cout << " STEP 2 :: MET set" << std::endl;     
   
   
   
   ///****************************************
   ///**** STEP 3 -  jet identification ****
   ///************* between all combination of jets get the best combination 
   
   step = 3;
   if (step > nStepToDo) {
    FillTree(vars);
    continue;
   }
   
   if (debug) std::cout << " STEP 3 " << std::endl;
   
   std::vector<std::vector<int> > combinations;
   if (debug) std::cout << " STEP 3 :: nJets = " << nJets << " ::: " << GetNumList(whitelistJet) << std::endl;     
   int buffer = Build4ObjectsCombinations(combinations,nJets,&whitelistJet);
   if (debug) std::cout << " STEP 3 :: numCombinations = " << buffer << " : " << combinations.size() << std::endl;     
   
    std::pair<double,int> bestCombination = GetCombinationGeneral(reader,combinations,&whitelistJet);
   
   double btag_value = bestCombination.first;
   int nBestCombination = bestCombination.second;
   
   if (debug) std::cout << " STEP 3 :: nBestCombination = " << nBestCombination << " : " << buffer  << std::endl;        
   if (nBestCombination == -1) continue;
   
   int q1 = combinations.at(nBestCombination).at(0);
   int q2 = combinations.at(nBestCombination).at(1);
   int b1 = combinations.at(nBestCombination).at(2);
   int b2 = combinations.at(nBestCombination).at(3);    
    
   if (debug) std::cout << " STEP 3 :: q1 = " << q1 << " q2 = " << q2 << " b1 = " << b1 << " b2 = " << b2 <<  std::endl;        
   
    SetQJetVariables(vars, reader, q1, q2);
    SetBJetVariables(vars, reader, b1, b2);
    
    ///**********************************
    ///**** STEP 4 - jet selection ****
    ///******* select event only if ...
    
    step = 4;
    if (step > nStepToDo) {
     FillTree(vars);
     continue;
    }
    
    
    ///**********************************
    ///**** STEP 5 - SAVE ****
    ///******* save event
    ///**** No more selections applied ****
    
    step = 5;
    FillTree(vars);
    
 ///==== ... to be continued in next program ... ====
  ///=================================================
  
 }
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 
 SaveTree(vars);
 
 std::cout << " *** end *** " << std::endl;
 
 return 0;
}


