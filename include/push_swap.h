/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:21:42 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/13 16:08:33 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stk
{
	int				num;
	int				rl_pos;
	struct s_stk	*nxt;
	struct s_stk	*prv;
}					t_stk;

void				ft_swap_ab(t_stk **stk, int c);
void				ft_swap_s(t_stk **swap1, t_stk **swap2, int c);
void				ft_push_ab(t_stk **a, t_stk **b, int c);
void				ft_push_b_void(t_stk **a, t_stk **b, t_stk *memo);
void				ft_push_b_filled(t_stk **a, t_stk **b, t_stk *memo);
void				ft_rotate_ab(t_stk **stk, int c);
void				ft_rotate_r(t_stk **stk1, t_stk **stk2, int c);
void				ft_reverse_rotate_ab(t_stk **stk, int c);
void				ft_reverse_rotate_r(t_stk **stk1, t_stk **stk2, int c);
int					ft_max_nbr_length(int max_size);
int					ft_check_sort(t_stk **a, int stk_size);
t_stk				*ft_new_copied_node(t_stk *to_copy_node);
void				ft_fill_a_frst(char **all_arg, int max_size);
void				ft_sorter_select(t_stk **a, int max_size);
void				ft_fill_stk(char **all_arg, int size, t_stk **a,
						t_stk *stk);
t_stk				*ft_new_node(void);
void				ft_rl_pos_sorted(t_stk	**stk, int max_size);
int					*ft_sorted_numbers(t_stk	**stk, int max_size);
int					*ft_stk_to_array(t_stk	**stk, int max_size);
int					ft_check_argv(char **argv, int size);
int					ft_check_only_int(char **argv, int size);
int					ft_check_size_int(char **argv, int size);
int					ft_check_dup_int(char **argv, int size);
void				ft_radix(t_stk **a, int max_size);
void				ft_stk_mv_radix(t_stk **a, t_stk **b, int max_size,
						int bit_pos);
void				ft_sort_three(t_stk **a);
void				ft_sort_five(t_stk **a);
int					ft_lookfor_pos(t_stk **a, int pos);
void				ft_push_first(t_stk **a, t_stk **b);
void				ft_push_last(t_stk **a, t_stk **b);
void				ft_sort_three_five(t_stk **a);
void				ft_sort_four(t_stk **a);
void				ft_push_first_of_four(t_stk **a, t_stk **b);
void				ft_free_stk(t_stk **stk, int size);
#endif