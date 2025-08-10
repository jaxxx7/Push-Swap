/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:40:01 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/09 17:16:30 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	check_input(argv);
	stack_b = NULL;
	stack_a = init_stack(argv);
	set_index(stack_a);
	radix_sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
