/* 
TO COMPILE:

export ROOTSYS=~/Desktop/root
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH
export DYLD_LIBRARY_PATH=$ROOTSYS/lib:$DYLD_LIBRARY_PATH 

c++ -o counter `root-config --glibs --cflags` counter.cpp

TO RUN:     

./count


*/

#include <cmath>
#include <iostream>
#include "TF1.h"
#include "TTree.h"
#include "TCut.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TROOT.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TText.h"
#include <map>
#include <vector>

#include <iomanip>

using namespace std ;

struct coll 
{
 coll (string name) : m_name (name) {} ;
 void add (const double & XS, std::pair<TTree*,TTree*> al) 
 {
  samples[XS] = al ;
 }
 double getEqSigma (TCut cut){
  double events = 0. ;
  for (map<double, std::pair<TTree*,TTree*> >::iterator it = samples.begin () ;
  it != samples.end () ; 
  ++it){
   it->second.second->SetBranchAddress ("preselection_efficiency", &preselection_efficiency) ;
   it->second.second->SetBranchAddress ("numEntriesBefore", &numEntriesBefore) ;
   it->second.second->GetEntry (0) ;
   
   if (it->second.first->GetEntries () != 0) {
    events += (it->first * (1000. * it->second.first->GetEntries (cut)) * preselection_efficiency / numEntriesBefore) ;
   }
  }
  return events ;
 } ;
 
 double getAll () {
  double events = 0. ;
  for (map<double, std::pair<TTree*,TTree*> >::iterator it = samples.begin () ;
  it != samples.end () ; 
  ++it){
   it->second.second->SetBranchAddress("preselection_efficiency",&preselection_efficiency);
   it->second.second->SetBranchAddress("numEntriesBefore",&numEntriesBefore);
   it->second.second->GetEntry(0);
   
   if (it->second.first->GetEntries () != 0) {
    events += (it->first * 1000.);
   }
  }
  return events ;
 } ;
 
 map<double, std::pair<TTree*,TTree*> > samples ;
 string m_name ; 
 
 double XSection;
 double preselection_efficiency;
 int numEntriesBefore;  
} ;


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---


