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
 
 double pT_RECO_q1;
 double pT_RECO_q2;
 double phi_RECO_q1;
 double phi_RECO_q2;
 double eta_RECO_q1;
 double eta_RECO_q2;
 double eta_RECO_q1_eta_RECO_q2;
 double Deta_RECO_q12;
 double Mjj;

 
 Float_t input_variables_Jet[1000];
 Double_t* MVA_Jet;
 
 TMVA::Reader *TMVAreader_Jet = new TMVA::Reader( "!Color:!Silent" );
 TMVAreader_Jet->AddVariable("pT_RECO_q1",&input_variables_Jet[0]);
 TMVAreader_Jet->AddVariable("pT_RECO_q2",&input_variables_Jet[1]);
 TMVAreader_Jet->AddVariable("eta_RECO_q1",&input_variables_Jet[2]);
 TMVAreader_Jet->AddVariable("eta_RECO_q2",&input_variables_Jet[3]);
 TMVAreader_Jet->AddVariable("eta_RECO_q1_eta_RECO_q2",&input_variables_Jet[4]);
 TMVAreader_Jet->AddVariable("Deta_RECO_q12",&input_variables_Jet[5]);
 TMVAreader_Jet->AddVariable("Mjj",&input_variables_Jet[6]);
 
 
 
 ///==== book MVA Jet ====
 
 std::vector<std::string> stdstrMethod_Jet;
 try {
  stdstrMethod_Jet = gConfigParser -> readStringListOption ("Jet::Methods");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }
 
 
 std::vector<std::string> stdstrAdditionalInputFile_Jet;
 try {
  stdstrAdditionalInputFile_Jet = gConfigParser -> readStringListOption ("Jet::AdditionalInputFiles");
 }
 catch (char const* exceptionString){
  std::cerr << " exception = " << exceptionString << std::endl;
 }
 
 MVA_Jet = new Double_t [stdstrMethod_Jet.size()];
 TBranch *newBranch[1000];
 
 TFile* file = new TFile(inputFile.c_str(), "update");
 TTree *tree = (TTree*)file->Get("outTreeJetLep");
 tree->SetBranchAddress("pT_RECO_q1",&pT_RECO_q1);
 tree->SetBranchAddress("pT_RECO_q2",&pT_RECO_q2);
 tree->SetBranchAddress("eta_RECO_q1",&eta_RECO_q1);
 tree->SetBranchAddress("eta_RECO_q2",&eta_RECO_q2);
 tree->SetBranchAddress("eta_RECO_q1_eta_RECO_q2",&eta_RECO_q1_eta_RECO_q2);
 tree->SetBranchAddress("Deta_RECO_q12",&Deta_RECO_q12);
 tree->SetBranchAddress("Mjj",&Mjj);
 
 ///==== add new branches ====
 for (int iMethod=0; iMethod<stdstrMethod_Jet.size(); iMethod++){
  TString methodName = stdstrMethod_Jet.at(iMethod) + "_method_Jet";
  TString weightfile = Form(stdstrAdditionalInputFile_Jet.at(iMethod).c_str());
  TMVAreader_Jet->BookMVA( methodName, weightfile );
  TString methodName4Tree = stdstrMethod_Jet.at(iMethod) + "_Jet";
  TString methodName4Tree2 = stdstrMethod_Jet.at(iMethod) + "_Jet/D";
  std::cerr << " methodName = " << methodName.Data() << std::endl;
  std::cerr << " methodName4Tree  = " << methodName4Tree.Data() << std::endl;
  std::cerr << " methodName4Tree2 = " << methodName4Tree2.Data() << std::endl;
  newBranch[iMethod] = tree->Branch(methodName4Tree,MVA_Jet+iMethod,methodName4Tree2);
 }
 
 
 ///==== loop ====
 Long64_t nentries = tree->GetEntries();
 
 for (Long64_t iEntry = 0; iEntry < nentries; iEntry++){
  if((iEntry%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEntry << " : " << nentries << std::endl;   
  
  tree->GetEntry(iEntry);
  
  input_variables_Jet[0] = static_cast<Float_t>(pT_RECO_q1);
  input_variables_Jet[1] = static_cast<Float_t>(pT_RECO_q2);
  input_variables_Jet[2] = static_cast<Float_t>(eta_RECO_q1);
  input_variables_Jet[3] = static_cast<Float_t>(eta_RECO_q2);
  input_variables_Jet[4] = static_cast<Float_t>(eta_RECO_q1_eta_RECO_q2);
  input_variables_Jet[5] = static_cast<Float_t>(Deta_RECO_q12);
  input_variables_Jet[6] = static_cast<Float_t>(Mjj);

  for (int iMethod=0; iMethod<stdstrMethod_Jet.size(); iMethod++){
   TString methodName = stdstrMethod_Jet.at(iMethod) + "_method_Jet";
   MVA_Jet[iMethod] = TMVAreader_Jet->EvaluateMVA(methodName);
  }  
  for (int iMethod=0; iMethod<stdstrMethod_Jet.size(); iMethod++){
   newBranch[iMethod]->Fill();
  }
 }
 // save only the new version of the tree
 tree->Write("", TObject::kOverwrite);
}

