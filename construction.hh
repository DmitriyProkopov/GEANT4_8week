#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh" 
#include "G4GenericMessenger.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"

//#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	MyDetectorConstruction();
	~MyDetectorConstruction();
	
	G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }
	
	virtual G4VPhysicalVolume *Construct();
	
private:
	G4LogicalVolume *logicDetector;	
	//virtual void ConstructSDandField();
	
	G4int nCols, nRows;
	
	G4Tubs *solidDetector, *solidDetector1,
	*solidFiberInner, *solidFiberOuter;
	G4Box *solidWorld, *solidRadiator, *solidScintillator, *solidBorPogl1,*solidBorPogl2, *solidBorPogl3, *solidBorPogl4, *solidBorPogl5, *solidBorPogl6, *solidBorPogl7, *solidBorPogl8, *solidBorPogl9, *solidBorPogl10, *solidEpoxy, *solidParaf, *solidStCd1, *solidStCd2, *solidStCd3;
	G4Sphere *solidGran;
	G4LogicalVolume *logicWorld, *logicRadiator, *logicScintillator, *logicBorPogl1, *logicBorPogl2, *logicBorPogl3, *logicDetector1, *logicBorPogl4,*logicBorPogl5,*logicBorPogl6, *logicBorPogl7, *logicBorPogl8, *logicBorPogl9, *logicBorPogl10, *logicFiberInner, *logicFiberOuter, *logicEpoxy, *logicParaf, *logicStCd1, *logicStCd2, *logicStCd3, *logicGran;
	G4VPhysicalVolume *physWorld, *physRadiator, *physDetector,*physDetector1, *physScintillator, *physBorPogl1, *physBorPogl2, *physBorPogl3, *physBorPogl4,*physBorPogl5,*physBorPogl6,*physBorPogl7, *physBorPogl8, *physBorPogl9, *physBorPogl10, *physFiberInner, *physFiberOuter, *physEpoxy, *physParaf, *physStCd1, *physStCd2, *physStCd3, *physGran;

	G4GenericMessenger *fMessenger;
	
	G4LogicalVolume *fScoringVolume;
	
	G4Material *SiO2, *H2O, *Aerogel, *worldMat, *NaI, *xilol, *PolystyreneFib, *PolystyreneScin, *B2O3, *ZnS,  *Bor, *PMMA, *Epoxy, *Parafin, *mCd;
	G4Element *C, *Na, *I, *H, *B, *O;
	
	void DefineMaterials();
	void ConstructCherenkov();
	void ConstructScintillator();
	
	G4double xWorld, yWorld, zWorld;
	G4bool isCherenkov, isScintillator;
	
	G4OpticalSurface *mirror;
};

#endif
