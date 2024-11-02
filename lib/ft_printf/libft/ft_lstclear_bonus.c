/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:20:20 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/04 17:24:54 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;

	if (*lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		now = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = now;
	}
}
