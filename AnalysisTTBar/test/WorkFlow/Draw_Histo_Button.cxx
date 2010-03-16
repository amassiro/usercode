{
 
 #include "Functions.hh"
 
 gROOT->ProcessLine(".x ./test/Style.cxx") ;
 
 TTree *treeEffVect[100];
 
 char *nameSample[1000];
 
 char name[1000];
 sprintf(name,"test/WorkFlow/FilesOut.txt"); 
 std::ifstream inFile(name);
 std::string buffer;
 if(!inFile.is_open())
 {
  std::cerr << "** ERROR: Can't open '" << inputFileList << "' for input" << std::endl;
  return false;
 }
 
 int totalSamples = 0;
 
 TH1F *histos[10000];
 
 int counterHisto = 0;
 int counterHistoPerFile = 0;
 TKey *key; 
 
 std::string kind = "TH1F";
 int NORMXSECT = 1;
 int REBIN = 1;

 
 
 
 
 while(1)
 {
  inFile >> buffer;
  if(!inFile.good()) break;
  
  counterHistoPerFile = 0;  
  nameSample[totalSamples] = new char [1000];
  sprintf(nameSample[totalSamples],"%s",buffer.c_str());
  char nameFile[1000];
  sprintf(nameFile,"output/out_TT_WorkFlowDrawer_Efficiency_%s.root",buffer.c_str());  
  TFile* f = new TFile(nameFile, "READ");
  treeEffVect[totalSamples] = (TTree) f->Get("outTreeSelections");
  char nameTreeEff[100];
  sprintf(nameTreeEff,"treeEff_%d",totalSamples); 
  treeEffVect[totalSamples].SetName(nameTreeEff);  
  
  TIter next(f->GetListOfKeys());
  while ((key = (TKey *) next())) {
   TString nameHistoFile = key->GetName();  
   TObject* temp = f->Get(nameHistoFile);
   std::string temp_name = (temp->ClassName());
   if (temp_name == kind) {   
    std::cerr << "class = " << temp->ClassName() << std::endl << "  ";
    std::cerr << counterHisto << ") " << nameHistoFile.Data() << std::endl;
    histos[counterHisto] = (TH1F) f->Get(nameHistoFile);
    TString nameHistoFile_After = Form("%s_%s",nameHistoFile.Data(),nameSample[totalSamples]);
    histos[counterHisto].SetName(nameHistoFile_After);
    histos[counterHisto].SetTitle(nameHistoFile_After);
    counterHisto++;
    counterHistoPerFile++;
   }
  }
  totalSamples++;
 }
 
 
 
 std::cout << " totalSamples = " << totalSamples << std::endl;
 std::cout << " counterHistoPerFile = " << counterHistoPerFile << std::endl;
 
 THStack* hs[1000];
 for (int iHisto=0; iHisto<counterHistoPerFile; iHisto++){
  char nameStack[100];
  sprintf(nameStack,"stack_%d",iHisto); 
  hs[iHisto] = new THStack(nameStack,nameStack);
 }
 
 TCanvas cHisto("cHisto","cHisto",800,600);
 cHisto.Divide(sqrt(counterHistoPerFile)+1,sqrt(counterHistoPerFile)+1);
 
 //  for (int iSample=(totalSamples-1); iSample>=0; iSample--){
  for (int iSample=0; iSample<totalSamples; iSample++){
   char nameHisto[100];
   sprintf(nameHisto,"histo_%d",iSample); 
   
   for (int iHisto=0; iHisto<counterHistoPerFile; iHisto++){
    //    cHisto.cd(iHisto+1);
    //    std::cout << " counterHistoPerFile * (iSample) + iHisto = " << counterHistoPerFile * (iSample) + iHisto << std::endl;
    double XSection;
    double preselection_efficiency;
    int numEntriesBefore;
    treeEffVect[iSample].SetBranchAddress("XSection",&XSection);
    treeEffVect[iSample].SetBranchAddress("preselection_efficiency",&preselection_efficiency);
    treeEffVect[iSample].SetBranchAddress("numEntriesBefore",&numEntriesBefore);
    treeEffVect[iSample].GetEntry(0);
    
    std::cout << "*** " << iHisto << ") " << nameSample[iSample] << " effTot = " <<  XSection * preselection_efficiency / numEntriesBefore * histos[counterHistoPerFile * (iSample) + iHisto].GetEntries() << " events / pb-1      <<<< " << histos[counterHistoPerFile * (iSample) + iHisto].GetEntries() << " = histo entries ";
    std::cout << "### " << " effTot = " <<  preselection_efficiency / numEntriesBefore * histos[counterHistoPerFile * (iSample) + iHisto].GetEntries() << " <<<< " << std::endl;
    
    if (NORMXSECT) histos[counterHistoPerFile * (iSample) + iHisto].Scale(XSection * preselection_efficiency / numEntriesBefore);
    else histos[counterHistoPerFile * (iSample) + iHisto].Scale(1. / histos[counterHistoPerFile * (iSample) + iHisto].GetEntries());
    
    
    histos[counterHistoPerFile * (iSample) + iHisto].Rebin(REBIN);
    
    if (iSample == 0){
     histos[counterHistoPerFile * (iSample) + iHisto].SetMarkerColor(kRed);
     histos[counterHistoPerFile * (iSample) + iHisto].SetLineColor(kRed);
     histos[counterHistoPerFile * (iSample) + iHisto].SetFillColor(kRed);
     histos[counterHistoPerFile * (iSample) + iHisto].SetLineWidth(4);
     if (NORMXSECT) histos[counterHistoPerFile * (iSample) + iHisto].SetFillStyle(3001);
     else histos[counterHistoPerFile * (iSample) + iHisto].SetFillStyle(0);
    }
    else if (iSample == 1){
     histos[counterHistoPerFile * (iSample) + iHisto].SetMarkerColor(kBlue);
     histos[counterHistoPerFile * (iSample) + iHisto].SetLineColor(kBlue);
     histos[counterHistoPerFile * (iSample) + iHisto].SetFillColor(kBlue);
     histos[counterHistoPerFile * (iSample) + iHisto].SetLineWidth(4);
     if (NORMXSECT) histos[counterHistoPerFile * (iSample) + iHisto].SetFillStyle(3001);
     else histos[counterHistoPerFile * (iSample) + iHisto].SetFillStyle(0);
    }
    else {
     histos[counterHistoPerFile * (iSample) + iHisto].SetMarkerColor(kOrange - 5 + iSample * 3);
     histos[counterHistoPerFile * (iSample) + iHisto].SetLineColor(kOrange - 5 + iSample * 3);
     histos[counterHistoPerFile * (iSample) + iHisto].SetFillColor(kOrange - 5 + iSample * 3);
     histos[counterHistoPerFile * (iSample) + iHisto].SetLineWidth(1);
     if (NORMXSECT) histos[counterHistoPerFile * (iSample) + iHisto].SetFillStyle(3001);
     else histos[counterHistoPerFile * (iSample) + iHisto].SetFillStyle(0);
    }
    
    if (iSample==0) {
     hs[iHisto].Add(histos[counterHistoPerFile * (iSample) + iHisto]);
     //     histos[counterHistoPerFile * (iSample) + iHisto].Draw();
     //     histos[counterHistoPerFile * (iSample) + iHisto].GetXaxis()->SetTitle(histos[counterHistoPerFile * (iSample) + iHisto].GetName());
    }
    else {
     hs[iHisto].Add(histos[counterHistoPerFile * (iSample) + iHisto]);
     //     histos[counterHistoPerFile * (iSample) + iHisto].Draw("same");
    }
    //    std::cerr << " name = " << histos[counterHistoPerFile * (iSample) + iHisto].GetName() << std::endl;
    gPad->SetGrid();
    //    if (iSample==(totalSamples-1)) gPad->BuildLegend();
   }
  }
  
  
  
  
  
  
  std::vector< std::string > vect_name;
  TControlBar *bar = new TControlBar("vertical", "fit control panel");
  gROOT->Add(bar);
  for (int iHisto=0; iHisto<counterHistoPerFile; iHisto++){
   std::string name_histo = histos[iHisto]->GetName();
   std::string name_kind = name_histo.substr(4);
   int found = 0;
   for (int i=0; i<vect_name.size(); i++){
    if (vect_name.at(i) == name_kind) {
     found = 1;
    }
   }
   if (found == 0) {
    vect_name.push_back(name_kind);
    std::cerr << "name_kind = " << name_kind << std::endl;
    TString CommandToROOT = Form("bar->AddButton(\"%s\",\"{Add(%d);}\",\"Add Histos\");\n",name_kind,vect_name.size()-1);
    gROOT->ProcessLine(CommandToROOT);
   }
  }
  bar->AddButton("Exit","{Exit();}","Exit from the program");
  bar->Show();
  
  
  
/*  if (!gROOT->FindObject("draw control panel")) { 
   TControlBar *bar = new TControlBar("vertical", "fit control panel");
   gROOT->Add(bar);
   for (int iHisto=0; iHisto<counterHistoPerFile; iHisto++){
    TString CommandToROOT = Form("bar->AddButton(\"%s\",\"{Draw(%d);}\",\"disegna\");\n",histos[iHisto].GetName(),iHisto);
    gROOT->ProcessLine(CommandToROOT);
   }
   bar->AddButton("Exit","{Exit();}","Exit from the program");
   bar->Show();
  }*/
  
 
  
  std::cerr << " ******************************************* end *******************************************" << std::endl;
  
  
 }
 
 
 