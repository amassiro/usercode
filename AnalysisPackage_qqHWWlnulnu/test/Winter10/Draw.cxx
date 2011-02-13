///==== draw results from "FinalSelection_Producer.exe" ====

#include <iomanip>
#include "TDRStyle.cc"
#include "Read.cc"

void Draw(TString fileSamples, TString WhatToPlot = "", double MIN = -10, double MAX = 10, int NBIN = 1000, double LUMI = 500, TString Cut = ""){
 
 TDRStyle();
 
 
 EColor vColor[1000] = {
  kGreen,(EColor) (kGreen+1),
  //kMagenta,(EColor) (kMagenta+1),(EColor) (kMagenta+2),
  kTeal,//(EColor) (kTeal+1),
  kRed,
  kGray,
  kOrange,(EColor) (kOrange+1),
  kBlue,//(EColor)(kBlue+1),(EColor) (kBlue+2),
  (EColor) (kPink+2),//(EColor) (kPink+1),(EColor) (kPink+2),
  kViolet,
  kYellow,
  kGray,(EColor) (kGray+1),(EColor) (kViolet),(EColor) (kYellow),(EColor) (kGray)
 };
 
 
 //  EColor vColor[1000] = {
  //   (EColor) (kGreen+2),kBlue,
 //   kBlack,
 //   //kMagenta,(EColor) (kMagenta+1),(EColor) (kMagenta+2),
 //   kRed,
 //   kTeal,//(EColor) (kTeal+1),
 //   kGray,
 //   kOrange,(EColor) (kOrange+1),
 //   //kBlue,//(EColor)(kBlue+1),(EColor) (kBlue+2),
 //   (EColor) (kPink+2),//(EColor) (kPink+1),(EColor) (kPink+2),
 //   kViolet,
 //   kYellow,
 //   kGray,(EColor) (kGray+1),(EColor) (kViolet),(EColor) (kYellow),(EColor) (kGray)
 //  };
 
 
  std::cerr << " Cut = " << Cut.Data() << std::endl;
 
 TTree *treeEffVect[100];
 TTree *treeJetLepVect[100];
 
 TH1F* histo[100];
 TH1F* histo_temp[100];
 
 
 char *nameSample[1000];
 char *nameHumanReadable[1000];
 char* xsectionName[1000];
 
 double xsection[1000];
 
 char nameFileIn[1000] = fileSamples.Data();
 
 int numberOfSamples =  ReadFile(nameFileIn,nameSample,nameHumanReadable, xsectionName);
 
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  char nameFile[20000];
  sprintf(nameFile,"output_Fall10/out_NtupleProducer_%s.root",nameSample[iSample]);  
  TFile* f = new TFile(nameFile, "READ");
  
  treeEffVect[iSample] = (TTree) f->Get("outTreeSelections");
  char nameTreeEff[100];
  sprintf(nameTreeEff,"treeEff_%d",iSample); 
  treeEffVect[iSample]->SetName(nameTreeEff);      
  
  treeJetLepVect[iSample] = (TTree) f->Get("outTreeJetLep");
  char nameTreeJetLep[100];
  sprintf(nameTreeJetLep,"treeJetLep_%d",iSample); 
  treeJetLepVect[iSample]->SetName(nameTreeJetLep);
 }
  
 ///===== create map for joint sample ====
 
 std::vector<int> join_samples;
 std::vector<std::string> name_samples;
 for (int iSample=0; iSample<numberOfSamples; iSample++){
  name_samples.push_back(nameHumanReadable[iSample]);
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
    //  for (int iSample=0; iSample<numberOfSamples; iSample++){
     for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
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
     
     //  for (int iSample=0; iSample<numberOfSamples; iSample++){
      for (int iSample = (numberOfSamples-1); iSample>= 0; iSample--){
       double XSection;
       int numEntriesBefore;
       double preselection_efficiency;
       treeEffVect[iSample]->SetBranchAddress("XSection",&XSection);
       treeEffVect[iSample]->SetBranchAddress("numEntriesBefore",&numEntriesBefore);
       treeEffVect[iSample]->SetBranchAddress("preselection_efficiency",&preselection_efficiency);  
       treeEffVect[iSample]->GetEntry(0);
       
       std::cout << " Xsection = " << XSection << " ~~~> " << xsection[iSample] << std::endl;
//       XSection = xsection[iSample];
       
       TString name_histo_temp = Form("%s_temp",nameSample[iSample]);
       histo_temp[iSample] = new TH1F(name_histo_temp,name_histo_temp,NBIN,MIN,MAX);
       
       char toDraw[1000];
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
      
      std::cout.precision (3) ;
      std::cout.unsetf(ios::scientific);
      
      double total_MC_expected = 0;
      double total_DATA_measured = 0;
      std::cout << std::endl << std::endl << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
      for (int iName=0; iName<reduced_name_samples.size(); iName++){
       std::cout << "  " << setw (12) << reduced_name_samples.at(iName) << " | " << histo[iName]->Integral() << std::endl;
       if (reduced_name_samples.at(iName) != "DATA") total_MC_expected += histo[iName]->Integral();
	   else total_DATA_measured += histo[iName]->Integral();
      }
      std::cout << std::endl;
      std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
      
      std::cout << " MC expected   = " << total_MC_expected << " +/- " << sqrt(total_MC_expected) << std::endl;
      std::cout << " DATA measured = " << total_DATA_measured << " +/- " << sqrt(total_DATA_measured) << std::endl;
      
      std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
      
      
      
      ///==================================================
      ///==================================================
      ///================================================== 
      ///================================================== 
      ///================================================== 
//       int numSignal = HowManySignalSamples;
      
      TIter Iterator(hs->GetHists());
      TKey *key;
      
      TH1F *vectHist[1000];
      
      TH1F *bkgHist;
      TH1F *sigHist;
      
      TCanvas* cCompare = new TCanvas("cCompare","cCompare",800,800);
       cCompare->Divide(2,2);
       cCompare->cd(1);
       hs->Draw();
       gPad->SetLogy();
       gPad->SetGrid();
       gPad->BuildLegend();
       double bkg_temp = 0;
       double sig_temp = 0;
       
       TString nameSignal = "ttbar";
       int numSample = 0;
       
       while (key = (TKey *) Iterator()){
	TString nameHisto;
	nameHisto = key->GetName();  
	TH1F* temp_h = gROOT->FindObject(nameHisto);
	vectHist[numSample] = temp_h;
	
	if (nameSignal == nameHisto) {
	 sig_temp += temp_h->Integral();
	 std::cerr << " [" << sig_temp << "] " << " >>> sig += " << temp_h->Integral() << " ~ " << temp_h->GetEntries() << "     =>  " << nameHisto.Data() << std::endl;
	 sigHist = (TH1F*) temp_h->Clone("signal");
	 sigHist->SetTitle("signal");
	 std::cerr << "  ====> signal = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
	}
	else{
	 bkg_temp += temp_h->Integral();
	 std::cerr << " [" << bkg_temp << "] >>> bkg += " << temp_h->Integral() << " ~ " << temp_h->GetEntries() << "     =>  " << nameHisto.Data() << std::endl;
	 if (bkgHist == NULL) {
	  bkgHist = (TH1F*) temp_h->Clone("background");
	  bkgHist->SetTitle("background");
	  std::cerr << "  ====> background = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
	 }
	 else bkgHist -> Add (temp_h);
	}
	
	std::cerr << " numSample = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
	numSample++;
       }
       
       
       //  int numBkg = (reduced_name_samples.size()-numSignal-1);
       //  while (key = (TKey *) Iterator()){
	   //   TString nameHisto;
	   //   nameHisto = key->GetName();  
	   //   TH1F* temp_h = gROOT->FindObject(nameHisto);
	   //   vectHist[numSample] = temp_h;
	   //   
	   //   if (numSample < numBkg) {
	//    bkg_temp += temp_h->Integral();
	//    std::cerr << " [" << bkg_temp << "] >>> bkg += " << temp_h->Integral() << " ~ " << temp_h->GetEntries() << "     =>  " << nameHisto.Data() << std::endl;
	//    if (numSample == 0) {
	 //     bkgHist = (TH1F*) temp_h->Clone("background");
	 //     bkgHist->SetTitle("background");
	 //     std::cerr << "  ====> background = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
	 //    }
	 //    else bkgHist -> Add (temp_h);
	 //   }
	 //   
	 //   if (numSample >= numBkg) {
	  //    sig_temp += temp_h->Integral();
	  //    std::cerr << " [" << sig_temp << "] " << " >>> sig += " << temp_h->Integral() << " ~ " << temp_h->GetEntries() << "     =>  " << nameHisto.Data() << std::endl;
	  //    if (numSample == numBkg) {
	   //     sigHist = (TH1F*) temp_h->Clone("signal");
	   //     sigHist->SetTitle("signal");
	   //     std::cerr << "  ====> signal = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
	   //    }
	   //    else sigHist -> Add (temp_h);
	   //   }
	   //   
	   //   std::cerr << " numSample = " << numSample << " => nameHisto = " << nameHisto.Data() << std::endl;
	   //   numSample++;
	   //  }
	   
	   
	   ///==================
	   TCanvas* cCompareSum = new TCanvas("cCompareSum","cCompareSum",800,800);
	   hs->Draw();
	   gPad->SetLogy();
	   gPad->SetGrid();
	   //   gPad->BuildLegend();
	   ///==================
	   
	   TCanvas* cHistos = new TCanvas("cHistos","cHistos",600,600);
	   cHistos->Divide(sqrt(numSample)+1,sqrt(numSample)+1);
	   for (int iSample = 0; iSample < numSample; iSample++){
	    cHistos->cd(iSample+1);
	    vectHist[iSample]->DrawClone();
	   }
	   
	   ///==================
	   TCanvas* cCompareSumSB = new TCanvas("cCompareSumSB","cCompareSumSB",800,800);
	   sigHist->SetLineWidth(4);
	   bkgHist->SetLineWidth(4);
	   sigHist->SetLineColor(kBlue);
	   bkgHist->SetLineColor(kRed);
	   sigHist->SetMarkerColor(kBlue);
	   bkgHist->SetMarkerColor(kRed);
	   sigHist->SetMarkerStyle(20);
	   bkgHist->SetMarkerStyle(20);
	   sigHist->SetMarkerSize(4);
	   bkgHist->SetMarkerSize(4);
	   sigHist->SetFillColor(0);
	   bkgHist->SetFillColor(0);
	   bkgHist->DrawNormalized();
	   sigHist->DrawNormalized("same");
	   gPad->SetLogy();
	   gPad->SetGrid();
	   gPad->BuildLegend();
	   ///==================
	   
	   cCompare->cd(2);
	   sigHist->SetLineWidth(2);
	   bkgHist->SetLineWidth(2);
	   sigHist->SetLineColor(kBlue);
	   bkgHist->SetLineColor(kRed);
	   sigHist->SetMarkerColor(kBlue);
	   bkgHist->SetMarkerColor(kRed);
	   sigHist->SetFillColor(0);
	   bkgHist->SetFillColor(0);
	   bkgHist->Draw();
	   sigHist->Draw("same");
	   gPad->SetLogy();
	   gPad->SetGrid();
	   gPad->BuildLegend();
	   
	   cCompare->cd(3);
	   
	   
	   TH1F* cumulBkg = bkgHist->Clone();
	   Double_t* integBkg = bkgHist->GetIntegral();
	   for (int iBin = 0; iBin < bkgHist->GetNbinsX(); iBin++){
	    integBkg[iBin] = 1 - integBkg[iBin];
	   }
	   cumulBkg->SetContent(integBkg);
	   cumulBkg->Scale(bkgHist->Integral());
	   cumulBkg->Draw();
	   
	   std::cerr << " sig = " << sigHist->Integral() << std::endl;
	   std::cerr << " bkg = " << bkgHist->Integral() << std::endl;
	   std::cerr << " bkg_temp = " << bkg_temp << std::endl;
	   
	   TH1F* cumulSig = sigHist->Clone();
	   Double_t* integSig = sigHist->GetIntegral();
	   for (int iBin = 0; iBin < sigHist->GetNbinsX(); iBin++){
	    integSig[iBin] = 1 - integSig[iBin];
	   }
	   cumulSig->SetContent(integSig);
	   cumulSig->Scale(sigHist->Integral());
	   cumulSig->Draw("same");
	   
	   gPad->SetLogy();
	   gPad->SetGrid();
	   gPad->BuildLegend();
	   
	   
	   
	   cCompare->cd(4);
	   bkgHist->DrawNormalized();
	   sigHist->DrawNormalized("same");
	   gPad->SetGrid();
	   gPad->BuildLegend();
	   
	   ///====================================================
	   ///====================================================
	   ///====================================================
	   ///====================================================
	   
	   
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
	      histo[iName]->SetLineWidth(4);
	      histo[iName]->DrawNormalized("");
	      already_drawn = true;
	     }
	     else {
	      histo[iName]->SetFillStyle(0);
	      histo[iName]->SetLineWidth(4);
	      histo[iName]->DrawNormalized("same");
	     }
	    }
	   }
	   gPad->SetGrid();
	   gPad->BuildLegend();
	   
	   
	   
	   
	   cCompareSum->cd();
	   gPad->SetLogy();
	   gPad->SetGrid();
	   gPad->BuildLegend();
	   gPad->Update();
	   
	   //   int cstop;
	   //   std::cin >> cstop;
	   
	   std::cerr << " ******************************************* end *******************************************" << std::endl;
	   
     }
     
     
     
