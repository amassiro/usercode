

void Draw(int iHisto){
 TCanvas* cc[1000];
 char nameCanvas[100];
 sprintf(nameCanvas,"cc_%d",iHisto); 
 cc[iHisto] = new TCanvas(nameCanvas,nameCanvas,500,500);
 if (NORMXSECT) hs[iHisto]->Draw();
 else hs[iHisto]->Draw("nostack");
 hs[iHisto]->GetXaxis()->SetTitle(histos[iHisto]->GetName());
 gPad->SetLogy();
 gPad->SetGrid();
 gPad->BuildLegend();
}


void Exit(){
 cout << endl << endl << "Good bye" << endl << endl;
 gApplication->Terminate(0);
}



void Add(int iName){
 std::cerr << "vect_name.at(" << iName << ") = " << vect_name.at(iName) << std::endl;
 TString CommandToROOT = Form("TControlBar *bar_%s = new TControlBar(\"%s\", \"Draw control panel %s\");\n",vect_name.at(iName),vect_name.at(iName),vect_name.at(iName));
 gROOT->ProcessLine(CommandToROOT);
 CommandToROOT = Form("gROOT->Add(bar_%s);\n",vect_name.at(iName));
 gROOT->ProcessLine(CommandToROOT);
 
 for (int iHisto=0; iHisto<counterHistoPerFile; iHisto++){
  std::string name_histo = histos[iHisto]->GetName();
  std::string name_kind = name_histo.substr(4);
  if (vect_name.at(iName) == name_kind){
   CommandToROOT = Form("bar_%s->AddButton(\"%s\",\"{Draw(%d);}\",\"disegna\");\n",vect_name.at(iName),histos[iHisto]->GetName(),iHisto);
   gROOT->ProcessLine(CommandToROOT);
  }
 }
 CommandToROOT = Form("bar_%s->Show();\n",vect_name.at(iName));
 gROOT->ProcessLine(CommandToROOT);
}