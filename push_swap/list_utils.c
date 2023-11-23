#include "push.h"

void	free_stack(node *stack)
{
	node	*helper;

	helper = stack;
	while (helper != NULL)
	{
		helper = stack->next;
		free(stack);
		stack = helper;
	}
}

node	*make_node(int index, int value)
{
	node	*new;

	new = malloc(sizeof(node));
	if (new == NULL)
		return (NULL);
	new->index = index;
	new->value = value;
	new->closest = INT_MAX;
	new->push_cost = index;
	new->next = NULL;
	return (new);
}

node	*make_list(int *values, int size)
{
	int i;
	node *head;
	node *curr;

	i = 1;
	head = make_node(0, values[0]);
	curr = head;
	while (i < size)
	{
		curr->next = make_node(i, values[i]);
		curr = curr->next;
		i++;
	}
	return (head);
}

int	stack_size(node *stack)
{
	int i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	print_stacks(node* s_a, node* s_b)
{
	node* helper_b;
	node* helper_a;
	int biggest = ft_max(stack_size(s_a), stack_size(s_b));
	helper_a = s_a;
	helper_b = s_b;
	while (biggest)
	{
		if (helper_a != NULL)
		{
			printf("Index: %i, Value is %i, push cost is: %i\t", helper_a->index, helper_a->value, helper_a->push_cost);
			helper_a = helper_a->next;
		}
 		printf("\t|\t");
		if (helper_b != NULL)
		{
			printf(" Index: %i, value: %i, push cost is: %i", helper_b->index, helper_b->value, helper_b->push_cost);
			helper_b = helper_b->next;
		} 
		biggest--;
		printf("\n");
	}
}
