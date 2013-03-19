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
#include "test/Latinos12/ttbar/plotUtils.C"

#include <iomanip>


///---- transform a std::vector of string into a string with proper (*) &&
std::string Compact(std::vector <std::string> vCut) {
 std::string totalString;
 for (int iCut=0; iCut<vCut.size(); iCut++) {
  totalString.append ( " ( " );
  totalString.append ( vCut.at(iCut) );
  totalString.append ( " ) " );
  if (iCut != (vCut.size()-1)) {
   totalString.append ( " && " );
  }
 }  
 return totalString;
}



///---- clear map -> set to 0
void Clear(std::vector <std::vector <double> > & vNumbers) {
 int nZone = vNumbers.size();
 for (int iZone=0; iZone<nZone; iZone++) {
  int nBin = (vNumbers.at(iZone)).size();
  for (int iBin=0; iBin<nBin; iBin++) {
   (vNumbers.at(iZone)).at(iBin) = 0;
  }
 }
}


///---- error on ratio
double ErrorRatio (double num, double errnum, double den, double errden) {
 double result = 0;
 if (den != 0) {
  double tempnum = errnum / den;
  double tempden = errden * num / den / den;
  result = sqrt ( (tempnum * tempnum) + (tempden * tempden) );
 }
 return result;
}


///---- less than "string" creator
std::string LessThan (std::string variable, double value) {
 std::string result;
 std::ostringstream cutDefinition;
 cutDefinition << variable;
 cutDefinition << "<";
 cutDefinition << value;
 result = cutDefinition.str();
 return result;
}

///---- more than "string" creator
std::string MoreThan (std::string variable, double value) {
 std::string result;
 std::ostringstream cutDefinition;
 cutDefinition << variable;
 cutDefinition << ">";
 cutDefinition << value;
 result = cutDefinition.str();
 return result;
}

