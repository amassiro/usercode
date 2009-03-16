{
 double pair_DEta;
 double pair_Mjj;
 double pair_pt1;
 double pair_pt2;
 int pair_numJet;
 double pair_SumPtOthers;
 double pair_MjjOthers;
 double pair_match;
 
//  TFile file0("/home/andrea/Cern/DataTemp/VBF/JetTagger/Data/JetTagging_NN_SinglePairTag_Creator_H160_WW_2l_JetCorrection.root","read");
 TFile file0("/home/andrea/Cern/DataTemp/VBF/JetTagger/Data/JetTagging_NN_SinglePairTag_Creator_H160_WW_2l_NOCORRECTION.root","read");
 //  JetTagging_NN_SinglePairTag_Creator_H160_WW_2l_04.root

 
 
 TTree* tNN = (TTree*) file0->Get("tNN");
 
 //---- Tree definition ----
 
 tNN->SetBranchAddress("pair_DEta",&pair_DEta);
 tNN->SetBranchAddress("pair_Mjj",&pair_Mjj);
 tNN->SetBranchAddress("pair_pt1",&pair_pt1);
 tNN->SetBranchAddress("pair_pt2",&pair_pt2);
 tNN->SetBranchAddress("pair_numJet",&pair_numJet);
 tNN->SetBranchAddress("pair_SumPtOthers",&pair_SumPtOthers);
 tNN->SetBranchAddress("pair_MjjOthers",&pair_MjjOthers);
 tNN->SetBranchAddress("pair_match",&pair_match);
 
 // -- Disable all branches ...
 tNN->SetBranchStatus("*",0); 
 // -- ... and switch on those you'd like to write out into the new tree
 tNN->SetBranchStatus("pair_DEta",1);
 tNN->SetBranchStatus("pair_Mjj",1);
 tNN->SetBranchStatus("pair_pt1",1);
 tNN->SetBranchStatus("pair_pt2",1);
 tNN->SetBranchStatus("pair_numJet",1);
 tNN->SetBranchStatus("pair_SumPtOthers",1);
 tNN->SetBranchStatus("pair_MjjOthers",1);
 
 //-- Create a new file + a clone of old tree in new file
 TFile *newfile = new TFile("smallfile_NOCORRECTION.root","recreate");
 TTree *Signal = tNN->CloneTree(0);
 Signal->SetName("Signal");
 TTree *BackGround = tNN->CloneTree(0);
 BackGround->SetName("BackGround");
 
 tNN->SetBranchStatus("pair_match",1);
 
 int nentries = tNN->GetEntries();
//  nentries/=10;
 for (Int_t i=0;i<nentries; i++) {
  tNN->GetEntry(i);
  if (abs(pair_match-1)<0.1) Signal->Fill();
  else BackGround->Fill();
 }
 
 Signal->AutoSave();
 BackGround->AutoSave();
 
 Signal->Print();
 BackGround->Print();
 newfile->Write();
 
 
}
