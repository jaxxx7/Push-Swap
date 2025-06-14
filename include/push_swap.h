/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:40:04 by mhachem           #+#    #+#             */
/*   Updated: 2025/06/11 16:18:31 by mhachem          ###   ########.fr       */
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
void	check_input(int argc, char **argv);
int		check_int(char **argv);
int		check_double(char **argv);
int		check_digit(char **argv);
// prout.c
int		print_error(void);
int		count_args(char **args);
// init_stack.c
t_stack	*init_stack(char **argv, int split);
// set_index.c
t_stack	set_index(t_stack *stack_a, t_stack *stack_b);

#endif