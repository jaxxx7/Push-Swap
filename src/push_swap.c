/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:40:01 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/07 15:52:42 by mhachem          ###   ########.fr       */
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
	if (ft_stack_size(stack_a) == 3)
		tiny_sort(&stack_a);
	else if (ft_stack_size(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	/*t_stack *tmp = stack_a;
	while (tmp)
	{
		printf("value = %d, index = %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	} */
	free_stack(stack_a);
	free_stack(stack_b);
}
