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
#include "test/Latinos12/ttbar/plotUtils.C"

#include <iomanip>

///==== Macros input are: input file name

int GetTop_Result_forDataCard(TString input, int iVar = 0, int PlusCut = 0, int iWP = 0, TString suffix = "") {
 
 ///=== Open the input ROOT File from test/MCDATAComparisonPLOTTool.cpp
 
 TFile * Input_File = TFile::Open(input.Data());
 
 std::string nameHumanVariable = "|#eta|^{Jet}";
 std::vector<std::string> nameSamplesToJoin;
 nameSamplesToJoin.push_back("top");
 
 std::vector<std::string> Cuts;
 for (int iNumCut = 0; iNumCut<=PlusCut; iNumCut++) {
  Cuts.push_back("AB-CR");
  Cuts.push_back("B-CR");
  Cuts.push_back("A-CR");
  Cuts.push_back("AB-SR");
  Cuts.push_back("B-SR");
  Cuts.push_back("A-SR");
 }
 
 std::vector<float> Bin_Extremes;
 std::vector<float> row;
 
 ///===== Acquisition info from txt file: Name of the samples, Cut applied and Variables of Plot and their binning
 
 
 TString nameFileBinDefinition = Form ("test/Latinos12/ttbar/BinDefinition_%d.txt",iVar);
 std::ifstream inFile(nameFileBinDefinition.Data());
//  std::ifstream inFile("test/Latinos12/ttbar/BinDefinition.txt");
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
 
 char *name_Sample[1000];
 char *nameHumanReadable[1000];
 char* xsectionName[1000];
 
 double Normalization[1000];
 double xsection  [1000];
 char nameFileIn  [1000];
 
 int numberOfSamples = ReadFile("test/Latinos12/ttbar/datacard/SamplesH.txt", name_Sample, nameHumanReadable, xsectionName); 
 
 std::cout << " transform names ... " << std::endl;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  xsection[iSample] = atof(xsectionName[iSample]);
 }
 
 std::vector<std::string> nameSamples;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  nameSamples.push_back(nameHumanReadable[iSample]);
 }
 
 
 std::vector<std::string> reduced_name_samples;
 std::vector<int>         reduced_name_samples_flag;
 for (int iSample = (nameSamples.size()-1); iSample>= 0; iSample--){
  bool flag_name = false;
  for (unsigned int iName=0; iName<reduced_name_samples.size(); iName++){
   if (reduced_name_samples.at(iName) == nameSamples.at(iSample)) flag_name = true;
  }
  if (flag_name == false) {
//    if (nameSamples.at(iSample) != "DATA") {
    reduced_name_samples.push_back(nameSamples.at(iSample));
    reduced_name_samples_flag.push_back(-1);
//    }
  }
 }
 
 bool debug = false;
 

 ///=== Acquisition from the input file of the object: stack and histogramms 
 //  [iCut][iName]  ()
 TH1D* histo[103][83]; 
 //  [iCut]         ()
 THStack* stack[103];
 
 for(int iCut=0; iCut<Cuts.size();iCut++) {  
  TString stack_name = Form ("Data/%d_%d_stack", iCut, iVar);  //---- iVar == 0 !
  stack[iCut] = (THStack*) Input_File->Get(stack_name);
  
  for(int iSample = 0; iSample < reduced_name_samples.size(); iSample++) {   
   TString histo_name = Form ("Data/%s_%d_%d_Tot_temp", reduced_name_samples.at(iSample).c_str(), iCut, iVar);
   if (debug) std::cout << " histo_name[" << iSample << "::" << reduced_name_samples.size() << " = " << histo_name.Data() << std::endl;
   histo[iCut][iSample] = (TH1D*) Input_File->Get(histo_name);
   if (debug) std::cout << " histo[" << iCut << "][" << iSample << "] = " << histo[iCut][iSample] << std::endl;
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
 TH1D *SR_B_Zone_tt;
 
 TH1D *B_VV_CR;
 TH1D *B_VV_CR_Rebinned; 
 TH1D *A_VV_CR;
 TH1D *A_VV_CR_Rebinned; 
 TH1D *AB_VV_CR;
 TH1D *AB_VV_CR_Rebinned; 
 
 TH1D *B_VV_SR;
 TH1D *B_VV_SR_Rebinned; 
 TH1D *A_VV_SR;
 TH1D *A_VV_SR_Rebinned; 
 TH1D *AB_VV_SR;
 TH1D *AB_VV_SR_Rebinned; 
 
 for (int iEdge = 0; iEdge < Bin_Extremes.size(); iEdge++) {
  std::cout << " edge[" << iEdge << "] = " << Bin_Extremes.at(iEdge) << std::endl;
 }
 
 for(int iCut=0; iCut<Cuts.size(); iCut++) {  //---- 2 cuts : (AB, B, A) for CR and SR
   bool isDATA = false;
   bool isDivide = true;
   
   if (debug) { std::cout << "iCut = " << iCut << " :: " << Cuts.size() << std::endl; }
   
   ///==== Efficiency analysis in the control region 
   if (iCut == 0+6*PlusCut) {
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
    
//     TLegend * legend = makeLegend(*stack[iCut],nameSamples); ///=== See PlotUtils.C
    
    ///==== Total Efficiency Distriubution for each Cut and Variables
    
    EfficiencyHisto[iCut] = (TH1D*) num_Rebinned->Clone("EfficiencyHisto");
    EfficiencyHisto[iCut] -> Divide(den_Rebinned);
    
    ///==== Dynamical rebin for the stack, see PlotUtils.C
    
    stack_Rebinned[iCut]   = DynamicalRebinStack(stack[iCut],stack_Rebinned[iCut],Bin_Extremes,isDATA,isDivide);
    stack_Rebinned[iCut+1] = DynamicalRebinStack(stack[iCut+1],stack_Rebinned[iCut+1],Bin_Extremes,isDATA,isDivide);
    
    ///==== Efficiency on top and DATA samples
    
    TH1D* num_ttbar, *den_ttbar, *num_top, *den_top,*num_DATA, *den_DATA;
    TH1D * num_ttbar_Rebinned, * den_ttbar_Rebinned,* num_top_Rebinned, * den_top_Rebinned, * num_DATA_Rebinned, * den_DATA_Rebinned;
//     TH1D *B_VV_SR_Rebinned, *B_VV_SR, *AB_VV_SR_Rebinned, *AB_VV_SR;
    
    bool done;
    for(int iSample=0; iSample<reduced_name_samples.size(); iSample++) {
     if (debug) { 
      std::cout << " >>  reduced_name_samples = " << reduced_name_samples.at(iSample) << " [" << iSample << "][" << reduced_name_samples.size() << "]" << std::endl;
      std::cout << " >>  iCut = " << iCut << " :: " << Cuts.size() << std::endl;
     }
      
     for (int iNameToJoin = 0; iNameToJoin < nameSamplesToJoin.size(); iNameToJoin++){
      if (reduced_name_samples.at(iSample) == nameSamplesToJoin.at(iNameToJoin)) { 
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
     
     if(reduced_name_samples.at(iSample) == "DATA") { 
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
     if(reduced_name_samples.at(iSample) == "VV" || reduced_name_samples.at(iSample) == "VV-DY-Fake" || reduced_name_samples.at(iSample) == "VV-DY-Fake-CR") { 
      if (debug) { 
       std::cout << " >>  iCut = " << iCut << " :: " << Cuts.size() << std::endl;
       std::cout << " >>  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
       std::cout << " >>  ~~~~~ VV in CR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
       std::cout << " >>  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
      }
      
      B_VV_CR = (TH1D*) histo[iCut+1][iSample]->Clone("B_VV_CR");
      B_VV_CR_Rebinned = DynamicalRebinHisto(B_VV_CR,B_VV_CR_Rebinned,Bin_Extremes,isDATA, false);
            
      AB_VV_CR = (TH1D*) histo[iCut][iSample]->Clone("AB_VV_CR");
      AB_VV_CR_Rebinned = DynamicalRebinHisto(AB_VV_CR,AB_VV_CR_Rebinned,Bin_Extremes,isDATA, false);
      
//       std::cout << "  B_VV_CR->GetEntries() = " <<  B_VV_CR->GetEntries() << std::endl;
//       std::cout << " AB_VV_CR->GetEntries() = " << AB_VV_CR->GetEntries() << std::endl;
     
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
     std::cout << " bin = " << ii << "  ";
     std::cout << " num DATA = " << num_DATA_Rebinned->GetBinContent(ii+1) << " ~ ";
     std::cout << " bgk  MC  = " <<  B_VV_CR_Rebinned->GetBinContent(ii+1) << "   ";
     std::cout << " den DATA = " << den_DATA_Rebinned->GetBinContent(ii+1) << " ~ ";
     std::cout << " bgk  MC  = " << AB_VV_CR_Rebinned->GetBinContent(ii+1) << "   ";     
     std::cout << " eff  top = " << EfficiencyHisto_ttbar[iCut]->GetBinContent(ii+1) << "  " ;
     std::cout << " eff DATA = " << (num_DATA_Rebinned->GetBinContent(ii+1)  - B_VV_CR_Rebinned->GetBinContent(ii+1)) / (den_DATA_Rebinned->GetBinContent(ii+1) - AB_VV_CR_Rebinned->GetBinContent(ii+1))  << "  " ;
     std::cout << " SF (efficiency) = " << (num_DATA_Rebinned->GetBinContent(ii+1)  - B_VV_CR_Rebinned->GetBinContent(ii+1)) / (den_DATA_Rebinned->GetBinContent(ii+1) - AB_VV_CR_Rebinned->GetBinContent(ii+1)) / EfficiencyHisto_ttbar[iCut]->GetBinContent(ii+1)  << std::endl;
    }
    
    ///---- for efficiency measurement the VV contribution is subtracted using MC/DD estimation (begin) ----
    num_DATA_Rebinned->Add( B_VV_CR_Rebinned,-1);
    den_DATA_Rebinned->Add(AB_VV_CR_Rebinned,-1);
    ///---- for efficiency measurement the VV contribution is subtracted using MC/DD estimation (end) ----
    
    std::cout << " *** " << std::endl;
    for (int ii = 0; ii < num_DATA_Rebinned->GetNbinsX(); ii++) {
     std::cout << " num DATA = " << num_DATA_Rebinned->GetBinContent(ii+1) << std::endl;
     std::cout << " den DATA = " << den_DATA_Rebinned->GetBinContent(ii+1) << std::endl;
     //      std::cout << " num  VV  = " << num_DATA_Rebinned->GetBinContent(ii) << std::endl;
     if (num_DATA_Rebinned->GetBinContent(ii+1) > den_DATA_Rebinned->GetBinContent(ii+1) ) { ///---- only if MC subtraction greater than DATA!
      num_DATA_Rebinned->SetBinContent(ii+1,den_DATA_Rebinned->GetBinContent(ii+1));
     }
      
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
   
   if (iCut == 2+6*PlusCut) { // ---- A CR
    ///=== no btag part of the efficiency region               
    TH1D * num_Sig = (TH1D*) stack[iCut]->GetStack()->Last();
    TH1D * num_Sig_Rebinned;
    
    num_Sig_Rebinned = DynamicalRebinHisto(num_Sig,num_Sig_Rebinned,Bin_Extremes,isDATA, isDivide);
    
    num_Sig_Rebinned->SetFillStyle(3335);
    num_Sig_Rebinned->SetFillColor(kBlack);
    
//     TLegend * legend= makeLegend(*stack[iCut],nameSamples);
    
    stack_Rebinned[iCut] = DynamicalRebinStack(stack[iCut],stack_Rebinned[iCut],Bin_Extremes, isDATA, isDivide);
    
    TH1D* num_DATA_Sig, *num_DATA_Sig_Rebinned; 
    TH1D* num_ttbar_Sig,*num_ttbar_Sig_Rebinned, *num_top_Sig, *num_top_Sig_Rebinned;
    bool done = false;
    for(int iSample=0;iSample<reduced_name_samples.size(); iSample++) {
     
     for (int iNameToJoin = 0; iNameToJoin < nameSamplesToJoin.size(); iNameToJoin++){
      if (reduced_name_samples.at(iSample) == nameSamplesToJoin.at(iNameToJoin)) { 
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
     
     if(reduced_name_samples.at(iSample)=="DATA") { 
      isDATA = true;
      
      num_DATA_Sig = (TH1D*) histo[iCut][iSample]->Clone("num_DATA_Sig");
      num_DATA_Sig_Rebinned = DynamicalRebinHisto(num_DATA_Sig,num_DATA_Sig_Rebinned,Bin_Extremes, isDATA, isDivide);
      
      num_DATA_Sig_Rebinned->SetMarkerColor(kBlack);
      num_DATA_Sig_Rebinned->SetLineColor(kBlack);
      num_DATA_Sig_Rebinned->SetFillColor(kWhite);
      num_DATA_Sig_Rebinned->SetMarkerStyle(20);
      
      isDATA = false;
     }
     
     ///---- for MC subtraction ----
     if(reduced_name_samples.at(iSample) == "VV" || reduced_name_samples.at(iSample) == "VV-DY-Fake" || reduced_name_samples.at(iSample) == "VV-DY-Fake-CR") { 
      A_VV_CR = (TH1D*) histo[iCut][iSample]->Clone("A_VV_CR");
      A_VV_CR_Rebinned = DynamicalRebinHisto(A_VV_CR,A_VV_CR_Rebinned,Bin_Extremes,isDATA, false);
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
 
 if(iCut == 3+6*PlusCut ) {
    
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
  
//   TLegend * legend = makeLegend(*stack[iCut],nameSamples);
  
  ///=== Efficiency VBF Region 
  EfficiencyHisto[iCut]= (TH1D*) num_SR_Rebinned->Clone("EfficiencyHisto");
  EfficiencyHisto[iCut]->Divide(den_SR_Rebinned);
  
  stack_Rebinned[iCut] = DynamicalRebinStack(stack[iCut],stack_Rebinned[iCut],Bin_Extremes,isDATA,isDivide);
  stack_Rebinned[iCut+1] = DynamicalRebinStack(stack[iCut+1],stack_Rebinned[iCut],Bin_Extremes,isDATA,isDivide);
  
  TH1D* num_ttbar_SR, *den_ttbar_SR, *den_top_SR, *num_top_SR,* num_DATA_SR, *den_DATA_SR;
  TH1D * num_ttbar_SR_Rebinned, * den_ttbar_SR_Rebinned, * num_top_SR_Rebinned, * den_top_SR_Rebinned, * num_DATA_SR_Rebinned, * den_DATA_SR_Rebinned;
  bool done = false;
  
  for(int iSample=0;iSample<reduced_name_samples.size(); iSample++) {     
   for (int iNameToJoin = 0; iNameToJoin < nameSamplesToJoin.size(); iNameToJoin++){
    if (reduced_name_samples.at(iSample) == nameSamplesToJoin.at(iNameToJoin)) { 
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
   
    
    if(reduced_name_samples.at(iSample) == "DATA") { 
    isDATA = true;
    
    num_DATA_SR = (TH1D*)histo[iCut+1][iSample]->Clone("num_DATA_SR");
//     num_DATA_SR_Rebinned = DynamicalRebinHisto(num_DATA_SR,num_DATA_SR_Rebinned,Bin_Extremes,isDATA, isDivide);
    
    den_DATA_SR = (TH1D*)histo[iCut][iSample]->Clone("den_DATA_SR");
//     den_DATA_SR_Rebinned = DynamicalRebinHisto(den_DATA_SR,den_DATA_SR_Rebinned,Bin_Extremes, isDATA, isDivide);
//     
//     num_DATA_SR_Rebinned->SetMarkerColor(kBlack);
//     num_DATA_SR_Rebinned->SetLineColor(kBlack);
//     num_DATA_SR_Rebinned->SetFillColor(kWhite);
//     num_DATA_SR_Rebinned->SetMarkerStyle(20);
//     
//     den_DATA_SR_Rebinned->SetMarkerColor(kBlack);
//     den_DATA_SR_Rebinned->SetFillColor(kWhite);
//     den_DATA_SR_Rebinned->SetLineColor(kBlack);
//     den_DATA_SR_Rebinned->SetMarkerStyle(20);
    
    isDATA = false;
    
   }
   
   
   ///---- for MC subtraction ----
   if (reduced_name_samples.at(iSample) == "VV" || reduced_name_samples.at(iSample) == "VV-DY-Fake" || reduced_name_samples.at(iSample) == "VV-DY-Fake-SR") { 
//     std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
//     std::cout << " ~~~~~ VV in SR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
//     std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
    
    B_VV_SR = (TH1D*) histo[iCut+1][iSample]->Clone("B_VV_SR");
    B_VV_SR_Rebinned = DynamicalRebinHisto(B_VV_SR,B_VV_SR_Rebinned,Bin_Extremes,isDATA, false);
    
    AB_VV_SR = (TH1D*) histo[iCut][iSample]->Clone("AB_VV_SR");
    AB_VV_SR_Rebinned = DynamicalRebinHisto(AB_VV_SR,AB_VV_SR_Rebinned,Bin_Extremes,isDATA, false);
    
    A_VV_SR = (TH1D*) histo[iCut+2][iSample]->Clone("A_VV_SR");
    A_VV_SR_Rebinned = DynamicalRebinHisto(A_VV_SR,AB_VV_SR_Rebinned,Bin_Extremes,isDATA, false);

    
//     std::cout << "  B_VV_SR->GetEntries() = " <<  B_VV_SR->GetEntries() << std::endl;
//     std::cout << " AB_VV_SR->GetEntries() = " << AB_VV_SR->GetEntries() << std::endl;
    
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
  
  eff_DATA[iCut] = new TEfficiency(*num_DATA_SR_Rebinned,*den_DATA_SR_Rebinned); //---- ma questa non serve a nulla!
  eff_DATA[iCut]->Bayesian(den_DATA_SR->GetEntries(),num_DATA_SR_Rebinned->GetEntries(),0.95,1,1,false,true);
  
 }
 
 ///================
 ///==== SR - A ====
 if(iCut == 5+6*PlusCut) { //---- A SR
    
    TH1D * num_SR_Sig = (TH1D*)stack[iCut]->GetStack()->Last();
    TH1D * num_SR_Sig_Rebinned;
    num_SR_Sig_Rebinned = DynamicalRebinHisto(num_SR_Sig,num_SR_Sig_Rebinned,Bin_Extremes,isDATA,isDivide);
    
    num_SR_Sig_Rebinned->SetFillStyle(3335);
    num_SR_Sig_Rebinned->SetFillColor(kBlack);
    
//     TLegend * legend= makeLegend(*stack[iCut],nameSamples);
    
    stack_Rebinned[iCut] = DynamicalRebinStack(stack[iCut],stack_Rebinned[iCut],Bin_Extremes,isDATA,isDivide);
    
    TH1D* num_DATA_SR_Sig, *num_DATA_SR_Sig_Rebinned, *num_ttbar_Sig,*num_ttbar_Sig_Rebinned,*num_top_Sig,*num_top_Sig_Rebinned;
    TH1D* den_ttbar_Sig, *den_ttbar_Sig_Rebinned, *den_top_Sig, *den_top_Sig_Rebinned;
    TH1D* temp_hist_all, *temp_hist_all_rebinned;
    bool done = false;
    
    for(int iSample=0; iSample<reduced_name_samples.size(); iSample++) {
     for (int iNameToJoin = 0; iNameToJoin < nameSamplesToJoin.size(); iNameToJoin++){
      if (reduced_name_samples.at(iSample) == nameSamplesToJoin.at(iNameToJoin)) { 
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
       if (reduced_name_samples.at(iSample) != "DATA") {
	
	if (reduced_name_samples.at(iSample) != "qqH" && reduced_name_samples.at(iSample) != "ggH"  && reduced_name_samples.at(iSample) != "Latinos12"  && reduced_name_samples.at(iSample) != "HWW") {
	 if (!SR_AB_Zone_all_NoHiggs) {
	  temp_hist_all = (TH1D*) histo[iCut][iSample]->Clone("num_all_Sig"); 
	  SR_AB_Zone_all_NoHiggs = DynamicalRebinHisto( temp_hist_all, SR_AB_Zone_all_NoHiggs, Bin_Extremes, isDATA, isDivide);
	 }
	 else {
	  TString histo_name = Form ("%s_%d_%d_Tot_temp_my_tt_NoHiggs", reduced_name_samples.at(iSample).c_str(), iCut, 0);
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
	 TString histo_name = Form ("%s_%d_%d_Tot_temp_my_tt", reduced_name_samples.at(iSample).c_str(), iCut, 0);
	 temp_hist_all = (TH1D*) histo[iCut][iSample]->Clone(); //(histo_name.Data()); 
	temp_hist_all_rebinned = DynamicalRebinHisto( temp_hist_all, temp_hist_all_rebinned, Bin_Extremes, isDATA, isDivide);
	SR_AB_Zone_all->Add(temp_hist_all_rebinned);
	}
       }
      }
     }
     
     if (reduced_name_samples.at(iSample) == "DATA") {
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
 TH1D *SR_Other_B_Zone;
 TH1D *SR_DATA_B_Zone;
 TH1D *SR_DATA_A_Zone;
 TGraphAsymmErrors* SR_A_Zone_Estimation;
 TGraphAsymmErrors* SR_A_Zone_Estimation_allBackgrounds;
 TGraphAsymmErrors* SR_A_Zone_Estimation_allBackgrounds_NoHiggs;
 
 TH1D *SR_AB_Zone_tt;
 TH1D *SR_DATA_AB_Zone;
 
  
  bool isDivide = true;
  
  for(int iCut=0; iCut<Cuts.size(); iCut++) {
   if(iCut == 0+6*PlusCut) {
    ///==== Efficiency on DATA in the Efficiency region
    Efficiency_Control_Zone = (TEfficiency*) eff_DATA[iCut]->Clone("Efficiency_Control_Zone");
   }
   
   ///===== Distribution of data in the Btag Zone (Control Region)  after the VBF selections
   
   if (iCut == 4+6*PlusCut) {
    TH1D* Temp_Other = 0;
    
    for(int iSample=0; iSample<reduced_name_samples.size(); iSample++) {
     if(reduced_name_samples.at(iSample)=="DATA") {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample]->Clone("Temp");
      SR_DATA_B_Zone = DynamicalRebinHisto(Temp,SR_DATA_B_Zone,Bin_Extremes, true, isDivide);
      Temp->Delete();
     }
     else if (reduced_name_samples.at(iSample) == "top" ) {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp2"); 
      SR_B_Zone_tt =  DynamicalRebinHisto(Temp,SR_B_Zone_tt,   Bin_Extremes, false, isDivide);
      Temp->Delete();
     }
     else if (reduced_name_samples.at(iSample) != "qqH" && reduced_name_samples.at(iSample) != "Latinos12" && reduced_name_samples.at(iSample) != "ggH" && reduced_name_samples.at(iSample) != "HWW" && reduced_name_samples.at(iSample) != "All") {
      //       std::cout << " reduced_name_samples.at(" << iSample << ") = " << reduced_name_samples.at(iSample) << std::endl;
      if (!Temp_Other) { 
       Temp_Other = (TH1D*) histo[iCut][iSample] -> Clone("Temp3"); 
      }
      else {
       TH1D* Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp3");        
       Temp_Other -> Add (Temp);
      }
     }
    }
    
    if (Temp_Other) {
     SR_Other_B_Zone = DynamicalRebinHisto(Temp_Other,SR_Other_B_Zone,Bin_Extremes, false, isDivide);
    }
   }
   
   ///==== Distribution of DATA in the A zone Signal Region  (SR) [begin] ====   
   if (iCut == 5+6*PlusCut) {
    for (int iSample=0; iSample<reduced_name_samples.size(); iSample++) {
     if (reduced_name_samples.at(iSample) == "DATA") {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp"); 
      SR_DATA_A_Zone = DynamicalRebinHisto(Temp,SR_DATA_A_Zone,Bin_Extremes, true,  isDivide);
      Temp->Delete();
     }
     
     if (reduced_name_samples.at(iSample) == "top" ) {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp2"); 
      SR_A_Zone_tt =  DynamicalRebinHisto(Temp,SR_A_Zone_tt,   Bin_Extremes, false, isDivide);
      Temp->Delete();
     } 

    } 
   }
   ///==== Distribution for DATA in the A zone Signal Region  (SR) [end] ====
   
   ///==== Distribution for DATA in the AB zone Signal Region  (SR) [begin] ====   
   if (iCut == 3+6*PlusCut) {
    for (int iSample=0; iSample<reduced_name_samples.size(); iSample++) {
     if (reduced_name_samples.at(iSample) == "DATA") {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp"); 
      SR_DATA_AB_Zone = DynamicalRebinHisto(Temp,SR_DATA_AB_Zone,Bin_Extremes, true,  isDivide);
      Temp->Delete();
     }
     
     if (reduced_name_samples.at(iSample) == "top" ) {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iSample] -> Clone("Temp2"); 
      SR_AB_Zone_tt =  DynamicalRebinHisto(Temp,SR_AB_Zone_tt,   Bin_Extremes, false, isDivide);
      Temp->Delete();
     } 
     
    } 
   }
   ///==== Distribution for DATA in the AB zone Signal Region  (SR) [end] ====
   
  }
  
  ///==== Final Data driven estimation in the signal region for each Variable
  
  

  
  
  std::cout << "***********************************************************" << std::endl;
  std::cout << "******************** CORRECT ******************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  
  double MC_ScaleFactor_up   = 0;
  double MC_ScaleFactor_low  = 0;
  double MC_ScaleFactor_mean = 0;
  
  double MC_numABfromB_up   = 0;
  double MC_numABfromB_low  = 0;
  double MC_numABfromB_mean = 0;
  double MC_err_numABfromB_mean = 0;
  
  double MC_numAfromB_up   = 0;
  double MC_numAfromB_low  = 0;
  double MC_numAfromB_mean = 0;
  
  
  
  
  double ScaleFactor_up   = 0;
  double ScaleFactor_low  = 0;
  double ScaleFactor_mean = 0;
  
  double numABfromB_up   = 0;
  double numABfromB_low  = 0;
  double numABfromB_mean = 0;
  double err_numABfromB_mean = 0;
  double err_numABfromB_mean_fromMCsubtraction = 0;
  
  double numABMC = 0;                     //--- only over the \eta threshold
  double errnumABMC = 0;
  double numABMCandOverThreshold = 0;     //--- over and under the threshold, the whole \eta spectrum
  double errnumABMCandOverThreshold = 0;  //--- over and under the threshold, the whole \eta spectrum
  double numABMCOnlyOverThreshold = 0;    //--- actually, it is only A since \eta>2.5
  double errnumABMCOnlyOverThreshold = 0; //--- actually, it is only A since \eta>2.5
  
  
  
  double numAfromB_up   = 0;
  double numAfromB_low  = 0;
  double numAfromB_mean = 0;
  
  double diffEffMC = 0;
  
  double numB_DATA = 0;
  double numB_DATA_VV_Subtracted = 0;
  
  ///---- events in A from MC ----
  double numAMC = 0;
  double errnumAMC = 0;
  if (SR_DATA_A_Zone!=0 && SR_DATA_B_Zone!=0 && Efficiency_Control_Zone!=0) { 
   for(int iBin=0; iBin<SR_A_Zone_tt->GetNbinsX(); iBin++) { 
    numAMC += SR_A_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;  //---- the whole \eta range!!!
   }
  }
  
  
  
  ///---- inference ... 
  
  if (SR_DATA_A_Zone!=0 && SR_DATA_B_Zone!=0 && Efficiency_Control_Zone!=0) { 
   
   for(int iBin=0; iBin<SR_DATA_B_Zone->GetNbinsX(); iBin++) { 
    
    if (SR_DATA_B_Zone->GetBinCenter(iBin+1) < 2.5) {
     double eff_low, eff_up, eff_mean;
     double value_low, value_up, value_mean;
     //----        NUM * (1-eff)/eff        ----
     eff_mean = Efficiency_Control_Zone->GetEfficiency(iBin+1);
     eff_low  = eff_mean - Efficiency_Control_Zone->GetEfficiencyErrorLow(iBin+1);
     eff_up   = eff_mean + Efficiency_Control_Zone->GetEfficiencyErrorUp(iBin+1);
     
     ///---- subtraction of VV MC predictions ----     
     value_mean = eff_mean!=0  ?  1. / eff_mean * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     value_up   = eff_up!=0    ?  1. / eff_up   * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     value_low  = eff_low!=0   ?  1. / eff_low  * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     
     std::cout << " [" << iBin << "] :: value_mean = " << value_mean << " = 1. / " << eff_mean << " * (" << SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << " - " << B_VV_SR_Rebinned->GetBinContent(iBin+1) << " )" << std::endl;     
     
     numABfromB_up   += value_up  ;
     numABfromB_low  += value_low ;
     numABfromB_mean += value_mean;

     numAfromB_up   = numAfromB_up   + value_up   - (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1));
     numAfromB_low  = numAfromB_low  + value_low  - (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1));
     numAfromB_mean = numAfromB_mean + value_mean - (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1));
     
//      std::cout << " BDATA   [" << iBin << "] = "            << SR_DATA_B_Zone->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin));
//      std::cout << " ==>>     BMC (top) [" << iBin << "] = " << SR_B_Zone_tt->GetBinContent(iBin+1)     * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin));
//      std::cout << " :: BMC (other) = "                      << SR_Other_B_Zone->GetBinContent(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << std::endl;
//      std::cout << " :: BMC ( VV )  = "                      << B_VV_SR->GetBinContent(iBin+1)          << std::endl;
//      std::cout <<                                                                                                              "                 ==>>    ABMC (top) [" << iBin << "] = " << SR_AB_Zone_tt->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << std::endl;
//      std::cout << " eff_mean[" << iBin << "] = " << eff_mean << " --- (" << eff_low << "," << eff_up << ")  ---> MC@SR :: " << EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) << " ---> MC@CR :: " << EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1) << std::endl;
//      std::cout << " -->  value_up  @A [" << iBin << "] += " << value_up  << std::endl;
//      std::cout << " -->  value_low @A [" << iBin << "] += " << value_low << std::endl;
     
     std::cout << " BDATA   [" << iBin << "] = "            << SR_DATA_B_Zone->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin))    << std::endl;  
     std::cout << " B-top   [" << iBin << "] = "            << SR_B_Zone_tt->GetBinContent(iBin+1)     * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin))    << std::endl;
     std::cout << " B-VV    [" << iBin << "] = "            << B_VV_SR_Rebinned->GetBinContent(iBin+1) << std::endl;
     
     std::cout << " eff_mean[" << iBin << "] = " << eff_mean << " --- (" << eff_low << "," << eff_up << ")  ---> MC@SR :: " << EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) << " ---> MC@CR :: " << EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1) << std::endl;
     
     std::cout << " ADATA   [" << iBin << "] = "            << SR_DATA_A_Zone->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin))    << std::endl;  
     std::cout << " A-top   [" << iBin << "] = "            << SR_A_Zone_tt->GetBinContent(iBin+1)     * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin))    << std::endl;
     std::cout << " A-ext   [" << iBin << "] = "            << value_mean - (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) << " = " << value_mean  << " - "  << " ( " << SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << " - " << B_VV_SR_Rebinned->GetBinContent(iBin+1) << " ) " << std::endl;
     std::cout << " A-VV    [" << iBin << "] = "            << A_VV_SR_Rebinned->GetBinContent(iBin+1) << std::endl;
     std::cout << std::endl;
     
     
     if (EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) ! =0) diffEffMC = diffEffMC + SR_B_Zone_tt->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * (EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) - EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1)) / EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) ;
     else if (EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1) != 0) diffEffMC = diffEffMC + SR_B_Zone_tt->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * (EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) - EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1)) / EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1) ;
     else  diffEffMC = diffEffMC + 0. ;      
     
     errnumABMC = sqrt (errnumABMC*errnumABMC + SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)));
     numABMC += (SR_AB_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1) - Bin_Extremes.at(iBin))) ;
     
     double temperr = eff_mean!=0  ?  1. / eff_mean * SR_DATA_B_Zone->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     err_numABfromB_mean = sqrt(err_numABfromB_mean*err_numABfromB_mean + temperr*temperr);
     
     temperr = eff_mean!=0  ?  1. / eff_mean * B_VV_SR_Rebinned->GetBinError(iBin+1) : 0;
     err_numABfromB_mean_fromMCsubtraction = sqrt(err_numABfromB_mean_fromMCsubtraction*err_numABfromB_mean_fromMCsubtraction + temperr*temperr);
     
     
     numB_DATA = numB_DATA + SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) ;
     
     ///---- number of data events in SR - B after VV subtraction
     numB_DATA_VV_Subtracted = numB_DATA_VV_Subtracted + SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1) ;
     
     
     ///---- with MC efficiency scaling (begin) ----
     if (EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) != 0) value_mean = eff_mean!=0  ?  1. / eff_mean * EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1)/EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     else value_mean = eff_mean!=0  ?  1. / eff_mean * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     if (EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) != 0) value_up   = eff_up!=0    ?  1. / eff_up   * EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1)/EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     else value_up   = eff_up!=0    ?  1. / eff_up   * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     if (EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) != 0) value_low  = eff_low!=0   ?  1. / eff_low  * EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1)/EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     else value_low  = eff_low!=0   ?  1. / eff_low  * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     
