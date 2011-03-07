{
  #include "Read.cc"

 ///==== cfg creator ====
 
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsection[1000];
 
 char nameFileIn[1000] = {"test/Winter10/samples_skimmed.txt"};
 
 int numberOfSamples =  ReadFile(nameFileIn,nameSample,nameHumanReadable, xsection);

  system("mkdir test/Winter10/dir_cfg_SelectorJet");

 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Winter10/dir_cfg_SelectorJet/SelectorJets_%s.cfg",nameSample[iSample]);
  myfile.open (nameFile);
  
  myfile << "#### Selector Jets #### " << std::endl;
  myfile << "[Input]" << std::endl;
  myfile << "treeName = SimpleNtuple " << std::endl;
  myfile << "inputFile = output_Fall10/out_NtupleProducer_" << nameSample[iSample] << ".root" << std::endl;
  
  myfile << std::endl;
  myfile << "entryMOD = 1000 " << std::endl;
  
  
  myfile << std::endl;
  myfile << "[Jet]" << std::endl;
  myfile << "AdditionalInputFiles = \\" << std::endl;
  myfile << "   weights_Jet/TMVAnalysis_MLP.weights.xml, \\ " << std::endl;
  myfile << "   weights_Jet/TMVAnalysis_MLPCat.weights.xml, \\ " << std::endl;
  myfile << "   weights_Jet/TMVAnalysis_BDT.weights.xml, \\" << std::endl;
  myfile << "   weights_Jet/TMVAnalysis_Fisher.weights.xml, \\" << std::endl;
  myfile << "   weights_Jet/TMVAnalysis_Likelihood.weights.xml, \\" << std::endl;
  myfile << "   weights_Jet/TMVAnalysis_LikelihoodD.weights.xml" << std::endl;
  
  myfile << "Methods = \\" << std::endl;
  myfile << "   MLPCat, \\ " << std::endl;
  myfile << "   MLP, \\ " << std::endl;
  myfile << "   BDT, \\ " << std::endl;
  myfile << "   Fisher, \\" << std::endl;
  myfile << "   Likelihood, \\" << std::endl;
  myfile << "   LikelihoodD" << std::endl;
  myfile << std::endl;
  
  myfile.close(); 
  
  
  TString Command2Line = Form("./bin/FinalSelection_Producer_Jet.exe test/Winter10/dir_cfg_SelectorJet/SelectorJets_%s.cfg",nameSample[iSample]);
  gSystem->Exec(Command2Line);  
  
 }
 
}


