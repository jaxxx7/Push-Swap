/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:45:45 by mhachem           #+#    #+#             */
/*   Updated: 2025/06/11 16:44:08 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	sort_array(int *array)
{
	
}

t_stack	set_index(t_stack *stack_a, t_stack *stack_b)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * ft_stack_size(stack_a));
	i = 0;
	while (stack_a)
	{
		array[i] = stack_a->value;
		// printf("%i \n", array[i]);
		stack_a = stack_a->next;
		i++;
	}
	sort_array(array);
}
