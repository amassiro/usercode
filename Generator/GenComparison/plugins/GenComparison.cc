// -*- C++ -*-
//
// Package:    GenComparison
// Class:      GenComparison
// 
/**\class GenComparison GenComparison.cc Generator/GenComparison/plugins/GenComparison.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
 */
//
// Original Author:  Andrea Massironi
//         Created:  Tue, 10 Sep 2013 15:30:18 GMT
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

// my

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TTree.h"

// #include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/JetReco/interface/GenJetCollection.h"

#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/GenRunInfoProduct.h"



#include "Math/VectorUtil.h"

// #include "TLorentzVector.h"

//
// class declaration
//

class GenComparison : public edm::EDAnalyzer {
 public:
  explicit GenComparison(const edm::ParameterSet&);
  ~GenComparison();

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

 private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;

  void FindDaughterParticles(const reco::Candidate** pCurrent, std::vector<const reco::Candidate*>* pFinal) const;
  const float getVdecay(reco::GenParticleRefVector genParticles) const;
  const float getPtV(reco::GenParticleRefVector genParticles) const;
  const float getPtZ(reco::GenParticleRefVector genParticles) const;
  const float getPtW(reco::GenParticleRefVector genParticles) const;
  const float mjj (reco::GenJetRefVector genJets, reco::GenParticleRefVector genParticles) const;
  const float leadingGenJetPt (size_t index, reco::GenJetRefVector genJets, reco::GenParticleRefVector genParticles) const;
  const float leadingGenJetEta(size_t index, reco::GenJetRefVector genJets, reco::GenParticleRefVector genParticles) const;
  const int   nJets(float minPt,  reco::GenJetRefVector genJets, reco::GenParticleRefVector genParticles) const;

//   const bool isThisJetALepton(const reco::GenJet jet, reco::GenParticleRefVector genParticles, float drCut) const;
  const bool isThisJetALepton(const reco::GenJetRef jet, reco::GenParticleRefVector genParticles) const;

  const float leadingLHEJetPt(size_t index) const;

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------

  lhef::HEPEUP LHEhepeup_;

  bool isWH_;
  bool isZH_;

  bool saveLHE_;

  TTree* myTree_;

  float Vdecay_;

  float HiggsPt_;
  float HiggsEta_;

  float baseW_;

  float mjj_;

  float jetpt1_;
  float jeteta1_;
  float ptV_;

  int njet20_;
  int njet30_;

  int nmu_;

  float lhejetpt1_;

  //---- mass of W/Z from Higgs decay
  float mV1_;
  float mV2_;

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
GenComparison::GenComparison(const edm::ParameterSet& iConfig) {
 isWH_ = iConfig.getUntrackedParameter< bool >("isWH",false);
 isZH_ = iConfig.getUntrackedParameter< bool >("isZH",false);

 saveLHE_ = iConfig.getUntrackedParameter< bool >("saveLHE",false);

   //now do what ever initialization is needed
 edm::Service<TFileService> fs ;
 myTree_  =        fs -> make <TTree>("myTree","myTree");

 myTree_ -> Branch("Vdecay",   &Vdecay_, "Vdecay/F");

 myTree_ -> Branch("HiggsPt",  &HiggsPt_,  "HiggsPt/F");
 myTree_ -> Branch("HiggsEta", &HiggsEta_, "HiggsEta/F");

 myTree_ -> Branch("baseW",   &baseW_, "baseW/F");

 myTree_ -> Branch("jetpt1",  &jetpt1_,  "jetpt1/F");
 myTree_ -> Branch("jeteta1", &jeteta1_, "jeteta1/F");
 myTree_ -> Branch("mjj",  &mjj_,  "mjj/F");

 myTree_ -> Branch("ptV", &ptV_, "ptV/F");

 myTree_ -> Branch("njet20", &njet20_, "njet20/I");
 myTree_ -> Branch("njet30", &njet30_, "njet30/I");

 myTree_ -> Branch("nmu", &nmu_, "nmu/I");

 myTree_ -> Branch("lhejetpt1", &lhejetpt1_, "lhejetpt1/F");

 myTree_ -> Branch("mV1", &mV1_, "mV1/F");
 myTree_ -> Branch("mV2", &mV2_, "mV2/F");

}


GenComparison::~GenComparison()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
  GenComparison::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
 lhejetpt1_ = -10.; 
 if (saveLHE_) {
  edm::Handle<LHEEventProduct> productLHEHandle;
  iEvent.getByLabel("source", productLHEHandle);
  LHEhepeup_ = (*(productLHEHandle.product())).hepeup();

  lhejetpt1_ = leadingLHEJetPt(0);
 }


