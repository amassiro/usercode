{
 ///==== cfg creator ====
 
 #include <iomanip>
 #include <string>

 char *nameSample[10000];
 char *nameSampleFile[10000];
 char* xsection[10000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("test/Spring10/samples_skimmed.txt");
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
    
    nameSampleFile[numberOfSamples] = new char [10000];
    line >> nameSampleFile[numberOfSamples]; 
    std::cout << nameSampleFile[numberOfSamples] << " ";

    xsection[numberOfSamples] = new char [10000];
    line >> xsection[numberOfSamples]; 
    std::cout << xsection[numberOfSamples] << " ";
    std::cout << std::endl;
    numberOfSamples++;
   } 
  }
 }



 system("mkdir test/Spring10/dir_cfg_skimmed");
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Spring10/dir_cfg_skimmed/NtupleProducer_%s.cfg",nameSample[iSample]);
  myfile.open (nameFile);
  
  myfile << std::fixed;
  myfile << std::setprecision(20);
  myfile << "[Input]" << std::endl;
  myfile << "treeName = SimpleNtple " << std::endl;
  myfile << "inputFile = /gwterax2/users/govoni/qqH_WW_lvlv/presel/" << nameSampleFile[iSample] << std::endl;
  char toDo[1000];
  sprintf(toDo,"double xsec = %s",xsection[iSample]);
  gROOT->ProcessLine(toDo);
  myfile << "inputXSection = " << xsec << std::endl;
  myfile << "histoNameEvents = events" << std::endl;
  myfile << std::endl;
  myfile << "entryMIN = 0 " << std::endl;
  myfile << "entryMAX = -1 " << std::endl;
  myfile << "entryMOD = 1000 " << std::endl;
  myfile << "nStepToDo = 4 " << std::endl;
  myfile << std::endl;
  myfile << "[Output]" << std::endl;
  myfile << "OutFileNameEfficiencies = /gwpool/users/amassiro/VBF/Analysis/AnalysisPackage_qqHWWlnulnu/output/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;
  myfile << std::endl;
  
  myfile.close(); 
 }
 
}


