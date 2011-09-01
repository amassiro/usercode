{
 ///==== cfg creator ====
 
 #include <iomanip>
 #include <string>
 #include "Read.cc"
 
// char outputDirectory[1000] = {"/gwteraz/users/amassiro/VBFPlainRoot/Latinos_26Jul2011_DATA/"};
// char    inputDirectory[1000] = {"/gwteraz/users/amassiro/VBF/DATA_PATLatinos_25July_Divided/"};
 char    inputDirectory[1000] = {"/gwteraz/users/amassiro/VBF/DATA_PATLatinos_16Aug2011_Divided/"};  
 char outputDirectory[1000] = {"/gwteraz/users/amassiro/VBFPlainRoot/Latinos_16Aug2011_DATA/"}; 
  
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsection[1000];
 
 char nameFileIn[1000] = {"test/Latinos/samples_DATA.txt"};
 
 int numberOfSamples =  ReadFile(nameFileIn,nameSample,nameHumanReadable, xsection);
 
 TString toDoShell;
 
 toDoShell= Form ("mkdir test/Latinos/dir_cfg_skimmed_DATA");
 system (toDoShell.Data());


 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  std::string name_samples = nameHumanReadable[iSample];
  if (name_samples  != "DATA") continue;
  
  toDoShell = Form ("mkdir %s/%s", outputDirectory, nameSample[iSample]);
  system (toDoShell.Data());

  TString toDoTemp = Form ("ls  %s/%s | grep MiBi | tr \"_\" \" \" | tr \".\" \" \" |    awk '{print $2}' &> ___tempList.txt", inputDirectory, nameSample[iSample]);
  system (toDoTemp.Data());
  
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
// nFile -= 1; ///----> there is the source file too!


 std::ifstream indataList;
 indataList.open("___tempList.txt"); // opens the file
 
 for (int iFile = 0; iFile < nFile; iFile++) {
  
  int listNumFile;
  indataList >> listNumFile;
  std::cout << " ---> listNumFile = " << listNumFile << std::endl;
  
  std::ofstream myfile;
  char nameFile[1000];
  sprintf(nameFile,"test/Latinos/dir_cfg_skimmed_DATA/NtupleProducerPATtoNT_%s_%d.cfg",nameSample[iSample],iFile);
  myfile.open (nameFile);
  
  myfile << std::fixed;
  myfile << std::setprecision(20);
  myfile << "[Input]" << std::endl;
  myfile << "treeName = MiBiCommonNTOneLeptonTwoJetsAK5PF/SimpleNtuplePATtoNT " << std::endl;

  myfile << "inputFile = " << inputDirectory << "/" << nameSample[iSample] << "/MiBiCommonNT_" << listNumFile << ".root" << std::endl;
//  myfile << "inputFile = " << inputDirectory << "/" << nameSample[iSample] << "/MiBiCommonNT_" << iFile << ".root" << std::endl;
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
   
//  myfile << "HLTVector = \\  " << std::endl;
//  myfile << "        HLT_DoubleMu6_v*, \\  " << std::endl;
//  myfile << "        HLT_DoubleMu7_v*, \\  " << std::endl;
//  myfile << "        HLT_Mu13_Mu8_v*, \\  " << std::endl;
//  myfile << "        HLT_Mu17_Mu8_v*, \\  " << std::endl;
//  myfile << "        HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v*, \\  " << std::endl;
//  myfile << "        HLT_Ele17_CaloIdT_TrkIdVL_CaloIsoVL_TrkIsoVL_Ele8_CaloIdT_TrkIdVL_CaloIsoVL_TrkIsoVL_v*, \\  " << std::endl;
//  myfile << "        HLT_Mu8_Ele17_CaloIdL_v*, \\  " << std::endl;
//  myfile << "        HLT_Mu17_Ele8_CaloIdL_v*, \\  " << std::endl;
//  myfile << "        HLT_Mu15_v*, \\  " << std::endl;
//  myfile << "        HLT_Mu24_v*, \\  " << std::endl;
//  myfile << "        HLT_Mu30_v*, \\  " << std::endl;
//  myfile << "        HLT_IsoMu17_v*, \\  " << std::endl;
//  myfile << "        HLT_IsoMu20_eta2p1_v*, \\  " << std::endl;
//  myfile << "        HLT_Ele27_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_v*, \\  " << std::endl;
//  myfile << "        HLT_Ele32_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_v*, \\  " << std::endl;
//  myfile << "        HLT_Ele52_CaloIdVT_TrkIdT_v*  " << std::endl;
//  myfile << "        " << std::endl;
    
//  myfile << "HLTVector =  \\" << std::endl;
//  myfile << "        HLT_DoubleMu6_v*, \\" << std::endl;
//  myfile << "        HLT_DoubleMu7_v*, \\" << std::endl;
//  myfile << "        HLT_Mu13_Mu8_v*, \\" << std::endl;
//  myfile << "        HLT_Mu17_Mu8_v*, \\" << std::endl;
//  myfile << "        HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v*, \\" << std::endl;
//  myfile << "        HLT_Ele17_CaloIdT_TrkIdVL_CaloIsoVL_TrkIsoVL_Ele8_CaloIdT_TrkIdVL_CaloIsoVL_TrkIsoVL_v*, \\" << std::endl;
//  myfile << "        HLT_Mu8_Ele17_CaloIdL_v*, \\" << std::endl;
//  myfile << "        HLT_Mu17_Ele8_CaloIdL_v*" << std::endl;
//  myfile << "        " << std::endl;

  
  myfile <<  "[Selection]" << std::endl;
  myfile << std::endl;
  myfile << "[Output]" << std::endl;

  myfile << "outFileName = " << outputDirectory << "/" << nameSample[iSample] << "/out_NtupleProducer_" << listNumFile << ".root" << std::endl;
//  myfile << "outFileName = " << outputDirectory << "/" << nameSample[iSample] << "/out_NtupleProducer_" << iFile << ".root" << std::endl;

  myfile << std::endl;
  myfile.close();
 
  } 
 
 indataList.close();
 
 }

}


