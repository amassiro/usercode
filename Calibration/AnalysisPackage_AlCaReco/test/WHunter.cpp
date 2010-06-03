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
 
 
 std::cout << ">>>>> input::entryMIN  " << entryMIN  << std::endl;  
 std::cout << ">>>>> input::entryMAX  " << entryMAX  << std::endl;  
 std::cout << ">>>>> input::entryMOD  " << entryMOD  << std::endl;  
 
 std::cout << ">>>>> input::BinMass   " << BinMass  << std::endl;  
 
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
 
 
 TFile outFile(OutFileName.c_str(),"RECREATE");
 outFile.cd();
 
 TH1F hPt("hPt","hPt",2000,0,2000);
 TH1F hMT("hMT","hMT",BinMass,0,200);
 
 
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
    
    (
    (
    ( reader.GetFloat("electrons_hOverE")->at(iEle)            < 0.05
    && reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle)    < 0.0103
    && fabs(reader.GetFloat("electrons_deltaPhiIn")->at(iEle)) < 0.8
    && fabs(reader.GetFloat("electrons_deltaEtaIn")->at(iEle)) < 0.00688
    && reader.GetFloat("electrons_tkIso")->at(iEle)            < 7.33
    && reader.GetFloat("electrons_emIso03")->at(iEle)          < 4.68
    )
    && (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) < 1.479))
    ||
    (
    ( reader.GetFloat("electrons_hOverE")->at(iEle)            < 0.0389
    && reader.GetFloat("electrons_sigmaIetaIeta")->at(iEle)    < 0.0307
    && fabs(reader.GetFloat("electrons_deltaPhiIn")->at(iEle)) < 0.7
    && fabs(reader.GetFloat("electrons_deltaEtaIn")->at(iEle)) < 0.00944
    && reader.GetFloat("electrons_tkIso")->at(iEle)            < 7.76
    && reader.GetFloat("electrons_emIso03")->at(iEle)          < 3.09
    )
    && (fabs((reader.Get4V("electrons")->at(iEle)).Eta()) >= 1.479))
    )
    &&
     
     ///==== Branson ====
     
    (reader.Get4V("met")->at(0)).Et() > 20
    && reader.Get4V("electrons")->at(iEle).Pt() > 20 && reader.Get4V("electrons")->at(iEle).Pt() < 60
    && deltaPhi(reader.Get4V("electrons")->at(iEle).Phi(),(reader.Get4V("met")->at(0)).Phi()) > 0.75
     //   || reader.GetFloat("sumET")->at(0) < 40
     //   || (reader.GetFloat("sumET")->at(0) > 10 && reader.Get4V("met")->at(0).Et() > (30 + 2/15. * (reader.GetFloat("sumET")->at(0)-25)))
     //   || (reader.GetFloat("sumET")->at(0) < 10 && reader.Get4V("met")->at(0).Et() > (20 + 0.8 * (reader.GetFloat("sumET")->at(0))))
    
    )
     {
      whitelist.push_back(iEle);
     }
     else {
      blacklist.push_back(iEle);
     }
     
  }
  
  
  int iEleMaxPt  = SelectLepton(*reader.Get4V("electrons"),"maxPt",5,&blacklist);
  if (iEleMaxPt!= -1) {
   std::cerr << " nEles = " << nEles << " " ;
   std::cerr << " iEleMaxPt = " << iEleMaxPt << std::endl;
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
   hPt.Fill(reader.Get4V("electrons")->at(iEleMaxPt).Pt());
   
   double MT = mT(reader.Get4V("met")->at(0),(reader.Get4V("electrons")->at(iEleMaxPt)));
   hMT.Fill(MT);
   selEvents++;
  }
 } //loop over the events 
 
 end = clock();
 std::cout <<"Time = " <<  ((double) (end - start)) << " (a.u.)" << std::endl;  
 std::cout << " selEvents = " << selEvents << " : " << entryMAX - entryMIN << std::endl;
 hPt.Write();
 hMT.Write();
 hMT.SetMarkerColor(kRed);
 hMT.SetLineColor(kRed);
 hMT.SetLineWidth(1.0);
 hMT.SetMarkerSize(1.0);
 hMT.Draw("E");
 gPad->SaveAs(outFileNameImage.c_str());
 outFile.Write();
  
 return 0;
}



