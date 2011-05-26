double returnUncJES(double eta, double pT){
  gSystem->Load("libFWCoreFWLite.so");
  AutoLibraryLoader::enable();
  JetCorrectionUncertainty *jecUnc = new JetCorrectionUncertainty("Jec10V3_Uncertainty_AK5PF.txt");

  jecUnc->setJetEta(eta);
  jecUnc->setJetPt(pT);
  double unc = jecUnc->getUncertainty(true);
  return unc;
}

