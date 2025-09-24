#include "apc.h"

int main(int argc, char *argv[])
{

	if (argc != 4)
    {
        if (argc > 4) 
        {
            char *num1 = argv[1];
            char *num2 = argv[argc - 1]; // last argument is num2
            argv[1] = num1;
            argv[2] = "*"; // set operator to avoid wildcard (glob), other multiplication done by "*"
            argv[3] = num2;
            argc = 4; // reset argument count
        }
        else
        {
            printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);
            return FAILURE;
        }
    }
	/* Declare the pointers */

	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL, *tailR = NULL;

	char operator = argv[2][0];

	digit_to_list(&head1, &tail1, &head2, &tail2, argv);

	switch (operator)
	{
	case '+':
		/* call the function to perform the addition operation */
		addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	case '-':
		/* call the function to perform the subtraction operation */
		subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	case '*':
		/* call the function to perform the multiplication operation */
		multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	case '/':
		/* call the function to perform the division operation */
		division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	default:
		printf("Invalid Input!!! Try again...\n");
		return FAILURE;
	}

	print_list(headR);

	return 0;
}
