import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        #'file:ZH_ZToMuMu_H_M_125_8TeV_powheg_herwigpp_cff_py_GEN.root'
        'file:../../../ZH_ZToMuMu_HToWW_M_125_8TeV_powheg_herwigpp_cff_py_GEN.root'
      )
)

process.demo = cms.EDAnalyzer('GenComparison',
    isZH   = cms.untracked.bool(True),
)



process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("ZH_Herwig.root")
    )

process.p = cms.Path(process.demo)
