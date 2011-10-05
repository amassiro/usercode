

void FillListOfName (THStack stack, std::vector<std::string>* nameSample) {
 nameSample->clear();
 TList * lista = stack.GetHists () ;
 TIter next (lista) ;
 TObject * obj ;
 while ((obj = next ())) {
  nameSample->push_back(obj->GetName ()) ;
 }
 
 for (int iName = 0; iName < nameSample->size(); iName++){
  std::string remword = "_0_0_Tot_temp";
  size_t pos;
  if((pos = nameSample->at(iName).find(remword)) != string::npos) {
   nameSample->at(iName).erase(pos,remword.length());
  }
  std::cout << " [" << iName << "][" << nameSample->size() << "] = " << nameSample->at(iName) << std::endl;
 }
}



TLegend * makeLegend (THStack stack, const std::vector<std::string> & nameSample) { 
 TLegend * leg = new TLegend (0.7, 0.6, 0.9, 0.9, NULL, "brNDC") ;
 leg->SetBorderSize (0) ;
 leg->SetTextFont (42) ;
 leg->SetTextSize (0.04) ;
 leg->SetLineColor (1) ;
 leg->SetLineStyle (1) ;
 leg->SetLineWidth (1) ;
 leg->SetFillColor (0) ;
 leg->SetFillStyle (0) ;
 
 TList * pippo = stack.GetHists () ;
 TIter next (pippo) ;
 TObject * obj ;
 int i=0;
 while ((obj = next ())) {
  TString name = Form("%s",nameSample.at(i).c_str());
  leg->AddEntry (obj,name,"f") ;
  i++;
 }
 return leg ;
}


TLegend * makeLegendTitle (THStack stack) {
  TLegend * leg = new TLegend (0.6, 0.5, 0.95, 0.95, NULL, "brNDC") ;
  leg->SetBorderSize (0) ;
  leg->SetTextFont (42) ;
  leg->SetTextSize (0.04) ;
  leg->SetLineColor (1) ;
  leg->SetLineStyle (1) ;
  leg->SetLineWidth (1) ;
  leg->SetFillColor (0) ;
  leg->SetFillStyle (0) ;

  TList * pippo = stack.GetHists () ;
  TIter next (pippo) ;
  TObject * obj ;
  while ((obj = next ())) {
      leg->AddEntry (obj, obj->GetTitle (),"f") ;
  }
  return leg ;
}


TH1D * PullPlot (TH1D* hDATA, TH1D* hMC, double min, double max) {
 std::string nameNew = "pp_" ;
 nameNew += hDATA->GetName() ;
 nameNew += "_" ;
 nameNew += hMC->GetName() ; 
 TH1D * hPool = (TH1D *) hDATA->Clone (nameNew.c_str ()) ;
 for (int iBin = 0 ; iBin < hDATA->GetNbinsX () ; ++iBin)
 {
  double A = hDATA->GetBinContent (iBin) ;
  double B = hMC->GetBinContent (iBin) ;
  
  double e_A = hDATA->GetBinError (iBin) ;
  double e_B = hMC->GetBinError (iBin) ;
  
  if  (A+B != 0) 
  {
   hPool->SetBinContent (iBin, (A-B)/ (A+B)*2.) ;
   //             hPool->SetBinError (iBin,4. * A /  (A+B) /  (A+B) * sqrt (A+B)) ;
   /*
    *             e_A * d/dA (0.5 * (A-B)/(A+B)) =
    *             e_A * 0.5 * ( d/d(A-B) (A-B)/(A+B) * d/dA (A-B) +
    *                           d/d(A+B) (A-B)/(A+B) * d/dA (A+B) ) = 
    */                       
   double d_A = e_A * 0.5 * ( 1./(A+B) - (A-B)/( (A+B)*(A+B) ) ) ;                            
   double d_B = e_B * 0.5 * ( -1./(A+B) + (A-B)/( (A+B)*(A+B) ) ) ;
   double d_tot = sqrt (d_A * d_A + d_B * d_B) ;                     
   hPool->SetBinError (iBin, d_tot) ;
  }
 }
 
 hPool->SetLineColor (kBlack) ;
 hPool->SetLineWidth (1) ;
 hPool->SetMarkerColor (kBlack) ;
 hPool->SetMarkerStyle (20) ;
 hPool->SetMarkerSize (1) ;
 hPool->GetXaxis ()->SetTitle (hMC->GetXaxis ()->GetTitle ()) ; 
 hPool->GetYaxis ()->SetTitle ("2 (DATA-MC)/ (DATA+MC)") ; 
 hPool->GetYaxis ()->SetRangeUser (min, max) ; 
 return hPool;
}


