/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:13:40 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:13:40 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	shift_stack(t_n *popped, int up)
{
	while (popped != NULL)
	{
		if (up)
			popped->index += 1;
		else
			popped->index -= 1;
		popped = popped->next;
	}
}

void	pick_rotate(t_n **stack, int reverse, char prnt)
{
	if (reverse)
		rev_rotate(stack, prnt);
	else
		rotate(stack, prnt);
}

t_n	*fetch_last(t_n *stack)
{
	t_n	*last;

	while (stack->next != NULL)
		stack = stack->next;
	last = stack;
	return (last);
}
