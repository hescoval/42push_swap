#include "push.h"

void	find_closest(node *head_a, node *head_b)
{
	node	*h_a;
	node	*h_b;
	int closest;

	h_a = head_a;
	while (h_a != NULL)
	{
		h_b = head_b;
		while (h_b != NULL)
		{
			closest = h_a->closest;
			if (h_a->closest == h_a->value)
				h_a->closest = h_b->value;
			if (ft_abs(h_a->value - h_b->value) < ft_abs(closest - h_a->value))
				h_a->closest = h_b->value;
			h_b = h_b->next;
		}
		h_a = h_a->next;
	}
}
