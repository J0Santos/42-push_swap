/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:15:12 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 18:01:20 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*s;

	if (!lst || !f)
		return (0);
	p = ft_lstnew((*f)(lst->content));
	s = p;
	while (lst->next)
	{
		lst = lst->next;
		p->next = ft_lstnew((*f)(lst->content));
		if (!p)
		{
			ft_lstdelone(p->next, del);
			return (0);
		}
		p = p->next;
	}
	return (s);
}
