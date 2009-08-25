import FWCore.ParameterSet.Config as cms

process = cms.Process("AmbResolverTEST")

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

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10))

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

# --- THE JET CLEANING --- --- --- --- --- --- --- --- --- --- --- 

from HiggsAnalysis.VBFHiggsToVV.VBFJetCleaner_cfi import *
process.caloJetCleaner = cleanedJetTemplateCaloJet.clone()
process.caloJetCleaner.src = cms.InputTag("iterativeCone5CaloJets")
#process.caloJetCleaner.src = cms.InputTag("L2L3CorJetIcone5")

from HiggsAnalysis.VBFHiggsToVV.VBFJetCleaner_cfi import *
process.caloJetCleanerRef = cleanedJetTemplateCaloJetRef.clone()
process.caloJetCleanerRef.src = cms.InputTag("iterativeCone5CaloJets")
#process.caloJetCleanerRef.src = cms.InputTag("L2L3CorJetIcone5")


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
                               
process.p = cms.Path (process.caloJetCleaner +
                      process.caloJetCleanerRef)


# process.o = cms.EndPath ( process.out )
