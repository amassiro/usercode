{
 ///==== transform sample data card from "common" style to "my program" one
 ///== from
 //  ## name xsection(pb) dbs-name link-where-find-xsection-values number-of-MC-evets-available  NLO-x-sections link-for-NLO (if available)    notes
 //  H130_2W_2lnu_wbf_7TeV        0.0726*0.48     /H130_2W_2lnu_wbf_7TeV/Summer09-MC_31X_V3_156BxLumiPileUp-v1/GEN-SIM-RECO   [1]  1.1866 * 0.2959 * 0.324 * 0.324   [8]
 //  
 
 ///== to 
 // SingleTop_tChannel-madgraph_new     VBFPreselection               VBFNtupleL2L3Antikt5CaloJets/SimpleNtple   24.60
 
 
 #include <iostream>
 #include <iomanip>
 
 std::ofstream myfile;
 char nameFile[1000];
 sprintf(nameFile,"samples_temp.txt");
 myfile.open (nameFile);
 
 
 char *nameSample[1000];
 char *nameSamplePrefix[1000];
 char *nameSampleTree[1000];
 char *dataSample[1000];
 char *reference[1000];
 
 char* xsection[1000];
 
 int numberOfSamples = 0;
 std::ifstream inFile("/home/andrea/Cern/Code/VBF/qqHWW/listOfSamples.txt");
 std::string buffer;
 
 while(!inFile.eof()){
  getline(inFile,buffer);
  std::cout << "buffer = " << buffer << std::endl;
  if (!(buffer.empty())){
   if (buffer.at(0) != '#'){ ///---> save from empty line at the end! --- and skip empty line!
    
    std::stringstream line( buffer );       
    nameSample[numberOfSamples] = new char [1000];
    line >> nameSample[numberOfSamples]; 
    //     std::cout << nameSample[numberOfSamples] << " ";
    
    xsection[numberOfSamples] = new char [1000];
    line >> xsection[numberOfSamples]; 
    
    dataSample[numberOfSamples] = new char [1000];
    line >> dataSample[numberOfSamples];
    
    reference[numberOfSamples] = new char [1000];
    line >> reference[numberOfSamples];
    
    std::string buffer_temp;
    if (line.str() != ""){
     line >> buffer_temp;
     if (!(buffer_temp.empty()) && buffer_temp.at(0) != '#') { //== if NLO calculations
      std::cout << "====== " << buffer_temp << std::endl;
      std::stringstream line_temp( buffer_temp );       
      xsection[numberOfSamples] = "";
      line_temp >> xsection[numberOfSamples];
     }
    }
    std::cout << " " << nameSample[numberOfSamples] << " : " << xsection[numberOfSamples] << " ";
    std::cout << std::endl;
    
    std::left;
//     myfile << setfill (' ') << setw(40) << nameSample[numberOfSamples] << " " << "VBFPreselection" << " " << "VBFNtupleL2L3Antikt5CaloJets/SimpleNtple " << setfill (' ') << setw(30) << xsection[numberOfSamples] << " " << reference[numberOfSamples] << std::endl;  
    
    myfile << setfill (' ') << setw(40) << nameSample[numberOfSamples] << " " << "VBFPreselection" << " " << "VBFNtupleL2L3Antikt5CaloJets/SimpleNtple " << setfill (' ') << setw(30) << xsection[numberOfSamples] << std::endl;  
    
    numberOfSamples++;
   }
   else {
    myfile << buffer << std::endl;
   }
   
  }
 }
 
 myfile.close(); 
 
 
 
}     