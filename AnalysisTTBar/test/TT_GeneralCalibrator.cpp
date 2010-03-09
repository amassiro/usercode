#include "treeReader.h"
#include "hFactory.h"
#include "hFunctions.h"
#include "stdHisto.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"



#include "JetCalibrator.h"
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

#include "TTBarUtils.h"







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
 
 std::string treeName      = gConfigParser -> readStringOption("Input::treeName");
 std::string inputFileList = gConfigParser -> readStringOption("Input::inputFileList");
 
 int entryMAX = gConfigParser -> readIntOption("Input::entryMAX");
 int entryMIN = gConfigParser -> readIntOption("Input::entryMIN");
 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  

 std::string outputFileName    = gConfigParser -> readStringOption("Output::fileName");
 std::cout << ">>>>> output::fileName  " << outputFileName  << std::endl;  
 
 
 // Open ntple
 TChain* chain = new TChain(treeName.c_str());
 if(!FillChain(*chain, inputFileList.c_str())) return 1;
 treeReader reader((TTree*)(chain));
 

 double MassW =  gConfigParser -> readDoubleOption("Input::MassW");
 
 double dPt =  gConfigParser  -> readDoubleOption("Input::dPt");
 double dEta =  gConfigParser -> readDoubleOption("Input::dEta"); 

 double minPt =  gConfigParser  -> readDoubleOption("Input::minPt");
 double maxPt =  gConfigParser  -> readDoubleOption("Input::maxPt");
 double maxEta =  gConfigParser -> readDoubleOption("Input::maxEta");
 
 
 std::cout << ">>>>> data::MassW  " << MassW  << std::endl;  
 std::cout << ">>>>> data::dPt    " << dPt    << std::endl;  
 std::cout << ">>>>> data::dEta   " << dEta   << std::endl;  
 std::cout << ">>>>> data::minPt  " << minPt  << std::endl;  
 std::cout << ">>>>> data::maxPt  " << maxPt  << std::endl;  
 std::cout << ">>>>> data::maxEta " << maxEta << std::endl;  
 std::cout << ">>>>> data::MassW  " << MassW  << std::endl;  
 
 
 ///==============================================================
 JetCalibrator myJetCalibrator(MassW,minPt,maxPt,maxEta,dPt,dEta);
 ///==============================================================
 
 std::cout << ">>>>> JetCalibrator::PtMin      " << myJetCalibrator.getPtMin()      << std::endl;  
 std::cout << ">>>>> JetCalibrator::PtMax      " << myJetCalibrator.getPtMax()      << std::endl;  
 std::cout << ">>>>> JetCalibrator::EtaMax     " << myJetCalibrator.getEtaMax()     << std::endl;  
 std::cout << ">>>>> JetCalibrator::DPt        " << myJetCalibrator.getDPt()        << std::endl;  
 std::cout << ">>>>> JetCalibrator::DEta       " << myJetCalibrator.getDEta()       << std::endl;  
 std::cout << ">>>>> JetCalibrator::IntPt      " << myJetCalibrator.getIntPt()      << std::endl;  
 std::cout << ">>>>> JetCalibrator::IntEta     " << myJetCalibrator.getIntEta()     << std::endl;  
 std::cout << ">>>>> JetCalibrator::NParameter " << myJetCalibrator.getNParameter() << std::endl;  
 std::cout << ">>>>> JetCalibrator::MResonance " << myJetCalibrator.getMResonance() << std::endl;  

 TFile outFile(outputFileName.c_str(),"RECREATE");
 TTree outTree("outTree","outTree");
 double t_M_Reco;
 std::vector<double>* t_pT_Reco = new std::vector<double>;
 std::vector<double>* t_pT_MC = new std::vector<double>;
 std::vector<double>* t_Eta_Reco = new std::vector<double>;
 int t_Cycle_num; //---- 0 = Before, 1 = After
 int t_Indip; //---- 0 = No Indip, 1 = Indip
 
 outTree.Branch("t_pT_Reco","std::vector<double>",&t_pT_Reco);
 outTree.Branch("t_pT_MC","std::vector<double>",&t_pT_MC);
 outTree.Branch("t_Eta_Reco","std::vector<double>",&t_Eta_Reco);
 outTree.Branch("t_M_Reco",&t_M_Reco,"t_M_Reco/D");
 outTree.Branch("t_Cycle_num",&t_Cycle_num,"t_Cycle_num/I");
 outTree.Branch("t_Indip",&t_Indip,"t_Indip/I");
 
 TH2F hKK_num("hKK_num","hKK_num",myJetCalibrator.getIntPt(),myJetCalibrator.getPtMin(),myJetCalibrator.getPtMax(),myJetCalibrator.getIntEta(),0,myJetCalibrator.getEtaMax()); //---- correction function K(eta) x K(pT) ----
 std::vector<TH2F> hKK_vect;
 std::vector<TH2F> hKK_err_vect;
 
 
 
 
 
 
 std::cout << ">>>>> tree::entries " << chain -> GetEntries()  << std::endl;
 entryMAX = std::min (static_cast<int>(entryMAX),static_cast<int>(chain -> GetEntries()));
 
 double start, end;
 
 
 ///===============================
 ///==== Filling JetCalibrator ====
 
 std::vector<ROOT::Math::XYZTVector>* mcF_fromV1 = new std::vector<ROOT::Math::XYZTVector>;
 std::vector<ROOT::Math::XYZTVector>* mcF_fromV2 = new std::vector<ROOT::Math::XYZTVector>;
 start = clock();
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent)
 {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
  
  std::vector<ROOT::Math::XYZTVector>* mcV1 = reader.Get4V("mcV1");
  std::vector<ROOT::Math::XYZTVector>* mcV2 = reader.Get4V("mcV2");
  
  std::vector<float>* mcV1_charge = reader.GetFloat("mcV1_charge");
  std::vector<float>* mcV2_charge = reader.GetFloat("mcV2_charge");
  
  std::vector<ROOT::Math::XYZTVector>* mcF1_fromV1 = reader.Get4V("mcF1_fromV1");
  std::vector<ROOT::Math::XYZTVector>* mcF1_fromV2 = reader.Get4V("mcF1_fromV2");
  std::vector<ROOT::Math::XYZTVector>* mcF2_fromV1 = reader.Get4V("mcF2_fromV1");
  std::vector<ROOT::Math::XYZTVector>* mcF2_fromV2 = reader.Get4V("mcF2_fromV2");
  
  std::vector<float>* mcF1_fromV1_pdgId = reader.GetFloat("mcF1_fromV1_pdgId");
  std::vector<float>* mcF1_fromV2_pdgId = reader.GetFloat("mcF1_fromV2_pdgId");
  std::vector<float>* mcF2_fromV1_pdgId = reader.GetFloat("mcF2_fromV1_pdgId");
  std::vector<float>* mcF2_fromV2_pdgId = reader.GetFloat("mcF2_fromV2_pdgId");
  
  std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
  
  mcF_fromV1->clear();
  mcF_fromV2->clear();
  mcF_fromV1->push_back(mcF1_fromV1->at(0));
  mcF_fromV1->push_back(mcF2_fromV1->at(0));
  mcF_fromV2->push_back(mcF1_fromV2->at(0));
  mcF_fromV2->push_back(mcF2_fromV2->at(0));
    
  std::vector<int> matchIt;
  int matched = 0;
  
  std::pair<int,int> decayMC = GetMCDecayChannel(mcF1_fromV1_pdgId->at(0),mcF2_fromV1_pdgId->at(0),mcF1_fromV2_pdgId->at(0),mcF2_fromV2_pdgId->at(0));
   
  if (decayMC.first == 2 && decayMC.second == 1){
   ///==== emu - quark ======== < 2 , 1 >
   matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromV2,0.3,0.1,2.0,&matchIt);
  }
  if (decayMC.first == 2 && decayMC.second == 2){
   ///==== quark - emu ======== < 2 , 2 >
   matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromV1,0.3,0.1,2.0,&matchIt);
  }
  
  if (matched > 0){
   if (matched == 2){
    std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> InputJetPair(jets->at(matchIt.at(0)),jets->at(matchIt.at(1)));
    
    ///--------------------------------------
    bool okJet = myJetCalibrator.AddJetPair(InputJetPair);
    ///--------------------------------------   
    if (okJet){
     hKK_num.Fill(jets->at(matchIt.at(0)).Pt(),jets->at(matchIt.at(0)).Eta());
     hKK_num.Fill(jets->at(matchIt.at(1)).Pt(),jets->at(matchIt.at(1)).Eta());
    }
   }
  }
 } //loop over the events
 


