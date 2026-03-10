/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

/* |A| - |B| */
int subtraction(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2,
                Dlist **hR, Dlist **tR)
{
    (void)h1; (void)h2; (void)t1; (void)t2;
    free_list(hR, tR);

    Dlist *p = *t1, *q = *t2;
    int borrow = 0;

    while (p)
    {
        int a = p->data - borrow;
        int b = q ? q->data : 0;

        if (a < b) {
            a += 10;
            borrow = 1;
        }
        else borrow = 0;

        insert_at_front(hR, tR, a - b);

        p = p->prev;
        if (q) q = q->prev;
    }

    strip_leading_zeros(hR, tR);
    return SUCCESS;
}

