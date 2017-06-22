//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//

#include "EventAction.hh"

#include "TClonesArray.h"


#include "MinerHit.hh"
#include "BaseHit.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"
#include "G4SDManager.hh"

#include "RootIO.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction()
: G4UserEventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event*)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* event)
{
  
  G4SDManager* fSDM = G4SDManager::GetSDMpointer();
  G4HCofThisEvent* HCofEvent = event->GetHCofThisEvent();
  MinerHitsCollection*  craigHits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_Craig_hits")));
  MinerHitsCollection*  craigHits2 = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_Craig_hits2")));

  MinerHitsCollection*  insideIBHits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_insideIB_hits")));
  MinerHitsCollection*  atNeutronDetHits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atNeutronDet_hits")));
  MinerHitsCollection*  atLeadHits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atLead_hits")));
  MinerHitsCollection*  atStartTCHits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atStartTC_hits")));
  MinerHitsCollection*  atPoly1Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atPoly1_hits")));
  MinerHitsCollection*  atPoly2Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atPoly2_hits")));
  MinerHitsCollection*  atPoly3Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atPoly3_hits")));
  MinerHitsCollection*  atPoly4Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atPoly4_hits")));
  MinerHitsCollection*  atPoly5Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atPoly5_hits")));
  MinerHitsCollection*  atPoly6Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atPoly6_hits")));
  MinerHitsCollection*  atPoly7Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atPoly7_hits")));
  MinerHitsCollection*  atPoly8Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atPoly8_hits")));
  MinerHitsCollection*  atPoly9Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_atPoly9_hits")));

  RootIO::GetInstance()->AddHits(craigHits,1);
  RootIO::GetInstance()->AddHits(craigHits2,2);


  RootIO::GetInstance()->FillMonitoring(atStartTCHits,13);
  RootIO::GetInstance()->FillMonitoring(atPoly1Hits,14);
  RootIO::GetInstance()->FillMonitoring(atPoly2Hits,15);
  RootIO::GetInstance()->FillMonitoring(atPoly3Hits,16);
  RootIO::GetInstance()->FillMonitoring(atPoly4Hits,17);
  RootIO::GetInstance()->FillMonitoring(atPoly5Hits,18);
  RootIO::GetInstance()->FillMonitoring(atPoly6Hits,19);
  RootIO::GetInstance()->FillMonitoring(atPoly7Hits,20);
  RootIO::GetInstance()->FillMonitoring(atPoly8Hits,21);
  RootIO::GetInstance()->FillMonitoring(atPoly9Hits,21);
  RootIO::GetInstance()->FillMonitoring(atLeadHits,23);
  RootIO::GetInstance()->FillMonitoring(atNeutronDetHits,24);
  RootIO::GetInstance()->FillMonitoring(insideIBHits,25);

  if (craigHits->entries() > 0){
    RootIO::GetInstance()->FillMonitoring(atStartTCHits,26);
    RootIO::GetInstance()->FillMonitoring(atPoly1Hits,27);
    RootIO::GetInstance()->FillMonitoring(atPoly2Hits,28);
    RootIO::GetInstance()->FillMonitoring(atPoly3Hits,29);
    RootIO::GetInstance()->FillMonitoring(atPoly4Hits,30);
    RootIO::GetInstance()->FillMonitoring(atPoly5Hits,31);
    RootIO::GetInstance()->FillMonitoring(atPoly6Hits,32);
    RootIO::GetInstance()->FillMonitoring(atPoly7Hits,33);
    RootIO::GetInstance()->FillMonitoring(atPoly8Hits,34);
    RootIO::GetInstance()->FillMonitoring(atPoly9Hits,35);
    RootIO::GetInstance()->FillMonitoring(atLeadHits,36);
    RootIO::GetInstance()->FillMonitoring(atNeutronDetHits,37);
  }



  RootIO::GetInstance()->Write();


}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
