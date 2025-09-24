#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	// step 1: compare numbers
	int cmp = compare_lists(*head1, *head2);

	if (cmp == 0) // Equal numbers -> result = 0
	{
		insert_at_first(headR, tailR, 0);
		return SUCCESS;
	}
	else if (cmp < 0) // num1 < num2 -> swap
	{
		swap_lists(head1, tail1, head2, tail2);
	}

	// step2: subtract (num1 > num2 now)
	Dlist *p1 = *tail1;
	Dlist *p2 = *tail2;
	int borrow = 0;

	while (p1 || p2)
	{
		int differ = (p1 ? p1->data : 0) - borrow - (p2 ? p2->data : 0);

		if (differ < 0)
		{
			differ += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}

		insert_at_first(headR, tailR, differ);

		if (p1)
			p1 = p1->prev;
		if (p2)
			p2 = p2->prev;
	}

	// step 3: Remove leading zeros
	while (*headR && (*headR)->data == 0 && (*headR)->next)
	{
		Dlist *temp = *headR;
		*headR = (*headR)->next;
		(*headR)->prev = NULL;
		free(temp);
	}

	return SUCCESS;
}