///==== end Filling JetCalibrator ====
///===================================


///======================
///==== minimization ====

int nCycle = gConfigParser -> readIntOption("Calibration::nCycle");
int Algorithm = gConfigParser -> readIntOption("Calibration::Algorithm");

std::cout << ">>>>> Calibration::nCycle " << nCycle << std::endl;   

if (Algorithm == 0) std::cout << ">>>>> Calibration::Algorithm UpdateMatrixInversion" << std::endl;   
if (Algorithm == 1) std::cout << ">>>>> Calibration::Algorithm UpdateRUL3" << std::endl;   
if (Algorithm == 2) std::cout << ">>>>> Calibration::Algorithm UpdateL3 ----------> Be Careful!" << std::endl;   
if (Algorithm == 3) std::cout << ">>>>> Calibration::Algorithm UpdateKUpdate ----------> Be Careful!" << std::endl;   
if (Algorithm == 4) std::cout << ">>>>> Calibration::Algorithm UpdateRUFit" << std::endl;   
if (Algorithm == 5) std::cout << ">>>>> Calibration::Algorithm UpdateSFit" << std::endl;   
if (Algorithm == 6) std::cout << ">>>>> Calibration::Algorithm UpdateMIB" << std::endl;   
if (Algorithm == 7) std::cout << ">>>>> Calibration::Algorithm UpdateSRooFit" << std::endl;   
if (Algorithm == 8) std::cout << ">>>>> Calibration::Algorithm UpdateSL3" << std::endl;   

