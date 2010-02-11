{
 TFile *_file1 = TFile::Open("output/out_TT_General_Calibrator_New.root");
 TTree* outTree1 = (TTree*) _file1->Get("outTree"); 
 
 TCanvas c_After("c_After","c_After",800,600);
 
 
 TH1F htemp0("htemp0","Before",1000,0,200);
 TH1F htemp1("htemp1","After",1000,0,200);
 
 outTree1->Draw("t_M_Reco >> htemp0","t_Cycle_num==0 && t_Indip==0");
 outTree1->Draw("t_M_Reco >> htemp1","t_Cycle_num==1 && t_Indip==0");
 
 htemp0.SetLineColor(kBlue);
 htemp0.SetFillColor(kBlue);
 htemp0.SetFillStyle(3002);
 htemp1.SetLineColor(kRed);
 
 gPad->SetGrid();
 
 TF1 funzPeak("funzPeak","gaus(0)",20,140);
 TF1 funzBkg("funzBkg","pol2(0)",20,140);
 TF1 funz("funz","gaus(0)+pol2(3)",20,140);
 funz.SetParameter(0,10);
 funz.SetParameter(1,80);
 funz.SetParameter(2,10);
 funz.SetParName(1,"Mass");
 funz.SetParName(2,"#sigma");
 htemp0.Fit("funz","RME");
 htemp1.Fit("funz","RME");
 
 funzPeak.SetParameter(0,funz.GetParameter(0));
 funzPeak.SetParameter(1,funz.GetParameter(1));
 funzPeak.SetParameter(2,funz.GetParameter(2));
 funzPeak.SetLineColor(kGreen);
 funzPeak.Draw("same");
 
 gPad->BuildLegend();
 
 
 
 htemp1.Draw();
 htemp0.Draw("same");
 funz.Draw("same");
 funzPeak.Draw("same");
 
 gPad->BuildLegend();
 
 
 
 ///----------------------------------------------------------
 
 TCanvas c_Num("c_Num","c_Num",800,600);

 TH2F* hKK_num = (TH2F*) _file1->Get("hKK_num"); 
 hKK_num->Draw("colz");
 
 
 ///----------------------------------------------------------
 
 TCanvas c_Pt("c_Pt","c_Pt",800,600);
 
 
 TH1F htemp0_Pt("htemp0_Pt","Before Pt",1000,0,4);
 TH1F htemp1_Pt("htemp1_Pt","After Pt",1000,0,4);
 
 outTree1->Draw("(t_pT_Reco / t_pT_MC) >> htemp0_Pt","t_Cycle_num==0 && t_Indip==0");
 outTree1->Draw("(t_pT_Reco / t_pT_MC) >> htemp1_Pt","t_Cycle_num==1 && t_Indip==0");
 
 htemp0_Pt.SetLineColor(kBlue);
 htemp0_Pt.SetFillColor(kBlue);
 htemp0_Pt.SetFillStyle(3002);
 htemp1_Pt.SetLineColor(kRed);
 
 gPad->SetGrid();
 
 htemp1_Pt.Draw();
 htemp0_Pt.Draw("same"); 
 gPad->BuildLegend();
 
 
}




