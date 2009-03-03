{
 #include "NNfunction.h"
 #include "NNfunction.cxx"
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
 
 
 TH1F hPt("hPt","hPt All Jets",2000,0.,200.);
 TH1F hPtMatch("hPtMatch","hPtMatch Tag Jets",2000,0.,200.);
 TH2F hPt_2D("hPt_2D","hPt_2D",1000,-2.,2.,2000,0.,200.);
 
 
 TH1F hBool("hBool","hBool",1000,-2.,2.);
 TH1F hBoolYes("hBoolYes","hBoolYes",1000,-2.,2.);
 TH1F hBoolNo("hBoolNo","hBoolNo",1000,-2.,2.);
 
 TH2F hBoolAndMatch("hBoolAndMatch","hBoolAndMatch",1000,-2.,2.,1000,-2.,2.);
 
 NNfunction miaNN;
 int numTotEntries = tNN->GetEntries();
 std:cerr << " Tot = " << numTotEntries << std::endl;
 for (int i =40000;i<300000;i++){
//  for (int i =40000;i<50000;i++){   
//   for (int i =0;i<numTotEntries;i++){
  if (!(i%1000)) std::cerr << " i = " << i << std::endl;
  tNN->GetEntry(i);
  double flag = miaNN.Value(0,px_jet,py_jet,pz_jet,E_jet);
  
  hBool.Fill(flag);
  hBoolAndMatch.Fill(flag,match);
  if (match==1) {
   hBoolYes.Fill(flag);
   hPtMatch.Fill(sqrt(px_jet*px_jet+py_jet*py_jet));
  }
  else {
   hBoolNo.Fill(flag);
  }
  hPt.Fill(sqrt(px_jet*px_jet+py_jet*py_jet));
  hPt_2D.Fill(flag,sqrt(px_jet*px_jet+py_jet*py_jet));
 }
 
 hBool.Draw();
 hBool.GetXaxis()->SetTitle("NN output");
 hBool.Draw();
 
 hBoolYes.SetLineColor(kBlue);
 hBoolYes.Draw("same");
 
 hBoolNo.SetLineColor(kRed);
 hBoolNo.Draw("same");
 
 
 TCanvas nuovo;
 hBoolAndMatch.Draw("colz");
 hBoolAndMatch.SetMarkerColor(kRed);
 hBoolAndMatch.SetMarkerStyle(8);
 hBoolAndMatch.SetMarkerSize(0.5);
 hBoolAndMatch.GetXaxis()->SetTitle("NN output");
 hBoolAndMatch.GetYaxis()->SetTitle("MC match");
 hBoolAndMatch.Draw("colz");
 
 
 
 
 TCanvas cDraw_2("cDraw_2","cDraw_2");
 cDraw_2.Divide(2,1);
 
 cDraw_2.cd(1);
 
 hBoolNo.SetLineColor(kBlue);
 hBoolNo.Draw();
 hBoolNo.GetXaxis()->SetTitle("NN output");
 hBoolNo.Draw("same");
 
 hBoolYes.SetLineColor(kRed);
 hBoolYes.Draw("same");
 gPad->SetGrid();
 
 
 cDraw_2.cd(2);
 TH1F* efficiency_NN_Signal = new TH1F("efficiency_NN_Signal","Efficiency = num (NN output>x) / total number",1000,-2,2);
 TH1F* efficiency_NN_Background = new TH1F("efficiency_NN_Background","Efficiency = num (NN output>x) / total number",1000,-2,2);
 
 TH2F* efficiency_NN_Signal_Background = new TH2F("efficiency_NN_Signal_Background","Efficiency = num (NN output>x) / total number",500,0,1,500,0,1);
 
 
 double totalYes = hBoolYes.GetEntries();
 double totalNo = hBoolNo.GetEntries();
 double total = hBool.GetEntries();
 
 std::cerr << " total = " << total << std::endl;
 for (int i=1; i< 1001; i++){
  double yes = hBoolYes->Integral(i,1001);
  double no =  hBoolNo->Integral(i,1001);
  efficiency_NN_Signal->SetBinContent(i,yes/totalYes);
  efficiency_NN_Background->SetBinContent(i,no/totalNo);
  efficiency_NN_Signal_Background->Fill(yes/totalYes,no/totalNo,i);
 }
 
 efficiency_NN_Background->Draw();
 efficiency_NN_Background->SetLineColor(kBlue);
 efficiency_NN_Background->SetLineWidth(2);
 efficiency_NN_Background->GetXaxis()->SetTitle("NN output");
 efficiency_NN_Background->GetYaxis()->SetTitle("efficiency");
 efficiency_NN_Background->Draw();
 
 efficiency_NN_Signal->SetLineColor(kRed);
 efficiency_NN_Signal->SetLineWidth(2);
 efficiency_NN_Signal->Draw("same");
 
 TLegend pippo(0.5,0.5,0.8,0.7);
 pippo.AddEntry(efficiency_NN_Signal,"Tag Jets","f");
 pippo.AddEntry(efficiency_NN_Background,"Non Tag Jets","f");
 pippo.Draw();
 
 gPad->SetGrid();
 
 
 
 
 
 TCanvas cDraw_3("cDraw_3","cDraw_3");
 cDraw_3.cd(0);
 hPt_2D.Draw("colz");
 hPt_2D.GetXaxis()->SetTitle("NN output");
 hPt_2D.GetYaxis()->SetTitle("Pt (GeV)");
 hPt_2D.GetXaxis()->SetTitleSize(0.04);
 hPt_2D.GetXaxis()->SetTitleOffset(1.2);
 hPt_2D.GetYaxis()->SetTitleSize(0.04);
 hPt_2D.GetYaxis()->SetTitleOffset(1.2);
 hPt_2D.Draw("colz");
 cDraw_3.Update();
 
 /*
 TCanvas cDraw_Video("cDraw_Video","cDraw_Video");
 TText *text;
 
 char name[1000];
 TH1D* profile;
 for (int i=200; i< 600; i+=4){
  std::cerr << " i = " << i << std::endl;
  sprintf(name,"NNoutput%f",i/1000.*4-2);
  profile = hPt_2D.ProjectionY(name,i,1001);
  if (i>290) profile->Rebin(2);
  if (i>320) profile->Rebin(2);
  if (i>400) profile->Rebin(2);
  if (i>550) profile->Rebin(2);
  profile->SetLineColor(kBlue);
  profile->Draw();
  sprintf(name,"NN output > %f",i/1000.*4-2);
  TPaveText* pt = new TPaveText(0.4,0.8,0.9,0.9,"brNDC");
  pt->SetTextColor(2);
  pt->SetTextSize(0.05357143);
  pt->AddText(name);
  pt->Draw();
  cDraw_Video.SaveAs("video.gif+");
  cDraw_Video.Update();
 }*/
 
 
 TCanvas cDraw_4("cDraw_4","cDraw_4");
 cDraw_4.cd(0);
 hPt.Draw();
 hPt.SetLineColor(kBlue);
 hPt.GetXaxis()->SetTitle("Pt (GeV)");
 hPt.Draw();
 hPtMatch.SetLineColor(kRed);
 hPtMatch.Draw("same");
 cDraw_3.Update();
 
 TCanvas cDraw_5("cDraw_5","cDraw_5");
 cDraw_5.cd(0);
 efficiency_NN_Signal_Background->Draw("colz");
 efficiency_NN_Signal_Background->GetXaxis()->SetTitle("Signal efficiency");
 efficiency_NN_Signal_Background->GetYaxis()->SetTitle("Background efficiency");
 efficiency_NN_Signal_Background->GetXaxis()->SetTitleSize(0.04);
 efficiency_NN_Signal_Background->GetXaxis()->SetTitleOffset(1.2);
 efficiency_NN_Signal_Background->GetYaxis()->SetTitleSize(0.04);
 efficiency_NN_Signal_Background->GetYaxis()->SetTitleOffset(1.2);
 efficiency_NN_Signal_Background->Draw("colz");
 cDraw_5.Update();
 
}