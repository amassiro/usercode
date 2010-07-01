void Correlation( TString nameSampleIN = "",TCut extCut = "" ){
 
 std::cerr << " extCut = " << extCut.Print() << std::endl;
 TCut totalCut = extCut;
 
 
 
 double pT_RECO_q1;
 double pT_RECO_q2;
 double eta_RECO_q1;
 double eta_RECO_q2;
 double eta_RECO_q1_eta_RECO_q2;
 double Deta_RECO_q12;
 double Mjj;
 int JV_20;
 int JV_30;
 int CJV_20;
 int CJV_30;
 int AnalysisStep; 
 double MLP_Jet;
 double BDT_Jet;
 double Fisher_Jet;
 double Likelihood_Jet;
 double LikelihoodD_Jet;
 
 int pdgId_RECO_l1;
 int pdgId_RECO_l2;
 double pT_RECO_l1;
 double pT_RECO_l2;
 double eta_RECO_l1;
 double eta_RECO_l2;
 double eta_RECO_l1_eta_RECO_l2;
 double Deta_RECO_l12;
 double Dphi_RECO_l12;
 double Mll;
 double charge_RECO_l1_charge_RECO_l2;
 double MLP_Lep;
 double BDT_Lep;
 double Fisher_Lep;
 double Likelihood_Lep;
 double LikelihoodD_Lep;
 
 
 
 int numVariable = 9;
 double Var1;
 double Var2;

 char* NameVar[1000] = {
//   "pT_RECO_q1",
//   "pT_RECO_q2",
//   "phi_RECO_q1",
//   "phi_RECO_q2",
//   "eta_RECO_q1",
//   "eta_RECO_q2",
//   "eta_RECO_q1_eta_RECO_q2",
//   "Deta_RECO_q12",
//   "Mjj",
"min(abs(phi_RECO_q1-phi_RECO_q2),abs(6.283185307179586 - abs(phi_RECO_q1-phi_RECO_q2)))",

  "JV_20",
//   "JV_30",
  "CJV_20",
//   "CJV_30",
//   "AnalysisStep", 
//   "MLP_Jet",
//   "BDT_Jet",
//   "Fisher_Jet",
//   "Likelihood_Jet",
//   "LikelihoodD_Jet", 
//   "pdgId_RECO_l1",
//   "pdgId_RECO_l2",
//   "pT_RECO_l1",
//   "pT_RECO_l2",
//   "eta_RECO_l1",
//   "eta_RECO_l2",
//   "eta_RECO_l1_eta_RECO_l2",
//   "Deta_RECO_l12",
//   "Dphi_RECO_l12",
//   "Mll",
//   "charge_RECO_l1_charge_RECO_l2",
//   "MLP_Lep",
//   "BDT_Lep",
//   "Fisher_Lep",
  "Likelihood_Lep",
  "NBjets_trackCountingHighPurBJetTags",
  "NBjets_trackCountingHighEffBJetTags",
//  "NBjets_combinedSecondaryVertexBJetTags",
 "NBjets_combinedSecondaryVertexMVABJetTags",
//   "Z_01_30",
  "Z_03_30",
//   "Z_05_30",
//   "Z_07_30",
//   "Z_09_30",
  "Z_10_30",
//   "Z_12_30",
//   "Z_14_30",
//   "Z_01_20",
//   "Z_03_20",
//   "Z_05_20",
//   "Z_07_20",
//   "Z_09_20",
//   "Z_10_20",
//   "Z_12_20",
//   "Z_14_20"
  
  
  
  
//   "LikelihoodD_Lep"
 };
 
 
 
 TTree *signal_background[100]; 
 double weights[100];
 
 TTree *treeEffVect[100];
 char *nameSample[1000];
 char *nameSamplePrefix[1000];
 char *nameSampleTree[1000];
 double xsection[1000];
 std::ifstream inFile("/home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/test/Spring10/samples.txt");
 std::string buffer;
 
 int totalSamples = 0;
 int iSample = -1;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  //   std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   //    std::cout << "buffer.at(0) = " << buffer.at(0) << std::endl;
   if (buffer.at(0) != '#'){ ///--------------------------------------- NON FUNZIONA!!!
    std::stringstream line( buffer );       
    nameSample[totalSamples] = new char [1000];
    line >> nameSample[totalSamples]; 
    std::cout << nameSample[totalSamples] << " ";
    
    std::string nameStr = nameSample[totalSamples];
    if (nameSampleIN.Data() == nameStr){
     std::cerr << " >>> found sample ..." << std::endl;
     iSample = totalSamples;
    }
     
    
    nameSamplePrefix[totalSamples] = new char [1000];
    line >> nameSamplePrefix[totalSamples];
    
    nameSampleTree[totalSamples] = new char [1000];
    line >> nameSampleTree[totalSamples];
    
    line >> xsection[totalSamples]; 
    std::cout << xsection[totalSamples] << " ";
    
    char nameFile[1000];
    sprintf(nameFile,"/home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/output_Spring10/out_FinalSelection_%s.root",nameSample[totalSamples]);  
    TFile* f = new TFile(nameFile, "READ");
    
    treeEffVect[totalSamples] = (TTree) f->Get("outTreeSelections");
    char nameTreeEff[100];
    sprintf(nameTreeEff,"treeEff_%d",totalSamples); 
    treeEffVect[totalSamples]->SetName(nameTreeEff);      
    
    double XSection;
    double eff_Channel_Filter;
    double preselection_efficiency;
    int numEntriesBefore;
    treeEffVect[totalSamples]->SetBranchAddress("XSection",&XSection);
    treeEffVect[totalSamples]->SetBranchAddress("preselection_efficiency",&preselection_efficiency);
    treeEffVect[totalSamples]->SetBranchAddress("numEntriesBefore",&numEntriesBefore);
    treeEffVect[totalSamples]->GetEntry(0);
    
    ///**********************************************************************
    weights[totalSamples] = XSection * preselection_efficiency / numEntriesBefore;
    signal_background[totalSamples] = (TTree) f->Get("outTreeJetLep");
    ///**********************************************************************
    std::cout << std::endl;
    totalSamples++;
   } 
  }
 }
 
 
 
 
 
 if (iSample == -1) {
  std::cerr << "something went wrong ... " << std::endl;
  exit(0);
 }


