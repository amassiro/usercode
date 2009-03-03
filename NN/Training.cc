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
 
 nnetw.SetLearningMethod(TMultiLayerPerceptron::kSteepestDescent);
 std::cerr << "Training ..." << std::endl;
 nnetw.Train(2000,"text,graph,update=5");
 nnetw.Export();
 
 nnetw.DumpWeights("myWeights.txt");
 
 
 
 
 
 TCanvas* mlpa_canvas = new TCanvas("mlpa_canvas","Network analysis");
 mlpa_canvas->Divide(2,2);
 TMLPAnalyzer ana(nnetw);
 // Initialisation
 ana.GatherInformations();
 // output to the console
 ana.CheckNetwork();
 mlpa_canvas->cd(1);
 // shows how each variable influences the network
 ana.DrawDInputs();
 mlpa_canvas->cd(2);
 // shows the network structure
 nnetw->Draw();
 mlpa_canvas->cd(3);
 // draws the resulting network
//  ana.DrawNetwork(0,"type==1","type==0");
 mlpa_canvas->cd(4);
 // Use the NN to plot the results for each sample
 // This will give approx. the same result as DrawNetwork.
 // All entries are used, while DrawNetwork focuses on 
 // the test sample. Also the xaxis range is manually set.
 mlpa_canvas->cd(0);
 
}
