#include "push.h"

int p_Error()
{
	write(2, "Error\n", 6);
	return 1;
}