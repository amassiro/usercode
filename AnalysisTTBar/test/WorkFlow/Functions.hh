

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
TString CommandToROOT = Form("TControlBar *bar_%s = new TControlBar(\"vertical\", \"Draw control panel %s\");\n",vect_name.at(iName),vect_name.at(iName));
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




void AddTab(int iName){
 std::cerr << "vect_name.at(" << iName << ") = " << vect_name.at(iName) << std::endl;
 TString CommandToROOT = Form("TControlBar *bar_%s = new TControlBar(\"vertical\", \"Draw control panel %s\");\n",vect_name.at(iName),vect_name.at(iName));
 gROOT->ProcessLine(CommandToROOT);
 CommandToROOT = Form("gROOT->Add(bar_%s);\n",vect_name.at(iName));
 gROOT->ProcessLine(CommandToROOT);
 
 std::vector< std::string > vect_name_variable_temp;
 for (int iHisto=0; iHisto<counterHistoPerFile; iHisto++){
  std::string name_histo = histos[iHisto]->GetName();
  int pos = name_histo.find("h_"); ///---- h_0_jets_pt
  std::string temp_name_kind;
  if (pos!=string::npos) temp_name_kind = name_histo.substr(2); ///---- 0_jets_pt_sample_possible
   pos = temp_name_kind.find("_");
  if (pos!=string::npos) temp_name_kind = temp_name_kind.substr(pos+1); ///---- jets_pt_sample_possible
   pos = temp_name_kind.find("_");
  std::string end = temp_name_kind;
  std::string middle = temp_name_kind;
  if (pos!=string::npos) middle = temp_name_kind.substr(0,pos); ///---- jets
  if (pos!=string::npos) end = temp_name_kind.substr(pos+1); ///---- pt_sample_possible
  pos = end.find("_");
  if (pos!=string::npos) end = end.substr(0,pos); ///---- pt
    
   
    std::string name_kind = middle;
   
   if (vect_name.at(iName) == name_kind){
    int found = 0;
    for (int iVar=0; iVar<vect_name_variable_temp.size(); iVar++){
     if (vect_name_variable_temp.at(iVar) == end) {
      found = 1;
     }
    }
    if (found == 0) {
     vect_name_variable_temp.push_back(end);
     std::cerr << " end = " << end << std::endl;
     TString CommandToROOT = Form("bar_%s->AddButton(\"%s\",\"{AddVar(%d,%d);}\",\"Add Variable\");\n",vect_name.at(iName),end,iName,vect_name_variable_temp.size()-1);
     gROOT->ProcessLine(CommandToROOT);
    }
   } 
 }
 CommandToROOT = Form("bar_%s->Show();\n",vect_name.at(iName));
 gROOT->ProcessLine(CommandToROOT);
 
}


void AddVar(int iName, int iVariable){
 std::cerr << "vect_name.at(" << iName << ") = " << vect_name.at(iName) << std::endl;
 TString CommandToROOT = Form("TControlBar *bar_%s = new TControlBar(\"vertical\", \"Draw control panel %s\");\n",vect_name.at(iName),vect_name.at(iName));
 gROOT->ProcessLine(CommandToROOT);
 CommandToROOT = Form("gROOT->Add(bar_%s);\n",vect_name.at(iName));
 gROOT->ProcessLine(CommandToROOT);
 std::vector< std::string > vect_name_variable_temp;
 for (int iHisto=0; iHisto<counterHistoPerFile; iHisto++){
  std::string name_histo = histos[iHisto]->GetName();
  int pos = name_histo.find("h_"); ///---- h_0_jets_pt
  std::string temp_name_kind;
  if (pos!=string::npos) temp_name_kind = name_histo.substr(2); ///---- 0_jets_pt_sample_possible
   pos = temp_name_kind.find("_");
  if (pos!=string::npos) temp_name_kind = temp_name_kind.substr(pos+1); ///---- jets_pt_sample_possible
   pos = temp_name_kind.find("_");
  std::string end = temp_name_kind;
  std::string middle = temp_name_kind;
  if (pos!=string::npos) middle = temp_name_kind.substr(0,pos); ///---- jets
   if (pos!=string::npos) end = temp_name_kind.substr(pos+1); ///---- pt_sample_possible
    pos = end.find("_");
   if (pos!=string::npos) end = end.substr(0,pos); ///---- pt
    
    std::string name_kind = middle;
   
   if (vect_name.at(iName) == name_kind){
    int found = 0;
    for (int iVar=0; iVar<vect_name_variable_temp.size(); iVar++){
     if (vect_name_variable_temp.at(iVar) == end) {
      found = 1;
     }
    }
    if (found == 0) {
     vect_name_variable_temp.push_back(end);
    }
   } 
 }
 
 
 std::cerr << "vect_name.at(" << iName << ") = " << vect_name.at(iName) << std::endl;
 CommandToROOT = Form("TControlBar *bar_%s_%s = new TControlBar(\"vertical\", \"Draw control panel %s\");\n",vect_name.at(iName),vect_name_variable_temp.at(iVariable),vect_name_variable_temp.at(iVariable));
 gROOT->ProcessLine(CommandToROOT);
 CommandToROOT = Form("gROOT->Add(bar_%s_%s);\n",vect_name.at(iName),vect_name_variable_temp.at(iVariable));
 gROOT->ProcessLine(CommandToROOT);
 
 for (int iHisto=0; iHisto<counterHistoPerFile; iHisto++){
  std::string name_histo = histos[iHisto]->GetName();
  int pos = name_histo.find("h_"); ///---- h_0_jets_pt
  std::string temp_name_kind;
  if (pos!=string::npos) temp_name_kind = name_histo.substr(2); ///---- 0_jets_pt_sample_possible
   pos = temp_name_kind.find("_");
  if (pos!=string::npos) temp_name_kind = temp_name_kind.substr(pos+1); ///---- jets_pt_sample_possible
   pos = temp_name_kind.find("_");
  std::string end = temp_name_kind;
  std::string middle = temp_name_kind;
  if (pos!=string::npos) middle = temp_name_kind.substr(0,pos); ///---- jets
   if (pos!=string::npos) end = temp_name_kind.substr(pos+1); ///---- pt_sample_possible
    pos = end.find("_");
   if (pos!=string::npos) end = end.substr(0,pos); ///---- pt
    
    std::string name_kind = middle;
   
   if (vect_name.at(iName) == name_kind && vect_name_variable_temp.at(iVariable) == end){
    CommandToROOT = Form("bar_%s_%s->AddButton(\"%s\",\"{Draw(%d);}\",\"disegna\");\n",vect_name.at(iName),vect_name_variable_temp.at(iVariable),histos[iHisto]->GetName(),iHisto);
   gROOT->ProcessLine(CommandToROOT);
  }
 }
 CommandToROOT = Form("bar_%s_%s->Show();\n",vect_name.at(iName),vect_name_variable_temp.at(iVariable));
 gROOT->ProcessLine(CommandToROOT);
 
 
}