 edm::Handle<reco::GenParticleCollection> handle_genParticles;
 iEvent.getByLabel("genParticles",handle_genParticles);

 reco::GenParticleRefVector genParticles;
 genParticles.clear();
 for(size_t i=0; i<handle_genParticles->size(); i++) {
  genParticles.push_back( reco::GenParticleRef(handle_genParticles,i) );
 }

 edm::Handle<GenEventInfoProduct> GenInfoHandle;
 iEvent.getByLabel("generator", GenInfoHandle);

 GenEventInfoProduct   GenInfoHandle_ = *(GenInfoHandle.product());

 baseW_ = GenInfoHandle_.weight();


 //---- Higgs properties ----
 HiggsPt_ = -1;
 HiggsEta_ = -999;
 const reco::Candidate* mcH = 0;

  // loop over gen particlesHiggsPt
 for(size_t gp=0; gp<genParticles.size();gp++){

  int pdgId  = genParticles[gp] -> pdgId();
  int status = genParticles[gp] -> status();
   
    // Stop {1000006}
  if( (pdgId == 25) && (status == 3) ) {
   mcH = &(*(genParticles[gp]));
   HiggsPt_  = mcH->pt();
   HiggsEta_ = mcH->eta();
  }
 } // loop over gen particles

 Vdecay_ = getVdecay(genParticles);



 edm::Handle<reco::GenJetCollection> genJetHandle;
 iEvent.getByLabel("ak5GenJets",genJetHandle);
 reco::GenJetRefVector genJets;
 genJets.clear();
 for(size_t i=0; i<genJetHandle->size(); i++) {
  genJets.push_back( reco::GenJetRef(genJetHandle,i) );
 }

 jetpt1_  = leadingGenJetPt (0, genJets, genParticles);
 jeteta1_ = leadingGenJetEta(0, genJets, genParticles);

//  ptV_ = getPtV(genParticles);
 if (isWH_) ptV_ = getPtW(genParticles);
 if (isZH_) ptV_ = getPtZ(genParticles);

 njet20_ = nJets(20, genJets, genParticles);
 njet30_ = nJets(30, genJets, genParticles);

 mjj_ = mjj (genJets, genParticles);

