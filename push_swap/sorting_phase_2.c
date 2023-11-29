#include "push.h"

void sort_to_b(node **s_a, node **s_b)
{
	node *helper;
	node *target;
	node *to_push;
	int min_cost;
	int curr_total;

	while (stack_size(*s_a) > 3)
	{
		min_cost = INT_MAX;
		helper = *s_a;
		check_cost(*s_a, *s_b);
		find_closest(*s_a, *s_b);
		while (helper)
		{
			target = find_node(*s_b, helper->closest);
			curr_total = total_cost(s_a, s_b, helper, target);
			if (curr_total < min_cost)
			{
				min_cost = curr_total;
				to_push = helper;
			}
			helper = helper->next;
		}
		do_command(s_a, s_b, to_push, 0, min_cost);
		push(s_a, s_b, 'b');
/* 		print_stacks(*s_a, *s_b); */
	}
}