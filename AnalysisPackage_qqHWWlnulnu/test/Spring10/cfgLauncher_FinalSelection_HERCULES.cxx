{
 char *nameSample[1000];
 char *nameSamplePrefix[1000];
 char *nameSampleTree[1000];
 
 char* xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("test/Spring10/samples.txt");
 std::string buffer;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){
    std::stringstream line( buffer );       
    nameSample[numberOfSamples] = new char [1000];
    line >> nameSample[numberOfSamples]; 
    std::cout << nameSample[numberOfSamples] << " ";
    
    nameSamplePrefix[numberOfSamples] = new char [1000];
    line >> nameSamplePrefix[numberOfSamples];
    
    nameSampleTree[numberOfSamples] = new char [1000];
    line >> nameSampleTree[numberOfSamples];
    
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
  sprintf(nameFile,"dir_cfg/do_FinalSelection_%s.sh",nameSample[iSample]);
  myfile.open (nameFile);

  myfile << "#!/bin/sh" << std::endl;
  myfile << "cd /gwpool/users/amassiro/VBF/Releases/CMSSW_3_5_6/src/" << std::endl;
  myfile << "source /gwpool/initcms/slc5-cmssw.sh" << std::endl;
  myfile << "cmsenv" << std::endl;
  myfile << "cd /gwpool/users/amassiro/VBF/Analysis/AnalysisPackage_qqHWWlnulnu/" << std::endl;
  myfile << "source scripts/setup.sh" << std::endl;
  myfile << "./bin/FinalSelection_Producer.exe test/Spring10/dir_cfg/FinalSelection_" << nameSample[iSample] << ".cfg" << std::endl;
  myfile << std::endl;

  myfile.close(); 
  
  
  TString Command2Line = Form("chmod +x %s",nameFile);
  gSystem->Exec(Command2Line);

  Command2Line = Form("qsub -V -d ./ -q production %s",nameFile);
  gSystem->Exec(Command2Line);
  
 }
}
