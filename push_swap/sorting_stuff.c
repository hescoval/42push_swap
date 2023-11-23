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
	printf("\n\n%i", is_sorted(s_a));
	free_stack(s_a);
	free_stack(s_b);
}