//      value_mean = eff_mean!=0  ?  1. / eff_mean * EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1)/EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
//      value_up   = eff_up!=0    ?  1. / eff_up   * EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1)/EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
//      value_low  = eff_low!=0   ?  1. / eff_low  * EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1)/EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) * (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) : 0;
     
     MC_numABfromB_up   += value_up  ;
     MC_numABfromB_low  += value_low ;
     MC_numABfromB_mean += value_mean;
     
     MC_numAfromB_up   = MC_numAfromB_up   + value_up   - (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1));
     MC_numAfromB_low  = MC_numAfromB_low  + value_low  - (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1));
     MC_numAfromB_mean = MC_numAfromB_mean + value_mean - (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1));
     
     double MC_temperr;
     
     if (EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) != 0) MC_temperr = eff_mean!=0  ?  1. / eff_mean * EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1)/EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) * SR_DATA_B_Zone->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     else  MC_temperr = eff_mean!=0  ?  1. / eff_mean * SR_DATA_B_Zone->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) : 0;
     
     MC_err_numABfromB_mean = sqrt(MC_err_numABfromB_mean*MC_err_numABfromB_mean + MC_temperr*MC_temperr);

     std::cout << " MC_numABfromB_mean = " << value_mean << " = " << "1. / " << eff_mean << " * " << EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1) << " / " << EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) << " * ( " << SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << " - " << B_VV_SR_Rebinned->GetBinContent(iBin+1) << " ) " << std::endl;
     if  ((SR_A_Zone_tt->GetBinContent(iBin+1)     * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin))) != 0) std::cout << " A-ext-(MC sub) /  A-top   [" << iBin << "] = "            << ( value_mean - (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) ) / (SR_A_Zone_tt->GetBinContent(iBin+1)     * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin))) << " = " << "(" <<  value_mean << " - ( " << SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << " - " << B_VV_SR_Rebinned->GetBinContent(iBin+1) << ") ) / (  " << SR_A_Zone_tt->GetBinContent(iBin+1)     * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << " ) " << std::endl;
     else                                                                                                   std::cout << " A-ext-(MC sub) /  A-top   [" << iBin << "] = "            << "NA"                                                                                                                                                                                                                                               << " = " << "(" <<  value_mean << " - ( " << SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << " - " << B_VV_SR_Rebinned->GetBinContent(iBin+1) << ") ) / (  " << SR_A_Zone_tt->GetBinContent(iBin+1)     * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) << " ) " << std::endl;
     
     
     std::cout << " MC_numAfromB_mean{" << "sum" << "} = " << MC_numAfromB_mean << std::endl;
     std::cout << " MC_numAfromB_mean{" << iBin << "} = " << value_mean - (SR_DATA_B_Zone->GetBinContent(iBin+1) * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) - B_VV_SR_Rebinned->GetBinContent(iBin+1)) << std::endl;
     std::cout << std::endl;
     std::cout << " ******************* " << std::endl;
     std::cout << std::endl;
     ///---- with MC efficiency scaling (end) ----
       
     errnumABMCandOverThreshold = sqrt (errnumABMCandOverThreshold*errnumABMCandOverThreshold + SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)));
     numABMCandOverThreshold   += (SR_AB_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1) - Bin_Extremes.at(iBin))) ;   
    }
    else { //---- eta > 2-5
     errnumABMCOnlyOverThreshold = sqrt (numABMCOnlyOverThreshold*numABMCOnlyOverThreshold + SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)));
     numABMCOnlyOverThreshold   += (SR_AB_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1) - Bin_Extremes.at(iBin))) ;   
    
     errnumABMCandOverThreshold = sqrt (numABMCandOverThreshold*numABMCandOverThreshold + SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)) * SR_AB_Zone_tt->GetBinError(iBin+1)  * (Bin_Extremes.at(iBin+1)-Bin_Extremes.at(iBin)));
     numABMCandOverThreshold   += (SR_AB_Zone_tt->GetBinContent(iBin+1)   * (Bin_Extremes.at(iBin+1) - Bin_Extremes.at(iBin))) ;   
    }
    
   }
  }
    
  std::cout << "***********************************************************" << std::endl;
  std::cout << "****************** MC prediction **************************" << std::endl;  
  std::cout << "  numAB (MC) also with eta>2.5        = " << numABMCandOverThreshold         << " +/- " << errnumABMCandOverThreshold << std::endl;
  std::cout << "  numAB (MC)         = " << numABMC         << " +/- " << errnumABMC << std::endl;
  std::cout << "  numABfromB (DATA)  = " << numABfromB_mean << " +/- " << (numABfromB_up-numABfromB_low)/2. << std::endl;
  std::cout << "  numABfromB (DATA) up  = " << numABfromB_up  << std::endl;
  std::cout << "  numABfromB (DATA) low = " << numABfromB_low << std::endl;
  
  ScaleFactor_up   = numABfromB_low  / numABMC;
  ScaleFactor_low  = numABfromB_up   / numABMC;
  ScaleFactor_mean = numABfromB_mean / numABMC;
  