 /*
 ///--- gen info level (begin) ----
 // here's an example of accessing particles in the event record (HepMCProduct)
 //
 edm::Handle< edm::HepMCProduct > EvtHandle ;

 // find initial (unsmeared, unfiltered,...) HepMCProduct
//
 iEvent.getByLabel( "generator", EvtHandle ) ;
 const HepMC::GenEvent* Evt = EvtHandle->GetEvent() ;

 // this a pointer - and not an array/vector/... 
 // because this example explicitely assumes
 // that there one and only Higgs in the record

 HepMC::GenVertex* HiggsDecVtx = 0 ;

 // find the 1st vertex with outgoing Higgs 
 // and get Higgs decay vertex from there;
 //
 // in principal, one can look for the vertex 
 // with incoming Higgs as well...
 //
 for ( HepMC::GenEvent::vertex_const_iterator vit=Evt->vertices_begin(); vit!=Evt->vertices_end(); vit++ ) {
  for ( HepMC::GenVertex::particles_out_const_iterator
        pout=(*vit)->particles_out_const_begin();
        pout!=(*vit)->particles_out_const_end(); pout++ ) {
         if ( (*pout)->pdg_id() == 25 && (*pout)->status() == 2 ) {
          if ( (*pout)->end_vertex() != 0 ) {
           HiggsDecVtx = (*pout)->end_vertex() ;
           break ;
          }
         }
        }
        if ( HiggsDecVtx != 0 ) {
         break ; // break the initial loop over vertices
        }
 }

 if ( HiggsDecVtx == 0 ) {
//   std::cout << " There is NO Higgs in this event ! " << std::endl ;
//   return ;
 }

//  if ( iEvent.id().event() == 1 )
//  {
//   cout << " " << endl ;
//   cout << " We do some example printouts in the event 1 " << endl ;
//   cout << " Higgs decay found at the vertex " << HiggsDecVtx->barcode() <<" (barcode)" << endl ;
// 
//   vector<HepMC::GenParticle*> HiggsChildren;
// 
//   for ( HepMC::GenVertex::particles_out_const_iterator H0in = 
//         HiggsDecVtx->particles_out_const_begin(); 
//         H0in != HiggsDecVtx->particles_out_const_end(); 
//         H0in++ ) 
//   { 
//    HiggsChildren.push_back(*H0in);
//   }
//   cout << " Number of Higgs (immediate) children = " << HiggsChildren.size() << endl ;
//   for (unsigned int ic=0; ic<HiggsChildren.size(); ic++ )
//   {
//    HiggsChildren[ic]->print() ;   
//   }
//  }

 mV1_ = -1;
 mV2_ = -1;

 if ( HiggsDecVtx =!= 0 ) {

 // select and store stable descendants of the Higgs
  std::vector<HepMC::GenParticle*> StableHiggsDesc ;

  for ( HepMC::GenVertex::particle_iterator
        des=HiggsDecVtx->particles_begin(HepMC::descendants);
        des!=HiggsDecVtx->particles_end(HepMC::descendants); des++ )
  {
   if ( iEvent.id().event() == 1 ) (*des)->print() ;
   if ( (*des)->status() == 1 ) StableHiggsDesc.push_back(*des) ;
  }

  HepMC::FourVector Mom2part ;
//  double            XMass2part = 0.;
//  double            XMass4part = 0.;
//  double            XMass2pairs  = 0.;
//  std::vector< HepMC::FourVector > Mom2partCont ;

 // browse the array of stable descendants
 // and do 2-mu inv.mass
  //
  for ( unsigned int i=0; i<StableHiggsDesc.size(); i++ ) {
  // skip other than mu
   //
   if ( abs(StableHiggsDesc[i]->pdg_id()) != 13 ) continue ; 
   for ( unsigned int j=i+1; j<StableHiggsDesc.size(); j++ ) {
  // skip other than mu
    //
    if ( abs(StableHiggsDesc[j]->pdg_id()) != 13 ) continue ;
    //
   // skip same charge combo's
    //
    if ( (StableHiggsDesc[i]->pdg_id()*StableHiggsDesc[j]->pdg_id()) > 0 ) 
     continue ;
    //
           // OK, opposite charges, do the job
    //
    Mom2part = HepMC::FourVector((StableHiggsDesc[i]->momentum().px()+StableHiggsDesc[j]->momentum().px()),
                                  (StableHiggsDesc[i]->momentum().py()+StableHiggsDesc[j]->momentum().py()),
                                  (StableHiggsDesc[i]->momentum().pz()+StableHiggsDesc[j]->momentum().pz()),
                                  (StableHiggsDesc[i]->momentum().e()+StableHiggsDesc[j]->momentum().e())) ;
       
    if (! mV1_) mV1_ = Mom2part.m() ;
    else if (! mV2_) mV2_ = Mom2part.m() ;
   }
  }
 
 }
 ///--- gen info level (end) ----

 */
 
 
 
 
 
 
 
 
 
 myTree_ -> Fill();

}


// ------------ method called once each job just before starting event loop  ------------
void 
  GenComparison::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
  GenComparison::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
GenComparison::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
GenComparison::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
GenComparison::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
GenComparison::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/



void GenComparison::FindDaughterParticles(const reco::Candidate** pCurrent, std::vector<const reco::Candidate*>* pFinal = 0) const {
  
  // Variable for decayed current particle
 const reco::Candidate* pCurrentNew = 0;
  
//  std::cout << " (*pCurrent) -> numberOfDaughters() = " << (*pCurrent) -> numberOfDaughters() << std::endl;
//  std::cout << " pFinal = " << pFinal << std::endl;
//  std::cout << " (*pCurrent) -> pdgId() = " << (*pCurrent) -> pdgId() << std::endl;

 for(unsigned int i = 0; i < (*pCurrent) -> numberOfDaughters(); ++i) {
//   std::cout << "  -> (*pCurrent) -> daughter(" << i << ") -> pdgId() = " << (*pCurrent) -> daughter(i) -> pdgId() << std::endl;

  if( (pFinal != 0) && ((*pCurrent) -> daughter(i) -> pdgId() != (*pCurrent) -> pdgId()) ) {
   if ( (*pCurrent) -> daughter(i) -> pdgId() != 22) { //---- no photons! 
    pFinal -> push_back((*pCurrent) -> daughter(i));
   }
  }

  if((*pCurrent) -> daughter(i) -> pdgId() == (*pCurrent) -> pdgId())
   pCurrentNew = (*pCurrent) -> daughter(i);
 }
  
  // Change the current particle into the decayed one
 if(pCurrentNew) {
  (*pCurrent) = pCurrentNew;
  //---- and look fo daughters again ...
//   std::cout << " ---> do it again! " << std::endl;
  FindDaughterParticles(pCurrent, pFinal);
 } 
}




