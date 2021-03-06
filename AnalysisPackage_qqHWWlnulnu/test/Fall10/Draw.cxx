///==== draw results from "FinalSelection_Producer.exe" ====

#include <iomanip>

void Draw(TString fileSamples, TString WhatToPlot = "", double MIN = -10, double MAX = 10, int NBIN = 1000, double LUMI = 500, TString Cut = "", int HowManySignalSamples = 5){
 
 ///===========================================================================
 
 //  gROOT->Reset();
 //  gROOT->SetStyle("Plain");
 //  gStyle->SetPalette(1); 
 //  gStyle->SetOptStat(1110);
 //  gStyle->SetPadTickX(1);
 //  gStyle->SetPadTickY(1);
 //  gStyle->SetTitleBorderSize(0);
 
 // style:
 
 //For the canvas:
 gStyle->SetCanvasBorderMode(0);
 gStyle->SetCanvasColor(kWhite);
 gStyle->SetCanvasDefH(800); //600
 //Height of canvas
 gStyle->SetCanvasDefW(800);//800 //Width of canvas
 gStyle->SetCanvasDefX(0);   //POsition on screen
 gStyle->SetCanvasDefY(0);
 
 // For the Pad:
 gStyle->SetPadBorderMode(0);
 // gStyle->SetPadBorderSize(Width_t size = 1);
 gStyle->SetPadColor(kWhite);
 gStyle->SetPadGridX(false);
 gStyle->SetPadGridY(false);
 gStyle->SetGridColor(0);
 gStyle->SetGridStyle(3);
 gStyle->SetGridWidth(1);
 
 //For the frame:
 gStyle->SetFrameBorderMode(0);
 gStyle->SetFrameBorderSize(1);
 gStyle->SetFrameFillColor(0);
 gStyle->SetFrameFillStyle(0);
 gStyle->SetFrameLineColor(1);
 gStyle->SetFrameLineStyle(1);
 gStyle->SetFrameLineWidth(1);
 
 // For the histo:
 gStyle->SetHistLineColor(1);
 gStyle->SetHistLineStyle(0);
 gStyle->SetHistLineWidth(2);
 gStyle->SetEndErrorSize(2);
 //  gStyle->SetErrorMarker(20);
 //gStyle->SetErrorX(0.);
 gStyle->SetMarkerStyle(8);
 
 
 // For the statistics box:
 gStyle->SetOptFile(0);
 //  gStyle->SetOptStat(1);
 gStyle->SetOptStat(0);
 gStyle->SetStatColor(kWhite);
 gStyle->SetStatFont(42);
 gStyle->SetStatFontSize(0.025);
 gStyle->SetStatTextColor(1);
 gStyle->SetStatFormat("6.4g");
 gStyle->SetStatBorderSize(1);
 //   gStyle->SetStatBorderSize(0);
 gStyle->SetStatH(.1);
 gStyle->SetStatW(.15);
 
 //  gStyle->SetStatX(.9);
 // gStyle->SetStatY(.9);
 
 // For the Global title:
 gStyle->SetOptTitle(0);
 //   gStyle->SetOptTitle(1);
 gStyle->SetTitleFont(42);
 gStyle->SetTitleColor(1);
 gStyle->SetTitleTextColor(1);
 gStyle->SetTitleFillColor(10);
 gStyle->SetTitleFontSize(0.05);
 
 // For the axis titles:
 gStyle->SetTitleColor(1, "XYZ");
 gStyle->SetTitleFont(42, "XYZ");
 //  gStyle->SetTitleSize(0.06, "XYZ");
 gStyle->SetTitleSize(0.04, "XYZ");
 gStyle->SetTitleXOffset(0.9);
 // gStyle->SetTitleYOffset(1.25);
 //gStyle->SetTitleXOffset(0.5);
 gStyle->SetTitleYOffset(1.0);
 
 // For the axis labels:
 gStyle->SetLabelColor(1, "XYZ");
 gStyle->SetLabelFont(42, "XYZ");
 gStyle->SetLabelOffset(0.007, "XYZ");
 
 gStyle->SetLabelSize(0.05, "XYZ");
 //gStyle->SetLabelSize(0.02, "XYZ");
 
 // For the axis:
 gStyle->SetAxisColor(1, "XYZ");
 gStyle->SetStripDecimals(kTRUE);
 gStyle->SetTickLength(0.03, "XYZ");
 gStyle->SetNdivisions(510, "XYZ");
 gStyle->SetPadTickX(0);  // To get tick marks on the opposite side of the frame
 gStyle->SetPadTickY(1);
 // // Postscript options:
 //   //gStyle->SetPaperSize(20.,20.);
 
 // CC style  
 gStyle->SetTitleXOffset(0.8);
 //   gStyle->SetTitleYOffset(0.8);
 //Inv Mass Presel
 gStyle->SetTitleYOffset(1.0);
 
 gStyle->SetLabelOffset(0.005, "XYZ");
 gStyle->SetTitleSize(0.07, "XYZ");
 gStyle->SetTitleFont(22,"X");
 gStyle->SetTitleFont(22,"Y");
 /*  gStyle->SetPadBottomMargin(0.13);
  * gStyle->SetPadTopMargin(0.23);
  * gStyle->SetPadLeftMargin(0.15);
  * gStyle->SetPadRightMargin(0.21);*/
 /*  //PlotPt4Lep=====================
  * gStyle->SetPadBottomMargin(0.15);
  * gStyle->SetPadTopMargin(0.05);
  * gStyle->SetPadLeftMargin(0.15);
  * gStyle->SetPadRightMargin(0.05);*/
 /*  //PlotPrePreSelInvMass=====================
  * gStyle->SetPadBottomMargin(0.15);
  * gStyle->SetPadTopMargin(0.10);
  * gStyle->SetPadLeftMargin(0.15);
  * gStyle->SetPadRightMargin(0.10);*/
 /*  //PlotPrePreSelEff=====================
  * gStyle->SetPadBottomMargin(0.15);
  * gStyle->SetPadTopMargin(0.15);
  * gStyle->SetPadLeftMargin(0.15);
  * gStyle->SetPadRightMargin(0.15);*/
 //PlotInvMass=====================
 gStyle->SetPadBottomMargin(0.15);
 gStyle->SetPadTopMargin(0.05);
 gStyle->SetPadLeftMargin(0.15);
 gStyle->SetPadRightMargin(0.10);
 /*  //PlotEffvsEff=====================
  * gStyle->SetPadBottomMargin(0.15);
  * gStyle->SetPadTopMargin(0.05);
  * gStyle->SetPadLeftMargin(0.15);
  * gStyle->SetPadRightMargin(0.05);*/
 /*  //JetMET=====================
  * gStyle->SetPadBottomMargin(0.15);
  * gStyle->SetPadTopMargin(0.05);
  * gStyle->SetPadLeftMargin(0.15);
  * gStyle->SetPadRightMargin(0.05);*/
 //   //Met2dEff=====================
 //   gStyle->SetPadBottomMargin(0.15);
 //   gStyle->SetPadTopMargin(0.05);
 //   gStyle->SetPadLeftMargin(0.15);
 //   gStyle->SetPadRightMargin(0.15);
 //   //Dalitz+PtVsMET=====================
 //   gStyle->SetPadBottomMargin(0.15);
 //   gStyle->SetPadTopMargin(0.10);
 //   gStyle->SetPadLeftMargin(0.15);
 //   gStyle->SetPadRightMargin(0.15);
 
 /*  gStyle->SetPadBottomMargin(0.13);
  * gStyle->SetPadLeftMargin(0.15);*/
 //  gStyle->SetHistLineWidth(3);
 gStyle->SetHistLineWidth(2);
 gStyle->SetLineStyleString(5,"20 12 4 12");
 gStyle->SetLineStyleString(6,"20 12 4 12 4 12 4 12");
 gStyle->SetLineStyleString(7,"20 20");
 gStyle->SetLineStyleString(8,"20 12 4 12 4 12");
 gStyle->SetLineStyleString(9,"80 20");
 
 
 //  TGaxis::SetMaxDigits(2);
 
 
 gStyle->cd(); 
 
 ///===========================================================================
 
 
 
 
 
 
 
 
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
 
 
 char *nameSample[10000];
 char *nameHumanReadable[10000];
 char* xsectionName[10000];
 
 double xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile(fileSamples.Data());
 std::string buffer;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  //  std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){ 
    std::stringstream line( buffer );       
    nameSample[numberOfSamples] = new char [10000];
    line >> nameSample[numberOfSamples]; 
    std::cout << nameSample[numberOfSamples] << " ";
    
    xsectionName[numberOfSamples] = new char [10000];
    line >> xsectionName[numberOfSamples]; 
    std::cout << xsectionName[numberOfSamples] << " ";
    
    nameHumanReadable[numberOfSamples] = new char [10000];
    line >> nameHumanReadable[numberOfSamples]; 
    std::cout << nameHumanReadable[numberOfSamples] << " ";
    
    std::cout << std::endl;
    
    char nameFile[20000];
    sprintf(nameFile,"output/NtupleProducerTTBar_%s.root",nameSample[numberOfSamples]);  
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
 
 
//  for (int iSample=0; iSample<numberOfSamples; iSample++){
//   std::cout << " iSample = " << iSample << std::endl;
//   char toDo[1000];
//   sprintf(toDo,"xsection[%d]= %s ; ",iSample,xsectionName[iSample]);
//   std::cout << " toDo = " << toDo << std::endl;
//   gROOT->ProcessLine(toDo);
//   std::cout << " xsection[" << iSample << "] = " << xsection[iSample] << std::endl;
// }
 
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
      int numSignal = HowManySignalSamples;
      
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
     
     
     
