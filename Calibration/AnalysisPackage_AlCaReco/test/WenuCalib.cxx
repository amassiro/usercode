{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  


  TFile *fdata = TFile::Open("output/Wenu_DATA_4analysis.root");  

  TFile *fmc   = TFile::Open("output/Wenu_MC_4analysis.root");  
 
  
  TH1F *hWd = (TH1F*)fdata->Get("hetEB") ;

  float s;
  TH1F *hWM[200];
  char hname[100];
  for (int i = 0; i < 200; i++){
    sprintf(hname,"hetEBscaled_%d",i);
    hWM[i] = (TH1F*)fmc->Get(hname) ;
    s = float(hWd->GetSumOfWeights())/float(hWM[i]->GetSumOfWeights());
    hWM[i]->Sumw2();
    hWM[i]->Scale(s);
  }
  

  float alpha;
  TGraph *gChi = new TGraph();
  for (int i=0;i<200;i++){
    float chi2=0;
    for (int j=1;j<26;j++){
      float yy = hWd->GetBinContent(j);
      float ff = hWM[i]->GetBinContent(j);
      if (ff!=0) chi2 += ( (yy-ff)*(yy-ff)/ff );
      // cout << ff << " " << yy << " " << chi2 << endl;
    }
    alpha = (i-100.)/1000.;
    gChi->SetPoint(i,alpha,chi2);
  }
/*

  TGraph *gChi = new TGraph();
  for (int i=0;i<200;i++){
    float chi2 = hWM[i]->KolmogorovTest(hWd,"M");    
    float alpha = (i-100.)/1000.;
    gChi->SetPoint(i,alpha,chi2);
  }
*/

  TCanvas *cc = new TCanvas("cc","cc"); 
  cc->Divide(2,1);

  cc->cd(2);
  gChi->SetMarkerStyle(7);
  gChi->SetMarkerColor(2);
  gChi->Draw("AP");
 
  float xmin = gChi->GetMean();
  TF1 *myfit = new TF1("myfit","pol2",-1,1);
  myfit->SetRange(-0.07,0.00);
  gChi->Fit("myfit","sameQRM");
  float a=myfit->GetParameter(0);
  float b=myfit->GetParameter(1);
  float c=myfit->GetParameter(2);
  gChi->GetXaxis()->SetTitle("Relative scale variation");
  gChi->GetYaxis()->SetTitle("#chi^{2}");
  gPad->Update();

  alpha = -b/2./c;
  
  std::cerr << " alpha = " << alpha << " bin best = " << (alpha-(-0.1) ) / 0.2 * 200 << std::endl;
  char hnameBest[100];
  sprintf(hnameBest,"hetEBscaled_%d",(alpha-(-0.1) ) / 0.2 * 200);
  TH1F *hWm = (TH1F*)fmc->Get(hnameBest) ;
  float s = float(hWd->GetSumOfWeights())/float(hWm->GetSumOfWeights());
  hWm->Scale(s);
  
  cc->cd(1);
  hWm->SetFillColor(2); 
  hWm->SetFillStyle(3004); 
  hWd->SetMarkerStyle(20);
  hWd->GetXaxis()->SetTitle("Electron E_{T} (GeV)");
  hWd->GetYaxis()->SetTitle("Events/4 GeV");

  hWd->Draw("e");
  hWm->Draw("BARsame");
  hWd->Draw("esame");


  // verdice parabola e deltachi = 1
  float mW = 80.4*(1+(-b/2./c));
  float chiMin = a-b*b/(4.*c);
  float deltachi = chiMin+1.;
  float dmp = (-b+sqrt(b*b-4.*c*(a-deltachi)))/2./c;
  float dmm = (-b-sqrt(b*b-4.*c*(a-deltachi)))/2./c;

  dmp = b/2./c+dmp ; 
  dmm = b/2./c+dmm ; 

  cout << endl;
  cout << "m_W = " << mW << " +/- " << 80.4*dmm << " GeV/c^2" << endl;
  cout << "relative scale = " << 1.-b/2./c << " +/- " << dmm << endl;

  char massa[80],relsca[80];
  sprintf (massa,"m_{W} = %.1f +/- %.1f GeV/c^{2}",mW,80.4*dmp);
  sprintf (relsca,"scale = %.3f +/- %.3f ",1-b/2./c,dmp);

  TLatex tmm(-0.075,11.5,massa);
  TLatex tss(-0.075,11.0,relsca);

  tmm->Draw();
  tss->Draw();

}

