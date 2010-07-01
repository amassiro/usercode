
void DrawStack(THStack* hs){
 TObjArray * histos = hs->GetStack () ;
 Int_t number = histos->GetEntries();
 TH1F * last = (TH1F*) histos->At (number-1) ;
 last->Draw () ;
 for (int i = number-2 ; i >=0 ; --i) 
 {
  TH1F * histo = (TH1F*) histos->At (i) ;
  Style_t origStyle = std::cout << histo->GetFillStyle () << std::endl ;
  Color_t origColor = std::cout << histo->GetFillColor () << std::endl ;
  TH1F * dummy = histo->Clone () ;
  dummy->SetFillStyle (1001) ; 
  dummy->SetFillColor (10) ;        
  dummy->Draw ("same") ;
  //  histo->SetFillStyle (origStyle) ; 
  //  histo->SetFillColor (origColor) ;        
  histo->Draw ("same") ;
 }
}

