/*
NAMETEMPLATE
*/
#ifndef NAMETEMPLATE_h
#define NAMETEMPLATE_h

#include <vector>
#include <cmath>

#include "treeReader.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif

#include "Math/GenVector/VectorUtil.h"


std::pair<double,int> GetCombinationChi2(
                                         treeReader& reader,
					 std::vector<std::vector<int> >& combinations,
					 std::vector<int>* whitelistJet,
					 const ROOT::Math::XYZTVector& lepton,
					 const ROOT::Math::XYZTVector& MET);
 

std::pair<double,int> GetCombinationGeneral(
                                         treeReader& reader,
					 std::vector<std::vector<int> >& combinations,
					 std::vector<int>* whitelistJet);

 
#endif

