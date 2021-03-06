import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        #'file:WplusH_Wmunu_8TeV_cff_py_GEN.root'
        'file:WplusH_HWW_allWmunu_8TeV_cff_py_GEN.root'
    )
)

process.demo = cms.EDAnalyzer('GenComparison',
  isWH = cms.untracked.bool(True),
  saveLHE = cms.untracked.bool(True)
)



process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("WH_Minlo.root")
    )

process.p = cms.Path(process.demo)
