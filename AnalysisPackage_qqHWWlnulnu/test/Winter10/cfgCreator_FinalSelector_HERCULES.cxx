{
 ///==== cfg creator ====
 
 #include <iomanip>
 #include <string>
 #include "Read.cc"
 
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsection[1000];
 
 char nameFileIn[1000] = {"test/Winter10/samples_skimmed.txt"};
 
 int numberOfSamples =  ReadFile(nameFileIn,nameSample,nameHumanReadable, xsection);
 
 system("mkdir test/Winter10/dir_cfg_skimmed");
 system ("mkdir /gwpool/users/amassiro/VBF/Analysis/AnalysisPackage_qqHWWlnulnu/output_Winter10");
 
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Winter10/dir_cfg_skimmed/NtupleProducer_%s.cfg",nameSample[iSample]);
  myfile.open (nameFile);
  
  myfile << std::fixed;
  myfile << std::setprecision(20);
  myfile << "[Input]" << std::endl;
  myfile << "treeName = SimpleNtuple " << std::endl;
  myfile << "inputFile = /gwterax1/users/amassiro/VBF/Fall10_Feb11MCandDATA/" << nameSample[iSample] << "/Jets2Lepton2_MiBiCommonNTOneLeptonTwoJetsPFlow_TOT.root" << std::endl;
  myfile << "  inFileNameJSON = /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions10/7TeV/Reprocessing/Cert_136033-149442_7TeV_Dec22ReReco_Collisions10_CMSSWConfig.txt " << std::endl;

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
  myfile << "OutFileNameEfficiencies = /gwpool/users/amassiro/VBF/Analysis/AnalysisPackage_qqHWWlnulnu/output_Winter10/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;
  myfile << std::endl;
  
  myfile.close(); 
 }
 
}


