#include "push.h"

void	shift_stack(node *popped, int up)
{
	while (popped != NULL)
	{
		if (up)
			popped->index += 1;
		else
			popped->index -= 1;
		popped = popped->next;
	}
}

void	pick_rotate(node **stack, int reverse)
{
	if (reverse)
		rev_rotate(stack);
 	else
		rotate(stack);
}

node	*fetch_last(node *stack)
{
	node *last;

	while (stack->next != NULL)
		stack = stack->next;
	last = stack;
	return (last);
}