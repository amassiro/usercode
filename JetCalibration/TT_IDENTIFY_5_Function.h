

double eval_DR_bb(double DR_bb){
 double result_up = (-3.82573e-03) + (1.41472e-02) * DR_bb + (-1.71696e-02) * DR_bb * DR_bb + (9.64878e-03) * DR_bb * DR_bb * DR_bb + (-2.43159e-03) * DR_bb * DR_bb * DR_bb * DR_bb + (2.21839e-04) * DR_bb * DR_bb * DR_bb * DR_bb * DR_bb;
 double result_down = (-4.26288e-03) + (1.40067e-02) * DR_bb + (-1.39796e-02) * DR_bb * DR_bb + (6.65092e-03) * DR_bb * DR_bb * DR_bb + (-1.49731e-03) * DR_bb * DR_bb * DR_bb * DR_bb + (1.26794e-04) * DR_bb * DR_bb * DR_bb * DR_bb * DR_bb;
 double result;
 if (result_down != 0) result = fabs(result_up / result_down);
 if (DR_bb >4) result = 0;
 if (DR_bb < 0.5) result = 0;
 return result;
}

double eval_DR_qq(double DR_qq){
 double result_up = (-3.32662e-03) + (8.55567e-03) * DR_qq + (-3.75460e-03) * DR_qq * DR_qq + (-1.59952e-05) * DR_qq * DR_qq * DR_qq + (2.55905e-04) * DR_qq * DR_qq * DR_qq * DR_qq + (-3.45180e-05) * DR_qq * DR_qq * DR_qq * DR_qq * DR_qq;
 double result_down = (-3.59175e-03) + (1.37385e-02) * DR_qq + (-1.72147e-02) * DR_qq * DR_qq + (9.77301e-03) * DR_qq * DR_qq * DR_qq + (-2.45796e-03) * DR_qq * DR_qq * DR_qq * DR_qq + (2.22835e-04) * DR_qq * DR_qq * DR_qq * DR_qq * DR_qq;
 double result;
 if (result_down != 0) result = fabs(result_up / result_down);
 if (DR_qq >4) result = 0;
 if (DR_qq < 0.5) result = 0;
 return result;
}


double eval_q_trackCountingHighEffBJetTags(double x){ 
 double result_up = (-0.170644) * exp((-1.18821) * x) + (0.0156448) * exp(-0.5*((x-(0.956014))/(0.61802))*((x-(0.956014))/(0.61802))) + (0.165707) * exp((-1.13331) * x) + (9.34581e-05);
 double result_down = (0.49763) * exp((-1.30413) * x) + (0.00106353) * exp(-0.5*((x-(4.37409))/(-7.66343))*((x-(4.37409))/(-7.66343))) + (-0.502457) * exp((-1.35164) * x) + (0.000146039); //---- FIXME may be optimized!  
 double result;
 if (result_down != 0) result = fabs(result_up / result_down);
 if (x >40) result = 0;
 return result;
}


double eval_b_trackCountingHighEffBJetTags(double x){ 
 double result_up = (0.00404993) * exp((-0.123128) * x) + (-3256.96) * exp(-0.5*((x-(0.989383))/(0.000301955))*((x-(0.989383))/(0.000301955))) + (-0.00443926) * exp((-2.12971) * x) + (4.94723e-05); //---- FIXME may be optimized!  
 double result_down = (0.49516) * exp((-1.29324) * x) + (-0.00296982) * exp(-0.5*((x-(2.52131))/(0.949705))*((x-(2.52131))/(0.949705))) + (-0.504652) * exp((-1.43253) * x) + (7.77085e-05); //---- FIXME may be optimized!  
 double result;
 if (result_down != 0) result = fabs(result_up / result_down);
 if (x >40) result = 0;
 return result;
}




double eval_b_pT(double x){ 
 double result_up = (0.0122425) * exp((-0.0343777) * x) + (-0.0130454) * exp((-0.0876625) * x );
 double result_down = (0.0113235) * exp((-0.0327694) * x) + (-0.0247253) * exp((-0.11953) * x ); 
 double result;
 if (result_down != 0) result = fabs(result_up / result_down);
 if (x >200) result = 0;
 if (x < 10) result = 0; 
 return result;
}

double eval_q_pT(double x){ 
 double result_up = (0.0123922) * exp((-0.0401886) * x) + (-0.013578) * exp((-0.166507) * x );
 double result_down = (0.934062) * exp((-0.0433747) * x) + (-0.938336) * exp((-0.0439213) * x );
 double result;
 if (result_down != 0) result = fabs(result_up / result_down);
 if (x >200) result = 0;
 if (x < 10) result = 0; 
 return result;
}

