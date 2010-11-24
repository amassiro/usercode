///==== draw results from "FinalSelection_Producer.exe" ====

#include "test/Spring10/Tools_Draw.h"

void DrawDistribution1D(TString fileSamples, TString WhatToPlot = "", double MIN = -10, double MAX = 10, int NBIN = 1000, double LUMI = 500, TString Cut = "", int HowManySignalSamples = 5){
  
 
 EColor vColor[1000] = {
  kGreen,(EColor) (kGreen+1),
  //kMagenta,(EColor) (kMagenta+1),(EColor) (kMagenta+2),
  kTeal,(EColor) (kTeal+1),
  kOrange,(EColor) (kOrange+1),
  kGray,(EColor)(kGray+1),(EColor) (kGray+2),
  kPink,(EColor) (kPink+1),(EColor) (kPink+2),
  kBlue,(EColor) (kBlue+1),(EColor) (kViolet),(EColor) (kYellow),(EColor) (kGray)
 };
 
 
 
 
 std::cerr << " Cut = " << Cut.Data() << std::endl;

 TTree *treeEffVect[100];
 TTree *treeJetLepVect[100];
 
 TH1F* histo[100];
 TH1F* histo_temp[100];
 
 char *nameSample[1000];
 char *nameSampleFile[1000];
 char *joinSampleName[1000];
 
 double xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("test/samples_skimmed.txt");
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

    nameSampleFile[numberOfSamples] = new char [1000];
    line >> nameSampleFile[numberOfSamples]; 
    std::cout << nameSampleFile[numberOfSamples] << " ";
    
    xsection[numberOfSamples] = new char [1000];
    line >> xsection[numberOfSamples]; 
    std::cout << xsection[numberOfSamples] << " ";
    std::cout << std::endl;
  
    joinSampleName[numberOfSamples] = new char [1000];
    line >> joinSampleName[numberOfSamples]; 
    std::cout << joinSampleName[numberOfSamples] << " ";
    std::cout << std::endl;
        
    char nameFile[1000];
    sprintf(nameFile,"output/out_NtupleProducer_%s.root",nameSample[numberOfSamples]);  
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
 
 
 ///===== create map for joint sample ====
 
 std::vector<int> join_samples;
 std::vector<std::string> name_samples;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  name_samples.push_back(joinSampleName[iSample]);
  join_samples.push_back(-1);
 }
//  int name_counter = 0;
//  for (int iSample=0; iSample<numberOfSamples; iSample++){
//   for (int jSample=iSample; jSample<numberOfSamples; jSample++){   
//    if (join_samples.at(jSample) == -1 && name_samples.at(jSample) == name_samples.at(iSample)) join_samples.at(jSample) = name_counter;
//   }
//   name_counter++;
//  }
//  
//  for (int iSample=0; iSample<numberOfSamples; iSample++){
//   std::cout << " sample = " << name_samples.at(iSample) << " : " << join_samples.at(iSample) << std::endl;
//  }
 
 std::vector<std::string> reduced_name_samples;
 std::vector<int>         reduced_name_samples_flag;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  bool flag_name = false;
  for (int iName=0; iName<reduced_name_samples.size(); iName++){
   if (reduced_name_samples.at(iName) == name_samples.at(iSample)) flag_name = true;
  }
  if (flag_name == false) {
   reduced_name_samples.push_back(name_samples.at(iSample));
   reduced_name_samples_flag.push_back(-1);
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
  
  TString name_histo_temp = Form("%s_temp",nameSample[iSample]);
  
  histo_temp[iSample] = new TH1F(name_histo_temp,name_histo_temp,NBIN,MIN,MAX);
  
  char toDraw[100];
  sprintf(toDraw,"%s >> %s",WhatToPlot.Data(),name_histo_temp.Data()); 
  treeJetLepVect[iSample]->Draw(toDraw,Cut,"");
  
  std::cerr << " numEntriesBefore = " << numEntriesBefore << " > " << histo_temp[iSample]->GetEntries();
  if (numEntriesBefore != 0)
   std::cerr << " normalization = " << LUMI * XSection * preselection_efficiency / numEntriesBefore << " = " << LUMI << " * " << XSection << " * " << preselection_efficiency << " / " << numEntriesBefore << " >> " << nameSample[iSample] << std::endl;
  double normalization;
  if (numEntriesBefore != 0) normalization = LUMI * XSection * preselection_efficiency / numEntriesBefore;
  else normalization = 0;
  
  if (normalization>0) histo_temp[iSample]->Scale(normalization);
  
  for (int iName=0; iName<reduced_name_samples.size(); iName++){
   if (name_samples.at(iSample) == reduced_name_samples.at(iName)){
    if (reduced_name_samples_flag.at(iName) == -1){
     histo[iName] = new TH1F(reduced_name_samples.at(iName).c_str(),reduced_name_samples.at(iName).c_str(),NBIN,MIN,MAX);
     reduced_name_samples_flag.at(iName) = 1;
    }
    histo[iName] -> Add(histo_temp[iSample]);
   }
  }
 }
 
 
 for (int iName=0; iName<reduced_name_samples.size(); iName++){
  histo[iName]->GetXaxis()->SetTitle(WhatToPlot);
  histo[iName]->SetMarkerColor(vColor[iName]);
  histo[iName]->SetLineColor(vColor[iName]);
  histo[iName]->SetFillColor(vColor[iName]);
  histo[iName]->SetLineWidth(2);
  histo[iName]->SetFillStyle(3001);  
  if (reduced_name_samples.at(iName) != "DATA") {
   hs->Add(histo[iName]);
  }
  else {
   histo[iName]->SetMarkerStyle(20);
   histo[iName]->SetMarkerSize(1);
   histo[iName]->SetMarkerColor(kBlack);
   histo[iName]->SetLineColor(kBlack);
   histo[iName]->SetFillColor(kBlack);
   histo[iName]->SetLineWidth(2);
   histo[iName]->SetFillStyle(3001);  
  }
 }
 
 
//  TCanvas cHisto("cHisto","cHisto",800,600);
 hs->Draw();
 hs->GetXaxis()->SetTitle(WhatToPlot);
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
 
 
 DrawSB(hs,HowManySignalSamples,numberOfSamples-HowManySignalSamples,0);
  
//  TCanvas* cCompare = (TCanvas*) gDirectory->Get("cCompare");
 for (int iName=0; iName<reduced_name_samples.size(); iName++){
  if (reduced_name_samples.at(iName) == "DATA") {
   cCompare->cd(1);
   histo[iName]->Draw("EsameB");
   cCompare->cd(2);
   histo[iName]->Draw("EsameB");
   cCompareSum->cd();
   histo[iName]->Draw("EsameB");
  }
 }
 
 
 TCanvas* cNormalized = new TCanvas("cNormalized","cNormalized",800,800);
 bool already_drawn = false;
 for (int iName=0; iName<reduced_name_samples.size(); iName++){
  if (reduced_name_samples.at(iName) == "DATA") {
//    histo[iName]->Draw("EsameB");
  }
  else {
   if (already_drawn == false) {
    histo[iName]->SetFillStyle(0);
    histo[iName]->DrawNormalized();
    already_drawn = true;
   }
   else {
    histo[iName]->SetFillStyle(0);
    histo[iName]->DrawNormalized("same");
   }
  }
 }
 gPad->SetGrid();
 gPad->BuildLegend();
 
 
 std::cerr << " ******************************************* end *******************************************" << std::endl;
 
 
}


