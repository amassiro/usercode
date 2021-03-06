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
 vars.m_efficiencyTree -> Branch("numEntriesBefore",     &vars.numEntriesBefore,         "numEntriesBefore/I");
 vars.m_efficiencyTree -> Branch("preselection_efficiency",     &vars.preselection_efficiency,         "preselection_efficiency/D");
 
 
 
 //-------------------------
 //---- Reduced tree ----
 //-------------------------
 
 vars.m_reducedTree = new TTree("outTreeJetLep", "outTreeJetLep");
 vars.m_reducedTree -> SetDirectory(vars.m_outputRootFile);
 
 vars.m_reducedTree -> Branch("runId",        &vars.runId,               "runId/I");
 vars.m_reducedTree -> Branch("lumiId",       &vars.lumiId,             "lumiId/I");
 vars.m_reducedTree -> Branch("eventId",      &vars.eventId,           "eventId/I");
 
 //~~~~ lepton variables
 vars.m_reducedTree -> Branch("l1_pX",  &vars.l1_pX,   "l1_pX/D");
 vars.m_reducedTree -> Branch("l1_pY",  &vars.l1_pY,   "l1_pY/D");
 vars.m_reducedTree -> Branch("l1_pZ",  &vars.l1_pZ,   "l1_pZ/D");
 vars.m_reducedTree -> Branch("l1_pT",  &vars.l1_pT,   "l1_pT/D");
 vars.m_reducedTree -> Branch("l1_E",  &vars.l1_E,   "l1_E/D");
 vars.m_reducedTree -> Branch("l1_Eta",  &vars.l1_Eta,   "l1_Eta/D");
 vars.m_reducedTree -> Branch("l1_Phi",  &vars.l1_Phi,   "l1_Phi/D"); 
 
 vars.m_reducedTree -> Branch("l1_charge",  &vars.l1_charge,   "l1_charge/D");
 vars.m_reducedTree -> Branch("l1_flavour", &vars.l1_flavour, "l1_flavour/I");
 vars.m_reducedTree -> Branch("l1_dxy",     &vars.l1_dxy,         "l1_dxy/D");
 vars.m_reducedTree -> Branch("l1_dz",      &vars.l1_dz,           "l1_dz/D");
 vars.m_reducedTree -> Branch("l1_3DipSig", &vars.l1_3DipSig, "l1_3DipSig/D");
 vars.m_reducedTree -> Branch("l1_tkIso",   &vars.l1_tkIso,     "l1_tkIso/D");
 vars.m_reducedTree -> Branch("l1_emIso",   &vars.l1_emIso,     "l1_emIso/D");
 vars.m_reducedTree -> Branch("l1_hadIso",  &vars.l1_hadIso,   "l1_hadIso/D");
 vars.m_reducedTree -> Branch("l1_isEB",          &vars.l1_isEB,                   "l1_isEB/I");
 vars.m_reducedTree -> Branch("l1_sigmaIetaIeta", &vars.l1_sigmaIetaIeta, "l1_sigmaIetaIeta/D");
 vars.m_reducedTree -> Branch("l1_DphiIn",        &vars.l1_DphiIn,               "l1_DphiIn/D");
 vars.m_reducedTree -> Branch("l1_DetaIn",        &vars.l1_DetaIn,               "l1_DetaIn/D");
 vars.m_reducedTree -> Branch("l1_HOverE",        &vars.l1_HOverE,               "l1_HOverE/D");
 vars.m_reducedTree -> Branch("l1_fbrem",         &vars.l1_fbrem,                 "l1_fbrem/D");
 vars.m_reducedTree -> Branch("l1_EOverP",        &vars.l1_EOverP,               "l1_EOverP/D");
 vars.m_reducedTree -> Branch("l1_tracker",                  &vars.l1_tracker,                                   "l1_tracker/I");
 vars.m_reducedTree -> Branch("l1_standalone",               &vars.l1_standalone,                             "l1_standalone/I");
 vars.m_reducedTree -> Branch("l1_global",                   &vars.l1_global,                                     "l1_global/I");
 vars.m_reducedTree -> Branch("l1_normalizedChi2",           &vars.l1_normalizedChi2,                     "l1_normalizedChi2/D");
 vars.m_reducedTree -> Branch("l1_numberOfValidTrackerHits", &vars.l1_numberOfValidTrackerHits, "l1_numberOfValidTrackerHits/I");
 vars.m_reducedTree -> Branch("l1_numberOfValidMuonHits",    &vars.l1_numberOfValidMuonHits,       "l1_numberOfValidMuonHits/I");
 
 vars.m_reducedTree -> Branch("l2_pX",  &vars.l2_pX,   "l2_pX/D");
 vars.m_reducedTree -> Branch("l2_pY",  &vars.l2_pY,   "l2_pY/D");
 vars.m_reducedTree -> Branch("l2_pZ",  &vars.l2_pZ,   "l2_pZ/D");
 vars.m_reducedTree -> Branch("l2_pT",  &vars.l2_pT,   "l2_pT/D");
 vars.m_reducedTree -> Branch("l2_E",  &vars.l2_E,   "l2_E/D");
 vars.m_reducedTree -> Branch("l2_Eta",  &vars.l2_Eta,   "l2_Eta/D");
 vars.m_reducedTree -> Branch("l2_Phi",  &vars.l2_Phi,   "l2_Phi/D"); 
 
 vars.m_reducedTree -> Branch("l2_charge",  &vars.l2_charge,   "l2_charge/D");
 vars.m_reducedTree -> Branch("l2_flavour", &vars.l2_flavour, "l2_flavour/I");
 vars.m_reducedTree -> Branch("l2_dxy",     &vars.l2_dxy,         "l2_dxy/D");
 vars.m_reducedTree -> Branch("l2_dz",      &vars.l2_dz,           "l2_dz/D");
 vars.m_reducedTree -> Branch("l2_3DipSig", &vars.l2_3DipSig, "l2_3DipSig/D");
 vars.m_reducedTree -> Branch("l2_tkIso",   &vars.l2_tkIso,     "l2_tkIso/D");
 vars.m_reducedTree -> Branch("l2_emIso",   &vars.l2_emIso,     "l2_emIso/D");
 vars.m_reducedTree -> Branch("l2_hadIso",  &vars.l2_hadIso,   "l2_hadIso/D");
 vars.m_reducedTree -> Branch("l2_isEB",          &vars.l2_isEB,                   "l2_isEB/I");
 vars.m_reducedTree -> Branch("l2_sigmaIetaIeta", &vars.l2_sigmaIetaIeta, "l2_sigmaIetaIeta/D");
 vars.m_reducedTree -> Branch("l2_DphiIn",        &vars.l2_DphiIn,               "l2_DphiIn/D");
 vars.m_reducedTree -> Branch("l2_DetaIn",        &vars.l2_DetaIn,               "l2_DetaIn/D");
 vars.m_reducedTree -> Branch("l2_HOverE",        &vars.l2_HOverE,               "l2_HOverE/D");
 vars.m_reducedTree -> Branch("l2_fbrem",         &vars.l2_fbrem,                 "l2_fbrem/D");
 vars.m_reducedTree -> Branch("l2_EOverP",        &vars.l2_EOverP,               "l2_EOverP/D");
 vars.m_reducedTree -> Branch("l2_tracker",                  &vars.l2_tracker,                                   "l2_tracker/I");
 vars.m_reducedTree -> Branch("l2_standalone",               &vars.l2_standalone,                             "l2_standalone/I");
 vars.m_reducedTree -> Branch("l2_global",                   &vars.l2_global,                                     "l2_global/I");
 vars.m_reducedTree -> Branch("l2_normalizedChi2",           &vars.l2_normalizedChi2,                     "l2_normalizedChi2/D");
 vars.m_reducedTree -> Branch("l2_numberOfValidTrackerHits", &vars.l2_numberOfValidTrackerHits, "l2_numberOfValidTrackerHits/I");
 vars.m_reducedTree -> Branch("l2_numberOfValidMuonHits",    &vars.l2_numberOfValidMuonHits,       "l2_numberOfValidMuonHits/I");
 

 vars.m_reducedTree -> Branch("M_ll", &vars.M_ll, "M_ll/D");
 vars.m_reducedTree -> Branch("DEta_ll", &vars.DEta_ll, "DEta_ll/D");
 vars.m_reducedTree -> Branch("DPhi_ll", &vars.DPhi_ll, "DPhi_ll/D");
 
 vars.m_reducedTree -> Branch("l1_Z", &vars.l1_Z, "l1_Z/D");
 vars.m_reducedTree -> Branch("l2_Z", &vars.l2_Z, "l2_Z/D");
 vars.m_reducedTree -> Branch("Z_ll", &vars.Z_ll, "Z_ll/D");
 
 
 vars.m_reducedTree -> Branch("Nleptons_pT5", &vars.Nleptons_pT5, "Nleptons_pT5/I");
 vars.m_reducedTree -> Branch("Nleptons_pT10", &vars.Nleptons_pT10, "Nleptons_pT10/I");
 vars.m_reducedTree -> Branch("Nleptons_pT15", &vars.Nleptons_pT15, "Nleptons_pT15/I");
 vars.m_reducedTree -> Branch("Nleptons_pT20", &vars.Nleptons_pT20, "Nleptons_pT20/I");
 vars.m_reducedTree -> Branch("Nleptons_pT25", &vars.Nleptons_pT25, "Nleptons_pT25/I");
 vars.m_reducedTree -> Branch("Nleptons_pT30", &vars.Nleptons_pT30, "Nleptons_pT30/I");
 
 //~~~~ met variables
 vars.m_reducedTree-> Branch("met_X",    &vars.met_X,       "met_X/D");
 vars.m_reducedTree-> Branch("met_Y",    &vars.met_Y,       "met_Y/D");
 vars.m_reducedTree-> Branch("met",        &vars.met,           "met/D");
 vars.m_reducedTree-> Branch("pmet",      &vars.pmet,         "pmet/D");
 vars.m_reducedTree-> Branch("chmet",    &vars.chmet,       "chmet/D");
 vars.m_reducedTree-> Branch("chmet_X",    &vars.chmet_X,       "chmet_X/D");
 vars.m_reducedTree-> Branch("chmet_Y",    &vars.chmet_Y,       "chmet_Y/D");
 vars.m_reducedTree-> Branch("pchmet", &vars.pchmet,    "pchmet/D");
 vars.m_reducedTree-> Branch("minMet", &vars.minMet,   "minMet/D");
  
