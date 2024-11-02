/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:12:14 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/06 22:59:55 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;

	i = 0;
	dest_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (size <= dest_l)
		return (size + src_l);
	while (src[i] && dest_l + i < size - 1)
	{
		dst[dest_l + i] = src[i];
		i++;
	}
	dst[dest_l + i] = '\0';
	return (src_l + dest_l);
}
