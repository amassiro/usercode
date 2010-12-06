#include "Variables.h"

void InitializeTree(Variables& vars, const std::string& outputRootFileName)
{
  
  vars.m_outputRootFile = new TFile(outputRootFileName.c_str(), "RECREATE");  

  //--------------------------
  //---- Efficiency tree ----
  //--------------------------
  
  vars.m_efficiencyTree = new TTree("outTreeSelections", "outTreeSelections");
  vars.m_efficiencyTree -> SetDirectory(vars.m_outputRootFile);
  
  vars.m_efficiencyTree -> Branch("XSection", &vars.XSection, "XSection/D");
  vars.m_efficiencyTree -> Branch("dataFlag",     &vars.dataFlag,         "dataFlag/I");
  
  
  
  //-------------------------
  //---- Reduced tree ----
  //-------------------------
  
  vars.m_reducedTree = new TTree("outTreeJetLep", "outTreeJetLep");
  vars.m_reducedTree -> SetDirectory(vars.m_outputRootFile);
  
  vars.m_reducedTree -> Branch("runId",        &vars.runId,               "runId/I");
  vars.m_reducedTree -> Branch("lumiId",       &vars.lumiId,             "lumiId/I");
  vars.m_reducedTree -> Branch("eventId",      &vars.eventId,           "eventId/I");
  
  //~~~~ lepton variables
  vars.m_reducedTree -> Branch("lep_pX",  &vars.lep_pX,   "lep_pX/D");
  vars.m_reducedTree -> Branch("lep_pY",  &vars.lep_pY,   "lep_pY/D");
  vars.m_reducedTree -> Branch("lep_pZ",  &vars.lep_pZ,   "lep_pZ/D");
  vars.m_reducedTree -> Branch("lep_pT",  &vars.lep_pT,   "lep_pT/D");
  vars.m_reducedTree -> Branch("lep_E",  &vars.lep_E,   "lep_E/D");
 
  vars.m_reducedTree -> Branch("lep_charge",  &vars.lep_charge,   "lep_charge/D");
  vars.m_reducedTree -> Branch("lep_flavour", &vars.lep_flavour, "lep_flavour/I");
  vars.m_reducedTree -> Branch("lep_dxy",     &vars.lep_dxy,         "lep_dxy/D");
  vars.m_reducedTree -> Branch("lep_dz",      &vars.lep_dz,           "lep_dz/D");
  vars.m_reducedTree -> Branch("lep_3DipSig", &vars.lep_3DipSig, "lep_3DipSig/D");
  vars.m_reducedTree -> Branch("lep_tkIso",   &vars.lep_tkIso,     "lep_tkIso/D");
  vars.m_reducedTree -> Branch("lep_emIso",   &vars.lep_emIso,     "lep_emIso/D");
  vars.m_reducedTree -> Branch("lep_hadIso",  &vars.lep_hadIso,   "lep_hadIso/D");
  vars.m_reducedTree -> Branch("lep_isEB",          &vars.lep_isEB,                   "lep_isEB/I");
  vars.m_reducedTree -> Branch("lep_sigmaIetaIeta", &vars.lep_sigmaIetaIeta, "lep_sigmaIetaIeta/D");
  vars.m_reducedTree -> Branch("lep_DphiIn",        &vars.lep_DphiIn,               "lep_DphiIn/D");
  vars.m_reducedTree -> Branch("lep_DetaIn",        &vars.lep_DetaIn,               "lep_DetaIn/D");
  vars.m_reducedTree -> Branch("lep_HOverE",        &vars.lep_HOverE,               "lep_HOverE/D");
  vars.m_reducedTree -> Branch("lep_fbrem",         &vars.lep_fbrem,                 "lep_fbrem/D");
  vars.m_reducedTree -> Branch("lep_EOverP",        &vars.lep_EOverP,               "lep_EOverP/D");
  vars.m_reducedTree -> Branch("lep_tracker",                  &vars.lep_tracker,                                   "lep_tracker/I");
  vars.m_reducedTree -> Branch("lep_standalone",               &vars.lep_standalone,                             "lep_standalone/I");
  vars.m_reducedTree -> Branch("lep_global",                   &vars.lep_global,                                     "lep_global/I");
  vars.m_reducedTree -> Branch("lep_normalizedChi2",           &vars.lep_normalizedChi2,                     "lep_normalizedChi2/D");
  vars.m_reducedTree -> Branch("lep_numberOfValidTrackerHits", &vars.lep_numberOfValidTrackerHits, "lep_numberOfValidTrackerHits/I");
  vars.m_reducedTree -> Branch("lep_numberOfValidMuonHits",    &vars.lep_numberOfValidMuonHits,       "lep_numberOfValidMuonHits/I");
  
  
  //~~~~ met variables
  vars.m_reducedTree-> Branch("met_X",    &vars.met_X,       "met_X/D");
  vars.m_reducedTree-> Branch("met_Y",    &vars.met_Y,       "met_Y/D");
  vars.m_reducedTree-> Branch("met",    &vars.met,       "met/D");
  
  
  //~~~~ jet variables
   
  vars.m_reducedTree -> Branch("q1_pX", &vars.q1_pX, "q1_pX/D"); 
  vars.m_reducedTree -> Branch("q1_pY", &vars.q1_pY, "q1_pY/D"); 
  vars.m_reducedTree -> Branch("q1_pZ", &vars.q1_pZ, "q1_pZ/D"); 
  vars.m_reducedTree -> Branch("q1_pT", &vars.q1_pT, "q1_pT/D"); 
  vars.m_reducedTree -> Branch("q1_E", &vars.q1_E, "q1_E/D"); 
  vars.m_reducedTree -> Branch("q1_Eta", &vars.q1_Eta, "q1_Eta/D"); 
  vars.m_reducedTree -> Branch("q1_Phi", &vars.q1_Phi, "q1_Phi/D"); 
  vars.m_reducedTree -> Branch("q1_bTag_trackCountingHighPurBJetTags", &vars.q1_bTag_trackCountingHighPurBJetTags, "q1_bTag_trackCountingHighPurBJetTags/D"); 
  vars.m_reducedTree -> Branch("q1_bTag_trackCountingHighEffBJetTags", &vars.q1_bTag_trackCountingHighEffBJetTags, "q1_bTag_trackCountingHighEffBJetTags/D"); 
  vars.m_reducedTree -> Branch("q2_pX", &vars.q2_pX, "q2_pX/D"); 
  vars.m_reducedTree -> Branch("q2_pY", &vars.q2_pY, "q2_pY/D"); 
  vars.m_reducedTree -> Branch("q2_pZ", &vars.q2_pZ, "q2_pZ/D"); 
  vars.m_reducedTree -> Branch("q2_pT", &vars.q2_pT, "q2_pT/D"); 
  vars.m_reducedTree -> Branch("q2_E", &vars.q2_E, "q2_E/D"); 
  vars.m_reducedTree -> Branch("q2_Eta", &vars.q2_Eta, "q2_Eta/D"); 
  vars.m_reducedTree -> Branch("q2_Phi", &vars.q2_Phi, "q2_Phi/D"); 
  vars.m_reducedTree -> Branch("q2_bTag_trackCountingHighPurBJetTags", &vars.q2_bTag_trackCountingHighPurBJetTags, "q2_bTag_trackCountingHighPurBJetTags/D"); 
  vars.m_reducedTree -> Branch("q2_bTag_trackCountingHighEffBJetTags", &vars.q2_bTag_trackCountingHighEffBJetTags, "q2_bTag_trackCountingHighEffBJetTags/D"); 
  
  vars.m_reducedTree -> Branch("M_qq", &vars.M_qq, "M_qq/D"); 
  vars.m_reducedTree -> Branch("DEta_qq", &vars.DEta_qq, "DEta_qq/D"); 
  vars.m_reducedTree -> Branch("DPhi_qq", &vars.DPhi_qq, "DPhi_qq/D"); 
  
  
  
  //~~~~ b-jets variables
  vars.m_reducedTree -> Branch("b1_pX", &vars.b1_pX, "b1_pX/D"); 
  vars.m_reducedTree -> Branch("b1_pY", &vars.b1_pY, "b1_pY/D"); 
  vars.m_reducedTree -> Branch("b1_pZ", &vars.b1_pZ, "b1_pZ/D"); 
  vars.m_reducedTree -> Branch("b1_pT", &vars.b1_pT, "b1_pT/D"); 
  vars.m_reducedTree -> Branch("b1_E", &vars.b1_E, "b1_E/D"); 
  vars.m_reducedTree -> Branch("b1_Eta", &vars.b1_Eta, "b1_Eta/D"); 
  vars.m_reducedTree -> Branch("b1_Phi", &vars.b1_Phi, "b1_Phi/D"); 
  vars.m_reducedTree -> Branch("b1_bTag_trackCountingHighPurBJetTags", &vars.b1_bTag_trackCountingHighPurBJetTags, "b1_bTag_trackCountingHighPurBJetTags/D"); 
  vars.m_reducedTree -> Branch("b1_bTag_trackCountingHighEffBJetTags", &vars.b1_bTag_trackCountingHighEffBJetTags, "b1_bTag_trackCountingHighEffBJetTags/D"); 
  vars.m_reducedTree -> Branch("b2_pX", &vars.b2_pX, "b2_pX/D"); 
  vars.m_reducedTree -> Branch("b2_pY", &vars.b2_pY, "b2_pY/D"); 
  vars.m_reducedTree -> Branch("b2_pZ", &vars.b2_pZ, "b2_pZ/D"); 
  vars.m_reducedTree -> Branch("b2_pT", &vars.b2_pT, "b2_pT/D"); 
  vars.m_reducedTree -> Branch("b2_E", &vars.b2_E, "b2_E/D"); 
  vars.m_reducedTree -> Branch("b2_Eta", &vars.b2_Eta, "b2_Eta/D"); 
  vars.m_reducedTree -> Branch("b2_Phi", &vars.b2_Phi, "b2_Phi/D"); 
  vars.m_reducedTree -> Branch("b2_bTag_trackCountingHighPurBJetTags", &vars.b2_bTag_trackCountingHighPurBJetTags, "b2_bTag_trackCountingHighPurBJetTags/D"); 
  vars.m_reducedTree -> Branch("b2_bTag_trackCountingHighEffBJetTags", &vars.b2_bTag_trackCountingHighEffBJetTags, "b2_bTag_trackCountingHighEffBJetTags/D"); 
  
  vars.m_reducedTree -> Branch("M_bb", &vars.M_bb, "M_bb/D"); 
  vars.m_reducedTree -> Branch("DEta_bb", &vars.DEta_bb, "DEta_bb/D"); 
  vars.m_reducedTree -> Branch("DPhi_bb", &vars.DPhi_bb, "DPhi_bb/D"); 
  
}

