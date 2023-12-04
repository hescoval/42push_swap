/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:26:43 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:26:44 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_n	*find_node(t_n *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	find_max(t_n *stack)
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

int	find_min(t_n *stack)
{
	int	min;

	min = stack->value;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	do_command_second(t_n **s_a, t_n **s_b, t_n *to_push, int total)
{
	t_n	*target;
	int	direction;

	target = find_node(*s_b, to_push->closest);
	direction = same_direction(*s_a, *s_b, to_push, target);
	if (direction == 1)
		r_both(s_a, s_b, to_push, &total);
	if (direction == 2)
		rr_both(s_a, s_b, to_push, &total);
	if (total)
		both_ways(s_a, s_b, to_push, 0);
}
