/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:21:08 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/04 18:22:58 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*node;

	node = 0;
	while (lst)
	{
		newnode = ft_lstnew((*f)(lst->content));
		if (newnode == 0)
		{
			ft_lstclear(&node, del);
			return (0);
		}
		ft_lstadd_back(&node, newnode);
		lst = lst->next;
	}
	return (node);
}
