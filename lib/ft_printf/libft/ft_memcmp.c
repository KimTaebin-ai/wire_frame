/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:11:57 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/06 23:00:54 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*pt1 = (unsigned char *)s1;
	const unsigned char	*pt2 = (unsigned char *)s2;

	while (n--)
	{
		if (*pt1 != *pt2)
			return (*pt1 - *pt2);
		pt1++;
		pt2++;
	}
	return (0);
}
