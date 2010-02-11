#include <iostream>

{

 int numEvents[10] = {10,100,1000,2000,3000,4000,5000,6000,7000,8000};
 
 for (int i=0; i<10; i++){
  
  char name[1000];
  sprintf(name,"test_All_TTBarNtupleL2L3Antikt5CaloJets_%d.cfg",i);
  
  char outputFileName[1000];
  sprintf(outputFileName,"out_TT_General_Calibrator_%d.root",numEvents[i]);
  
  
  ofstream outfile (name);
  outfile << "[Input] " << std::endl;
  outfile << "treeName = TTBarNtupleL2L3Antikt5CaloJets/SimpleTree" << std::endl;
  outfile << "inputFileList = /afs/cern.ch/user/a/amassiro/scratch0/VBF/TTBar/Analysis/data/list.txt" << std::endl;
  
  outfile << "entryMIN = 0" << std::endl;
  outfile << "entryMAX = " << numEvents[i] << std::endl;
  outfile << "entryMOD = 1000" << std::endl;
  outfile << std::endl;
  outfile << "MassW =  80.0" << std::endl;
  outfile << "dPt = 200.0 << std::endl;
  outfile << "dEta = 5.0" << std::endl;
  outfile << "minPt = 10.0" << std::endl;
  outfile << "maxPt =  210.0" << std::endl;
  outfile << "minPt = 10.0" << std::endl;
  outfile << "maxEta =  5.0" << std::endl;
  outfile << std::endl;
 
  outfile << "[Calibration]" << std::endl;
  outfile << "nCycle = 1" << std::endl;
  outfile << "Algorithm = 6" << std::endl;
  outfile << "#########################" << std::endl;
  outfile << "# 0 UpdateMatrixInversion" << std::endl;
  outfile << "# 1 UpdateRUL3" << std::endl;
  outfile << "# 2 UpdateL3" << std::endl;
  outfile << "# 3 UpdateKUpdate" << std::endl;
  outfile << "# 4 UpdateRUFit" << std::endl;
  outfile << "# 5 UpdateSFit" << std::endl;
  outfile << "# 6 UpdateMIB" << std::endl;
  outfile << "# 7 UpdateSRooFit" << std::endl;
  outfile << "#########################" << std::endl;
  outfile << std::endl;
  
  outfile << "[Test]" << std::endl;
  outfile << "entryMIN = " << numEvents[i] +1 << std::endl;
  outfile << "entryMAX = " << numEvents[i] + 10000 << std::endl;
  outfile << std::endl;
  
  outfile << "[Output]" << std::endl;
  outfile << "fileName = " << outputFileName << std::endl;
  outfile << std::endl;
    
  outfile.close();
  
  

  //---- sh to send to LSF  
  char name_sh[1000];
  sprintf(name_sh,"test_All_%d_sh.sh",i);
  ofstream outfile_sh (name_sh);
  
  outfile_sh << "#!/bin/bash " << std::endl;
  outfile_sh << "cd -" << std::endl;
  
  outfile_sh << "source /afs/cern.ch/sw/lcg/app/releases/ROOT/5.21.04/slc4_amd64_gcc34/root/bin/thisroot.sh" << std::endl;  
  outfile_sh << "CLHEPSYS=/afs/cern.ch/sw/lcg/external/clhep/2.0.4.2/slc4_amd64_gcc34/" << std::endl;
  outfile_sh << "export CLHEPSYS" << std::endl;  
  outfile_sh << "PATH=${PATH}:${CLHEPSYS}/bin" << std::endl;
  outfile_sh << "export PATH" << std::endl;  
  outfile_sh << "LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${CLHEPSYS}/lib" << std::endl;
  outfile_sh << "export LD_LIBRARY_PATH" << std::endl;  
  
  outfile_sh << "source /afs/cern.ch/user/a/amassiro/scratch0/VBF/TTBar/Analysis/script/setup.sh" << std::endl;
  outfile_sh << "rfcp /castor/cern.ch/user/a/amassiro/TTBar/madgraph_all/VBF_SimpleTree_TTBar_All.root ./" << std::endl; 
  outfile_sh << "/afs/cern.ch/user/a/amassiro/scratch0/VBF/TTBar/Analysis/bin/TT_GeneralCalibrator.exe " << name << std::endl; 
  outfile_sh << "cp " << outputFileName << "/afs/cern.ch/user/a/amassiro/scratch0/VBF/TTBar/Analysis/output/" << std::endl;
  outfile_sh << std::endl;
  outfile_sh.close();
  
  TString CommandToShell = Form("chmod 777 /afs/cern.ch/user/a/amassiro/scratch0/VBF/TTBar/Analysis/%s",name_sh);
  gSystem->Exec(CommandToShell);
  
  CommandToShell = Form("bsub -q \"8nm\" %s",name_sh);
//   gSystem->Exec(CommandToShell);
  
 }
}
