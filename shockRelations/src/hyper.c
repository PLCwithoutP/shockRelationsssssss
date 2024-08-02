#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI_F 3.14159265
#include "../oblique/exact_functions.h"
#include "../common/displaying_funcs.h"

int main(void)
{
    // Definitions and memory allocation
    float *pGamma1 = NULL;
    float *pBeta1 = NULL;
    float *pMach1 = NULL;
    float *pExact_theta_val = NULL;

    // Calculation mode definitions
    struct modes {
        char calc_key[3];
        char isen_key[3]; // Isentropic flow
        char norm_key[3]; // Normal shock
        char obl_key[3]; // Oblique shock
    };
    struct modes selection = {" ", "Is", "Ns", "Os"};
    
    float p_ratio = 0;
    float rho_ratio = 0;
    float T_ratio = 0;
    float U_ratio_prl = 0;
    float U_ratio_perp = 0;
    float exact_cp_val = 0;
    float exact_theta_val = 0;
    float const_M_sin = 0;
    float total_p_ratio = 0;
    float Mach2 = 0;

    float gamma1 = 0;
    float beta1 = 0;
    float Mach1 = 0;
    
    int selection_check = 1;
    // Memory allocation and check
    pGamma1 = (float*) malloc(sizeof(float));
    pBeta1 = (float*) malloc(sizeof(float));
    pMach1 = (float*) malloc(sizeof(float));
    pExact_theta_val = (float*) malloc(sizeof(float));

    if (pGamma1 == NULL || pBeta1 == NULL || pMach1 == NULL || pExact_theta_val == NULL)
    {
        printf("Memory allocation could not be done, program is exiting.");
        return -1;
    }
    
    // Taking values
    printf("Which calculation do you want to do?\n");
    printf("Enter two characters code for the mode selection.\n");
    printf("Is: isentropic flow\n");
    printf("Ns: normal shock\n");
    printf("Os: oblique shock\n");
    scanf("%s", selection.calc_key);
    while (selection_check == 1) {
    if (strcmp(selection.calc_key,selection.isen_key) == 0)
    {
        printf("Selected: isentropic\n");
        selection_check = 2;
    }
    else if (strcmp(selection.calc_key,selection.norm_key) == 0)
    {
        printf("Selected: normal shock\n");
        selection_check = 3;
    }
    else if (strcmp(selection.calc_key,selection.obl_key) == 0)
    {
        printf("Selected: oblique shock\n");
        selection_check = 4;
    }
    else
    {
        printf("Selection is %s\n", selection.calc_key);
        printf("Wrong selection, try again.\n");
        scanf("%s", selection.calc_key);
    }
    }
    
    printf("Please enter specific heat ratio: \n");
    scanf("%f", &gamma1);
    *pGamma1 = gamma1;
    printf("Please enter wave angle in degrees: \n");
    scanf("%f", &beta1);
    while (beta1 == 0 || beta1 == 90 || beta1 == 180 || beta1 == 270 || beta1 == 360)
    {
        printf("These values cannot be accepted, please enter acceptable values.\n");
        printf("Please enter wave angle in degrees: \n");
        scanf("%f", &beta1);
    }
    *pBeta1 = beta1*PI_F/180;
    printf("Please enter Mach number: \n");
    scanf("%f", &Mach1);
    *pMach1 = Mach1;

    const_M_sin = pow((*pMach1)*sin(*pBeta1),2);

    // Function executions
    p_ratio = exact_s_pressure(pGamma1, pBeta1, pMach1, const_M_sin); // Static
    total_p_ratio = exact_t_pressure(pGamma1, pBeta1, pMach1, const_M_sin); // Total
    rho_ratio = exact_density(pGamma1, pBeta1, pMach1, const_M_sin);
    T_ratio = exact_temp(p_ratio, rho_ratio);
    U_ratio_prl = vel_ratio_prl(pGamma1, pBeta1, pMach1, const_M_sin);
    U_ratio_perp = vel_ratio_perp(pGamma1, pBeta1, pMach1, const_M_sin);
    exact_cp_val = exact_cp(pGamma1, pBeta1, pMach1, const_M_sin);
    *pExact_theta_val = exact_theta(pGamma1, pBeta1, pMach1, const_M_sin); // Deflection Angle
    Mach2 = mach_after(pGamma1, pBeta1, pMach1, const_M_sin, pExact_theta_val); 

    exact_theta_val = (*pExact_theta_val)*180/PI_F;

    // Display
    display_inputs(pGamma1, pBeta1, pMach1);
    display_outputs(p_ratio, rho_ratio, T_ratio, U_ratio_prl, U_ratio_perp, exact_cp_val, exact_theta_val, total_p_ratio, Mach2);


    // Freeing memory
    free(pGamma1);
    pGamma1 = NULL;
    free(pBeta1);
    pBeta1 = NULL;
    free(pMach1);
    pMach1 = NULL;
    free(pExact_theta_val);
    pExact_theta_val = NULL;

    return 0;
}