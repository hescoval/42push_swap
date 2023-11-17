/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:31:04 by hescoval          #+#    #+#             */
/*   Updated: 2023/10/12 09:32:03 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

void	p_hdecimal(unsigned int n, int *printed, char flag, char *hexstring)
{
	char	print;

	if (n >= 16)
	{
		p_hdecimal((n / 16), printed, flag, hexstring);
		print = hexstring[n % 16];
		if (flag == 'X')
			print = ft_toupper(print);
		write(1, &print, 1);
		*printed += 1;
	}
	else
	{
		print = hexstring[n % 16];
		if (flag == 'X')
			print = ft_toupper(print);
		write(1, &print, 1);
		*printed += 1;
	}
}

void	p_pointer(unsigned long n, int *printed, char *hexstring)
{
	char	print;

	if (n >= 16)
	{
		p_pointer((n / 16), printed, hexstring);
		print = hexstring[n % 16];
		write(1, &print, 1);
		*printed += 1;
	}
	else
	{
		print = hexstring[n % 16];
		write(1, &print, 1);
		*printed += 1;
	}
}

void	p_hex(va_list args, int *printed, char flag)
{
	char			*hexa;
	unsigned long	pointer;

	hexa = "0123456789abcdef";
	if (flag == 'p')
	{
		pointer = va_arg(args, unsigned long);
		if (pointer == 0)
		{
			write(1, "(nil)", 5);
			*printed += 5;
			return ;
		}
		write(1, "0x", 2);
		*printed += 2;
		p_pointer(pointer, printed, hexa);
	}
	else
		p_hdecimal(va_arg(args, unsigned int), printed, flag, hexa);
}
