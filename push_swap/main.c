#include "push.h"

int main(int ac, char **av)
{
	int values = input_checker(ac, av);
	if(values == 0)
		return (p_Error());

	int *arr = malloc(sizeof(int) * values);
	if(!arr)
		return(p_Error());
	arr = fill_array(arr, ac, av);
	if(!arr)
		return(p_Error());

	if(check_duplicates(arr, values))
	{
		free(arr);
		return(p_Error());
	}

	for(int i = 0; i < values; i++)
	{
		printf("[%i]\n", arr[i]);
	}
	free(arr);
	return 1;
}