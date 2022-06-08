/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:50:19 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/05/31 12:58:54 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_ab(t_stk **stk)
{
	if ((*stk))
		*stk = (*stk)->nxt;
}

void	ft_rotate_r(t_stk **stk1, t_stk **stk2)
{
	ft_rotate_ab(stk1);
	ft_rotate_ab(stk2);
}

void	ft_reverse_rotate_ab(t_stk **stk)
{
	if ((*stk))
		*stk = (*stk)->prv;
}

void	ft_reverse_rotate_r(t_stk **stk1, t_stk **stk2)
{
	ft_reverse_rotate_ab(stk1);
	ft_reverse_rotate_ab(stk2);
}
