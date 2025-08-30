/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:54:06 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/30 12:31:17 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
		{
			if (!argv[i][j + 1])
				return (1);
			j++;
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_double(char **argv)
{
	int	i;
	int	j;
	int	val_i;
	int	val_j;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		val_i = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			val_j = ft_atoi(argv[j]);
			if (val_i == val_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int(char **argv)
{
	int		i;
	long	c;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		c = ft_atoi(argv[i]);
		if (c < INT_MIN || c > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

void	check_input(char **argv)
{
	char	**array;

	array = argv + 1;
	if (check_digit(array)
		|| check_double(array)
		|| check_int(array))
		print_error();
}

/*
int	main(int argc, char **argv)
{
	check_input(argc, argv);
} */