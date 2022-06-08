/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests_rl_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:58:51 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/08 11:00:01 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stk	*test;
	t_stk	*test_2;
	t_stk	*test_3;
	t_stk	*test_4;
	t_stk	*test_5;
	t_stk	*test_6;
	t_stk	*test_7;
	t_stk	*test_8;
	t_stk	**a;
	t_stk	**b;
	int		j;

	j = 0;
	test = malloc(sizeof(t_stk));
	if (!test)
		return (0);
	test_2 = malloc(sizeof(t_stk));
	if (!test_2)
		return (0);
	test_3 = malloc(sizeof(t_stk));
	if (!test_3)
		return (0);
	test_4 = malloc(sizeof(t_stk));
	if (!test_4)
		return (0);
	test_5 = malloc(sizeof(t_stk));
	if (!test_5)
		return (0);
	test_6 = malloc(sizeof(t_stk));
	if (!test_6)
		return (0);
	test_7 = malloc(sizeof(t_stk));
	if (!test_7)
		return (0);
	test_8 = malloc(sizeof(t_stk));
	if (!test_8)
		return (0);
	a = malloc(sizeof(t_stk));
	if (!a)
		return (0);
	b = malloc(sizeof(t_stk));
	if (!b)
		return (0);
	test->num = 0;
	test->nxt = test_2;
	test->prv = test_8;
	test->rl_pos = 0;
	test_2->num = -2147483648;
	test_2->nxt = test_3;
	test_2->prv = test;
	test_2->rl_pos = 1;
	test_3->num = 2147483647;
	test_3->nxt = test_4;
	test_3->prv = test_2;
	test_3->rl_pos = 2;
	test_4->num = 5;
	test_4->nxt = test_5;
	test_4->prv = test_3;
	test_4->rl_pos = 3;
	//-------------------------
	test_5->num = -111111;
	test_5->nxt = test_6;
	test_5->prv = test_4;
	test_5->rl_pos = 4;
	test_6->num = 111111;
	test_6->nxt = test_7;
	test_6->prv = test_5;
	test_6->rl_pos = 5;
	test_7->num = 2589741;
	test_7->nxt = test_8;
	test_7->prv = test_6;
	test_7->rl_pos = 6;
	test_8->num = 3345678;
	test_8->nxt = test;
	test_8->prv = test_7;
	test_8->rl_pos = 7;
	//-------------------------
	*a = test;
	*b = NULL;
	ft_rl_pos_sorted(a, 8);
	j = 0;
	while (j < 8)
	{
		printf("NUM:		%i\n", (*a)->rl_pos);
		*a = (*a)->nxt;
		j++;
	}
	return (0);
}

//gcc main_tests_rl_pos.c src/push_swap_rl_pos.c && ./a.out
// 0 -2147483648 2147483647 5 -111111 111111 2589741 3345678 