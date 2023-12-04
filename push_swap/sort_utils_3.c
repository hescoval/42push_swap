/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:03:39 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:03:40 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	find_closest_inverse(t_n *head_a, t_n *head_b)
{
	t_n	*h_a;
	t_n	*h_b;
	int	curr;

	h_b = head_b;
	while (h_b != NULL)
	{
		h_b->closest = INT_MIN;
		h_a = head_a;
		while (h_a != NULL)
		{
			curr = h_b->value;
			if (h_b->value < h_a->value)
			{
				if (ft_abs(curr - h_b->closest) > ft_abs(curr - h_a->value))
					h_b->closest = h_a->value;
			}
			h_a = h_a->next;
		}
		if (h_b->closest == INT_MIN)
			h_b->closest = find_min(head_a);
		h_b = h_b->next;
	}
}

void	min_to_top(t_n **head)
{
	t_n	*helper;

	helper = find_node(*head, find_min(*head));
	while (helper->index != 0)
		rev_rotate(head, 'a');
}

void	r_both(t_n **s_a, t_n **s_b, t_n *to_push, int *total)
{
	t_n	*target;

	target = find_node(*s_b, to_push->closest);
	while (target->index != 0 && to_push->index != 0)
	{
		rotate(s_a, '0');
		rotate(s_b, '0');
		ft_printf("rr\n");
		*total -= 1;
	}
}

void	rr_both(t_n **s_a, t_n **s_b, t_n *to_push, int *total)
{
	t_n	*target;

	target = find_node(*s_b, to_push->closest);
	while (target->index != 0 && to_push->index != 0)
	{
		rev_rotate(s_a, '0');
		rev_rotate(s_b, '0');
		ft_printf("rrr\n");
		*total -= 1;
	}
}
