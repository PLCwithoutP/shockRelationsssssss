#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
// Include Guards

float exact_s_pressure(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin); // Static
float exact_t_pressure(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin); // Total
float exact_density(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin);
float exact_temp(float p_ratio,float rho_ratio);
float vel_ratio_prl(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin);
float vel_ratio_perp(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin);
float mach_after(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin, float *pExactTheta);
float exact_cp(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin);
float exact_theta(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin);


#endif