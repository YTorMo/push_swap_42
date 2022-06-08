/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:18:13 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/08 12:03:50 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	while (size-- && stk && a)
	{
		*stk = ft_new_node();
		(*stk)->num = ft_atoi((const char *)all_arg[size]);
		(*stk)->nxt = *stk;
		(*stk)->prv = *stk;
		ft_push_ab(stk, a, size, 0);
	}
	ft_rl_pos_sorted(a, max_size);
	ft_radix(a, max_size);
	free(stk);
	free(a);
}

//gcc main.c src/push_swap_init.c src/push_swap_utils.c src/operations_push.c libft/ft_atoi.c libft/ft_putstr_fd.c libft/ft_strlen.c && ./a.out 0 -2147483648 2147483647 5 -111111 111111 2589741 3345678

//gcc main.c src/push_swap_init.c src/push_swap_utils.c src/operations_push.c libft/ft_atoi.c libft/ft_putstr_fd.c libft/ft_strlen.c src/push_swap_rl_pos.c && ./a.out 0 -2147483648 2147483647 5 -111111 111111 2589741 3345678

// 3251486 0 12 -36528 96 57 -2 -75 -1 32165 100 -200 666