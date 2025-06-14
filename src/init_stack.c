/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:17:15 by mhachem           #+#    #+#             */
/*   Updated: 2025/06/11 12:56:54 by mhachem          ###   ########.fr       */
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
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_stack	*init_stack(char **argv, int split)
{
	int		i;
	int		value;
	t_stack	*stack;
	t_stack	*new_node;

	stack = NULL;
	if (split)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		new_node = stack_new(value);
		if (!new_node)
			return (NULL);
		append_node(&stack, new_node);
		i++;
	}
	return (stack);
}
