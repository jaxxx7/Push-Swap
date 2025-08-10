/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:09:53 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/09 17:22:22 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

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

int	ft_array_size(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

int	bits_number(t_stack **a)
{
	int	bits;
	int	value;

	bits = 0;
	value = (*a)->index;
	while (value >> bits)
		bits++;
	return (bits);
}
