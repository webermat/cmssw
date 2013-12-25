import FWCore.ParameterSet.Config as cms

METTesterPostProcessor = cms.EDAnalyzer("METTesterPostProcessor",
                                   InputMETLabel = cms.string("pfMet"),
                                   )
METTesterPostProcessorSequence = cms.Sequence(METTesterPostProcessor)
