{
 ///==== cfg creator ====
 
 #include <iomanip>
 #include <string>
 #include "Read.cc"
 
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsection[1000];
 
 char nameFileIn[1000] = {"test/Spring11/samples_skimmed_PATtoNT.txt"};
 
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
  myfile << "treeName = SimpleNtuplePATtoNT " << std::endl;
  myfile << "inputFile = /gwteray/users/amassiro/VBF/Spring11_4July_MCandDATA_PATLatinos/" << nameSample[iSample] << "/" << nameSample[iSample] << ".root" << std::endl;
//  myfile << "  inFileNameJSON = /gwpool/users/amassiro/VBF/Analysis/Spring11/AnalysisPackage_qqHWWlnulnu/data/OR.json" << std::endl;        
  myfile << "  inFileNameJSON = /gwpool/users/amassiro/VBF/Analysis/Latinos/AnalysisPackage_qqHWWlnulnu/data/certifiedLatinos.42X.json" << std::endl;       
  
  
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
  myfile << "outFileName = /gwteray/users/amassiro/VBFPlainRoot/Latinos_3Jul2011/out_NtupleProducerPATtoNT_" << nameSample[iSample] << ".root" << std::endl;
    
  myfile << std::endl;
  
  myfile.close(); 
 }
 
}


