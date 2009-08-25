# import FWCore.ParameterSet.Config as cms
# 
# ## Jet cleaning  ##
# 
# process.load("HiggsAnalysis.VBFHiggsToVV.VBFJetCleanerTemplateCaloJet_cfi")
# #process.load("HiggsAnalysis.VBFHiggsToVV.VBFJetCleanerTemplatePFJet_cfi")
# from HiggsAnalysis.VBFHiggsToWWto2l2nu.VBFJetCleanerTemplateCaloJet_cfi import cleanedJetTemplateCaloJet
# from HiggsAnalysis.VBFHiggsToWWto2l2nu.VBFJetCleanerTemplatePFJet_cfi import cleanedJetTemplatePFJet
# 
# process.cleanedIterativeCone5CaloJets = cleanedJetTemplateCaloJet.clone(
#    src = cms.InputTag("iterativeCone5CaloJets"),
#    GSFInputTag = cms.InputTag("isolatedElectrons")
# )
# 
# process.cleanedSisCone5CaloJets = cleanedJetTemplateCaloJet.clone(
#    src = cms.InputTag("sisCone5CaloJets"),
#    GSFInputTag = cms.InputTag("isolatedElectrons") 
# )
# 
# process.cleanedIterativeCone5PFJets = cleanedJetTemplatePFJet.clone(
#    src = cms.InputTag("iterativeCone5PFJets"),
#    GSFInputTag = cms.InputTag("isolatedElectrons") 
# )
# 
# process.cleanedSisCone5PFJets = cleanedJetTemplatePFJet.clone(
#    src = cms.InputTag("sisCone5PFJets"),
#    GSFInputTag = cms.InputTag("isolatedElectrons") 
# )
# 
# process.jetCleaningSequence = cms.Sequence(
#  process.cleanedIterativeCone5CaloJets +
#  process.cleanedSisCone5CaloJets       +
#  process.cleanedIterativeCone5PFJets   +
#  process.cleanedSisCone5PFJets 
# )