//---- jetdeau [jd] variables: met and jet corrections
 vars.m_reducedTree-> Branch("jd_dphi1",    &vars.jd_dphi1,       "jd_dphi1/D");
 vars.m_reducedTree-> Branch("jd_dphi2",    &vars.jd_dphi2,       "jd_dphi2/D");
  
 vars.m_reducedTree-> Branch("jd_Delta_q1_P",    &vars.jd_Delta_q1_P,       "jd_Delta_q1_P/D");
 vars.m_reducedTree-> Branch("jd_Delta_q2_P",    &vars.jd_Delta_q2_P,       "jd_Delta_q2_P/D");
  
 vars.m_reducedTree-> Branch("jd_between",    &vars.jd_between,       "jd_between/D"); 
  
 vars.m_reducedTree-> Branch("jd_met",    &vars.jd_met,       "jd_met/D");
 vars.m_reducedTree-> Branch("jd_met_X",    &vars.jd_met_X,       "jd_met_X/D");
 vars.m_reducedTree-> Branch("jd_met_Y",    &vars.jd_met_Y,       "jd_met_Y/D");
 vars.m_reducedTree-> Branch("jd_pmet",    &vars.jd_pmet,       "jd_pmet/D");


 vars.m_reducedTree-> Branch("jd_q1_pX",    &vars.jd_q1_pX,       "jd_q1_pX/D");
 vars.m_reducedTree-> Branch("jd_q1_pY",    &vars.jd_q1_pY,       "jd_q1_pY/D");
 vars.m_reducedTree-> Branch("jd_q1_pZ",    &vars.jd_q1_pZ,       "jd_q1_pZ/D");
 vars.m_reducedTree-> Branch("jd_q1_pT",    &vars.jd_q1_pT,       "jd_q1_pT/D");
 vars.m_reducedTree-> Branch("jd_q1_E",      &vars.jd_q1_E,         "jd_q1_E/D");
 vars.m_reducedTree-> Branch("jd_q1_Eta",   &vars.jd_q1_Eta,      "jd_q1_Eta/D");
 vars.m_reducedTree-> Branch("jd_q1_Phi",   &vars.jd_q1_Phi,      "jd_q1_Phi/D");
 
 vars.m_reducedTree-> Branch("jd_q2_pX",    &vars.jd_q2_pX,       "jd_q2_pX/D");
 vars.m_reducedTree-> Branch("jd_q2_pY",    &vars.jd_q2_pY,       "jd_q2_pY/D");
 vars.m_reducedTree-> Branch("jd_q2_pZ",    &vars.jd_q2_pZ,       "jd_q2_pZ/D");
 vars.m_reducedTree-> Branch("jd_q2_pT",    &vars.jd_q2_pT,       "jd_q2_pT/D");
 vars.m_reducedTree-> Branch("jd_q2_E",      &vars.jd_q2_E,         "jd_q2_E/D");
 vars.m_reducedTree-> Branch("jd_q2_Eta",   &vars.jd_q2_Eta,      "jd_q2_Eta/D");
 vars.m_reducedTree-> Branch("jd_q2_Phi",   &vars.jd_q2_Phi,      "jd_q2_Phi/D");
 
 vars.m_reducedTree-> Branch("jd_M_qq",   &vars.jd_M_qq,         "jd_M_qq/D");
 

 //~~ additional variables 
 vars.m_reducedTree -> Branch("NsoftMu", &vars.NsoftMu, "NsoftMu/I");
 vars.m_reducedTree -> Branch("mT", &vars.mT, "mT/D");
 vars.m_reducedTree -> Branch("DPhiJet_ll", &vars.DPhiJet_ll, "DPhiJet_ll/D");
 vars.m_reducedTree -> Branch("maxDPhiJet_ll", &vars.maxDPhiJet_ll, "maxDPhiJet_ll/D");
 vars.m_reducedTree -> Branch("DPhiSingleJet_ll",    &vars.DPhiSingleJet_ll,    "DPhiSingleJet_ll/D");
 vars.m_reducedTree -> Branch("DPhiDoubleJet_ll", &vars.DPhiDoubleJet_ll, "DPhiDoubleJet_ll/D");


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
 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags", &vars.NBjets_trackCountingHighPurBJetTags, "NBjets_trackCountingHighPurBJetTags/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags", &vars.NBjets_trackCountingHighEffBJetTags, "NBjets_trackCountingHighEffBJetTags/I"); 
 
 vars.m_reducedTree -> Branch("totalJV_20", &vars.totalJV_20, "totalJV_20/I"); 
 vars.m_reducedTree -> Branch("totalJV_30", &vars.totalJV_30, "totalJV_30/I"); 
 vars.m_reducedTree -> Branch("totalJV_40", &vars.totalJV_40, "totalJV_40/I"); 
 
 vars.m_reducedTree -> Branch("JV_20", &vars.JV_20, "JV_20/I"); 
 vars.m_reducedTree -> Branch("JV_30", &vars.JV_30, "JV_30/I"); 
 vars.m_reducedTree -> Branch("JV_40", &vars.JV_40, "JV_40/I"); 
 vars.m_reducedTree -> Branch("CJV_20", &vars.CJV_20, "CJV_20/I"); 
 vars.m_reducedTree -> Branch("CJV_30", &vars.CJV_30, "CJV_30/I"); 
 vars.m_reducedTree -> Branch("CJV_40", &vars.CJV_40, "CJV_40/I"); 
 vars.m_reducedTree -> Branch("q_Z_01_20", &vars.q_Z_01_20, "q_Z_01_20/I"); 
 vars.m_reducedTree -> Branch("q_Z_03_20", &vars.q_Z_03_20, "q_Z_03_20/I"); 
 vars.m_reducedTree -> Branch("q_Z_05_20", &vars.q_Z_05_20, "q_Z_05_20/I"); 
 vars.m_reducedTree -> Branch("q_Z_07_20", &vars.q_Z_07_20, "q_Z_07_20/I"); 
 vars.m_reducedTree -> Branch("q_Z_09_20", &vars.q_Z_09_20, "q_Z_09_20/I"); 
 vars.m_reducedTree -> Branch("q_Z_10_20", &vars.q_Z_10_20, "q_Z_10_20/I"); 
 vars.m_reducedTree -> Branch("q_Z_12_20", &vars.q_Z_12_20, "q_Z_12_20/I"); 
 vars.m_reducedTree -> Branch("q_Z_14_20", &vars.q_Z_14_20, "q_Z_14_20/I"); 
 vars.m_reducedTree -> Branch("q_Z_01_30", &vars.q_Z_01_30, "q_Z_01_30/I"); 
 vars.m_reducedTree -> Branch("q_Z_03_30", &vars.q_Z_03_30, "q_Z_03_30/I"); 
 vars.m_reducedTree -> Branch("q_Z_05_30", &vars.q_Z_05_30, "q_Z_05_30/I"); 
 vars.m_reducedTree -> Branch("q_Z_07_30", &vars.q_Z_07_30, "q_Z_07_30/I"); 
 vars.m_reducedTree -> Branch("q_Z_09_30", &vars.q_Z_09_30, "q_Z_09_30/I"); 
 vars.m_reducedTree -> Branch("q_Z_10_30", &vars.q_Z_10_30, "q_Z_10_30/I"); 
 vars.m_reducedTree -> Branch("q_Z_12_30", &vars.q_Z_12_30, "q_Z_12_30/I"); 
 vars.m_reducedTree -> Branch("q_Z_14_30", &vars.q_Z_14_30, "q_Z_14_30/I");  
 vars.m_reducedTree -> Branch("q_Z_01_40", &vars.q_Z_01_40, "q_Z_01_40/I"); 
 vars.m_reducedTree -> Branch("q_Z_03_40", &vars.q_Z_03_40, "q_Z_03_40/I"); 
 vars.m_reducedTree -> Branch("q_Z_05_40", &vars.q_Z_05_40, "q_Z_05_40/I"); 
 vars.m_reducedTree -> Branch("q_Z_07_40", &vars.q_Z_07_40, "q_Z_07_40/I"); 
 vars.m_reducedTree -> Branch("q_Z_09_40", &vars.q_Z_09_40, "q_Z_09_40/I"); 
 vars.m_reducedTree -> Branch("q_Z_10_40", &vars.q_Z_10_40, "q_Z_10_40/I"); 
 vars.m_reducedTree -> Branch("q_Z_12_40", &vars.q_Z_12_40, "q_Z_12_40/I"); 
 vars.m_reducedTree -> Branch("q_Z_14_40", &vars.q_Z_14_40, "q_Z_14_40/I"); 
 
 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_m20", &vars.NBjets_trackCountingHighPurBJetTags_m20, "NBjets_trackCountingHighPurBJetTags_m20/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_m15", &vars.NBjets_trackCountingHighPurBJetTags_m15, "NBjets_trackCountingHighPurBJetTags_m15/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_m10", &vars.NBjets_trackCountingHighPurBJetTags_m10, "NBjets_trackCountingHighPurBJetTags_m10/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_m05", &vars.NBjets_trackCountingHighPurBJetTags_m05, "NBjets_trackCountingHighPurBJetTags_m05/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_m04", &vars.NBjets_trackCountingHighPurBJetTags_m04, "NBjets_trackCountingHighPurBJetTags_m04/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_m03", &vars.NBjets_trackCountingHighPurBJetTags_m03, "NBjets_trackCountingHighPurBJetTags_m03/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_m02", &vars.NBjets_trackCountingHighPurBJetTags_m02, "NBjets_trackCountingHighPurBJetTags_m02/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_m01", &vars.NBjets_trackCountingHighPurBJetTags_m01, "NBjets_trackCountingHighPurBJetTags_m01/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_00", &vars.NBjets_trackCountingHighPurBJetTags_00, "NBjets_trackCountingHighPurBJetTags_00/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_01", &vars.NBjets_trackCountingHighPurBJetTags_01, "NBjets_trackCountingHighPurBJetTags_01/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_02", &vars.NBjets_trackCountingHighPurBJetTags_02, "NBjets_trackCountingHighPurBJetTags_02/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_03", &vars.NBjets_trackCountingHighPurBJetTags_03, "NBjets_trackCountingHighPurBJetTags_03/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_04", &vars.NBjets_trackCountingHighPurBJetTags_04, "NBjets_trackCountingHighPurBJetTags_04/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_05", &vars.NBjets_trackCountingHighPurBJetTags_05, "NBjets_trackCountingHighPurBJetTags_05/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_10", &vars.NBjets_trackCountingHighPurBJetTags_10, "NBjets_trackCountingHighPurBJetTags_10/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_15", &vars.NBjets_trackCountingHighPurBJetTags_15, "NBjets_trackCountingHighPurBJetTags_15/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_20", &vars.NBjets_trackCountingHighPurBJetTags_20, "NBjets_trackCountingHighPurBJetTags_20/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_21", &vars.NBjets_trackCountingHighPurBJetTags_21, "NBjets_trackCountingHighPurBJetTags_21/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_22", &vars.NBjets_trackCountingHighPurBJetTags_22, "NBjets_trackCountingHighPurBJetTags_22/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_30", &vars.NBjets_trackCountingHighPurBJetTags_30, "NBjets_trackCountingHighPurBJetTags_30/I"); 
 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_m20", &vars.NBjets_trackCountingHighEffBJetTags_m20, "NBjets_trackCountingHighEffBJetTags_m20/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_m15", &vars.NBjets_trackCountingHighEffBJetTags_m15, "NBjets_trackCountingHighEffBJetTags_m15/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_m10", &vars.NBjets_trackCountingHighEffBJetTags_m10, "NBjets_trackCountingHighEffBJetTags_m10/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_m05", &vars.NBjets_trackCountingHighEffBJetTags_m05, "NBjets_trackCountingHighEffBJetTags_m05/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_m04", &vars.NBjets_trackCountingHighEffBJetTags_m04, "NBjets_trackCountingHighEffBJetTags_m04/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_m03", &vars.NBjets_trackCountingHighEffBJetTags_m03, "NBjets_trackCountingHighEffBJetTags_m03/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_m02", &vars.NBjets_trackCountingHighEffBJetTags_m02, "NBjets_trackCountingHighEffBJetTags_m02/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_m01", &vars.NBjets_trackCountingHighEffBJetTags_m01, "NBjets_trackCountingHighEffBJetTags_m01/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_00", &vars.NBjets_trackCountingHighEffBJetTags_00, "NBjets_trackCountingHighEffBJetTags_00/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_01", &vars.NBjets_trackCountingHighEffBJetTags_01, "NBjets_trackCountingHighEffBJetTags_01/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_02", &vars.NBjets_trackCountingHighEffBJetTags_02, "NBjets_trackCountingHighEffBJetTags_02/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_03", &vars.NBjets_trackCountingHighEffBJetTags_03, "NBjets_trackCountingHighEffBJetTags_03/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_04", &vars.NBjets_trackCountingHighEffBJetTags_04, "NBjets_trackCountingHighEffBJetTags_04/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_05", &vars.NBjets_trackCountingHighEffBJetTags_05, "NBjets_trackCountingHighEffBJetTags_05/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_10", &vars.NBjets_trackCountingHighEffBJetTags_10, "NBjets_trackCountingHighEffBJetTags_10/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_15", &vars.NBjets_trackCountingHighEffBJetTags_15, "NBjets_trackCountingHighEffBJetTags_15/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_20", &vars.NBjets_trackCountingHighEffBJetTags_20, "NBjets_trackCountingHighEffBJetTags_20/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_21", &vars.NBjets_trackCountingHighEffBJetTags_21, "NBjets_trackCountingHighEffBJetTags_21/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_22", &vars.NBjets_trackCountingHighEffBJetTags_22, "NBjets_trackCountingHighEffBJetTags_22/I"); 
 vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_30", &vars.NBjets_trackCountingHighEffBJetTags_30, "NBjets_trackCountingHighEffBJetTags_30/I"); 
 
  vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_193_softJet", &vars.NBjets_trackCountingHighEffBJetTags_193_softJet, "NBjets_trackCountingHighEffBJetTags_193_softJet/I"); 
  vars.m_reducedTree -> Branch("NBjets_trackCountingHighEffBJetTags_210_softJet", &vars.NBjets_trackCountingHighEffBJetTags_210_softJet, "NBjets_trackCountingHighEffBJetTags_210_softJet/I"); 
  vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_193_softJet", &vars.NBjets_trackCountingHighPurBJetTags_193_softJet, "NBjets_trackCountingHighPurBJetTags_193_softJet/I"); 
  vars.m_reducedTree -> Branch("NBjets_trackCountingHighPurBJetTags_210_softJet", &vars.NBjets_trackCountingHighPurBJetTags_210_softJet, "NBjets_trackCountingHighPurBJetTags_210_softJet/I"); 
 
 
 
 
 
 
 
 
 //~~~~ PV variables 
 vars.m_reducedTree -> Branch("nPV", &vars.nPV, "nPV/I"); 
 
 //~~~~ MC variables
 vars.m_reducedTree -> Branch("numPUMC",        &vars.numPUMC,       "numPUMC/I"); 
 vars.m_reducedTree -> Branch("numPUMCit",     &vars.numPUMCit,     "numPUMCit/I"); 
 vars.m_reducedTree -> Branch("numPUMCoot", &vars.numPUMCoot, "numPUMCoot/I"); 
 vars.m_reducedTree -> Branch("ptH", &vars.ptH, "ptH/D"); 
 
 
}


