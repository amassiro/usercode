import FWCore.ParameterSet.Config as cms

cleanedJetTemplateCaloJet = cms.EDFilter("VBFJetCleaningTemplateCaloJet",
   src = cms.InputTag("L2L3CorJetIcone5"),
   GSFInputTag = cms.InputTag("pixelMatchGsfElectrons"),
   maxDeltaR = cms.double(0.2),
   maxHEoverEmE = cms.double(0.2),
   minEleOJetEratio = cms.double(0.9)
)

cleanedJetTemplateCaloJetRef = cms.EDFilter("VBFJetCleaningTemplateCaloJetRef",
   src = cms.InputTag("L2L3CorJetIcone5"),
   GSFInputTag = cms.InputTag("pixelMatchGsfElectrons"),
   maxDeltaR = cms.double(0.2),
   maxHEoverEmE = cms.double(0.2),
   minEleOJetEratio = cms.double(0.9)
)

# cleanedJetTemplatePFJet = cms.EDFilter("VBFJetCleaningTemplatePFJet",
#    src = cms.InputTag("iterativeCone5PFJets"),
#    GSFInputTag = cms.InputTag("pixelMatchGsfElectrons"),
#    maxDeltaR = cms.double(0.2),
#    maxHEoverEmE = cms.double(0.2),
#    minEleOJetEratio = cms.double(0.9)
# )
# 
# cleanedJetTemplatePFJet = cms.EDFilter("VBFJetCleaningTemplatePFJetRef",
#    src = cms.InputTag("iterativeCone5PFJets"),
#    GSFInputTag = cms.InputTag("pixelMatchGsfElectrons"),
#    maxDeltaR = cms.double(0.2),
#    maxHEoverEmE = cms.double(0.2),
#    minEleOJetEratio = cms.double(0.9)
# )


