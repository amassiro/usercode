void Diff(TString name1, TString name2, TString nameOut){
 
 //       [WP][Sample]
 double v1[100][1000];
 double v2[100][1000];
 
 int numLine = 0;
 int nName = 0;
 std::string buffer;
 
 std::ifstream file1 (name1.Data()); 
 std::vector< std::string > nameSamples1;
 while(!file1.eof()) {
  getline(file1,buffer);
  std::cout << " buffer = " << buffer << std::endl;
  std::stringstream line( buffer );      
  if (buffer != ""){   
   if (numLine == 0) {
    std::string tempStringName;
    while ( line >> tempStringName ) {
     nameSamples1.push_back(tempStringName); 
    }
   }
   else {
    nName = 0;
    double temp;
    while ( line >> temp ) {
     v1[numLine-1][nName] = temp; 
     nName++;
    }
   }
   numLine++;
  }
 }
 
 numLine = 0;
 nName = 0;
 std::ifstream file2 (name2.Data()); 
 std::vector< std::string > nameSamples2;
 while(!file2.eof()) {
  getline(file2,buffer);
  std::cout << " buffer = " << buffer << std::endl;
  std::stringstream line( buffer );      
  if (buffer != ""){   
   if (numLine == 0) {
    std::string tempStringName;
    while ( line >> tempStringName ) {
     nameSamples2.push_back(tempStringName); 
    }
   }
   else {
    nName = 0;
    double temp;
    while ( line >> temp ) {
     v2[numLine-1][nName] = temp; 
     nName++;
    }
   }
   numLine++;
  }
 }
 
 
 int nWP = (numLine-1) / 2;
 std::cout << " nWP = " << nWP << " :: numLine = " << numLine << std::endl;
 
 ofstream myfile;
 myfile.open (nameOut.Data());

 std::cout << " nameOut = " << nameOut.Data() << std::endl;

 for (int iName=0; iName<nName; iName++) {
  myfile << " " << nameSamples1.at(iName) << "   ";
 }
 myfile << std::endl;

 myfile.precision (5);
 for (int iWP = 0; iWP < nWP; iWP++) {
  for (int iName=0; iName<nName; iName++) {
   myfile << " " <<  1. + fabs(v1[iWP][iName] -  v2[iWP][iName]) / (v1[iWP][iName] +  v2[iWP][iName]) * 2. << " " ;
  }
  myfile << std::endl;
 }
 
 
 myfile.close();
 
 std::cout << std::endl;
 
 gApplication->Terminate(0);

 
}