void InitializeTreeTrigger(Variables& vars, const std::vector<std::string> & HLTVector, treeReader& reader){

// std::vector < std::pair < std::string, std::vector<std::string> > > expandedHLTVector;
//  std::vector < std::pair < std::string, std::vector<int> > > expandedHLTVector;
//  std::vector < std::vector<int> > expandedHLTVector;
    
 //==== (1)     create list of trigger pieces: A_B*C_D* --> A_B, C_D
 //==== (2)     and create list of triggers: A* ---> A_1, A_43, ...
 std::string strStar ("*");
 for (int iHLT = 0; iHLT < HLTVector.size(); iHLT++){ 
 //==== (1)  
  size_t found;
  size_t pos0 = 0;
  std::vector <std::string> listExpandedHLTVector;
  while(1) { 
     found = HLTVector.at(iHLT).find(strStar, pos0);
     if (found != std::string::npos) {
        std::string tempName = HLTVector.at(iHLT).substr (pos0,found-1); // "generalities"          
        listExpandedHLTVector.push_back(tempName);
        pos0 = found+1;
     }
     else {
        break;
     }
   }

 //==== (2)  
  std::vector <int> numbersExpandedHLTVector;
  std::vector <std::string> namesExpandedHLTVector;
    
  int entryMAXt = reader.GetEntries();
  for(int iEvent = 0 ; iEvent < entryMAXt ; ++iEvent) {
   if (!(iEvent%(entryMAXt/10))) std::cout << " *** HLT *** " << HLTVector.at(iHLT) << " *** " << iEvent << ":" << entryMAXt << std::endl;
   
   reader.GetEntry(iEvent);
   for (int iReaderHLT = 0; iReaderHLT < reader.GetString("HLT_Names")->size(); iReaderHLT++){
    pos0 = 0;
    bool is_a_usable_trigger = true;
    for (int subPath = 0; subPath < listExpandedHLTVector.size(); subPath++){
      found = reader.GetString("HLT_Names")->at(iReaderHLT).find(listExpandedHLTVector.at(subPath), pos0);
      if (found == std::string::npos)  is_a_usable_trigger = false;
      else pos0 = found+1;
    }
    if  (is_a_usable_trigger) {
    
    
     bool alreadyDone = false;
     for (int selectedHLT = 0; selectedHLT < namesExpandedHLTVector.size(); selectedHLT++) {
       if (namesExpandedHLTVector.at(selectedHLT) == reader.GetString("HLT_Names")->at(iReaderHLT)) alreadyDone = true;
     }
    
     if (!alreadyDone) {    
       namesExpandedHLTVector.push_back(reader.GetString("HLT_Names")->at(iReaderHLT));
       numbersExpandedHLTVector.push_back(iReaderHLT);
      }
    }
  }
  
    for (int iReaderHLT = 0; iReaderHLT < reader.GetString("HLT_Names")->size(); iReaderHLT++){
      if (reader.GetString("HLT_Names")->at(iReaderHLT) == HLTVector.at(iHLT)) {
       numbersExpandedHLTVector.push_back(iReaderHLT);
       namesExpandedHLTVector.push_back(reader.GetString("HLT_Names")->at(iReaderHLT));
       }
    }
   }
 
 //  std::pair < std::string, std::vector<int> > pair_listExpandedHLTVector (HLTVector.at(iHLT), numbersExpandedHLTVector);
//  vars.expandedHLTVector.push_back(pair_listExpandedHLTVector);
  vars.expandedHLTVector.push_back(numbersExpandedHLTVector);
  vars.expandedNamesHLTVector.push_back(namesExpandedHLTVector);
   
   
   std::cout << " *** " << std::endl;
   std::cout << " *** "  << HLTVector.at(iHLT) << " *** " << std::endl;  
    for (int selectedHLT = 0; selectedHLT < namesExpandedHLTVector.size(); selectedHLT++) {
       std::cout << " [" << selectedHLT << " : " <<  namesExpandedHLTVector.size() << "]  " << HLTVector.at(iHLT) << " :: " << namesExpandedHLTVector.at(selectedHLT) << std::endl;
     }
   std::cout << " *** " << std::endl;   
 }

 //==== set branches ====
 vars.HLTVector_names_ = HLTVector;
 for (int iHLT = 0; iHLT < vars.HLTVector_names_.size(); iHLT++){
  vars.HLTVector_.push_back(-1);
 }
 vars.m_reducedTree -> Branch("HLTVectorNames","std::vector<std::string>",&vars.HLTVector_names_);
 vars.m_reducedTree -> Branch("HLTVector","std::vector<int>",&vars.HLTVector_);  
}


