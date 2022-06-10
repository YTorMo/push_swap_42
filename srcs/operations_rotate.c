/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:50:19 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/10 17:50:35 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_ab(t_stk **stk, int c)
{
	if ((*stk))
		*stk = (*stk)->nxt;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	ft_rotate_r(t_stk **stk1, t_stk **stk2, int c)
{
	ft_rotate_ab(stk1, 0);
	ft_rotate_ab(stk2, 0);
	if (c == 'r')
		ft_putstr_fd("rr\n", 1);
}

void	ft_reverse_rotate_ab(t_stk **stk, int c)
{
	if ((*stk))
		*stk = (*stk)->prv;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	ft_reverse_rotate_r(t_stk **stk1, t_stk **stk2, int c)
{
	ft_reverse_rotate_ab(stk1, 0);
	ft_reverse_rotate_ab(stk2, 0);
	if (c == 'r')
		ft_putstr_fd("rrr\n", 1);
}
