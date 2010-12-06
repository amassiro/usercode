/*
AnalysisTTBar
*/

#include "AnalysisTTBar.h"


///==== return the value of the Min Chi2 and the corresponding number in the combinations ====
std::pair<double,int> GetCombinationChi2(treeReader& reader, std::vector<std::vector<int> >& combinations,std::vector<int>* whitelistJet,const ROOT::Math::XYZTVector& lepton, const ROOT::Math::XYZTVector& MET){
 
 double Chi2 = -1;
 double Chi2Combination = -1;
 
//  std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
//  std::vector<float>* jets_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags");
//  
//  int nComb = combinations.size();
//  
//  for (int iComb = 0; iComb<nComb; iComb++){
//   int q1 = combinations.at(iComb).at(0);
//   int q2 = combinations.at(iComb).at(1);
//   int b1 = combinations.at(iComb).at(2); //---> in this analysis this is the bjet that couple with qq
//   int b2 = combinations.at(iComb).at(3);    
//   
//   if(whitelistJet != NULL)
//    if( (whitelistJet -> at(q1)) != 1 || (whitelistJet -> at(q2)) != 1 || (whitelistJet -> at(b1)) != 1 || (whitelistJet -> at(b2)) != 1)
//     continue;
//    
//    double sigma1 = 1;
//   double sigma2 = 1;
//   double sigma3 = 1;
//   
//   double massW = 80.398;
//   double massTop = 170; //--------- ??????????????????????????????????????????????????
//   ROOT::Math::XYZTVector neutrino; // = GetNeutrino(MET,lepton,massW);
//   
//   double Chi2_temp = 0;
//   Chi2_temp += ((jets->at(q1) + jets->at(q2)).M() - massW) * ((jets->at(q1) + jets->at(q2)).M() - massW)  / sigma1 / sigma1; 
//   
//   Chi2_temp += ((jets->at(q1) + jets->at(q2) + jets->at(b1)).M() - massTop) * ((jets->at(q1) + jets->at(q2)).M() - massTop)  / sigma2 / sigma2; 
//   
//   Chi2_temp += ((jets->at(b2) + lepton + neutrino).M() - massTop) * ((jets->at(q1) + jets->at(q2)).M() - massTop)  / sigma3 / sigma3; 
//   
//   if (Chi2_temp < Chi2 || Chi2 == -1) {
//    Chi2 = Chi2_temp;
//    Chi2Combination = iComb;
//   }
//  }
 
 std::pair<double,int> result;
 result.first = Chi2;
 result.second = Chi2Combination;
 return result;
}




///==== return btag sum value o and the number in the combinations ====

std::pair<double,int> GetCombinationGeneral(treeReader& reader, std::vector<std::vector<int> >& combinations, std::vector<int>* whitelistJet){
  std::vector<ROOT::Math::XYZTVector>* jets = reader.Get4V("jets");
  std::vector<float>* jets_trackCountingHighEffBJetTags = reader.GetFloat("jets_trackCountingHighEffBJetTags");
  
  int bestComb = -1;
  int nComb = combinations.size();
  
  double btagCombined = -999;
  double pTCombined = -999;
  
 for (int iComb = 0; iComb<nComb; iComb++){
   int q1 = combinations.at(iComb).at(0);
   int q2 = combinations.at(iComb).at(1);
   int b1 = combinations.at(iComb).at(2); //---> in this analysis this is the bjet that couple with qq
   int b2 = combinations.at(iComb).at(3);    

//    std::cout << " q1 = " << q1 << " q2 = " << q2 << " b1 = " << b1 << " b2 = " << b2 <<  std::endl;        
   
   if(whitelistJet != NULL)
     if( (whitelistJet -> at(q1)) != 1 || (whitelistJet -> at(q2)) != 1 || (whitelistJet -> at(b1)) != 1 || (whitelistJet -> at(b2)) != 1)
      continue;
     
//    std::cout << " passed ... " << std::endl;  
     
     if (jets_trackCountingHighEffBJetTags->at(b1) < jets_trackCountingHighEffBJetTags->at(q1)) continue;
     if (jets_trackCountingHighEffBJetTags->at(b1) < jets_trackCountingHighEffBJetTags->at(q2)) continue;
     if (jets_trackCountingHighEffBJetTags->at(b2) < jets_trackCountingHighEffBJetTags->at(q1)) continue;
     if (jets_trackCountingHighEffBJetTags->at(b2) < jets_trackCountingHighEffBJetTags->at(q2)) continue;

     if (jets_trackCountingHighEffBJetTags->at(b1) < jets_trackCountingHighEffBJetTags->at(b2)) continue;

     double btagCombined_temp  = jets_trackCountingHighEffBJetTags->at(b1) + jets_trackCountingHighEffBJetTags->at(b2);
     if ( btagCombined > btagCombined_temp) continue;
     btagCombined = btagCombined_temp;
     
     if ( jets->at(q1).Pt() < jets->at(q2).Pt()) continue;
     double pTCombined_temp = jets->at(q1).Pt() + jets->at(q2).Pt();
     if ( pTCombined > pTCombined_temp) continue;
     pTCombined = pTCombined_temp;
     
     bestComb = iComb;
 }
 
 std::pair<double,int> result;
 result.first = btagCombined;
 result.second = bestComb;
 return result;
};



