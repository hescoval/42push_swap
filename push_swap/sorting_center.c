#include "push.h"

void	initial_pushes(node **s_a, node **s_b)
{
	int pushes = 0;
	while(stack_size(*s_a) > 3 && pushes < 2)
	{
		print_stacks(*s_a, *s_b);
		push(s_a, s_b);
		printf("pb\n");
		pushes++;
	}
	print_stacks(*s_a, *s_b);
/* 	if(is_sorted(*s_b) && stack_size(*s_b) == 2)
	{
		swap(s_b);
		ft_printf("sb\n");
	} */
}

void	start_sort(node *s_a, node *s_b)
{
	int	size;
	int sent;

	sent = 0;
	size = stack_size(s_a);
	if (!is_sorted(s_a) && size > 3)
	{
 		sent = 1; 
		initial_pushes(&s_a, &s_b);
		sort_to_b(&s_a, &s_b);
	}

/* 	sort_a(&s_a); */
	if(sent)
	{
/* 		final_sort(&s_a, &s_b); */
		free_stack(s_b);
	}

	free_stack(s_a);
}
