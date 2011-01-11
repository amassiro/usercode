{
 ///==== cfg creator ====
 
 #include <iomanip>
 #include <string>

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






 system("mkdir test/Fall10/dir_cfg_skimmed");
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Fall10/dir_cfg_skimmed/NtupleProducer_%s.cfg",nameSample[iSample]);
  myfile.open (nameFile);
  
  myfile << std::fixed;
  myfile << std::setprecision(20);
  myfile << "[Input]" << std::endl;
  myfile << "treeName = SimpleNtuple " << std::endl;
  myfile << "inputFile = /gwterax1/users/amassiro/VBF/Fall10_Dec10MCandDATA/" << nameSample[iSample] << "/Jets2Lepton2_MiBiCommonNTOneLeptonTwoJetsPFlow_TOT.root" << std::endl;
  myfile << "  inFileNameJSON = /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions10/7TeV/Reprocessing/Cert_136033-149442_7TeV_Nov4ReReco_Collisions10_JSON.txt" << std::endl;

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
  myfile << "OutFileNameEfficiencies = /gwpool/users/amassiro/VBF/Analysis/AnalysisPackage_qqHWWlnulnu/output_Fall10/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;
  myfile << std::endl;
  
  myfile.close(); 
 }
 
}


