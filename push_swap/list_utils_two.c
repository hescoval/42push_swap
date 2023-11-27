#include "push.h"

node *find_node(node *stack, int value)
{
	while(stack != NULL)
	{
		if(stack->value == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
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