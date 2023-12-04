/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:01:50 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:01:51 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	high_to_top(t_n **head, char prnt)
{
	int	half_size;
	t_n	*helper;

	half_size = stack_size(*head) / 2;
	helper = find_node(*head, find_max(*head));
	if (helper->index > half_size)
		while (helper->index != 0)
			rev_rotate(head, prnt);
	else
		while (helper->index != 0)
			rotate(head, prnt);
}

void	find_closest(t_n *head_a, t_n *head_b)
{
	t_n	*h_a;
	t_n	*h_b;
	int	curr;

	h_a = head_a;
	while (h_a != NULL)
	{
		h_a->closest = INT_MAX;
		h_b = head_b;
		while (h_b != NULL)
		{
			curr = h_a->value;
			if (h_b->value < h_a->value)
			{
				if (ft_abs(curr - h_a->closest) > ft_abs(curr - h_b->value))
					h_a->closest = h_b->value;
			}
			h_b = h_b->next;
		}
		if (h_a->closest == INT_MAX)
			h_a->closest = find_max(head_b);
		h_a = h_a->next;
	}
}

void	check_cost(t_n *head_a, t_n *head_b)
{
	int	size;

	size = stack_size(head_a);
	while (head_a != NULL)
	{
		if (head_a->index <= (size / 2))
			head_a->push_cost = head_a->index;
		else
			head_a->push_cost = size - head_a->index;
		head_a = head_a->next;
	}
	size = stack_size(head_b);
	while (head_b != NULL)
	{
		if (head_b->index <= (size / 2))
			head_b->push_cost = head_b->index;
		else
			head_b->push_cost = size - head_b->index;
		head_b = head_b->next;
	}
}

int	is_sorted(t_n *head)
{
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	same_direction(t_n *s_a, t_n *s_b, t_n *curr_a, t_n *target)
{
	int	half_a;
	int	half_b;
	int	curr_i;
	int	target_i;

	half_a = stack_size(s_a) / 2;
	half_b = stack_size(s_b) / 2;
	curr_i = curr_a->index;
	target_i = target->index;
	if (curr_i == 0 || target_i == 0)
		return (0);
	if (curr_i > half_a && target_i > half_b)
		return (2);
	if (curr_i <= half_a && target_i <= half_b)
		return (1);
	return (0);
}