const float GenComparison::getVdecay(reco::GenParticleRefVector genParticles) const {

 float finalState = 0;
 //  Z = +
 //  W+ = -
 //  W- = - *10

 //  1 = other
 //  2 = mu
 //  3 = e
 //  4 = tau

 const reco::Candidate* mcV = 0;
 const reco::Candidate* mcF1_fromV;
 const reco::Candidate* mcF2_fromV;

 // loop over gen particles
 for(size_t gp=0; gp<genParticles.size();++gp){
  
  int pdgId  = genParticles[gp] -> pdgId();
  int status = genParticles[gp] -> status();
  
  // Z {23}
  if( (pdgId == 23) && (status == 3) ) {
   if (((genParticles[gp])) -> mother() && ((genParticles[gp])) -> mother() -> pdgId() != 25) { //--- not son of the Higgs
    mcV = &(*(genParticles[gp]));
    finalState = +1;
   }
  }

  // W {24}
  if( (abs(pdgId) == 24) && (status == 3) ) {
   if ((genParticles[gp]) -> mother() && (genParticles[gp]) -> mother() -> pdgId() != 25) { //--- not son of the Higgs
    mcV = &(*(genParticles[gp]));
    if (pdgId ==  24) finalState = -1;
    if (pdgId == -24) finalState = -10;
   }
  }

 } // loop over gen particles

 if (mcV != 0) {
  // find fermions from vector boson decay
  std::vector<const reco::Candidate*> fFromVBuffer;
  FindDaughterParticles(&mcV, &fFromVBuffer);
    
//   std::cout << "   >> fFromVBuffer.size() = " << fFromVBuffer.size() << std::endl;
  if (fFromVBuffer.size() == 2) {
   mcF1_fromV = fFromVBuffer.at(0); 
   mcF2_fromV = fFromVBuffer.at(1);
  
   // If leptons, see if there is a photon emission
//    if(abs(mcF1_fromV -> pdgId()) >= 11) {
//     FindDaughterParticles(&mcF1_fromV);
//    }
//    if(abs(mcF2_fromV -> pdgId()) >= 11) {
//     FindDaughterParticles(&mcF2_fromV);
//    }

   // mm or mnum
   if ( abs(mcF1_fromV -> pdgId()) == 13 || abs(mcF2_fromV -> pdgId()) == 13 ) {
    finalState = finalState*2;
   }
   
   // ee or enue
   else if ( abs(mcF1_fromV -> pdgId()) == 11 || abs(mcF2_fromV -> pdgId()) == 11 ) {
    finalState = finalState*3;
   }
 
   // tt or tnut
   else if ( abs(mcF1_fromV -> pdgId()) == 15 || abs(mcF2_fromV -> pdgId()) == 15 ) {
    finalState = finalState*4;
   }
   else {
    finalState = finalState*5; //---- other decays
   }
  }
 }

 return finalState;
}



const float GenComparison::getPtV(reco::GenParticleRefVector genParticles) const {

 float ptV = -9999;

 const reco::Candidate* mcV = 0;

 // loop over gen particles
 for(size_t gp=0; gp<genParticles.size();++gp){
  
  int pdgId  = genParticles[gp] -> pdgId();
  int status = genParticles[gp] -> status();
  
  // Z {23}
  if( (pdgId == 23) && (status == 3) ) {
   if (((genParticles[gp])) -> mother() && ((genParticles[gp])) -> mother() -> pdgId() != 25) { //--- not son of the Higgs
    mcV = &(*(genParticles[gp]));
   }
  }

  // W {24}
  if( (abs(pdgId) == 24) && (status == 3) ) {
   if ((genParticles[gp]) -> mother() && (genParticles[gp]) -> mother() -> pdgId() != 25) { //--- not son of the Higgs
    mcV = &(*(genParticles[gp]));
   }
  }

 } // loop over gen particles

 if (mcV != 0) {
  ptV = mcV->pt();
 }
 
 return ptV;
}


