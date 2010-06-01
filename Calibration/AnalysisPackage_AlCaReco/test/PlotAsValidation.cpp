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
 
 
 TTree m_tree("m_tree","m_tree");
 float m_eta;
 float m_phi;
 float m_pTk;
 float m_MaxEnergy;
 float m_energy;
 float m_Energy25;
 float m_ESCoP;
 float m_eSeedOverPout;
 float m_pOut;
 float m_preshower;
 float m_Energy9;
 float m_Energy49;
 float m_pErr;
 int m_class;
 float m_recHits;
 double m_chis;
 int m_lost;
 int m_found;
 double m_momentum;
 double m_ndof;
 double m_chisN;
 int m_runID;
 int m_eventID;

 m_tree.Branch("eta",&m_eta,"eta/F");
 m_tree.Branch("phi",&m_phi,"phi/F");
 m_tree.Branch("pTk",&m_pTk,"pTk/F");
 m_tree.Branch("MaxEnergy",&m_MaxEnergy,"MaxEnergy/F");
 m_tree.Branch("energy",&m_energy,"energy/F");
 m_tree.Branch("Energy25",&m_Energy25,"Energy25/F");
 m_tree.Branch("ESCoP",&m_ESCoP,"ESCoP/F");
 m_tree.Branch("eSeedOverPout",&m_eSeedOverPout,"eSeedOverPout/F");
 m_tree.Branch("pOut",&m_pOut,"pOut/F");
 m_tree.Branch("Energy9",&m_Energy9,"Energy9/F");
 m_tree.Branch("Energy49",&m_Energy49,"Energy49/F");
 m_tree.Branch("Presh",&m_preshower,"Presh/F");
 m_tree.Branch("pErr",&m_pErr,"pErr/F");
 m_tree.Branch("recHits",&m_recHits,"recHits/F");
 m_tree.Branch("class",&m_class,"class/I");
 m_tree.Branch("chis",&m_chis,"chis/D");
 m_tree.Branch("lost",&m_lost,"lost/I");
 m_tree.Branch("found",&m_found,"found/I");
 m_tree.Branch("ndof",&m_ndof,"ndof/D");
 m_tree.Branch("momentum",&m_momentum,"m_momentum/D");
 m_tree.Branch("chisN",&m_chisN,"chisN/D");
 m_tree.Branch("runID",&m_runID,"runID/I");
 m_tree.Branch("eventID",&m_eventID,"eventID/I");
 
 double start, end;
 
 if (entryMAX == -1) entryMAX = reader.GetEntries();
 else if (reader.GetEntries() < entryMAX) entryMAX = reader.GetEntries();
 
 int step = 0;
 start = clock();
 int nEleTot = 0;
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent) {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
  
  int nEles = reader.Get4V("electrons")->size();
  int nEleSel = 0;
  ROOT::Math::XYZTVector Resonance(0,0,0,0);
  std::cerr << " nEles = " << nEles << std::endl;
  for (int iEle = 0; iEle < nEles; iEle++){    
   m_eta = reader.Get4V("electrons")->at(iEle).Eta();
   m_energy = reader.GetFloat("Calo_Energy")->at(iEle);
   m_ESCoP = reader.GetFloat("ESCoP")->at(iEle);
   m_recHits = reader.GetFloat("recHits")->at(iEle);
   m_eventID = reader.GetInt("eventId")->at(iEle);
   m_runID = reader.GetInt("runId")->at(iEle);
   m_tree.Fill();
   nEleTot++;
  }
 } //loop over the events 
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 
 std::cerr << " nEleTot = " << nEleTot << " : " << entryMAX << " evts " << std::endl;
 
 m_tree.Write();
 
 return 0;
}



