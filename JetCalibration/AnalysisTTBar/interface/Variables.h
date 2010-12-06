#include "treeReader.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"
#include "hFactory.h"
#include "h2Factory.h"
#include "stdHisto.h"

#include "TH1F.h"
#include "TProfile.h"
#include "TObject.h"
#include "TTree.h"

struct Variables
{
 //---- tree definition
 TFile* m_outputRootFile;
 TTree* m_reducedTree;
 TTree* m_efficiencyTree;
 
 
 //---- input parameters
 double XSection;
 int dataFlag; 
 int runId; 
 int lumiId; 
 int eventId; 
 int numEntriesBefore;
 
 
 //---- lepton variables
 double lep_pX;
 double lep_pY;
 double lep_pZ;
 double lep_pT;
 double lep_E;
 
 double lep_charge;
 int          lep_flavour;
 double lep_dxy;
 double lep_dz;
 double lep_3DipSig;
 double lep_tkIso;
 double lep_emIso;
 double lep_hadIso;
 int          lep_isEB;
 double lep_sigmaIetaIeta;
 double lep_DphiIn;
 double lep_DetaIn;
 double lep_HOverE;
 double lep_fbrem;
 double lep_EOverP;
 int          lep_tracker;
 int          lep_standalone;
 int          lep_global;
 double lep_normalizedChi2;
 int          lep_numberOfValidTrackerHits;
 int          lep_numberOfValidMuonHits;
 
 
 //---- met variables
 double met_X;
 double met_Y;
 double met;
 
 
 //---- jet variables
 double q1_pX;
 double q1_pY;
 double q1_pZ;
 double q1_pT;
 double q1_E;
 double q1_Eta;
 double q1_Phi;
 double q1_bTag_trackCountingHighPurBJetTags;
 double q1_bTag_trackCountingHighEffBJetTags;
 
 double q2_pX;
 double q2_pY;
 double q2_pZ;
 double q2_pT;
 double q2_E;
 double q2_Eta;
 double q2_Phi;
 double q2_bTag_trackCountingHighPurBJetTags;
 double q2_bTag_trackCountingHighEffBJetTags;
 
 double M_qq;
 double DEta_qq;
 double DPhi_qq;
 
 
 //---- jet variables
 double b1_pX;
 double b1_pY;
 double b1_pZ;
 double b1_pT;
 double b1_E;
 double b1_Eta;
 double b1_Phi;
 double b1_bTag_trackCountingHighPurBJetTags;
 double b1_bTag_trackCountingHighEffBJetTags;
 
 double b2_pX;
 double b2_pY;
 double b2_pZ;
 double b2_pT;
 double b2_E;
 double b2_Eta;
 double b2_Phi;
 double b2_bTag_trackCountingHighPurBJetTags;
 double b2_bTag_trackCountingHighEffBJetTags;
 
 double M_bb;
 double DEta_bb;
 double DPhi_bb;
 
};



void InitializeTree(Variables&, const std::string&);
void FillTree(Variables& vars);

void SetLeptonMuVariables(Variables& vars, treeReader& reader,const int& iLep);
void SetLeptonEleVariables(Variables& vars, treeReader& reader,const int& iLep);

void SetMetVariables(Variables& vars, treeReader& reader, const std::string& metType);

void SetQJetVariables(Variables& vars, treeReader& reader, const int& q1, const int& q2);
void SetBJetVariables(Variables& vars, treeReader& reader, const int& b1, const int& b2);

void SaveTree(Variables& vars);