int GetTop_Macro_forDataCard(int iWP, std::string suffix = "of") {
 
 std::cout << std::endl;
 std::cout << " ============== " << std::endl;
 std::cout << " Top datadriven " << std::endl;
 std::cout << " ============== " << std::endl;
 std::cout << std::endl;
 
 int _debug = 0;
 //  int _debug = 1;
 //---- 0 = no debug
 
 std::string inputDirectory = "output_Latinos_tree_2012_2jet_Top";
 std::string fileSamples = "test/Latinos12/ttbar/datacard/SamplesH.txt";
 
 std::string treeName = "latino";
 std::string inputBeginningFile = "latino_";
 
 double LUMI = 19602.;
 
 
 std::vector <std::string> v_commonCut_WW; 
 
 v_commonCut_WW.push_back("pt1>20");
 v_commonCut_WW.push_back("pt2>10");
 v_commonCut_WW.push_back("(ch1*ch2)<0");
 
 v_commonCut_WW.push_back("trigger==1.");
 v_commonCut_WW.push_back("pfmet>20.");
 v_commonCut_WW.push_back("mll>12");
 v_commonCut_WW.push_back("(zveto==1||!sameflav)");
 v_commonCut_WW.push_back("mpmet>20.");
 v_commonCut_WW.push_back("bveto_mu==1");
 v_commonCut_WW.push_back("nextra==0");
//  v_commonCut_WW.push_back("(bveto_ip==1 && nbjettche==0)");
 v_commonCut_WW.push_back("bveto_ip==1");
 v_commonCut_WW.push_back("ptll>45");
 
 v_commonCut_WW.push_back("( !sameflav || ( (njet!=0 || dymva1>0.88) && (njet!=1 || dymva1>0.84) && ( njet==0 || njet==1 || (pfmet > 45.0)) ) )");
 v_commonCut_WW.push_back("(njet==0 || njet==1 || (dphilljetjet<pi/180.*165. || !sameflav )  )");

 //---- 2 or 3 jets 
 v_commonCut_WW.push_back("(njet >= 2 && njet <= 3 && (jetpt3 <= 30 || !(jetpt3 > 30 && (  (jeteta1-jeteta3 > 0 && jeteta2-jeteta3 < 0) || (jeteta2-jeteta3 > 0 && jeteta1-jeteta3 < 0))))) ");
 
 std::string commonCut_WW = Compact(v_commonCut_WW);
 
 std::string TopEnrichedCut_WW = "(!sameflav)";
 
 
 
 std::vector <std::string> v_commonCut_Higgs; 

 v_commonCut_Higgs.push_back(commonCut_WW); 
 
 //---- VBF cut based ---- 
 double            mH[100]  =     {110  ,115  , 120 , 125 , 130 , 135 , 140 , 145 , 150 , 155 , 160 , 170 , 180 , 190 , 200 , 250 , 300 , 350 , 400 , 450 , 500 , 550 , 600 };
 
 double cutmap_pt1min[100]  = { 20  , 20  , 20  , 23  , 25  , 25  , 25  , 25  , 27  , 27  , 30  , 34  , 36  , 38  , 40  , 55  , 70  , 80  , 90  , 110 , 120 , 130 , 140 };
 double cutmap_pt2min[100]  = { 10  , 10  , 10  , 10  , 10  , 12  , 15  , 15  , 25  , 25  , 25  , 25  , 25  , 25  , 25  , 25  , 25  , 25  , 25  , 25  , 25  , 25  , 25  };
 double cutmap_mllmax[100]  = { 40  , 40  , 40  , 43  , 45  , 45  , 45  , 45  , 50  , 50  , 50  , 50  , 60  , 80  , 90  , 150 , 200 , 250 , 300 , 350 , 400 , 450 , 500 };
 double cutmap_dphimax[100] = { 115 , 115 , 115 , 100 , 90  , 90  , 90  , 90  , 90  , 90  , 60  , 60  , 70  , 90  , 100 , 140 , 175 , 175 , 175 , 175 , 175 , 175 , 175 };
 
 double cutmap_mtmax[100]   = { 110 , 110 , 120 , 123 , 125 , 128 , 130 , 140 , 150 , 155 , 160 , 170 , 180 , 190 , 200 , 250 , 300 , 350 , 400 , 450 , 500 , 550 , 600 };
 
 
 //---- select different flavour or same flavour
 if (suffix == "of") {
  v_commonCut_Higgs.push_back("!sameflav");
 }
 if (suffix == "sf") {
  v_commonCut_Higgs.push_back("sameflav");
 } 
 
 
 
 v_commonCut_Higgs.push_back("abs(eta1 - (jeteta1+jeteta2)/2)/detajj < 0.5");
 v_commonCut_Higgs.push_back("abs(eta2 - (jeteta1+jeteta2)/2)/detajj < 0.5");
 
 v_commonCut_Higgs.push_back("detajj>3.5");
 v_commonCut_Higgs.push_back("mjj>500");
 
 
 v_commonCut_Higgs.push_back(LessThan("mll",cutmap_mllmax[iWP]));
 v_commonCut_Higgs.push_back(MoreThan("pt1",cutmap_pt1min[iWP]));
 v_commonCut_Higgs.push_back(MoreThan("pt2",cutmap_pt2min[iWP]));
 v_commonCut_Higgs.push_back(LessThan("dphill",cutmap_dphimax[iWP]));
 
 v_commonCut_Higgs.push_back(MoreThan("mth",30));
 v_commonCut_Higgs.push_back(LessThan("mth",cutmap_mtmax[iWP]));
 
 std::string commonCut_Higgs = Compact(v_commonCut_Higgs);

 
 std::vector < std::string > vnameSample;
 char *nameSample[300];
 char *nameHumanReadable[300];
 char* xsectionName[300];
 
 int numberOfSamples = ReadFile(fileSamples.c_str(), nameSample, nameHumanReadable, xsectionName); 
 int nSample = numberOfSamples;
 
 char NameNormalization[300][300];
 for (int iSample=0; iSample<nSample; iSample++) {    
  vnameSample.push_back(nameHumanReadable[iSample]);
  
  if (vnameSample.at(vnameSample.size()-1) != "DATA") {
   sprintf (NameNormalization[iSample], "(%s) *  %f / 1000. ", xsectionName[iSample], LUMI);
  }
  else {
   sprintf (NameNormalization[iSample], "1");
  }
 }
 
 std::vector <double> etaBins;
 etaBins.push_back (0.0);
 etaBins.push_back (0.5);
 etaBins.push_back (1.0);
 etaBins.push_back (1.5);
 //  etaBins.push_back (2.0);
 etaBins.push_back (2.5);
 etaBins.push_back (300.0);
 int nBin = etaBins.size() - 1 ;
 int nBin_MAX = nBin-1 ; //---- last bin has eta>2.5 --> always bvetoed? --> check!!
 std::vector <std::string> binCut; 
 
 for (int iBin=0; iBin<nBin; iBin++) {
  std::ostringstream binDefinition;
  binDefinition << " ( ";
  binDefinition << "((abs(jeteta1)<abs(jeteta2))*abs(jeteta1)+((abs(jeteta1)>=abs(jeteta2))*abs(jeteta2))) > " << etaBins.at(iBin);
  binDefinition << " && ";
  binDefinition << "((abs(jeteta1)<abs(jeteta2))*abs(jeteta1)+((abs(jeteta1)>=abs(jeteta2))*abs(jeteta2))) < " << etaBins.at(iBin+1);
  binDefinition << " ) ";
  binCut.push_back(binDefinition.str());
 }
 
 //----- zone        bin
 std::vector < std::vector <double> > DD_Top;
 std::vector < std::vector <double> > Top;
 std::vector < std::vector <double> > Other;
 std::vector < std::vector <double> > DATA; 
 std::vector < std::vector <double> > DATA_Sub; 
 
 std::vector < std::vector <double> > err_DD_Top;
 std::vector < std::vector <double> > err_Top;
 std::vector < std::vector <double> > err_Other;
 std::vector < std::vector <double> > err_DATA; 
 std::vector < std::vector <double> > err_DATA_Sub; 
 
 //-----  bin
 std::vector <double> eff_Top;
 std::vector <double> err_eff_Top;
 std::vector <double> eff_Top_Higgs;
 std::vector <double> err_eff_Top_Higgs;
 std::vector <double> eff_DATA;
 std::vector <double> err_eff_DATA;
 
 
 ///---- zones:
 ///---- AB    ---> 1! jet btagged and it is the most central or no jet btagged
 ///---- B     ---> 1! jet btagged and it is the most central
 ///---- A     ---> no jet btagged
 
 
 std::vector <std::string> zoneCut; 
 ///--- AB
 zoneCut.push_back("nbjettche==0 || (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10))) )");
 ///--- B
 zoneCut.push_back("                 nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10))) ");
 ///--- A
 zoneCut.push_back("nbjettche==0");
 
 int nZone = zoneCut.size();
 
 
 
 
 
 
 ///---- prepare map ----
 for (int iZone=0; iZone<nZone; iZone++) {
  std::vector <double> zone_temp;
  std::vector <double> err_zone_temp;
  for (int iBin=0; iBin<nBin; iBin++) {
   zone_temp.push_back(0);
   err_zone_temp.push_back(0);
  }
  DD_Top.push_back     (zone_temp);
  err_DD_Top.push_back (err_zone_temp);
  Top.push_back     (zone_temp);
  err_Top.push_back (err_zone_temp);
  Other.push_back     (zone_temp);
  err_Other.push_back (err_zone_temp);
  DATA.push_back     (zone_temp);
  err_DATA.push_back (err_zone_temp);  
  DATA_Sub.push_back     (zone_temp);
  err_DATA_Sub.push_back     (zone_temp);
 }
 for (int iBin=0; iBin<nBin; iBin++) {
  eff_Top_Higgs.push_back(0);
  err_eff_Top_Higgs.push_back(0);
  eff_Top.push_back(0);
  err_eff_Top.push_back(0);
  eff_DATA.push_back(0);
  err_eff_DATA.push_back(0);
 }
 
 
 //  TTree::SetDirectory(0);
 TH1F histo("histo","histo",1,0,2);
 histo.Sumw2();
 //  histo.SetDirectory(0);
 
 ///---- fill maps ----
 for (int iSample=0; iSample<nSample; iSample++) {    
  char nameFile[20000];
  sprintf(nameFile,"%s/%s%s.root",inputDirectory.c_str(),inputBeginningFile.c_str(),nameSample[iSample]);  
  //   if (_debug >= 2)
  std::cout << " nameFile[" << iSample << "] = " << nameFile << std::endl;
  TFile* f = new TFile(nameFile, "READ");
  TTree* treeJetLepVect = (TTree*)f->Get(treeName.c_str());   
  char nameTreeJetLep[41];
  sprintf(nameTreeJetLep,"treeJetLep_%d",iSample); 
  treeJetLepVect->SetName(nameTreeJetLep);
  
  for (int iZone=0; iZone<nZone; iZone++) {
   if (_debug >= 2) std:cout << ">>>> iZone = " << iZone << " :: " << nZone << std::endl;
   for (int iBin=0; iBin<nBin; iBin++) {
    std::string effective_cut;
    std::string normalization = NameNormalization[iSample];
    if (_debug >= 2) std::cout << " normalization = " << normalization << std::endl;
    effective_cut.append ( normalization );
    effective_cut.append ( " * ( " );
    
    effective_cut.append ( " ( " );
    effective_cut.append ( zoneCut.at(iZone) );  //---- which zone: AB, B, A
    effective_cut.append ( " ) " );
    effective_cut.append ( " && " );
    effective_cut.append ( " ( " );
    effective_cut.append ( binCut.at(iBin) );  //---- which eta bin
    effective_cut.append ( " ) " );
    effective_cut.append ( " && " );
    effective_cut.append ( " ( " );
    effective_cut.append ( commonCut_WW );  //---- WW level 
    effective_cut.append ( " ) " );  
    effective_cut.append ( " && " );
    effective_cut.append ( " ( " );
    effective_cut.append ( TopEnrichedCut_WW );  //---- Top enriched level 
    effective_cut.append ( " ) " );  
    
    
    
    
    effective_cut.append ( " ) " );
    
    if (_debug >= 2) std::cout << " effective_cut[" << iSample << "::" << nSample << "][" << iZone << "::" << nZone << "][" << iBin << "::" << nBin << "] = " << effective_cut << std::endl;
    
    histo.Reset();
    histo.SetDirectory(gDirectory);
    treeJetLepVect -> Draw ("1 >> histo",effective_cut.c_str(),"goff");
    
    double error_integral;
    double integral = histo.IntegralAndError(0, 2, error_integral);
    
    if (_debug >= 2) std::cout << " vnameSample.at(" << iSample << ") = " << vnameSample.at(iSample) << std::endl;
    
    if (vnameSample.at(iSample) == "top") {
     Top.at(iZone).at(iBin)     += integral;
     double temp_err = (err_Top.at(iZone)).at(iBin);
     (err_Top.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
    }
    
    if (vnameSample.at(iSample) == "VV-DY-Fake") {
     (Other.at(iZone)).at(iBin)     += integral;
     double temp_err = (err_Other.at(iZone)).at(iBin);
     (err_Other.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
    }
    
    if (vnameSample.at(iSample) == "DATA") {
     (DATA.at(iZone)).at(iBin)     += integral;     
     double temp_err = (err_DATA.at(iZone)).at(iBin);
     (err_DATA.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
    }
    
   }
  } 
 }
 
 ///---- data with MC subtracted ----
 for (int iZone=0; iZone<nZone; iZone++) {
  for (int iBin=0; iBin<nBin; iBin++) {
   (DATA_Sub.at(iZone)).at(iBin)     = ( (DATA.at(iZone)).at(iBin) - (Other.at(iZone)).at(iBin) );
   (err_DATA_Sub.at(iZone)).at(iBin) = sqrt( (err_DATA.at(iZone)).at(iBin)*(err_DATA.at(iZone)).at(iBin) + (err_Other.at(iZone)).at(iBin)*(err_Other.at(iZone)).at(iBin) );

   //---- no negative events!!!
   if ((DATA_Sub.at(iZone)).at(iBin) < 0  ||  (DATA.at(iZone)).at(iBin) == 0) {
    (DATA_Sub.at(iZone)).at(iBin) = 0;
    (err_DATA_Sub.at(iZone)).at(iBin) = 0;
   }
  }
 }
 
 
 std::cout << std::endl;
 std::cout << " calculate efficiency " << std::endl;
 
 ///---- calculate efficiency ----
 
 ///---- zones:
 ///---- AB    ---> 1! jet btagged and it is the most central or no jet btagged
 ///---- B     ---> 1! jet btagged and it is the most central
 ///---- A     ---> no jet btagged
 
 for (int iBin=0; iBin<nBin; iBin++) {
  
  ///----       B               /           AB       
  
  if (Top.at(0).at(iBin)) {
   eff_Top.at(iBin) = Top.at(1).at(iBin) / Top.at(0).at(iBin);
   double errNum = err_Top.at(1).at(iBin) / Top.at(0).at(iBin);
   double errDen = err_Top.at(0).at(iBin) * Top.at(1).at(iBin) / Top.at(0).at(iBin) / Top.at(0).at(iBin);
   err_eff_Top.at(iBin) =  sqrt(errNum*errNum + errDen*errDen);
  }
  else {
   eff_Top.at(iBin) = 0;
   err_eff_Top.at(iBin) = 0;
  }
  
  if ( (DATA_Sub.at(0)).at(iBin) != 0) {
   eff_DATA.at(iBin) = (DATA_Sub.at(1)).at(iBin) / (DATA_Sub.at(0)).at(iBin);
   double errNum = (err_DATA_Sub.at(1)).at(iBin) / (DATA_Sub.at(0)).at(iBin);
   double errDen = (err_DATA_Sub.at(0)).at(iBin) * (DATA_Sub.at(1)).at(iBin) / (DATA_Sub.at(0)).at(iBin) / (DATA_Sub.at(0)).at(iBin);
   err_eff_DATA.at(iBin) =  sqrt(errNum*errNum + errDen*errDen);
   
   std::cout << " (DATA_Sub.at(0)).at(" << iBin <<") = " << (DATA_Sub.at(0)).at(iBin) ;
   std::cout << " (DATA_Sub.at(1)).at(" << iBin <<") = " << (DATA_Sub.at(1)).at(iBin) ;
   std::cout << "         eff_DATA.at(" << iBin <<") = " << eff_DATA.at(iBin) ;
   std::cout << std::endl;
   
  }
  else 
  {
   eff_DATA.at(iBin) = 0;
   err_eff_DATA.at(iBin) = 0;
  }
  
  if (_debug >= 1) std::cout << " eff_Top [" << iBin << "] = " << eff_Top.at(iBin)  << " +/- " << err_eff_Top.at(iBin)  << std::endl;
  if (_debug >= 1) std::cout << " eff_DATA[" << iBin << "] = " << eff_DATA.at(iBin) << " +/- " << err_eff_DATA.at(iBin) << std::endl;
  
 }
 
 
 
 
 
 
 
 ///---- apply efficiency ----
 
 std::cout << std::endl;
 std::cout << " apply efficiency " << std::endl;
 
 ///---- zones:
 ///---- AB    ---> 1! jet btagged and it is the most central or no jet btagged
 ///---- B     ---> 1! jet btagged and it is the most central
 ///---- A     ---> no jet btagged
 
 Clear(Top);
 Clear(Other);
 Clear(DATA);
 Clear(DATA_Sub);
 
 Clear(err_Top);
 Clear(err_Other);
 Clear(err_DATA);
 Clear(err_DATA_Sub);
 
 
 ///---- fill maps ----
 for (int iSample=0; iSample<nSample; iSample++) {    
  char nameFile[20000];
  sprintf(nameFile,"%s/%s%s.root",inputDirectory.c_str(),inputBeginningFile.c_str(),nameSample[iSample]);  
  //   if (_debug >= 2)
  std::cout << " nameFile[" << iSample << "] = " << nameFile << std::endl;
  TFile* f = new TFile(nameFile, "READ");
  TTree* treeJetLepVect = (TTree*)f->Get(treeName.c_str());   
  char nameTreeJetLep[41];
  sprintf(nameTreeJetLep,"treeJetLep_%d",iSample); 
  treeJetLepVect->SetName(nameTreeJetLep);
  
  for (int iZone=0; iZone<nZone; iZone++) {
   if (_debug >= 2) std:cout << ">>>> iZone = " << iZone << " :: " << nZone << std::endl;
   for (int iBin=0; iBin<nBin; iBin++) {
    std::string effective_cut;
    std::string normalization = NameNormalization[iSample];
    if (_debug >= 2) std::cout << " normalization = " << normalization << std::endl;
    effective_cut.append ( normalization );
    effective_cut.append ( " * ( " );
    
    effective_cut.append ( " ( " );
    effective_cut.append ( zoneCut.at(iZone) );  //---- which zone: AB, B, A
    effective_cut.append ( " ) " );
    effective_cut.append ( " && " );
    effective_cut.append ( " ( " );
    effective_cut.append ( binCut.at(iBin) );  //---- which eta bin
    effective_cut.append ( " ) " );
    effective_cut.append ( " && " );
    effective_cut.append ( " ( " );
    effective_cut.append ( commonCut_Higgs );  //---- Higgs level 
    effective_cut.append ( " ) " );    
    
    effective_cut.append ( " ) " );
    
    if (_debug >= 2) std::cout << " effective_cut[" << iSample << "::" << nSample << "][" << iZone << "::" << nZone << "][" << iBin << "::" << nBin << "] = " << effective_cut << std::endl;
    
    histo.Reset();
    histo.SetDirectory(gDirectory);
    treeJetLepVect -> Draw ("1 >> histo",effective_cut.c_str(),"goff");
    
    double error_integral;
    double integral = histo.IntegralAndError(0, 2, error_integral);
    
    if (_debug >= 2) std::cout << " vnameSample.at(" << iSample << ") = " << vnameSample.at(iSample) << std::endl;
    
    if (vnameSample.at(iSample) == "top") {
     Top.at(iZone).at(iBin)     += integral;
     double temp_err = (err_Top.at(iZone)).at(iBin);
     (err_Top.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
    }
    
    if (vnameSample.at(iSample) == "VV-DY-Fake") {
     (Other.at(iZone)).at(iBin)     += integral;
     double temp_err = (err_Other.at(iZone)).at(iBin);
     (err_Other.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
    }
    
    if (vnameSample.at(iSample) == "DATA") {
     (DATA.at(iZone)).at(iBin)     += integral;     
     double temp_err = (err_DATA.at(iZone)).at(iBin);
     (err_DATA.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
    }
    
   }
  } 
 }
 
 ///---- data with MC subtracted ----
 for (int iZone=0; iZone<nZone; iZone++) {
  for (int iBin=0; iBin<nBin; iBin++) {
   (DATA_Sub.at(iZone)).at(iBin)     = ( (DATA.at(iZone)).at(iBin) - (Other.at(iZone)).at(iBin) );
   (err_DATA_Sub.at(iZone)).at(iBin) = sqrt( (err_DATA.at(iZone)).at(iBin)*(err_DATA.at(iZone)).at(iBin) + (err_Other.at(iZone)).at(iBin)*(err_Other.at(iZone)).at(iBin) );
  
   //---- no negative events!!!
   if ((DATA_Sub.at(iZone)).at(iBin) < 0  ||  (DATA.at(iZone)).at(iBin) == 0) {
    (DATA_Sub.at(iZone)).at(iBin) = 0;
    (err_DATA_Sub.at(iZone)).at(iBin) = 0;
   }
  }
 }
 
 
 std::cout << std::endl;
 
 
 ///---- calculate efficiency: for MC only !!! ----
 
 for (int iBin=0; iBin<nBin; iBin++) {
  ///----       B               /           AB         
  if (Top.at(0).at(iBin)) {
   eff_Top_Higgs.at(iBin) = Top.at(1).at(iBin) / Top.at(0).at(iBin);
   double errNum = err_Top.at(1).at(iBin) / Top.at(0).at(iBin);
   double errDen = err_Top.at(0).at(iBin) * Top.at(1).at(iBin) / Top.at(0).at(iBin) / Top.at(0).at(iBin);
   err_eff_Top_Higgs.at(iBin) =  sqrt(errNum*errNum + errDen*errDen);
  }
  else {
   eff_Top_Higgs.at(iBin) = 0;
   err_eff_Top_Higgs.at(iBin) = 0;
  }
 }
  
  
 ///---- plot to screen information ----
 
 for (int iBin=0; iBin<nBin; iBin++) {
  std::cout << " eff_DATA.at(" << iBin << ")= " <<  eff_DATA.at(iBin) ;
  std::cout << " ; eff_Top.at(" << iBin << ")= " <<  eff_Top.at(iBin) ;
  std::cout << " ; eff_Top_Higgs.at(" << iBin << ")= " <<  eff_Top_Higgs.at(iBin) ;
  std::cout << " +/- " <<  err_eff_Top_Higgs.at(iBin) ;
  std::cout << std::endl;
 }

 ///---- correct eff_DATA using variation in MC ----
 ///---- and add error on it! ----
 
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  if (eff_DATA.at(iBin)) {
   if ( (eff_Top.at(iBin) != 0) && (eff_Top_Higgs.at(iBin != 0)) ) {
    double additional_error = eff_DATA.at(iBin) * (eff_Top_Higgs.at(iBin) - eff_Top.at(iBin)) / (eff_Top_Higgs.at(iBin) + eff_Top.at(iBin)) * 2.;
    eff_DATA.at(iBin)     = eff_DATA.at(iBin) * eff_Top_Higgs.at(iBin) / eff_Top.at(iBin);
    err_eff_DATA.at(iBin) = err_eff_DATA.at(iBin) * eff_Top_Higgs.at(iBin) / eff_Top.at(iBin); //---- scale the error according to new efficiency
    err_eff_DATA.at(iBin) = sqrt( err_eff_DATA.at(iBin)*err_eff_DATA.at(iBin) + additional_error*additional_error ); //---- add the "efficiency variation" as a systematic error on eff_DATA (thus an error on alpha!)
   }
  }
 }
 ///---- use efficiency to measure data driven Top ----
 
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  ///----       AB =     B (data subtracted)   /   efficiency
  if (eff_DATA.at(iBin)) {
   (DD_Top.at(0)).at(iBin) = (DATA_Sub.at(1)).at(iBin) / eff_DATA.at(iBin);
   //---- remove DATA statistics error ----
   //   if (Alpha != 0) {
    //    err_Alpha = Alpha * sqrt ( err_Alpha/Alpha*err_Alpha/Alpha - 1./Ncontrol ) ;
   //   }
//    (err_DD_Top.at(0)).at(iBin) = ErrorRatio ((DATA_Sub.at(1)).at(iBin), (err_DATA_Sub.at(1)).at(iBin), eff_DATA.at(iBin), err_eff_DATA.at(iBin));
   (err_DD_Top.at(0)).at(iBin) = ErrorRatio ((DATA_Sub.at(1)).at(iBin),                             0, eff_DATA.at(iBin), err_eff_DATA.at(iBin));
   std::cout << "  eff_DATA.at(" << iBin << ") = " <<  eff_DATA.at(iBin);
   std::cout << " +/- " <<  err_eff_DATA.at(iBin);
   std::cout << "  DATA.at(Zone = 1) = " <<  (DATA.at(1)).at(iBin);
   std::cout << "  DATA_Sub = " <<  (DATA_Sub.at(1)).at(iBin);
   std::cout << "  +/- " <<  (err_DATA_Sub.at(1)).at(iBin);
   std::cout << "  (Other.at(1)).at(" << iBin << ") = " << (Other.at(1)).at(iBin);
   std::cout << "; DD_Top.at(0).at(" << iBin << ") = " << (DD_Top.at(0)).at(iBin);
   std::cout << "; err_DD_Top = " << (err_DD_Top.at(0)).at(iBin) << std::endl;
  }
  else {
   std::cout << " ### efficiency = 0 for " << iBin << std::endl;
  } 
 }

 //---- calculate global scale factor ----
 double totalTop_Central_DD = 0;
 double err_totalTop_Central_DD = 0;
 double totalTop_Central    = 0;
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  totalTop_Central        += (       Top.at(0)).at(iBin);
  totalTop_Central_DD     += (    DD_Top.at(0)).at(iBin);
  err_totalTop_Central_DD += (err_DD_Top.at(0)).at(iBin);
 }
 
 double GlobalSF = 1.;
 double err_GlobalSF = 1.;
 if (totalTop_Central != 0) {
  GlobalSF     =     totalTop_Central_DD / totalTop_Central ;
  err_GlobalSF = err_totalTop_Central_DD / totalTop_Central ;
 }
 std::cout << std::endl;
 std::cout << " GlobalSF = " << GlobalSF << " +/- " << err_GlobalSF << std::endl;
 std::cout << " totalTop_Central    = " << totalTop_Central    << std::endl;
 std::cout << " totalTop_Central_DD = " << totalTop_Central_DD << " +/- " << err_totalTop_Central_DD << std::endl;
 
 double totalTop_Forward = 0;
 for (int iBin=nBin_MAX; iBin<nBin; iBin++) {
  totalTop_Forward += (Top.at(0)).at(iBin);
  
  std::cout << "  eff_DATA.at(" << iBin << ") = " <<  eff_DATA.at(iBin);
  std::cout << "  DATA.at(1) = " <<  (DATA.at(1)).at(iBin);
  std::cout << "  DATA_Sub = " <<  (DATA_Sub.at(1)).at(iBin);
//   std::cout << "; DD_Top.at(0).at(" << iBin << ") = " << (DD_Top.at(0)).at(iBin);
//   std::cout << "; err_DD_Top = " << (err_DD_Top.at(0)).at(iBin) << std::endl;
  
 }
 
 double totalTop_Central_Forward;
 totalTop_Central_Forward = totalTop_Central + totalTop_Forward;
 
 double DD_totalTop_Central_Forward;
 DD_totalTop_Central_Forward = totalTop_Central_Forward * GlobalSF;
 double err_DD_totalTop_Central_Forward;
 err_DD_totalTop_Central_Forward = totalTop_Central_Forward * err_GlobalSF;
 
 ///---- for datacard ----
 double Ncontrol = 0;
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  Ncontrol += (DATA.at(1)).at(iBin);
 }
 double Ncontrol_Sub = 0;
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  Ncontrol_Sub += (DATA_Sub.at(1)).at(iBin);
 } 

 //---- only the bvetoed region is "btag+bvetoed" - "btagged"
 double DD_totalTop;
 DD_totalTop = DD_totalTop_Central_Forward - Ncontrol_Sub;
 double err_DD_totalTop;
 err_DD_totalTop = err_DD_totalTop_Central_Forward;
 

 std::cout << std::endl;
 std::cout << std::endl;
 
 double Alpha = 0;
 double err_Alpha = 0;
 if (Ncontrol != 0) {
  Alpha     =     DD_totalTop / Ncontrol;
  err_Alpha = err_DD_totalTop / Ncontrol;
  std::cout << " Alpha      = " << Alpha        << std::endl;
  std::cout << " err_Alpha  = " << err_Alpha    << std::endl;
   
  //---- add MC subtraction as an error --> 100% error on MC subtraction!!! ----
  double additional_error_MC_sub = (Ncontrol_Sub - Ncontrol) / (Ncontrol);
  err_Alpha = Alpha * sqrt ( err_Alpha/Alpha*err_Alpha/Alpha + additional_error_MC_sub*additional_error_MC_sub ) ;
 }
 else {
  std::cout << " ### ERROR: Scale Factor = 0 " << std::endl;
  gApplication->Terminate(0);
 }
 
 
 std::cout << std::endl;
 std::cout << " ###################### " << std::endl;
 std::cout << " GlobalSF   = " << GlobalSF     << std::endl;
 std::cout << " Alpha      = " << Alpha        << std::endl;
 std::cout << " err_Alpha  = " << err_Alpha    << std::endl;
 std::cout << " Ncontrol   = " << Ncontrol     << std::endl; 
 std::cout << " ###################### " << std::endl;
 std::cout << std::endl;

 
  
 TString nameFileOut = Form ("test/Latinos12/ttbar/result-all-%s-%d.txt",suffix.c_str(), iWP);
 std::cout << " cat " << nameFileOut.Data() << std::endl;
 std::cout << std::endl;
 
 std::ofstream myfileAll; 
//  myfileAll.open (nameFileOut.Data(),std::fstream::app);
 myfileAll.open (nameFileOut.Data());
 myfileAll << std::setw (11) << mH[iWP]                << "   " ;
 myfileAll << std::setw (11) << Ncontrol                  << "   " ;  
 myfileAll << std::setw (11) << Alpha                  << "   " ;  
 myfileAll << std::setw (11) << err_Alpha              << "   " ;  
 myfileAll << std::endl;
 myfileAll.close();
 
 
 
 nameFileOut = Form ("test/Latinos12/ttbar/result-all-SF-%s-%d.txt",suffix.c_str(), iWP);
 std::cout << " cat " << nameFileOut.Data() << std::endl;
 std::cout << std::endl;
 
 std::ofstream myfileAllSF; 
 myfileAllSF.open (nameFileOut.Data());
 myfileAllSF << std::setw (11) << mH[iWP]                << "   " ;
 myfileAllSF << std::setw (11) << GlobalSF               << "   " ;  
 myfileAllSF << std::setw (11) << err_GlobalSF           << "   " ;  
 myfileAllSF << std::endl;
 myfileAllSF.close();
 
 gApplication->Terminate(0);
 
}


