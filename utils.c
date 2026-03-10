#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Create a new node */
Dlist *create_node(int data)
{
    Dlist *n = malloc(sizeof(Dlist));
    if (!n) return NULL;
    n->prev = n->next = NULL;
    n->data = data;
    return n;
}

/* Insert at end */
int insert_at_end(Dlist **head, Dlist **tail, int data)
{
    Dlist *n = create_node(data);
    if (!n) return FAILURE;

    if (*head == NULL)
        *head = *tail = n;
    else {
        (*tail)->next = n;
        n->prev = *tail;
        *tail = n;
    }
    return SUCCESS;
}

/* Insert at front */
int insert_at_front(Dlist **head, Dlist **tail, int data)
{
    Dlist *n = create_node(data);
    if (!n) return FAILURE;

    if (*head == NULL)
        *head = *tail = n;
    else {
        n->next = *head;
        (*head)->prev = n;
        *head = n;
    }
    return SUCCESS;
}

/* Free list */
void free_list(Dlist **head, Dlist **tail)
{
    Dlist *p = *head;
    while (p) {
        Dlist *next = p->next;
        free(p);
        p = next;
    }
    *head = *tail = NULL;
}

/* Read signed number */
int read_number_with_sign(Dlist **head, Dlist **tail, const char *str, int *sign)
{
    free_list(head, tail);
    *sign = 1;

    while (*str == ' ') str++;

    if (*str == '-') { *sign = -1; str++; }
    else if (*str == '+') str++;

    while (*str == ' ') str++;
    while (*str == '0') str++;

    if (!isdigit(*str))
    {
        insert_at_end(head, tail, 0);
        *sign = 1;
        return SUCCESS;
    }

    while (*str && isdigit(*str))
        insert_at_end(head, tail, *str++ - '0');

    return SUCCESS;
}

/* Print digits */
void print_list(Dlist *head)
{
    while (head) {
        printf("%d", head->data);
        head = head->next;
    }
}

/* Remove leading zeros */
void strip_leading_zeros(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && (*head)->next) {
        Dlist *tmp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(tmp);
    }

    if (!*head) {
        insert_at_end(head, tail, 0);
        return;
    }

    Dlist *p = *head;
    while (p->next) p = p->next;
    *tail = p;
}

/* Compare magnitudes */
int compare_numbers(Dlist *h1, Dlist *h2)
{
    int l1 = 0, l2 = 0;
    Dlist *p = h1, *q = h2;

    while (p) { l1++; p = p->next; }
    while (q) { l2++; q = q->next; }

    if (l1 > l2) return 1;
    if (l1 < l2) return -1;

    while (h1 && h2) {
        if (h1->data > h2->data) return 1;
        if (h1->data < h2->data) return -1;
        h1 = h1->next;
        h2 = h2->next;
    }

    return 0;
}
