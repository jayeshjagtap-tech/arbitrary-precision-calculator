/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

static void multiply_digit(Dlist *head, Dlist **h, Dlist **t, int d)
{
    free_list(h, t);

    if (d == 0)
    {
        insert_at_end(h, t, 0);
        return;
    }

    Dlist *tail = head;
    while (tail->next) tail = tail->next;

    int carry = 0;
    for (Dlist *p = tail; p; p = p->prev)
    {
        int prod = p->data * d + carry;
        insert_at_front(h, t, prod % 10);
        carry = prod / 10;
    }

    while (carry)
    {
        insert_at_front(h, t, carry % 10);
        carry /= 10;
    }
}

/* magnitude division */
int division(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2,
             Dlist **hR, Dlist **tR)
{
    (void)t1; (void)t2;
    free_list(hR, tR);

    if ((*h2)->data == 0 && (*h2)->next == NULL)
        return FAILURE;

    if (compare_numbers(*h1, *h2) < 0)
    {
        insert_at_end(hR, tR, 0);
        return SUCCESS;
    }

    Dlist *curH = NULL, *curT = NULL;

    for (Dlist *p = *h1; p; p = p->next)
    {
        insert_at_end(&curH, &curT, p->data);
        strip_leading_zeros(&curH, &curT);

        int low = 0, high = 9, best = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            Dlist *ph = NULL, *pt = NULL;
            multiply_digit(*h2, &ph, &pt, mid);
            int cmp = compare_numbers(curH, ph);

            free_list(&ph, &pt);

            if (cmp >= 0) { best = mid; low = mid + 1; }
            else high = mid - 1;
        }

        insert_at_end(hR, tR, best);

        if (best != 0)
        {
            Dlist *ph = NULL, *pt = NULL;
            multiply_digit(*h2, &ph, &pt, best);

            Dlist *tmpH = NULL, *tmpT = NULL;
            Dlist *x = curT, *y = pt;
            int borrow = 0;

            while (x)
            {
                int a = x->data - borrow;
                int b = y ? y->data : 0;

                if (a < b)
                {
                    a += 10;
                    borrow = 1;
                }
                else borrow = 0;

                insert_at_front(&tmpH, &tmpT, a - b);

                x = x->prev;
                if (y) y = y->prev;
            }

            free_list(&curH, &curT);
            curH = tmpH;
            curT = tmpT;

            free_list(&ph, &pt);
        }
    }

    strip_leading_zeros(hR, tR);
    free_list(&curH, &curT);

    return SUCCESS;
}

