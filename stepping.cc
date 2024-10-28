#include "stepping.hh"
#include "G4Track.hh"
#include "G4Event.hh"
#include "G4RootAnalysisManager.hh"
#include "construction.hh"
#include "G4Step.hh"
#include <G4VProcess.hh>

int Nphoton1=0;
double eng=0;


MySteppingAction::MySteppingAction(MyEventAction *eventAction)
 : G4UserSteppingAction(),
  fEventAction(eventAction)
{
	fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{

        G4Track *track = step->GetTrack();
        G4double edep = step->GetTotalEnergyDeposit();
        fEventAction->AddEdep(edep);
        G4RootAnalysisManager *man = G4RootAnalysisManager::Instance();
        
	G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
	
	//const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
	G4double energy = track->GetKineticEnergy();
	G4double length = track->GetTrackLength();
	 G4double X = track->GetPosition().x();
	  G4double Z = track->GetPosition().z();
	  G4double Y = track->GetPosition().y();
	  G4double R = track->GetPosition().r();
	  G4double t = track->GetLocalTime();
	
	if (track->GetTrackStatus() == fStopAndKill) {
	
	  if (track->GetDefinition()->GetParticleName() == "alpha")
	{
	   
	   if ((volume->GetName()=="logicGran") /* or (volume->GetName()=="logicDetector") or (volume->GetName()=="logicFiberInner")or (volume->GetName()=="logicFiberOuter")   or (volume->GetName()=="logicWorld") or (volume->GetName()=="logicBorPogl9") or (volume->GetName()=="logicBorPogl10")*/) 
	    // if (volume->GetName()!="logicScintillator")
	    {
	          fEventAction->AddEdep(energy*keV);
	          man->FillNtupleDColumn(1, 0, energy*MeV);
	         // man->FillNtupleDColumn(3, 0, X);
	         // man->FillNtupleDColumn(3, 1, Z);
	         // man->FillNtupleDColumn(3, 2, Y);
	         // man->FillNtupleDColumn(3, 3, R);
	         // man->FillNtupleDColumn(4, 0, t);
	          man->AddNtupleRow(1);
	         // man->AddNtupleRow(3);
	         // man->AddNtupleRow(4);
	          Nphoton1++;
	        //  G4cout << R << G4endl;
	         
	    }
	}
	}
	
	
	
	
}
