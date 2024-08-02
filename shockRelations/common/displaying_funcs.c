#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI_F 3.14159265
#include "displaying_funcs.h"


void display_inputs(float *pGamma1, float *pBeta1, float *pMach1)
{
    printf("Given inputs are: \n");
    printf("Specific heat ratio is: %f\n", *pGamma1);
    printf("Wave angle is: %f degrees\n", (*pBeta1)/PI_F*180);
    printf("Mach number is: %f\n", *pMach1);
    
}
void display_outputs(float p_ratio, float rho_ratio, float T_ratio, float U_ratio_prl, float U_ratio_perp, float exact_cp_val, float exact_theta_val, float total_p_ratio, float Mach2)
{
    printf("Resulting values are: \n");
    printf("Exact static pressure ratio is: %f\n", p_ratio);
    printf("Exact density ratio is: %f\n", rho_ratio);
    printf("Exact temperature ratio is: %f\n", T_ratio);
    printf("Exact parallel velocity ratio is: %f\n", U_ratio_prl);
    printf("Exact perpendicular velocity ratio is: %f\n", U_ratio_perp);
    printf("Exact pressure coefficient is: %f\n", exact_cp_val);
    printf("Exact deflection angle is: %f\n", exact_theta_val);
    printf("Exact total pressure ratio is: %f\n", total_p_ratio);
    printf("Exact downstream Mach number is: %f\n", Mach2);
    
}