TH1D * PullPlotAsRatio (TH1D* hDATA, TH1D* hMC, double min, double max) {
 std::string nameNew = "ppR_" ;
 nameNew += hDATA->GetName() ;
 nameNew += "_" ;
 nameNew += hMC->GetName() ; 
 TH1D * hPool = (TH1D *) hMC->Clone (nameNew.c_str ()) ;
 for (int iBin = 0 ; iBin < hDATA->GetNbinsX () ; ++iBin)
 {
  double A = hDATA->GetBinContent (iBin) ;
  double B = hMC->GetBinContent (iBin) ;
  
  double e_A = hDATA->GetBinError (iBin) ;
  double e_B = hMC->GetBinError (iBin) ;
  
  if  (B != 0) 
  {
   hPool->SetBinContent (iBin, A/B) ;
   //             hPool->SetBinError (iBin,4. * A /  (A+B) /  (A+B) * sqrt (A+B)) ;
   /*
    *             f = A / B
    *             d_A = e_A * df/dA
    *             d_B = e_B * df/dB = e_B * (-A/B^2) 
    */                       
   double d_A = e_A / B ;
   double d_B = e_B * A / (B * B) ;
   double d_tot = sqrt (d_A * d_A + d_B * d_B) ;                     
   hPool->SetBinError (iBin, d_tot) ;
  }
 }
 hPool->SetLineColor (kBlack) ;
 hPool->SetLineWidth (1) ;
 hPool->SetMarkerColor (kBlack) ;
 hPool->SetMarkerStyle (20) ;
 hPool->SetMarkerSize (1) ;
 hPool->GetXaxis ()->SetTitle (hMC->GetXaxis ()->GetTitle ()) ; 
 hPool->GetYaxis ()->SetTitle ("data/mc") ; 
 hPool->GetYaxis ()->SetRangeUser (min, max) ; 
 return hPool ;
}


void PrintHContent (TH1D * histo) {
 for (int iBin = 0 ; iBin < histo->GetNbinsX () ; ++iBin)
 {
  double A = histo->GetBinContent (iBin) ;
  std::cout << A << ", " <<std::endl;
 }
 std::cout<< "\n"<<std::endl;    
}




TH1D* DynamicalRebinHisto ( TH1D * original_Histo, TH1D* rebinned_Histo, std::vector<float>  binning,  TString &nameHisto, bool isDATA, bool isDivide) {
 
 int original_iBin=0;
 
 std::vector<float> Bin_Counts;
 std::vector<float> Bin_Errors;
 std::vector<float> edge;
 
 if (binning.size()>990) {
  std::cerr << "Error: Invalid Number of Bins" << std::endl;
  return(0);
  
 }
 
 Float_t Bin_size[1000];
 
 edge.push_back(original_Histo->GetXaxis()->GetBinLowEdge(1));
 binning.at(0) = original_Histo->GetXaxis()->GetBinLowEdge(1);
 
 if (binning.at(binning.size()-1) > original_Histo->GetXaxis()->GetBinUpEdge(original_Histo->GetNbinsX())) {
  std::cerr << "Error: Invalid Max Bin" << std::endl;
  return(0);
 }
 
 if (binning.at(binning.size()-1) != original_Histo->GetXaxis()->GetBinUpEdge(original_Histo->GetNbinsX())) {
  binning.push_back(original_Histo->GetXaxis()->GetBinUpEdge(original_Histo->GetNbinsX()));
 }
 
 
 for(int iBin=0; iBin<binning.size()-1; iBin++) {
  Bin_Counts.push_back(0);
  Bin_Errors.push_back(0);
  if (fabs(binning.at(iBin+1)-binning.at(iBin)) < original_Histo->GetXaxis()->GetBinWidth(original_iBin+1)) { 
   std::cerr << "Error: Invalid Bin Width:: iBin = " << iBin << " ==> " << fabs(binning.at(iBin+1)-binning.at(iBin)) << " < " << original_Histo->GetXaxis()->GetBinWidth(original_iBin+1) << std::endl;
   return(0);
  }
  while(binning.at(iBin+1) >= original_Histo->GetXaxis()->GetBinUpEdge(original_iBin+1) && original_iBin <= original_Histo->GetNbinsX()) {
   Bin_Counts.at(iBin)=Bin_Counts.at(iBin)+fabs(original_Histo->GetBinContent(original_iBin+1));
   Bin_Errors.at(iBin)=sqrt(Bin_Errors.at(iBin)*Bin_Errors.at(iBin)+original_Histo->GetBinError(original_iBin+1)*original_Histo->GetBinError(original_iBin+1));
   original_iBin++;
  }
  
  
  if (original_iBin != original_Histo->GetNbinsX())
   edge.push_back(original_Histo->GetXaxis()->GetBinLowEdge(original_iBin+1));
  
  if (original_iBin == original_Histo->GetNbinsX())
   edge.push_back(original_Histo->GetXaxis()->GetBinUpEdge(original_iBin));
  
  if (isDivide)
  {  
   Bin_Counts.at(iBin) = Bin_Counts.at(iBin)/(fabs(edge.at(iBin+1)-edge.at(iBin)));
   Bin_Errors.at(iBin) = Bin_Errors.at(iBin)/(fabs(edge.at(iBin+1)-edge.at(iBin)));
  }
  else{
   Bin_Counts.at(iBin) = Bin_Counts.at(iBin);
   Bin_Errors.at(iBin) = Bin_Errors.at(iBin);
  }
  
 }
 
 binning.clear();
 
 for(int iBin=0; iBin<edge.size();iBin++)
 {
  Bin_size[iBin]=edge.at(iBin);
  binning.push_back(edge.at(iBin)); 
 }
 
 rebinned_Histo = new TH1D(nameHisto,original_Histo->GetTitle(),edge.size()-1,Bin_size);
 
 if(!isDATA || (isDATA && isDivide))
 {  
  for(int iBin=0; iBin<edge.size()-1;iBin++)
  {rebinned_Histo->SetBinContent(iBin+1,fabs(Bin_Counts.at(iBin)));
  rebinned_Histo->SetBinError(iBin+1,fabs(Bin_Errors.at(iBin)));
  }
 }
 
 if(isDATA && !isDivide)
 {
  for( int iBin=0; iBin<edge.size()-1; iBin++)
  { 
   for(int iTime=0; iTime<Bin_Counts.at(iBin); iTime++)
   {
    rebinned_Histo->Fill(rebinned_Histo->GetBinCenter(iBin+1));
   }
  }
 }
 
 rebinned_Histo->SetMarkerStyle(original_Histo->GetMarkerStyle());
 rebinned_Histo->SetMarkerColor(original_Histo->GetMarkerColor());
 rebinned_Histo->SetLineColor(original_Histo->GetLineColor());
 rebinned_Histo->SetFillStyle(original_Histo->GetFillStyle());
 rebinned_Histo->SetFillColor(original_Histo->GetFillColor());
 
 return(rebinned_Histo); 
}  


