/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

/* magnitude multiplication */
int multiplication(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2,
                   Dlist **hR, Dlist **tR)
{
    (void)t1; (void)t2;
    free_list(hR, tR);

    int n1 = 0, n2 = 0;

    for (Dlist *p = *h1; p; p = p->next) n1++;
    for (Dlist *q = *h2; q; q = q->next) n2++;

    int *res = calloc(n1 + n2, sizeof(int));

    int i = 0;
    for (Dlist *p = *t1; p; p = p->prev, i++)
    {
        int j = 0;
        for (Dlist *q = *t2; q; q = q->prev, j++)
            res[i + j] += p->data * q->data;
    }

    for (int k = 0; k < n1 + n2; k++)
    {
        if (res[k] >= 10)
        {
            res[k + 1] += res[k] / 10;
            res[k] %= 10;
        }
    }

    int top = n1 + n2 - 1;
    while (top > 0 && res[top] == 0) top--;

    for (int k = top; k >= 0; k--)
        insert_at_end(hR, tR, res[k]);

    free(res);
    return SUCCESS;
}

