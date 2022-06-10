/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_five_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:06 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/10 08:21:14 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_five(t_stk **a, int max_size)
{
	t_stk	**b;
	int		i;

	b = malloc (sizeof(t_stk));
	memo = malloc (sizeof(t_stk));
	i = 0;
	if (b && memo)
	{
		*b = NULL;
		i = ft_lookfor_pos(a, 0);
		ft_lookfor_and_sort(a, b, i, max_size);
		free(memo);
		free(b);
	}
}

void	ft_lookfor_and_sort(t_stk **a, t_stk **b, int i, int max_size)
{
	if (i == 0)
		ft_push_ab(a, b, max_size, 'b');
	else if (i <= 2)
	{
		while ((*a)->rlo_pos !=0)
	}
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
