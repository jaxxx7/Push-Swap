/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:40:01 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/03 17:15:46 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		split;

	split = 0;
	if ((argc == 2 && ft_strlen(argv[1]) == 1 && !ft_isdigit(argv[1][0]))
		|| argc == 1)
		return (0);
	if (argc == 2 && ft_strlen(argv[1]) > 1)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_array_size(argv) + 1;
		split = 1;
	}
	check_input(argc, argv);
	stack_b = NULL;
	stack_a = init_stack(argv, split);
	set_index(stack_a);
	radix_sort(&stack_a, &stack_b);
	/* t_stack *tmp = stack_a;
	while (tmp)
	{
		printf("value = %d, index = %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	} */
	free_stack(stack_a);
	free_stack(stack_b);
	if (split)
		ft_free(argv);
}