const float GenComparison::getPtZ(reco::GenParticleRefVector genParticles) const {

 float ptV = -9999;

 const reco::Candidate* mcV = 0;

 // loop over gen particles
 for(size_t gp=0; gp<genParticles.size();++gp){
  
  int pdgId  = genParticles[gp] -> pdgId();
  int status = genParticles[gp] -> status();
  
  // Z {23}
  if( (pdgId == 23) && (status == 3) ) {
   if (((genParticles[gp])) -> mother() && ((genParticles[gp])) -> mother() -> pdgId() != 25) { //--- not son of the Higgs
    mcV = &(*(genParticles[gp]));
   }
  }
 } // loop over gen particles

 if (mcV != 0) {
  ptV = mcV->pt();
 }
 
 return ptV;
}


const float GenComparison::getPtW(reco::GenParticleRefVector genParticles) const {

 float ptV = -9999;

 const reco::Candidate* mcV = 0;

 bool foundW = false;

 // loop over gen particles
 for(size_t gp=0; gp<genParticles.size();++gp){

  int pdgId  = genParticles[gp] -> pdgId();
  int status = genParticles[gp] -> status();

  // W {24}
  if (abs(pdgId) == 24) {
//    std::cout << " W status = " << status << std::endl;
   foundW = true; 
  }
  
  if( (abs(pdgId) == 24) && (status == 3) ) {
   if ((genParticles[gp]) -> mother() && (genParticles[gp]) -> mother() -> pdgId() != 25) { //--- not son of the Higgs
    mcV = &(*(genParticles[gp]));
   }
  }

 } // loop over gen particles

 if (mcV != 0) {
  ptV = mcV->pt();
 }

 if (!foundW) {
  std::cout << " >> ma come e' possibile che non hai un W ?" << std::endl;
  for(size_t gp=0; gp<genParticles.size();gp++){
   int pdgId  = genParticles[gp] -> pdgId();
   int status = genParticles[gp] -> status();
   std::cout << "   " << gp << " :: " << genParticles.size() << "  -->  [" << pdgId << "] = " << status << std::endl;
  }
 }

 return ptV;
}


const float GenComparison::mjj(reco::GenJetRefVector genJets, reco::GenParticleRefVector genParticles) const {
 float pt_ofIndex_1 = leadingGenJetPt(0, genJets, genParticles);
 float pt_ofIndex_2 = leadingGenJetPt(1, genJets, genParticles);
 float mjj=-10.0;
 // loop over particles in the event

 const reco::GenJet* jet1 = 0;
 const reco::GenJet* jet2 = 0;

 for (unsigned int  iPart = 0 ; iPart < genJets.size (); ++iPart) {
  if((genJets[iPart]->pt())==pt_ofIndex_1) {
   jet1 = &(*(genJets[iPart]));
  }
  if((genJets[iPart]->pt())==pt_ofIndex_2) {
   jet2 = &(*(genJets[iPart]));
  }
 }

 if (jet1 != 0 && jet2 != 0) {
  float pt1 = jet1->pt();
  float eta1 = jet1->eta();
  float phi1 = jet1->phi();
//   TLorentzVector j1;
//   j1.SetPtEtaPhiM(pt1,eta1,phi1,0);

  float pt2 = jet2->pt();
  float eta2 = jet2->eta();
  float phi2 = jet2->phi();
//   TLorentzVector j2;
//   j2.SetPtEtaPhiM(pt2,eta2,phi2,0);
  
//   std::cout << pt1 << eta1 << phi1;
//   float py1 = jet1->py();
//   float pz1 = jet1->pz();
//   float E1 = jet1->p();
//   float px2 = jet2->px();
//   float py2 = jet2->py();
//   float pz2 = jet2->pz();
//   float E2 = jet2->p();
//   mjj = sqrt (
//     (E1+E2)*(E1+E2)-
//     (px1+px2)*(px1+px2)-
//     (py1+py2)*(py1+py2)-
//     (pz1+pz2)*(pz1+pz2)
//              );

  mjj = sqrt(2*pt1*pt2*(cosh(eta1-eta2) - cos(phi1-phi2)));
  //   mjj = (jet1->p4() + jet2->p4()).pt();
 }
 return mjj;
}


