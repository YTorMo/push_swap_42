/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rl_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:31:47 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/10 14:10:51 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rl_pos_sorted(t_stk	**stk, int max_size)
{
	int	*pos;
	int	i;
	int	j;

	pos = ft_sorted_numbers(stk, max_size);
	i = 0;
	while (i < max_size)
	{
		j = 0;
		while ((*stk)->num != pos[j])
			j++;
		(*stk)->rl_pos = j;
		*stk = ((*stk)->nxt);
		i++;
	}
	free(pos);
}

int	*ft_sorted_numbers(t_stk	**stk, int max_size)
{
	int		memo;
	int		memo_2;
	int		*arr_sort;
	int		i;
	int		j;

	i = 0;
	arr_sort = ft_stk_to_array(stk, max_size);
	while (i < (max_size - 1))
	{
		j = 0 + i;
		memo = arr_sort[j];
		while (j++ < max_size)
		{
			if (arr_sort[j - 1] < memo)
			{
				memo_2 = memo;
				memo = arr_sort[j - 1];
				arr_sort[j - 1] = memo_2;
			}
		}
		arr_sort[i] = memo;
		i++;
	}
	return (arr_sort);
}

int	*ft_stk_to_array(t_stk	**stk, int max_size)
{
	int	*arr_stk;
	int	i;

	arr_stk = malloc(sizeof(int) * max_size);
	i = 0;
	if (!arr_stk)
		return (0);
	while (max_size--)
	{
		arr_stk[i] = (*stk)->num;
		*stk = (*stk)->nxt;
		i++;
	}
	return (arr_stk);
}
