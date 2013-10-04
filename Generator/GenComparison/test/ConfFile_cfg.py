import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        #'file:WH_WToMuNu_H_M_125_8TeV_powheg_herwigpp_cff_py_GEN.root'
        'file:WplusH_Wmunu_8TeV_cff_py_GEN.root'
    )
)

process.demo = cms.EDAnalyzer('GenComparison'
)



process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("testMINLO.root")
    )

process.p = cms.Path(process.demo)
