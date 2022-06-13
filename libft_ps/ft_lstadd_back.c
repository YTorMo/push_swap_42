/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:42:31 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/05/23 14:34:37 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*memo;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			memo = ft_lstlast(*lst);
			memo->nxt = new;
		}
	}
}
