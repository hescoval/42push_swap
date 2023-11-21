#include "push.h"

void	free_stack(node *stack)
{
	node	*helper;
	helper = stack;
	while(helper != NULL)
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
	new->closest = value;
	new->next = NULL;
	return (new);
}

node	*make_list(int *values, int size)
{
	int i = 1;
	node* head = make_node(0, values[0]);
	node* curr = head;
	while(i < size)
	{
		curr->next = make_node(i, values[i]);
		curr = curr->next;
		i++;
	}
	return(head);
}
int stack_size(node *stack)
{
	int i = 0;
	while(stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return i;
}
