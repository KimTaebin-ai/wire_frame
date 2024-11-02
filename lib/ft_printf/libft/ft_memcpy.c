/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:12:01 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/06 22:55:15 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*_dest;
	const unsigned char	*_src;

	_dest = (unsigned char *)dest;
	_src = (const unsigned char *)src;
	if (_dest == _src)
		return (dest);
	while (n--)
	{
		*_dest = *_src;
		_dest++;
		_src++;
	}
	return (dest);
}
