import FWCore.ParameterSet.Config as cms

process = cms.Process("PreselTEST")

# --- ============== --- --- --- --- --- --- --- --- --- --- --- --- 
# --- general things --- --- --- --- --- --- --- --- --- --- --- --- 
# --- ============== --- --- --- --- --- --- --- --- --- --- --- --- 

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True))

process.load("Configuration.StandardSequences.Geometry_cff") # for CaloGeometryRecord

process.load('Configuration/StandardSequences/Services_cff')
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'INFO'

# --- ====== --- --- --- --- --- --- --- --- --- --- --- 
# --- INPUT  --- --- --- --- --- --- --- --- --- --- --- 
# --- ====== --- --- --- --- --- --- --- --- --- --- --- 

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(500))

process.source = cms.Source(
    "PoolSource",
    debugFlag = cms.untracked.bool(True),
    debugVebosity = cms.untracked.uint32(1),
    fileNames = cms.untracked.vstring(
      'file:/data/govoni/HiggsTest/FC722191-8DC6-DD11-9772-001A645CEDA6.root',
    )
    )
    
# --- ==================== --- --- --- --- --- --- --- --- --- --- --- 
# --- THE VBF SELECTIONS   --- --- --- --- --- --- --- --- --- --- --- 
# --- ==================== --- --- --- --- --- --- --- --- --- --- --- 


# --- THE AMBIGUITY RESOLVER --- --- --- --- --- --- --- --- --- --- --- 

from HiggsAnalysis.VBFHiggsToVV.VBFEleAmbiguityResolver_cfi import *
process.ambResolver = ambiguityResolvedElectrons.clone()

# --- THE JET CLEANING --- --- --- --- --- --- --- --- --- --- --- 

from HiggsAnalysis.VBFHiggsToVV.VBFJetCleaner_cfi import *
process.caloJetCleaner = cleanedJetTemplateCaloJet.clone()
process.caloJetCleaner.src = cms.InputTag("iterativeCone5CaloJets")
process.caloJetCleaner.GSFInputTag = cms.InputTag("ambResolver")
#process.caloJetCleaner.src = cms.InputTag("L2L3CorJetIcone5")

# --- THE LOOSE JET FILTER --- --- --- --- --- --- --- --- --- --- --- 

from HiggsAnalysis.VBFHiggsToVV.FwdJetsPreselFilter_cfi import *
process.VBFselect = looseVBFselect.clone()

# --- THE ELECTRONS PT FILTER --- --- --- --- --- --- --- --- --- --- --- 

from HiggsAnalysis.VBFHiggsToVV.LepMinNumFilter_cfi import *
process.minLepSelect = minLepSelector.clone()
process.minLepSelect.electronsTag = cms.InputTag("ambResolver")

# --- ====== --- --- --- --- --- --- --- --- --- --- --- 
# --- OUTPUT --- --- --- --- --- --- --- --- --- --- --- 
# --- ====== --- --- --- --- --- --- --- --- --- --- --- 

process.out = cms.OutputModule("PoolOutputModule",
                               verbose = cms.untracked.bool(True),
                               fileName = cms.untracked.string('VBFHiggsToVVPreselTEST.root'),
                               outputCommands = cms.untracked.vstring('keep *')
                               )

# --- ====== --- --- --- --- --- --- --- --- --- --- --- 
# --- PATHS  --- --- --- --- --- --- --- --- --- --- --- 
# --- ====== --- --- --- --- --- --- --- --- --- --- --- 
                               
process.p = cms.Path (process.ambResolver +
                      process.caloJetCleaner +
                      process.VBFselect +
                      process.minLepSelect)


# process.o = cms.EndPath ( process.out )
