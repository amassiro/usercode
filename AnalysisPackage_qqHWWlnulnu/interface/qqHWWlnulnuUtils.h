/*
qqHWWlnulnuUtils
*/
#ifndef qqHWWlnulnuUtils_h
#define qqHWWlnulnuUtils_h

#include <vector>
#include <cmath>

#include "treeReader.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif

#include "Math/GenVector/VectorUtil.h"






///==== MC Decay Channel of V V ====
///==== lepton - lepton ==== < 1 ,   > 
///==== emu - emu ========== < 1 , 1 >
///==== emu - tau ========== < 1 , 2 >
///==== tau - emu ========== < 1 , 3 >
///==== tau - tau ========== < 1 , 4 >
///==== lepton - quark ===== < 2 ,   >
///==== emu - quark ======== < 2 , 1 >
///==== quark - emu ======== < 2 , 2 >
///==== tau - quark ======== < 2 , 3 >
///==== quark - tau ======== < 2 , 4 >
///==== quark - quark ====== < 3 , -1 >

std::pair<int,int> GetMCDecayChannel(const std::vector<float>& pdgId);
std::pair<int,int> GetMCDecayChannel(float pdgId11,float pdgId12, float pdgId21, float pdgId22);




///==== get GoodCombination ====
///==== return the value of the Max MVA and the corresponding number in the combinations ====
std::pair<double,int> GetCombinationMVA(treeReader& reader, std::vector<std::vector<int> >& combinations,TMVA::Reader* TMVAreader, TString& methodName, Float_t* input_variables, std::vector<int>* whitelistJet = NULL);


///==== return the value of the Min Chi2 and the corresponding number in the combinations ====
std::pair<double,int> GetCombinationChi2(treeReader& reader, std::vector<std::vector<int> >& combinations,std::vector<int>* whitelistJet);
 


///==== get Selected Lepton ====
int SelectLeptonTTBar(std::vector<ROOT::Math::XYZTVector>& leptons,const std::string& method,const double& ptMin,const double& etaMax,int& numLeptons,const std::vector<int>* blacklist);

///==== get Selected Muon ====
int SelectMuonTTBar(std::vector<ROOT::Math::XYZTVector>& leptons,
		    std::vector<float>& tkIso,
		    std::vector<float>& emIso,
		    std::vector<float>& hadIso,
		    const std::string& method,
		    const double& ptMin,
		    const double& etaMax,
		    const double& isoMax,
		    int& numLeptons,
		    const std::vector<int>* blacklist
		    );

///==== get Selected Electron ====
int SelectElectronTTBar(std::vector<ROOT::Math::XYZTVector>& leptons,
		    std::vector<float>& tkIso,
		    std::vector<float>& emIso,
		    std::vector<float>& hadIso,
		    std::vector<float>& eleId,
		    std::vector<float>& eled0,
		    const std::string& method,
		    const double& ptMin,
		    const double& etaMax,
		    const double& isoMax,
		    const double& d0Max,
		    int& numLeptons,
		    const std::vector<int>* blacklist
		    );

///==== get num Jets ====
int getNumJets(const std::vector<int>& whitelist);


///==== CopyTree ====
void CopyTree();



///==== get Jet Energy Correction ====
double getJEC(const ROOT::Math::XYZTVector& Jet);


///==== get best Combination Jet ID with MVA ====
std::pair<double,int> GetCombination_Jets_ID_MVA(std::vector<ROOT::Math::XYZTVector> &jets, std::vector<std::vector<int> >& combinations,TMVA::Reader* TMVAreader, TString& methodName, Float_t* input_variables, std::vector<int>* whitelistJet);
// std::pair<double,int> GetCombination_Jets_ID_MVA(treeReader& reader, std::vector<std::vector<int> >& combinations,TMVA::Reader* TMVAreader, TString& methodName, Float_t* input_variables, std::vector<int>* whitelistJet);
 
#endif

