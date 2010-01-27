#include "Riostream.h"
void W_MC_2() {
 
 // read file $ROOTSYS/tutorials/tree/basic.dat
 // this file has 3 columns of float data
 TString dir = gSystem->UnixPathName(gInterpreter->GetCurrentMacroName());
 dir.ReplaceAll("tmp.txt","");
 dir.ReplaceAll("/./","/");
 ifstream in;
 in.open(Form("%stmp.txt",dir.Data()));
 
 Float_t x,y;
 Int_t nlines = 0;
 TFile *f = new TFile("basic.root","RECREATE");
 TH2F *h2 = new TH2F("h2","h2",1000,-100,100,1000,-100,100);
 TNtuple *ntuple = new TNtuple("ntuple","data from ascii file","x:y");
 
 int num = 0;
 while (1) {
  if (!(num%3)) continue;
  in >> x >> y;
  if (!in.good()) break;
  if (nlines < 5) printf("x=%8f, y=%8f\n",x,y);
  h2->Fill(x,y);
  ntuple->Fill(x,y);
  nlines++;
  num++;
 }
 printf(" found %d points\n",nlines);
 
 in.close();
 
 f->Write();
}
