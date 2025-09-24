#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *p1 = *tail1;
	Dlist *p2 = *tail2;
	int carry = 0;

	while (p1 || p2 || carry)
	{
		int sum = carry;
		if (p1)
		{
			sum += p1->data;
			p1 = p1->prev;
		}
		if (p2)
		{
			sum += p2->data;
			p2 = p2->prev;
		}

		carry = sum / 10;
		sum = sum % 10;
		insert_at_first(headR, tailR, sum);
	}
	
	return SUCCESS;
}
