/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:17:15 by mhachem           #+#    #+#             */
/*   Updated: 2025/06/10 12:18:43 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	append_node(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = new;
		return;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_stack	*init_stack(char **argv)
{
	int		i;
	int		value;
	t_stack	*stack;

	stack = NULL;
	i = 0;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		append_node(&stack, stack_new(value));
	}
}
