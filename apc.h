#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
} Dlist;

/* Include the prototypes here */

/*Addition */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Division */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*store the operands into the list */
void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

/* Print the list result */
void print_list(Dlist *head);

/* Helper to insert at front */
void insert_at_first(Dlist **head, Dlist **tail, int data);

/* Helper to insert at end */
void insert_at_last(Dlist **head, Dlist **tail, int data);

/* Compare two numbers stored in linked lists */
int compare_lists(Dlist *head1, Dlist *head2);

/* Swap list pointers */
void swap_lists(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2);

#endif
