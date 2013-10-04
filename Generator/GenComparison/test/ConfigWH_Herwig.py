import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        #'file:WH_WToMuNu_H_M_125_8TeV_powheg_herwigpp_cff_py_GEN.root'
        #'file:../../../WH_HtoZZ_M_125_8TeV_powheg_herwigpp_cff_py_GEN.root'
        #'file:../../../WH_WToMuNu_HtoZZ_M_125_8TeV_powheg_herwigpp_cff_py_GEN.root'
        'file:../../../WH_WToMuNu_HtoZZ_M_125_8TeV_powheg_herwigpp_cff_py_GEN_minjetkt_1.root'
    )
)

process.demo = cms.EDAnalyzer('GenComparison',
  isWH = cms.untracked.bool(True)
)



process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("WH_Herwig.root")
    #fileName = cms.string("WH_Herwig_WH_HZZ_WMuNu.root")
    #fileName = cms.string("WH_Herwig_WH_HZZ_WMuNu_minjetkt1.root")
    )

process.p = cms.Path(process.demo)