void SetTriggerVariables(Variables& vars, treeReader& reader){
 for (int iHLT = 0; iHLT < vars.HLTVector_names_.size(); iHLT++){
  vars.HLTVector_.at(iHLT) = -1;
 }

// 
// for (std::vector<std::string>::const_iterator iHLTA = vars.HLTVector_names_.begin(); iHLTA<vars.HLTVector_names_.end(); iHLTA++){
//  for (int iHLT = 0; iHLT < reader.GetString("HLT_Names")->size(); iHLT++){
//   if (reader.GetString("HLT_Names")->at(iHLT) == *iHLTA && reader.GetFloat("HLT_Accept")->at(iHLT) == 1) {
//    vars.HLTVector_.at(iHLTA - vars.HLTVector_names_.begin()) = 1;
//   }
//   else if (reader.GetString("HLT_Names")->at(iHLT) == *iHLTA && reader.GetFloat("HLT_Accept")->at(iHLT) != 1){
//    vars.HLTVector_.at(iHLTA - vars.HLTVector_names_.begin()) = 0;
//   }
//  }
// }
//


/*
 for (int iHLTExp = 0; iHLTExp < vars.expandedHLTVector.size(); iHLTExp++) {
    for (int iHLTList = 0; iHLTList < vars.expandedHLTVector.at(iHLTExp).size(); iHLTList++) {
     for (int iHLT = 0; iHLT < reader.GetString("HLT_Names")->size(); iHLT++){
       if (iHLT == vars.expandedHLTVector.at(iHLTExp).at(iHLTList) && reader.GetFloat("HLT_Accept")->at(iHLT) == 1) {
          vars.HLTVector_.at(iHLTExp) = 1;
        }
       else if (iHLT == vars.expandedHLTVector.at(iHLTExp).at(iHLTList) && reader.GetFloat("HLT_Accept")->at(iHLT) != 1){
        if (vars.HLTVector_.at(iHLTExp) != 1) vars.HLTVector_.at(iHLTExp) = 0;
       } 
     }
   }
 }    
 */
 
  for (int iHLTExp = 0; iHLTExp < vars.expandedNamesHLTVector.size(); iHLTExp++) {
    for (int iHLTList = 0; iHLTList < vars.expandedNamesHLTVector.at(iHLTExp).size(); iHLTList++) {
     for (int iHLT = 0; iHLT < reader.GetString("HLT_Names")->size(); iHLT++){
       if (reader.GetString("HLT_Names")->at(iHLT) == vars.expandedNamesHLTVector.at(iHLTExp).at(iHLTList) && reader.GetFloat("HLT_Accept")->at(iHLT) == 1) {
          vars.HLTVector_.at(iHLTExp) = 1;
        }
       else if (reader.GetString("HLT_Names")->at(iHLT) == vars.expandedNamesHLTVector.at(iHLTExp).at(iHLTList)  && reader.GetFloat("HLT_Accept")->at(iHLT) != 1){
        if (vars.HLTVector_.at(iHLTExp) != 1) vars.HLTVector_.at(iHLTExp) = 0;
       } 
     }
   }
 }    
 
 }





void FillTree(Variables& vars){
 vars.m_reducedTree -> Fill();
}

