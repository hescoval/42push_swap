/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:23:32 by hescoval          #+#    #+#             */
/*   Updated: 2023/10/12 09:23:33 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_char(va_list args, int *printed)
{
	int				hold;
	unsigned char	print;

	hold = va_arg(args, int);
	print = (unsigned char) hold;
	write(1, &print, 1);
	*printed += 1;
}
