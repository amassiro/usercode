import FWCore.ParameterSet.Config as cms

process = cms.Process("AlCaValidationTEST")
process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

process.options = cms.untracked.PSet(
        wantSummary = cms.untracked.bool(True)
        )

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring()

process.source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)

secFiles.extend( (
                   ) )

#readFiles.extend( ['
     #"file:/tmp/amassiro/MC/EcalCalElectron_6_1.root"
   #' ] );

readFiles.extend( ['/store/relval/CMSSW_3_5_8/RelValZEE/ALCARECO/START3X_V26_EcalCalElectron-v1/0017/8622EA17-9052-DF11-8644-00304867D836.root','/store/relval/CMSSW_3_5_8/RelValZEE/ALCARECO/START3X_V26_EcalCalElectron-v1/0016/D64BA39D-6E52-DF11-BDF3-002618943879.root' ] );





process.AlCaValidationTEST = cms.EDAnalyzer("AlCaValidation",
  ElectronLabel=cms.InputTag("gsfElectrons"),
  AlcaBarrelHitCollection=cms.InputTag("alCaIsolatedElectrons:alcaBarrelHits"),
  AlcaEndcapHitCollection=cms.InputTag("alCaIsolatedElectrons:alcaEndcapHits"),
  HistOutFile = cms.untracked.string("Validation_Ntuple_TTbar_3_7_0_pre4.root"),
  EcalIsoTag = cms.InputTag("egammaEcalIsolation"),
  ElePtTkIsoTag = cms.InputTag("egammaElectronSqPtTkIsolation"),
  EleTkIsoTag = cms.InputTag("egammaElectronTkIsolation"),
  HoETag = cms.InputTag("egammaHOE"),
  HCalIsoTag = cms.InputTag("egammaHcalIsolation"),
  METTag = cms.InputTag("met")
)

process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("/tmp/amassiro/ValidAlCaTest.root"),
    closeFileFast = cms.untracked.bool(True)
)


process.p = cms.Path(process.AlCaValidationTEST)
