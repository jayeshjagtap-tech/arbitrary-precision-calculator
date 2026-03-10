/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

/* magnitude addition */
int addition(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2,
             Dlist **hR, Dlist **tR)
{
    /* Silence unused parameter warnings */
    (void)h1;
    (void)h2;

    free_list(hR, tR);

    int carry = 0;
    Dlist *p = *t1, *q = *t2;

    while (p || q || carry)
    {
        int a = p ? p->data : 0;
        int b = q ? q->data : 0;
        int sum = a + b + carry;

        insert_at_front(hR, tR, sum % 10);
        carry = sum / 10;

        if (p) p = p->prev;
        if (q) q = q->prev;
    }

    return SUCCESS;
}
