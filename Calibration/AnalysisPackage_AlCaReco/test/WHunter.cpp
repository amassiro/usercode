#include "treeReader.h"
#include "hFactory.h"
#include "hFunctions.h"
#include "stdHisto.h"
#include "ConfigParser.h"
#include "ntpleUtils.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TMinuit.h"
#include "Math/GenVector/VectorUtil.h"
#include "TRandom3.h"
#include <time.h>
#include <sstream>
#include "ntpleUtils.h"
#include "stdHisto.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif


double mT(const ROOT::Math::XYZTVector& v1, const ROOT::Math::XYZTVector& v2){
 return sqrt((v1.Et() + v2.Et()) * (v1.Et() + v2.Et()) - (v1 + v2).Pt() * (v1 + v2).Pt());
}

double mTDirect(double ET,double PT){
 return sqrt(ET*ET - PT*PT);
}




int main(int argc, char** argv)
{ 
 //Check if all nedeed arguments to parse are there                                                                                                                               
 if(argc != 2)
 {
  std::cerr << ">>>>> analysis.cpp::usage: " << argv[0] << " configFileName" << std::endl ;
  return 1;
 }
 
 // Parse the config file                                                                                                                                                          
 parseConfigFile (argv[1]) ;
 
 std::string treeName  = gConfigParser -> readStringOption("Input::treeName");
 std::string inputFile = gConfigParser -> readStringOption("Input::inputFile");
 
 int entryMAX = gConfigParser -> readIntOption("Input::entryMAX");
 int entryMIN = gConfigParser -> readIntOption("Input::entryMIN");
 int entryMOD = gConfigParser -> readIntOption("Input::entryMOD");
 
 int BinMass = gConfigParser -> readIntOption("Input::BinMass");
 int BinPt   = gConfigParser -> readIntOption("Input::BinPt");
 
 
 std::cout << ">>>>> input::entryMIN  " << entryMIN  << std::endl;  
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 std::cout << ">>>>> input::BinMass   " << BinMass  << std::endl;  
 std::cout << ">>>>> input::BinPt     " << BinPt  << std::endl;  
 
 double PTMIN = gConfigParser -> readDoubleOption("Selections::PTMIN");
 std::cout << ">>>>> Selections::PTMIN  " << PTMIN  << std::endl;  
 
 double MINMT = gConfigParser -> readDoubleOption("Selections::MINMT");
 std::cout << ">>>>> Selections::MINMT  " << MINMT  << std::endl;  
 
 
 
 
 // Open ntple
 TChain* chain = new TChain(treeName.c_str());
 chain->Add(inputFile.c_str());
 treeReader reader((TTree*)(chain));
 
 
 
 
 ///----------------
 ///---- output ----
 std::string OutFileName    = gConfigParser -> readStringOption("Output::outFileName");
 std::cout << ">>>>> Output::outFileName  " << OutFileName  << std::endl;  

 std::string outFileNameImage    = gConfigParser -> readStringOption("Output::outFileNameImage");
 std::cout << ">>>>> Output::outFileNameImage  " << outFileNameImage  << std::endl;  
 
 std::string outFileNameImagePT    = gConfigParser -> readStringOption("Output::outFileNameImagePT");
 std::cout << ">>>>> Output::outFileNameImagePT  " << outFileNameImagePT  << std::endl;  
 
 std::string outFileNameImageET    = gConfigParser -> readStringOption("Output::outFileNameImageET");
 std::cout << ">>>>> Output::outFileNameImageET  " << outFileNameImageET  << std::endl;  
 
 
 TFile outFile(OutFileName.c_str(),"RECREATE");
 outFile.cd();
 
 TH1F* SwissCrossDistDATA = new TH1F("SwissCrossDistDATA","SwissCrossDistDATA",100,0,1.5); 
 
 TH1F hEt("hEt","hEt",BinPt,0,200);
 TH1F hPt("hPt","hPt",BinPt,0,200);
 TH1F hMT("hMT","hMT",BinMass,0,200);
 TTree myTree("myTree","myTree");
 double Eta;
 double pT;
 double ET;
 double MT;
 double EoP;
 double SwissE4;
 double MaxEnergy;
 
 myTree.Branch("Eta",&Eta,"Eta/D");
 myTree.Branch("ET",&ET,"ET/D");
 myTree.Branch("pT",&pT,"pT/D");
 myTree.Branch("MT",&MT,"MT/D");
 myTree.Branch("EoP",&EoP,"EoP/D");
 
 myTree.Branch("SwissE4",&SwissE4,"SwissE4/D");
 myTree.Branch("MaxEnergy",&MaxEnergy,"MaxEnergy/D");
 
 double start, end;
 
 if (entryMAX == -1) entryMAX = reader.GetEntries();
 else if (reader.GetEntries() < entryMAX) entryMAX = reader.GetEntries();
 
 int selEvents = 0;
 int step = 0;
 start = clock();
 for(int iEvent = entryMIN ; iEvent < entryMAX ; ++iEvent) {
  reader.GetEntry(iEvent);
  if((iEvent%entryMOD) == 0) std::cout << ">>>>> analysis::GetEntry " << iEvent << std::endl;   
  
  int nEles = reader.Get4V("electrons")->size();
  int nEleSel = 0;
  
  std::vector<int> blacklist;
  std::vector<int> whitelist;
  /*
  for (int iEle = 0; iEle < nEles; iEle++){    
   if
//     (
//     reader.GetInt("electrons_mishits")->at(iEle) > 1
//     || reader.GetFloat("electrons_deltaPhiIn")->at(iEle) > 0.1
//     || reader.GetFloat("electrons_deltaEtaIn")->at(iEle) > 0.02
//     || reader.Get4V("electrons")->at(iEle).Pt() < 5
//     || (reader.GetFloat("electrons_eOverP")->at(iEle) > 5 || reader.GetFloat("electrons_eOverP")->at(iEle) < 0.35)
//     || reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle) < 0.02
//     || (reader.Get4V("met")->at(0)).P() < 30
//     || reader.GetFloat("electrons_hOverE")->at(iEle) > 0.2
//     || reader.GetFloat("electrons_tkIso")->at(iEle) > 2.0
//     || reader.GetFloat("electrons_emIso04")->at(iEle) > 3.0
//     || reader.GetFloat("electrons_hadIso04_1")->at(iEle) > 2.0    
//     || reader.GetFloat("electrons_hadIso03_1")->at(iEle) > 2.0
//     )


// (
// ((reader.GetInt("electrons_mishits")->at(iEle) > 1
// || reader.GetFloat("electrons_tkIso")->at(iEle)      > 1.966
// || reader.GetFloat("electrons_emIso03")->at(iEle)    > 3.155
// || reader.GetFloat("electrons_hadIso03_1")->at(iEle) > 8.739
// || reader.GetFloat("electrons_hOverE")->at(iEle)     > 0.033
// || reader.GetFloat("electrons_deltaPhiIn")->at(iEle) > 0.032
// || reader.GetFloat("electrons_deltaEtaIn")->at(iEle) > 0.019
// //     || reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle) > 0.010
// ) && (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) < 1.479))
// ||
// ((reader.GetInt("electrons_mishits")->at(iEle) > 1
// || reader.GetFloat("electrons_tkIso")->at(iEle)      > 1.136
// || reader.GetFloat("electrons_emIso03")->at(iEle)    > 7.991
// || reader.GetFloat("electrons_hadIso03_1")->at(iEle) > 1.762
// || reader.GetFloat("electrons_hOverE")->at(iEle)     > 0.034
// || reader.GetFloat("electrons_deltaPhiIn")->at(iEle) > 0.025
// || reader.GetFloat("electrons_deltaEtaIn")->at(iEle) > 0.008
// //     || reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle) > 0.031
// ) && (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) > 1.479))



///==== EleId ====
//http://cmssw.cvs.cern.ch/cgi-bin/cmssw.cgi/CMSSW/RecoEgamma/ElectronIdentification/python/electronIdCutBased_cfi.py?revision=1.23&view=markup
//# variables H/E sigmaietaieta deltaphiin deltaetain e2x5/e5X5 e1x5/e5x5 isoTk ecalTk hcalTk(barrel/endcap)
//barrel = cms.vdouble(0.05, 0.0103, 0.8, 0.00688, -1, -1, 7.33, 4.68, 9999., 9999., 9999.,9999., 0.000, -9999., 9999., 9999., 9999, -1, 0, 0),
//endcap = cms.vdouble(0.0389, 0.0307, 0.7, 0.00944, -1, -1, 7.76, 3.09, 2.23, 9999., 9999.,9999., 0.000, -9999., 9999., 9999., 9999, -1, 0, 0)

(
(
 ( reader.GetFloat("electrons_hOverE")->at(iEle)   > 0.05
|| reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle) > 0.0103
|| reader.GetFloat("electrons_deltaPhiIn")->at(iEle) > 0.8
|| reader.GetFloat("electrons_deltaEtaIn")->at(iEle) > 0.00688
|| reader.GetFloat("electrons_tkIso")->at(iEle)      > 7.33
|| reader.GetFloat("electrons_emIso03")->at(iEle)    > 4.68
)
&& (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) < 1.479))
||
(
( reader.GetFloat("electrons_hOverE")->at(iEle)   > 0.0389
|| reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle) > 0.0307
|| reader.GetFloat("electrons_deltaPhiIn")->at(iEle) > 0.7
|| reader.GetFloat("electrons_deltaEtaIn")->at(iEle) > 0.00944
|| reader.GetFloat("electrons_tkIso")->at(iEle)      > 7.76
|| reader.GetFloat("electrons_emIso03")->at(iEle)    > 3.09
)
&& (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) >= 1.479))
)
if

///==== Branson ====
 (
  (reader.Get4V("met")->at(0)).Et() < 20
  || reader.Get4V("electrons")->at(iEle).Pt() < 20 || reader.Get4V("electrons")->at(iEle).Pt() > 60
  || deltaPhi(reader.Get4V("electrons")->at(iEle).Phi(),(reader.Get4V("met")->at(0)).Phi()) < 0.75
//   || reader.GetFloat("sumET")->at(0) > 40
//   || (reader.GetFloat("sumET")->at(0) > 10 && reader.Get4V("met")->at(0).Et() < (30 + 2/15. * (reader.GetFloat("sumET")->at(0)-25)))
//   || (reader.GetFloat("sumET")->at(0) < 10 && reader.Get4V("met")->at(0).Et() < (20 + 0.8 * (reader.GetFloat("sumET")->at(0))))
 )

///=== old ===
//    (
//      ((reader.GetInt("electrons_mishits")->at(iEle) > 1
//     || reader.GetFloat("electrons_tkIso")->at(iEle)      > 1.966
//     || reader.GetFloat("electrons_emIso03")->at(iEle)    > 3.155
//     || reader.GetFloat("electrons_hadIso03_1")->at(iEle) > 8.739
//     || reader.GetFloat("electrons_hOverE")->at(iEle)     > 0.033
//     || reader.GetFloat("electrons_deltaPhiIn")->at(iEle) > 0.032
//     || reader.GetFloat("electrons_deltaEtaIn")->at(iEle) > 0.019
// //     || reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle) > 0.010
//     ) && (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) < 1.479))
//     ||
//      ((reader.GetInt("electrons_mishits")->at(iEle) > 1
//     || reader.GetFloat("electrons_tkIso")->at(iEle)      > 1.136
//     || reader.GetFloat("electrons_emIso03")->at(iEle)    > 7.991
//     || reader.GetFloat("electrons_hadIso03_1")->at(iEle) > 1.762
//     || reader.GetFloat("electrons_hOverE")->at(iEle)     > 0.034
//     || reader.GetFloat("electrons_deltaPhiIn")->at(iEle) > 0.025
//     || reader.GetFloat("electrons_deltaEtaIn")->at(iEle) > 0.008
// //     || reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle) > 0.031
//     ) && (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) > 1.479))
//     || (reader.Get4V("met")->at(0)).P() < 30
//     || reader.Get4V("electrons")->at(iEle).Pt() < 20
//    )
    {
    blacklist.push_back(iEle);
   }
   else {
    whitelist.push_back(iEle);
   }
    
  }
*/
  
  
  for (int iEle = 0; iEle < nEles; iEle++){    
   if (
   
    ///==== EleId ====
    //http://cmssw.cvs.cern.ch/cgi-bin/cmssw.cgi/CMSSW/RecoEgamma/ElectronIdentification/python/electronIdCutBased_cfi.py?revision=1.23&view=markup
    //# variables H/E sigmaietaieta deltaphiin deltaetain e2x5/e5X5 e1x5/e5x5 isoTk ecalTk hcalTk(barrel/endcap)
    //barrel = cms.vdouble(0.05, 0.0103, 0.8, 0.00688, -1, -1, 7.33, 4.68, 9999., 9999., 9999.,9999., 0.000, -9999., 9999., 9999., 9999, -1, 0, 0),
    //endcap = cms.vdouble(0.0389, 0.0307, 0.7, 0.00944, -1, -1, 7.76, 3.09, 2.23, 9999., 9999.,9999., 0.000, -9999., 9999., 9999., 9999, -1, 0, 0)
    
//     (
//     (
//     ( reader.GetFloat("electrons_hOverE")->at(iEle)            < 0.05
//     && reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle)    < 0.0103
//     && fabs(reader.GetFloat("electrons_deltaPhiIn")->at(iEle)) < 0.8
//     && fabs(reader.GetFloat("electrons_deltaEtaIn")->at(iEle)) < 0.00688
//     && reader.GetFloat("electrons_tkIso")->at(iEle)            < 7.33
//     && reader.GetFloat("electrons_emIso03")->at(iEle)          < 4.68
//     )
//     && (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) < 1.479))
//     ||
//     (
//     ( reader.GetFloat("electrons_hOverE")->at(iEle)            < 0.0389
//     && reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle)    < 0.0307
//     && fabs(reader.GetFloat("electrons_deltaPhiIn")->at(iEle)) < 0.7
//     && fabs(reader.GetFloat("electrons_deltaEtaIn")->at(iEle)) < 0.00944
//     && reader.GetFloat("electrons_tkIso")->at(iEle)            < 7.76
//     && reader.GetFloat("electrons_emIso03")->at(iEle)          < 3.09
//     )
//     && (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) >= 1.479))
//     )
//     &&
     
     ///==== Branson ====
     
    (
    reader.Get4V("met")->at(0)).Et() > 20
    && reader.Get4V("electrons")->at(iEle).Pt() > PTMIN 
    && reader.Get4V("electrons")->at(iEle).Pt() < 60
    && deltaPhi(reader.Get4V("electrons")->at(iEle).Phi(),(reader.Get4V("met")->at(0)).Phi()) > 0.75
    && (((reader.Get4V("met")->at(0)).Et() / reader.GetFloat("sumEt")->at(0)) > (-0.07 * (reader.Get4V("met")->at(0)).Et() + 3.5 ) 
    || ((reader.Get4V("met")->at(0)).Et() / reader.GetFloat("sumEt")->at(0)) > 0.4)
//     && (reader.Get4V("met")->at(0)).Et() > (-0.08 * (reader.Get4V("met")->at(0)).Et() / reader.GetFloat("sumEt")->at(0) +4)
    
//      && reader.GetFloat("sumEt")->at(0) < 40
//      && ((reader.GetFloat("sumEt")->at(0) >= 10 && reader.Get4V("met")->at(0).Et() > (30 + 2/15. * (reader.GetFloat("sumEt")->at(0)-25)))
//        || (reader.GetFloat("sumEt")->at(0) < 10 && reader.Get4V("met")->at(0).Et() > (20 + 0.8 * (reader.GetFloat("sumEt")->at(0)))))
    
 
 
 ///=== + eleID
//     reader.Get4V("met")->at(0)).Et() > 18
//     && reader.Get4V("electrons")->at(iEle).Et() > 18
//     && reader.Get4V("electrons")->at(iEle).Pt() > PTMIN 
//     && reader.Get4V("electrons")->at(iEle).Pt() < 60
//     && deltaPhi(reader.Get4V("electrons")->at(iEle).Phi(),(reader.Get4V("met")->at(0)).Phi()) > 0.75
//     && (((reader.Get4V("met")->at(0)).Et() / reader.GetFloat("sumEt")->at(0)) > (-0.1 * (reader.Get4V("met")->at(0)).Et() + 2.6 ) 
//     || ((reader.Get4V("met")->at(0)).Et() / reader.GetFloat("sumEt")->at(0)) > 0.5)
    
    )
     {
      whitelist.push_back(iEle);
//       std::cerr << " reader.GetFloat(\"sumEt\")->at(0) = " << reader.GetFloat("sumEt")->at(0) << std::endl;
     }
     else {
      blacklist.push_back(iEle);
     }
     
  }
  
  
  int iEleMaxPt  = SelectLepton(*reader.Get4V("electrons"),"maxPt",5,&blacklist);
  if (iEleMaxPt!= -1) {
//    std::cerr << " nEles = " << nEles << " " ;
//    std::cerr << " iEleMaxPt = " << iEleMaxPt << std::endl;
  }
  for (int iEle = 0; iEle < nEles; iEle++){    
   bool skipEle = false;
   
   for(unsigned int kk = 0; kk < blacklist.size(); ++kk){
    if(blacklist.at(kk) == static_cast<int>(iEle)) skipEle = true;
   }
   if (iEle == iEleMaxPt) skipEle = true;
   if (reader.GetFloat("Calo_Energy")->at(iEle) < 10.0) skipEle = true;
   if (!skipEle) {
    nEleSel++;
   }
  }
//   if (iEleMaxPt != -1){
   if (iEleMaxPt != -1 && nEleSel == 0){   
   MT = mT(reader.Get4V("met")->at(0),(reader.Get4V("electrons")->at(iEleMaxPt)));
   pT = reader.Get4V("electrons")->at(iEleMaxPt).Pt();   
   ET = (reader.GetFloat("electrons_scE")->at(iEleMaxPt)) * sin(reader.Get4V("electrons")->at(iEleMaxPt).Theta());
   EoP = reader.GetFloat("electrons_eOverP")->at(iEleMaxPt);
   Eta = reader.Get4V("electrons")->at(iEleMaxPt).Eta();
   if (MT > MINMT){
    hPt.Fill(pT);
    hEt.Fill(ET);
    std::cerr << " runId = " << reader.GetInt("runId")->at(0) << " lumiId = " << reader.GetInt("lumiId")->at(0) << " eventId = " << reader.GetInt("eventId")->at(0) << " ET(SC) = " << ET << " Eta = " << Eta << std::endl;    
   }
   
   SwissE4 = reader.GetFloat("SwissE4")->at(iEleMaxPt);
   MaxEnergy = reader.GetFloat("MaxEnergy")->at(iEleMaxPt);
   
   if (MT>30 && EoP<3 && ET>18) {
    SwissCrossDistDATA->Fill((1-SwissE4/MaxEnergy));
    std::cerr << " (1-SwissE4/MaxEnergy) = " << (1-SwissE4/MaxEnergy) << std::endl;
   }
   
   hMT.Fill(MT);
   myTree.Fill();
   selEvents++;
   }
 } //loop over the events 
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 std::cout << " selEvents = " << selEvents << " : " << entryMAX - entryMIN << std::endl;
 
 TH1F efficiency("efficiency","efficiency",1,0,1);
 efficiency.SetBinContent(1,static_cast<double>(selEvents)/static_cast<double>(entryMAX - entryMIN));
 efficiency.Write();
 
 hEt.SetMarkerColor(kGreen);
 hEt.SetMarkerStyle(20);
 hEt.SetMarkerSize(1.0);
 hEt.SetLineColor(kGreen);
 hEt.SetLineWidth(2.0);
 hEt.Write();
 hEt.Draw("E");
 gPad->SaveAs(outFileNameImageET.c_str());
 hPt.SetMarkerColor(kBlue);
 hPt.SetMarkerStyle(20);
 hPt.SetMarkerSize(1.0);
 hPt.SetLineColor(kBlue);
 hPt.SetLineWidth(2.0);
 hPt.Write();
 hPt.Draw("E");
 gPad->SaveAs(outFileNameImagePT.c_str());
 hMT.SetMarkerColor(kRed);
 hMT.SetMarkerStyle(20);
 hMT.SetMarkerSize(1.0);
 hMT.SetLineColor(kRed);
 hMT.SetLineWidth(2.0);
 hMT.Write();
 hMT.Draw("E");
 gPad->SaveAs(outFileNameImage.c_str());
 
 
 SwissCrossDistDATA->SetMarkerColor(kRed);
 SwissCrossDistDATA->SetMarkerStyle(20);
 SwissCrossDistDATA->SetMarkerSize(1.0);
 SwissCrossDistDATA->SetLineColor(kRed);
 SwissCrossDistDATA->SetLineWidth(2.0);
 SwissCrossDistDATA->Draw("E"); 
 gPad->SaveAs("testSwiss.png");
 
 myTree.Write();
 outFile.Write();
  
 return 0;
}



