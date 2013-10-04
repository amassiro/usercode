import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
     'file:/data/amassiro/CMSSWRoot/Summer12/VBF_HToWWTo2LAndTau2Nu_M-125_8TeV-powheg-pythia6_AODSIM/00344783-8FFC-E111-BA46-00266CFFC13C.root'
    )
)

process.demo = cms.EDAnalyzer('ParticleDumper',
)

process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("HWW_particleDumper.root")
    )

process.p = cms.Path(process.demo)
