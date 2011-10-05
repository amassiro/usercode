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
#include "TH2D.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TPaveStats.h"
#include "TText.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "test/TDRStyle.cc"
#include "test/Read.cc"
#include "test/Latinos/ttbar/plotUtils.C"


int Efficiency_vs_Cut(TString input, TString output, TString selectionsFile)
{
 
 ///===== Vector of Color used in the Plot
 
 EColor vColor[1000] = {
  kGreen,
  //kMagenta,(EColor) (kMagenta+1),(EColor) (kMagenta+2),
  kTeal,//(EColor) (kTeal+1),
  kRed,
  kGray,
  kOrange,(EColor) (kOrange+1),
  kBlue,//(EColor)(kBlue+1),(EColor) (kBlue+2),
  (EColor) (kPink+2),//(EColor) (kPink+1),(EColor) (kPink+2),
  kViolet,
  kGreen,
  kAzure,
  //   kWhite,16\6
  kTeal,
  kYellow,
  (EColor) (kTeal+1),
  (EColor) (kOrange+2),
  (EColor) (kGreen+2),
  kGray,(EColor) (kGray+1),(EColor) (kViolet),(EColor) (kYellow)
 };
 
 ///=== Open the input ROOT File from MCDATAComparisonPLOTTool.cpp
 
 TFile * Input_File = TFile::Open(input.Data());
 
 
 ///===== Output ROOT file
 
 TFile  output_Plott(output.Data(),"RECREATE");
 output_Plott.cd();
 gStyle->SetOptStat(0);
 
 
 ///===== Acuisition info from txt file: Name of the samples, Cut applied and Variables of Plot and their binning "Efficiency_vs_Cut.txt"
 
 std::vector<std::string> nameSample;
 std::vector<std::string> nameSampleToJoin;
 std::vector<std::string> Cuts;
 std::vector<std::string> HumanCuts;
 std::vector<std::pair<std::string,int> > Variable;
 std::vector<std::string> nameHumanVariable;
 std::vector<std::vector<float> > Bin_Extremes;
 std::vector<float> row;
 
 std::ifstream inFile(selectionsFile.Data(),ios::binary);
 std::string buffer;
 int flag=0, flag2=0;
 int iPoint=0;
 int iBin=0;
 std::string sample_temp;
 
 while(!inFile.eof()) {
  getline(inFile,buffer);
  std::stringstream line( buffer );
  if(buffer =="[SampleNameToJoin]") continue;
  if (buffer=="[Cut]") flag=1;
  if(buffer=="[Variables]") flag=2;
  
  if(flag==0 && buffer !=""&& buffer!="[SampleNameToJoin]") {
   if (buffer.at(0)!='#') {
    line>>sample_temp;
    nameSampleToJoin.push_back(sample_temp);
//     nameSample.push_back(sample_temp);
    std::cout<<"[Name Sample]:  "<<sample_temp<<std::endl;
   }
  }
  
  if(flag==1 && buffer!=""&& buffer!="[Cut]") {
   if (buffer.at(0)!='#') {
    line >> sample_temp; 
    Cuts.push_back(sample_temp);
    line >> sample_temp;
    HumanCuts.push_back(sample_temp);
   }
  }
  
  
  if(flag==2 && buffer!="" && buffer!="[Variables]" && flag2==1) {
   if(buffer.at(0)!='#') { 
    if(buffer==sample_temp) continue;
    std::string strtemp;
    for(int iBuf=0; iBuf<buffer.size(); iBuf++) {  
     if(buffer.at(iBuf)!=' ') {
      strtemp=strtemp+buffer.at(iBuf); 
     }
     else {
      float f =(float) atof(strtemp.c_str()); 
      row.push_back(f);
      strtemp.clear();
     }
    } 
   }
   
   Bin_Extremes.push_back(row);
   row.clear();
   flag2 = 0;
   continue;
  }
  
  if(flag==2 && buffer!="" && buffer!="[Variables]"&& flag2==0) {
   if (buffer.at(0)!='#') { 
    int k=0;
    std::pair<std::string,int> temp;
    sample_temp.clear();
    for(int iBuf=0; iBuf<buffer.size(); iBuf++) {
     if(buffer.at(iBuf)!=' ') {
      sample_temp=sample_temp+buffer.at(iBuf);
     }
     else {
      if (k==0) {
       temp.first=sample_temp;
       temp.second=iPoint;
       k++;
       sample_temp.clear();
      }
     }
    }
    
    Variable.push_back(temp);
    nameHumanVariable.push_back(sample_temp);
    std::cout<<"[Variable]:  "<<temp.first<<" [Name Human Readeble]:      "<<sample_temp<<std::endl;
    iPoint++;
    flag2 = 1;
    continue;
   }
  } 
 }
 
 
 
 for (int iNameToJoin = 0; iNameToJoin < nameSampleToJoin.size(); iNameToJoin++){
  std::cout << " Joint [" << iNameToJoin << "::" << nameSampleToJoin.size() << "] = " << nameSampleToJoin.at(iNameToJoin) << std::endl;
 }
 
 for (int iCutHR = 0; iCutHR < HumanCuts.size(); iCutHR++){
  std::cout << " CutHR [" << iCutHR << "::" << HumanCuts.size() << "] = " << HumanCuts.at(iCutHR) << " >> " << Cuts.at(iCutHR) << std::endl;
 }
 
 
 
 ///=== Acquisition from the input file of the object: stack and histogramms 
 
 ///      [iCut][iVar][iSample]
 TH1D* histo [100][100][100];
 TH1D* histoRebinned [100][100][100];
 THStack* stack[100][100];
 TCanvas* canvas[100][100];
 
 for(int iCut=0; iCut<Cuts.size();iCut++) {  
  for(int iVar=0; iVar<Variable.size();iVar++) {
   TString stack_name = Form("Data/%d_%d_stack", iCut, iVar);
   stack[iCut][iVar]= (THStack*)Input_File->Get(stack_name);
   
   if (iCut == 0 && iVar == 0) {
    FillListOfName (*stack[iCut][iVar], &nameSample);
    nameSample.push_back("DATA");
   }
   
   TString Canvas_name = Form("All/Var/%d_%d_Canvas", iCut, iVar);
   canvas[iCut][iVar]=(TCanvas*) Input_File->Get(Canvas_name);
   
   for(int iSample =0; iSample<nameSample.size(); iSample++) {    
    TString histo_name = Form("Data/%s_%d_%d_Tot_temp", nameSample.at(iSample).c_str(), iCut, iVar);
    histo[iCut][iVar][iSample] = (TH1D*) Input_File->Get(histo_name);
    bool isDATA = nameSample.at(iSample) == "DATA";
    bool isDivide = false;
    histoRebinned[iCut][iVar][iSample] = DynamicalRebinHisto(histo[iCut][iVar][iSample],histoRebinned[iCut][iVar][iSample],Bin_Extremes[iVar],isDATA,isDivide);
   }
  }
 } 
 
 ///                   [iBin][iVar]
 TH1D* EfficiencyHisto_ttbar[100][100]; 
 TEfficiency* eff_DATA[100][100];
 TH1D* PurityHisto_BTag[100][100];
 TH1D* PurityHisto_All [100][100];

 ///                   [iSample][iBin][iVar]
 TH1D* CompositionHisto_Samples_BTag[20][100][100];
 TH1D* CompositionHisto_Samples_All [20][100][100];
 
 THStack* CompositionHisto_BTag[100][100];
 THStack* CompositionHisto_All [100][100];
 
 ///=== Calculation of the Efficiency vs Progressive Selection from Efficiency to Signal zone
 
 TLegend * legAll = new TLegend(0.0,0.0,1.0,1.0);
 
 for(int iVar=0; iVar< Variable.size(); iVar++) { 
  ///====== Variable selection
//   if(Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(abs(q1_Eta))+(abs(q1_Eta)>=abs(q2_Eta))*(abs(q2_Eta))" && 
//    Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(q1_pT)+(abs(q1_Eta)>=abs(q2_Eta))*(q2_pT)")
//    continue;
  
  for (int iEdge = 0; iEdge < Bin_Extremes[iVar].size(); iEdge++) {
   std::cout << " edge[" << iVar << "][" << iEdge << "] = " << Bin_Extremes[iVar].at(iEdge) << std::endl;
  }
  
  output_Plott.cd();
  TDirectory* cdVar = (TDirectory*) output_Plott.mkdir(nameHumanVariable.at(iVar).c_str());
  TDirectory* cdVarBin[100];
  for(int iBin=0; iBin<Bin_Extremes[iVar].size()-1; iBin++) {  
   TString TitleDir = Form("%.2f<%s<%.2f",Bin_Extremes[iVar].at(iBin),nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin+1));
   cdVarBin[iBin] = (TDirectory*) cdVar->mkdir(TitleDir.Data());
  }
  output_Plott.cd(nameHumanVariable.at(iVar).c_str());
  
  
  for(int iBin=0; iBin<Bin_Extremes[iVar].size()-1; iBin++) {  
   TString eff_name = Form("%s_%d",nameHumanVariable.at(iVar).c_str(),iBin);
   EfficiencyHisto_ttbar[iBin][iVar] = new TH1D(eff_name,"",Cuts.size()/3,0,Cuts.size()/3);
   
   eff_name = Form("%s_DATA_%d_num",nameHumanVariable.at(iVar).c_str(),iBin);
   TH1D* num_DATA_temp = new TH1D(eff_name,"",Cuts.size()/3,0,Cuts.size()/3);
   
   eff_name = Form("%s_DATA_%d_den",nameHumanVariable.at(iVar).c_str(),iBin);
   TH1D* den_DATA_temp = new TH1D(eff_name,"",Cuts.size()/3,0,Cuts.size()/3);
   
   eff_name = Form("Purity_All_%s_%d",nameHumanVariable.at(iVar).c_str(),iBin);
   PurityHisto_All[iBin][iVar] = new TH1D(eff_name,"",Cuts.size()/3,0,Cuts.size()/3);
   
   eff_name = Form("Purity_BTag_%s_%d",nameHumanVariable.at(iVar).c_str(),iBin);
   PurityHisto_BTag[iBin][iVar] = new TH1D(eff_name,"",Cuts.size()/3,0,Cuts.size()/3);
   
   TString composition_name = Form("Composition_BTag_%s_%d",nameHumanVariable.at(iVar).c_str(),iBin);
   CompositionHisto_BTag[iBin][iVar] = new THStack(composition_name,"");
   
   composition_name = Form("Composition_All_%s_%d",nameHumanVariable.at(iVar).c_str(),iBin);
   CompositionHisto_All[iBin][iVar] = new THStack(composition_name,"");   
   for(int iSample=0; iSample<nameSample.size(); iSample++) {
    TString composition_sample_name = Form("Composition_BTag_%s_%s_%d",nameSample.at(iSample).c_str(),nameHumanVariable.at(iVar).c_str(),iBin);
    CompositionHisto_Samples_BTag[iSample][iBin][iVar] = new TH1D(composition_sample_name,"",Cuts.size()/3,0,Cuts.size()/3);
    composition_sample_name = Form("Composition_All_%s_%s_%d",nameSample.at(iSample).c_str(),nameHumanVariable.at(iVar).c_str(),iBin);
    CompositionHisto_Samples_All [iSample][iBin][iVar] = new TH1D(composition_sample_name,"",Cuts.size()/3,0,Cuts.size()/3);
    
    CompositionHisto_Samples_BTag[iSample][iBin][iVar]->SetFillColor(histoRebinned[0][0][iSample]->GetFillColor());
    CompositionHisto_Samples_All [iSample][iBin][iVar]->SetFillColor(histoRebinned[0][0][iSample]->GetFillColor());
    CompositionHisto_Samples_BTag[iSample][iBin][iVar]->SetFillStyle(histoRebinned[0][0][iSample]->GetFillStyle());
    CompositionHisto_Samples_All [iSample][iBin][iVar]->SetFillStyle(histoRebinned[0][0][iSample]->GetFillStyle());
    CompositionHisto_Samples_BTag[iSample][iBin][iVar]->SetLineColor(histoRebinned[0][0][iSample]->GetLineColor());
    CompositionHisto_Samples_All [iSample][iBin][iVar]->SetLineColor(histoRebinned[0][0][iSample]->GetLineColor());
    CompositionHisto_Samples_BTag[iSample][iBin][iVar]->SetLineWidth(histoRebinned[0][0][iSample]->GetLineWidth());
    CompositionHisto_Samples_All [iSample][iBin][iVar]->SetLineWidth(histoRebinned[0][0][iSample]->GetLineWidth());
    
    legAll->AddEntry(CompositionHisto_Samples_All [iSample][iBin][iVar],nameSample.at(iSample).c_str());
   }
   
   if (iBin == 0 && iVar == 0) {
    TCanvas cTemp;
    cTemp.SetName("Legend");
    legAll->SetFillColor(kWhite);
    legAll->Draw();
    cTemp.Write();
   }
   
   int j = 0;
   int iCutBin = 0;  
   
   for(int iCut=0;  iCut<Cuts.size()-1; iCut++) {
    bool isDATA = false;
    bool isDivide = false;
    
    if (iCut%3 == 0)
     iCutBin++;
    
    TString CutName_down = Form("VBF_noBtag_%d",j);
    TString CutName_up = Form("VBF_Btag_%d",j);
    TString Cut_down = Form("%s",Cuts.at(iCut).c_str());
    TString Cut_up = Form("%s",Cuts.at(iCut+1).c_str());
    
    if(Cut_down == CutName_down && Cut_up == CutName_up) {
     j++;
     
     TH1D* num = (TH1D*) stack[iCut+1][iVar]->GetStack()->Last();
     TH1D* num_Rebinned;
     num_Rebinned = DynamicalRebinHisto(num,num_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
     
     TH1D* den = (TH1D*) stack[iCut][iVar]->GetStack()->Last();
     TH1D* den_Rebinned;
     den_Rebinned = DynamicalRebinHisto(den,den_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
     
     TH1D * num_DATA, *den_DATA, *num_ttbar, *num_top, *den_ttbar, *den_top;
     TH1D * num_DATA_Rebinned, * den_DATA_Rebinned,*num_ttbar_Rebinned, *num_top_Rebinned, *den_ttbar_Rebinned, *den_top_Rebinned;
     bool done = false;
     
     for(int iSample=0; iSample<nameSample.size(); iSample++) {
      for (int iNameToJoin = 0; iNameToJoin < nameSampleToJoin.size(); iNameToJoin++) {
       if (nameSample.at(iSample) == nameSampleToJoin.at(iNameToJoin)) { 
	// 	if (!num_ttbar) {
	 if (!done) {
	 done = true;
	 TString nameHisto = Form ("num_%s_%d_%d",nameSample.at(iSample).c_str(),iCut,iSample);
	 num_ttbar = (TH1D*) histo[iCut+1][iVar][iSample]->Clone(nameHisto.Data());
// 	 std::cout << " nameHisto = " << nameHisto.Data() << std::endl;
	 // 	num_ttbar->Sumw2();
	 num_ttbar_Rebinned = DynamicalRebinHisto(num_ttbar,num_ttbar_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
	 
	 nameHisto = Form ("den_%s_%d_%d",nameSample.at(iSample).c_str(),iCut,iSample);
	 den_ttbar = (TH1D*) histo[iCut][iVar][iSample]->Clone(nameHisto.Data());
	 den_ttbar_Rebinned = DynamicalRebinHisto(den_ttbar,den_ttbar_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);	
	} 
	else {
	 TString nameHisto = Form ("num_%s_%d_%d",nameSample.at(iSample).c_str(),iCut,iSample);
	 num_top = (TH1D*)histo[iCut+1][iVar][iSample]->Clone(nameHisto.Data());
	 // 	num_top->Sumw2();
	 num_top_Rebinned = DynamicalRebinHisto(num_top,num_top_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	 
	 nameHisto = Form ("den_%s_%d_%d",nameSample.at(iSample).c_str(),iCut,iSample);
	 den_top = (TH1D*) histo[iCut][iVar][iSample]->Clone(nameHisto.Data());
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
       
       isDATA = false;
      }
     }
     
     /// top background Effciency
     
     
     if (den_ttbar_Rebinned->GetBinContent(iBin+1)!=0) {    
      std::cerr << " Eff[" << iCutBin << "] = " << num_ttbar_Rebinned->GetBinContent(iBin+1) << " / " << den_ttbar_Rebinned->GetBinContent(iBin+1) << " = " << num_ttbar_Rebinned->GetBinContent(iBin+1)/den_ttbar_Rebinned->GetBinContent(iBin+1) << std::endl;
      EfficiencyHisto_ttbar[iBin][iVar]->SetBinContent(iCutBin, num_ttbar_Rebinned->GetBinContent(iBin+1)/den_ttbar_Rebinned->GetBinContent(iBin+1));
      EfficiencyHisto_ttbar[iBin][iVar]->SetBinError (iCutBin, 1. / (den_ttbar_Rebinned->GetBinContent(iBin+1)) * sqrt( num_ttbar_Rebinned->GetBinError(iBin+1) * num_ttbar_Rebinned->GetBinError(iBin+1) + num_ttbar_Rebinned->GetBinContent(iBin+1) * num_ttbar_Rebinned->GetBinContent(iBin+1) / (den_ttbar_Rebinned->GetBinContent(iBin+1) * den_ttbar_Rebinned->GetBinContent(iBin+1)) * (den_ttbar_Rebinned->GetBinError(iBin+1) * den_ttbar_Rebinned->GetBinError(iBin+1))));
     }
     else {
      std::cerr << " Eff[" << iCutBin << "] = " << num_ttbar_Rebinned->GetBinContent(iBin+1) << " / " << den_ttbar_Rebinned->GetBinContent(iBin+1) << " = " << -1 << std::endl;      
      EfficiencyHisto_ttbar[iBin][iVar]->SetBinContent(iCutBin, -1);
      EfficiencyHisto_ttbar[iBin][iVar]->SetBinError (iCutBin, 0);
     }
     
     if (den_Rebinned->GetBinContent(iBin+1) != 0) {
      std::cerr << " Pur[" << iCutBin << "] = " << den_ttbar_Rebinned->GetBinContent(iBin+1) << " / " << den_Rebinned->GetBinContent(iBin+1) << " = " << den_ttbar_Rebinned->GetBinContent(iBin+1)/den_Rebinned->GetBinContent(iBin+1) << std::endl;
      PurityHisto_All[iBin][iVar]->SetBinContent(iCutBin,den_ttbar_Rebinned->GetBinContent(iBin+1)/den_Rebinned->GetBinContent(iBin+1));
      PurityHisto_All[iBin][iVar]->SetBinError(iCutBin,(1./(den_Rebinned->GetBinContent(iBin+1)))*sqrt(den_ttbar_Rebinned->GetBinError(iBin+1)*den_ttbar_Rebinned->GetBinError(iBin+1)+(den_ttbar_Rebinned->GetBinContent(iBin+1)*den_ttbar_Rebinned->GetBinContent(iBin+1))/(den_Rebinned->GetBinContent(iBin+1)*den_Rebinned->GetBinContent(iBin+1))*(den_Rebinned->GetBinError(iBin+1)*den_Rebinned->GetBinError(iBin+1))));

      for(int iSample=0; iSample<nameSample.size(); iSample++) {
//        TH1D* den_sample_Rebinned;
//        den_sample_Rebinned = DynamicalRebinHisto(histo[iCut][iVar][iSample],den_sample_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
       CompositionHisto_Samples_All [iSample][iBin][iVar] -> SetBinContent (iCutBin,histoRebinned[iCut][iVar][iSample]->GetBinContent(iBin+1) / den_Rebinned->GetBinContent(iBin+1));
       CompositionHisto_Samples_All [iSample][iBin][iVar] -> SetBinError   (iCutBin,0);
//        std::cout << " --- nameSample = " << nameSample.at(iSample) << " iCutBin = " << iCutBin << std::endl;
//        std::cout << " ^^^ histoRebinned[" << iCut << "][" << iVar << "][" << iSample << "]->GetBinContent(" << iBin << "+1) = " << histoRebinned[iCut][iVar][iSample]->GetBinContent(iBin+1) << std::endl;
//        std::cout << " ~~~ den_Rebinned->GetBinContent(" << iBin << "+1) = " << den_Rebinned->GetBinContent(iBin+1) << std::endl;
      }
      
     }
     else {
      std::cerr << " Pur[" << iCutBin << "] = " << den_ttbar_Rebinned->GetBinContent(iBin+1) << " / " << den_Rebinned->GetBinContent(iBin+1) << " = " << -1 << std::endl;
      PurityHisto_All[iBin][iVar]->SetBinContent(iCutBin,-1);
      PurityHisto_All[iBin][iVar]->SetBinError(iCutBin,0);
     }
     
     if (num_Rebinned->GetBinContent(iBin+1) != 0) {
      std::cerr << " Pur[" << iCutBin << "] = " << num_ttbar_Rebinned->GetBinContent(iBin+1) << " / " << num_Rebinned->GetBinContent(iBin+1) << " = " << num_ttbar_Rebinned->GetBinContent(iBin+1)/num_Rebinned->GetBinContent(iBin+1) << std::endl;     
      PurityHisto_BTag[iBin][iVar]->SetBinContent(iCutBin,num_ttbar_Rebinned->GetBinContent(iBin+1)/num_Rebinned->GetBinContent(iBin+1));
      PurityHisto_BTag[iBin][iVar]->SetBinError(iCutBin,(1./(num_Rebinned->GetBinContent(iBin+1)))*sqrt(num_ttbar_Rebinned->GetBinError(iBin+1)*num_ttbar_Rebinned->GetBinError(iBin+1)+(num_ttbar_Rebinned->GetBinContent(iBin+1)*num_ttbar_Rebinned->GetBinContent(iBin+1))/(num_Rebinned->GetBinContent(iBin+1)*num_Rebinned->GetBinContent(iBin+1))*(num_Rebinned->GetBinError(iBin+1)*num_Rebinned->GetBinError(iBin+1)))); 
      
      for(int iSample=0; iSample<nameSample.size(); iSample++) {
//        TH1D* num_sample_Rebinned;
//        num_sample_Rebinned = DynamicalRebinHisto(histo[iCut+1][iVar][iSample],num_sample_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
       CompositionHisto_Samples_BTag[iSample][iBin][iVar] -> SetBinContent (iCutBin,histoRebinned[iCut+1][iVar][iSample]->GetBinContent(iBin+1) / num_Rebinned->GetBinContent(iBin+1));
       CompositionHisto_Samples_BTag[iSample][iBin][iVar] -> SetBinError   (iCutBin,0);
      }
      
     }
     else {
      std::cerr << " Pur[" << iCutBin << "] = " << num_ttbar_Rebinned->GetBinContent(iBin+1) << " / " << num_Rebinned->GetBinContent(iBin+1) << " = " << -1 << std::endl;     
      PurityHisto_BTag[iBin][iVar]->SetBinContent(iCutBin,-1);
      PurityHisto_BTag[iBin][iVar]->SetBinError(iCutBin,0); 
     }
     
    
     if(den_DATA_Rebinned->GetBinContent(iBin+1)!=0) { 
      num_DATA_temp->SetBinContent(iCutBin,num_DATA_Rebinned->GetBinContent(iBin+1));
      num_DATA_temp->SetBinError(iCutBin,num_DATA_Rebinned->GetBinError(iBin+1));
      
      den_DATA_temp->SetBinContent(iCutBin,den_DATA_Rebinned->GetBinContent(iBin+1));
      den_DATA_temp->SetBinError(iCutBin,den_DATA_Rebinned->GetBinError(iBin+1));
     }
     
    } 
   }
   
   eff_DATA[iBin][iVar] = new TEfficiency(*num_DATA_temp,*den_DATA_temp);
   eff_DATA[iBin][iVar] -> Bayesian(den_DATA_temp->GetEntries(),num_DATA_temp->GetEntries(),0.68,1,1,false,true);
   
//    num_DATA_temp->Write();
//    den_DATA_temp->Write();
   
   for(int iSample=0; iSample<nameSample.size(); iSample++) {
    if (nameSample.at(iSample) != "DATA") {
     int tempiCutBin = 0;
     for (int iBin2=0; iBin2<HumanCuts.size(); iBin2 = iBin2 + 3) {
      CompositionHisto_Samples_BTag[iSample][iBin][iVar] -> GetXaxis() -> SetBinLabel(tempiCutBin+1,HumanCuts.at(iBin2).c_str());
      CompositionHisto_Samples_All [iSample][iBin][iVar] -> GetXaxis() -> SetBinLabel(tempiCutBin+1,HumanCuts.at(iBin2).c_str());
      tempiCutBin++;
     }
     CompositionHisto_BTag[iBin][iVar] -> Add (CompositionHisto_Samples_BTag[iSample][iBin][iVar]);
     CompositionHisto_All [iBin][iVar] -> Add (CompositionHisto_Samples_All [iSample][iBin][iVar]);
     
     cdVarBin[iBin]->cd();
     CompositionHisto_Samples_BTag[iSample][iBin][iVar]->Write();
     CompositionHisto_Samples_All [iSample][iBin][iVar]->Write();
    }
   }
   
   cdVarBin[iBin]->cd();
   CompositionHisto_BTag[iBin][iVar] -> Write();
   CompositionHisto_All [iBin][iVar] -> Write(); 
   
   cdVarBin[iBin]->cd();
   
   TCanvas c1;
   
   EfficiencyHisto_ttbar[iBin][iVar]->SetMarkerColor(kBlue);
   EfficiencyHisto_ttbar[iBin][iVar]->SetLineColor(kBlue);
   EfficiencyHisto_ttbar[iBin][iVar]->SetLineWidth(2);
   EfficiencyHisto_ttbar[iBin][iVar]->SetMarkerStyle(20);
   EfficiencyHisto_ttbar[iBin][iVar]->SetFillStyle(3001);
   EfficiencyHisto_ttbar[iBin][iVar]->SetFillColor(kBlue);
   
   PurityHisto_All[iBin][iVar]->SetMarkerColor(kBlue);
   PurityHisto_All[iBin][iVar]->SetLineColor(kBlue);
   PurityHisto_All[iBin][iVar]->SetLineWidth(2);
   PurityHisto_All[iBin][iVar]->SetMarkerStyle(20);
   PurityHisto_All[iBin][iVar]->SetFillStyle(3001);
   PurityHisto_All[iBin][iVar]->SetFillColor(kBlue);
   
   PurityHisto_BTag[iBin][iVar]->SetMarkerColor(kBlue);
   PurityHisto_BTag[iBin][iVar]->SetLineColor(kBlue);
   PurityHisto_BTag[iBin][iVar]->SetLineWidth(2);
   PurityHisto_BTag[iBin][iVar]->SetMarkerStyle(20);
   PurityHisto_BTag[iBin][iVar]->SetFillStyle(3001);
   PurityHisto_BTag[iBin][iVar]->SetFillColor(kBlue);
   
   
   eff_DATA[iBin][iVar]->SetMarkerColor(kBlack);
   eff_DATA[iBin][iVar]->SetLineColor(kBlack);
   eff_DATA[iBin][iVar]->SetLineWidth(2);
   eff_DATA[iBin][iVar]->SetMarkerStyle(20);
   
   iCutBin = 0;
   for (int iBin2=0; iBin2<HumanCuts.size(); iBin2 = iBin2 + 3) {
    EfficiencyHisto_ttbar[iBin][iVar] -> GetXaxis()->SetBinLabel(iCutBin+1,HumanCuts.at(iBin2).c_str());
    PurityHisto_All[iBin][iVar]       -> GetXaxis()->SetBinLabel(iCutBin+1,HumanCuts.at(iBin2).c_str());
    PurityHisto_BTag[iBin][iVar]      -> GetXaxis()->SetBinLabel(iCutBin+1,HumanCuts.at(iBin2).c_str());
//     eff_DATA[iBin][iVar]              -> GetXaxis()->SetBinLabel(iCutBin+1,HumanCuts.at(iBin2).c_str());
//     CompositionHisto_All [iBin][iVar] -> GetXaxis()->SetBinLabel(iCutBin+1,HumanCuts.at(iBin2).c_str());
//     CompositionHisto_BTag[iBin][iVar] -> GetXaxis()->SetBinLabel(iCutBin+1,HumanCuts.at(iBin2).c_str());    
    iCutBin++;
   }
   
   EfficiencyHisto_ttbar[iBin][iVar]->GetYaxis()->SetRangeUser(0.0,1.0);
   EfficiencyHisto_ttbar[iBin][iVar]->GetXaxis()->SetTitle("");
   EfficiencyHisto_ttbar[iBin][iVar]->GetYaxis()->SetTitle("Efficiency");
   TString Title = Form("Efficiency in the region %.2f< %s <%.2f",Bin_Extremes[iVar].at(iBin),nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin+1));
   EfficiencyHisto_ttbar[iBin][iVar]->SetTitle(Title);
   
   EfficiencyHisto_ttbar[iBin][iVar]->Draw("E3");
   
   TLegend * leg =new TLegend(0.75,0.7,0.98,0.9);
   leg->AddEntry(EfficiencyHisto_ttbar[iBin][iVar],"eff on MC tt");
   leg->SetFillColor(kWhite);
   leg->Draw();
   
   Title = Form("efficiency_MC_%s_%.2f-%.2f",nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin),Bin_Extremes[iVar].at(iBin+1));
   c1.SetName(Title);
   c1.Write();
   
   
   eff_DATA[iBin][iVar]->Draw("AP");
   leg->SetFillColor(kWhite);
   leg->Draw();
   leg->Clear();
   leg->AddEntry(eff_DATA[iBin][iVar],"eff on DATA");
   
   Title = Form("efficiency_DATA_%s_%.2f-%.2f",nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin),Bin_Extremes[iVar].at(iBin+1));
   c1.SetName(Title);
   c1.Write();
   
   PurityHisto_All[iBin][iVar]->GetYaxis()->SetRangeUser(0,1); 
   PurityHisto_All[iBin][iVar]->GetXaxis()->SetTitle("");
   PurityHisto_All[iBin][iVar]->GetYaxis()->SetTitle("Purity");
   Title = Form("Purity C.R. in the region %.2f< %s <%.2f",Bin_Extremes[iVar].at(iBin),nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin+1));
   PurityHisto_All[iBin][iVar]->SetTitle(Title);
   
   PurityHisto_All[iBin][iVar]->Draw("E");
   
   Title = Form("Purity_%s_%.1f-%.1f",nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin),Bin_Extremes[iVar].at(iBin+1));
   c1.SetName(Title);
   c1.Write();
   
   PurityHisto_BTag[iBin][iVar]->GetYaxis()->SetRangeUser(0,1);
   PurityHisto_BTag[iBin][iVar]->GetXaxis()->SetTitle("");
   PurityHisto_BTag[iBin][iVar]->GetYaxis()->SetTitle("Purity");
   Title = Form("Purity C.R. b-Tag  %.2f< %s <%.2f",Bin_Extremes[iVar].at(iBin),nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin+1));
   PurityHisto_BTag[iBin][iVar]->SetTitle(Title);
   
   PurityHisto_BTag[iBin][iVar]->Draw("E");
   
   Title = Form("Purity_%s_%.1f-%.1f",nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin),Bin_Extremes[iVar].at(iBin+1));
   c1.SetName(Title);
   c1.Write();
   
   
   CompositionHisto_All [iBin][iVar] -> Draw();
   Title = Form("Composition_All_%s_%.1f-%.1f",nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin),Bin_Extremes[iVar].at(iBin+1));
   c1.SetName(Title);
   c1.Write();

   CompositionHisto_BTag [iBin][iVar] -> Draw();
   Title = Form("Composition_BTag_%s_%.1f-%.1f",nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin),Bin_Extremes[iVar].at(iBin+1));
   c1.SetName(Title);
   c1.Write();
   
  }
  
  int iCutBin=0;
  int i=0,j=0;
  
  TString eff_name = Form("Sys_%s",nameHumanVariable.at(iVar).c_str());
  TH1D* SysBias = new TH1D(eff_name,"",Cuts.size()/3,0,Cuts.size()/3);
  
  eff_name = Form("Kolmogorov_Test_%s",nameHumanVariable.at(iVar).c_str());
  TH1D* Kolmogorov_Distribution = new TH1D(eff_name,eff_name,Cuts.size()/3,0,Cuts.size()/3);
  
  eff_name = Form("Chi_Test_%s",nameHumanVariable.at(iVar).c_str());
  TH1D* Chi_Distribution = new TH1D(eff_name,eff_name,Cuts.size()/3,0,Cuts.size()/3);
  
  for(int iCut=0; iCut<Cuts.size(); iCut++) {
   std::cerr << " iCut = " << iCut << std::endl;
   
   bool isDATA =false;
   bool isDivide =false;
   
   if (iCut%3==0)
    iCutBin++;
   
   TString CutName_BTag = Form("VBF_Btag_%d",i);
   TString Cut_BTag = Form("%s",Cuts.at(iCut).c_str());
   
   TString CutName_Sig= Form("VBF_Sig_%d",j);
   TString Cut_Sig= Form("%s",Cuts.at(iCut).c_str());
   
   if(CutName_BTag == Cut_BTag) { 
    i++;
    
    std::cerr << " >> Btag <<" << std::endl;
    
    THStack* stack_Rebinned;
    stack_Rebinned = DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
    
    TH1D* num_Rebinned;
    num_Rebinned = (TH1D*) stack_Rebinned->GetStack()->Last();
    
    TH1D* num_DATA, *num_DATA_Rebinned;
    
    for(int iSample =0; iSample<nameSample.size(); iSample++) {
     
     if(nameSample.at(iSample)!="DATA") continue;
     
     isDATA = true;     
     num_DATA = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_DATA");
     num_DATA_Rebinned = DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
     isDATA=false;
    }
    
    double Kolmogorov_Probability = num_DATA_Rebinned->KolmogorovTest(num_Rebinned,"D");
    double Chi_Probability = num_DATA_Rebinned->Chi2Test(num_Rebinned,"UWP");
    
    Kolmogorov_Distribution->SetBinContent(iCutBin,Kolmogorov_Probability);
    Chi_Distribution->SetBinContent(iCutBin,Chi_Probability);
   }
   
   if(CutName_Sig == Cut_Sig) {
    j++;
    
    std::cerr << " >> Sig <<" << std::endl;
    
    TH1D* num_ttbar_Sig, *num_top_Sig;
    TH1D* num_top_Sig_Rebinned, *num_ttbar_Sig_Rebinned;
    bool done = false ;
    
    for(int iSample =0; iSample<nameSample.size(); iSample++) {
     for (int iNameToJoin = 0; iNameToJoin < nameSampleToJoin.size(); iNameToJoin++){
      if (nameSample.at(iSample) == nameSampleToJoin.at(iNameToJoin)) { 
       if (!done) {
	done = true;
// 	if (!num_ttbar_Sig) {
	TString nameHisto = Form ("%s_%d_%d",nameSample.at(iSample).c_str(),iCut,iSample);
	num_ttbar_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone(nameHisto.Data());
	num_ttbar_Sig_Rebinned = DynamicalRebinHisto(num_ttbar_Sig,num_ttbar_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
       } 
       else {
	TString nameHisto = Form ("%s_%d_%d",nameSample.at(iSample).c_str(),iCut,iSample);
	num_top_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone(nameHisto.Data());
	num_top_Sig_Rebinned = DynamicalRebinHisto(num_top_Sig,num_top_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	num_ttbar_Sig_Rebinned->Add(num_top_Sig_Rebinned);
       }
      }
     }
    }
    
    std::cerr << " >> alpha << " << std::endl;
    
    double alfa=0, beta=0;
    double err_alfa=0,err_beta=0;
    
    for(int iBin=0; iBin<num_ttbar_Sig_Rebinned->GetNbinsX(); iBin++) {
     if (nameHumanVariable.at(iVar) == "|#eta|^{CJet}" && num_ttbar_Sig_Rebinned->GetBinCenter(iBin+1)<=2.5) {
      alfa = alfa + num_ttbar_Sig_Rebinned->GetBinContent(iBin+1);
      err_alfa = sqrt(err_alfa*err_alfa+num_ttbar_Sig_Rebinned->GetBinError(iBin+1)*num_ttbar_Sig_Rebinned->GetBinError(iBin+1));
     }
     
     if (nameHumanVariable.at(iVar) == "|#eta|^{CJet}" && num_ttbar_Sig_Rebinned->GetBinCenter(iBin+1)>2.5) {
      beta = beta + num_ttbar_Sig_Rebinned->GetBinContent(iBin+1);
      err_beta = sqrt(err_beta*err_beta+num_ttbar_Sig_Rebinned->GetBinError(iBin+1)*num_ttbar_Sig_Rebinned->GetBinError(iBin+1));
     }
    }
    
    SysBias->SetBinContent(iCutBin,(alfa+beta)/(alfa));
    SysBias->SetBinError(iCutBin,sqrt((1/(alfa*alfa))*(err_beta*err_beta)+(beta/(alfa*alfa))*(beta/(alfa*alfa))*(err_alfa*err_alfa)));
    
   }
   
  }
  
  
  TCanvas c2;
  
  Kolmogorov_Distribution->SetMarkerColor(kRed);
  Kolmogorov_Distribution->SetLineColor(kRed);
  Kolmogorov_Distribution->SetLineWidth(2);
  Kolmogorov_Distribution->SetMarkerStyle(20);
  Kolmogorov_Distribution->SetFillStyle(3001);
  Kolmogorov_Distribution->SetFillColor(kRed);
  
  Chi_Distribution->SetMarkerColor(kBlue);
  Chi_Distribution->SetLineColor(kBlue);
  Chi_Distribution->SetLineWidth(2);
  Chi_Distribution->SetMarkerStyle(21);
  Chi_Distribution->SetFillStyle(3001);
  Chi_Distribution->SetFillColor(kBlue);
  
  iCutBin=0;
  
  for(int iBin=0; iBin<HumanCuts.size(); iBin=iBin+3) {
   Kolmogorov_Distribution->GetXaxis()->SetBinLabel(iCutBin+1,HumanCuts.at(iBin).c_str());
   Chi_Distribution->GetXaxis()->SetBinLabel(iCutBin+1,HumanCuts.at(iBin).c_str());
   iCutBin++;
  }
  
  TString Title = Form("Compatibility_Test_Result_%s",nameHumanVariable.at(iVar).c_str()); 
  Kolmogorov_Distribution->GetYaxis()->SetTitle("Probability");
  Chi_Distribution->GetYaxis()->SetTitle("Probability");
  c2.SetName(Title);
  
  TLegend* leg = new TLegend(0.9,0.8,0.98,0.9);
  leg->AddEntry(Kolmogorov_Distribution,"Kolmogorov Probability");
  leg->AddEntry(Chi_Distribution,"Chi^{2} Probability");
  leg->SetFillColor(kWhite);
  
  Kolmogorov_Distribution->Draw("E");
  Chi_Distribution->Draw("E");
  leg->Draw();
  c2.Write();
  
  
  SysBias->SetMarkerColor(kRed);
  SysBias->SetLineColor(kRed);
  SysBias->SetLineWidth(2);
  SysBias->SetMarkerStyle(22);
  SysBias->SetFillStyle(3001);
  SysBias->SetFillColor(kRed);
  
  iCutBin=0;
  
  for(int iBin=0; iBin<HumanCuts.size(); iBin=iBin+3) {
   SysBias->GetXaxis()->SetBinLabel(iCutBin+1,HumanCuts.at(iBin).c_str());
   iCutBin++;
  }
  
  Title = Form("Correction Factor tt MC %s>2.5",nameHumanVariable.at(iVar).c_str()); 
  SysBias->SetTitle(Title);
  SysBias->GetYaxis()->SetTitle("Correction Factor");
  Title = Form("#frac{#alpha+#beta}{#alpha}_vs_Cuts_%s",nameHumanVariable.at(iVar).c_str());
  c2.SetName(Title);
  SysBias->Draw("E1");
  c2.Write();
  
  
 }
 
 
 
 
 return(0);
}