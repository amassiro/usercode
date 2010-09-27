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
#include "qqHWWlnulnuUtils.h"

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
 
 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 int pdgId_RECO_l1;
 int pdgId_RECO_l2;
 double pT_RECO_l1;
 double pT_RECO_l2;
 double eta_RECO_l1;
 double eta_RECO_l2;
 double eta_RECO_l1_eta_RECO_l2;
 double Deta_RECO_l12;
 double Dphi_RECO_l12;
 double Mll;
 double charge_RECO_l1_charge_RECO_l2;
 
 Float_t input_variables_Lep[1000];
 Double_t* MVA_Lep;
 
 
 
 TMVA::Reader *TMVAreader_Lep = new TMVA::Reader( "!Color:!Silent" );
 TMVAreader_Lep->AddVariable("pdgId_RECO_l1",&input_variables_Lep[0]);
 TMVAreader_Lep->AddVariable("pdgId_RECO_l2",&input_variables_Lep[1]);
 TMVAreader_Lep->AddVariable("pT_RECO_l1",&input_variables_Lep[2]);
 TMVAreader_Lep->AddVariable("pT_RECO_l2",&input_variables_Lep[3]);
 TMVAreader_Lep->AddVariable("eta_RECO_l1",&input_variables_Lep[4]);
 TMVAreader_Lep->AddVariable("eta_RECO_l2",&input_variables_Lep[5]);
 TMVAreader_Lep->AddVariable("eta_RECO_l1_eta_RECO_l2",&input_variables_Lep[6]);
 TMVAreader_Lep->AddVariable("Deta_RECO_l12",&input_variables_Lep[7]);
 TMVAreader_Lep->AddVariable("Dphi_RECO_l12",&input_variables_Lep[8]);
 TMVAreader_Lep->AddVariable("Mll",&input_variables_Lep[9]);
 TMVAreader_Lep->AddVariable("charge_RECO_l1_charge_RECO_l2",&input_variables_Lep[10]);
 
 
 ///==== book MVA Lepton ====
 
 
 std::vector<std::string> stdstrMethod_Lep;
 try {
  stdstrMethod_Lep = gConfigParser -> readStringListOption ("Lepton::Methods");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }
 
 std::vector<std::string> stdstrAdditionalInputFile_Lep;
 try {
  stdstrAdditionalInputFile_Lep = gConfigParser -> readStringListOption ("Lepton::AdditionalInputFiles");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }
 
 MVA_Lep = new Double_t [stdstrMethod_Lep.size()];
 TBranch *newBranch[1000];
 
 TFile* file = new TFile(inputFile.c_str(), "update");
 TTree *tree = (TTree*)file->Get("outTreeJetLep");
 tree->SetBranchAddress("pdgId_RECO_l1",&pdgId_RECO_l1);
 tree->SetBranchAddress("pdgId_RECO_l2",&pdgId_RECO_l2);
 tree->SetBranchAddress("pT_RECO_l1",&pT_RECO_l1);
 tree->SetBranchAddress("pT_RECO_l2",&pT_RECO_l2);
 tree->SetBranchAddress("eta_RECO_l1",&eta_RECO_l1);
 tree->SetBranchAddress("eta_RECO_l2",&eta_RECO_l2);
 tree->SetBranchAddress("eta_RECO_l1_eta_RECO_l2",&eta_RECO_l1_eta_RECO_l2);
 tree->SetBranchAddress("Deta_RECO_l12",&Deta_RECO_l12);
 tree->SetBranchAddress("Dphi_RECO_l12",&Dphi_RECO_l12);
 tree->SetBranchAddress("Mll",&Mll);
 tree->SetBranchAddress("charge_RECO_l1_charge_RECO_l2",&charge_RECO_l1_charge_RECO_l2);
 
 ///==== add new branches ====
 for (int iMethod=0; iMethod<stdstrMethod_Lep.size(); iMethod++){
  TString methodName = stdstrMethod_Lep.at(iMethod) + "_method_Lep";
  TString weightfile = Form(stdstrAdditionalInputFile_Lep.at(iMethod).c_str());
  TMVAreader_Lep->BookMVA( methodName, weightfile );
  
  TString methodName4Tree = stdstrMethod_Lep.at(iMethod) + "_Lep";
  TString methodName4Tree2 = stdstrMethod_Lep.at(iMethod) + "_Lep/D";
  std::cerr << " methodName  = " << methodName.Data() << std::endl;
  std::cerr << " methodName4Tree  = " << methodName4Tree.Data() << std::endl;
  std::cerr << " methodName4Tree2 = " << methodName4Tree2.Data() << std::endl;  
  newBranch[iMethod] = tree->Branch(methodName4Tree,MVA_Lep+iMethod,methodName4Tree2);
 } 
 
 ///==== loop ====
 Long64_t nentries = tree->GetEntries();
 
 for (Long64_t iEntry = 0; iEntry < nentries; iEntry++){
  if((iEntry%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEntry << " : " << nentries << std::endl;   
  
  tree->GetEntry(iEntry);
  
  input_variables_Lep[0] = static_cast<float>( pdgId_RECO_l1 );
  input_variables_Lep[1] = static_cast<float>( pdgId_RECO_l2 );
  input_variables_Lep[2] = static_cast<float>( pT_RECO_l1 );
  input_variables_Lep[3] = static_cast<float>( pT_RECO_l2 );
  input_variables_Lep[4] = static_cast<float>( eta_RECO_l1 );
  input_variables_Lep[5] = static_cast<float>( eta_RECO_l2 );
  input_variables_Lep[6] = static_cast<float>( eta_RECO_l1_eta_RECO_l2 );
  input_variables_Lep[7] = static_cast<float>( Deta_RECO_l12 );
  input_variables_Lep[8] = static_cast<float>( Dphi_RECO_l12 );
  input_variables_Lep[9] = static_cast<float>( Mll );
  input_variables_Lep[10] = static_cast<float>( charge_RECO_l1_charge_RECO_l2 );
  
  for (int iMethod=0; iMethod<stdstrMethod_Lep.size(); iMethod++){
   TString methodName = stdstrMethod_Lep.at(iMethod) + "_method_Lep";
   MVA_Lep[iMethod] = TMVAreader_Lep->EvaluateMVA(methodName); 
  }
  for (int iMethod=0; iMethod<stdstrMethod_Lep.size(); iMethod++){
   newBranch[iMethod]->Fill();
  }
 }
 // save only the new version of the tree
 tree->Write("", TObject::kOverwrite);
}





