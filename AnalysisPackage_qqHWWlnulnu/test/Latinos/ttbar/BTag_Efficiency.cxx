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
#include "/home/raffaele/Programmi/AnalysisPackage/AnalysisPackage_qqHWWlnulnu/test/TDRStyle.cc"
#include "/home/raffaele/Programmi/AnalysisPackage/AnalysisPackage_qqHWWlnulnu/test/Read.cc"
#include "/home/raffaele/Programmi/AnalysisPackage/AnalysisPackage_qqHWWlnulnu/test/Latinos/ttbar/plotUtils.C"


///==== Macros input are: input file name, output file name, output dumper file

int BTag_Efficiency(TString input, TString output, TString dumper)
{
 
 ///===== Vector of Color used in the Plot, taken from test/MCDATAComparisonPLOTTool.cpp
   
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
//   kAzure,
//   kWhite,
  kTeal,
  kYellow,
  kGreen,
  (EColor) (kTeal+1),
  (EColor) (kOrange+2),
  (EColor) (kGreen+2),
  kGray,(EColor) (kGray+1),(EColor) (kViolet),(EColor) (kYellow),(EColor) (kGray)
 };
 
 ///=== Open the input ROOT File from test/MCDATAComparisonPLOTTool.cpp
 
 TFile * Input_File = TFile::Open(input.Data());

 std::vector<std::string> nameSample;
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
 
///===== Acuisition info from txt file: Name of the samples, Cut applied and Variables of Plot and their binning
 
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
  if(buffer =="[SampleName]") continue;
  if (buffer=="[Cut]") flag=1;
  if(buffer=="[Variables]") flag=2;
  if(buffer=="[Number_Closure_Test]") flag=3;
  
  if(flag==0 && buffer !="" && buffer!="[SampleName]")
  {
    if (buffer.at(0)!='#')
    {
      line>>sample_temp;
      std::cout<<"Sample:"<<"   "<<sample_temp<<std::endl;
      nameSample.push_back(sample_temp); ///== vector with samples name according to the standard of MCDATAComparisonPLOTTool.cpp
    }
  }
  
  if(flag==1 && buffer!="" && buffer!="[Cut]")
  {
    if (buffer.at(0)!='#') {line>>sample_temp;
                            Cuts.push_back(sample_temp); ///== Vector with the ID name for each cut applied
       
                            }
  }
  

  if(flag==2 && buffer!="" && buffer!="[Variables]" && flag2==1) ///== binning vector acquisition
  {
    if(buffer.at(0)!='#') { 
                            if(buffer==sample_temp) continue;
			    std::string strtemp;
			    
			    for(int iBuf=0; iBuf<buffer.size(); iBuf++)
			    {  
			      if(buffer.at(iBuf)!=' ')
			      {
			        strtemp=strtemp+buffer.at(iBuf);
				
			      }
			      else{
				   float f =(float) atof(strtemp.c_str()); 
				   row.push_back(f);
				   strtemp.clear();}
			    } 
                         }
                         
    ///=== Vector fill with the information for the binning applied for each variable                     
    Bin_Extremes.push_back(row);
    row.clear();
    flag2=0;
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
				  sample_temp=sample_temp+buffer.at(iBuf);
				}
				else{
				      if(k==0)
				      { temp.first=sample_temp;
				        temp.second=iPoint;
				        k++;
				        sample_temp.clear();
				      }
				}
			      }
                              
			      Variable.push_back(temp);
			      
                              nameHumanVariable.push_back(sample_temp);
			      
			      std::cout<<"Variable Used:"<<"      "<<temp.first<<"    "<<"Name Human Variable:"<<"  "<<sample_temp<<std::endl;
			      
			      iPoint++;
                              flag2=1;
			      continue;
    }
  }

if(flag==3 && buffer !="" && buffer!="[Number_Closure_Test]")
  {
    if (buffer.at(0)!='#')
    {
      line>>sample_temp;
      std::cout<<"Number Closure Test :"<<"    "<<sample_temp<<std::endl;
      Closure_Number=(int) atoi(sample_temp.c_str());
    }
  }
  
  
}

///=== Acquisition from the input file of the object: stack and histogramms 

TH1D* histo [100][100][100];
THStack* stack[100][100];
TCanvas* canvas[100][100];

 for(int iCut=0; iCut<Cuts.size();iCut++)
 {  
  for(int iVar=0; iVar<Variable.size();iVar++)
   {
     for(int iSample=0; iSample<nameSample.size(); iSample++)
     {    
        TString histo_name =Form("Data/%s_%d_%d_Tot_temp", nameSample.at(iSample).c_str(), iCut, iVar);
        histo[iCut][iVar][iSample] = (TH1D*) Input_File->Get(histo_name);
     }
     TString stack_name= Form("Data/%d_%d_stack", iCut, iVar);
     stack[iCut][iVar]= (THStack*)Input_File->Get(stack_name);
     TString Canvas_name= Form("All/Var/%d_%d_Canvas", iCut, iVar);
     canvas[iCut][iVar]=(TCanvas*) Input_File->Get(Canvas_name);
    
   }
 } 
 


///=== Efficiency Evaluation

TH1D* EfficiencyHisto[100][100];
TH1D* EfficiencyHisto_ttbar[100][100];
TH1D* PurityHisto[100][100];
THStack* stack_Rebinned[100][100];
TEfficiency* eff_DATA[100][100];


