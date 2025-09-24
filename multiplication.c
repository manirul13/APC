#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int len1 = 0, len2 = 0;

    // Find lengths of both numbers
    for (Dlist *t = *head1; t; t = t->next) len1++;
    for (Dlist *t = *head2; t; t = t->next) len2++;

    // Allocate result array
    int *result = calloc(len1 + len2, sizeof(int));
    if (!result) return FAILURE;

    int i = len1 - 1;

    // Multiply each digit of num1 with each digit of num2
    for (Dlist *p1 = *tail1; p1; p1 = p1->prev, i--)
    {
        int carry = 0;
        int j = len2 - 1;
        for (Dlist *p2 = *tail2; p2; p2 = p2->prev, j--)
        {
            int mul = p1->data * p2->data + result[i + j + 1] + carry;
            carry = mul / 10;
            result[i + j + 1] = mul % 10;
        }
        result[i] += carry;
    }

    // Skip leading zeros
    int start = 0;
    while (start < len1 + len2 - 1 && result[start] == 0)
        start++;

    // Insert result digits into the linked list
    for (int k = start; k < len1 + len2; k++)
        insert_at_last(headR, tailR, result[k]);

    free(result);
    return SUCCESS;
}
