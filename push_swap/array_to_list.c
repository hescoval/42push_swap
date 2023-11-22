#include "push.h"

int	number(char c)
{
	if(ft_isdigit(c) || c == '-')
		return 1;
	return 0;
}

int	check_duplicates(int *arr, int size)
{
	int i = 0;
	while(i < size - 1)
	{
		int j = i + 1;
		while(j < size)
		{
			if(arr[i] == arr[j])
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

int	*fill_array(int *arr, int ac, char **strs)
{
	int i;
	int j;
	int values;

	i = 1;
	values = 0;
	while (i < ac)
	{
		j = 0;
		while (strs[i][j])
		{
			while (!number(strs[i][j]) && strs[i][j])
				j++;
			if (number(strs[i][j]) && strs[i][j])
			{
				if (ft_atoi(&strs[i][j]) != ft_atol(&strs[i][j]))
					return (NULL);
				arr[values++] = ft_atoi(&strs[i][j]);
			}
			while (number(strs[i][j]) && strs[i][j])
				j++;
		}
		i++;
	}
	return (arr);
}