TH1D* DynamicalRebinHisto ( TH1D* original_Histo, TH1D* rebinned_Histo, std::vector<float>  binning, bool isDATA, bool isDivide) {
//  TRandom3* index = new TRandom3();
//  index -> SetSeed(0);
 TString name;
 
 do {
  name = Form("%s_Rebinned_%d_%d",original_Histo->GetName(),int (gRandom->Uniform(0,100000)), int (gRandom->Uniform(0,100000)));
//   std::cout << " name = " << name.Data() << std::endl;
 } 
 while (gROOT->FindObject(name));
  
 rebinned_Histo = DynamicalRebinHisto(original_Histo,rebinned_Histo,binning,name, isDATA, isDivide); 
 return (rebinned_Histo);
}



THStack* DynamicalRebinStack ( THStack * original_Stack,THStack* rebinned_Stack, std::vector<float> binning, bool isDATA, bool isDivide) {
 TRandom3* index= new TRandom3();
 index->SetSeed(0);
 TString name =Form("%s_Rebinned_%d",original_Stack->GetName(),int(index->Uniform(0,10000000)));
 
 TObjArray* histos = original_Stack->GetStack () ;
 
 rebinned_Stack = new THStack();
 
 for( int iHisto=0; iHisto< histos->GetEntries(); iHisto++)
 {
  if(iHisto==0)
  {  
   TH1D* original_Histo1 = (TH1D*) histos->At(iHisto);
   TH1D* rebinned_Histo1;
   name = name + Form("_%d",iHisto);
   rebinned_Histo1 = DynamicalRebinHisto(original_Histo1,rebinned_Histo1,binning,name, isDATA, isDivide);
   rebinned_Stack->Add(rebinned_Histo1);
  }
  
  else{
   TH1D* original_Histo1 = (TH1D*) histos->At(iHisto-1);
   TH1D* original_Histo2 = (TH1D*) histos->At(iHisto);
   TH1D* rebinned_Histo1;
   TH1D* rebinned_Histo2;
   TString name1 = name + Form("_%d",iHisto);
   TString name2 = name + Form("_%d_%d",iHisto,iHisto);
   rebinned_Histo1 = DynamicalRebinHisto(original_Histo1,rebinned_Histo1,binning,name1, isDATA, isDivide);
   rebinned_Histo2 = DynamicalRebinHisto(original_Histo2,rebinned_Histo2,binning,name2, isDATA, isDivide);
   rebinned_Histo2->Add(rebinned_Histo1,-1);
   rebinned_Stack->Add(rebinned_Histo2);
  }
  
 }
 
 return(rebinned_Stack);
}


 
/*TH2D* DynamicalRebinHisto2D( TH2D* original_Histo, TH2D* rebinned_Histo, std::vector<float>  binningX, std::vector<float>  binningY, bool isDATA, bool isDivide)  
{
  TRandom3* index= new TRandom3();
  index->SetSeed(0);
  TString name_Rebinned_px =Form("%s_Rebinned_px_%d",original_Histo->GetName(),int(index->Uniform(0,1000000)));
  TString name_Rebinned_py =Form("%s_Rebinned_py_%d",original_Histo->GetName(),int(index->Uniform(0,1000000)));
  
  TString name_px=Form("%s_px",original_Histo->GetName());
  TString name_py=Form("%s_py",original_Histo->GetName());

  TH1D* original_Histo_px = original_Histo->ProjectionX(name_px,1,original_Histo->GetNbinsX(),"e");
  TH1D* original_Histo_py = original_Histo->ProjectionX(name_py,1,original_Histo->GetNbinsY(),"e");
  TH1D* rebinned_Histo_px;
  TH1D* rebinned_Histo_py;
  
  rebinned_Histo_px=DynamicalRebinHisto(original_Histo_px,rebinned_Histo_px,binningX,name_Rebinned_px, isDATA, isDivide);
  rebinned_Histo_py=DynamicalRebinHisto(original_Histo_py,rebinned_Histo_py,binningY,name_Rebinned_py, isDATA, isDivide);
 
  Float_t Bin_sizeX[1000];
  Float_t Bin_sizeY[1000];
 
  for(int iBin=0; iBin<binningX.size();iBin++)
  {
   Bin_sizeX[iBin]=binningX.at(iBin);
  }
   
  for(int iBin=0; iBin<binningY.size();iBin++)
  {
   Bin_sizeY[iBin]=binningY.at(iBin);
  }
  
  TString name =Form("%s_Rebinned_%d",original_Histo->GetName(),int(index->Uniform(0,1000000)));
  
  rebinned_Histo= new TH2D(name,original_Histo->GetTitle(),binningX.size()-1,Bin_sizeX,binningY.size()-1,Bin_sizeY);
  
 for(int iBinX=0; iBinX<rebinned_Histo->GetNbinsX(); iBinX++)
  {
    for(int iBinY=0; iBinY<rebinned_Histo->GetNbinsY(); iBinY++)
    {
      int x=rebinned_Histo->GetXaxis()->GetBinCenter(iBinX+1);
      int y=rebinned_Histo->GetYaxis()->GetBinCenter(iBinY+1);
      int binglobal=rebinned_Histo->FindBin(x,y);
      rebinned_Histo->GetBinXYZ(binglobal,x,y);
//       rebinned_Histo->SetBinContent(x,y,
    }
  }
      
  
  
  return(rebinned_Histo);
 }
 */
 
