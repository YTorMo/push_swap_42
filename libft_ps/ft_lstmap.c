/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:48:27 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/05/23 14:33:59 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_memo;

	new_lst = NULL;
	while (lst)
	{
		new_memo = ft_lstnew(f(lst->content));
		if (!new_memo)
		{
			del(new_lst);
			free(new_lst);
			free(new_memo);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_memo);
		lst = lst->nxt;
	}
	return (new_lst);
}
