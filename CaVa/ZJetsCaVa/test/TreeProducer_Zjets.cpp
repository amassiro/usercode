///==== test program ====

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
#include "ZJetsCaVa.h"

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
  
 TTree tree("outTree","outTree");
 double xMC;
 double xRECO;
 double xMCEXP;
 double xKind;
 double xDR;
 double xMass;
 
 tree.Branch("xMC",&xMC,"xMC/D");
 tree.Branch("xRECO",&xRECO,"xRECO/D");
 tree.Branch("xMCEXP",&xMCEXP,"xMCEXP/D");
 tree.Branch("xKind",&xKind,"xKind/D");
 tree.Branch("xDR",&xDR,"xDR/D");
 tree.Branch("xMass",&xMass,"xMass/D");
 
 
 std::vector<ROOT::Math::XYZTVector>* v_JetRecoil = new std::vector<ROOT::Math::XYZTVector>;
 std::vector<ROOT::Math::XYZTVector>* v_GenJetRecoil = new std::vector<ROOT::Math::XYZTVector>;
 
 double start, end;
 
 if (entryMAX == -1) entryMAX = reader.GetEntries();
 else if (reader.GetEntries() < entryMAX) entryMAX = reader.GetEntries();
 
 start = clock();
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent) {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << " : " << entryMAX << std::endl;   
  
  ///==== Z search ====
  double MassZ = 90.;
  std::vector<int> itSelEle;
  
  double DmassZ_ele = SelectResonanceOppositeCharge(itSelEle,*reader.Get4V("mc_ele"),*reader.GetFloat("mc_ele_charge"),MassZ,-1.,0);
  
//   std::cerr << " Mass eles performed " << itSelEle.at(0) << " " << itSelEle.at(1) <<  " : " << reader.GetFloat("mc_ele_charge")->size() << std::endl;

  std::vector<int> itSelMu;
  double DmassZ_mu = SelectResonanceOppositeCharge(itSelMu,*reader.Get4V("mc_mu"),*reader.GetFloat("mc_mu_charge"),MassZ,-1.,0);
  
//   std::cerr << " Mass  mus performed " << itSelMu.at(0) << " " << itSelMu.at(1) << " : " << reader.GetFloat("mc_mu_charge")->size() << std::endl;
  
  ROOT::Math::XYZTVector ZBoson(0,0,0,0);
  
  if (itSelEle.at(0)!=-1 && itSelEle.at(1)!=-1 && DmassZ_ele < DmassZ_mu){
   ///==== electrons ====
   ZBoson = (reader.Get4V("mc_ele")->at(itSelEle.at(0)) + (reader.Get4V("mc_ele")->at(itSelEle.at(1))));
   xMass = ZBoson.mass();
   xKind = 0;
  }
  else {
   if (itSelMu.at(0)!=-1 && itSelMu.at(1)!=-1){
    ///==== muons ====
    ZBoson = (reader.Get4V("mc_mu")->at(itSelMu.at(0)) + reader.Get4V("mc_mu")->at(itSelMu.at(1)));
    xMass = ZBoson.mass();
    xKind = 1;
   }
   else {
    continue;
   }
  }
  
  ROOT::Math::XYZTVector JetRecoil(0,0,0,0);
  JetRecoil = -ZBoson;
  
  ///==== GenJet search ====
  std::vector<int> matchItGenZ;
  v_JetRecoil->clear();
  v_JetRecoil->push_back(JetRecoil);
  int matched = 0;
  matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*reader.Get4V("genJets"),*v_JetRecoil,0.3,0.1,2.0,&matchItGenZ);
  
  ///==== GenJet - RecoJet match ====
  if (matchItGenZ.at(0) == -1) continue;
  ROOT::Math::XYZTVector GenJetRecoil = reader.Get4V("genJets")->at(matchItGenZ.at(0));
  v_GenJetRecoil->clear();
  v_GenJetRecoil->push_back(GenJetRecoil);
  
  std::vector<int> matchItRecoGen;
  matched = 0;
  matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*reader.Get4V("jets"),*v_GenJetRecoil,0.3,0.1,2.0,&matchItRecoGen);
  if (matchItRecoGen.at(0) == -1) continue;
  
  ///==== Fill ntuple ====
  xMC = reader.Get4V("genJets")->at(matchItGenZ.at(0)).Pt();
  xRECO = reader.Get4V("jets")->at(matchItRecoGen.at(0)).Pt();
  xMCEXP = ZBoson.Pt();
  
  xDR = ROOT::Math::VectorUtil::DeltaR(reader.Get4V("jets")->at(matchItRecoGen.at(0)),reader.Get4V("genJets")->at(matchItGenZ.at(0)));
  
  tree.Fill();
  
 } //loop over the events 
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 
 outFile.Write();

 delete v_GenJetRecoil;
 delete v_JetRecoil;
 
 return 0;
}
