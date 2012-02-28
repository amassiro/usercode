#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TLine.h"
#include "TROOT.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "THStack.h"
#include "TRandom3.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TPaveStats.h"
#include "TText.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "test/TDRStyle.cc"
#include "test/Read.cc"
#include "test/Latinos/ttbar/plotUtils.C"


///==== Macros input are: input file name

int GetTop_Result_forDataCard(TString input) {
 
 ///=== Open the input ROOT File from test/MCDATAComparisonPLOTTool.cpp
 
 TFile * Input_File = TFile::Open(input.Data());
 
 std::string nameHumanVariable = "|#eta|^{CJet}";
 std::vector<std::string> nameSamplesToJoin;
 nameSamplesToJoin.push_back("top");
 
 std::vector<std::string> Cuts;
 Cuts.push_back("AB-CR");
 Cuts.push_back("B-CR");
 Cuts.push_back("A-CR");
 Cuts.push_back("AB-SR");
 Cuts.push_back("B-SR");
 Cuts.push_back("A-SR");
 
 std::vector<float> Bin_Extremes;
 std::vector<float> row;
 
 ///===== Acquisition info from txt file: Name of the samples, Cut applied and Variables of Plot and their binning
 
 std::ifstream inFile("test/Latinos/ttbar/BinDefinition.txt");
 std::string buffer;
 
 while(!inFile.eof()) {
  getline(inFile,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   double tempEdge;
   while ( line >> tempEdge ) {
    Bin_Extremes.push_back(tempEdge);
    }
  }
 }
 
 std::ifstream inFileSamples("test/Latinos/ttbar/datacard/SamplesHMIT.txt");
 
 
 char *name_Sample[1000];
 char *nameHumanReadable[1000];
 char* xsectionName[1000];
 
 double Normalization[1000];
 double xsection  [1000];
 char nameFileIn  [1000];
 
 int numberOfSamples = ReadFile("test/Latinos/ttbar/datacard/SamplesHMIT.txt", name_Sample, nameHumanReadable, xsectionName); 
 
 std::cout << " transform names ... " << std::endl;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  xsection[iSample] = atof(xsectionName[iSample]);
 }
 
 std::vector<std::string> nameSamples;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  nameSamples.push_back(nameHumanReadable[iSample]);
 }
 
 

 ///=== Acquisition from the input file of the object: stack and histogramms 
 //  [iCut][iName]  ()
 TH1D* histo[103][83]; 
 //  [iCut]         ()
 THStack* stack[103];
 
 for(int iCut=0; iCut<Cuts.size();iCut++) {  
  TString stack_name = Form ("Data/%d_%d_stack", iCut, 0);  //---- iVar == 0 !
  stack[iCut] = (THStack*) Input_File->Get(stack_name);
  
  for(int iSample = 0; iSample < nameSamples.size(); iSample++) {   
   TString histo_name = Form ("Data/%s_%d_%d_Tot_temp", nameSamples.at(iSample).c_str(), iCut, 0);
   histo[iCut][iSample] = (TH1D*) Input_File->Get(histo_name);
  }
 }
 
 
 ///=== Efficiency Evaluation
 
 ///              [iCut]
 TH1D* EfficiencyHisto[103];
 TH1D* EfficiencyHisto_ttbar[103];
 TH1D* PurityHisto[103];
 THStack* stack_Rebinned[103];
 TEfficiency* eff_DATA[103];
 ///                
 TH1D *SR_AB_Zone_all;
 TH1D *SR_AB_Zone_all_NoHiggs;
