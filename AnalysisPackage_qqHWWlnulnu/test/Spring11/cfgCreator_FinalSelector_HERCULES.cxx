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
  myfile << "inputFile = /gwteray/users/amassiro/VBF/Spring11_May4_MCandDATA/" << nameSample[iSample] << "/Jets2Lepton2_MiBiCommonNTOneLeptonTwoJetsAK5PF_TOT.root" << std::endl;
  myfile << "  inFileNameJSON = /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions11/7TeV/Prompt//Cert_160404-163369_7TeV_PromptReco_Collisions11_JSON.txt" << std::endl;

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
  myfile << "[Output]" << std::endl;
  myfile << "outFileName = //gwpool/users/amassiro/VBF/Analysis/Spring11/AnalysisPackage_qqHWWlnulnu/output_Spring11/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;
  myfile << std::endl;
  
  myfile.close(); 
 }
 
}


