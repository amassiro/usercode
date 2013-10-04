import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        #'file:/data/amassiro/CMSSWRoot/Summer12/WH_HToZZTo4L_M-125_8TeV-pythia6_AODSIM_PU_S10_START53_V7C-v1/2204BC4B-D4A0-E211-ADA0-003048F0E5AA.root'
        'file:../../../WH_HToZZTo4Mu_WToMuNu_M_125_TuneZ2star_8TeV_pythia6_tauola_cff_py_GEN.root'
    )
)

process.demo = cms.EDAnalyzer('GenComparison',
  isWH   = cms.untracked.bool(True),
)



process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("WH_Pythia.root")
    )

process.p = cms.Path(process.demo)


