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
		do_command(s_b, s_a, to_push);
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

void	do_command(node **s_a, node **s_b, node *to_push)
{
	int total;
	int direction;

	node *target = find_node(*s_b, to_push->closest);
	total = ft_max(to_push->push_cost, target->push_cost);
	int to_do = ft_min(to_push->push_cost, target->push_cost);
	direction = same_direction(*s_a, *s_b, to_push, target);
	if(direction)
		helper_rotate(s_a, s_b, to_do, direction, &total);
	if(total)
		both_ways(s_a, s_b, to_push, target);
}

void helper_rotate(node **s_a, node **s_b, int times, int direction, int *total)
{
	while(times && direction)
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
		times--;
		*total -= 1;
	}
}

void both_ways(node **s_a, node **s_b, node *push, node *target)
{
	int size_a = stack_size(*s_a) / 2;
	int size_b = stack_size(*s_b) / 2;

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
			rev_rotate(s_b, 'b');
		else
			rotate(s_b, 'b');
/* 		print_stacks(*s_a, *s_b); */
	}
}