//   std::cout << "  ScaleFactor_up   = " << ScaleFactor_up << std::endl;
//   std::cout << "  ScaleFactor_low  = " << ScaleFactor_low << std::endl;
//   std::cout << "  ScaleFactor_mean = " << ScaleFactor_mean << std::endl;
  
  
  double errStatFromB = 0;
  errStatFromB = err_numABfromB_mean / numABMC;
  
  
  
  
  double ScaleFactor_OverThreshold_up   = ScaleFactor_up;
  double ScaleFactor_OverThreshold_low  = ScaleFactor_low;
  double ScaleFactor_OverThreshold_mean = ScaleFactor_mean;
 
//   double Global_ScaleFactor_up   = numAfromB_up   / numAMC ;
//   double Global_ScaleFactor_low  = numAfromB_low  / numAMC ;
//   double Global_ScaleFactor_mean = numAfromB_mean / numAMC ;
    
  
  double Global_ScaleFactor_up   = 1;
  double Global_ScaleFactor_low  = 1;
  double Global_ScaleFactor_mean = 1;
  
  if (numAMC != 0) Global_ScaleFactor_up   = (numABMCOnlyOverThreshold * ScaleFactor_OverThreshold_up   + numAfromB_up  ) / numAMC;
  if (numAMC != 0) Global_ScaleFactor_low  = (numABMCOnlyOverThreshold * ScaleFactor_OverThreshold_low  + numAfromB_low ) / numAMC;
  if (numAMC != 0) Global_ScaleFactor_mean = (numABMCOnlyOverThreshold * ScaleFactor_OverThreshold_mean + numAfromB_mean) / numAMC;
  

  std::cout << "  Global ScaleFactor     = " << Global_ScaleFactor_mean << " +/- " << (Global_ScaleFactor_up-Global_ScaleFactor_low)/2. << std::endl;
  std::cout << "  Global ScaleFactor up  = " << Global_ScaleFactor_up   << std::endl;
  std::cout << "  Global ScaleFactor low = " << Global_ScaleFactor_low  << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << "  Global ScaleFactor     = " << Global_ScaleFactor_mean ;
  std::cout << " +/- " << (Global_ScaleFactor_up-Global_ScaleFactor_low)/2. << "(syst) +/- " ;
  std::cout << errStatFromB << " (stat) = ";
  std::cout << sqrt(errStatFromB*errStatFromB + (Global_ScaleFactor_up-Global_ScaleFactor_low)/2.*(Global_ScaleFactor_up-Global_ScaleFactor_low)/2.) << std::endl;
  std::cout << "  numB (DATA)       = " << numB_DATA           << " +/- " << sqrt(numB_DATA) << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  

  
  //---- for back-compatibility ----
  double SF     = Global_ScaleFactor_mean;
  double errSF  = sqrt(errStatFromB*errStatFromB + (Global_ScaleFactor_up-Global_ScaleFactor_low)/2.*(Global_ScaleFactor_up-Global_ScaleFactor_low)/2.);
  double SF_low = ScaleFactor_low;
  double SF_up  = ScaleFactor_up;
  
  std::cout << " numAMC      = " << numAMC      << std::endl;
  std::cout << " numAMC * SF = " << numAMC * SF << " +/- " << numAMC * errSF << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  
  if (numAMC != 0) std::cout << " Additional Systematics from MC variation of efficiency     = " << - diffEffMC/numAMC     << std::endl;
  else std::cout << " Additional Systematics from MC variation of efficiency     = " << -1     << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  
  
  
  ///---- with MC efficiency scaling (begin) ----
  double MC_errStatFromB = 0;
  MC_errStatFromB = MC_err_numABfromB_mean / numABMC;
  
  double MC_ScaleFactor_up   = MC_numABfromB_low  / numABMC;
  double MC_ScaleFactor_low  = MC_numABfromB_up   / numABMC;
  double MC_ScaleFactor_mean = MC_numABfromB_mean / numABMC;
   
  double MC_ScaleFactor_OverThreshold_up   = MC_ScaleFactor_up;
  double MC_ScaleFactor_OverThreshold_low  = MC_ScaleFactor_low;
  double MC_ScaleFactor_OverThreshold_mean = MC_ScaleFactor_mean;
  
  double MC_Global_ScaleFactor_up   = 1; 
  double MC_Global_ScaleFactor_low  = 1; 
  double MC_Global_ScaleFactor_mean = 1; 
  
  if (numAMC != 0) MC_Global_ScaleFactor_up   = (numABMCOnlyOverThreshold * MC_ScaleFactor_OverThreshold_up   + MC_numAfromB_up  ) / numAMC;
  if (numAMC != 0) MC_Global_ScaleFactor_low  = (numABMCOnlyOverThreshold * MC_ScaleFactor_OverThreshold_low  + MC_numAfromB_low ) / numAMC;
  if (numAMC != 0) MC_Global_ScaleFactor_mean = (numABMCOnlyOverThreshold * MC_ScaleFactor_OverThreshold_mean + MC_numAfromB_mean) / numAMC;
  
  double MC_SF     = MC_Global_ScaleFactor_mean;
  double MC_errSF  = sqrt(MC_errStatFromB*MC_errStatFromB + (MC_Global_ScaleFactor_up-MC_Global_ScaleFactor_low)/2.*(MC_Global_ScaleFactor_up-MC_Global_ScaleFactor_low)/2.);
  double MC_SF_low = MC_ScaleFactor_low;
  double MC_SF_up  = MC_ScaleFactor_up;
  
  std::cout << " MC_SF = " << MC_SF << std::endl;
  
  ///---- save for datacard ----///
  TString nameFileOut;
  
  nameFileOut = Form ("test/Latinos12/ttbar/result-all%s.txt",suffix.Data());
  std::cout << " writing in " << nameFileOut.Data() << " ... " << std::endl;
  std::ofstream myfileAll; 
  myfileAll.open (nameFileOut.Data(),std::fstream::app);
  myfileAll << std::setw (11) << numAMC * SF                << "  +/-  " ;
  myfileAll << std::setw (11) << numAMC * errSF             << "  ~ (stat) ~ " ;  
  myfileAll << std::setw (11) << numAMC * (SF_up-SF_low)/2. << "  ~~~  " ;
  myfileAll << std::setw (11) << numAMC * SF_low << " < " ;
  myfileAll << std::setw (11) << numAMC * SF_up  << " < " ;
  myfileAll << std::setw (5)  << " +/- " ;
  if (numAMC != 0 && SF != 0) myfileAll << std::setw (11) << diffEffMC/numAMC/SF*100  << " % (SR - CR) ---> " ;
  else myfileAll << std::setw (11) << -1  << " % (SR - CR) ---> " ;
  if (numAMC != 0 && SF != 0) myfileAll << std::setw (11) << numAMC * SF * (1. - diffEffMC/numAMC/SF) << "  +/-  " ;
  else  myfileAll << std::setw (11) << -1 << "  +/-  " ;
  if (numAMC != 0 && SF != 0) myfileAll << std::setw (11) << numAMC * (SF_up-SF_low)/2. * (1. - diffEffMC/numAMC/SF) << "  ~~~  " ;
  else  myfileAll << std::setw (11) << -1 << "  ~~~  " ;
  myfileAll << std::endl;
  myfileAll.close();
  
  
  nameFileOut = Form ("test/Latinos12/ttbar/result-SF%s.txt",suffix.Data());
  std::cout << " writing in " << nameFileOut.Data() << " ... " << std::endl;
  std::ofstream myfileScaleFactor; 
  myfileScaleFactor.open (nameFileOut.Data(),std::fstream::app);
  myfileScaleFactor << SF ;
  myfileScaleFactor << " +/- ";
  myfileScaleFactor << errSF;
  myfileScaleFactor << "    ";
  myfileScaleFactor << MC_SF ;
  myfileScaleFactor << " +/- ";
  myfileScaleFactor << MC_errSF;
  myfileScaleFactor << std::endl;
  
  myfileScaleFactor.close();
  
  nameFileOut = Form ("test/Latinos12/ttbar/result-value%s.txt",suffix.Data());
  std::cout << " writing in " << nameFileOut.Data() << " ... " << std::endl;
  std::ofstream myfileValue; 
  myfileValue.open (nameFileOut.Data(),std::fstream::app);
  //   NON CORREGGERE PER LA VARIAZIONE DI EFFICIENZA NEL MC -> ERRORRE NEL MC GRANDE????
  myfileValue << numAMC * MC_SF << std::endl;
  // anzi ora CORREGGILO dato che hai un MC con tanti eventi!!!
