/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_five_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:06 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/10 08:45:13 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_five(t_stk **a, int max_size)
{
	t_stk	**b;

	b = malloc(sizeof(t_stk));
	if (b)
	{
		*b = NULL;
		ft_push_first(a, b, i, max_size);
		ft_push_last(a, b, i, max_size);
		ft_sort_three(a, 3);
		ft_push_ab(b, a, max_size, 'a');
		ft_rotate_ab(a, 'a');
		ft_push_ab(b, a, max_size, 'a');
		free(b);
	}
}

void	ft_push_first(t_stk **a, t_stk **b, int max_size)
{
	int	i;

	i = ft_lookfor_pos(a, 0);
	if (i <= 2)
	{
		while ((*a)->rlo_pos != 0)
			ft_rotate_ab(a, 'a');
	}
	else
	{
		while ((*a)->rlo_pos != 0)
			ft_reverse_rotate_ab(a, 'a');
	}
	ft_push_ab(a, b, max_size, 'b');
}

void	ft_push_last(t_stk **a, t_stk **b, int max_size)
{
	int	i;

	i = ft_lookfor_pos(a, 4);
	if (i == 3)
	{
		while ((*a)->rlo_pos != 4)
			ft_reverse_rotate_ab(a, 'a');
	}
	else
	{
		while ((*a)->rlo_pos != 4)
			ft_rotate_ab(a, 'a');
	}
	ft_push_ab(a, b, max_size, 'b');
}

int	ft_lookfor_pos(t_stk **a, int pos)
{
	t_stk	*memo;
	int		i;

	i = 0;
	memo = *a;
	while (memo->rl_pos != pos)
	{
		i++;
		memo = memo->nxt;
	}
	return (i);
}
