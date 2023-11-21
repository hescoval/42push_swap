#include "push.h"


void print_stacks(node* s_a, node* s_b)
{
	node* helper_a = s_a;
	node* helper_b = s_b;
	printf("Stack A \t\t\t\t Stack B\n-------------------------\n");
	while(helper_a != NULL || helper_b != NULL)
	{
		if(helper_a != NULL)
		{
			printf(" Index is %i, value is %i\t", helper_a->index, helper_a->value);
			helper_a = helper_a->next;
		}
		printf("\t|\t");
		if(helper_b != NULL)
		{
			printf(" Index is %i, value is %i", helper_b->index, helper_b->value);
			helper_b = helper_b->next;
		}
		printf("\n");
	}
}

void start_sort(node* s_a, node* s_b)
{
	print_stacks(s_a, s_b);
	printf("\n\n\n\n");
	push(&s_a, &s_b);
	push(&s_a, &s_b);
	print_stacks(s_a, s_b);
	free_stack(s_a);
	free_stack(s_b);
}
