/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:06:38 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 17:06:20 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stk **a)
{
	if ((*a)->rl_pos == 1)
	{
		if ((*a)->nxt->rl_pos == 0)
			ft_swap_ab(a, 'a');
		else
			ft_reverse_rotate_ab(a, 'a');
	}
	else if ((*a)->rl_pos == 2)
	{
		if ((*a)->nxt->rl_pos == 0)
			ft_rotate_ab(a, 'a');
		else
		{
			ft_swap_ab(a, 'a');
			ft_reverse_rotate_ab(a, 'a');
		}
	}
	else if ((*a)->rl_pos == 0)
	{
		ft_swap_ab(a, 'a');
		ft_rotate_ab(a, 'a');
	}
}
