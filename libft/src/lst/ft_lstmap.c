/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:39:57 by rbourgea          #+#    #+#             */
/*   Updated: 2023/12/19 12:39:58 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*next;

	if (!lst)
		return ((void *)0);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return ((void *)0);
	next = new;
	tmp = lst->next;
	while (tmp)
	{
		next->next = ft_lstnew((*f)(tmp->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return ((void *)0);
		}
		next = next->next;
		tmp = tmp->next;
	}
	return (new);
}