void FillTree(Variables& vars)
{
  vars.m_reducedTree -> Fill();
}

void FillEfficiencyTree(Variables& vars)
{
 vars.m_efficiencyTree -> Fill();
}

void SaveTree(Variables& vars)
{
  // save tree
  vars.m_outputRootFile -> cd();
  vars.m_reducedTree -> Write();
  vars.m_efficiencyTree -> Write();
  vars.m_outputRootFile -> Close();
}

void SetLeptonEleVariables(Variables& vars, treeReader& reader, const int& iLep)
{
 vars.lep_pX = reader.Get4V("electrons")->at(iLep).X();
 vars.lep_pY = reader.Get4V("electrons")->at(iLep).Y();
 vars.lep_pZ = reader.Get4V("electrons")->at(iLep).Z();
 vars.lep_pT = reader.Get4V("electrons")->at(iLep).pt(); 
 vars.lep_E = reader.Get4V("electrons")->at(iLep).E();
 
 vars.lep_charge = reader.GetFloat("electrons_charge")->at(iLep);
 vars.lep_flavour = 11;
 vars.lep_dxy = reader.GetFloat("electrons_dxy")->at(iLep) ;
 vars.lep_dz =reader.GetFloat("electrons_dz")->at(iLep);
 vars.lep_3DipSig = reader.GetFloat("electrons_3DipSignificance")->at(iLep);
 vars.lep_tkIso = reader.GetFloat("electrons_tkIsoR03")->at(iLep);
 vars.lep_emIso =  reader.GetFloat("electrons_emIsoR03")->at(iLep);
 vars.lep_hadIso = reader.GetFloat("electrons_hadIsoR03_depth1")->at(iLep)+reader.GetFloat("electrons_hadIsoR03_depth2")->at(iLep);
 vars.lep_isEB = reader.GetInt("electrons_isEB")->at(iLep) ;
 vars.lep_sigmaIetaIeta = reader.GetFloat("electrons_sigmaIetaIeta")->at(iLep);
 vars.lep_DphiIn = reader.GetFloat("electrons_deltaPhiIn")->at(iLep);
 vars.lep_DetaIn = reader.GetFloat("electrons_deltaEtaIn")->at(iLep);
 vars.lep_HOverE = reader.GetFloat("electrons_hOverE")->at(iLep);
 vars.lep_fbrem = reader.GetFloat("electrons_fbrem")->at(iLep); 
 vars.lep_EOverP = reader.GetFloat("electrons_eOverP")->at(iLep);
 vars.lep_tracker = -999;
 vars.lep_standalone = -999;
 vars.lep_global = -999;
 vars.lep_normalizedChi2 = -999;
 vars.lep_numberOfValidTrackerHits = -999;
 vars.lep_numberOfValidMuonHits = -999;
}



