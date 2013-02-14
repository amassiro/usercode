{
//  scp amassiro@cmsmi4.cern.ch:/data2/amassiro/VBF/Summer12/02Oct2012/Shape/playground/FINALdc/*.root ./
 
 #include <map>

 
//  TF2 *f2 = new TF2("f2","0.1+(1-(x-2)*(x-2))*(1-(y-2)*(y-2))",1,3,1,3);
//  UInt_t Number = 3;
//  Double_t Red[Number]    = { 1.00, 0.00, 0.00};
//  Double_t Green[Number]  = { 0.00, 1.00, 0.00};
//  Double_t Blue[Number]   = { 1.00, 0.00, 1.00};
//  Double_t Length[Number] = { 0.00, 0.50, 1.00 };
//  Int_t nb=50;
//  TColor::CreateGradientColorTable(Number,Length,Red,Green,Blue,nb);
 
//  const Int_t NRGBs = 5;
//  const Int_t NCont = 255;
//  
//  Double_t stops[NRGBs] = { 1.00, 0.00, 0.34, 0.61, 0.84 };
//  Double_t red[NRGBs]   = { 0.51, 0.00, 0.00, 0.87, 1.00 };
//  Double_t green[NRGBs] = { 0.00, 0.00, 0.81, 1.00, 0.20 };
//  Double_t blue[NRGBs]  = { 0.00, 0.51, 1.00, 0.12, 0.00 };
//  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
//  gStyle->SetNumberContours(NCont);
 
 gStyle->SetPalette(1);
 
 
//  const Int_t NRGBs = 5;
//  const Int_t NCont = 50;
//  
//  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
//  Double_t red[NRGBs]   = { 0.51, 1.00, 0.87, 0.00, 0.00 };
//  Double_t green[NRGBs] = { 0.00, 0.20, 1.00, 0.81, 0.00 };
//  Double_t blue[NRGBs]  = { 0.00, 0.00, 0.12, 1.00, 0.51 };
//  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
//  gStyle->SetNumberContours(NCont);
//  
 
 //                   1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27
 Double_t MH[1000];
//  = {110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165};

 
 
//   //---- from 110 to 124 step 0.5 GeV
//   for (int i=0; i<28; i++) {
//     MH[i] = 110+i*0.5;
//    std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//   }
//  
//   //---- from 124 to 127 step 0.1 GeV
//   for (int i=28; i<58; i++) {
//     MH[i] = 124+(i-28)/10.;
//    std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//   }
//   
//   //---- from 127 to 160 step 1 GeV
//   for (int i=58; i<84; i++) {
//     MH[i] = 127+(i-58);
//    std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//   }
//   
//   //---- from 160 to 300 step 2 GeV
//   for (int i=84; i<300; i++) {
//     MH[i] = 160+2*(i-84);
//    std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//   }
//  
//  int nMass = 100;
 
 
//  //---- from 110 to 124 step 1 GeV
//  for (int i=0; i<14; i++) {
//   MH[i] = 110+i;
//   std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//  }
// 
//  //---- from 124 to 127 step 0.1 GeV
//  for (int i=14; i<44; i++) {
//   MH[i] = 124+(i-14)/10.;
//   std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//  }
//  
//  //---- from 127 to 160 step 1 GeV
//  for (int i=44; i<70; i++) {
//   MH[i] = 127+(i-44);
//   std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//  }
//  
//  //---- from 160 to 300 step 2 GeV
//  for (int i=70; i<300; i++) {
//   MH[i] = 160+2*(i-70);
//   std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//  }
 

 
//  //---- from 110 to 120 step 2 GeV
//  for (int i=0; i<5; i++) {
//   MH[i] = 110+2*i;
//   std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//  }
//  
//  //---- from 120 to 130 step 1 GeV
//  for (int i=5; i<15; i++) {
//   MH[i] = 120+(i-5);
//   std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//  }
//  
//  //---- from 130 to 300 step 2 GeV
//  for (int i=15; i<100; i++) {
//   MH[i] = 130+2*(i-15);
//   std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//  }

 
//  Double_t MH[200] = {110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 170, 180, 190, 200, 250, 300, 350, 400, 450, 500, 550, 600, 700, 800, 900, 1000};
 Double_t MH[200] = {110, 112.5, 115, 117.5, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 145, 150, 155, 160, 170, 180, 190, 200, 250, 300, 350, 400, 500, 600};
 int nMass = 33; 
//  int nMass = 36; 
 

 
 
//  Double_t MH[200] = {110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 170, 180, 190, 200, 250, 300};
//  int nMass = 15; 

 Double_t MH[200] = {110, 115, 120, 125, 130, 135, 140, 150, 160, 170, 180, 190, 200, 250, 300};
 int nMass = 13; 
 
 
 
//   int nMass = 47;
 //  int nMass = 18;
 
 bool debug = true;
 bool doGraph = true;
 int nDo = 0; 
 bool doZeroFilter = true;
 
 
 
 ///================================================0
 int doJetBin = 2;
 //---- 0 = 0 jet
 //---- 1 = 1 jet
 //---- 2 = 0+1 jet
 ///================================================0
 
 
 
 bool doColoured = true;
 
  
//  //---- from 110 to 300 step 2 GeV
//  for (int i=0; i<300; i++) {
//   MH[i] = 110+2*i;
// //   std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//  }
//  
//  //---- from 160 to 300 step 2 GeV
//  for (int i=50; i<300; i++) {
//   MH[i] = 160+2*(i-50);
// //   std::cout << " MH[" << i << "] = " << MH[i] << std::endl;
//  }
 
  
 Float_t Mu[800];
 Float_t dLL[200][800];
 Float_t LL[200][800];

//  double minMu = 0.025;
//  double maxMu = 3.025;
//  int nMu = 60;
 
 double maxMu = 3.0125;
 double minMu = 0.0125;
 int nMu = 120;

//  double minMu = 0.05;
//  double maxMu = 5.05;
//  int nMu = 50;

//  double minMu = 0.0125;
//  double maxMu = 5.0125;
//  int nMu = 200;
 
//  double minMu = 0.0125;
//  double maxMu = 3.0125;
//  int nMu = 120;
 
 
 double deltaMu = (maxMu-minMu) / nMu;

 //           mass              mu     LL
 std::map <float, float>  LLmap[800];

 TString name;

 TFile* inputFileRoot[800];

//  int nMu = 0;
 for (int iMass = 0; iMass < nMass; iMass++) {
//   name = Form ("higgsCombineTest.MultiDimFit.mH%d.0jet.root",int(MH[iMass]));
//   name = Form ("higgsCombineTest.MultiDimFit.mH%d.1jet.root",int(MH[iMass]));

//  --> only 0 jet!
//    name = Form ("0jetOnly/higgsCombineTest.MultiDimFit.mH%d.0jet.root",int(MH[iMass]));
   

//  --> used!!!
// name = Form ("higgsCombineTest.MultiDimFit.mH%d.01jet.root",int(MH[iMass]));
// name = Form ("01jet/higgsCombineTest.MultiDimFit.mH%d.root",int(MH[iMass]));

//    if (doJetBin==0)         name = Form ("0jet/higgsCombineTest.MultiDimFit.mH%d.0jet.root",int(MH[iMass]));
//    if (doJetBin==1)         name = Form ("1jet/higgsCombineTest.MultiDimFit.mH%d.1jet.root",int(MH[iMass]));
//    if (doJetBin==2)         name = Form ("01jet/higgsCombineTest.MultiDimFit.mH%d.01jet.root",int(MH[iMass]));

   if (doJetBin==0)         name = Form ("0jet-78TeV/higgsCombineTest.MultiDimFit.mH%d.0jet.root",int(MH[iMass]));
   if (doJetBin==1)         name = Form ("1jet-78TeV/higgsCombineTest.MultiDimFit.mH%d.1jet.root",int(MH[iMass]));
   if (doJetBin==2)         name = Form ("01jet-78TeV/higgsCombineTest.MultiDimFit.mH%d.01jet.root",int(MH[iMass]));
   


//   name = Form ("mu0_5_50bin/higgsCombineTest.MultiDimFit.mH%d.01jet.root",int(MH[iMass]));
  inputFileRoot[iMass] = TFile::Open(name,"READ");
  TTree* limit = (TTree*) inputFileRoot[iMass] -> Get ("limit");
  float r;
  float deltaNLL;
  limit->SetBranchAddress("r",&r);
  limit->SetBranchAddress("deltaNLL",&deltaNLL);
//   nMu = limit->GetEntries();

  std::map <float, float> LLmap_mass;
  for (int iEntry=0; iEntry<limit->GetEntries(); iEntry++) {
   limit->GetEntry(iEntry);
   if (debug) std::cout << " r[" << iEntry << "] = " << r << " :: deltaNLL = " << deltaNLL << std::endl;
   Mu[iEntry] = r;
   dLL[iMass][iEntry] = deltaNLL;
   LLmap_mass[r] = deltaNLL;
  }
  LLmap[iMass] = LLmap_mass;
 }

//  double minMu = 100;
//  double maxMu = -1;
//  int iMinMu = -1;
//  for (int iMu=0; iMu<nMu; iMu++) {t
//   std::cout << " minMu = " << minMu << " < Mu[" << iMu << "] = " << Mu[iMu] << " < maxMu = " << maxMu << std::endl;
//   if (minMu > Mu[iMu]) {
//    iMinMu = iMu;
//    minMu = Mu[iMu];
//   }
//   if (maxMu < Mu[iMu]) {
//    maxMu = Mu[iMu];
//   }
//  }




 //---- apply shift "bad events" ----
 double maxDELTA = 2.0;
 double maxDoubleDELTA = 0.24;
 for (int iDo = 0; iDo<nDo; iDo++) {
  if (debug) std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
  if (debug) std::cout << " iDo = " << iDo << " :: " << nDo << std::endl;
   for (int iMass = 0; iMass < nMass; iMass++) {
    double tempbeforebefore = 0;
    double tempbefore = 0;
    int itemp = 0;
    double shift = 0;
    double beforeshift = 0;
    double scale = 0;
    double ibinshift = -1;
    for(std::map <float, float>::iterator iterator = LLmap[iMass].begin(); iterator != LLmap[iMass].end(); iterator++) {
     double temp = iterator->second;
     if (itemp == 0) {
       tempbefore = temp;
       tempbeforebefore = temp;
     }
     else {
//        if (iMass == 2) std::cout << "mu = " << iterator->first << " ::: fabs(temp - tempbefore) = " << fabs(temp - tempbefore) << " > " << maxDELTA  << " :: fabs(beforeshift - (temp - tempbefore)) = " << fabs(beforeshift - (temp - tempbefore)) << " > " << maxDoubleDELTA << std::endl;
       if (itemp != 2 && (fabs(temp - tempbefore) > maxDELTA || ( itemp != 2 && fabs(beforeshift - (temp - tempbefore)) > maxDoubleDELTA ) && beforeshift!=0)) {
//          shift = (temp - tempbefore);	 
         shift = (temp - tempbefore) - beforeshift;	 
         scale = temp/tempbefore;
         ibinshift = itemp;
// 	 if (iMass == 1) std::cout << " iMass = " << iMass << "; ibinshift = " << ibinshift << "; shift = " << shift << "; temp = " << temp << "; tempbefore = " << tempbefore << "; beforeshift = " << beforeshift << std::endl;
	 break;
      }
     }
     beforeshift = temp - tempbefore;
     tempbefore = temp;
     itemp++;
    }
   
   if (debug) std::cout << " MH[" << iMass << "] = " << MH[iMass] << " :: ibinshift = " << ibinshift << " --> shift = " << shift << std::endl;
    itemp = 0;
    for(std::map <float, float>::iterator iterator = LLmap[iMass].begin(); iterator != LLmap[iMass].end(); iterator++) {
     double temp = iterator->second;
     if (itemp < ibinshift) {
//       std::cout << " temp old = " << temp;
      temp += shift ;
//      temp = temp*scale;
//      std::cout << " ::>> scale = " << scale << " ::>> temp new = " << temp << std::endl;
    }
    iterator->second = temp;
    itemp++;
   }
  }
 }

 
 
 
 
//---- apply shift for mu=0 same performance ----
 for (int iMass = 0; iMass < nMass; iMass++) {
//   double scale = dLL[0][iMinMu] / dLL[iMass][iMinMu];
  double shift = (LLmap[0])[minMu+deltaMu] - (LLmap[iMass])[minMu+deltaMu] + 0.1; // 0.1 arbitrary
//   std::cout << " shift = " << shift;
  for(std::map <float, float>::iterator iterator = LLmap[iMass].begin(); iterator != LLmap[iMass].end(); iterator++) {
   double temp = iterator->second;
   iterator->second = (temp + shift);
  }
//   for (int iMu=0; iMu<nMu; iMu++) {
//    LL[iMass][iMu] = scale * dLL[iMass][iMu];
//   }
 }

 std::cout << "  (LLmap[0])[" << minMu+deltaMu << "] = " <<  (LLmap[0])[minMu+deltaMu] << std::endl;
 
 //---- apply shift for minLL = 0 ----
 int iMin = -1;
 double muMin = -1;
 double minZ = 1000;
  for (int iMass = 0; iMass < nMass; iMass++) {
  for(std::map <float, float>::iterator iterator = LLmap[iMass].begin(); iterator != LLmap[iMass].end(); iterator++) {
   double temp = iterator->second;
   if (minZ > temp) {
    minZ = temp;
    iMin = iMass;
    muMin =  iterator->first;
   }
  }
 }
 std::cout << " minZ = " << minZ << std::endl;
 
 for (int iMass = 0; iMass < nMass; iMass++) {
  for(std::map <float, float>::iterator iterator = LLmap[iMass].begin(); iterator != LLmap[iMass].end(); iterator++) {
   double temp = iterator->second;
   iterator->second = (temp - minZ);
  }
 }
 
 
 //---- multiply x2 because I want 2 DeltaLogLikelihood ----
 for (int iMass = 0; iMass < nMass; iMass++) {
  for(std::map <float, float>::iterator iterator = LLmap[iMass].begin(); iterator != LLmap[iMass].end(); iterator++) {
   double temp = iterator->second;
   iterator->second = 2*temp;
  }
 }
 
 
 if (doZeroFilter) {
  //---- apply binFilling if "0" somewhere ----
  for (int iMass = 0; iMass < nMass; iMass++) {
   std::map <float, float>::iterator prev_iterator = LLmap[0].end();
   for(std::map <float, float>::iterator iterator = LLmap[0].begin(); iterator != LLmap[0].end(); iterator++) {
    if ((LLmap[iMass])[iterator->first] == 0 && prev_iterator != LLmap[0].end() ) {
     (LLmap[iMass])[iterator->first] = (LLmap[iMass])[prev_iterator->first];
    }
    prev_iterator = iterator;
   }
  }
 }
 
 std::cout << "  (LLmap[0])[" << minMu+deltaMu << "] = " <<  (LLmap[0])[minMu+deltaMu] << std::endl;
 std::cout << " nMass, MH[0], MH[" << nMass <<"], nMu, minMu, maxMu = " << nMass << "," << MH[0] << "," << MH[nMass] << "," << nMu << "," << minMu << "," << maxMu << std::endl;
 std::cout << " deltaMu = " << deltaMu << std::endl;
 std::cout << " minMu = " << minMu << std::endl;
 std::cout << " maxMu = " << maxMu << std::endl;

 TGraph2D* grScanMuMH = new TGraph2D();
 grScanMuMH -> SetTitle ("");
//  TH2F* scanMuMH = new TH2F("scanMuMH","", nMass, MH[0], MH[nMass], nMu, minMu, maxMu);
 TH2F* scanMuMH = new TH2F("scanMuMH","", nMass, MH, nMu, minMu, maxMu);
 TH2F* scanMuMHtemp = new TH2F("scanMuMHtemp","", nMass-1, MH, nMu, minMu, maxMu);
 //  TH2F(const char* name, const char* title, Int_t nbinsx, const Double_t* xbins, Int_t nbinsy, Double_t ylow, Double_t yup)
 
 
 int iPointGr = 0;
 for (int iMass = 0; iMass < nMass; iMass++) {
//   for (int iMu=0; iMu<nMu; iMu++) {
//    scanMuMH->Fill (MH[iMass]+0.1, Mu[iMu],LL[iMass][iMu]);
//    std::cout << " MH[" << iMass << "]+0.1, Mu[" << iMu << "],LL[" << iMass << "][" << iMu << "] = " << MH[iMass]+0.1 << "," << Mu[iMu] << "," << LL[iMass][iMu] << std::endl;
//   }

 if (debug) std::cout << " MH[" << iMass << " ] = " << MH[iMass] << std::endl;
 if (debug) std::cout << " nMass, MH[0], MH[" << nMass <<"], nMu, minMu, maxMu = " << nMass << "," << MH[0] << "," << MH[nMass] << "," << nMu << "," << minMu << "," << maxMu << std::endl;
  for(std::map <float, float>::iterator iterator = LLmap[iMass].begin(); iterator != LLmap[iMass].end(); iterator++) {
   if (scanMuMH->GetBinContent(scanMuMH->FindBin(MH[iMass], iterator->first + deltaMu/10)) == 0)  scanMuMH->Fill (MH[iMass], iterator->first + deltaMu/10.,iterator->second);
//    else {
//      std::cout << " ALREADY FILLED: scanMuMH->FindBin(MH[" << iMass << "], " << iterator->first + deltaMu/10 << ") = " << scanMuMH->FindBin(MH[iMass], iterator->first + deltaMu/10) << std::endl;
//    }
//    std::cout << " scanMuMH->FindBin(MH[" << iMass << "], " << iterator->first << ") = " << scanMuMH->FindBin(MH[iMass], iterator->first) << std::endl;
//    std::cout << " scanMuMH->FindBin(" << MH[iMass] << " , " << iterator->first << ") = " << scanMuMH->FindBin(MH[iMass], iterator->first) << std::endl;
   grScanMuMH->SetPoint(iPointGr,MH[iMass], iterator->first,iterator->second);
   iPointGr++;
  }

 }


 TCanvas* cc = new TCanvas ("cc","cc",600,600);
 scanMuMH->GetXaxis()->SetTitle("m_{H} (GeV)");
 scanMuMH->GetYaxis()->SetTitle("#sigma/#sigma_{SM}");
 scanMuMH->GetZaxis()->SetTitle("-2#DeltaLL"); 
 scanMuMH -> Draw ("colz");
 gStyle->SetOptStat(0);
 gPad -> SetRightMargin(0.10);
 cc->SaveAs ("cc.png");
 cc->SaveAs ("cc.png");
 
 
 TCanvas* cc2Cont = new TCanvas ("cc2Cont","cc2Cont",600,600);
//  Double_t levels[100] = {0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0};
 Double_t levels[100] = {2.3,6.0,7, 8, 9, 10};
 gStyle->SetOptStat(0);
 scanMuMH -> SetContour (2,levels);
 scanMuMH -> Draw ("CONT Z LIST");
 gPad->Update();
 
 TObjArray *conts = (TObjArray*)  gROOT->GetListOfSpecials()->FindObject("contours");
 
 if (doColoured) grScanMuMH -> Draw ("COLZ");
//  grScanMuMH -> Draw ("AL");
 grScanMuMH->GetXaxis()->SetTitle("m_{H} (GeV)");
 grScanMuMH->GetYaxis()->SetTitle("#sigma/#sigma_{SM}");
 grScanMuMH->GetZaxis()->SetTitle("-2 #Delta ln L");
//  grScanMuMH->GetZaxis()->SetRangeUser(0,20);
//  grScanMuMH->GetZaxis()->SetRangeUser(0,10);
 grScanMuMH->GetZaxis()->SetRangeUser(0,12);
 if (doColoured)  {
  gPad -> SetRightMargin(0.15);
//   gPad -> SetLogz();
 }
 
 
 scanMuMHtemp->GetXaxis()->SetTitle("m_{H} (GeV)");
 scanMuMHtemp->GetYaxis()->SetTitle("#sigma/#sigma_{SM}");
 scanMuMHtemp->GetZaxis()->SetTitle("-2#DeltaLL");
 if (!doColoured) scanMuMHtemp -> Draw ("");
 gPad->SetGrid(); 
 
//  gPad -> SetRightMargin(0.15);

//  scanMuMH -> Draw ("CONT1 LIST SAME");
 
//  scanMuMH -> Draw ("A");
 gPad->Update();

 int nGraphs = 2;
 TLatex l;
 l.SetTextSize(0.03);
//  l.SetTextColor(kWhite);
 l.SetTextColor(kBlack);
 char val[2000];
 Double_t x0, y0, z0; 
 int TotalConts = 2;
 for(int i = 0; i < TotalConts; i++){
      contLevel = (TList*)conts->At(i);
      z0 = levels[i];
      z0 = levels[i];
      printf("Z-Level Passed in as:  Z = %f\n", z0);

      // Get first graph from list on curves on this level
      curv = (TGraph*)contLevel->First();
      for(int j = 0; j < contLevel->GetSize(); j++){
         curv->GetPoint(0, x0, y0);
         if (z0<0) curv->SetLineColor(kRed);
         if (z0>0) curv->SetLineColor(kBlue);
         nGraphs ++;
         printf("\tGraph: %d  -- %d Elements\n", nGraphs,curv->GetN());

	 // Draw clones of the graphs to avoid deletions in case the 1st
	 // pad is redrawn.
         
         gc = (TGraph*)curv->Clone();
         gc->GetXaxis()->SetTitle("m_{H} (GeV)");
         gc->GetYaxis()->SetTitle("Signal strength (#mu)");
         gc -> SetTitle ("");
         gc->SetLineColor(kBlack);
//          gc->SetLineColor(kWhite);
         gc->SetLineWidth(4);
         if (i==0) {
          gc->SetLineStyle(1);
         }
         else {
          gc->SetLineStyle(7);
         }
         if (j==0 && i==0) {
//           gc->Draw("AC");
          gc->Draw("C");
         }
         else {
          gc->Draw("C");
         }
         
         sprintf(val,"-2#DeltaLL = %g",z0);
//          l.DrawLatex(x0,y0,val);
         curv = (TGraph*)contLevel->After(curv); // Get Next graph
      }
   }
	 
 
//  sprintf(val,"X");
//  l.DrawLatex(MH[iMin],muMin,val);

 TLatex textcommon;
 textcommon.SetTextSize(0.04);
 textcommon.SetTextColor(kWhite);
 
//  if (doJetBin == 0) sprintf(val,"#splitline{CMS Preliminary}{#splitline{#sqrt{s} = 8 TeV, L = 19.5 fb^{-1}}{e#mu 0 jet}}");
//  if (doJetBin == 1) sprintf(val,"#splitline{CMS Preliminary}{#splitline{#sqrt{s} = 8 TeV, L = 19.5 fb^{-1}}{e#mu 1 jet}}");
//  if (doJetBin == 2) sprintf(val,"#splitline{CMS Preliminary}{#splitline{#sqrt{s} = 8 TeV, L = 19.5 fb^{-1}}{e#mu 0+1 jet}}");

 if (doJetBin == 0) sprintf(val,"#splitline{CMS Preliminary}{#splitline{#splitline{#sqrt{s} = 7/8 TeV}{L = 4.9 + 19.5 fb^{-1}}}{e#mu 0 jet}}");
 if (doJetBin == 1) sprintf(val,"#splitline{CMS Preliminary}{#splitline{#splitline{#sqrt{s} = 7/8 TeV}{L = 4.9 + 19.5 fb^{-1}}}{e#mu 1 jet}}");
 if (doJetBin == 2) sprintf(val,"#splitline{CMS Preliminary}{#splitline{#splitline{#sqrt{s} = 7/8 TeV}{L = 4.9 + 19.5 fb^{-1}}}{e#mu 0+1 jet}}");

 textcommon.DrawLatex(140,2.5,val);
 
 
 TGraph* grX = new TGraph();
 grX->SetPoint (0, MH[iMin],muMin);
 grX->SetLineWidth(2);
 grX->SetMarkerSize(2.5);
 grX->SetMarkerStyle(5);
//  grX->Draw ("P");
 
 scanMuMH->SetLineWidth(2);
 scanMuMH->SetLineStyle(2);
 scanMuMH->GetZaxis()->SetRangeUser(0,10);
 scanMuMH->GetXaxis()->SetTitle("m_{H} (GeV)");
 scanMuMH->GetYaxis()->SetTitle("#sigma/#sigma_{SM}");
 cc2Cont->SaveAs ("cc2Cont.png");
 cc2Cont->SaveAs ("cc2Cont.pdf");
 cc2Cont->SaveAs ("cc2Cont.eps");
 cc->SaveAs ("cc.png");
 
 
 TCanvas* ccScan2 = new TCanvas ("ccScan2","ccScan2",600,600);
 grScanMuMH -> Draw ("cont3");
 grScanMuMH->GetXaxis()->SetTitle("m_{H} (GeV)");
 grScanMuMH->GetYaxis()->SetTitle("#sigma/#sigma_{SM}");
 ccScan2->SaveAs ("ccScan2.png");
 ccScan2->SaveAs ("ccScan2.pdf");
 
 
 TCanvas* ccScan = new TCanvas ("ccScan","ccScan",600,600);
 grScanMuMH -> Draw ("colz");
//  grScanMuMH -> Draw ("cont3");
 grScanMuMH->GetXaxis()->SetTitle("m_{H} (GeV)");
 grScanMuMH->GetYaxis()->SetTitle("#sigma/#sigma_{SM}");
 grScanMuMH->GetZaxis()->SetTitle("-2 #Delta ln L");
 grScanMuMH->GetZaxis()->SetRangeUser(0,20);
 gPad -> SetRightMargin(0.15);
 ccScan->SaveAs ("ccScan.png");
 ccScan->SaveAs ("ccScan.pdf");

 ccScan -> SetLogz();
 ccScan->SaveAs ("ccScan_logz.png");
 ccScan->SaveAs ("ccScan_logz.pdf");
  //  TList* contour = grScanMuMH->GetContourList(4);
//  TGraph* idcur = new TGraph();
//  while (idcur) {
//   idcur = (TGraph*) contour->After(idcur);
//   idcur -> Draw ("L");
//  }

 
 
 if (doGraph) {
  TCanvas* ccM[200];
  TGraph*  grM[200];
  for (int iMass = 0; iMass < nMass; iMass++) {
   name = Form ("cc%d",int(MH[iMass]));
   ccM[iMass] = new TCanvas (name,name,400,400);
   grM[iMass] = new TGraph ();
   int iPoint = 0;
   for(std::map <float, float>::iterator iterator = LLmap[iMass].begin(); iterator != LLmap[iMass].end(); iterator++) {
    grM[iMass]->SetPoint (iPoint, iterator->first,iterator->second);
    iPoint++;
   }
   grM[iMass] -> SetMarkerSize(1);
   grM[iMass] -> SetMarkerStyle(20);
   grM[iMass] -> Draw ("AP");
   grM[iMass] -> GetXaxis()->SetTitle("#mu");
   grM[iMass] -> GetYaxis()->SetTitle("-2#DeltaLL");
   
   name = Form ("cc%d.png",int(MH[iMass]));
   ccM[iMass] -> SaveAs(name);
   name = Form ("cc%d.pdf",int(MH[iMass]));
   ccM[iMass] -> SaveAs(name);
  }
 }
}




