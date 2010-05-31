// -*- C++ -*-
//
// Package:    AlCaValidation
// Class:      AlCaValidation
// 
/**\class AlCaValidation AlCaValidation.cc Validation/AlCaValidation/src/AlCaValidation.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrea Massironi,27 1-020,+41227670757,
//         Created:  Thu May 13 11:34:24 CEST 2010
// $Id: AlCaValidation.cc,v 1.4 2010/05/31 10:24:39 amassiro Exp $
//
//


// system include files
#include <memory>

#include "Validation/AlCaValidation/interface/AlCaValidation.h"

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"


//
// constructors and destructor
//
AlCaValidation::AlCaValidation(const edm::ParameterSet& iConfig)
{
 eventNaiveId_ = 0;
   //now do what ever initialization is needed
  ElectronLabel_ = iConfig.getParameter<edm::InputTag>("ElectronLabel");
  AlcaBarrelHitCollection_ = iConfig.getParameter<edm::InputTag>("AlcaBarrelHitCollection");
  AlcaEndcapHitCollection_ = iConfig.getParameter<edm::InputTag>("AlcaEndcapHitCollection");
  edm::Service<TFileService> fs ;
  outTree_  = fs->make <TTree>("SimpleNtple","SimpleNtple");
  hBarrelGlobalCrystalsMap_  = fs->make <TH2F>("BarrelGlobalCrystalsMap","BarrelGlobalCrystalsMap",170,-85,85,360,0,360);
  hEndcapGlobalCrystalsMap_  = fs->make <TH2F>("EndcapGlobalCrystalsMap","EndcapGlobalCrystalsMap",100,0,100,100,0,100);
  hBarrelLocalCrystalsEnergy_  = fs->make <TH2F>("BarrelLocalCrystalsEnergy","BarrelLocalCrystalsEnergy",20,-10,10,20,-10,10);
  hEndcapLocalCrystalsEnergy_  = fs->make <TH2F>("EndcapLocalCrystalsEnergy","EndcapLocalCrystalsEnergy",20,-10,10,20,-10,10);
  hZee_  = fs->make <TH1F>("Zee","Zee",100,0,200);

  NtupleFactory_ = new NtupleFactory(outTree_);

  NtupleFactory_->Add4V("electrons"); ///==== eleIt->p4();

  NtupleFactory_->Add3V("electrons_tracker_atVtx"); 
  ///==== momentum = eleIt->trackMomentumAtVtx()
  
  NtupleFactory_->AddFloat("MaxEnergy"); ///==== itrechit->energy ()
  NtupleFactory_->AddFloat("Calo_Energy"); ///==== eleIt->caloEnergy()
  NtupleFactory_->AddFloat("Energy25"); 
  NtupleFactory_->AddFloat("ESCoP"); 
  NtupleFactory_->AddFloat("eSeedOverPout"); 
  
  NtupleFactory_->Add3V("electrons_tracker_Out"); 
  ///==== momentum = eleIt->trackMomentumOut()

  NtupleFactory_->AddFloat("Energy_seed"); 
  NtupleFactory_->AddFloat("Energy9"); 
  NtupleFactory_->AddFloat("Energy49"); 
  NtupleFactory_->AddFloat("Presh"); 
  NtupleFactory_->AddFloat("pErr"); 
  NtupleFactory_->AddFloat("recHits"); ///==== recHits_+=itrechit->energy();

  NtupleFactory_->AddInt("class"); 
  NtupleFactory_->AddFloat("chis"); 
  
  NtupleFactory_->AddInt("lost"); 
  NtupleFactory_->AddInt("found"); 
  NtupleFactory_->AddFloat("ndof"); 
  NtupleFactory_->AddFloat("chisN"); 

  NtupleFactory_->AddInt("runId"); 
  NtupleFactory_->AddInt("lumiId"); 
  NtupleFactory_->AddInt("BXId"); 
  NtupleFactory_->AddInt("eventId"); 
  NtupleFactory_->AddInt("eventNaiveId"); 

    NtupleFactory_->Add4V("electrons");
    NtupleFactory_->AddFloat("electrons_charge"); 
    NtupleFactory_->AddFloat("electrons_tkIso"); 
    NtupleFactory_->AddFloat("electrons_emIso03"); 
    NtupleFactory_->AddFloat("electrons_emIso04"); 
    NtupleFactory_->AddFloat("electrons_hadIso03_1"); 
    NtupleFactory_->AddFloat("electrons_hadIso03_2"); 
    NtupleFactory_->AddFloat("electrons_hadIso04_1"); 
    NtupleFactory_->AddFloat("electrons_hadIso04_2"); 
    NtupleFactory_->AddFloat("electrons_scTheta");
    NtupleFactory_->AddFloat("electrons_scE");
    NtupleFactory_->AddFloat("electrons_eOverP");
    NtupleFactory_->AddFloat("electrons_eSeed");
    NtupleFactory_->AddFloat("electrons_fbrem");
    NtupleFactory_->AddFloat("electrons_sigmaIetaIeta");
    NtupleFactory_->AddFloat("electrons_pin");
    NtupleFactory_->AddFloat("electrons_pout");
    NtupleFactory_->AddFloat("electrons_hOverE");
    NtupleFactory_->AddFloat("electrons_deltaPhiIn");
    NtupleFactory_->AddFloat("electrons_deltaEtaIn");
    NtupleFactory_->AddInt("electrons_mishits");

}


AlCaValidation::~AlCaValidation()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)
 NtupleFactory_->WriteNtuple();
 delete NtupleFactory_;
}


//
// member functions
//

// ------------ method called to for each event  ------------
void
  AlCaValidation::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
 ++eventNaiveId_;

 std::cout << " eventNaiveId = " << eventNaiveId_ << std::endl;

 double energia5 = 0 ;
 pTk_ = 0. ;
 math::XYZVector Zmoment(0.,0.,0.);
 double  Zenergy=0;
  //get the EB rechit collection
 edm::Handle<EBRecHitCollection> barrelRecHitsHandle ;
 const EBRecHitCollection*  barrelHitsCollection = 0 ;
 iEvent.getByLabel (AlcaBarrelHitCollection_, barrelRecHitsHandle) ;
 barrelHitsCollection = barrelRecHitsHandle.product () ; // get a ptr to the product

 edm::Handle<EERecHitCollection> endcapRecHitsHandle ;
 const EERecHitCollection*  endcapHitsCollection = 0 ; 
 iEvent.getByLabel (AlcaEndcapHitCollection_,endcapRecHitsHandle) ;
 endcapHitsCollection = endcapRecHitsHandle.product () ; // get a ptr to the product
  
 edm::Handle<reco::GsfElectronCollection> pElectrons ;
 iEvent.getByLabel (ElectronLabel_, pElectrons) ;
  
  //PG loop on the electrons
 int i=0;
 bool EE=0;
 for (reco::GsfElectronCollection::const_iterator eleIt = pElectrons->begin () ;
      eleIt != pElectrons->end () ;
      ++eleIt) 
 {
  eta_=eleIt->eta () ;
  recHits_=0;
  pErr_=eleIt->trackMomentumError();
  chis_=eleIt->gsfTrack()->chi2();
  lost_=eleIt->gsfTrack()->lost();
  found_=eleIt->gsfTrack()->found();
  ndof_=eleIt->gsfTrack()->ndof();
  chisN_ = eleIt->gsfTrack()->normalizedChi2();
  class_=eleIt->classification();
  preshower_=eleIt->superCluster()->preshowerEnergy();
  phi_=eleIt->phi () ;
  pTk_ = eleIt->trackMomentumAtVtx ().R () ; 
  ESCoP_= eleIt->eSuperClusterOverP();
  energy_=eleIt->caloEnergy();  
  eSeedOverPout_=eleIt->eSeedClusterOverPout();
  pOut_ = eleIt->trackMomentumOut().R();    
  Zmoment+= eleIt->trackMomentumAtVtx();
  momentum_ = eleIt->p();
   
  seed_energy_ = -1;
  const std::vector<std::pair<DetId,float> > & hits= eleIt->superCluster()->hitsAndFractions();
  for (std::vector<std::pair<DetId,float> > ::const_iterator rh = hits.begin(); rh!=hits.end(); ++rh){
   if ((*rh).first.subdetId()== EcalBarrel){
    EBRecHitCollection::const_iterator itrechit = barrelHitsCollection->find((*rh).first);
    if (itrechit==barrelHitsCollection->end()) continue;
    recHits_+=itrechit->energy();
    if (itrechit->energy() > seed_energy_) seed_energy_ = itrechit->energy();
   }
   if ((*rh).first.subdetId()== EcalEndcap){
    EERecHitCollection::const_iterator itrechit = endcapHitsCollection->find((*rh).first);
    if (itrechit==endcapHitsCollection->end()) continue;
    recHits_+=itrechit->energy();
    if (itrechit->energy() > seed_energy_) seed_energy_ = itrechit->energy();
   }
   else
   { 
//           std::cerr<<"something is wrong about where the hit is\n";
//               std::cerr<<"subDetID= "<<(*rh).first.subdetId()<<"\n";
   }
  }
  if (energy_>40) ++i;
     //PG look for the max detid in the cluster relative to the electron
  DetId Max = 0;
  if ((fabs(eleIt->eta())<1.49)){
   DetId temp;
   temp = EcalClusterTools::getMaximum(eleIt->superCluster()->hitsAndFractions(),barrelHitsCollection).first;
   Max=temp;
  }
  else 
  {
   DetId temp;
   temp = EcalClusterTools::getMaximum(eleIt->superCluster()->hitsAndFractions(),endcapHitsCollection).first;
   Max=temp;
  }
  if (Max.det () == 0){ continue;} 
   
  NtupleFactory_->Fill4V("electrons",eleIt->p4()); 
  NtupleFactory_->Fill3V("electrons_tracker_atVtx",eleIt->trackMomentumAtVtx());
  NtupleFactory_->Fill3V("electrons_tracker_Out",eleIt->trackMomentumOut());

  NtupleFactory_->FillFloat("recHits",recHits_);
  ///==== Barrel or Endcap
  if ( Max.subdetId () == EcalBarrel  ) //PG in the barrel
  {
   EBDetId EBMax (Max) ;    
   EBRecHitCollection::const_iterator itrechit ;
   energia5 = Energy25Barrel (EBMax.ieta (), EBMax.iphi (), 5,barrelHitsCollection) ;
   itrechit = barrelHitsCollection->find (Max) ;
   MaxEnergy_=itrechit->energy () ;
   hBarrelGlobalCrystalsMap_ -> Fill (EBMax.ieta () , EBMax.iphi ()) ;
   Energy25_=energia5 ;
   Energy49_= Energy25Barrel (EBMax.ieta(),EBMax.iphi(),7,barrelHitsCollection);
   Energy9_=Energy25Barrel (EBMax.ieta(),EBMax.iphi(),3,barrelHitsCollection);
   NtupleFactory_->FillFloat("Energy25",Energy25_);
   NtupleFactory_->FillFloat("Energy9",Energy9_); 
   NtupleFactory_->FillFloat("Energy49",Energy49_); 
   NtupleFactory_->FillFloat("MaxEnergy",MaxEnergy_);
   Zenergy+=energia5;
   fillAroundBarrel (
     barrelHitsCollection, 
   EBMax.ieta (), 
   EBMax.iphi (),
   pTk_ 
                    ) ;
  } //PG in the barrel
     
  else //PG in the endcap
  {      
   EE=1;
   EEDetId EEMax (Max) ;  
   EERecHitCollection::const_iterator itrechit ;
   itrechit = endcapHitsCollection->find (Max) ;
   MaxEnergy_ = itrechit->energy () ;
   energia5 = Energy25Endcap (EEMax.ix (), EEMax.iy (), EEMax.zside(),5, endcapHitsCollection) ;
   hEndcapGlobalCrystalsMap_ -> Fill (EEMax.ix () , EEMax.iy ()) ;
   Energy25_ = energia5 ;
   Energy49_ = Energy25Endcap (EEMax.ix (), EEMax.iy (), EEMax.zside(),7, endcapHitsCollection) ;
   Energy9_ = Energy25Endcap (EEMax.ix (), EEMax.iy (), EEMax.zside(),3, endcapHitsCollection) ;
   NtupleFactory_->FillFloat("Energy25",Energy25_);
   NtupleFactory_->FillFloat("Energy9",Energy9_); 
   NtupleFactory_->FillFloat("Energy49",Energy49_); 
   NtupleFactory_->FillFloat("MaxEnergy",MaxEnergy_);
   Zenergy+=energia5+preshower_;
   fillAroundEndcap (
     endcapHitsCollection, 
   EEMax.ix (), 
   EEMax.iy (),
   pTk_
                    ) ;
  } //PG in the endcap
  NtupleFactory_->FillInt("runId", iEvent.id().run());
  NtupleFactory_->FillInt("lumiId", iEvent.luminosityBlock());
  NtupleFactory_->FillInt("BXId", iEvent.bunchCrossing());
  NtupleFactory_->FillInt("eventId", iEvent.id().event());
  NtupleFactory_->FillInt("eventNaiveId", eventNaiveId_);

  NtupleFactory_->FillInt("lost",lost_); 
  NtupleFactory_->FillInt("found",found_); 
  NtupleFactory_->FillFloat("ndof",ndof_); 
  NtupleFactory_->FillFloat("chisN",chisN_); 
  NtupleFactory_->FillInt("class",class_); 
  NtupleFactory_->FillFloat("chis",chis_); 
  NtupleFactory_->FillFloat("pErr",pErr_); 
  NtupleFactory_->FillFloat("ESCoP",ESCoP_); 
  NtupleFactory_->FillFloat("eSeedOverPout",eSeedOverPout_); 
  NtupleFactory_->FillFloat("Calo_Energy",energy_); ///==== eleIt->caloEnergy()
  
  
  NtupleFactory_->FillFloat("electrons_charge",(eleIt->charge()));
  NtupleFactory_->FillFloat("electrons_tkIso",(eleIt->dr03TkSumPt()));
  NtupleFactory_->FillFloat("electrons_emIso03",(eleIt->dr03EcalRecHitSumEt()));
  NtupleFactory_->FillFloat("electrons_emIso04",(eleIt->dr04EcalRecHitSumEt()));
  NtupleFactory_->FillFloat("electrons_hadIso03_1",(eleIt->dr03HcalDepth1TowerSumEt()));
  NtupleFactory_->FillFloat("electrons_hadIso03_2",(eleIt->dr03HcalDepth2TowerSumEt()));
  NtupleFactory_->FillFloat("electrons_hadIso04_1",(eleIt->dr04HcalDepth1TowerSumEt()));
  NtupleFactory_->FillFloat("electrons_hadIso04_2",(eleIt->dr04HcalDepth2TowerSumEt()));

  NtupleFactory_->FillFloat("electrons_sigmaIetaIeta",eleIt->sigmaIetaIeta());
  NtupleFactory_->FillFloat("electrons_scTheta",(2*atan(exp(-(eleIt->superCluster()->eta())))));
  NtupleFactory_->FillFloat("electrons_scE",eleIt->superCluster()->energy());
  NtupleFactory_->FillFloat("electrons_eOverP",eleIt->eSuperClusterOverP());
//  NtupleFactory_->FillFloat("electrons_eSeed",eleIt->superCluster()->seed()->energy());
  NtupleFactory_->FillFloat("electrons_eSeed",seed_energy_);
  NtupleFactory_->FillFloat("electrons_fbrem",eleIt->fbrem());
  NtupleFactory_->FillFloat("electrons_pin",eleIt->trackMomentumAtVtx().R());
  NtupleFactory_->FillFloat("electrons_pout",eleIt->trackMomentumOut().R());
  NtupleFactory_->FillFloat("electrons_hOverE",eleIt->hadronicOverEm());
  NtupleFactory_->FillFloat("electrons_deltaPhiIn",eleIt->deltaPhiSuperClusterTrackAtVtx());
  NtupleFactory_->FillFloat("electrons_deltaEtaIn",eleIt->deltaEtaSuperClusterTrackAtVtx());
  NtupleFactory_->FillInt("electrons_mishits",eleIt->gsfTrack()->trackerExpectedHitsInner().numberOfHits());
  
 } //PG loop over electrons
 
 NtupleFactory_->FillNtuple(); 
 double MZ;
 MZ = sqrt( Zenergy*Zenergy - Zmoment.R()*Zmoment.R());
 if (i==2)
  hZee_->Fill(MZ);
}


// ------------ method called once each job just before starting event loop  ------------
void 
AlCaValidation::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
AlCaValidation::endJob() {
}



// ----------------------------------------------------------------



// ----------------------------------------------------------------


void
AlCaValidation::fillAroundBarrel (const EcalRecHitCollection * recHits, int eta, int phi, double momentum)
{

  for (EcalRecHitCollection::const_iterator elem = recHits->begin () ;
       elem != recHits->end () ;
       ++elem)
    {
      EBDetId elementId = elem->id () ; 
      hBarrelLocalCrystalsEnergy_->Fill (
        elementId.ieta () - eta ,
        elementId.iphi () - phi ,
        elem->energy ()
      ) ;
    }   
  return ;
}


// ----------------------------------------------------------------


void
AlCaValidation::fillAroundEndcap (const EcalRecHitCollection * recHits, int ics, int ips, double momentum)
{
  for (EcalRecHitCollection::const_iterator elem = recHits->begin () ;
       elem != recHits->end () ;
       ++elem)
    {
      EEDetId elementId = elem->id () ; 
      hEndcapLocalCrystalsEnergy_->Fill (
        elementId.ix () - ics ,
        elementId.iy () - ips ,
        elem->energy ()
      ) ;
    }   
  return ;
}


// ----------------------------------------------------------------


//! MF energy in the 5x5 neighbourhood around MaxId
//! in the barrel
double AlCaValidation::Energy25Barrel (int eta, int phi,int side,
                const EcalRecHitCollection * barrelHitsCollection)
{
  int curr_eta = 0 ;
  int curr_phi = 0 ;
  double dummy = 0. ;
 //PG questo puo' essere in futuro specificato separatamente per eta,phi
     //PG loop on the energy reconstruction window
  for (int ii = 0 ; ii < side ; ++ii)
  for (int ij = 0 ; ij < side ; ++ij)
    {
      curr_eta = eta - (side/2) + ii ;
      curr_phi = phi - (side/2) + ij ;
      if (abs (curr_eta) > 85) continue ;
      if (curr_eta * eta <= 0) 
        {
          if (eta > 0) --curr_eta ; 
          else curr_eta++ ; 
        }  // JUMP over 0
      if (curr_phi < 1) curr_phi += 360 ;
      if (curr_phi > 360) curr_phi -= 360 ;
      if (EBDetId::validDetId (curr_eta,curr_phi))
       {
         EBDetId det = EBDetId (curr_eta,curr_phi,EBDetId::ETAPHIMODE) ;
         EcalRecHitCollection::const_iterator curr_recHit = barrelHitsCollection->find (det) ;
         if (isnan(curr_recHit->energy())) continue;
         if (curr_recHit->energy()<0) continue;
         if (curr_recHit->energy()>1000) continue;
         dummy  = dummy + curr_recHit->energy () ;
        }
    }
 return dummy ;
}


// ----------------------------------------------------------------


//! MF energy in the 5x5 neighbourhood around MaxId
//! in the endcap   
double AlCaValidation::Energy25Endcap (int ics, int ips, int z,int side,
                  const EcalRecHitCollection * endcapHitsCollection)
{
  int curr_x = 0 ;
  int curr_y = 0 ;
  int local_x = 0 ;
  int local_y = 0 ;
  double dummy = 0. ;
  //PG loop on the energy reconstruction window
  for (int ii = 0 ; ii < side ; ++ii)
  for (int ij = 0 ; ij < side ; ++ij)
   {
    curr_x = ics - (side/2) + ii ;
    curr_y = ips - (side/2) + ij ;
    local_x = curr_x - 1 ;
    local_y = curr_y - 1 ;
    if (curr_x>100 || curr_x<0) continue ; //PG prob qs ctrl nn serve visto qllo dopo
    if (curr_y>100 || curr_y<0) continue ; //PG prob qs ctrl nn serve visto qllo dopo
    if (EEDetId::validDetId (curr_x,curr_y,z))
     {
      EEDetId det = EEDetId (curr_x,curr_y,z,EEDetId::XYMODE) ;
      EcalRecHitCollection::const_iterator curr_recHit = endcapHitsCollection->find (det) ;
      if (isnan(curr_recHit->energy())) continue;
      if (curr_recHit->energy()<0) continue;
      if (curr_recHit->energy()>1000) continue;
      dummy  = dummy + curr_recHit->energy () ;
     } 
   } 
  return dummy ;
} 





//define this as a plug-in
DEFINE_FWK_MODULE(AlCaValidation);
