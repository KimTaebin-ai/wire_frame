/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:12:04 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/06 23:01:36 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*_dest;
	const unsigned char	*_src = (const unsigned char *)src;

	i = 0;
	_dest = (unsigned char *)dest;
	if (dest > src)
	{
		while (n--)
			_dest[n] = _src[n];
	}
	if (dest < src)
	{
		while (n--)
		{
			_dest[i] = _src[i];
			i++;
		}
	}
	return (dest);
}
