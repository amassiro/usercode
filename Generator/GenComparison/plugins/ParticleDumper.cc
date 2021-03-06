// -*- C++ -*-
//
// Package:    ParticleDumper
// Class:      ParticleDumper
// 
/**\class ParticleDumper ParticleDumper.cc Generator/ParticleDumper/plugins/ParticleDumper.cc

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
#include <algorithm>

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

class ParticleDumper : public edm::EDAnalyzer {
 public:
  explicit ParticleDumper(const edm::ParameterSet&);
  ~ParticleDumper();

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

 private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;

  void FindDaughterParticles(const reco::Candidate** pCurrent, std::vector<const reco::Candidate*>* pFinal) const;
  const std::pair<float, float> getLeptonsFromHWWMC(reco::GenParticleRefVector genParticles, float *ptll) const;

  // ----------member data ---------------------------

  lhef::HEPEUP LHEhepeup_;

  TTree* myTree_;

  float pt1_;
  float pt2_;
  float ptll_;

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
ParticleDumper::ParticleDumper(const edm::ParameterSet& iConfig) {

 //now do what ever initialization is needed
 edm::Service<TFileService> fs ;
 myTree_  =        fs -> make <TTree>("myTree","myTree");

 myTree_ -> Branch("pt1",  &pt1_,  "pt1/F");
 myTree_ -> Branch("pt2",  &pt2_,  "pt2/F");
 myTree_ -> Branch("ptll", &ptll_, "ptll/F");

}


ParticleDumper::~ParticleDumper()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
  ParticleDumper::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
 edm::Handle<reco::GenParticleCollection> handle_genParticles;
 iEvent.getByLabel("genParticles",handle_genParticles);

 reco::GenParticleRefVector genParticles;
 genParticles.clear();
 for(size_t i=0; i<handle_genParticles->size(); i++) {
  genParticles.push_back( reco::GenParticleRef(handle_genParticles,i) );
 }


 std::pair <float, float> ptpair = getLeptonsFromHWWMC(genParticles, &ptll_);

 pt1_ = ptpair.first;
 pt2_ = ptpair.second;

 if (pt1_ < pt2_) std::swap<float> (pt1_, pt2_);

 myTree_ -> Fill();
}


// ------------ method called once each job just before starting event loop  ------------
void 
  ParticleDumper::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
  ParticleDumper::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
ParticleDumper::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
ParticleDumper::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
ParticleDumper::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
ParticleDumper::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/





//---- H > WW > lvlv : WW decay final state

const std::pair<float, float> ParticleDumper::getLeptonsFromHWWMC(reco::GenParticleRefVector genParticles, float* ptll) const {

 float lep1 = -1;
 float lep2 = -1;
 *ptll = -1.;

 const reco::Candidate* mcH = 0;

  // loop over gen particles
 for(size_t gp=0; gp<genParticles.size();++gp){
  int pdgId  = genParticles[gp] -> pdgId();
  int status = genParticles[gp] -> status();
  // H {25}
  if( (pdgId == 25) && (status == 3) ) {
   mcH = &(*(genParticles[gp]));
  }
 } // loop over gen particles

  // find vector bosons
 if (mcH != 0) {
  std::vector<const reco::Candidate*> VfromHBuffer;
  FindDaughterParticles(&mcH,&VfromHBuffer);

   // H > VV
  if(VfromHBuffer.size() == 2) {
   const reco::Candidate* mcV1;
   const reco::Candidate* mcV2;

   mcV1 = VfromHBuffer.at(0);
   mcV2 = VfromHBuffer.at(1);

   const reco::Candidate* mcF1_fromV1 = 0;
   const reco::Candidate* mcF2_fromV1 = 0;
   const reco::Candidate* mcF1_fromV2 = 0;
   const reco::Candidate* mcF2_fromV2 = 0;
  
   bool isHWWok = true;
   std::vector<const reco::Candidate*> fFromV1Buffer;
   FindDaughterParticles(&mcV1,&fFromV1Buffer);   
   if(fFromV1Buffer.size() == 2) {
    mcF1_fromV1 = fFromV1Buffer.at(0);
    mcF2_fromV1 = fFromV1Buffer.at(1);
     // If leptons, see if there is a photon emission
//     if(abs(mcF1_fromV1 -> pdgId()) >= 11) {
//      FindDaughterParticles(&mcF1_fromV1);
//     }
//     if(abs(mcF2_fromV1 -> pdgId()) >= 11) {
//      FindDaughterParticles(&mcF2_fromV1);
//     }
   }
   else {
    isHWWok  = false;
   }

   std::vector<const reco::Candidate*> fFromV2Buffer;
   FindDaughterParticles(&mcV2,&fFromV2Buffer);   
   if(fFromV2Buffer.size() == 2) {
    mcF1_fromV2 = fFromV2Buffer.at(0);
    mcF2_fromV2 = fFromV2Buffer.at(1);
     // If leptons, see if there is a photon emission
//     if(abs(mcF1_fromV2 -> pdgId()) >= 11) {
//      FindDaughterParticles(&mcF1_fromV2);
//     }
//     if(abs(mcF2_fromV2 -> pdgId()) >= 11) {
//      FindDaughterParticles(&mcF2_fromV2);
//     }
   }
   else {
    isHWWok  = false;
   }

   const reco::Candidate* f1 = 0;
   const reco::Candidate* f2 = 0;
   
   if (isHWWok) {
    //                                  e                                     m                                     t
    if ( (abs(mcF1_fromV1 -> pdgId()) == 11) || (abs(mcF1_fromV1 -> pdgId()) == 13) || (abs(mcF1_fromV1 -> pdgId()) == 15) )  {
     lep1 = mcF1_fromV1 -> pt();
     f1 = mcF1_fromV1;
    }
    if ( (abs(mcF2_fromV1 -> pdgId()) == 11) || (abs(mcF2_fromV1 -> pdgId()) == 13) || (abs(mcF2_fromV1 -> pdgId()) == 15) ) {
     lep1 = mcF2_fromV1 -> pt();
     f1 = mcF2_fromV1;
    }

    if ( (abs(mcF1_fromV2 -> pdgId()) == 11) || (abs(mcF1_fromV2 -> pdgId()) == 13) || (abs(mcF1_fromV2 -> pdgId()) == 15) ) {
     lep2 = mcF1_fromV2 -> pt();
     f2 = mcF1_fromV2;
    }
    if ( (abs(mcF2_fromV2 -> pdgId()) == 11) || (abs(mcF2_fromV2 -> pdgId()) == 13) || (abs(mcF2_fromV2 -> pdgId()) == 15) ) {
     lep2 = mcF2_fromV2 -> pt();
     f2 = mcF2_fromV2;
    }
    *ptll = ((f1->p4() + f2->p4()).pt());
   }
  }
 }
 return std::pair<float, float> (lep1,lep2);
}







void ParticleDumper::FindDaughterParticles(const reco::Candidate** pCurrent, std::vector<const reco::Candidate*>* pFinal = 0) const {
  
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





// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
  ParticleDumper::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
 edm::ParameterSetDescription desc;
 desc.setUnknown();
 descriptions.addDefault(desc);
  }

//define this as a plug-in
  DEFINE_FWK_MODULE(ParticleDumper);
