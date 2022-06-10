/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:49:42 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/10 13:54:42 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	*is_sort;
	int	i;

	i = 0;
	is_sort = malloc(sizeof(int) * stk_size);
	if (!is_sort)
		return (0);
	while (stk_size > i)
	{
		is_sort[i] = (*a)->num;
		*a = (*a)->nxt;
		i++;
	}
	i = 1;
	while (stk_size > i)
	{
		if (is_sort[i - 1] > is_sort[i])
			return (0);
		i++;
	}
	free(is_sort);
	return (1);
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
