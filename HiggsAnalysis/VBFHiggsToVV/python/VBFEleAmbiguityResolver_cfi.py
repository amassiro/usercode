import FWCore.ParameterSet.Config as cms


ambiguityResolvedElectrons = cms.EDFilter("VBFEleAmbiguityResolution",
   src = cms.InputTag("pixelMatchGsfElectrons"),
)


# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


ambiguityResolvedElectronsRef = cms.EDFilter("VBFEleAmbiguityResolutionRef",
   src = cms.InputTag("pixelMatchGsfElectrons"),
)


# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


ambiguityResolvedElectronsSequence = cms.Sequence (
 ambiguityResolvedElectrons *
 ambiguityResolvedElectronsRef 
)