for (int iCycle=0; iCycle< nCycle; iCycle++) { 
 std::cerr << "Cycle = " << iCycle << std::endl;
 std::cerr << "chi2 = " << myJetCalibrator.getChi2() << std::endl;
 
 ///------------------------------------------------------------
 if (Algorithm == 0) myJetCalibrator.UpdateMatrixInversion();
 if (Algorithm == 1) myJetCalibrator.UpdateRUL3();
 if (Algorithm == 2) myJetCalibrator.UpdateL3();
 if (Algorithm == 3) myJetCalibrator.UpdateKUpdate();
 if (Algorithm == 4) myJetCalibrator.UpdateRUFit();
 if (Algorithm == 5) myJetCalibrator.UpdateSFit();
 if (Algorithm == 6) myJetCalibrator.UpdateMIB();
 if (Algorithm == 7) myJetCalibrator.UpdateSRooFit();
 if (Algorithm == 8) myJetCalibrator.UpdateSL3();
 ///------------------------------------------------------------
 
 std::ostringstream oss;
 oss << "hKK_" << iCycle;
 std::string nameHisto(oss.str());
 TH2F hKK_tmp(nameHisto.c_str(),nameHisto.c_str(),myJetCalibrator.getIntPt(),myJetCalibrator.getPtMin(),myJetCalibrator.getPtMax(),myJetCalibrator.getIntEta(),0,myJetCalibrator.getEtaMax()); //---- correction function K(eta) x K(pT) ----

 oss << "_err";
 std::string nameHistoErr(oss.str());
 
 TH2F hKK_err_tmp(nameHistoErr.c_str(),nameHistoErr.c_str(),myJetCalibrator.getIntPt(),myJetCalibrator.getPtMin(),myJetCalibrator.getPtMax(),myJetCalibrator.getIntEta(),0,myJetCalibrator.getEtaMax()); //---- error on correction function K(eta) x K(pT) ----
 
 
 for (int iEta=0; iEta<myJetCalibrator.getIntEta(); iEta++){
  for (int iPt=0; iPt<myJetCalibrator.getIntPt(); iPt++){
   hKK_tmp.SetBinContent(iPt+1,iEta+1,myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt,iEta)));
   hKK_err_tmp.SetBinContent(iPt+1,iEta+1,myJetCalibrator.getKKErr(myJetCalibrator.GetInt(iPt,iEta)));   
   //    std::cerr << "KK[" << iPt << "][" << iEta << "] = " << myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt,iEta)) << std::endl;
  }
 }
 std::cerr << "JetCalibrator::chi2 = " << myJetCalibrator.getChi2() << std::endl;
 hKK_vect.push_back(hKK_tmp);  
 hKK_err_vect.push_back(hKK_err_tmp);  
}

