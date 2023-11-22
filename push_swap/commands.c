#include "push.h"

void	push(node **stack_pop, node **stack_push)
{
	node	*helper;

	helper = *stack_pop;
	if (stack_size(*stack_pop) == 0)
		return;
	shift_stack(*stack_pop, 0);
	shift_stack(*stack_push, 1);
	*stack_pop = (*stack_pop)->next;
	helper->next = *stack_push;
	*stack_push = helper;
	(*stack_push)->index = 0;
}

void	rev_rotate(node **stack)
{
	node *helper;
	node *last;

	last = fetch_last(*stack);
	helper = *stack;
	shift_stack(*stack, 1);
	int size = stack_size(*stack);
	int i = 0;
	while (i < size - 1)
	{
		if (i == size - 2)
			helper->next = NULL;
		helper = helper->next;
		i++;
	}
	last->next = *stack;
	*stack = last;
	(*stack)->index = 0;
}

void	rotate(node **stack)
{
	node	*second;
	node	*helper;
	node	*last;
	int		size;

	size = stack_size(*stack);
	helper = *stack;
	last = fetch_last(*stack);
	second = (*stack)->next;

	shift_stack(*stack, 0);
	(*stack) = second;
	last->next = helper;
	helper->index = size - 1;
	helper->next = NULL;
}

void	swap(node **stack)
{
	node* second;
	
	if(stack_size(*stack) < 2)
		return;
	second = (*stack)->next;
	second->index = 0;
	(*stack)->index = 1;
	(*stack)->next = second->next;
	second->next = (*stack);
	(*stack) = second;
}