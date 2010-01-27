All: TT_RECO_1 TT_RECO_2 TT_RECO_3 TT_RECO_4 TT_RECO_5 TT_RECO_6 TT_RECO_7 TT_RECO_8 TT_GEN_1 TT_RECO_5_Alfa TT_General_Calibrator

TT_RECO_1: TT_RECO_1.cpp
	c++ -o TT_RECO_1 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_1.cpp dict.cpp treeReader.cc

TT_RECO_2: TT_RECO_2.cpp
	c++ -o TT_RECO_2 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_2.cpp dict.cpp treeReader.cc

TT_RECO_3: TT_RECO_3.cpp
	c++ -o TT_RECO_3 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_3.cpp dict.cpp treeReader.cc

TT_RECO_4: TT_RECO_4.cpp
	c++ -o TT_RECO_4 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_4.cpp dict.cpp treeReader.cc

TT_RECO_5: TT_RECO_5.cpp
	c++ -o TT_RECO_5 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_5.cpp dict.cpp treeReader.cc

TT_RECO_6: TT_RECO_6.cpp
	c++ -o TT_RECO_6 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_6.cpp dict.cpp treeReader.cc

TT_RECO_7: TT_RECO_7.cpp
	c++ -o TT_RECO_7 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_7.cpp dict.cpp treeReader.cc

TT_RECO_8: TT_RECO_8.cpp
	c++ -o TT_RECO_8 `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_8.cpp dict.cpp treeReader.cc


TT_GEN_1: TT_GEN_1.cpp
	c++ -o TT_GEN_1 `root-config --cflags --glibs` -lMinuit -lGenVector TT_GEN_1.cpp dict.cpp treeReader.cc

TT_RECO_5_Alfa: TT_RECO_5_Alfa.cpp
	c++ -o TT_RECO_5_Alfa `root-config --cflags --glibs` -lMinuit -lGenVector TT_RECO_5_Alfa.cpp dict.cpp treeReader.cc

TT_General_Calibrator: TT_General_Calibrator.cpp
	c++ -o TT_General_Calibrator `root-config --cflags --glibs` -lMinuit -lGenVector TT_General_Calibrator.cpp dict.cpp treeReader.cc JetCalibrator.cc

clean:
	rm *~

clear:
	rm TT_RECO_1 TT_RECO_2 TT_RECO_3 TT_RECO_4 TT_RECO_5 TT_RECO_6 TT_RECO_7 TT_RECO_8 TT_GEN_1 TT_RECO_5_Alfa TT_General_Calibrator
