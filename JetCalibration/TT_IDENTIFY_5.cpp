{
 #include "TT_IDENTIFY_5_Function.h"

TFile *_file1 = TFile::Open("output/output_TT_IDENTIFY_1.root");

TCanvas c_h_b_jets_trackCountingHighEffBJetTags;
TH1F* h_Not_b_jets_trackCountingHighEffBJetTags = (TH1F*) _file1->Get("h_Not_b_jets_trackCountingHighEffBJetTags"); 
h_Not_b_jets_trackCountingHighEffBJetTags->SetLineColor(kRed);
h_Not_b_jets_trackCountingHighEffBJetTags->Scale(1. / h_Not_b_jets_trackCountingHighEffBJetTags->GetEntries());
h_Not_b_jets_trackCountingHighEffBJetTags->Draw();
gPad->SetGrid();

TH1F* h_b_jets_trackCountingHighEffBJetTags = (TH1F*) _file1->Get("h_b_jets_trackCountingHighEffBJetTags"); 
h_b_jets_trackCountingHighEffBJetTags->SetLineColor(kGreen);
h_b_jets_trackCountingHighEffBJetTags->Scale(1. / h_b_jets_trackCountingHighEffBJetTags->GetEntries());
h_b_jets_trackCountingHighEffBJetTags->Draw("same");
gPad->SetGrid();


TF1 *f_b_jets_trackCountingHighEffBJetTags = new TF1("f_b_jets_trackCountingHighEffBJetTags","eval_b_trackCountingHighEffBJetTags(x)",0,40);
double maxh = h_Not_b_jets_trackCountingHighEffBJetTags->GetMaximum();
double maxf = f_b_jets_trackCountingHighEffBJetTags->GetMaximum();
TString namef = Form("%f / %f * f_b_jets_trackCountingHighEffBJetTags ",maxh, maxf);
TF1 *f_b_jets_trackCountingHighEffBJetTags_Normalized = new TF1("f_b_jets_trackCountingHighEffBJetTags_Normalized",namef,0,40);
f_b_jets_trackCountingHighEffBJetTags_Normalized->Draw("same");
c_h_b_jets_trackCountingHighEffBJetTags.Print("c_h_b_jets_trackCountingHighEffBJetTags.png");





TCanvas c_h_q_jets_trackCountingHighEffBJetTags;
TH1F* h_q_jets_trackCountingHighEffBJetTags = (TH1F*) _file1->Get("h_q_jets_trackCountingHighEffBJetTags"); 
h_q_jets_trackCountingHighEffBJetTags->SetLineColor(kGreen);
h_q_jets_trackCountingHighEffBJetTags->Scale(1. / h_q_jets_trackCountingHighEffBJetTags->GetEntries());
h_q_jets_trackCountingHighEffBJetTags->Draw();
gPad->SetGrid();

TH1F* h_Not_q_jets_trackCountingHighEffBJetTags = (TH1F*) _file1->Get("h_Not_q_jets_trackCountingHighEffBJetTags"); 
h_Not_q_jets_trackCountingHighEffBJetTags->SetLineColor(kRed);
h_Not_q_jets_trackCountingHighEffBJetTags->Scale(1. / h_Not_q_jets_trackCountingHighEffBJetTags->GetEntries());
h_Not_q_jets_trackCountingHighEffBJetTags->Draw("same");
gPad->SetGrid();


TF1 *f_q_jets_trackCountingHighEffBJetTags = new TF1("f_q_jets_trackCountingHighEffBJetTags","eval_q_trackCountingHighEffBJetTags(x)",0,40);
maxh = h_Not_q_jets_trackCountingHighEffBJetTags->GetMaximum();
maxf = f_q_jets_trackCountingHighEffBJetTags->GetMaximum(0.3,20);
TString namef = Form("%f / %f * f_q_jets_trackCountingHighEffBJetTags ",maxh, maxf);
TF1 *f_q_jets_trackCountingHighEffBJetTags_Normalized = new TF1("f_q_jets_trackCountingHighEffBJetTags_Normalized",namef,0,40);
f_q_jets_trackCountingHighEffBJetTags_Normalized->Draw("same");
c_h_q_jets_trackCountingHighEffBJetTags.Print("c_h_q_jets_trackCountingHighEffBJetTags.png");










TCanvas c_DR_qq;
TH1F* DR_RECO_Not_qq = (TH1F*) _file1->Get("DR_RECO_Not_qq"); 
DR_RECO_Not_qq->SetLineColor(kRed);
DR_RECO_Not_qq->Scale(1. / DR_RECO_Not_qq->GetEntries());
DR_RECO_Not_qq->Draw();
gPad->SetGrid();

TH1F* DR_RECO_qq = (TH1F*) _file1->Get("DR_RECO_qq"); 
DR_RECO_qq->SetLineColor(kGreen);
DR_RECO_qq->Scale(1. / DR_RECO_qq->GetEntries());
DR_RECO_qq->Draw("same");
gPad->SetGrid();


TF1 *f_DR_qq = new TF1("f_DR_qq","eval_DR_qq(x)",0,40);
double maxh = DR_RECO_Not_qq->GetMaximum();
double maxf = f_DR_qq->GetMaximum();
TString namef = Form("%f / %f * f_DR_qq ",maxh, maxf);
TF1 *f_DR_qq_Normalized = new TF1("f_DR_qq_Normalized",namef,0,40);
f_DR_qq_Normalized->Draw("same");
c_DR_qq.Print("c_DR_qq.png");





TCanvas c_DR_bb;
TH1F* DR_RECO_Not_bb = (TH1F*) _file1->Get("DR_RECO_Not_bb"); 
DR_RECO_Not_bb->SetLineColor(kRed);
DR_RECO_Not_bb->Scale(1. / DR_RECO_Not_bb->GetEntries());
DR_RECO_Not_bb->Draw();
gPad->SetGrid();

TH1F* DR_RECO_bb = (TH1F*) _file1->Get("DR_RECO_bb"); 
DR_RECO_bb->SetLineColor(kGreen);
DR_RECO_bb->Scale(1. / DR_RECO_bb->GetEntries());
DR_RECO_bb->Draw("same");
gPad->SetGrid();


TF1 *f_DR_bb = new TF1("f_DR_bb","eval_DR_bb(x)",0,40);
double maxh = DR_RECO_Not_bb->GetMaximum();
double maxf = f_DR_bb->GetMaximum();
TString namef = Form("%f / %f * f_DR_bb ",maxh, maxf);
TF1 *f_DR_bb_Normalized = new TF1("f_DR_bb_Normalized",namef,0,40);
f_DR_bb_Normalized->Draw("same");
c_DR_bb.Print("c_DR_bb.png");






TCanvas c_b_pT;
TH1F* pT_RECO_Not_b = (TH1F*) _file1->Get("pT_RECO_Not_b"); 
pT_RECO_Not_b->SetLineColor(kRed);
pT_RECO_Not_b->Scale(1. / pT_RECO_Not_b->GetEntries());
pT_RECO_Not_b->Draw();
gPad->SetGrid();

TH1F* pT_RECO_b = (TH1F*) _file1->Get("pT_RECO_b"); 
pT_RECO_b->SetLineColor(kGreen);
pT_RECO_b->Scale(1. / pT_RECO_b->GetEntries());
pT_RECO_b->Draw("same");
gPad->SetGrid();


TF1 *f_b_pT = new TF1("f_b_pT","eval_b_pT(x)",0,200);
double maxh = pT_RECO_Not_b->GetMaximum();
double maxf = f_b_pT->GetMaximum();
TString namef = Form("%f / %f * f_b_pT ",maxh, maxf);
TF1 *f_b_pT_Normalized = new TF1("f_b_pT_Normalized",namef,0,200);
f_b_pT_Normalized->Draw("same");
c_b_pT.Print("c_b_pT.png");





TCanvas c_q_pT;
TH1F* pT_RECO_q = (TH1F*) _file1->Get("pT_RECO_q"); 
pT_RECO_q->SetLineColor(kGreen);
pT_RECO_q->Scale(1. / pT_RECO_q->GetEntries());
pT_RECO_q->Draw();
gPad->SetGrid();

TH1F* pT_RECO_Not_q = (TH1F*) _file1->Get("pT_RECO_Not_q"); 
pT_RECO_Not_q->SetLineColor(kRed);
pT_RECO_Not_q->Scale(1. / pT_RECO_Not_q->GetEntries());
pT_RECO_Not_q->Draw("same");
gPad->SetGrid();


TF1 *f_q_pT = new TF1("f_q_pT","eval_q_pT(x)",0,200);
double maxh = pT_RECO_q->GetMaximum();
double maxf = f_q_pT->GetMaximum();
TString namef = Form("%f / %f * f_q_pT ",maxh, maxf);
TF1 *f_q_pT_Normalized = new TF1("f_q_pT_Normalized",namef,0,200);
f_q_pT_Normalized->Draw("same");
c_q_pT.Print("c_q_pT.png");

}




