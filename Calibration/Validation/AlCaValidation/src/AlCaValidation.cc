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
// $Id: AlCaValidation.cc,v 1.12 2010/07/01 13:23:25 amassiro Exp $
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

#include "DataFormats/Common/interface/ValueMap.h"

//
// constructors and destructor
//
AlCaValidation::AlCaValidation(const edm::ParameterSet& iConfig)
{
 eventNaiveId_ = 0;
   //now do what ever initialization is needed
  HLTInputTag_ = iConfig.getParameter<edm::InputTag>("HLTInputTag");
  MetTag_ = iConfig.getParameter<edm::InputTag>("MetTag");
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

  doEleId_ = iConfig.getUntrackedParameter<bool> ("doEleId", false);
  if (doEleId_){
   eleIDCut_eIDRobustLooseInputTag_      = iConfig.getParameter<edm::InputTag>("eleIDCut_eIDRobustLooseInputTag");
   eleIDCut_eIDRobustLooseV00InputTag_   = iConfig.getParameter<edm::InputTag>("eleIDCut_eIDRobustLooseV00InputTag");
   eleIDCut_eIDRobustTightInputTag_      = iConfig.getParameter<edm::InputTag>("eleIDCut_eIDRobustTightInputTag");
   eleIDCut_eIDRobustHighEnergyInputTag_ = iConfig.getParameter<edm::InputTag>("eleIDCut_eIDRobustHighEnergyInputTag");
   eleIDCut_eIDLooseInputTag_            = iConfig.getParameter<edm::InputTag>("eleIDCut_eIDLooseInputTag");
   eleIDCut_eIDTightInputTag_            = iConfig.getParameter<edm::InputTag>("eleIDCut_eIDTightInputTag");
   eleIDCut_eIDClassesLooseInputTag_     = iConfig.getParameter<edm::InputTag>("eleIDCut_eIDClassesLooseInputTag");
   eleIDCut_eIDClassesMediumInputTag_    = iConfig.getParameter<edm::InputTag>("eleIDCut_eIDClassesMediumInputTag");
   eleIDCut_eIDClassesTightInputTag_     = iConfig.getParameter<edm::InputTag>("eleIDCut_eIDClassesTightInputTag");
  }

  doEleIdCIC_ = iConfig.getUntrackedParameter<bool> ("doEleIdCIC", false);
  if (doEleIdCIC_){
   eleIDCut_eidVeryLooseInputTag_        = iConfig.getParameter<edm::InputTag>("eleIDCut_eidVeryLooseInputTag");
   eleIDCut_eidLooseInputTag_            = iConfig.getParameter<edm::InputTag>("eleIDCut_eidLooseInputTag");
   eleIDCut_eidMediumInputTag_           = iConfig.getParameter<edm::InputTag>("eleIDCut_eidMediumInputTag");
   eleIDCut_eidTightInputTag_            = iConfig.getParameter<edm::InputTag>("eleIDCut_eidTightInputTag");
   eleIDCut_eidSuperTightInputTag_       = iConfig.getParameter<edm::InputTag>("eleIDCut_eidSuperTightInputTag");
   eleIDCut_eidHyperTight1InputTag_      = iConfig.getParameter<edm::InputTag>("eleIDCut_eidHyperTight1InputTag");
   eleIDCut_eidHyperTight2InputTag_      = iConfig.getParameter<edm::InputTag>("eleIDCut_eidHyperTight2InputTag");
   eleIDCut_eidHyperTight3InputTag_      = iConfig.getParameter<edm::InputTag>("eleIDCut_eidHyperTight3InputTag");
   eleIDCut_eidHyperTight4InputTag_      = iConfig.getParameter<edm::InputTag>("eleIDCut_eidHyperTight4InputTag");
  }

  NtupleFactory_ = new NtupleFactory(outTree_);

  NtupleFactory_->AddInt("iSM"); 
  NtupleFactory_->AddInt("iSC");

  NtupleFactory_->Add4V("met"); ///==== caloMET
  NtupleFactory_->AddFloat("sumEt"); 
  
    
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

  NtupleFactory_->AddFloat("SwissE4"); 
  NtupleFactory_->AddFloat("Energy_seed"); 
  NtupleFactory_->AddFloat("Energy4"); 
  NtupleFactory_->AddFloat("Energy9"); 
  NtupleFactory_->AddFloat("Energy49"); 
  NtupleFactory_->AddFloat("electrons_ES"); 
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

  NtupleFactory_->AddFloat("electrons_eIDRobustLoose"); 
  NtupleFactory_->AddFloat("electrons_eIDRobustLooseV00"); 
  NtupleFactory_->AddFloat("electrons_eIDRobustTight"); 
  NtupleFactory_->AddFloat("electrons_eIDRobustHighEnergy"); 
  NtupleFactory_->AddFloat("electrons_eIDLoose"); 
  NtupleFactory_->AddFloat("electrons_eIDTight"); 
  NtupleFactory_->AddFloat("electrons_eIDClassesLoose"); 
  NtupleFactory_->AddFloat("electrons_eIDClassesMedium"); 
  NtupleFactory_->AddFloat("electrons_eIDClassesTight"); 

  NtupleFactory_->AddFloat("electrons_eidVeryLoose"); 
  NtupleFactory_->AddFloat("electrons_eidLoose"); 
  NtupleFactory_->AddFloat("electrons_eidMedium"); 
  NtupleFactory_->AddFloat("electrons_eidTight"); 
  NtupleFactory_->AddFloat("electrons_eidSuperTight"); 
  NtupleFactory_->AddFloat("electrons_eidHyperTight1"); 
  NtupleFactory_->AddFloat("electrons_eidHyperTight2"); 
  NtupleFactory_->AddFloat("electrons_eidHyperTight3"); 
  NtupleFactory_->AddFloat("electrons_eidHyperTight4"); 

  NtupleFactory_->AddInt("HLT_Photon10_L1R");
  NtupleFactory_->AddInt("HLT_Photon15_L1R");
  NtupleFactory_->AddInt("HLT_Photon20_L1R");
  NtupleFactory_->AddInt("HLT_Ele15_LW_L1R");

  NtupleFactory_->AddFloat("E_xtal"); 
  NtupleFactory_->AddInt("ieta_xtal");
  NtupleFactory_->AddInt("iphi_xtal");
  NtupleFactory_->AddInt("ix_xtal");
  NtupleFactory_->AddInt("iy_xtal");

  
  NtupleFactory_->AddFloat("electrons_SC_phiWidth");
  NtupleFactory_->AddFloat("electrons_SC_etaWidth");

  NtupleFactory_->Add3V("electrons_p_atVtx");
  NtupleFactory_->Add3V("electrons_p_atCalo");
  NtupleFactory_->AddFloat("electrons_scEt");
  NtupleFactory_->AddFloat("electrons_scEta");
  NtupleFactory_->AddFloat("electrons_scPhi");
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

//  std::cout << " eventNaiveId = " << eventNaiveId_ << std::endl;

 //*********** HLT INFO
 edm::Handle<edm::TriggerResults> hltresults;
 iEvent.getByLabel(HLTInputTag_,hltresults);
 const edm::TriggerNames & triggerNames = iEvent.triggerNames(*hltresults);


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
  
  std::vector<edm::Handle<edm::ValueMap<float> > > eleIdCutHandles(9) ;
  if (doEleId_){
   iEvent.getByLabel (eleIDCut_eIDRobustLooseInputTag_,      eleIdCutHandles[0]) ;
   iEvent.getByLabel (eleIDCut_eIDRobustLooseV00InputTag_,   eleIdCutHandles[1]) ;
   iEvent.getByLabel (eleIDCut_eIDRobustTightInputTag_,      eleIdCutHandles[2]) ;
   iEvent.getByLabel (eleIDCut_eIDRobustHighEnergyInputTag_, eleIdCutHandles[3]) ;
   iEvent.getByLabel (eleIDCut_eIDLooseInputTag_,            eleIdCutHandles[4]) ;
   iEvent.getByLabel (eleIDCut_eIDTightInputTag_,            eleIdCutHandles[5]) ;
   iEvent.getByLabel (eleIDCut_eIDClassesLooseInputTag_,     eleIdCutHandles[6]) ;
   iEvent.getByLabel (eleIDCut_eIDClassesMediumInputTag_,    eleIdCutHandles[7]) ;
   iEvent.getByLabel (eleIDCut_eIDClassesTightInputTag_,     eleIdCutHandles[8]) ;
 }
 if (doEleIdCIC_){
  iEvent.getByLabel (eleIDCut_eidVeryLooseInputTag_,    eleIdCutHandles[0]) ;
  iEvent.getByLabel (eleIDCut_eidLooseInputTag_,        eleIdCutHandles[1]) ;
  iEvent.getByLabel (eleIDCut_eidMediumInputTag_,       eleIdCutHandles[2]) ;
  iEvent.getByLabel (eleIDCut_eidTightInputTag_,        eleIdCutHandles[3]) ;
  iEvent.getByLabel (eleIDCut_eidSuperTightInputTag_,   eleIdCutHandles[4]) ;
  iEvent.getByLabel (eleIDCut_eidHyperTight1InputTag_,  eleIdCutHandles[5]) ;
  iEvent.getByLabel (eleIDCut_eidHyperTight2InputTag_,  eleIdCutHandles[6]) ;
  iEvent.getByLabel (eleIDCut_eidHyperTight3InputTag_,  eleIdCutHandles[7]) ;
  iEvent.getByLabel (eleIDCut_eidHyperTight4InputTag_,  eleIdCutHandles[8]) ;
 }

 
 
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
   
  int iSM = -1000;
  int iSC = -1000;
  seed_energy_ = -1;
  const std::vector<std::pair<DetId,float> > & hits= eleIt->superCluster()->hitsAndFractions();
  for (std::vector<std::pair<DetId,float> > ::const_iterator rh = hits.begin(); rh!=hits.end(); ++rh){
   if ((*rh).first.subdetId()== EcalBarrel){
    EBRecHitCollection::const_iterator itrechit = barrelHitsCollection->find((*rh).first);
    if (itrechit==barrelHitsCollection->end()) continue;
    recHits_+=itrechit->energy();
    EBDetId barrelId (itrechit->id ()); 
    NtupleFactory_->FillFloat("E_xtal",itrechit->energy());
    NtupleFactory_->FillInt("ieta_xtal",barrelId.ieta());
    NtupleFactory_->FillInt("iphi_xtal",barrelId.iphi());
    NtupleFactory_->FillInt("ix_xtal",-1000);
    NtupleFactory_->FillInt("iy_xtal",-1000);
    if (itrechit->energy() > seed_energy_) {
     seed_energy_ = itrechit->energy();
     iSC = -1000;
     iSM = barrelId.ism();
    }
   }
   if ((*rh).first.subdetId()== EcalEndcap){
    EERecHitCollection::const_iterator itrechit = endcapHitsCollection->find((*rh).first);
    if (itrechit==endcapHitsCollection->end()) continue;
    recHits_+=itrechit->energy();
    EEDetId endcapId (itrechit->id ()); 
    NtupleFactory_->FillFloat("E_xtal",itrechit->energy());
    NtupleFactory_->FillInt("ix_xtal",endcapId.ix());
    NtupleFactory_->FillInt("iy_xtal",endcapId.iy());
    NtupleFactory_->FillInt("ieta_xtal",-1000);
    NtupleFactory_->FillInt("iphi_xtal",-1000);
    if (itrechit->energy() > seed_energy_) {
     seed_energy_ = itrechit->energy();
     iSC = endcapId.isc();
     iSM = -1000;
    }   
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
  if (Max.det () == 0){
   NtupleFactory_->ClearNtuple();
   continue;
  }
  
  
  NtupleFactory_->Fill3V("electrons_p_atVtx",eleIt->trackMomentumAtVtx());
  NtupleFactory_->Fill3V("electrons_p_atCalo",eleIt->trackMomentumAtCalo());

  
  NtupleFactory_->Fill4V("electrons",eleIt->p4()); 
  NtupleFactory_->Fill3V("electrons_tracker_atVtx",eleIt->trackMomentumAtVtx());
  NtupleFactory_->Fill3V("electrons_tracker_Out",eleIt->trackMomentumOut());

  NtupleFactory_->FillFloat("electrons_ES",eleIt->superCluster()->preshowerEnergy());
  NtupleFactory_->FillFloat("electrons_SC_phiWidth",eleIt->superCluster()->phiWidth());
  NtupleFactory_->FillFloat("electrons_SC_etaWidth",eleIt->superCluster()->etaWidth());

  double R  = TMath::Sqrt(eleIt->superCluster()->x()*eleIt->superCluster()->x() + eleIt->superCluster()->y()*eleIt->superCluster()->y() +eleIt->superCluster()->z()*eleIt->superCluster()->z());
  double Rt = TMath::Sqrt(eleIt->superCluster()->x()*eleIt->superCluster()->x() + eleIt->superCluster()->y()*eleIt->superCluster()->y());

  NtupleFactory_->FillFloat("electrons_scE",eleIt->superCluster()->energy());
  NtupleFactory_->FillFloat("electrons_scEt",eleIt->superCluster()->energy()*(Rt/R));
  NtupleFactory_->FillFloat("electrons_scEta",eleIt->superCluster()->eta());
  NtupleFactory_->FillFloat("electrons_scPhi",eleIt->superCluster()->phi());


  
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
   Energy49_ = Energy25Barrel (EBMax.ieta(),EBMax.iphi(),7,barrelHitsCollection);
   Energy9_ =  Energy25Barrel (EBMax.ieta(),EBMax.iphi(),3,barrelHitsCollection);
   Energy4_ =  Energy4Barrel  (EBMax.ieta(),EBMax.iphi(),barrelHitsCollection);
   NtupleFactory_->FillFloat("Energy25",Energy25_);
   NtupleFactory_->FillFloat("Energy9",Energy9_); 
   NtupleFactory_->FillFloat("Energy49",Energy49_); 
   NtupleFactory_->FillFloat("Energy4",Energy4_);   
   NtupleFactory_->FillFloat("MaxEnergy",MaxEnergy_);
   NtupleFactory_->FillFloat("SwissE4",SwissE4Barrel(EBMax.ieta(),EBMax.iphi(),barrelHitsCollection));
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
   Energy9_ =  Energy25Endcap (EEMax.ix (), EEMax.iy (), EEMax.zside(),3, endcapHitsCollection) ;
   Energy4_ =   Energy4Endcap (EEMax.ix (), EEMax.iy (), EEMax.zside(),endcapHitsCollection);

   NtupleFactory_->FillFloat("Energy25",Energy25_);
   NtupleFactory_->FillFloat("Energy9",Energy9_); 
   NtupleFactory_->FillFloat("Energy49",Energy49_); 
   NtupleFactory_->FillFloat("Energy4",Energy4_); 
   NtupleFactory_->FillFloat("MaxEnergy",MaxEnergy_);
   NtupleFactory_->FillFloat("SwissE4",SwissE4Endcap(EEMax.ix (), EEMax.iy (), EEMax.zside(),endcapHitsCollection)); 
   Zenergy+=energia5+preshower_;
   fillAroundEndcap (endcapHitsCollection, EEMax.ix (), EEMax.iy (), pTk_) ;
  } //PG in the endcap
 
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

  NtupleFactory_->FillInt("iSM",iSM);
  NtupleFactory_->FillInt("iSC",iSC);

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

  if (doEleId_){
   reco::GsfElectronRef eleRef(pElectrons,eleIt - pElectrons->begin ());
   NtupleFactory_->FillFloat("electrons_eIDRobustLoose",(*(eleIdCutHandles[0]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eIDRobustLooseV00",(*(eleIdCutHandles[1]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eIDRobustTight",(*(eleIdCutHandles[2]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eIDRobustHighEnergy",(*(eleIdCutHandles[3]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eIDLoose",(*(eleIdCutHandles[4]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eIDTight",(*(eleIdCutHandles[5]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eIDClassesLoose",(*(eleIdCutHandles[6]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eIDClassesMedium",(*(eleIdCutHandles[7]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eIDClassesTight",(*(eleIdCutHandles[8]))[eleRef]); 
  }

  if (doEleIdCIC_){
   reco::GsfElectronRef eleRef(pElectrons,eleIt - pElectrons->begin ());
   NtupleFactory_->FillFloat("electrons_eidVeryLoose",(*(eleIdCutHandles[0]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eidLoose",(*(eleIdCutHandles[1]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eidMedium",(*(eleIdCutHandles[2]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eidTight",(*(eleIdCutHandles[3]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eidSuperTight",(*(eleIdCutHandles[4]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eidHyperTight1",(*(eleIdCutHandles[5]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eidHyperTight2",(*(eleIdCutHandles[6]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eidHyperTight3",(*(eleIdCutHandles[7]))[eleRef]); 
   NtupleFactory_->FillFloat("electrons_eidHyperTight4",(*(eleIdCutHandles[8]))[eleRef]); 
  }

 } //PG loop over electrons

 NtupleFactory_->FillInt("runId", iEvent.id().run());
 NtupleFactory_->FillInt("lumiId", iEvent.luminosityBlock());
 NtupleFactory_->FillInt("BXId", iEvent.bunchCrossing());
 NtupleFactory_->FillInt("eventId", iEvent.id().event());
 NtupleFactory_->FillInt("eventNaiveId", eventNaiveId_);

 edm::Handle<reco::CaloMETCollection> MetHandle ;
 iEvent.getByLabel (MetTag_,MetHandle);
 
 const reco::CaloMET* met = &(MetHandle->front());
 NtupleFactory_->Fill4V("met",met->p4());
 
 NtupleFactory_->FillFloat("sumEt",met->sumEt());

 dumpHLTInfo (hltresults,triggerNames);

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

void AlCaValidation::dumpHLTInfo (edm::Handle<edm::TriggerResults>  hltresults, const edm::TriggerNames & triggerNames)
{
  unsigned int trigger_size     = 0;
  unsigned int trigger_position = 0;

  if(hltresults.isValid()) {
    trigger_size = hltresults->size();
    trigger_position = triggerNames.triggerIndex("HLT_Photon10_L1R");
    if (trigger_position < trigger_size) 
      NtupleFactory_->FillInt("HLT_Photon10_L1R",(int) (hltresults->accept(trigger_position)));
    else NtupleFactory_->FillInt("HLT_Photon10_L1R",-500);

     trigger_position = triggerNames.triggerIndex("HLT_Photon15_L1R");
    if (trigger_position < trigger_size) 
      NtupleFactory_->FillInt("HLT_Photon15_L1R",(int) (hltresults->accept(trigger_position)));
    else NtupleFactory_->FillInt("HLT_Photon15_L1R",-500);

   trigger_position = triggerNames.triggerIndex("HLT_Photon20_L1R");
    if (trigger_position < trigger_size) 
      NtupleFactory_->FillInt("HLT_Photon20_L1R",(int) (hltresults->accept(trigger_position)));
    else NtupleFactory_->FillInt("HLT_Photon20_L1R",-500);

   trigger_position = triggerNames.triggerIndex("HLT_Ele15_LW_L1R");
    if (trigger_position < trigger_size) 
      NtupleFactory_->FillInt("HLT_Ele15_LW_L1R",(int) (hltresults->accept(trigger_position)));
    else NtupleFactory_->FillInt("HLT_Ele15_LW_L1R",-500);
  }
  else {
    NtupleFactory_->FillInt("HLT_Photon10_L1R",-999);
    NtupleFactory_->FillInt("HLT_Photon15_L1R",-999);
    NtupleFactory_->FillInt("HLT_Photon20_L1R",-999);
    NtupleFactory_->FillInt("HLT_Ele15_LW_L1R",-999);
  }
  return ;

} 


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



//! AM energy in the 2x2 neighbourhood around MaxId
//! in the barrel
double AlCaValidation::Energy4Barrel (int eta, int phi, const EcalRecHitCollection * barrelHitsCollection)
{

  int curr_eta = 0 ;
  int curr_phi = 0 ;

  double E4[4] = {0,0,0,0};
  
  for (int ii = -1 ; ii < 2 ; ++ii){
   for (int ij = -1 ; ij < 2 ; ++ij){
    curr_eta = eta + ii ;
    curr_phi = phi + ij ;
    if (abs (curr_eta) > 85) continue ;
    if (curr_eta * eta <= 0) 
    {
     if (eta > 0) --curr_eta ; 
     else curr_eta++ ; 
    }  // JUMP over 0
    if (curr_phi < 1) curr_phi += 360 ;
    if (curr_phi > 360) curr_phi -= 360 ;
    if (EBDetId::validDetId (curr_eta,curr_phi)){
     EBDetId det = EBDetId (curr_eta,curr_phi,EBDetId::ETAPHIMODE) ;
     EcalRecHitCollection::const_iterator curr_recHit = barrelHitsCollection->find (det) ;
     if (isnan(curr_recHit->energy())) continue;
     if (curr_recHit->energy()<0) continue;
     if (curr_recHit->energy()>1000) continue;
     int dx = diff_neta_s(eta,curr_eta);
     int dy = diff_nphi_s(phi,curr_phi);
     double en = curr_recHit->energy ();
     if(dx <= 0 && dy <=0) E4[0] += en;
     if(dx >= 0 && dy <=0) E4[1] += en;
     if(dx <= 0 && dy >=0) E4[2] += en;
     if(dx >= 0 && dy >=0) E4[3] += en;
    }
   }
  }
  return (*std::max_element( E4,E4+4));
}

// ----------------------------------------------------------------



  
//! AM energy in the 2x2 neighbourhood around MaxId
//! in the endcap   
double AlCaValidation::Energy4Endcap (int ics, int ips, int z, const EcalRecHitCollection * endcapHitsCollection){
 int curr_x = 0 ;
 int curr_y = 0 ;
 double E4[4] = {0,0,0,0};
 //PG loop on the energy reconstruction window
 for (int ii = -1 ; ii < 2 ; ++ii){
  for (int ij = -1 ; ij < 2 ; ++ij){
   curr_x = ics + ii ;
   curr_y = ips + ij ;
   if (curr_x>100 || curr_x<0) continue ; //PG prob qs ctrl nn serve visto qllo dopo
   if (curr_y>100 || curr_y<0) continue ; //PG prob qs ctrl nn serve visto qllo dopo
   if (EEDetId::validDetId (curr_x,curr_y,z))
   {
    EEDetId det = EEDetId (curr_x,curr_y,z,EEDetId::XYMODE) ;
    EcalRecHitCollection::const_iterator curr_recHit = endcapHitsCollection->find (det) ;
    if (isnan(curr_recHit->energy())) continue;
    if (curr_recHit->energy()<0) continue;
    if (curr_recHit->energy()>1000) continue;
    double en = curr_recHit->energy ();
    int dx = ics - curr_x;
    int dy = ips - curr_y;
    if(dx <= 0 && dy <=0) E4[0] += en;
    if(dx >= 0 && dy <=0) E4[1] += en;
    if(dx <= 0 && dy >=0) E4[2] += en;
    if(dx >= 0 && dy >=0) E4[3] += en;
   } 
  }
 } 
 return (*std::max_element( E4,E4+4));
}



// ----------------------------------------------------------------



//! AM energy in the 2x2 neighbourhood around MaxId Swiss Cross definition
//! in the barrel
double AlCaValidation::SwissE4Barrel (int eta, int phi, const EcalRecHitCollection * barrelHitsCollection)
{

 int curr_eta = 0 ;
 int curr_phi = 0 ;

 double E4 = 0;
  
 for (int ii = -1 ; ii < 2 ; ++ii){
  for (int ij = -1 ; ij < 2 ; ++ij){
   curr_eta = eta + ii ;
   curr_phi = phi + ij ;
   if (abs (curr_eta) > 85) continue ;
   if (curr_eta * eta <= 0) 
   {
    if (eta > 0) --curr_eta ; 
    else curr_eta++ ; 
   }  // JUMP over 0
   if (curr_phi < 1) curr_phi += 360 ;
   if (curr_phi > 360) curr_phi -= 360 ;
   if (EBDetId::validDetId (curr_eta,curr_phi)){
    EBDetId det = EBDetId (curr_eta,curr_phi,EBDetId::ETAPHIMODE) ;
    EcalRecHitCollection::const_iterator curr_recHit = barrelHitsCollection->find (det) ;
    if (isnan(curr_recHit->energy())) continue;
    if (curr_recHit->energy()<0) continue;
    if (curr_recHit->energy()>1000) continue;
    int dx = diff_neta_s(eta,curr_eta);
    int dy = diff_nphi_s(phi,curr_phi);
    double en = curr_recHit->energy ();
    if(dx != 0 && dy ==0) E4 += en;
    if(dx == 0 && dy !=0) E4 += en;
   }
  }
 }
 return E4;
}

// ----------------------------------------------------------------



  
//! AM energy in the 2x2 neighbourhood around MaxId Swiss Cross definition
//! in the endcap   
double AlCaValidation::SwissE4Endcap (int ics, int ips, int z, const EcalRecHitCollection * endcapHitsCollection){
 int curr_x = 0 ;
 int curr_y = 0 ;
 double E4 = 0;
 //PG loop on the energy reconstruction window
 for (int ii = -1 ; ii < 2 ; ++ii){
  for (int ij = -1 ; ij < 2 ; ++ij){
   curr_x = ics + ii ;
   curr_y = ips + ij ;
   if (curr_x>100 || curr_x<0) continue ; //PG prob qs ctrl nn serve visto qllo dopo
   if (curr_y>100 || curr_y<0) continue ; //PG prob qs ctrl nn serve visto qllo dopo
   if (EEDetId::validDetId (curr_x,curr_y,z))
   {
    EEDetId det = EEDetId (curr_x,curr_y,z,EEDetId::XYMODE) ;
    EcalRecHitCollection::const_iterator curr_recHit = endcapHitsCollection->find (det) ;
    if (isnan(curr_recHit->energy())) continue;
    if (curr_recHit->energy()<0) continue;
    if (curr_recHit->energy()>1000) continue;
    double en = curr_recHit->energy ();
    int dx = ics - curr_x;
    int dy = ips - curr_y;
    if(dx != 0 && dy ==0) E4 += en;
    if(dx == 0 && dy !=0) E4 += en;
   } 
  }
 } 
 return E4;
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

// ----------------------------------------------------------------

int AlCaValidation::diff_neta_s(Int_t neta1, Int_t neta2){
 Int_t mdiff;
 mdiff=(neta1-neta2);
 return mdiff;
}
 
// ----------------------------------------------------------------

 // Calculate the distance in xtals taking into account the periodicity of the Barrel 
 
int AlCaValidation::diff_nphi_s(Int_t nphi1,Int_t nphi2) { 
 Int_t mdiff; 
 if(abs(nphi1-nphi2) < (360-abs(nphi1-nphi2))) { 
  mdiff=nphi1-nphi2; 
 } 
 else { 
  mdiff=360-abs(nphi1-nphi2); 
  if(nphi1>nphi2) mdiff=-mdiff; 
 } 
 return mdiff; 
} 

// ----------------------------------------------------------------


//define this as a plug-in
DEFINE_FWK_MODULE(AlCaValidation);
