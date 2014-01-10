#include <iostream>

#include "Validation/RecoMET/plugins/METTesterPostProcessor.h"
#include "Validation/RecoMET/plugins/METTester.h"
#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

using namespace std;

METTesterPostProcessor::METTesterPostProcessor(const edm::ParameterSet& pSet)
{
  // get ahold of back-end interface
  //  DQMStore* val = &*edm::Service<DQMStore>();
  val= edm::Service<DQMStore>().operator->();
  iConfig=pSet;
  inputMETLabel_           =iConfig.getParameter<edm::InputTag>("InputMETLabel");
}

METTesterPostProcessor::~METTesterPostProcessor(){
}

void METTesterPostProcessor::beginJob(void){
}

void METTesterPostProcessor::beginRun(const edm::Run&, const edm::EventSetup& iSetup) {
  mMETResolution_GenMETTrue_METResolution=0;
}

void METTesterPostProcessor::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
}

void METTesterPostProcessor::endRun(const edm::Run&, const edm::EventSetup&) {
  if (val) {
    val->setCurrentFolder("JetMET/METValidation/");
    met_dirs= val->getSubdirs();
    //bin definition for resolution plot 
    int nBins = 10;
    float bins[] = {0.,20.,40.,60.,80.,100.,150.,200.,300.,400.,500.};
    //loop over met subdirectories
    for (int i=0; i<int(met_dirs.size()); i++) {
      val->setCurrentFolder(met_dirs[i]);
      mMETResolution_GenMETTrue_METResolution     = val->book1D("METTask_METResolution_GenMETTrue_InMETBins","METTask_METResolution_GenMETTrue_InMETBins",nBins, bins);
      //fill res plot
      FillpfMETRes(met_dirs[i]);
    }
  }
}

void METTesterPostProcessor::FillpfMETRes(std::string metdir)
{
  mMETDifference_GenMETTrue_MET0to20=0;
  mMETDifference_GenMETTrue_MET20to40=0;
  mMETDifference_GenMETTrue_MET40to60=0;
  mMETDifference_GenMETTrue_MET60to80=0;
  mMETDifference_GenMETTrue_MET80to100=0;
  mMETDifference_GenMETTrue_MET100to150=0;
  mMETDifference_GenMETTrue_MET150to200=0;
  mMETDifference_GenMETTrue_MET200to300=0;
  mMETDifference_GenMETTrue_MET300to400=0;
  mMETDifference_GenMETTrue_MET400to500=0;

  mMETDifference_GenMETTrue_MET0to20 = val->get(metdir+"/METResolution_GenMETTrue_MET0to20");
  mMETDifference_GenMETTrue_MET20to40 = val->get(metdir+"/METResolution_GenMETTrue_MET20to40"); 
  mMETDifference_GenMETTrue_MET40to60 = val->get(metdir+"/METResolution_GenMETTrue_MET40to60");
  mMETDifference_GenMETTrue_MET60to80 = val->get(metdir+"/METResolution_GenMETTrue_MET60to80");
  mMETDifference_GenMETTrue_MET80to100 = val->get(metdir+"/METResolution_GenMETTrue_MET80to100");
  mMETDifference_GenMETTrue_MET100to150 = val->get(metdir+"/METResolution_GenMETTrue_MET100to150");
  mMETDifference_GenMETTrue_MET150to200 = val->get(metdir+"/METResolution_GenMETTrue_MET150to200");
  mMETDifference_GenMETTrue_MET200to300 = val->get(metdir+"/METResolution_GenMETTrue_MET200to300");
  mMETDifference_GenMETTrue_MET300to400 = val->get(metdir+"/METResolution_GenMETTrue_MET300to400");
  mMETDifference_GenMETTrue_MET400to500 = val->get(metdir+"/METResolution_GenMETTrue_MET400to500"); 
  mMETResolution_GenMETTrue_METResolution->setBinContent(1, mMETDifference_GenMETTrue_MET0to20->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinContent(2, mMETDifference_GenMETTrue_MET20to40->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinContent(3, mMETDifference_GenMETTrue_MET40to60->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinContent(4, mMETDifference_GenMETTrue_MET60to80->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinContent(5, mMETDifference_GenMETTrue_MET80to100->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinContent(6, mMETDifference_GenMETTrue_MET100to150->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinContent(7, mMETDifference_GenMETTrue_MET150to200->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinContent(8, mMETDifference_GenMETTrue_MET200to300->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinContent(9, mMETDifference_GenMETTrue_MET300to400->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinContent(10, mMETDifference_GenMETTrue_MET400to500->getMean());
  mMETResolution_GenMETTrue_METResolution->setBinError(1, mMETDifference_GenMETTrue_MET0to20->getRMS());
  mMETResolution_GenMETTrue_METResolution->setBinError(2, mMETDifference_GenMETTrue_MET20to40->getRMS());
  mMETResolution_GenMETTrue_METResolution->setBinError(3, mMETDifference_GenMETTrue_MET40to60->getRMS());
  mMETResolution_GenMETTrue_METResolution->setBinError(4, mMETDifference_GenMETTrue_MET60to80->getRMS());
  mMETResolution_GenMETTrue_METResolution->setBinError(5, mMETDifference_GenMETTrue_MET80to100->getRMS());
  mMETResolution_GenMETTrue_METResolution->setBinError(6, mMETDifference_GenMETTrue_MET100to150->getRMS());
  mMETResolution_GenMETTrue_METResolution->setBinError(7, mMETDifference_GenMETTrue_MET150to200->getRMS());
  mMETResolution_GenMETTrue_METResolution->setBinError(8, mMETDifference_GenMETTrue_MET200to300->getRMS());
  mMETResolution_GenMETTrue_METResolution->setBinError(9, mMETDifference_GenMETTrue_MET300to400->getRMS());
  mMETResolution_GenMETTrue_METResolution->setBinError(10, mMETDifference_GenMETTrue_MET400to500->getRMS());
  
}

void METTesterPostProcessor::endJob(){

}