void FillEfficiencyTree(Variables& vars){
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


void SetLeptonsVariables(Variables& vars, treeReader& reader,const int& iLep1, const int& iLep2, const int& FlavourLep1, const int& FlavourLep2)
{
//  std::cerr << " iLep1 = " << iLep1 << std::endl;
//  std::cerr << " iLep2 = " << iLep2 << std::endl;
//  std::cerr << " FlavourLep1 = " << FlavourLep1 << std::endl;
//  std::cerr << " FlavourLep2 = " << FlavourLep2 << std::endl; 
 if (FlavourLep1 == 13) {
  vars.l1_pX = reader.Get4V("muons")->at(iLep1).X();
  vars.l1_pY = reader.Get4V("muons")->at(iLep1).Y();
  vars.l1_pZ = reader.Get4V("muons")->at(iLep1).Z();
  vars.l1_pT = reader.Get4V("muons")->at(iLep1).pt(); 
  vars.l1_E = reader.Get4V("muons")->at(iLep1).E();
  vars.l1_Eta = reader.Get4V("muons")->at(iLep1).Eta();
  vars.l1_Phi = reader.Get4V("muons")->at(iLep1).Phi(); 
  
  vars.l1_charge = reader.GetFloat("muons_charge")->at(iLep1);
  vars.l1_flavour = 13;
  vars.l1_dxy = reader.GetFloat("muons_dxy_PV")->at(iLep1) ;
  vars.l1_dz =reader.GetFloat("muons_dz_PV")->at(iLep1);
  vars.l1_3DipSig = 0; // reader.GetFloat("muons_3DipSignificance")->at(iLep1);
  vars.l1_tkIso = reader.GetFloat("muons_tkIsoR03")->at(iLep1);
  vars.l1_emIso =  reader.GetFloat("muons_emIsoR03")->at(iLep1);
  vars.l1_hadIso = reader.GetFloat("muons_hadIsoR03")->at(iLep1);
  vars.l1_isEB = -999;
  vars.l1_sigmaIetaIeta = -999;
  vars.l1_DphiIn = -999;
  vars.l1_DetaIn = -999;
  vars.l1_HOverE = -999;
  vars.l1_fbrem = -999; 
  vars.l1_EOverP = -999;
  vars.l1_tracker = reader.GetInt("muons_tracker")->at(iLep1);
  vars.l1_standalone = reader.GetInt("muons_standalone")->at(iLep1);
  vars.l1_global = reader.GetInt("muons_global")->at(iLep1);
  vars.l1_normalizedChi2 = reader.GetFloat("muons_normalizedChi2")->at(iLep1);
  vars.l1_numberOfValidTrackerHits = reader.GetInt("muons_numberOfValidTrackerHits")->at(iLep1);
  vars.l1_numberOfValidMuonHits = reader.GetInt("muons_numberOfValidMuonHits")->at(iLep1);
 }
 if (FlavourLep2 == 13) {
  vars.l2_pX = reader.Get4V("muons")->at(iLep2).X();
  vars.l2_pY = reader.Get4V("muons")->at(iLep2).Y();
  vars.l2_pZ = reader.Get4V("muons")->at(iLep2).Z();
  vars.l2_pT = reader.Get4V("muons")->at(iLep2).pt(); 
  vars.l2_E = reader.Get4V("muons")->at(iLep2).E();
  vars.l2_Eta = reader.Get4V("muons")->at(iLep2).Eta();
  vars.l2_Phi = reader.Get4V("muons")->at(iLep2).Phi();
  
  vars.l2_charge = reader.GetFloat("muons_charge")->at(iLep2);
  vars.l2_flavour = 13;
  vars.l2_dxy = reader.GetFloat("muons_dxy_PV")->at(iLep2) ;
  vars.l2_dz =reader.GetFloat("muons_dz_PV")->at(iLep2);
  vars.l2_3DipSig = 0; //reader.GetFloat("muons_3DipSignificance")->at(iLep2);
  vars.l2_tkIso = reader.GetFloat("muons_tkIsoR03")->at(iLep2);
  vars.l2_emIso =  reader.GetFloat("muons_emIsoR03")->at(iLep2);
  vars.l2_hadIso = reader.GetFloat("muons_hadIsoR03")->at(iLep2);
  vars.l2_isEB = -999;
  vars.l2_sigmaIetaIeta = -999;
  vars.l2_DphiIn = -999;
  vars.l2_DetaIn = -999;
  vars.l2_HOverE = -999;
  vars.l2_fbrem = -999; 
  vars.l2_EOverP = -999;
  vars.l2_tracker = reader.GetInt("muons_tracker")->at(iLep2);
  vars.l2_standalone = reader.GetInt("muons_standalone")->at(iLep2);
  vars.l2_global = reader.GetInt("muons_global")->at(iLep2);
  vars.l2_normalizedChi2 = reader.GetFloat("muons_normalizedChi2")->at(iLep2);
  vars.l2_numberOfValidTrackerHits = reader.GetInt("muons_numberOfValidTrackerHits")->at(iLep2);
  vars.l2_numberOfValidMuonHits = reader.GetInt("muons_numberOfValidMuonHits")->at(iLep2);
 }
 
 if (FlavourLep1 == 11) {
  vars.l1_pX = reader.Get4V("electrons")->at(iLep1).X();
  vars.l1_pY = reader.Get4V("electrons")->at(iLep1).Y();
  vars.l1_pZ = reader.Get4V("electrons")->at(iLep1).Z();
  vars.l1_pT = reader.Get4V("electrons")->at(iLep1).pt(); 
  vars.l1_E = reader.Get4V("electrons")->at(iLep1).E();
  vars.l1_Eta = reader.Get4V("electrons")->at(iLep1).Eta();
  vars.l1_Phi = reader.Get4V("electrons")->at(iLep1).Phi();
  
  vars.l1_charge = reader.GetFloat("electrons_charge")->at(iLep1);
  vars.l1_flavour = 11;
  vars.l1_dxy = reader.GetFloat("electrons_dxy_PV")->at(iLep1) ;
  vars.l1_dz =reader.GetFloat("electrons_dz_PV")->at(iLep1);
  vars.l1_3DipSig = 0; //reader.GetFloat("electrons_3DipSignificance")->at(iLep1);
  vars.l1_tkIso = reader.GetFloat("electrons_tkIsoR03")->at(iLep1);
  vars.l1_emIso =  reader.GetFloat("electrons_emIsoR03")->at(iLep1);
  vars.l1_hadIso = reader.GetFloat("electrons_hadIsoR03_depth1")->at(iLep1)+reader.GetFloat("electrons_hadIsoR03_depth2")->at(iLep1);
  vars.l1_isEB = reader.GetInt("electrons_isEB")->at(iLep1) ;
  vars.l1_sigmaIetaIeta = reader.GetFloat("electrons_sigmaIetaIeta")->at(iLep1);
  vars.l1_DphiIn = reader.GetFloat("electrons_deltaPhiIn")->at(iLep1);
  vars.l1_DetaIn = reader.GetFloat("electrons_deltaEtaIn")->at(iLep1);
  vars.l1_HOverE = reader.GetFloat("electrons_hOverE")->at(iLep1);
  vars.l1_fbrem = reader.GetFloat("electrons_fbrem")->at(iLep1); 
  vars.l1_EOverP = reader.GetFloat("electrons_eSCOverP")->at(iLep1);
  vars.l1_tracker = -999;
  vars.l1_standalone = -999;
  vars.l1_global = -999;
  vars.l1_normalizedChi2 = -999;
  vars.l1_numberOfValidTrackerHits = -999;
  vars.l1_numberOfValidMuonHits = -999;
 }
 if (FlavourLep2 == 11) {
  vars.l2_pX = reader.Get4V("electrons")->at(iLep2).X();
  vars.l2_pY = reader.Get4V("electrons")->at(iLep2).Y();
  vars.l2_pZ = reader.Get4V("electrons")->at(iLep2).Z();
  vars.l2_pT = reader.Get4V("electrons")->at(iLep2).pt(); 
  vars.l2_E = reader.Get4V("electrons")->at(iLep2).E();
  vars.l2_Eta = reader.Get4V("electrons")->at(iLep2).Eta();
  vars.l2_Phi = reader.Get4V("electrons")->at(iLep2).Phi();
  
  vars.l2_charge = reader.GetFloat("electrons_charge")->at(iLep2);
  vars.l2_flavour = 11;
  vars.l2_dxy = reader.GetFloat("electrons_dxy_PV")->at(iLep2) ;
  vars.l2_dz =reader.GetFloat("electrons_dz_PV")->at(iLep2);
  vars.l2_3DipSig = 0; // reader.GetFloat("electrons_3DipSignificance")->at(iLep2);
  vars.l2_tkIso = reader.GetFloat("electrons_tkIsoR03")->at(iLep2);
  vars.l2_emIso =  reader.GetFloat("electrons_emIsoR03")->at(iLep2);
  vars.l2_hadIso = reader.GetFloat("electrons_hadIsoR03_depth1")->at(iLep2)+reader.GetFloat("electrons_hadIsoR03_depth2")->at(iLep2);
  vars.l2_isEB = reader.GetInt("electrons_isEB")->at(iLep2) ;
  vars.l2_sigmaIetaIeta = reader.GetFloat("electrons_sigmaIetaIeta")->at(iLep2);
  vars.l2_DphiIn = reader.GetFloat("electrons_deltaPhiIn")->at(iLep2);
  vars.l2_DetaIn = reader.GetFloat("electrons_deltaEtaIn")->at(iLep2);
  vars.l2_HOverE = reader.GetFloat("electrons_hOverE")->at(iLep2);
  vars.l2_fbrem = reader.GetFloat("electrons_fbrem")->at(iLep2); 
  vars.l2_EOverP = reader.GetFloat("electrons_eSCOverP")->at(iLep2);
  vars.l2_tracker = -999;
  vars.l2_standalone = -999;
  vars.l2_global = -999;
  vars.l2_normalizedChi2 = -999;
  vars.l2_numberOfValidTrackerHits = -999;
  vars.l2_numberOfValidMuonHits = -999;
 }
 
 double etaMean = (vars.q1_Eta + vars.q2_Eta) / 2.;
 double dEta = fabs(vars.q1_Eta - vars.q2_Eta);
 ///==== Zepp for lepton ====
 ///==== and ====
 ///==== Zepp for lepton system ====
 
 if (FlavourLep1 == 11 && FlavourLep2 == 11) {
  vars.M_ll = (reader.Get4V("electrons")->at(iLep1) + reader.Get4V("electrons")->at(iLep2)).mass();
  vars.DEta_ll = deltaEta(reader.Get4V("electrons")->at(iLep1).Eta() , reader.Get4V("electrons")->at(iLep2).Eta());
  vars.DPhi_ll = deltaPhi(reader.Get4V("electrons")->at(iLep1).Phi() , reader.Get4V("electrons")->at(iLep2).Phi());  
  vars.l1_Z = (reader.Get4V("electrons")->at(iLep1).Eta() - etaMean)/dEta;
  vars.l2_Z = (reader.Get4V("electrons")->at(iLep2).Eta() - etaMean)/dEta;
  vars.Z_ll = ((reader.Get4V("electrons")->at(iLep1) + reader.Get4V("electrons")->at(iLep2)).Eta() - etaMean)/dEta;
 }
 if (FlavourLep1 == 11 && FlavourLep2 == 13) {
  vars.M_ll = (reader.Get4V("electrons")->at(iLep1) + reader.Get4V("muons")->at(iLep2)).mass();
  vars.DEta_ll = deltaEta(reader.Get4V("electrons")->at(iLep1).Eta() , reader.Get4V("muons")->at(iLep2).Eta());
  vars.DPhi_ll = deltaPhi(reader.Get4V("electrons")->at(iLep1).Phi() , reader.Get4V("muons")->at(iLep2).Phi());  
  vars.l1_Z = (reader.Get4V("electrons")->at(iLep1).Eta() - etaMean)/dEta;
  vars.l2_Z = (reader.Get4V("muons")->at(iLep2).Eta() - etaMean)/dEta;
  vars.Z_ll = ((reader.Get4V("electrons")->at(iLep1) + reader.Get4V("muons")->at(iLep2)).Eta() - etaMean)/dEta;
 }
 if (FlavourLep1 == 13 && FlavourLep2 == 11) {
  vars.M_ll = (reader.Get4V("muons")->at(iLep1) + reader.Get4V("electrons")->at(iLep2)).mass();
  vars.DEta_ll = deltaEta(reader.Get4V("muons")->at(iLep1).Eta() , reader.Get4V("electrons")->at(iLep2).Eta());
  vars.DPhi_ll = deltaPhi(reader.Get4V("muons")->at(iLep1).Phi() , reader.Get4V("electrons")->at(iLep2).Phi());  
  vars.l1_Z = (reader.Get4V("muons")->at(iLep1).Eta() - etaMean)/dEta;
  vars.l2_Z = (reader.Get4V("electrons")->at(iLep2).Eta() - etaMean)/dEta;
  vars.Z_ll = ((reader.Get4V("muons")->at(iLep1) + reader.Get4V("electrons")->at(iLep2)).Eta() - etaMean)/dEta;
 }
 if (FlavourLep1 == 13 && FlavourLep2 == 13) {
  vars.M_ll = (reader.Get4V("muons")->at(iLep1) + reader.Get4V("muons")->at(iLep2)).mass();
  vars.DEta_ll = deltaEta(reader.Get4V("muons")->at(iLep1).Eta() , reader.Get4V("muons")->at(iLep2).Eta());
  vars.DPhi_ll = deltaPhi(reader.Get4V("muons")->at(iLep1).Phi() , reader.Get4V("muons")->at(iLep2).Phi());  
  vars.l1_Z = (reader.Get4V("muons")->at(iLep1).Eta() - etaMean)/dEta;
  vars.l2_Z = (reader.Get4V("muons")->at(iLep2).Eta() - etaMean)/dEta;
  vars.Z_ll = ((reader.Get4V("muons")->at(iLep1) + reader.Get4V("muons")->at(iLep2)).Eta() - etaMean)/dEta;
 }
}



void SetMetVariables(Variables& vars, treeReader& reader, const std::string& metType, const int& iLep1, const int& iLep2, const int& FlavourLep1, const int& FlavourLep2)
//void SetMetVariables(Variables& vars, treeReader& reader, const std::string& metType)
{
 double Lep1_phi = 100. ;
 if (FlavourLep1 == 11 ) Lep1_phi = reader.Get4V ("electrons")->at (iLep1).Phi () ;
 else Lep1_phi = reader.Get4V ("muons")->at (iLep1).Phi () ;
 double Lep2_phi = 100. ;
 if (FlavourLep2 == 11 ) Lep2_phi = reader.Get4V ("electrons")->at (iLep2).Phi () ;
 else Lep2_phi = reader.Get4V ("muons")->at (iLep2).Phi () ;

 double MET_phi = reader.Get4V (metType)->at (0).Phi () ;
 double deltaPhiMin = std::min (deltaPhi (MET_phi, Lep1_phi), deltaPhi (MET_phi, Lep2_phi)) ;

 if (deltaPhiMin < 1.57079632679) vars.pmet = reader.Get4V(metType)->at(0).P() * sin (deltaPhiMin) ;
 else vars.pmet = reader.Get4V(metType)->at(0).P() ;

 vars.met_X = reader.Get4V(metType)->at(0).X();
 vars.met_Y = reader.Get4V(metType)->at(0).Y();
 vars.met = reader.Get4V(metType)->at(0).P();
 


 double Lep1_eta = 100. ;
 if (FlavourLep1 == 11 ) Lep1_eta = reader.Get4V ("electrons")->at (iLep1).eta () ;
 else Lep1_eta = reader.Get4V ("muons")->at (iLep1).eta () ;
 double Lep2_eta = 100. ;
 if (FlavourLep2 == 11 ) Lep2_eta = reader.Get4V ("electrons")->at (iLep2).eta () ;
 else Lep2_eta = reader.Get4V ("muons")->at (iLep2).eta () ;

 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >  totalP4; 
 for(int iCand = 0; iCand <  reader.Get4V ("PFCandidate")->size(); iCand ++){
        double DPhi1 = deltaPhi (reader.Get4V ("PFCandidate")->at(iCand).Phi(), Lep1_phi);
        double DEta1 = Lep1_eta - reader.Get4V ("PFCandidate")->at(iCand).Eta();        
        double DR1 = sqrt(DPhi1 * DPhi1 + DEta1 * DEta1);
        
        double DPhi2 = deltaPhi (reader.Get4V ("PFCandidate")->at(iCand).Phi(), Lep2_phi);
        double DEta2 = Lep2_eta - reader.Get4V ("PFCandidate")->at(iCand).Eta();        
        double DR2 = sqrt(DPhi2 * DPhi2 + DEta2 * DEta2);
        
        if(DR1 <=0.1) continue;
        if(DR2 <=0.1) continue;
        totalP4 += reader.Get4V ("PFCandidate")->at(iCand);
 }
 
  if (FlavourLep1 == 11 ) totalP4 +=  reader.Get4V ("electrons")->at (iLep1);
  else totalP4 +=  reader.Get4V ("muons")->at (iLep1);

  if (FlavourLep2 == 11 ) totalP4 +=  reader.Get4V ("electrons")->at (iLep2);
  else totalP4 +=  reader.Get4V ("muons")->at (iLep2);

  vars.chmet = totalP4.Pt();
      
  totalP4 *= -1;  
  vars.chmet_X = totalP4.X();
  vars.chmet_Y = totalP4.Y();
  
  ///==== proj-chmet ====
  
 double chMET_phi = totalP4.Phi () ;
 deltaPhiMin = std::min (deltaPhi (chMET_phi, Lep1_phi), deltaPhi (chMET_phi, Lep2_phi)) ;

 if (deltaPhiMin < 1.57079632679) vars.pchmet = totalP4.Pt() * sin (deltaPhiMin) ;
 else vars.pchmet = totalP4.Pt() ;
  
  
 ///==== min Met ====
  vars.minMet=std::min(fabs(vars.pmet),fabs(vars.pchmet));
  
}

void SetEventVariables(Variables& vars, treeReader& reader)
{
 if (reader.GetInt("lumiId")->size() != 0) vars.lumiId = reader.GetInt("lumiId")->at(0);
 else vars.lumiId = -1;
 if (reader.GetInt("eventId")->size() != 0) vars.eventId = reader.GetInt("eventId")->at(0);
 else vars.eventId = -1;
 if (reader.GetInt("runId")->size() != 0) vars.runId = reader.GetInt("runId")->at(0);
 else vars.runId = -1;
}


void SetMCVariables(Variables& vars, treeReader& reader)
{
 if (reader.GetInt("mc_PUit_NumInteractions")->size() != 0) {
  vars.numPUMCit = reader.GetInt("mc_PUit_NumInteractions")->at(0);
 }
 else {
  vars.numPUMCit = -1;
 }
 
 if (reader.GetInt("mc_PUoot_NumInteractions")->size() != 0) {
 
  vars.numPUMCoot = 0;
  
  for (int iter = 0; iter<reader.GetInt("mc_PUoot_NumInteractions")->size(); iter++) {
     vars.numPUMCoot += reader.GetInt("mc_PUoot_NumInteractions")->at(iter);
  }
//  vars.numPUMCoot = reader.GetFloat("mc_PUoot_zpositions")->size();
//  std::cout << " (A) = " <<  vars.numPUMCoot << " --- (B) = " << reader.GetFloat("mc_PUoot_zpositions")->size() << std::endl;
//  vars.numPUMCoot = reader.GetInt("mc_PUoot_NumInteractions")->at(0);
 }
 else {
  vars.numPUMCoot = -1;
 }
 
 if ( vars.numPUMCit != -1 && vars.numPUMCoot != -1) {
  vars.numPUMC = (vars.numPUMCit + vars.numPUMCoot + 0.5) / 3;
 }
 else  if ( vars.numPUMCit != -1) {
   vars.numPUMC = vars.numPUMCit;
 } else   if ( vars.numPUMCoot != -1) {
   vars.numPUMC = (vars.numPUMCoot + 0.5) / 2;
 } else {
    vars.numPUMC = -1;
 }

 
 if (reader.Get4V("mc_H")->size() != 0) {
  vars.ptH = reader.Get4V("mc_H")->at(0).Pt();
 }
 else {
  vars.ptH = -1;
 }
 
}


void SetPVVariables(Variables& vars, treeReader& reader)
{
 vars.nPV = reader.GetInt("PV_ndof")->size();
}


void SetQJetVariables(Variables& vars, treeReader& reader, const int& q1, const int& q2, const std::vector<int>& blacklistJet_forCJV, const std::vector<int>& blacklistJet_forBtag, const std::vector<int>& blacklistJet_forTotalCJV)
{
 vars.q1_pX = reader.Get4V("jets")->at(q1).X();
 vars.q1_pY = reader.Get4V("jets")->at(q1).Y();
 vars.q1_pZ = reader.Get4V("jets")->at(q1).Z();
 vars.q1_pT = reader.Get4V("jets")->at(q1).pt();
 vars.q1_E = reader.Get4V("jets")->at(q1).E();
 vars.q1_Eta = reader.Get4V("jets")->at(q1).Eta();
 vars.q1_Phi = reader.Get4V("jets")->at(q1).Phi();
 vars.q1_bTag_trackCountingHighPurBJetTags = reader.GetFloat("trackCountingHighPurBJetTags")->at(q1);
 vars.q1_bTag_trackCountingHighEffBJetTags = reader.GetFloat("trackCountingHighEffBJetTags")->at(q1);
 
 vars.q2_pX = reader.Get4V("jets")->at(q2).X();
 vars.q2_pY = reader.Get4V("jets")->at(q2).Y();
 vars.q2_pZ = reader.Get4V("jets")->at(q2).Z();
 vars.q2_pT = reader.Get4V("jets")->at(q2).pt();
 vars.q2_E = reader.Get4V("jets")->at(q2).E();
 vars.q2_Eta = reader.Get4V("jets")->at(q2).Eta();
 vars.q2_Phi = reader.Get4V("jets")->at(q2).Phi();
 vars.q2_bTag_trackCountingHighPurBJetTags = reader.GetFloat("trackCountingHighPurBJetTags")->at(q2);
 vars.q2_bTag_trackCountingHighEffBJetTags = reader.GetFloat("trackCountingHighEffBJetTags")->at(q2);
 
 vars.M_qq = (reader.Get4V("jets")->at(q1) + reader.Get4V("jets")->at(q2)).mass();
 vars.DEta_qq = deltaEta(reader.Get4V("jets")->at(q1).Eta() , reader.Get4V("jets")->at(q2).Eta());
 vars.DPhi_qq = deltaPhi(reader.Get4V("jets")->at(q1).Phi() , reader.Get4V("jets")->at(q2).Phi());
 
 vars.CJV_20 = getCJV(*(reader.Get4V("jets")),q1,q2,20.,&blacklistJet_forCJV);
 vars.CJV_30 = getCJV(*(reader.Get4V("jets")),q1,q2,30.,&blacklistJet_forCJV);
 vars.CJV_40 = getCJV(*(reader.Get4V("jets")),q1,q2,40.,&blacklistJet_forCJV);
 
 vars.JV_20 = getJV(*(reader.Get4V("jets")),20.,&blacklistJet_forCJV);
 vars.JV_30 = getJV(*(reader.Get4V("jets")),30.,&blacklistJet_forCJV);
 vars.JV_40 = getJV(*(reader.Get4V("jets")),40.,&blacklistJet_forCJV);
 
 
 vars.q_Z_01_20 = getZepp(*(reader.Get4V("jets")),q1,q2,20.,0.1,&blacklistJet_forCJV);
 vars.q_Z_03_20 = getZepp(*(reader.Get4V("jets")),q1,q2,20.,0.3,&blacklistJet_forCJV);
 vars.q_Z_05_20 = getZepp(*(reader.Get4V("jets")),q1,q2,20.,0.5,&blacklistJet_forCJV);
 vars.q_Z_07_20 = getZepp(*(reader.Get4V("jets")),q1,q2,20.,0.7,&blacklistJet_forCJV);
 vars.q_Z_09_20 = getZepp(*(reader.Get4V("jets")),q1,q2,20.,0.9,&blacklistJet_forCJV);
 vars.q_Z_10_20 = getZepp(*(reader.Get4V("jets")),q1,q2,20.,1.0,&blacklistJet_forCJV);
 vars.q_Z_12_20 = getZepp(*(reader.Get4V("jets")),q1,q2,20.,1.2,&blacklistJet_forCJV);
 vars.q_Z_14_20 = getZepp(*(reader.Get4V("jets")),q1,q2,20.,1.4,&blacklistJet_forCJV);
 
 vars.q_Z_01_30 = getZepp(*(reader.Get4V("jets")),q1,q2,30.,0.1,&blacklistJet_forCJV);
 vars.q_Z_03_30 = getZepp(*(reader.Get4V("jets")),q1,q2,30.,0.3,&blacklistJet_forCJV);
 vars.q_Z_05_30 = getZepp(*(reader.Get4V("jets")),q1,q2,30.,0.5,&blacklistJet_forCJV);
 vars.q_Z_07_30 = getZepp(*(reader.Get4V("jets")),q1,q2,30.,0.7,&blacklistJet_forCJV);
 vars.q_Z_09_30 = getZepp(*(reader.Get4V("jets")),q1,q2,30.,0.9,&blacklistJet_forCJV);
 vars.q_Z_10_30 = getZepp(*(reader.Get4V("jets")),q1,q2,30.,1.0,&blacklistJet_forCJV);
 vars.q_Z_12_30 = getZepp(*(reader.Get4V("jets")),q1,q2,30.,1.2,&blacklistJet_forCJV);
 vars.q_Z_14_30 = getZepp(*(reader.Get4V("jets")),q1,q2,30.,1.4,&blacklistJet_forCJV);
 
 vars.q_Z_01_40 = getZepp(*(reader.Get4V("jets")),q1,q2,40.,0.1,&blacklistJet_forCJV);
 vars.q_Z_03_40 = getZepp(*(reader.Get4V("jets")),q1,q2,40.,0.3,&blacklistJet_forCJV);
 vars.q_Z_05_40 = getZepp(*(reader.Get4V("jets")),q1,q2,40.,0.5,&blacklistJet_forCJV);
 vars.q_Z_07_40 = getZepp(*(reader.Get4V("jets")),q1,q2,40.,0.7,&blacklistJet_forCJV);
 vars.q_Z_09_40 = getZepp(*(reader.Get4V("jets")),q1,q2,40.,0.9,&blacklistJet_forCJV);
 vars.q_Z_10_40 = getZepp(*(reader.Get4V("jets")),q1,q2,40.,1.0,&blacklistJet_forCJV);
 vars.q_Z_12_40 = getZepp(*(reader.Get4V("jets")),q1,q2,40.,1.2,&blacklistJet_forCJV);
 vars.q_Z_14_40 = getZepp(*(reader.Get4V("jets")),q1,q2,40.,1.4,&blacklistJet_forCJV);
 
 
 vars.NBjets_trackCountingHighEffBJetTags_193_softJet = 0;
 vars.NBjets_trackCountingHighEffBJetTags_210_softJet = 0;
 vars.NBjets_trackCountingHighPurBJetTags_193_softJet = 0;
 vars.NBjets_trackCountingHighPurBJetTags_210_softJet = 0;

 vars.NBjets_trackCountingHighPurBJetTags = 0;
 vars.NBjets_trackCountingHighEffBJetTags = 0;

 vars.NBjets_trackCountingHighPurBJetTags_m20 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_m15 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_m10 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_m05 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_m04 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_m03 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_m02 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_m01 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_00 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_01 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_02 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_03 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_04 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_05 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_10 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_20 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_21 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_22 = 0;
 vars.NBjets_trackCountingHighPurBJetTags_30 = 0;
 
 vars.NBjets_trackCountingHighEffBJetTags_m20 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_m15 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_m10 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_m05 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_m04 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_m03 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_m02 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_m01 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_00 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_01 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_02 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_03 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_04 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_05 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_10 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_20 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_21 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_22 = 0;
 vars.NBjets_trackCountingHighEffBJetTags_30 = 0;
 
 for (int iJet = 0; iJet < reader.Get4V("jets")->size(); iJet++){
  bool skipJet = false;
  for(unsigned int kk = 0; kk < blacklistJet_forBtag.size(); ++kk) {
   if(blacklistJet_forBtag.at(kk) == static_cast<int>(iJet)) skipJet = true;
  }
  if (reader.Get4V("jets")->at(iJet).pt() < 20.0) skipJet = true;
      if (skipJet) continue;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) > -50.0) vars.NBjets_trackCountingHighPurBJetTags++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) > -50.0) vars.NBjets_trackCountingHighEffBJetTags++;

      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) > -2.0) vars.NBjets_trackCountingHighPurBJetTags_m20++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) > -1.5) vars.NBjets_trackCountingHighPurBJetTags_m15++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) > -1.0) vars.NBjets_trackCountingHighPurBJetTags_m10++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) > -0.5) vars.NBjets_trackCountingHighPurBJetTags_m05++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) > -0.4) vars.NBjets_trackCountingHighPurBJetTags_m04++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) > -0.3) vars.NBjets_trackCountingHighPurBJetTags_m03++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) > -0.2) vars.NBjets_trackCountingHighPurBJetTags_m02++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) > -0.1) vars.NBjets_trackCountingHighPurBJetTags_m01++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  0.0) vars.NBjets_trackCountingHighPurBJetTags_00++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  0.1) vars.NBjets_trackCountingHighPurBJetTags_01++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  0.2) vars.NBjets_trackCountingHighPurBJetTags_02++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  0.3) vars.NBjets_trackCountingHighPurBJetTags_03++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  0.4) vars.NBjets_trackCountingHighPurBJetTags_04++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  0.5) vars.NBjets_trackCountingHighPurBJetTags_05++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  1.0) vars.NBjets_trackCountingHighPurBJetTags_10++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  1.5) vars.NBjets_trackCountingHighPurBJetTags_15++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  2.0) vars.NBjets_trackCountingHighPurBJetTags_20++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  2.1) vars.NBjets_trackCountingHighPurBJetTags_21++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  2.2) vars.NBjets_trackCountingHighPurBJetTags_22++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >  3.0) vars.NBjets_trackCountingHighPurBJetTags_30++;      
 
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) > -2.0) vars.NBjets_trackCountingHighEffBJetTags_m20++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) > -1.5) vars.NBjets_trackCountingHighEffBJetTags_m15++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) > -1.0) vars.NBjets_trackCountingHighEffBJetTags_m10++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) > -0.5) vars.NBjets_trackCountingHighEffBJetTags_m05++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) > -0.4) vars.NBjets_trackCountingHighEffBJetTags_m04++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) > -0.3) vars.NBjets_trackCountingHighEffBJetTags_m03++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) > -0.2) vars.NBjets_trackCountingHighEffBJetTags_m02++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) > -0.1) vars.NBjets_trackCountingHighEffBJetTags_m01++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  0.0) vars.NBjets_trackCountingHighEffBJetTags_00++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  0.1) vars.NBjets_trackCountingHighEffBJetTags_01++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  0.2) vars.NBjets_trackCountingHighEffBJetTags_02++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  0.3) vars.NBjets_trackCountingHighEffBJetTags_03++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  0.4) vars.NBjets_trackCountingHighEffBJetTags_04++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  0.5) vars.NBjets_trackCountingHighEffBJetTags_05++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  1.0) vars.NBjets_trackCountingHighEffBJetTags_10++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  1.5) vars.NBjets_trackCountingHighEffBJetTags_15++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  2.0) vars.NBjets_trackCountingHighEffBJetTags_20++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  2.1) vars.NBjets_trackCountingHighEffBJetTags_21++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  2.2) vars.NBjets_trackCountingHighEffBJetTags_22++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >  3.0) vars.NBjets_trackCountingHighEffBJetTags_30++;      
      
 }
 
 
 ///==== soft jet tagging ====
 
 
 for (int iJet = 0; iJet < reader.Get4V("jets")->size(); iJet++){
  bool skipJet = false;
  for(unsigned int kk = 0; kk < blacklistJet_forBtag.size(); ++kk) {
   if(blacklistJet_forBtag.at(kk) == static_cast<int>(iJet)) skipJet = true;
  }
  if (reader.Get4V("jets")->at(iJet).pt() >= 30.0 || reader.Get4V("jets")->at(iJet).pt() <= 7) skipJet = true;
      if (skipJet) continue;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >= 1.93) vars.NBjets_trackCountingHighEffBJetTags_193_softJet ++;
      if (reader.GetFloat("trackCountingHighEffBJetTags")->at(iJet) >= 2.10) vars.NBjets_trackCountingHighEffBJetTags_210_softJet ++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >= 1.93) vars.NBjets_trackCountingHighPurBJetTags_193_softJet ++;
      if (reader.GetFloat("trackCountingHighPurBJetTags")->at(iJet) >= 2.10) vars.NBjets_trackCountingHighPurBJetTags_210_softJet ++;
 }
 
 
 ///==== Jet Counter ====
 
 vars.totalJV_20 = getJV(*(reader.Get4V("jets")),20.,&blacklistJet_forTotalCJV);
 vars.totalJV_30 = getJV(*(reader.Get4V("jets")),30.,&blacklistJet_forTotalCJV);
 vars.totalJV_40 = getJV(*(reader.Get4V("jets")),40.,&blacklistJet_forTotalCJV);
 
}


