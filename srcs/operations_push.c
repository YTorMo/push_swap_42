/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:53:17 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 15:10:02 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_ab(t_stk **a, t_stk **b, int c)
{
	t_stk	*memo;

	memo = NULL;
	if (!(*b) && *a)
		ft_push_b_void(a, b, memo);
	else if (*a)
		ft_push_b_filled(a, b, memo);
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	ft_push_b_void(t_stk **a, t_stk **b, t_stk *memo)
{
	t_stk	*memo_2;

	memo_2 = NULL;
	*b = ft_new_copied_node(*a);
	memo_2 = *a;
	*a = (*a)->nxt;
	memo = (*a)->prv->prv;
	(*a)->prv->prv->nxt = *a;
	(*a)->prv = NULL;
	free(memo_2);
	(*a)->prv = memo;
	(*b)->prv = *b;
	(*b)->nxt = *b;
}

void	ft_push_b_filled(t_stk **a, t_stk **b, t_stk *memo)
{
	t_stk	*memo_2;

	memo_2 = NULL;
	memo = ft_new_copied_node(*a);
	memo->prv = (*b)->prv;
	memo->nxt = *b;
	(*b)->prv->nxt = memo;
	(*b)->prv = memo;
	*b = memo;
	memo = *a;
	*a = memo->nxt;
	(*a)->prv = memo->prv;
	memo->prv->nxt = *a;
	memo->nxt = NULL;
	memo->prv = NULL;
	memo->rl_pos = -1;
	free(memo);
	if ((*a)->rl_pos == -1)
		*a = NULL;
}
