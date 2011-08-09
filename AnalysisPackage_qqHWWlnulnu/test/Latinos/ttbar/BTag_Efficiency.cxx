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
#include "THStack.h"
#include "TRandom3.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TPaveStats.h"
#include "TText.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "/home/raffaele/Programmi/AnalysisPackage/AnalysisPackage_qqHWWlnulnu/test/TDRStyle.cc"
#include "/home/raffaele/Programmi/AnalysisPackage/AnalysisPackage_qqHWWlnulnu/test/Read.cc"
#include "/home/raffaele/Programmi/AnalysisPackage/AnalysisPackage_qqHWWlnulnu/test/Latinos/ttbar/plotUtils.C"


int BTag_Efficiency()
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
//   kWhite,
  kTeal,
  kYellow,
  (EColor) (kTeal+1),
  (EColor) (kOrange+2),
  (EColor) (kGreen+2),
  kGray,(EColor) (kGray+1),(EColor) (kViolet),(EColor) (kYellow),(EColor) (kGray)
 };
  
 ///=== Open the input ROOT File
 
 TFile * Input_File = TFile::Open("/home/raffaele/Programmi/AnalysisPackage/AnalysisPackage_qqHWWlnulnu/output/out_ComparisonPLOTT_GluGluToHToWWTo2L2Nu_M-160_7TeV-powheg-pythia6.root");
 std::vector<std::string> nameSample;
 std::vector<std::string> Cuts;
 std::vector<std::pair<std::string,int> > Variable;
 std::vector<std::vector<float> > Bin_Extremes;
 std::vector<float> row;
 
///===== Acuisition info from txt file: Name of the samples, Cut applied and Variables of Plot 
 
 std::ifstream inFile("test/Latinos/ttbar/BTag_Efficiency.txt",ios::binary);
 std::string buffer;
 int flag=0, flag2=0;
 int iPoint=0;
 int iBin=0;
 std::string sample_temp;
 
 while(!inFile.eof())
 {
  getline(inFile,buffer);
  std::stringstream line( buffer );
  if(buffer =="[SampleName]") continue;
  if (buffer=="[cut]") flag=1;
  if(buffer=="[variables]") flag=2;
  
  if(flag==0 && buffer !=""&& buffer!="[SampleName]")
  {
    if (buffer.at(0)!='#')
    {
      line>>sample_temp;
      std::cout<<sample_temp<<std::endl;
      nameSample.push_back(sample_temp);
    }
  }
  
  if(flag==1 && buffer!=""&& buffer!="[cut]")
  {
    if (buffer.at(0)!='#') {line>>sample_temp;
                            Cuts.push_back(sample_temp);}
  }
  
  if(flag==2 && buffer!="" && buffer!="[variables]"&& flag2==0)
  {
     if (buffer.at(0)!='#') { line>>sample_temp;
			      std::pair<std::string,int> temp (sample_temp,iPoint);
			      Variable.push_back(temp);			      
                              iPoint++;
                              flag2=1;}
  }

  if(flag==2 && buffer!="" && buffer!="[variables]" && flag2==1)
  {
    if(buffer.at(0)!='#') { 
                            if(buffer==sample_temp) continue;
			    std::string strtemp;
			    for(int iBuf=0; iBuf<buffer.size(); iBuf++)
			    {  
			      if(buffer.at(iBuf)!=' ')
			      {
			        strtemp=strtemp+buffer.at(iBuf);}
			      else{
				   float f =(float) atof(strtemp.c_str());
				   row.push_back(f);
				   strtemp.clear();}
			    } 
                         }
    Bin_Extremes.push_back(row);
    row.clear();
    flag2=0;
 }
}
    
///=== Acquisition from the input file 

TH1F* histo [100][100][100];
THStack* stack[100][100];
TCanvas* canvas[100][100];

 for(int iCut=0; iCut<Cuts.size();iCut++)
 {  
  for(int iVar=0; iVar<Variable.size();iVar++)
   {
     for(int iSample=0; iSample<nameSample.size(); iSample++)
     {    
        TString histo_name =Form("Data/%s_%d_%d_Tot_temp", nameSample.at(iSample).c_str(), iCut, iVar);
        histo[iCut][iVar][iSample] = (TH1F*) Input_File->Get(histo_name);
     }
     TString stack_name= Form("Data/%d_%d_stack", iCut, iVar);
     stack[iCut][iVar]= (THStack*)Input_File->Get(stack_name);
     TString Canvas_name= Form("All/Var/%d_%d_Canvas", iCut, iVar);
     canvas[iCut][iVar]=(TCanvas*) Input_File->Get(Canvas_name);
    
   }
 } 
 

TH1F* EfficiencyHisto[100][100];
TH1F* EfficiencyHisto_ttbar[100][100];
TH1F* PurityHisto[100][100];
THStack* stack_Rebinned[100][100];
TEfficiency* eff_DATA[100][100];

///===== Output ROOT file

TFile  output_Plott("test/Latinos/ttbar/Efficiency_Plott.root","RECREATE");
output_Plott.cd();
gStyle->SetOptStat(0);

