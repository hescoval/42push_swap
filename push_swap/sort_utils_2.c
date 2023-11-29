#include "push.h"

void	final_sort(node **s_a, node **s_b)
{
	node *helper;
	node *target;
	node *to_push;
	int min_cost;
	int curr_total;

	while (stack_size(*s_b) > 0)
	{
		min_cost = INT_MAX;
		helper = *s_b;
		check_cost(*s_a, *s_b);
		find_closest_inverse(*s_a, *s_b);
		while (helper)
		{
			target = find_node(*s_a, helper->closest);
			curr_total = total_cost(s_a, s_b, helper, target);
			if (curr_total < min_cost)
			{
				min_cost = curr_total;
				to_push = helper;
			}
			helper = helper->next;
		}
		do_command(s_b, s_a, to_push, 1, min_cost);
		push(s_b, s_a, 'a');
/* 		print_stacks(*s_a, *s_b); */
	}
}

int	total_cost(node **s_a, node **s_b, node *curr, node *target)
{
	int total;
	if (same_direction(*s_a, *s_b, curr, target))
		total = ft_max(curr->push_cost, target->push_cost);
	else
		total = curr->push_cost + target->push_cost;
	return (total);
}

void	do_command(node **s_a, node **s_b, node *to_push, int yep, int total)
{
	int direction;

	node *target = find_node(*s_b, to_push->closest);
	direction = same_direction(*s_a, *s_b, to_push, target);
	if(direction)
		helper_rotate(s_a, s_b, to_push, direction, &total);
	if(total)
		both_ways(s_a, s_b, to_push, target, yep);
}

void helper_rotate(node **s_a, node **s_b, node *to_push, int direction, int *total)
{
	node *target = find_node(*s_b, to_push->closest);
	while(target->index != 0 && to_push->index != 0)
	{
		if(direction == 1)
		{
			rotate(s_a, '0');
			rotate(s_b, '0');
			ft_printf("rr\n");
		}
		else
		{
			rev_rotate(s_a, '0');
			rev_rotate(s_b, '0');
			ft_printf("rrr\n");
		}
/* 		print_stacks(*s_a, *s_b); */
		*total -= 1;
	}
}

void both_ways(node **s_a, node **s_b, node *push, node *target, int yep)
{
	int size_a = stack_size(*s_a) / 2;
	int size_b = stack_size(*s_b) / 2;
	char print = 'b';
	if(yep)
		print = 'a';
	while(push->index != 0)
	{
		if(push->index > size_a)
			rev_rotate(s_a, 'a');
		else
			rotate(s_a, 'a');
/* 		print_stacks(*s_a, *s_b); */
	}
	while(target->index != 0)
	{
		if(target->index > size_b)
			rev_rotate(s_b, print);
		else
			rotate(s_b, print);
/* 		print_stacks(*s_a, *s_b); */
	}
}