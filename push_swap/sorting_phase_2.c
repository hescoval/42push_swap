/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_phase_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:23:46 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:23:47 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_to_b(t_n **s_a, t_n **s_b)
{
	t_n	*helper;
	t_n	*target;
	t_n	*to_push;
	int	nums[2];

	while (stack_size(*s_a) > 3)
	{
		nums[0] = INT_MAX;
		helper = *s_a;
		check_cost(*s_a, *s_b);
		find_closest(*s_a, *s_b);
		while (helper)
		{
			target = find_node(*s_b, helper->closest);
			nums[1] = total_cost(s_a, s_b, helper, target);
			if (nums[1] < nums[0])
			{
				nums[0] = nums[1];
				to_push = helper;
			}
			helper = helper->next;
		}
		do_command_second(s_a, s_b, to_push, nums[0]);
		push(s_a, s_b, 'b');
	}
}
