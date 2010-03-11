/*
TTBarUtils
*/

#include "TTBarUtils.h"


///==== MC Decay Channel of VV ====
std::pair<int,int> GetMCDecayChannel(const std::vector<float>& pdgId){

 std::pair<int,int> result;
 result.first  = -1;
 result.second = -1;
 
 if (pdgId.size() == 4){
  ///=================   Vf
  ///== pdgId.at(0) ==> f11 
  ///== pdgId.at(1) ==> f12 (V = 1 & f = 2)
  ///== pdgId.at(2) ==> f21
  ///== pdgId.at(3) ==> f22
  
  int f11 = pdgId.at(0);
  int f12 = pdgId.at(1);
  int f21 = pdgId.at(2);
  int f22 = pdgId.at(3);
  
  
  ///==== lepton - lepton ====
  if (f11 >= 11 && f11 <= 16 && f21 >= 11 && f21 <= 16) {
   result.first  = 1;
   ///==== emu - emu ====
   if (f11 >= 11 && f11 <= 14 && f21 >= 11 && f21 <= 14) {
    result.second  = 1;
   }
   ///==== emu - tau ====
   if (f11 >= 11 && f11 <= 14 && f21 >=15 && f21 <= 16) {
    result.second  = 2;
   }
   ///==== tau - emu ====
   if (f21 >= 11 && f21 <= 14 && f11 >= 15 && f11 <= 16) {
    result.second  = 3;    
   }
   ///==== tau - tau ====
   if (f21 >= 15 && f21 <= 16 && f11 >= 15 && f11 <= 16) {
    result.second  = 4;
   }
  }
  
  ///==== lepton - quark ====
  if ((f11 >= 11 && f11 <= 16 && f21 >= 1 && f21 <= 4) || (f21 >= 11 && f21 <= 16 && f11 >= 1 && f11 <= 4)) {
   result.first  = 2;
   ///==== emu - quark ====
   if (f11 >= 11 && f11 <= 14 && f21 >= 1 && f21 <= 4){
    result.second  = 1;
   }
   ///==== quark - emu ====
   if (f21 >= 11 && f21 <= 14 && f11 >= 1 && f11 <= 4) {
    result.second  = 2;
   }
   ///==== tau - quark ====
   if (f21 >= 1 && f21 <= 4 && f11 >= 15 && f11 <= 16){
    result.second  = 3;
   }
   ///==== quark -tau ====
   if (f11 >= 1 && f11 <= 4 && f21 >=15 && f21 <= 16) {
    result.second  = 4;
   }   
  }

  ///==== quark - quark ====
  if (f11 >= 1 && f11 <= 4 && f21 >= 1 && f21 <= 4) {
   result.first  = 3;
  }
 }
 
 return result;
}
  
 
 
 
 std::pair<int,int> GetMCDecayChannel(float pdgId11,float pdgId12, float pdgId21, float pdgId22){
  std::vector<float> vectPdgId;
  vectPdgId.push_back(pdgId11);
  vectPdgId.push_back(pdgId12);
  vectPdgId.push_back(pdgId21);
  vectPdgId.push_back(pdgId22);
  return GetMCDecayChannel(vectPdgId);
 }
 
 
 
 
 
 
 
 
 
 
 
 