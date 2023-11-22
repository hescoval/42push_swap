#include "push.h"

int	main(int ac, char **av)
{
	int 	*arr;
	int 	values;
	node	*stack_a;
	node	*stack_b;

	values = input_checker(ac, av);
	if (values == 0)
		return (p_Error());
	arr = malloc(sizeof(int) * values);	// Malloc array correct size
	if (!arr)	// Malloc protection
		return (p_Error());
	arr = fill_array(arr, ac, av);	//Fill'er up
	if (!arr)	//Overflow check
		return (p_Error());
 	if (check_duplicates(arr, values))	//Dupe check
	{
		free(arr);
		return (p_Error());
	} 
	stack_a = make_list(arr, values);
	stack_b = NULL;
	free(arr);
	start_sort(stack_a, stack_b);
}