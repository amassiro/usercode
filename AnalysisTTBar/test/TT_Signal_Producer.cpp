///===============================================================================================
///==== clone tree signal in order to divide semileptonic decay (e/mu) from other ttbar decay ====
///===============================================================================================


#include "treeReader.h"
#include "ConfigParser.h"
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
 
 std::string outputRootFileName_e = outputRootFileName + "_e.root";
 std::string outputRootFileName_mu = outputRootFileName + "_mu.root";
 std::string outputRootFileName_emu = outputRootFileName + "_emu.root";
 std::string outputRootFileName_other = outputRootFileName + "_other.root";
 
 std::cout << ">>>>> Data::outputRootFileName_e = " << outputRootFileName_e  << std::endl;  
 std::cout << ">>>>> Data::outputRootFileName_mu = " << outputRootFileName_mu  << std::endl;  
 std::cout << ">>>>> Data::outputRootFileName_emu = " << outputRootFileName_emu  << std::endl;  
 std::cout << ">>>>> Data::outputRootFileName_other = " << outputRootFileName_other  << std::endl;  
 
 TFile outputRootFile_emu(outputRootFileName_emu.c_str(), "RECREATE");
 TTree* cloneTree_emu = chain -> CloneTree(0);
 TFile outputRootFile_e(outputRootFileName_e.c_str(), "RECREATE");
 TTree* cloneTree_e = chain -> CloneTree(0);
 TFile outputRootFile_mu(outputRootFileName_mu.c_str(), "RECREATE");
 TTree* cloneTree_mu = chain -> CloneTree(0);
 TFile outputRootFile_other(outputRootFileName_other.c_str(), "RECREATE");
 TTree* cloneTree_other = chain -> CloneTree(0);
 
 
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
 
 outputRootFile_e.cd();
 outputRootFile_e.mkdir(TString(treeNameLeptonFilter.c_str()));
 outputRootFile_e.cd(TString(treeNameLeptonFilter.c_str()));
 hLeptonFilterTotal->Write();
 hLeptonFilterPassed->Write();
 outputRootFile_e.cd();
 outputRootFile_e.mkdir(TString(treeNameJetCounterFilter.c_str()));
 outputRootFile_e.cd(TString(treeNameJetCounterFilter.c_str()));
 hJetCounterFilterTotal->Write();
 hJetCounterFilterPassed->Write();
 outputRootFile_e.cd();
 
 outputRootFile_mu.cd();
 outputRootFile_mu.mkdir(TString(treeNameLeptonFilter.c_str()));
 outputRootFile_mu.cd(TString(treeNameLeptonFilter.c_str()));
 hLeptonFilterTotal->Write();
 hLeptonFilterPassed->Write();
 outputRootFile_mu.cd();
 outputRootFile_mu.mkdir(TString(treeNameJetCounterFilter.c_str()));
 outputRootFile_mu.cd(TString(treeNameJetCounterFilter.c_str()));
 hJetCounterFilterTotal->Write();
 hJetCounterFilterPassed->Write();
 outputRootFile_mu.cd();
 
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
  
  std::vector<int> matchIt;
  int matched = 0;
  
  std::pair<int,int> decayMC = GetMCDecayChannel(mcF1_fromV1_pdgId->at(0),mcF2_fromV1_pdgId->at(0),mcF1_fromV2_pdgId->at(0),mcF2_fromV2_pdgId->at(0));
  
  if (decayMC.first == 2 && (decayMC.second == 1 || decayMC.second == 2)){
   ///==== emu - quark ======== < 2 , 1 >
   ///==== quark - emu ======== < 2 , 2 >
   cloneTree_emu -> Fill();
   if (fabs(mcF1_fromV1_pdgId->at(0)) == 11 || fabs(mcF1_fromV1_pdgId->at(0)) == 12 || fabs(mcF1_fromV2_pdgId->at(0)) == 11 || fabs(mcF1_fromV2_pdgId->at(0)) == 12){
    cloneTree_e -> Fill();
   }
   else {
//     std::cerr << mcF1_fromV1_pdgId->at(0) << " ";
//     std::cerr << mcF2_fromV1_pdgId->at(0) << " ";
//     std::cerr << mcF1_fromV2_pdgId->at(0) << " ";
//     std::cerr << mcF2_fromV2_pdgId->at(0) << " ";
//     std::cerr << std::endl;
    cloneTree_mu -> Fill();
   }
  }
  else {
   ///==== emu - emu ========== < 1 , 1 >
   ///==== emu - tau ========== < 1 , 2 >
   ///==== tau - emu ========== < 1 , 3 >
   ///==== tau - tau ========== < 1 , 4 >
   ///==== emu - quark ======== < 2 , 1 >
   ///==== quark - emu ======== < 2 , 2 >
   ///==== tau - quark ======== < 2 , 3 >
   ///==== quark - tau ======== < 2 , 4 >
   ///==== quark - quark ====== < 3 , -1 >
   cloneTree_other -> Fill();
  }  
 } // loop over the events
 
 
 cloneTree_e   -> AutoSave();
 cloneTree_mu  -> AutoSave();
 cloneTree_emu -> AutoSave();
 cloneTree_other -> AutoSave();
 
 
 
 outputRootFile_emu.cd();
 TH1F eff_emu("eff_emu","eff_emu",1,0,1);
 eff_emu.SetBinContent(1,static_cast<double>(cloneTree_emu->GetEntries()) / (entryMAX - entryMIN));
 eff_emu.Write();
 
 outputRootFile_e.cd();
 TH1F eff_e("eff_e","eff_e",1,0,1);
 eff_e.SetBinContent(1,static_cast<double>(cloneTree_e->GetEntries()) / (entryMAX - entryMIN));
 eff_e.Write();
 
 outputRootFile_mu.cd();
 TH1F eff_mu("eff_mu","eff_mu",1,0,1);
 eff_mu.SetBinContent(1,static_cast<double>(cloneTree_mu->GetEntries()) / (entryMAX - entryMIN));
 eff_mu.Write();
 
 outputRootFile_other.cd();
 TH1F eff_other("eff_other","eff_other",1,0,1);
 eff_other.SetBinContent(1,static_cast<double>(cloneTree_other->GetEntries()) / (entryMAX - entryMIN));
 eff_other.Write();
 
 
 std::cout << "total event = " << entryMAX - entryMIN << std::endl;
 std::cout << "e =     " << static_cast<double>(cloneTree_e->GetEntries()) / (entryMAX - entryMIN) << std::endl;
 std::cout << "mu =    " << static_cast<double>(cloneTree_mu->GetEntries()) / (entryMAX - entryMIN) << std::endl;
 std::cout << "emu =   " << static_cast<double>(cloneTree_emu->GetEntries()) / (entryMAX - entryMIN) << std::endl;
 std::cout << "other = " << static_cast<double>(cloneTree_other->GetEntries()) / (entryMAX - entryMIN) << std::endl;
 
 
 return 0;
}
