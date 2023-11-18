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
	new->next = NULL;
	return (new);
}

node	*make_list(int *values, int size)
{
	int i = 0;
	node* head;
	node* curr = make_node(i, values[i]);
	head = curr;
	while(i < size - 1)
	{
		curr->next = make_node(i + 1, values[i + 1]);
		curr = curr->next;
		i++;
	}
	return(head);
}