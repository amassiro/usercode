 
 {
  TCanvas cc("cc","cc",800,500);
  
  TH1F pt_ele((TH1F) _file0->Get("pt_ele"));
  TH1F pt_ele_nu((TH1F) _file0->Get("pt_ele_nu"));
  TH1F pt_mu((TH1F) _file0->Get("pt_mu"));
  TH1F pt_mu_nu((TH1F) _file0->Get("pt_mu_nu"));
  TH1F pt_d_had((TH1F) _file0->Get("pt_d_had"));
  TH1F pt_u_had((TH1F) _file0->Get("pt_u_had"));
  TH1F pt_s_had((TH1F) _file0->Get("pt_s_had"));
  TH1F pt_c_had((TH1F) _file0->Get("pt_c_had"));
  
  pt_ele.SetLineColor(kRed);
  pt_ele_nu.SetLineColor(kBlue);
  pt_mu.SetLineColor(kRed+1);
  pt_mu_nu.SetLineColor(kBlue+1);
  pt_d_had.SetLineColor(kRed+2);
  pt_u_had.SetLineColor(kBlue+2);
  pt_s_had.SetLineColor(kRed+3);
  pt_c_had.SetLineColor(kBlue+3);
  
  pt_ele.SetFillColor(2);
  pt_ele_nu.SetFillColor(4);
  pt_mu.SetFillColor(3);
  pt_mu_nu.SetFillColor(5);
  pt_d_had.SetFillColor(kBlue);
  pt_u_had.SetFillColor(kBlue+1);
  pt_s_had.SetFillColor(kBlue+2);
  pt_c_had.SetFillColor(kBlue+3);
  
  pt_ele.SetFillStyle(0000);
  pt_ele_nu.SetFillStyle(0000);
  pt_mu.SetFillStyle(0000);
  pt_mu_nu.SetFillStyle(0000);
  pt_d_had.SetFillStyle(0000);
  pt_u_had.SetFillStyle(0000);
  pt_s_had.SetFillStyle(0000);
  pt_c_had.SetFillStyle(0000);
  
  pt_ele.DrawNormalized();
  pt_ele_nu.DrawNormalized("same");
  pt_mu.DrawNormalized("same");
  pt_mu_nu.DrawNormalized("same");
  pt_d_had.DrawNormalized("same");
  pt_u_had.DrawNormalized("same");
  pt_s_had.DrawNormalized("same");
  pt_c_had.DrawNormalized("same");
  
  
  
  TLegend* leg = new TLegend(0.5,0.7,0.9,0.9);
  leg->AddEntry(&pt_ele,"p_{T} ele","f");
  leg->AddEntry(&pt_ele_nu,"p_{T} ele #nu","f");
  leg->AddEntry(&pt_mu,"p_{T} mu","f");
  leg->AddEntry(&pt_mu_nu,"p_{T} mu #nu","f");
  leg->AddEntry(&pt_d_had,"p_{T} d had","f");
  leg->AddEntry(&pt_u_had,"p_{T} u had","f");
  leg->AddEntry(&pt_s_had,"p_{T} s had","f");
  leg->AddEntry(&pt_c_had,"p_{T} c had","f");
  leg->Draw();
  
  cc.SaveAs("cc.png");
  
  
  
  
  
  
  
  
  
  TCanvas cc2("cc2","cc2",800,500);
  
  TH1F pt_lept((TH1F) _file0->Get("pt_lept"));
  TH1F pt_had((TH1F) _file0->Get("pt_had"));
  
  pt_lept.SetLineColor(kRed);
  pt_had.SetLineColor(kGreen);
   
  pt_lept.SetFillColor(kRed);
  pt_had.SetFillColor(kGreen);
  
  pt_lept.SetFillStyle(0000);
  pt_had.SetFillStyle(0000);
  
  pt_lept.DrawNormalized();
  pt_had.DrawNormalized("same");
  
  
  
  TLegend* leg2 = new TLegend(0.5,0.7,0.9,0.9);
  leg2->AddEntry(&pt_lept,"p_{T} lept","f");
  leg2->AddEntry(&pt_had,"p_{T} had","f");
  leg2->Draw();
  
 }
 
 
 