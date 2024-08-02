#include "exact_functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



float exact_s_pressure(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin)
{
    float p_ratio = 0;

    p_ratio = 1 + (2*(*pGamma1)*(const_M_sin - 1))/((*pGamma1) + 1);

    return p_ratio;
}

float exact_density(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin)
{
    float rho_ratio = 0;

    rho_ratio = (((*pGamma1) + 1)*const_M_sin)/(((*pGamma1) - 1)*const_M_sin + 2);

    return rho_ratio;
}

float exact_temp(float p_ratio, float rho_ratio)
{
    float T_ratio = 0;

    T_ratio = p_ratio / rho_ratio;

    return T_ratio;
}

float vel_ratio_prl(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin)
{
    float U_ratio_prl= 0;

    U_ratio_prl = 1 - (2*const_M_sin - 1)/((*pGamma1 + 1)*pow(*pMach1,2));

    return U_ratio_prl;
}

float vel_ratio_perp(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin)
{
    float U_ratio_perp= 0;

    U_ratio_perp = ((2*const_M_sin - 1)*cos(*pBeta1))/((*pGamma1 + 1)*pow(*pMach1,2));

    return U_ratio_perp;
}

float exact_cp(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin)
{
    float exact_cp_val = 0;

    exact_cp_val = (4/(*pGamma1 + 1))*(pow(sin(*pBeta1),2) - 1/(pow(*pMach1,2)));

    return exact_cp_val;
}

float exact_theta(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin)
{
    float exact_tan_theta_val = 0;
    float exact_theta_val = 0;

    exact_tan_theta_val = 2*(1/tan(*pBeta1))*((const_M_sin - 1)/((pow(*pMach1,2)*(*pGamma1 + cos(2*(*pBeta1))))+2));
    exact_theta_val = atan(exact_tan_theta_val);

    return exact_theta_val;
}

float exact_t_pressure(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin)
{
    float total_p_ratio = 0;

    total_p_ratio = pow((((*pGamma1 + 1)*const_M_sin)/((*pGamma1 - 1)*const_M_sin + 2)),(*pGamma1/(*pGamma1 - 1))) * pow((*pGamma1 + 1)/(2*(*pGamma1)*const_M_sin - (*pGamma1 - 1)),(1/(*pGamma1 - 1)));

    return total_p_ratio;
}

float mach_after(float *pGamma1, float *pBeta1, float *pMach1, float const_M_sin, float *pExactTheta)
{
    float Mach2 = 0;
    
    Mach2 = 1/sin(*pBeta1 - *pExactTheta) * sqrt(((*pGamma1 - 1) * const_M_sin + 2)/(2*(*pGamma1)*const_M_sin-(*pGamma1 - 1)));

    return Mach2;
}