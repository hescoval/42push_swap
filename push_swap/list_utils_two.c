#include "push.h"

int find_index(node *stack, int value)
{
	while(stack != NULL)
	{
		if(stack->value == value)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

int find_max(node *stack)
{
	int	max;

	max = stack->value;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int find_min(node *stack)
{
	int	min;

	min = stack->value;
	stack = stack->next;

	while(stack != NULL)
	{
		if(stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return(min);
}