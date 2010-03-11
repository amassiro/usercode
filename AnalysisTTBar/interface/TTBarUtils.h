/*
TTBarUtils
*/
#ifndef TTBarUtils_h
#define TTBarUtils_h

#include <vector>

///==== MC Decay Channel of V V ====
///==== lepton - lepton ==== < 1 ,   > 
///==== emu - emu ========== < 1 , 1 >
///==== emu - tau ========== < 1 , 2 >
///==== tau - emu ========== < 1 , 3 >
///==== tau - tau ========== < 1 , 4 >
///==== lepton - quark ===== < 2 ,   >
///==== emu - quark ======== < 2 , 1 >
///==== quark - emu ======== < 2 , 2 >
///==== tau - quark ======== < 2 , 3 >
///==== quark - tau ======== < 2 , 4 >
///==== quark - quark ====== < 3 ,   >

std::pair<int,int> GetMCDecayChannel(const std::vector<float>& pdgId);
std::pair<int,int> GetMCDecayChannel(float pdgId11,float pdgId12, float pdgId21, float pdgId22);


#endif

