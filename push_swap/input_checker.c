/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:19:26 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:19:26 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	isdigit_s(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '\t' || c == '-')
		return (1);
	return (0);
}

int	check_string(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			return (0);
		if (str[i] == '-' && i && (str[i - 1] != ' ' && str[i - 1] != '\t'))
			return (0); 
		if (!isdigit_s(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_values(int ac, char **strs)
{
	int	i;
	int	values;
	int	j;

	values = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (strs[i][j])
		{
			while (!ft_isdigit(strs[i][j]))
				j++;
			if (ft_isdigit(strs[i][j]))
				values++;
			while (ft_isdigit(strs[i][j]))
				j++;
		}
		i++;
	}
	return (values);
}

int	input_checker(int ac, char **strs)
{
	int	values;
	int	i;

	i = 1;
	values = check_values(ac, strs);
	while (i < ac)
	{
		if (!check_string(strs[i]))
			return (-1);
		i++;
	}
	return (values);
}
