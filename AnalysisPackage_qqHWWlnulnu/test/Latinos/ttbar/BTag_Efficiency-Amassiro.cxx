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


///==== Macros input are: input file name, output file name, output dumper file

int BTag_Efficiency_Amassiro(TString input, TString output, TString dumper) {
 
 ///=== Open the input ROOT File from test/MCDATAComparisonPLOTTool.cpp
 
 TFile * Input_File = TFile::Open(input.Data());
 
 std::vector<std::string> nameSample;
 std::vector<std::string> nameSampleToJoin;
 std::vector<std::string> Cuts;
 std::vector<std::pair<std::string,int> > Variable;
 std::vector<std::string> nameHumanVariable;
 std::vector<std::vector<float> > Bin_Extremes;
 std::vector<float> row;
 
 ///===== Output ROOT file
 
 TFile  output_Plott(output.Data(),"RECREATE");
 output_Plott.cd();
 gStyle->SetOptStat(0);
 
 ///===== Dumper output file
 
 std::ofstream outFile(dumper.Data(),std::ios::out);
 
 ///===== Acquisition info from txt file: Name of the samples, Cut applied and Variables of Plot and their binning
 
 std::ifstream inFile("test/Latinos/ttbar/BTag_Efficiency.txt",ios::binary);
 std::string buffer;
 int Closure_Number;
 int flag=0, flag2=0;
 int iPoint=0;
 int iBin=0;
 std::string sample_temp;
 
 while(!inFile.eof())
 {
  getline(inFile,buffer);
  std::stringstream line( buffer );
  if (buffer == "[SampleNameToJoin]") continue;
  if (buffer == "[Cut]") flag = 1;
  if (buffer == "[Variables]") flag = 2;
  if (buffer == "[Number_Closure_Test]") flag = 3;
  
  if(flag==0 && buffer !="" && buffer!="[SampleNameToJoin]")
  {
   if (buffer.at(0)!='#')
   {
    line>>sample_temp;
    std::cout<< "Sample:" << "   " <<sample_temp<< std::endl;
    nameSampleToJoin.push_back(sample_temp); ///== vector with samples name according to the standard of MCDATAComparisonPLOTTool.cpp
   }
  }
  
  if(flag==1 && buffer!="" && buffer!="[Cut]")
  {
   if (buffer.at(0)!='#') {
    line>>sample_temp;
    Cuts.push_back(sample_temp); ///== Vector with the ID name for each cut applied   
   }
  }
  
  
  if(flag==2 && buffer!="" && buffer!="[Variables]" && flag2==1) ///== binning vector acquisition
  {
   if(buffer.at(0)!='#') { 
    if(buffer==sample_temp) continue;
    std::string strtemp;
    
    for(int iBuf=0; iBuf<buffer.size(); iBuf++) {  
     if(buffer.at(iBuf) != ' ') {
      strtemp = strtemp + buffer.at(iBuf);
     }
     else {
      float f =(float) atof(strtemp.c_str()); 
      row.push_back(f);
      strtemp.clear();
     }
    } 
   }
   
   ///=== Vector fill with the information for the binning applied for each variable                     
   Bin_Extremes.push_back(row);
   row.clear();
   flag2 = 0;
   continue;
  }
  
  if(flag==2 && buffer!="" && buffer!="[Variables]"&& flag2==0) ///=== Acquisition variable for effiency study
  {
   if (buffer.at(0)!='#') { 
    int k=0;
    std::pair<std::string,int> temp;
    sample_temp.clear();
    
    for(int iBuf=0; iBuf<buffer.size(); iBuf++)
    {
     if(buffer.at(iBuf)!=' ')
     {
      sample_temp = sample_temp + buffer.at(iBuf);
     }
     else{
      if(k==0){
       temp.first=sample_temp;
       temp.second=iPoint;
       k++;
       sample_temp.clear();
      }
     }
    }
    
    Variable.push_back(temp);
    
    nameHumanVariable.push_back(sample_temp);
    
    std::cout<< "Variable Used:" << "      " <<temp.first<< "    " << "Name Human Variable:" << "  " <<sample_temp<< std::endl;
    
    iPoint++;
    flag2 = 1;
    continue;
   }
  }
  
  if(flag==3 && buffer !="" && buffer!="[Number_Closure_Test]")
  {
   if (buffer.at(0)!='#')
   {
    line>>sample_temp;
    std::cout<< "Number Closure Test :" << "    " <<sample_temp<< std::endl;
    Closure_Number=(int) atoi(sample_temp.c_str());
   }
  }
  
  
 }
 
 ///=== Acquisition from the input file of the object: stack and histogramms 
 ///       [iCut][iVar][iSample]
 TH1D* histo [100][100][100];
 ///          [iCut][iVar]
 THStack* stack[100][100];
 
 for(int iCut=0; iCut<Cuts.size();iCut++) {  
  for(int iVar=0; iVar<Variable.size();iVar++) {   
   TString stack_name = Form ("Data/%d_%d_stack", iCut, iVar);
   stack[iCut][iVar] = (THStack*) Input_File->Get(stack_name);
   
   if (iCut == 0 && iVar == 0) {
    FillListOfName (*stack[iCut][iVar], &nameSample);
    nameSample.push_back("DATA");
   }
   
   for(int iSample = 0; iSample < nameSample.size(); iSample++) {    
    TString histo_name = Form ("Data/%s_%d_%d_Tot_temp", nameSample.at(iSample).c_str(), iCut, iVar);
    histo[iCut][iVar][iSample] = (TH1D*) Input_File->Get(histo_name);
//     std::cerr << " histo [iCut][iVar][iSample] = " << "[" << iCut << "][" << iVar << "][" << iSample << "] --> " << nameSample.at(iSample) << " ---> " << histo[iCut][iVar][iSample] << std::endl;
   }
  }
 }
 
 
 for (int iNameToJoin = 0; iNameToJoin < nameSampleToJoin.size(); iNameToJoin++){
  std::cout << " Joint [" << iNameToJoin << "::" << nameSampleToJoin.size() << "] = " << nameSampleToJoin.at(iNameToJoin) << std::endl;
 }
 
 
 ///=== Efficiency Evaluation
 
 ///              [iCut][iVar]
 TH1D* EfficiencyHisto[100][100];
 TH1D* EfficiencyHisto_ttbar[100][100];
 TH1D* PurityHisto[100][100];
 THStack* stack_Rebinned[100][100];
 TEfficiency* eff_DATA[100][100];
 ///                  [iVar]
 TH1D *SR_AB_Zone_all[100];
 TH1D *SR_AB_Zone_all_NoHiggs[100];
 TH1D *SR_AB_Zone_tt[100];
 
 TH1D *SR_A_Zone_tt[100];
 
 for(int iVar=0; iVar< Variable.size(); iVar++) { 
  
  for (int iEdge = 0; iEdge < Bin_Extremes[iVar].size(); iEdge++) {
   std::cout << " edge[" << iVar << "][" << iEdge << "] = " << Bin_Extremes[iVar].at(iEdge) << std::endl;
  }
  
  ///==== Variable selection ====
  
//   if( Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(abs(q1_Eta))+(abs(q1_Eta)>=abs(q2_Eta))*(abs(q2_Eta))" && 
//       Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(q1_pT)+(abs(q1_Eta)>=abs(q2_Eta))*(q2_pT)")
//    continue;

  ///============================
  
  output_Plott.cd();
  TDirectory* cdAll = (TDirectory*) output_Plott.mkdir(nameHumanVariable.at(iVar).c_str());
  TDirectory* cdEff = cdAll->mkdir("Efficiency_Study");
  cdEff -> mkdir ("SR");
  cdEff -> mkdir ("CR");
  
  cdAll->mkdir("Closure_Test");
 
  TString way = Form("%s/Efficiency_Study",nameHumanVariable.at(iVar).c_str());
  output_Plott.cd(way);
  
  for(int iCut=0; iCut<Cuts.size(); iCut++) {  
   bool isDATA = false;
   bool isDivide = true;
   
   ///==== Efficiency analysis in the control region 
   
   if(Cuts.at(iCut) == "Control_Region" && Cuts.at(iCut+1) == "Control_Region_Btag") {
    /// Check for the right pair of cuts
    TH1D * num = (TH1D*) stack[iCut+1][iVar]->GetStack()->Last();
    TH1D * num_Rebinned; 
    num_Rebinned = DynamicalRebinHisto(num,num_Rebinned,Bin_Extremes[iVar],isDATA, isDivide); ///== Dynamical Rebin of the Histogram with the new binning defined in Bin_Extremes[iVar],
    num_Rebinned->SetFillStyle(3335);
    num_Rebinned->SetFillColor(kBlack);
    ///=== isData is a bool variable that indicates if we work on data sample, isDivide if we want to divide the bin content for the bin width
    ///=== For the implementation See PlotUtils.c
   
    TH1D * den = (TH1D*) stack[iCut][iVar]->GetStack()->Last();
    TH1D * den_Rebinned;
    
    den_Rebinned = DynamicalRebinHisto(den,den_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
    den_Rebinned->SetFillStyle(3335);
    den_Rebinned->SetFillColor(kBlack);
    
    TLegend * legend = makeLegend(*stack[iCut][iVar],nameSample); ///=== See PlotUtils.C
    
    ///==== Total Efficiency Distriubution for each Cut and Variables
    
    EfficiencyHisto[iCut][iVar] = (TH1D*) num_Rebinned->Clone("EfficiencyHisto");
    EfficiencyHisto[iCut][iVar] -> Divide(den_Rebinned);
    
    ///==== Dynamical rebin for the stack, see PlotUtils.C
    
    stack_Rebinned[iCut][iVar]   = DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
    stack_Rebinned[iCut+1][iVar] = DynamicalRebinStack(stack[iCut+1][iVar],stack_Rebinned[iCut+1][iVar],Bin_Extremes[iVar],isDATA,isDivide);
    
    ///==== Efficiency on top and DATA samples
    
    TH1D* num_ttbar, *den_ttbar, *num_top, *den_top,*num_DATA, *den_DATA;
    TH1D * num_ttbar_Rebinned, * den_ttbar_Rebinned,* num_top_Rebinned, * den_top_Rebinned, * num_DATA_Rebinned, * den_DATA_Rebinned;
    bool done;
    for(int iSample=0; iSample<nameSample.size(); iSample++) {     
     for (int iNameToJoin = 0; iNameToJoin < nameSampleToJoin.size(); iNameToJoin++){
      if (nameSample.at(iSample) == nameSampleToJoin.at(iNameToJoin)) { 
//        if (!num_ttbar) {
       if (!done) {
	done = true;
	num_ttbar = (TH1D*) histo[iCut+1][iVar][iSample]->Clone("num_ttbar");
	num_ttbar_Rebinned = DynamicalRebinHisto(num_ttbar,num_ttbar_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
	
	den_ttbar = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_ttbar");
	den_ttbar_Rebinned = DynamicalRebinHisto(den_ttbar,den_ttbar_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);	
       } 
       else {
	num_top = (TH1D*)histo[iCut+1][iVar][iSample]->Clone("num_top");
	num_top_Rebinned = DynamicalRebinHisto(num_top,num_top_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	den_top = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_top");
	den_top_Rebinned = DynamicalRebinHisto(den_top,den_top_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	num_ttbar_Rebinned->Add(num_top_Rebinned);
	den_ttbar_Rebinned->Add(den_top_Rebinned);
       }
      }
     }
     
     if(nameSample.at(iSample) == "DATA") { 
      isDATA = true;
      
      num_DATA = (TH1D*) histo[iCut+1][iVar][iSample]->Clone("num_DATA");
      num_DATA_Rebinned = DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
      
      den_DATA = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_DATA");
      den_DATA_Rebinned = DynamicalRebinHisto(den_DATA,den_DATA_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
      
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
    }
    /// top background Effciency
    
    EfficiencyHisto_ttbar[iCut][iVar] = (TH1D*) num_ttbar_Rebinned->Clone("EfficiencyHisto_ttbar");	
    EfficiencyHisto_ttbar[iCut][iVar] -> Divide(den_ttbar_Rebinned);
    
    ///==== Purity Distribution in the total and Btag Control Region
    
    PurityHisto[iCut+1][iVar] = (TH1D*) num_ttbar_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut+1][iVar] -> Divide(num_Rebinned);
    
    PurityHisto[iCut][iVar] = (TH1D*) den_ttbar_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut][iVar] -> Divide(den_Rebinned);
    
    num_DATA_Rebinned = DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes[iVar],true,false);
    den_DATA_Rebinned = DynamicalRebinHisto(den_DATA,den_DATA_Rebinned,Bin_Extremes[iVar],true,false);
    
    eff_DATA[iCut][iVar] = new TEfficiency(*num_DATA_Rebinned,*den_DATA_Rebinned);
    eff_DATA[iCut][iVar]->Bayesian(den_DATA->GetEntries(),num_DATA->GetEntries(),0.68,1,1,false,true);
    eff_DATA[iCut][iVar]->SetMarkerColor(kBlack);
    eff_DATA[iCut][iVar]->SetLineColor(kBlack);
    eff_DATA[iCut][iVar]->SetLineWidth(2);
    
   }
   
   std::cerr << " >> Cuts.at(" << iCut << ") = " << Cuts.at(iCut) << std::endl;
   
   if(Cuts.at(iCut) == "Control_Region_noBtag") {
    ///=== no btag part of the efficiency region               
    TH1D * num_Sig = (TH1D*) stack[iCut][iVar]->GetStack()->Last();
    TH1D * num_Sig_Rebinned;
    
    num_Sig_Rebinned = DynamicalRebinHisto(num_Sig,num_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
    
    num_Sig_Rebinned->SetFillStyle(3335);
    num_Sig_Rebinned->SetFillColor(kBlack);
    
    TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample);
    
    stack_Rebinned[iCut][iVar] = DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar], isDATA, isDivide);
    
    TH1D* num_DATA_Sig, *num_DATA_Sig_Rebinned; 
    TH1D* num_ttbar_Sig,*num_ttbar_Sig_Rebinned, *num_top_Sig, *num_top_Sig_Rebinned;
    bool done = false;
    for(int iSample=0;iSample<nameSample.size(); iSample++) {
     
     for (int iNameToJoin = 0; iNameToJoin < nameSampleToJoin.size(); iNameToJoin++){
      if (nameSample.at(iSample) == nameSampleToJoin.at(iNameToJoin)) { 
       //        if (!num_ttbar_Sig) {
	if (!done) {
	 done = true;
	 num_ttbar_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_ttbar_Sig");
	 num_ttbar_Sig_Rebinned = DynamicalRebinHisto(num_ttbar_Sig,num_ttbar_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
	} 
       else {
	num_top_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_top_Sig");
	num_top_Sig_Rebinned = DynamicalRebinHisto(num_top_Sig,num_top_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	num_ttbar_Sig_Rebinned->Add(num_top_Sig_Rebinned);
       }
      }
     }
       
       if(nameSample.at(iSample)=="DATA") { 
	isDATA = true;
	
	num_DATA_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_DATA_Sig");
	num_DATA_Sig_Rebinned = DynamicalRebinHisto(num_DATA_Sig,num_DATA_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	num_DATA_Sig_Rebinned->SetMarkerColor(kBlack);
	num_DATA_Sig_Rebinned->SetLineColor(kBlack);
	num_DATA_Sig_Rebinned->SetFillColor(kWhite);
	num_DATA_Sig_Rebinned->SetMarkerStyle(20);
	
	isDATA = false;
       }
      }
      
    ///==== Purity Even
    PurityHisto[iCut][iVar] = (TH1D*) num_ttbar_Sig_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut][iVar]->Divide(num_Sig_Rebinned);
    
    
   }
      
   ///=== Efficiency and purity after VBF selections 
   ///=================
   ///==== SR - AB ====
   ///=================
   ///==== SR - B =====
   
   if(Cuts.at(iCut) == "Signal_Region" && Cuts.at(iCut+1)=="Signal_Region_Btag") {
    
    TString waySR = Form("%s/Efficiency_Study/SR",nameHumanVariable.at(iVar).c_str());
    output_Plott.cd(waySR);
    
    TH1D * num_SR = (TH1D*) stack[iCut+1][iVar]->GetStack()->Last();
    TH1D * num_SR_Rebinned;
    num_SR_Rebinned = DynamicalRebinHisto(num_SR,num_SR_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
    
    num_SR_Rebinned->SetFillStyle(3335);
    num_SR_Rebinned->SetFillColor(kBlack);
    
    TH1D * den_SR = (TH1D*) stack[iCut][iVar]->GetStack()->Last();
    TH1D * den_SR_Rebinned;
    den_SR_Rebinned = DynamicalRebinHisto(den_SR,den_SR_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
    
    den_SR_Rebinned->SetFillStyle(3335);
    den_SR_Rebinned->SetFillColor(kBlack);
    
    TLegend * legend = makeLegend(*stack[iCut][iVar],nameSample);
    
    ///=== Efficiency VBF Region 
    EfficiencyHisto[iCut][iVar]= (TH1D*) num_SR_Rebinned->Clone("EfficiencyHisto");
    EfficiencyHisto[iCut][iVar]->Divide(den_SR_Rebinned);
    
    stack_Rebinned[iCut][iVar]=DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
    stack_Rebinned[iCut+1][iVar]=DynamicalRebinStack(stack[iCut+1][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
    
    TH1D* num_ttbar_SR, *den_ttbar_SR, *den_top_SR, *num_top_SR,* num_DATA_SR, *den_DATA_SR;
    TH1D * num_ttbar_SR_Rebinned, * den_ttbar_SR_Rebinned, * num_top_SR_Rebinned, * den_top_SR_Rebinned, * num_DATA_SR_Rebinned, * den_DATA_SR_Rebinned;
    bool done = false;
    
    for(int iSample=0;iSample<nameSample.size(); iSample++) {     
     for (int iNameToJoin = 0; iNameToJoin < nameSampleToJoin.size(); iNameToJoin++){
      if (nameSample.at(iSample) == nameSampleToJoin.at(iNameToJoin)) { 
       //        if (!num_ttbar_SR) {
	if (!done) {
	done = true;
	num_ttbar_SR = (TH1D*) histo[iCut+1][iVar][iSample]->Clone("num_ttbar_SR");
	num_ttbar_SR_Rebinned = DynamicalRebinHisto(num_ttbar_SR,num_ttbar_SR_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	den_ttbar_SR = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_ttbar_SR");
	den_ttbar_SR_Rebinned = DynamicalRebinHisto(den_ttbar_SR,den_ttbar_SR_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
       } 
       else {
	num_top_SR = (TH1D*)histo[iCut+1][iVar][iSample]->Clone("num_top_SR");
	num_top_SR_Rebinned = DynamicalRebinHisto(num_top_SR,num_top_SR_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	den_top_SR = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_top");
	den_top_SR_Rebinned = DynamicalRebinHisto(den_top_SR,den_top_SR_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	num_ttbar_SR_Rebinned->Add(num_top_SR_Rebinned);
	den_ttbar_SR_Rebinned->Add(den_top_SR_Rebinned);
       }
      }
     }
     
     if(nameSample.at(iSample) == "DATA") { 
      isDATA=true;
      
      num_DATA_SR = (TH1D*)histo[iCut+1][iVar][iSample]->Clone("num_DATA_SR");
      num_DATA_SR_Rebinned=DynamicalRebinHisto(num_DATA_SR,num_DATA_SR_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
      
      den_DATA_SR = (TH1D*)histo[iCut][iVar][iSample]->Clone("den_DATA_SR");
      den_DATA_SR_Rebinned = DynamicalRebinHisto(den_DATA_SR,den_DATA_SR_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
      
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
    
    EfficiencyHisto_ttbar[iCut][iVar]= (TH1D*) num_ttbar_SR_Rebinned->Clone("EfficiencyHisto_ttbar_SR");
    EfficiencyHisto_ttbar[iCut][iVar]->Divide(den_ttbar_SR_Rebinned);
    
    ///=== Purity Distributions
    
    PurityHisto[iCut+1][iVar]= (TH1D*) num_ttbar_SR_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut+1][iVar]->Divide(num_SR_Rebinned);
    
    PurityHisto[iCut][iVar]= (TH1D*) den_ttbar_SR_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut][iVar]->Divide(den_SR_Rebinned);
    
    
    num_DATA_SR_Rebinned=DynamicalRebinHisto(num_DATA_SR,num_DATA_SR_Rebinned,Bin_Extremes[iVar],true,false);
    den_DATA_SR_Rebinned=DynamicalRebinHisto(den_DATA_SR,den_DATA_SR_Rebinned,Bin_Extremes[iVar],true,false);
    
    eff_DATA[iCut][iVar]= new TEfficiency(*num_DATA_SR_Rebinned,*den_DATA_SR_Rebinned);
    eff_DATA[iCut][iVar]->Bayesian(den_DATA_SR->GetEntries(),num_DATA_SR_Rebinned->GetEntries(),0.95,1,1,false,true);
    
    
   }
   
   ///================
   ///==== SR - A ====
   if(Cuts.at(iCut) == "Signal_Region_Signal") {
    
    TH1D * num_SR_Sig = (TH1D*)stack[iCut][iVar]->GetStack()->Last();
    TH1D * num_SR_Sig_Rebinned;
    num_SR_Sig_Rebinned = DynamicalRebinHisto(num_SR_Sig,num_SR_Sig_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
    
    num_SR_Sig_Rebinned->SetFillStyle(3335);
    num_SR_Sig_Rebinned->SetFillColor(kBlack);
    
    TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample);
    
    stack_Rebinned[iCut][iVar] = DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
    
    TH1D* num_DATA_SR_Sig, *num_DATA_SR_Sig_Rebinned, *num_ttbar_Sig,*num_ttbar_Sig_Rebinned,*num_top_Sig,*num_top_Sig_Rebinned;
    TH1D* den_ttbar_Sig, *den_ttbar_Sig_Rebinned, *den_top_Sig, *den_top_Sig_Rebinned;
    TH1D* temp_hist_all, *temp_hist_all_rebinned;
    bool done = false;
    
    for(int iSample=0; iSample<nameSample.size(); iSample++) {
     for (int iNameToJoin = 0; iNameToJoin < nameSampleToJoin.size(); iNameToJoin++){
      if (nameSample.at(iSample) == nameSampleToJoin.at(iNameToJoin)) { 
//        if (!num_ttbar_Sig) {
      if (!done) {
       done = true;
	num_ttbar_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_ttbar_Sig");
	num_ttbar_Sig_Rebinned = DynamicalRebinHisto(num_ttbar_Sig,num_ttbar_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
	
	den_ttbar_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_ttbar_Sig");
	den_ttbar_Sig_Rebinned = DynamicalRebinHisto(den_ttbar_Sig,den_ttbar_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
       }
       else {
	num_top_Sig = (TH1D*)histo[iCut][iVar][iSample]->Clone("num_top_Sig");
	num_top_Sig_Rebinned = DynamicalRebinHisto(num_top_Sig,num_top_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	den_top_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_top_Sig");
	den_top_Sig_Rebinned = DynamicalRebinHisto(den_top_Sig,den_top_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	num_ttbar_Sig_Rebinned->Add(num_top_Sig_Rebinned);
	den_ttbar_Sig_Rebinned->Add(den_top_Sig_Rebinned);
       }
      }
      else {
       if (nameSample.at(iSample) != "DATA") {
	
	if (nameSample.at(iSample) != "qqH" && nameSample.at(iSample) != "ggH") {
	 if (!SR_AB_Zone_all_NoHiggs[iVar]) {
	  temp_hist_all = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_all_Sig"); 
	  SR_AB_Zone_all_NoHiggs[iVar] = DynamicalRebinHisto( temp_hist_all, SR_AB_Zone_all_NoHiggs[iVar], Bin_Extremes[iVar], isDATA, isDivide);
	 }
	 else {
	  TString histo_name = Form ("%s_%d_%d_Tot_temp_my_tt_NoHiggs", nameSample.at(iSample).c_str(), iCut, iVar);
	  temp_hist_all = (TH1D*) histo[iCut][iVar][iSample]->Clone(); //(histo_name.Data()); 
	  temp_hist_all_rebinned = DynamicalRebinHisto( temp_hist_all, temp_hist_all_rebinned, Bin_Extremes[iVar], isDATA, isDivide);
	  SR_AB_Zone_all_NoHiggs[iVar]->Add(temp_hist_all_rebinned);
	 }
	}
	
	if (!SR_AB_Zone_all[iVar]) {
	 temp_hist_all = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_all_Sig"); 
	 SR_AB_Zone_all[iVar] = DynamicalRebinHisto( temp_hist_all, SR_AB_Zone_all[iVar], Bin_Extremes[iVar], isDATA, isDivide);
	}
	else {
	 TString histo_name = Form ("%s_%d_%d_Tot_temp_my_tt", nameSample.at(iSample).c_str(), iCut, iVar);
	 temp_hist_all = (TH1D*) histo[iCut][iVar][iSample]->Clone(); //(histo_name.Data()); 
	 temp_hist_all_rebinned = DynamicalRebinHisto( temp_hist_all, temp_hist_all_rebinned, Bin_Extremes[iVar], isDATA, isDivide);
	 SR_AB_Zone_all[iVar]->Add(temp_hist_all_rebinned);
	}
       }
      }
     }
          
     if(nameSample.at(iSample)=="DATA") {
      isDATA = true;
      
      num_DATA_SR_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_DATA_SR_Sig");
      num_DATA_SR_Sig_Rebinned = DynamicalRebinHisto(num_DATA_SR_Sig,num_DATA_SR_Sig_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
      
      isDATA = false;
     } 
    }
    
    std::cerr << " [iCut][iVar] ->  [" << iCut << "][" << iVar << "]" << std::endl;
    
    ///==== Purity Distribution
    
    PurityHisto[iCut][iVar]= (TH1D*) num_ttbar_Sig_Rebinned->Clone("PurityHisto");
    PurityHisto[iCut][iVar]->Divide(num_SR_Sig_Rebinned);
    
    SR_AB_Zone_tt[iVar] = (TH1D*) den_ttbar_Sig_Rebinned->Clone();
    
   }
   
   
  } //---- end loop cut
 } //---- end loop var
 
 std::cerr << " *** Final *** " << std::endl;
 
 ///===== Final Plot for Efficiency Comparison and DATA Driven Estimation
 
 ///                            [iVar]
 TEfficiency* Efficiency_Control_Zone[100];
 TH1D *SR_B_Zone[100];
 TH1D *SR_DATA_A_Zone[100];
 TGraphAsymmErrors* SR_A_Zone_Estimation[100];
 TGraphAsymmErrors* SR_A_Zone_Estimation_allBackgrounds[100];
 TGraphAsymmErrors* SR_A_Zone_Estimation_allBackgrounds_NoHiggs[100];
 
 
 for(int iVar=0; iVar<Variable.size(); iVar++) {
  
  TString way = Form("%s/Efficiency_Study",nameHumanVariable.at(iVar).c_str());
  output_Plott.cd(way);
  
  bool isDivide = true;
  
  for(int iCut=0; iCut<Cuts.size(); iCut++) {
   if(Cuts.at(iCut) == "Control_Region" && Cuts.at(iCut+1) == "Control_Region_Btag" ) {
    ///==== Efficiency on DATA in the Efficiency region
    Efficiency_Control_Zone[iVar] = (TEfficiency*) eff_DATA[iCut][iVar]->Clone("Efficiency_Control_Zone");
   }
   
   if(Cuts.at(iCut) == "Signal_Region")
   {
   }
   
   ///===== Distribution of data in the Btag Zone (Control Region)  after the VBF selections
   
   if (Cuts.at(iCut) == "Signal_Region_Btag") {
    for(int iSample=0; iSample<nameSample.size(); iSample++) {
     if(nameSample.at(iSample)!="DATA") continue;
     
     TH1D* Temp;
     Temp = (TH1D*) histo[iCut][iVar][iSample]->Clone("Temp");
     
     SR_B_Zone[iVar] = DynamicalRebinHisto(Temp,SR_B_Zone[iVar],Bin_Extremes.at(iVar), true, isDivide);
     Temp->Delete();
     
    }
   }
   
   ///==== Distribution fo DATA in the A zone Signal Region  (SR) [begin] ====   
   if (Cuts.at(iCut) == "Signal_Region_Signal") {
    for(int iSample=0; iSample<nameSample.size(); iSample++) {
     if (nameSample.at(iSample)=="DATA") {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iVar][iSample] -> Clone("Temp"); 
      SR_DATA_A_Zone[iVar] = DynamicalRebinHisto(Temp,SR_DATA_A_Zone[iVar],Bin_Extremes.at(iVar), true,  isDivide);
      Temp->Delete();
     }
     
     if (nameSample.at(iSample) == "top" ) {
      TH1D* Temp;
      Temp = (TH1D*) histo[iCut][iVar][iSample] -> Clone("Temp2"); 
      SR_A_Zone_tt[iVar] =  DynamicalRebinHisto(Temp,SR_A_Zone_tt[iVar],   Bin_Extremes.at(iVar), false, isDivide);
      Temp->Delete();
     } 
     
    } 
   }
   ///==== Distribution fo DATA in the A zone Signal Region  (SR) [end] ====
   
   
  }
  
  ///==== Final Data driven estimation in the signal region for each Variable
  
  if (SR_DATA_A_Zone[iVar]!=0 && SR_B_Zone[iVar]!=0 && Efficiency_Control_Zone[iVar]!=0) { 
   
   SR_A_Zone_Estimation[iVar] = new TGraphAsymmErrors(SR_DATA_A_Zone[iVar]);
   
   for(int iBin=0; iBin<SR_DATA_A_Zone[iVar]->GetNbinsX(); iBin++) { 
// // //     if (Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0) { ///=== Estimation is possible if and only if the efficiency is not null
// // //        SR_A_Zone_Estimation[iVar] -> SetPoint(iBin,SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1),SR_B_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))));
// // //        if (SR_B_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))-abs((1/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*sqrt(((Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1))*(Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1))*((SR_B_Zone[iVar]->GetBinContent(iBin+1)*SR_B_Zone[iVar]->GetBinContent(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)*Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))+SR_B_Zone[iVar]->GetBinError(iBin+1)*SR_B_Zone[iVar]->GetBinError(iBin+1)*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))))>=0) { 
// // // // 	std::cout << " iBin = " << iBin << " --> primo " << std::endl;
// // //         ///=== Errors are evaluated through the propagation formula
// // //          
// // //        double value_low, value_high, value_mean;
// // //        double error_low, error_high;
// // //        double eff_low, eff_up;
// // //        //----        NUM * (1-eff)/eff        ----
// // //        eff_mean = Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1);
// // //        eff_low  = eff_mean - Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1);
// // //        eff_up   = eff_mean + Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1);
// // //        
// // //        value_mean = (1.-eff_mean)/eff_mean * SR_B_Zone[iVar]->GetBinContent(iBin+1);
// // //        value_low  = (1.-eff_up)  /eff_up   * SR_B_Zone[iVar]->GetBinContent(iBin+1);
// // //        
// // //        error_low = sqrt( (value_mean - value_low)*(value_mean - value_low) + (1.-eff_mean)/eff_mean*(1.-eff_mean)/eff_mean*SR_B_Zone[iVar]->GetBinError(iBin+1)*SR_B_Zone[iVar]->GetBinError(iBin+1) );
// // //        error_up  = sqrt( (value_mean - value_up )*(value_mean - value_up ) + (1.-eff_mean)/eff_mean*(1.-eff_mean)/eff_mean*SR_B_Zone[iVar]->GetBinError(iBin+1)*SR_B_Zone[iVar]->GetBinError(iBin+1) );
// // //        
// // // 
// // //         SR_A_Zone_Estimation[iVar]->SetPointError(iBin,
// // //            SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,
// // //            SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,
// // // 	   error_low,
// // //            error_up
// // // //            (1./(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))) * sqrt(((Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1))*(Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1))*((SR_B_Zone[iVar]->GetBinContent(iBin+1)*SR_B_Zone[iVar]->GetBinContent(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)*Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))+SR_B_Zone[iVar]->GetBinError(iBin+1)*SR_B_Zone[iVar]->GetBinError(iBin+1)*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))),
// // // //            (1./(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))) * sqrt(((Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1))*(Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1))*((SR_B_Zone[iVar]->GetBinContent(iBin+1)*SR_B_Zone[iVar]->GetBinContent(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)*Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))+SR_B_Zone[iVar]->GetBinError(iBin+1)*SR_B_Zone[iVar]->GetBinError(iBin+1)*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))))
// // // 	);
// // //        }
// // //        else {
// // // // 	std::cout << " iBin = " << iBin << " --> secondo " << std::endl;
// // // 	SR_A_Zone_Estimation[iVar]->SetPointError(
// // // 	 iBin,
// // // 	 SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,
// // //          SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,
// // // // 	 SR_B_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))),
// // // //          (1/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))) * sqrt(((Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1))*(Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1))*((SR_B_Zone[iVar]->GetBinContent(iBin+1)*SR_B_Zone[iVar]->GetBinContent(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)*Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))+SR_B_Zone[iVar]->GetBinError(iBin+1)*SR_B_Zone[iVar]->GetBinError(iBin+1)*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))))
// // //          SR_B_Zone[iVar]->GetBinContent(iBin+1)/Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) / Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) * (Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1)),
// // //          SR_B_Zone[iVar]->GetBinContent(iBin+1)/Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) / Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) * (Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1))
// // // 	);
// // //        }
// // //    }
// // //    else {
// // //     SR_A_Zone_Estimation[iVar]->SetPoint(iBin,SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1),0);
// // //     SR_A_Zone_Estimation[iVar]->SetPointError(iBin,SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,0,0);
// // //    }
// // //    

	///=== Errors are evaluated through the propagation formula
	double value_low, value_up, value_mean;
	double error_low, error_up;
	double eff_low, eff_up, eff_mean;
	//----        NUM * (1-eff)/eff        ----
	eff_mean = Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1);
	eff_low  = eff_mean - Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1);
	eff_up   = eff_mean + Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1);
	
	value_mean = eff_mean ? (1.-eff_mean)/eff_mean * SR_B_Zone[iVar]->GetBinContent(iBin+1) : 0;
	value_low  = eff_up   ? (1.-eff_up)  /eff_up   * SR_B_Zone[iVar]->GetBinContent(iBin+1) : 0;
	value_up   = eff_low  ? (1.-eff_low) /eff_low  * SR_B_Zone[iVar]->GetBinContent(iBin+1) : 0;
	
	double err_stat = eff_mean ? (1.-eff_mean)/eff_mean*SR_B_Zone[iVar]->GetBinError(iBin+1) : 0;
	
	error_low = sqrt( (value_mean - value_low)*(value_mean - value_low) + err_stat*err_stat );
	error_up  = sqrt( (value_mean - value_up )*(value_mean - value_up ) + err_stat*err_stat );
	
	///---- correction for negative values!
// 	if (value_mean - error_low < 0 ) error_low = value_mean;
	
// 	if (SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1) < 2.5) { 
	 SR_A_Zone_Estimation[iVar] -> SetPoint(iBin,SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1),value_mean);
	 double half_binWidth = SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2.;
	 SR_A_Zone_Estimation[iVar] -> SetPointError(iBin,half_binWidth,half_binWidth,error_low,error_up);     
// 	}
// 	else {
// 	 	 SR_A_Zone_Estimation[iVar] -> SetPoint(iBin,SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1),0);
	 // 	 double half_binWidth = SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2.;
	 // 	 SR_A_Zone_Estimation[iVar] -> SetPointError(iBin,half_binWidth,half_binWidth,0,0);     
// 	}
	
// 	SR_A_Zone_Estimation[iVar] -> SetPoint(iBin,SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1),value_mean);
// 	double half_binWidth = SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2.;
// 	SR_A_Zone_Estimation[iVar] -> SetPointError(iBin,half_binWidth,half_binWidth,error_low,error_up);     
	
// 	std::cout << " value_mean = " << value_mean << " === error_low = " << error_low << " === error_up = " << error_up <<  std::endl;
   }
   
   SR_A_Zone_Estimation_allBackgrounds_NoHiggs[iVar] = new TGraphAsymmErrors(SR_DATA_A_Zone[iVar]);
   for(int iBin=0; iBin<SR_DATA_A_Zone[iVar]->GetNbinsX(); iBin++) { 
    SR_A_Zone_Estimation_allBackgrounds_NoHiggs[iVar] -> SetPoint(iBin,SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1),SR_AB_Zone_all_NoHiggs[iVar]->GetBinContent(iBin+1) + (!(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)) ? 0 : SR_B_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))));
    double err1 = SR_AB_Zone_all_NoHiggs[iVar]->GetBinContent(iBin+1);
    double err2low = !(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)) ? 0 : SR_B_Zone[iVar]->GetBinContent(iBin+1)/Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) / Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) * (Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1));
    double err2up  = !(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)) ? 0 : SR_B_Zone[iVar]->GetBinContent(iBin+1)/Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) / Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) * (Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1));
    
    SR_A_Zone_Estimation_allBackgrounds_NoHiggs[iVar]->SetPointError(
     iBin,
     SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,
     SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,
     sqrt(err1 * err1 + err2low * err2low),
     sqrt(err1 * err1 + err2up  * err2up)         
    );
   }
   
   
   SR_A_Zone_Estimation_allBackgrounds[iVar] = new TGraphAsymmErrors(SR_DATA_A_Zone[iVar]);
   for(int iBin=0; iBin<SR_DATA_A_Zone[iVar]->GetNbinsX(); iBin++) { 
    SR_A_Zone_Estimation_allBackgrounds[iVar] -> SetPoint(iBin,SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1),SR_AB_Zone_all[iVar]->GetBinContent(iBin+1) + (!(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)) ? 0 : SR_B_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))));
    double err1 = SR_AB_Zone_all[iVar]->GetBinContent(iBin+1);
    double err2low = !(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)) ? 0 : SR_B_Zone[iVar]->GetBinContent(iBin+1)/Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) / Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) * (Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1));
    double err2up  = !(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)) ? 0 : SR_B_Zone[iVar]->GetBinContent(iBin+1)/Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) / Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1) * (Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1));
    
    SR_A_Zone_Estimation_allBackgrounds[iVar]->SetPointError(
     iBin,
     SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,
     SR_DATA_A_Zone[iVar]->GetBinWidth(iBin+1)/2,
     sqrt(err1 * err1 + err2low * err2low),
     sqrt(err1 * err1 + err2up  * err2up)         
    );
    
    std::cerr << " iBin = " << iBin << ":" << SR_DATA_A_Zone[iVar]->GetNbinsX() << " --> Data = " << SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1) << " ==> MC + DD = " << SR_AB_Zone_all[iVar]->GetBinContent(iBin+1) << " + " << (!(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)) ? 0 : SR_B_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))) << std::endl;
   }
  }
  
 }
 
 ///==== Information dumper in an external File
 
 std::string edge;
 std::string error;
 
 for(int iVar=0; iVar<Variable.size(); iVar++) {
  
  bool isDATA = false;
  bool isDivide = false; //---> in this way I do NOT have to multiply later for bin-width
  
  double alfa = 0, beta = 0;
  double err_alfa = 0, err_beta = 0;
  double ratio = 0;
  double err_ratio = 0;

  
  double tt_Events_MC = 0;
  double tt_Events_DD_up   = 0;
  double tt_Events_DD_down = 0;
  double tt_Events_DD_mean = 0;
  
  std::cout << std::endl;
  
  for(int iBin=0; iBin<SR_A_Zone_Estimation[iVar]->GetMaxSize(); iBin++) {   ///==== cicle on bin (begin)
   if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0  && SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1) < 2.5) { 
    
    tt_Events_MC = tt_Events_MC + SR_A_Zone_tt[iVar]->GetBinContent(iBin+1) * (Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin));
    
    tt_Events_DD_mean = tt_Events_DD_mean + SR_B_Zone[iVar]->GetBinContent(iBin+1) * ((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)) / (Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))) * (Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin));
    
    double tempX, tempY;
    int err = SR_A_Zone_Estimation[iVar]->GetPoint(iBin,tempX, tempY);
    
    tt_Events_DD_up   = tt_Events_DD_up   + (tempY + SR_A_Zone_Estimation[iVar]->GetErrorYhigh(iBin)) * (Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin));
    tt_Events_DD_down = tt_Events_DD_down + (tempY - SR_A_Zone_Estimation[iVar]->GetErrorYlow(iBin) ) * (Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin));
    
    std::cout << " tt_Events_DD_mean >> " << tt_Events_DD_mean << std::endl;
   }
   
   if(nameHumanVariable.at(iVar) == "|#eta|^{CJet}") {
    if (SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1) < 2.5) {
     alfa     = alfa + SR_A_Zone_tt[iVar]->GetBinContent(iBin+1);
     err_alfa = sqrt( err_alfa * err_alfa  +  SR_A_Zone_tt[iVar]->GetBinError(iBin+1) * SR_A_Zone_tt[iVar]->GetBinError(iBin+1));
    }
    if (SR_DATA_A_Zone[iVar]->GetBinCenter(iBin+1) >= 2.5) {
     beta = beta + SR_A_Zone_tt[iVar]->GetBinContent(iBin+1);
     err_beta = sqrt(err_beta*err_beta+SR_A_Zone_tt[iVar]->GetBinError(iBin+1)*SR_A_Zone_tt[iVar]->GetBinError(iBin+1));
    }
   }
   
   
   
  } ///==== cicle on bin (end)
  
  
  if (nameHumanVariable.at(iVar) == "|#eta|^{CJet}") {
   ratio = (alfa+beta) / (alfa);
   err_ratio = sqrt ( (1/(alfa*alfa)) * (err_beta*err_beta) + (beta/(alfa*alfa)) * (beta/(alfa*alfa)) * (err_alfa*err_alfa) );
   outFile << alfa  << "   " << err_alfa  << std::endl;
   outFile << beta  << "   " << err_beta  << std::endl;
   outFile << ratio << "   " << err_ratio << std::endl;
  }
  
  
  
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "*******************************************************" << std::endl;
  std::cout << "*******************************************************" << std::endl;
  std::cout << "*******************************************************" << std::endl;  
  std::cout << " >>> input <<< " << std::endl;
  std::cout << " WorkingPoint = " << input << std::endl;
  std::cout << std::endl;
  std::cout << " >>> result <<< " << std::endl;
  std::cout << " N       = " << tt_Events_DD_mean << " +/- " << (tt_Events_DD_up - tt_Events_DD_down) / 2.  << " -->  " << 1. + (tt_Events_DD_up - tt_Events_DD_down) / tt_Events_DD_mean << std::endl; 
  std::cout << " N (ave) = " << (tt_Events_DD_up + tt_Events_DD_down) / 2. << " +/- " << (tt_Events_DD_up - tt_Events_DD_down) / 2.  << " -->  " << 1. + (tt_Events_DD_up - tt_Events_DD_down) / (tt_Events_DD_up + tt_Events_DD_down) << std::endl; 
  std::cout << " N       [" << tt_Events_DD_down << " :: " << tt_Events_DD_up << "] " << std::endl; 
