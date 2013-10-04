import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing ('analysis')
# add a list of strings for events to process
# only new variables!
#options.register ('inputFiles',
                  #'',
                  #VarParsing.multiplicity.list,
                  #VarParsing.varType.string,
                  #"input files")

options.parseArguments()


process = cms.Process("MYANALYSIS")


#process.load('Configuration.StandardSequences.Services_cff')
#process.load('Configuration.StandardSequences.GeometryDB_cff')
#process.load('Configuration.StandardSequences.MagneticField_38T_cff')
#process.load('Configuration.StandardSequences.Reconstruction_cff')
#process.load('Configuration.StandardSequences.EndOfProcess_cff')
#process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
#process.load('Configuration.EventContent.EventContent_cff')


process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.printTree = cms.EDAnalyzer("ParticleTreeDrawer",
                                   src = cms.InputTag("genParticles"),
                                   printP4 = cms.untracked.bool(False),
                                   printPtEtaPhi = cms.untracked.bool(False),
                                   printVertex = cms.untracked.bool(False),
                                   printStatus = cms.untracked.bool(False),
                                   printIndex = cms.untracked.bool(False),
                                   status = cms.untracked.vint32( 3 )
                                   )


process.printDecay = cms.EDAnalyzer("ParticleDecayDrawer",
    src = cms.InputTag("genParticles"),
    printP4 = cms.untracked.bool(False),
    printPtEtaPhi = cms.untracked.bool(False),
    printVertex = cms.untracked.bool(False)
  )



process.printListTree = cms.EDAnalyzer("ParticleListDrawer",
  maxEventsToPrint = cms.untracked.int32(1),
  printVertex = cms.untracked.bool(False),
  src = cms.InputTag("genParticles")
)




process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring('RMMEFN'))
process.source.fileNames = cms.untracked.vstring(
   #'file:/tmp/amassiro/provaGENSIM.root'
   #'file:/tmp/amassiro/SILHMCHM4_14TeV_modified_GEN.root'
   #'file:/data/amassiro/CMSSWRoot/Summer12/VBF_HToWWTo2LAndTau2Nu_M-600_8TeV-powheg-pythia6_AODSIM/F86C4A2D-9492-E111-847C-1CC1DE0540F0.root'
   #'file:/data/amassiro/CMSSWRoot/Summer12/GluGluToHHTo2B2WToLNuLNu_mH-125_8TeV-madgraph-pythia6-tauola_AODSIM_PU_S10_START53_V19-v1/4486E5A3-3EF7-E211-A407-0017A4770834.root'
   #'file:ZH_Zmumu_8TeV_cff_py_GEN.root'
   #'file:ZH_ZToMuMu_H_M_125_8TeV_powheg_herwigpp_cff_py_GEN.root'
   #'file:/data/amassiro/CMSSWRoot/Summer12/WH_HToZZTo4L_M-125_8TeV-pythia6_AODSIM_PU_S10_START53_V7C-v1/2204BC4B-D4A0-E211-ADA0-003048F0E5AA.root'

   #'file:WH_WToMuNu_H_M_125_8TeV_powheg_herwigpp_cff_py_GEN.root'
 )

process.source.fileNames = cms.untracked.vstring (options.inputFiles)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )

#process.printDecayPath = cms.Path(process.printTree)
process.printDecayPath = cms.Path(process.printTree*process.printDecay*process.printListTree)


  
  
