


TLegend * makeLegend (THStack stack, const std::vector<std::string> & nameSample)
{
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
  int i=0;
  while ((obj = next ()))
    { TString name =Form("%s",nameSample.at(i).c_str());
      leg->AddEntry (obj,name,"f") ;
      i++;
    }
  return leg ;

}


TLegend * makeLegendTitle (THStack stack)
{
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
  while ((obj = next ()))
    {
      leg->AddEntry (obj, obj->GetTitle (),"f") ;
    }
  return leg ;

}


TH1F * PullPlot (TH1F* hDATA, TH1F* hMC, double min, double max)
  {
     std::string nameNew = "pp_" ;
     nameNew += hDATA->GetName() ;
     nameNew += "_" ;
     nameNew += hMC->GetName() ; 
     TH1F * hPool = (TH1F *) hDATA->Clone (nameNew.c_str ()) ;
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
             e_A * d/dA (0.5 * (A-B)/(A+B)) =
             e_A * 0.5 * ( d/d(A-B) (A-B)/(A+B) * d/dA (A-B) +
                           d/d(A+B) (A-B)/(A+B) * d/dA (A+B) ) = 
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


TH1F * PullPlotAsRatio (TH1F* hDATA, TH1F* hMC, double min, double max)
  {
    std::string nameNew = "ppR_" ;
    nameNew += hDATA->GetName() ;
    nameNew += "_" ;
    nameNew += hMC->GetName() ; 
    TH1F * hPool = (TH1F *) hMC->Clone (nameNew.c_str ()) ;
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
             f = A / B
             d_A = e_A * df/dA
             d_B = e_B * df/dB = e_B * (-A/B^2) 
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


void PrintHContent (TH1F * histo)
  {
    for (int iBin = 0 ; iBin < histo->GetNbinsX () ; ++iBin)
       {
         double A = histo->GetBinContent (iBin) ;
         std::cout << A << ", " <<std::endl;
       }
    std::cout<< "\n"<<std::endl;    
  }




TH1F* DynamicalRebinHisto ( TH1F * original_Histo, TH1F* rebinned_Histo, const std::vector<float> & binning, const TString &nameHisto)
{
 int original_iBin=0;

 std::vector<float> Bin_Counts;
 std::vector<float> Bin_Errors;
 std::vector<float> edge;
 
 if(binning.size()>990)
 {
      std::cerr<<"Error: Invalid Number of Bins"<<std::endl;
      return(0);
      
   }
 Float_t Bin_size[1000];
 
 edge.push_back(original_Histo->GetXaxis()->GetBinLowEdge(1));
 binning.at(0)=original_Histo->GetXaxis()->GetBinLowEdge(1);
 
 if(binning.at(binning.size()-1) > original_Histo->GetXaxis()->GetBinUpEdge(original_Histo->GetNbinsX()))
    {
      std::cerr<<"Error: Invalid Max Bin"<<std::endl;
      return(0);
    }
    
 if(binning.at(binning.size()-1) != original_Histo->GetXaxis()->GetBinUpEdge(original_Histo->GetNbinsX()))
 {
   binning.push_back(original_Histo->GetXaxis()->GetBinUpEdge(original_Histo->GetNbinsX()));
  }
  
 
 for(int iBin=0; iBin<binning.size()-1; iBin++)
 {
   Bin_Counts.push_back(0);
   Bin_Errors.push_back(0);
   if(fabs(binning.at(iBin+1)-binning.at(iBin))< original_Histo->GetXaxis()->GetBinWidth(original_iBin+1))
   { 
     std::cerr<<"Error: Invalid Bin Width"<<std::endl;
     return(0);
    }
   while(binning.at(iBin+1) >= original_Histo->GetXaxis()->GetBinUpEdge(original_iBin+1) && original_iBin<=original_Histo->GetNbinsX())
   { 
     Bin_Counts.at(iBin)=Bin_Counts.at(iBin)+original_Histo->GetBinContent(original_iBin+1);
     Bin_Errors.at(iBin)=sqrt(Bin_Errors.at(iBin)*Bin_Errors.at(iBin)+original_Histo->GetBinError(original_iBin+1)*original_Histo->GetBinError(original_iBin+1));
     original_iBin++;
    }
   
   
   if(original_iBin !=original_Histo->GetNbinsX())
    edge.push_back(original_Histo->GetXaxis()->GetBinLowEdge(original_iBin+1));
   
   if(original_iBin ==original_Histo->GetNbinsX())
    edge.push_back(original_Histo->GetXaxis()->GetBinUpEdge(original_iBin));
   
    Bin_Counts.at(iBin)=Bin_Counts.at(iBin)/(fabs(edge.at(iBin+1)-edge.at(iBin)));
    Bin_Errors.at(iBin)=Bin_Errors.at(iBin)/(fabs(edge.at(iBin+1)-edge.at(iBin)));
//    std::cout<<" Counts.at(" <<iBin<< ")= "<<Bin_Counts.at(iBin)<<"  edge.at("<<iBin<<")=" <<edge.at(iBin)<<std::endl;
 }
 

 for(int iBin=0; iBin<edge.size();iBin++)
 {
   Bin_size[iBin]=edge.at(iBin);
   }

 rebinned_Histo= new TH1F(nameHisto,original_Histo->GetTitle(),edge.size()-1,Bin_size);


 for(int iBin=0; iBin<edge.size()-1;iBin++)
 {rebinned_Histo->SetBinContent(iBin+1,Bin_Counts.at(iBin));
  rebinned_Histo->SetBinError(iBin+1,Bin_Errors.at(iBin));
 }

rebinned_Histo->SetMarkerStyle(original_Histo->GetMarkerStyle());
rebinned_Histo->SetMarkerColor(original_Histo->GetMarkerColor());
rebinned_Histo->SetLineColor(original_Histo->GetLineColor());
rebinned_Histo->SetFillStyle(original_Histo->GetFillStyle());
rebinned_Histo->SetFillColor(original_Histo->GetFillColor());

return(rebinned_Histo); 
}  


TH1F* DynamicalRebinHisto ( TH1F * original_Histo, TH1F* rebinned_Histo, const std::vector<float> & binning)  
{
  TString name =Form("%s_Rebinned",original_Histo->GetName());
  rebinned_Histo=DynamicalRebinHisto(original_Histo,rebinned_Histo,binning,name);  
  return(rebinned_Histo);
 }
 
 
 
 THStack* DynamicalRebinStack ( THStack * original_Stack, const std::vector<float> & binning)  
{
  TString name =Form("%s_Rebinned",original_Stack->GetName());
  
  THStack *rebinned_Stack= new THStack();
  
  TObjArray* histos = original_Stack->GetStack () ;
  
  for( int iHisto=0; iHisto< histos->GetEntries(); iHisto++)
  {
    if(iHisto==0)
    {  
     TH1F* original_Histo1 = (TH1F*) histos->At(iHisto);
     TH1F* rebinned_Histo1;
     rebinned_Histo1=DynamicalRebinHisto(original_Histo1,rebinned_Histo1,binning,name);
     rebinned_Stack->Add(rebinned_Histo1);
    }
    
    else{
           TH1F* original_Histo1 = (TH1F*) histos->At(iHisto-1);
           TH1F* original_Histo2 = (TH1F*) histos->At(iHisto);
	   TH1F* rebinned_Histo1;
           TH1F* rebinned_Histo2;
	   rebinned_Histo1=DynamicalRebinHisto(original_Histo1,rebinned_Histo1,binning,name);
           rebinned_Histo2=DynamicalRebinHisto(original_Histo2,rebinned_Histo2,binning,name);
	   rebinned_Histo1->Sumw2();
	   rebinned_Histo2->Sumw2();
	   rebinned_Histo2->Add(rebinned_Histo1,-1);
	   rebinned_Stack->Add(rebinned_Histo2);
    }
      
  }
  
  return(rebinned_Stack);
 }