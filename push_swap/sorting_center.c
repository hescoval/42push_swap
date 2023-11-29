#include "push.h"

void	sort_a(node **s_a)
{
	if(is_sorted(*s_a))
		return;
	if (find_min(*s_a) == (*s_a)->value)
	{
		rev_rotate(s_a, 'a');
		swap(s_a, 'a');
	}
	else if (find_max(*s_a) == (*s_a)->value)
	{
		rotate(s_a, 'a');
		if (!is_sorted(*s_a))
			swap(s_a, 'a');
	}
	else
	{
		if (find_node(*s_a, find_max(*s_a))->index == 1)
			rev_rotate(s_a, 'a');
		else
			swap(s_a, 'a');
	}
}

void	initial_pushes(node **s_a, node **s_b)
{
	int pushes = 0;
	while(stack_size(*s_a) > 3 && pushes < 2)
	{
/* 		print_stacks(*s_a, *s_b); */
		push(s_a, s_b, 'b');
		pushes++;
	}
/* 	print_stacks(*s_a, *s_b); */
}

void	start_sort(node *s_a, node *s_b)
{
	int	size;
	int sent;

	sent = 0;
	size = stack_size(s_a);
	if(is_sorted(s_a))
		return;
	if (size > 3)
	{
 		sent = 1; 
		initial_pushes(&s_a, &s_b);
		sort_to_b(&s_a, &s_b);
		high_to_top(&s_b, 'b');
/* 		print_stacks(s_a, s_b); */
	}
	sort_a(&s_a);
/* 	print_stacks(s_a, s_b); */
	if(sent)
	{
 		final_sort(&s_a, &s_b);
		min_to_top(&s_a);
 		print_stacks(s_a, s_b);
		free_stack(s_b);
	}
	free_stack(s_a);
}
