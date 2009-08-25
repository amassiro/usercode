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


# --- THE AMBIGUITY RESOLVER --- --- --- --- --- --- --- --- --- --- --- 

from HiggsAnalysis.VBFHiggsToVV.VBFEleAmbiguityResolver_cfi import *
process.ambResolver = ambiguityResolvedElectrons.clone()


from HiggsAnalysis.VBFHiggsToVV.VBFEleAmbiguityResolver_cfi import *
process.ambResolverRef = ambiguityResolvedElectronsRef.clone()


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
                      process.ambResolverRef)


# process.o = cms.EndPath ( process.out )
