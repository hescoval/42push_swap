#include "push.h"

//Decrease all of stack_pop's indexes by 1.
//Increase all of stack_push's indexes by 1;
//Make stack_pop point to 2nd node (if it exists, NULL otherwise)
//Make stack_push point to popped node

/*		A			B					A			B
	|	1	|						|	2	|	|	1	|
	|	2	|			----->		|	3	|
	|	3	|
*/

//Error handling----

void push(node **stack_pop, node **stack_push)
{
	shift_stack(*stack_pop, 0);
	shift_stack(*stack_push, 1);

	node *helper = *stack_pop;

	*stack_pop = (*stack_pop)->next;
	
	helper->next = *stack_push;
	*stack_push = helper;
	(*stack_push)->index = 0;
}


void	rotate(node **stack)
{
	shift_stack(*stack, 1);
	int size = stack_size(*stack);
	int i = 0;
	node *helper = *stack;
	node *last = fetch_last(*stack);
	while(i < size - 1)
	{
		if(i == size - 2)
			helper->next = NULL;
		helper = helper->next;
		i++;
	}
	last->next = *stack;
	*stack = last;
	(*stack)->index = 0;
}