//   myfileValue << numAMC * SF << std::endl;
  
  myfileValue.close();
  
  std::cout << " numABMC = " << numABMC << std::endl;
  std::cout << " MC_errStatFromB = " << MC_errStatFromB << std::endl;
  std::cout << " MC_errSF = " << MC_errSF << std::endl;
  std::cout << " numAMC * MC_SF = " << numAMC * MC_SF << " +/- " << numAMC * MC_errSF << std::endl;
  std::cout << "***********************************************************" << std::endl;
  std::cout << "***********************************************************" << std::endl;
  
  nameFileOut = Form ("test/Latinos12/ttbar/result-syst-stat%s.txt",suffix.Data());
  std::cout << " writing in " << nameFileOut.Data() << " ... " << std::endl;
  std::ofstream myfileSystStat; 
  myfileSystStat.open (nameFileOut.Data(),std::fstream::app);
  //---- alpha factor : A/B
  std::cout << "(numAMC * MC_SF) / numB_DATA  = " << "(" << numAMC << " * " << MC_SF << ")" << " / " << numB_DATA << std::endl;
//   NON CORREGGERE PER LA VARIAZIONE DI EFFICIENZA NEL MC -> ERRORRE NEL MC GRANDE????
  if (numB_DATA!=0) myfileSystStat << (numAMC * MC_SF) / numB_DATA << std::endl;
    // anzi ora CORREGGILO dato che hai un MC con tanti eventi!!!
