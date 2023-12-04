/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:03:43 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:03:43 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	final_sort(t_n **s_a, t_n **s_b)
{
	t_n	*helper;
	t_n	*target;
	t_n	*to_push;
	int	nums[2];

	while (stack_size(*s_b) > 0)
	{
		nums[0] = INT_MAX;
		helper = *s_b;
		check_cost(*s_a, *s_b);
		find_closest_inverse(*s_a, *s_b);
		while (helper)
		{
			target = find_node(*s_a, helper->closest);
			nums[1] = total_cost(s_a, s_b, helper, target);
			if (nums[1] < nums[0])
			{
				nums[0] = nums[1];
				to_push = helper;
			}
			helper = helper->next;
		}
		do_command(s_b, s_a, to_push, nums[0]);
		push(s_b, s_a, 'a');
	}
}

int	total_cost(t_n **s_a, t_n **s_b, t_n *curr, t_n *target)
{
	int	total;

	if (same_direction(*s_a, *s_b, curr, target))
		total = ft_max(curr->push_cost, target->push_cost);
	else
		total = curr->push_cost + target->push_cost;
	return (total);
}

void	do_command(t_n **s_a, t_n **s_b, t_n *to_push, int total)
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
		both_ways(s_a, s_b, to_push, 1);
}

void	both_ways(t_n **s_a, t_n **s_b, t_n *push, int yep)
{
	char	print;
	t_n		*target;

	target = find_node(*s_b, push->closest);
	print = 'b';
	if (yep)
		print = 'a';
	while (push->index != 0)
	{
		if (push->index > stack_size(*s_a) / 2)
			rev_rotate(s_a, 'a');
		else
			rotate(s_a, 'a');
	}
	while (target->index != 0)
	{
		if (target->index > stack_size(*s_b) / 2)
			rev_rotate(s_b, print);
		else
			rotate(s_b, print);
	}
}
