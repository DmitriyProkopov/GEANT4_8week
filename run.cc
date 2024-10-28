#include "run.hh"
#include "G4AnalysisManager.hh"

MyRunAction::MyRunAction()
{
G4RootAnalysisManager *man = G4RootAnalysisManager::Instance();	
        
        
       
        man->CreateNtuple("Hits","Hits");
	man->CreateNtupleIColumn("Photons");
	//man->CreateH1("0","Ph", 10, 0 ,1000);
        man->FinishNtuple(0);


        
        man->CreateNtuple("length","length");
	man->CreateNtupleDColumn("Length");
       man->FinishNtuple(1);
        
        man->CreateNtuple("Scoring", "Scoring");
	man->CreateNtupleDColumn("fEdep");
	man->FinishNtuple(2);
	
	//man->CreateNtuple("Capteff", "Capteff");
	//man->CreateNtupleDColumn("X");
	//man->CreateNtupleDColumn("Y");
	//man->CreateNtupleDColumn("Z");
	//man->CreateNtupleDColumn("R");
	//man->FinishNtuple(3);
	
	//man->CreateNtuple("time", "time");
	//man->CreateNtupleDColumn("t");
	//man->FinishNtuple(4);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
	G4RootAnalysisManager *man = G4RootAnalysisManager::Instance();	
        
        man->OpenFile("capteff.root");
        
    //    man->CreateNtuple("Hits","Hits");
	//man->CreateNtupleDColumn("Photons");
     //   man->FinishNtuple(0);
	
	
	
	//man->OpenFile("output.root");
	
	
	
	
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
	G4RootAnalysisManager *man = G4RootAnalysisManager::Instance();
	
	 man->Write();
	 man->CloseFile();
}
