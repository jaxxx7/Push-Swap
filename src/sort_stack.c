/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:58:07 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/03 14:54:17 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_stack **stack_a)
{
	int		max_elem;
	t_stack	*element;
	int		max_bits;

	element = *stack_a;
	max_elem = element->index;
	element = element->next;
	while (element)
	{
		if (element->index > max_elem)
		{
			max_elem = element->index;
		}
		element = element->next;
	}
	max_bits = 0;
	while ((max_elem >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

t_stack	*find_highest(t_stack *a)
{
	t_stack	*highest;

	highest = a;
	while (a)
	{
		if (a->value > highest->value)
			highest = a;
		a = a->next;
	}
	return (highest);
}

void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int		max_bit;
	int		i;
	int		j;
	int		stack_size;

	if (ft_stack_size(*a) == 3)
		tiny_sort(a);
	max_bit = max_bits(a);
	stack_size = ft_stack_size(*a);
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < stack_size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
