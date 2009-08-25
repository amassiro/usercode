#ifndef LepMinNumFilter_h
#define LepMinNumFilter_h

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/MakerMacros.h"

//
// class declaration
//

class LepMinNumFilter : public edm::EDFilter {

  public:
    explicit LepMinNumFilter (const edm::ParameterSet&) ;
    ~LepMinNumFilter () ;

  private:
    virtual void beginJob (const edm::EventSetup&)  ;
    virtual bool filter (edm::Event&, const edm::EventSetup&) ;
    virtual void endJob ()  ;

  private:

    edm::InputTag m_electronsTag ;
    edm::InputTag m_muonsTag ;
    double m_ptThres ;
    int m_nLep ;

} ;


#endif
