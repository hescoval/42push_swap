/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:21:08 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/04 14:21:09 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct t_n
{
	int			index;
	int			value;
	int			closest;
	int			push_cost;
	struct t_n	*next;
}				t_n;

//Initial int array utils
int		input_checker(int ac, char **strs);
int		*fill_array(int *arr, int ac, char **strs);
int		check_duplicates(int *arr, int size);
void	start_sort(t_n *s_a, t_n *s_b);

//List utils
t_n		*make_node(int index, int value);
t_n		*make_list(int *values, int size);
void	free_stack(t_n *stack);
int		find_min(t_n *stack);
int		find_max(t_n *stack);

//For debugging and error stuff
void	print_stacks(t_n *s_a, t_n *s_b);
int		p_error(int values);

//Sorting Algorithm Helpers
void	find_closest(t_n *head_a, t_n *head_b);
void	check_cost(t_n *head_a, t_n *head_b);
int		is_sorted(t_n *head);
t_n		*find_node(t_n *stack, int value);
void	sort_to_b(t_n **s_a, t_n **s_b);
void	initial_pushes(t_n **s_a, t_n **s_b);
int		same_direction(t_n *s_a, t_n *s_b, t_n *curr_a, t_n *target);
void	high_to_top(t_n **head, char prnt);
int		total_cost(t_n **s_a, t_n **s_b, t_n *curr, t_n *target);
void	do_command(t_n **s_a, t_n **s_b, t_n *to_push, int total);
void	do_command_second(t_n **s_a, t_n **s_b, t_n *to_push, int total);
void	both_ways(t_n **s_a, t_n **s_b, t_n *push, int yep);
void	find_closest_inverse(t_n *head_a, t_n *head_b);
void	min_to_top(t_n **head);
void	r_both(t_n **s_a, t_n **s_b, t_n *to_push, int *total);
void	rr_both(t_n **s_a, t_n **s_b, t_n *to_push, int *total);

//Command helpers
void	shift_stack(t_n *popped, int up);
int		stack_size(t_n *stack);
t_n		*fetch_last(t_n *stack);
void	final_sort(t_n **s_a, t_n **s_b);

//Commands
void	push(t_n **stack_pop, t_n **stack_push, char prnt);
void	pick_rotate(t_n **stack, int reverse, char prnt);
void	rev_rotate(t_n **stack, char prnt);
void	rotate(t_n **stack, char prnt);
void	swap(t_n **stack, char prnt);

#endif
