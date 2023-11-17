/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:23:17 by hescoval          #+#    #+#             */
/*   Updated: 2023/10/12 09:23:18 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_flag(const char *str, va_list args, int *printed)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				p_char(args, printed);
			if (*str == 's')
				p_str(args, printed);
			if (*str == 'p' || *str == 'x' || *str == 'X')
				p_hex(args, printed, *str);
			if (*str == 'i' || *str == 'd' || *str == 'u')
				p_deci(args, printed, *str);
			if (*str == '%')
				p_module(printed);
		}
		else
		{
			write(1, str, 1);
			*printed += 1;
		}
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed;

	printed = 0;
	va_start(args, str);
	check_flag(str, args, &printed);
	va_end(args);
	return (printed);
}

/* int main(void)
{
	char *pointer = "string";
	ft_printf("%p\n", pointer);
	ft_printf("%X\n", 10231231);
	ft_printf("%x", 10231231);
} */