///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void SetNSoftMu(Variables& vars,  treeReader& reader,  const int& iLep1, const int& iLep2, const int& FlavourLep1, const int& FlavourLep2){
  int NumSoftMu = 0;
  for(int iMu=0;iMu<reader.Get4V("muons")->size();iMu++){ 
     bool skipMu=false;
     bool flag_soft= IsMu_Soft(reader,iMu);  
    if (
      flag_soft && 
      ( FlavourLep1 != 13  ||  iMu != iLep1) &&
      ( FlavourLep2 != 13  ||  iMu != iLep2)
      ) {
       NumSoftMu++;
       }
  }
  vars.NsoftMu = NumSoftMu;
}


///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void SetMTVariable(Variables& vars, treeReader& reader, const std::string& metType, const int& iLep1, const int& iLep2, const int& FlavourLep1, const int& FlavourLep2){

 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >  totalP4; 
 
  if(FlavourLep1==11 && FlavourLep2==11)
     totalP4=reader.Get4V ("electrons")->at (iLep1)+reader.Get4V ("electrons")->at (iLep2);

  if(FlavourLep1==11 && FlavourLep2==13)
    totalP4=reader.Get4V ("electrons")->at (iLep1)+reader.Get4V ("muons")->at (iLep2);

  if(FlavourLep1==13 && FlavourLep2==11)
    totalP4=reader.Get4V ("muons")->at (iLep1)+reader.Get4V ("electrons")->at (iLep2);

   if(FlavourLep1==13 && FlavourLep2==13)
     totalP4=reader.Get4V ("muons")->at (iLep1)+reader.Get4V ("muons")->at (iLep2);

    double DeltaPhipfMet=fabs(deltaPhi(totalP4.Phi(),reader.Get4V(metType)->at(0).Phi()));

    vars.mT=sqrt(2*totalP4.Pt()*reader.Get4V(metType)->at(0).Pt()*(1-cos(DeltaPhipfMet)));
    
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void SetDPhiJetll(Variables& vars, treeReader& reader, const int& iLep1, const int& iLep2, const int& FlavourLep1, const int& FlavourLep2, const int& q1, const int& q2){

 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >  totalP4; 

  if(FlavourLep1==11 && FlavourLep2==11)
     totalP4 = reader.Get4V ("electrons")->at (iLep1)+reader.Get4V ("electrons")->at (iLep2);

  if(FlavourLep1==11 && FlavourLep2==13)
    totalP4 = reader.Get4V ("electrons")->at (iLep1)+reader.Get4V ("muons")->at (iLep2);

  if(FlavourLep1==13 && FlavourLep2==11)
    totalP4 = reader.Get4V ("muons")->at (iLep1)+reader.Get4V ("electrons")->at (iLep2);

   if(FlavourLep1==13 && FlavourLep2==13)
     totalP4 = reader.Get4V ("muons")->at (iLep1)+reader.Get4V ("muons")->at (iLep2);

  vars.DPhiSingleJet_ll    = fabs(deltaPhi(reader.Get4V("jets")->at(q1).Phi(),totalP4.Phi()));
  vars.DPhiDoubleJet_ll = fabs(deltaPhi((reader.Get4V("jets")->at(q1) + reader.Get4V("jets")->at(q2)).Phi(),totalP4.Phi()));


  vars.DPhiJet_ll = std::min (vars.DPhiSingleJet_ll, vars.DPhiDoubleJet_ll);
  vars.maxDPhiJet_ll = std::max (vars.DPhiSingleJet_ll, vars.DPhiDoubleJet_ll);
  
  
}


