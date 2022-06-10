/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:18:13 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/10 11:35:58 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_a_frst(char **all_arg, int max_size)
{
	int		size;
	int		i;
	t_stk	**stk;
	t_stk	**a;

	size = max_size;
	i = 0;
	stk = malloc(sizeof(t_stk));
	a = malloc(sizeof(t_stk));
	if (a && stk)
	{
		while (size--)
		{
			*stk = ft_new_node();
			(*stk)->num = ft_atoi((const char *)all_arg[size]);
			(*stk)->nxt = *stk;
			(*stk)->prv = *stk;
			ft_push_ab(stk, a, size);
		}
		ft_rl_pos_sorted(a, max_size);
		ft_sorter_select(a, max_size);
		free(stk);
		free(a);
	}
}

void	ft_sorter_select(t_stk **a, int max_size)
{
	if (max_size == 2)
	{
		if (!ft_check_sort(a, max_size))
			ft_swap_ab(a, 'a');
	}
	else if (max_size == 3)
		ft_sort_three(a);
	else if (max_size == 4)
		ft_sort_four(a);
	else if (max_size == 5)
		ft_sort_five(a);
	else if (max_size > 5)
		ft_radix(a, max_size);
}
