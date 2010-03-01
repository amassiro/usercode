#include "treeReader.h"
#include "hFactory.h"
#include "hFunctions.h"
#include "stdHisto.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"



#include "JetCalibrator.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"
#include "Math/GenVector/VectorUtil.h"
#include "TRandom3.h"
#include <time.h>
#include <sstream>
#include "ntpleUtils.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif


double mT(const ROOT::Math::XYZTVector& v1, const ROOT::Math::XYZTVector& v2){
 return sqrt((v1.Et() + v2.Et()) * (v1.Et() + v2.Et()) - (v1 + v2).Pt() * (v1 + v2).Pt());
}


void Correct(std::vector<int> &matchIt){
 ///---- correct matchVector -> (1,2,4,3) => (1,2,3,4)
 if (matchIt.at(0) > matchIt.at(1)){
  double temp = matchIt.at(0);
  matchIt.at(0) = matchIt.at(1);
  matchIt.at(1) = temp;
 }
 if (matchIt.at(2) > matchIt.at(3)){
  double temp = matchIt.at(2);
  matchIt.at(2) = matchIt.at(3);
  matchIt.at(3) = temp;
 }
}

int CalculateMatch(std::vector<int> &matchIt,std::vector<int> & combination){
 int Match4 = 0;
 int q1 = combination.at(0);
 int q2 = combination.at(1);
 int b1 = combination.at(2);
 int b2 = combination.at(3);
 if (q1 == (matchIt.at(0)) || q1 == (matchIt.at(1))){
  Match4 ++;
 }
 if (q2 == (matchIt.at(0)) || q2 == (matchIt.at(1))){
  Match4 ++;
 }
 if (b1 == (matchIt.at(2)) || b1 == (matchIt.at(3))){
  Match4 ++;
 }
 if (b2 == (matchIt.at(2)) || b2 == (matchIt.at(3))){
  Match4 ++;
 }
 return Match4;
}



int main(int argc, char** argv)
{
 //Check if all nedeed arguments to parse are there                                                                                                                               
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }
 
 TRandom3 myRand;
