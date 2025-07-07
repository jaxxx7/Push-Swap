/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:58:07 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/07 15:23:34 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_stack_a(t_stack **a, t_stack **b, int i)
{
	int	j;
	int	stack_size;

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
}

void	handle_stack_b(t_stack **a, t_stack **b, int i)
{
	int	b_size;
	int	j;

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
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bit;
	int	i;

	max_bit = max_bits(a);
	i = 0;
	while (i < max_bit)
	{
		handle_stack_a(a, b, i);
		handle_stack_b(a, b, i);
		i++;
	}
	while (ft_stack_size(*b) > 0)
		pa(a, b);
}