void SetLeptonMuVariables(Variables& vars, treeReader& reader,const int& iLep)
{
 vars.lep_pX = reader.Get4V("muons")->at(iLep).X();
 vars.lep_pY = reader.Get4V("muons")->at(iLep).Y();
 vars.lep_pZ = reader.Get4V("muons")->at(iLep).Z();
 vars.lep_pT = reader.Get4V("muons")->at(iLep).pt(); 
 vars.lep_E = reader.Get4V("muons")->at(iLep).E();
 
 vars.lep_charge = reader.GetFloat("muons_charge")->at(iLep);
 vars.lep_flavour = 13;
 vars.lep_dxy = reader.GetFloat("muons_dxy")->at(iLep) ;
 vars.lep_dz =reader.GetFloat("muons_dz")->at(iLep);
 vars.lep_3DipSig = reader.GetFloat("muons_3DipSignificance")->at(iLep);
 vars.lep_tkIso = reader.GetFloat("muons_tkIsoR03")->at(iLep);
 vars.lep_emIso =  reader.GetFloat("muons_emIsoR03")->at(iLep);
 vars.lep_hadIso = reader.GetFloat("muons_hadIsoR03")->at(iLep);
 vars.lep_isEB = -999;
 vars.lep_sigmaIetaIeta = -999;
 vars.lep_DphiIn = -999;
 vars.lep_DetaIn = -999;
 vars.lep_HOverE = -999;
 vars.lep_fbrem = -999; 
 vars.lep_EOverP = -999;
 vars.lep_tracker = reader.GetInt("muons_tracker")->at(iLep);
 vars.lep_standalone = reader.GetInt("muons_standalone")->at(iLep);
 vars.lep_global = reader.GetInt("muons_global")->at(iLep);
 vars.lep_normalizedChi2 = reader.GetFloat("muons_normalizedChi2")->at(iLep);
 vars.lep_numberOfValidTrackerHits = reader.GetInt("muons_numberOfValidTrackerHits")->at(iLep);
 vars.lep_numberOfValidMuonHits = reader.GetInt("muons_numberOfValidMuonHits")->at(iLep);
}


