import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        #'file:/data/amassiro/CMSSWRoot/Summer12/Summer12_DR53X_ZH_HToZZTo4L_M-125_8TeV-pythia6_AODSIM_PU_S10_START53_V7C-v1/F6D893B1-BBA0-E211-A38E-0025901D493C.root'
        'file:../../../ZH_HToZZTo4Mu_ZToMuMu_M_125_TuneZ2star_8TeV_pythia6_tauola_cff_py_GEN.root'
    )
)

process.demo = cms.EDAnalyzer('GenComparison',
      isZH   = cms.untracked.bool(True),
)



## if you need some filter modules define and configure them here
#process.genParticlesForFilter = cms.EDProducer("GenParticleProducer",
    #saveBarCodes = cms.untracked.bool(True),
    #src = cms.InputTag("generator"),
    #abortOnUnknownPDGCode = cms.untracked.bool(True)
#)

#process.genSelectorFourLep = cms.EDFilter("GenParticleSelector",
  #filter = cms.bool(True),
  #src = cms.InputTag('genParticlesForFilter'),
  #cut = cms.string('(abs(pdgId()) == 11 || abs(pdgId()) == 13 || abs(pdgId()) == 15) && (mother().pdgId() == 23 || abs(mother().pdgId()) == 24)'), 
 #)

#process.selectedFourLepCandFilter = cms.EDFilter("CandViewCountFilter",
   #src = cms.InputTag('genSelectorFourLep'),
   #filter = cms.bool(True),
   #minNumber = cms.uint32(6)
 #)

#process.productionFilterSequence = cms.Sequence(process.genParticlesForFilter + process.genSelectorFourLep + process.selectedFourLepCandFilter)



process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("ZH_Pythia.root")
    )

process.p = cms.Path(process.demo)


