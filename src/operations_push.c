/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:53:17 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/07 16:52:22 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_ab(t_stk **a, t_stk **b, int max_size)
{
	t_stk		*memo;

	memo = NULL;
	if (!(*b) && *a)
		ft_push_b_void(a, b, memo, max_size);
	else if (*a)
		ft_push_b_filled(a, b, memo, max_size);
}

void	ft_push_b_void(t_stk **a, t_stk **b, t_stk *memo, int max_size)
{
	*b = ft_new_copied_node(*a);
	*a = (*a)->nxt;
	memo = (*a)->prv->prv;
	(*a)->prv->prv->nxt = *a;
	(*a)->prv = NULL;
	free((*a)->prv);
	(*a)->prv = memo;
	(*b)->prv = *b;
	(*b)->nxt = *b;
	(*b)->f_pos = max_size;
}

void	ft_push_b_filled(t_stk **a, t_stk **b, t_stk *memo, int max_size)
{
	t_stk	*memo_2;

	memo_2 = NULL;
	memo = ft_new_copied_node(*a);
	memo->prv = (*b)->prv;
	memo->nxt = *b;
	(*b)->prv->nxt = memo;
	(*b)->prv = memo;
	*b = memo;
	*a = (*a)->nxt;
	memo_2 = (*a)->prv->prv;
	(*a)->prv->prv->nxt = *a;
	(*a)->prv = NULL;
	free((*a)->prv);
	(*a)->prv = memo_2;
	(*b)->f_pos = max_size;
	if ((*a)->num == (*b)->num)
	{
		*a = NULL;
		free(*a);
	}
}
