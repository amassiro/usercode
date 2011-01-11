{


 char *nameSample[1000];
 char *nameSampleFile[1000];
 char* xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("test/Spring10/samples_skimmed.txt");
 std::string buffer;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer[0] != '#'){
    std::stringstream line( buffer );       
    nameSample[numberOfSamples] = new char [1000];
    line >> nameSample[numberOfSamples]; 
    std::cout << nameSample[numberOfSamples] << " ";
    
    nameSampleFile[numberOfSamples] = new char [1000];
    line >> nameSampleFile[numberOfSamples]; 
    std::cout << nameSampleFile[numberOfSamples] << " ";

    xsection[numberOfSamples] = new char [1000];
    line >> xsection[numberOfSamples]; 
    std::cout << xsection[numberOfSamples] << " ";
    std::cout << std::endl;
    numberOfSamples++;
   } 
  }
 }
 
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Spring10/dir_cfg_skimmed/NtupleProducer_%s.sh",nameSample[iSample]);
  myfile.open (nameFile);

  myfile << "#!/bin/sh" << std::endl;
  myfile << "cd /gwpool/users/amassiro/VBF/Releases/CMSSW_3_5_6/src/" << std::endl;
  myfile << "source /gwpool/initcms/slc5-cmssw.sh" << std::endl;
  myfile << "cmsenv" << std::endl;
  myfile << "cd /gwpool/users/amassiro/VBF/Analysis/AnalysisPackage_qqHWWlnulnu/" << std::endl;
  myfile << "source scripts/setup.sh" << std::endl;
  myfile << "./bin/NtupleProducer.exe test/Spring10/dir_cfg_skimmed/NtupleProducer_" << nameSample[iSample] << ".cfg" << std::endl;
  myfile << std::endl;

  myfile.close(); 
  
  
  TString Command2Line = Form("chmod +x %s",nameFile);
  gSystem->Exec(Command2Line);

  Command2Line = Form("qsub -V -d ./ -q shortcms %s",nameFile);
  gSystem->Exec(Command2Line);
  
 }
}
