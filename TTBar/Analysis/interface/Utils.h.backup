#ifndef Utils_h
#define Utils_h

#include "TVector3.h"
#include <map>
#include "Math/GenVector/VectorUtil.h"


double deltaPhi (double phi1, double phi2);
//  ------------------------------------------------------------
double deltaEta (double eta1, double eta2);

//  ------------------------------------------------------------
double deltaR (double phi1, double eta1, double phi2, double eta2);

//  ------------------------------------------------------------
template <class T1, class T2>
std::map<float, std::pair<int, int> > MatchingDRMap(std::vector<T1>& collection1,
                                                    std::vector<T2>& collection2)
{
  // define map of all possible DRs
  typedef std::map<float, std::pair<int, int> > DRMap;
  DRMap myDRMap;
  myDRMap.clear();  
  // compute all DRs 
  for(unsigned int it1 = 0; it1 <  collection1.size(); ++it1)
  {
    for(unsigned int it2 = 0; it2 < collection2.size(); ++it2)
    {
      float DR = deltaR((collection1.at(it1)) . Eta(), (collection1.at(it1)) . Phi(),
                        (collection2.at(it2)) . Eta(), (collection2.at(it2)) . Phi());
      std::pair<int, int> dummy(it1, it2);
      myDRMap[DR] = dummy;
    }
  }
  return myDRMap;
}

// --------------------------------------------------------------------------------------




template <class T1, class T2>
  int GetMatching(std::vector<T1>& collection1, //---- RECO
                std::vector<T2>& collection2, //---- MC
                const float& DRMax,
                float ptRatioMin,
                float ptRatioMax,
                std::vector<int>* matchIt1 = 0) //---- index from RECO that matches with MC

{
  // get the DR map between two collection of particles
  typedef std::map<float, std::pair<int, int> > DRMap;
  DRMap myDRMap = MatchingDRMap(collection1, collection2);
  
    // define boolean flags to avoid double usage of the same particle
  std::vector<bool> isUsed1;
  for(unsigned int i = 0; i < collection1.size(); ++ i)
    isUsed1.push_back(false);
  
  std::vector<bool> isUsed2;
  for(unsigned int i = 0; i < collection2.size(); ++ i)
    isUsed2.push_back(false);
  
  
  // intialize the vector which will store the result of the matching
  if(matchIt1 != 0)
  {
    (*matchIt1).clear();
    for(unsigned int i = 0; i < collection2.size(); ++i)
      (*matchIt1).push_back(-1);
  }
  
  // loop over the DRmap to get the smallest DR matchings
  unsigned int nMatching = 0;
  
  for(DRMap::const_iterator mapIt = myDRMap.begin();
      mapIt != myDRMap.end(); ++mapIt)
  {
    int it1 = (mapIt -> second).first;
    int it2 = (mapIt -> second).second;
    
    float DR = mapIt -> first;
    
    TVector3 momentum1(collection1.at(it1) . Px(),
                       collection1.at(it1) . Py(),
                       collection1.at(it1) . Pz());
    TVector3 momentum2(collection2.at(it2) . Px(),
                       collection2.at(it2) . Py(),
                       collection2.at(it2) . Pz());
    
    if( 1. * collection1.at(it1) . Pt() / (collection2.at(it2)) . Pt() < ptRatioMin) 
      continue;
    if( 1. * collection1.at(it1) . Pt() / (collection2.at(it2)) . Pt() > ptRatioMax) 
      continue;
    
    if( (DR <= DRMax) && (isUsed1.at(it1) == false) && (isUsed2.at(it2) == false) )
    {
      isUsed1.at(it1) = true; 
      isUsed2.at(it2) = true; 
      ++nMatching;
      
      if(matchIt1 != 0)
        (*matchIt1).at(it2) = it1;
    }
    
    if( (nMatching == collection2.size()) || (DR > DRMax) )
      break;    
  }
  
  return nMatching;
}

#endif