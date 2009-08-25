import FWCore.ParameterSet.Config as cms

process = cms.Process("HLTTEST")

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
#       'file:/tmp/amassiro/VBFHWW2l2nuTest_1.root'
        'file:/tmp/amassiro/FC722191-8DC6-DD11-9772-001A645CEDA6.root'
#       'file:/media/amassiro/Data/HVV_test/FC722191-8DC6-DD11-9772-001A645CEDA6.root',
    )
)
    
# --- ==================== --- --- --- --- --- --- --- --- --- --- --- 
# --- THE VBF SELECTIONS   --- --- --- --- --- --- --- --- --- --- --- 
# --- ==================== --- --- --- --- --- --- --- --- --- --- --- 

# --- THE HLT --- --- --- --- --- --- --- --- --- --- --- 

from HLTrigger.HLTfilters.hltHighLevel_cfi import *
process.hltHighLevel_VBF = hltHighLevel.clone(
 HLTPaths = cms.vstring("HLT_Mu9","HLT_Mu11","HLT_Mu15","HLT_DoubleMu3","HLT_IsoMu9","HLT_IsoEle18_L1R","HLT_LooseIsoEle15_LW_L1R","HLT_Ele10_SW_L1R","HLT_Ele15_SW_L1R","HLT_DoubleEle5_SW_L1R","HLT_Jet110","HLT_Jet180","HLT_DiJetAve70","HLT_DiJetAve130","HLT_FwdJet20","HLT_IsoEle12_Jet40","HLT_IsoEle12_DoubleJet80","HLT_IsoMu7_Jet40")
)

process.report = cms.EDFilter("HLTrigReport",
    HLTriggerResults = cms.InputTag("TriggerResults","","HLT")
)



# --- ====== --- --- --- --- --- --- --- --- --- --- --- 
# --- OUTPUT --- --- --- --- --- --- --- --- --- --- --- 
# --- ====== --- --- --- --- --- --- --- --- --- --- --- 

process.out = cms.OutputModule("PoolOutputModule",
                               verbose = cms.untracked.bool(True),
                               fileName = cms.untracked.string('/tmp/amassiro/VBFHiggsToVVHLTTest.root'),
                               outputCommands = cms.untracked.vstring('keep *')
                               )

# --- ====== --- --- --- --- --- --- --- --- --- --- --- 
# --- PATHS  --- --- --- --- --- --- --- --- --- --- --- 
# --- ====== --- --- --- --- --- --- --- --- --- --- --- 
                               
process.p = cms.Path (process.report + process.hltHighLevel_VBF)


# process.o = cms.EndPath ( process.out )
