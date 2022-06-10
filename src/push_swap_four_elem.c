/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_four_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:12:12 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/10 09:41:37 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_four(t_stk **a, int max_size)
{
	t_stk	**b;

	b = malloc(sizeof(t_stk));
	if (b)
	{
		*b = NULL;
		ft_push_first_of_four(a, b, max_size);
		ft_sort_three_five(a, 3);
		ft_push_ab(b, a, max_size, 'a');
		free(b);
	}
}

void	ft_push_first_of_four(t_stk **a, t_stk **b, int max_size)
{
	int	i;

	i = ft_lookfor_pos(a, 0);
	if (i == 3)
		ft_reverse_rotate_ab(a, 'a');
	else
	{
		while ((*a)->rl_pos != 0)
			ft_rotate_ab(a, 'a');
	}
	ft_push_ab(a, b, max_size, 'b');
}
