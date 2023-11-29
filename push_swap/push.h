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
void	high_to_top(node **head, char prnt);
int	total_cost(node **s_a, node **s_b, node *curr, node *target);
void	do_command(node **s_a, node **s_b, node *to_push);
void helper_rotate(node **s_a, node **s_b, int times, int direction, int *total);
void both_ways(node **s_a, node **s_b, node *push, node *target);
void find_closest_inverse(node *head_a, node *head_b);
void	min_to_top(node **head);

//Command helpers
void	shift_stack(node *popped, int up);
int		stack_size(node *stack);
node	*fetch_last(node *stack);
void	final_sort(node **s_a, node **s_b);

//Commands
void	push(node **stack_pop, node **stack_push, char prnt);
void	pick_rotate(node **stack, int reverse, char prnt);
void	rev_rotate(node **stack, char prnt);
void	rotate(node **stack, char prnt);
void	swap(node **stack, char prnt);

#endif