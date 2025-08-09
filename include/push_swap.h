/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:40:04 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/09 14:58:20 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;
// check_input.c
void	check_input(char **argv);
int		check_int(char **argv);
int		check_double(char **argv);
int		check_digit(char **argv);
// utils.c
int		print_error(void);
int		count_args(char **args);
int		ft_stack_size(t_stack *lst);
int		ft_array_size(char **array);
int		bits_number(t_stack **a);
// mini_sort.c
t_stack	*find_highest(t_stack *a);
void	tiny_sort(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
int		max_bits(t_stack **stack_a);
// init_stack.c
t_stack	*init_stack(char **argv);
// set_index.c
int		partition(int *array, int start, int end);
void	quick_sort(int *array, int start, int end);
t_stack	*set_index(t_stack *stack_a);
// operations
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **push);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
// wrappers
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
// sort_stack.c
void	radix_sort(t_stack **a, t_stack **b);
// free_stack.c
void	free_stack(t_stack *stack);
#endif