//   if (numB_DATA!=0) myfileSystStat << (numAMC * SF) / numB_DATA << std::endl;
  else myfileSystStat << 0 << std::endl;
  myfileSystStat.close();
  
  nameFileOut = Form ("test/Latinos12/ttbar/result-syst-method%s.txt",suffix.Data());
  std::cout << " writing in " << nameFileOut.Data() << " ... " << std::endl;
  std::ofstream myfileSystMethod; 
  myfileSystMethod.open (nameFileOut.Data(),std::fstream::app);
  std::cout << "(1. + fabs((MC_SF-SF)/(MC_SF)))  = " << "1. + fabs((" << MC_SF << " - " << SF << ")/(" << MC_SF << ")))" << std::endl;
  if (MC_SF != 0) myfileSystMethod << (1. + fabs((MC_SF-SF)/(MC_SF))) << std::endl;  
  else myfileSystMethod << 1.000 << std::endl;  //---- else no systematic error? HP: mc scaling not there
  myfileSystMethod.close();
  
  nameFileOut = Form ("test/Latinos12/ttbar/result-syst-CR-stat%s.txt",suffix.Data());
  std::cout << " writing in " << nameFileOut.Data() << " ... " << std::endl;
  std::ofstream myfileSystStatCR; 
  myfileSystStatCR.open (nameFileOut.Data(),std::fstream::app);
  //   NON CORREGGERE PER LA VARIAZIONE DI EFFICIENZA NEL MC -> ERRORRE NEL MC GRANDE????
  if (MC_SF != 0) myfileSystStatCR << (1. + fabs(MC_Global_ScaleFactor_up-MC_Global_ScaleFactor_low)/2./MC_SF) << std::endl;  
      // anzi ora CORREGGILO dato che hai un MC con tanti eventi!!!
