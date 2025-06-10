/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:40:01 by mhachem           #+#    #+#             */
/*   Updated: 2025/06/10 12:26:04 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if(argc == 2)
		argv = ft_split(argv[1], ' ');
	check_input(argc, argv);
	stack_b = NULL;
	stack_a = init_stack(argv);
	while (stack_a)
	{
		printf("%i \n", stack_a->value);
		stack_a = stack_a->next;
	}
}
