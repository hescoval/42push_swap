#include "push.h"

void start_sort(node* s_a, node* s_b)
{

}

void print_stacks(node* s_a, node* s_b)
{
	node* helper_a = s_a;
	node* helper_b = s_b;
	printf("Stack A \t Stack B\n-------------------------\n");
	while(helper_a != NULL || helper_b != NULL)
	{
		if(helper_a != NULL)
		{
			printf(" %i", helper_a->value);
			helper_a = helper_a->next;
		}
		printf("\t|\t");
		if(helper_b != NULL)
		{
			printf(" %i", helper_b->value);
			helper_b = helper_b->next;
		}
		printf("\n");
	}
}