//   std::cout << " N (dc)  = " << (tt_Events_DD_up + tt_Events_DD_down) / 2. << " -->  " << 1. + (tt_Events_DD_up - tt_Events_DD_down) / (tt_Events_DD_up + tt_Events_DD_down) << std::endl; 
  if (tt_Events_DD_down < 0) {
   std::cout << "***************************************************************************" << std::endl;
   std::cout << "****************** corrected for negative values **************************" << std::endl;  
   std::cout << " N (ave) = " << (tt_Events_DD_up + 0) / 2. << " +/- " << (tt_Events_DD_up - 0) / 2.  << " -->  " << 1. + (tt_Events_DD_up - 0) / (tt_Events_DD_up + 0) << std::endl; 
   std::cout << " N       [" << 0 << " :: " << tt_Events_DD_up << "] " << std::endl; 
  }
  std::cout << "***********************************************************" << std::endl;
  std::cout << "****************** MC prediction **************************" << std::endl;  
  std::cout << "  N (MC)  = " << tt_Events_MC << " --> Scale factor = " << tt_Events_DD_mean / tt_Events_MC << std::endl;
  std::cout << "  N (MC)  = " << tt_Events_MC << " --> Scale factor = " << (tt_Events_DD_up + tt_Events_DD_down)/2. / tt_Events_MC << std::endl;
  if (tt_Events_DD_down < 0) { 
   std::cout << "  N (MC)  = " << tt_Events_MC << " --> Scale factor = " << (tt_Events_DD_up + 0.)/2. / tt_Events_MC << std::endl;
  }
  std::cout << "*******************************************************" << std::endl;
  std::cout << "*******************************************************" << std::endl;
  std::cout << "*******************************************************" << std::endl;  
  std::cout << "  alpha  = " << alfa  << " +/- " << err_alfa  << std::endl;
  std::cout << "  beta   = " << beta  << " +/- " << err_beta  << std::endl;
  std::cout << "  ratio  = " << ratio << " +/- " << err_ratio << std::endl;  
  std::cout << "*******************************************************" << std::endl;
  std::cout << "*******************************************************" << std::endl;
  std::cout << "*******************************************************" << std::endl;  
  std::cout << " >>> result <<< " << std::endl;
  std::cout << " N       = " << ratio * tt_Events_DD_mean << " +/- " << ratio * (tt_Events_DD_up - tt_Events_DD_down) / 2.  << " -->  " << 1. + (tt_Events_DD_up - tt_Events_DD_down) / 2. / tt_Events_DD_mean << std::endl; 
  std::cout << " N (ave) = " << ratio * (tt_Events_DD_up + tt_Events_DD_down) / 2. << " +/- " << ratio * (tt_Events_DD_up - tt_Events_DD_down) / 2.  << " -->  " << 1. + (tt_Events_DD_up - tt_Events_DD_down) / (tt_Events_DD_up + tt_Events_DD_down) << std::endl; 
  std::cout << " N       [" << ratio * tt_Events_DD_down << " :: " << ratio * tt_Events_DD_up << "] " << std::endl; 