int main () 
{
 vector<coll> samples ;
 TFile * input_01 = new TFile ("output/out_NtupleProducer_DATA.root") ;
 
 samples.push_back (coll ("vbf 130")) ;
 TFile * input_vbf_130 = new TFile ("output/out_NtupleProducer_H130_2W_2lnu_wbf_7TeV.root") ;
 std::pair<TTree*, TTree*> pair_vbf_130 ((TTree*) input_vbf_130->Get ("outTreeJetLep"), (TTree*) input_vbf_130->Get ("outTreeSelections"));
 samples.back ().add (3.68586419414400068e-02, pair_vbf_130) ;
 
 samples.push_back (coll ("vbf 160")) ;
 TFile * input_vbf_160 = new TFile ("output/out_NtupleProducer_H160_2W_2lnu_wbf_7TeV.root") ;
 std::pair<TTree*, TTree*> pair_vbf_160 ((TTree*) input_vbf_160->Get ("outTreeJetLep"), (TTree*) input_vbf_160->Get ("outTreeSelections"));
 samples.back ().add (8.57660314088160014e-02, pair_vbf_160) ;
 
 samples.push_back (coll ("gg 130")) ;
 TFile * input_gg_130 = new TFile ("output/out_NtupleProducer_H130_2W_2lnu_gluonfusion_7TeV.root") ;
 std::pair<TTree*, TTree*> pair_gg_130 ((TTree*) input_gg_130->Get ("outTreeJetLep"), (TTree*) input_gg_130->Get ("outTreeSelections"));
 samples.back ().add (3.68586419414400068e-02, pair_gg_130) ;
 
 samples.push_back (coll ("gg 160")) ;
 TFile * input_gg_160 = new TFile ("output/out_NtupleProducer_H160_2W_2lnu_gluonfusion_7TeV.root") ;
 std::pair<TTree*, TTree*> pair_gg_160 ((TTree*) input_gg_160->Get ("outTreeJetLep"), (TTree*) input_gg_160->Get ("outTreeSelections"));
 samples.back ().add (8.57660314088160014e-02, pair_gg_160) ;
 
 samples.push_back (coll ("tt    ")) ;
 TFile * input_02 = new TFile ("output/out_NtupleProducer_TTbarJets_Tauola-madgraph_Summer10-START36_V9_S09-v1.root") ;
 std::pair<TTree*, TTree*> pair_02 ((TTree*) input_02->Get ("outTreeJetLep"), (TTree*) input_02->Get ("outTreeSelections"));
 samples.back ().add (165., pair_02) ;
 
 samples.push_back (coll ("Wj_mad")) ;
 TFile * input_03 = new TFile ("output/out_NtupleProducer_WJets_7TeV-madgraph-tauola_Summer10-START36_V9_S09-v1.root") ;
 std::pair<TTree*, TTree*> pair_03 ((TTree*) input_03->Get ("outTreeJetLep"), (TTree*) input_03->Get ("outTreeSelections"));
 samples.back ().add (28049., pair_03) ;
 
 samples.push_back (coll ("Zj_mad")) ;
 TFile * input_04 = new TFile ("output/out_NtupleProducer_ZJets_7TeV-madgraph-tauola_Summer10-START36_V9_S09-v2.root") ;
 std::pair<TTree*, TTree*> pair_04 ((TTree*) input_04->Get ("outTreeJetLep"), (TTree*) input_04->Get ("outTreeSelections"));
 samples.back ().add (4485., pair_04) ;
 
 samples.push_back (coll ("WW_mad")) ;
 TFile * input_05 = new TFile ("output/out_NtupleProducer_WW_Spring10-START3X_V26_S09-v1.root") ;
 std::pair<TTree*, TTree*> pair_05 ((TTree*) input_05->Get ("outTreeJetLep"), (TTree*) input_05->Get ("outTreeSelections"));
 samples.back ().add (43., pair_05) ;
 
 samples.push_back (coll ("VZ_mad")) ;
 TFile * input_06 = new TFile ("output/out_NtupleProducer_ZZ_Spring10-START3X_V26_S09-v1.root") ;
 std::pair<TTree*, TTree*> pair_06 ((TTree*) input_06->Get ("outTreeJetLep"), (TTree*) input_06->Get ("outTreeSelections"));
 samples.back ().add (5.9, pair_06) ;
 TFile * input_07 = new TFile ("output/out_NtupleProducer_WZ_Spring10-START3X_V26_S09-v1.root") ;
 std::pair<TTree*, TTree*> pair_07 ((TTree*) input_07->Get ("outTreeJetLep"), (TTree*) input_07->Get ("outTreeSelections"));
 samples.back ().add (18, pair_07) ;
 
 samples.push_back (coll ("St    ")) ;
 TFile * input_09 = new TFile ("output/out_NtupleProducer_SingleTop_sChannel-madgraph_Spring10-START3X_V26_S09-v1.root ") ;
 std::pair<TTree*, TTree*> pair_09 ((TTree*) input_09->Get ("outTreeJetLep"), (TTree*) input_09->Get ("outTreeSelections"));
 samples.back ().add (4.3, pair_09) ;
 TFile * input_10 = new TFile ("output/out_NtupleProducer_SingleTop_tChannel-madgraph_Spring10-START3X_V26_S09-v1.root ") ;
 std::pair<TTree*, TTree*> pair_10 ((TTree*) input_10->Get ("outTreeJetLep"), (TTree*) input_10->Get ("outTreeSelections"));
 samples.back ().add (63, pair_10) ;
 TFile * input_11 = new TFile ("output/out_NtupleProducer_SingleTop_tWChannel-madgraph_Spring10-START3X_V26_S09-v1.root") ;
 std::pair<TTree*, TTree*> pair_11 ((TTree*) input_11->Get ("outTreeJetLep"), (TTree*) input_11->Get ("outTreeSelections"));
 samples.back ().add (10.6, pair_11) ;
 
 samples.push_back (coll ("Zj_alp")) ;
 TFile * input_12 = new TFile ("output/out_NtupleProducer_Z0Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_12 ((TTree*) input_12->Get ("outTreeJetLep"), (TTree*) input_12->Get ("outTreeSelections"));
 samples.back ().add (2004.550, pair_12) ;
 TFile * input_13 = new TFile ("output/out_NtupleProducer_Z1Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_13 ((TTree*) input_13->Get ("outTreeJetLep"), (TTree*) input_13->Get ("outTreeSelections"));
 samples.back ().add (388.890, pair_13) ;
 TFile * input_14 = new TFile ("output/out_NtupleProducer_Z1Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_14 ((TTree*) input_14->Get ("outTreeJetLep"), (TTree*) input_14->Get ("outTreeSelections"));
 samples.back ().add (9.727, pair_14) ;
 TFile * input_15 = new TFile ("output/out_NtupleProducer_Z1Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_15 ((TTree*) input_15->Get ("outTreeJetLep"), (TTree*) input_15->Get ("outTreeSelections"));
 samples.back ().add (0.080, pair_15) ;
 TFile * input_16 = new TFile ("output/out_NtupleProducer_Z1Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_16 ((TTree*) input_16->Get ("outTreeJetLep"), (TTree*) input_16->Get ("outTreeSelections"));
 samples.back ().add (0.000, pair_16) ;
 TFile * input_17 = new TFile ("output/out_NtupleProducer_Z2Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_17 ((TTree*) input_17->Get ("outTreeJetLep"), (TTree*) input_17->Get ("outTreeSelections"));
 samples.back ().add (97.092, pair_17) ;
 TFile * input_18 = new TFile ("output/out_NtupleProducer_Z2Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_18 ((TTree*) input_18->Get ("outTreeJetLep"), (TTree*) input_18->Get ("outTreeSelections"));
 samples.back ().add (8.505, pair_18) ;
 TFile * input_19 = new TFile ("output/out_NtupleProducer_Z2Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_19 ((TTree*) input_19->Get ("outTreeJetLep"), (TTree*) input_19->Get ("outTreeSelections"));
 samples.back ().add (0.112, pair_19) ;
 TFile * input_20 = new TFile ("output/out_NtupleProducer_Z2Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_20 ((TTree*) input_20->Get ("outTreeJetLep"), (TTree*) input_20->Get ("outTreeSelections"));
 samples.back ().add (0.000, pair_20) ;
 TFile * input_21 = new TFile ("output/out_NtupleProducer_Z3Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_21 ((TTree*) input_21->Get ("outTreeJetLep"), (TTree*) input_21->Get ("outTreeSelections"));
 samples.back ().add (21.980, pair_21) ;
 TFile * input_22 = new TFile ("output/out_NtupleProducer_Z3Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_22 ((TTree*) input_22->Get ("outTreeJetLep"), (TTree*) input_22->Get ("outTreeSelections"));
 samples.back ().add (3.837, pair_22) ;
 TFile * input_23 = new TFile ("output/out_NtupleProducer_Z3Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_23 ((TTree*) input_23->Get ("outTreeJetLep"), (TTree*) input_23->Get ("outTreeSelections"));
 samples.back ().add (0.075, pair_23) ;
 TFile * input_24 = new TFile ("output/out_NtupleProducer_Z3Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_24 ((TTree*) input_24->Get ("outTreeJetLep"), (TTree*) input_24->Get ("outTreeSelections"));
 samples.back ().add (0.000, pair_24) ;
 TFile * input_25 = new TFile ("output/out_NtupleProducer_Z4Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_25 ((TTree*) input_25->Get ("outTreeJetLep"), (TTree*) input_25->Get ("outTreeSelections"));
 samples.back ().add (4.329, pair_25) ;
 TFile * input_26 = new TFile ("output/out_NtupleProducer_Z4Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_26 ((TTree*) input_26->Get ("outTreeJetLep"), (TTree*) input_26->Get ("outTreeSelections"));
 samples.back ().add (1.231, pair_26) ;
 TFile * input_27 = new TFile ("output/out_NtupleProducer_Z4Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_27 ((TTree*) input_27->Get ("outTreeJetLep"), (TTree*) input_27->Get ("outTreeSelections"));
 samples.back ().add (0.033, pair_27) ;
 TFile * input_28 = new TFile ("output/out_NtupleProducer_Z4Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_28 ((TTree*) input_28->Get ("outTreeJetLep"), (TTree*) input_28->Get ("outTreeSelections"));
 samples.back ().add (0.000, pair_28) ;
 TFile * input_29 = new TFile ("output/out_NtupleProducer_Z5Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_29 ((TTree*) input_29->Get ("outTreeJetLep"), (TTree*) input_29->Get ("outTreeSelections"));
 samples.back ().add (1.011, pair_29) ;
 TFile * input_30 = new TFile ("output/out_NtupleProducer_Z5Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_30 ((TTree*) input_30->Get ("outTreeJetLep"), (TTree*) input_30->Get ("outTreeSelections"));
 samples.back ().add (0.423, pair_30) ;
 TFile * input_31 = new TFile ("output/out_NtupleProducer_Z5Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_31 ((TTree*) input_31->Get ("outTreeJetLep"), (TTree*) input_31->Get ("outTreeSelections"));
 samples.back ().add (0.017, pair_31) ;
 TFile * input_32 = new TFile ("output/out_NtupleProducer_Z5Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_32 ((TTree*) input_32->Get ("outTreeJetLep"), (TTree*) input_32->Get ("outTreeSelections"));
 samples.back ().add (0.000, pair_32) ;
 
 samples.push_back (coll ("Wj_alp")) ;
 TFile * input_33 = new TFile ("output/out_NtupleProducer_W0Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_33 ((TTree*) input_33->Get ("outTreeJetLep"), (TTree*) input_33->Get ("outTreeSelections"));
 samples.back ().add (24458.922, pair_33) ;
 TFile * input_34 = new TFile ("output/out_NtupleProducer_W1Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_34 ((TTree*) input_34->Get ("outTreeJetLep"), (TTree*) input_34->Get ("outTreeSelections"));
 samples.back ().add (4472.294, pair_34) ;
 TFile * input_35 = new TFile ("output/out_NtupleProducer_W1Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_35 ((TTree*) input_35->Get ("outTreeJetLep"), (TTree*) input_35->Get ("outTreeSelections"));
 samples.back ().add (94.339, pair_35) ;
 TFile * input_36 = new TFile ("output/out_NtupleProducer_W1Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_36 ((TTree*) input_36->Get ("outTreeJetLep"), (TTree*) input_36->Get ("outTreeSelections"));
 samples.back ().add (0.718, pair_36) ;
 TFile * input_37 = new TFile ("output/out_NtupleProducer_W1Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_37 ((TTree*) input_37->Get ("outTreeJetLep"), (TTree*) input_37->Get ("outTreeSelections"));
 samples.back ().add (0.001, pair_37) ;
 TFile * input_38 = new TFile ("output/out_NtupleProducer_W2Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_38 ((TTree*) input_38->Get ("outTreeJetLep"), (TTree*) input_38->Get ("outTreeSelections"));
 samples.back ().add (1098.580, pair_38) ;
 TFile * input_39 = new TFile ("output/out_NtupleProducer_W2Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_39 ((TTree*) input_39->Get ("outTreeJetLep"), (TTree*) input_39->Get ("outTreeSelections"));
 samples.back ().add (81.255, pair_39) ;
 TFile * input_40 = new TFile ("output/out_NtupleProducer_W2Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_40 ((TTree*) input_40->Get ("outTreeJetLep"), (TTree*) input_40->Get ("outTreeSelections"));
 samples.back ().add (0.970, pair_40) ;
 TFile * input_41 = new TFile ("output/out_NtupleProducer_W2Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_41 ((TTree*) input_41->Get ("outTreeJetLep"), (TTree*) input_41->Get ("outTreeSelections"));
 samples.back ().add (0.002, pair_41) ;
 TFile * input_42 = new TFile ("output/out_NtupleProducer_W3Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_42 ((TTree*) input_42->Get ("outTreeJetLep"), (TTree*) input_42->Get ("outTreeSelections"));
 samples.back ().add (242.030, pair_42) ;
 TFile * input_43 = new TFile ("output/out_NtupleProducer_W3Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_43 ((TTree*) input_43->Get ("outTreeJetLep"), (TTree*) input_43->Get ("outTreeSelections"));
 samples.back ().add (37.805, pair_43) ;
 TFile * input_44 = new TFile ("output/out_NtupleProducer_W3Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_44 ((TTree*) input_44->Get ("outTreeJetLep"), (TTree*) input_44->Get ("outTreeSelections"));
 samples.back ().add (0.674, pair_44) ;
 TFile * input_45 = new TFile ("output/out_NtupleProducer_W3Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_45 ((TTree*) input_45->Get ("outTreeJetLep"), (TTree*) input_45->Get ("outTreeSelections"));
 samples.back ().add (0.002, pair_45) ;
 TFile * input_46 = new TFile ("output/out_NtupleProducer_W4Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_46 ((TTree*) input_46->Get ("outTreeJetLep"), (TTree*) input_46->Get ("outTreeSelections"));
 samples.back ().add (47.576, pair_46) ;
 TFile * input_47 = new TFile ("output/out_NtupleProducer_W4Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_47 ((TTree*) input_47->Get ("outTreeJetLep"), (TTree*) input_47->Get ("outTreeSelections"));
 samples.back ().add (11.566, pair_47) ;
 TFile * input_48 = new TFile ("output/out_NtupleProducer_W4Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_48 ((TTree*) input_48->Get ("outTreeJetLep"), (TTree*) input_48->Get ("outTreeSelections"));
 samples.back ().add (0.306, pair_48) ;
 TFile * input_49 = new TFile ("output/out_NtupleProducer_W4Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_49 ((TTree*) input_49->Get ("outTreeJetLep"), (TTree*) input_49->Get ("outTreeSelections"));
 samples.back ().add (0.001, pair_49) ;
 TFile * input_50 = new TFile ("output/out_NtupleProducer_W5Jets_Pt0to100-alpgen_Spring10-START3X_V26_S09-v1.root") ;      
 std::pair<TTree*, TTree*> pair_50 ((TTree*) input_50->Get ("outTreeJetLep"), (TTree*) input_50->Get ("outTreeSelections"));
 samples.back ().add (11.423, pair_50) ;
 TFile * input_51 = new TFile ("output/out_NtupleProducer_W5Jets_Pt100to300-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_51 ((TTree*) input_51->Get ("outTreeJetLep"), (TTree*) input_51->Get ("outTreeSelections"));
 samples.back ().add (3.846, pair_51) ;
 TFile * input_52 = new TFile ("output/out_NtupleProducer_W5Jets_Pt300to800-alpgen_Spring10-START3X_V26_S09-v1.root") ;    
 std::pair<TTree*, TTree*> pair_52 ((TTree*) input_52->Get ("outTreeJetLep"), (TTree*) input_52->Get ("outTreeSelections"));
 samples.back ().add (0.163, pair_52) ;
 TFile * input_53 = new TFile ("output/out_NtupleProducer_W5Jets_Pt800to1600-alpgen_Spring10-START3X_V26_S09-v1.root") ;   
 std::pair<TTree*, TTree*> pair_53 ((TTree*) input_53->Get ("outTreeJetLep"), (TTree*) input_53->Get ("outTreeSelections"));
 samples.back ().add (0.001, pair_53) ;
 
 //PG questo e' un altro sample, ma ci sono i getti?
 //PG in powheg si direbbe di no
 //   TFile * input_54 = new TFile ("output/out_NtupleProducer_WminusToENu-CTEQ66-powheg_Summer10-START36_V9_S09-v1.root") ;    
 //   std::pair<TTree*, TTree*> pair_54 ((TTree*) input_54->Get ("outTreeJetLep"), (TTree*) input_54->Get ("outTreeSelections"));
 //   samples.back ().add (3954.000, pair_54) ;
 //   TFile * input_55 = new TFile ("output/out_NtupleProducer_WminusToMuNu-CTEQ66-powheg_Summer10-START36_V9_S09-v1.root") ;   
 //   std::pair<TTree*, TTree*> pair_55 ((TTree*) input_55->Get ("outTreeJetLep"), (TTree*) input_55->Get ("outTreeSelections"));
 //   samples.back ().add (3948.000, pair_55) ;
 //   TFile * input_56 = new TFile ("output/out_NtupleProducer_WminusToTauNu-CTEQ66-powheg_Summer10-START36_V9_S09-v2.root") ;  
 //   std::pair<TTree*, TTree*> pair_56 ((TTree*) input_56->Get ("outTreeJetLep"), (TTree*) input_56->Get ("outTreeSelections"));
 //   samples.back ().add (3949.000, pair_56) ;
 //   TFile * input_57 = new TFile ("output/out_NtupleProducer_WplusToENu-CTEQ66-powheg_Summer10-START36_V9_S09-v2.root") ;
 //   std::pair<TTree*, TTree*> pair_57 ((TTree*) input_57->Get ("outTreeJetLep"), (TTree*) input_57->Get ("outTreeSelections"));
 //   samples.back ().add (5825.000, pair_57) ;
 //   TFile * input_58 = new TFile ("output/out_NtupleProducer_WplusToMuNu-CTEQ66-powheg_Summer10-START36_V9_S09-v1.root") ;    
 //   std::pair<TTree*, TTree*> pair_58 ((TTree*) input_58->Get ("outTreeJetLep"), (TTree*) input_58->Get ("outTreeSelections"));
 //   samples.back ().add (5822.000, pair_58) ;
 //   TFile * input_59 = new TFile ("output/out_NtupleProducer_WplusToTauNu-CTEQ66-powheg_Summer10-START36_V9_S09-v1.root") ;   
 //   std::pair<TTree*, TTree*> pair_59 ((TTree*) input_59->Get ("outTreeJetLep"), (TTree*) input_59->Get ("outTreeSelections"));
 //   samples.back ().add (5816.000, pair_59) ;
 
 
 vector<TCut> selections ;
 selections.push_back ("") ;
 selections.push_back ("Mjj>200") ;
 selections.push_back ("Mjj>200&&Deta_RECO_q12>1.5") ;
 //   selections.push_back ("Mjj>200&&Deta_RECO_q12>2&&CJV_20<1") ;
 //   selections.push_back ("Mjj>200&&Deta_RECO_q12>2&&CJV_20<1&&Mll<80&&Mll>12") ;
 selections.push_back ("Mjj>200&&Deta_RECO_q12>2&&CJV_20<1&&Mll<80&&Mll>12&&Dphi_RECO_l12<2") ;
 //   selections.push_back ("Mjj>500&&Deta_RECO_q12>2&&CJV_20<1&&Mll<80&&Mll>12&&Dphi_RECO_l12<2") ;
 //   selections.push_back ("  pT_RECO_q1>30&&pT_RECO_q2>30&&abs(eta_RECO_q1)>0.2&&abs(eta_RECO_q2)>0.2&&eta_RECO_q1_eta_RECO_q2<0.0&&Deta_RECO_q12>1.3&&Mjj>550&&CJV_30<1&&pT_RECO_l1>10&&pT_RECO_l2>10&&abs(eta_RECO_l1)<2.1&&abs(eta_RECO_l2)<2.1&&eta_RECO_l1_eta_RECO_l2<6&&eta_RECO_l1_eta_RECO_l2>0&&Deta_RECO_l12<1.3&&Dphi_RECO_l12<3.0&&((Mll<70&&Mll>10&&pdgId_RECO_l1==pdgId_RECO_l2)||(pdgId_RECO_l1!=pdgId_RECO_l2))&&charge_RECO_l1_charge_RECO_l2==-1&&tkIso_l1/pT_RECO_l1<0.05&&emIso_l1/pT_RECO_l1<0.05&&hadIso_l1/pT_RECO_l1<0.03&&NBjets_trackCountingHighEffBJetTags<3&&NBjets_trackCountingHighPurBJetTags<2&&MET>20");
 selections.push_back ("  pT_RECO_q1>30&&pT_RECO_q2>30&&abs(eta_RECO_q1)>0.2&&abs(eta_RECO_q2)>0.2&&eta_RECO_q1_eta_RECO_q2<0.0&&Deta_RECO_q12>1.3&&Mjj>400&&CJV_30<1&&pT_RECO_l1>10&&pT_RECO_l2>10&&abs(eta_RECO_l1)<2.1&&abs(eta_RECO_l2)<2.1&&eta_RECO_l1_eta_RECO_l2<6&&eta_RECO_l1_eta_RECO_l2>0&&Deta_RECO_l12<1.3&&Dphi_RECO_l12<3.0&&((Mll<70&&Mll>10&&pdgId_RECO_l1==pdgId_RECO_l2)||(pdgId_RECO_l1!=pdgId_RECO_l2))&&charge_RECO_l1_charge_RECO_l2==-1&&MET>20");
 
 cout.precision (2) ;
 cout.unsetf(ios::scientific);
 
 for (int iSample = 0 ; iSample < samples.size () ; ++iSample)
 {
  std::cout << setw (8) << samples.at (iSample).m_name ;
  std::cout << "  |  " << setw (8) << samples.at (iSample).getAll () ;
  std::cout << "  |  " << setw (8) << samples.at (iSample).getEqSigma (selections.at (0)) ;
  for (int iSel = 1 ; iSel < selections.size () ; ++iSel) 
  {
   std::cout << "  |  " << setw (8) << samples.at (iSample).getEqSigma (selections.at (iSel));
   std:cout  << " (" << setw (6) << samples.at (iSample).getEqSigma (selections.at (iSel)) / samples.at (iSample).getEqSigma (selections.at (iSel-1)) << ")" ;
  }
  std::cout << endl ;            
 }  
 
 return 0 ;
 
}
