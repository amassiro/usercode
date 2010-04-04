///============================================================================================
///==== clone tree signal in order to divide semileptonic decay (e/mu) from other WW decay ====
///============================================================================================


#include "treeReader.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"
#include "qqHWWlnulnuUtils.h"



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
 
 std::string treeName = gConfigParser -> readStringOption("Input::treeName");
 
 int entryMAX = gConfigParser -> readIntOption("Input::entryMAX");
 int entryMIN = gConfigParser -> readIntOption("Input::entryMIN");
 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 std::cout << ">>>>> Input::entryMIN  " << entryMIN  << std::endl;  
 std::cout << ">>>>> Input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> Input::entryMOD  " << entryMOD  << std::endl;  
 
 std::string inputFile = gConfigParser -> readStringOption("Input::inputFile");
 std::cout << ">>>>> Input::inputFile" << inputFile  << std::endl;  
 
 TChain* chain = new TChain(treeName.c_str());
 chain->Add(inputFile.c_str());
 treeReader reader((TTree*)(chain));
 
 // Open output root file for clone tree
 std::string outputRootFileName;
 std::string str (".root");
 int found;
 found=inputFile.find(str);
 if (found!=std::string::npos) {
  outputRootFileName = inputFile.substr(0,found);
 }
 std::cout << ">>>>> Data::outputFileTemplate = " << outputRootFileName  << std::endl;  
 
 std::string outputRootFileName_ee = outputRootFileName + "_ee.root";
 std::string outputRootFileName_emu = outputRootFileName + "_emu.root";
 std::string outputRootFileName_mumu = outputRootFileName + "_mumu.root";
 std::string outputRootFileName_other = outputRootFileName + "_other.root";
 
 std::cout << ">>>>> Data::outputRootFileName_ee = " << outputRootFileName_ee  << std::endl;  
 std::cout << ">>>>> Data::outputRootFileName_emu = " << outputRootFileName_emu  << std::endl;  
 std::cout << ">>>>> Data::outputRootFileName_mumu = " << outputRootFileName_mumu  << std::endl;  
 std::cout << ">>>>> Data::outputRootFileName_other = " << outputRootFileName_other  << std::endl;  

 std::string treeNameDir = gConfigParser -> readStringOption("Input::treeNameDir");
 
 TFile outputRootFile_emu(outputRootFileName_emu.c_str(), "RECREATE");
 outputRootFile_emu.mkdir(TString(treeNameDir.c_str()));
 outputRootFile_emu.cd(TString(treeNameDir.c_str()));
 TTree* cloneTree_emu = chain -> CloneTree(0);
 outputRootFile_emu.cd();
 
 TFile outputRootFile_ee(outputRootFileName_ee.c_str(), "RECREATE");
 outputRootFile_ee.mkdir(TString(treeNameDir.c_str()));
 outputRootFile_ee.cd(TString(treeNameDir.c_str()));
 TTree* cloneTree_ee = chain -> CloneTree(0);
 outputRootFile_ee.cd();
  
 TFile outputRootFile_mumu(outputRootFileName_mumu.c_str(), "RECREATE");
 outputRootFile_mumu.mkdir(TString(treeNameDir.c_str()));
 outputRootFile_mumu.cd(TString(treeNameDir.c_str()));
 TTree* cloneTree_mumu = chain -> CloneTree(0);
 outputRootFile_mumu.cd();
 
 TFile outputRootFile_other(outputRootFileName_other.c_str(), "RECREATE");
 outputRootFile_other.mkdir(TString(treeNameDir.c_str()));
 outputRootFile_other.cd(TString(treeNameDir.c_str()));
 TTree* cloneTree_other = chain -> CloneTree(0);
 outputRootFile_other.cd();
 
 
 
 std::string treeNameLeptonFilter      = gConfigParser -> readStringOption("Input::treeNameLeptonFilter");
 std::string treeNameJetCounterFilter  = gConfigParser -> readStringOption("Input::treeNameJetCounterFilter");
 std::cout << ">>>>> Input::inputFile                 " << inputFile  << std::endl;  
 std::cout << ">>>>> Input::treeNameLeptonFilter      " << treeNameLeptonFilter  << std::endl;  
 std::cout << ">>>>> Input::treeNameJetCounterFilter  " << treeNameJetCounterFilter  << std::endl;  
 TFile File(inputFile.c_str()) ;
 TH1F* hLeptonFilterTotal = (TH1F*) File.Get(TString(treeNameLeptonFilter.c_str()) + "/totalEvents");
 TH1F* hLeptonFilterPassed = (TH1F*) File.Get(TString(treeNameLeptonFilter.c_str()) + "/passedEvents");  
 TH1F* hJetCounterFilterTotal = (TH1F*) File.Get(TString(treeNameJetCounterFilter.c_str()) + "/totalEvents");
 TH1F* hJetCounterFilterPassed = (TH1F*) File.Get(TString(treeNameJetCounterFilter.c_str()) + "/passedEvents"); 
 
 outputRootFile_ee.cd();
 outputRootFile_ee.mkdir(TString(treeNameLeptonFilter.c_str()));
 outputRootFile_ee.cd(TString(treeNameLeptonFilter.c_str()));
 hLeptonFilterTotal->Write();
 hLeptonFilterPassed->Write();
 outputRootFile_ee.cd();
 outputRootFile_ee.mkdir(TString(treeNameJetCounterFilter.c_str()));
 outputRootFile_ee.cd(TString(treeNameJetCounterFilter.c_str()));
 hJetCounterFilterTotal->Write();
 hJetCounterFilterPassed->Write();
 outputRootFile_ee.cd();
 
 outputRootFile_mumu.cd();
 outputRootFile_mumu.mkdir(TString(treeNameLeptonFilter.c_str()));
 outputRootFile_mumu.cd(TString(treeNameLeptonFilter.c_str()));
 hLeptonFilterTotal->Write();
 hLeptonFilterPassed->Write();
 outputRootFile_mumu.cd();
 outputRootFile_mumu.mkdir(TString(treeNameJetCounterFilter.c_str()));
 outputRootFile_mumu.cd(TString(treeNameJetCounterFilter.c_str()));
 hJetCounterFilterTotal->Write();
 hJetCounterFilterPassed->Write();
 outputRootFile_mumu.cd();
 
 outputRootFile_emu.cd();
 outputRootFile_emu.mkdir(TString(treeNameLeptonFilter.c_str()));
 outputRootFile_emu.cd(TString(treeNameLeptonFilter.c_str()));
 hLeptonFilterTotal->Write();
 hLeptonFilterPassed->Write();
 outputRootFile_emu.cd();
 outputRootFile_emu.mkdir(TString(treeNameJetCounterFilter.c_str()));
 outputRootFile_emu.cd(TString(treeNameJetCounterFilter.c_str()));
 hJetCounterFilterTotal->Write();
 hJetCounterFilterPassed->Write();
 outputRootFile_emu.cd();
 
 outputRootFile_other.cd();
 outputRootFile_other.mkdir(TString(treeNameLeptonFilter.c_str()));
 outputRootFile_other.cd(TString(treeNameLeptonFilter.c_str()));
 hLeptonFilterTotal->Write();
 hLeptonFilterPassed->Write();
 outputRootFile_other.cd();
 outputRootFile_other.mkdir(TString(treeNameJetCounterFilter.c_str()));
 outputRootFile_other.cd(TString(treeNameJetCounterFilter.c_str()));
 hJetCounterFilterTotal->Write();
 hJetCounterFilterPassed->Write();
 outputRootFile_other.cd();
 
 
 double start, end;
 if (entryMAX == -1) entryMAX = reader.GetEntries();
 else if (reader.GetEntries() < entryMAX) entryMAX = reader.GetEntries();
 
 std::vector<ROOT::Math::XYZTVector>* mcF_fromV1 = new std::vector<ROOT::Math::XYZTVector>;
 std::vector<ROOT::Math::XYZTVector>* mcF_fromV2 = new std::vector<ROOT::Math::XYZTVector>;
 
 start = clock();
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent) {
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
  
  mcF_fromV1->clear();
  mcF_fromV2->clear();
  mcF_fromV1->push_back(mcF1_fromV1->at(0));
  mcF_fromV1->push_back(mcF2_fromV1->at(0));
  mcF_fromV2->push_back(mcF1_fromV2->at(0));
  mcF_fromV2->push_back(mcF2_fromV2->at(0));
  
  
  int f11 = fabs(mcF1_fromV1_pdgId->at(0));
  int f12 = fabs(mcF2_fromV1_pdgId->at(0));
  int f21 = fabs(mcF1_fromV2_pdgId->at(0));
  int f22 = fabs(mcF2_fromV2_pdgId->at(0));
  

  if (f11 >= 11 && f11 <= 12 && f21 >= 11 && f21 <= 12) {
   cloneTree_ee -> Fill();
  }
  else if (f11 >= 13 && f11 <= 14 && f21 >= 13 && f21 <= 14) {
   cloneTree_mumu -> Fill();
  }
  else if ((f11 >= 11 && f11 <= 12 && f21 >= 13 && f21 <= 14) || (f11 >= 13 && f11 <= 14 && f21 >= 11 && f21 <= 12)){
   cloneTree_emu -> Fill();
  }
  else {
   cloneTree_other -> Fill();
  }
  
 } // loop over the events
 
 
 cloneTree_ee    -> AutoSave();
 cloneTree_emu   -> AutoSave();
 cloneTree_mumu  -> AutoSave();
 cloneTree_other -> AutoSave();
 
 
 
 outputRootFile_emu.cd();
 TH1F eff_emu("eff_emu","eff_emu",1,0,1);
 eff_emu.SetBinContent(1,static_cast<double>(cloneTree_emu->GetEntries()) / (entryMAX - entryMIN));
 eff_emu.Write();
 
 outputRootFile_ee.cd();
 TH1F eff_ee("eff_ee","eff_ee",1,0,1);
 eff_ee.SetBinContent(1,static_cast<double>(cloneTree_ee->GetEntries()) / (entryMAX - entryMIN));
 eff_ee.Write();
 
 outputRootFile_mumu.cd();
 TH1F eff_mumu("eff_mumu","eff_mumu",1,0,1);
 eff_mumu.SetBinContent(1,static_cast<double>(cloneTree_mumu->GetEntries()) / (entryMAX - entryMIN));
 eff_mumu.Write();
 
 outputRootFile_other.cd();
 TH1F eff_other("eff_other","eff_other",1,0,1);
 eff_other.SetBinContent(1,static_cast<double>(cloneTree_other->GetEntries()) / (entryMAX - entryMIN));
 eff_other.Write();
 
 
 std::cout << "total event = " << entryMAX - entryMIN << std::endl;
 std::cout << "ee =      " << static_cast<double>(cloneTree_ee->GetEntries()) / (entryMAX - entryMIN) << std::endl;
 std::cout << "mumu =    " << static_cast<double>(cloneTree_mumu->GetEntries()) / (entryMAX - entryMIN) << std::endl;
 std::cout << "emu =     " << static_cast<double>(cloneTree_emu->GetEntries()) / (entryMAX - entryMIN) << std::endl;
 std::cout << "other =   " << static_cast<double>(cloneTree_other->GetEntries()) / (entryMAX - entryMIN) << std::endl;
 
 
 return 0;
}
