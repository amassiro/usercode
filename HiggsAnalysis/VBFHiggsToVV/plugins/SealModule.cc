#include <FWCore/PluginManager/interface/ModuleDef.h>
#include <FWCore/Framework/interface/MakerMacros.h>
#include "PhysicsTools/UtilAlgos/interface/ObjectSelector.h"
#include "PhysicsTools/UtilAlgos/interface/SortCollectionSelector.h"

//PG FIXME jet cleaner : from where?

#include "HiggsAnalysis/VBFHiggsToVV/plugins/FwdJetsPreselFilter.h"
DEFINE_ANOTHER_FWK_MODULE(FwdJetsPreselFilter) ;

#include "HiggsAnalysis/VBFHiggsToVV/plugins/LepMinNumFilter.h"
DEFINE_ANOTHER_FWK_MODULE(LepMinNumFilter) ;

#include "HiggsAnalysis/VBFHiggsToVV/plugins/VBFEleAmbiguityResolver.h"
typedef ObjectSelector<VBFEleAmbiguityResolver> VBFEleAmbiguityResolution ;
typedef ObjectSelector<VBFEleAmbiguityResolver, edm::RefVector<reco::PixelMatchGsfElectronCollection> > VBFEleAmbiguityResolutionRef ;
DEFINE_ANOTHER_FWK_MODULE (VBFEleAmbiguityResolution);
DEFINE_ANOTHER_FWK_MODULE (VBFEleAmbiguityResolutionRef);

#include "HiggsAnalysis/VBFHiggsToVV/plugins/VBFJetCleanerTemplate.h"
typedef ObjectSelector<VBFJetCleanerTemplate<reco::CaloJetCollection> > VBFJetCleaningTemplateCaloJet ;
DEFINE_ANOTHER_FWK_MODULE (VBFJetCleaningTemplateCaloJet) ;
typedef ObjectSelector<VBFJetCleanerTemplate<reco::CaloJetCollection>,
edm::RefVector<reco::CaloJetCollection>
  > VBFJetCleaningTemplateCaloJetRef ;
DEFINE_ANOTHER_FWK_MODULE (VBFJetCleaningTemplateCaloJetRef) ;

//PG FIXME
//PG - does pflow need jet cleaning?
typedef ObjectSelector<VBFJetCleanerTemplate<reco::PFJetCollection> > VBFJetCleaningTemplatePFJet ;
DEFINE_ANOTHER_FWK_MODULE (VBFJetCleaningTemplatePFJet) ;
typedef ObjectSelector<VBFJetCleanerTemplate<reco::PFJetCollection>,
edm::RefVector<reco::PFJetCollection>
  > VBFJetCleaningTemplatePFJetRef ;
DEFINE_ANOTHER_FWK_MODULE (VBFJetCleaningTemplatePFJetRef) ;

