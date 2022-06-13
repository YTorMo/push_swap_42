/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_four_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:12:12 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 14:59:52 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_stk **a)
{
	t_stk	**b;

	b = malloc(sizeof(t_stk));
	if (b)
	{
		*b = NULL;
		ft_push_first_of_four(a, b);
		ft_sort_three_five(a);
		ft_push_ab(b, a, 'a');
		free(b);
	}
}

void	ft_push_first_of_four(t_stk **a, t_stk **b)
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
	ft_push_ab(a, b, 'b');
}
