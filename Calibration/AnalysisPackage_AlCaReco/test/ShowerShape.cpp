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
 
 TTree myTree("myTree","myTree");
 double Eta;
 double pT;
 double ET;
 double EoP;
 double SwissE4;
 double MaxEnergy;
 TH2F *h2ShowerShapeEB = new TH2F("h2ShowerShapeEB","Shower Shape i#phi i#eta",170,-85,85,360,0,360);
 TH2F *h2ShowerShapeEE = new TH2F("h2ShowerShapeEE","Shower Shape ix iy",100,0,100,100,0,100);

 h2ShowerShapeEB->GetXaxis()->SetTitle("i#eta");
 h2ShowerShapeEB->GetYaxis()->SetTitle("i#phi");

 h2ShowerShapeEE->GetXaxis()->SetTitle("ix");
 h2ShowerShapeEE->GetYaxis()->SetTitle("iy");
 
 myTree.Branch("Eta",&Eta,"Eta/D");
 myTree.Branch("ET",&ET,"ET/D");
 myTree.Branch("pT",&pT,"pT/D");
 myTree.Branch("EoP",&EoP,"EoP/D");
 myTree.Branch("SwissE4",&SwissE4,"SwissE4/D");
 myTree.Branch("MaxEnergy",&MaxEnergy,"MaxEnergy/D");
 myTree.Branch("h2ShowerShapeEB","TH2F",&h2ShowerShapeEB,128000,0);
 myTree.Branch("h2ShowerShapeEE","TH2F",&h2ShowerShapeEE,128000,0);
 
 double start, end;
 
 if (entryMAX == -1) entryMAX = reader.GetEntries();
 else if (reader.GetEntries() < entryMAX) entryMAX = reader.GetEntries();
 
 start = clock();
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent) {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << ":" << entryMAX << std::endl;   

  h2ShowerShapeEB->Reset();
  h2ShowerShapeEE->Reset();
  int nXtal = reader.GetFloat("E_xtal")->size();
  for (int iXtal = 0; iXtal < nXtal; iXtal++){
   if (reader.GetInt("ix_xtal")->at(iXtal) == -1000) {
    ///==== Barrel EB ====
    h2ShowerShapeEB->Fill(reader.GetInt("ieta_xtal")->at(iXtal),reader.GetInt("iphi_xtal")->at(iXtal),reader.GetFloat("E_xtal")->at(iXtal));
   }
   else {
    ///==== Endcap EE ====
    h2ShowerShapeEE->Fill(reader.GetInt("ix_xtal")->at(iXtal),reader.GetInt("iy_xtal")->at(iXtal),reader.GetFloat("E_xtal")->at(iXtal));
   }
  }  
  
  if (reader.GetInt("runId")->size()!=0){
   TString TitleEB = Form ("Shower Shape i#phi i#eta Run = %d --- lumi = %d --- event = %d",reader.GetInt("runId")->at(0),reader.GetInt("lumiId")->at(0),reader.GetInt("eventId")->at(0));
   h2ShowerShapeEB->SetTitle(TitleEB);
   
   TString TitleEE = Form ("Shower Shape ix iy Run = %d --- lumi = %d --- event = %d",reader.GetInt("runId")->at(0),reader.GetInt("lumiId")->at(0),reader.GetInt("eventId")->at(0));
   h2ShowerShapeEE->SetTitle(TitleEE);
  }
  
  int nEles = reader.Get4V("electrons")->size();
  for (int iEle = 0; iEle < nEles; iEle++){
//    std::cerr << "iEle = " << iEle << " : " << nEles << std::endl;
   if (
    (reader.Get4V("met")->at(0)).Et() > 20
    && reader.Get4V("electrons")->at(iEle).Pt() > 10 
    && reader.Get4V("electrons")->at(iEle).Pt() < 60
    && deltaPhi(reader.Get4V("electrons")->at(iEle).Phi(),(reader.Get4V("met")->at(0)).Phi()) > 0.75
    && (((reader.Get4V("met")->at(0)).Et() / reader.GetFloat("sumEt")->at(0)) > (-0.07 * (reader.Get4V("met")->at(0)).Et() + 3.5 ) 
    || ((reader.Get4V("met")->at(0)).Et() / reader.GetFloat("sumEt")->at(0)) > 0.4)
    )
    {
     std::cerr << "selected ..." << std::endl;
     pT = reader.Get4V("electrons")->at(iEle).Pt();   
     ET = (reader.GetFloat("electrons_scE")->at(iEle)) * sin(reader.Get4V("electrons")->at(iEle).Theta());
     EoP = reader.GetFloat("electrons_eOverP")->at(iEle);
     Eta = reader.Get4V("electrons")->at(iEle).Eta();
     SwissE4 = reader.GetFloat("SwissE4")->at(iEle);
     MaxEnergy = reader.GetFloat("MaxEnergy")->at(iEle);
     myTree.Fill();
    }
   }
 } //loop over the events 
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  

 myTree.Write();
 outFile.Write();
  
 return 0;
}



