/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_deci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:32:17 by hescoval          #+#    #+#             */
/*   Updated: 2023/10/12 09:32:18 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printchar(char x)
{
	write(1, &x, 1);
}

void	ft_uputnbr(unsigned int nbr, int *printed)
{
	if (nbr >= 10)
		ft_uputnbr(nbr / 10, printed);
	printchar(nbr % 10 + '0');
	*printed += 1;
}

void	ft_putnbr(int nbr, int *printed)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*printed += 11;
	}
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
			*printed += 1;
		}
		if (nbr >= 10)
			ft_putnbr(nbr / 10, printed);
		printchar(nbr % 10 + '0');
		*printed += 1;
	}
}

void	p_deci(va_list args, int *printed, char flag)
{
	if (flag == 'u')
		ft_uputnbr(va_arg(args, unsigned int), printed);
	else
		ft_putnbr(va_arg(args, int), printed);
}
