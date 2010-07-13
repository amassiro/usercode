void CheckButton(){
 if (iEvent==0) {
  bar->SetButtonState("Prev", 3 );
 }
 else {
  bar->SetButtonState("Prev", 0 );
 }
 
 if (iEvent==myTree->GetEntries()) {
  bar->SetButtonState("Next", 3 );
 }
 else {
  bar->SetButtonState("Next", 0 );
 }
 
}


void Next(){
 cout << endl << endl << "Next electron" << endl << endl;
 if (myTree->GetEntries() > iEvent) iEvent++;
 else {
  std::cerr << " =================== " << std::endl;
  std::cerr << " ==== max found ====" << std::endl;
  std::cerr << " =================== " << std::endl;
 }
 CheckButton();
 Draw();
}

void Prev(){
 cout << endl << endl << "Previous electron" << endl << endl;
 if (iEvent>0) iEvent--;
 else {
  std::cerr << " =================== " << std::endl;
  std::cerr << " ==== min found ====" << std::endl;
  std::cerr << " =================== " << std::endl;
 }
 CheckButton();
 Draw();
}


void Draw(){
 std::cerr << "iEvent = " << iEvent << ":" << myTree->GetEntries() << std::endl;
 myTree->GetEntry(iEvent);
 TString nameCut = Form("");
 if (EoP<3 && ET>18){
  ccSS->cd(1);
  h2ShowerShapeEB->Draw("colz");
  gPad->SetGrid();
  if (h2ShowerShapeEB->GetEntries()>0) gPad->SetLogz();
  else  gPad->SetLogz(0);
  
  //   ccSS->cd(3);
  //   h2ShowerShapeEB->Draw("surf2 CYL");
  
  
  ccSS->cd(2);
  h2ShowerShapeEE->Draw("colz");
  gPad->SetGrid();
  if (h2ShowerShapeEE->GetEntries()>0) gPad->SetLogz();
  else  gPad->SetLogz(0);
  
  std::cerr << " Ele ET  = " << ET << std::endl;
  std::cerr << " Ele pT  = " << pT << std::endl;
  std::cerr << " Ele eta = " << Eta << std::endl;
  std::cerr << " Ele EoP = " << EoP << std::endl;
  
 }
 else {
  std::cerr << "Not good ..." << std::endl;
 }
}



void Exit(){
 cout << endl << endl << "Good bye" << endl << endl;
 gApplication->Terminate(0);
}



