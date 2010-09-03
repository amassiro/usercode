///==== draw results from "FinalSelection_Producer.exe" ====

#include "test/Spring10/Tools_Draw.h"

void Draw_Results_Tree(TString WhatToPlot = "", double MIN = -10, double MAX = 10, int NBIN = 1000, double LUMI = 500, TString Cut = ""){
//  void Draw_Results_Tree(TString WhatToPlot = "", int kindTree = 0, double MIN = -10, double MAX = 10, int NBIN = 1000, double LUMI = 500){
  
 std::cerr << " Cut = " << Cut.Data() << std::endl;

 TTree *treeEffVect[100];
 TTree *treeLepVect[100];
 TTree *treeJetVect[100];
 TTree *treeJetLepVect[100];
 
 TH1F* histo[100];
 
 char *nameSample[1000];
 char *nameSamplePrefix[1000];
 char *nameSampleTree[1000];
 
 double xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("/home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/test/Spring10/samples.txt");
 std::string buffer;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
//   std::cout << "buffer = " << buffer << std::endl;
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
    sprintf(nameFile,"output_Spring10/out_FinalSelector_%s.root",nameSample[numberOfSamples]);  
    TFile* f = new TFile(nameFile, "READ");
    
    treeEffVect[numberOfSamples] = (TTree) f->Get("outTreeSelections");
    char nameTreeEff[100];
    sprintf(nameTreeEff,"treeEff_%d",numberOfSamples); 
    treeEffVect[numberOfSamples]->SetName(nameTreeEff);      
    
    treeJetLepVect[numberOfSamples] = (TTree) f->Get("outTreeJetLep");
    char nameTreeJetLep[100];
    sprintf(nameTreeJetLep,"treeJetLep_%d",numberOfSamples); 
    treeJetLepVect[numberOfSamples]->SetName(nameTreeJetLep);

    numberOfSamples++;
   } 
  }
 }
 
 
 
 THStack* hs = new THStack("stack","stack");
 
 
 std::cout << " numberOfSamples = " << numberOfSamples << std::endl;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  
//  for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
  double XSection;
  double eff_Channel_Filter;
  double preselection_efficiency;
  int numEntriesBefore;
  treeEffVect[iSample]->SetBranchAddress("XSection",&XSection);
  treeEffVect[iSample]->SetBranchAddress("preselection_efficiency",&preselection_efficiency);
  treeEffVect[iSample]->SetBranchAddress("eff_Channel_Filter",&eff_Channel_Filter);
  treeEffVect[iSample]->SetBranchAddress("numEntriesBefore",&numEntriesBefore);
  treeEffVect[iSample]->GetEntry(0);
  
  histo[iSample] = new TH1F(nameSample[iSample],nameSample[iSample],NBIN,MIN,MAX);
  
  char toDraw[100];
  sprintf(toDraw,"%s >> %s",WhatToPlot.Data(),nameSample[iSample]); 
  treeJetLepVect[iSample]->Draw(toDraw,Cut,"");
//   if (kindTree == 0) treeJetVect[iSample]->Draw(toDraw,"","");
//   if (kindTree == 1) treeLepVect[iSample]->Draw(toDraw,"","");
  
  std::cerr << " numEntriesBefore = " << numEntriesBefore << " > " << histo[iSample]->GetEntries();
  std::cerr << " normalization = " << LUMI * XSection * preselection_efficiency / numEntriesBefore << " = " << LUMI << " * " << XSection << " * " << preselection_efficiency << " / " << numEntriesBefore << " >> " << nameSample[iSample] << std::endl;
  double normalization = LUMI * XSection * preselection_efficiency / numEntriesBefore;
  
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
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 
 DrawSB(hs,3,25,0);
  
 
 std::cerr << " ******************************************* end *******************************************" << std::endl;
 
 
}