///==== end minimization ====
///==========================



///==============
///==== test ====

///---- same sample as before ----

for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent)
{
 reader.GetEntry (iEvent) ;
 std::vector<ROOT::Math::XYZTVector>* mcV1 = reader.Get4V("mcV1");
 std::vector<ROOT::Math::XYZTVector>* mcV2 = reader.Get4V("mcV2");
 
 std::vector<float>* mcV1_charge = reader.GetFloat("mcV1_charge");
 std::vector<float>* mcV2_charge = reader.GetFloat("mcV2_charge");
 
 std::vector<ROOT::Math::XYZTVector>* mcF1_fromV1 = reader.Get4V("mcF1_fromV1");
 std::vector<ROOT::Math::XYZTVector>* mcF1_fromV2 = reader.Get4V("mcF1_fromV2");
 std::vector<ROOT::Math::XYZTVector>* mcF2_fromV1 = reader.Get4V("mcF2_fromV1");
 std::vector<ROOT::Math::XYZTVector>* mcF2_fromV2 = reader.Get4V("mcF2_fromV2");
 
 std::vector<float>* mcF1_fromV1_pdgId = reader.GetFloat("mcF1_fromV1_pdgId");
 std::vector<float>* mcF1_fromV2_pdgId = reader.GetFloat("mcF1_fromV2_pdgId");
 std::vector<float>* mcF2_fromV1_pdgId = reader.GetFloat("mcF2_fromV1_pdgId");
 std::vector<float>* mcF2_fromV2_pdgId = reader.GetFloat("mcF2_fromV2_pdgId");
 
 std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
 
 mcF_fromV1->clear();
 mcF_fromV2->clear();
 mcF_fromV1->push_back(mcF1_fromV1->at(0));
 mcF_fromV1->push_back(mcF2_fromV1->at(0));
 mcF_fromV2->push_back(mcF1_fromV2->at(0));
 mcF_fromV2->push_back(mcF2_fromV2->at(0));
 
 std::vector<int> matchIt;
 int matched = 0;
 
 std::pair<int,int> decayMC = GetMCDecayChannel(mcF1_fromV1_pdgId->at(0),mcF2_fromV1_pdgId->at(0),mcF1_fromV2_pdgId->at(0),mcF2_fromV2_pdgId->at(0));
 
 if (decayMC.first == 2 && decayMC.second == 1){
  ///==== emu - quark ======== < 2 , 1 >
  matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromV2,0.3,0.1,2.0,&matchIt);
 }
 if (decayMC.first == 2 && decayMC.second == 2){
  ///==== quark - emu ======== < 2 , 2 >
  matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromV1,0.3,0.1,2.0,&matchIt);
 }
 
 
 if (matched > 0){
  if (matched == 2){
   int iPt1 = myJetCalibrator.GetIntPt(jets->at(matchIt.at(0)).Pt());
   int iEta1 = myJetCalibrator.GetIntEta(jets->at(matchIt.at(0)).Eta());
   
   int iPt2 = myJetCalibrator.GetIntPt(jets->at(matchIt.at(1)).Pt());
   int iEta2 = myJetCalibrator.GetIntEta(jets->at(matchIt.at(0)).Eta());
   
   double M_temp = (jets->at(matchIt.at(0)) + jets->at(matchIt.at(1))).M();
   //---- data not used, out of range for KK!
   if ((iPt1 != -1) && (iPt2 != -1) && (iEta1 != -1.) && (iEta2 != -1)) {
    
    M_temp = M_temp * sqrt(myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt1,iEta1)) * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt2,iEta2)));    
    t_M_Reco = M_temp;    
    t_Eta_Reco->push_back(jets->at(matchIt.at(0)).Eta());
    t_Eta_Reco->push_back(jets->at(matchIt.at(1)).Eta());
    t_pT_Reco->push_back(jets->at(matchIt.at(0)).Pt() * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt1,iEta1)));
    t_pT_Reco->push_back(jets->at(matchIt.at(1)).Pt() * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt2,iEta2))); 
    
    if (decayMC.second == 2){  ///==== quark - emu ======== < 2 , 2 >
     t_pT_MC->push_back(mcF_fromV1->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV1->at(1).Pt());
    }
    else {///==== emu - quark ======== < 2 , 1 >
     t_pT_MC->push_back(mcF_fromV2->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV2->at(1).Pt());
    }
    t_Cycle_num = 1; //---- after
    t_Indip = 0; //---- No Indip
    outTree.Fill();   
    t_pT_Reco->clear();
      
    t_Cycle_num = 0; //---- before
    t_Indip = 0; //---- No Indip
    M_temp = (jets->at(matchIt.at(0)) + jets->at(matchIt.at(1))).M();
    t_M_Reco = M_temp; 
    t_pT_Reco->push_back(jets->at(matchIt.at(0)).Pt());
    t_pT_Reco->push_back(jets->at(matchIt.at(1)).Pt()); 
    outTree.Fill();
    
    t_pT_Reco->clear();
    t_pT_MC->clear();   
    t_Eta_Reco->clear();
   }
  }
 } 
}



