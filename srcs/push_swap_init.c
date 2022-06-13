/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:18:13 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 15:20:57 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_a_frst(char **all_arg, int max_size)
{
	t_stk	*stk;
	t_stk	**a;

	a = malloc(sizeof(t_stk));
	stk = NULL;
	if (a)
	{
		ft_fill_stk(all_arg, max_size, a, stk);
		ft_rl_pos_sorted(a, max_size);
		ft_sorter_select(a, max_size);
		ft_free_stk(a, max_size);
		free(a);
	}
}

void	ft_fill_stk(char **all_arg, int size, t_stk **a, t_stk *stk)
{
	while (size--)
	{
		if (!(*a))
		{
			*a = ft_new_node();
			(*a)->num = ft_atoi((const char *)all_arg[size]);
			(*a)->nxt = (*a);
			(*a)->prv = (*a);
		}
		else
		{
			stk = ft_new_node();
			stk->num = ft_atoi((const char *)all_arg[size]);
			stk->prv = (*a)->prv;
			stk->nxt = *a;
			(*a)->prv->nxt = stk;
			(*a)->prv = stk;
			*a = stk;
		}
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
	{
		if (!ft_check_sort(a, max_size))
			ft_sort_three(a);
	}
	else if (max_size == 4)
	{
		if (!ft_check_sort(a, max_size))
			ft_sort_four(a);
	}
	else if (max_size == 5)
	{
		if (!ft_check_sort(a, max_size))
			ft_sort_five(a);
	}
	else if (max_size > 5)
	{
		if (!ft_check_sort(a, max_size))
			ft_radix(a, max_size);
	}
}
