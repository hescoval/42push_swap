#include "push.h"

void	find_closest(node *head_a, node *head_b)
{
	node	*h_a;
	node	*h_b;
	int curr;

	h_a = head_a;
	while (h_a != NULL)
	{
		h_a->closest = INT_MAX;
		h_b = head_b;
		while (h_b != NULL)
		{
			curr = h_a->value;
			if(h_b->value < h_a->value)
			{
				if(ft_abs(curr - h_a->closest) > ft_abs(curr - h_b->value))
					h_a->closest = h_b->value;
			}
			h_b = h_b->next;
		}
		if(h_a->closest == INT_MAX) //Didnt find a value lower than itself.
			h_a->closest = find_max(head_b);
		h_a = h_a->next;
	}
}

void	check_cost(node *head_a, node *head_b)
{
	int size = stack_size(head_a);

	while (head_a != NULL)
	{
		if (head_a->index <= (size / 2))
			head_a->push_cost = head_a->index;
		else
			head_a->push_cost = size - head_a->index;
		head_a = head_a->next;
	}

	size = stack_size(head_b);
	while (head_b != NULL)
	{
		if (head_b->index <= (size / 2))
			head_b->push_cost = head_b->index;
		else
			head_b->push_cost = size - head_b->index;
		head_b = head_b->next;
	}
}

int	is_sorted(node *head)
{
	while(head->next != NULL)
	{
		if(head->value > head->next->value)
			return 0;
		head = head->next;
	}
	return 1;
}

int	same_direction(node *s_a, node *s_b, node *curr_a, node *target)
{
	int half_a = stack_size(s_a) / 2;
	int half_b = stack_size(s_b) / 2;

	int curr_i = curr_a->index;
	int target_i = target->index;
	if(curr_i == 0 || target_i == 0)
		return 0;
	if(curr_i > half_a && target_i > half_b)
		return 2;
	if(curr_i <= half_a && target_i <= half_b)
		return 1;
	return 0;
}