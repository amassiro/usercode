{
 
 
 int num = 20;
 
 ///===================
 ///==== real data ====
 ///===================
 
 double X[100] =    {0, 1, 5, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 45 };
 double errX[100] = {0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 };
  
 
 ///==== pmet > 15 ====
 
 double YDATA_A_ee[100] =    { 217 ,        208 ,        175 ,        141 ,        129 ,        120 ,        107 ,         96 ,         84 ,         78 ,         70 ,         63 ,         57 ,         54 ,         49 ,         46 ,         43 ,         40 ,         37 ,         34};
 double errYDATA_A_ee[100]; 
 
 double YDATA_A_mumu[100] =    { 305 ,        289 ,        234 ,        169 ,        145 ,        128 ,        110 ,         97 ,         88 ,         79 ,         74 ,         62 ,         59 ,         52 ,         50 ,         47 ,         43 ,         40 ,         36 ,         33};
 double errYDATA_A_mumu[100]; 
 
 double YDATA_A_emu[100] =    { 131 ,        127 ,        118 ,        107 ,        104 ,        100 ,         97 ,         95 ,         92 ,         89 ,         89 ,         86 ,         86 ,         82 ,         78 ,         77 ,         76 ,         74 ,         71 ,         67};
 double errYDATA_A_emu[100];
 
 double YDATA_A_metReversed_ee[100] =    {114 ,          0 ,          0 ,          0 ,          0 ,          0 ,          7 ,         18 ,         30 ,         36 ,         44 ,         51 ,         57 ,         60 ,         65 ,         68 ,         71 ,         74 ,         77 ,         80};
 double errYDATA_A_metReversed_ee[100] ;
 
 double YDATA_A_metReversed_mumu[100] =    {116 ,          0 ,          0 ,          0 ,          0 ,          0 ,          6 ,         19 ,         28 ,         37 ,         42 ,         54 ,         57 ,         64 ,         66 ,         69 ,         73 ,         76 ,         80 ,         83};
 double errYDATA_A_metReversed_mumu[100] ;
 
 double YDATA_A_metReversed_emu[100] =    {  99 ,          0 ,          0 ,          0 ,          0 ,          0 ,          2 ,          4 ,          7 ,         10 ,         10 ,         13 ,         13 ,         17 ,         21 ,         22 ,         23 ,         25 ,         28 ,         32};
 double errYDATA_A_metReversed_emu[100];
 
 double YDATA_A_metReversed_noLimit_ee[100] =    {  217 ,          9 ,         42 ,         76 ,         88 ,         97 ,        110 ,        121 ,        133 ,        139 ,        147 ,        154 ,        160 ,        163 ,        168 ,        171 ,        174 ,        177 ,        180 ,        183};
 double errYDATA_A_metReversed_noLimit_ee[100] ;
 
 double YDATA_A_metReversed_noLimit_mumu[100] =    { 305 ,         16 ,         71 ,        136 ,        160 ,        177 ,        195 ,        208 ,        217 ,        226 ,        231 ,        243 ,        246 ,        253 ,        255 ,        258 ,        262 ,        265 ,        269 ,        272};
 double errYDATA_A_metReversed_noLimit_mumu[100] ;
 
 double YDATA_A_metReversed_noLimit_emu[100] =    {131 ,          4 ,         13 ,         24 ,         27 ,         31 ,         34 ,         36 ,         39 ,         42 ,         42 ,         45 ,         45 ,         49 ,         53 ,         54 ,         55 ,         57 ,         60 ,         64};
 double errYDATA_A_metReversed_noLimit_emu[100];
 
 
 
 
 
 
 
 double YDATA_B_ee[100] =    {2165 ,       2043 ,       1607 ,       1085 ,        923 ,        766 ,        643 ,        533 ,        460 ,        384 ,        312 ,        247 ,        196 ,        158 ,        131 ,        108 ,         91 ,         80 ,         74 ,         53};
 double errYDATA_B_ee[100]; 
 
 double YDATA_B_mumu[100] =    {2927 ,       2765 ,       2117 ,       1480 ,       1246 ,       1038 ,        879 ,        721 ,        596 ,        470 ,        394 ,        318 ,        263 ,        223 ,        180 ,        152 ,        130 ,        105 ,         85 ,         63};
 double errYDATA_B_mumu[100]; 
 
 double YDATA_B_emu[100] =    {108 ,        106 ,        100 ,         93 ,         92 ,         88 ,         85 ,         85 ,         80 ,         75 ,         69 ,         68 ,         66 ,         61 ,         60 ,         58 ,         56 ,         55 ,         52 ,         47};
 double errYDATA_B_emu[100];
 
 double YDATA_B_metReversed_ee[100] =    {  706 ,          0 ,          0 ,          0 ,          0 ,          0 ,         63 ,        173 ,        246 ,        322 ,        394 ,        459 ,        510 ,        548 ,        575 ,        598 ,        615 ,        626 ,        632 ,        653};
 double errYDATA_B_metReversed_ee[100] ;
 
 double YDATA_B_metReversed_mumu[100] =    {   962 ,          0 ,          0 ,          0 ,          0 ,          0 ,         83 ,        241 ,        366 ,        492 ,        568 ,        644 ,        699 ,        739 ,        782 ,        810 ,        832 ,        857 ,        877 ,        899};
 double errYDATA_B_metReversed_mumu[100] ;
 
 double YDATA_B_metReversed_emu[100] =    { 86 ,          0 ,          0 ,          0 ,          0 ,          0 ,          1 ,          1 ,          6 ,         11 ,         17 ,         18 ,         20 ,         25 ,         26 ,         28 ,         30 ,         31 ,         34 ,         39};
 double errYDATA_B_metReversed_emu[100];
 
 double YDATA_B_metReversed_noLimit_ee[100] =    { 2165 ,        122 ,        558 ,       1080 ,       1242 ,       1399 ,       1522 ,       1632 ,       1705 ,       1781 ,       1853 ,       1918 ,       1969 ,       2007 ,       2034 ,       2057 ,       2074 ,       2085 ,       2091 ,       2112};
 double errYDATA_B_metReversed_noLimit_ee[100] ;
 
 double YDATA_B_metReversed_noLimit_mumu[100] =    {   2927 ,        162 ,        810 ,       1447 ,       1681 ,       1889 ,       2048 ,       2206 ,       2331 ,       2457 ,       2533 ,       2609 ,       2664 ,       2704 ,       2747 ,       2775 ,       2797 ,       2822 ,       2842 ,       2864};
 double errYDATA_B_metReversed_noLimit_mumu[100] ;
 
 double YDATA_B_metReversed_noLimit_emu[100] =    {108 ,          2 ,          8 ,         15 ,         16 ,         20 ,         23 ,         23 ,         28 ,         33 ,         39 ,         40 ,         42 ,         47 ,         48 ,         50 ,         52 ,         53 ,         56 ,         61};
 double errYDATA_B_metReversed_noLimit_emu[100];
 
 
 ///==== old, before bug fix ====
//  double YDATA_A_ee[100] =    {  67 ,         65 ,         55 ,         46 ,         44 ,         41 ,         33 ,         27 ,         24 ,         21 ,         20 ,         18 ,         18 ,         15 ,         14 ,         13 ,         13 ,         12 ,         11 ,         10 };
//  double errYDATA_A_ee[100]; 
//  
//  double YDATA_A_mumu[100] =    {308 ,        292 ,        236 ,        171 ,        147 ,        130 ,        112 ,         98 ,         89 ,         80 ,         75 ,         63 ,         60 ,         53 ,         51 ,         48 ,         43 ,         40 ,         36 ,         33 };
//  double errYDATA_A_mumu[100]; 
//  
//  double YDATA_A_emu[100] =    {72 ,         70 ,         65 ,         58 ,         56 ,         56 ,         54 ,         54 ,         53 ,         51 ,         51 ,         50 ,         50 ,         48 ,         46 ,         45 ,         44 ,         43 ,         42 ,         39};
//  double errYDATA_A_emu[100];
//  
//  double YDATA_A_metReversed_ee[100] =    {37 ,          0 ,          0 ,          0 ,          0 ,          0 ,          4 ,         10 ,         13 ,         16 ,         17 ,         19 ,         19 ,         22 ,         23 ,         24 ,         24 ,         25 ,         26 ,         27};
//  double errYDATA_A_metReversed_ee[100] ;
//  
//  double YDATA_A_metReversed_mumu[100] =    {118 ,          0 ,          0 ,          0 ,          0 ,          0 ,          6 ,         20 ,         29 ,         38 ,         43 ,         55 ,         58 ,         65 ,         67 ,         70 ,         75 ,         78 ,         82 ,         85};
//  double errYDATA_A_metReversed_mumu[100] ;
//  
//  double YDATA_A_metReversed_emu[100] =    {55 ,          0 ,          0 ,          0 ,          0 ,          0 ,          1 ,          1 ,          2 ,          4 ,          4 ,          5 ,          5 ,          7 ,          9 ,         10 ,         11 ,         12 ,         13 ,         16};
//  double errYDATA_A_metReversed_emu[100];
//  
//  double YDATA_A_metReversed_noLimit_ee[100] =    { 67 ,          2 ,         12 ,         21 ,         23 ,         26 ,         34 ,         40 ,         43 ,         46 ,         47 ,         49 ,         49 ,         52 ,         53 ,         54 ,         54 ,         55 ,         56 ,         57};
//  double errYDATA_A_metReversed_noLimit_ee[100] ;
//  
//  double YDATA_A_metReversed_noLimit_mumu[100] =    {308 ,         16 ,         72 ,        137 ,        161 ,        178 ,        196 ,        210 ,        219 ,        228 ,        233 ,        245 ,        248 ,        255 ,        257 ,        260 ,        265 ,        268 ,        272 ,        275};
//  double errYDATA_A_metReversed_noLimit_mumu[100] ;
//  
//  double YDATA_A_metReversed_noLimit_emu[100] =    { 72 ,          2 ,          7 ,         14 ,         16 ,         16 ,         18 ,         18 ,         19 ,         21 ,         21 ,         22 ,         22 ,         24 ,         26 ,         27 ,         28 ,         29 ,         30 ,         33};
//  double errYDATA_A_metReversed_noLimit_emu[100];
//  
//  
//  
//  
//  
//  
//  
//  double YDATA_B_ee[100] =    { 607 ,        570 ,        434 ,        306 ,        257 ,        213 ,        172 ,        142 ,        122 ,        106 ,         80 ,         64 ,         48 ,         38 ,         31 ,         27 ,         24 ,         20 ,         19 ,         14};
//  double errYDATA_B_ee[100]; 
//  
//  double YDATA_B_mumu[100] =    {2927 ,       2765 ,       2117 ,       1480 ,       1246 ,       1038 ,        879 ,        721 ,        596 ,        470 ,        394 ,        318 ,        263 ,        223 ,        181 ,        153 ,        131 ,        106 ,         86 ,         63};
//  double errYDATA_B_mumu[100]; 
//  
//  double YDATA_B_emu[100] =    {60 ,         58 ,         55 ,         50 ,         50 ,         47 ,         44 ,         43 ,         41 ,         38 ,         36 ,         36 ,         35 ,         32 ,         31 ,         30 ,         29 ,         29 ,         28 ,         25};
//  double errYDATA_B_emu[100];
//  
//  double YDATA_B_metReversed_ee[100] =    {197 ,          0 ,          0 ,          0 ,          0 ,          0 ,         25 ,         55 ,         75 ,         91 ,        117 ,        133 ,        149 ,        159 ,        166 ,        170 ,        173 ,        177 ,        178 ,        183};
//  double errYDATA_B_metReversed_ee[100] ;
//  
//  double YDATA_B_metReversed_mumu[100] =    {  962 ,          0 ,          0 ,          0 ,          0 ,          0 ,         83 ,        241 ,        366 ,        492 ,        568 ,        644 ,        699 ,        739 ,        781 ,        809 ,        831 ,        856 ,        876 ,        899};
//  double errYDATA_B_metReversed_mumu[100] ;
//  
//  double YDATA_B_metReversed_emu[100] =    {45 ,          0 ,          0 ,          0 ,          0 ,          0 ,          1 ,          2 ,          4 ,          7 ,          9 ,          9 ,         10 ,         13 ,         14 ,         15 ,         16 ,         16 ,         17 ,         20};
//  double errYDATA_B_metReversed_emu[100];
//  
//  double YDATA_B_metReversed_noLimit_ee[100] =    {607 ,         37 ,        173 ,        301 ,        350 ,        394 ,        435 ,        465 ,        485 ,        501 ,        527 ,        543 ,        559 ,        569 ,        576 ,        580 ,        583 ,        587 ,        588 ,        593};
//  double errYDATA_B_metReversed_noLimit_ee[100] ;
//  
//  double YDATA_B_metReversed_noLimit_mumu[100] =    {  2927 ,        162 ,        810 ,       1447 ,       1681 ,       1889 ,       2048 ,       2206 ,       2331 ,       2457 ,       2533 ,       2609 ,       2664 ,       2704 ,       2746 ,       2774 ,       2796 ,       2821 ,       2841 ,       2864};
//  double errYDATA_B_metReversed_noLimit_mumu[100] ;
//  
//  double YDATA_B_metReversed_noLimit_emu[100] =    {60 ,          2 ,          5 ,         10 ,         10 ,         13 ,         16 ,         17 ,         19 ,         22 ,         24 ,         24 ,         25 ,         28 ,         29 ,         30 ,         31 ,         31 ,         32 ,         35};
//  double errYDATA_B_metReversed_noLimit_emu[100];
//  
 
 for (int i=0; i<num; i++) {
  errYDATA_B_mumu[i] = sqrt(YDATA_B_mumu[i]);
  errYDATA_B_ee[i] = sqrt(YDATA_B_ee[i]);
  errYDATA_B_metReversed_mumu[i] = sqrt(YDATA_B_metReversed_mumu[i]);
  errYDATA_A_metReversed_mumu[i] = sqrt(YDATA_A_metReversed_mumu[i]);
  errYDATA_B_emu[i] = sqrt(YDATA_B_emu[i]);
  errYDATA_A_emu[i] = sqrt(YDATA_A_emu[i]);
  errYDATA_B_metReversed_ee[i] = sqrt(YDATA_B_metReversed_ee[i]);
  errYDATA_A_metReversed_ee[i] = sqrt(YDATA_A_metReversed_ee[i]);
  
  errYDATA_A_mumu[i] = sqrt(YDATA_A_mumu[i]);
  errYDATA_A_ee[i] = sqrt(YDATA_A_ee[i]);
  
  errYDATA_B_metReversed_emu[i] = sqrt(YDATA_B_metReversed_emu[i]);
  errYDATA_A_metReversed_emu[i] = sqrt(YDATA_A_metReversed_emu[i]);
  
  errYDATA_A_metReversed_noLimit_ee[i] = sqrt(YDATA_A_metReversed_noLimit_ee[i]);
  errYDATA_A_metReversed_noLimit_mumu[i] = sqrt(YDATA_A_metReversed_noLimit_mumu[i]);
  errYDATA_B_metReversed_noLimit_ee[i] = sqrt(YDATA_B_metReversed_noLimit_ee[i]);
  errYDATA_B_metReversed_noLimit_mumu[i] = sqrt(YDATA_B_metReversed_noLimit_mumu[i]);
  
 }
 
 
 double YDATA_R_N_ee[100];
 double errYDATA_R_N_ee[100];
 
 double YDATA_R_N_mumu[100];
 double errYDATA_R_N_mumu[100];
 
 
 double YDATA_R_n_ee[100];
 double errYDATA_R_n_ee[100];
 double YDATA_R_noLimit_n_ee[100];
 double errYDATA_R_noLimit_n_ee[100];
 
 double YDATA_R_corrected_n_ee[100];
 double errYDATA_R_corrected_n_ee[100];
 double YDATA_R_corrected_noLimit_n_ee[100];
 double errYDATA_R_corrected_noLimit_n_ee[100];
 
 double YDATA_R_n_mumu[100];
 double errYDATA_R_n_mumu[100];
 double YDATA_R_noLimit_n_mumu[100];
 double errYDATA_R_noLimit_n_mumu[100];
 
 double YDATA_R_corrected_n_mumu[100];
 double errYDATA_R_corrected_n_mumu[100];
 double YDATA_R_corrected_noLimit_n_mumu[100];
 double errYDATA_R_corrected_noLimit_n_mumu[100];
 
 double YDATA_k_B_ee[100];
 double errYDATA_k_B_ee[100];
 double YDATA_k_noLimit_B_ee[100];
 double errYDATA_k_noLimit_B_ee[100];
 
 double YDATA_k_B_mumu[100];
 double errYDATA_k_B_mumu[100];
 double YDATA_k_noLimit_B_mumu[100];
 double errYDATA_k_noLimit_B_mumu[100];
 
 double YDATA_k_A_ee[100];
 double errYDATA_k_A_ee[100];
 double YDATA_k_noLimit_A_ee[100];
 double errYDATA_k_noLimit_A_ee[100];
 
 double YDATA_k_A_mumu[100];
 double errYDATA_k_A_mumu[100];
 double YDATA_k_noLimit_A_mumu[100];
 double errYDATA_k_noLimit_A_mumu[100];
 
 double YDATA_A_inf_mumu[100];
 double errYDATA_A_inf_mumu[100];
 
 double YDATA_A_inf_ee[100];
 double errYDATA_A_inf_ee[100];
 
 
 for (int i=0; i<num; i++) {
  YDATA_R_n_mumu[i] = YDATA_A_metReversed_mumu[i] / YDATA_B_metReversed_mumu[i];
  YDATA_R_noLimit_n_mumu[i] = YDATA_A_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_mumu[i];
 
  errYDATA_R_n_mumu[i] = sqrt((errYDATA_A_metReversed_mumu[i] / YDATA_B_metReversed_mumu[i])*(errYDATA_A_metReversed_mumu[i] / YDATA_B_metReversed_mumu[i]) + (errYDATA_B_metReversed_mumu[i] * YDATA_A_metReversed_mumu[i] / YDATA_B_metReversed_mumu[i] / YDATA_B_metReversed_mumu[i])*(errYDATA_B_metReversed_mumu[i] * YDATA_A_metReversed_mumu[i] / YDATA_B_metReversed_mumu[i] / YDATA_B_metReversed_mumu[i]));
  errYDATA_R_noLimit_n_mumu[i] = sqrt((errYDATA_A_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_mumu[i])*(errYDATA_A_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_mumu[i]) + (errYDATA_B_metReversed_noLimit_mumu[i] * YDATA_A_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_mumu[i])*(errYDATA_B_metReversed_noLimit_mumu[i] * YDATA_A_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_mumu[i]));
  
  YDATA_R_N_mumu[i] = YDATA_A_mumu[i] / YDATA_B_mumu[i];
  errYDATA_R_N_mumu[i] = sqrt((errYDATA_A_mumu[i] / YDATA_B_mumu[i])*(errYDATA_A_mumu[i] / YDATA_B_mumu[i]) + (errYDATA_B_mumu[i] * YDATA_A_mumu[i] / YDATA_B_mumu[i] / YDATA_B_mumu[i])*(errYDATA_B_mumu[i] * YDATA_A_mumu[i] / YDATA_B_mumu[i] / YDATA_B_mumu[i]));  
  
  YDATA_k_B_mumu[i] = 0.5 * sqrt( YDATA_B_metReversed_mumu[i] / YDATA_B_metReversed_ee[i] ) ;
  errYDATA_k_B_mumu[i] = 1./4. * sqrt(1. / YDATA_B_metReversed_mumu[i] + YDATA_B_metReversed_ee[i]/ YDATA_B_metReversed_mumu[i]/ YDATA_B_metReversed_mumu[i]);  
  
  YDATA_k_noLimit_B_mumu[i] = 0.5 * sqrt( YDATA_B_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_ee[i] ) ;
  errYDATA_k_noLimit_B_mumu[i] = 1./4. * sqrt(1. / YDATA_B_metReversed_noLimit_mumu[i] + YDATA_B_metReversed_noLimit_ee[i]/ YDATA_B_metReversed_noLimit_mumu[i]/ YDATA_B_metReversed_noLimit_mumu[i]);  
  
  YDATA_A_inf_mumu[i] = (YDATA_B_mumu[i] - YDATA_k_B_mumu[i] * YDATA_B_emu[i]) * YDATA_R_n_mumu[i];
  
  YDATA_k_noLimit_A_mumu[i] = 0.5 * sqrt( YDATA_A_metReversed_noLimit_mumu[i] / YDATA_A_metReversed_noLimit_ee[i] ) ;
  errYDATA_k_noLimit_A_mumu[i] = 1./4. * sqrt(1. / YDATA_A_metReversed_noLimit_mumu[i] + YDATA_A_metReversed_noLimit_ee[i]/ YDATA_A_metReversed_noLimit_mumu[i]/ YDATA_A_metReversed_noLimit_mumu[i]);  
  
  YDATA_k_A_mumu[i] = 0.5 * sqrt( YDATA_A_metReversed_mumu[i] / YDATA_A_metReversed_ee[i] ) ;
  errYDATA_k_A_mumu[i] = 1./4. * sqrt(1. / YDATA_A_metReversed_mumu[i] + YDATA_A_metReversed_ee[i]/ YDATA_A_metReversed_mumu[i]/ YDATA_A_metReversed_mumu[i]);    
  
  YDATA_R_corrected_n_mumu[i] = (YDATA_A_metReversed_mumu[i] - YDATA_k_A_mumu[i] * YDATA_A_metReversed_emu[i])/ YDATA_B_metReversed_mumu[i];
  errYDATA_R_corrected_n_mumu[i] = sqrt( (errYDATA_k_A_mumu[i] * YDATA_A_metReversed_emu[i] / YDATA_B_metReversed_mumu[i]) * (errYDATA_k_A_mumu[i] * YDATA_A_metReversed_emu[i] / YDATA_B_metReversed_mumu[i]) + (errYDATA_A_metReversed_mumu[i] / YDATA_B_metReversed_mumu[i]) * (errYDATA_A_metReversed_mumu[i] / YDATA_B_metReversed_mumu[i]) +  (errYDATA_k_A_mumu[i] * YDATA_A_metReversed_emu[i] / YDATA_B_metReversed_mumu[i]) * (errYDATA_k_A_mumu[i] * YDATA_A_metReversed_emu[i] / YDATA_B_metReversed_mumu[i]) +   (errYDATA_B_metReversed_mumu[i] * (YDATA_A_metReversed_mumu[i] - YDATA_k_A_mumu[i] * YDATA_A_metReversed_emu[i])/ YDATA_B_metReversed_mumu[i]/ YDATA_B_metReversed_mumu[i]) * (errYDATA_B_metReversed_mumu[i] * (YDATA_A_metReversed_mumu[i] - YDATA_k_A_mumu[i] * YDATA_A_metReversed_emu[i])/ YDATA_B_metReversed_mumu[i]/ YDATA_B_metReversed_mumu[i]));

  YDATA_R_corrected_noLimit_n_mumu[i] = (YDATA_A_metReversed_noLimit_mumu[i] - YDATA_k_noLimit_A_mumu[i] * YDATA_A_metReversed_noLimit_emu[i])/ YDATA_B_metReversed_noLimit_mumu[i];
  errYDATA_R_corrected_noLimit_n_mumu[i] = sqrt( (errYDATA_k_noLimit_A_mumu[i] * YDATA_A_metReversed_noLimit_emu[i] / YDATA_B_metReversed_noLimit_mumu[i]) * (errYDATA_k_noLimit_A_mumu[i] * YDATA_A_metReversed_noLimit_emu[i] / YDATA_B_metReversed_noLimit_mumu[i]) + (errYDATA_A_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_mumu[i]) * (errYDATA_A_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_mumu[i]) +  (errYDATA_k_noLimit_A_mumu[i] * YDATA_A_metReversed_noLimit_emu[i] / YDATA_B_metReversed_noLimit_mumu[i]) * (errYDATA_k_noLimit_A_mumu[i] * YDATA_A_metReversed_noLimit_emu[i] / YDATA_B_metReversed_noLimit_mumu[i]) +   (errYDATA_B_metReversed_noLimit_mumu[i] * (YDATA_A_metReversed_noLimit_mumu[i] - YDATA_k_noLimit_A_mumu[i] * YDATA_A_metReversed_noLimit_emu[i])/ YDATA_B_metReversed_noLimit_mumu[i]/ YDATA_B_metReversed_noLimit_mumu[i]) * (errYDATA_B_metReversed_noLimit_mumu[i] * (YDATA_A_metReversed_noLimit_mumu[i] - YDATA_k_noLimit_A_mumu[i] * YDATA_A_metReversed_noLimit_emu[i])/ YDATA_B_metReversed_noLimit_mumu[i]/ YDATA_B_metReversed_noLimit_mumu[i]));
    
  errYDATA_A_inf_mumu[i] =   sqrt(((YDATA_B_mumu[i] - YDATA_k_B_mumu[i] * YDATA_B_emu[i]) * errYDATA_R_n_mumu[i])*((YDATA_B_mumu[i] - YDATA_k_B_mumu[i] * YDATA_B_emu[i]) * errYDATA_R_n_mumu[i])  +     
  ((errYDATA_B_mumu[i]) * YDATA_R_n_mumu[i]) * (errYDATA_B_mumu[i]) * YDATA_R_n_mumu[i] + 
  (errYDATA_k_B_mumu[i] * YDATA_B_emu[i] * YDATA_R_n_mumu[i])*(errYDATA_k_B_mumu[i] * YDATA_B_emu[i] * YDATA_R_n_mumu[i]) + 
  (YDATA_k_B_mumu[i] * errYDATA_B_emu[i] * YDATA_R_n_mumu[i])*(YDATA_k_B_mumu[i] * errYDATA_B_emu[i] * YDATA_R_n_mumu[i])) ;
  
 }
 
 for (int i=0; i<num; i++) {
  YDATA_R_n_ee[i] = YDATA_A_metReversed_ee[i] / YDATA_B_metReversed_ee[i];
  YDATA_R_noLimit_n_ee[i] = YDATA_A_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i];
  
  errYDATA_R_n_ee[i] = sqrt((errYDATA_A_metReversed_ee[i] / YDATA_B_metReversed_ee[i])*(errYDATA_A_metReversed_ee[i] / YDATA_B_metReversed_ee[i]) + (errYDATA_B_metReversed_ee[i] * YDATA_A_metReversed_ee[i] / YDATA_B_metReversed_ee[i] / YDATA_B_metReversed_ee[i])*(errYDATA_B_metReversed_ee[i] * YDATA_A_metReversed_ee[i] / YDATA_B_metReversed_ee[i] / YDATA_B_metReversed_ee[i]));
  errYDATA_R_noLimit_n_ee[i] = sqrt((errYDATA_A_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i])*(errYDATA_A_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i]) + (errYDATA_B_metReversed_noLimit_ee[i] * YDATA_A_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i])*(errYDATA_B_metReversed_noLimit_ee[i] * YDATA_A_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i]));
  
  YDATA_R_N_ee[i] = YDATA_A_ee[i] / YDATA_B_ee[i];
  errYDATA_R_N_ee[i] = sqrt((errYDATA_A_ee[i] / YDATA_B_ee[i])*(errYDATA_A_ee[i] / YDATA_B_ee[i]) + (errYDATA_B_ee[i] * YDATA_A_ee[i] / YDATA_B_ee[i] / YDATA_B_ee[i])*(errYDATA_B_ee[i] * YDATA_A_ee[i] / YDATA_B_ee[i] / YDATA_B_ee[i]));
  
  YDATA_k_B_ee[i] = 0.5 * sqrt( YDATA_B_metReversed_ee[i] / YDATA_B_metReversed_mumu[i] ) ; ;
  errYDATA_k_B_ee[i] = 1./4. * sqrt(1. / YDATA_B_metReversed_ee[i] + YDATA_B_metReversed_mumu[i] / YDATA_B_metReversed_ee[i] / YDATA_B_metReversed_ee[i]);  
  
  YDATA_k_noLimit_B_ee[i] = 0.5 * sqrt( YDATA_B_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_mumu[i] ) ;
  errYDATA_k_noLimit_B_ee[i] = 1./4. * sqrt(1. / YDATA_B_metReversed_noLimit_ee[i] + YDATA_B_metReversed_noLimit_mumu[i] / YDATA_B_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i]);  
  
  YDATA_A_inf_ee[i] = (YDATA_B_ee[i] - YDATA_k_B_ee[i] * YDATA_B_emu[i]) * YDATA_R_n_ee[i];
  
  YDATA_k_noLimit_A_ee[i] = 0.5 * sqrt( YDATA_A_metReversed_noLimit_ee[i] / YDATA_A_metReversed_noLimit_mumu[i] ) ;
  errYDATA_k_noLimit_A_ee[i] = 1./4. * sqrt(1. / YDATA_A_metReversed_noLimit_ee[i] + YDATA_A_metReversed_noLimit_mumu[i] / YDATA_A_metReversed_noLimit_ee[i] / YDATA_A_metReversed_noLimit_ee[i]);  
  
  YDATA_k_A_ee[i] = 0.5 * sqrt( YDATA_A_metReversed_ee[i] / YDATA_A_metReversed_mumu[i] ) ;
  errYDATA_k_A_ee[i] = 1./4. * sqrt(1. / YDATA_A_metReversed_ee[i] + YDATA_A_metReversed_mumu[i] / YDATA_A_metReversed_ee[i] / YDATA_A_metReversed_ee[i]);  
  
  
  YDATA_R_corrected_n_ee[i] = (YDATA_A_metReversed_ee[i] - YDATA_k_A_ee[i] * YDATA_A_metReversed_emu[i])/ YDATA_B_metReversed_ee[i];
  errYDATA_R_corrected_n_ee[i] = sqrt( (errYDATA_k_A_ee[i] * YDATA_A_metReversed_emu[i] / YDATA_B_metReversed_ee[i]) * (errYDATA_k_A_ee[i] * YDATA_A_metReversed_emu[i] / YDATA_B_metReversed_ee[i]) + (errYDATA_A_metReversed_ee[i] / YDATA_B_metReversed_ee[i]) * (errYDATA_A_metReversed_ee[i] / YDATA_B_metReversed_ee[i]) +  (errYDATA_k_A_ee[i] * YDATA_A_metReversed_emu[i] / YDATA_B_metReversed_ee[i]) * (errYDATA_k_A_ee[i] * YDATA_A_metReversed_emu[i] / YDATA_B_metReversed_ee[i]) +   (errYDATA_B_metReversed_ee[i] * (YDATA_A_metReversed_ee[i] - YDATA_k_A_ee[i] * YDATA_A_metReversed_emu[i])/ YDATA_B_metReversed_ee[i]/ YDATA_B_metReversed_ee[i]) * (errYDATA_B_metReversed_ee[i] * (YDATA_A_metReversed_ee[i] - YDATA_k_A_ee[i] * YDATA_A_metReversed_emu[i])/ YDATA_B_metReversed_ee[i]/ YDATA_B_metReversed_ee[i]));
  YDATA_R_corrected_noLimit_n_ee[i] = (YDATA_A_metReversed_noLimit_ee[i] - YDATA_k_noLimit_A_ee[i] * YDATA_A_metReversed_noLimit_emu[i])/ YDATA_B_metReversed_noLimit_ee[i];
  errYDATA_R_corrected_noLimit_n_ee[i] = sqrt( (errYDATA_k_noLimit_A_ee[i] * YDATA_A_metReversed_noLimit_emu[i] / YDATA_B_metReversed_noLimit_ee[i]) * (errYDATA_k_noLimit_A_ee[i] * YDATA_A_metReversed_noLimit_emu[i] / YDATA_B_metReversed_noLimit_ee[i]) + (errYDATA_A_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i]) * (errYDATA_A_metReversed_noLimit_ee[i] / YDATA_B_metReversed_noLimit_ee[i]) +  (errYDATA_k_noLimit_A_ee[i] * YDATA_A_metReversed_noLimit_emu[i] / YDATA_B_metReversed_noLimit_ee[i]) * (errYDATA_k_noLimit_A_ee[i] * YDATA_A_metReversed_noLimit_emu[i] / YDATA_B_metReversed_noLimit_ee[i]) +   (errYDATA_B_metReversed_noLimit_ee[i] * (YDATA_A_metReversed_noLimit_ee[i] - YDATA_k_noLimit_A_ee[i] * YDATA_A_metReversed_noLimit_emu[i])/ YDATA_B_metReversed_noLimit_ee[i]/ YDATA_B_metReversed_noLimit_ee[i]) * (errYDATA_B_metReversed_noLimit_ee[i] * (YDATA_A_metReversed_noLimit_ee[i] - YDATA_k_noLimit_A_ee[i] * YDATA_A_metReversed_noLimit_emu[i])/ YDATA_B_metReversed_noLimit_ee[i]/ YDATA_B_metReversed_noLimit_ee[i]));
  
  
  errYDATA_A_inf_ee[i] =   sqrt(((YDATA_B_ee[i] - YDATA_k_B_ee[i] * YDATA_B_emu[i]) * errYDATA_R_n_ee[i])*((YDATA_B_ee[i] - YDATA_k_B_ee[i] * YDATA_B_emu[i]) * errYDATA_R_n_ee[i])  +     
  ((errYDATA_B_ee[i]) * YDATA_R_n_ee[i]) * (errYDATA_B_ee[i]) * YDATA_R_n_ee[i] + 
  (errYDATA_k_B_ee[i] * YDATA_B_emu[i] * YDATA_R_n_ee[i])*(errYDATA_k_B_ee[i] * YDATA_B_emu[i] * YDATA_R_n_ee[i]) + 
  (YDATA_k_B_ee[i] * errYDATA_B_emu[i] * YDATA_R_n_ee[i])*(YDATA_k_B_ee[i] * errYDATA_B_emu[i] * YDATA_R_n_ee[i])) ;
 }
 
 
 
 
 
 
 
 
 
 
 
 ///============================================
 ///==================== MC ====================
 ///============================================
 
 ///==== pmet > 15 ---- MC ====
 
 
 ///==== madgraph ====
 
 double Ymad_A_ee[100] =    {103.9 ,      97.89 ,      73.63 ,      47.98 ,      39.04 ,      31.63 ,       26.2 ,      20.43 ,      17.03 ,      13.15 ,      9.837 ,      6.095 ,      5.568 ,      5.291 ,      3.756 ,      3.547 ,      2.325 ,      1.877 ,      1.461 ,     0.7981};
 double errYmad_A_ee[100] = {  7.048 ,      6.861 ,      5.996 ,      4.816 ,      4.382 ,      3.997 ,      3.741 ,       3.16 ,      2.892 ,      2.559 ,      2.077 ,      1.578 ,      1.551 ,       1.54 ,       1.24 ,      1.227 ,     0.8602 ,     0.7346 ,     0.6458 ,     0.5032}; 
 
 double Ymad_A_mumu[100] =    { 167.2 ,      157.2 ,      120.5 ,      78.88 ,      62.46 ,      52.31 ,      41.74 ,      34.95 ,      24.73 ,      19.89 ,      16.38 ,      13.83 ,      11.47 ,      9.138 ,      8.623 ,      6.592 ,       4.89 ,      3.702 ,       2.95 ,       2.72};
 double errYmad_A_mumu[100] = { 8.871 ,      8.577 ,      7.627 ,      6.266 ,      5.544 ,       5.12 ,      4.551 ,      4.134 ,      3.375 ,      3.039 ,      2.722 ,       2.56 ,      2.288 ,      2.125 ,       2.09 ,      1.822 ,      1.673 ,      1.402 ,      1.306 ,       1.29}; 
 
 double Ymad_A_emu[100] =    {    17.4 ,      16.11 ,      13.86 ,        9.9 ,      8.981 ,      6.816 ,      4.359 ,      3.371 ,      2.725 ,      2.264 ,      1.708 ,      1.271 ,     0.9031 ,     0.8664 ,     0.8664 ,     0.8664 ,     0.6939 ,     0.6201 ,     0.6201 ,     0.4476};
 double errYmad_A_emu[100] = { 2.415 ,      2.323 ,      2.178 ,      1.856 ,      1.746 ,      1.531 ,      1.231 ,      1.079 ,     0.9676 ,     0.8684 ,     0.7364 ,     0.6341 ,     0.5164 ,     0.5151 ,     0.5151 ,     0.5151 ,     0.4853 ,     0.4797 ,     0.4797 ,     0.4476};
 
 double Ymad_A_metReversed_ee[100] =    {  28.68 ,          0 ,          0 ,          0 ,          0 ,          0 ,      2.478 ,      8.255 ,      11.65 ,      15.54 ,      18.84 ,      22.59 ,      23.11 ,      23.39 ,      24.93 ,      25.14 ,      26.36 ,      26.81 ,      27.22 ,      27.88};
 double errYmad_A_metReversed_ee[100] = {  3.882 ,          0 ,          0 ,          0 ,          0 ,          0 ,      1.037 ,      2.254 ,      2.589 ,      2.919 ,       3.28 ,      3.547 ,      3.559 ,      3.563 ,      3.679 ,      3.683 ,      3.785 ,      3.812 ,      3.828 ,      3.849};
 
 double Ymad_A_metReversed_mumu[100] =    {   46.89 ,          0 ,          0 ,          0 ,          0 ,          0 ,      5.144 ,      11.94 ,      22.16 ,         27 ,       30.5 ,      33.06 ,      35.42 ,      37.75 ,      38.27 ,       40.3 ,         42 ,      43.19 ,      43.94 ,      44.17};
 double errYmad_A_metReversed_mumu[100] = { 4.838 ,          0 ,          0 ,          0 ,          0 ,          0 ,       1.64 ,      2.512 ,      3.466 ,      3.764 ,      3.999 ,      4.105 ,      4.262 ,      4.346 ,      4.363 ,      4.482 ,      4.539 ,       4.63 ,      4.658 ,      4.663};
 
 double Ymad_A_metReversed_emu[100] =    {   5.167 ,          0 ,          0 ,          0 ,          0 ,          0 ,      0.808 ,      1.796 ,      2.441 ,      2.903 ,      3.458 ,      3.896 ,      4.264 ,        4.3 ,        4.3 ,        4.3 ,      4.473 ,      4.547 ,      4.547 ,      4.719};
 double errYmad_A_metReversed_emu[100] = { 1.36 ,          0 ,          0 ,          0 ,          0 ,          0 ,      0.578 ,     0.8277 ,     0.9559 ,      1.047 ,      1.144 ,      1.203 ,      1.258 ,      1.259 ,      1.259 ,      1.259 ,      1.271 ,      1.273 ,      1.273 ,      1.284};
 
 double Ymad_A_metReversed_noLimit_ee[100] =    {    103.9 ,      5.992 ,      30.25 ,      55.91 ,      64.84 ,      72.25 ,      77.68 ,      83.45 ,      86.85 ,      90.74 ,      94.04 ,      97.79 ,      98.31 ,      98.59 ,      100.1 ,      100.3 ,      101.6 ,        102 ,      102.4 ,      103.1};
 double errYmad_A_metReversed_noLimit_ee[100] = {    7.048 ,      1.615 ,      3.705 ,      5.146 ,       5.52 ,      5.805 ,      5.974 ,        6.3 ,      6.428 ,      6.567 ,      6.735 ,      6.869 ,      6.876 ,      6.878 ,      6.938 ,      6.941 ,      6.996 ,       7.01 ,      7.019 ,       7.03};
 
 double Ymad_A_metReversed_noLimit_mumu[100] =    { 167.2 ,      9.937 ,      46.69 ,       88.3 ,      104.7 ,      114.9 ,      125.4 ,      132.2 ,      142.5 ,      147.3 ,      150.8 ,      153.4 ,      155.7 ,        158 ,      158.6 ,      160.6 ,      162.3 ,      163.5 ,      164.2 ,      164.5};
 double errYmad_A_metReversed_noLimit_mumu[100] = { 8.871 ,      2.267 ,      4.531 ,       6.28 ,      6.926 ,      7.245 ,      7.615 ,      7.849 ,      8.204 ,      8.335 ,      8.443 ,      8.494 ,      8.571 ,      8.613 ,      8.622 ,      8.682 ,      8.712 ,       8.76 ,      8.775 ,      8.777};
 
 double Ymad_A_metReversed_noLimit_emu[100] =    {    17.4 ,      1.294 ,      3.543 ,      7.501 ,       8.42 ,      10.58 ,      13.04 ,      14.03 ,      14.68 ,      15.14 ,      15.69 ,      16.13 ,       16.5 ,      16.53 ,      16.53 ,      16.53 ,      16.71 ,      16.78 ,      16.78 ,      16.95};
 double errYmad_A_metReversed_noLimit_emu[100] = {  2.415 ,      0.658 ,      1.043 ,      1.544 ,      1.668 ,      1.867 ,      2.077 ,       2.16 ,      2.212 ,      2.253 ,        2.3 ,       2.33 ,      2.359 ,      2.359 ,      2.359 ,      2.359 ,      2.365 ,      2.366 ,      2.366 ,      2.373};
 
 
 
 double Ymad_B_ee[100] =    {  1848 ,       1721 ,       1260 ,      778.4 ,      630.1 ,      488.9 ,      373.6 ,      296.9 ,      229.1 ,      177.1 ,      125.8 ,      95.94 ,      74.29 ,      56.17 ,      42.67 ,      30.74 ,      21.61 ,      16.44 ,      11.53 ,      6.723};
 double errYmad_B_ee[100] = {  24.63 ,      23.77 ,      20.27 ,      15.85 ,      14.23 ,      12.47 ,      10.89 ,      9.668 ,       8.48 ,      7.396 ,      6.166 ,       5.36 ,      4.759 ,      4.156 ,      3.619 ,      3.048 ,      2.567 ,      2.293 ,      1.883 ,      1.486};
 
 double Ymad_B_mumu[100] =    {     2427 ,       2268 ,       1643 ,       1035 ,      830.4 ,      652.8 ,      518.8 ,      398.3 ,      309.3 ,      233.5 ,      175.2 ,      132.5 ,        103 ,      75.63 ,      57.45 ,      43.48 ,      32.48 ,      26.23 ,      22.99 ,      12.44};
 double errYmad_B_mumu[100] = { 28.18 ,      27.25 ,      23.14 ,      18.33 ,      16.37 ,      14.48 ,      12.88 ,      11.24 ,       9.89 ,      8.517 ,      7.334 ,      6.328 ,      5.561 ,      4.777 ,      4.174 ,      3.635 ,      3.152 ,      2.884 ,      2.739 ,      2.023};
 
 double Ymad_B_emu[100] =    {    5.824 ,      5.482 ,      4.952 ,      4.464 ,      3.636 ,      3.636 ,      2.529 ,      2.161 ,       2.11 ,      1.165 ,      1.034 ,      1.034 ,      1.034 ,     0.7814 ,    0.06929 ,    0.06929 ,          0 ,          0 ,          0 ,          0};
 double errYmad_B_emu[100] = {   1.329 ,      1.284 ,       1.25 ,      1.221 ,      1.102 ,      1.102 ,     0.8826 ,     0.8022 ,     0.8006 ,     0.5773 ,     0.5663 ,     0.5663 ,     0.5663 ,      0.507 ,    0.06929 ,    0.06929 ,          0 ,          0 ,          0 ,          0};
 
 double Ymad_B_metReversed_ee[100] =    {    425.7 ,          0 ,          0 ,          0 ,          0 ,          0 ,      52.11 ,      128.8 ,      196.6 ,      248.6 ,      299.9 ,      329.8 ,      351.4 ,      369.5 ,        383 ,        395 ,      404.1 ,      409.3 ,      414.2 ,        419};
 double errYmad_B_metReversed_ee[100] = {11.61 ,          0 ,          0 ,          0 ,          0 ,          0 ,      4.042 ,      6.436 ,      7.937 ,      8.956 ,      9.843 ,       10.3 ,      10.59 ,      10.85 ,      11.04 ,      11.21 ,      11.33 ,      11.39 ,      11.46 ,      11.52};
 
 double Ymad_B_metReversed_mumu[100] =    {  583 ,          0 ,          0 ,          0 ,          0 ,          0 ,      64.17 ,      184.7 ,      273.7 ,      349.6 ,      407.8 ,      450.5 ,      480.1 ,      507.4 ,      525.6 ,      539.5 ,      550.5 ,      556.8 ,        560 ,      570.6};
 double errYmad_B_metReversed_mumu[100] = { 13.67 ,          0 ,          0 ,          0 ,          0 ,          0 ,       4.59 ,       7.79 ,      9.441 ,       10.7 ,      11.54 ,      12.12 ,      12.49 ,      12.81 ,      13.02 ,      13.18 ,       13.3 ,      13.36 ,       13.4 ,      13.52};
 
 double Ymad_B_metReversed_emu[100] =    {  2.764 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.2349 ,     0.6028 ,     0.6537 ,      1.599 ,       1.73 ,       1.73 ,       1.73 ,      1.982 ,      2.694 ,      2.694 ,      2.764 ,      2.764 ,      2.764 ,      2.764};
 double errYmad_B_metReversed_emu[100] = {0.9133 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.2349 ,     0.4365 ,     0.4395 ,     0.7077 ,     0.7165 ,     0.7165 ,     0.7165 ,     0.7597 ,     0.9107 ,     0.9107 ,     0.9133 ,     0.9133 ,     0.9133 ,     0.9133};
 
 double Ymad_B_metReversed_noLimit_ee[100] =    {  1848 ,      127.1 ,      587.7 ,       1069 ,       1218 ,       1359 ,       1474 ,       1551 ,       1619 ,       1671 ,       1722 ,       1752 ,       1774 ,       1792 ,       1805 ,       1817 ,       1826 ,       1831 ,       1836 ,       1841};
 double errYmad_B_metReversed_noLimit_ee[100] = { 24.63 ,       6.45 ,      13.98 ,      18.84 ,       20.1 ,      21.23 ,      22.09 ,      22.65 ,      23.12 ,      23.49 ,      23.84 ,      24.04 ,      24.16 ,      24.27 ,      24.36 ,      24.44 ,      24.49 ,      24.52 ,      24.55 ,      24.58};
 
 double Ymad_B_metReversed_noLimit_mumu[100] =    {   2427 ,      158.4 ,      783.4 ,       1392 ,       1596 ,       1774 ,       1908 ,       2029 ,       2118 ,       2193 ,       2252 ,       2294 ,       2324 ,       2351 ,       2369 ,       2383 ,       2394 ,       2401 ,       2404 ,       2414};
 double errYmad_B_metReversed_noLimit_mumu[100] = {  28.18 ,      7.156 ,      16.08 ,       21.4 ,      22.94 ,      24.17 ,      25.06 ,      25.84 ,      26.39 ,      26.86 ,      27.21 ,      27.46 ,      27.62 ,      27.77 ,      27.87 ,      27.94 ,         28 ,      28.03 ,      28.04 ,      28.11};

 double Ymad_B_metReversed_noLimit_emu[100] =    {  5.824 ,     0.3422 ,     0.8722 ,       1.36 ,      2.187 ,      2.187 ,      3.295 ,      3.663 ,      3.714 ,      4.659 ,       4.79 ,       4.79 ,       4.79 ,      5.042 ,      5.754 ,      5.754 ,      5.824 ,      5.824 ,      5.824 ,      5.824};
 double errYmad_B_metReversed_noLimit_emu[100] = {  1.329 ,     0.3422 ,      0.451 ,     0.5226 ,     0.7415 ,     0.7415 ,     0.9931 ,      1.059 ,       1.06 ,      1.197 ,      1.202 ,      1.202 ,      1.202 ,      1.228 ,      1.327 ,      1.327 ,      1.329 ,      1.329 ,      1.329 ,      1.329};
 
 ///==== powheg ====
 
 double Ypow_A_ee[100] =    {   105.6 ,      97.92 ,       71.4 ,      46.04 ,      38.19 ,      30.32 ,      26.37 ,      20.11 ,       14.4 ,       9.25 ,      6.748 ,      5.068 ,      4.172 ,      2.953 ,      2.259 ,      2.187 ,      1.412 ,      1.073 ,      1.001 ,     0.4719};
 double errYpow_A_ee[100] = { 6.047 ,      5.781 ,      4.915 ,      3.914 ,      3.557 ,      3.216 ,      2.998 ,      2.636 ,       2.13 ,      1.604 ,      1.395 ,      1.187 ,      1.042 ,      0.831 ,     0.7059 ,     0.7023 ,     0.5667 ,     0.5047 ,     0.4995 ,     0.3268}; 
 
 double Ypow_A_mumu[100] =    {   162.6 ,      152.5 ,      118.7 ,      77.18 ,      63.42 ,      52.85 ,      41.61 ,      32.58 ,      24.76 ,      18.27 ,      14.31 ,      9.769 ,      8.196 ,      6.592 ,      5.106 ,      3.899 ,      3.016 ,      1.681 ,      1.237 ,     0.2346};
 double errYpow_A_mumu[100] = {    7.892 ,      7.642 ,      6.801 ,      5.444 ,      4.924 ,      4.512 ,      4.008 ,      3.576 ,      3.058 ,      2.568 ,      2.336 ,      1.981 ,      1.867 ,      1.634 ,      1.457 ,      1.118 ,      1.001 ,     0.6549 ,     0.5744 ,     0.2151}; 
 
 double Ypow_A_emu[100] =    {   16.26 ,      16.03 ,      12.06 ,      8.637 ,      6.802 ,      5.517 ,      5.016 ,      4.159 ,      3.731 ,       2.66 ,      2.063 ,      1.848 ,      1.409 ,      1.409 ,      1.195 ,      1.195 ,     0.9809 ,     0.6587 ,     0.6587 ,     0.2142};
 double errYpow_A_emu[100] = {  1.944 ,      1.931 ,      1.659 ,      1.401 ,      1.237 ,       1.12 ,      1.076 ,      0.987 ,     0.9394 ,     0.8081 ,     0.7299 ,     0.6978 ,     0.5423 ,     0.5423 ,     0.4982 ,     0.4982 ,     0.4498 ,     0.3805 ,     0.3805 ,     0.2142};
 
 double Ypow_A_metReversed_ee[100] =    { 28.13 ,          0 ,          0 ,          0 ,          0 ,          0 ,      1.758 ,      8.015 ,      13.73 ,      18.88 ,      21.38 ,      23.06 ,      23.95 ,      25.17 ,      25.87 ,      25.94 ,      26.71 ,      27.05 ,      27.13 ,      27.65};
 double errYpow_A_metReversed_ee[100] = {3.071 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.6639 ,      1.575 ,      2.212 ,      2.619 ,      2.736 ,      2.832 ,      2.889 ,      2.956 ,      2.988 ,      2.989 ,      3.018 ,      3.029 ,       3.03 ,      3.053};
 
 double Ypow_A_metReversed_mumu[100] =    { 48.84 ,          0 ,          0 ,          0 ,          0 ,          0 ,      7.233 ,      16.27 ,      24.09 ,      30.57 ,      34.54 ,      39.07 ,      40.65 ,      42.25 ,      43.74 ,      44.94 ,      45.83 ,      47.16 ,      47.61 ,      48.61};
 double errYpow_A_metReversed_mumu[100] = {  4.378 ,          0 ,          0 ,          0 ,          0 ,          0 ,      1.763 ,      2.526 ,      3.133 ,      3.546 ,      3.703 ,      3.904 ,       3.96 ,      4.062 ,      4.129 ,      4.233 ,      4.262 ,      4.329 ,       4.34 ,      4.373};
 
 double Ypow_A_metReversed_emu[100] =    { 5.303 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.2866 ,      1.143 ,      1.572 ,      2.643 ,       3.24 ,      3.454 ,      3.893 ,      3.893 ,      4.107 ,      4.107 ,      4.322 ,      4.644 ,      4.644 ,      5.088};
 double errYpow_A_metReversed_emu[100] = {  1.099 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.2261 ,     0.4844 ,     0.5713 ,     0.7455 ,     0.8222 ,     0.8497 ,     0.9564 ,     0.9564 ,     0.9801 ,     0.9801 ,      1.003 ,      1.031 ,      1.031 ,      1.078};
 
 double Ypow_A_metReversed_noLimit_ee[100] =    {  105.6 ,      7.713 ,      34.23 ,      59.59 ,      67.45 ,      75.32 ,      79.27 ,      85.52 ,      91.24 ,      96.39 ,      98.89 ,      100.6 ,      101.5 ,      102.7 ,      103.4 ,      103.4 ,      104.2 ,      104.6 ,      104.6 ,      105.2};
 double errYpow_A_metReversed_noLimit_ee[100] = { 6.047 ,      1.772 ,      3.522 ,      4.609 ,       4.89 ,      5.121 ,      5.251 ,      5.442 ,      5.659 ,       5.83 ,      5.884 ,      5.929 ,      5.956 ,      5.989 ,      6.005 ,      6.006 ,       6.02 ,      6.026 ,      6.026 ,      6.038};
 
 double Ypow_A_metReversed_noLimit_mumu[100] =    { 162.6 ,      10.08 ,      43.86 ,       85.4 ,      99.16 ,      109.7 ,        121 ,        130 ,      137.8 ,      144.3 ,      148.3 ,      152.8 ,      154.4 ,        156 ,      157.5 ,      158.7 ,      159.6 ,      160.9 ,      161.3 ,      162.3};
 double errYpow_A_metReversed_noLimit_mumu[100] = { 7.892 ,      1.972 ,      4.005 ,      5.714 ,      6.168 ,      6.475 ,      6.799 ,      7.036 ,      7.276 ,      7.463 ,      7.539 ,       7.64 ,      7.668 ,      7.721 ,      7.757 ,      7.813 ,      7.829 ,      7.865 ,      7.872 ,       7.89};
 
 double Ypow_A_metReversed_noLimit_emu[100] =    {  16.26 ,     0.2304 ,      4.196 ,      7.621 ,      9.455 ,      10.74 ,      11.24 ,       12.1 ,      12.53 ,       13.6 ,      14.19 ,      14.41 ,      14.85 ,      14.85 ,      15.06 ,      15.06 ,      15.28 ,       15.6 ,       15.6 ,      16.04};
 double errYpow_A_metReversed_noLimit_emu[100] = {  1.944 ,     0.2304 ,      1.014 ,      1.348 ,        1.5 ,      1.589 ,      1.619 ,      1.675 ,      1.702 ,      1.768 ,      1.802 ,      1.815 ,      1.867 ,      1.867 ,      1.879 ,      1.879 ,      1.891 ,      1.907 ,      1.907 ,      1.932};
 
 
 double Ypow_B_ee[100] =    { 1679 ,       1565 ,       1150 ,      709.2 ,      565.2 ,      460.7 ,      362.3 ,      275.9 ,      211.2 ,      162.7 ,      125.9 ,      93.94 ,      69.44 ,         50 ,      38.17 ,      28.06 ,      19.17 ,      14.78 ,       12.2 ,      5.897};
 double errYpow_B_ee[100] = {   23.24 ,       22.4 ,      19.21 ,       15.1 ,      13.48 ,      12.25 ,      10.87 ,      9.427 ,      8.231 ,      7.216 ,      6.372 ,      5.475 ,      4.712 ,      3.977 ,      3.493 ,      3.058 ,      2.529 ,      2.235 ,      2.026 ,      1.359};
 
 double Ypow_B_mumu[100] =    {   2224 ,       2076 ,       1529 ,      964.1 ,      773.6 ,      619.4 ,      483.7 ,      368.4 ,      287.8 ,      217.3 ,      159.6 ,      122.6 ,      94.26 ,      65.02 ,      51.77 ,       38.5 ,      27.81 ,      21.28 ,      17.98 ,      8.825};
 double errYpow_B_mumu[100] = {    26.8 ,      25.88 ,      22.21 ,      17.64 ,      15.74 ,      14.08 ,      12.41 ,      10.77 ,      9.531 ,       8.25 ,      7.032 ,      6.182 ,      5.414 ,      4.457 ,      3.983 ,      3.469 ,      2.995 ,      2.598 ,      2.398 ,      1.662};
 
 double Ypow_B_emu[100] =    {  3.782 ,      3.399 ,      1.592 ,      1.423 ,     0.9448 ,     0.3697 ,     0.1555 ,     0.1056 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0};
 double errYpow_B_emu[100] = {   1.034 ,     0.9972 ,     0.6153 ,     0.5916 ,     0.4854 ,     0.2439 ,     0.1168 ,     0.1056 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0};
 
 double Ypow_B_metReversed_ee[100] =    {  408.4 ,          0 ,          0 ,          0 ,          0 ,          0 ,      46.03 ,      132.5 ,      197.1 ,      245.7 ,      282.5 ,      314.4 ,      338.9 ,      358.4 ,      370.2 ,      380.3 ,      389.2 ,      393.6 ,      396.2 ,      402.5};
 double errYpow_B_metReversed_ee[100] = {    11.53 ,          0 ,          0 ,          0 ,          0 ,          0 ,      3.864 ,      6.645 ,      8.079 ,      8.997 ,      9.613 ,      10.15 ,      10.53 ,      10.83 ,      10.99 ,      11.12 ,      11.25 ,      11.31 ,      11.35 ,      11.45};
 
 double Ypow_B_metReversed_mumu[100] =    {    549.9 ,          0 ,          0 ,          0 ,          0 ,          0 ,      66.17 ,      181.5 ,      262.1 ,      332.6 ,      390.3 ,      427.2 ,      455.6 ,      484.9 ,      498.1 ,      511.4 ,      522.1 ,      528.6 ,      531.9 ,      541.1};
 double errYpow_B_metReversed_mumu[100] = {  13.26 ,          0 ,          0 ,          0 ,          0 ,          0 ,      4.661 ,      7.724 ,      9.212 ,      10.37 ,      11.24 ,      11.73 ,       12.1 ,      12.48 ,      12.64 ,      12.79 ,      12.91 ,         13 ,      13.04 ,      13.15};
 
 double Ypow_B_metReversed_emu[100] =    {   0.3697 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.2142 ,     0.2641 ,     0.3697 ,     0.3697 ,     0.3697 ,     0.3697 ,     0.3697 ,     0.3697 ,     0.3697 ,     0.3697 ,     0.3697 ,     0.3697 ,     0.3697 ,     0.3697};
 double errYpow_B_metReversed_emu[100] = {  0.2439 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.2142 ,     0.2199 ,     0.2439 ,     0.2439 ,     0.2439 ,     0.2439 ,     0.2439 ,     0.2439 ,     0.2439 ,     0.2439 ,     0.2439 ,     0.2439 ,     0.2439 ,     0.2439};
 
 double Ypow_B_metReversed_noLimit_ee[100] =    {    1679 ,      114.1 ,      528.3 ,      969.5 ,       1113 ,       1218 ,       1316 ,       1403 ,       1467 ,       1516 ,       1553 ,       1585 ,       1609 ,       1629 ,       1640 ,       1651 ,       1659 ,       1664 ,       1666 ,       1673};
 double errYpow_B_metReversed_noLimit_ee[100] = {  23.24 ,      6.159 ,      13.08 ,      17.66 ,      18.93 ,      19.75 ,      20.54 ,      21.24 ,      21.73 ,      22.09 ,      22.34 ,      22.58 ,      22.75 ,      22.89 ,      22.97 ,      23.03 ,       23.1 ,      23.13 ,      23.15 ,       23.2};
 
 double Ypow_B_metReversed_noLimit_mumu[100] =    {  2224 ,      147.7 ,      694.3 ,       1259 ,       1450 ,       1604 ,       1740 ,       1855 ,       1936 ,       2006 ,       2064 ,       2101 ,       2129 ,       2159 ,       2172 ,       2185 ,       2196 ,       2202 ,       2206 ,       2215};
 double errYpow_B_metReversed_noLimit_mumu[100] = {    26.8 ,      6.971 ,         15 ,      20.18 ,      21.69 ,       22.8 ,      23.75 ,      24.54 ,      25.05 ,       25.5 ,      25.86 ,      26.08 ,      26.25 ,      26.43 ,       26.5 ,      26.57 ,      26.63 ,      26.67 ,      26.69 ,      26.75};

 double Ypow_B_metReversed_noLimit_emu[100] =    { 3.782 ,     0.3833 ,       2.19 ,       2.36 ,      2.838 ,      3.413 ,      3.627 ,      3.677 ,      3.782 ,      3.782 ,      3.782 ,      3.782 ,      3.782 ,      3.782 ,      3.782 ,      3.782 ,      3.782 ,      3.782 ,      3.782 ,      3.782};
 double errYpow_B_metReversed_noLimit_emu[100] = {    1.034 ,     0.2729 ,     0.8308 ,     0.8478 ,     0.9128 ,      1.005 ,      1.027 ,      1.028 ,      1.034 ,      1.034 ,      1.034 ,      1.034 ,      1.034 ,      1.034 ,      1.034 ,      1.034 ,      1.034 ,      1.034 ,      1.034 ,      1.034};
 
 ///==== ttbar ====
 
 
 double Yttbar_A_ee[100] =    {   37.11 ,      36.72 ,      35.36 ,      33.83 ,      33.13 ,      32.57 ,      31.83 ,      31.08 ,      30.44 ,       29.7 ,      28.95 ,      28.32 ,      27.58 ,      26.83 ,      26.15 ,      25.47 ,      24.75 ,      24.04 ,      23.29 ,      21.37 };
 double errYttbar_A_ee[100] =   {    0.4254 ,     0.4231 ,     0.4153 ,     0.4063 ,      0.402 ,     0.3988 ,     0.3941 ,     0.3894 ,     0.3854 ,     0.3805 ,     0.3757 ,     0.3716 ,     0.3667 ,     0.3615 ,     0.3568 ,     0.3524 ,     0.3474 ,     0.3425 ,      0.337 ,      0.323};
 
 double Yttbar_A_mumu[100] =    {     53.19 ,      52.68 ,      50.88 ,      48.43 ,      47.54 ,      46.63 ,      45.62 ,      44.53 ,       43.5 ,      42.55 ,      41.55 ,      40.56 ,      39.65 ,      38.64 ,      37.66 ,      36.81 ,      35.75 ,      34.71 ,      33.55 ,      30.98};
 double errYttbar_A_mumu[100] =  {     0.508 ,     0.5055 ,     0.4966 ,     0.4844 ,     0.4798 ,     0.4751 ,     0.4698 ,      0.464 ,     0.4584 ,     0.4535 ,      0.448 ,     0.4428 ,     0.4377 ,     0.4319 ,     0.4267 ,     0.4221 ,     0.4162 ,     0.4101 ,     0.4032 ,     0.3875};
 
 double Yttbar_A_emu[100] =      {     94.96 ,      94.29 ,      91.12 ,      86.96 ,      85.41 ,      83.66 ,      81.84 ,      80.16 ,      78.47 ,      76.77 ,      75.08 ,      73.28 ,      71.33 ,      69.49 ,      67.62 ,      65.72 ,      64.11 ,      62.26 ,      60.35 ,      55.56};
 double errYttbar_A_emu[100] = {    0.6793 ,     0.6769 ,     0.6656 ,     0.6503 ,     0.6446 ,     0.6378 ,     0.6307 ,     0.6241 ,     0.6175 ,     0.6107 ,     0.6042 ,      0.597 ,     0.5889 ,     0.5813 ,     0.5735 ,     0.5655 ,     0.5587 ,     0.5506 ,     0.5421 ,     0.5204};
 
 double Yttbar_A_metReversed_ee[100] =     {     32.23 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.3959 ,      1.146 ,      1.795 ,      2.535 ,      3.279 ,      3.911 ,      4.647 ,        5.4 ,      6.082 ,      6.765 ,      7.484 ,       8.19 ,      8.941 ,      10.86};
 double errYttbar_A_metReversed_ee[100] =  {    0.3967 ,          0 ,          0 ,          0 ,          0 ,          0 ,    0.04472 ,    0.07546 ,    0.09382 ,     0.1121 ,     0.1273 ,     0.1388 ,     0.1513 ,     0.1633 ,     0.1732 ,     0.1821 ,     0.1914 ,     0.2001 ,     0.2092 ,     0.2303};
 
 double Yttbar_A_metReversed_mumu[100] =   {     46.07 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.4494 ,       1.54 ,      2.571 ,      3.515 ,      4.522 ,      5.506 ,      6.415 ,       7.43 ,      8.412 ,      9.265 ,      10.32 ,      11.36 ,      12.52 ,      15.09};
 double errYttbar_A_metReversed_mumu[100] = {    0.4721 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.0465 ,     0.0873 ,     0.1129 ,     0.1313 ,      0.149 ,     0.1639 ,     0.1769 ,     0.1906 ,     0.2021 ,     0.2116 ,     0.2229 ,     0.2339 ,     0.2457 ,     0.2697};
 
 double Yttbar_A_metReversed_emu[100] =   {     82.75 ,          0 ,          0 ,          0 ,          0 ,          0 ,      0.917 ,      2.596 ,      4.286 ,       5.98 ,      7.675 ,      9.477 ,      11.42 ,      13.27 ,      15.14 ,      17.03 ,      18.64 ,      20.49 ,       22.4 ,      27.19};
 double errYttbar_A_metReversed_emu[100] = {    0.6343 ,          0 ,          0 ,          0 ,          0 ,          0 ,    0.06731 ,     0.1131 ,     0.1449 ,     0.1713 ,     0.1933 ,     0.2144 ,     0.2356 ,     0.2538 ,     0.2711 ,     0.2873 ,     0.3003 ,     0.3149 ,     0.3294 ,     0.3627};
 
 double Yttbar_A_metReversed_noLimit_ee[100] =     {     37.11 ,     0.3934 ,      1.749 ,      3.278 ,      3.985 ,      4.538 ,      5.278 ,      6.028 ,      6.677 ,      7.417 ,      8.161 ,      8.793 ,      9.529 ,      10.28 ,      10.96 ,      11.65 ,      12.37 ,      13.07 ,      13.82 ,      15.74};
 double errYttbar_A_metReversed_noLimit_ee[100] = {    0.4254 ,    0.04366 ,    0.09189 ,      0.126 ,     0.1391 ,      0.148 ,       0.16 ,     0.1711 ,       0.18 ,     0.1902 ,     0.1995 ,      0.207 ,     0.2156 ,     0.2242 ,     0.2315 ,     0.2383 ,     0.2454 ,     0.2523 ,     0.2595 ,     0.2768};
 
 double Yttbar_A_metReversed_noLimit_mumu[100] =    {     53.19 ,     0.5134 ,      2.308 ,      4.758 ,      5.653 ,      6.556 ,      7.571 ,      8.661 ,      9.692 ,      10.64 ,      11.64 ,      12.63 ,      13.54 ,      14.55 ,      15.53 ,      16.39 ,      17.44 ,      18.48 ,      19.64 ,      22.21};
 double errYttbar_A_metReversed_noLimit_mumu[100] =  {     0.508 ,    0.05092 ,     0.1071 ,     0.1533 ,      0.167 ,       0.18 ,     0.1933 ,     0.2069 ,     0.2189 ,      0.229 ,     0.2396 ,     0.2491 ,     0.2579 ,     0.2675 ,     0.2758 ,     0.2828 ,     0.2914 ,     0.2998 ,     0.3092 ,     0.3286};
 
 double Yttbar_A_metReversed_noLimit_emu[100] =    {     94.96 ,     0.6773 ,       3.84 ,      8.006 ,      9.555 ,      11.31 ,      13.12 ,       14.8 ,      16.49 ,      18.19 ,      19.88 ,      21.68 ,      23.63 ,      25.47 ,      27.34 ,      29.23 ,      30.85 ,       32.7 ,       34.6 ,       39.4};
 double errYttbar_A_metReversed_noLimit_emu[100] = {    0.6793 ,    0.05746 ,     0.1359 ,     0.1966 ,     0.2145 ,     0.2339 ,     0.2524 ,     0.2682 ,     0.2831 ,     0.2975 ,     0.3107 ,     0.3242 ,     0.3386 ,     0.3516 ,     0.3642 ,     0.3765 ,     0.3865 ,     0.3979 ,     0.4095 ,     0.4367};
 
 
 
 double Yttbar_B_ee[100] =     {     39.78 ,      39.32 ,      37.56 ,      35.37 ,      34.45 ,      33.53 ,      32.59 ,      31.66 ,      30.74 ,      29.92 ,      29.01 ,      28.08 ,      27.25 ,      26.33 ,      25.44 ,      24.52 ,      23.54 ,      22.76 ,         22 ,      19.84};
 double errYttbar_B_ee[100] =  {   0.4395 ,      0.437 ,     0.4272 ,      0.415 ,     0.4095 ,     0.4043 ,     0.3985 ,     0.3926 ,     0.3868 ,     0.3816 ,     0.3755 ,     0.3695 ,     0.3639 ,     0.3578 ,     0.3517 ,     0.3452 ,      0.338 ,     0.3326 ,     0.3272 ,     0.3106};
 
 double Yttbar_B_mumu[100] =    {     51.16 ,      50.53 ,      48.22 ,      45.36 ,      44.28 ,      43.12 ,      42.05 ,      40.89 ,      39.75 ,       38.7 ,      37.54 ,      36.46 ,      35.49 ,      34.32 ,       33.3 ,      32.23 ,      31.22 ,      30.12 ,      29.03 ,      26.26};
 double errYttbar_B_mumu[100] =   {    0.4987 ,     0.4956 ,     0.4841 ,     0.4693 ,     0.4638 ,     0.4576 ,      0.452 ,     0.4457 ,     0.4394 ,     0.4338 ,     0.4272 ,     0.4212 ,     0.4155 ,     0.4087 ,     0.4027 ,     0.3963 ,     0.3901 ,     0.3831 ,     0.3759 ,     0.3576};
 
 double Yttbar_B_emu[100] =      {      93.1 ,      91.97 ,      87.83 ,      82.51 ,      80.43 ,       78.4 ,      76.24 ,      74.14 ,      71.95 ,      69.83 ,      67.77 ,      65.74 ,      63.75 ,      61.62 ,      59.53 ,      57.57 ,      55.44 ,      53.55 ,      51.59 ,      46.47};
 double errYttbar_B_emu[100] =  { 0.6731 ,     0.6691 ,     0.6538 ,     0.6336 ,     0.6254 ,     0.6175 ,      0.609 ,     0.6006 ,     0.5915 ,     0.5827 ,     0.5738 ,     0.5653 ,     0.5566 ,     0.5472 ,     0.5376 ,     0.5287 ,     0.5188 ,     0.5098 ,     0.5005 ,     0.4748};
 
 double Yttbar_B_metReversed_ee[100] =    {     33.01 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.4194 ,      1.356 ,      2.272 ,      3.092 ,      3.998 ,      4.928 ,      5.764 ,      6.683 ,       7.57 ,      8.488 ,      9.472 ,      10.25 ,      11.01 ,      13.17};
 double errYttbar_B_metReversed_ee[100] = {  0.401 ,          0 ,          0 ,          0 ,          0 ,          0 ,    0.04494 ,    0.08177 ,     0.1057 ,     0.1234 ,     0.1409 ,     0.1559 ,     0.1686 ,     0.1812 ,     0.1928 ,     0.2041 ,     0.2159 ,     0.2241 ,     0.2319 ,     0.2536};
 
 double Yttbar_B_metReversed_mumu[100] =    {      42.6 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.5542 ,      1.712 ,      2.849 ,        3.9 ,      5.058 ,      6.142 ,      7.113 ,      8.288 ,      9.303 ,      10.38 ,      11.38 ,      12.49 ,      13.57 ,      16.35};
 double errYttbar_B_metReversed_mumu[100] =  { 0.4548 ,          0 ,          0 ,          0 ,          0 ,          0 ,    0.05069 ,    0.09074 ,     0.1173 ,     0.1366 ,      0.156 ,     0.1717 ,      0.185 ,     0.1996 ,     0.2114 ,     0.2232 ,     0.2338 ,     0.2452 ,      0.256 ,      0.281};

 double Yttbar_B_metReversed_emu[100] =    {     77.37 ,          0 ,          0 ,          0 ,          0 ,          0 ,      1.131 ,      3.225 ,      5.415 ,      7.531 ,      9.597 ,      11.62 ,      13.62 ,      15.74 ,      17.83 ,      19.79 ,      21.92 ,      23.81 ,      25.77 ,       30.9};
 double errYttbar_B_metReversed_emu[100] = { 0.6136 ,          0 ,          0 ,          0 ,          0 ,          0 ,    0.07461 ,     0.1255 ,     0.1629 ,     0.1922 ,     0.2173 ,     0.2385 ,     0.2582 ,     0.2776 ,     0.2958 ,     0.3113 ,     0.3276 ,     0.3414 ,     0.3549 ,     0.3886};
 
 double Yttbar_B_metReversed_noLimit_ee[100] =     {     39.78 ,     0.4583 ,      2.225 ,       4.41 ,      5.335 ,       6.25 ,       7.19 ,      8.127 ,      9.042 ,      9.863 ,      10.77 ,       11.7 ,      12.53 ,      13.45 ,      14.34 ,      15.26 ,      16.24 ,      17.02 ,      17.78 ,      19.94};
 double errYttbar_B_metReversed_noLimit_ee[100] =  { 0.4395 ,    0.04685 ,      0.103 ,     0.1446 ,     0.1595 ,     0.1724 ,     0.1853 ,     0.1975 ,     0.2085 ,      0.218 ,     0.2284 ,     0.2379 ,     0.2464 ,     0.2552 ,     0.2636 ,     0.2719 ,     0.2809 ,     0.2873 ,     0.2934 ,     0.3109};
 
 double Yttbar_B_metReversed_noLimit_mumu[100] =    {     51.16 ,     0.6309 ,      2.938 ,      5.801 ,      6.879 ,      8.042 ,      9.113 ,      10.27 ,      11.41 ,      12.46 ,      13.62 ,       14.7 ,      15.67 ,      16.85 ,      17.86 ,      18.94 ,      19.94 ,      21.04 ,      22.13 ,       24.9};
 double errYttbar_B_metReversed_noLimit_mumu[100] =  { 0.4987 ,    0.05524 ,     0.1194 ,     0.1685 ,      0.183 ,     0.1982 ,     0.2106 ,     0.2237 ,     0.2357 ,     0.2459 ,     0.2571 ,      0.267 ,     0.2757 ,     0.2857 ,     0.2941 ,     0.3027 ,     0.3106 ,     0.3192 ,     0.3276 ,     0.3475};
 
 double Yttbar_B_metReversed_noLimit_emu[100] =    {      93.1 ,      1.134 ,      5.268 ,      10.59 ,      12.67 ,       14.7 ,      16.86 ,      18.96 ,      21.15 ,      23.26 ,      25.33 ,      27.35 ,      29.35 ,      31.47 ,      33.56 ,      35.52 ,      37.65 ,      39.54 ,       41.5 ,      46.63};
 double errYttbar_B_metReversed_noLimit_emu[100] = { 0.6731 ,    0.07367 ,     0.1601 ,     0.2273 ,     0.2488 ,     0.2679 ,     0.2867 ,     0.3039 ,     0.3212 ,      0.337 ,     0.3519 ,     0.3654 ,     0.3785 ,      0.392 ,     0.4051 ,     0.4166 ,     0.4289 ,     0.4395 ,     0.4501 ,     0.4771};
 
 
 
 ///==== old, before bug fix ====
 /*
 ///==== madgraph ====
 
 double Ymad_A_ee[100] =    {     28.98 ,      27.19 ,      18.83 ,      13.16 ,      10.09 ,      7.057 ,      5.206 ,      3.335 ,      2.318 ,      1.737 ,      1.721 ,      1.123 ,      1.123 ,      1.123 ,      1.123 ,      1.123 ,    0.07381 ,    0.07381 ,    0.07381 ,          0};
 double errYmad_A_ee[100] = { 3.734 ,      3.635 ,       3.01 ,      2.494 ,       2.21 ,      1.811 ,      1.536 ,      1.175 ,      1.079 ,      0.976 ,     0.9759 ,     0.8613 ,     0.8613 ,     0.8613 ,     0.8613 ,     0.8613 ,    0.07381 ,    0.07381 ,    0.07381 ,          0}; 
 
 double Ymad_A_mumu[100] =    {     168.9 ,        159 ,      122.1 ,      80.36 ,      63.69 ,      53.55 ,      42.64 ,      35.61 ,      25.39 ,      20.37 ,      16.62 ,      13.83 ,      11.47 ,      9.138 ,      8.623 ,      6.592 ,       4.89 ,      3.702 ,       2.95 ,       2.72};
 double errYmad_A_mumu[100] = {8.894 ,        8.6 ,      7.651 ,      6.294 ,      5.573 ,      5.151 ,      4.574 ,      4.152 ,      3.397 ,      3.058 ,      2.732 ,       2.56 ,      2.288 ,      2.125 ,       2.09 ,      1.822 ,      1.673 ,      1.402 ,      1.306 ,       1.29}; 
 
 double Ymad_A_emu[100] =    {7.832 ,      7.002 ,      5.115 ,       3.11 ,      3.093 ,      2.079 ,      1.286 ,     0.8745 ,     0.8052 ,     0.8052 ,     0.8052 ,      0.368 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0};
 double errYmad_A_emu[100] = {3.63 ,      3.288 ,      2.589 ,      2.244 ,      2.228 ,      2.228 ,      1.545 ,      1.177 ,      1.126 ,     0.8916 ,     0.7814 ,     0.7814 ,     0.7814 ,     0.7814 ,    0.06929 ,    0.06929 ,          0 ,          0 ,          0 ,          0};
 
 double Ymad_A_metReversed_ee[100] =    { 6.317 ,          0 ,          0 ,          0 ,          0 ,          0 ,      1.111 ,      2.982 ,      3.999 ,      4.579 ,      4.596 ,      5.194 ,      5.194 ,      5.194 ,      5.194 ,      5.194 ,      6.243 ,      6.243 ,      6.243 ,      6.317};
 double errYmad_A_metReversed_ee[100] = { 1.75 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.8394 ,      1.297 ,      1.378 ,      1.453 ,      1.453 ,      1.524 ,      1.524 ,      1.524 ,      1.524 ,      1.524 ,      1.749 ,      1.749 ,      1.749 ,       1.75};
 
 double Ymad_A_metReversed_mumu[100] =    {48.12 ,          0 ,          0 ,          0 ,          0 ,          0 ,      5.486 ,      12.51 ,      22.74 ,      27.75 ,      31.51 ,       34.3 ,      36.66 ,      38.99 ,       39.5 ,      41.53 ,      43.23 ,      44.42 ,      45.17 ,       45.4};
 double errYmad_A_metReversed_mumu[100] = { 4.871 ,          0 ,          0 ,          0 ,          0 ,          0 ,      1.675 ,      2.546 ,      3.491 ,      3.791 ,      4.032 ,      4.144 ,        4.3 ,      4.383 ,        4.4 ,      4.517 ,      4.574 ,      4.665 ,      4.692 ,      4.697};
 
 double Ymad_A_metReversed_noLimit_ee[100] =    { 28.98 ,      1.787 ,      10.15 ,      15.82 ,      18.89 ,      21.92 ,      23.77 ,      25.64 ,      26.66 ,      27.24 ,      27.26 ,      27.86 ,      27.86 ,      27.86 ,      27.86 ,      27.86 ,      28.91 ,      28.91 ,      28.91 ,      28.98 };
 double errYmad_A_metReversed_noLimit_ee[100] = {    3.734 ,     0.8507 ,      2.209 ,      2.778 ,      3.009 ,      3.265 ,      3.403 ,      3.544 ,      3.574 ,      3.604 ,      3.604 ,      3.633 ,      3.633 ,      3.633 ,      3.633 ,      3.633 ,      3.733 ,      3.733 ,      3.733 ,      3.734};
 
 double Ymad_A_metReversed_noLimit_mumu[100] =    { 168.9 ,      9.937 ,      46.86 ,      88.59 ,      105.3 ,      115.4 ,      126.3 ,      133.3 ,      143.6 ,      148.6 ,      152.3 ,      155.1 ,      157.5 ,      159.8 ,      160.3 ,      162.4 ,      164.1 ,      165.2 ,        166 ,      166.2};
 double errYmad_A_metReversed_noLimit_mumu[100] = {8.894 ,      2.267 ,      4.534 ,      6.284 ,      6.931 ,       7.25 ,      7.628 ,      7.865 ,       8.22 ,      8.351 ,      8.464 ,      8.517 ,      8.594 ,      8.636 ,      8.645 ,      8.705 ,      8.735 ,      8.782 ,      8.797 ,        8.8};
 
 
 double Ymad_B_ee[100] =    {  520.5 ,      487.2 ,      342.3 ,      213.1 ,      174.2 ,      130.1 ,      100.6 ,      81.96 ,      64.19 ,      50.37 ,      36.19 ,      27.05 ,      20.56 ,      17.16 ,      12.88 ,      8.699 ,       5.33 ,      4.515 ,      3.754 ,      2.493};
 double errYmad_B_ee[100] = { 13.02    ,   12.61  ,     10.51    ,   8.272  ,     7.492  ,     6.407  ,     5.642   ,    5.092   ,    4.531   ,    4.013    ,    3.37   ,    2.896   ,    2.563   ,    2.354  ,     2.042,       1.674     ,  1.273  ,     1.214 ,      1.133    ,  0.9518};
 
 double Ymad_B_mumu[100] =    {  2428 ,       2269 ,       1644 ,       1035 ,      830.9 ,      653.3 ,      519.3 ,      398.3 ,      309.3 ,      233.5 ,      175.2 ,      132.5 ,        103 ,      75.63 ,      57.45 ,      43.48 ,      32.48 ,      26.23 ,      22.99 ,      12.44};
 double errYmad_B_mumu[100] = {28.18  ,     27.26    ,   23.14    ,   18.33   ,    16.37   ,    14.48    ,   12.88   ,    11.24    ,    9.89  ,     8.517     ,  7.334     ,  6.328    ,   5.561   ,    4.777   ,    4.174  ,     3.635  ,     3.152  ,    2.884    ,   2.739  ,     2.023};
 
 double Ymad_B_emu[100] =    { 3.63 ,      3.288 ,      2.589 ,      2.244 ,      2.228 ,      2.228 ,      1.545 ,      1.177 ,      1.126 ,     0.8916 ,     0.7814 ,     0.7814 ,     0.7814 ,     0.7814 ,    0.06929 ,    0.06929 ,          0 ,          0 ,          0 ,          0};
 double errYmad_B_emu[100] = {  1.057    ,  0.9999    ,  0.8818   ,   0.8474    ,  0.8472    ,  0.8472  ,    0.6799     , 0.5717    ,  0.5695   ,   0.5188    ,   0.507    ,   0.507     ,  0.507    ,   0.507 ,    0.06929  ,   0.06929   ,        0   ,        0       ,    0       ,    0};
 
 double Ymad_B_metReversed_ee[100] =    {   113.8 ,          0 ,          0 ,          0 ,          0 ,          0 ,      13.22 ,      31.89 ,      49.66 ,      63.47 ,      77.66 ,      86.79 ,      93.29 ,      96.68 ,        101 ,      105.1 ,      108.5 ,      109.3 ,      110.1 ,      111.4};
 double errYmad_B_metReversed_ee[100] = { 6.007       ,    0        ,   0        ,   0    ,       0   ,        0   ,    2.061  ,     3.186    ,   3.944    ,    4.47   ,    4.972  ,     5.263  ,     5.433  ,     5.526    ,   5.649   ,    5.769 ,      5.871 ,      5.883   ,    5.899   ,    5.931};
 
 double Ymad_B_metReversed_mumu[100] =    {  583.5 ,          0 ,          0 ,          0 ,          0 ,          0 ,      64.17 ,      185.2 ,      274.2 ,        350 ,      408.2 ,      450.9 ,      480.5 ,      507.8 ,        526 ,        540 ,        551 ,      557.2 ,      560.5 ,        571};
 double errYmad_B_metReversed_mumu[100] = {13.68  ,         0    ,       0   ,        0       ,    0   ,        0    ,    4.59  ,     7.799     ,  9.448    ,    10.7   ,    11.55     ,  12.13    ,    12.5 ,      12.82     ,  13.03     ,  13.19   ,    13.31     ,  13.37  ,     13.4   ,    13.53};
 
 double Ymad_B_metReversed_noLimit_ee[100] =    { 520.5 ,      33.29 ,      178.2 ,      307.4 ,      346.4 ,      390.4 ,      419.9 ,      438.6 ,      456.3 ,      470.2 ,      484.3 ,      493.5 ,        500 ,      503.4 ,      507.7 ,      511.8 ,      515.2 ,        516 ,      516.8 ,        518};
 double errYmad_B_metReversed_noLimit_ee[100] = { 13.02 ,      3.213 ,      7.675 ,      10.05 ,      10.64 ,      11.33 ,      11.73 ,      11.98 ,       12.2 ,      12.38 ,      12.57 ,      12.69 ,      12.76 ,       12.8 ,      12.86 ,      12.91 ,      12.95 ,      12.96 ,      12.97 ,      12.98};
 
 double Ymad_B_metReversed_noLimit_mumu[100] =    {  2428 ,      158.8 ,      783.9 ,       1393 ,       1597 ,       1775 ,       1909 ,       2030 ,       2119 ,       2195 ,       2253 ,       2296 ,       2325 ,       2352 ,       2371 ,       2385 ,       2396 ,       2402 ,       2405 ,       2416};
 double errYmad_B_metReversed_noLimit_mumu[100] = { 28.18 ,      7.164 ,      16.08 ,      21.41 ,      22.94 ,      24.18 ,      25.07 ,      25.85 ,      26.39 ,      26.87 ,      27.21 ,      27.46 ,      27.63 ,      27.78 ,      27.87 ,      27.95 ,      28.01 ,      28.04 ,      28.05 ,      28.11};
 
 ///==== powheg ====
 
//  double Ypow_A_ee[100] =    {   21.99 ,      19.99 ,      14.75 ,      8.669 ,      6.539 ,      4.344 ,      2.912 ,      2.593 ,      2.165 ,       1.14 ,     0.9668 ,      0.827 ,     0.4178 ,     0.3975 ,     0.3975 ,     0.3975 ,     0.3298 ,    0.08327 ,    0.01116 ,    0.01116};
//  double errYpow_A_ee[100] = { 2.613 ,      2.483 ,      2.173 ,      1.582 ,      1.352 ,      1.104 ,     0.9242 ,     0.8878 ,     0.7845 ,     0.4777 ,      0.461 ,     0.4503 ,     0.2667 ,     0.2659 ,     0.2659 ,     0.2659 ,     0.2571 ,    0.07297 ,    0.01116 ,    0.01116}; 
 double Ypow_A_ee[100] =    {  23.06 ,      21.06 ,       15.4 ,      8.884 ,      6.753 ,      4.558 ,      3.126 ,      2.593 ,      2.165 ,       1.14 ,     0.9668 ,      0.827 ,     0.4178 ,     0.3975 ,     0.3975 ,     0.3975 ,     0.3298 ,    0.08327 ,    0.01116 ,    0.01116};
 double errYpow_A_ee[100] = {2.656 ,      2.529 ,      2.205 ,      1.596 ,      1.369 ,      1.124 ,     0.9487 ,     0.8878 ,     0.7845 ,     0.4777 ,      0.461 ,     0.4503 ,     0.2667 ,     0.2659 ,     0.2659 ,     0.2659 ,     0.2571 ,    0.07297 ,    0.01116 ,    0.01116}; 
 
 double Ypow_A_mumu[100] =    {     164.6 ,      154.3 ,      120.4 ,      78.41 ,      64.31 ,      53.74 ,       42.4 ,      33.36 ,      25.65 ,      19.17 ,       15.2 ,      10.21 ,      8.196 ,      6.592 ,      5.106 ,      3.899 ,      3.016 ,      1.681 ,      1.237 ,     0.2346};
 double errYpow_A_mumu[100] = {   7.939 ,      7.689 ,      6.851 ,      5.491 ,      4.965 ,      4.557 ,      4.056 ,       3.63 ,      3.123 ,      2.645 ,       2.42 ,      2.029 ,      1.867 ,      1.634 ,      1.457 ,      1.118 ,      1.001 ,     0.6549 ,     0.5744 ,     0.2151}; 
 
 double Ypow_A_emu[100] =    { 8.047 ,      8.047 ,       6.13 ,      3.979 ,      3.123 ,      2.909 ,       2.48 ,      1.838 ,      1.623 ,     0.7668 ,     0.5526 ,     0.5526 ,     0.5526 ,     0.5526 ,     0.5526 ,     0.5526 ,     0.3384 ,     0.2304 ,     0.2304 ,          0};
 double errYpow_A_emu[100] = { 1.331 ,      1.331 ,      1.129 ,      0.919 ,     0.8131 ,     0.7843 ,     0.7235 ,     0.6212 ,     0.5831 ,     0.3956 ,     0.3326 ,     0.3326 ,     0.3326 ,     0.3326 ,     0.3326 ,     0.3326 ,     0.2544 ,     0.2304 ,     0.2304 ,          0};
 
 double Ypow_A_metReversed_ee[100] =    { 3.47 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.3442 ,     0.8771 ,      1.306 ,      2.331 ,      2.503 ,      2.643 ,      3.052 ,      3.073 ,      3.073 ,      3.073 ,       3.14 ,      3.387 ,      3.459 ,      3.459};
 double errYpow_A_metReversed_ee[100] = {  0.979 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.2419 ,     0.4128 ,     0.5857 ,     0.8546 ,     0.8637 ,     0.8693 ,      0.942 ,     0.9422 ,     0.9422 ,     0.9422 ,     0.9446 ,     0.9763 ,      0.979 ,      0.979};
 
 double Ypow_A_metReversed_mumu[100] =    {49.74 ,          0 ,          0 ,          0 ,          0 ,          0 ,      7.339 ,      16.37 ,      24.08 ,      30.57 ,      34.54 ,      39.53 ,      41.54 ,      43.15 ,      44.63 ,      45.84 ,      46.72 ,      48.06 ,       48.5 ,       49.5};
 double errYpow_A_metReversed_mumu[100] = {4.424 ,          0 ,          0 ,          0 ,          0 ,          0 ,      1.766 ,      2.528 ,      3.132 ,      3.545 ,      3.703 ,      3.931 ,       4.01 ,      4.111 ,      4.177 ,       4.28 ,      4.309 ,      4.375 ,      4.386 ,      4.418};
 
 double Ypow_A_metReversed_noLimit_ee[100] =    { 23.06 ,      2.004 ,      7.663 ,      14.18 ,      16.31 ,       18.5 ,      19.93 ,      20.47 ,       20.9 ,      21.92 ,      22.09 ,      22.23 ,      22.64 ,      22.66 ,      22.66 ,      22.66 ,      22.73 ,      22.98 ,      23.05 ,      23.05};
 double errYpow_A_metReversed_noLimit_ee[100] = { 2.656 ,     0.8127 ,      1.482 ,      2.123 ,      2.276 ,      2.407 ,      2.481 ,      2.503 ,      2.538 ,      2.613 ,      2.616 ,      2.618 ,      2.643 ,      2.643 ,      2.643 ,      2.643 ,      2.644 ,      2.655 ,      2.656 ,      2.656};
 
 double Ypow_A_metReversed_noLimit_mumu[100] =    { 164.6 ,      10.25 ,       44.2 ,      86.15 ,      100.3 ,      110.8 ,      122.2 ,      131.2 ,      138.9 ,      145.4 ,      149.4 ,      154.4 ,      156.4 ,        158 ,      159.5 ,      160.7 ,      161.5 ,      162.9 ,      163.3 ,      164.3};
 double errYpow_A_metReversed_noLimit_mumu[100] = {  7.939 ,      1.979 ,      4.012 ,      5.735 ,      6.196 ,      6.502 ,      6.825 ,      7.061 ,      7.299 ,      7.486 ,      7.562 ,      7.676 ,      7.717 ,      7.769 ,      7.805 ,       7.86 ,      7.876 ,      7.912 ,      7.919 ,      7.937};
 
 
 
//  double Ypow_B_ee[100] =    { 480.8 ,      445.5 ,      324.3 ,      193.2 ,      152.1 ,      122.5 ,      90.84 ,      68.24 ,      50.59 ,      39.79 ,      26.51 ,      19.25 ,      12.99 ,      9.364 ,       7.53 ,      6.197 ,      3.954 ,      3.382 ,      3.136 ,      0.813};
//  double errYpow_B_ee[100] = {  12.46 ,      11.97 ,      10.21 ,      7.949 ,      7.031 ,      6.399 ,      5.492 ,      4.729 ,      4.041 ,      3.547 ,      2.865 ,       2.44 ,      2.014 ,      1.725 ,      1.557 ,      1.442 ,      1.131 ,      1.078 ,      1.053 ,     0.3798};
 double Ypow_B_ee[100] =    {481 ,      445.8 ,      324.5 ,      193.5 ,      152.3 ,      122.7 ,      91.06 ,      68.45 ,      50.81 ,         40 ,      26.73 ,      19.47 ,      12.99 ,      9.364 ,       7.53 ,      6.197 ,      3.954 ,      3.382 ,      3.136 ,      0.813};
 double errYpow_B_ee[100] = { 12.47     ,  11.98      , 10.21  ,     7.952   ,    7.034     ,  6.403      , 5.496  ,     4.734  ,     4.047     ,  3.553   ,    2.873   ,   2.449      , 2.014    ,   1.725    ,   1.557,       1.442     ,  1.131    ,   1.078    ,   1.053   ,   0.3798};
 
 double Ypow_B_mumu[100] =    {   2224 ,       2076 ,       1529 ,      963.7 ,      773.6 ,      619.6 ,      483.8 ,      368.5 ,      287.9 ,      217.4 ,      159.6 ,      122.6 ,      94.26 ,      65.02 ,      51.77 ,       38.5 ,      27.81 ,      21.28 ,      17.98 ,      8.825};
 double errYpow_B_mumu[100] = {   26.8   ,    25.88    ,   22.21   ,    17.63   ,    15.74   ,    14.08    ,   12.41,       10.77    ,   9.531   ,     8.25   ,    7.032 ,      6.182    ,   5.414,       4.457 ,      3.983 ,      3.469 ,      2.995     ,  2.598 ,      2.398 ,      1.662};
 
 double Ypow_B_emu[100] =    {  1.643 ,       1.26 ,     0.6334 ,     0.6334 ,     0.1555 ,     0.1555 ,     0.1555 ,     0.1056 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0 ,          0};
 double errYpow_B_emu[100] = {   0.6632   ,   0.6045   ,  0.3578     , 0.3578   ,  0.1168   ,   0.1168 ,     0.1168  ,    0.1056      ,     0    ,       0       ,    0   ,        0        ,   0       ,    0      ,     0       ,    0        ,   0       ,    0        ,   0      ,     0};
 
 double Ypow_B_metReversed_ee[100] =    {   104.7 ,          0 ,          0 ,          0 ,          0 ,          0 ,      13.64 ,      36.24 ,      53.89 ,      64.69 ,      77.97 ,      85.23 ,      91.71 ,      95.33 ,      97.16 ,       98.5 ,      100.7 ,      101.3 ,      101.6 ,      103.9};
 double errYpow_B_metReversed_ee[100] = {      5.887       ,   0 ,          0      ,     0 ,          0      ,     0 ,       2.11,         3.5   ,   4.276 ,      4.694    ,   5.139     ,  5.354  ,     5.532  ,     5.629 ,      5.678 ,      5.708     ,  5.778    ,   5.788  ,     5.792    ,  5.875};
 
 double Ypow_B_metReversed_mumu[100] =    {    550 ,          0 ,          0 ,          0 ,          0 ,          0 ,      66.17 ,      181.5 ,      262.1 ,      332.7 ,      390.4 ,      427.4 ,      455.8 ,        485 ,      498.3 ,      511.5 ,      522.2 ,      528.7 ,        532 ,      541.2};
 double errYpow_B_metReversed_mumu[100] = { 13.26      ,     0  ,         0     ,      0       ,    0  ,        0   ,    4.661   ,    7.724  ,     9.212     ,  10.38  ,     11.24   ,    11.73    ,    12.1 ,      12.48  ,     12.64     ,  12.79 ,      12.91   ,       13  ,     13.04  ,     13.15};
 
 double Ypow_B_metReversed_noLimit_ee[100] =    { 481 ,      35.25 ,      156.5 ,      287.6 ,      328.7 ,      358.3 ,        390 ,      412.6 ,      430.2 ,        441 ,      454.3 ,      461.5 ,        468 ,      471.7 ,      473.5 ,      474.8 ,      477.1 ,      477.6 ,      477.9 ,      480.2};
 double errYpow_B_metReversed_noLimit_ee[100] = {  12.47 ,      3.463 ,      7.148 ,      9.601 ,      10.29 ,       10.7 ,      11.19 ,      11.53 ,      11.79 ,      11.95 ,      12.13 ,      12.22 ,       12.3 ,      12.35 ,      12.37 ,      12.38 ,      12.42 ,      12.42 ,      12.42 ,      12.46};
 
 double Ypow_B_metReversed_noLimit_mumu[100] =    {2224 ,      147.7 ,      694.7 ,       1260 ,       1450 ,       1604 ,       1740 ,       1855 ,       1936 ,       2006 ,       2064 ,       2101 ,       2130 ,       2159 ,       2172 ,       2185 ,       2196 ,       2203 ,       2206 ,       2215};
 double errYpow_B_metReversed_noLimit_mumu[100] = {  26.8 ,      6.971 ,         15 ,      20.18 ,      21.69 ,       22.8 ,      23.75 ,      24.54 ,      25.05 ,       25.5 ,      25.86 ,      26.08 ,      26.25 ,      26.43 ,       26.5 ,      26.57 ,      26.63 ,      26.67 ,      26.69 ,      26.75};
 
 ///==== ttbar ====
 
 double Yttbar_A_ee[100] =    { 11.23 ,      11.08 ,      10.61 ,      10.18 ,      9.975 ,      9.798 ,      9.605 ,      9.407 ,      9.226 ,       8.97 ,       8.67 ,      8.443 ,      8.193 ,      7.899 ,        7.7 ,      7.469 ,      7.264 ,      7.084 ,      6.836 ,      6.264};
 double errYttbar_A_ee[100] = {  0.234 ,     0.2324 ,     0.2272 ,     0.2227 ,     0.2207 ,     0.2189 ,     0.2167 ,     0.2146 ,     0.2127 ,     0.2097 ,     0.2062 ,     0.2035 ,     0.2003 ,     0.1966 ,     0.1942 ,     0.1913 ,     0.1886 ,     0.1863 ,      0.183 ,     0.1752}; 
 
 double Yttbar_A_mumu[100] =    {  53.26 ,      52.74 ,      50.94 ,      48.49 ,       47.6 ,      46.69 ,      45.67 ,      44.58 ,      43.55 ,      42.61 ,       41.6 ,      40.61 ,      39.71 ,      38.69 ,       37.7 ,      36.85 ,      35.79 ,      34.75 ,      33.59 ,      31.01};
 double errYttbar_A_mumu[100] = { 0.5083 ,     0.5058 ,     0.4969 ,     0.4846 ,       0.48 ,     0.4753 ,     0.4701 ,     0.4642 ,     0.4587 ,     0.4537 ,     0.4482 ,      0.443 ,      0.438 ,     0.4321 ,     0.4269 ,     0.4223 ,     0.4164 ,     0.4104 ,     0.4034 ,     0.3877}; 
 
 double Yttbar_A_emu[100] =    {  51.45 ,      51.03 ,      49.26 ,         47 ,      46.12 ,      45.18 ,      44.25 ,      43.34 ,      42.42 ,      41.42 ,      40.49 ,      39.44 ,      38.45 ,      37.41 ,      36.43 ,      35.45 ,      34.54 ,       33.5 ,      32.49 ,      29.95};
 double errYttbar_A_emu[100] = { 0.4991 ,      0.497 ,     0.4883 ,     0.4771 ,     0.4727 ,     0.4678 ,     0.4631 ,     0.4582 ,     0.4533 ,     0.4478 ,     0.4428 ,     0.4371 ,     0.4316 ,     0.4257 ,     0.4202 ,     0.4147 ,     0.4094 ,     0.4032 ,      0.397 ,     0.3815};
 
 double Yttbar_A_metReversed_ee[100] =    { 9.715 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.1093 ,     0.3076 ,     0.4883 ,     0.7444 ,      1.045 ,      1.271 ,      1.522 ,      1.816 ,      2.014 ,      2.246 ,      2.451 ,      2.631 ,      2.879 ,      3.451};
 double errYttbar_A_metReversed_ee[100] = {  0.2179 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.0232 ,    0.03804 ,     0.0472 ,    0.05934 ,    0.07053 ,      0.078 ,    0.08569 ,    0.09391 ,    0.09888 ,     0.1044 ,     0.1092 ,      0.113 ,     0.1182 ,     0.1296};
 
 double Yttbar_A_metReversed_mumu[100] =    {    46.12 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.4497 ,      1.541 ,      2.572 ,      3.516 ,      4.523 ,      5.508 ,      6.417 ,      7.438 ,      8.424 ,      9.277 ,      10.33 ,      11.37 ,      12.53 ,      15.11};
 double errYttbar_A_metReversed_mumu[100] = {0.4724 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.0465 ,     0.0873 ,     0.1129 ,     0.1313 ,      0.149 ,     0.1639 ,     0.1769 ,     0.1907 ,     0.2022 ,     0.2117 ,      0.223 ,     0.2339 ,     0.2458 ,     0.2699};
 
 double Yttbar_A_metReversed_noLimit_ee[100] =    { 11.23 ,     0.1472 ,     0.6207 ,      1.047 ,      1.254 ,      1.431 ,      1.624 ,      1.822 ,      2.003 ,      2.259 ,       2.56 ,      2.786 ,      3.036 ,       3.33 ,      3.529 ,      3.761 ,      3.966 ,      4.145 ,      4.393 ,      4.966};
 double errYttbar_A_metReversed_noLimit_ee[100] = { 0.234 ,    0.02726 ,    0.05573 ,    0.07161 ,    0.07776 ,    0.08264 ,     0.0883 ,    0.09331 ,     0.0974 ,     0.1038 ,     0.1106 ,     0.1155 ,     0.1208 ,     0.1268 ,     0.1305 ,     0.1347 ,     0.1385 ,     0.1415 ,     0.1457 ,     0.1551};
 
 double Yttbar_A_metReversed_noLimit_mumu[100] =    {  53.26 ,     0.5134 ,      2.314 ,      4.769 ,      5.663 ,      6.568 ,      7.586 ,      8.678 ,      9.709 ,      10.65 ,      11.66 ,      12.64 ,      13.55 ,      14.57 ,      15.56 ,      16.41 ,      17.47 ,      18.51 ,      19.67 ,      22.25};
 double errYttbar_A_metReversed_noLimit_mumu[100] = {    0.5083 ,    0.05092 ,     0.1072 ,     0.1535 ,     0.1671 ,     0.1801 ,     0.1935 ,     0.2071 ,     0.2191 ,     0.2291 ,     0.2397 ,     0.2492 ,      0.258 ,     0.2676 ,     0.2759 ,      0.283 ,     0.2915 ,        0.3 ,     0.3093 ,     0.3288};
 
 
 double Yttbar_B_ee[100] =    { 11.86 ,      11.74 ,      11.17 ,      10.48 ,      10.15 ,      9.873 ,      9.596 ,      9.351 ,      9.076 ,      8.828 ,      8.583 ,      8.289 ,       8.03 ,      7.788 ,      7.519 ,      7.307 ,      7.036 ,      6.774 ,      6.562 ,      5.932};
 double errYttbar_B_ee[100] = { 0.2394 ,     0.2382 ,     0.2322 ,     0.2246 ,     0.2209 ,     0.2179 ,     0.2149 ,      0.212 ,     0.2088 ,     0.2058 ,      0.203 ,     0.1995 ,     0.1963 ,     0.1934 ,     0.1901 ,     0.1875 ,     0.1839 ,     0.1807 ,     0.1781 ,     0.1695};
 
 double Yttbar_B_mumu[100] =    {  51.25 ,      50.61 ,      48.31 ,      45.44 ,      44.36 ,      43.19 ,      42.12 ,      40.96 ,      39.82 ,      38.76 ,       37.6 ,      36.52 ,      35.55 ,      34.37 ,      33.34 ,      32.26 ,      31.26 ,      30.16 ,      29.07 ,      26.29};
 double errYttbar_B_mumu[100] = {   0.499 ,      0.496 ,     0.4846 ,     0.4697 ,     0.4642 ,      0.458 ,     0.4523 ,      0.446 ,     0.4398 ,     0.4341 ,     0.4276 ,     0.4215 ,     0.4158 ,      0.409 ,     0.4029 ,     0.3965 ,     0.3904 ,     0.3834 ,     0.3762 ,     0.3579};
 
 double Yttbar_B_emu[100] =    {  50.38 ,      49.78 ,      47.61 ,      44.62 ,      43.36 ,      42.25 ,      41.13 ,      39.95 ,      38.81 ,       37.6 ,      36.51 ,      35.41 ,      34.34 ,      33.28 ,      32.15 ,      31.11 ,      29.97 ,      28.94 ,       27.8 ,      25.02};
 double errYttbar_B_emu[100] = { 0.4952 ,     0.4923 ,     0.4815 ,     0.4661 ,     0.4593 ,     0.4534 ,     0.4474 ,     0.4408 ,     0.4344 ,     0.4276 ,     0.4213 ,      0.415 ,     0.4085 ,     0.4023 ,     0.3951 ,     0.3886 ,     0.3812 ,     0.3745 ,     0.3669 ,     0.3478};
 
 double Yttbar_B_metReversed_ee[100] =    {   9.732 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.1361 ,     0.3802 ,     0.6556 ,     0.9034 ,      1.149 ,      1.442 ,      1.702 ,      1.943 ,      2.212 ,      2.424 ,      2.696 ,      2.958 ,       3.17 ,      3.799};
 double errYttbar_B_metReversed_ee[100] = {  0.2164 ,          0 ,          0 ,          0 ,          0 ,          0 ,    0.02621 ,    0.04341 ,    0.05712 ,    0.06702 ,    0.07518 ,    0.08387 ,    0.09125 ,    0.09726 ,     0.1034 ,     0.1081 ,     0.1142 ,     0.1191 ,      0.123 ,     0.1345};
 
 double Yttbar_B_metReversed_mumu[100] =    {    42.67 ,          0 ,          0 ,          0 ,          0 ,          0 ,     0.5542 ,      1.712 ,      2.857 ,      3.909 ,       5.07 ,      6.154 ,      7.127 ,      8.303 ,      9.332 ,      10.41 ,      11.41 ,      12.51 ,       13.6 ,      16.38};
 double errYttbar_B_metReversed_mumu[100] = { 0.4552 ,          0 ,          0 ,          0 ,          0 ,          0 ,    0.05069 ,    0.09074 ,     0.1174 ,     0.1368 ,     0.1561 ,     0.1719 ,     0.1851 ,     0.1997 ,     0.2118 ,     0.2236 ,     0.2341 ,     0.2454 ,     0.2562 ,     0.2813};
 
 double Yttbar_B_metReversed_noLimit_ee[100] =    {  11.86 ,      0.118 ,     0.6927 ,      1.385 ,       1.71 ,      1.989 ,      2.266 ,       2.51 ,      2.786 ,      3.033 ,      3.279 ,      3.572 ,      3.832 ,      4.074 ,      4.342 ,      4.554 ,      4.826 ,      5.088 ,        5.3 ,      5.929};
 double errYttbar_B_metReversed_noLimit_ee[100] = {  0.2394 ,    0.02419 ,    0.05843 ,    0.08292 ,    0.09234 ,    0.09913 ,     0.1057 ,     0.1112 ,     0.1172 ,     0.1223 ,      0.127 ,     0.1323 ,     0.1371 ,     0.1412 ,     0.1455 ,     0.1489 ,     0.1534 ,     0.1571 ,       0.16 ,     0.1691};
 
 double Yttbar_B_metReversed_noLimit_mumu[100] =    { 51.25 ,     0.6309 ,      2.936 ,      5.807 ,      6.887 ,      8.052 ,      9.128 ,      10.29 ,      11.43 ,      12.48 ,      13.64 ,      14.73 ,       15.7 ,      16.88 ,      17.91 ,      18.98 ,      19.99 ,      21.09 ,      22.18 ,      24.95};
 double errYttbar_B_metReversed_noLimit_mumu[100] = {     0.499 ,    0.05524 ,     0.1193 ,     0.1685 ,     0.1831 ,     0.1983 ,     0.2107 ,     0.2238 ,     0.2359 ,     0.2461 ,     0.2573 ,     0.2672 ,     0.2759 ,     0.2859 ,     0.2944 ,      0.303 ,     0.3109 ,     0.3195 ,     0.3279 ,     0.3478};
 
 */
 
 
 
 ///==== draw ====
 
 ///==== ratio (N)
 
 ///==== ratio ====
 
 ///==== powheg ====
 
 double Ratio_powmumu [100];
 double errRatio_powmumu [100];
 double Ratio_powee [100];
 double errRatio_powee [100];
 
 for (int i=0; i<num; i++) {  
  if (Ypow_B_mumu[i] != 0) Ratio_powmumu[i] = Ypow_A_mumu[i] / Ypow_B_mumu[i];
  if (Ypow_B_mumu[i] != 0) errRatio_powmumu[i] = sqrt(errYpow_A_mumu[i] * errYpow_A_mumu[i] / Ypow_B_mumu[i] / Ypow_B_mumu[i] + Ypow_A_mumu[i] / Ypow_B_mumu[i] * Ypow_A_mumu[i] / Ypow_B_mumu[i] / Ypow_B_mumu[i] / Ypow_B_mumu[i] * errYpow_B_mumu[i] * errYpow_B_mumu[i]) ;
  
  if (Ypow_B_ee[i] != 0) Ratio_powee[i] = Ypow_A_ee[i] / Ypow_B_ee[i];
  if (Ypow_B_ee[i] != 0) errRatio_powee[i] = sqrt(errYpow_A_ee[i] * errYpow_A_ee[i] / Ypow_B_ee[i] / Ypow_B_ee[i] + Ypow_A_ee[i] / Ypow_B_ee[i] * Ypow_A_ee[i] / Ypow_B_ee[i] / Ypow_B_ee[i] / Ypow_B_ee[i] * errYpow_B_ee[i] * errYpow_B_ee[i]) ;
 }
 
 TGraphErrors* grRatio_powmumu = new TGraphErrors(num,X,Ratio_powmumu,errX,errRatio_powmumu);
 grRatio_powmumu->SetTitle("DY #mu#mu @reco powheg");
 grRatio_powmumu->GetXaxis()->SetTitle("met threshold (GeV)");
 grRatio_powmumu->GetYaxis()->SetTitle("Ratio");
 grRatio_powmumu->SetMarkerColor(kOrange);
 grRatio_powmumu->SetFillColor(kOrange);
 grRatio_powmumu->SetLineColor(kOrange);
 grRatio_powmumu->SetMarkerStyle(20+2);
 grRatio_powmumu->SetMarkerSize(1);
 grRatio_powmumu->SetLineWidth(2);
 
 TGraphErrors* grRatio_powee = new TGraphErrors(num,X,Ratio_powee,errX,errRatio_powee);
 grRatio_powee->SetTitle("DY ee @reco powheg");
 grRatio_powee->GetXaxis()->SetTitle("met threshold (GeV)");
 grRatio_powee->GetYaxis()->SetTitle("Ratio");
 grRatio_powee->SetMarkerColor(kTeal);
 grRatio_powee->SetFillColor(kTeal);
 grRatio_powee->SetLineColor(kTeal);
 grRatio_powee->SetMarkerStyle(21+2);
 grRatio_powee->SetMarkerSize(1);
 grRatio_powee->SetLineWidth(1);
 
 
 ///==== madgraph ====
 
 double Ratio_madmumu [100];
 double errRatio_madmumu [100];
 double Ratio_madee [100];
 double errRatio_madee [100];
 
 for (int i=0; i<num; i++) {  
  if (Ymad_B_mumu[i] != 0) Ratio_madmumu[i] = Ymad_A_mumu[i] / Ymad_B_mumu[i];
  if (Ymad_B_mumu[i] != 0) errRatio_madmumu[i] = sqrt(errYmad_A_mumu[i] * errYmad_A_mumu[i] / Ymad_B_mumu[i] / Ymad_B_mumu[i] + Ymad_A_mumu[i] / Ymad_B_mumu[i] * Ymad_A_mumu[i] / Ymad_B_mumu[i] / Ymad_B_mumu[i] / Ymad_B_mumu[i] * errYmad_B_mumu[i] * errYmad_B_mumu[i]) ;
  
  if (Ymad_B_ee[i] != 0) Ratio_madee[i] = Ymad_A_ee[i] / Ymad_B_ee[i];
  if (Ymad_B_ee[i] != 0) errRatio_madee[i] = sqrt(errYmad_A_ee[i] * errYmad_A_ee[i] / Ymad_B_ee[i] / Ymad_B_ee[i] + Ymad_A_ee[i] / Ymad_B_ee[i] * Ymad_A_ee[i] / Ymad_B_ee[i] / Ymad_B_ee[i] / Ymad_B_ee[i] * errYmad_B_ee[i] * errYmad_B_ee[i]) ;
 }
 
 TGraphErrors* grRatio_madmumu = new TGraphErrors(num,X,Ratio_madmumu,errX,errRatio_madmumu);
 grRatio_madmumu->SetTitle("DY #mu#mu @reco madgraph");
 grRatio_madmumu->GetXaxis()->SetTitle("met threshold (GeV)");
 grRatio_madmumu->GetYaxis()->SetTitle("Ratio");
 grRatio_madmumu->SetMarkerColor(kRed+4);
 grRatio_madmumu->SetFillColor(kRed+4);
 grRatio_madmumu->SetLineColor(kRed+4);
 grRatio_madmumu->SetMarkerStyle(20+4);
 grRatio_madmumu->SetMarkerSize(1);
 grRatio_madmumu->SetLineWidth(2);
 
 TGraphErrors* grRatio_madee = new TGraphErrors(num,X,Ratio_madee,errX,errRatio_madee);
 grRatio_madee->SetTitle("DY ee @reco madgraph");
 grRatio_madee->GetXaxis()->SetTitle("met threshold (GeV)");
 grRatio_madee->GetYaxis()->SetTitle("Ratio");
 grRatio_madee->SetMarkerColor(kBlue+4);
 grRatio_madee->SetFillColor(kBlue+4);
 grRatio_madee->SetLineColor(kBlue+4);
 grRatio_madee->SetMarkerStyle(21+4);
 grRatio_madee->SetMarkerSize(1);
 grRatio_madee->SetLineWidth(1);
 
 
 
 
 
 
 
 ///==== ratio inversed (n)
 
 
 
 ///==== powheg
 
 
 double RatioInversed_powmumu [100];
 double errRatioInversed_powmumu [100];
 double RatioInversed_powee [100];
 double errRatioInversed_powee [100];
 
 for (int i=0; i<num; i++) {  
  if (Ypow_B_metReversed_mumu[i] != 0) RatioInversed_powmumu[i] = Ypow_A_metReversed_mumu[i] / Ypow_B_metReversed_mumu[i];
  if (Ypow_B_metReversed_mumu[i] != 0) errRatioInversed_powmumu[i] = sqrt(errYpow_A_metReversed_mumu[i] * errYpow_A_metReversed_mumu[i] / Ypow_B_metReversed_mumu[i] / Ypow_B_metReversed_mumu[i] + Ypow_A_metReversed_mumu[i] / Ypow_B_metReversed_mumu[i] * Ypow_A_metReversed_mumu[i] / Ypow_B_metReversed_mumu[i] / Ypow_B_metReversed_mumu[i] / Ypow_B_metReversed_mumu[i] * errYpow_B_metReversed_mumu[i] * errYpow_B_metReversed_mumu[i]) ;
  
  if (Ypow_B_metReversed_ee[i] != 0) RatioInversed_powee[i] = Ypow_A_metReversed_ee[i] / Ypow_B_metReversed_ee[i];
  if (Ypow_B_metReversed_ee[i] != 0) errRatioInversed_powee[i] = sqrt(errYpow_A_metReversed_ee[i] * errYpow_A_metReversed_ee[i] / Ypow_B_metReversed_ee[i] / Ypow_B_metReversed_ee[i] + Ypow_A_metReversed_ee[i] / Ypow_B_metReversed_ee[i] * Ypow_A_metReversed_ee[i] / Ypow_B_metReversed_ee[i] / Ypow_B_metReversed_ee[i] / Ypow_B_metReversed_ee[i] * errYpow_B_metReversed_ee[i] * errYpow_B_metReversed_ee[i]) ;
 }
 
 TGraphErrors* grRatioInversed_powmumu = new TGraphErrors(num,X,RatioInversed_powmumu,errX,errRatioInversed_powmumu);
 grRatioInversed_powmumu->SetTitle("DY #mu#mu @reco powheg");
 grRatioInversed_powmumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 grRatioInversed_powmumu->GetYaxis()->SetTitle("RatioInversed");
 grRatioInversed_powmumu->SetMarkerColor(kOrange);
 grRatioInversed_powmumu->SetFillColor(kOrange);
 grRatioInversed_powmumu->SetLineColor(kOrange);
 grRatioInversed_powmumu->SetMarkerStyle(20+2);
 grRatioInversed_powmumu->SetMarkerSize(1);
 grRatioInversed_powmumu->SetLineWidth(2);
 
 TGraphErrors* grRatioInversed_powee = new TGraphErrors(num,X,RatioInversed_powee,errX,errRatioInversed_powee);
 grRatioInversed_powee->SetTitle("DY ee @reco powheg");
 grRatioInversed_powee->GetXaxis()->SetTitle("met < threshold (GeV)");
 grRatioInversed_powee->GetYaxis()->SetTitle("RatioInversed");
 grRatioInversed_powee->SetMarkerColor(kTeal);
 grRatioInversed_powee->SetFillColor(kTeal);
 grRatioInversed_powee->SetLineColor(kTeal);
 grRatioInversed_powee->SetMarkerStyle(21+2);
 grRatioInversed_powee->SetMarkerSize(1);
 grRatioInversed_powee->SetLineWidth(1);
 
 
 
 
 ///==== madgraph
 
 
 double RatioInversed_madmumu [100];
 double errRatioInversed_madmumu [100];
 double RatioInversed_madee [100];
 double errRatioInversed_madee [100];
 
 for (int i=0; i<num; i++) {  
  if (Ymad_B_metReversed_mumu[i] != 0) RatioInversed_madmumu[i] = Ymad_A_metReversed_mumu[i] / Ymad_B_metReversed_mumu[i];
  if (Ymad_B_metReversed_mumu[i] != 0) errRatioInversed_madmumu[i] = sqrt(errYmad_A_metReversed_mumu[i] * errYmad_A_metReversed_mumu[i] / Ymad_B_metReversed_mumu[i] / Ymad_B_metReversed_mumu[i] + Ymad_A_metReversed_mumu[i] / Ymad_B_metReversed_mumu[i] * Ymad_A_metReversed_mumu[i] / Ymad_B_metReversed_mumu[i] / Ymad_B_metReversed_mumu[i] / Ymad_B_metReversed_mumu[i] * errYmad_B_metReversed_mumu[i] * errYmad_B_metReversed_mumu[i]) ;
  
  if (Ymad_B_metReversed_ee[i] != 0) RatioInversed_madee[i] = Ymad_A_metReversed_ee[i] / Ymad_B_metReversed_ee[i];
  if (Ymad_B_metReversed_ee[i] != 0) errRatioInversed_madee[i] = sqrt(errYmad_A_metReversed_ee[i] * errYmad_A_metReversed_ee[i] / Ymad_B_metReversed_ee[i] / Ymad_B_metReversed_ee[i] + Ymad_A_metReversed_ee[i] / Ymad_B_metReversed_ee[i] * Ymad_A_metReversed_ee[i] / Ymad_B_metReversed_ee[i] / Ymad_B_metReversed_ee[i] / Ymad_B_metReversed_ee[i] * errYmad_B_metReversed_ee[i] * errYmad_B_metReversed_ee[i]) ;
 }
 
 TGraphErrors* grRatioInversed_madmumu = new TGraphErrors(num,X,RatioInversed_madmumu,errX,errRatioInversed_madmumu);
 grRatioInversed_madmumu->SetTitle("DY #mu#mu @reco madgraph");
 grRatioInversed_madmumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 grRatioInversed_madmumu->GetYaxis()->SetTitle("RatioInversed");
 grRatioInversed_madmumu->SetMarkerColor(kRed+4);
 grRatioInversed_madmumu->SetFillColor(kRed+4);
 grRatioInversed_madmumu->SetLineColor(kRed+4);
 grRatioInversed_madmumu->SetMarkerStyle(20+4);
 grRatioInversed_madmumu->SetMarkerSize(1);
 grRatioInversed_madmumu->SetLineWidth(2);
 
 TGraphErrors* grRatioInversed_madee = new TGraphErrors(num,X,RatioInversed_madee,errX,errRatioInversed_madee);
 grRatioInversed_madee->SetTitle("DY ee @reco madgraph");
 grRatioInversed_madee->GetXaxis()->SetTitle("met < threshold (GeV)");
 grRatioInversed_madee->GetYaxis()->SetTitle("RatioInversed");
 grRatioInversed_madee->SetMarkerColor(kBlue+4);
 grRatioInversed_madee->SetFillColor(kBlue+4);
 grRatioInversed_madee->SetLineColor(kBlue+4);
 grRatioInversed_madee->SetMarkerStyle(21+4);
 grRatioInversed_madee->SetMarkerSize(1);
 grRatioInversed_madee->SetLineWidth(1);
 
 
 
 
 
 
 ///==== ratio inversed_noLimit (n)
 
 
 
 ///==== powheg
 
 
 double RatioInversed_noLimit_powmumu [100];
 double errRatioInversed_noLimit_powmumu [100];
 double RatioInversed_noLimit_powee [100];
 double errRatioInversed_noLimit_powee [100];
 
 for (int i=0; i<num; i++) {  
  if (Ypow_B_metReversed_noLimit_mumu[i] != 0) RatioInversed_noLimit_powmumu[i] = Ypow_A_metReversed_noLimit_mumu[i] / Ypow_B_metReversed_noLimit_mumu[i];
  if (Ypow_B_metReversed_noLimit_mumu[i] != 0) errRatioInversed_noLimit_powmumu[i] = sqrt(errYpow_A_metReversed_noLimit_mumu[i] * errYpow_A_metReversed_noLimit_mumu[i] / Ypow_B_metReversed_noLimit_mumu[i] / Ypow_B_metReversed_noLimit_mumu[i] + Ypow_A_metReversed_noLimit_mumu[i] / Ypow_B_metReversed_noLimit_mumu[i] * Ypow_A_metReversed_noLimit_mumu[i] / Ypow_B_metReversed_noLimit_mumu[i] / Ypow_B_metReversed_noLimit_mumu[i] / Ypow_B_metReversed_noLimit_mumu[i] * errYpow_B_metReversed_noLimit_mumu[i] * errYpow_B_metReversed_noLimit_mumu[i]) ;
  
  if (Ypow_B_metReversed_noLimit_ee[i] != 0) RatioInversed_noLimit_powee[i] = Ypow_A_metReversed_noLimit_ee[i] / Ypow_B_metReversed_noLimit_ee[i];
  if (Ypow_B_metReversed_noLimit_ee[i] != 0) errRatioInversed_noLimit_powee[i] = sqrt(errYpow_A_metReversed_noLimit_ee[i] * errYpow_A_metReversed_noLimit_ee[i] / Ypow_B_metReversed_noLimit_ee[i] / Ypow_B_metReversed_noLimit_ee[i] + Ypow_A_metReversed_noLimit_ee[i] / Ypow_B_metReversed_noLimit_ee[i] * Ypow_A_metReversed_noLimit_ee[i] / Ypow_B_metReversed_noLimit_ee[i] / Ypow_B_metReversed_noLimit_ee[i] / Ypow_B_metReversed_noLimit_ee[i] * errYpow_B_metReversed_noLimit_ee[i] * errYpow_B_metReversed_noLimit_ee[i]) ;
 }
 
 TGraphErrors* grRatioInversed_noLimit_powmumu = new TGraphErrors(num,X,RatioInversed_noLimit_powmumu,errX,errRatioInversed_noLimit_powmumu);
 grRatioInversed_noLimit_powmumu->SetTitle("DY #mu#mu @reco powheg");
 grRatioInversed_noLimit_powmumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 grRatioInversed_noLimit_powmumu->GetYaxis()->SetTitle("RatioInversed_noLimit");
 grRatioInversed_noLimit_powmumu->SetMarkerColor(kOrange);
 grRatioInversed_noLimit_powmumu->SetFillColor(kOrange);
 grRatioInversed_noLimit_powmumu->SetLineColor(kOrange);
 grRatioInversed_noLimit_powmumu->SetMarkerStyle(20+2);
 grRatioInversed_noLimit_powmumu->SetMarkerSize(1);
 grRatioInversed_noLimit_powmumu->SetLineWidth(2);
 
 TGraphErrors* grRatioInversed_noLimit_powee = new TGraphErrors(num,X,RatioInversed_noLimit_powee,errX,errRatioInversed_noLimit_powee);
 grRatioInversed_noLimit_powee->SetTitle("DY ee @reco powheg");
 grRatioInversed_noLimit_powee->GetXaxis()->SetTitle("met < threshold (GeV)");
 grRatioInversed_noLimit_powee->GetYaxis()->SetTitle("RatioInversed_noLimit");
 grRatioInversed_noLimit_powee->SetMarkerColor(kTeal);
 grRatioInversed_noLimit_powee->SetFillColor(kTeal);
 grRatioInversed_noLimit_powee->SetLineColor(kTeal);
 grRatioInversed_noLimit_powee->SetMarkerStyle(21+2);
 grRatioInversed_noLimit_powee->SetMarkerSize(1);
 grRatioInversed_noLimit_powee->SetLineWidth(1);
 
 
 
 
 ///==== madgraph
 
 
 double RatioInversed_noLimit_madmumu [100];
 double errRatioInversed_noLimit_madmumu [100];
 double RatioInversed_noLimit_madee [100];
 double errRatioInversed_noLimit_madee [100];
 
 for (int i=0; i<num; i++) {  
  if (Ymad_B_metReversed_noLimit_mumu[i] != 0) RatioInversed_noLimit_madmumu[i] = Ymad_A_metReversed_noLimit_mumu[i] / Ymad_B_metReversed_noLimit_mumu[i];
  if (Ymad_B_metReversed_noLimit_mumu[i] != 0) errRatioInversed_noLimit_madmumu[i] = sqrt(errYmad_A_metReversed_noLimit_mumu[i] * errYmad_A_metReversed_noLimit_mumu[i] / Ymad_B_metReversed_noLimit_mumu[i] / Ymad_B_metReversed_noLimit_mumu[i] + Ymad_A_metReversed_noLimit_mumu[i] / Ymad_B_metReversed_noLimit_mumu[i] * Ymad_A_metReversed_noLimit_mumu[i] / Ymad_B_metReversed_noLimit_mumu[i] / Ymad_B_metReversed_noLimit_mumu[i] / Ymad_B_metReversed_noLimit_mumu[i] * errYmad_B_metReversed_noLimit_mumu[i] * errYmad_B_metReversed_noLimit_mumu[i]) ;
  
  if (Ymad_B_metReversed_noLimit_ee[i] != 0) RatioInversed_noLimit_madee[i] = Ymad_A_metReversed_noLimit_ee[i] / Ymad_B_metReversed_noLimit_ee[i];
  if (Ymad_B_metReversed_noLimit_ee[i] != 0) errRatioInversed_noLimit_madee[i] = sqrt(errYmad_A_metReversed_noLimit_ee[i] * errYmad_A_metReversed_noLimit_ee[i] / Ymad_B_metReversed_noLimit_ee[i] / Ymad_B_metReversed_noLimit_ee[i] + Ymad_A_metReversed_noLimit_ee[i] / Ymad_B_metReversed_noLimit_ee[i] * Ymad_A_metReversed_noLimit_ee[i] / Ymad_B_metReversed_noLimit_ee[i] / Ymad_B_metReversed_noLimit_ee[i] / Ymad_B_metReversed_noLimit_ee[i] * errYmad_B_metReversed_noLimit_ee[i] * errYmad_B_metReversed_noLimit_ee[i]) ;
 }
 
 TGraphErrors* grRatioInversed_noLimit_madmumu = new TGraphErrors(num,X,RatioInversed_noLimit_madmumu,errX,errRatioInversed_noLimit_madmumu);
 grRatioInversed_noLimit_madmumu->SetTitle("DY #mu#mu @reco madgraph");
 grRatioInversed_noLimit_madmumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 grRatioInversed_noLimit_madmumu->GetYaxis()->SetTitle("RatioInversed_noLimit");
 grRatioInversed_noLimit_madmumu->SetMarkerColor(kRed+4);
 grRatioInversed_noLimit_madmumu->SetFillColor(kRed+4);
 grRatioInversed_noLimit_madmumu->SetLineColor(kRed+4);
 grRatioInversed_noLimit_madmumu->SetMarkerStyle(20+4);
 grRatioInversed_noLimit_madmumu->SetMarkerSize(1);
 grRatioInversed_noLimit_madmumu->SetLineWidth(2);
 
 TGraphErrors* grRatioInversed_noLimit_madee = new TGraphErrors(num,X,RatioInversed_noLimit_madee,errX,errRatioInversed_noLimit_madee);
 grRatioInversed_noLimit_madee->SetTitle("DY ee @reco madgraph");
 grRatioInversed_noLimit_madee->GetXaxis()->SetTitle("met < threshold (GeV)");
 grRatioInversed_noLimit_madee->GetYaxis()->SetTitle("RatioInversed_noLimit");
 grRatioInversed_noLimit_madee->SetMarkerColor(kBlue+4);
 grRatioInversed_noLimit_madee->SetFillColor(kBlue+4);
 grRatioInversed_noLimit_madee->SetLineColor(kBlue+4);
 grRatioInversed_noLimit_madee->SetMarkerStyle(21+4);
 grRatioInversed_noLimit_madee->SetMarkerSize(1);
 grRatioInversed_noLimit_madee->SetLineWidth(1);
 
 
 
 
 
 ///==== Occupancy (N)
 
 
 TGraphErrors* gr_N_DATA_B_mumu = new TGraphErrors(num,X,YDATA_B_mumu,errX,errYDATA_B_mumu);
 gr_N_DATA_B_mumu->SetTitle("NB #mu#mu @reco DATA");
 gr_N_DATA_B_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_DATA_B_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_N_DATA_B_mumu->SetMarkerColor(kYellow);
 gr_N_DATA_B_mumu->SetFillColor(kYellow);
 gr_N_DATA_B_mumu->SetLineColor(kYellow);
 gr_N_DATA_B_mumu->SetMarkerStyle(20+2);
 gr_N_DATA_B_mumu->SetMarkerSize(1);
 gr_N_DATA_B_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_N_DATA_B_ee = new TGraphErrors(num,X,YDATA_B_ee,errX,errYDATA_B_ee);
 gr_N_DATA_B_ee->SetTitle("NB ee @reco DATA");
 gr_N_DATA_B_ee->GetXaxis()->SetTitle("met threshold (GeV)");
 gr_N_DATA_B_ee->GetYaxis()->SetTitle("Occupancy");
 gr_N_DATA_B_ee->SetMarkerColor(kTeal);
 gr_N_DATA_B_ee->SetFillColor(kTeal);
 gr_N_DATA_B_ee->SetLineColor(kTeal);
 gr_N_DATA_B_ee->SetMarkerStyle(21+2);
 gr_N_DATA_B_ee->SetMarkerSize(1);
 gr_N_DATA_B_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_N_pow_B_mumu = new TGraphErrors(num,X,Ypow_B_mumu,errX,errYpow_B_mumu);
 gr_N_pow_B_mumu->SetTitle("NB DY #mu#mu @reco powheg");
 gr_N_pow_B_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_pow_B_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_N_pow_B_mumu->SetMarkerColor(kOrange);
 gr_N_pow_B_mumu->SetFillColor(kOrange);
 gr_N_pow_B_mumu->SetLineColor(kOrange);
 gr_N_pow_B_mumu->SetMarkerStyle(20+2);
 gr_N_pow_B_mumu->SetMarkerSize(1);
 gr_N_pow_B_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_N_pow_B_ee = new TGraphErrors(num,X,Ypow_B_ee,errX,errYpow_B_ee);
 gr_N_pow_B_ee->SetTitle("NB DY ee @reco powheg");
 gr_N_pow_B_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_pow_B_ee->GetYaxis()->SetTitle("Occupancy");
 gr_N_pow_B_ee->SetMarkerColor(kBlue);
 gr_N_pow_B_ee->SetFillColor(kBlue);
 gr_N_pow_B_ee->SetLineColor(kBlue);
 gr_N_pow_B_ee->SetMarkerStyle(21+2);
 gr_N_pow_B_ee->SetMarkerSize(1);
 gr_N_pow_B_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_N_mad_B_mumu = new TGraphErrors(num,X,Ymad_B_mumu,errX,errYmad_B_mumu);
 gr_N_mad_B_mumu->SetTitle("NB DY #mu#mu @reco madgraph");
 gr_N_mad_B_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_mad_B_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_N_mad_B_mumu->SetMarkerColor(kRed);
 gr_N_mad_B_mumu->SetFillColor(kRed);
 gr_N_mad_B_mumu->SetLineColor(kRed);
 gr_N_mad_B_mumu->SetMarkerStyle(20+2);
 gr_N_mad_B_mumu->SetMarkerSize(1);
 gr_N_mad_B_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_N_mad_B_ee = new TGraphErrors(num,X,Ymad_B_ee,errX,errYmad_B_ee);
 gr_N_mad_B_ee->SetTitle("NB DY ee @reco madgraph");
 gr_N_mad_B_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_mad_B_ee->GetYaxis()->SetTitle("Occupancy");
 gr_N_mad_B_ee->SetMarkerColor(kGreen);
 gr_N_mad_B_ee->SetFillColor(kGreen);
 gr_N_mad_B_ee->SetLineColor(kGreen);
 gr_N_mad_B_ee->SetMarkerStyle(21+2);
 gr_N_mad_B_ee->SetMarkerSize(1);
 gr_N_mad_B_ee->SetLineWidth(2);
 
 TGraphErrors* gr_N_ttbar_B_mumu = new TGraphErrors(num,X,Yttbar_B_mumu,errX,errYttbar_B_mumu);
 gr_N_ttbar_B_mumu->SetTitle("NB  #mu#mu @reco ttbar");
 gr_N_ttbar_B_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_ttbar_B_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_N_ttbar_B_mumu->SetMarkerColor(kViolet);
 gr_N_ttbar_B_mumu->SetFillColor(kViolet);
 gr_N_ttbar_B_mumu->SetLineColor(kViolet);
 gr_N_ttbar_B_mumu->SetMarkerStyle(20+2);
 gr_N_ttbar_B_mumu->SetMarkerSize(1);
 gr_N_ttbar_B_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_N_ttbar_B_ee = new TGraphErrors(num,X,Yttbar_B_ee,errX,errYttbar_B_ee);
 gr_N_ttbar_B_ee->SetTitle("NB ee @reco ttbar");
 gr_N_ttbar_B_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_ttbar_B_ee->GetYaxis()->SetTitle("Occupancy");
 gr_N_ttbar_B_ee->SetMarkerColor(kMagenta);
 gr_N_ttbar_B_ee->SetFillColor(kMagenta);
 gr_N_ttbar_B_ee->SetLineColor(kMagenta);
 gr_N_ttbar_B_ee->SetMarkerStyle(21+2);
 gr_N_ttbar_B_ee->SetMarkerSize(1);
 gr_N_ttbar_B_ee->SetLineWidth(2);
 
 
 TCanvas cc_N_B_ee;
 TMultiGraph* mgr_N_B_ee = new TMultiGraph(); 
 mgr_N_B_ee->Add(gr_N_DATA_B_ee);
 mgr_N_B_ee->Add(gr_N_mad_B_ee);
 mgr_N_B_ee->Add(gr_N_pow_B_ee);
 mgr_N_B_ee->Add(gr_N_ttbar_B_ee);
 mgr_N_B_ee->Draw("AP");
 mgr_N_B_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_N_B_ee->GetYaxis()->SetTitle("occupancy ee B");
  
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 TCanvas cc_N_B_mumu;
 TMultiGraph* mgr_N_B_mumu = new TMultiGraph(); 
 mgr_N_B_mumu->Add(gr_N_DATA_B_mumu);
 mgr_N_B_mumu->Add(gr_N_mad_B_mumu);
 mgr_N_B_mumu->Add(gr_N_pow_B_mumu);
 mgr_N_B_mumu->Add(gr_N_ttbar_B_mumu);
 mgr_N_B_mumu->Draw("AP");
 mgr_N_B_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_N_B_mumu->GetYaxis()->SetTitle("occupancy mumu B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 TGraphErrors* gr_N_DATA_A_mumu = new TGraphErrors(num,X,YDATA_A_mumu,errX,errYDATA_A_mumu);
 gr_N_DATA_A_mumu->SetTitle("NA #mu#mu @reco DATA");
 gr_N_DATA_A_mumu->GetXaxis()->SetTitle("met threshold (GeV)");
 gr_N_DATA_A_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_N_DATA_A_mumu->SetMarkerColor(kYellow);
 gr_N_DATA_A_mumu->SetFillColor(kYellow);
 gr_N_DATA_A_mumu->SetLineColor(kYellow);
 gr_N_DATA_A_mumu->SetMarkerStyle(20+2);
 gr_N_DATA_A_mumu->SetMarkerSize(1);
 gr_N_DATA_A_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_N_DATA_A_ee = new TGraphErrors(num,X,YDATA_A_ee,errX,errYDATA_A_ee);
 gr_N_DATA_A_ee->SetTitle("NA ee @reco DATA");
 gr_N_DATA_A_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_DATA_A_ee->GetYaxis()->SetTitle("Occupancy");
 gr_N_DATA_A_ee->SetMarkerColor(kTeal);
 gr_N_DATA_A_ee->SetFillColor(kTeal);
 gr_N_DATA_A_ee->SetLineColor(kTeal);
 gr_N_DATA_A_ee->SetMarkerStyle(21+2);
 gr_N_DATA_A_ee->SetMarkerSize(1);
 gr_N_DATA_A_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_N_pow_A_mumu = new TGraphErrors(num,X,Ypow_A_mumu,errX,errYpow_A_mumu);
 gr_N_pow_A_mumu->SetTitle("NA DY #mu#mu @reco powheg");
 gr_N_pow_A_mumu->GetXaxis()->SetTitle("met threshold (GeV)");
 gr_N_pow_A_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_N_pow_A_mumu->SetMarkerColor(kOrange);
 gr_N_pow_A_mumu->SetFillColor(kOrange);
 gr_N_pow_A_mumu->SetLineColor(kOrange);
 gr_N_pow_A_mumu->SetMarkerStyle(20+2);
 gr_N_pow_A_mumu->SetMarkerSize(1);
 gr_N_pow_A_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_N_pow_A_ee = new TGraphErrors(num,X,Ypow_A_ee,errX,errYpow_A_ee);
 gr_N_pow_A_ee->SetTitle("NA DY ee @reco powheg");
 gr_N_pow_A_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_pow_A_ee->GetYaxis()->SetTitle("Occupancy");
 gr_N_pow_A_ee->SetMarkerColor(kBlue);
 gr_N_pow_A_ee->SetFillColor(kBlue);
 gr_N_pow_A_ee->SetLineColor(kBlue);
 gr_N_pow_A_ee->SetMarkerStyle(21+2);
 gr_N_pow_A_ee->SetMarkerSize(1);
 gr_N_pow_A_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_N_mad_A_mumu = new TGraphErrors(num,X,Ymad_A_mumu,errX,errYmad_A_mumu);
 gr_N_mad_A_mumu->SetTitle("NA DY #mu#mu @reco madgraph");
 gr_N_mad_A_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_mad_A_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_N_mad_A_mumu->SetMarkerColor(kRed);
 gr_N_mad_A_mumu->SetFillColor(kRed);
 gr_N_mad_A_mumu->SetLineColor(kRed);
 gr_N_mad_A_mumu->SetMarkerStyle(20+2);
 gr_N_mad_A_mumu->SetMarkerSize(1);
 gr_N_mad_A_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_N_mad_A_ee = new TGraphErrors(num,X,Ymad_A_ee,errX,errYmad_A_ee);
 gr_N_mad_A_ee->SetTitle("NA DY ee @reco madgraph");
 gr_N_mad_A_ee->GetXaxis()->SetTitle("met threshold (GeV)");
 gr_N_mad_A_ee->GetYaxis()->SetTitle("Occupancy");
 gr_N_mad_A_ee->SetMarkerColor(kGreen);
 gr_N_mad_A_ee->SetFillColor(kGreen);
 gr_N_mad_A_ee->SetLineColor(kGreen);
 gr_N_mad_A_ee->SetMarkerStyle(21+2);
 gr_N_mad_A_ee->SetMarkerSize(1);
 gr_N_mad_A_ee->SetLineWidth(2);
 
 TGraphErrors* gr_N_ttbar_A_mumu = new TGraphErrors(num,X,Yttbar_A_mumu,errX,errYttbar_A_mumu);
 gr_N_ttbar_A_mumu->SetTitle("NA #mu#mu @reco ttbar");
 gr_N_ttbar_A_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_ttbar_A_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_N_ttbar_A_mumu->SetMarkerColor(kViolet);
 gr_N_ttbar_A_mumu->SetFillColor(kViolet);
 gr_N_ttbar_A_mumu->SetLineColor(kViolet);
 gr_N_ttbar_A_mumu->SetMarkerStyle(20+2);
 gr_N_ttbar_A_mumu->SetMarkerSize(1);
 gr_N_ttbar_A_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_N_ttbar_A_ee = new TGraphErrors(num,X,Yttbar_A_ee,errX,errYttbar_A_ee);
 gr_N_ttbar_A_ee->SetTitle("NA ee @reco ttbar");
 gr_N_ttbar_A_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_N_ttbar_A_ee->GetYaxis()->SetTitle("Occupancy");
 gr_N_ttbar_A_ee->SetMarkerColor(kMagenta);
 gr_N_ttbar_A_ee->SetFillColor(kMagenta);
 gr_N_ttbar_A_ee->SetLineColor(kMagenta);
 gr_N_ttbar_A_ee->SetMarkerStyle(21+2);
 gr_N_ttbar_A_ee->SetMarkerSize(1);
 gr_N_ttbar_A_ee->SetLineWidth(2);
 
 
 
 TCanvas cc_N_A_ee;
 TMultiGraph* mgr_N_A_ee = new TMultiGraph(); 
 mgr_N_A_ee->Add(gr_N_DATA_A_ee);
 mgr_N_A_ee->Add(gr_N_mad_A_ee);
 mgr_N_A_ee->Add(gr_N_pow_A_ee);
 mgr_N_A_ee->Add(gr_N_ttbar_A_ee);
 mgr_N_A_ee->Draw("AP");
 mgr_N_A_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_N_A_ee->GetYaxis()->SetTitle("occupancy ee A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas cc_N_A_mumu;
 TMultiGraph* mgr_N_A_mumu = new TMultiGraph(); 
 mgr_N_A_mumu->Add(gr_N_DATA_A_mumu);
 mgr_N_A_mumu->Add(gr_N_mad_A_mumu);
 mgr_N_A_mumu->Add(gr_N_pow_A_mumu);
 mgr_N_A_mumu->Add(gr_N_ttbar_A_mumu);
 mgr_N_A_mumu->Draw("AP");
 mgr_N_A_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_N_A_mumu->GetYaxis()->SetTitle("occupancy mumu A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 ///==== Occupancy (n)
 
 
 TGraphErrors* gr_n_DATA_B_metReversed_mumu = new TGraphErrors(num,X,YDATA_B_metReversed_mumu,errX,errYDATA_B_metReversed_mumu);
 gr_n_DATA_B_metReversed_mumu->SetTitle("nB #mu#mu @reco DATA");
 gr_n_DATA_B_metReversed_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_DATA_B_metReversed_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_DATA_B_metReversed_mumu->SetMarkerColor(kYellow);
 gr_n_DATA_B_metReversed_mumu->SetFillColor(kYellow);
 gr_n_DATA_B_metReversed_mumu->SetLineColor(kYellow);
 gr_n_DATA_B_metReversed_mumu->SetMarkerStyle(20+2);
 gr_n_DATA_B_metReversed_mumu->SetMarkerSize(1);
 gr_n_DATA_B_metReversed_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_DATA_B_metReversed_ee = new TGraphErrors(num,X,YDATA_B_metReversed_ee,errX,errYDATA_B_metReversed_ee);
 gr_n_DATA_B_metReversed_ee->SetTitle("nB ee @reco DATA");
 gr_n_DATA_B_metReversed_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_DATA_B_metReversed_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_DATA_B_metReversed_ee->SetMarkerColor(kTeal);
 gr_n_DATA_B_metReversed_ee->SetFillColor(kTeal);
 gr_n_DATA_B_metReversed_ee->SetLineColor(kTeal);
 gr_n_DATA_B_metReversed_ee->SetMarkerStyle(21+2);
 gr_n_DATA_B_metReversed_ee->SetMarkerSize(1);
 gr_n_DATA_B_metReversed_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_n_pow_B_metReversed_mumu = new TGraphErrors(num,X,Ypow_B_metReversed_mumu,errX,errYpow_B_metReversed_mumu);
 gr_n_pow_B_metReversed_mumu->SetTitle("nB DY #mu#mu @reco powheg");
 gr_n_pow_B_metReversed_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_pow_B_metReversed_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_pow_B_metReversed_mumu->SetMarkerColor(kOrange);
 gr_n_pow_B_metReversed_mumu->SetFillColor(kOrange);
 gr_n_pow_B_metReversed_mumu->SetLineColor(kOrange);
 gr_n_pow_B_metReversed_mumu->SetMarkerStyle(20+2);
 gr_n_pow_B_metReversed_mumu->SetMarkerSize(1);
 gr_n_pow_B_metReversed_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_pow_B_metReversed_ee = new TGraphErrors(num,X,Ypow_B_metReversed_ee,errX,errYpow_B_metReversed_ee);
 gr_n_pow_B_metReversed_ee->SetTitle("nB DY ee @reco powheg");
 gr_n_pow_B_metReversed_ee->GetXaxis()->SetTitle("met threshold (GeV)");
 gr_n_pow_B_metReversed_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_pow_B_metReversed_ee->SetMarkerColor(kBlue);
 gr_n_pow_B_metReversed_ee->SetFillColor(kBlue);
 gr_n_pow_B_metReversed_ee->SetLineColor(kBlue);
 gr_n_pow_B_metReversed_ee->SetMarkerStyle(21+2);
 gr_n_pow_B_metReversed_ee->SetMarkerSize(1);
 gr_n_pow_B_metReversed_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_n_mad_B_metReversed_mumu = new TGraphErrors(num,X,Ymad_B_metReversed_mumu,errX,errYmad_B_metReversed_mumu);
 gr_n_mad_B_metReversed_mumu->SetTitle("nB DY #mu#mu @reco madgraph");
 gr_n_mad_B_metReversed_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_mad_B_metReversed_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_mad_B_metReversed_mumu->SetMarkerColor(kRed);
 gr_n_mad_B_metReversed_mumu->SetFillColor(kRed);
 gr_n_mad_B_metReversed_mumu->SetLineColor(kRed);
 gr_n_mad_B_metReversed_mumu->SetMarkerStyle(20+2);
 gr_n_mad_B_metReversed_mumu->SetMarkerSize(1);
 gr_n_mad_B_metReversed_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_mad_B_metReversed_ee = new TGraphErrors(num,X,Ymad_B_metReversed_ee,errX,errYmad_B_metReversed_ee);
 gr_n_mad_B_metReversed_ee->SetTitle("nB DY ee @reco madgraph");
 gr_n_mad_B_metReversed_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_mad_B_metReversed_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_mad_B_metReversed_ee->SetMarkerColor(kGreen);
 gr_n_mad_B_metReversed_ee->SetFillColor(kGreen);
 gr_n_mad_B_metReversed_ee->SetLineColor(kGreen);
 gr_n_mad_B_metReversed_ee->SetMarkerStyle(21+2);
 gr_n_mad_B_metReversed_ee->SetMarkerSize(1);
 gr_n_mad_B_metReversed_ee->SetLineWidth(2);
 
 TGraphErrors* gr_n_ttbar_B_metReversed_mumu = new TGraphErrors(num,X,Yttbar_B_metReversed_mumu,errX,errYttbar_B_metReversed_mumu);
 gr_n_ttbar_B_metReversed_mumu->SetTitle("nB  #mu#mu @reco ttbar");
 gr_n_ttbar_B_metReversed_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_ttbar_B_metReversed_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_ttbar_B_metReversed_mumu->SetMarkerColor(kViolet);
 gr_n_ttbar_B_metReversed_mumu->SetFillColor(kViolet);
 gr_n_ttbar_B_metReversed_mumu->SetLineColor(kViolet);
 gr_n_ttbar_B_metReversed_mumu->SetMarkerStyle(20+2);
 gr_n_ttbar_B_metReversed_mumu->SetMarkerSize(1);
 gr_n_ttbar_B_metReversed_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_ttbar_B_metReversed_ee = new TGraphErrors(num,X,Yttbar_B_metReversed_ee,errX,errYttbar_B_metReversed_ee);
 gr_n_ttbar_B_metReversed_ee->SetTitle("nB ee @reco ttbar");
 gr_n_ttbar_B_metReversed_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_ttbar_B_metReversed_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_ttbar_B_metReversed_ee->SetMarkerColor(kMagenta);
 gr_n_ttbar_B_metReversed_ee->SetFillColor(kMagenta);
 gr_n_ttbar_B_metReversed_ee->SetLineColor(kMagenta);
 gr_n_ttbar_B_metReversed_ee->SetMarkerStyle(21+2);
 gr_n_ttbar_B_metReversed_ee->SetMarkerSize(1);
 gr_n_ttbar_B_metReversed_ee->SetLineWidth(2);
 
 
 TCanvas cc_n_B_metReversed_ee;
 TMultiGraph* mgr_n_B_metReversed_ee = new TMultiGraph(); 
 mgr_n_B_metReversed_ee->Add(gr_n_DATA_B_metReversed_ee);
 mgr_n_B_metReversed_ee->Add(gr_n_mad_B_metReversed_ee);
 mgr_n_B_metReversed_ee->Add(gr_n_pow_B_metReversed_ee);
 mgr_n_B_metReversed_ee->Add(gr_n_ttbar_B_metReversed_ee);
 mgr_n_B_metReversed_ee->Draw("AP");
 mgr_n_B_metReversed_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n_B_metReversed_ee->GetYaxis()->SetTitle("occupancy ee B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 TCanvas cc_n_B_metReversed_mumu;
 TMultiGraph* mgr_n_B_metReversed_mumu = new TMultiGraph(); 
 mgr_n_B_metReversed_mumu->Add(gr_n_DATA_B_metReversed_mumu);
 mgr_n_B_metReversed_mumu->Add(gr_n_mad_B_metReversed_mumu);
 mgr_n_B_metReversed_mumu->Add(gr_n_pow_B_metReversed_mumu);
 mgr_n_B_metReversed_mumu->Add(gr_n_ttbar_B_metReversed_mumu);
 mgr_n_B_metReversed_mumu->Draw("AP");
 mgr_n_B_metReversed_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n_B_metReversed_mumu->GetYaxis()->SetTitle("occupancy mumu B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 TGraphErrors* gr_n_DATA_A_metReversed_mumu = new TGraphErrors(num,X,YDATA_A_metReversed_mumu,errX,errYDATA_A_metReversed_mumu);
 gr_n_DATA_A_metReversed_mumu->SetTitle("nA #mu#mu @reco DATA");
 gr_n_DATA_A_metReversed_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_DATA_A_metReversed_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_DATA_A_metReversed_mumu->SetMarkerColor(kYellow);
 gr_n_DATA_A_metReversed_mumu->SetFillColor(kYellow);
 gr_n_DATA_A_metReversed_mumu->SetLineColor(kYellow);
 gr_n_DATA_A_metReversed_mumu->SetMarkerStyle(20+2);
 gr_n_DATA_A_metReversed_mumu->SetMarkerSize(1);
 gr_n_DATA_A_metReversed_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_DATA_A_metReversed_ee = new TGraphErrors(num,X,YDATA_A_metReversed_ee,errX,errYDATA_A_metReversed_ee);
 gr_n_DATA_A_metReversed_ee->SetTitle("nA ee @reco DATA");
 gr_n_DATA_A_metReversed_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_DATA_A_metReversed_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_DATA_A_metReversed_ee->SetMarkerColor(kTeal);
 gr_n_DATA_A_metReversed_ee->SetFillColor(kTeal);
 gr_n_DATA_A_metReversed_ee->SetLineColor(kTeal);
 gr_n_DATA_A_metReversed_ee->SetMarkerStyle(21+2);
 gr_n_DATA_A_metReversed_ee->SetMarkerSize(1);
 gr_n_DATA_A_metReversed_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_n_pow_A_metReversed_mumu = new TGraphErrors(num,X,Ypow_A_metReversed_mumu,errX,errYpow_A_metReversed_mumu);
 gr_n_pow_A_metReversed_mumu->SetTitle("nA DY #mu#mu @reco powheg");
 gr_n_pow_A_metReversed_mumu->GetXaxis()->SetTitle("met threshold (GeV)");
 gr_n_pow_A_metReversed_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_pow_A_metReversed_mumu->SetMarkerColor(kOrange);
 gr_n_pow_A_metReversed_mumu->SetFillColor(kOrange);
 gr_n_pow_A_metReversed_mumu->SetLineColor(kOrange);
 gr_n_pow_A_metReversed_mumu->SetMarkerStyle(20+2);
 gr_n_pow_A_metReversed_mumu->SetMarkerSize(1);
 gr_n_pow_A_metReversed_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_pow_A_metReversed_ee = new TGraphErrors(num,X,Ypow_A_metReversed_ee,errX,errYpow_A_metReversed_ee);
 gr_n_pow_A_metReversed_ee->SetTitle("nA DY ee @reco powheg");
 gr_n_pow_A_metReversed_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_pow_A_metReversed_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_pow_A_metReversed_ee->SetMarkerColor(kBlue);
 gr_n_pow_A_metReversed_ee->SetFillColor(kBlue);
 gr_n_pow_A_metReversed_ee->SetLineColor(kBlue);
 gr_n_pow_A_metReversed_ee->SetMarkerStyle(21+2);
 gr_n_pow_A_metReversed_ee->SetMarkerSize(1);
 gr_n_pow_A_metReversed_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_n_mad_A_metReversed_mumu = new TGraphErrors(num,X,Ymad_A_metReversed_mumu,errX,errYmad_A_metReversed_mumu);
 gr_n_mad_A_metReversed_mumu->SetTitle("nA DY #mu#mu @reco madgraph");
 gr_n_mad_A_metReversed_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_mad_A_metReversed_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_mad_A_metReversed_mumu->SetMarkerColor(kRed);
 gr_n_mad_A_metReversed_mumu->SetFillColor(kRed);
 gr_n_mad_A_metReversed_mumu->SetLineColor(kRed);
 gr_n_mad_A_metReversed_mumu->SetMarkerStyle(20+2);
 gr_n_mad_A_metReversed_mumu->SetMarkerSize(1);
 gr_n_mad_A_metReversed_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_mad_A_metReversed_ee = new TGraphErrors(num,X,Ymad_A_metReversed_ee,errX,errYmad_A_metReversed_ee);
 gr_n_mad_A_metReversed_ee->SetTitle("nA DY ee @reco madgraph");
 gr_n_mad_A_metReversed_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_mad_A_metReversed_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_mad_A_metReversed_ee->SetMarkerColor(kGreen);
 gr_n_mad_A_metReversed_ee->SetFillColor(kGreen);
 gr_n_mad_A_metReversed_ee->SetLineColor(kGreen);
 gr_n_mad_A_metReversed_ee->SetMarkerStyle(21+2);
 gr_n_mad_A_metReversed_ee->SetMarkerSize(1);
 gr_n_mad_A_metReversed_ee->SetLineWidth(2);
 
 TGraphErrors* gr_n_ttbar_A_metReversed_mumu = new TGraphErrors(num,X,Yttbar_A_metReversed_mumu,errX,errYttbar_A_metReversed_mumu);
 gr_n_ttbar_A_metReversed_mumu->SetTitle("nA #mu#mu @reco ttbar");
 gr_n_ttbar_A_metReversed_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_ttbar_A_metReversed_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_ttbar_A_metReversed_mumu->SetMarkerColor(kViolet);
 gr_n_ttbar_A_metReversed_mumu->SetFillColor(kViolet);
 gr_n_ttbar_A_metReversed_mumu->SetLineColor(kViolet);
 gr_n_ttbar_A_metReversed_mumu->SetMarkerStyle(20+2);
 gr_n_ttbar_A_metReversed_mumu->SetMarkerSize(1);
 gr_n_ttbar_A_metReversed_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_ttbar_A_metReversed_ee = new TGraphErrors(num,X,Yttbar_A_metReversed_ee,errX,errYttbar_A_metReversed_ee);
 gr_n_ttbar_A_metReversed_ee->SetTitle("nA ee @reco ttbar");
 gr_n_ttbar_A_metReversed_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_ttbar_A_metReversed_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_ttbar_A_metReversed_ee->SetMarkerColor(kMagenta);
 gr_n_ttbar_A_metReversed_ee->SetFillColor(kMagenta);
 gr_n_ttbar_A_metReversed_ee->SetLineColor(kMagenta);
 gr_n_ttbar_A_metReversed_ee->SetMarkerStyle(21+2);
 gr_n_ttbar_A_metReversed_ee->SetMarkerSize(1);
 gr_n_ttbar_A_metReversed_ee->SetLineWidth(2);
 
 
 
 TCanvas cc_n_A_metReversed_ee;
 TMultiGraph* mgr_n_A_metReversed_ee = new TMultiGraph(); 
 mgr_n_A_metReversed_ee->Add(gr_n_DATA_A_metReversed_ee);
 mgr_n_A_metReversed_ee->Add(gr_n_mad_A_metReversed_ee);
 mgr_n_A_metReversed_ee->Add(gr_n_pow_A_metReversed_ee);
 mgr_n_A_metReversed_ee->Add(gr_n_ttbar_A_metReversed_ee);
 mgr_n_A_metReversed_ee->Draw("AP");
 mgr_n_A_metReversed_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n_A_metReversed_ee->GetYaxis()->SetTitle("occupancy ee A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas cc_n_A_metReversed_mumu;
 TMultiGraph* mgr_n_A_metReversed_mumu = new TMultiGraph(); 
 mgr_n_A_metReversed_mumu->Add(gr_n_DATA_A_metReversed_mumu);
 mgr_n_A_metReversed_mumu->Add(gr_n_mad_A_metReversed_mumu);
 mgr_n_A_metReversed_mumu->Add(gr_n_pow_A_metReversed_mumu);
 mgr_n_A_metReversed_mumu->Add(gr_n_ttbar_A_metReversed_mumu);
 mgr_n_A_metReversed_mumu->Draw("AP");
 mgr_n_A_metReversed_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n_A_metReversed_mumu->GetYaxis()->SetTitle("occupancy mumu A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 
 
 
 
 
 
 ///==== Occupancy (n) ==== noLimit
 
 
 TGraphErrors* gr_n_DATA_B_metReversed_noLimit_mumu = new TGraphErrors(num,X,YDATA_B_metReversed_noLimit_mumu,errX,errYDATA_B_metReversed_noLimit_mumu);
 gr_n_DATA_B_metReversed_noLimit_mumu->SetTitle("nB #mu#mu @reco DATA");
 gr_n_DATA_B_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_DATA_B_metReversed_noLimit_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_DATA_B_metReversed_noLimit_mumu->SetMarkerColor(kYellow);
 gr_n_DATA_B_metReversed_noLimit_mumu->SetFillColor(kYellow);
 gr_n_DATA_B_metReversed_noLimit_mumu->SetLineColor(kYellow);
 gr_n_DATA_B_metReversed_noLimit_mumu->SetMarkerStyle(20+2);
 gr_n_DATA_B_metReversed_noLimit_mumu->SetMarkerSize(1);
 gr_n_DATA_B_metReversed_noLimit_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_DATA_B_metReversed_noLimit_ee = new TGraphErrors(num,X,YDATA_B_metReversed_noLimit_ee,errX,errYDATA_B_metReversed_noLimit_ee);
 gr_n_DATA_B_metReversed_noLimit_ee->SetTitle("nB ee @reco DATA");
 gr_n_DATA_B_metReversed_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_DATA_B_metReversed_noLimit_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_DATA_B_metReversed_noLimit_ee->SetMarkerColor(kTeal);
 gr_n_DATA_B_metReversed_noLimit_ee->SetFillColor(kTeal);
 gr_n_DATA_B_metReversed_noLimit_ee->SetLineColor(kTeal);
 gr_n_DATA_B_metReversed_noLimit_ee->SetMarkerStyle(21+2);
 gr_n_DATA_B_metReversed_noLimit_ee->SetMarkerSize(1);
 gr_n_DATA_B_metReversed_noLimit_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_n_pow_B_metReversed_noLimit_mumu = new TGraphErrors(num,X,Ypow_B_metReversed_noLimit_mumu,errX,errYpow_B_metReversed_noLimit_mumu);
 gr_n_pow_B_metReversed_noLimit_mumu->SetTitle("nB DY #mu#mu @reco powheg");
 gr_n_pow_B_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_pow_B_metReversed_noLimit_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_pow_B_metReversed_noLimit_mumu->SetMarkerColor(kOrange);
 gr_n_pow_B_metReversed_noLimit_mumu->SetFillColor(kOrange);
 gr_n_pow_B_metReversed_noLimit_mumu->SetLineColor(kOrange);
 gr_n_pow_B_metReversed_noLimit_mumu->SetMarkerStyle(20+2);
 gr_n_pow_B_metReversed_noLimit_mumu->SetMarkerSize(1);
 gr_n_pow_B_metReversed_noLimit_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_pow_B_metReversed_noLimit_ee = new TGraphErrors(num,X,Ypow_B_metReversed_noLimit_ee,errX,errYpow_B_metReversed_noLimit_ee);
 gr_n_pow_B_metReversed_noLimit_ee->SetTitle("nB DY ee @reco powheg");
 gr_n_pow_B_metReversed_noLimit_ee->GetXaxis()->SetTitle("met threshold (GeV)");
 gr_n_pow_B_metReversed_noLimit_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_pow_B_metReversed_noLimit_ee->SetMarkerColor(kBlue);
 gr_n_pow_B_metReversed_noLimit_ee->SetFillColor(kBlue);
 gr_n_pow_B_metReversed_noLimit_ee->SetLineColor(kBlue);
 gr_n_pow_B_metReversed_noLimit_ee->SetMarkerStyle(21+2);
 gr_n_pow_B_metReversed_noLimit_ee->SetMarkerSize(1);
 gr_n_pow_B_metReversed_noLimit_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_n_mad_B_metReversed_noLimit_mumu = new TGraphErrors(num,X,Ymad_B_metReversed_noLimit_mumu,errX,errYmad_B_metReversed_noLimit_mumu);
 gr_n_mad_B_metReversed_noLimit_mumu->SetTitle("nB DY #mu#mu @reco madgraph");
 gr_n_mad_B_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_mad_B_metReversed_noLimit_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_mad_B_metReversed_noLimit_mumu->SetMarkerColor(kRed);
 gr_n_mad_B_metReversed_noLimit_mumu->SetFillColor(kRed);
 gr_n_mad_B_metReversed_noLimit_mumu->SetLineColor(kRed);
 gr_n_mad_B_metReversed_noLimit_mumu->SetMarkerStyle(20+2);
 gr_n_mad_B_metReversed_noLimit_mumu->SetMarkerSize(1);
 gr_n_mad_B_metReversed_noLimit_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_mad_B_metReversed_noLimit_ee = new TGraphErrors(num,X,Ymad_B_metReversed_noLimit_ee,errX,errYmad_B_metReversed_noLimit_ee);
 gr_n_mad_B_metReversed_noLimit_ee->SetTitle("nB DY ee @reco madgraph");
 gr_n_mad_B_metReversed_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_mad_B_metReversed_noLimit_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_mad_B_metReversed_noLimit_ee->SetMarkerColor(kGreen);
 gr_n_mad_B_metReversed_noLimit_ee->SetFillColor(kGreen);
 gr_n_mad_B_metReversed_noLimit_ee->SetLineColor(kGreen);
 gr_n_mad_B_metReversed_noLimit_ee->SetMarkerStyle(21+2);
 gr_n_mad_B_metReversed_noLimit_ee->SetMarkerSize(1);
 gr_n_mad_B_metReversed_noLimit_ee->SetLineWidth(2);
 
 TGraphErrors* gr_n_ttbar_B_metReversed_noLimit_mumu = new TGraphErrors(num,X,Yttbar_B_metReversed_noLimit_mumu,errX,errYttbar_B_metReversed_noLimit_mumu);
 gr_n_ttbar_B_metReversed_noLimit_mumu->SetTitle("nB  #mu#mu @reco ttbar");
 gr_n_ttbar_B_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_ttbar_B_metReversed_noLimit_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_ttbar_B_metReversed_noLimit_mumu->SetMarkerColor(kViolet);
 gr_n_ttbar_B_metReversed_noLimit_mumu->SetFillColor(kViolet);
 gr_n_ttbar_B_metReversed_noLimit_mumu->SetLineColor(kViolet);
 gr_n_ttbar_B_metReversed_noLimit_mumu->SetMarkerStyle(20+2);
 gr_n_ttbar_B_metReversed_noLimit_mumu->SetMarkerSize(1);
 gr_n_ttbar_B_metReversed_noLimit_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_ttbar_B_metReversed_noLimit_ee = new TGraphErrors(num,X,Yttbar_B_metReversed_noLimit_ee,errX,errYttbar_B_metReversed_noLimit_ee);
 gr_n_ttbar_B_metReversed_noLimit_ee->SetTitle("nB ee @reco ttbar");
 gr_n_ttbar_B_metReversed_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_ttbar_B_metReversed_noLimit_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_ttbar_B_metReversed_noLimit_ee->SetMarkerColor(kMagenta);
 gr_n_ttbar_B_metReversed_noLimit_ee->SetFillColor(kMagenta);
 gr_n_ttbar_B_metReversed_noLimit_ee->SetLineColor(kMagenta);
 gr_n_ttbar_B_metReversed_noLimit_ee->SetMarkerStyle(21+2);
 gr_n_ttbar_B_metReversed_noLimit_ee->SetMarkerSize(1);
 gr_n_ttbar_B_metReversed_noLimit_ee->SetLineWidth(2);
 
 
 TCanvas cc_n_B_metReversed_noLimit_ee;
 TMultiGraph* mgr_n_B_metReversed_noLimit_ee = new TMultiGraph(); 
 mgr_n_B_metReversed_noLimit_ee->Add(gr_n_DATA_B_metReversed_noLimit_ee);
 mgr_n_B_metReversed_noLimit_ee->Add(gr_n_mad_B_metReversed_noLimit_ee);
 mgr_n_B_metReversed_noLimit_ee->Add(gr_n_pow_B_metReversed_noLimit_ee);
 mgr_n_B_metReversed_noLimit_ee->Add(gr_n_ttbar_B_metReversed_noLimit_ee);
 mgr_n_B_metReversed_noLimit_ee->Draw("AP");
 mgr_n_B_metReversed_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n_B_metReversed_noLimit_ee->GetYaxis()->SetTitle("occupancy ee B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 TCanvas cc_n_B_metReversed_noLimit_mumu;
 TMultiGraph* mgr_n_B_metReversed_noLimit_mumu = new TMultiGraph(); 
 mgr_n_B_metReversed_noLimit_mumu->Add(gr_n_DATA_B_metReversed_noLimit_mumu);
 mgr_n_B_metReversed_noLimit_mumu->Add(gr_n_mad_B_metReversed_noLimit_mumu);
 mgr_n_B_metReversed_noLimit_mumu->Add(gr_n_pow_B_metReversed_noLimit_mumu);
 mgr_n_B_metReversed_noLimit_mumu->Add(gr_n_ttbar_B_metReversed_noLimit_mumu);
 mgr_n_B_metReversed_noLimit_mumu->Draw("AP");
 mgr_n_B_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n_B_metReversed_noLimit_mumu->GetYaxis()->SetTitle("occupancy mumu B");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 TGraphErrors* gr_n_DATA_A_metReversed_noLimit_mumu = new TGraphErrors(num,X,YDATA_A_metReversed_noLimit_mumu,errX,errYDATA_A_metReversed_noLimit_mumu);
 gr_n_DATA_A_metReversed_noLimit_mumu->SetTitle("nA #mu#mu @reco DATA");
 gr_n_DATA_A_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_DATA_A_metReversed_noLimit_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_DATA_A_metReversed_noLimit_mumu->SetMarkerColor(kYellow);
 gr_n_DATA_A_metReversed_noLimit_mumu->SetFillColor(kYellow);
 gr_n_DATA_A_metReversed_noLimit_mumu->SetLineColor(kYellow);
 gr_n_DATA_A_metReversed_noLimit_mumu->SetMarkerStyle(20+2);
 gr_n_DATA_A_metReversed_noLimit_mumu->SetMarkerSize(1);
 gr_n_DATA_A_metReversed_noLimit_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_DATA_A_metReversed_noLimit_ee = new TGraphErrors(num,X,YDATA_A_metReversed_noLimit_ee,errX,errYDATA_A_metReversed_noLimit_ee);
 gr_n_DATA_A_metReversed_noLimit_ee->SetTitle("nA ee @reco DATA");
 gr_n_DATA_A_metReversed_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_DATA_A_metReversed_noLimit_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_DATA_A_metReversed_noLimit_ee->SetMarkerColor(kTeal);
 gr_n_DATA_A_metReversed_noLimit_ee->SetFillColor(kTeal);
 gr_n_DATA_A_metReversed_noLimit_ee->SetLineColor(kTeal);
 gr_n_DATA_A_metReversed_noLimit_ee->SetMarkerStyle(21+2);
 gr_n_DATA_A_metReversed_noLimit_ee->SetMarkerSize(1);
 gr_n_DATA_A_metReversed_noLimit_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_n_pow_A_metReversed_noLimit_mumu = new TGraphErrors(num,X,Ypow_A_metReversed_noLimit_mumu,errX,errYpow_A_metReversed_noLimit_mumu);
 gr_n_pow_A_metReversed_noLimit_mumu->SetTitle("nA DY #mu#mu @reco powheg");
 gr_n_pow_A_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met threshold (GeV)");
 gr_n_pow_A_metReversed_noLimit_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_pow_A_metReversed_noLimit_mumu->SetMarkerColor(kOrange);
 gr_n_pow_A_metReversed_noLimit_mumu->SetFillColor(kOrange);
 gr_n_pow_A_metReversed_noLimit_mumu->SetLineColor(kOrange);
 gr_n_pow_A_metReversed_noLimit_mumu->SetMarkerStyle(20+2);
 gr_n_pow_A_metReversed_noLimit_mumu->SetMarkerSize(1);
 gr_n_pow_A_metReversed_noLimit_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_pow_A_metReversed_noLimit_ee = new TGraphErrors(num,X,Ypow_A_metReversed_noLimit_ee,errX,errYpow_A_metReversed_noLimit_ee);
 gr_n_pow_A_metReversed_noLimit_ee->SetTitle("nA DY ee @reco powheg");
 gr_n_pow_A_metReversed_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_pow_A_metReversed_noLimit_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_pow_A_metReversed_noLimit_ee->SetMarkerColor(kBlue);
 gr_n_pow_A_metReversed_noLimit_ee->SetFillColor(kBlue);
 gr_n_pow_A_metReversed_noLimit_ee->SetLineColor(kBlue);
 gr_n_pow_A_metReversed_noLimit_ee->SetMarkerStyle(21+2);
 gr_n_pow_A_metReversed_noLimit_ee->SetMarkerSize(1);
 gr_n_pow_A_metReversed_noLimit_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_n_mad_A_metReversed_noLimit_mumu = new TGraphErrors(num,X,Ymad_A_metReversed_noLimit_mumu,errX,errYmad_A_metReversed_noLimit_mumu);
 gr_n_mad_A_metReversed_noLimit_mumu->SetTitle("nA DY #mu#mu @reco madgraph");
 gr_n_mad_A_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_mad_A_metReversed_noLimit_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_mad_A_metReversed_noLimit_mumu->SetMarkerColor(kRed);
 gr_n_mad_A_metReversed_noLimit_mumu->SetFillColor(kRed);
 gr_n_mad_A_metReversed_noLimit_mumu->SetLineColor(kRed);
 gr_n_mad_A_metReversed_noLimit_mumu->SetMarkerStyle(20+2);
 gr_n_mad_A_metReversed_noLimit_mumu->SetMarkerSize(1);
 gr_n_mad_A_metReversed_noLimit_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_mad_A_metReversed_noLimit_ee = new TGraphErrors(num,X,Ymad_A_metReversed_noLimit_ee,errX,errYmad_A_metReversed_noLimit_ee);
 gr_n_mad_A_metReversed_noLimit_ee->SetTitle("nA DY ee @reco madgraph");
 gr_n_mad_A_metReversed_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_mad_A_metReversed_noLimit_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_mad_A_metReversed_noLimit_ee->SetMarkerColor(kGreen);
 gr_n_mad_A_metReversed_noLimit_ee->SetFillColor(kGreen);
 gr_n_mad_A_metReversed_noLimit_ee->SetLineColor(kGreen);
 gr_n_mad_A_metReversed_noLimit_ee->SetMarkerStyle(21+2);
 gr_n_mad_A_metReversed_noLimit_ee->SetMarkerSize(1);
 gr_n_mad_A_metReversed_noLimit_ee->SetLineWidth(2);
 
 TGraphErrors* gr_n_ttbar_A_metReversed_noLimit_mumu = new TGraphErrors(num,X,Yttbar_A_metReversed_noLimit_mumu,errX,errYttbar_A_metReversed_noLimit_mumu);
 gr_n_ttbar_A_metReversed_noLimit_mumu->SetTitle("nA #mu#mu @reco ttbar");
 gr_n_ttbar_A_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_ttbar_A_metReversed_noLimit_mumu->GetYaxis()->SetTitle("Occupancy");
 gr_n_ttbar_A_metReversed_noLimit_mumu->SetMarkerColor(kViolet);
 gr_n_ttbar_A_metReversed_noLimit_mumu->SetFillColor(kViolet);
 gr_n_ttbar_A_metReversed_noLimit_mumu->SetLineColor(kViolet);
 gr_n_ttbar_A_metReversed_noLimit_mumu->SetMarkerStyle(20+2);
 gr_n_ttbar_A_metReversed_noLimit_mumu->SetMarkerSize(1);
 gr_n_ttbar_A_metReversed_noLimit_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_n_ttbar_A_metReversed_noLimit_ee = new TGraphErrors(num,X,Yttbar_A_metReversed_noLimit_ee,errX,errYttbar_A_metReversed_noLimit_ee);
 gr_n_ttbar_A_metReversed_noLimit_ee->SetTitle("nA ee @reco ttbar");
 gr_n_ttbar_A_metReversed_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_n_ttbar_A_metReversed_noLimit_ee->GetYaxis()->SetTitle("Occupancy");
 gr_n_ttbar_A_metReversed_noLimit_ee->SetMarkerColor(kMagenta);
 gr_n_ttbar_A_metReversed_noLimit_ee->SetFillColor(kMagenta);
 gr_n_ttbar_A_metReversed_noLimit_ee->SetLineColor(kMagenta);
 gr_n_ttbar_A_metReversed_noLimit_ee->SetMarkerStyle(21+2);
 gr_n_ttbar_A_metReversed_noLimit_ee->SetMarkerSize(1);
 gr_n_ttbar_A_metReversed_noLimit_ee->SetLineWidth(2);
 
 
 
 TCanvas cc_n_A_metReversed_noLimit_ee;
 TMultiGraph* mgr_n_A_metReversed_noLimit_ee = new TMultiGraph(); 
 mgr_n_A_metReversed_noLimit_ee->Add(gr_n_DATA_A_metReversed_noLimit_ee);
 mgr_n_A_metReversed_noLimit_ee->Add(gr_n_mad_A_metReversed_noLimit_ee);
 mgr_n_A_metReversed_noLimit_ee->Add(gr_n_pow_A_metReversed_noLimit_ee);
 mgr_n_A_metReversed_noLimit_ee->Add(gr_n_ttbar_A_metReversed_noLimit_ee);
 mgr_n_A_metReversed_noLimit_ee->Draw("AP");
 mgr_n_A_metReversed_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n_A_metReversed_noLimit_ee->GetYaxis()->SetTitle("occupancy ee A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas cc_n_A_metReversed_noLimit_mumu;
 TMultiGraph* mgr_n_A_metReversed_noLimit_mumu = new TMultiGraph(); 
 mgr_n_A_metReversed_noLimit_mumu->Add(gr_n_DATA_A_metReversed_noLimit_mumu);
 mgr_n_A_metReversed_noLimit_mumu->Add(gr_n_mad_A_metReversed_noLimit_mumu);
 mgr_n_A_metReversed_noLimit_mumu->Add(gr_n_pow_A_metReversed_noLimit_mumu);
 mgr_n_A_metReversed_noLimit_mumu->Add(gr_n_ttbar_A_metReversed_noLimit_mumu);
 mgr_n_A_metReversed_noLimit_mumu->Draw("AP");
 mgr_n_A_metReversed_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n_A_metReversed_noLimit_mumu->GetYaxis()->SetTitle("occupancy mumu A");
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 ///==== madgraph ====
 
 double Ratio_madmumu [100];
 double errRatio_madmumu [100];
 double Ratio_madee [100];
 double errRatio_madee [100];
 
 for (int i=0; i<num; i++) {  
  if (Ymad_B_mumu[i] != 0) Ratio_madmumu[i] = Ymad_A_mumu[i] / Ymad_B_mumu[i];
  if (Ymad_B_mumu[i] != 0) errRatio_madmumu[i] = sqrt(errYmad_A_mumu[i] * errYmad_A_mumu[i] / Ymad_B_mumu[i] / Ymad_B_mumu[i] + Ymad_A_mumu[i] / Ymad_B_mumu[i] * Ymad_A_mumu[i] / Ymad_B_mumu[i] / Ymad_B_mumu[i] / Ymad_B_mumu[i] * errYmad_B_mumu[i] * errYmad_B_mumu[i]) ;
  
  if (Ymad_B_ee[i] != 0) Ratio_madee[i] = Ymad_A_ee[i] / Ymad_B_ee[i];
  if (Ymad_B_ee[i] != 0) errRatio_madee[i] = sqrt(errYmad_A_ee[i] * errYmad_A_ee[i] / Ymad_B_ee[i] / Ymad_B_ee[i] + Ymad_A_ee[i] / Ymad_B_ee[i] * Ymad_A_ee[i] / Ymad_B_ee[i] / Ymad_B_ee[i] / Ymad_B_ee[i] * errYmad_B_ee[i] * errYmad_B_ee[i]) ;
 }
 
 TGraphErrors* grRatio_madmumu = new TGraphErrors(num,X,Ratio_madmumu,errX,errRatio_madmumu);
 grRatio_madmumu->SetTitle("DY #mu#mu @reco madgraph");
 grRatio_madmumu->GetXaxis()->SetTitle("met threshold (GeV)");
 grRatio_madmumu->GetYaxis()->SetTitle("Ratio");
 grRatio_madmumu->SetMarkerColor(kRed+4);
 grRatio_madmumu->SetFillColor(kRed+4);
 grRatio_madmumu->SetLineColor(kRed+4);
 grRatio_madmumu->SetMarkerStyle(20+4);
 grRatio_madmumu->SetMarkerSize(1);
 grRatio_madmumu->SetLineWidth(2);
 
 TGraphErrors* grRatio_madee = new TGraphErrors(num,X,Ratio_madee,errX,errRatio_madee);
 grRatio_madee->SetTitle("DY ee @reco madgraph");
 grRatio_madee->GetXaxis()->SetTitle("met threshold (GeV)");
 grRatio_madee->GetYaxis()->SetTitle("Ratio");
 grRatio_madee->SetMarkerColor(kBlue+4);
 grRatio_madee->SetFillColor(kBlue+4);
 grRatio_madee->SetLineColor(kBlue+4);
 grRatio_madee->SetMarkerStyle(21+4);
 grRatio_madee->SetMarkerSize(1);
 grRatio_madee->SetLineWidth(1);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 ///==== DATA ====
   
 
 ///==== ratio from data ====
 
 TGraphErrors* gr_R_n_mumu = new TGraphErrors(num,X,YDATA_R_n_mumu,errX,errYDATA_R_n_mumu);
 gr_R_n_mumu->SetTitle("R^{#mu#mu}_{DATA}");
 gr_R_n_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_R_n_mumu->GetYaxis()->SetTitle("ratio");
 gr_R_n_mumu->SetMarkerColor(kRed);
 gr_R_n_mumu->SetFillColor(kRed);
 gr_R_n_mumu->SetLineColor(kRed);
 gr_R_n_mumu->SetMarkerStyle(20);
 gr_R_n_mumu->SetMarkerSize(1);
 gr_R_n_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_R_n_ee = new TGraphErrors(num,X,YDATA_R_n_ee,errX,errYDATA_R_n_ee);
 gr_R_n_ee->SetTitle("R^{ee}_{DATA}");
 gr_R_n_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_R_n_ee->GetYaxis()->SetTitle("ratio");
 gr_R_n_ee->SetMarkerColor(kBlue);
 gr_R_n_ee->SetFillColor(kBlue);
 gr_R_n_ee->SetLineColor(kBlue);
 gr_R_n_ee->SetMarkerStyle(21);
 gr_R_n_ee->SetMarkerSize(1);
 gr_R_n_ee->SetLineWidth(1);

 
 TGraphErrors* gr_R_corrected_n_mumu = new TGraphErrors(num,X,YDATA_R_corrected_n_mumu,errX,errYDATA_R_corrected_n_mumu);
 gr_R_corrected_n_mumu->SetTitle("R^{#mu#mu}_{DATA} corr");
 gr_R_corrected_n_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_R_corrected_n_mumu->GetYaxis()->SetTitle("ratio");
 gr_R_corrected_n_mumu->SetMarkerColor(kGreen);
 gr_R_corrected_n_mumu->SetFillColor(kGreen);
 gr_R_corrected_n_mumu->SetLineColor(kGreen);
 gr_R_corrected_n_mumu->SetMarkerStyle(28);
 gr_R_corrected_n_mumu->SetMarkerSize(1);
 gr_R_corrected_n_mumu->SetLineWidth(2);
 gr_R_corrected_n_mumu->SetLineStyle(2);
 
 TGraphErrors* gr_R_corrected_n_ee = new TGraphErrors(num,X,YDATA_R_corrected_n_ee,errX,errYDATA_R_corrected_n_ee);
 gr_R_corrected_n_ee->SetTitle("R^{ee}_{DATA} corr");
 gr_R_corrected_n_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_R_corrected_n_ee->GetYaxis()->SetTitle("ratio");
 gr_R_corrected_n_ee->SetMarkerColor(kGreen);
 gr_R_corrected_n_ee->SetFillColor(kGreen);
 gr_R_corrected_n_ee->SetLineColor(kGreen);
 gr_R_corrected_n_ee->SetMarkerStyle(28);
 gr_R_corrected_n_ee->SetMarkerSize(1);
 gr_R_corrected_n_ee->SetLineWidth(1);
 gr_R_corrected_n_ee->SetLineStyle(2);
 
 
 
 
 
 
 ///==== ratio from data = noLimit ====
 
 TGraphErrors* gr_R_noLimit_n_mumu = new TGraphErrors(num,X,YDATA_R_noLimit_n_mumu,errX,errYDATA_R_noLimit_n_mumu);
 gr_R_noLimit_n_mumu->SetTitle("R^{#mu#mu}_{DATA}");
 gr_R_noLimit_n_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_R_noLimit_n_mumu->GetYaxis()->SetTitle("ratio");
 gr_R_noLimit_n_mumu->SetMarkerColor(kRed);
 gr_R_noLimit_n_mumu->SetFillColor(kRed);
 gr_R_noLimit_n_mumu->SetLineColor(kRed);
 gr_R_noLimit_n_mumu->SetMarkerStyle(20);
 gr_R_noLimit_n_mumu->SetMarkerSize(1);
 gr_R_noLimit_n_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_R_noLimit_n_ee = new TGraphErrors(num,X,YDATA_R_noLimit_n_ee,errX,errYDATA_R_noLimit_n_ee);
 gr_R_noLimit_n_ee->SetTitle("R^{ee}_{DATA}");
 gr_R_noLimit_n_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_R_noLimit_n_ee->GetYaxis()->SetTitle("ratio");
 gr_R_noLimit_n_ee->SetMarkerColor(kBlue);
 gr_R_noLimit_n_ee->SetFillColor(kBlue);
 gr_R_noLimit_n_ee->SetLineColor(kBlue);
 gr_R_noLimit_n_ee->SetMarkerStyle(21);
 gr_R_noLimit_n_ee->SetMarkerSize(1);
 gr_R_noLimit_n_ee->SetLineWidth(1);
 
 
 TGraphErrors* gr_R_corrected_noLimit_n_mumu = new TGraphErrors(num,X,YDATA_R_corrected_noLimit_n_mumu,errX,errYDATA_R_corrected_noLimit_n_mumu);
 gr_R_corrected_noLimit_n_mumu->SetTitle("R^{#mu#mu}_{DATA} corr");
 gr_R_corrected_noLimit_n_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_R_corrected_noLimit_n_mumu->GetYaxis()->SetTitle("ratio");
 gr_R_corrected_noLimit_n_mumu->SetMarkerColor(kGreen);
 gr_R_corrected_noLimit_n_mumu->SetFillColor(kGreen);
 gr_R_corrected_noLimit_n_mumu->SetLineColor(kGreen);
 gr_R_corrected_noLimit_n_mumu->SetMarkerStyle(28);
 gr_R_corrected_noLimit_n_mumu->SetMarkerSize(1);
 gr_R_corrected_noLimit_n_mumu->SetLineWidth(2);
 gr_R_corrected_noLimit_n_mumu->SetLineStyle(2);
 
 TGraphErrors* gr_R_corrected_noLimit_n_ee = new TGraphErrors(num,X,YDATA_R_corrected_noLimit_n_ee,errX,errYDATA_R_corrected_noLimit_n_ee);
 gr_R_corrected_noLimit_n_ee->SetTitle("R^{ee}_{DATA} corr");
 gr_R_corrected_noLimit_n_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_R_corrected_noLimit_n_ee->GetYaxis()->SetTitle("ratio");
 gr_R_corrected_noLimit_n_ee->SetMarkerColor(kGreen);
 gr_R_corrected_noLimit_n_ee->SetFillColor(kGreen);
 gr_R_corrected_noLimit_n_ee->SetLineColor(kGreen);
 gr_R_corrected_noLimit_n_ee->SetMarkerStyle(28);
 gr_R_corrected_noLimit_n_ee->SetMarkerSize(1);
 gr_R_corrected_noLimit_n_ee->SetLineWidth(1);
 gr_R_corrected_noLimit_n_ee->SetLineStyle(2);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 TGraphErrors* gr_R_N_mumu = new TGraphErrors(num,X,YDATA_R_N_mumu,errX,errYDATA_R_N_mumu);
 gr_R_N_mumu->SetTitle("R^{#mu#mu}_{DATA}");
 gr_R_N_mumu->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_R_N_mumu->GetYaxis()->SetTitle("ratio");
 gr_R_N_mumu->SetMarkerColor(kRed);
 gr_R_N_mumu->SetFillColor(kRed);
 gr_R_N_mumu->SetLineColor(kRed);
 gr_R_N_mumu->SetMarkerStyle(20);
 gr_R_N_mumu->SetMarkerSize(1);
 gr_R_N_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_R_N_ee = new TGraphErrors(num,X,YDATA_R_N_ee,errX,errYDATA_R_N_ee);
 gr_R_N_ee->SetTitle("R^{ee}_{DATA}");
 gr_R_N_ee->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_R_N_ee->GetYaxis()->SetTitle("ratio");
 gr_R_N_ee->SetMarkerColor(kBlue);
 gr_R_N_ee->SetFillColor(kBlue);
 gr_R_N_ee->SetLineColor(kBlue);
 gr_R_N_ee->SetMarkerStyle(21);
 gr_R_N_ee->SetMarkerSize(1);
 gr_R_N_ee->SetLineWidth(1);
 
 
 
 ///==== plot ====
 
 ///==== n ====
 
 TCanvas cc_R_ee;
 TMultiGraph* mgr_ee_R = new TMultiGraph(); 
 mgr_ee_R->Add(gr_R_n_ee);
 mgr_ee_R->Add(gr_R_corrected_n_ee);
 mgr_ee_R->Add(grRatioInversed_madee);
 mgr_ee_R->Add(grRatioInversed_powee);
 mgr_ee_R->Draw("AP");
 mgr_ee_R->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_ee_R->GetYaxis()->SetTitle("ratio ee");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas cc_R_mumu;
 TMultiGraph* mgr_mumu_R = new TMultiGraph(); 
 mgr_mumu_R->Add(gr_R_n_mumu);
 mgr_mumu_R->Add(gr_R_corrected_n_mumu);
 mgr_mumu_R->Add(grRatioInversed_madmumu);
 mgr_mumu_R->Add(grRatioInversed_powmumu);
 mgr_mumu_R->Draw("AP");
 mgr_mumu_R->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_mumu_R->GetYaxis()->SetTitle("ratio #mu#mu");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 
 ///==== noLimit ==== 
 
 TCanvas cc_R_noLimit_ee;
 TMultiGraph* mgr_ee_R_noLimit = new TMultiGraph(); 
 mgr_ee_R_noLimit->Add(gr_R_noLimit_n_ee);
 mgr_ee_R_noLimit->Add(gr_R_corrected_noLimit_n_ee);
 mgr_ee_R_noLimit->Add(grRatioInversed_noLimit_madee);
 mgr_ee_R_noLimit->Add(grRatioInversed_noLimit_powee);
 mgr_ee_R_noLimit->Draw("AP");
 mgr_ee_R_noLimit->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_ee_R_noLimit->GetYaxis()->SetTitle("ratio ee");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas cc_R_noLimit_mumu;
 TMultiGraph* mgr_mumu_R_noLimit = new TMultiGraph(); 
 mgr_mumu_R_noLimit->Add(gr_R_noLimit_n_mumu);
 mgr_mumu_R_noLimit->Add(gr_R_corrected_noLimit_n_mumu);
 mgr_mumu_R_noLimit->Add(grRatioInversed_noLimit_madmumu);
 mgr_mumu_R_noLimit->Add(grRatioInversed_noLimit_powmumu);
 mgr_mumu_R_noLimit->Draw("AP");
 mgr_mumu_R_noLimit->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_mumu_R_noLimit->GetYaxis()->SetTitle("ratio #mu#mu");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 ///==== N ====
 
 
 
 
 TCanvas cc_R_N_ee;
 TMultiGraph* mgr_ee_R = new TMultiGraph(); 
 mgr_ee_R->Add(gr_R_N_ee);
 mgr_ee_R->Add(grRatio_madee);
 mgr_ee_R->Add(grRatio_powee);
 mgr_ee_R->Draw("AP");
 mgr_ee_R->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_ee_R->GetYaxis()->SetTitle("ratio ee");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 TCanvas cc_R_N_mumu;
 TMultiGraph* mgr_mumu_R = new TMultiGraph(); 
 mgr_mumu_R->Add(gr_R_N_mumu);
 mgr_mumu_R->Add(grRatio_madmumu);
 mgr_mumu_R->Add(grRatio_powmumu);
 mgr_mumu_R->Draw("AP");
 mgr_mumu_R->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_mumu_R->GetYaxis()->SetTitle("ratio #mu#mu");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 ///==== k from data ====
 
 TGraphErrors* gr_k_B_mumu = new TGraphErrors(num,X,YDATA_k_B_mumu,errX,errYDATA_k_B_mumu);
 gr_k_B_mumu->SetTitle("k^{#mu#mu}_{DATA} B");
 gr_k_B_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_k_B_mumu->GetYaxis()->SetTitle("k");
 gr_k_B_mumu->SetMarkerColor(kRed);
 gr_k_B_mumu->SetFillColor(kRed);
 gr_k_B_mumu->SetLineColor(kRed);
 gr_k_B_mumu->SetMarkerStyle(20);
 gr_k_B_mumu->SetMarkerSize(1);
 gr_k_B_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_k_B_ee = new TGraphErrors(num,X,YDATA_k_B_ee,errX,errYDATA_k_B_ee);
 gr_k_B_ee->SetTitle("k^{ee}_{DATA} B");
 gr_k_B_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_k_B_ee->GetYaxis()->SetTitle("k");
 gr_k_B_ee->SetMarkerColor(kBlue);
 gr_k_B_ee->SetFillColor(kBlue);
 gr_k_B_ee->SetLineColor(kBlue);
 gr_k_B_ee->SetMarkerStyle(21);
 gr_k_B_ee->SetMarkerSize(1);
 gr_k_B_ee->SetLineWidth(1);
 
 TGraphErrors* gr_k_A_mumu = new TGraphErrors(num,X,YDATA_k_A_mumu,errX,errYDATA_k_A_mumu);
 gr_k_A_mumu->SetTitle("k^{#mu#mu}_{DATA} A");
 gr_k_A_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_k_A_mumu->GetYaxis()->SetTitle("k");
 gr_k_A_mumu->SetMarkerColor(kOrange);
 gr_k_A_mumu->SetFillColor(kOrange);
 gr_k_A_mumu->SetLineColor(kOrange);
 gr_k_A_mumu->SetMarkerStyle(20);
 gr_k_A_mumu->SetMarkerSize(1);
 gr_k_A_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_k_A_ee = new TGraphErrors(num,X,YDATA_k_A_ee,errX,errYDATA_k_A_ee);
 gr_k_A_ee->SetTitle("k^{ee}_{DATA} A");
 gr_k_A_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_k_A_ee->GetYaxis()->SetTitle("k");
 gr_k_A_ee->SetMarkerColor(kTeal);
 gr_k_A_ee->SetFillColor(kTeal);
 gr_k_A_ee->SetLineColor(kTeal);
 gr_k_A_ee->SetMarkerStyle(21);
 gr_k_A_ee->SetMarkerSize(1);
 gr_k_A_ee->SetLineWidth(1);
 
 
 
 
 
 
 
 
 TGraphErrors* gr_k_noLimit_B_mumu = new TGraphErrors(num,X,YDATA_k_noLimit_B_mumu,errX,errYDATA_k_noLimit_B_mumu);
 gr_k_noLimit_B_mumu->SetTitle("k^{#mu#mu}_{DATA} B noLimit");
 gr_k_noLimit_B_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_k_noLimit_B_mumu->GetYaxis()->SetTitle("k");
 gr_k_noLimit_B_mumu->SetMarkerColor(kRed-1);
 gr_k_noLimit_B_mumu->SetFillColor(kRed-1);
 gr_k_noLimit_B_mumu->SetLineColor(kRed-1);
 gr_k_noLimit_B_mumu->SetMarkerStyle(20+4);
 gr_k_noLimit_B_mumu->SetMarkerSize(1);
 gr_k_noLimit_B_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_k_noLimit_B_ee = new TGraphErrors(num,X,YDATA_k_noLimit_B_ee,errX,errYDATA_k_noLimit_B_ee);
 gr_k_noLimit_B_ee->SetTitle("k^{ee}_{DATA} B noLimit");
 gr_k_noLimit_B_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_k_noLimit_B_ee->GetYaxis()->SetTitle("k");
 gr_k_noLimit_B_ee->SetMarkerColor(kBlue-1);
 gr_k_noLimit_B_ee->SetFillColor(kBlue-1);
 gr_k_noLimit_B_ee->SetLineColor(kBlue-1);
 gr_k_noLimit_B_ee->SetMarkerStyle(21+4);
 gr_k_noLimit_B_ee->SetMarkerSize(1);
 gr_k_noLimit_B_ee->SetLineWidth(1);
 
 TGraphErrors* gr_k_noLimit_A_mumu = new TGraphErrors(num,X,YDATA_k_noLimit_A_mumu,errX,errYDATA_k_noLimit_A_mumu);
 gr_k_noLimit_A_mumu->SetTitle("k^{#mu#mu}_{DATA} A noLimit");
 gr_k_noLimit_A_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_k_noLimit_A_mumu->GetYaxis()->SetTitle("k");
 gr_k_noLimit_A_mumu->SetMarkerColor(kOrange-1);
 gr_k_noLimit_A_mumu->SetFillColor(kOrange-1);
 gr_k_noLimit_A_mumu->SetLineColor(kOrange-1);
 gr_k_noLimit_A_mumu->SetMarkerStyle(20+4);
 gr_k_noLimit_A_mumu->SetMarkerSize(1);
 gr_k_noLimit_A_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_k_noLimit_A_ee = new TGraphErrors(num,X,YDATA_k_noLimit_A_ee,errX,errYDATA_k_noLimit_A_ee);
 gr_k_noLimit_A_ee->SetTitle("k^{ee}_{DATA} A noLimit");
 gr_k_noLimit_A_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_k_noLimit_A_ee->GetYaxis()->SetTitle("k");
 gr_k_noLimit_A_ee->SetMarkerColor(kTeal-1);
 gr_k_noLimit_A_ee->SetFillColor(kTeal-1);
 gr_k_noLimit_A_ee->SetLineColor(kTeal-1);
 gr_k_noLimit_A_ee->SetMarkerStyle(21+4);
 gr_k_noLimit_A_ee->SetMarkerSize(1);
 gr_k_noLimit_A_ee->SetLineWidth(1);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 TCanvas cc_k;
 TMultiGraph* mgr_k = new TMultiGraph();
 
 mgr_k->Add(gr_k_B_mumu);
 mgr_k->Add(gr_k_A_mumu);
 mgr_k->Add(gr_k_noLimit_B_mumu);
 mgr_k->Add(gr_k_noLimit_A_mumu);
 mgr_k->Add(gr_k_B_ee);
 mgr_k->Add(gr_k_A_ee);
 mgr_k->Add(gr_k_noLimit_B_ee);
 mgr_k->Add(gr_k_noLimit_A_ee);
 mgr_k->Draw("AP");
 mgr_k->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_k->GetYaxis()->SetTitle("k");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 ///==== N_emu from data ====
 
 TGraphErrors* gr_B_emu = new TGraphErrors(num,X,YDATA_B_emu,errX,errYDATA_B_emu);
 gr_B_emu->SetTitle("N^{e#mu}_{DATA} B");
 gr_B_emu->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_B_emu->GetYaxis()->SetTitle("occupancy");
 gr_B_emu->SetMarkerColor(kRed);
 gr_B_emu->SetFillColor(kRed);
 gr_B_emu->SetLineColor(kRed);
 gr_B_emu->SetMarkerStyle(20);
 gr_B_emu->SetMarkerSize(1);
 gr_B_emu->SetLineWidth(2);
 
 TGraphErrors* gr_A_emu = new TGraphErrors(num,X,YDATA_A_emu,errX,errYDATA_A_emu);
 gr_A_emu->SetTitle("N^{e#mu}_{DATA} A");
 gr_A_emu->GetXaxis()->SetTitle("met > threshold (GeV)");
 gr_A_emu->GetYaxis()->SetTitle("occupancy");
 gr_A_emu->SetMarkerColor(kBlue);
 gr_A_emu->SetFillColor(kBlue);
 gr_A_emu->SetLineColor(kBlue);
 gr_A_emu->SetMarkerStyle(20);
 gr_A_emu->SetMarkerSize(1);
 gr_A_emu->SetLineWidth(2);
 
 TCanvas cc_N_emu;
 TMultiGraph* mgr_N_emu = new TMultiGraph();
 
 mgr_N_emu->Add(gr_B_emu);
 mgr_N_emu->Add(gr_A_emu);
 mgr_N_emu->Draw("AP");
 mgr_N_emu->GetXaxis()->SetTitle("met > threshold (GeV)");
 mgr_N_emu->GetYaxis()->SetTitle("occupancy");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 ///==== n_emu, n_ee, n_mumu from data ====
 
 TGraphErrors* gr_B_emu = new TGraphErrors(num,X,YDATA_B_metReversed_emu,errX,errYDATA_B_metReversed_emu);
 gr_B_emu->SetTitle("n^{e#mu}_{DATA} B");
 gr_B_emu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_B_emu->GetYaxis()->SetTitle("occupancy");
 gr_B_emu->SetMarkerColor(kRed);
 gr_B_emu->SetFillColor(kRed);
 gr_B_emu->SetLineColor(kRed);
 gr_B_emu->SetMarkerStyle(20);
 gr_B_emu->SetMarkerSize(1);
 gr_B_emu->SetLineWidth(2);
 
 TGraphErrors* gr_A_emu = new TGraphErrors(num,X,YDATA_A_metReversed_emu,errX,errYDATA_A_metReversed_emu);
 gr_A_emu->SetTitle("n^{e#mu}_{DATA} A");
 gr_A_emu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_A_emu->GetYaxis()->SetTitle("occupancy");
 gr_A_emu->SetMarkerColor(kBlue);
 gr_A_emu->SetFillColor(kBlue);
 gr_A_emu->SetLineColor(kBlue);
 gr_A_emu->SetMarkerStyle(20);
 gr_A_emu->SetMarkerSize(1);
 gr_A_emu->SetLineWidth(2);

 TGraphErrors* gr_B_ee = new TGraphErrors(num,X,YDATA_B_metReversed_ee,errX,errYDATA_B_metReversed_ee);
 gr_B_ee->SetTitle("n^{ee}_{DATA} B");
 gr_B_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_B_ee->GetYaxis()->SetTitle("occupancy");
 gr_B_ee->SetMarkerColor(kMagenta);
 gr_B_ee->SetFillColor(kMagenta);
 gr_B_ee->SetLineColor(kMagenta);
 gr_B_ee->SetMarkerStyle(20);
 gr_B_ee->SetMarkerSize(1);
 gr_B_ee->SetLineWidth(2);
 
 TGraphErrors* gr_A_ee = new TGraphErrors(num,X,YDATA_A_metReversed_ee,errX,errYDATA_A_metReversed_ee);
 gr_A_ee->SetTitle("n^{ee}_{DATA} A");
 gr_A_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_A_ee->GetYaxis()->SetTitle("occupancy");
 gr_A_ee->SetMarkerColor(kGreen);
 gr_A_ee->SetFillColor(kGreen);
 gr_A_ee->SetLineColor(kGreen);
 gr_A_ee->SetMarkerStyle(20);
 gr_A_ee->SetMarkerSize(1);
 gr_A_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_B_mumu = new TGraphErrors(num,X,YDATA_B_metReversed_mumu,errX,errYDATA_B_metReversed_mumu);
 gr_B_mumu->SetTitle("n^{#mu#mu}_{DATA} B");
 gr_B_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_B_mumu->GetYaxis()->SetTitle("occupancy");
 gr_B_mumu->SetMarkerColor(kOrange);
 gr_B_mumu->SetFillColor(kOrange);
 gr_B_mumu->SetLineColor(kOrange);
 gr_B_mumu->SetMarkerStyle(20);
 gr_B_mumu->SetMarkerSize(1);
 gr_B_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_A_mumu = new TGraphErrors(num,X,YDATA_A_metReversed_mumu,errX,errYDATA_A_metReversed_mumu);
 gr_A_mumu->SetTitle("n^{#mu#mu}_{DATA} A");
 gr_A_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_A_mumu->GetYaxis()->SetTitle("occupancy");
 gr_A_mumu->SetMarkerColor(kTeal);
 gr_A_mumu->SetFillColor(kTeal);
 gr_A_mumu->SetLineColor(kTeal);
 gr_A_mumu->SetMarkerStyle(20);
 gr_A_mumu->SetMarkerSize(1);
 gr_A_mumu->SetLineWidth(2);
 
 TCanvas cc_n;
 TMultiGraph* mgr_n = new TMultiGraph();
 
 mgr_n->Add(gr_B_emu);
 mgr_n->Add(gr_A_emu);
 mgr_n->Add(gr_B_ee);
 mgr_n->Add(gr_A_ee);
 mgr_n->Add(gr_B_mumu);
 mgr_n->Add(gr_A_mumu);
 mgr_n->Draw("AP");
 mgr_n->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n->GetYaxis()->SetTitle("occupancy");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 ///==== n_emu, n_ee, n_mumu from data - no met Limit ====
 
 TGraphErrors* gr_B_noLimit_emu = new TGraphErrors(num,X,YDATA_B_metReversed_noLimit_emu,errX,errYDATA_B_metReversed_noLimit_emu);
 gr_B_noLimit_emu->SetTitle("n^{e#mu}_{DATA} B");
 gr_B_noLimit_emu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_B_noLimit_emu->GetYaxis()->SetTitle("occupancy");
 gr_B_noLimit_emu->SetMarkerColor(kRed);
 gr_B_noLimit_emu->SetFillColor(kRed);
 gr_B_noLimit_emu->SetLineColor(kRed);
 gr_B_noLimit_emu->SetMarkerStyle(20);
 gr_B_noLimit_emu->SetMarkerSize(1);
 gr_B_noLimit_emu->SetLineWidth(2);
 
 TGraphErrors* gr_A_noLimit_emu = new TGraphErrors(num,X,YDATA_A_metReversed_noLimit_emu,errX,errYDATA_A_metReversed_noLimit_emu);
 gr_A_noLimit_emu->SetTitle("n^{e#mu}_{DATA} A");
 gr_A_noLimit_emu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_A_noLimit_emu->GetYaxis()->SetTitle("occupancy");
 gr_A_noLimit_emu->SetMarkerColor(kBlue);
 gr_A_noLimit_emu->SetFillColor(kBlue);
 gr_A_noLimit_emu->SetLineColor(kBlue);
 gr_A_noLimit_emu->SetMarkerStyle(20);
 gr_A_noLimit_emu->SetMarkerSize(1);
 gr_A_noLimit_emu->SetLineWidth(2);
 
 TGraphErrors* gr_B_noLimit_ee = new TGraphErrors(num,X,YDATA_B_metReversed_noLimit_ee,errX,errYDATA_B_metReversed_noLimit_ee);
 gr_B_noLimit_ee->SetTitle("n^{ee}_{DATA} B");
 gr_B_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_B_noLimit_ee->GetYaxis()->SetTitle("occupancy");
 gr_B_noLimit_ee->SetMarkerColor(kMagenta);
 gr_B_noLimit_ee->SetFillColor(kMagenta);
 gr_B_noLimit_ee->SetLineColor(kMagenta);
 gr_B_noLimit_ee->SetMarkerStyle(20);
 gr_B_noLimit_ee->SetMarkerSize(1);
 gr_B_noLimit_ee->SetLineWidth(2);
 
 TGraphErrors* gr_A_noLimit_ee = new TGraphErrors(num,X,YDATA_A_metReversed_noLimit_ee,errX,errYDATA_A_metReversed_noLimit_ee);
 gr_A_noLimit_ee->SetTitle("n^{ee}_{DATA} A");
 gr_A_noLimit_ee->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_A_noLimit_ee->GetYaxis()->SetTitle("occupancy");
 gr_A_noLimit_ee->SetMarkerColor(kGreen);
 gr_A_noLimit_ee->SetFillColor(kGreen);
 gr_A_noLimit_ee->SetLineColor(kGreen);
 gr_A_noLimit_ee->SetMarkerStyle(20);
 gr_A_noLimit_ee->SetMarkerSize(1);
 gr_A_noLimit_ee->SetLineWidth(2);
 
 
 TGraphErrors* gr_B_noLimit_mumu = new TGraphErrors(num,X,YDATA_B_metReversed_noLimit_mumu,errX,errYDATA_B_metReversed_noLimit_mumu);
 gr_B_noLimit_mumu->SetTitle("n^{#mu#mu}_{DATA} B");
 gr_B_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_B_noLimit_mumu->GetYaxis()->SetTitle("occupancy");
 gr_B_noLimit_mumu->SetMarkerColor(kOrange);
 gr_B_noLimit_mumu->SetFillColor(kOrange);
 gr_B_noLimit_mumu->SetLineColor(kOrange);
 gr_B_noLimit_mumu->SetMarkerStyle(20);
 gr_B_noLimit_mumu->SetMarkerSize(1);
 gr_B_noLimit_mumu->SetLineWidth(2);
 
 TGraphErrors* gr_A_noLimit_mumu = new TGraphErrors(num,X,YDATA_A_metReversed_noLimit_mumu,errX,errYDATA_A_metReversed_noLimit_mumu);
 gr_A_noLimit_mumu->SetTitle("n^{#mu#mu}_{DATA} A");
 gr_A_noLimit_mumu->GetXaxis()->SetTitle("met < threshold (GeV)");
 gr_A_noLimit_mumu->GetYaxis()->SetTitle("occupancy");
 gr_A_noLimit_mumu->SetMarkerColor(kTeal);
 gr_A_noLimit_mumu->SetFillColor(kTeal);
 gr_A_noLimit_mumu->SetLineColor(kTeal);
 gr_A_noLimit_mumu->SetMarkerStyle(20);
 gr_A_noLimit_mumu->SetMarkerSize(1);
 gr_A_noLimit_mumu->SetLineWidth(2);
 
 TCanvas cc_n_noLimit;
 TMultiGraph* mgr_n_noLimit = new TMultiGraph();
 
 mgr_n_noLimit->Add(gr_B_noLimit_emu);
 mgr_n_noLimit->Add(gr_A_noLimit_emu);
 mgr_n_noLimit->Add(gr_B_noLimit_ee);
 mgr_n_noLimit->Add(gr_A_noLimit_ee);
 mgr_n_noLimit->Add(gr_B_noLimit_mumu);
 mgr_n_noLimit->Add(gr_A_noLimit_mumu);
 mgr_n_noLimit->Draw("AP");
 mgr_n_noLimit->GetXaxis()->SetTitle("met < threshold (GeV)");
 mgr_n_noLimit->GetYaxis()->SetTitle("occupancy");
 
 
 TLegend* leg = gPad->BuildLegend();
 leg->SetFillColor(kWhite);
 gPad->SetGrid();
 
 
 
 
 
 }