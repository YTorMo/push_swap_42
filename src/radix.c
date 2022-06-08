/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:23:49 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/08 09:26:13 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_radix(t_stk **a, int max_size)
{
	int		max_iter;
	int		max_num;
	int		bit_pos;
	t_stk	**b;

	max_num = max_size - 1;
	max_iter = 0;
	bit_pos = 0;
	b = malloc(sizeof(t_stk));
 	if (b)
	{
		while ((max_num >> max_iter) != 0)
			++max_iter;
		while (/* bit_pos < max_iter */ !ft_check_sort(a, max_size))
		{
			ft_stk_mv_radix(a, b, max_size, bit_pos);
			while ((*b))
			{
				ft_push_ab(b, a, max_size);
				ft_putstr_fd("pa\n", 1);
			}
			bit_pos++;
		}
		free(b);
	}
}

void	ft_stk_mv_radix(t_stk **a, t_stk **b, int max_size, int bit_pos)
{
	int	size;
	int	num;

	size = max_size;
	while (size)
	{
		num = (*a)->rl_pos;
		if ((num >> bit_pos) & 1)
		{
			ft_rotate_ab(a);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			ft_push_ab(a, b, max_size);
			ft_putstr_fd("pb\n", 1);
		}
		size--;
	}
}
