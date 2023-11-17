#include "push.h"

int main(int ac, char **av)
{
	int values = input_checker(ac, av);
	if(values == 0)
		return (p_Error());

	int *arr = malloc(sizeof(int) * values);
	if(!arr)
		return(p_Error());
	fill_array(arr, ac, av);

/*
	if(check_duplicates(arr))
	{
		free(arr);
		return(p_Error());
	}
*/
	return 1;
}