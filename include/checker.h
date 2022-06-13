/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:33:06 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 16:14:21 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

typedef struct s_stk
{
	int				num;
	int				rl_pos;
	struct s_stk	*nxt;
	struct s_stk	*prv;
}					t_stk;

t_stk			**ft_fill_a(char **all_arg, int max_size);
static void		ft_check_instructions(t_stk **a, t_stk **b);
int				ft_check_sort(t_stk **a, int stk_size);
t_stk			*ft_new_node(void);
static int		ft_exec_instruc(char *instruc, t_stk **a, t_stk **b);
static int		ft_exec_instruc2(char *instruc, t_stk **a, t_stk **b);
void			ft_swap_ab(t_stk **stk, int c);
void			ft_swap_s(t_stk **swap1, t_stk **swap2, int c);
void			ft_push_ab(t_stk **a, t_stk **b, int c);
void			ft_rotate_ab(t_stk **stk, int c);
void			ft_rotate_r(t_stk **stk1, t_stk **stk2, int c);
void			ft_reverse_rotate_ab(t_stk **stk, int c);
void			ft_reverse_rotate_r(t_stk **stk1, t_stk **stk2, int c);
void			ft_fill_stk(char **all_arg, int size, t_stk **a);
void			ft_free_stk(t_stk **stk, int size);

#endif