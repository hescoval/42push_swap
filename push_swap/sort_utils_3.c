#include "push.h"

void find_closest_inverse(node *head_a, node *head_b)
{
	node	*h_a;
	node	*h_b;
	int curr;

	h_b = head_b;
	while (h_b != NULL)
	{
		h_b->closest = INT_MIN;
		h_a = head_a;
		while (h_a != NULL)
		{
			curr = h_b->value;
			if(h_b->value < h_a->value)
			{
				if(ft_abs(curr - h_b->closest) > ft_abs(curr - h_a->value))
					h_b->closest = h_a->value;
			}
			h_a = h_a->next;
		}
		if(h_b->closest == INT_MIN) //Didnt find a value lower than itself.
			h_b->closest = find_min(head_a);
		h_b = h_b->next;
	}
}

void	min_to_top(node **head)
{
	node *helper = find_node(*head, find_min(*head));

	while(helper->index != 0)
		rev_rotate(head, 'a');
}