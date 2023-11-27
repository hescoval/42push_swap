#include "push.h"

void both_ways(node **s_a, node **s_b, node *push, node *target)
{
	int size_a = stack_size(*s_a) / 2;
	int size_b = stack_size(*s_b) / 2;

	while(push->index != 0)
	{
		if(push->index > size_a)
		{
			rev_rotate(s_a);
			printf("rra\n");
		}
		else
		{
			rotate(s_a);
			printf("ra\n");
		}
		print_stacks(*s_a, *s_b);
	}
	while(target->index != 0)
	{
		if(target->index > size_b)
		{
			rev_rotate(s_b);
			printf("rrb\n");
		}
		else
		{
			rotate(s_b);
			printf("rb\n");
		}
		print_stacks(*s_a, *s_b);
	}
}

void helper_rotate(node **s_a, node **s_b, int times, int direction, int *total)
{
	while(times && direction)
	{
		if(direction == 1)
		{
			rotate(s_a);
			rotate(s_b);
			ft_printf("rr\n");
		}
		else
		{
			rev_rotate(s_a);
			rev_rotate(s_b);
			ft_printf("rrr\n");
		}
		print_stacks(*s_a, *s_b);
		times--;
		*total -= 1;
	}
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

int	total_cost(node **s_a, node **s_b, node *curr, node *target)
{
	int total;
	if (same_direction(*s_a, *s_b, curr, target))
		total = ft_max(curr->push_cost, target->push_cost);
	else
		total = curr->push_cost + target->push_cost;
	return (total);
}

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
		do_command(s_a, s_b, to_push);
		push(s_a, s_b);
		ft_printf("pb\n");
		print_stacks(*s_a, *s_b);
	}
}