for(int iVar=0; iVar< Variable.size(); iVar++)
 { 

   ///====== Variable selection
    
    if(Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(abs(q1_Eta))+(abs(q1_Eta)>=abs(q2_Eta))*(abs(q2_Eta))" && 
       Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(q1_pT)+(abs(q1_Eta)>=abs(q2_Eta))*(q2_pT)")
       continue;
     
    output_Plott.cd();
    TDirectory* cdAll = (TDirectory*) output_Plott.mkdir(nameHumanVariable.at(iVar).c_str());
    cdAll->mkdir("Efficiency_Study");
    cdAll->mkdir("Closure_Test");
    TString way=Form("%s/Efficiency_Study",nameHumanVariable.at(iVar).c_str());
    output_Plott.cd(way);
    
    for(int iCut=0; iCut<Cuts.size(); iCut++)
    {  
      	bool isDATA =false;
	bool isDivide =true;
	
       ///==== Efficiency analysis in the control region 
       
       if(Cuts.at(iCut)=="Efficiency_Zone" && Cuts.at(iCut+1)=="Efficiency_Zone_Btag") /// Check for the right pair of cuts
       {

        TH1D * num = (TH1D*) stack[iCut+1][iVar]->GetStack()->Last();
	TH1D * num_Rebinned; 
	num_Rebinned=DynamicalRebinHisto(num,num_Rebinned,Bin_Extremes[iVar],isDATA, isDivide); ///== Dynamical Rebin of the Histogram with the new binning defined in Bin_Extremes[iVar],
	num_Rebinned->SetFillStyle(3335);
        num_Rebinned->SetFillColor(kBlack);
       
	///=== isData is a bool variable that indicates if we work on data sample, isDivide if we want to divide the bin content for the bin width
	///=== For the implementation See PlotUtils.c
        
        TH1D * den = (TH1D*) stack[iCut][iVar]->GetStack()->Last();
	TH1D * den_Rebinned;
	
	den_Rebinned=DynamicalRebinHisto(den,den_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	den_Rebinned->SetFillStyle(3335);
        den_Rebinned->SetFillColor(kBlack);
       
	TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample); ///=== See PlotUtils.C
        
        ///==== Total Efficiency Distriubution for each Cut and Variables
	
	EfficiencyHisto[iCut][iVar]= (TH1D*) num_Rebinned->Clone("EfficiencyHisto");
        EfficiencyHisto[iCut][iVar]->Divide(den_Rebinned);
	
	///==== Dynamical rebin for the stack, see PlotUtils.C
	
	stack_Rebinned[iCut][iVar]=DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
	stack_Rebinned[iCut+1][iVar]=DynamicalRebinStack(stack[iCut+1][iVar],stack_Rebinned[iCut+1][iVar],Bin_Extremes[iVar],isDATA,isDivide);

	///==== Efficiency on top and DATA samples
       
	TH1D* num_ttbar, *den_ttbar, *num_top, *den_top,*num_DATA, *den_DATA;
	TH1D * num_ttbar_Rebinned, * den_ttbar_Rebinned,* num_top_Rebinned, * den_top_Rebinned, * num_DATA_Rebinned, * den_DATA_Rebinned;

	
	for(int iSample=0;iSample<nameSample.size(); iSample++)
        {
	  
         if(nameSample.at(iSample)!="ttbar" && nameSample.at(iSample)!="top" && nameSample.at(iSample)!="DATA") continue;
	 
	 if(nameSample.at(iSample)=="ttbar")
	 { 
          num_ttbar = (TH1D*) histo[iCut+1][iVar][iSample]->Clone("num_ttbar");
	  num_ttbar_Rebinned=DynamicalRebinHisto(num_ttbar,num_ttbar_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
	  
	  den_ttbar = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_ttbar");
	  den_ttbar_Rebinned=DynamicalRebinHisto(den_ttbar,den_ttbar_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	 }
          
         if(nameSample.at(iSample)=="top")
	 {
	  num_top = (TH1D*)histo[iCut+1][iVar][iSample]->Clone("num_top");
          num_top_Rebinned=DynamicalRebinHisto(num_top,num_top_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	  
	  den_top =(TH1D*)histo[iCut][iVar][iSample]->Clone("den_top");
	  den_top_Rebinned=DynamicalRebinHisto(den_top,den_top_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
          }

         if(nameSample.at(iSample)=="DATA")
	 { 
	   isDATA=true;
	   
	   num_DATA = (TH1D*)histo[iCut+1][iVar][iSample]->Clone("num_DATA");
	   num_DATA_Rebinned=DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);

	   den_DATA = (TH1D*)histo[iCut][iVar][iSample]->Clone("den_DATA");
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
         
         EfficiencyHisto_ttbar[iCut][iVar]= (TH1D*) num_ttbar_Rebinned->Clone("EfficiencyHisto_ttbar");
	 EfficiencyHisto_ttbar[iCut][iVar]->Add(num_top_Rebinned);
	 den_ttbar_Rebinned->Add(den_top_Rebinned);
	 EfficiencyHisto_ttbar[iCut][iVar]->Divide(den_ttbar_Rebinned);
	 
	 ///==== Purtity Distribution in the total and Btag Efficiency Zone
	 
	 PurityHisto[iCut+1][iVar]= (TH1D*) num_ttbar_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut+1][iVar]->Add(num_top_Rebinned);
	 PurityHisto[iCut+1][iVar]->Divide(num_Rebinned);
	 
	 PurityHisto[iCut][iVar]= (TH1D*) den_ttbar_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut][iVar]->Divide(den_Rebinned);
	 
	 ///==== Plot in different Canvas  
	 
         TCanvas c1 ; 
	 
	 num_Rebinned->GetYaxis()->SetRangeUser(0,num_DATA_Rebinned->GetMaximum()+1.1*num_DATA_Rebinned->GetBinError(num_DATA_Rebinned->GetMaximumBin()));
         num_Rebinned->SetTitle(" Efficiency Region B-Tag ");
	 num_Rebinned->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 num_Rebinned->GetYaxis()->SetTitle("Events/BinWidth");
	 
	 num_Rebinned->Draw("hist");
	 stack_Rebinned[iCut+1][iVar]->Draw("same hist");
	 num_Rebinned->Draw("E2same");
         num_DATA_Rebinned->Draw("Esame");
	 
	 legend->AddEntry(num_DATA_Rebinned, "DATA");
         legend->Draw();
	 
         TString Title = Form("num_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str()); 
         c1.SetName(Title);
         c1.Write();
         
	 den_Rebinned->GetYaxis()->SetRangeUser(0,den_DATA_Rebinned->GetMaximum()+1.1*den_DATA_Rebinned->GetBinError(den_DATA_Rebinned->GetMaximumBin()));
         den_Rebinned->SetTitle(" Efficiency Region ");
	 den_Rebinned->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 den_Rebinned->GetYaxis()->SetTitle("Events/BinWidth");
	 
	 den_Rebinned->Draw ("hist") ;
         stack_Rebinned[iCut][iVar]->Draw("same hist ");
         den_Rebinned->Draw ("E2same") ;
	 den_DATA_Rebinned->Draw("Esame");
         
	 legend->Draw();
         Title = Form("den_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut).c_str());  
         c1.SetName(Title);
         c1.Write();
         
         num_DATA_Rebinned=DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes[iVar],true,false);
	 den_DATA_Rebinned=DynamicalRebinHisto(den_DATA,den_DATA_Rebinned,Bin_Extremes[iVar],true,false);
	 
	 eff_DATA[iCut][iVar]= new TEfficiency(*num_DATA_Rebinned,*den_DATA_Rebinned);
	 eff_DATA[iCut][iVar]->Bayesian(den_DATA->GetEntries(),num_DATA->GetEntries(),0.68,1,1,false,true);
	 eff_DATA[iCut][iVar]->SetMarkerColor(kBlack);
	 eff_DATA[iCut][iVar]->SetLineColor(kBlack);
	 eff_DATA[iCut][iVar]->SetLineWidth(2);
         eff_DATA[iCut][iVar]->SetMarkerStyle(20);
	 eff_DATA[iCut][iVar]->Draw("AP");
	 
	 Title=Form("efficiency_DATA_%s_%s/%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str(),Cuts.at(iCut).c_str());
	 c1.SetName(Title);
	 c1.Write();
	 
	 EfficiencyHisto[iCut][iVar]->GetYaxis()->SetRangeUser(0,EfficiencyHisto[iCut][iVar]->GetMaximum()+1.1*EfficiencyHisto[iCut][iVar]->GetBinError(EfficiencyHisto[iCut][iVar]->GetMaximumBin()));
         EfficiencyHisto[iCut][iVar]->Draw("E");
         Title = Form("efficiency_%s_%s/%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str(),Cuts.at(iCut).c_str()); 
         c1.SetName(Title);
         c1.Write();
         
         EfficiencyHisto_ttbar[iCut][iVar]->GetYaxis()->SetRangeUser(0,EfficiencyHisto_ttbar[iCut][iVar]->GetMaximum()+1.1*EfficiencyHisto_ttbar[iCut][iVar]->GetBinError(EfficiencyHisto_ttbar[iCut][iVar]->GetMaximumBin()));
         EfficiencyHisto_ttbar[iCut][iVar]->Draw("E");
         Title = Form("efficiency_ttbar_%s_%s/%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str(),Cuts.at(iCut).c_str());
         c1.SetName(Title);
         c1.Write();
	 
	 
	 PurityHisto[iCut][iVar]->GetYaxis()->SetRangeUser(0,PurityHisto[iCut+1][iVar]->GetMaximum()+0.5);
	 PurityHisto[iCut][iVar]->SetTitle("Purity in the Efficiency Region");
	 PurityHisto[iCut][iVar]->SetLineColor(kBlack);
	 PurityHisto[iCut][iVar]->SetMarkerColor(kRed);
	 PurityHisto[iCut][iVar]->SetMarkerStyle(20);
	 PurityHisto[iCut][iVar]->SetLineWidth(2);
	 PurityHisto[iCut][iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 PurityHisto[iCut][iVar]->GetYaxis()->SetTitle("Purity");
	 PurityHisto[iCut][iVar]->Draw("E");
	 
         Title=Form("Purity_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut).c_str());
	 c1.SetName(Title);
	 c1.Write();
	 
	 PurityHisto[iCut+1][iVar]->GetYaxis()->SetRangeUser(0,PurityHisto[iCut][iVar]->GetMaximum()+0.5);
	 PurityHisto[iCut+1][iVar]->SetTitle("Purity in the B-Tag Efficiency Region ");
	 PurityHisto[iCut+1][iVar]->SetLineColor(kBlack);
	 PurityHisto[iCut+1][iVar]->SetMarkerColor(kRed);
	 PurityHisto[iCut+1][iVar]->SetMarkerStyle(20);
	 PurityHisto[iCut+1][iVar]->SetLineWidth(2);
	 PurityHisto[iCut+1][iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 PurityHisto[iCut+1][iVar]->GetYaxis()->SetTitle("Purity");
	 PurityHisto[iCut+1][iVar]->Draw("E");
	 
	 Title=Form("Purity_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str());
	 c1.SetName(Title);
	 c1.Write();
	 
       }
       
       if(Cuts.at(iCut)=="Efficiency_Zone_noBtag") ///=== no btag part of the efficiency region
       {
	 TH1D * num_Sig= (TH1D*)stack[iCut][iVar]->GetStack()->Last();
	 TH1D * num_Sig_Rebinned;
	
	 num_Sig_Rebinned=DynamicalRebinHisto(num_Sig,num_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
         
	 num_Sig_Rebinned->SetFillStyle(3335);
         num_Sig_Rebinned->SetFillColor(kBlack);
         
	 TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample);
	 
	 stack_Rebinned[iCut][iVar]=DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar], isDATA, isDivide);
	 
	 TH1D* num_DATA_Sig, *num_DATA_Sig_Rebinned; 
	 TH1D* num_ttbar_Sig,*num_ttbar_Sig_Rebinned, *num_top_Sig, *num_top_Sig_Rebinned;
	 
	 for(int iSample=0;iSample<nameSample.size(); iSample++)
	 {
	   if(nameSample.at(iSample)!="ttbar" && nameSample.at(iSample)!="top" && nameSample.at(iSample)!="DATA") continue;
	 
	   if(nameSample.at(iSample)=="ttbar")
	   { 
            num_ttbar_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_ttbar_Sig");
	    num_ttbar_Sig_Rebinned=DynamicalRebinHisto(num_ttbar_Sig,num_ttbar_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
	   }
          
           if(nameSample.at(iSample)=="top")
	   {
	    num_top_Sig = (TH1D*)histo[iCut][iVar][iSample]->Clone("num_top_Sig");
            num_top_Sig_Rebinned=DynamicalRebinHisto(num_top_Sig,num_top_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	   }

	   
	   if(nameSample.at(iSample)=="DATA")
	   { 
	    isDATA=true;
	    
            num_DATA_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_DATA_Sig");
	    num_DATA_Sig_Rebinned=DynamicalRebinHisto(num_DATA_Sig,num_DATA_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);

            num_DATA_Sig_Rebinned->SetMarkerColor(kBlack);
            num_DATA_Sig_Rebinned->SetLineColor(kBlack);
	    num_DATA_Sig_Rebinned->SetFillColor(kWhite);
            num_DATA_Sig_Rebinned->SetMarkerStyle(20);
	   
	    isDATA=false;
	  }
	 }
	 
	 ///==== Purtity Even
	 PurityHisto[iCut][iVar]= (TH1D*) num_ttbar_Sig_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut][iVar]->Add(num_top_Sig_Rebinned);
	 PurityHisto[iCut][iVar]->Divide(num_Sig_Rebinned);
	 
	 ///==== Plot in different Canvas  
         TCanvas s1 ;   
	 
	 num_Sig_Rebinned->GetYaxis()->SetRangeUser(0,num_DATA_Sig_Rebinned->GetMaximum()+1.1*num_DATA_Sig_Rebinned->GetBinError(num_DATA_Sig_Rebinned->GetMaximumBin()));
         num_Sig_Rebinned->SetTitle(" Efficiency Region no B-Tag ");
	 num_Sig_Rebinned->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 num_Sig_Rebinned->GetYaxis()->SetTitle("Events/BinWidth");
	 
	 num_Sig_Rebinned->Draw("hist") ;
         stack_Rebinned[iCut][iVar]->Draw("same hist");
         num_Sig_Rebinned->Draw ("sameE2") ;
	 num_DATA_Sig_Rebinned->Draw("Esame");
	 legend->AddEntry(num_DATA_Sig_Rebinned, "DATA");
         legend->Draw();
         
	 TString Title = Form("num_Sig_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut).c_str()); 
         s1.SetName(Title);
         s1.Write();
	 
	 
	 PurityHisto[iCut][iVar]->GetYaxis()->SetRangeUser(0,PurityHisto[iCut][iVar]->GetMaximum()+0.5);
	 PurityHisto[iCut][iVar]->SetTitle("Purity in the no B-Tag Efficiency");
	 PurityHisto[iCut][iVar]->SetLineColor(kBlack);
	 PurityHisto[iCut][iVar]->SetMarkerColor(kRed);
         PurityHisto[iCut][iVar]->SetMarkerStyle(20);
	 PurityHisto[iCut][iVar]->SetLineWidth(2);
	 PurityHisto[iCut][iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 PurityHisto[iCut][iVar]->GetYaxis()->SetTitle("Purity");
	 PurityHisto[iCut][iVar]->Draw("E");
	 
         Title=Form("Purity_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut).c_str());
	 s1.SetName(Title);
	 s1.Write();
          
	  
       }
	   
       
	///=== Efficiency and purity after VBF selections 
	
       if(Cuts.at(iCut)=="VBF_Zone" && Cuts.at(iCut+1)=="VBF_Zone_Btag")
       {
        
	TH1D * num_VBF = (TH1D*) stack[iCut+1][iVar]->GetStack()->Last();
	TH1D * num_VBF_Rebinned;
	num_VBF_Rebinned=DynamicalRebinHisto(num_VBF,num_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
	num_VBF_Rebinned->SetFillStyle(3335);
        num_VBF_Rebinned->SetFillColor(kBlack);
       
        TH1D * den_VBF = (TH1D*) stack[iCut][iVar]->GetStack()->Last();
	TH1D * den_VBF_Rebinned;
	den_VBF_Rebinned=DynamicalRebinHisto(den_VBF,den_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
        den_VBF_Rebinned->SetFillStyle(3335);
        den_VBF_Rebinned->SetFillColor(kBlack);
	
        TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample);
        
	///=== Efficiency VBF Region 
	EfficiencyHisto[iCut][iVar]= (TH1D*) num_VBF_Rebinned->Clone("EfficiencyHisto");
        EfficiencyHisto[iCut][iVar]->Divide(den_VBF_Rebinned);
	
	stack_Rebinned[iCut][iVar]=DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
	stack_Rebinned[iCut+1][iVar]=DynamicalRebinStack(stack[iCut+1][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
	
        TH1D* num_ttbar_VBF, *den_ttbar_VBF, *den_top_VBF, *num_top_VBF,* num_DATA_VBF, *den_DATA_VBF;
	TH1D * num_ttbar_VBF_Rebinned, * den_ttbar_VBF_Rebinned, * num_top_VBF_Rebinned, * den_top_VBF_Rebinned, * num_DATA_VBF_Rebinned, * den_DATA_VBF_Rebinned;

	
	for(int iSample=0;iSample<nameSample.size(); iSample++)
        {
         if(nameSample.at(iSample)!="ttbar" && nameSample.at(iSample)!="top" && nameSample.at(iSample)!="DATA")continue;
	 
	 if(nameSample.at(iSample)=="ttbar")
	 {
	   
          num_ttbar_VBF = (TH1D*) histo[iCut+1][iVar][iSample]->Clone("num_ttbar_VBF");
          num_ttbar_VBF_Rebinned=DynamicalRebinHisto(num_ttbar_VBF,num_ttbar_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	  
	  den_ttbar_VBF = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_ttbar_VBF");
	  den_ttbar_VBF_Rebinned=DynamicalRebinHisto(den_ttbar_VBF,den_ttbar_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	   
	 }
	 
	 	 
	 if(nameSample.at(iSample)=="top")
	 {
          num_top_VBF = (TH1D*)histo[iCut+1][iVar][iSample]->Clone("num_top_VBF");
          num_top_VBF_Rebinned=DynamicalRebinHisto(num_top_VBF,num_top_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	  
	  den_top_VBF =(TH1D*)histo[iCut][iVar][iSample]->Clone("den_top");
	  den_top_VBF_Rebinned=DynamicalRebinHisto(den_top_VBF,den_top_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	 }
	           
         if(nameSample.at(iSample)=="DATA")
	 { 
	   isDATA=true;
	   
           num_DATA_VBF = (TH1D*)histo[iCut+1][iVar][iSample]->Clone("num_DATA_VBF");
	   num_DATA_VBF_Rebinned=DynamicalRebinHisto(num_DATA_VBF,num_DATA_VBF_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);

	   den_DATA_VBF = (TH1D*)histo[iCut][iVar][iSample]->Clone("den_DATA_VBF");
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
        
         ///=== Effciency top background VBF Region
         
         EfficiencyHisto_ttbar[iCut][iVar]= (TH1D*) num_ttbar_VBF_Rebinned->Clone("EfficiencyHisto_ttbar_VBF");
	 EfficiencyHisto_ttbar[iCut][iVar]->Add(num_top_VBF_Rebinned);
	 den_ttbar_VBF_Rebinned->Add(den_top_VBF_Rebinned);
         EfficiencyHisto_ttbar[iCut][iVar]->Divide(den_ttbar_VBF_Rebinned);
	 
	 ///=== Purity Distributions
	 
	 PurityHisto[iCut+1][iVar]= (TH1D*) num_ttbar_VBF_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut+1][iVar]->Add(num_top_VBF_Rebinned);
	 PurityHisto[iCut+1][iVar]->Divide(num_VBF_Rebinned);
	 
	 PurityHisto[iCut][iVar]= (TH1D*) den_ttbar_VBF_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut][iVar]->Divide(den_VBF_Rebinned);
        
         TCanvas c2 ;   
         
	 num_VBF_Rebinned->GetYaxis()->SetRangeUser(0,num_DATA_VBF_Rebinned->GetMaximum()+num_DATA_VBF_Rebinned->GetBinError(num_DATA_VBF_Rebinned->GetMaximumBin()));
         num_VBF_Rebinned->SetTitle("VBF Control Region");
	 num_VBF_Rebinned->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 num_VBF_Rebinned->GetYaxis()->SetTitle("Events/BinWidth");
	 
	 num_VBF_Rebinned->Draw ("hist") ;
         stack_Rebinned[iCut+1][iVar]->Draw("same hist ");
         num_VBF_Rebinned->Draw ("E2same") ;
	 num_DATA_VBF_Rebinned->Draw("Esame");
         
	 legend->AddEntry(num_DATA_VBF_Rebinned, "DATA");
	 legend->Draw();
        
	 TString Title = Form("num_VBF_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str()); 
         c2.SetName(Title);
	 c2.Write();
         
	 den_VBF_Rebinned->GetYaxis()->SetRangeUser(0,den_DATA_VBF_Rebinned->GetMaximum()+den_DATA_VBF_Rebinned->GetBinError(den_DATA_VBF_Rebinned->GetMaximumBin()));
         den_VBF_Rebinned->SetTitle(" VBF Region ");
	 den_VBF_Rebinned->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 den_VBF_Rebinned->GetYaxis()->SetTitle("Events/BinWidth");
	 den_VBF_Rebinned->Draw ("hist") ;
         stack_Rebinned[iCut][iVar]->Draw("same hist ");
         den_VBF_Rebinned->Draw ("E2same") ;
	 den_DATA_VBF_Rebinned->Draw("Esame");
         
	 legend->Draw();
         Title = Form("den_VBF_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut).c_str()); 
         c2.SetName(Title);
         c2.Write();
	     
	 EfficiencyHisto[iCut][iVar]->GetYaxis()->SetRangeUser(0,EfficiencyHisto[iCut][iVar]->GetMaximum()+1.1*EfficiencyHisto[iCut][iVar]->GetBinError(EfficiencyHisto[iCut][iVar]->GetMaximumBin()));
	 EfficiencyHisto[iCut][iVar]->Draw("E");
         
	 Title = Form("efficiency_VBF_%s_%s/%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str(),Cuts.at(iCut).c_str()); 
         c2.SetName(Title);
         c2.Write();
	
	 EfficiencyHisto_ttbar[iCut][iVar]->GetYaxis()->SetRangeUser(0,EfficiencyHisto_ttbar[iCut][iVar]->GetMaximum()+1.1*EfficiencyHisto_ttbar[iCut][iVar]->GetBinError(EfficiencyHisto_ttbar[iCut][iVar]->GetMaximumBin()));
         EfficiencyHisto_ttbar[iCut][iVar]->Draw("E");
         
	 Title = Form("efficiency_ttbar_VBF_%s_%s/%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str(),Cuts.at(iCut).c_str()); 
         c2.SetName(Title);
	 c2.Write();
	  
	 num_DATA_VBF_Rebinned=DynamicalRebinHisto(num_DATA_VBF,num_DATA_VBF_Rebinned,Bin_Extremes[iVar],true,false);
	 den_DATA_VBF_Rebinned=DynamicalRebinHisto(den_DATA_VBF,den_DATA_VBF_Rebinned,Bin_Extremes[iVar],true,false);
	 
	 eff_DATA[iCut][iVar]= new TEfficiency(*num_DATA_VBF_Rebinned,*den_DATA_VBF_Rebinned);
	 eff_DATA[iCut][iVar]->Bayesian(den_DATA_VBF->GetEntries(),num_DATA_VBF_Rebinned->GetEntries(),0.95,1,1,false,true);
	  
	 eff_DATA[iCut][iVar]->SetMarkerColor(kBlack);
         eff_DATA[iCut][iVar]->SetLineColor(kBlack);
         eff_DATA[iCut][iVar]->SetMarkerStyle(20);
	 eff_DATA[iCut][iVar]->SetLineWidth(2);
	 eff_DATA[iCut][iVar]->Draw("AP");
	 
	 Title=Form("efficiency_DATA_VBF_%s_%s/%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str(),Cuts.at(iCut).c_str());
	 c2.SetName(Title);
	 c2.Write();
	 
	 
	 PurityHisto[iCut][iVar]->GetYaxis()->SetRangeUser(0,PurityHisto[iCut+1][iVar]->GetMaximum()+0.5);
	 PurityHisto[iCut][iVar]->SetTitle("Purity in the VBF Region");
	 PurityHisto[iCut][iVar]->SetLineColor(kBlack);
	 PurityHisto[iCut][iVar]->SetMarkerColor(kRed);
	 PurityHisto[iCut][iVar]->SetLineWidth(2);
	 PurityHisto[iCut][iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 PurityHisto[iCut][iVar]->GetYaxis()->SetTitle("Purity");
	 PurityHisto[iCut][iVar]->Draw("E");
	
	 Title=Form("Purity_VBF_%s_%s",nameHumanVariable.at(iVar).c_str(), Cuts.at(iCut).c_str());
	 c2.SetName(Title);
	 c2.Write();
	 
         PurityHisto[iCut+1][iVar]->GetYaxis()->SetRangeUser(0,PurityHisto[iCut+1][iVar]->GetMaximum()+0.5);
	 PurityHisto[iCut+1][iVar]->SetTitle("Purity in the VBF Control Region");
	 PurityHisto[iCut+1][iVar]->SetLineColor(kBlack);
	 PurityHisto[iCut+1][iVar]->SetMarkerColor(kRed);
	 PurityHisto[iCut+1][iVar]->SetLineWidth(2);
	 PurityHisto[iCut+1][iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 PurityHisto[iCut+1][iVar]->GetYaxis()->SetTitle("Purity");
	 PurityHisto[iCut+1][iVar]->Draw("E");

         Title=Form("Purity_VBF_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut+1).c_str());
	 c2.SetName(Title);
	 c2.Write();
	 
       }
       
       if(Cuts.at(iCut)=="VBF_Zone_Signal")
       {
	 TH1D * num_VBF_Sig= (TH1D*)stack[iCut][iVar]->GetStack()->Last();
	 TH1D * num_VBF_Sig_Rebinned;
	 num_VBF_Sig_Rebinned=DynamicalRebinHisto(num_VBF_Sig,num_VBF_Sig_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
        	   
	 num_VBF_Sig_Rebinned->SetFillStyle(3335);
         num_VBF_Sig_Rebinned->SetFillColor(kBlack);
        
	 TLegend * legend= makeLegend(*stack[iCut][iVar],nameSample);
	
	 stack_Rebinned[iCut][iVar]=DynamicalRebinStack(stack[iCut][iVar],stack_Rebinned[iCut][iVar],Bin_Extremes[iVar],isDATA,isDivide);
	 
	 TH1D* num_DATA_VBF_Sig, *num_DATA_VBF_Sig_Rebinned, * num_ttbar_Sig,*num_ttbar_Sig_Rebinned,*num_top_Sig,*num_top_Sig_Rebinned;
	 
	 for(int iSample=0;iSample<nameSample.size(); iSample++)
	 {
	   
	   if(nameSample.at(iSample)!="ttbar" && nameSample.at(iSample)!="top" && nameSample.at(iSample)!="DATA") continue;
	 
	   if(nameSample.at(iSample)=="ttbar")
	   { 
            num_ttbar_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_ttbar_Sig");
	    num_ttbar_Sig_Rebinned=DynamicalRebinHisto(num_ttbar_Sig,num_ttbar_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
	   }
          
           if(nameSample.at(iSample)=="top")
	   {
	    num_top_Sig = (TH1D*)histo[iCut][iVar][iSample]->Clone("num_top_Sig");
            num_top_Sig_Rebinned=DynamicalRebinHisto(num_top_Sig,num_top_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	   }
  
	   if(nameSample.at(iSample)=="DATA")
	   {
	    isDATA=true;
	    
            num_DATA_VBF_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_DATA_VBF_Sig");
	    num_DATA_VBF_Sig_Rebinned=DynamicalRebinHisto(num_DATA_VBF_Sig,num_DATA_VBF_Sig_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            
            num_DATA_VBF_Sig_Rebinned->SetMarkerColor(kBlack);
            num_DATA_VBF_Sig_Rebinned->SetLineColor(kBlack);
	    num_DATA_VBF_Sig_Rebinned->SetFillColor(kWhite);
            num_DATA_VBF_Sig_Rebinned->SetMarkerStyle(20);
	    
	    isDATA=false;

	   }
	 }
	 
	  ///==== Purtity Distribution
	  
	 PurityHisto[iCut][iVar]= (TH1D*) num_ttbar_Sig_Rebinned->Clone("PurityHisto");
	 PurityHisto[iCut][iVar]->Add(num_top_Sig_Rebinned);
	 PurityHisto[iCut][iVar]->Divide(num_VBF_Sig_Rebinned);
	 
	 ///==== Plot in different Canvas  
         TCanvas s2 ;   
	 
	 num_VBF_Sig_Rebinned->GetYaxis()->SetRangeUser(0,num_DATA_VBF_Sig_Rebinned->GetMaximum()+1.1*num_DATA_VBF_Sig_Rebinned->GetBinError(num_DATA_VBF_Sig_Rebinned->GetMaximumBin()));
         num_VBF_Sig_Rebinned->SetTitle("VBF Signal Region");
	 num_VBF_Sig_Rebinned->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 num_VBF_Sig_Rebinned->GetYaxis()->SetTitle("Events/BinWidth");
	 
	 num_VBF_Sig_Rebinned->Draw("hist") ;
         stack_Rebinned[iCut][iVar]->Draw("same hist");
         num_VBF_Sig_Rebinned->Draw ("sameE2") ;
	 num_DATA_VBF_Sig_Rebinned->Draw("Esame");
	 
	 legend->AddEntry(num_DATA_VBF_Sig_Rebinned, "DATA");
         legend->Draw();
         
	 TString Title = Form("num_VBF_Sig_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut).c_str()); 
         s2.SetName(Title);
         s2.Write();
	 
	 PurityHisto[iCut][iVar]->GetYaxis()->SetRangeUser(0,PurityHisto[iCut][iVar]->GetMaximum()+0.5);
	 PurityHisto[iCut][iVar]->SetTitle("Purity in the Signal Region");
	 PurityHisto[iCut][iVar]->SetLineColor(kBlack);
	 PurityHisto[iCut][iVar]->SetMarkerColor(kRed);
	 PurityHisto[iCut][iVar]->SetLineWidth(2);
	 PurityHisto[iCut][iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
	 PurityHisto[iCut][iVar]->GetYaxis()->SetTitle("Purity");
	 PurityHisto[iCut][iVar]->Draw("E");
	 
         Title=Form("Purity_%s_%s",nameHumanVariable.at(iVar).c_str(),Cuts.at(iCut).c_str());
	 s2.SetName(Title);
	 s2.Write();
         
          
       }
    }
 }
 
 ///===== Final Plot for Efficiency Comparison and DATA Driven Estimation
 
 TEfficiency* Efficiency_Control_Zone[100];
 TH1D *VBF_Btag_Zone[100];
 TH1D *VBF_DATA_Sig_Zone[100];
 TGraphAsymmErrors* VBF_Sig_Zone_Estimation[100];

 
 for(int iVar=0; iVar<Variable.size(); iVar++)
 {
    if(Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(abs(q1_Eta))+(abs(q1_Eta)>=abs(q2_Eta))*(abs(q2_Eta))" && 
       Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(q1_pT)+(abs(q1_Eta)>=abs(q2_Eta))*(q2_pT)")
      continue;
   
    TString way=Form("%s/Efficiency_Study",nameHumanVariable.at(iVar).c_str());
    output_Plott.cd(way);
  
    TCanvas c3;
    TLegend * leg =new TLegend(0.75,0.7,0.98,0.9);
    TLegend * leg2 =new TLegend(0.75,0.7,0.98,0.9);
    
    bool isDivide=true;
    
    for(int iCut=0; iCut<Cuts.size(); iCut++)
    {
      if(Cuts.at(iCut)=="Efficiency_Zone" && Cuts.at(iCut+1)=="Efficiency_Zone_Btag" )
      {
         ///==== Efficiency on DATA in the Efficiency region
        Efficiency_Control_Zone[iVar]= (TEfficiency*) eff_DATA[iCut][iVar]->Clone("Efficiency_Control_Zone");
	
        EfficiencyHisto_ttbar[iCut][iVar]->SetFillColor(kRed);
        EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerColor(kRed);
        EfficiencyHisto_ttbar[iCut][iVar]->SetFillStyle(3003);
        EfficiencyHisto_ttbar[iCut][iVar]->SetLineColor(kRed);
        EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerStyle(21);
        EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerSize(2);
        EfficiencyHisto_ttbar[iCut][iVar]->SetLineWidth(2);
        EfficiencyHisto_ttbar[iCut][iVar]->GetYaxis()->SetTitle("Efficiency");
        EfficiencyHisto_ttbar[iCut][iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
        EfficiencyHisto_ttbar[iCut][iVar]->SetTitle(" Efficiency in the Efficiency Zone");
     
        EfficiencyHisto[iCut][iVar]->SetFillColor(kBlue);
        EfficiencyHisto[iCut][iVar]->SetMarkerColor(kBlue);
        EfficiencyHisto[iCut][iVar]->SetFillStyle(3002);
        EfficiencyHisto[iCut][iVar]->SetLineColor(kBlue);
        EfficiencyHisto[iCut][iVar]->SetMarkerStyle(20);
        EfficiencyHisto[iCut][iVar]->SetMarkerSize(2);
        EfficiencyHisto[iCut][iVar]->SetLineWidth(2);
        EfficiencyHisto[iCut][iVar]->GetYaxis()->SetTitle("Efficiency");
        EfficiencyHisto[iCut][iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
        EfficiencyHisto[iCut][iVar]->SetTitle(" Efficiency in the Efficiency Zone");
       
        EfficiencyHisto[iCut][iVar]->Draw("E2");
        EfficiencyHisto_ttbar[iCut][iVar]->Draw("E2same");
        eff_DATA[iCut][iVar]->Draw("Esame");
       
        leg->SetFillColor(kWhite);
        leg->AddEntry(EfficiencyHisto_ttbar[iCut][iVar],"eff on tt (MC) ","pl");
        leg->AddEntry(EfficiencyHisto[iCut][iVar], "eff on tot (MC) ","pl");
        leg->AddEntry(eff_DATA[iCut][iVar]," eff on DATA ","pl");
        
	TString Title = Form("Efficiency_Control_Zone_%s",nameHumanVariable.at(iVar).c_str());
        leg->Draw();
        c3.SetName(Title);
        c3.Write();

        leg->Clear();
        leg->AddEntry(EfficiencyHisto_ttbar[iCut][iVar], "eff on tt (MC) ","pl");
       
        EfficiencyHisto_ttbar[iCut][iVar]->GetYaxis()->SetRangeUser(0,1);
        EfficiencyHisto_ttbar[iCut][iVar]->GetYaxis()->SetTitle("Efficiency");
        EfficiencyHisto_ttbar[iCut][iVar]->SetFillColor(kBlue);
        EfficiencyHisto_ttbar[iCut][iVar]->SetFillStyle(3001);
        EfficiencyHisto_ttbar[iCut][iVar]->SetLineColor(kBlue);
        EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerStyle(21);
        EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerSize(2);
        EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerColor(kBlue);
        EfficiencyHisto_ttbar[iCut][iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str()); 
        EfficiencyHisto_ttbar[iCut][iVar]->SetTitle("Comparison MC Signal- Control Region");
        EfficiencyHisto_ttbar[iCut][iVar]->Draw("E1");
      }
        
      if(Cuts.at(iCut)=="VBF_Zone")
      {
        EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerColor(kRed);
        EfficiencyHisto_ttbar[iCut][iVar]->SetFillColor(kRed);
        EfficiencyHisto_ttbar[iCut][iVar]->SetFillStyle(3002);
        EfficiencyHisto_ttbar[iCut][iVar]->SetLineColor(kRed);
        EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerSize(2);
	EfficiencyHisto_ttbar[iCut][iVar]->SetMarkerStyle(20);
	
	EfficiencyHisto_ttbar[iCut][iVar]->Draw("E1same");
        leg->AddEntry(EfficiencyHisto_ttbar[iCut][iVar],"eff on tt (MC), VBF","pl");
       
	TString Title = Form("Efficiency_Comparison_CZ/SZ_%s",nameHumanVariable.at(iVar).c_str());
        leg->Draw();
	
        c3.SetName(Title);
        c3.Write();
       
      }
       
      ///===== Distribution of data in the Btag Zone (Control Region)  after the VBF selections
     
      if(Cuts.at(iCut)=="VBF_Zone_Btag")
      {
       for(int iSample=0; iSample<nameSample.size(); iSample++)
       {
	 if(nameSample.at(iSample)!="DATA")continue;
       
	  TH1D* Temp;
	  Temp=(TH1D*) histo[iCut][iVar][iSample]->Clone("Temp");

	  VBF_Btag_Zone[iVar]=DynamicalRebinHisto(Temp,VBF_Btag_Zone[iVar],Bin_Extremes.at(iVar), true, isDivide);
	  Temp->Delete();
	  
       }
      }
     
      ///==== Distribution fo DATA in the VBF Signal Region  
     
      if(Cuts.at(iCut)=="VBF_Zone_Signal")
      {
       
       for(int iSample=0; iSample<nameSample.size(); iSample++)
       {
	 if(nameSample.at(iSample)!="DATA")continue;
	 
	  TH1D* Temp;
	  Temp=(TH1D*) histo[iCut][iVar][iSample]->Clone("Temp"); 
	 
	  VBF_DATA_Sig_Zone[iVar]=DynamicalRebinHisto(Temp,VBF_DATA_Sig_Zone[iVar],Bin_Extremes.at(iVar), true,isDivide);
	  Temp->Delete();
	}
       
       }
   }
     
   ///==== Final Data driven estimation in the signal region for each Variable
   
   if(VBF_DATA_Sig_Zone[iVar]!=0 && VBF_Btag_Zone[iVar]!=0 && Efficiency_Control_Zone[iVar]!=0)
   { 
    
    VBF_Sig_Zone_Estimation[iVar]=new TGraphAsymmErrors(VBF_DATA_Sig_Zone[iVar]);
   
    for(int iBin=0; iBin<VBF_DATA_Sig_Zone[iVar]->GetNbinsX(); iBin++)
    { 
      if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0) ///=== Estimation is possible if and only if the efficiency is not null
      {       
        VBF_Sig_Zone_Estimation[iVar]->SetPoint(iBin,VBF_DATA_Sig_Zone[iVar]->GetBinCenter(iBin+1),VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))));
       
        if(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))-abs((1/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*sqrt(((Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1))*(Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1))*((VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*VBF_Btag_Zone[iVar]->GetBinContent(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)*Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))+VBF_Btag_Zone[iVar]->GetBinError(iBin+1)*VBF_Btag_Zone[iVar]->GetBinError(iBin+1)*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))))>=0)
        { 
	  ///=== Errors are evaluated through the propagation formula
	  VBF_Sig_Zone_Estimation[iVar]->SetPointError(iBin,VBF_DATA_Sig_Zone[iVar]->GetBinWidth(iBin+1)/2,VBF_DATA_Sig_Zone[iVar]->GetBinWidth(iBin+1)/2,(1/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*sqrt(((Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1))*(Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1))*((VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*VBF_Btag_Zone[iVar]->GetBinContent(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)*Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))+VBF_Btag_Zone[iVar]->GetBinError(iBin+1)*VBF_Btag_Zone[iVar]->GetBinError(iBin+1)*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))),(1/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*sqrt(((Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1))*(Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1))*((VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*VBF_Btag_Zone[iVar]->GetBinContent(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)*Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))+VBF_Btag_Zone[iVar]->GetBinError(iBin+1)*VBF_Btag_Zone[iVar]->GetBinError(iBin+1)*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))));
       }
       else{
	    VBF_Sig_Zone_Estimation[iVar]->SetPointError(iBin,VBF_DATA_Sig_Zone[iVar]->GetBinWidth(iBin+1)/2,VBF_DATA_Sig_Zone[iVar]->GetBinWidth(iBin+1)/2,VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))),(1/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*sqrt(((Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1))*(Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1))*((VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*VBF_Btag_Zone[iVar]->GetBinContent(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)*Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))+VBF_Btag_Zone[iVar]->GetBinError(iBin+1)*VBF_Btag_Zone[iVar]->GetBinError(iBin+1)*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))*(1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))));
           }
	 
      }
      else{
	   VBF_Sig_Zone_Estimation[iVar]->SetPoint(iBin,VBF_DATA_Sig_Zone[iVar]->GetBinCenter(iBin+1),0);
	   VBF_Sig_Zone_Estimation[iVar]->SetPointError(iBin,VBF_DATA_Sig_Zone[iVar]->GetBinWidth(iBin+1)/2,VBF_DATA_Sig_Zone[iVar]->GetBinWidth(iBin+1)/2,0,0);
      }
      
	   
    }
     
    ///==== Plot of data and top background DD in the Signal Region
   
    VBF_Sig_Zone_Estimation[iVar]->SetMarkerStyle(21);
    VBF_Sig_Zone_Estimation[iVar]->SetMarkerColor(kBlue);
    VBF_Sig_Zone_Estimation[iVar]->SetLineColor(kBlue);
    VBF_Sig_Zone_Estimation[iVar]->SetLineWidth(2);
    VBF_Sig_Zone_Estimation[iVar]->SetFillColor(kBlue);
    VBF_Sig_Zone_Estimation[iVar]->SetFillStyle(3002);
   
   
    VBF_DATA_Sig_Zone[iVar]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
    VBF_DATA_Sig_Zone[iVar]->GetYaxis()->SetTitle("nEvents/BinWidth");
    VBF_DATA_Sig_Zone[iVar]->SetTitle("Data Driven Estimation");
    VBF_DATA_Sig_Zone[iVar]->SetMarkerColor(kBlack);
    VBF_DATA_Sig_Zone[iVar]->SetLineColor(kBlack);
    VBF_DATA_Sig_Zone[iVar]->SetFillColor(kWhite);
    VBF_DATA_Sig_Zone[iVar]->SetMarkerStyle(20);
    VBF_DATA_Sig_Zone[iVar]->SetLineWidth(2);
   
    leg->Clear();
    leg->AddEntry(VBF_DATA_Sig_Zone[iVar],"DATA in S.R.");
    leg->AddEntry(VBF_Sig_Zone_Estimation[iVar], "Data driven reconstr.");
   
    VBF_DATA_Sig_Zone[iVar]->Draw("E1");
    VBF_Sig_Zone_Estimation[iVar]->Draw("PE2same");
    leg->Draw(); 
   
    TString Title = Form("Data_Driven_Result_Signal_DATA_%s",nameHumanVariable.at(iVar).c_str());
    c3.SetName(Title);
    c3.Write();
        	   
   }

  }

  ///==== Information dumper in an external File
  
  std::string edge;
  std::string error;
  
  for(int iVar=0; iVar<Variable.size(); iVar++)
  {
    if(Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(abs(q1_Eta))+(abs(q1_Eta)>=abs(q2_Eta))*(abs(q2_Eta))" && 
       Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(q1_pT)+(abs(q1_Eta)>=abs(q2_Eta))*(q2_pT)")continue;
    
    bool isDATA=false;
    bool isDivide=false;
   
    outFile<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<std::endl;
    outFile<<"#"<< nameHumanVariable.at(iVar)<<std::endl;
    outFile<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<std::endl;
   
    
    double alfa=0, beta=0;
    double err_alfa=0,err_beta=0;
    double ratio=0;
    double err_ratio=0;
    double tt_Events=0;
    double tt_Events_Error=0;
    double Final_Error=0;
    
    
    for(int iBin=0; iBin<Bin_Extremes[iVar].size(); iBin++)
    {
     std::ostringstream ss;
     ss<<Bin_Extremes[iVar].at(iBin);
     edge=edge+' '+' '+(ss.str());
    
    }

    outFile<<"################  "<<std::endl;
    outFile<<"# Binning edge "<<std::endl;
    outFile<<"################  "<<std::endl;
    outFile<<edge<<std::endl;
    outFile<<"#--------------------------"<<std::endl;
    outFile<<"#--------------------------"<<std::endl;
   
    for(int iCut=0; iCut<Cuts.size(); iCut++)
    {
     if(Cuts.at(iCut)=="Efficiency_Zone" && Cuts.at(iCut+1)=="Efficiency_Zone_Btag")
     {
        TH1D * num = (TH1D*) stack[iCut+1][iVar]->GetStack()->Last();
	TH1D * num_Rebinned;
	num_Rebinned=DynamicalRebinHisto(num,num_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
        TH1D * den = (TH1D*) stack[iCut][iVar]->GetStack()->Last();
	TH1D * den_Rebinned;
	den_Rebinned=DynamicalRebinHisto(den,den_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
        
	TH1D* num_DATA,*num_DATA_Rebinned, *num_ttbar, *num_ttbar_Rebinned, *num_top, *num_top_Rebinned;
	TH1D  *den_DATA,*den_DATA_Rebinned, *den_ttbar, *den_ttbar_Rebinned, *den_top, *den_top_Rebinned;
	
        for(int iSample=0; iSample<nameSample.size(); iSample++)
        {
          if(nameSample.at(iSample)!="DATA" && nameSample.at(iSample)!="ttbar" && nameSample.at(iSample)!="top")continue;
          
	  if(nameSample.at(iSample)=="DATA")
	   {
	    isDATA=true;
	    num_DATA = (TH1D*) histo[iCut+1][iVar][iSample]->Clone("num_DATA");
	    num_DATA_Rebinned=DynamicalRebinHisto(num_DATA,num_DATA_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            
	    den_DATA = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_DATA");
	    den_DATA_Rebinned=DynamicalRebinHisto(den_DATA,den_DATA_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            isDATA=false;
	  }
	   
	  if(nameSample.at(iSample)=="ttbar")
	  {
	    num_ttbar = (TH1D*) histo[iCut+1][iVar][iSample]->Clone("num_ttbar");
	    num_ttbar_Rebinned=DynamicalRebinHisto(num_ttbar,num_ttbar_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            
	    den_ttbar = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_ttbar");
	    den_ttbar_Rebinned=DynamicalRebinHisto(den_ttbar,den_ttbar_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
          }
	
	  if(nameSample.at(iSample)=="top")
	  {
	    num_top = (TH1D*) histo[iCut+1][iVar][iSample]->Clone("num_top");
	    num_top_Rebinned=DynamicalRebinHisto(num_top,num_top_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            
	    den_top = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_top");
	    den_top_Rebinned=DynamicalRebinHisto(den_top,den_top_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
          }
	}
        
        num_ttbar_Rebinned->Add(num_top_Rebinned);
        den_ttbar_Rebinned->Add(den_top_Rebinned);
        
	///====================================================
        outFile<<"*******************************"<<std::endl;
	outFile<<"Events after Efficiency Region Cuts "<<std::endl;
	outFile<<"*******************************"<<std::endl;
	
        edge.clear();
     
        for(int iBin=0; iBin<den_Rebinned->GetNbinsX(); iBin++)
        {     
         std::ostringstream ss,se;
         ss<<den_Rebinned->GetBinContent(iBin+1);
         edge=edge+' '+' '+(ss.str());
         se<<den_Rebinned->GetBinError(iBin+1);
         error=error+' '+' '+(se.str());
        }
     
        outFile<<"################  "<<std::endl;
        outFile<<"#    MC Events in Efficiency Region Total     "<<std::endl;
        outFile<<"################  "<<std::endl;
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
     
        outFile<<"###############  "<<std::endl;
        outFile<<"#   DATA Events in Efficiency Region Total     "<<std::endl;
        outFile<<"###############  "<<std::endl;
        outFile<<edge<<std::endl;
        outFile<<error<<std::endl;          
        edge.clear();
        error.clear();
     
        for(int iBin=0; iBin<num_Rebinned->GetNbinsX(); iBin++)
        {     
          std::ostringstream ss,se;
          ss<<den_ttbar_Rebinned->GetBinContent(iBin+1);
          edge=edge+' '+' '+(ss.str());
          se<<den_ttbar_Rebinned->GetBinError(iBin+1);
          error=error+' '+' '+(se.str());
        }
     
        outFile<<"################  "<<std::endl;
        outFile<<"#   Top Background Events in Efficiency Region     "<<std::endl;
        outFile<<"################  "<<std::endl;
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
     
        outFile<<"############## "<<std::endl;
        outFile<<"#   MC Events in Efficiency Btag Region     "<<std::endl;
        outFile<<"##############  "<<std::endl;
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
     
        outFile<<"################  "<<std::endl;
        outFile<<"#   DATA Events in Efficiency Btag Region    "<<std::endl;
        outFile<<"################  "<<std::endl;
        outFile<<edge<<std::endl;
        outFile<<error<<std::endl;          
        edge.clear();
        error.clear();
    
        for(int iBin=0; iBin<num_DATA_Rebinned->GetNbinsX(); iBin++)
        {     
          std::ostringstream ss, se;
          ss<<num_ttbar_Rebinned->GetBinContent(iBin+1);
          edge=edge+' '+' '+(ss.str());
          se<<num_ttbar_Rebinned->GetBinError(iBin+1);
          error=error+' '+' '+(se.str());
        }
     
        outFile<<"##################  "<<std::endl;
        outFile<<"#  Top Background Events in Efficiency Btag Region  "<<std::endl;
        outFile<<"##################  "<<std::endl;
        outFile<<edge<<std::endl;
        outFile<<error<<std::endl;          
        edge.clear();
        error.clear();
    
    
     }
   
     if(Cuts.at(iCut)=="Efficiency_Zone_noBtag")
     {
        TH1D * num_Sig= (TH1D*)stack[iCut][iVar]->GetStack()->Last();
        TH1D * num_Sig_Rebinned;
        num_Sig_Rebinned=DynamicalRebinHisto(num_Sig,num_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
    
        TH1D* num_DATA_Sig, *num_DATA_Sig_Rebinned; 
	 
        for(int iSample=0;iSample<nameSample.size(); iSample++)
        {
	   if(nameSample.at(iSample)=="DATA")
	   { 
	     isDATA=true;
	     num_DATA_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_DATA_Sig");
	     num_DATA_Sig_Rebinned=DynamicalRebinHisto(num_DATA_Sig,num_DATA_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	     isDATA=false;
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
     
        outFile<<"###############  "<<std::endl;
        outFile<<"#   MC Events in Efficiency Region noBtag  "<<std::endl;
        outFile<<"###############  "<<std::endl;
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
     
        outFile<<"#################  "<<std::endl;
        outFile<<"#    DATA Events in Efficiency Region noBtag   "<<std::endl;
        outFile<<"#################  "<<std::endl;
        outFile<<edge<<std::endl;
        outFile<<error<<std::endl;          
        edge.clear();
        error.clear();
     }
     ///=================================================
  
     if(Cuts.at(iCut)=="VBF_Zone" && Cuts.at(iCut+1)=="VBF_Zone_Btag")
     {
        TH1D * num_VBF = (TH1D*) stack[iCut+1][iVar]->GetStack()->Last();
	TH1D * num_VBF_Rebinned;
	num_VBF_Rebinned=DynamicalRebinHisto(num_VBF,num_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	
        TH1D * den_VBF = (TH1D*) stack[iCut][iVar]->GetStack()->Last();
	TH1D * den_VBF_Rebinned;
	den_VBF_Rebinned=DynamicalRebinHisto(den_VBF,den_VBF_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
        
	TH1D* num_DATA_VBF, *den_DATA_VBF;
	TH1D* num_DATA_VBF_Rebinned, *den_DATA_VBF_Rebinned;
	
        for(int iSample=0; iSample<nameSample.size(); iSample++)
        {
           if(nameSample.at(iSample)=="DATA")
	   {
	    isDATA=true; 
            num_DATA_VBF = (TH1D*) histo[iCut+1][iVar][iSample]->Clone("num_DATA_VBF");
	    num_DATA_VBF_Rebinned=DynamicalRebinHisto(num_DATA_VBF,num_DATA_VBF_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);
            
	    den_DATA_VBF = (TH1D*) histo[iCut][iVar][iSample]->Clone("den_DATA_VBF");
	    den_DATA_VBF_Rebinned=DynamicalRebinHisto(den_DATA_VBF,den_DATA_VBF_Rebinned,Bin_Extremes[iVar],isDATA,isDivide);	    
	    isDATA=false;
	   }
        }
     
        outFile<<"************************************  "<<std::endl;
        outFile<<" Events after VBF Cuts  "<<std::endl;
        outFile<<"************************************  "<<std::endl;
        edge.clear();
     
        for(int iBin=0; iBin<den_VBF_Rebinned->GetNbinsX(); iBin++)
        {     
          std::ostringstream ss,se;
          ss<<den_VBF_Rebinned->GetBinContent(iBin+1);
          edge=edge+' '+' '+(ss.str());
          se<<den_VBF_Rebinned->GetBinError(iBin+1);
          error=error+' '+' '+(se.str());
        }
     
        outFile<<"##################  "<<std::endl;
        outFile<<"#   MC Events in VBF Region    "<<std::endl;
        outFile<<"##################  "<<std::endl;
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
     
        outFile<<"##################  "<<std::endl;
        outFile<<"#    DATA Events in VBF Region   "<<std::endl;
        outFile<<"##################  "<<std::endl;
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
     
        outFile<<"#################  "<<std::endl;
        outFile<<"#   MC Events in VBF Control Region    "<<std::endl;
        outFile<<"#################  "<<std::endl;
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
     
        outFile<<"##################  "<<std::endl;
        outFile<<"#    DATA Events in VBF Control Region     "<<std::endl;
        outFile<<"##################  "<<std::endl;
        outFile<<edge<<std::endl;
        outFile<<error<<std::endl;          
        edge.clear();
        error.clear();
     }
   
     if(Cuts.at(iCut)=="VBF_Zone_Signal")
     {
        TH1D * num_VBF_Sig= (TH1D*)stack[iCut][iVar]->GetStack()->Last();
        TH1D * num_VBF_Sig_Rebinned;
        num_VBF_Sig_Rebinned=DynamicalRebinHisto(num_VBF_Sig,num_VBF_Sig_Rebinned,Bin_Extremes[iVar],isDATA, isDivide);
    
        TH1D* num_DATA_VBF_Sig, *num_DATA_VBF_Sig_Rebinned, *num_ttbar_VBF_Sig, *num_ttbar_VBF_Sig_Rebinned;
        TH1D* num_top_VBF_Sig, *num_top_VBF_Sig_Rebinned;
        TH1D *num_DATA_VBF_Sig_Divide_Rebinned;
	 
        for(int iSample=0;iSample<nameSample.size(); iSample++)
        {
	  if(nameSample.at(iSample)!="DATA" && nameSample.at(iSample)!="ttbar" && nameSample.at(iSample)!="top")continue;
         
          if( nameSample.at(iSample)=="ttbar")
	  {  
	    num_ttbar_VBF_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_ttbar_VBF_Sig");
	    num_ttbar_VBF_Sig_Rebinned=DynamicalRebinHisto(num_ttbar_VBF_Sig,num_ttbar_VBF_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	  }
	
	  if( nameSample.at(iSample)=="top")
	  {  
	    num_top_VBF_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_top_VBF_Sig");
	    num_top_VBF_Sig_Rebinned=DynamicalRebinHisto(num_top_VBF_Sig,num_top_VBF_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	  }
	
	  if(nameSample.at(iSample)=="DATA")
	  { 
	    isDATA=true;
	    num_DATA_VBF_Sig = (TH1D*) histo[iCut][iVar][iSample]->Clone("num_DATA_VBF_Sig_Rebinned");
	    num_DATA_VBF_Sig_Rebinned=DynamicalRebinHisto(num_DATA_VBF_Sig,num_DATA_VBF_Sig_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);
	    
	    isDivide=true;
	    num_DATA_VBF_Sig_Divide_Rebinned=DynamicalRebinHisto(num_DATA_VBF_Sig,num_DATA_VBF_Sig_Divide_Rebinned,Bin_Extremes[iVar], isDATA, isDivide);   
	    
	    isDivide=false;
	    isDATA=false;
	    
	  }
        }
	 
        num_ttbar_VBF_Sig_Rebinned->Add(num_top_VBF_Sig_Rebinned);
    
        
        for(int iBin=0; iBin<num_VBF_Sig_Rebinned->GetNbinsX(); iBin++)
        {     
          std::ostringstream ss,se;
          ss<<num_VBF_Sig_Rebinned->GetBinContent(iBin+1);
          edge=edge+' '+' '+(ss.str());
          se<<num_VBF_Sig_Rebinned->GetBinError(iBin+1);
          error=error+' '+' '+(se.str());
      
          if(nameHumanVariable.at(iVar)=="|#eta|^{CJet}" && num_ttbar_VBF_Sig_Rebinned->GetBinCenter(iBin+1)<2.5)
	  {
	    alfa=alfa+num_ttbar_VBF_Sig_Rebinned->GetBinContent(iBin+1);
            err_alfa=sqrt(err_alfa*err_alfa+num_ttbar_VBF_Sig_Rebinned->GetBinError(iBin+1)*num_ttbar_VBF_Sig_Rebinned->GetBinError(iBin+1));
	  }
     
          if(nameHumanVariable.at(iVar)=="|#eta|^{CJet}" && num_ttbar_VBF_Sig_Rebinned->GetBinCenter(iBin+1)>=2.5)
	  {
	    beta=beta+num_ttbar_VBF_Sig_Rebinned->GetBinContent(iBin+1);
	    err_beta=sqrt(err_beta*err_beta+num_ttbar_VBF_Sig_Rebinned->GetBinError(iBin+1)*num_ttbar_VBF_Sig_Rebinned->GetBinError(iBin+1));
	  }
        }
     
        outFile<<"#################  "<<std::endl;
        outFile<<"#    MC Events in VBF Signal Region     "<<std::endl;
        outFile<<"#################  "<<std::endl;
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
     
        outFile<<"###################  "<<std::endl;
        outFile<<"#   DATA Events in VBF Signal Region     "<<std::endl;
        outFile<<"####################  "<<std::endl;
        outFile<<edge<<std::endl;
        outFile<<error<<std::endl;          
        edge.clear();
        error.clear();
	
        for(int iBin=0; iBin<num_DATA_VBF_Sig_Divide_Rebinned->GetNbinsX(); iBin++)
        {     
          std::ostringstream ss,se;
          ss<<num_DATA_VBF_Sig_Divide_Rebinned->GetBinContent(iBin+1);
          edge=edge+' '+' '+(ss.str());
          se<<num_DATA_VBF_Sig_Divide_Rebinned->GetBinError(iBin+1);
          error=error+' '+' '+(se.str());
        }
     
        outFile<<"######################  "<<std::endl;
        outFile<<"#   DATA Events in VBF Signal Region (Bin Width Divided)    "<<std::endl;
        outFile<<"#####  "<<std::endl;
        outFile<<edge<<std::endl;
        outFile<<error<<std::endl;          
        edge.clear();
        error.clear();
	
     }
    }
 
    for(int iBin=0; iBin<Efficiency_Control_Zone[iVar]->GetTotalHistogram()->GetNbinsX(); iBin++)
    {     
       std::ostringstream ss,se,sf;
       ss<<Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1);
       edge=edge+' '+' '+(ss.str());
       se<<Efficiency_Control_Zone[iVar]->GetEfficiencyErrorUp(iBin+1);
       sf<<Efficiency_Control_Zone[iVar]->GetEfficiencyErrorLow(iBin+1);
       error=error+' '+'+'+(se.str())+' '+'-'+(sf.str());
       
     }

    outFile<<"#-#-#-#-#-#-#-#-#-#-#-#-#-#   "<<std::endl;
    outFile<<"# Efficiency measured in the Efficiency Region   "<<std::endl;
    outFile<<"#-#-#-#-#-#-#-#-#-#-#-#-#-#   "<<std::endl;
    outFile<<edge<<std::endl;
    outFile<<error<<std::endl;          
    edge.clear();
    error.clear();
   
    for(int iBin=0; iBin<VBF_Sig_Zone_Estimation[iVar]->GetMaxSize(); iBin++)
    {
        std::ostringstream ss,se,sf;
        if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0)
        {  
          ss<<((VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))))*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin)));
          edge=edge+' '+' '+(ss.str());
          se<<sqrt((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin)))*(VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))));
          sf<<sqrt((VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin)))*(VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))));
          error=error+' '+'+'+(se.str())+' '+'-'+(sf.str());
        }
     
         else{
                 edge=edge+' '+' '+'0';
                 error=error+' '+'+'+'0'+' '+'-'+'0';
             }
    }
 
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"# Data driven events in the signal region ( no correction factor)"<<std::endl;
    outFile<<"#-------------------   "<<std::endl;
    outFile<<edge<<std::endl;
    outFile<<error<<std::endl;          
    edge.clear();
    error.clear();
 
    for(int iBin=0; iBin<VBF_Sig_Zone_Estimation[iVar]->GetMaxSize(); iBin++)
    {
      std::ostringstream ss,se,sf;
      if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0)
      {  
      ss<<((VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))));
      edge=edge+' '+' '+(ss.str());
      se<<sqrt((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin))*(VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)));
      sf<<sqrt((VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))*(VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin)));
      error=error+' '+'+'+(se.str())+' '+'-'+(sf.str());
      	
      }
      else{
            edge=edge+' '+' '+'0';
            error=error+' '+'+'+'0'+' '+'-'+'0';
	 
          }
    }
 
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"### Data driven events in the signal region divide Bin Width (no correction factor)"<<std::endl;
    outFile<<"#-------------------   "<<std::endl;
    outFile<<edge<<std::endl;
    outFile<<error<<std::endl;          
    edge.clear();
    error.clear(); 

    for(int iBin=0; iBin<VBF_Sig_Zone_Estimation[iVar]->GetMaxSize(); iBin++)
    {
      if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0)
      {     
        tt_Events=tt_Events+VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin));
        tt_Events_Error=sqrt(tt_Events_Error*tt_Events_Error+((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin)));
      }
       
    
    }
 
    Final_Error=1+tt_Events_Error/(tt_Events); ///=== 1 + Relative Error
  
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"### Data driven Final Result (no correction factor)"<<std::endl;
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"  tt Events   "<< tt_Events<<"  error  "<<Final_Error<<"  sys   "<<err_ratio<<std::endl;
    outFile<<error<<std::endl;          
    edge.clear();
    error.clear();
  
    
    tt_Events=0;
    tt_Events_Error=0;
    Final_Error=0;
  
    for(int iBin=0; iBin<VBF_Sig_Zone_Estimation[iVar]->GetMaxSize(); iBin++)
    {
      if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0)
      {  
          tt_Events=tt_Events+VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)));
          tt_Events_Error=sqrt(tt_Events_Error*tt_Events_Error+((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2));  
   
       
      }
    }
 
    Final_Error=1+tt_Events_Error/(tt_Events);
  
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"### Data driven Final Result divided by Bin Width (no correction factor) "<<std::endl;
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"  tt Events   "<< tt_Events<<"  error  "<<Final_Error<<"  sys   "<<err_ratio<<std::endl;
    outFile<<error<<std::endl;          
    edge.clear();
    error.clear();
 
    tt_Events=0;
    tt_Events_Error=0;
    Final_Error=0;
    
    if(nameHumanVariable.at(iVar)=="|#eta|^{CJet}")
    {
      outFile<<"###############  "<<std::endl;
      outFile<<"#    (alfa+beta)/alfa     "<<std::endl;
      outFile<<"###############  "<<std::endl;
      ratio=(alfa+beta)/(alfa);
      err_ratio=sqrt((1/(alfa*alfa))*(err_beta*err_beta)+(beta/(alfa*alfa))*(beta/(alfa*alfa))*(err_alfa*err_alfa));
      outFile<<alfa<<"   "<<err_alfa<<std::endl;
      outFile<<beta<<"   "<<err_beta<<std::endl;
      outFile<<ratio<<"   "<<err_ratio<<std::endl;
    }
     
    for(int iBin=0; iBin<VBF_Sig_Zone_Estimation[iVar]->GetMaxSize(); iBin++)
    {
      std::ostringstream ss,se,sf;
      if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0)
      {  
        if(ratio!=0)
        {
           ss<<((VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))))*ratio*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin)));
           edge=edge+' '+' '+(ss.str());
           se<<sqrt((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*ratio)*(VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*ratio)+err_ratio*err_ratio*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))))*(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))));
           sf<<sqrt((VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*ratio)*(VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*ratio)+err_ratio*err_ratio*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))))*(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))));
	   error=error+' '+'+'+(se.str())+' '+'-'+(sf.str());
        }
     else{
          ss<<(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))));
          edge=edge+' '+' '+(ss.str());
          se<<VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin);
          sf<<VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin);
          error=error+' '+'+'+(se.str())+' '+'-'+(sf.str());
	 }
           
      }
    else{
         edge=edge+' '+' '+'0';
         error=error+' '+'+'+'0'+' '+'-'+'0';
        }
    }
 
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"### Data driven events in the signal region (corrected)"<<std::endl;
    outFile<<"#-------------------   "<<std::endl;
    outFile<<edge<<std::endl;
    outFile<<error<<std::endl;          
    edge.clear();
    error.clear();
 
    for(int iBin=0; iBin<VBF_Sig_Zone_Estimation[iVar]->GetMaxSize(); iBin++)
    {
       std::ostringstream ss,se,sf;
       if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0)
       {  
         if(ratio!=0)
         {  
           ss<<((VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))))*ratio);
           edge=edge+' '+' '+(ss.str());
           se<<sqrt((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)*ratio)*(VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)*ratio)+err_ratio*err_ratio*(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))))*(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))));
           sf<<sqrt((VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin)*ratio)*(VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin)*ratio)+err_ratio*err_ratio*(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))))*(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))));
           error=error+' '+'+'+(se.str())+' '+'-'+(sf.str());
         }
       else{
             ss<<(VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))));
             edge=edge+' '+' '+(ss.str());
             se<<VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin);
             sf<<VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin);
             error=error+' '+'+'+(se.str())+' '+'-'+(sf.str());
	   }
       }
   else{
        edge=edge+' '+' '+'0';
        error=error+' '+'+'+'0'+' '+'-'+'0';
       }
    }
 
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"### Data driven events in the signal region divide Bin Width (corrected)"<<std::endl;
    outFile<<"#-------------------   "<<std::endl;
    outFile<<edge<<std::endl;
    outFile<<error<<std::endl;          
    edge.clear();
    error.clear(); 

    for(int iBin=0; iBin<VBF_Sig_Zone_Estimation[iVar]->GetMaxSize(); iBin++)
    {
       if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0)
       {  
         if(ratio!=0)
         {  
             tt_Events=tt_Events+VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*ratio*((Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin)));
             tt_Events_Error=sqrt(tt_Events_Error*tt_Events_Error+((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*ratio*ratio+err_ratio*err_ratio*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))));  
         }
     else{
           tt_Events=tt_Events+VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*((Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin)));
           tt_Events_Error=sqrt(tt_Events_Error*tt_Events_Error+((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin))*(Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin)));
         }
       
       }  
    }
 
    Final_Error=1+tt_Events_Error/(tt_Events);
  
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"### Data driven Final Result (corrected)"<<std::endl;
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"  tt Events   "<< tt_Events<<"  error  "<<Final_Error<<"  sys   "<<err_ratio<<std::endl;
    outFile<<error<<std::endl;          
    edge.clear();
    error.clear();
  
    tt_Events=0;
    tt_Events_Error=0;
    Final_Error=0;
    
  
    for(int iBin=0; iBin<VBF_Sig_Zone_Estimation[iVar]->GetMaxSize(); iBin++)
    {
       if(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)!=0)
       {  
         if(ratio!=0)
         { 
            tt_Events=tt_Events+VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*ratio;
            tt_Events_Error=sqrt(tt_Events_Error*tt_Events_Error+((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*ratio*ratio+err_ratio*err_ratio*VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))));  
         }
     else{
           tt_Events=tt_Events+VBF_Btag_Zone[iVar]->GetBinContent(iBin+1)*((1-Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1))/(Efficiency_Control_Zone[iVar]->GetEfficiency(iBin+1)))*((Bin_Extremes[iVar].at(iBin+1)-Bin_Extremes[iVar].at(iBin)));
           tt_Events_Error=sqrt(tt_Events_Error*tt_Events_Error+((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2)*((VBF_Sig_Zone_Estimation[iVar]->GetErrorYhigh(iBin)+VBF_Sig_Zone_Estimation[iVar]->GetErrorYlow(iBin))/2));  
         }
       }
    }
 
    Final_Error=1+tt_Events_Error/(tt_Events);
  
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"### Data driven Final Result divided by Bin Width (corrected) "<<std::endl;
    outFile<<"#-------------------   "<<std::endl;
    outFile<<"  tt Events   "<< tt_Events<<"  error  "<<Final_Error<<"  sys   "<<err_ratio<<std::endl;
    outFile<<error<<std::endl;          
    edge.clear();
    error.clear();
 
  }

