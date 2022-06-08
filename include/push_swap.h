/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:21:42 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/08 10:32:18 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stk
{
	int				num;
	int				rl_pos;
	struct s_stk	*nxt;
	struct s_stk	*prv;
}					t_stk;

void				ft_swap_ab(t_stk **stk, int c);
void				ft_swap_s(t_stk **swap1, t_stk **swap2);
void				ft_push_ab(t_stk **a, t_stk **b, int max_size, int c);
void				ft_push_b_void(t_stk **a, t_stk **b, t_stk *memo,
						int max_size);
void				ft_push_b_filled(t_stk **a, t_stk **b, t_stk *memo,
						int max_size);
void				ft_rotate_ab(t_stk **stk, int c);
void				ft_rotate_r(t_stk **stk1, t_stk **stk2);
void				ft_reverse_rotate_ab(t_stk **stk, int c);
void				ft_reverse_rotate_r(t_stk **stk1, t_stk **stk2);
int					ft_max_nbr_length(int max_size);
int					ft_check_sort(t_stk **a, int stk_size);
t_stk				*ft_new_copied_node(t_stk *to_copy_node);
void				ft_fill_a_frst(char **all_arg, int max_size);
t_stk				*ft_new_node(void);
void				ft_rl_pos_sorted(t_stk	**stk, int max_size);
int					*ft_sorted_numbers(t_stk	**stk, int max_size);
int					*ft_stk_to_array(t_stk	**stk, int max_size);
void				ft_radix(t_stk **a, int max_size);
void				ft_stk_mv_radix(t_stk **a, t_stk **b, int max_size,
						int bit_pos);
#endif