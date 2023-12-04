/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:31:21 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:31:21 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int ac, char **av)
{
	int	*arr;
	int	values;
	t_n	*stack_a;
	t_n	*stack_b;

	values = input_checker(ac, av);
	arr = malloc(sizeof(int) * values);
	if (!arr)
		return (p_error(values));
	arr = fill_array(arr, ac, av);
	if (!arr)
	{
		free(arr);
		return (p_error(values));
	}
	if (check_duplicates(arr, values))
	{
		free(arr);
		return (p_error(values));
	}
	stack_a = make_list(arr, values);
	stack_b = NULL;
	free(arr);
	start_sort(stack_a, stack_b);
}
