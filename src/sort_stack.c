/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:58:07 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/05 15:45:48 by mhachem          ###   ########.fr       */
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

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b);
		else
			ra(a);
	}
	tiny_sort(a);
	if ((*b)->index < (*b)->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
}
int	bits_number(t_stack **a)
{
	int	bits;
	int	i;

	i = 0;
	bits = (*a)->index;
	while ((bits >> 0) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bit;
	int	i;
	int	j;
	int	stack_size;
	int	b_size;

	max_bit = max_bits(a);
	i = 0;
	while (i < max_bit)
	{
		stack_size = ft_stack_size(*a);
		j = 0;
		while (j < stack_size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		b_size = ft_stack_size(*b);
		j = 0;
		while (j < b_size)
		{
			if ((((*b)->index >> (i + 1)) & 1) == 1)
				pa(a, b);
			else
				rb(b);
			j++;
		}
		i++;
	}
}
