#ifndef PUSH_H
# define PUSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct node
{
	int index;
	int value;
	struct node *next;
}	node;

int input_checker(int ac, char **strs);
int p_Error();
int *fill_array(int *arr, int ac, char **strs);
int check_duplicates(int *arr, int size);

#endif