///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void SetJDVariables(Variables& vars, treeReader& reader, const int& iLep1, const int& iLep2, const int& FlavourLep1, const int& FlavourLep2, const int& q1, const int& q2, const std::string& metType){

 //-- Z direction
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >  totalZ; 
 
  if(FlavourLep1==11 && FlavourLep2==11)
     totalZ = reader.Get4V ("electrons")->at (iLep1)+reader.Get4V ("electrons")->at (iLep2);

  if(FlavourLep1==11 && FlavourLep2==13)
    totalZ = reader.Get4V ("electrons")->at (iLep1)+reader.Get4V ("muons")->at (iLep2);

  if(FlavourLep1==13 && FlavourLep2==11)
    totalZ = reader.Get4V ("muons")->at (iLep1)+reader.Get4V ("electrons")->at (iLep2);

   if(FlavourLep1==13 && FlavourLep2==13)
     totalZ = reader.Get4V ("muons")->at (iLep1)+reader.Get4V ("muons")->at (iLep2);

  //-- inversion of Z direction -> jet pair direction
   totalZ = - totalZ;

 //-- check that -Z is between jets -> angle -Z, jet1/2 < 90°
   vars.jd_dphi1 = fabs(deltaPhi(reader.Get4V("jets")->at(q1).Phi(),totalZ.Phi()));
   vars.jd_dphi2 = fabs(deltaPhi(reader.Get4V("jets")->at(q2).Phi(),totalZ.Phi()));
   
 //-- correction transverse direction of jets wrt -Z direction
  
   ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >  temp_q1 = reader.Get4V("jets")->at(q1); 
   ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> >  temp_q2 = reader.Get4V("jets")->at(q2); 

   ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag>    V_q1 = temp_q1.Vect();
   ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag>    V_q2 = temp_q2.Vect();   
   ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag>    V_Z  = totalZ.Vect();
  
   V_q1.SetZ (0);
   V_q2.SetZ (0);
   V_Z.SetZ (0);
      
   ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag> V_q1q2 = V_q1.Cross(V_q2);
   ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag> V_q1Z = V_q1.Cross(V_Z);
   ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag> V_Zq2 = V_Z.Cross(V_q2);

  if  ((V_q1q2.Z() * V_q1Z.Z()) > 0 && (V_q1Z.Z() * V_Zq2.Z()) > 0) {
   vars.jd_between = 1;
  }
  else {
   vars.jd_between = 0;
  }

