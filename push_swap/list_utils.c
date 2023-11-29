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
	
	helper_a = s_a;
	helper_b = s_b;
	while (helper_a != NULL)
	{
		printf("{ %i} -->", helper_a->value);
		helper_a = helper_a->next;
	}
 	printf("\n\n");
	while (helper_b != NULL)
	{
		printf("{ %i} -->", helper_b->value);
		helper_b = helper_b->next;
	} 
	printf("\n");
}
