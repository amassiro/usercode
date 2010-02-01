/*
source ~/Desktop/setupRoot5.25.sh
rootcint -f dict.cpp -c LinkDef.h
c++ -o TT_IDENTIFY_1 `root-config --cflags --glibs` -lMinuit -lGenVector TT_IDENTIFY_1.cpp dict.cpp treeReader.cc
*/

///---- Identification method of correct jets in a ttbar sample ----

#include "treeReader.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"

#include "Math/GenVector/VectorUtil.h"

#include "TRandom3.h"

#include "src/Utils.cc"

#include <time.h>
#include <sstream>

#include "include/Utils.h"

int main (int argc, char ** argv)
{
 
 TFile f (argv[1]) ;
 TTree * tr = (TTree*) f.Get (argv[2]) ;
 treeReader reader (tr) ;
 
 TFile outFile(argv[3],"RECREATE");
 TTree outTree("outTree","outTree");
 double t_M_Reco;
 std::vector<double>* t_pT_Reco = new std::vector<double>;
 std::vector<double>* t_pT_MC = new std::vector<double>;
 std::vector<double>* t_Eta_Reco = new std::vector<double>;
 int t_Cycle_num; //---- 0 = Before, 1 = After
 int t_Indip; //---- 0 = No Indip, 1 = Indip
 
 outTree.Branch("t_pT_Reco","std::vector<double>",&t_pT_Reco);
 outTree.Branch("t_pT_MC","std::vector<double>",&t_pT_MC);
 outTree.Branch("t_Eta_Reco","std::vector<double>",&t_Eta_Reco);
 outTree.Branch("t_M_Reco",&t_M_Reco,"t_M_Reco/D");
 outTree.Branch("t_Cycle_num",&t_Cycle_num,"t_Cycle_num/I");
 outTree.Branch("t_Indip",&t_Indip,"t_Indip/I");
 
 TH1F DR_MC_qq("DR_MC_qq","DR_MC_qq",1000,0,4);
 TH1F DR_MC_bb("DR_MC_bb","DR_MC_bb",1000,0,4);
 TH1F DR_RECO_qq("DR_RECO_qq","DR_RECO_qq",1000,0,4);
 TH1F DR_RECO_bb("DR_RECO_bb","DR_RECO_bb",1000,0,4);
 
 TH1F DR_RECO_Not_qq("DR_RECO_Not_qq","DR_RECO_Not_qq",1000,0,4);
 TH1F DR_RECO_Not_bb("DR_RECO_Not_bb","DR_RECO_Not_bb",1000,0,4);
 
 
 TH1F DR_MC_qb("DR_MC_qb","DR_MC_qb",1000,0,4);
 TH1F DR_RECO_qb("DR_RECO_qb","DR_RECO_qb",1000,0,4);
 
 
 TH1F pT_MC_q("pT_MC_q","pT_MC_q",1000,0,200);
 TH1F pT_MC_b("pT_MC_b","pT_MC_b",1000,0,200);
 TH1F pT_RECO_q("pT_RECO_q","pT_RECO_q",1000,0,200);
 TH1F pT_RECO_b("pT_RECO_b","pT_RECO_b",1000,0,200);
 
 TH1F h_b_jets_trackCountingHighEffBJetTags("h_b_jets_trackCountingHighEffBJetTags","h_b_jets_trackCountingHighEffBJetTags",1000,0,40);
 TH1F h_q_jets_trackCountingHighEffBJetTags("h_q_jets_trackCountingHighEffBJetTags","h_q_jets_trackCountingHighEffBJetTags",1000,0,40);
 
 TH1F h_b_jets_trackCountingHighEffBJetTagsDR("h_b_jets_trackCountingHighEffBJetTagsDR","h_b_jets_trackCountingHighEffBJetTagsDR",1000,0,4);
 TH1F h_q_jets_trackCountingHighEffBJetTagsDR("h_q_jets_trackCountingHighEffBJetTagsDR","h_q_jets_trackCountingHighEffBJetTagsDR",1000,0,40);
 
 TH1F h_b_jets_trackCountingHighPurBJetTags("h_b_jets_trackCountingHighPurBJetTags","h_b_jets_trackCountingHighPurBJetTags",1000,0,40);
 TH1F h_q_jets_trackCountingHighPurBJetTags("h_q_jets_trackCountingHighPurBJetTags","h_q_jets_trackCountingHighPurBJetTags",1000,0,40);
 
 TH1F h_b_jets_simpleSecondaryVertexBJetTags("h_b_jets_simpleSecondaryVertexBJetTags","h_b_jets_simpleSecondaryVertexBJetTags",1000,0,40);
 TH1F h_q_jets_simpleSecondaryVertexBJetTags("h_q_jets_simpleSecondaryVertexBJetTags","h_q_jets_simpleSecondaryVertexBJetTags",1000,0,40);
 
 TH1F h_b_jets_combinedSecondaryVertexBJetTags("h_b_jets_combinedSecondaryVertexBJetTags","h_b_jets_combinedSecondaryVertexBJetTags",1000,0,40);
 TH1F h_q_jets_combinedSecondaryVertexBJetTags("h_q_jets_combinedSecondaryVertexBJetTags","h_q_jets_combinedSecondaryVertexBJetTags",1000,0,40);
 
 TH1F h_b_jets_combinedSecondaryVertexMVABJetTags("h_b_jets_combinedSecondaryVertexMVABJetTags","h_b_jets_combinedSecondaryVertexMVABJetTags",1000,0,40);
 TH1F h_q_jets_combinedSecondaryVertexMVABJetTags("h_q_jets_combinedSecondaryVertexMVABJetTags","h_q_jets_combinedSecondaryVertexMVABJetTags",1000,0,40);
 
 
 
 TH1F h_Not_b_jets_trackCountingHighEffBJetTags("h_Not_b_jets_trackCountingHighEffBJetTags","h_Not_b_jets_trackCountingHighEffBJetTags",1000,0,40);
 TH1F h_Not_q_jets_trackCountingHighEffBJetTags("h_Not_q_jets_trackCountingHighEffBJetTags","h_Not_q_jets_trackCountingHighEffBJetTags",1000,0,40);
 TH1F h_Not_b_jets_trackCountingHighEffBJetTagsDR("h_Not_b_jets_trackCountingHighEffBJetTagsDR","h_Not_b_jets_trackCountingHighEffBJetTagsDR",1000,0,4);
 TH1F h_Not_q_jets_trackCountingHighEffBJetTagsDR("h_Not_q_jets_trackCountingHighEffBJetTagsDR","h_Not_q_jets_trackCountingHighEffBJetTagsDR",1000,0,40);
 TH1F h_Not_b_jets_trackCountingHighPurBJetTags("h_Not_b_jets_trackCountingHighPurBJetTags","h_Not_b_jets_trackCountingHighPurBJetTags",1000,0,40);
 TH1F h_Not_q_jets_trackCountingHighPurBJetTags("h_Not_q_jets_trackCountingHighPurBJetTags","h_Not_q_jets_trackCountingHighPurBJetTags",1000,0,40);
 TH1F h_Not_b_jets_simpleSecondaryVertexBJetTags("h_Not_b_jets_simpleSecondaryVertexBJetTags","h_Not_b_jets_simpleSecondaryVertexBJetTags",1000,0,40);
 TH1F h_Not_q_jets_simpleSecondaryVertexBJetTags("h_Not_q_jets_simpleSecondaryVertexBJetTags","h_Not_q_jets_simpleSecondaryVertexBJetTags",1000,0,40);
 TH1F h_Not_b_jets_combinedSecondaryVertexBJetTags("h_Not_b_jets_combinedSecondaryVertexBJetTags","h_Not_b_jets_combinedSecondaryVertexBJetTags",1000,0,40);
 TH1F h_Not_q_jets_combinedSecondaryVertexBJetTags("h_Not_q_jets_combinedSecondaryVertexBJetTags","h_Not_q_jets_combinedSecondaryVertexBJetTags",1000,0,40);
 TH1F h_Not_b_jets_combinedSecondaryVertexMVABJetTags("h_Not_b_jets_combinedSecondaryVertexMVABJetTags","h_Not_b_jets_combinedSecondaryVertexMVABJetTags",1000,0,40);
 TH1F h_Not_q_jets_combinedSecondaryVertexMVABJetTags("h_Not_q_jets_combinedSecondaryVertexMVABJetTags","h_Not_q_jets_combinedSecondaryVertexMVABJetTags",1000,0,40);
 
 TH1F pT_RECO_Not_q("pT_RECO_Not_q","pT_RECO_Not_q",1000,0,200);
 TH1F pT_RECO_Not_b("pT_RECO_Not_b","pT_RECO_Not_b",1000,0,200);
 
 
 
 
 double start, end;
 
 int nentries =  tr->GetEntries ();
 std::cerr << "nentries = " << nentries << std::endl;
 if (argc >= 5) nentries = atoi(argv[4]);
 std::cerr << "nentries = " << nentries << std::endl;
 
 std::cerr << std::endl << "*** Fill Data ***" << std::endl;
 start = clock();
 for (int iEvent = 0 ; iEvent < nentries ; ++iEvent)
 {
  reader.GetEntry (iEvent) ;
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
  
  
  ///---- find: q,q', b1, b2 ---- Pool ----
  
  std::vector<ROOT::Math::XYZTVector>* mcF_fromVandB = new std::vector<ROOT::Math::XYZTVector>;
  if (fabs(mcF1_fromV1_pdgId->at(0)) <= 4 && fabs(mcF1_fromV2_pdgId->at(0)) >= 11 ){
   mcF_fromVandB->push_back(mcF1_fromV1->at(0));
   mcF_fromVandB->push_back(mcF2_fromV1->at(0));
  } else if (fabs(mcF1_fromV2_pdgId->at(0)) <= 4 && fabs(mcF1_fromV1_pdgId->at(0)) >= 11 ){
   mcF_fromVandB->push_back(mcF1_fromV2->at(0));
   mcF_fromVandB->push_back(mcF2_fromV2->at(0));
  }
  
  mcF_fromVandB->push_back(mcB1->at(0));
  mcF_fromVandB->push_back(mcB2->at(0));
  
  if ( mcF_fromVandB->size() != 4 ) continue; //---- only if at MC level found bb + qq' + (lnu) ----
  
  std::vector<int> matchIt;
  int matched = 0;
  matched = GetMatching<ROOT::Math::XYZTVector,ROOT::Math::XYZTVector>(*jets,*mcF_fromVandB,0.3,0.1,2.0,&matchIt);
  
  if (matched == 4){

   DR_MC_qq.Fill(ROOT::Math::VectorUtil::DeltaR(mcF_fromVandB->at(0),mcF_fromVandB->at(1)));
   DR_RECO_qq.Fill(ROOT::Math::VectorUtil::DeltaR(jets->at(matchIt.at(0)),jets->at(matchIt.at(1))));

   DR_MC_bb.Fill(ROOT::Math::VectorUtil::DeltaR(mcF_fromVandB->at(2),mcF_fromVandB->at(3)));
   DR_RECO_bb.Fill(ROOT::Math::VectorUtil::DeltaR(jets->at(matchIt.at(2)),jets->at(matchIt.at(3))));
  
   DR_MC_qb.Fill(std::min(ROOT::Math::VectorUtil::DeltaR(mcF_fromVandB->at(0),mcF_fromVandB->at(2)),ROOT::Math::VectorUtil::DeltaR(mcF_fromVandB->at(0),mcF_fromVandB->at(3))));
   DR_MC_qb.Fill(std::min(ROOT::Math::VectorUtil::DeltaR(mcF_fromVandB->at(1),mcF_fromVandB->at(2)),ROOT::Math::VectorUtil::DeltaR(mcF_fromVandB->at(1),mcF_fromVandB->at(3))));

   DR_RECO_qb.Fill(std::min(ROOT::Math::VectorUtil::DeltaR(jets->at(matchIt.at(0)),jets->at(matchIt.at(2))),ROOT::Math::VectorUtil::DeltaR(jets->at(matchIt.at(0)),jets->at(matchIt.at(3)))));
   DR_RECO_qb.Fill(std::min(ROOT::Math::VectorUtil::DeltaR(jets->at(matchIt.at(1)),jets->at(matchIt.at(2))),ROOT::Math::VectorUtil::DeltaR(jets->at(matchIt.at(1)),jets->at(matchIt.at(3)))));
      
   //---- fill "background" ----
   
   
   int q1 = -1;
   int q2 = -1;
   int b1 = -1;
   int b2 = -1;
   for (int ijet = 0; ijet < jets->size(); ijet++){
    if (ijet != (matchIt.at(0)) && ijet != (matchIt.at(1))){
     if (q1 == -1) {
      q1 = ijet;
     }
     else if (q2 == -1){
      q2 = ijet;
     }
    }
    if (ijet != (matchIt.at(2)) && ijet != (matchIt.at(3))){
     if (b1 == -1) {
      b1 = ijet;
     }
     else if (b2 == -1){
      b2 = ijet;
     }
    }
   }
   
   if (q1 != -1 && q2 != -1) {
    DR_RECO_Not_qq.Fill(ROOT::Math::VectorUtil::DeltaR(jets->at(q1),jets->at(q2)));
    h_Not_q_jets_trackCountingHighEffBJetTags.Fill(jets_trackCountingHighEffBJetTags->at(q1));
    h_Not_q_jets_trackCountingHighEffBJetTags.Fill(jets_trackCountingHighEffBJetTags->at(q2));
    h_Not_q_jets_trackCountingHighPurBJetTags.Fill(jets_trackCountingHighPurBJetTags->at(q1));
    h_Not_q_jets_trackCountingHighPurBJetTags.Fill(jets_trackCountingHighPurBJetTags->at(q2));
    h_Not_q_jets_simpleSecondaryVertexBJetTags.Fill(jets_simpleSecondaryVertexBJetTags->at(q1));
    h_Not_q_jets_simpleSecondaryVertexBJetTags.Fill(jets_simpleSecondaryVertexBJetTags->at(q2));   
    h_Not_q_jets_combinedSecondaryVertexBJetTags.Fill(jets_combinedSecondaryVertexBJetTags->at(q1));
    h_Not_q_jets_combinedSecondaryVertexBJetTags.Fill(jets_combinedSecondaryVertexBJetTags->at(q2));
    h_Not_q_jets_combinedSecondaryVertexMVABJetTags.Fill(jets_combinedSecondaryVertexMVABJetTags->at(q1));
    h_Not_q_jets_combinedSecondaryVertexMVABJetTags.Fill(jets_combinedSecondaryVertexMVABJetTags->at(q2));
    pT_RECO_Not_q.Fill(jets->at(q1).Pt());
    pT_RECO_Not_q.Fill(jets->at(q2).Pt());
   }
   if (b1 != -1 && b2 != -1) {
    DR_RECO_Not_bb.Fill(ROOT::Math::VectorUtil::DeltaR(jets->at(b1),jets->at(b2)));
    h_Not_b_jets_trackCountingHighEffBJetTags.Fill(jets_trackCountingHighEffBJetTags->at(b1));
    h_Not_b_jets_trackCountingHighEffBJetTags.Fill(jets_trackCountingHighEffBJetTags->at(b2));
    h_Not_b_jets_trackCountingHighPurBJetTags.Fill(jets_trackCountingHighPurBJetTags->at(b1));
    h_Not_b_jets_trackCountingHighPurBJetTags.Fill(jets_trackCountingHighPurBJetTags->at(b2));
    h_Not_b_jets_simpleSecondaryVertexBJetTags.Fill(jets_simpleSecondaryVertexBJetTags->at(b1));
    h_Not_b_jets_simpleSecondaryVertexBJetTags.Fill(jets_simpleSecondaryVertexBJetTags->at(b2));   
    h_Not_b_jets_combinedSecondaryVertexBJetTags.Fill(jets_combinedSecondaryVertexBJetTags->at(b1));
    h_Not_b_jets_combinedSecondaryVertexBJetTags.Fill(jets_combinedSecondaryVertexBJetTags->at(b2));
    h_Not_b_jets_combinedSecondaryVertexMVABJetTags.Fill(jets_combinedSecondaryVertexMVABJetTags->at(b1));
    h_Not_b_jets_combinedSecondaryVertexMVABJetTags.Fill(jets_combinedSecondaryVertexMVABJetTags->at(b2));
    pT_RECO_Not_b.Fill(jets->at(b1).Pt());
    pT_RECO_Not_b.Fill(jets->at(b2).Pt());
   }
   
   
   pT_MC_q.Fill(mcF_fromVandB->at(0).Pt());
   pT_MC_q.Fill(mcF_fromVandB->at(1).Pt());
   pT_MC_b.Fill(mcF_fromVandB->at(2).Pt());
   pT_MC_b.Fill(mcF_fromVandB->at(3).Pt());
   
   pT_RECO_q.Fill(jets->at(matchIt.at(0)).Pt());
   pT_RECO_q.Fill(jets->at(matchIt.at(1)).Pt());
   pT_RECO_b.Fill(jets->at(matchIt.at(2)).Pt());
   pT_RECO_b.Fill(jets->at(matchIt.at(3)).Pt());
   
   h_q_jets_trackCountingHighEffBJetTags.Fill(jets_trackCountingHighEffBJetTags->at(matchIt.at(0)));
   h_q_jets_trackCountingHighEffBJetTags.Fill(jets_trackCountingHighEffBJetTags->at(matchIt.at(1)));
   h_b_jets_trackCountingHighEffBJetTags.Fill(jets_trackCountingHighEffBJetTags->at(matchIt.at(2)));
   h_b_jets_trackCountingHighEffBJetTags.Fill(jets_trackCountingHighEffBJetTags->at(matchIt.at(3)));
   
   h_q_jets_trackCountingHighEffBJetTagsDR.Fill(jets_trackCountingHighEffBJetTagsDR->at(matchIt.at(0)));
   h_q_jets_trackCountingHighEffBJetTagsDR.Fill(jets_trackCountingHighEffBJetTagsDR->at(matchIt.at(1)));
   h_b_jets_trackCountingHighEffBJetTagsDR.Fill(jets_trackCountingHighEffBJetTagsDR->at(matchIt.at(2)));
   h_b_jets_trackCountingHighEffBJetTagsDR.Fill(jets_trackCountingHighEffBJetTagsDR->at(matchIt.at(3)));
   
   h_q_jets_trackCountingHighPurBJetTags.Fill(jets_trackCountingHighPurBJetTags->at(matchIt.at(0)));
   h_q_jets_trackCountingHighPurBJetTags.Fill(jets_trackCountingHighPurBJetTags->at(matchIt.at(1)));
   h_b_jets_trackCountingHighPurBJetTags.Fill(jets_trackCountingHighPurBJetTags->at(matchIt.at(2)));
   h_b_jets_trackCountingHighPurBJetTags.Fill(jets_trackCountingHighPurBJetTags->at(matchIt.at(3)));
   
   h_q_jets_simpleSecondaryVertexBJetTags.Fill(jets_simpleSecondaryVertexBJetTags->at(matchIt.at(0)));
   h_q_jets_simpleSecondaryVertexBJetTags.Fill(jets_simpleSecondaryVertexBJetTags->at(matchIt.at(1)));
   h_b_jets_simpleSecondaryVertexBJetTags.Fill(jets_simpleSecondaryVertexBJetTags->at(matchIt.at(2)));
   h_b_jets_simpleSecondaryVertexBJetTags.Fill(jets_simpleSecondaryVertexBJetTags->at(matchIt.at(3)));
   
   h_q_jets_combinedSecondaryVertexBJetTags.Fill(jets_combinedSecondaryVertexBJetTags->at(matchIt.at(0)));
   h_q_jets_combinedSecondaryVertexBJetTags.Fill(jets_combinedSecondaryVertexBJetTags->at(matchIt.at(1)));
   h_b_jets_combinedSecondaryVertexBJetTags.Fill(jets_combinedSecondaryVertexBJetTags->at(matchIt.at(2)));
   h_b_jets_combinedSecondaryVertexBJetTags.Fill(jets_combinedSecondaryVertexBJetTags->at(matchIt.at(3)));
   
   h_q_jets_combinedSecondaryVertexMVABJetTags.Fill(jets_combinedSecondaryVertexMVABJetTags->at(matchIt.at(0)));
   h_q_jets_combinedSecondaryVertexMVABJetTags.Fill(jets_combinedSecondaryVertexMVABJetTags->at(matchIt.at(1)));
   h_b_jets_combinedSecondaryVertexMVABJetTags.Fill(jets_combinedSecondaryVertexMVABJetTags->at(matchIt.at(2)));
   h_b_jets_combinedSecondaryVertexMVABJetTags.Fill(jets_combinedSecondaryVertexMVABJetTags->at(matchIt.at(3)));
   
      
  }
  delete mcF_fromVandB;
 }
 
 
 outFile.Write();   
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;
 
 delete t_pT_Reco;
 delete t_pT_MC;
 delete t_Eta_Reco;
 
 
 
 
 
 
 
 
 return 0 ;
}