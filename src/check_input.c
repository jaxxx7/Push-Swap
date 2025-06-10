/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:54:06 by mhachem           #+#    #+#             */
/*   Updated: 2025/06/10 12:46:22 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
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

int	check_double(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int(int argc, char **argv)
{
	int		i;
	long	c;

	i = 0;
	while (argv[i])
	{
		c = ft_atoi(argv[i]);
		if (c < INT_MIN || c > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

void	check_input(int argc, char **argv)
{
	int		len;
	char	**array;

	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		len = count_args(argv);
	}
	else
	{
		array = argv + 1;
		len = argc;
	}
	if (check_digit(len, array)
		|| check_double(len, array)
		|| check_int(len, array))
	{
		if (argc == 2)
			ft_free(array);
		print_error();
	}
}
/*
int	main(int argc, char **argv)
{
	check_input(argc, argv);
} */