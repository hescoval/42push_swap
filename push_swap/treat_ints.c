#include "push.h"

int number(char c)
{
	if(ft_isdigit(c) || c == '-')
		return 1;
	return 0;
}

int *fill_array(int *arr, int ac, char **strs)
{
	int i = 1;
	int values = 0;
	while(i < ac)
	{
		int j = 0;
		while(strs[i][j])
		{
			while(!number(strs[i][j]) && strs[i][j])
				j++;
			if(number(strs[i][j]) && strs[i][j])
				arr[values++] = ft_atoi(&strs[i][j]);
			while(number(strs[i][j]) && strs[i][j])
				j++;
		}
		i++;
	}
	return (arr);
}