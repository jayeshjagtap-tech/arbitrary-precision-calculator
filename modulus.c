/*****************************************************************************************
 * Title       : Modulus
 * Description : Computes A % B for two big integers using DLL representation.
 * Formula     : A % B = A − (A/B) * B
 *****************************************************************************************/

#include "apc.h"

/* modulus = A - (A/B)*B */
int modulus(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2,
            Dlist **hR, Dlist **tR)
{
    /* Remainder has same sign as numerator */
    (void)t1; (void)t2;

    /* Step 1: Compute quotient Q = A / B */
    Dlist *qH = NULL, *qT = NULL;
    if (division(h1, t1, h2, t2, &qH, &qT) == FAILURE)
        return FAILURE;

    /* Step 2: Compute product P = Q * B */
    Dlist *pH = NULL, *pT = NULL;
    multiplication(&qH, &qT, h2, t2, &pH, &pT);

    /* Step 3: R = A - P */
    subtraction(h1, t1, &pH, &pT, hR, tR);

    /* Cleanup temp lists */
    free_list(&qH, &qT);
    free_list(&pH, &pT);

    strip_leading_zeros(hR, tR);
    return SUCCESS;
}
