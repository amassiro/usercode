{
 #include "test/Functions.hh"
 gStyle->SetOptStat(0);
 gStyle->SetOptFit(0);

 ///==== Draw the Shape of the crystals in Ecal ====

 TChain* myTree = new TChain("myTree");
 myTree->Add("/home/andrea/Cern/Code/WeCalib/AnalysisPackage_AlCaReco/output/out_Data_ShowerShape_NewData_Run2010A-EcalCalElectron-Jun9thReReco_v1.root");
 myTree->Add("/home/andrea/Cern/Code/WeCalib/AnalysisPackage_AlCaReco/output/out_Data_ShowerShape_NewData_Commissioning10-EcalCalElectron-May27thReReco_v1.root");
 
//  TFile* fileIn = new TFile("output/out_Data_ShowerShape_NewData_Run2010A-EcalCalElectron-Jun9thReReco_v1.root","READ");
//  TFile* fileIn = new TFile("output/out_Data_ShowerShape.root","READ");
//  TTree* myTree = (TTree*) fileIn->Get("myTree");

 TH2F *h2ShowerShapeEB = new TH2F("h2ShowerShapeEB","Shower Shape i#phi i#eta",170,-85,85,360,0,360);
 TH2F *h2ShowerShapeEE = new TH2F("h2ShowerShapeEE","Shower Shape ix iy",100,0,100,100,0,100);

 double pT;
 double Eta;
 double EoP;
 double ET;
 myTree->SetBranchAddress("pT",&pT);
 myTree->SetBranchAddress("Eta",&Eta);
 myTree->SetBranchAddress("EoP",&EoP);
 myTree->SetBranchAddress("ET",&ET);
 
 myTree->SetBranchAddress("h2ShowerShapeEB",&h2ShowerShapeEB);
 myTree->SetBranchAddress("h2ShowerShapeEE",&h2ShowerShapeEE);

//  TCanvas* ccSS = new TCanvas("ccSS","Shower Shape",800,800);
//  ccSS->Divide(2,2);
 TCanvas* ccSS = new TCanvas("ccSS","Shower Shape",800,400);
 ccSS->Divide(2,1);
 
 TControlBar *bar = new TControlBar("vertical", "Electron");
 gROOT->Add(bar);
 bar->AddButton("Next","{Next();}","Next electron");
 bar->AddButton("Prev","{Prev();}","Previous electron");
 bar->AddButton("Exit","{Exit();}","Exit from the program");
 bar->Show();

 int iEvent = 0;
 CheckButton();
 
 
}