/*
 THStack* DynamicalRebinStack2D ( THStack * original_Stack,THStack* rebinned_Stack, std::vector<float> binningX, std::vector<float> binningY, bool isDATA, bool isDivide)  
{
  TString name =Form("%s_Rebinned",original_Stack->GetName());
  
  TObjArray* histos = original_Stack->GetStack () ;
  
  rebinned_Stack = new THStack();
  
  for( int iHisto=0; iHisto< histos->GetEntries(); iHisto++)
  {
    if(iHisto==0)
    {  
     TH2D* original_Histo1 = (TH2D*) histos->At(iHisto);
     TH2D* rebinned_Histo1;
     rebinned_Histo1=DynamicalRebinHisto2D(original_Histo1,rebinned_Histo1,binningX,binningY,isDATA, isDivide);
     rebinned_Stack->Add(rebinned_Histo1);
    }
    
    else{
           TH2D* original_Histo1 = (TH2D*) histos->At(iHisto-1);
           TH2D* original_Histo2 = (TH2D*) histos->At(iHisto);
	   TH2D* rebinned_Histo1;
           TH2D* rebinned_Histo2;
	   rebinned_Histo1=DynamicalRebinHisto2D(original_Histo1,rebinned_Histo1,binningX,binningY, isDATA, isDivide);
           rebinned_Histo2=DynamicalRebinHisto2D(original_Histo2,rebinned_Histo2,binningX,binningY, isDATA, isDivide);
	   rebinned_Histo2->Add(rebinned_Histo1,-1);
	   rebinned_Stack->Add(rebinned_Histo2);
    }
      
  }
  
  return(rebinned_Stack);
 }
*/