#ifndef METTesterPostProcessor_H
#define METTesterPostProcessor_H

#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"

#include <vector>
#include <string>

#include "TFile.h"
#include "TH1.h"
#include "TMath.h"

class METTesterPostProcessor : public edm::EDAnalyzer
{
 public:
  explicit METTesterPostProcessor( const edm::ParameterSet& pSet ) ;
  ~METTesterPostProcessor();
                                   
      
  virtual void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup ) ;
  virtual void beginJob(void) ;
  virtual void beginRun(const edm::Run&, const edm::EventSetup& iSetup);
  virtual void endJob();
  void endRun(const edm::Run& , const edm::EventSetup& ) ;

 private:

  DQMStore* val;
  edm::InputTag inputMETLabel_;
  MonitorElement* mMETResolution_GenMETTrue_METResolution;
  edm::ParameterSet iConfig;
  std::vector<std::string> met_dirs;
  void FillpfMETRes(std::string metdir);
  MonitorElement* mMETDifference_GenMETTrue_MET0to20;
  MonitorElement* mMETDifference_GenMETTrue_MET20to40;
  MonitorElement* mMETDifference_GenMETTrue_MET40to60;
  MonitorElement* mMETDifference_GenMETTrue_MET60to80;
  MonitorElement* mMETDifference_GenMETTrue_MET80to100;
  MonitorElement* mMETDifference_GenMETTrue_MET100to150;
  MonitorElement* mMETDifference_GenMETTrue_MET150to200;
  MonitorElement* mMETDifference_GenMETTrue_MET200to300;
  MonitorElement* mMETDifference_GenMETTrue_MET300to400;
  MonitorElement* mMETDifference_GenMETTrue_MET400to500;
};

#endif
