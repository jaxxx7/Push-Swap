/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:40:04 by mhachem           #+#    #+#             */
/*   Updated: 2025/06/09 17:29:46 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct	s_stack
{
	int		value;
	int		index;
	struct	s_stack	*next;
}				t_stack;
// check_input.c
void	check_input(int argc, char **argv);
int		check_int(int argc, char **argv);
int		check_double(int argc, char **argv);
int		check_digit(int argc, char **argv);
// prout.c
int		print_error(void);
int		count_args(char **args);
// init_stack.c
t_stack	*init_stack(char **argv);

#endif