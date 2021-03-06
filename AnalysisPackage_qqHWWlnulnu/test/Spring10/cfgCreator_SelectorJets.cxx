{
 ///==== cfg creator ====
 
 char *nameSample[1000];
 char *nameSamplePrefix[1000];
 char *nameSampleTree[1000];
 
 char* xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("test/Spring10/samples_training.txt");
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
  sprintf(nameFile,"test/Spring10/dir_cfg_SelectorJet/SelectorJets_%s.cfg",nameSample[iSample]);
  myfile.open (nameFile);
  
  myfile << "#### Selector Jets #### " << std::endl;
  myfile << "[Input]" << std::endl;
  myfile << "treeName = " << nameSampleTree[iSample] << std::endl;
  myfile << "inputFile = /media/LINUX/Data/VBF/Spring10/" << nameSamplePrefix[iSample] << "_" << nameSample[iSample] << ".root" << std::endl;
  char toDo[1000];
  sprintf(toDo,"double xsec = %s",xsection[iSample]);
  gROOT->ProcessLine(toDo);
  myfile << "inputXSection = " << xsec << std::endl;
  myfile << "treeNameLeptonFilter = VBFPtMinLeptonCountFilterAll" << std::endl;
  myfile << "treeNameJetCounterFilter = VBFEtMinCaloJetCountFilterL2L3Antikt5CaloJets " << std::endl;
  myfile << std::endl;
  myfile << "entryMIN = 0 " << std::endl;
  myfile << "entryMAX = -1 " << std::endl;
  myfile << "entryMOD = 1000 " << std::endl;
  myfile << "nStepToDo = 5 " << std::endl;
  myfile << std::endl;
  myfile << "[Output]" << std::endl;
  myfile << "OutFileNameEfficiencies = /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/output_Spring10/out_SelectorJets_" << nameSample[iSample] << ".root" << std::endl;
  myfile << std::endl;
  
  myfile.close(); 
 }
 
}


