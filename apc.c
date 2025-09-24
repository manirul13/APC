#include "apc.h"

void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
    char *num1 = argv[1];
    char *num2 = argv[3];

    for (int i = 0; num1[i]; i++)
        insert_at_last(head1, tail1, num1[i] - '0');

    for (int i = 0; num2[i]; i++)
        insert_at_last(head2, tail2, num2[i] - '0');
}

void print_list(Dlist *head)
{
    if (!head)
    {
        printf("0\n");
        return;
    }
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    new->data = data;
    new->prev = *tail;
    new->next = NULL;

    if (*tail)
        (*tail)->next = new;
    else
        *head = new;

    *tail = new;
}

void insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head)
    {
        (*head)->prev = new;
    }
    else
    {
        *tail = new;
    }

    *head = new;
}

int compare_lists(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;
    for (Dlist *t = head1; t; t = t->next)
        len1++;
    for (Dlist *t = head2; t; t = t->next)
        len2++;

    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;

    // Same length → compare digit by digit
    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return 1;
        if (head1->data < head2->data)
            return -1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}

void swap_lists(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2)
{
    Dlist *tmpH = *h1, *tmpT = *t1;
    *h1 = *h2;
    *t1 = *t2;
    *h2 = tmpH;
    *t2 = tmpT;
}