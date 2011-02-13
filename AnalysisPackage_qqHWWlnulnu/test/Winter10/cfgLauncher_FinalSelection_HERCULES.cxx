{
 #include "Read.cc"
 
 char *nameSample[10000];
 char *nameHumanReadable[10000];
 char* xsection[10000];

 char nameFileIn[1000] = {"test/Winter10/samples_skimmed.txt"};
 int numberOfSamples =  ReadFile(nameFileIn,nameSample,nameHumanReadable, xsection);
  
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Winter10/dir_cfg_skimmed/NtupleProducer_%s.sh",nameSample[iSample]);
  myfile.open (nameFile);

  myfile << "#!/bin/sh" << std::endl;
  myfile << "source  /gwpool/initcms/root-standalone.sh" << std::endl;
  myfile << "cd /gwpool/users/amassiro/VBF/Analysis/AnalysisPackage_qqHWWlnulnu/" << std::endl;
  myfile << "source scripts/setup.sh" << std::endl;
  myfile << "./bin/NtupleProducer.exe test/Winter10/dir_cfg_skimmed/NtupleProducer_" << nameSample[iSample] << ".cfg" << std::endl;
  myfile << std::endl;

  myfile.close(); 
  
  
  TString Command2Line = Form("chmod +x %s",nameFile);
  gSystem->Exec(Command2Line);

  Command2Line = Form("qsub -V -d ./ -q shortcms %s",nameFile);
  gSystem->Exec(Command2Line);
  
 }
}