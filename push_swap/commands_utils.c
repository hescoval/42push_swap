#include "push.h"

void shift_stacks(node *popped, node *pushed)
{
	while(popped != NULL)
	{
		popped->index -= 1;
		popped = popped->next;
	}

	while(pushed != NULL)
	{
		pushed->index += 1;
		pushed = pushed->next;
	}
}