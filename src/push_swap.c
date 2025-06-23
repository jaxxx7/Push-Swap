/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:40:01 by mhachem           #+#    #+#             */
/*   Updated: 2025/06/21 11:57:10 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		split;

	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strlen(argv[1]) > 1)
	{
		argv = ft_split(argv[1], ' ');
		split = 1;
	}
	check_input(argc, argv);
	stack_b = NULL;
	stack_a = init_stack(argv, split);
	set_index(stack_a);
	radix_sort(&stack_a, &stack_b);
	/* while (stack_a)
	{
		printf("value = %d, index = %d\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	} */
	if (split)
		ft_free(argv);
}
