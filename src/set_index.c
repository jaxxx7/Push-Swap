/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:45:45 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/10 13:32:12 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *array, int start, int end)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	i = start - 1;
	j = start;
	pivot = array[end];
	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	i++;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	return (i);
}

void	quick_sort(int *array, int start, int end)
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = partition(array, start, end);
	quick_sort(array, start, pivot -1);
	quick_sort(array, pivot + 1, end);
}

int	*fill_array(int *array, t_stack *stack_a)
{
	int		i;

	i = 0;
	array = malloc(sizeof(int) * ft_stack_size(stack_a));
	if (!array)
		return (0);
	while (stack_a)
	{
		array[i] = stack_a->value;
		stack_a = stack_a->next;
		i++;
	}
	quick_sort(array, 0, i - 1);
	return (array);
}

t_stack	*set_index(t_stack *stack_a)
{
	int		*array;
	int		i;

	array = NULL;
	array = fill_array(array, stack_a);
	while (stack_a)
	{
		i = 0;
		while (array[i] != stack_a->value)
			i++;
		stack_a->index = i;
		stack_a = stack_a->next;
	}
	free(array);
	return (stack_a);
}

/*
int	main()
{
	int	array[5] = {2, 4, 7, 1, 3};
	quick_sort(array, 0, 4);
	int	i = 0;
	while (i < 5)
	{
		printf("%i \n", array[i]);
		i++;
	}
}
	*/
