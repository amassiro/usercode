// -*- C++ -*-
//
// Package:    GenFilters
// Class:      LepMinNumFilter
// 
/**\class LepMinNumFilter LepMinNumFilter.cc GeneratorInterface/GenFilters/src/LepMinNumFilter.cc

 Description: require at least a given number of leptons (m_nLep) 
 with a minimum pT (m_ptThres) in the gen particles collection (m_genParticlesTag) for each event,
 with |eta| < 2.7

 Implementation:
     leptons are electrons, muons, taus, identified by the PDG MC particle numbering scheme: 11, 13, 15
*/
//
// Original Author:  P. Govoni
//         Created:  Mon Apr 20 15:02:55 CEST 2009
// $Id: LepMinNumFilter.cc,v 1.2 2009/03/26 23:03:28 yarba Exp $
//
//


// system include files
//#include <vector>
//#include <boost/format.hpp>

// user include files
#include "HiggsAnalysis/VBFHiggsToVV/plugins/LepMinNumFilter.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"


//! ctor
LepMinNumFilter::LepMinNumFilter (const edm::ParameterSet& iConfig) : 
  m_electronsTag (iConfig.getParameter<edm::InputTag> ("electronsTag")) ,
  m_muonsTag (iConfig.getParameter<edm::InputTag> ("muonsTag")) ,
  m_ptThres (iConfig.getParameter<double> ("ptThres")) ,
  m_nLep (iConfig.getParameter<int> ("nLep")) 
{}


// ----------------------------------------------------------------


//! dtor
LepMinNumFilter::~LepMinNumFilter () {}


// ----------------------------------------------------------------


void LepMinNumFilter::beginJob (const edm::EventSetup&) 
{}


// ----------------------------------------------------------------


void LepMinNumFilter::endJob () 
{}


// ----------------------------------------------------------------


//! loop over the gen particles and count leptons
bool 
LepMinNumFilter::filter (
    edm::Event& iEvent,
    const edm::EventSetup& iSetup) 
{
  edm::Handle<reco::MuonCollection> muonsHandle ;
  iEvent.getByLabel (m_muonsTag, muonsHandle) ;

  edm::Handle<edm::View<reco::GsfElectron> > electronsHandle ;
  iEvent.getByLabel (m_electronsTag, electronsHandle) ;

  int nSelected = 0 ;

  //PG loop over electrons
  for (int iEle = 0 ; iEle < electronsHandle->size () ; ++iEle)
    {
      if (electronsHandle->at (iEle).eta () < 2.7 &&
          electronsHandle->at (iEle).pt () > m_ptThres) ++nSelected ;
    } //PG loop over electrons

  //PG loop over muons
  for (int iMu = 0 ; iMu < muonsHandle->size () ; ++iMu)
    {
       if (muonsHandle->at (iMu).eta () < 2.7 &&
           muonsHandle->at (iMu).pt () > m_ptThres) ++nSelected ;
    } //PG loop over muons

  if (nSelected >= m_nLep) return true ;
  return false ;
}
