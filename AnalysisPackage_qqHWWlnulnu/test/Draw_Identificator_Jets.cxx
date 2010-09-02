// {
//  TH1F match("match","match",3,0,3);
//  TH2F match2D("match2D","match2D",3,0,3,20,0,20);
//  
//  TTree* tree = (TTree*) _file0->Get("outTree");
//  TCanvas cc("cc","cc",1000,500);
//  cc.Divide(2);
//  cc.cd(1);
//  tree->Draw("n_jets:n_matched >> match2D","","colz");
//  match2D.Draw("colz");
//  cc.cd(2);
//  tree->Draw("n_matched >> match");
//  match.DrawNormalized();
// }

{
 TH1F match1("match1","MaxPt",3,0,3);
 TH1F match2("match2","MaxMVA",3,0,3);
 TTree* tree1 = (TTree*) _file0->Get("outTree");
 TTree* tree2 = (TTree*) _file1->Get("outTree");
 TCanvas cc("cc","cc",500,500);
 tree1->Draw("n_matched >> match1");
 tree2->Draw("n_matched >> match2");
 
 
 match1.SetLineWidth(2);
 match1.SetLineColor(kRed);
 
 match2.SetLineWidth(2);
 match2.SetLineColor(kBlue);
 
//  match1.GetYaxis()->SetRangeUser(0.0,1.0);
 for(int i=0;i<3; i++) {
  char name[100];
  sprintf(name,"%d",i);
  match2.GetXaxis()->SetBinLabel(i+1,name);
 }
 match2.DrawNormalized(); 
 match1.DrawNormalized("same");

 gPad->SetGrid();
 gPad->BuildLegend();
 
}
