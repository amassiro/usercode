///==== draw results from "FinalSelection_Producer.exe" ====

#include "test/WorkFlow/Tools_Draw.h"

void Draw_Results_Tree_2D(TString WhatToPlotX = "", TString WhatToPlotY = "", double MINX = -10, double MAXX = 10, int NBINX = 1000, double MINY = -10, double MAXY = 10, int NBINY = 1000, double LUMI = 500,TString Cut = ""){
 
 std::cerr << " Cut = " << Cut.Data() << std::endl;
 
 //kindTree = 0 -> jet
 //kindTree = 1 -> lep
 
 //  int NBIN = 1000;
 //  double MIN = -10;
 //  double MAX = 10;
 //  double LUMI = 500;
 
 TTree *treeEffVect[100];
 TTree *treeLepVect[100];
 TTree *treeJetVect[100];
 TTree *treeJetLepVect[100];
 
 TH2F* histo[100];
 
 char *nameSample[1000];
 char *nameSamplePrefix[1000];
 char *nameSampleTree[1000];
 
 double xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("/home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/test/WorkFlow/samples_temp.txt");
 std::string buffer;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){
    std::stringstream line( buffer );       
    nameSample[numberOfSamples] = new char [1000];
    line >> nameSample[numberOfSamples]; 
    std::cout << nameSample[numberOfSamples] << " ";
    
    nameSamplePrefix[numberOfSamples] = new char [1000];
    line >> nameSamplePrefix[numberOfSamples];
    
    nameSampleTree[numberOfSamples] = new char [1000];
    line >> nameSampleTree[numberOfSamples];
    
    xsection[numberOfSamples] = new char [1000];
    line >> xsection[numberOfSamples]; 
    std::cout << xsection[numberOfSamples] << " ";
    std::cout << std::endl;
    
    char nameFile[1000];
    sprintf(nameFile,"output/out_FinalSelection_%s.root",nameSample[numberOfSamples]);  
    TFile* f = new TFile(nameFile, "READ");
    
    treeEffVect[numberOfSamples] = (TTree) f->Get("outTreeSelections");
    char nameTreeEff[100];
    sprintf(nameTreeEff,"treeEff_%d",numberOfSamples); 
    treeEffVect[numberOfSamples]->SetName(nameTreeEff);      
    
    treeJetLepVect[numberOfSamples] = (TTree) f->Get("outTreeJetLep");
    char nameTreeJetLep[100];
    sprintf(nameTreeJetLep,"treeJetLep_%d",numberOfSamples); 
    treeJetLepVect[numberOfSamples]->SetName(nameTreeJetLep);
    
    //     treeJetVect[numberOfSamples] = (TTree) f->Get("outTreeJet");
    //     char nameTreeJet[100];
    //     sprintf(nameTreeJet,"treeJet_%d",numberOfSamples); 
    //     treeJetVect[numberOfSamples]->SetName(nameTreeJet);
    
    //     treeLepVect[numberOfSamples] = (TTree) f->Get("outTreeLep");
    //     char nameTreeLep[100];
    //     sprintf(nameTreeLep,"treeLep_%d",numberOfSamples); 
    //     treeLepVect[numberOfSamples]->SetName(nameTreeLep);
    
    numberOfSamples++;
   } 
  }
 }
 
 
 
 THStack* hs = new THStack("stack","stack");
 
 
 std::cout << " numberOfSamples = " << numberOfSamples << std::endl;
 //  for (int iSample=0; iSample<numberOfSamples; iSample++){

for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
 double XSection;
 double eff_Channel_Filter;
 double preselection_efficiency;
 int numEntriesBefore;
 treeEffVect[iSample]->SetBranchAddress("XSection",&XSection);
 treeEffVect[iSample]->SetBranchAddress("preselection_efficiency",&preselection_efficiency);
 treeEffVect[iSample]->SetBranchAddress("eff_Channel_Filter",&eff_Channel_Filter);
 treeEffVect[iSample]->SetBranchAddress("numEntriesBefore",&numEntriesBefore);
 treeEffVect[iSample]->GetEntry(0);
 
 std::cerr << " numEntriesBefore = " << numEntriesBefore << std::endl;
 std::cerr << " normalization = " << LUMI * XSection * preselection_efficiency / numEntriesBefore << std::endl;
 double normalization = LUMI * XSection * preselection_efficiency / numEntriesBefore;
 
 histo[iSample] = new TH2F(nameSample[iSample],nameSample[iSample],NBINX,MINX,MAXX,NBINY,MINY,MAXY);
 
 char toDraw[100];
 sprintf(toDraw,"%s:%s >> %s",WhatToPlotY.Data(),WhatToPlotX.Data(),nameSample[iSample]); 
 char cutDraw[100];
 sprintf(cutDraw,"%s",Cut.Data());
 treeJetLepVect[iSample]->Draw(toDraw,cutDraw,"");
 //   if (kindTree == 0) treeJetVect[iSample]->Draw(toDraw,"","");
 //   if (kindTree == 1) treeLepVect[iSample]->Draw(toDraw,"","");
 histo[iSample]->Scale(normalization);
 
 if (iSample == 0){
  histo[iSample]->SetMarkerColor(kRed);
  histo[iSample]->SetLineColor(kRed);
  histo[iSample]->SetFillColor(kRed);
  histo[iSample]->SetLineWidth(4);
 }
 else if (iSample == 1){
  histo[iSample]->SetMarkerColor(kBlue);
  histo[iSample]->SetLineColor(kBlue);
  histo[iSample]->SetFillColor(kBlue);
  histo[iSample]->SetLineWidth(4);
 }
 else if (iSample == 2){
  histo[iSample]->SetMarkerColor(kYellow);
  histo[iSample]->SetLineColor(kYellow);
  histo[iSample]->SetFillColor(kYellow);
  histo[iSample]->SetLineWidth(4);
 }
 else {
  histo[iSample]->SetMarkerColor(kOrange - 5 + iSample * 3);
  histo[iSample]->SetLineColor(kOrange - 5 + iSample * 3);
  histo[iSample]->SetFillColor(kOrange - 5 + iSample * 3);
  histo[iSample]->SetLineWidth(1);
  histo[iSample]->SetFillStyle(0);
 }
 
 hs->Add(histo[iSample]);
}


//  TCanvas cHisto("cHisto","cHisto",800,600);
 hs->Draw();
 gPad->SetLogz();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 
 DrawSB2D(hs,5,9,1);
 
 
 std::cerr << " ******************************************* end *******************************************" << std::endl;
 
 
 }
 
 
 