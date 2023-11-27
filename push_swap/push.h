#ifndef PUSH_H
# define PUSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <limits.h>

typedef struct node
{
	int		index;
	int		value;
	int		closest;
	int		push_cost;
	struct	node *next;
}				node;

//Initial int array utils
int		input_checker(int ac, char **strs);
int		*fill_array(int *arr, int ac, char **strs);
int		check_duplicates(int *arr, int size);
void	start_sort(node *s_a, node *s_b);

//List utils
node	*make_node(int index, int value);
node	*make_list(int *values, int size);
void	free_stack(node *stack);
int		find_min(node *stack);
int		find_max(node *stack);

//For debugging and error stuff
void	print_stacks(node *s_a, node *s_b);
int		p_Error();

//Sorting Algorithm Helpers
void	find_closest(node *head_a, node *head_b);
void	check_cost(node *head_a, node *head_b);
int		is_sorted(node *head);
node	*find_node(node *stack, int value);
void	sort_to_b(node **s_a, node **s_b);
void	initial_pushes(node **s_a, node **s_b);
int		same_direction(node *s_a, node *s_b, node *curr_a, node *target);

//Command helpers
void	shift_stack(node *popped, int up);
int		stack_size(node *stack);
node	*fetch_last(node *stack);

//Commands
void	push(node **stack_pop, node **stack_push);
void	pick_rotate(node **stack, int reverse);
void	rev_rotate(node **stack);
void	rotate(node **stack);
void	swap(node **stack);

#endif