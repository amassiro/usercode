double ptHWeight(double pt){ 
if (pt < 0) return 1;
if (pt >= 0 && pt < 2) return 1.04063 ; 
if (pt >= 2 && pt < 3) return 1.26116 ; 
if (pt >= 3 && pt < 4) return 1.28082 ; 
if (pt >= 4 && pt < 5) return 1.26689 ; 
if (pt >= 5 && pt < 6) return 1.23895 ; 
if (pt >= 6 && pt < 7) return 1.2193 ; 
if (pt >= 7 && pt < 8) return 1.18701 ; 
if (pt >= 8 && pt < 9) return 1.18053 ; 
if (pt >= 9 && pt < 10) return 1.16694 ; 
if (pt >= 10 && pt < 11) return 1.16697 ; 
if (pt >= 11 && pt < 12) return 1.16239 ; 
if (pt >= 12 && pt < 13) return 1.15137 ; 
if (pt >= 13 && pt < 14) return 1.15202 ; 
if (pt >= 14 && pt < 15) return 1.14699 ; 
if (pt >= 15 && pt < 16) return 1.14213 ; 
if (pt >= 16 && pt < 17) return 1.12637 ; 
if (pt >= 17 && pt < 18) return 1.13243 ; 
if (pt >= 18 && pt < 19) return 1.14425 ; 
if (pt >= 19 && pt < 20) return 1.14385 ; 
if (pt >= 20 && pt < 21) return 1.13998 ; 
if (pt >= 21 && pt < 22) return 1.12952 ; 
if (pt >= 22 && pt < 23) return 1.13872 ; 
if (pt >= 23 && pt < 24) return 1.13383 ; 
if (pt >= 24 && pt < 25) return 1.12462 ; 
if (pt >= 25 && pt < 26) return 1.11421 ; 
if (pt >= 26 && pt < 27) return 1.1197 ; 
if (pt >= 27 && pt < 28) return 1.12123 ; 
if (pt >= 28 && pt < 29) return 1.12277 ; 
if (pt >= 29 && pt < 30) return 1.09236 ; 
if (pt >= 30 && pt < 31) return 1.08413 ; 
if (pt >= 31 && pt < 32) return 1.0948 ; 
if (pt >= 32 && pt < 33) return 1.08884 ; 
if (pt >= 33 && pt < 34) return 1.07764 ; 
if (pt >= 34 && pt < 35) return 1.08777 ; 
if (pt >= 35 && pt < 36) return 1.10338 ; 
if (pt >= 36 && pt < 37) return 1.07855 ; 
if (pt >= 37 && pt < 38) return 1.05481 ; 
if (pt >= 38 && pt < 39) return 1.06916 ; 
if (pt >= 39 && pt < 40) return 1.06382 ; 
if (pt >= 40 && pt < 41) return 1.05845 ; 
if (pt >= 41 && pt < 42) return 1.0529 ; 
if (pt >= 42 && pt < 43) return 1.04719 ; 
if (pt >= 43 && pt < 44) return 1.04137 ; 
if (pt >= 44 && pt < 45) return 1.03546 ; 
if (pt >= 45 && pt < 46) return 1.02947 ; 
if (pt >= 46 && pt < 47) return 1.02344 ; 
if (pt >= 47 && pt < 48) return 1.01737 ; 
if (pt >= 48 && pt < 49) return 1.01128 ; 
if (pt >= 49 && pt < 50) return 1.00519 ; 
if (pt >= 50 && pt < 51) return 0.999092 ; 
if (pt >= 51 && pt < 52) return 0.993005 ; 
if (pt >= 52 && pt < 53) return 0.986933 ; 
if (pt >= 53 && pt < 54) return 0.980882 ; 
if (pt >= 54 && pt < 55) return 0.974854 ; 
if (pt >= 55 && pt < 56) return 0.968853 ; 
if (pt >= 56 && pt < 57) return 0.962881 ; 
if (pt >= 57 && pt < 58) return 0.956938 ; 
if (pt >= 58 && pt < 59) return 0.951027 ; 
if (pt >= 59 && pt < 60) return 0.945148 ; 
if (pt >= 60 && pt < 61) return 0.939302 ; 
if (pt >= 61 && pt < 62) return 0.933489 ; 
if (pt >= 62 && pt < 63) return 0.927708 ; 
if (pt >= 63 && pt < 64) return 0.921959 ; 
if (pt >= 64 && pt < 65) return 0.91624 ; 
if (pt >= 65 && pt < 66) return 0.910552 ; 
if (pt >= 66 && pt < 67) return 0.904893 ; 
if (pt >= 67 && pt < 68) return 0.899263 ; 
if (pt >= 68 && pt < 69) return 0.893659 ; 
if (pt >= 69 && pt < 70) return 0.888082 ; 
if (pt >= 70 && pt < 71) return 0.88253 ; 
if (pt >= 71 && pt < 72) return 0.877003 ; 
if (pt >= 72 && pt < 73) return 0.8715 ; 
if (pt >= 73 && pt < 74) return 0.866019 ; 
if (pt >= 74 && pt < 75) return 0.86056 ; 
if (pt >= 75 && pt < 76) return 0.855122 ; 
if (pt >= 76 && pt < 77) return 0.849703 ; 
if (pt >= 77 && pt < 78) return 0.844303 ; 
if (pt >= 78 && pt < 79) return 0.83892 ; 
if (pt >= 79 && pt < 80) return 0.833555 ; 
if (pt >= 80 && pt < 81) return 0.828207 ; 
if (pt >= 81 && pt < 82) return 0.822874 ; 
if (pt >= 82 && pt < 83) return 0.817557 ; 
if (pt >= 83 && pt < 84) return 0.812254 ; 
if (pt >= 84 && pt < 85) return 0.806965 ; 
if (pt >= 85 && pt < 86) return 0.801689 ; 
if (pt >= 86 && pt < 87) return 0.796425 ; 
if (pt >= 87 && pt < 88) return 0.791184 ; 
if (pt >= 88 && pt < 89) return 0.785934 ; 
if (pt >= 89 && pt < 90) return 0.780705 ; 
if (pt >= 90 && pt < 91) return 0.775488 ; 
if (pt >= 91 && pt < 92) return 0.770281 ; 
if (pt >= 92 && pt < 93) return 0.765084 ; 
if (pt >= 93 && pt < 94) return 0.759897 ; 
if (pt >= 94 && pt < 95) return 0.754722 ; 
if (pt >= 95 && pt < 96) return 0.749554 ; 
if (pt >= 96 && pt < 97) return 0.744393 ; 
if (pt >= 97 && pt < 98) return 0.739242 ; 
if (pt >= 98 && pt < 99) return 0.734109 ; 
if (pt >= 99 && pt < 100) return 0.728965 ; 
if (pt >= 100 && pt < 101) return 0.723837 ; 
if (pt >= 101 && pt < 102) return 0.718717 ; 
if (pt >= 102 && pt < 103) return 0.713603 ; 
if (pt >= 103 && pt < 104) return 0.708498 ; 
if (pt >= 104 && pt < 105) return 0.703401 ; 
if (pt >= 105 && pt < 106) return 0.698311 ; 
if (pt >= 106 && pt < 107) return 0.69323 ; 
if (pt >= 107 && pt < 108) return 0.688154 ; 
if (pt >= 108 && pt < 109) return 0.683086 ; 
if (pt >= 109 && pt < 110) return 0.678025 ; 
if (pt >= 110 && pt < 111) return 0.67297 ; 
if (pt >= 111 && pt < 112) return 0.667921 ; 
if (pt >= 112 && pt < 113) return 0.662878 ; 
if (pt >= 113 && pt < 114) return 0.657843 ; 
if (pt >= 114 && pt < 115) return 0.652814 ; 
if (pt >= 115 && pt < 116) return 0.647791 ; 
if (pt >= 116 && pt < 117) return 0.642774 ; 
if (pt >= 117 && pt < 118) return 0.637765 ; 
if (pt >= 118 && pt < 119) return 0.632762 ; 
if (pt >= 119 && pt < 120) return 0.627765 ; 
if (pt >= 120 && pt < 121) return 0.622775 ; 
if (pt >= 121 && pt < 122) return 0.617792 ; 
if (pt >= 122 && pt < 123) return 0.614795 ; 
if (pt >= 123 && pt < 124) return 0.614058 ; 
if (pt >= 124 && pt < 125) return 0.613378 ; 
if (pt >= 125 && pt < 126) return 0.612702 ; 
if (pt >= 126 && pt < 127) return 0.612019 ; 
if (pt >= 127 && pt < 128) return 0.611431 ; 
if (pt >= 128 && pt < 129) return 0.610763 ; 
if (pt >= 129 && pt < 130) return 0.610107 ; 
if (pt >= 130 && pt < 131) return 0.609465 ; 
if (pt >= 131 && pt < 132) return 0.608829 ; 
if (pt >= 132 && pt < 133) return 0.608201 ; 
if (pt >= 133 && pt < 134) return 0.607578 ; 
if (pt >= 134 && pt < 135) return 0.606963 ; 
if (pt >= 135 && pt < 136) return 0.606354 ; 
if (pt >= 136 && pt < 137) return 0.605746 ; 
if (pt >= 137 && pt < 138) return 0.605145 ; 
if (pt >= 138 && pt < 139) return 0.604549 ; 
if (pt >= 139 && pt < 140) return 0.603959 ; 
if (pt >= 140 && pt < 141) return 0.603374 ; 
if (pt >= 141 && pt < 142) return 0.602796 ; 
if (pt >= 142 && pt < 143) return 0.602223 ; 
if (pt >= 143 && pt < 144) return 0.60165 ; 
if (pt >= 144 && pt < 145) return 0.601085 ; 
if (pt >= 145 && pt < 146) return 0.600525 ; 
if (pt >= 146 && pt < 147) return 0.599971 ; 
if (pt >= 147 && pt < 148) return 0.599422 ; 
if (pt >= 148 && pt < 149) return 0.598878 ; 
if (pt >= 149 && pt < 150) return 0.598338 ; 
if (pt >= 150 && pt < 151) return 0.597804 ; 
if (pt >= 151 && pt < 152) return 0.597274 ; 
if (pt >= 152 && pt < 153) return 0.59675 ; 
if (pt >= 153 && pt < 154) return 0.59623 ; 
if (pt >= 154 && pt < 155) return 0.595716 ; 
if (pt >= 155 && pt < 156) return 0.595207 ; 
if (pt >= 156 && pt < 157) return 0.594702 ; 
if (pt >= 157 && pt < 158) return 0.594203 ; 
if (pt >= 158 && pt < 159) return 0.593709 ; 
if (pt >= 159 && pt < 160) return 0.593219 ; 
if (pt >= 160 && pt < 161) return 0.592735 ; 
if (pt >= 161 && pt < 162) return 0.592255 ; 
if (pt >= 162 && pt < 163) return 0.591781 ; 
if (pt >= 163 && pt < 164) return 0.591312 ; 
if (pt >= 164 && pt < 165) return 0.590847 ; 
if (pt >= 165 && pt < 166) return 0.590388 ; 
if (pt >= 166 && pt < 167) return 0.589934 ; 
if (pt >= 167 && pt < 168) return 0.589485 ; 
if (pt >= 168 && pt < 169) return 0.589041 ; 
if (pt >= 169 && pt < 170) return 0.588602 ; 
if (pt >= 170 && pt < 171) return 0.588168 ; 
if (pt >= 171 && pt < 172) return 0.587739 ; 
if (pt >= 172 && pt < 173) return 0.587315 ; 
if (pt >= 173 && pt < 174) return 0.586897 ; 
if (pt >= 174 && pt < 175) return 0.586483 ; 
if (pt >= 175 && pt < 176) return 0.586075 ; 
if (pt >= 176 && pt < 177) return 0.585672 ; 
if (pt >= 177 && pt < 178) return 0.585274 ; 
if (pt >= 178 && pt < 179) return 0.584881 ; 
if (pt >= 179 && pt < 180) return 0.584493 ; 
if (pt >= 180 && pt < 181) return 0.584111 ; 
if (pt >= 181 && pt < 182) return 0.583733 ; 
if (pt >= 182 && pt < 183) return 0.583361 ; 
if (pt >= 183 && pt < 184) return 0.582994 ; 
if (pt >= 184 && pt < 185) return 0.582632 ; 
if (pt >= 185 && pt < 186) return 0.582275 ; 
if (pt >= 186 && pt < 187) return 0.581923 ; 
if (pt >= 187 && pt < 188) return 0.581577 ; 
if (pt >= 188 && pt < 189) return 0.581235 ; 
if (pt >= 189 && pt < 190) return 0.580899 ; 
if (pt >= 190 && pt < 191) return 0.580567 ; 
if (pt >= 191 && pt < 192) return 0.580241 ; 
if (pt >= 192 && pt < 193) return 0.57992 ; 
if (pt >= 193 && pt < 194) return 0.579603 ; 
if (pt >= 194 && pt < 195) return 0.579292 ; 
if (pt >= 195 && pt < 196) return 0.578986 ; 
if (pt >= 196 && pt < 197) return 0.578684 ; 
if (pt >= 197 && pt < 198) return 0.578387 ; 
if (pt >= 198 && pt < 199) return 0.578096 ; 
if (pt >= 199 && pt < 200) return 0.577809 ; 
if (pt >= 200 && pt < 201) return 0.577527 ; 
if (pt >= 201 && pt < 202) return 0.577249 ; 
if (pt >= 202 && pt < 203) return 0.576976 ; 
if (pt >= 203 && pt < 204) return 0.576708 ; 
if (pt >= 204 && pt < 205) return 0.576445 ; 
if (pt >= 205 && pt < 206) return 0.576186 ; 
if (pt >= 206 && pt < 207) return 0.575932 ; 
if (pt >= 207 && pt < 208) return 0.575682 ; 
if (pt >= 208 && pt < 209) return 0.575436 ; 
if (pt >= 209 && pt < 210) return 0.575196 ; 
if (pt >= 210 && pt < 211) return 0.57496 ; 
if (pt >= 211 && pt < 212) return 0.574731 ; 
if (pt >= 212 && pt < 213) return 0.574503 ; 
if (pt >= 213 && pt < 214) return 0.574278 ; 
if (pt >= 214 && pt < 215) return 0.574057 ; 
if (pt >= 215 && pt < 216) return 0.573841 ; 
if (pt >= 216 && pt < 217) return 0.57363 ; 
if (pt >= 217 && pt < 218) return 0.573421 ; 
if (pt >= 218 && pt < 219) return 0.573217 ; 
if (pt >= 219 && pt < 220) return 0.573016 ; 
if (pt >= 220 && pt < 221) return 0.572819 ; 
if (pt >= 221 && pt < 222) return 0.572626 ; 
if (pt >= 222 && pt < 223) return 0.572436 ; 
if (pt >= 223 && pt < 224) return 0.572249 ; 
if (pt >= 224 && pt < 225) return 0.572065 ; 
if (pt >= 225 && pt < 226) return 0.571884 ; 
if (pt >= 226 && pt < 227) return 0.571706 ; 
if (pt >= 227 && pt < 228) return 0.571531 ; 
if (pt >= 228 && pt < 229) return 0.571359 ; 
if (pt >= 229 && pt < 230) return 0.57119 ; 
if (pt >= 230 && pt < 231) return 0.571022 ; 
if (pt >= 231 && pt < 232) return 0.570858 ; 
if (pt >= 232 && pt < 233) return 0.570695 ; 
if (pt >= 233 && pt < 234) return 0.570535 ; 
if (pt >= 234 && pt < 235) return 0.570376 ; 
if (pt >= 235 && pt < 236) return 0.570219 ; 
if (pt >= 236 && pt < 237) return 0.570064 ; 
if (pt >= 237 && pt < 238) return 0.569911 ; 
if (pt >= 238 && pt < 239) return 0.569759 ; 
if (pt >= 239 && pt < 240) return 0.569608 ; 
if (pt >= 240 && pt < 241) return 0.569458 ; 
if (pt >= 241 && pt < 242) return 0.569309 ; 
if (pt >= 242 && pt < 243) return 0.569161 ; 
if (pt >= 243 && pt < 244) return 0.569013 ; 
if (pt >= 244 && pt < 245) return 0.568866 ; 
if (pt >= 245 && pt < 246) return 0.56872 ; 
if (pt >= 246 && pt < 247) return 0.568574 ; 
if (pt >= 247 && pt < 248) return 0.568426 ; 
if (pt >= 248 && pt < 249) return 0.568276 ; 
if (pt >= 249 && pt < 250) return 0.568126 ; 
if (pt >= 249 && pt < 250) return 0.568126 ; 
return 0.568126 ; 
} 