//  double resolution = 0.2;

 // Parse the config file                                                                                                                                                          
 parseConfigFile (argv[1]) ;
 
 std::string treeName      = gConfigParser -> readStringOption("Input::treeName");
 std::string inputFileList = gConfigParser -> readStringOption("Input::inputFileList");
 
 int entryMAX = gConfigParser -> readIntOption("Input::entryMAX");
 int entryMIN = gConfigParser -> readIntOption("Input::entryMIN");
 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 
 std::cout << ">>>>> input::entryMIN  " << entryMIN  << std::endl;  
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 
 double resolution = gConfigParser -> readDoubleOption("Additional::resolution");
 
 // Open ntple
 TChain* chain = new TChain(treeName.c_str());
 if(!FillChain(*chain, inputFileList.c_str())) return 1;
 treeReader reader((TTree*)(chain));
 
 
 std::string outputFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << outputFileName  << std::endl;  
 
 TFile outFile(outputFileName.c_str(),"RECREATE");
 TTree outTree("outTree","outTree");
 
 
 double pT_RECO_q1;
 double pT_RECO_q2;
 
 double MT_Wqq_MC;
 double MT_Wln_MC;
 double MT_Wjj_MC;

 double nuPtSum_MC;
 double GenMetPtSum_MC;
 double nuEtSum_MC;
 double GenMetEtSum_MC;
 
 double nuPhi_MC;
 double GenMetPhi_MC;
 double nuPt_MC;
 double GenMetPt_MC;
 double nuEt_MC;
 double GenMetEt_MC;
 
 double mT_Wqq_MC;
 double mT_Wjj_MC;
 double mT_Wln_MC;
 double mT_Wln_2_MC;
 double mT_WlPFMET_MC;
 double mT_WlMET_MC;
 double mT_WlGenMET_MC;
 
 double mT_WRecolGenMet_MC;
 double mT_WRecolMet_MC;
 double mT_WRecolPFMet_MC;
 
 outTree.Branch("nuPtSum_MC",&nuPtSum_MC,"nuPtSum_MC/D");
 outTree.Branch("GenMetPtSum_MC",&GenMetPtSum_MC,"GenMetPtSum_MC/D");
 outTree.Branch("nuEtSum_MC",&nuEtSum_MC,"nuEtSum_MC/D");
 outTree.Branch("GenMetEtSum_MC",&GenMetEtSum_MC,"GenMetEtSum_MC/D");
 
 outTree.Branch("nuPhi_MC",&nuPhi_MC,"nuPhi_MC/D");
 outTree.Branch("GenMetPhi_MC",&GenMetPhi_MC,"GenMetPhi_MC/D");
 outTree.Branch("nuPt_MC",&nuPt_MC,"nuPt_MC/D");
 outTree.Branch("GenMetPt_MC",&GenMetPt_MC,"GenMetPt_MC/D");
 outTree.Branch("nuEt_MC",&nuEt_MC,"nuEt_MC/D");
 outTree.Branch("GenMetEt_MC",&GenMetEt_MC,"GenMetEt_MC/D");
 
 outTree.Branch("pT_RECO_q1",&pT_RECO_q1,"pT_RECO_q1/D");
 outTree.Branch("pT_RECO_q2",&pT_RECO_q2,"pT_RECO_q2/D");
 outTree.Branch("MT_Wjj_MC",&MT_Wjj_MC,"MT_Wjj_MC/D");
 outTree.Branch("MT_Wqq_MC",&MT_Wqq_MC,"MT_Wqq_MC/D");
 outTree.Branch("MT_Wln_MC",&MT_Wln_MC,"MT_Wln_MC/D");
 outTree.Branch("mT_Wln_2_MC",&mT_Wln_2_MC,"mT_Wln_2_MC/D");
 outTree.Branch("mT_Wjj_MC",&mT_Wjj_MC,"mT_Wjj_MC/D");
 outTree.Branch("mT_Wqq_MC",&mT_Wqq_MC,"mT_Wqq_MC/D");
 outTree.Branch("mT_Wln_MC",&mT_Wln_MC,"mT_Wln_MC/D");
 outTree.Branch("mT_WlPFMET_MC",&mT_WlPFMET_MC,"mT_WlPFMET_MC/D");
 outTree.Branch("mT_WlMET_MC",&mT_WlMET_MC,"mT_WlMET_MC/D");
 outTree.Branch("mT_WlGenMET_MC",&mT_WlGenMET_MC,"mT_WlGenMET_MC/D");
 outTree.Branch("mT_WRecolGenMet_MC",&mT_WRecolGenMet_MC,"mT_WRecolGenMet_MC/D");
 outTree.Branch("mT_WRecolMet_MC",&mT_WRecolMet_MC,"mT_WRecolMet_MC/D");
 outTree.Branch("mT_WRecolPFMet_MC",&mT_WRecolPFMet_MC,"mT_WRecolPFMet_MC/D");
 
 std::cout << ">>>>> tree::entries " << chain -> GetEntries()  << std::endl;
 entryMAX = std::min (static_cast<int>(entryMAX),static_cast<int>(chain -> GetEntries()));
 
 double start, end;
 std::vector<ROOT::Math::XYZTVector>* mcF_fromVandB = new std::vector<ROOT::Math::XYZTVector>;
 std::vector<ROOT::Math::XYZTVector>* mcF_fromWlnu = new std::vector<ROOT::Math::XYZTVector>;
 std::vector<ROOT::Math::XYZTVector>* mcF_fromWl = new std::vector<ROOT::Math::XYZTVector>;
 std::vector<ROOT::Math::XYZTVector>* mcF_fromWnu = new std::vector<ROOT::Math::XYZTVector>;
 
 start = clock();
 
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent)
 {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
  
  std::vector<ROOT::Math::XYZTVector>* mcV1 = reader.Get4V("mcV1");
  std::vector<ROOT::Math::XYZTVector>* mcV2 = reader.Get4V("mcV2");
  
  std::vector<float>* mcV1_charge = reader.GetFloat("mcV1_charge");
  std::vector<float>* mcV2_charge = reader.GetFloat("mcV2_charge");
  
  std::vector<ROOT::Math::XYZTVector>* mcF1_fromV1 = reader.Get4V("mcF1_fromV1");
  std::vector<ROOT::Math::XYZTVector>* mcF1_fromV2 = reader.Get4V("mcF1_fromV2");
  std::vector<ROOT::Math::XYZTVector>* mcF2_fromV1 = reader.Get4V("mcF2_fromV1");
  std::vector<ROOT::Math::XYZTVector>* mcF2_fromV2 = reader.Get4V("mcF2_fromV2");
  
  std::vector<float>* mcF1_fromV1_pdgId = reader.GetFloat("mcF1_fromV1_pdgId");
  std::vector<float>* mcF1_fromV2_pdgId = reader.GetFloat("mcF1_fromV2_pdgId");
  std::vector<float>* mcF2_fromV1_pdgId = reader.GetFloat("mcF2_fromV1_pdgId");
  std::vector<float>* mcF2_fromV2_pdgId = reader.GetFloat("mcF2_fromV2_pdgId");
  
  std::vector<ROOT::Math::XYZTVector>* mcB1 = reader.Get4V("mcB1");
  std::vector<ROOT::Math::XYZTVector>* mcB2 = reader.Get4V("mcB2");
  
  std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
  std::vector<float>* jets_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags");
  std::vector<float>* jets_trackCountingHighEffBJetTagsDR = reader.GetFloat("jets_trackCountingHighEffBJetTagsDR");
  std::vector<float>* jets_trackCountingHighPurBJetTags = reader.GetFloat("jets_trackCountingHighPurBJetTags");
  std::vector<float>* jets_simpleSecondaryVertexBJetTags = reader.GetFloat("jets_simpleSecondaryVertexBJetTags");
  std::vector<float>* jets_combinedSecondaryVertexBJetTags = reader.GetFloat("jets_combinedSecondaryVertexBJetTags");
  std::vector<float>* jets_combinedSecondaryVertexMVABJetTags = reader.GetFloat("jets_combinedSecondaryVertexMVABJetTags");
  
  std::vector<ROOT::Math::XYZTVector>* met    = reader.Get4V("met");
  std::vector<ROOT::Math::XYZTVector>* genMet = reader.Get4V("genMet");
  std::vector<ROOT::Math::XYZTVector>* pfMet  = reader.Get4V("PFMet");
  
  std::vector<ROOT::Math::XYZTVector>* electrons = reader.Get4V("electrons");
  std::vector<ROOT::Math::XYZTVector>* muons     = reader.Get4V("muons");
  
  
  
  ///---- find: q,q', b1, b2 ---- Pool ----
  
  mcF_fromWlnu->clear();
  mcF_fromWl->clear();
  mcF_fromWnu->clear();
  mcF_fromVandB->clear();
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 && fabs(mcF1_fromV2_pdgId->at(0)) <= 14){ //---- no tau!
   mcF_fromVandB->push_back(mcF1_fromV1->at(0));
   mcF_fromVandB->push_back(mcF2_fromV1->at(0));
   mcF_fromWlnu->push_back(mcF1_fromV2->at(0));
   mcF_fromWlnu->push_back(mcF2_fromV2->at(0));
   if (static_cast<int>(mcF1_fromV2_pdgId->at(0)) %2 == 0) {//---- neutrino
    mcF_fromWnu->push_back(mcF1_fromV2->at(0));
    mcF_fromWl->push_back(mcF2_fromV2->at(0));
   }
   else {
    mcF_fromWnu->push_back(mcF2_fromV2->at(0));
    mcF_fromWl->push_back(mcF1_fromV2->at(0));
   }
   
  } else if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4 && fabs(mcF1_fromV1_pdgId->at(0)) >= 11 && fabs(mcF1_fromV1_pdgId->at(0)) <= 14 ){
   mcF_fromVandB->push_back(mcF1_fromV2->at(0));
   mcF_fromVandB->push_back(mcF2_fromV2->at(0));
   mcF_fromWlnu->push_back(mcF1_fromV1->at(0));
   mcF_fromWlnu->push_back(mcF2_fromV1->at(0));

   if (static_cast<int>(mcF1_fromV1_pdgId->at(0)) %2 == 0) {//---- neutrino
    mcF_fromWnu->push_back(mcF1_fromV1->at(0));
    mcF_fromWl->push_back(mcF2_fromV1->at(0));
   }
   else {
    mcF_fromWnu->push_back(mcF2_fromV1->at(0));
    mcF_fromWl->push_back(mcF1_fromV1->at(0));
   }
   
  }
  
  mcF_fromVandB->push_back(mcB1->at(0));
  mcF_fromVandB->push_back(mcB2->at(0));
  
  
  
  if ( mcF_fromVandB->size() == 4 ){//---- only if at MC level found bb + qq' + (lnu) ----
   std::vector<int> matchIt;
   int matched = 0;
   matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromVandB,0.3,0.1,2.0,&matchIt);
   if (matched == 4){
    ///---- correct matchVector -> (1,2,4,3) => (1,2,3,4)
    Correct(matchIt);
    
    int q1 = matchIt.at(0);
    int q2 = matchIt.at(1);
    int b1 = matchIt.at(2);
    int b2 = matchIt.at(3);    
    
    pT_RECO_q1 = jets->at(q1).Pt();
    pT_RECO_q2 = jets->at(q2).Pt();
    
    MT_Wjj_MC = ((jets->at(q1) + jets->at(q2)).Mt());
    MT_Wqq_MC = ((mcF_fromVandB->at(0) + mcF_fromVandB->at(1)).Mt());    
    MT_Wln_MC = ((mcF_fromWlnu->at(0) + mcF_fromWlnu->at(1)).Mt());
    
    mT_Wjj_MC = mT(jets->at(q1),jets->at(q2));
    mT_Wqq_MC = mT(mcF_fromVandB->at(0),mcF_fromVandB->at(1));
    mT_Wln_MC = mT(mcF_fromWlnu->at(0),mcF_fromWlnu->at(1));

    mT_WlGenMET_MC =  mT(genMet->at(0),mcF_fromWl->at(0));
    mT_WlMET_MC = mT(met->at(0),mcF_fromWl->at(0));
    mT_WlPFMET_MC =  mT(pfMet->at(0),mcF_fromWl->at(0));
    
    mT_Wln_2_MC = mT(mcF_fromWl->at(0),mcF_fromWnu->at(0));
    
    GenMetPhi_MC = genMet->at(0).Phi();
    nuPhi_MC = mcF_fromWnu->at(0).Phi();
    
    GenMetPt_MC = genMet->at(0).Pt();
    nuPt_MC = mcF_fromWnu->at(0).Pt();

    GenMetEt_MC = genMet->at(0).Et();
    nuEt_MC = mcF_fromWnu->at(0).Et();
    
    nuPtSum_MC = (mcF_fromWnu->at(0) + mcF_fromWl->at(0)).Pt();
    GenMetPtSum_MC = (genMet->at(0) + mcF_fromWl->at(0)).Pt();

    nuEtSum_MC = (mcF_fromWnu->at(0) + mcF_fromWl->at(0)).Et();
    GenMetEtSum_MC = (genMet->at(0) + mcF_fromWl->at(0)).Et();
    
    
    std::vector<int> matchIt_lepton;
    int matched_lepton = 0;
    std::vector<ROOT::Math::XYZTVector>* leptons = new std::vector<ROOT::Math::XYZTVector>;
    for (int ivect = 0; ivect < electrons->size(); ivect++) leptons->push_back(electrons->at(ivect));
    for (int ivect = 0; ivect < muons->size(); ivect++) leptons->push_back(muons->at(ivect));
    matched_lepton = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*leptons,*mcF_fromWl,0.05,0.7,1.3,&matchIt_lepton);
    if (matched_lepton==1){
     double correction = 1;
     if (resolution != 0) correction = myRand.Gaus(1,resolution);
     mT_WRecolGenMet_MC =  mT(genMet->at(0),correction * leptons->at(matchIt_lepton.at(0)));
     mT_WRecolMet_MC =  mT(met->at(0),correction * leptons->at(matchIt_lepton.at(0)));
     mT_WRecolPFMet_MC =  mT(pfMet->at(0),correction * leptons->at(matchIt_lepton.at(0)));     
     outTree.Fill();    
    }
    
//     std::cerr << " Ratio = " << pfMet->at(0).Et() << " = " << met->at(0).Et() << " = " << genMet->at(0).Et() << " = " << mcF_fromWnu->at(0).Et() << " = " << mcF_fromWl->at(0).Et() << " = " << mcF_fromWlnu->at(0).Et() << " = " << mcF_fromWlnu->at(1).Et() << std::endl;
    
   }
  }
 } //loop over the events 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 delete mcF_fromVandB;  
 delete mcF_fromWlnu;  
 delete mcF_fromWl;  
 delete mcF_fromWnu;  
 
 outFile.Write();   

return 0;
}