//  TH1D *SR_AB_Zone_tt;
 
 TH1D *SR_A_Zone_tt;
 
 for (int iEdge = 0; iEdge < Bin_Extremes.size(); iEdge++) {
  std::cout << " edge[" << iEdge << "] = " << Bin_Extremes.at(iEdge) << std::endl;
 }
 
 for(int iCut=0; iCut<Cuts.size(); iCut++) {  //---- 2 cuts : (AB, B, A) for CR and SR
   bool isDATA = false;
   bool isDivide = true;
   
   ///==== Efficiency analysis in the control region 
   if (iCut == 0) {
    /// Check for the right pair of cuts
    TH1D * num = (TH1D*) stack[iCut+1]->GetStack()->Last();
    TH1D * num_Rebinned; 
    num_Rebinned = DynamicalRebinHisto(num,num_Rebinned,Bin_Extremes,isDATA, isDivide); ///== Dynamical Rebin of the Histogram with the new binning defined in Bin_Extremes,
    num_Rebinned->SetFillStyle(3335);
    num_Rebinned->SetFillColor(kBlack);
    ///=== isData is a bool variable that indicates if we work on data sample, isDivide if we want to divide the bin content for the bin width
    ///=== For the implementation See PlotUtils.c
    
    TH1D * den = (TH1D*) stack[iCut]->GetStack()->Last();
    TH1D * den_Rebinned;
    
    den_Rebinned = DynamicalRebinHisto(den,den_Rebinned,Bin_Extremes, isDATA, isDivide);
    den_Rebinned->SetFillStyle(3335);
    den_Rebinned->SetFillColor(kBlack);
    
    TLegend * legend = makeLegend(*stack[iCut],nameSamples); ///=== See PlotUtils.C
    
    ///==== Total Efficiency Distriubution for each Cut and Variables
    
    EfficiencyHisto[iCut] = (TH1D*) num_Rebinned->Clone("EfficiencyHisto");
    EfficiencyHisto[iCut] -> Divide(den_Rebinned);
    
    ///==== Dynamical rebin for the stack, see PlotUtils.C
    
    stack_Rebinned[iCut]   = DynamicalRebinStack(stack[iCut],stack_Rebinned[iCut],Bin_Extremes,isDATA,isDivide);
    stack_Rebinned[iCut+1] = DynamicalRebinStack(stack[iCut+1],stack_Rebinned[iCut+1],Bin_Extremes,isDATA,isDivide);
    
    ///==== Efficiency on top and DATA samples
    
    TH1D* num_ttbar, *den_ttbar, *num_top, *den_top,*num_DATA, *den_DATA;
    TH1D * num_ttbar_Rebinned, * den_ttbar_Rebinned,* num_top_Rebinned, * den_top_Rebinned, * num_DATA_Rebinned, * den_DATA_Rebinned;
    TH1D *B_VV_SR_Rebinned, *B_VV_SR, *AB_VV_SR_Rebinned, *AB_VV_SR;
    
    bool done;
    for(int iSample=0; iSample<nameSamples.size(); iSample++) {     
     for (int iNameToJoin = 0; iNameToJoin < nameSamplesToJoin.size(); iNameToJoin++){
      if (nameSamples.at(iSample) == nameSamplesToJoin.at(iNameToJoin)) { 
       if (!done) {
	done = true;
	num_ttbar = (TH1D*) histo[iCut+1][iSample]->Clone("num_ttbar");
	num_ttbar_Rebinned = DynamicalRebinHisto(num_ttbar,num_ttbar_Rebinned,Bin_Extremes,isDATA, isDivide);
	
	den_ttbar = (TH1D*) histo[iCut][iSample]->Clone("den_ttbar");
	den_ttbar_Rebinned = DynamicalRebinHisto(den_ttbar,den_ttbar_Rebinned,Bin_Extremes, isDATA, isDivide);	
       } 
       else {
	num_top = (TH1D*)histo[iCut+1][iSample]->Clone("num_top");
	num_top_Rebinned = DynamicalRebinHisto(num_top,num_top_Rebinned,Bin_Extremes, isDATA, isDivide);
	
	den_top = (TH1D*) histo[iCut][iSample]->Clone("den_top");
	den_top_Rebinned = DynamicalRebinHisto(den_top,den_top_Rebinned,Bin_Extremes, isDATA, isDivide);
	
	num_ttbar_Rebinned->Add(num_top_Rebinned);
	den_ttbar_Rebinned->Add(den_top_Rebinned);
       }
      }
     }
     
     if(nameSamples.at(iSample) == "DATA") { 
      isDATA = true;
      
      num_DATA = (TH1D*) histo[iCut+1][iSample]->Clone("num_DATA");
      num_DATA_Rebinned = DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes,isDATA, isDivide);
      
      den_DATA = (TH1D*) histo[iCut][iSample]->Clone("den_DATA");
      den_DATA_Rebinned = DynamicalRebinHisto(den_DATA,den_DATA_Rebinned,Bin_Extremes,isDATA, isDivide);
      
      num_DATA_Rebinned->SetMarkerColor(kBlack);
      num_DATA_Rebinned->SetLineColor(kBlack);
      num_DATA_Rebinned->SetFillColor(kWhite);
      num_DATA_Rebinned->SetMarkerStyle(20);
      den_DATA_Rebinned->SetMarkerColor(kBlack);
      den_DATA_Rebinned->SetFillColor(kWhite);
      den_DATA_Rebinned->SetLineColor(kBlack);
      den_DATA_Rebinned->SetMarkerStyle(20);
      
      isDATA = false;
     }
     
     ///---- for MC subtraction ----
     if(nameSamples.at(iSample) == "VV") { 
      B_VV_SR = (TH1D*) histo[iCut+1][iSample]->Clone("B_VV_SR");
      B_VV_SR_Rebinned = DynamicalRebinHisto(B_VV_SR,B_VV_SR_Rebinned,Bin_Extremes,isDATA, false);
      
      AB_VV_SR = (TH1D*) histo[iCut][iSample]->Clone("AB_VV_SR");
      AB_VV_SR_Rebinned = DynamicalRebinHisto(AB_VV_SR,AB_VV_SR_Rebinned,Bin_Extremes,isDATA, false);
      
      std::cout << "  B_VV_SR->GetEntries() = " <<  B_VV_SR->GetEntries() << std::endl;
      std::cout << " AB_VV_SR->GetEntries() = " << AB_VV_SR->GetEntries() << std::endl;
     
     } 
    }
    
    /// top background Effciency
    
    EfficiencyHisto_ttbar[iCut] = (TH1D*) num_ttbar_Rebinned->Clone("EfficiencyHisto_ttbar");
    EfficiencyHisto_ttbar[iCut] -> Divide(den_ttbar_Rebinned);
    
    ///==== Purity Distribution in the total and Btag Control Region
    
    PurityHisto[iCut+1] = (TH1D*) num_ttbar_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut+1] -> Divide(num_Rebinned);
    
    PurityHisto[iCut] = (TH1D*) den_ttbar_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut] -> Divide(den_Rebinned);
    
    num_DATA_Rebinned = DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes,true,false);
    den_DATA_Rebinned = DynamicalRebinHisto(den_DATA,den_DATA_Rebinned,Bin_Extremes,true,false);
    
    
    for (int ii = 0; ii < num_DATA_Rebinned->GetNbinsX(); ii++) {
     std::cout << " num DATA = " << num_DATA_Rebinned->GetBinContent(ii+1) << "     ";
     std::cout << " bgk  MC  = " <<  B_VV_SR_Rebinned->GetBinContent(ii+1) << "     ";
     std::cout << " den DATA = " << den_DATA_Rebinned->GetBinContent(ii+1) << "     ";
     std::cout << " bgk  MC  = " << AB_VV_SR_Rebinned->GetBinContent(ii+1) << "     ";     
     std::cout << " eff  top = " << EfficiencyHisto_ttbar[iCut]->GetBinContent(ii+1) << "    " ;
     std::cout << " eff DATA = " << (num_DATA_Rebinned->GetBinContent(ii+1)  - B_VV_SR_Rebinned->GetBinContent(ii+1)) / (den_DATA_Rebinned->GetBinContent(ii+1) - AB_VV_SR_Rebinned->GetBinContent(ii+1))  << "    " ;
     std::cout << " SF       = " << (num_DATA_Rebinned->GetBinContent(ii+1)  - B_VV_SR_Rebinned->GetBinContent(ii+1)) / (den_DATA_Rebinned->GetBinContent(ii+1) - AB_VV_SR_Rebinned->GetBinContent(ii+1)) / EfficiencyHisto_ttbar[iCut]->GetBinContent(ii+1)  << std::endl;
    }
    
    num_DATA_Rebinned->Add( B_VV_SR_Rebinned,-1);
    den_DATA_Rebinned->Add(AB_VV_SR_Rebinned,-1);
    
    std::cout << " *** " << std::endl;
    for (int ii = 0; ii < num_DATA_Rebinned->GetNbinsX(); ii++) {
     std::cout << " num DATA = " << num_DATA_Rebinned->GetBinContent(ii+1) << std::endl;
     std::cout << " den DATA = " << den_DATA_Rebinned->GetBinContent(ii+1) << std::endl;
     //      std::cout << " num  VV  = " << num_DATA_Rebinned->GetBinContent(ii) << std::endl;
     if (num_DATA_Rebinned->GetBinContent(ii+1) < 0 || den_DATA_Rebinned->GetBinContent(ii+1) < 0) {
      num_DATA_Rebinned->SetBinContent(ii+1,0.5);
      den_DATA_Rebinned->SetBinContent(ii+1,1);
     }
    }
    
    eff_DATA[iCut] = new TEfficiency(*num_DATA_Rebinned,*den_DATA_Rebinned);
    eff_DATA[iCut]->Bayesian(den_DATA->GetEntries(),num_DATA->GetEntries(),0.68,1,1,false,true);
    eff_DATA[iCut]->SetMarkerColor(kBlack);
    eff_DATA[iCut]->SetLineColor(kBlack);
    eff_DATA[iCut]->SetLineWidth(2);
    
   }
   
   if (iCut == 2) { // ---- A CR
    ///=== no btag part of the efficiency region               
    TH1D * num_Sig = (TH1D*) stack[iCut]->GetStack()->Last();
    TH1D * num_Sig_Rebinned;
    
    num_Sig_Rebinned = DynamicalRebinHisto(num_Sig,num_Sig_Rebinned,Bin_Extremes,isDATA, isDivide);
    
    num_Sig_Rebinned->SetFillStyle(3335);
    num_Sig_Rebinned->SetFillColor(kBlack);
    
    TLegend * legend= makeLegend(*stack[iCut],nameSamples);
    
    stack_Rebinned[iCut] = DynamicalRebinStack(stack[iCut],stack_Rebinned[iCut],Bin_Extremes, isDATA, isDivide);
    
    TH1D* num_DATA_Sig, *num_DATA_Sig_Rebinned; 
    TH1D* num_ttbar_Sig,*num_ttbar_Sig_Rebinned, *num_top_Sig, *num_top_Sig_Rebinned;
    bool done = false;
    for(int iSample=0;iSample<nameSamples.size(); iSample++) {
     
     for (int iNameToJoin = 0; iNameToJoin < nameSamplesToJoin.size(); iNameToJoin++){
      if (nameSamples.at(iSample) == nameSamplesToJoin.at(iNameToJoin)) { 
       if (!done) {
	done = true;
	num_ttbar_Sig = (TH1D*) histo[iCut][iSample]->Clone("num_ttbar_Sig");
	num_ttbar_Sig_Rebinned = DynamicalRebinHisto(num_ttbar_Sig,num_ttbar_Sig_Rebinned,Bin_Extremes,isDATA, isDivide);
       } 
       else {
	num_top_Sig = (TH1D*) histo[iCut][iSample]->Clone("num_top_Sig");
	num_top_Sig_Rebinned = DynamicalRebinHisto(num_top_Sig,num_top_Sig_Rebinned,Bin_Extremes, isDATA, isDivide);
	num_ttbar_Sig_Rebinned->Add(num_top_Sig_Rebinned);
       }
      }
     }
     
     if(nameSamples.at(iSample)=="DATA") { 
      isDATA = true;
      
      num_DATA_Sig = (TH1D*) histo[iCut][iSample]->Clone("num_DATA_Sig");
      num_DATA_Sig_Rebinned = DynamicalRebinHisto(num_DATA_Sig,num_DATA_Sig_Rebinned,Bin_Extremes, isDATA, isDivide);
      
      num_DATA_Sig_Rebinned->SetMarkerColor(kBlack);
      num_DATA_Sig_Rebinned->SetLineColor(kBlack);
      num_DATA_Sig_Rebinned->SetFillColor(kWhite);
      num_DATA_Sig_Rebinned->SetMarkerStyle(20);
      
      isDATA = false;
     }
    }
    
    ///==== Purity Even
    PurityHisto[iCut] = (TH1D*) num_ttbar_Sig_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut]->Divide(num_Sig_Rebinned);
    
    
 }
 
 ///=== Efficiency and purity after VBF selections 
 ///=================
 ///==== SR - AB ====
 ///=================
 ///==== SR - B =====
 
 if(iCut == 3 ) {
    
  TH1D * num_SR = (TH1D*) stack[iCut+1]->GetStack()->Last();
  TH1D * num_SR_Rebinned;
  num_SR_Rebinned = DynamicalRebinHisto(num_SR,num_SR_Rebinned,Bin_Extremes, isDATA, isDivide);
  
  num_SR_Rebinned->SetFillStyle(3335);
  num_SR_Rebinned->SetFillColor(kBlack);
  
  TH1D * den_SR = (TH1D*) stack[iCut]->GetStack()->Last();
  TH1D * den_SR_Rebinned;
  den_SR_Rebinned = DynamicalRebinHisto(den_SR,den_SR_Rebinned,Bin_Extremes, isDATA, isDivide);
  
  den_SR_Rebinned->SetFillStyle(3335);
  den_SR_Rebinned->SetFillColor(kBlack);
  
  TLegend * legend = makeLegend(*stack[iCut],nameSamples);
  
  ///=== Efficiency VBF Region 
  EfficiencyHisto[iCut]= (TH1D*) num_SR_Rebinned->Clone("EfficiencyHisto");
  EfficiencyHisto[iCut]->Divide(den_SR_Rebinned);
  
  stack_Rebinned[iCut] = DynamicalRebinStack(stack[iCut],stack_Rebinned[iCut],Bin_Extremes,isDATA,isDivide);
  stack_Rebinned[iCut+1] = DynamicalRebinStack(stack[iCut+1],stack_Rebinned[iCut],Bin_Extremes,isDATA,isDivide);
  
  TH1D* num_ttbar_SR, *den_ttbar_SR, *den_top_SR, *num_top_SR,* num_DATA_SR, *den_DATA_SR;
  TH1D * num_ttbar_SR_Rebinned, * den_ttbar_SR_Rebinned, * num_top_SR_Rebinned, * den_top_SR_Rebinned, * num_DATA_SR_Rebinned, * den_DATA_SR_Rebinned;
  bool done = false;
  
  for(int iSample=0;iSample<nameSamples.size(); iSample++) {     
   for (int iNameToJoin = 0; iNameToJoin < nameSamplesToJoin.size(); iNameToJoin++){
    if (nameSamples.at(iSample) == nameSamplesToJoin.at(iNameToJoin)) { 
     if (!done) {
      done = true;
      num_ttbar_SR = (TH1D*) histo[iCut+1][iSample]->Clone("num_ttbar_SR");
      num_ttbar_SR_Rebinned = DynamicalRebinHisto(num_ttbar_SR,num_ttbar_SR_Rebinned,Bin_Extremes, isDATA, isDivide);
      
      den_ttbar_SR = (TH1D*) histo[iCut][iSample]->Clone("den_ttbar_SR");
	den_ttbar_SR_Rebinned = DynamicalRebinHisto(den_ttbar_SR,den_ttbar_SR_Rebinned,Bin_Extremes, isDATA, isDivide);
     } 
     else {
      num_top_SR = (TH1D*)histo[iCut+1][iSample]->Clone("num_top_SR");
      num_top_SR_Rebinned = DynamicalRebinHisto(num_top_SR,num_top_SR_Rebinned,Bin_Extremes, isDATA, isDivide);
      
      den_top_SR = (TH1D*) histo[iCut][iSample]->Clone("den_top");
	den_top_SR_Rebinned = DynamicalRebinHisto(den_top_SR,den_top_SR_Rebinned,Bin_Extremes, isDATA, isDivide);
	
	num_ttbar_SR_Rebinned->Add(num_top_SR_Rebinned);
	den_ttbar_SR_Rebinned->Add(den_top_SR_Rebinned);
     }
    }
   }
   
    
   if(nameSamples.at(iSample) == "DATA") { 
    isDATA = true;
    
    num_DATA_SR = (TH1D*)histo[iCut+1][iSample]->Clone("num_DATA_SR");
    num_DATA_SR_Rebinned = DynamicalRebinHisto(num_DATA_SR,num_DATA_SR_Rebinned,Bin_Extremes,isDATA, isDivide);
    
    den_DATA_SR = (TH1D*)histo[iCut][iSample]->Clone("den_DATA_SR");
    den_DATA_SR_Rebinned = DynamicalRebinHisto(den_DATA_SR,den_DATA_SR_Rebinned,Bin_Extremes, isDATA, isDivide);
    
    num_DATA_SR_Rebinned->SetMarkerColor(kBlack);
    num_DATA_SR_Rebinned->SetLineColor(kBlack);
    num_DATA_SR_Rebinned->SetFillColor(kWhite);
    num_DATA_SR_Rebinned->SetMarkerStyle(20);
    
    den_DATA_SR_Rebinned->SetMarkerColor(kBlack);
    den_DATA_SR_Rebinned->SetFillColor(kWhite);
    den_DATA_SR_Rebinned->SetLineColor(kBlack);
    den_DATA_SR_Rebinned->SetMarkerStyle(20);
    
    isDATA = false;
    
   }
   
  }  
  
  ///=== Effciency top background VBF Region
  
  EfficiencyHisto_ttbar[iCut] = (TH1D*) num_ttbar_SR_Rebinned->Clone("EfficiencyHisto_ttbar_SR");
  EfficiencyHisto_ttbar[iCut]->Divide(den_ttbar_SR_Rebinned);
  
  ///=== Purity Distributions
  
  PurityHisto[iCut+1] = (TH1D*) num_ttbar_SR_Rebinned->Clone("PurityHisto");
  PurityHisto[iCut+1]->Divide(num_SR_Rebinned);
  
  PurityHisto[iCut]= (TH1D*) den_ttbar_SR_Rebinned->Clone("PurityHisto");
  PurityHisto[iCut]->Divide(den_SR_Rebinned);
  
  
  num_DATA_SR_Rebinned = DynamicalRebinHisto(num_DATA_SR,num_DATA_SR_Rebinned,Bin_Extremes,true,false);
  den_DATA_SR_Rebinned = DynamicalRebinHisto(den_DATA_SR,den_DATA_SR_Rebinned,Bin_Extremes,true,false);
  
  eff_DATA[iCut] = new TEfficiency(*num_DATA_SR_Rebinned,*den_DATA_SR_Rebinned);
  eff_DATA[iCut]->Bayesian(den_DATA_SR->GetEntries(),num_DATA_SR_Rebinned->GetEntries(),0.95,1,1,false,true);
  
 }
 
 ///================
 ///==== SR - A ====
 if(iCut == 5) { //---- A SR
    
    TH1D * num_SR_Sig = (TH1D*)stack[iCut]->GetStack()->Last();
    TH1D * num_SR_Sig_Rebinned;
    num_SR_Sig_Rebinned = DynamicalRebinHisto(num_SR_Sig,num_SR_Sig_Rebinned,Bin_Extremes,isDATA,isDivide);
    
    num_SR_Sig_Rebinned->SetFillStyle(3335);
    num_SR_Sig_Rebinned->SetFillColor(kBlack);
    
    TLegend * legend= makeLegend(*stack[iCut],nameSamples);
    
    stack_Rebinned[iCut] = DynamicalRebinStack(stack[iCut],stack_Rebinned[iCut],Bin_Extremes,isDATA,isDivide);
    
    TH1D* num_DATA_SR_Sig, *num_DATA_SR_Sig_Rebinned, *num_ttbar_Sig,*num_ttbar_Sig_Rebinned,*num_top_Sig,*num_top_Sig_Rebinned;
    TH1D* den_ttbar_Sig, *den_ttbar_Sig_Rebinned, *den_top_Sig, *den_top_Sig_Rebinned;
    TH1D* temp_hist_all, *temp_hist_all_rebinned;
    bool done = false;
    
    for(int iSample=0; iSample<nameSamples.size(); iSample++) {
     for (int iNameToJoin = 0; iNameToJoin < nameSamplesToJoin.size(); iNameToJoin++){
      if (nameSamples.at(iSample) == nameSamplesToJoin.at(iNameToJoin)) { 
       if (!done) {
	done = true;
	num_ttbar_Sig = (TH1D*) histo[iCut][iSample]->Clone("num_ttbar_Sig");
	num_ttbar_Sig_Rebinned = DynamicalRebinHisto(num_ttbar_Sig,num_ttbar_Sig_Rebinned,Bin_Extremes,isDATA, isDivide);
	
	den_ttbar_Sig = (TH1D*) histo[iCut][iSample]->Clone("den_ttbar_Sig");
	den_ttbar_Sig_Rebinned = DynamicalRebinHisto(den_ttbar_Sig,den_ttbar_Sig_Rebinned,Bin_Extremes, isDATA, isDivide);
       }
       else {
	num_top_Sig = (TH1D*)histo[iCut][iSample]->Clone("num_top_Sig");
	num_top_Sig_Rebinned = DynamicalRebinHisto(num_top_Sig,num_top_Sig_Rebinned,Bin_Extremes, isDATA, isDivide);
	
	den_top_Sig = (TH1D*) histo[iCut][iSample]->Clone("den_top_Sig");
	den_top_Sig_Rebinned = DynamicalRebinHisto(den_top_Sig,den_top_Sig_Rebinned,Bin_Extremes, isDATA, isDivide);
	
	num_ttbar_Sig_Rebinned->Add(num_top_Sig_Rebinned);
	den_ttbar_Sig_Rebinned->Add(den_top_Sig_Rebinned);
       }
      }
      else {
       if (nameSamples.at(iSample) != "DATA") {
	
	if (nameSamples.at(iSample) != "qqH" && nameSamples.at(iSample) != "ggH") {
	 if (!SR_AB_Zone_all_NoHiggs) {
	  temp_hist_all = (TH1D*) histo[iCut][iSample]->Clone("num_all_Sig"); 
	  SR_AB_Zone_all_NoHiggs = DynamicalRebinHisto( temp_hist_all, SR_AB_Zone_all_NoHiggs, Bin_Extremes, isDATA, isDivide);
	 }
	 else {
	  TString histo_name = Form ("%s_%d_%d_Tot_temp_my_tt_NoHiggs", nameSamples.at(iSample).c_str(), iCut, 0);
	  temp_hist_all = (TH1D*) histo[iCut][iSample]->Clone(); //(histo_name.Data()); 
	temp_hist_all_rebinned = DynamicalRebinHisto( temp_hist_all, temp_hist_all_rebinned, Bin_Extremes, isDATA, isDivide);
	SR_AB_Zone_all_NoHiggs->Add(temp_hist_all_rebinned);
	 }
	}
	
	if (!SR_AB_Zone_all) {
	 temp_hist_all = (TH1D*) histo[iCut][iSample]->Clone("num_all_Sig"); 
	 SR_AB_Zone_all = DynamicalRebinHisto( temp_hist_all, SR_AB_Zone_all, Bin_Extremes, isDATA, isDivide);
	}
	else {
	 TString histo_name = Form ("%s_%d_%d_Tot_temp_my_tt", nameSamples.at(iSample).c_str(), iCut, 0);
	 temp_hist_all = (TH1D*) histo[iCut][iSample]->Clone(); //(histo_name.Data()); 
	temp_hist_all_rebinned = DynamicalRebinHisto( temp_hist_all, temp_hist_all_rebinned, Bin_Extremes, isDATA, isDivide);
	SR_AB_Zone_all->Add(temp_hist_all_rebinned);
	}
       }
      }
     }
     
     if(nameSamples.at(iSample) == "DATA") {
      isDATA = true;
      
      num_DATA_SR_Sig = (TH1D*) histo[iCut][iSample]->Clone("num_DATA_SR_Sig");
      num_DATA_SR_Sig_Rebinned = DynamicalRebinHisto(num_DATA_SR_Sig,num_DATA_SR_Sig_Rebinned,Bin_Extremes,isDATA,isDivide);
      
      isDATA = false;
     } 
    }
    
    ///==== Purity Distribution
    
    PurityHisto[iCut] = (TH1D*) num_ttbar_Sig_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut]->Divide(num_SR_Sig_Rebinned);
    
