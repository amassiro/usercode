double ptHWeight(double pt){ 
if (pt < 0) return 1;
if (pt >= 0 && pt < 2) return 1.11903 ; 
if (pt >= 2 && pt < 3) return 1.14494 ; 
if (pt >= 3 && pt < 4) return 1.16497 ; 
if (pt >= 4 && pt < 5) return 1.13408 ; 
if (pt >= 5 && pt < 6) return 1.09525 ; 
if (pt >= 6 && pt < 7) return 1.08863 ; 
if (pt >= 7 && pt < 8) return 1.04259 ; 
if (pt >= 8 && pt < 9) return 1.05574 ; 
if (pt >= 9 && pt < 10) return 1.01626 ; 
if (pt >= 10 && pt < 11) return 1.02304 ; 
if (pt >= 11 && pt < 12) return 1.0265 ; 
if (pt >= 12 && pt < 13) return 1.02808 ; 
if (pt >= 13 && pt < 14) return 1.01727 ; 
if (pt >= 14 && pt < 15) return 1.02531 ; 
if (pt >= 15 && pt < 16) return 1.0254 ; 
if (pt >= 16 && pt < 17) return 1.02461 ; 
if (pt >= 17 && pt < 18) return 1.01185 ; 
if (pt >= 18 && pt < 19) return 1.01952 ; 
if (pt >= 19 && pt < 20) return 1.03479 ; 
if (pt >= 20 && pt < 21) return 1.02129 ; 
if (pt >= 21 && pt < 22) return 1.02466 ; 
if (pt >= 22 && pt < 23) return 1.04353 ; 
if (pt >= 23 && pt < 24) return 1.0291 ; 
if (pt >= 24 && pt < 25) return 1.01863 ; 
if (pt >= 25 && pt < 26) return 1.03191 ; 
if (pt >= 26 && pt < 27) return 1.01211 ; 
if (pt >= 27 && pt < 28) return 1.03187 ; 
if (pt >= 28 && pt < 29) return 1.02901 ; 
if (pt >= 29 && pt < 30) return 1.03446 ; 
if (pt >= 30 && pt < 31) return 1.03674 ; 
if (pt >= 31 && pt < 32) return 1.03581 ; 
if (pt >= 32 && pt < 33) return 1.02951 ; 
if (pt >= 33 && pt < 34) return 1.04242 ; 
if (pt >= 34 && pt < 35) return 1.04378 ; 
if (pt >= 35 && pt < 36) return 1.02699 ; 
if (pt >= 36 && pt < 37) return 1.04342 ; 
if (pt >= 37 && pt < 38) return 1.02372 ; 
if (pt >= 38 && pt < 39) return 1.03208 ; 
if (pt >= 39 && pt < 40) return 1.04361 ; 
if (pt >= 40 && pt < 41) return 1.03834 ; 
if (pt >= 41 && pt < 42) return 1.01824 ; 
if (pt >= 42 && pt < 43) return 1.03976 ; 
if (pt >= 43 && pt < 44) return 1.03402 ; 
if (pt >= 44 && pt < 45) return 1.01595 ; 
if (pt >= 45 && pt < 46) return 1.03791 ; 
if (pt >= 46 && pt < 47) return 1.0276 ; 
if (pt >= 47 && pt < 48) return 1.03462 ; 
if (pt >= 48 && pt < 49) return 1.00968 ; 
if (pt >= 49 && pt < 50) return 1.02453 ; 
if (pt >= 50 && pt < 52) return 1.01121 ; 
if (pt >= 52 && pt < 54) return 1.0069 ; 
if (pt >= 54 && pt < 56) return 1.00269 ; 
if (pt >= 56 && pt < 58) return 0.998631 ; 
if (pt >= 58 && pt < 60) return 0.994724 ; 
if (pt >= 60 && pt < 62) return 0.990926 ; 
if (pt >= 62 && pt < 64) return 0.987373 ; 
if (pt >= 64 && pt < 66) return 0.983909 ; 
if (pt >= 66 && pt < 68) return 0.980566 ; 
if (pt >= 68 && pt < 70) return 0.97733 ; 
if (pt >= 70 && pt < 73) return 0.964333 ; 
if (pt >= 73 && pt < 76) return 0.959897 ; 
if (pt >= 76 && pt < 79) return 0.955569 ; 
if (pt >= 79 && pt < 82) return 0.951303 ; 
if (pt >= 82 && pt < 85) return 0.947061 ; 
if (pt >= 85 && pt < 88) return 0.94281 ; 
if (pt >= 88 && pt < 91) return 0.93852 ; 
if (pt >= 91 && pt < 94) return 0.934181 ; 
if (pt >= 94 && pt < 97) return 0.929762 ; 
if (pt >= 97 && pt < 100) return 0.925243 ; 
if (pt >= 100 && pt < 105) return 0.903504 ; 
if (pt >= 105 && pt < 110) return 0.895779 ; 
if (pt >= 110 && pt < 115) return 0.887671 ; 
if (pt >= 115 && pt < 120) return 0.87916 ; 
if (pt >= 120 && pt < 125) return 0.870235 ; 
if (pt >= 125 && pt < 130) return 0.86089 ; 
if (pt >= 130 && pt < 135) return 0.851127 ; 
if (pt >= 135 && pt < 140) return 0.840952 ; 
if (pt >= 140 && pt < 145) return 0.830372 ; 
if (pt >= 145 && pt < 150) return 0.819396 ; 
if (pt >= 150 && pt < 155) return 0.808014 ; 
if (pt >= 155 && pt < 160) return 0.796325 ; 
if (pt >= 160 && pt < 165) return 0.784236 ; 
if (pt >= 165 && pt < 170) return 0.771804 ; 
if (pt >= 170 && pt < 175) return 0.759041 ; 
if (pt >= 175 && pt < 180) return 0.745959 ; 
if (pt >= 180 && pt < 185) return 0.732575 ; 
if (pt >= 185 && pt < 190) return 0.718897 ; 
if (pt >= 190 && pt < 195) return 0.704941 ; 
if (pt >= 195 && pt < 200) return 0.690717 ; 
if (pt >= 200 && pt < 205) return 0.676238 ; 
if (pt >= 205 && pt < 210) return 0.661514 ; 
if (pt >= 210 && pt < 215) return 0.646556 ; 
if (pt >= 215 && pt < 220) return 0.631373 ; 
if (pt >= 220 && pt < 225) return 0.615961 ; 
if (pt >= 225 && pt < 230) return 0.600373 ; 
if (pt >= 230 && pt < 235) return 0.584574 ; 
if (pt >= 235 && pt < 240) return 0.568587 ; 
if (pt >= 240 && pt < 245) return 0.55242 ; 
if (pt >= 245 && pt < 250) return 0.536079 ; 
if (pt >= 250 && pt < 255) return 0.57982 ; 
if (pt >= 255 && pt < 260) return 0.57982 ; 
if (pt >= 260 && pt < 265) return 0.57982 ; 
if (pt >= 265 && pt < 270) return 0.57982 ; 
if (pt >= 270 && pt < 275) return 0.57982 ; 
if (pt >= 275 && pt < 280) return 0.57982 ; 
if (pt >= 280 && pt < 285) return 0.57982 ; 
if (pt >= 285 && pt < 290) return 0.57982 ; 
if (pt >= 290 && pt < 295) return 0.57982 ; 
if (pt >= 295 && pt < 300) return 0.57982 ; 
if (pt >= 300 && pt < 305) return 0.57982 ; 
if (pt >= 305 && pt < 310) return 0.57982 ; 
if (pt >= 310 && pt < 315) return 0.57982 ; 
if (pt >= 315 && pt < 320) return 0.57982 ; 
if (pt >= 320 && pt < 325) return 0.57982 ; 
if (pt >= 325 && pt < 330) return 0.57982 ; 
if (pt >= 330 && pt < 335) return 0.57982 ; 
if (pt >= 335 && pt < 340) return 0.57982 ; 
if (pt >= 340 && pt < 345) return 0.57982 ; 
if (pt >= 345 && pt < 350) return 0.57982 ; 
if (pt >= 350 && pt < 355) return 0.57982 ; 
if (pt >= 355 && pt < 360) return 0.57982 ; 
if (pt >= 360 && pt < 365) return 0.57982 ; 
if (pt >= 365 && pt < 370) return 0.57982 ; 
if (pt >= 370 && pt < 375) return 0.57982 ; 
if (pt >= 375 && pt < 380) return 0.57982 ; 
if (pt >= 380 && pt < 385) return 0.57982 ; 
if (pt >= 385 && pt < 390) return 0.57982 ; 
if (pt >= 390 && pt < 395) return 0.57982 ; 
if (pt >= 395 && pt < 400) return 0.57982 ; 
if (pt >= 400 && pt < 410) return 0.57982 ; 
if (pt >= 410 && pt < 420) return 0.57982 ; 
if (pt >= 420 && pt < 430) return 0.57982 ; 
if (pt >= 430 && pt < 440) return 0.57982 ; 
if (pt >= 440 && pt < 450) return 0.57982 ; 
if (pt >= 450 && pt < 460) return 0.57982 ; 
if (pt >= 460 && pt < 470) return 0.57982 ; 
if (pt >= 470 && pt < 480) return 0.57982 ; 
if (pt >= 480 && pt < 490) return 0.57982 ; 
if (pt >= 490 && pt < 500) return 0.57982 ; 
if (pt >= 490 && pt < 500) return 0.57982 ; 
return 0.57982 ; 
} 
