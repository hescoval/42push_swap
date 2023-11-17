/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:32:10 by hescoval          #+#    #+#             */
/*   Updated: 2023/10/12 09:32:11 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_str(va_list args, int *printed)
{
	int		i;
	char	*print;

	i = 0;
	print = va_arg(args, char *);
	if (!print)
	{
		write(1, "(null)", 6);
		*printed += 6;
		return ;
	}
	while (print[i])
	{
		write(1, &print[i], 1);
		*printed += 1;
		i++;
	}
}