double* Correlation = new double ((numVariable)*(numVariable-1));
std::cerr << "num of pairs = " << (numVariable)*(numVariable-1) << std::endl;
 
 TCanvas* cc = new TCanvas("cc","cc",800,800);
 cc->Divide(numVariable,numVariable);
 
 signal_background[iSample]->SetLineColor(kRed);
 signal_background[iSample]->SetMarkerColor(kRed);
 signal_background[iSample]->SetMarkerStyle(20);
 signal_background[iSample]->SetMarkerSize(0.1);
 
 gStyle->SetPaintTextFormat("5.2f");
 TH2F* h2Corr = new TH2F("h2Corr","h2Corr",numVariable,0,numVariable,numVariable,0,numVariable);
 
 for (int iVar = 0; iVar < numVariable; iVar++){
  h2Corr->GetXaxis()->SetBinLabel(iVar+1,NameVar[iVar]);
  h2Corr->GetYaxis()->SetBinLabel(iVar+1,NameVar[iVar]);
  h2Corr->SetBinContent(iVar+1,iVar+1,1.);
  for (int jVar = iVar+1; jVar < numVariable; jVar++){
   cc->cd(1 + numVariable*(numVariable-1) - (iVar)*(numVariable) + jVar);
//    cc->cd(iVar*(numVariable-1) + jVar)-
   char toDraw[1000];
   sprintf(toDraw,"%s:%s",NameVar[iVar],NameVar[jVar]);
   char toCut[1000];
   sprintf(toCut,"");
   totalCut = extCut + toCut;
//    std::cerr << " signal_background[iSample] = " << signal_background[iSample]->GetEntries() << std::endl;
   signal_background[iSample]->Draw(toDraw,totalCut,"colz");
   gPad->SetGrid();
   TH2F *htemp = (TH2F*)gPad->GetPrimitive("htemp"); // empty, but has axes
   htemp->Draw("colz");
   h2Corr->SetBinContent(iVar+1,jVar+1,htemp->GetCorrelationFactor());
   h2Corr->SetBinContent(jVar+1,iVar+1,htemp->GetCorrelationFactor());
   std::cerr << "Correlation[" << NameVar[iVar] << "][" << NameVar[jVar] << "] = " << htemp->GetCorrelationFactor() << std::endl;
//    Correlation[iVar*(numVariable-1) + jVar] = graph->GetCorrelationFactor();
  }
 } 
 
 
 TCanvas* ccCorr = new TCanvas("ccCorr","ccCorr",800,800);
 h2Corr->Draw("colz");
 h2Corr->Draw("textSAME");
 
 
}