for(int iVar=0; iVar< Variable.size(); iVar++)
 { 
   ///====== Variable selection
    if(Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(abs(q1_Eta))+(abs(q1_Eta)>=abs(q2_Eta))*(abs(q2_Eta))" && 
       Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(q1_pT)+(abs(q1_Eta)>=abs(q2_Eta))*(q2_pT)") continue;
     
    for(int iCut=0; iCut<Cuts.size(); iCut++)
    {  
      	bool isDATA =false;
	bool isDivide = true;
       ///==== Selection of the "ttbar" cuts for the control region 
       if(Cuts.at(iCut)=="ttbar_noBtag" && Cuts.at(iCut+1)=="ttbar_Btag")
       {

        TH1F * num = (TH1F*) stack[iCut+1][iVar]->GetStack()->Last();
	TH1F * num_Rebinned; 
       
	num_Rebinned=DynamicalRebinHisto(num,num_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);

        num_Rebinned->SetFillStyle(3335);
        num_Rebinned->SetFillColor(kBlack);
        num_Rebinned->SetMarkerSize(0);
	num_Rebinned->SetLineWidth(0);
	
        TH1F * den = (TH1F*) stack[iCut][iVar]->GetStack()->Last();
	TH1F * den_Rebinned;
	
	den_Rebinned=DynamicalRebinHisto(den,den_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	den_Rebinned->SetFillStyle(3335);
        den_Rebinned->SetFillColor(kBlack);
        den_Rebinned->SetMarkerSize(0);
	den_Rebinned->SetLineWidth(0);
	
	TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample);
        
	TH1F* num_ttbar, *den_ttbar, *num_top, *den_top,*num_DATA, *den_DATA;
	TH1F * num_ttbar_Rebinned, * den_ttbar_Rebinned,* num_top_Rebinned, * den_top_Rebinned, * num_DATA_Rebinned, * den_DATA_Rebinned;

        ///==== Efficiency Distriubution for each Cut and Variables
	
	EfficiencyHisto[iCut][iVar]= (TH1F*) num_Rebinned->Clone("EfficiencyHisto");
        EfficiencyHisto[iCut][iVar]->Divide(den_Rebinned);
	
	///==== Dynamical rebin for the stack
	stack_Rebinned[iCut][iVar]=DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
	stack_Rebinned[iCut+1][iVar]=DynamicalRebinStack(stack[iCut+1][iVar],stack_Rebinned[iCut+1][iVar],Bin_Extremes[iVar],isDATA,isDivide);

	///==== Efficiency for ttbar, top and DATA
	for(int iSample=0;iSample<nameSample.size(); iSample++)
        {
	  
         if(nameSample.at(iSample)!="ttbar" && nameSample.at(iSample)!="top" && nameSample.at(iSample)!="DATA") continue;
	 
	 if(nameSample.at(iSample)=="ttbar")
	 { 
          num_ttbar = (TH1F*) histo[iCut+1][iVar][iSample]->Clone("num_ttbar");
	  num_ttbar_Rebinned=DynamicalRebinHisto(num_ttbar,num_ttbar_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
	  
	  den_ttbar = (TH1F*) histo[iCut][iVar][iSample]->Clone("den_ttbar");
	  den_ttbar_Rebinned=DynamicalRebinHisto(den_ttbar,den_ttbar_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	 }
          
         if(nameSample.at(iSample)=="top")
	 {
	  num_top = (TH1F*)histo[iCut+1][iVar][iSample]->Clone("num_top");
          num_top_Rebinned=DynamicalRebinHisto(num_top,num_top_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	  
	  den_top =(TH1F*)histo[iCut][iVar][iSample]->Clone("den_top");
	  den_top_Rebinned=DynamicalRebinHisto(den_top,den_top_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
          }

         if(nameSample.at(iSample)=="DATA")
	 { 
	   isDATA=true;
	   
	   num_DATA = (TH1F*)histo[iCut+1][iVar][iSample]->Clone("num_DATA");
	   num_DATA_Rebinned=DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);

	   den_DATA = (TH1F*)histo[iCut][iVar][iSample]->Clone("den_DATA");
	   den_DATA_Rebinned=DynamicalRebinHisto(den_DATA,den_DATA_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
	   
	   	   
	   num_DATA_Rebinned->SetMarkerColor(kBlack);
           num_DATA_Rebinned->SetLineColor(kBlack);
	   num_DATA_Rebinned->SetFillColor(kWhite);
           num_DATA_Rebinned->SetMarkerStyle(20);
	   den_DATA_Rebinned->SetMarkerColor(kBlack);
	   den_DATA_Rebinned->SetFillColor(kWhite);
           den_DATA_Rebinned->SetLineColor(kBlack);
           den_DATA_Rebinned->SetMarkerStyle(20);
	   
	   isDATA=false;
	 }
        }
        
         /// top background Effciency
         EfficiencyHisto_ttbar[iCut][iVar]= (TH1F*) num_ttbar_Rebinned->Clone("EfficiencyHisto_ttbar");
	 EfficiencyHisto_ttbar[iCut][iVar]->Add(num_top_Rebinned);
	 den_ttbar_Rebinned->Add(den_top_Rebinned);
	 EfficiencyHisto_ttbar[iCut][iVar]->Divide(den_ttbar_Rebinned);
	 
	 ///==== Purtity histos
	 PurityHisto[iCut+1][iVar]= (TH1F*) num_ttbar_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut+1][iVar]->Add(num_top_Rebinned);
	 PurityHisto[iCut+1][iVar]->Divide(num_Rebinned);
	 
	 PurityHisto[iCut][iVar]= (TH1F*) den_ttbar_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut][iVar]->Add(den_top_Rebinned);
	 PurityHisto[iCut][iVar]->Divide(den_Rebinned);
	 
	 ///==== Plot in different Canvas  
         TCanvas c1 ;   
	 
	 num_Rebinned->GetYaxis()->SetRangeUser(0,num_DATA_Rebinned->GetMaximum()+1.1*num_DATA_Rebinned->GetBinError(num_DATA_Rebinned->GetMaximumBin()));
         num_Rebinned->Draw("hist") ;
         stack_Rebinned[iCut+1][iVar]->Draw("same hist");
         num_Rebinned->Draw ("sameE2") ;
	 num_DATA_Rebinned->Draw("Esame");
	 legend->AddEntry(num_DATA_Rebinned, "DATA");
         legend->Draw();
         TString Title = Form("num_%d_%d_stack",iCut+1,iVar); 
         c1.SetName(Title);
         c1.Write();
         
	 den_Rebinned->GetYaxis()->SetRangeUser(0,den_DATA_Rebinned->GetMaximum()+1.1*den_DATA_Rebinned->GetBinError(den_DATA_Rebinned->GetMaximumBin()));
         den_Rebinned->Draw ("hist") ;
         stack_Rebinned[iCut][iVar]->Draw("same hist ");
         den_Rebinned->Draw ("E2same") ;
	 den_DATA_Rebinned->Draw("Esame");
         legend->Draw();
         Title = Form("den_%d_%d_stack",iCut,iVar);  
         c1.SetName(Title);
         c1.Write();
         
	 
         num_DATA_Rebinned=DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes[iVar],true,false);
	 den_DATA_Rebinned=DynamicalRebinHisto(den_DATA,den_DATA_Rebinned,Bin_Extremes[iVar],true,false);
	 
	 eff_DATA[iCut][iVar]= new TEfficiency(*num_DATA_Rebinned,*den_DATA_Rebinned);
	 eff_DATA[iCut][iVar]->Bayesian(den_DATA->GetEntries(),num_DATA->GetEntries(),0.95,1,1,true,true);
	  
	 eff_DATA[iCut][iVar]->SetMarkerColor(kBlack);
	 eff_DATA[iCut][iVar]->SetLineColor(kBlack);
	 eff_DATA[iCut][iVar]->SetLineWidth(2);
         eff_DATA[iCut][iVar]->SetMarkerStyle(20);
         
	 eff_DATA[iCut][iVar]->Draw();
	 Title=Form("%d_%d_efficiency_DATA_%d_%d", iCut+1, iVar, iCut, iVar);
	 c1.SetName(Title);
	 c1.Write();
	 
	 EfficiencyHisto[iCut][iVar]->GetYaxis()->SetRangeUser(0,EfficiencyHisto[iCut][iVar]->GetMaximum()+1.1*EfficiencyHisto[iCut][iVar]->GetBinError(EfficiencyHisto[iCut][iVar]->GetMaximumBin()));
         EfficiencyHisto[iCut][iVar]->Draw("E");
         Title = Form("%d_%d_efficiency_%d_%d",iCut+1,iVar,iCut,iVar); 
         c1.SetName(Title);
         c1.Write();
         
         EfficiencyHisto_ttbar[iCut][iVar]->GetYaxis()->SetRangeUser(0,EfficiencyHisto_ttbar[iCut][iVar]->GetMaximum()+1.1*EfficiencyHisto_ttbar[iCut][iVar]->GetBinError(EfficiencyHisto_ttbar[iCut][iVar]->GetMaximumBin()));
         EfficiencyHisto_ttbar[iCut][iVar]->Draw("E");
         Title = Form("%d_%d_efficiency_ttbar_%d_%d",iCut+1,iVar,iCut,iVar);
         c1.SetName(Title);
         c1.Write();
	 
	 PurityHisto[iCut][iVar]->Draw();
         Title=Form("%d_%d_Purity", iCut, iVar);
	 c1.SetName(Title);
	 c1.Write();
	 
	 PurityHisto[iCut+1][iVar]->Draw();
         Title=Form("%d_%d_Purity_%d_%d", iCut+1, iVar);
	 c1.SetName(Title);
	 c1.Write();
	 
       }
       
       if(Cuts.at(iCut)=="ttbar_Sig")
       {
	 TH1F * num_Sig= (TH1F*)stack[iCut][iVar]->GetStack()->Last();
	 TH1F * num_Sig_Rebinned;
	
	 num_Sig_Rebinned=DynamicalRebinHisto(num_Sig,num_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
         
	 num_Sig_Rebinned->SetFillStyle(3335);
         num_Sig_Rebinned->SetFillColor(kBlack);
         num_Sig_Rebinned->SetMarkerSize(0);
	 num_Sig_Rebinned->SetLineWidth(0);
	 
	 TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample);
	 stack_Rebinned[iCut][iVar]=DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar], isDATA, isDivide);
	 TH1F* num_DATA_Sig, *num_DATA_Sig_Rebinned; 
	 
	 for(int iSample=0;iSample<nameSample.size(); iSample++)
	 {
	   if(nameSample.at(iSample)=="DATA")
	   { 
	    isDATA=true;
	    
            num_DATA_Sig = (TH1F*) histo[iCut][iVar][iSample]->Clone("num_DATA_Sig");
	    num_DATA_Sig_Rebinned=DynamicalRebinHisto(num_DATA_Sig,num_DATA_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);

            num_DATA_Sig_Rebinned->SetMarkerColor(kBlack);
            num_DATA_Sig_Rebinned->SetLineColor(kBlack);
	    num_DATA_Sig_Rebinned->SetFillColor(kWhite);
            num_DATA_Sig_Rebinned->SetMarkerStyle(20);
	   
	    isDATA=false;
	  }
	 }
	 
	 ///==== Plot in different Canvas  
         TCanvas s1 ;   
	 
	 num_Sig_Rebinned->GetYaxis()->SetRangeUser(0,num_DATA_Sig_Rebinned->GetMaximum()+1.1*num_DATA_Sig_Rebinned->GetBinError(num_DATA_Sig_Rebinned->GetMaximumBin()));
         num_Sig_Rebinned->Draw("hist") ;
         stack_Rebinned[iCut][iVar]->Draw("same hist");
         num_Sig_Rebinned->Draw ("sameE2") ;
	 num_DATA_Sig_Rebinned->Draw("Esame");
	 legend->AddEntry(num_DATA_Sig_Rebinned, "DATA");
         legend->Draw();
         TString Title = Form("num_Sig_%d_%d_stack",iCut,iVar); 
         s1.SetName(Title);
         s1.Write();
          
       }
	   
       
	///=== Efficiency and purity for VBF selections   
       if(Cuts.at(iCut)=="VBF_noBtag" && Cuts.at(iCut+1)=="VBF_Btag")
       {
        TH1F * num_VBF = (TH1F*) stack[iCut+1][iVar]->GetStack()->Last();
	TH1F * num_VBF_Rebinned;
	num_VBF_Rebinned=DynamicalRebinHisto(num_VBF,num_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	num_VBF_Rebinned->SetFillStyle(3335);
        num_VBF_Rebinned->SetFillColor(kBlack);
        num_VBF_Rebinned->SetMarkerSize(0);
	num_VBF_Rebinned->SetLineWidth(0);
	
        TH1F * den_VBF = (TH1F*) stack[iCut][iVar]->GetStack()->Last();
	TH1F * den_VBF_Rebinned;
	den_VBF_Rebinned=DynamicalRebinHisto(den_VBF,den_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
        den_VBF_Rebinned->SetFillStyle(3335);
        den_VBF_Rebinned->SetFillColor(kBlack);
	den_VBF_Rebinned->SetLineWidth(0);
        den_VBF_Rebinned->SetMarkerSize(0);
	
        TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample);
        
	EfficiencyHisto[iCut][iVar]= (TH1F*) num_VBF_Rebinned->Clone("EfficiencyHisto");
        EfficiencyHisto[iCut][iVar]->Divide(den_VBF_Rebinned);
	stack_Rebinned[iCut][iVar]=DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
	stack_Rebinned[iCut+1][iVar]=DynamicalRebinStack(stack[iCut+1][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
	
        TH1F* num_ttbar_VBF, *den_ttbar_VBF, *den_top_VBF, *num_top_VBF,* num_DATA_VBF, *den_DATA_VBF;
        
	TH1F * num_ttbar_VBF_Rebinned, * den_ttbar_VBF_Rebinned, * num_top_VBF_Rebinned, * den_top_VBF_Rebinned, * num_DATA_VBF_Rebinned, * den_DATA_VBF_Rebinned;

	
	for(int iSample=0;iSample<nameSample.size(); iSample++)
        {
         if(nameSample.at(iSample)!="ttbar" && nameSample.at(iSample)!="top" && nameSample.at(iSample)!="DATA")continue;
	 
	 if(nameSample.at(iSample)=="ttbar")
	 {
	   
          num_ttbar_VBF = (TH1F*) histo[iCut+1][iVar][iSample]->Clone("num_ttbar_VBF");
          num_ttbar_VBF_Rebinned=DynamicalRebinHisto(num_ttbar_VBF,num_ttbar_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	  
	  den_ttbar_VBF = (TH1F*) histo[iCut][iVar][iSample]->Clone("den_ttbar_VBF");
	  den_ttbar_VBF_Rebinned=DynamicalRebinHisto(den_ttbar_VBF,den_ttbar_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	   
	 }
	 
	 	 
	 if(nameSample.at(iSample)=="top")
	 {
          num_top_VBF = (TH1F*)histo[iCut+1][iVar][iSample]->Clone("num_top_VBF");
          num_top_VBF_Rebinned=DynamicalRebinHisto(num_top_VBF,num_top_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	  
	  den_top_VBF =(TH1F*)histo[iCut][iVar][iSample]->Clone("den_top");
	  den_top_VBF_Rebinned=DynamicalRebinHisto(den_top_VBF,den_top_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	 }
	           
         if(nameSample.at(iSample)=="DATA")
	 { 
	   isDATA=true;
	   
           num_DATA_VBF = (TH1F*)histo[iCut+1][iVar][iSample]->Clone("num_DATA_VBF");
	   num_DATA_VBF_Rebinned=DynamicalRebinHisto(num_DATA_VBF,num_DATA_VBF_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);

	   den_DATA_VBF = (TH1F*)histo[iCut][iVar][iSample]->Clone("den_DATA_VBF");
	   den_DATA_VBF_Rebinned=DynamicalRebinHisto(den_DATA_VBF,den_DATA_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);

	   num_DATA_VBF_Rebinned->SetMarkerColor(kBlack);
           num_DATA_VBF_Rebinned->SetLineColor(kBlack);
	   num_DATA_VBF_Rebinned->SetFillColor(kWhite);
           num_DATA_VBF_Rebinned->SetMarkerStyle(20);
	   
	   den_DATA_VBF_Rebinned->SetMarkerColor(kBlack);
           den_DATA_VBF_Rebinned->SetFillColor(kWhite);
	   den_DATA_VBF_Rebinned->SetLineColor(kBlack);
           den_DATA_VBF_Rebinned->SetMarkerStyle(20);
	   
	   isDATA=false;
	   
	 }
        }  
        
         EfficiencyHisto_ttbar[iCut][iVar]= (TH1F*) num_ttbar_VBF_Rebinned->Clone("EfficiencyHisto_ttbar_VBF");
	 EfficiencyHisto_ttbar[iCut][iVar]->Add(num_top_VBF_Rebinned);
	 den_ttbar_VBF_Rebinned->Add(den_top_VBF_Rebinned);
         EfficiencyHisto_ttbar[iCut][iVar]->Divide(den_ttbar_VBF_Rebinned);
	 
	 PurityHisto[iCut+1][iVar]= (TH1F*) num_ttbar_VBF_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut+1][iVar]->Add(num_top_VBF_Rebinned);
	 PurityHisto[iCut+1][iVar]->Divide(num_VBF_Rebinned);
	 
	 PurityHisto[iCut][iVar]= (TH1F*) den_ttbar_VBF_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut][iVar]->Add(den_top_VBF_Rebinned);
	 PurityHisto[iCut][iVar]->Divide(den_VBF_Rebinned);
        
         TCanvas c2 ;   
         
	 num_VBF_Rebinned->GetYaxis()->SetRangeUser(0,num_DATA_VBF_Rebinned->GetMaximum()+num_DATA_VBF_Rebinned->GetBinError(num_DATA_VBF_Rebinned->GetMaximumBin()));
         num_VBF_Rebinned->Draw ("hist") ;
         stack_Rebinned[iCut+1][iVar]->Draw("same hist ");
         num_VBF_Rebinned->Draw ("E2same") ;
	 num_DATA_VBF_Rebinned->Draw("Esame");
         legend->Draw();
         TString Title = Form("num_VBF_%d_%d_stack",iCut+1,iVar); 
         c2.SetName(Title);
	 c2.Write();
         
	 den_VBF_Rebinned->GetYaxis()->SetRangeUser(0,den_DATA_VBF_Rebinned->GetMaximum()+den_DATA_VBF_Rebinned->GetBinError(den_DATA_VBF_Rebinned->GetMaximumBin()));
         den_VBF_Rebinned->Draw ("hist") ;
         stack_Rebinned[iCut][iVar]->Draw("same hist ");
         den_VBF_Rebinned->Draw ("E2same") ;
	 den_DATA_VBF_Rebinned->Draw("Esame");
         legend->Draw();
         Title = Form("den_VBF_%d_%d_stack",iCut,iVar); 
         c2.SetName(Title);
         c2.Write();
	     
	 EfficiencyHisto[iCut][iVar]->GetYaxis()->SetRangeUser(0,EfficiencyHisto[iCut][iVar]->GetMaximum()+1.1*EfficiencyHisto[iCut][iVar]->GetBinError(EfficiencyHisto[iCut][iVar]->GetMaximumBin()));
	 EfficiencyHisto[iCut][iVar]->Draw("E");
         Title = Form("%d_%d_efficiency_VBF_%d_%d",iCut+1,iVar,iCut,iVar); 
         c2.SetName(Title);
         c2.Write();
	
	 EfficiencyHisto_ttbar[iCut][iVar]->GetYaxis()->SetRangeUser(0,EfficiencyHisto_ttbar[iCut][iVar]->GetMaximum()+1.1*EfficiencyHisto_ttbar[iCut][iVar]->GetBinError(EfficiencyHisto_ttbar[iCut][iVar]->GetMaximumBin()));
         EfficiencyHisto_ttbar[iCut][iVar]->Draw("E");
         Title = Form("%d_%d_efficiency_ttbar_VBF_%d_%d",iCut+1,iVar,iCut,iVar); 
         c2.SetName(Title);
	 c2.Write();
	  
	 num_DATA_VBF_Rebinned=DynamicalRebinHisto(num_DATA_VBF,num_DATA_VBF_Rebinned,Bin_Extremes[iVar],true,false);
	 den_DATA_VBF_Rebinned=DynamicalRebinHisto(den_DATA_VBF,den_DATA_VBF_Rebinned,Bin_Extremes[iVar],true,false);
	 
	 eff_DATA[iCut][iVar]= new TEfficiency(*num_DATA_VBF_Rebinned,*den_DATA_VBF_Rebinned);
	 eff_DATA[iCut][iVar]->Bayesian(den_DATA_VBF->GetEntries(),num_DATA_VBF_Rebinned->GetEntries(),0.95,1,1,true,true);
	  
	 eff_DATA[iCut][iVar]->SetMarkerColor(kViolet);
         eff_DATA[iCut][iVar]->SetLineColor(kViolet);
         eff_DATA[iCut][iVar]->SetMarkerStyle(23);
	 eff_DATA[iCut][iVar]->SetLineWidth(2);
	 eff_DATA[iCut][iVar]->Draw("ALP");
	 Title=Form("%d_%d_efficiency_DATA_VBF%d_%d", iCut+1, iVar, iCut, iVar);
	 c2.SetName(Title);
	 c2.Write();
	 
	 PurityHisto[iCut][iVar]->Draw();
         Title=Form("%d_%d_Purity_VBF", iCut, iVar);
	 c2.SetName(Title);
	 c2.Write();
	 
	 PurityHisto[iCut+1][iVar]->Draw();
         Title=Form("%d_%d_Purity_VBF", iCut+1, iVar);
	 c2.SetName(Title);
	 c2.Write();
	 
       }
       
       if(Cuts.at(iCut)=="VBF_Sig")
       {
	 TH1F * num_VBF_Sig= (TH1F*)stack[iCut][iVar]->GetStack()->Last();
	 TH1F * num_VBF_Sig_Rebinned;
	 num_VBF_Sig_Rebinned=DynamicalRebinHisto(num_VBF_Sig,num_VBF_Sig_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
        	   
	 num_VBF_Sig_Rebinned->SetFillStyle(3335);
         num_VBF_Sig_Rebinned->SetFillColor(kBlack);
         num_VBF_Sig_Rebinned->SetMarkerSize(0);
	 num_VBF_Sig_Rebinned->SetLineWidth(0);
	 
	 TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample);
	 stack_Rebinned[iCut][iVar]=DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
	 TH1F* num_DATA_VBF_Sig, *num_DATA_VBF_Sig_Rebinned; 
	 
	 for(int iSample=0;iSample<nameSample.size(); iSample++)
	 {
	   if(nameSample.at(iSample)=="DATA")
	   {
	    isDATA=true;
	    
            num_DATA_VBF_Sig = (TH1F*) histo[iCut][iVar][iSample]->Clone("num_DATA_VBF_Sig");
	    num_DATA_VBF_Sig_Rebinned=DynamicalRebinHisto(num_DATA_VBF_Sig,num_DATA_VBF_Sig_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            
            num_DATA_VBF_Sig_Rebinned->SetMarkerColor(kBlack);
            num_DATA_VBF_Sig_Rebinned->SetLineColor(kBlack);
	    num_DATA_VBF_Sig_Rebinned->SetFillColor(kWhite);
            num_DATA_VBF_Sig_Rebinned->SetMarkerStyle(20);
	    
	    isDATA=false;

	   }
	 }
	 
	 ///==== Plot in different Canvas  
         TCanvas s2 ;   
	 
	 num_VBF_Sig_Rebinned->GetYaxis()->SetRangeUser(0,num_DATA_VBF_Sig_Rebinned->GetMaximum()+1.1*num_DATA_VBF_Sig_Rebinned->GetBinError(num_DATA_VBF_Sig_Rebinned->GetMaximumBin()));
         num_VBF_Sig_Rebinned->Draw("hist") ;
         stack_Rebinned[iCut][iVar]->Draw("same hist");
         num_VBF_Sig_Rebinned->Draw ("sameE2") ;
	 num_DATA_VBF_Sig_Rebinned->Draw("Esame");
	 legend->AddEntry(num_DATA_VBF_Sig_Rebinned, "DATA");
         legend->Draw();
         TString Title = Form("num_VBF_Sig_%d_%d_stack",iCut,iVar); 
         s2.SetName(Title);
         s2.Write();
          
       }
    }
 }
 
 
 
 
///===== Final Plot for efficiency comparison 
for(int iVar=0; iVar<Variable.size(); iVar++)
{
  if(Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(abs(q1_Eta))+(abs(q1_Eta)>=abs(q2_Eta))*(abs(q2_Eta))" && 
       Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(q1_pT)+(abs(q1_Eta)>=abs(q2_Eta))*(q2_pT)") continue;
  
  TCanvas c3;
  TLegend * leg =new TLegend(0.75,0.7,0.98,0.9);
  flag=0;
  
  for(int iCut=0; iCut<Cuts.size(); iCut++)
  {
 
   if(EfficiencyHisto[iCut][iVar]!=0 && EfficiencyHisto_ttbar[iCut][iVar] !=0)
    { EfficiencyHisto[iCut][iVar]->SetFillColor(kGreen);
      EfficiencyHisto[iCut][iVar]->SetMarkerColor(kGreen+2);
      EfficiencyHisto[iCut][iVar]->SetFillStyle(3002);
      EfficiencyHisto[iCut][iVar]->SetLineColor(kGreen);
      EfficiencyHisto[iCut][iVar]->SetMarkerStyle(22);
      EfficiencyHisto[iCut][iVar]->SetMarkerSize(2);
      EfficiencyHisto[iCut][iVar]->SetLineWidth(2);
    

      if(Cuts.at(iCut)=="ttbar_noBtag" && flag==0)
      {
       flag=1;
       EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerColor(kBlue+1);
       EfficiencyHisto_ttbar[iCut][iVar]->SetFillColor(kBlue);
       EfficiencyHisto_ttbar[iCut][iVar]->SetFillStyle(3001);
       EfficiencyHisto_ttbar[iCut][iVar]->SetLineColor(kBlue+1);
       EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerStyle(21);
       EfficiencyHisto_ttbar[iCut][iVar]->GetYaxis()->SetRangeUser(0,1);
       
       EfficiencyHisto_ttbar[iCut][iVar]->GetYaxis()->SetTitle("Efficiency");
       EfficiencyHisto_ttbar[iCut][iVar]->SetTitle(" Efficiency in Controlled Zone");
       EfficiencyHisto_ttbar[iCut][iVar]->Draw("E2");
       EfficiencyHisto[iCut][iVar]->Draw("E2same");
       eff_DATA[iCut][iVar]->Draw("Esame");
       leg->SetFillColor(kWhite);
       leg->AddEntry(EfficiencyHisto_ttbar[iCut][iVar],"eff on tt (MC) ","pl");
       leg->AddEntry(EfficiencyHisto[iCut][iVar], "eff on tot (MC) ","pl");
       leg->AddEntry(eff_DATA[iCut][iVar]," eff on DATA ","pl");
       TString Title = Form("Efficiency_Control_Zone_%s",Variable.at(iVar).first.c_str());
       leg->Draw();
       c3.SetName(Title);
       c3.Write();
       
       leg->Clear();
       leg->AddEntry(EfficiencyHisto[iCut][iVar], "eff on tot (MC) ","pl");
       EfficiencyHisto[iCut][iVar]->GetYaxis()->SetRangeUser(0,1);
       EfficiencyHisto[iCut][iVar]->GetYaxis()->SetTitle(" Efficiency");
       EfficiencyHisto[iCut][iVar]->SetTitle("Comparison Signal- Control Region");
       EfficiencyHisto[iCut][iVar]->Draw("E2");
      }

      
      if(flag!=0 && Cuts.at(iCut)=="VBF_noBtag")
      {

        EfficiencyHisto[iCut][iVar]->SetMarkerColor(kRed+1);
        EfficiencyHisto[iCut][iVar]->SetFillColor(kRed);
        EfficiencyHisto[iCut][iVar]->SetFillStyle(3004);
        EfficiencyHisto[iCut][iVar]->SetLineColor(kRed);
        EfficiencyHisto[iCut][iVar]->SetMarkerStyle(33);
	EfficiencyHisto[iCut][iVar]->SetMarkerSize(1.5);
	EfficiencyHisto[iCut][iVar]->Draw("E2same");
        leg->AddEntry(EfficiencyHisto[iCut][iVar],"eff on tot (MC), VBF","pl");
        TString Title = Form("Efficiency_Comparison_CZ/SZ_%s",Variable.at(iVar).first.c_str());
        leg->Draw();
        c3.SetName(Title);
        c3.Write();
 
      }
   }
 }
}

///==== Export in a txt file

std::ofstream outFile("/home/raffaele/Programmi/AnalysisPackage/AnalysisPackage_qqHWWlnulnu/test/Latinos/ttbar/Event_Dumper.txt",std::ios::out);
std::string edge;
std::string error;

for(int iVar=0; iVar<Variable.size(); iVar++)
{
   if(Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(abs(q1_Eta))+(abs(q1_Eta)>=abs(q2_Eta))*(abs(q2_Eta))" && 
       Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(q1_pT)+(abs(q1_Eta)>=abs(q2_Eta))*(q2_pT)") continue;
    
   bool isDATA=false;
   bool isDivide=false;
   
   outFile<<"####################"<<std::endl;
   outFile<<"#"<< Variable.at(iVar).first<<std::endl;
   outFile<<"####################"<<std::endl;
   
   for(int iBin=0; iBin<Bin_Extremes[iVar].size(); iBin++)
   {
    std::ostringstream ss;
    ss<<Bin_Extremes[iVar].at(iBin);
    edge=edge+' '+' '+(ss.str());
    
    }

   
   outFile<<"# Binning edge "<<std::endl;
   outFile<<edge<<std::endl;
   outFile<<"#--------------------------"<<std::endl;
   
  for(int iCut=0; iCut<Cuts.size(); iCut++)
  {
    if(Cuts.at(iCut)=="ttbar_noBtag" && Cuts.at(iCut+1)=="ttbar_Btag")
    {
        TH1F * num = (TH1F*) stack[iCut+1][iVar]->GetStack()->Last();
	TH1F * num_Rebinned;
	num_Rebinned=DynamicalRebinHisto(num,num_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
        TH1F * den = (TH1F*) stack[iCut][iVar]->GetStack()->Last();
	TH1F * den_Rebinned;
	den_Rebinned=DynamicalRebinHisto(den,den_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
        
	TH1F* num_DATA, *den_DATA;
	TH1F* num_DATA_Rebinned, *den_DATA_Rebinned;
	
     for(int iSample=0; iSample<nameSample.size(); iSample++)
     {
       if(nameSample.at(iSample)=="DATA")
	   {
	    num_DATA = (TH1F*) histo[iCut+1][iVar][iSample]->Clone("num_DATA");
	    num_DATA_Rebinned=DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            
	    den_DATA = (TH1F*) histo[iCut][iVar][iSample]->Clone("den_DATA");
	    den_DATA_Rebinned=DynamicalRebinHisto(den_DATA,den_DATA_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            
	   }
     }
     
     ///====================================================
     
     outFile<<"# Events after preselection Cuts "<<std::endl;
     
     edge.clear();
     
     for(int iBin=0; iBin<den_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<den_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<den_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#    MC A+B     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
     for(int iBin=0; iBin<den_DATA_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<den_DATA_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<den_DATA_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      DATA A+B     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
     for(int iBin=0; iBin<num_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<num_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<num_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      MC B     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
     for(int iBin=0; iBin<num_DATA_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss, se;
       ss<<num_DATA_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<num_DATA_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      DATA B     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
    
    
   }
   
   if(Cuts.at(iCut)=="ttbar_Sig")
   {
     TH1F * num_Sig= (TH1F*)stack[iCut][iVar]->GetStack()->Last();
     TH1F * num_Sig_Rebinned;
     num_Sig_Rebinned=DynamicalRebinHisto(num_Sig,num_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
    
     TH1F* num_DATA_Sig, *num_DATA_Sig_Rebinned; 
	 
     for(int iSample=0;iSample<nameSample.size(); iSample++)
      {
	   if(nameSample.at(iSample)=="DATA")
	   { 
	    
	    num_DATA_Sig = (TH1F*) histo[iCut][iVar][iSample]->Clone("num_DATA_Sig");
	    num_DATA_Sig_Rebinned=DynamicalRebinHisto(num_DATA_Sig,num_DATA_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	    
	  }
	 }
     
     edge.clear();     
     for(int iBin=0; iBin<num_Sig_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<num_Sig_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<num_Sig_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      MC A     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
  
     for(int iBin=0; iBin<num_DATA_Sig_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss, se;
       ss<<num_DATA_Sig_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<num_DATA_Sig_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      DATA A     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
     
  }
 ///=================================================
  
 if(Cuts.at(iCut)=="VBF_noBtag" && Cuts.at(iCut+1)=="VBF_Btag")
    {
        TH1F * num_VBF = (TH1F*) stack[iCut+1][iVar]->GetStack()->Last();
	TH1F * num_VBF_Rebinned;
	num_VBF_Rebinned=DynamicalRebinHisto(num_VBF,num_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
        TH1F * den_VBF = (TH1F*) stack[iCut][iVar]->GetStack()->Last();
	TH1F * den_VBF_Rebinned;
	den_VBF_Rebinned=DynamicalRebinHisto(den_VBF,den_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
        
	TH1F* num_DATA_VBF, *den_DATA_VBF;
	TH1F* num_DATA_VBF_Rebinned, *den_DATA_VBF_Rebinned;
	
     for(int iSample=0; iSample<nameSample.size(); iSample++)
     {
       if(nameSample.at(iSample)=="DATA")
	   {
            num_DATA_VBF = (TH1F*) histo[iCut+1][iVar][iSample]->Clone("num_DATA_VBF");
	    num_DATA_VBF_Rebinned=DynamicalRebinHisto(num_DATA_VBF,num_DATA_VBF_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            
	    den_DATA_VBF = (TH1F*) histo[iCut][iVar][iSample]->Clone("den_DATA_VBF");
	    den_DATA_VBF_Rebinned=DynamicalRebinHisto(den_DATA_VBF,den_DATA_VBF_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);	    
	    
	     
	  }
     }
    
     outFile<<" Events after VBF Cuts region "<<std::endl;
     edge.clear();
     
     for(int iBin=0; iBin<den_VBF_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<den_VBF_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<den_VBF_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      MC A+B     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
     for(int iBin=0; iBin<den_DATA_VBF_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<den_DATA_VBF_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<den_DATA_VBF_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     
     }
     
     outFile<<"#      DATA A+B     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
     for(int iBin=0; iBin<num_VBF_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<num_VBF_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<num_VBF_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      MC B     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
     for(int iBin=0; iBin<num_DATA_VBF_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<num_DATA_VBF_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<num_DATA_VBF_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      DATA B     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
    
   }
   
   if(Cuts.at(iCut)=="VBF_Sig")
   {
     TH1F * num_VBF_Sig= (TH1F*)stack[iCut][iVar]->GetStack()->Last();
     TH1F * num_VBF_Sig_Rebinned;
     num_VBF_Sig_Rebinned=DynamicalRebinHisto(num_VBF_Sig,num_VBF_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
    
     TH1F* num_DATA_VBF_Sig, *num_DATA_VBF_Sig_Rebinned; 
	 
     for(int iSample=0;iSample<nameSample.size(); iSample++)
      {
	   if(nameSample.at(iSample)=="DATA")
	   { 
	    
	    num_DATA_VBF_Sig = (TH1F*) histo[iCut][iVar][iSample]->Clone("num_DATA_VBF_Sig");
	    num_DATA_VBF_Sig_Rebinned=DynamicalRebinHisto(num_DATA_VBF_Sig,num_DATA_VBF_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	    
	  }
	 }
     
    
     for(int iBin=0; iBin<num_VBF_Sig_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<num_VBF_Sig_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<num_VBF_Sig_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      MC A     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
     for(int iBin=0; iBin<num_DATA_VBF_Sig_Rebinned->GetNbinsX(); iBin++)
     {     
       std::ostringstream ss,se;
       ss<<num_DATA_VBF_Sig_Rebinned->GetBinContent(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<num_DATA_VBF_Sig_Rebinned->GetBinError(iBin+1);
       error=error+' '+' '+(se.str());
     }
     
     outFile<<"#      DATA A     "<<std::endl;
     outFile<<edge<<std::endl;
     outFile<<error<<std::endl;          
     edge.clear();
     error.clear();
     
     
  }

  
 }
}
return(0);

}
