/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:32:34 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/10 18:20:20 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stk	**a;
	t_stk	**b;

	argv++;
	argc--;
	a = ft_fill_a_frst(argv, argc);
	b = malloc(sizeof(t_stk));
	if (!b)
		return (0);
	*b = NULL;
	ft_check_instructions(a, b);
	if (ft_check_sort(a, argc) && !(*b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(a);
	free(b);
	return (0);
}

t_stk	**ft_fill_a_frst(char **all_arg, int max_size)
{
	int		size;
	int		i;
	t_stk	**stk;
	t_stk	**a;

	size = max_size;
	i = 0;
	stk = malloc(sizeof(t_stk));
	a = malloc(sizeof(t_stk));
	if (!a || !stk)
		return (NULL);
	while (size--)
	{
		*stk = ft_new_node();
		(*stk)->num = ft_atoi((const char *)all_arg[size]);
		(*stk)->nxt = *stk;
		(*stk)->prv = *stk;
		ft_push_ab(stk, a, size);
	}
	free(stk);
	return (a);
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
