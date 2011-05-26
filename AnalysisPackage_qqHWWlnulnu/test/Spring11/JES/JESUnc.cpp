void JESUnc(){
  gSystem->Load("libFWCoreFWLite.so");
  AutoLibraryLoader::enable();
  JetCorrectionUncertainty *jecUnc = new JetCorrectionUncertainty("Jec10V3_Uncertainty_AK5PF.txt");

  ofstream myfile;
  myfile.open ("JESUnc.cxx");
  
  myfile << "double JESUnc(double eta, double pT){ " << std::endl;
  myfile << " double feta = abs(eta);" << std::endl;
  AutoLibraryLoader::enable();
  JetCorrectionUncertainty *jecUnc = new JetCorrectionUncertainty("Jec10V3_Uncertainty_AK5PF.txt");

  for (int iPt = 20; iPt < 100; iPt+=10){
   for (int iEta = 0; iEta < 50; iEta++){
    jecUnc->setJetEta(iEta / 10.);
    jecUnc->setJetPt(iPt);
    double unc = jecUnc->getUncertainty(true);
    myfile << " if (feta > " << iEta/10. << " && feta < " << (iEta+1)/10. << " && pT > " << iPt << " && pT < " << (iPt+10) << ") return  " << unc << " ; " << std::endl;
   }
  }

  myfile << "return 0;" << std::endl;
  myfile << "}" << std::endl;

  myfile.close(); 

}