//   if (SF != 0) myfileSystStatCR << (1. + fabs(Global_ScaleFactor_up-Global_ScaleFactor_low)/2./SF) << std::endl;

  else  myfileSystStatCR << -1 << std::endl;
  myfileSystStatCR.close();
  
   
  nameFileOut = Form ("test/Latinos12/ttbar/result-syst-MCSub%s.txt",suffix.Data());
  std::cout << " writing in " << nameFileOut.Data() << " ... " << std::endl;
  std::ofstream myfileSystMCSub; 
  myfileSystMCSub.open (nameFileOut.Data(),std::fstream::app);
  //   NON CORREGGERE PER LA VARIAZIONE DI EFFICIENZA NEL MC -> ERRORRE NEL MC GRANDE????
  if (MC_SF != 0 && numAMC != 0) myfileSystMCSub << (1. + fabs(err_numABfromB_mean_fromMCsubtraction/(numAMC * MC_SF))) << std::endl;
      // anzi ora CORREGGILO dato che hai un MC con tanti eventi!!!
//   if (SF != 0 && numAMC != 0) myfileSystMCSub << (1. + fabs(err_numABfromB_mean_fromMCsubtraction/(numAMC * SF))) << std::endl;
  else if (numABMCandOverThreshold != 0) myfileSystMCSub << (1. + fabs(err_numABfromB_mean_fromMCsubtraction/(numABMCandOverThreshold))) << std::endl; //---- estimation of the error?
  else  myfileSystMCSub << 1.000 << std::endl; //---- else NO error?
  myfileSystMCSub.close();
  
  
  
  
  TString nameForWP = Form ("test/Latinos12/ttbar/result-forNote-%d-%d%s.txt",iWP,PlusCut,suffix.Data());
  std::cout << "cat " << nameForWP.Data() << std::endl;
  std::ofstream myfileForNote; 
  myfileForNote.open (nameForWP.Data());  
  for(int iBin=0; iBin<SR_DATA_B_Zone->GetNbinsX(); iBin++) { 
   double eff_low, eff_up, eff_mean;
   eff_mean = Efficiency_Control_Zone->GetEfficiency(iBin+1);
   eff_low  = eff_mean - Efficiency_Control_Zone->GetEfficiencyErrorLow(iBin+1);
   eff_up   = eff_mean + Efficiency_Control_Zone->GetEfficiencyErrorUp(iBin+1);
   
   myfileForNote << std::setw (8) << Bin_Extremes.at(iBin)   << "  ";
   myfileForNote << std::setw (8) << Bin_Extremes.at(iBin+1) << "  ";
   myfileForNote << std::setw (8) << eff_mean << "  ";
   myfileForNote << std::setw (8) << fabs(eff_up-eff_low)/2. << "  ";
   myfileForNote << std::setw (8) << EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinContent(iBin+1) << "  ";  //---- SR
   myfileForNote << std::setw (8) << EfficiencyHisto_ttbar[3+6*PlusCut]->GetBinError(iBin+1) << "  ";  //---- SR
   myfileForNote << std::setw (8) << EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinContent(iBin+1) << "  ";  //---- CR 
   myfileForNote << std::setw (8) << EfficiencyHisto_ttbar[0+6*PlusCut]->GetBinError(iBin+1) << "  ";  //---- CR 
   myfileForNote << std::endl;
  } 
  myfileForNote.close();
  
  
  
  
  ///---- total systematics ----
  nameFileOut = Form ("test/Latinos12/ttbar/result-syst%s.txt",suffix.Data());
  std::cout << " writing in " << nameFileOut.Data() << " ... " << std::endl;
  std::ofstream myfileSyst; 
  myfileSyst.open (nameFileOut.Data(),std::fstream::app);
  double totalSyst = 0;
  //   NON CORREGGERE PER LA VARIAZIONE DI EFFICIENZA NEL MC -> ERRORRE NEL MC GRANDE????
  if (numAMC != 0 && MC_SF != 0) totalSyst = sqrt(totalSyst*totalSyst + err_numABfromB_mean_fromMCsubtraction/(numAMC * MC_SF) * err_numABfromB_mean_fromMCsubtraction/(numAMC * MC_SF));
  if (MC_SF != 0)                totalSyst = sqrt(totalSyst*totalSyst + MC_errSF/MC_SF * MC_errSF/MC_SF); //--- efficiency measurement in CR-A&B and statistics in SR-B
  if (MC_SF != 0)                totalSyst = sqrt(totalSyst*totalSyst + (MC_SF-SF)/(MC_SF) * (MC_SF-SF)/(MC_SF));    
      // anzi ora CORREGGILO dato che hai un MC con tanti eventi!!!
//   if (numAMC != 0 && SF != 0) totalSyst = sqrt(totalSyst*totalSyst + err_numABfromB_mean_fromMCsubtraction/(numAMC * SF) * err_numABfromB_mean_fromMCsubtraction/(numAMC * SF));
//   if (SF != 0)                totalSyst = sqrt(totalSyst*totalSyst + errSF/SF * MC_errSF/SF); //--- efficiency measurement in CR-A&B and statistics in SR-B
//   if (SF != 0)                totalSyst = sqrt(totalSyst*totalSyst + (MC_SF-SF)/(SF) * (MC_SF-SF)/(SF));    
  myfileSyst << (1. + totalSyst) << std::endl;
  myfileSyst.close();
    
  gApplication->Terminate(0);
 
}


