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
 
 int analysisStep = gConfigParser -> readIntOption("Input::analysisStep");
 std::cout << ">>>>> input::analysisStep  " << analysisStep  << std::endl;  
 
 double lumiMAX = gConfigParser -> readDoubleOption("Input::lumiMAX"); 
 double fractionLumiMAXcalib = gConfigParser -> readDoubleOption("Input::fractionLumiMAXcalib"); 

 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 std::cout << ">>>>> input::lumiMAX  " << lumiMAX  << std::endl;  
 std::cout << ">>>>> input::fractionLumiMAXcalib  " << fractionLumiMAXcalib  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 std::string treeNameEfficiency    = gConfigParser -> readStringOption("Input::treeNameEfficiency");
 std::cout << ">>>>> Input::treeNameEfficiency      " << treeNameEfficiency  << std::endl;  
 
 std::string outputFileName    = gConfigParser -> readStringOption("Output::fileName");
 std::cout << ">>>>> output::fileName  " << outputFileName  << std::endl;  
 
 
 ///==== Open ntple ====
 TChain* chainEff[1000];
 std::vector<TChain*> chain;
 std::vector<int> maxFilling;
 char *nameSample[1000];
 
 //  treeReader* reader[100];
 
 int stepAnalysis;
 ROOT::Math::XYZTVector* q_1 = new ROOT::Math::XYZTVector;
 ROOT::Math::XYZTVector* q_2 = new ROOT::Math::XYZTVector;
 ROOT::Math::XYZTVector* b_1 = new ROOT::Math::XYZTVector;
 ROOT::Math::XYZTVector* b_2 = new ROOT::Math::XYZTVector;
 
 double preselection_efficiency; 
 double analysisEfficiency; 
 double XSection;
 
 
 int numberOfSamples = 0;
 std::ifstream inFile(inputFileList.c_str());
 std::string buffer;
 
 if(!inFile.is_open())
 {
  std::cerr << "** ERROR: Can't open '" << inputFileList << "' for input" << std::endl;
  return false;
 }
 
 while(1)
 {
  inFile >> buffer;
  if(!inFile.good()) break;
  
  nameSample[numberOfSamples] = new char [1000];
  sprintf(nameSample[numberOfSamples],"%s",buffer.c_str());
  
  chain.push_back(new TChain(treeName.c_str()));
  
// chain[numberOfSamples] = new TChain(treeName.c_str());  
  chain[numberOfSamples]->Add(buffer.c_str());
  
  chain[numberOfSamples]->SetBranchAddress("stepAnalysis",&stepAnalysis);
  chain[numberOfSamples]->SetBranchAddress("q_1",&q_1);
  chain[numberOfSamples]->SetBranchAddress("q_2",&q_2);
  chain[numberOfSamples]->SetBranchAddress("b_1",&b_1);
  chain[numberOfSamples]->SetBranchAddress("b_2",&b_2);
  
//   chain[numberOfSamples]->SetName(buffer.c_str());
  
  chainEff[numberOfSamples] = new TChain(treeNameEfficiency.c_str());  
  chainEff[numberOfSamples]->Add(buffer.c_str());
  
  chainEff[numberOfSamples]->SetBranchAddress("XSection",&XSection);
  chainEff[numberOfSamples]->SetBranchAddress("analysisEfficiency",&analysisEfficiency);
  chainEff[numberOfSamples]->SetBranchAddress ("preselection_efficiency",&preselection_efficiency);
  
  
  //   reader[numberOfSamples] = new treeReader((TTree*)(chain[numberOfSamples]));
  numberOfSamples++;
 }
 
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
 std::vector<double>* t_Eta_Reco = new std::vector<double>;
 int t_Cycle_num; //---- 0 = Before, 1 = After
 int t_Indip; //---- 0 = No Indip, 1 = Indip
 
 outTree.Branch("t_pT_Reco","std::vector<double>",&t_pT_Reco);
 outTree.Branch("t_Eta_Reco","std::vector<double>",&t_Eta_Reco);
 outTree.Branch("t_M_Reco",&t_M_Reco,"t_M_Reco/D");
 outTree.Branch("t_Cycle_num",&t_Cycle_num,"t_Cycle_num/I");
 outTree.Branch("t_Indip",&t_Indip,"t_Indip/I");
 
 TH2F hKK_num("hKK_num","hKK_num",myJetCalibrator.getIntPt(),myJetCalibrator.getPtMin(),myJetCalibrator.getPtMax(),myJetCalibrator.getIntEta(),0,myJetCalibrator.getEtaMax()); //---- correction function K(eta) x K(pT) ----
 std::vector<TH2F> hKK_vect;
 std::vector<TH2F> hKK_err_vect;
 
 
 
 
 
 
 
 double start, end;
 
 
 ///===============================
 ///==== Filling JetCalibrator ====

 start = clock();
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::cout << ">>>>> tree::iSample " << iSample << " : " << numberOfSamples << " => " << nameSample[iSample] << std::endl;
  std::cout << ">>>>> tree::entries " << chain[iSample] -> GetEntries()  << std::endl;
  int entryMAX = static_cast<int>(chain[iSample] -> GetEntries());
  
  chainEff[iSample]->GetEntry(analysisStep-1);
  std::cout << ">>>>> tree::XSection = " << XSection << std::endl;
  std::cout << ">>>>> tree::analysisEfficiency = " << analysisEfficiency << std::endl;
  std::cout << ">>>>> tree::preselection_efficiency = " << preselection_efficiency << std::endl;
  
  int entryMAX_temp = fractionLumiMAXcalib * lumiMAX * XSection * preselection_efficiency * analysisEfficiency;
  std::cout << ">>>>> tree::entryMAX = " << entryMAX_temp << std::endl;
  
  if (entryMAX < entryMAX_temp) {
   std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
   std::cerr << ">>>>>>>> ERROR: not enough data available <<<<<<<<" << std::endl;
   std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
  }
  entryMAX = std::min(entryMAX,entryMAX_temp);
  std::cout << ">>>>> tree::entryMAX = " << entryMAX << std::endl;
  
  for(int iEvent = 0 ; iEvent < entryMAX ; ++iEvent){
//    std::cerr << "iEvent = " << iEvent << std::endl;
//    std::cerr << "entries = " << chain[iSample]->GetEntries() << std::endl;
//    std::cerr << "name = " << chain[iSample]->GetName() << std::endl;
//    std::cerr << "chain[" << iSample << "]->GetEntry(" << iEvent << ");" << std::endl;
   
   chain[iSample]->GetEntry(iEvent);
//    std::cerr << "stepAnalysis = " << stepAnalysis << std::endl;
   
   if (stepAnalysis != analysisStep) {
    if ((entryMAX+1) < static_cast<int>(chain[iSample] -> GetEntries())) {
     entryMAX++; //---- I need to go further ONLY if I have enough data ----
    }
    else { //---- throw an exception ----
     std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
     std::cerr << ">>>>>>>> ERROR: not enough data available <<<<<<<<" << std::endl;
     std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
    }
    continue;
   }
   
   if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
   
   std::pair<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector> InputJetPair(*q_1,*q_2);
   
   ///--------------------------------------
   bool okJet = myJetCalibrator.AddJetPair(InputJetPair);
   ///--------------------------------------   
   if (okJet){
    hKK_num.Fill(q_1->Pt(),q_1->Eta());
    hKK_num.Fill(q_2->Pt(),q_2->Eta());
   }
  } //loop over events
 } //loop over samples
 
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
 
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::cout << ">>>>> tree::iSample " << iSample << " : " << numberOfSamples << " => " << nameSample[iSample] << std::endl;
  std::cout << ">>>>> tree::entries " << chain[iSample] -> GetEntries()  << std::endl;
  int entryMAX = static_cast<int>(chain[iSample] -> GetEntries());
  
  chainEff[iSample]->GetEntry(analysisStep-1);
  std::cout << ">>>>> tree::XSection = " << XSection << std::endl;
  std::cout << ">>>>> tree::analysisEfficiency = " << analysisEfficiency << std::endl;
  std::cout << ">>>>> tree::preselection_efficiency = " << preselection_efficiency << std::endl;
  
  int entryMAX_temp = fractionLumiMAXcalib * lumiMAX * XSection * preselection_efficiency * analysisEfficiency;
  std::cout << ">>>>> tree::entryMAX = " << entryMAX_temp << std::endl;
  
  if (entryMAX < entryMAX_temp) {
   std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
   std::cerr << ">>>>>>>> ERROR: not enough data available <<<<<<<<" << std::endl;
   std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
  }
  entryMAX = std::min(entryMAX,entryMAX_temp);
  std::cout << ">>>>> tree::test::entryMAX = " << entryMAX << std::endl;
  
  for(int iEvent = 0 ; iEvent < entryMAX ; ++iEvent){
   chain[iSample]->GetEntry(iEvent);
   
   if (stepAnalysis != analysisStep) {
    if ((entryMAX+1) < static_cast<int>(chain[iSample] -> GetEntries())) {
     entryMAX++; //---- I need to go further ONLY if I have enough data ----
    }
    else { //---- throw an exception ----
     std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
     std::cerr << ">>>>>>>> ERROR: not enough data available <<<<<<<<" << std::endl;
     std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
    }
    continue;
   }
   
   if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
   
   int iPt1 = myJetCalibrator.GetIntPt(q_1->Pt());
   int iEta1 = myJetCalibrator.GetIntEta(q_1->Eta());
   
   int iPt2 = myJetCalibrator.GetIntPt(q_2->Pt());
   int iEta2 = myJetCalibrator.GetIntEta(q_2->Eta());
   
   double M_temp = ((*q_1) + (*q_2)).M();
   //---- data not used, out of range for KK!
   if ((iPt1 != -1) && (iPt2 != -1) && (iEta1 != -1.) && (iEta2 != -1)) {
    M_temp = M_temp * sqrt(myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt1,iEta1)) * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt2,iEta2)));    
    t_M_Reco = M_temp;    
    t_Eta_Reco->push_back(q_1->Eta());
    t_Eta_Reco->push_back(q_2->Eta());
    t_pT_Reco->push_back(q_1->Pt() * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt1,iEta1)));
    t_pT_Reco->push_back(q_2->Pt() * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt2,iEta2))); 
    
    t_Cycle_num = 1; //---- after
    t_Indip = 0; //---- No Indip
    outTree.Fill();   
    t_pT_Reco->clear();
    
    t_Cycle_num = 0; //---- before
    t_Indip = 0; //---- No Indip
    M_temp = ((*q_1) + (*q_2)).M();
    t_M_Reco = M_temp; 
    t_pT_Reco->push_back(q_1->Pt());
    t_pT_Reco->push_back(q_2->Pt()); 
    outTree.Fill();
    
    t_pT_Reco->clear();
    t_Eta_Reco->clear();
   }
  } //loop over events
  maxFilling.push_back(entryMAX);
 } //loop over samples
 
   
   
 ///---- independent sample ----
 std::cout << ">>>>> independent test <<<<<" << std::endl;
 
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::cout << ">>>>> tree::iSample " << iSample << " : " << numberOfSamples << " => " << nameSample[iSample] << std::endl;
  std::cout << ">>>>> tree::entries " << chain[iSample] -> GetEntries()  << std::endl;
  int entryMAX = static_cast<int>(chain[iSample] -> GetEntries());
  int entryMIN = static_cast<int>(chain[iSample] -> GetEntries());
  
  chainEff[iSample]->GetEntry(analysisStep-1);
  std::cout << ">>>>> tree::XSection = " << XSection << std::endl;
  std::cout << ">>>>> tree::analysisEfficiency = " << analysisEfficiency << std::endl;
  std::cout << ">>>>> tree::preselection_efficiency = " << preselection_efficiency << std::endl;
    
  int entryMIN_temp = maxFilling.at(iSample); //fractionLumiMAXcalib * lumiMAX * XSection * preselection_efficiency * analysisEfficiency;
  std::cout << ">>>>> tree::entryMIN = " << entryMIN_temp << std::endl;
  
  int entryMAX_temp = entryMIN_temp + (1.-fractionLumiMAXcalib) * lumiMAX * XSection * preselection_efficiency * analysisEfficiency;
  std::cout << ">>>>> tree::entryMAX = " << entryMAX_temp << std::endl;
  
  
  if (entryMAX < entryMAX_temp) {
   std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
   std::cerr << ">>>>>>>> ERROR: not enough data available <<<<<<<<" << std::endl;
   std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
  }
  entryMAX = std::min(entryMAX,entryMAX_temp);
  entryMIN = std::min(entryMIN,entryMIN_temp);

  std::cout << ">>>>> tree::test::entryMAX = " << entryMAX << std::endl;
  std::cout << ">>>>> tree::test::entryMIN = " << entryMIN << std::endl;
  
  for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent){
   chain[iSample]->GetEntry(iEvent);
   
   if (stepAnalysis != analysisStep) {
    if ((entryMAX+1) < static_cast<int>(chain[iSample] -> GetEntries())) {
     entryMAX++; //---- I need to go further ONLY if I have enough data ----
    }
    else { //---- throw an exception ----
     std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
     std::cerr << ">>>>>>>> ERROR: not enough data available <<<<<<<<" << std::endl;
     std::cerr << ">>>>>>>> ******************************** <<<<<<<<" << std::endl;
    }
    continue;
   }
   
   if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
   
   int iPt1 = myJetCalibrator.GetIntPt(q_1->Pt());
   int iEta1 = myJetCalibrator.GetIntEta(q_1->Eta());
   
   int iPt2 = myJetCalibrator.GetIntPt(q_2->Pt());
   int iEta2 = myJetCalibrator.GetIntEta(q_2->Eta());
   
   double M_temp = ((*q_1) + (*q_2)).M();
//    std::cerr << iPt1 << " " << iEta1 << " " << iPt2 << " " << iEta2 << std::endl;
   //---- data not used, out of range for KK!
   if ((iPt1 != -1) && (iPt2 != -1) && (iEta1 != -1.) && (iEta2 != -1)) {
    M_temp = M_temp * sqrt(myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt1,iEta1)) * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt2,iEta2)));    
    t_M_Reco = M_temp;    
    t_Eta_Reco->push_back(q_1->Eta());
    t_Eta_Reco->push_back(q_2->Eta());
    t_pT_Reco->push_back(q_1->Pt() * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt1,iEta1)));
    t_pT_Reco->push_back(q_2->Pt() * myJetCalibrator.getKK(myJetCalibrator.GetInt(iPt2,iEta2))); 
    
    t_Cycle_num = 1; //---- after
    t_Indip = 1; //---- Yes Indip
    outTree.Fill();   
    t_pT_Reco->clear();
    
    t_Cycle_num = 0; //---- before
    t_Indip = 1; //---- Yes Indip
    M_temp = ((*q_1) + (*q_2)).M();
    t_M_Reco = M_temp; 
    t_pT_Reco->push_back(q_1->Pt());
    t_pT_Reco->push_back(q_2->Pt()); 
    outTree.Fill();
    
    t_pT_Reco->clear();
    t_Eta_Reco->clear();
   }
  } //loop over events
 } //loop over samples
 
 
 
 
 ///==== end test ====
 ///==================
 
  
 for (int iHisto=0; iHisto<static_cast<int>(hKK_vect.size()); iHisto++){
  hKK_vect.at(iHisto).Write();
  hKK_err_vect.at(iHisto).Write();
 } 
 
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 return 0;
}



