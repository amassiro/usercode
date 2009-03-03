{
 TFile file0("/home/andrea/Cern/DataTemp/VBF/JetTagger/Data/NN.root","read");
 
 TTree* tNN = (TTree*) file0->Get("tNN");
 
 double px_jet;
 double py_jet;
 double pz_jet;
 double E_jet;
 double match; //---- -1 = no, 1 = yes
 
 tNN->SetBranchAddress("px_jet",&px_jet);
 tNN->SetBranchAddress("py_jet",&py_jet);
 tNN->SetBranchAddress("pz_jet",&pz_jet);
 tNN->SetBranchAddress("E_jet",&E_jet);
 tNN->SetBranchAddress("match",&match);
 
 TEventList Training ("Training","Training");
 TEventList Test ("Test","Test");
 int numTotEntries = (tNN->GetEntries())/10;
 std::cerr << " tot = " << tNN->GetEntries() << " used = " << numTotEntries << std::endl;
 for (int i =0;i<numTotEntries;i++){
  if ((i%5)) Training.Enter(i);
  else Test.Enter(i);
 }
 
 TMultiLayerPerceptron nnetw ("px_jet,py_jet,pz_jet,E_jet:9:5:3:match",tNN,&Training,&Test);
 nnetw.LoadWeights("myWeights.txt");
 nnetw.Draw();
 

}
