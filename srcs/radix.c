/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:23:49 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 10:54:49 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix(t_stk **a, int max_size)
{
	int		bit_pos;
	t_stk	**b;

	bit_pos = 0;
	b = malloc(sizeof(t_stk));
	if (b)
	{
		while (!ft_check_sort(a, max_size))
		{
			ft_stk_mv_radix(a, b, max_size, bit_pos);
			while ((*b))
				ft_push_ab(b, a, 'a');
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
	*b = NULL;
	while (size)
	{
		num = (*a)->rl_pos;
		if ((num >> bit_pos) & 1)
			ft_rotate_ab(a, 'a');
		else
			ft_push_ab(a, b, 'b');
		size--;
	}
}
