import FWCore.ParameterSet.Config as cms

process = cms.Process("VBFHiggsToVVPreselTEST")

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

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

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


# --- THE LOOSE JET FILTER --- --- --- --- --- --- --- --- --- --- --- 

from HiggsAnalysis.VBFHiggsToVV.FwdJetsPreselFilter_cfi import *
process.VBFselect = looseVBFselect.clone()

# --- THE ELECTRONS PT FILTER --- --- --- --- --- --- --- --- --- --- --- 

from HiggsAnalysis.VBFHiggsToVV.LepMinNumFilter_cfi import *
process.minLepSelect = minLepSelector.clone()

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
                               
process.p = cms.Path (process.VBFselect +
                      process.minLepSelect)


# process.o = cms.EndPath ( process.out )
