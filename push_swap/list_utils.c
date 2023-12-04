/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:05:10 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:05:10 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	free_stack(t_n *stack)
{
	t_n	*helper;

	helper = stack;
	while (helper != NULL)
	{
		helper = stack->next;
		free(stack);
		stack = helper;
	}
}

t_n	*make_node(int index, int value)
{
	t_n	*new;

	new = malloc(sizeof(t_n));
	if (new == NULL)
		return (NULL);
	new->index = index;
	new->value = value;
	new->closest = INT_MAX;
	new->push_cost = index;
	new->next = NULL;
	return (new);
}

t_n	*make_list(int *values, int size)
{
	int	i;
	t_n	*head;
	t_n	*curr;

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

int	stack_size(t_n *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	print_stacks(t_n *s_a, t_n *s_b)
{
	t_n	*helper_b;
	t_n	*helper_a;

	helper_a = s_a;
	helper_b = s_b;
	while (helper_a != NULL)
	{
		ft_printf("{ %i} -->", helper_a->value);
		helper_a = helper_a->next;
	}
	ft_printf("\n\n");
	while (helper_b != NULL)
	{
		ft_printf("{ %i} -->", helper_b->value);
		helper_b = helper_b->next;
	}
	ft_printf("\n");
}
