/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/

#include "apc.h"

int main()
{
    Dlist *h1 = NULL, *t1 = NULL;
    Dlist *h2 = NULL, *t2 = NULL;
    Dlist *hR = NULL, *tR = NULL;

    char num1[8192], num2[8192], opr, option;
    int sign1, sign2, signR;

    do
    {
        /* Read inputs */
        printf("Enter first number  : ");
        scanf("%s", num1);

        printf("Enter operator (+ - * / %%): ");
        scanf(" %c", &opr);

        printf("Enter second number : ");
        scanf("%s", num2);

        /* Convert to DLL with sign */
        read_number_with_sign(&h1, &t1, num1, &sign1);
        read_number_with_sign(&h2, &t2, num2, &sign2);

        switch (opr)
        {
            case '+':
                if (sign1 == sign2)
                {
                    addition(&h1, &t1, &h2, &t2, &hR, &tR);
                    signR = sign1;
                }
                else
                {
                    int cmp = compare_numbers(h1, h2);
                    if (cmp == 0)
                    {
                        insert_at_end(&hR, &tR, 0);
                        signR = 1;
                    }
                    else if (cmp > 0)
                    {
                        subtraction(&h1, &t1, &h2, &t2, &hR, &tR);
                        signR = sign1;
                    }
                    else
                    {
                        subtraction(&h2, &t2, &h1, &t1, &hR, &tR);
                        signR = sign2;
                    }
                }
                break;

            case '-':
                sign2 = -sign2;
                if (sign1 == sign2)
                {
                    addition(&h1, &t1, &h2, &t2, &hR, &tR);
                    signR = sign1;
                }
                else
                {
                    int cmp = compare_numbers(h1, h2);
                    if (cmp == 0)
                    {
                        insert_at_end(&hR, &tR, 0);
                        signR = 1;
                    }
                    else if (cmp > 0)
                    {
                        subtraction(&h1, &t1, &h2, &t2, &hR, &tR);
                        signR = sign1;
                    }
                    else
                    {
                        subtraction(&h2, &t2, &h1, &t1, &hR, &tR);
                        signR = sign2;
                    }
                }
                break;

            case '*':
                multiplication(&h1, &t1, &h2, &t2, &hR, &tR);
                signR = sign1 * sign2;
                break;

            case '/':
                if (h2->data == 0 && h2->next == NULL)
                {
                    printf("Result: DivisionByZeroError\n");
                    break;
                }

                if (compare_numbers(h1, h2) < 0)
                {
                    printf("Result: 0\n");
                    break;
                }

                division(&h1, &t1, &h2, &t2, &hR, &tR);
                signR = sign1 * sign2;
                break;

            case '%':
                if (h2->data == 0 && h2->next == NULL)
                {
                    printf("Result: DivisionByZeroError\n");
                    break;
                }

                modulus(&h1, &t1, &h2, &t2, &hR, &tR);
                signR = sign1;
                break;

            default:
                printf("Invalid operator!\n");
                break;
        }

        /* Print result (fixed: prints 0 correctly) */
        if (hR != NULL)
        {
            printf("Result: ");

            /* print '-' only if result is non-zero */
            if (signR == -1 && !(hR->data == 0 && hR->next == NULL))
                printf("-");

            print_list(hR);
            printf("\n");
        }

        /* Free memory */
        free_list(&h1, &t1);
        free_list(&h2, &t2);
        free_list(&hR, &tR);

        printf("Want to continue? (y/n): ");
        scanf(" %c", &option);

    } while (option == 'y' || option == 'Y');

    return 0;
}
