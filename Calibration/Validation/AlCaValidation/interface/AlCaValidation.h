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
// $Id: AlCaValidation.h,v 1.1 2010/05/14 21:10:33 amassiro Exp $
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

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/EgammaReco/interface/BasicClusterShapeAssociation.h"

#include "RecoEcal/EgammaCoreTools/interface/EcalClusterTools.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "Calibration/EcalAlCaRecoProducers/interface/AlCaElectronsProducer.h"
#include "DataFormats/EgammaCandidates/interface/SiStripElectron.h"
#include "DataFormats/EgammaCandidates/interface/ElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/Electron.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/EgammaReco/interface/BasicCluster.h"

//DS momentum
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/BasicCluster.h"
#include "DataFormats/EgammaReco/interface/ClusterShapeFwd.h"
#include "DataFormats/EgammaReco/interface/BasicClusterShapeAssociation.h"

#include "CondFormats/EcalObjects/interface/EcalIntercalibConstants.h"
#include "CondFormats/DataRecord/interface/EcalIntercalibConstantsRcd.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "CalibCalorimetry/CaloMiscalibTools/interface/EcalRecHitRecalib.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrackFwd.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"


#include "PhysicsTools/NtupleUtils/interface/NtupleFactory.h"

#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"



//
// class declaration
//

class AlCaValidation : public edm::EDAnalyzer {
   public:
      explicit AlCaValidation(const edm::ParameterSet&);
      ~AlCaValidation();

   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

     double Energy25Barrel (int eta, int phi,int side, const EBRecHitCollection* EBhits) ; //MF
     double Energy25Endcap (int ics, int ips, int z,int side, const EERecHitCollection* EEhits) ; //MF

     //!MF riempie grafico 5x5
     void EnergyOn25Barrel (int eta, int phi, const EBRecHitCollection* EBhits) ;
     
     void fillAroundBarrel (const EcalRecHitCollection * recHits, 
                            int eta, int phi, double momentum) ;
     void fillAroundEndcap (const EcalRecHitCollection * recHits, 
                            int ics, int ips, double momentum) ;


      // ----------member data ---------------------------

  edm::InputTag ElectronLabel_;
  edm::InputTag AlcaBarrelHitCollection_;
  edm::InputTag AlcaEndcapHitCollection_;

  TTree* outTree_;
  TH2F * hBarrelGlobalCrystalsMap_ ;
  TH2F * hEndcapGlobalCrystalsMap_ ;
  //! Energy aroung the MOX
  TH2F * hBarrelLocalCrystalsEnergy_ ;
  TH2F * hEndcapLocalCrystalsEnergy_ ;
  TH1F * hZee_;

  
  float eta_;
  float phi_;
  float pTk_;
  float MaxEnergy_;
  float energy_;
  float Energy25_;
  float ESCoP_;
  float eSeedOverPout_;
  float pOut_;
  float preshower_;
  float Energy9_;
  float Energy49_;
  float pErr_;
  int class_;
  float recHits_;
  double chis_;
  int lost_;
  int found_;
  double momentum_;
  double ndof_;
  double chisN_;

  int eventNaiveId_;

  NtupleFactory* NtupleFactory_;

};