//   std::cout << " N (dc)  = " << ratio * (tt_Events_DD_up + tt_Events_DD_down) / 2. << " -->  " << 1. + (tt_Events_DD_up - tt_Events_DD_down) / (tt_Events_DD_up + tt_Events_DD_down) << std::endl; 
  if (tt_Events_DD_down < 0) {
   std::cout << "***************************************************************************" << std::endl;
   std::cout << "****************** corrected for negative values **************************" << std::endl;  
   std::cout << " N (ave) = " << ratio * (tt_Events_DD_up + 0) / 2. << " +/- " << ratio * (tt_Events_DD_up - 0) / 2.  << " -->  " << 1. + (tt_Events_DD_up - 0) / (tt_Events_DD_up + 0) << std::endl;  
   std::cout << " N       [" << 0 << " :: " << ratio * tt_Events_DD_up << "] " << std::endl; 
  }
  std::cout << "***********************************************************" << std::endl;
  std::cout << "****************** MC prediction **************************" << std::endl;  
  std::cout << "  N (MC)  = " << tt_Events_MC << " --> Scale factor       = " << ratio * tt_Events_DD_mean / tt_Events_MC  << " +/- " << ratio * (tt_Events_DD_up - tt_Events_DD_down) / 2. / tt_Events_MC << std::endl;
  std::cout << "  N (MC)  = " << tt_Events_MC << " --> Scale factor (ave) = " << ratio * (tt_Events_DD_up + tt_Events_DD_down)/2. / tt_Events_MC  << " +/- " << ratio * (tt_Events_DD_up - tt_Events_DD_down) / 2. / tt_Events_MC << std::endl;
  if (tt_Events_DD_down < 0) { 
   std::cout << "  N (MC)  = " << tt_Events_MC << " --> Scale factor (<0)  = " << ratio * (tt_Events_DD_up + 0.)/2. / tt_Events_MC << " +/- " << ratio * (tt_Events_DD_up - 0) / 2. / tt_Events_MC << std::endl;
  }
  std::cout << "*******************************************************" << std::endl;
  std::cout << "*******************************************************" << std::endl;
  std::cout << "*******************************************************" << std::endl;  
  std::cout << std::endl;
 
  
  ///---- save for datacard ----///
  
  std::ofstream myfileValue; 
  myfileValue.open ("test/Latinos/ttbar/result-value.txt",std::fstream::app);
  myfileValue << (ratio * tt_Events_DD_mean) << std::endl;
  myfileValue.close();
  
  std::ofstream myfileSyst; 
  myfileSyst.open ("test/Latinos/ttbar/result-syst.txt",std::fstream::app);
  myfileSyst << (1. + (tt_Events_DD_up - tt_Events_DD_down) / 2. / tt_Events_DD_mean) << std::endl;
  myfileSyst.close();
  
  
  std::ofstream myfileAll; 
  myfileAll.open ("test/Latinos/ttbar/result-all.txt",std::fstream::app);
  myfileAll << (ratio * tt_Events_DD_mean) << "    " ;
  myfileAll << tt_Events_DD_down << " < " ;
  myfileAll << tt_Events_DD_mean << " < " ;
  myfileAll << tt_Events_DD_up << "   " ;
  myfileAll << (1. + (tt_Events_DD_up - tt_Events_DD_down) / 2. / tt_Events_DD_mean) << std::endl;
  myfileAll.close();
  
  
  
 }
 
 
 gApplication->Terminate(0);
 
}


