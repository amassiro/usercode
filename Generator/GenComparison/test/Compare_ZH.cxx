{
 // root -l -q -b Compare.cxx

  #include "plotUtils.C"

 //  LatinoStyle2();
 
 TGaxis::SetMaxDigits(3);
 //  gStyle->SetNdivisions(100);
 gStyle->SetOptTitle(0);
 
 //----------------------------------------------------------------------------
 // Pad
 //----------------------------------------------------------------------------

 gStyle->SetOptStat       (   0);
 gStyle->SetStatBorderSize(   0);
 gStyle->SetStatColor     (  10);
 gStyle->SetStatFont      (  42);
 gStyle->SetStatX         (0.94);
 gStyle->SetStatY         (0.91);
 gStyle -> cd(); 

 std::string FolderImages = "images_MINLO_HERWIGpp_Pythia_ZH";

 std::vector < std::string > vFile;
 std::vector < std::string > vNameSample;
 std::vector < int > vColorSample;
 std::vector < std::string > vSampleWeight;

//  std::vector < TCanvas > vCanvas;
 std::vector < std::string > vCuts;
 std::vector < std::string > vVariable;
 std::vector < std::string > vVariableHR; //---- for the image
 std::vector < int > vVariable_bin;
 std::vector < double > vVariable_min;
 std::vector < double > vVariable_max;


 vFile.push_back("ZH_Herwig.root");
 vFile.push_back("ZH_Minlo.root");
 vFile.push_back("ZH_Pythia.root");
//  vFile.push_back("WH_Herwig_WH_HZZ_Winclusive.root");
//  vFile.push_back("WH_Herwig_WH_HZZ_WMuNu.root");
//  vFile.push_back("WH_Herwig_WH_HZZ_WMuNu_minjetkt1.root");


 vNameSample.push_back("herwig++");
 vNameSample.push_back("minlo");
 vNameSample.push_back("pythia");
//  vNameSample.push_back("herwig++ W inclusive");
//  vNameSample.push_back("herwig++ Wmunu");
//  vNameSample.push_back("herwig++ Wmunu minjetkt=1");

 vColorSample.push_back(2);
 vColorSample.push_back(4);
 vColorSample.push_back(3);
//  vColorSample.push_back(5);
//  vColorSample.push_back(6);
//  vColorSample.push_back(7);


 vSampleWeight.push_back("baseW");
 vSampleWeight.push_back("baseW");
 vSampleWeight.push_back("baseW");
//  vSampleWeight.push_back("baseW*(Vdecay==2)");
//  vSampleWeight.push_back("baseW");
//  vSampleWeight.push_back("baseW");
//  vSampleWeight.push_back("baseW");

 vCuts.push_back ("1");
 vCuts.push_back ("njet30>=1");
//  vCuts.push_back ("Vdecay==-2"); // ----  Z > mu,mu

 vVariableHR.push_back("HiggsPt");
 vVariable.push_back("HiggsPt");
 vVariable_min.push_back(0);
 vVariable_max.push_back(200);
 vVariable_bin.push_back(20);

 vVariableHR.push_back("HiggsEta");
 vVariable.push_back("HiggsEta");
 vVariable_min.push_back(-5);
 vVariable_max.push_back(5);
 vVariable_bin.push_back(20);

 vVariableHR.push_back("jetpt1");
 vVariable.push_back("jetpt1");
 vVariable_min.push_back(0);
 vVariable_max.push_back(200);
 vVariable_bin.push_back(20);

 vVariableHR.push_back("jeteta1");
 vVariable.push_back("jeteta1");
 vVariable_min.push_back(-5);
 vVariable_max.push_back(5);
 vVariable_bin.push_back(20);

 vVariableHR.push_back("ptV");
 vVariable.push_back("ptV");
 vVariable_min.push_back(0);
 vVariable_max.push_back(200);
 vVariable_bin.push_back(20);

 vVariableHR.push_back("njet20");
 vVariable.push_back("njet20");
 vVariable_min.push_back(0);
 vVariable_max.push_back(10);
 vVariable_bin.push_back(10);

 vVariableHR.push_back("njet30");
 vVariable.push_back("njet30");
 vVariable_min.push_back(0);
 vVariable_max.push_back(10);
 vVariable_bin.push_back(10);

 vVariableHR.push_back("Vdecay");
 vVariable.push_back("Vdecay");
 vVariable_min.push_back(-40);
 vVariable_max.push_back(10);
 vVariable_bin.push_back(100);

 TFile *temp = new TFile ("temp.root","RECREATE");
 temp->cd();
 
 TLegend* leg = new TLegend(0.6,0.6,0.88,0.9);
 //  leg->SetFillColor(kWhite);
 leg->SetFillStyle(0);
 
 TTree* tree[100];
 
 
 for (int iFile = 0; iFile < vFile.size(); iFile++) {
  ///---- get the access to the trees ----
  TFile * file = TFile::Open(vFile.at(iFile).c_str() );
  TTree* tree[iFile] = (TTree*) file -> Get ("demo/myTree"); 
 }
 
 
 
 ofstream myfile;
 TString nameCuts = Form("%s/cuts.txt",FolderImages.c_str());
 myfile.open (nameCuts.Data());
 myfile << "Cuts definition:" << std::endl;
 for (int iCut = 0; iCut < vCuts.size(); iCut++) {
  myfile << iCut << " :: " << vCuts.at(iCut) << std::endl;
 }
 myfile.close(); 
 
 
 
 for (int iCut = 0; iCut < vCuts.size(); iCut++) {
  for (int iVar = 0; iVar < vVariable.size(); iVar++) {
//    TString nameCanvas = Form ("%d_%s",iCut,vVariableHR.at(iVar).c_str());
//    TCanvas* cc     = new TCanvas (nameCanvas.Data(),nameCanvas.Data(),500,500);
//    cc -> Divide (1,2);

//    TString nameCanvasRight = Form ("Right_%d_%s",iCut,vVariableHR.at(iVar).c_str());
//    TCanvas* ccRight = new TCanvas (nameCanvasRight.Data(),nameCanvasRight.Data(),700,700);
   
   TString nameCanvasNorm = Form ("norm_%d_%s",iCut,vVariableHR.at(iVar).c_str());
   TCanvas* ccNorm = new TCanvas (nameCanvasNorm.Data(),nameCanvasNorm.Data(),500,500);
   ccNorm -> Divide (1,2);
   
   TH1F* h[100];
   TH1F* hRight[100];
   TH1F* hNorm[100];
   for (int iFile = 0; iFile < vFile.size(); iFile++) {
    ///---- plot ----
    TString nameHisto   = Form ("%d_%s_%d",iCut,vVariableHR.at(iVar).c_str(),iFile);
    TString nameHistoHR = Form ("%s",vNameSample.at(iFile).c_str());
    temp->cd();
    h[iFile] = new TH1F (nameHisto.Data(),nameHistoHR.Data(),vVariable_bin.at(iVar), vVariable_min.at(iVar), vVariable_max.at(iVar));
    h[iFile] -> Sumw2();
    
    TString toDraw = Form ("%s >> %s",vVariable.at(iVar).c_str(), nameHisto.Data());
    TString toCut  = Form ("%s * (%s)",vSampleWeight.at(iFile).c_str(), vCuts.at(iCut).c_str());
    
    tree[iFile] -> Draw (toDraw.Data(), toCut.Data(), "goff");
    std::cout << " entries[" << vNameSample.at(iFile) << "]= " << tree[iFile] -> GetEntries (toCut.Data()) << std::endl;
    std::cout << " toDraw = " << toDraw.Data() << std::endl;
    std::cout << " toCut  = " << toCut.Data()  << std::endl;
    
    h[iFile]->SetLineWidth(2);
    h[iFile]->SetLineColor(vColorSample.at(iFile));
    //     h[iFile]->SetLineStyle(iFile+1);
    
    
    
//     ccRight->cd();
//     hRight[iFile] = IntegralRight(h[iFile]);
//     if (iFile == 0) {
//      hRight[iFile]-> GetYaxis() -> SetRangeUser ( 0.1, 1.5 * (hRight[iFile]->GetMaximum()) );
//      hRight[iFile]-> GetXaxis() -> SetTitle ( vVariable.at(iVar).c_str() );
//      hRight[iFile]->DrawClone("Ehisto");
//     }
//     else {
//      hRight[iFile]->DrawClone("Ehistosame");     
//     }
    
    
//     cc->cd(1);        
//     if (iFile == 0) {
//      h[iFile]-> GetYaxis() -> SetRangeUser ( 0.001, 3.5 * (h[iFile]->GetMaximum()) );
//      h[iFile]-> GetXaxis() -> SetTitle ( vVariable.at(iVar).c_str() );
//      h[iFile]->DrawClone("Ehisto");
//     }
//     else {
//      h[iFile]->DrawClone("Ehistosame");
//      cc->cd(2);
//      TH1F* hPull = PullPlotAsRatio (h[iFile], h[0], 0.5, 1.5);
//      TString axisName = Form ("XXX / %s", vNameSample.at(0).c_str() );
//      hPull->GetYaxis()-> SetTitle (axisName.Data());
//      hPull->SetLineColor(vColorSample.at(iFile));
//      hPull->SetMarkerColor(vColorSample.at(iFile));
//      if (iFile == 1) {
//       hPull->DrawClone();
//      }
//      else {
//       hPull->DrawClone("same");
//      }
//     }
    
    
    ccNorm->cd(1);
    double int_h = h[iFile]->Integral(0,h[iFile]->GetNbinsX()+1); //---- also overflow!
    hNorm[iFile] = (TH1F*) h[iFile] -> Clone();
    hNorm[iFile] -> Scale (1. / int_h);
    if (iFile == 0) {
     hNorm[iFile]-> GetXaxis() -> SetTitle ( vVariable.at(iVar).c_str() );
     hNorm[iFile]-> GetYaxis() -> SetRangeUser ( 0.001, 3.5 * (hNorm[iFile]->GetMaximum()) );
     hNorm[iFile]->DrawClone("Ehisto");
    }
    else {
     hNorm[iFile]->DrawClone("Ehistosame");
     ccNorm->cd(2);
     TH1F* hPull = PullPlotAsRatio (hNorm[iFile], hNorm[0], 0.5, 1.5);
     TString axisName = Form ("XXX / %s", vNameSample.at(0).c_str() );
     hPull->GetYaxis()-> SetTitle (axisName.Data());
     hPull->SetLineColor(vColorSample.at(iFile));
     hPull->SetMarkerColor(vColorSample.at(iFile));
     if (iFile == 1) {
      hPull->DrawClone();
     }
     else {
      hPull->DrawClone("same");
     }
    }
    
    if (iVar==0 && iCut==0) {
     leg->AddEntry(h[iFile],h[iFile]->GetTitle(),"l");
    }
    
    
    
   }
   
   //   cc -> SetBottomMargin(0.2);
   //   cc -> SetLeftMargin  (0.10);
   //   cc -> SetRightMargin (0.10);
   //   cc -> SetGrid();
   
//    cc->cd(1);
//    gPad->SetGrid();
//    leg->Draw();
//    cc->cd(2);
//    gPad->SetGrid();
   
   
   //   ccNorm -> SetBottomMargin(0.2);
   //   ccNorm -> SetLeftMargin  (0.10);
   //   ccNorm -> SetRightMargin (0.10);
   //   ccNorm -> SetGrid();
   ccNorm->cd(1);
   gPad->SetGrid();
   leg->Draw();
   ccNorm->cd(2);
   gPad->SetGrid();
   
   
//    TString nameImage = Form("%s/%s.pdf",FolderImages.c_str(),nameCanvas.Data());
//    cc     -> SaveAs(nameImage.Data());
   TString nameImageNorm = Form("%s/%s.pdf",FolderImages.c_str(),nameCanvasNorm.Data());
   ccNorm -> SaveAs(nameImageNorm.Data());
   nameImageNorm = Form("%s/%s.png",FolderImages.c_str(),nameCanvasNorm.Data());
   ccNorm -> SaveAs(nameImageNorm.Data());
   
   
//    cc->cd(1);
//    gPad->SetLogy();
//    nameImage = Form("%s/%s_log.pdf",FolderImages.c_str(),nameCanvas.Data());
//    cc     -> SaveAs(nameImage.Data());
   
   ccNorm->cd(1);
   gPad->SetLogy();
   nameImageNorm = Form("%s/%s_log.pdf",FolderImages.c_str(),nameCanvasNorm.Data());
   ccNorm->SaveAs(nameImageNorm.Data());
   nameImageNorm = Form("%s/%s_log.png",FolderImages.c_str(),nameCanvasNorm.Data());
   ccNorm->SaveAs(nameImageNorm.Data());
   
   
   
//    ccRight -> cd();
//    gPad->SetGrid();
//    nameImage = Form("%s/%s_right.pdf",FolderImages.c_str(),nameCanvas.Data());
//    ccRight -> SaveAs(nameImage.Data());
// 
//    ccRight -> cd();
//    gPad->SetLogy();
//    nameImage = Form("%s/%s_right_log.pdf",FolderImages.c_str(),nameCanvas.Data());
//    ccRight -> SaveAs(nameImage.Data());
   
   
  } 
  
  //   vCanvas.push_back(*cc);
 }
 
}
