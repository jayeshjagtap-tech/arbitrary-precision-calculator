#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dlist;

/* Utility */
Dlist *create_node(int data);
int insert_at_end(Dlist **head, Dlist **tail, int data);
int insert_at_front(Dlist **head, Dlist **tail, int data);
void free_list(Dlist **head, Dlist **tail);
int read_number_with_sign(Dlist **head, Dlist **tail, const char *str, int *sign);
void print_list(Dlist *head);
void strip_leading_zeros(Dlist **head, Dlist **tail);
int compare_numbers(Dlist *h1, Dlist *h2);

/* Arithmetic */
int addition(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2, Dlist **hR, Dlist **tR);
int subtraction(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2, Dlist **hR, Dlist **tR);
int multiplication(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2, Dlist **hR, Dlist **tR);
int division(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2, Dlist **hR, Dlist **tR);
int modulus(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2, Dlist **hR, Dlist **tR);
#endif