///---- independent sample ----

int entryMAXTest = gConfigParser -> readIntOption("Test::entryMAX");
int entryMINTest = gConfigParser -> readIntOption("Test::entryMIN");

entryMAXTest = std::min (static_cast<int>(entryMAXTest),static_cast<int>(chain -> GetEntries()));

for(int iEvent = entryMINTest ; iEvent < entryMAXTest ; ++iEvent)
{
 reader.GetEntry (iEvent) ;
 std::vector<ROOT::Math::XYZTVector>* mcV1 = reader.Get4V("mcV1");
 std::vector<ROOT::Math::XYZTVector>* mcV2 = reader.Get4V("mcV2");
 
 std::vector<float>* mcV1_charge = reader.GetFloat("mcV1_charge");
 std::vector<float>* mcV2_charge = reader.GetFloat("mcV2_charge");
 
 std::vector<ROOT::Math::XYZTVector>* mcF1_fromV1 = reader.Get4V("mcF1_fromV1");
 std::vector<ROOT::Math::XYZTVector>* mcF1_fromV2 = reader.Get4V("mcF1_fromV2");
 std::vector<ROOT::Math::XYZTVector>* mcF2_fromV1 = reader.Get4V("mcF2_fromV1");
 std::vector<ROOT::Math::XYZTVector>* mcF2_fromV2 = reader.Get4V("mcF2_fromV2");
 
 std::vector<float>* mcF1_fromV1_pdgId = reader.GetFloat("mcF1_fromV1_pdgId");
 std::vector<float>* mcF1_fromV2_pdgId = reader.GetFloat("mcF1_fromV2_pdgId");
 std::vector<float>* mcF2_fromV1_pdgId = reader.GetFloat("mcF2_fromV1_pdgId");
 std::vector<float>* mcF2_fromV2_pdgId = reader.GetFloat("mcF2_fromV2_pdgId");
 
 std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
 
 mcF_fromV1->clear();
 mcF_fromV2->clear();
 mcF_fromV1->push_back(mcF1_fromV1->at(0));
 mcF_fromV1->push_back(mcF2_fromV1->at(0));
 mcF_fromV2->push_back(mcF1_fromV2->at(0));
 mcF_fromV2->push_back(mcF2_fromV2->at(0));
 
 std::vector<int> matchIt;
 int matched = 0;

 std::pair<int,int> decayMC = GetMCDecayChannel(mcF1_fromV1_pdgId->at(0),mcF2_fromV1_pdgId->at(0),mcF1_fromV2_pdgId->at(0),mcF2_fromV2_pdgId->at(0));
 
 if (decayMC.first == 2 && decayMC.second == 1){
  ///==== emu - quark ======== < 2 , 1 >
  matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromV2,0.3,0.1,2.0,&matchIt);
 }
 if (decayMC.first == 2 && decayMC.second == 2){
  ///==== quark - emu ======== < 2 , 2 >
  matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromV1,0.3,0.1,2.0,&matchIt);
 }
 
 if (matched > 0){
  if (matched == 2){
   int iPt1 = myJetCalibrator.GetIntPt(jets->at(matchIt.at(0)).Pt());
   int iEta1 = myJetCalibrator.GetIntEta(jets->at(matchIt.at(0)).Eta());
   
   int iPt2 = myJetCalibrator.GetIntPt(jets->at(matchIt.at(1)).Pt());
   int iEta2 = myJetCalibrator.GetIntEta(jets->at(matchIt.at(0)).Eta());
   double M_temp = (jets->at(matchIt.at(0)) + jets->at(matchIt.at(1))).M();
   //---- data not used, out of range for KK!
   if ((iPt1 != -1) && (iPt2 != -1) && (iEta1 != -1.) && (iEta2 != -1)) {
    
    M_temp = M_temp * sqrt(myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt1,iEta1)) * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt2,iEta2)));    
    t_M_Reco = M_temp;    
    t_Eta_Reco->push_back(jets->at(matchIt.at(0)).Eta());
    t_Eta_Reco->push_back(jets->at(matchIt.at(1)).Eta());
    t_pT_Reco->push_back(jets->at(matchIt.at(0)).Pt() * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt1,iEta1)));
    t_pT_Reco->push_back(jets->at(matchIt.at(1)).Pt() * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt2,iEta2))); 
    
    if (decayMC.second == 2){  ///==== quark - emu ======== < 2 , 2 >
     t_pT_MC->push_back(mcF_fromV1->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV1->at(1).Pt());
    }
    else {///==== emu - quark ======== < 2 , 1 >
     t_pT_MC->push_back(mcF_fromV2->at(0).Pt());
     t_pT_MC->push_back(mcF_fromV2->at(1).Pt());
    }
    t_Cycle_num = 1; //---- after
    t_Indip = 1; //---- Yes Indip
    outTree.Fill();   
    t_pT_Reco->clear();
    
    t_Cycle_num = 0; //---- before
    t_Indip = 1; //---- Yes Indip
    M_temp = (jets->at(matchIt.at(0)) + jets->at(matchIt.at(1))).M();
    t_M_Reco = M_temp; 
    t_pT_Reco->push_back(jets->at(matchIt.at(0)).Pt());
    t_pT_Reco->push_back(jets->at(matchIt.at(1)).Pt());   
    outTree.Fill();
    
    t_pT_Reco->clear();
    t_pT_MC->clear();   
    t_Eta_Reco->clear();
   }
  }
 } 
}



///==== end test ====
///==================


delete mcF_fromV1;
delete mcF_fromV2;



for (int iHisto=0; iHisto<hKK_vect.size(); iHisto++){
 hKK_vect.at(iHisto).Write();
 hKK_err_vect.at(iHisto).Write();
} 

outFile.Write();   

end = clock();
std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;

delete t_pT_Reco;
delete t_pT_MC;
delete t_Eta_Reco;

return 0;
}



