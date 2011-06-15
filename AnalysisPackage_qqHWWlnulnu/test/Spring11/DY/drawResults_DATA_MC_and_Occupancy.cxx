{
 
 
 int num = 20;
 
 ///===================
 ///==== real data ====
 ///===================
 
 double X[100] =    {0, 1, 5, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 45 };
 double errX[100] = {0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0 };
  
 
 ///==== pmet > 15 ====
 
 double YDATA_A_ee[100] =    {  67 ,         65 ,         55 ,         46 ,         44 ,         41 ,         33 ,         27 ,         24 ,         21 ,         20 ,         18 ,         18 ,         15 ,         14 ,         13 ,         13 ,         12 ,         11 ,         10 };
 double errYDATA_A_ee[100]; 
 
 double YDATA_A_mumu[100] =    {308 ,        292 ,        236 ,        171 ,        147 ,        130 ,        112 ,         98 ,         89 ,         80 ,         75 ,         63 ,         60 ,         53 ,         51 ,         48 ,         43 ,         40 ,         36 ,         33 };
 double errYDATA_A_mumu[100]; 
 
 double YDATA_A_emu[100] =    {72 ,         70 ,         65 ,         58 ,         56 ,         56 ,         54 ,         54 ,         53 ,         51 ,         51 ,         50 ,         50 ,         48 ,         46 ,         45 ,         44 ,         43 ,         42 ,         39};
 double errYDATA_A_emu[100];
 
 double YDATA_A_metReversed_ee[100] =    {37 ,          0 ,          0 ,          0 ,          0 ,          0 ,          4 ,         10 ,         13 ,         16 ,         17 ,         19 ,         19 ,         22 ,         23 ,         24 ,         24 ,         25 ,         26 ,         27};
 double errYDATA_A_metReversed_ee[100] ;
 
 double YDATA_A_metReversed_mumu[100] =    {118 ,          0 ,          0 ,          0 ,          0 ,          0 ,          6 ,         20 ,         29 ,         38 ,         43 ,         55 ,         58 ,         65 ,         67 ,         70 ,         75 ,         78 ,         82 ,         85};
 double errYDATA_A_metReversed_mumu[100] ;
 
 double YDATA_A_metReversed_emu[100] =    {55 ,          0 ,          0 ,          0 ,          0 ,          0 ,          1 ,          1 ,          2 ,          4 ,          4 ,          5 ,          5 ,          7 ,          9 ,         10 ,         11 ,         12 ,         13 ,         16};
 double errYDATA_A_metReversed_emu[100];
 
 double YDATA_A_metReversed_noLimit_ee[100] =    { 67 ,          2 ,         12 ,         21 ,         23 ,         26 ,         34 ,         40 ,         43 ,         46 ,         47 ,         49 ,         49 ,         52 ,         53 ,         54 ,         54 ,         55 ,         56 ,         57};
 double errYDATA_A_metReversed_noLimit_ee[100] ;
 
 double YDATA_A_metReversed_noLimit_mumu[100] =    {308 ,         16 ,         72 ,        137 ,        161 ,        178 ,        196 ,        210 ,        219 ,        228 ,        233 ,        245 ,        248 ,        255 ,        257 ,        260 ,        265 ,        268 ,        272 ,        275};
 double errYDATA_A_metReversed_noLimit_mumu[100] ;
 
 double YDATA_A_metReversed_noLimit_emu[100] =    { 72 ,          2 ,          7 ,         14 ,         16 ,         16 ,         18 ,         18 ,         19 ,         21 ,         21 ,         22 ,         22 ,         24 ,         26 ,         27 ,         28 ,         29 ,         30 ,         33};
 double errYDATA_A_metReversed_noLimit_emu[100];
 
 
 
 
 
 
 
 double YDATA_B_ee[100] =    { 607 ,        570 ,        434 ,        306 ,        257 ,        213 ,        172 ,        142 ,        122 ,        106 ,         80 ,         64 ,         48 ,         38 ,         31 ,         27 ,         24 ,         20 ,         19 ,         14};
 double errYDATA_B_ee[100]; 
 
 double YDATA_B_mumu[100] =    {2927 ,       2765 ,       2117 ,       1480 ,       1246 ,       1038 ,        879 ,        721 ,        596 ,        470 ,        394 ,        318 ,        263 ,        223 ,        181 ,        153 ,        131 ,        106 ,         86 ,         63};
 double errYDATA_B_mumu[100]; 
 
 double YDATA_B_emu[100] =    {60 ,         58 ,         55 ,         50 ,         50 ,         47 ,         44 ,         43 ,         41 ,         38 ,         36 ,         36 ,         35 ,         32 ,         31 ,         30 ,         29 ,         29 ,         28 ,         25};
 double errYDATA_B_emu[100];
 
 double YDATA_B_metReversed_ee[100] =    {197 ,          0 ,          0 ,          0 ,          0 ,          0 ,         25 ,         55 ,         75 ,         91 ,        117 ,        133 ,        149 ,        159 ,        166 ,        170 ,        173 ,        177 ,        178 ,        183};
 double errYDATA_B_metReversed_ee[100] ;
 
 double YDATA_B_metReversed_mumu[100] =    {  962 ,          0 ,          0 ,          0 ,          0 ,          0 ,         83 ,        241 ,        366 ,        492 ,        568 ,        644 ,        699 ,        739 ,        781 ,        809 ,        831 ,        856 ,        876 ,        899};
 double errYDATA_B_metReversed_mumu[100] ;
 
 double YDATA_B_metReversed_emu[100] =    {45 ,          0 ,          0 ,          0 ,          0 ,          0 ,          1 ,          2 ,          4 ,          7 ,          9 ,          9 ,         10 ,         13 ,         14 ,         15 ,         16 ,         16 ,         17 ,         20};
 double errYDATA_B_metReversed_emu[100];
 
 double YDATA_B_metReversed_noLimit_ee[100] =    {607 ,         37 ,        173 ,        301 ,        350 ,        394 ,        435 ,        465 ,        485 ,        501 ,        527 ,        543 ,        559 ,        569 ,        576 ,        580 ,        583 ,        587 ,        588 ,        593};
 double errYDATA_B_metReversed_noLimit_ee[100] ;
 
 double YDATA_B_metReversed_noLimit_mumu[100] =    {  2927 ,        162 ,        810 ,       1447 ,       1681 ,       1889 ,       2048 ,       2206 ,       2331 ,       2457 ,       2533 ,       2609 ,       2664 ,       2704 ,       2746 ,       2774 ,       2796 ,       2821 ,       2841 ,       2864};
 double errYDATA_B_metReversed_noLimit_mumu[100] ;
 
 double YDATA_B_metReversed_noLimit_emu[100] =    {60 ,          2 ,          5 ,         10 ,         10 ,         13 ,         16 ,         17 ,         19 ,         22 ,         24 ,         24 ,         25 ,         28 ,         29 ,         30 ,         31 ,         31 ,         32 ,         35};
 double errYDATA_B_metReversed_noLimit_emu[100];
 
 
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