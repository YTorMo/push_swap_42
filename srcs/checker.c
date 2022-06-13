/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:32:34 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 16:14:48 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stk	**a;
	t_stk	**b;

	argv++;
	argc--;
	a = malloc(sizeof(t_stk));
	b = malloc(sizeof(t_stk));
	if (!b || !a)
		return (0);
	ft_fill_stk(argv, argc, a);
	*b = NULL;
	ft_check_instructions(a, b);
	if (ft_check_sort(a, argc) && !(*b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stk(a, argc);
	free(a);
	free(b);
	return (0);
}
	//system("leaks -q checker");

void	ft_fill_stk(char **all_arg, int size, t_stk **a)
{
	t_stk	*stk;

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

static void	ft_check_instructions(t_stk **a, t_stk **b)
{
	char	*instruc;
	char	*end_l;

	instruc = get_next_line(0);
	while (instruc)
	{
		end_l = ft_strchr(instruc, '\n');
		if (end_l)
			*end_l = '\0';
		if (!ft_exec_instruc(instruc, a, b))
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		free(instruc);
		instruc = get_next_line(0);
	}
}

static int	ft_exec_instruc(char *instruc, t_stk **a, t_stk **b)
{
	if (!ft_strncmp(instruc, "sa", 4))
		ft_swap_ab(a, 0);
	else if (!ft_strncmp(instruc, "sb", 4))
		ft_swap_ab(b, 0);
	else if (!ft_strncmp(instruc, "ss", 4))
		ft_swap_s(a, b, 0);
	else if (!ft_strncmp(instruc, "pa", 4))
		ft_push_ab(b, a, 0);
	else if (!ft_strncmp(instruc, "pb", 4))
		ft_push_ab(a, b, 0);
	else if (!ft_strncmp(instruc, "ra", 4))
		ft_rotate_ab(a, 0);
	else if (!ft_strncmp(instruc, "rb", 4))
		ft_rotate_ab(b, 0);
	else if (!ft_exec_instruc2(instruc, a, b))
		return (0);
	return (1);
}

static int	ft_exec_instruc2(char *instruc, t_stk **a, t_stk **b)
{
	if (!ft_strncmp(instruc, "rr", 4))
		ft_rotate_r(a, b, 0);
	else if (!ft_strncmp(instruc, "rra", 4))
		ft_reverse_rotate_ab(a, 0);
	else if (!ft_strncmp(instruc, "rrb", 4))
		ft_reverse_rotate_ab(b, 0);
	else if (!ft_strncmp(instruc, "rrr", 4))
		ft_reverse_rotate_r(a, b, 0);
	else
		return (0);
	return (1);
}
