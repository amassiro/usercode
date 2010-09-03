{
 char *nameSample[1000];
 char *nameSamplePrefix[1000];
 char *nameSampleTree[1000];
 
 char* xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("test/Spring10/samples.txt");
 std::string buffer;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){
    std::stringstream line( buffer );       
    nameSample[numberOfSamples] = new char [1000];
    line >> nameSample[numberOfSamples]; 
    std::cout << nameSample[numberOfSamples] << " ";
    
    nameSamplePrefix[numberOfSamples] = new char [1000];
    line >> nameSamplePrefix[numberOfSamples];
    
    nameSampleTree[numberOfSamples] = new char [1000];
    line >> nameSampleTree[numberOfSamples];
    
    xsection[numberOfSamples] = new char [1000];
    line >> xsection[numberOfSamples]; 
    std::cout << xsection[numberOfSamples] << " ";
    std::cout << std::endl;
    numberOfSamples++;
   } 
  }
 }
 
 for (int iSample = 0; iSample < numberOfSamples; iSample++){
  TString Command2Line = Form("./bin/FinalSelection_Producer.exe test/Spring10/dir_cfg_SelectorLepton/SelectorLeptons_%s.cfg",nameSample[iSample]);
  gSystem->Exec(Command2Line);
 }
}


