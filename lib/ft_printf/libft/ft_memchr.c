/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:11:53 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/06 23:00:50 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *)s;
	while (n--)
	{
		if (*dst == (unsigned char)c)
			return (dst);
		dst++;
	}
	return (0);
}
