/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:49:42 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 16:58:02 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_max_nbr_length(int max_size)
{
	int		i;

	i = 0;
	while (max_size > 0)
	{
		max_size /= 10;
		i++;
	}
	return (i);
}

int	ft_check_sort(t_stk **a, int stk_size)
{
	t_stk	*is_sort;
	int		i;
	int		sort;
	int		frst;

	i = 1;
	sort = 1;
	is_sort = *a;
	frst = is_sort->num;
	*a = (*a)->nxt;
	while (stk_size > i)
	{
		if (((is_sort)->num) > ((*a)->num))
			sort = 0;
		is_sort = *a;
		*a = (*a)->nxt;
		i++;
	}
	while ((*a)->num != frst)
		*a = (*a)->prv;
	return (sort);
}

t_stk	*ft_new_copied_node(t_stk *to_copy_node)
{
	t_stk	*new_node;

	new_node = malloc(sizeof(t_stk));
	if (!new_node)
		return (NULL);
	new_node->num = to_copy_node->num;
	new_node->rl_pos = to_copy_node->rl_pos;
	new_node->prv = to_copy_node->prv;
	new_node->nxt = to_copy_node->nxt;
	return (new_node);
}

t_stk	*ft_new_node(void)
{
	t_stk	*new_node;

	new_node = malloc(sizeof(t_stk));
	if (!new_node)
		return (NULL);
	return (new_node);
}

void	ft_free_stk(t_stk **stk, int size)
{
	t_stk	*memo;

	memo = *stk;
	*stk = (*stk)->nxt;
	while (size--)
	{
		free(memo);
		memo = *stk;
		*stk = (*stk)->nxt;
	}
}
