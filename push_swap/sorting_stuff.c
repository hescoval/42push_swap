#include "push.h"

void	start_sort(node *s_a, node *s_b)
{
 	int	size;
	int	pushed;

	size = stack_size(s_a);
	pushed = 0;
	print_stacks(s_a, s_b);
	printf("\n\n\n");
	while (pushed < 2 && size > 3)
	{
		push(&s_a, &s_b);
		pushed++;
		size = stack_size(s_a);
	}
	if(s_b)
		check_cost(s_a, s_b);

	print_stacks(s_a, s_b);
	printf("15 is in position: %i, and 2 is in position: %i", find_index(s_a, 15), find_index(s_b, 2));

	free_stack(s_a);
	free_stack(s_b);
}