void SetMetVariables(Variables& vars, treeReader& reader, const std::string& metType)
{
 vars.met_X = reader.Get4V(metType)->at(0).X();
 vars.met_Y = reader.Get4V(metType)->at(0).Y();
 vars.met = reader.Get4V(metType)->at(0).P();
}



void SetQJetVariables(Variables& vars, treeReader& reader, const int& q1, const int& q2)
{
  vars.q1_pX = reader.Get4V("jets")->at(q1).X();
  vars.q1_pY = reader.Get4V("jets")->at(q1).Y();
  vars.q1_pZ = reader.Get4V("jets")->at(q1).Z();
  vars.q1_pT = reader.Get4V("jets")->at(q1).pt();
  vars.q1_E = reader.Get4V("jets")->at(q1).E();
  vars.q1_Eta = reader.Get4V("jets")->at(q1).Eta();
  vars.q1_Phi = reader.Get4V("jets")->at(q1).Phi();
  vars.q1_bTag_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags")->at(q1);
  vars.q1_bTag_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags")->at(q1);
 
  vars.q2_pX = reader.Get4V("jets")->at(q2).X();
  vars.q2_pY = reader.Get4V("jets")->at(q2).Y();
  vars.q2_pZ = reader.Get4V("jets")->at(q2).Z();
  vars.q2_pT = reader.Get4V("jets")->at(q2).pt();
  vars.q2_E = reader.Get4V("jets")->at(q2).E();
  vars.q2_Eta = reader.Get4V("jets")->at(q2).Eta();
  vars.q2_Phi = reader.Get4V("jets")->at(q2).Phi();
  vars.q2_bTag_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags")->at(q2);
  vars.q2_bTag_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags")->at(q2);
  
  vars.M_qq = (reader.Get4V("jets")->at(q1) + reader.Get4V("jets")->at(q2)).mass();
  vars.DEta_qq = deltaEta(reader.Get4V("jets")->at(q1).Eta() , reader.Get4V("jets")->at(q2).Eta());
  vars.DPhi_qq = deltaPhi(reader.Get4V("jets")->at(q1).Phi() , reader.Get4V("jets")->at(q2).Phi());
}




