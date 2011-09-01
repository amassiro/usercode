{
 ///==== cfg creator ====
 
 #include <iomanip>
 #include <string>
 #include "Read.cc"
 
 char outputDirectory[1000] = {"/gwteraz/users/amassiro/VBFPlainRoot/Latinos_25Jul2011_Spring11/"};
 char    inputDirectory[1000] = {"/gwteraz/users/amassiro/VBF/Spring11_25July_MC_PATLatinos/"};  
  
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsection[1000];
 
 char nameFileIn[1000] = {"test/Latinos/samples_MC_Spring11.txt"};
 
 int numberOfSamples =  ReadFile(nameFileIn,nameSample,nameHumanReadable, xsection);

 TString toDoShell;
 
 toDoShell= Form ("mkdir test/Latinos/dir_cfg_skimmed_MC_Spring11");
 system (toDoShell.Data());
  
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
   std::string name_samples = nameHumanReadable[iSample];
  if (name_samples  == "DATA") continue;
  
 
  toDoShell = Form ("mkdir %s/%s", outputDirectory, nameSample[iSample]);
  system (toDoShell.Data());
  
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
  sprintf(nameFile,"test/Latinos/dir_cfg_skimmed_MC_Spring11/NtupleProducerPATtoNT_%s_%d.cfg",nameSample[iSample],iFile+1);
  myfile.open (nameFile);
  
  myfile << std::fixed;
  myfile << std::setprecision(20);
  myfile << "[Input]" << std::endl;
  myfile << "treeName = MiBiCommonNTOneLeptonTwoJetsAK5PF/SimpleNtuplePATtoNT " << std::endl;

  myfile << "inputFile = " << inputDirectory << "/" << nameSample[iSample] << "/MiBiCommonNT_" << iFile+1 << ".root" << std::endl;
  myfile << "inFileNameJSON = /gwpool/users/amassiro/VBF/Analysis/Latinos/AnalysisPackage_qqHWWlnulnu/data/certifiedLatinos.42X.json" << std::endl;       
  
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
  myfile << std::endl;
  myfile << "[Output]" << std::endl;
    
  myfile << "outFileName = " << outputDirectory << "/" << nameSample[iSample] << "/out_NtupleProducer_" << iFile+1 << ".root" << std::endl;
  myfile << std::endl;
  myfile.close();
 
  } 
 }
 
}


