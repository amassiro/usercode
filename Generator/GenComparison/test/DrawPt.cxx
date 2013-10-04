
{
 TTree* latino = (TTree*) _file0->Get("demo/myTree");


 TCanvas* cc1 = new TCanvas ("cc1","cc1",500,500);
//  TH1F* h1 = new TH1F("h1","pt 1st",30,0,300);
 TH1F* h1 = new TH1F("h1","pt 1st",300,0,300);
 h1->SetLineWidth(4);
 h1->SetLineColor(kBlue);
//  latino->Draw("pt1 >> h1","ptll<45");
 latino->Draw("pt1 >> h1");
 gPad->SetGrid();
 h1->DrawNormalized();

 TCanvas* cc2 = new TCanvas ("cc2","cc2",500,500);
//  TH1F* h2 = new TH1F("h2","pt 2nd",30,0,300);
 TH1F* h2 = new TH1F("h2","pt 2nd",300,0,300);
 h2->SetLineWidth(4);
 h2->SetLineColor(kRed);
//  latino->Draw("pt2 >> h2","ptll<45");
 latino->Draw("pt2 >> h2");
 gPad->SetGrid();
 h2->DrawNormalized();

}


