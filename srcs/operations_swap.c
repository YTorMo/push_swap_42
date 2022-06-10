/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:26:10 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/10 17:40:53 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_ab(t_stk **stk, int c)
{
	t_stk	*memo;
	t_stk	*memo_2;
	t_stk	*memo_3;

	memo = NULL;
	if ((*stk) && (*stk)->nxt)
	{
		memo = *stk;
		memo_2 = (*stk)->nxt;
		memo_3 = (*stk)->prv;
		memo->prv = memo_2;
		memo->nxt = memo_2->nxt;
		memo_2->nxt = memo;
		memo_2->prv = memo_3;
		memo->nxt->prv = memo;
		memo_3->nxt = memo_2;
		*stk = memo_2;
		if (c == 'a')
			ft_putstr_fd("sa\n", 1);
		else if (c == 'b')
			ft_putstr_fd("sb\n", 1);
	}
}

void	ft_swap_s(t_stk **swap1, t_stk **swap2, int c)
{
	ft_swap_ab(swap1, 0);
	ft_swap_ab(swap2, 0);
	if (c == 's')
		ft_putstr_fd("ss\n", 1);
}
