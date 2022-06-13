/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:24:52 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 15:45:25 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (!ft_check_argv(argv, argc - 1))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		ft_fill_a_frst(argv, argc - 1);
	}
	return (0);
}
	//system("leaks -q push_swap");

int	ft_check_argv(char **argv, int size)
{
	if (!ft_check_only_int(argv, size))
		return (0);
	else if (!ft_check_size_int(argv, size))
		return (0);
	else if (!ft_check_dup_int(argv, size))
		return (0);
	return (1);
}

int	ft_check_only_int(char **argv, int size)
{
	int	i;
	int	j;

	j = 0;
	while (size > j)
	{
		i = 0;
		if (argv[j][0] == '-')
			i++;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_check_size_int(char **argv, int size)
{
	int	i;

	i = 0;
	while (size > i)
	{
		if (ft_atoi(argv[i]) > __INT_MAX__
			|| ft_atoi(argv[i]) < ((__INT_MAX__ * -1) - 1))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_dup_int(char **argv, int size)
{
	int	i;
	int	j;

	j = 0;
	while ((size - 1) > j)
	{
		i = j + 1;
		while (i < size)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
