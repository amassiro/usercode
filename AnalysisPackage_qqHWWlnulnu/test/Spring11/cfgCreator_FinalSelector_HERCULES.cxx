{
 ///==== cfg creator ====
 
 #include <iomanip>
 #include <string>
 #include "Read.cc"
 
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsection[1000];
 
 char nameFileIn[1000] = {"test/Spring11/samples_skimmed.txt"};
 
 int numberOfSamples =  ReadFile(nameFileIn,nameSample,nameHumanReadable, xsection);
 
 system("mkdir test/Spring11/dir_cfg_skimmed");
 system ("mkdir /gwpool/users/amassiro/VBF/Analysis/Spring11/AnalysisPackage_qqHWWlnulnu/output_Spring11");
 
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Spring11/dir_cfg_skimmed/NtupleProducer_%s.cfg",nameSample[iSample]);
  myfile.open (nameFile);
  
  myfile << std::fixed;
  myfile << std::setprecision(20);
  myfile << "[Input]" << std::endl;
  myfile << "treeName = SimpleNtuple " << std::endl;
  myfile << "inputFile = /gwteray/users/amassiro/VBF/Spring11_May12_MCandDATA_NoVBFCut/" << nameSample[iSample] << "/Jets2Lepton2_MiBiCommonNTOneLeptonTwoJetsAK5PF_TOT.root" << std::endl;
//   myfile << "inputFile = /gwteray/users/amassiro/VBF/Spring11_May12_MCandDATA_LooseVBFCut/" << nameSample[iSample] << "/Jets2Lepton2_MiBiCommonNTOneLeptonTwoJetsAK5PF_TOT.root" << std::endl;
//  myfile << "inputFile = /gwteray/users/amassiro/VBF/Spring11_May9_MCandDATA_NoVBFCut/" << nameSample[iSample] << "/Jets2Lepton2_MiBiCommonNTOneLeptonTwoJetsAK5PF_TOT.root" << std::endl;
// myfile << "  inFileNameJSON = /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions11/7TeV/Prompt//Cert_160404-163369_7TeV_PromptReco_Collisions11_JSON.txt" << std::endl;
//  myfile << "  inFileNameJSON = /gwpool/users/amassiro/VBF/Analysis/Spring11/AnalysisPackage_qqHWWlnulnu/data/Cert_160404-163757_7TeV_PromptReco_Collisions11_JSON.txt" << std::endl;
//    myfile << "  inFileNameJSON = /gwpool/users/amassiro/VBF/Analysis/Spring11/AnalysisPackage_qqHWWlnulnu/data/Cert_160404-163757_7TeV_PromptReco_Collisions11_JSON.txt" << std::endl;
//    myfile << "  inFileNameJSON = /gwpool/users/amassiro/VBF/Analysis/Spring11/AnalysisPackage_qqHWWlnulnu/data/AND2.json" << std::endl;
//    myfile << "  inFileNameJSON = /gwpool/users/amassiro/VBF/Analysis/Spring11/AnalysisPackage_qqHWWlnulnu/data/newAND2.json" << std::endl;        
    myfile << "  inFileNameJSON = /gwpool/users/amassiro/VBF/Analysis/Spring11/AnalysisPackage_qqHWWlnulnu/data/OR.json" << std::endl;        

  char toDo[1000];
  sprintf(toDo,"double xsec = %s",xsection[iSample]);
  gROOT->ProcessLine(toDo);
  myfile << "inputXSection = " << xsec << std::endl;
  myfile << "histoNameEvents = events" << std::endl;
  myfile << std::endl;
  myfile << "entryMIN = 0 " << std::endl;
  myfile << "entryMAX = -1 " << std::endl;
  myfile << "entryMOD = 1000 " << std::endl;
  myfile << "nStepToDo = 5 " << std::endl;
  myfile << std::endl;
  
  myfile << "[Options]" << std::endl;
  myfile << "kind = 1" << std::endl;
 // myfile << "kind = -1" << std::endl;
  myfile << std::endl;
  
  
  
  myfile <<  "[Selection]" << std::endl;

  myfile <<  "# VBTF WP90" << std::endl;

  myfile <<  "eleCombinedIsoBarrel   = 0.085" << std::endl;
  myfile <<  "elesigmaIetaIetaBarrel = 0.01" << std::endl;
  myfile <<  "eledPhiBarrel = 0.071" << std::endl;
  myfile <<  "eledEtaBarrel = 0.007" << std::endl;

  myfile <<  "eleCombinedIsoEndcap   = 0.051" << std::endl;
  myfile <<  "elesigmaIetaIetaEndcap = 0.031" << std::endl;
  myfile <<  "eledPhiEndcap = 0.047" << std::endl;
  myfile <<  "eledEtaEndcap = 0.011" << std::endl;

  myfile <<  "#conversion rejection" << std::endl;
  myfile <<  "# electrons_mishits" << std::endl;
  myfile <<  "# electrons_dist" << std::endl;
  myfile <<  "# electrons_dcot" << std::endl;

  myfile <<  "elemishits = 0" << std::endl;
  myfile <<  "eledist    = 0.02" << std::endl;
  myfile <<  "eledcot    = 0.02" << std::endl;

  myfile <<  "#Impact parameter" << std::endl;

  myfile <<  "# electrons_dz_PV" << std::endl;
  myfile <<  "# electrons_dxy_PV" << std::endl;

  myfile <<  "eledzPV  = 0.05" << std::endl;
  myfile <<  "eledxyPV = 0.05" << std::endl;

  myfile <<  "# muon" << std::endl;
 
  myfile <<  "muCombinedIso = 0.15" << std::endl;
  myfile <<  "muChi2Ndof    = 10" << std::endl;
  
  myfile <<  "muValidTrackerHits = 10" << std::endl;
  myfile <<  "muValidMuonHits    = 0" << std::endl;
  
  myfile <<  "mutracker    = 1" << std::endl;
  myfile <<  "mustandalone = 1" << std::endl;
  myfile <<  "muglobal     = 1" << std::endl;
  
  myfile <<  "mudzPV     = 0.05" << std::endl;
  myfile <<  "mudxyPV    = 0.01" << std::endl;
 
  
  myfile << std::endl;
  myfile << std::endl;
  
  myfile << "[Output]" << std::endl;
//  myfile << "outFileName = /gwteray/users/amassiro/VBFPlainRoot/May142011LooseVBF_80WP/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;
//  myfile << "outFileName = /gwteray/users/amassiro/VBFPlainRoot/May142011LooseVBF_90WP/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;

//  myfile << "outFileName = /gwteray/users/amassiro/VBFPlainRoot/May142011NoVBF_80WP/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;
 myfile << "outFileName = /gwteray/users/amassiro/VBFPlainRoot/June142011NoVBF_90WP/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;

 // myfile << "outFileName = /gwteray/users/amassiro/VBFPlainRoot/May142011NoVBF_90WP_HLT/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;

 //myfile << "outFileName = /gwteray/users/amassiro/VBFPlainRoot/May142011NoVBF_90WP_JES_UP/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;
 // myfile << "outFileName = /gwteray/users/amassiro/VBFPlainRoot/May142011NoVBF_90WP_JES_DOWN/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;
    
  myfile << std::endl;
  
  myfile.close(); 
 }
 
}