const float GenComparison::leadingGenJetPt(size_t index, reco::GenJetRefVector genJets, reco::GenParticleRefVector genParticles) const {
 std::vector<float> v_jets_pt ;
 // loop over particles in the event
 for (unsigned int  iPart = 0 ; iPart < genJets.size (); ++iPart) {
  if ( abs(genJets[iPart]->eta()) > 4.7) continue ;
//   if (isThisJetALepton (genJets[iPart], genParticles) ) continue;
  v_jets_pt.push_back ( genJets[iPart]->pt());
 }
 if (v_jets_pt.size () > 0) {
  std::sort (v_jets_pt.rbegin (), v_jets_pt.rend ()) ;
 }
 //---- now return ----
 size_t count = 0;
 for(size_t i=0;i<v_jets_pt.size();++i) {
  if(++count > index) return v_jets_pt.at(i);
 }

 return -9999.9;
}


const float GenComparison::leadingGenJetEta(size_t index, reco::GenJetRefVector genJets, reco::GenParticleRefVector genParticles) const {
 float pt_ofIndex = leadingGenJetPt(index, genJets, genParticles);
 float eta=-9999.9;
 // loop over particles in the event

 for (unsigned int  iPart = 0 ; iPart < genJets.size (); ++iPart) {
  if ( abs(genJets[iPart]->eta()) > 4.7) continue ;
  if((genJets[iPart]->pt())!=pt_ofIndex) continue;
//   if (isThisJetALepton (genJets[iPart], genParticles) ) continue;
  eta = genJets[iPart]->eta() ;
 }
 //---- now return ----
 return eta;
}



const int GenComparison::nJets(float minPt,  reco::GenJetRefVector genJets, reco::GenParticleRefVector genParticles) const {
 int count = 0;
 for(size_t i=0;i<genJets.size();i++) {
  if ( abs(genJets[i]->eta()) > 4.7) continue ;
//   if (isThisJetALepton (genJets[i], genParticles) ) continue;
  if (genJets[i]->pt() > minPt) count++;
 }
 return count;
}



const float GenComparison::leadingLHEJetPt(size_t index) const {
 std::vector<float> v_jetsLHE_pt ;
 // loop over particles in the event
 for (unsigned int  iPart = 0 ; iPart < LHEhepeup_.IDUP.size (); ++iPart) {
  if (LHEhepeup_.ISTUP.at (iPart) != 1) continue ;
  int type = abs (LHEhepeup_.IDUP.at (iPart)) ;
  if ((type < 9 && type > 0) || type == 21) {  
   v_jetsLHE_pt.push_back (
     sqrt (LHEhepeup_.PUP.at (iPart) [0] * LHEhepeup_.PUP.at (iPart) [0] +   // px
     LHEhepeup_.PUP.at (iPart) [1] * LHEhepeup_.PUP.at (iPart) [1])    // py
                          );
  }
 }
 if (v_jetsLHE_pt.size () > 0) {
  std::sort (v_jetsLHE_pt.rbegin (), v_jetsLHE_pt.rend ()) ;
 }
 //---- now return ----
 size_t count = 0;
 for(size_t i=0;i<v_jetsLHE_pt.size();++i) {
  if(++count > index) return v_jetsLHE_pt.at(i);
 }

 return -1.0;
}

const bool GenComparison::isThisJetALepton(const reco::GenJetRef jet, reco::GenParticleRefVector genParticles) const {
// const bool GenComparison::isThisJetALepton(const reco::GenJet jet, reco::GenParticleRefVector genParticles, float drCut = 0.3) const {
 bool thisJetIsLepton(false);
 const reco::Candidate* mcL = 0;

 for(size_t gp=0; gp<genParticles.size();++gp){
  int pdgId  = genParticles[gp] -> pdgId();
  int status = genParticles[gp] -> status();

  // leptons
  if ((abs(pdgId) == 11 || abs(pdgId) == 13 || abs(pdgId) == 15) && (status == 2)) {
   mcL = &(*(genParticles[gp]));
   double dR = fabs(ROOT::Math::VectorUtil::DeltaR(jet->p4(),mcL->p4()) );
   if(dR < 0.4){ 
    thisJetIsLepton = true;
    break;
   }
  }
 }
 return thisJetIsLepton;
}




// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
  GenComparison::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
 edm::ParameterSetDescription desc;
 desc.setUnknown();
 descriptions.addDefault(desc);
  }

//define this as a plug-in
  DEFINE_FWK_MODULE(GenComparison);
