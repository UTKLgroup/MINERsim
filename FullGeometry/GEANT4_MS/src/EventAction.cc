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
  MinerHitsCollection*  muVetoTopHits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_muVetoTop_hits")));
  MinerHitsCollection*  muVetoBottomHits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_muVetoBottom_hits")));
  MinerHitsCollection*  backScintHits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_backScint_hits")));
  MinerHitsCollection*  det1Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_det1_hits")));
  MinerHitsCollection*  det2Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_det2_hits")));
  MinerHitsCollection*  det3Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_det3_hits")));
  MinerHitsCollection*  det4Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_det4_hits")));
  MinerHitsCollection*  det5Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_det5_hits")));
  MinerHitsCollection*  det6Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_det6_hits")));
  MinerHitsCollection*  det7Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_det7_hits")));
  MinerHitsCollection*  det8Hits = (MinerHitsCollection*)(HCofEvent->GetHC(fSDM->GetCollectionID("MS_det8_hits")));


  RootIO::GetInstance()->AddHits(craigHits,12);
  RootIO::GetInstance()->AddHits(muVetoTopHits,9);
  RootIO::GetInstance()->AddHits(muVetoBottomHits,10);
  RootIO::GetInstance()->AddHits(backScintHits,11);
  RootIO::GetInstance()->AddHits(det1Hits,1);
  RootIO::GetInstance()->AddHits(det2Hits,2);
  RootIO::GetInstance()->AddHits(det3Hits,3);
  RootIO::GetInstance()->AddHits(det4Hits,4);
  RootIO::GetInstance()->AddHits(det5Hits,5);
  RootIO::GetInstance()->AddHits(det6Hits,6);
  RootIO::GetInstance()->AddHits(det7Hits,7);
  RootIO::GetInstance()->AddHits(det8Hits,8);


  RootIO::GetInstance()->Write();


}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
