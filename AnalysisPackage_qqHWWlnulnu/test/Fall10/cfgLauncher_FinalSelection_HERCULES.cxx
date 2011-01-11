{

 char *nameSample[10000];
 char *nameHumanReadable[10000];
 char* xsection[10000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("test/Fall10/samples_skimmed.txt");
 std::string buffer;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer[0] != '#'){
    std::stringstream line( buffer );       
    nameSample[numberOfSamples] = new char [10000];
    line >> nameSample[numberOfSamples]; 
    std::cout << nameSample[numberOfSamples] << " ";
    
    xsection[numberOfSamples] = new char [10000];
    line >> xsection[numberOfSamples]; 
    std::cout << xsection[numberOfSamples] << " ";
    
    nameHumanReadable[numberOfSamples] = new char [10000];
    line >> nameHumanReadable[numberOfSamples]; 
    std::cout << nameHumanReadable[numberOfSamples] << " ";

    std::cout << std::endl;
    numberOfSamples++;
   } 
  }
 }

 
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Fall10/dir_cfg_skimmed/NtupleProducer_%s.sh",nameSample[iSample]);
  myfile.open (nameFile);

  myfile << "#!/bin/sh" << std::endl;
  myfile << "source  /gwpool/initcms/root-standalone.sh" << std::endl;
  myfile << "cd /gwpool/users/amassiro/VBF/Analysis/AnalysisPackage_qqHWWlnulnu/" << std::endl;
  myfile << "source scripts/setup.sh" << std::endl;
  myfile << "./bin/NtupleProducer.exe test/Fall10/dir_cfg_skimmed/NtupleProducer_" << nameSample[iSample] << ".cfg" << std::endl;
  myfile << std::endl;

  myfile.close(); 
  
  
  TString Command2Line = Form("chmod +x %s",nameFile);
  gSystem->Exec(Command2Line);

  Command2Line = Form("qsub -V -d ./ -q shortcms %s",nameFile);
  gSystem->Exec(Command2Line);
  
 }
}
