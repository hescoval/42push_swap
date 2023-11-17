#include "push.h"

int isdigit_S(char c)
{
	if((c >= '0' && c <= '9') || c == ' ' || c == '\t' || c == '-')
		return 1;
	return 0;
}

int check_string(char *str)
{
	int i = 0;
	
	if(!str[i])
		return 0;
	while(str[i])
	{	
		if(str[i] == '-' && !ft_isdigit(str[i + 1]))
			return 0;
		if(str[i] == '-' && i != 0 && (str[i - 1] != ' ' && str[i - 1] != '\t'))
			return 0; 
		if(!isdigit_S(str[i]))
			return 0;
		i++;
	}
	return 1;
}

int check_values(int ac, char **strs)
{
	int values = 0;
	int i = 1;
	while(i < ac)
	{
		int j = 0;
		while(strs[i][j])
		{
			while(!ft_isdigit(strs[i][j]))
				j++;
			if(ft_isdigit(strs[i][j]))
				values++;
			while(ft_isdigit(strs[i][j]))
				j++;
		}
		i++;
	}
	return values;
}

int input_checker(int ac, char **strs)
{
	int i = 1;
	while(i < ac)
	{
		if(!check_string(strs[i]))
			return 0;
		i++;
	}
	int values = check_values(ac, strs);
	return(values);
}