void SetBJetVariables(Variables& vars, treeReader& reader, const int& b1, const int& b2)
{
 vars.b1_pX = reader.Get4V("jets")->at(b1).X();
 vars.b1_pY = reader.Get4V("jets")->at(b1).Y();
 vars.b1_pZ = reader.Get4V("jets")->at(b1).Z();
 vars.b1_pT = reader.Get4V("jets")->at(b1).pt();
 vars.b1_E = reader.Get4V("jets")->at(b1).E();
 vars.b1_Eta = reader.Get4V("jets")->at(b1).Eta();
 vars.b1_Phi = reader.Get4V("jets")->at(b1).Phi();
 vars.b1_bTag_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags")->at(b1);
 vars.b1_bTag_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags")->at(b1);
 
 vars.b2_pX = reader.Get4V("jets")->at(b2).X();
 vars.b2_pY = reader.Get4V("jets")->at(b2).Y();
 vars.b2_pZ = reader.Get4V("jets")->at(b2).Z();
 vars.b2_pT = reader.Get4V("jets")->at(b2).pt();
 vars.b2_E = reader.Get4V("jets")->at(b2).E();
 vars.b2_Eta = reader.Get4V("jets")->at(b2).Eta();
 vars.b2_Phi = reader.Get4V("jets")->at(b2).Phi();
 vars.b2_bTag_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags")->at(b2);
 vars.b2_bTag_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags")->at(b2);
 
 vars.M_bb = (reader.Get4V("jets")->at(b1) + reader.Get4V("jets")->at(b2)).mass();
 vars.DEta_bb = deltaEta(reader.Get4V("jets")->at(b1).Eta() , reader.Get4V("jets")->at(b2).Eta());
 vars.DPhi_bb = deltaPhi(reader.Get4V("jets")->at(b1).Phi() , reader.Get4V("jets")->at(b2).Phi());
}



