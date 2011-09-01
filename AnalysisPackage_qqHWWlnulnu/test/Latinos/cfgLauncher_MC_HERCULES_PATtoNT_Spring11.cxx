{
///==== cfg launcher ====
 
 #include <iomanip>
 #include <string>
 #include "Read.cc"
 
 char    inputDirectory[1000] = {"/gwteraz/users/amassiro/VBF/Spring11_25July_MC_PATLatinos/"};  
 
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsection[1000];
 
 char nameFileIn[1000] = {"test/Latinos/samples_MC_Spring11.txt"};
 
 int numberOfSamples =  ReadFile(nameFileIn,nameSample,nameHumanReadable, xsection);
 
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::string name_samples = nameHumanReadable[iSample];
  if (name_samples  == "DATA") continue;

  TString toDoTemp = Form ("ls  %s/%s | wc -l &> ___temp.txt", inputDirectory, nameSample[iSample]);
  system (toDoTemp.Data());
  
 std::ifstream indata;
 indata.open("___temp.txt"); // opens the file
 int nFile;
 while ( !indata.eof() ) { // keep reading until end-of-file
  indata >> nFile;
  std::cout << "Number read is " << nFile << std::endl;
}
 indata.close();

 for (int iFile = 0; iFile < nFile; iFile++) {
  
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Latinos/dir_cfg_skimmed_MC_Spring11/NtupleProducerPATtoNT_%s_%d.sh",nameSample[iSample],iFile+1);
  myfile.open (nameFile);

  myfile << "#!/bin/sh" << std::endl;
  myfile << "source  /gwpool/initcms/root-standalone.sh" << std::endl;
  myfile << "cd /gwpool/users/amassiro/VBF/Analysis/Latinos/AnalysisPackage_qqHWWlnulnu/" << std::endl;
  myfile << "source scripts/setup.sh" << std::endl;
  myfile << "./bin/NtupleProducerFromPATtoNT.exe    test/Latinos/dir_cfg_skimmed_MC_Spring11/NtupleProducerPATtoNT_" << nameSample[iSample] << "_" << iFile+1 << ".cfg" << std::endl;
  myfile << std::endl;
  myfile.close(); 
   
  TString Command2Line = Form("chmod +x %s",nameFile);
  gSystem->Exec(Command2Line);


  if (iFile%2)  Command2Line = Form("qsub -V -d ./ -q longcms %s",nameFile);
  else   Command2Line = Form("qsub -V -d ./ -q production %s",nameFile);
  
  gSystem->Exec(Command2Line);

  } 
 }
 
}
 
