#include "push.h"

void shift_stack(node *popped, int up)
{
	if(up)
	{
		while(popped != NULL)
		{
			popped->index += 1;
			popped = popped->next;
		}
	}
}
void pick_rotate(node **stack, int reverse)
{
	if(reverse)
		rotate(stack);
	/* else
		rev_rotate(stack); */
}

node *fetch_last(node *stack)
{
	node *last;

	while(stack->next != NULL)
		stack = stack->next;

	last = stack;
	return(last);
}