///========= Closure Test For Data Driven Method validation

  TH1D* Sig_Estimation_Final;
 
  for(int iVar=0; iVar<Variable.size(); iVar++)
  {
     if(Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(abs(q1_Eta))+(abs(q1_Eta)>=abs(q2_Eta))*(abs(q2_Eta))" && 
        Variable.at(iVar).first!="(abs(q1_Eta)<abs(q2_Eta))*(q1_pT)+(abs(q1_Eta)>=abs(q2_Eta))*(q2_pT)" )
        continue;
      
     bool isDATA=false;
     bool isDivide=false;
     
        
     TH1D* Closure_Efficiency[1000];
     TH1D* BTag_VBF[1000];
     TH1D* Sig_Estimation[1000];
     TH1D* Sig_VBF_Rebinned[1000];
    
     TString way=Form("%s/Closure_Test",nameHumanVariable.at(iVar).c_str());
     output_Plott.cd(way);
           
     for(int iNum=0; iNum<Closure_Number; iNum++)
     { 
       
       TRandom3* num_eff= new TRandom3();
       TRandom3* den_eff= new TRandom3();
       TRandom3* num_btag= new TRandom3();
      
       num_eff->SetSeed(0);
       den_eff->SetSeed(0);
       num_btag->SetSeed(0);
        
      for(int iCut=0; iCut<Cuts.size(); iCut++)
      {
        if(Cuts.at(iCut)=="Efficiency_Zone" && Cuts.at(iCut+1)=="Efficiency_Zone_Btag")
        {  
          
	  TString name=Form("Closure_Efficiency_%s_%d",Variable[iVar].first.c_str(),iNum);
          
	  bool SkipEfficiency;
	  
	  TObjArray* histo_num_stack = stack_Rebinned[iCut+1][iVar]->GetStack() ;
	  TObjArray* histo_den_stack = stack_Rebinned[iCut][iVar]->GetStack() ;
	  
	  do{
	    
	      TH1D* num_total=(TH1D*) stack_Rebinned[iCut+1][iVar]->GetStack()->Last()->Clone("num_total");
              TH1D* den_total=(TH1D*) stack_Rebinned[iCut][iVar]->GetStack()->Last()->Clone("den_total");
             
	      num_total->Reset("ICEMS");
	      den_total->Reset("ICEMS");
	     
	      SkipEfficiency=false;
    
             for(int iHisto=0; iHisto<histo_num_stack->GetEntries(); iHisto++)
             {  
	       if(iHisto==0)
               {  
                 TH1D* Histo_num_1 = (TH1D*) histo_num_stack->At(iHisto);
	         TH1D* Histo_den_1 = (TH1D*) histo_den_stack->At(iHisto);
		 TH1D* Histo_num_temp_1=(TH1D*) Histo_num_1->Clone("Histo_num_temp_1");
		 TH1D* Histo_den_temp_1=(TH1D*) Histo_den_1->Clone("Histo_den_temp_1");
	     
	         for(int iBin=0; iBin<Histo_num_1->GetNbinsX(); iBin++)
	         { 
		  Histo_num_temp_1->SetBinContent(iBin+1,num_eff->Poisson(Histo_num_1->GetBinContent(iBin+1)));
	          Histo_den_temp_1->SetBinContent(iBin+1,den_eff->Poisson(Histo_den_1->GetBinContent(iBin+1)));
	         }
	         num_total->Add(Histo_num_temp_1);
	         den_total->Add(Histo_den_temp_1);
	       }
	    else{  
                 TH1D* Histo_num_1 = (TH1D*) histo_num_stack->At(iHisto-1);
                 TH1D* Histo_num_2 = (TH1D*) histo_num_stack->At(iHisto);
		 TH1D* Histo_den_1 = (TH1D*) histo_den_stack->At(iHisto-1);
                 TH1D* Histo_den_2 = (TH1D*) histo_den_stack->At(iHisto);
		 
		 TH1D* Histo_num_temp_1=(TH1D*) Histo_num_1->Clone("Histo_num_temp_1");
		 TH1D* Histo_num_temp_2=(TH1D*) Histo_num_2->Clone("Histo_num_temp_2");
		 TH1D* Histo_den_temp_1=(TH1D*) Histo_den_1->Clone("Histo_den_temp_1");
		 TH1D* Histo_den_temp_2=(TH1D*) Histo_den_2->Clone("Histo_den_temp_2");
		 
		 Histo_num_temp_2->Add(Histo_num_temp_1,-1);
                 Histo_den_temp_2->Add(Histo_den_temp_1,-1);
		   
		 for(int iBin=0;  iBin<Histo_num_2->GetNbinsX(); iBin++)
	         { 
		   Histo_num_temp_2->SetBinContent(iBin+1,num_eff->Poisson(Histo_num_temp_2->GetBinContent(iBin+1)));
		   Histo_den_temp_2->SetBinContent(iBin+1,den_eff->Poisson(Histo_den_temp_2->GetBinContent(iBin+1)));
		   
		 }
	   
	           num_total->Add(Histo_num_temp_2);
		   den_total->Add(Histo_den_temp_2);
	        } 
	    }
	    
          Closure_Efficiency[iNum]=(TH1D*) num_total->Clone("Closure_Efficiency");
          Closure_Efficiency[iNum]->SetName(name);
          Closure_Efficiency[iNum]->Divide(den_total);
	  
	  for(int iBin=0; iBin<Closure_Efficiency[iNum]->GetNbinsX(); iBin++)
	  {
	    if(Closure_Efficiency[iNum]->GetBinContent(iBin+1)>1)
	     SkipEfficiency=true;
	  }
	  
	 }while(SkipEfficiency);
	 
	}
           
        if(Cuts.at(iCut)=="VBF_Zone_Btag" && Cuts.at(iCut+1)=="VBF_Zone_Signal")
        {
	  
	
          TH1D* Sig_VBF = (TH1D*)stack[iCut+1][iVar]->GetStack()->Last();
	  Sig_VBF->Reset("ICEMS");
	
	  for(int iSample=0; iSample<nameSample.size(); iSample++)
	  {
	    if(nameSample.at(iSample)!="top" && nameSample.at(iSample)!="ttbar")continue;
	    
	    if(nameSample.at(iSample)=="ttbar")
	     Sig_VBF->Add(histo[iCut+1][iVar][iSample]);
	  
	    if(nameSample.at(iSample)=="top")
	     Sig_VBF->Add(histo[iCut+1][iVar][iSample]);
	  
	  }
	  
	  if(iNum==0)
	    Sig_VBF_Rebinned[iVar]=DynamicalRebinHisto(Sig_VBF,Sig_VBF_Rebinned[iVar],Bin_Extremes[iVar],isDATA,isDivide);
	   
          THStack* stack_rebin;
          stack_rebin=DynamicalRebinStack(stack[iCut][iVar],stack_rebin,Bin_Extremes[iVar],isDATA,isDivide);
	 
          TObjArray* histo_stack = stack_rebin->GetStack() ;

	  TString name=Form("BTag_VBF_%s_%d",Variable[iVar].first.c_str(),iCut);
          BTag_VBF[iNum]=(TH1D*)Sig_VBF_Rebinned[iVar]->Clone("BTag_VBF");
          BTag_VBF[iNum]->SetName(name);
          BTag_VBF[iNum]->Reset("ICEMS");
       
          for(int iHisto=0; iHisto<histo_stack->GetEntries(); iHisto++)
          {  
	    if(iHisto==0)
            {  
              TH1D* Histo1 = (TH1D*) histo_stack->At(iHisto);
	      TH1D* Histo_temp_1= (TH1D*) Histo1->Clone("Histo_temp_1");
	      
	      for(int iBin=0; iBin<Histo1->GetNbinsX(); iBin++)
	      {	
	       Histo_temp_1->SetBinContent(iBin+1,num_btag->PoissonD(Histo1->GetBinContent(iBin+1)));
	      }
	      
	      BTag_VBF[iNum]->Add(Histo_temp_1);
	    }
	    else{  
                   TH1D* Histo1 = (TH1D*) histo_stack->At(iHisto-1);
                   TH1D* Histo2 = (TH1D*) histo_stack->At(iHisto);
		   
		   TH1D* Histo_temp_1= (TH1D*) Histo1->Clone("Histo_temp_1");
		   TH1D* Histo_temp_2= (TH1D*) Histo2->Clone("Histo_temp_2");
		   
		   Histo_temp_2->Add(Histo_temp_1,-1);
		  
		   for(int iBin=0;  iBin<Histo1->GetNbinsX(); iBin++)
	           { 
		     Histo_temp_2->SetBinContent(iBin+1,num_btag->PoissonD(Histo_temp_2->GetBinContent(iBin+1)));
		   }
	   
	           BTag_VBF[iNum]->Add(Histo_temp_2);
	        } 
	  }

          if(Closure_Efficiency[iNum]!=0 && BTag_VBF[iNum]!=0 && Sig_VBF!=0)
          {
	
	     Sig_Estimation[iNum]=(TH1D*) Sig_VBF_Rebinned[iVar]->Clone("Sig_Estimation");
	     Sig_Estimation[iNum]->Reset("ICEMS");
	     
	     for(int iBin=0; iBin<BTag_VBF[iNum]->GetNbinsX(); iBin++)
	     { 
// 	       BTag_VBF[iNum]->SetBinError(iBin+1,sqrt(BTag_VBF[iNum]->GetBinContent(iBin+1))); ///== in this way i use Total MC in the control region as they were DATA

	       if(Closure_Efficiency[iNum]->GetBinContent(iBin+1)!=0)
	       { 
		 Sig_Estimation[iNum]->SetBinContent(iBin+1,BTag_VBF[iNum]->GetBinContent(iBin+1)*((1-Closure_Efficiency[iNum]->GetBinContent(iBin+1))/(Closure_Efficiency[iNum]->GetBinContent(iBin+1))));
	         Sig_Estimation[iNum]->SetBinError(iBin+1,(1/(Closure_Efficiency[iNum]->GetBinContent(iBin+1)))*sqrt(((Closure_Efficiency[iNum]->GetBinError(iBin+1))*(Closure_Efficiency[iNum]->GetBinError(iBin+1))*((BTag_VBF[iNum]->GetBinContent(iBin+1)*BTag_VBF[iNum]->GetBinContent(iBin+1))/(Closure_Efficiency[iNum]->GetBinContent(iBin+1)*Closure_Efficiency[iNum]->GetBinContent(iBin+1)))+BTag_VBF[iNum]->GetBinError(iBin+1)*BTag_VBF[iNum]->GetBinError(iBin+1)*(1-Closure_Efficiency[iNum]->GetBinContent(iBin+1))*(1-Closure_Efficiency[iNum]->GetBinContent(iBin+1)))));       

		 std::cout<<"[Test Number]:   "<<iNum<<"   [Bin Selected]:  "<<iBin<<"  [Simuated Efficiency]:   "<<Closure_Efficiency[iNum]->GetBinContent(iBin+1)<<"  [Simulated BTag Events]:   "<<BTag_VBF[iNum]->GetBinContent(iBin+1)<<"  [Data Driven Result]:   "<<Sig_Estimation[iNum]->GetBinContent(iBin+1)<<std::endl;
		 
	       }
	       else{
		      Sig_Estimation[iNum]->SetBinContent(iBin+1,0);
		      Sig_Estimation[iNum]->SetBinError(iBin+1,0);
	           }
		 

	     }
          }

       }
    }
    
   
    Sig_Estimation[iNum]->SetMarkerStyle(21);
    Sig_Estimation[iNum]->SetMarkerColor(kBlue);
    Sig_Estimation[iNum]->SetLineColor(kBlue);
    Sig_Estimation[iNum]->SetLineWidth(2);
    Sig_Estimation[iNum]->SetFillColor(kBlue);
    Sig_Estimation[iNum]->SetFillStyle(3002);
    TString Title=Form("Closure Test %s",nameHumanVariable.at(iVar).c_str());
    Sig_Estimation[iNum]->SetTitle(Title);
    Sig_Estimation[iNum]->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
    Sig_Estimation[iNum]->GetYaxis()->SetTitle("Events");
    Sig_Estimation[iNum]->GetYaxis()->SetRangeUser(0,Sig_Estimation[iNum]->GetMaximum()+1.3*Sig_Estimation[iNum]->GetBinError(Sig_Estimation[iNum]->GetMaximumBin()));
   
    Sig_VBF_Rebinned[iVar]->SetMarkerStyle(21);
    Sig_VBF_Rebinned[iVar]->SetMarkerColor(kRed);
    Sig_VBF_Rebinned[iVar]->SetLineColor(kRed);
    Sig_VBF_Rebinned[iVar]->SetLineWidth(2);
    Sig_VBF_Rebinned[iVar]->SetFillColor(kRed);
    Sig_VBF_Rebinned[iVar]->SetFillStyle(3002);
   
   
/*   TCanvas c5;
   TLegend * leg =new TLegend(0.75,0.7,0.98,0.9);
   leg->AddEntry(Sig_Estimation[iNum],"Data Driven Estimation");
   leg->AddEntry(Sig_VBF_Rebinned[iNum],"MC in VBF BVeto Region");
   leg->SetFillColor(kWhite);
   
   Sig_Estimation[iNum]->Draw("E2");
   Sig_VBF_Rebinned[iNum]->Draw("Esame");
   leg->Draw();
   Title=Form("Closure_Test_%s",nameHumanVariable.at(iVar).c_str());
   c5.SetName(Title);
   c5.Write();
*/
  }
 
  Sig_Estimation_Final=(TH1D*) Sig_Estimation[0]->Clone("Sig_Estimation_Final");
  Sig_Estimation_Final->Reset("ICEM");

  for(int iBin=0; iBin<Sig_Estimation_Final->GetNbinsX(); iBin++)
  {
    TString mean_Title=Form("mean-Distribution_%.1f < %s < %.1f",Bin_Extremes[iVar].at(iBin),nameHumanVariable.at(iVar).c_str(),Bin_Extremes[iVar].at(iBin+1));
    TH1D* mean_Distribution=new TH1D(mean_Title,mean_Title,100,0,15);
  
    for(int iNum=0; iNum<Closure_Number; iNum++)
    {
       mean_Distribution->Fill(Sig_Estimation[iNum]->GetBinContent(iBin+1));
    }
  
   TCanvas c5;
   
   Sig_Estimation_Final->SetBinContent(iBin+1,mean_Distribution->GetMean());
   Sig_Estimation_Final->SetBinError(iBin+1,mean_Distribution->GetRMS());
   
   std::cout<<"[Final Result]  "<<"  [Bin Number]:  "<<iBin<<"  [Bin Content]:  "<<mean_Distribution->GetMean()<<std::endl;
   
   mean_Distribution->GetXaxis()->SetTitle("Reconstructed Events");
   mean_Distribution->GetXaxis()->SetTitle("Bin Entries");
   mean_Distribution->Draw();
   
   TString Title=Form("Mean_Distribution_%s_%d",nameHumanVariable.at(iVar).c_str(),iBin);
   c5.SetName(Title);
   c5.Write();
  
  }

  Sig_Estimation_Final->SetMarkerStyle(21);
  Sig_Estimation_Final->SetMarkerColor(kBlue);
  Sig_Estimation_Final->SetLineColor(kBlue);
  Sig_Estimation_Final->SetLineWidth(2);
  Sig_Estimation_Final->SetFillColor(kBlue);
  Sig_Estimation_Final->SetFillStyle(3002);
  
  TString Title=Form("Result Closure Test %s",nameHumanVariable.at(iVar).c_str());
  Sig_Estimation_Final->SetTitle(Title);
  Sig_Estimation_Final->GetXaxis()->SetTitle(nameHumanVariable.at(iVar).c_str());
  Sig_Estimation_Final->GetYaxis()->SetTitle("Events");
  Sig_Estimation_Final->GetYaxis()->SetRangeUser(0,Sig_Estimation_Final->GetMaximum()+1.3*Sig_Estimation_Final->GetBinError(Sig_Estimation_Final->GetMaximumBin()));
   
  Sig_VBF_Rebinned[iVar]->SetMarkerStyle(21);
  Sig_VBF_Rebinned[iVar]->SetMarkerColor(kRed);
  Sig_VBF_Rebinned[iVar]->SetLineColor(kRed);
  Sig_VBF_Rebinned[iVar]->SetLineWidth(2);
  Sig_VBF_Rebinned[iVar]->SetFillColor(kRed);
  Sig_VBF_Rebinned[iVar]->SetFillStyle(3002);
   
   
  TCanvas c5;
  TLegend * leg =new TLegend(0.75,0.7,0.98,0.9);
  leg->AddEntry(Sig_Estimation[iVar],"Data Driven Estimation");
  leg->AddEntry(Sig_VBF_Rebinned[iVar],"MC in VBF BVeto Region");
  leg->SetFillColor(kWhite);
   
  Sig_Estimation_Final->Draw("E2");
  Sig_VBF_Rebinned[iVar]->Draw("Esame");
  leg->Draw();
  Title=Form("Result_Closure_Test_%s",nameHumanVariable.at(iVar).c_str());
  c5.SetName(Title);
  c5.Write();
 
   
   
 }
 return(0);

}


