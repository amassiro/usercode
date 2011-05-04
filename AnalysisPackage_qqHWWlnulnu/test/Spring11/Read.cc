int ReadFile(char nameFile[1000],char* nameSample[1000], char* nameHumanReadable[1000], char* xsectionName[1000]){
 
 int numberOfSamples = 0;
 std::ifstream inFile(nameFile);
 std::string buffer; 
 while(!inFile.eof()){
  getline(inFile,buffer);
  if (buffer != ""){ ///---> save from empty line at the end!
   if (buffer.at(0) != '#'){ 
    std::stringstream line( buffer );       
    nameSample[numberOfSamples] = new char [10000];
    line >> nameSample[numberOfSamples]; 
    std::cout << nameSample[numberOfSamples] << " ";
    
    xsectionName[numberOfSamples] = new char [10000];
    line >> xsectionName[numberOfSamples]; 
    std::cout << xsectionName[numberOfSamples] << " ";
    
    nameHumanReadable[numberOfSamples] = new char [10000];
    line >> nameHumanReadable[numberOfSamples]; 
    std::cout << nameHumanReadable[numberOfSamples] << " ";
    
    std::cout << std::endl;
    numberOfSamples++;
   } 
  }
 }
 
 return numberOfSamples;
}