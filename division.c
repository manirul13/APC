#include "apc.h"

int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    // Convert divisor to integer (for now supports within int range)
    long long divisor = 0;
    for (Dlist *p = *head2; p; p = p->next)
    {
        divisor = divisor * 10 + p->data;
    }

    if (divisor == 0)
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    long long rem = 0;
    int started = 0; // Flag to skip leading zeros

    for (Dlist *p = *head1; p; p = p->next)
    {
        rem = rem * 10 + p->data;
        int q = rem / divisor;
        rem %= divisor;

        if (q != 0 || started)
        {
            insert_at_last(headR, tailR, q);
            started = 1;
        }
    }

    if (!started) // If quotient is zero
        insert_at_last(headR, tailR, 0);

    return SUCCESS;
}
