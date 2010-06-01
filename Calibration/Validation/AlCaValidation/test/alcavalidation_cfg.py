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

#readFiles.extend( ['file:../../AlCaTest/test/AAB867A5-395C-DF11-902A-002618FDA26D.root'] );
#readFiles.extend( ['file:../scripts/EcalCalElectron_1_1.root'] );
#readFiles.extend( ['file:/gwtera/cms/users/amassiro/AlCaReco/May6thReRecoDump/EcalCalElectron_14_1.root'] );
readFiles.extend( ['file:/tmp/amassiro/AlCaDump/EcalCalElectron_3_1.root'] );

process.AlCaValidationTEST = cms.EDAnalyzer("AlCaValidation",
  MetTag                  = cms.InputTag("met"),
  ElectronLabel           = cms.InputTag("gsfElectrons"),
  AlcaBarrelHitCollection = cms.InputTag("alCaIsolatedElectrons:alcaBarrelHits"),
  AlcaEndcapHitCollection = cms.InputTag("alCaIsolatedElectrons:alcaEndcapHits"),
  EcalIsoTag              = cms.InputTag("egammaEcalIsolation"),
  ElePtTkIsoTag           = cms.InputTag("egammaElectronSqPtTkIsolation"),
  EleTkIsoTag             = cms.InputTag("egammaElectronTkIsolation"),
  HoETag                  = cms.InputTag("egammaHOE"),
  HCalIsoTag              = cms.InputTag("egammaHcalIsolation")
)

process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("ValidAlCaTest.root"),
    closeFileFast = cms.untracked.bool(True)
)


process.p = cms.Path(process.AlCaValidationTEST)
