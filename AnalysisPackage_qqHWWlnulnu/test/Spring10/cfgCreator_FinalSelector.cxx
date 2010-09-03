{
 ///==== cfg creator ====
 
 #include <iomanip>
 
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
  sprintf(nameFile,"dir_cfg/FinalSelection_%s.cfg",nameSample[iSample]);
  myfile.open (nameFile);
  
  myfile << std::fixed;
  myfile << std::setprecision(20);
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
  myfile << std::endl;
  myfile << "[Output]" << std::endl;
  myfile << "OutFileNameEfficiencies = /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/output_Spring10/out_FinalSelection_" << nameSample[iSample] << ".root" << std::endl;
  myfile << std::endl;
  
  myfile << "[Jet]" << std::endl;
  myfile << "AdditionalInputFiles = \\" << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Jet/TMVAnalysis_MLP.weights.xml, \\ " << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Jet/TMVAnalysis_BDT.weights.xml, \\" << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Jet/TMVAnalysis_Fisher.weights.xml, \\" << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Jet/TMVAnalysis_Likelihood.weights.xml, \\" << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Jet/TMVAnalysis_LikelihoodD.weights.xml" << std::endl;
  
  myfile << "Methods = \\" << std::endl;
  myfile << "   MLP, \\ " << std::endl;
  myfile << "   BDT, \\ " << std::endl;
  myfile << "   Fisher, \\" << std::endl;
  myfile << "   Likelihood, \\" << std::endl;
  myfile << "   LikelihoodD" << std::endl;
  myfile << std::endl;
  
  
  myfile << "[Lepton]" << std::endl;
  myfile << "AdditionalInputFiles = \\" << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Lep/TMVAnalysis_MLP.weights.xml, \\ " << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Lep/TMVAnalysis_BDT.weights.xml, \\" << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Lep/TMVAnalysis_Fisher.weights.xml, \\" << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Lep/TMVAnalysis_Likelihood.weights.xml, \\" << std::endl;
  myfile << "   /home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/weights_Lep/TMVAnalysis_LikelihoodD.weights.xml" << std::endl;
  
  myfile << "Methods = \\" << std::endl;
  myfile << "   MLP, \\ " << std::endl;
  myfile << "   BDT, \\" << std::endl;
  myfile << "   Fisher, \\" << std::endl;
  myfile << "   Likelihood, \\" << std::endl;
  myfile << "   LikelihoodD" << std::endl;
  myfile << std::endl;
  
  myfile.close(); 
 }
 
}