//     SR_AB_Zone_tt = (TH1D*) den_ttbar_Sig_Rebinned->Clone();
    
 }
 
 } //---- end loop cut

 std::cerr << " *** Final *** " << std::endl;
 
 ///===== Final Plot for Efficiency Comparison and DATA Driven Estimation
 
 ///                            
 TEfficiency* Efficiency_Control_Zone;
 TH1D *SR_DATA_B_Zone;
 TH1D *SR_DATA_A_Zone;
 TGraphAsymmErrors* SR_A_Zone_Estimation;
 TGraphAsymmErrors* SR_A_Zone_Estimation_allBackgrounds;
 TGraphAsymmErrors* SR_A_Zone_Estimation_allBackgrounds_NoHiggs;
 
 TH1D *SR_AB_Zone_tt;
 TH1D *SR_DATA_AB_Zone;
 
  
  bool isDivide = true;
  
  for(int iCut=0; iCut<Cuts.size(); iCut++) {
   if(iCut == 0) {
    ///==== Efficiency on DATA in the Efficiency region
    Efficiency_Control_Zone = (TEfficiency*) eff_DATA[iCut]->Clone("Efficiency_Control_Zone");
   }
   
   ///===== Distribution of data in the Btag Zone (Control Region)  after the VBF selections
   
   if (iCut == 4) {
    for(int iSample=0; iSample<nameSamples.size(); iSample++) {
     if(nameSamples.at(iSample)!="DATA") continue;
     
     TH1D* Temp;
     Temp = (TH1D*) histo[iCut][iSample]->Clone("Temp");
     
     SR_DATA_B_Zone = DynamicalRebinHisto(Temp,SR_DATA_B_Zone,Bin_Extremes, true, isDivide);
     Temp->Delete();
     
    }
   }
   
   ///==== Distribution fo DATA in the A zone Signal Region  (SR) [begin] ====   
   if (iCut == 5) {
    for(int iSample=0; iSample<nameSamples.size(); iSample++) {
     if (nameSamples.at(iSample)=="DATA") {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp"); 
      SR_DATA_A_Zone = DynamicalRebinHisto(Temp,SR_DATA_A_Zone,Bin_Extremes, true,  isDivide);
      Temp->Delete();
     }
     
     if (nameSamples.at(iSample) == "top" ) {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp2"); 
      SR_A_Zone_tt =  DynamicalRebinHisto(Temp,SR_A_Zone_tt,   Bin_Extremes, false, isDivide);
      Temp->Delete();
     } 
     
    } 
   }
   ///==== Distribution fo DATA in the A zone Signal Region  (SR) [end] ====
   
   ///==== Distribution fo DATA in the AB zone Signal Region  (SR) [begin] ====   
   if (iCut == 3) {
    for(int iSample=0; iSample<nameSamples.size(); iSample++) {
     if (nameSamples.at(iSample)=="DATA") {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp"); 
      SR_DATA_AB_Zone = DynamicalRebinHisto(Temp,SR_DATA_AB_Zone,Bin_Extremes, true,  isDivide);
      Temp->Delete();
     }
     
     if (nameSamples.at(iSample) == "top" ) {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp2"); 
      SR_AB_Zone_tt =  DynamicalRebinHisto(Temp,SR_AB_Zone_tt,   Bin_Extremes, false, isDivide);
      Temp->Delete();
     } 
     
    } 
   }
   ///==== Distribution fo DATA in the AB zone Signal Region  (SR) [end] ====
   
  }
  
  ///==== Final Data driven estimation in the signal region for each Variable
  
  
  double numAMC = 0;
  double errnumAMC = 0;
  
  double numB = 0;
  double numBfromA_mean = 0;
  double numBfromA_up   = 0;
  double numBfromA_low  = 0;
  
  std::cout << "***********************************************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  
  if (SR_DATA_A_Zone!=0 && SR_DATA_B_Zone!=0 && Efficiency_Control_Zone!=0) { 
   
   for(int iBin=0; iBin<SR_DATA_A_Zone->GetNbinsX(); iBin++) { 
    
    if (SR_DATA_A_Zone->GetBinCenter(iBin+1) < 2.5) {
     double eff_low, eff_up, eff_mean;
     double value_low, value_up, value_mean;
     //----        NUM * (1-eff)/eff        ----
     eff_mean = Efficiency_Control_Zone->GetEfficiency(iBin+1);
     eff_low  = eff_mean - Efficiency_Control_Zone->GetEfficiencyErrorLow(iBin+1);
     eff_up   = eff_mean + Efficiency_Control_Zone->GetEfficiencyErrorUp(iBin+1);
     
//      if (iBin == 0) eff_mean = 0.702;
//      if (iBin == 1) eff_mean = 0.733;
//      if (iBin == 2) eff_mean = 0.669;
//      if (iBin == 3) eff_mean = 0.707;
//      if (iBin == 4) eff_mean = 0.367;
     
     value_mean = eff_mean!=1  ?  eff_mean / (1.-eff_mean) * SR_A_Zone_tt->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     value_up   = eff_up!=1    ?  eff_up   / (1.-eff_up)   * SR_A_Zone_tt->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     value_low  = eff_low!=1   ?  eff_low  / (1.-eff_low)  * SR_A_Zone_tt->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     
     numBfromA_up   += value_up  ;
     numBfromA_low  += value_low ;
     numBfromA_mean += value_mean;
     
     std::cout << " eff_mean[" << iBin << "] = " << eff_mean << " --- (" << eff_low << "," << eff_up << ") " << std::endl;
     std::cout << " B (DATA)[" << iBin << "] = " << SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << std::endl;
     //      std::cout << " -->  value_up [" << iBin << "] += " << value_up  << std::endl;
//      std::cout << " -->  value_low[" << iBin << "] += " << value_low << std::endl;
     
    }
    
    errnumAMC = sqrt (errnumAMC*errnumAMC + SR_A_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * SR_A_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)));
    numAMC += SR_A_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
    numB   += SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
    
   }
  }
  
  
  std::cout << "***********************************************************" << std::endl;
  std::cout << "****************** MC prediction **************************" << std::endl;  
  std::cout << "  numA (MC)         = " << numAMC         << " +/- " << errnumAMC << std::endl;
  std::cout << "  numB (DATA)       = " << numB           << " +/- " << sqrt(numB) << std::endl;
  std::cout << "  numBfromA (DATA)  = " << numBfromA_mean << " +/- " << (numBfromA_up-numBfromA_low)/2. << std::endl;
  std::cout << "  numBfromA (DATA) up  = " << numBfromA_up  << std::endl;
  std::cout << "  numBfromA (DATA) low = " << numBfromA_low << std::endl;
  
  double SF = numB / numBfromA_mean ;
  double SF_low = numB / numBfromA_low;
  double SF_up  = numB / numBfromA_up ;
  double errSFsyst = 0.5 * (numB / numBfromA_low - numB / numBfromA_up);
  double errSFstat = sqrt(numB) / numBfromA_mean ;
  double errSF     = sqrt(errSFsyst*errSFsyst + errSFstat*errSFstat);
  
  std::cout << "  Scale Factor      = " << SF << " +/- " << errSFsyst  << " (+) " << errSFstat << " = " << errSF << std::endl;
  std::cout << "  Scale Factor (syst err)     = " << errSFsyst << std::endl;
  std::cout << "  Scale Factor (stat err)     = " << errSFstat << std::endl;
  
  std::cout << "***********************************************************" << std::endl;
  std::cout << "  top (@datacard) = " << numAMC * SF      << std::endl;
  std::cout << "  err             = " << (1. + errSF/SF)  << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  
  ///---- save for datacard ----///
  
  std::ofstream myfileValue; 
  myfileValue.open ("test/Latinos/ttbar/result-value.txt",std::fstream::app);
  myfileValue << numAMC * SF << std::endl;
  myfileValue.close();
  
  std::ofstream myfileSyst; 
  myfileSyst.open ("test/Latinos/ttbar/result-syst.txt",std::fstream::app);
  myfileSyst << (1. + errSF/SF) << std::endl;
  myfileSyst.close();
  
  
  std::ofstream myfileAll; 
  myfileAll.open ("test/Latinos/ttbar/result-all.txt",std::fstream::app);
  myfileAll << numAMC * SF << "    " ;
  myfileAll << numAMC * SF_low << " < " ;
  myfileAll << numAMC * SF_up  << " < " ;
  myfileAll << std::endl;
  myfileAll.close();
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  std::cout << "***********************************************************" << std::endl;
  std::cout << "****************** ALTERNATIVE ****************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  
  double numAfromB_up   = 0;
  double numAfromB_low  = 0;
  double numAfromB_mean = 0;
  
  double err_numAfromB_mean = 0;
  
  errnumAMC = 0;
  numAMC = 0;
  numB = 0;
  
  if (SR_DATA_A_Zone!=0 && SR_DATA_B_Zone!=0 && Efficiency_Control_Zone!=0) { 
   
   for(int iBin=0; iBin<SR_DATA_B_Zone->GetNbinsX(); iBin++) { 
    
    if (SR_DATA_B_Zone->GetBinCenter(iBin+1) < 2.5) {
     double eff_low, eff_up, eff_mean;
     double value_low, value_up, value_mean;
     //----        NUM * (1-eff)/eff        ----
     eff_mean = Efficiency_Control_Zone->GetEfficiency(iBin+1);
     eff_low  = eff_mean - Efficiency_Control_Zone->GetEfficiencyErrorLow(iBin+1);
     eff_up   = eff_mean + Efficiency_Control_Zone->GetEfficiencyErrorUp(iBin+1);
     
     value_mean = eff_mean!=0  ?  (1.-eff_mean) / eff_mean * SR_DATA_B_Zone->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     value_up   = eff_up!=0    ?  (1.-eff_up)   / eff_up   * SR_DATA_B_Zone->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     value_low  = eff_low!=0   ?  (1.-eff_low)  / eff_low  * SR_DATA_B_Zone->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     
     numAfromB_up   += value_up  ;
     numAfromB_low  += value_low ;
     numAfromB_mean += value_mean;
     
     std::cout << " eff_mean[" << iBin << "] = " << eff_mean << " --- (" << eff_low << "," << eff_up << ") " << std::endl;
     std::cout << " -->  value_up  @A [" << iBin << "] += " << value_up  << std::endl;
     std::cout << " -->  value_low @A [" << iBin << "] += " << value_low << std::endl;
     
     errnumAMC = sqrt (errnumAMC*errnumAMC + SR_A_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * SR_A_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)));
     numAMC += SR_A_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
     numB   += SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
     double temperr = eff_mean!=0  ?  (1.-eff_mean) / eff_mean * SR_DATA_B_Zone->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     err_numAfromB_mean = sqrt(err_numAfromB_mean*err_numAfromB_mean + temperr*temperr);
    }
   }
  }
  
  
  std::cout << "***********************************************************" << std::endl;
  std::cout << "****************** MC prediction **************************" << std::endl;  
  std::cout << "  numA (MC)         = " << numAMC         << " +/- " << errnumAMC << std::endl;
  std::cout << "  numB (DATA)       = " << numB           << " +/- " << sqrt(numB) << std::endl;
  std::cout << "  numAfromB (DATA)  = " << numAfromB_mean << " +/- " << (numAfromB_up-numAfromB_low)/2. << std::endl;
  std::cout << "  numAfromB (DATA) up  = " << numAfromB_up  << std::endl;
  std::cout << "  numAfromB (DATA) low = " << numAfromB_low << std::endl;
  
  SF = numAfromB_mean / numAMC ;
  SF_low = numAfromB_low / numAMC ;
  SF_up  = numAfromB_up  / numAMC ;
  errSFsyst = 0.5 * (numAfromB_up  / numAMC - numAfromB_low / numAMC);
  errSFstat = err_numAfromB_mean ;
  double errSF     = sqrt(errSFsyst*errSFsyst + errSFstat*errSFstat);
  
  std::cout << "  Scale Factor      = " << SF << " +/- " << errSFsyst  << " (+) " << errSFstat << " = " << errSF << std::endl;
  std::cout << "  Scale Factor (syst err)     = " << errSFsyst << std::endl;
  std::cout << "  Scale Factor (stat err)     = " << errSFstat << std::endl;
  
  std::cout << "***********************************************************" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  

  
  
  
  
  
  
  
  
  
  std::cout << "***********************************************************" << std::endl;
  std::cout << "******************** CORRECT ******************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  
  double ScaleFactor_up   = 0;
  double ScaleFactor_low  = 0;
  double ScaleFactor_mean = 0;
  
  double numABfromB_up   = 0;
  double numABfromB_low  = 0;
  double numABfromB_mean = 0;
  double err_numABfromB_mean = 0;
  
  double errnumABMC = 0;
  double numABMC = 0;
  
  double numAfromB_up   = 0;
  double numAfromB_low  = 0;
  double numAfromB_mean = 0;
  
  
  if (SR_DATA_A_Zone!=0 && SR_DATA_B_Zone!=0 && Efficiency_Control_Zone!=0) { 
   
   for(int iBin=0; iBin<SR_DATA_B_Zone->GetNbinsX(); iBin++) { 
    
    if (SR_DATA_B_Zone->GetBinCenter(iBin+1) < 2.5) {
     double eff_low, eff_up, eff_mean;
     double value_low, value_up, value_mean;
     //----        NUM * (1-eff)/eff        ----
     eff_mean = Efficiency_Control_Zone->GetEfficiency(iBin+1);
     eff_low  = eff_mean - Efficiency_Control_Zone->GetEfficiencyErrorLow(iBin+1);
     eff_up   = eff_mean + Efficiency_Control_Zone->GetEfficiencyErrorUp(iBin+1);
     
     value_mean = eff_mean!=0  ?  1. / eff_mean * SR_DATA_B_Zone->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     value_up   = eff_up!=0    ?  1. / eff_up   * SR_DATA_B_Zone->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     value_low  = eff_low!=0   ?  1. / eff_low  * SR_DATA_B_Zone->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     
     numABfromB_up   += value_up  ;
     numABfromB_low  += value_low ;
     numABfromB_mean += value_mean;
     
     std::cout << " eff_mean[" << iBin << "] = " << eff_mean << " --- (" << eff_low << "," << eff_up << ") " << std::endl;
     std::cout << " -->  value_up  @A [" << iBin << "] += " << value_up  << std::endl;
     std::cout << " -->  value_low @A [" << iBin << "] += " << value_low << std::endl;
     
     errnumABMC = sqrt (errnumABMC*errnumABMC + SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)));
     numABMC += SR_AB_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
     
     double temperr = eff_mean!=0  ?  1. / eff_mean * SR_DATA_B_Zone->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     err_numABfromB_mean = sqrt(err_numABfromB_mean*err_numABfromB_mean + temperr*temperr);
    }
   }
  }
    
  std::cout << "***********************************************************" << std::endl;
  std::cout << "****************** MC prediction **************************" << std::endl;  
  std::cout << "  numAB (MC)         = " << numABMC         << " +/- " << errnumABMC << std::endl;
  std::cout << "  numABfromB (DATA)  = " << numABfromB_mean << " +/- " << (numABfromB_up-numABfromB_low)/2. << std::endl;
  std::cout << "  numABfromB (DATA) up  = " << numABfromB_up  << std::endl;
  std::cout << "  numABfromB (DATA) low = " << numABfromB_low << std::endl;
  
  ScaleFactor_up   = numABfromB_low  / numABMC;
  ScaleFactor_low  = numABfromB_up   / numABMC;
  ScaleFactor_mean = numABfromB_mean / numABMC;
  
  std::cout << "  ScaleFactor_up   = " << ScaleFactor_up << std::endl;
  std::cout << "  ScaleFactor_low  = " << ScaleFactor_low << std::endl;
  std::cout << "  ScaleFactor_mean = " << ScaleFactor_mean << std::endl;
  
  double numB_DATA = 0;
  
  numAMC = 0;
  errnumAMC = 0;

  double errStatFromB = 0;
  
  if (SR_DATA_A_Zone!=0 && SR_DATA_B_Zone!=0 && Efficiency_Control_Zone!=0) { 
   
   for(int iBin=0; iBin<SR_DATA_B_Zone->GetNbinsX(); iBin++) { 
    double temperrnumABMC = SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
    double tempnumABMC = SR_AB_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
    
    if (SR_DATA_B_Zone->GetBinCenter(iBin+1) < 2.5) { 
     numB_DATA = SR_DATA_B_Zone->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
     
     numAfromB_up   += ( tempnumABMC * ScaleFactor_up   - numB_DATA ) ;
     numAfromB_low  += ( tempnumABMC * ScaleFactor_low  - numB_DATA ) ;
     numAfromB_mean += ( tempnumABMC * ScaleFactor_mean - numB_DATA ) ;
     
     double tempnumABMC = SR_AB_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
     double err_value_mean = SR_DATA_B_Zone->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
     double err_value_mean = eff_mean!=0  ?  1. / eff_mean * SR_DATA_B_Zone->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     errStatFromB   =  sqrt(errStatFromB*errStatFromB + err_value_mean * err_value_mean * (tempnumABMC / eff_mean / numABMC - 1) * (tempnumABMC / eff_mean / numABMC - 1));
    }
    else {
     numAfromB_up   += ( tempnumABMC * ScaleFactor_up   ) ;
     numAfromB_low  += ( tempnumABMC * ScaleFactor_low  ) ;
     numAfromB_mean += ( tempnumABMC * ScaleFactor_mean ) ;
    }
    
    errnumAMC = sqrt (errnumAMC*errnumAMC + SR_A_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * SR_A_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)));
    numAMC += SR_A_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
    
   }
  }

  double Global_ScaleFactor_up   = numAfromB_up   / numAMC ;
  double Global_ScaleFactor_low  = numAfromB_low  / numAMC ;
  double Global_ScaleFactor_mean = numAfromB_mean / numAMC ;

  std::cout << "  Global ScaleFactor     = " << Global_ScaleFactor_mean << " +/- " << (Global_ScaleFactor_up-Global_ScaleFactor_low)/2. << std::endl;
  std::cout << "  Global ScaleFactor up  = " << Global_ScaleFactor_up   << std::endl;
  std::cout << "  Global ScaleFactor low = " << Global_ScaleFactor_low  << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << "  Global ScaleFactor     = " << Global_ScaleFactor_mean << " +/- " << (Global_ScaleFactor_up-Global_ScaleFactor_low)/2. << "(syst) +/- " ;
  std::cout << errStatFromB << " (stat) = ";
  std::cout << sqrt(errStatFromB*errStatFromB + (Global_ScaleFactor_up-Global_ScaleFactor_low)/2.*(Global_ScaleFactor_up-Global_ScaleFactor_low)/2.) << std::endl;
  std::cout << "  numB (DATA)       = " << numB           << " +/- " << sqrt(numB) << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  
  
  
  
  
  
  
  gApplication->Terminate(0);
 
}