//  if  (0) {
//  vars.jd_Delta_q1_P  = 1;
//  vars.jd_Delta_q2_P  = 1;
//
//   vars.jd_met = vars.met;
//   vars.jd_met_X = vars.met_X;
//   vars.jd_met_Y = vars.met_Y;
//
//   vars.jd_q1_pX = vars.q1_pX;
//   vars.jd_q1_pY = vars.q1_pY;
//   vars.jd_q1_pZ = vars.q1_pZ;
//   vars.jd_q1_pT = vars.q1_pT;
//   vars.jd_q1_E   = vars.q1_E;
//   vars.jd_q1_Eta = vars.q1_Eta;
//   vars.jd_q1_Phi = vars.q1_Phi;
// 
//   vars.jd_q2_pX = vars.q2_pX;
//   vars.jd_q2_pY = vars.q2_pY;
//   vars.jd_q2_pZ = vars.q2_pZ;
//   vars.jd_q2_pT = vars.q2_pT;
//   vars.jd_q2_E   = vars.q2_E;
//   vars.jd_q2_Eta = vars.q2_Eta;
//   vars.jd_q2_Phi = vars.q2_Phi;
   
//  }
//  else { 
 
  ///-- alpha * q1 + beta * q2 = -Z   
    
   double delta =  temp_q1.X() * temp_q2.Y()  -  temp_q1.Y() * temp_q2.X() ;
   double alpha =  (totalZ.X() * temp_q2.Y()  -  totalZ.Y() * temp_q2.X()) / delta;
   double beta   =  (totalZ.Y() * temp_q1.X()  -  totalZ.X() * temp_q1.Y()) / delta;

   ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > new_q1 = alpha * temp_q1;
   ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > new_q2 =   beta * temp_q2;   

   vars.jd_Delta_q1_P = alpha ;
   vars.jd_Delta_q2_P = beta ;

   vars.jd_q1_pX = new_q1.X() ;
   vars.jd_q1_pY = new_q1.Y();
   vars.jd_q1_pZ = new_q1.Z();
   vars.jd_q1_pT = new_q1.Rho();
   vars.jd_q1_E   = sqrt(vars.q1_E * vars.q1_E - temp_q1.Pt() * temp_q1.Pt() + new_q1.Rho() * new_q1.Rho());
   vars.jd_q1_Eta = vars.q1_Eta;
   vars.jd_q1_Phi = vars.q1_Phi;
 
   vars.jd_q2_pX = new_q2.X() ;
   vars.jd_q2_pY = new_q2.Y();
   vars.jd_q2_pZ = new_q2.Z();
   vars.jd_q2_pT = new_q2.Rho();
   vars.jd_q2_E   = sqrt(vars.q2_E * vars.q2_E - temp_q2.Pt() * temp_q2.Pt() + new_q2.Rho() * new_q2.Rho());
   vars.jd_q2_Eta = vars.q2_Eta;
   vars.jd_q2_Phi = vars.q2_Phi;

   vars.jd_met_X = vars.met_X + vars.q1_pX - vars.jd_q1_pX + vars.q2_pX - vars.jd_q2_pX;
   vars.jd_met_Y = vars.met_Y + vars.q1_pY - vars.jd_q1_pY + vars.q2_pY - vars.jd_q2_pY;

   vars.jd_met = sqrt ( vars.jd_met_X * vars.jd_met_X + vars.jd_met_Y * vars.jd_met_Y);

    vars.jd_M_qq = ( new_q1 + new_q2 ).mass();


   //---- project-jd-met ---- 
  double Lep1_phi = 100. ;
  if (FlavourLep1 == 11 ) Lep1_phi = reader.Get4V ("electrons")->at (iLep1).Phi () ;
  else Lep1_phi = reader.Get4V ("muons")->at (iLep1).Phi () ;
  double Lep2_phi = 100. ;
  if (FlavourLep2 == 11 ) Lep2_phi = reader.Get4V ("electrons")->at (iLep2).Phi () ;
  else Lep2_phi = reader.Get4V ("muons")->at (iLep2).Phi () ;

  double MET_phi = atan2(vars.jd_met_Y,vars.jd_met_X) ;
  double deltaPhiMin = std::min (deltaPhi (MET_phi, Lep1_phi), deltaPhi (MET_phi, Lep2_phi)) ;

 if (deltaPhiMin < 1.57079632679) vars.jd_pmet = vars.jd_met * sin (deltaPhiMin) ;
 else vars.jd_pmet = vars.jd_met;

//  }
}
 



