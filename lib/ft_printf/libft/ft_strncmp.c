/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:12:24 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/06 23:00:42 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*_s1;
	unsigned char	*_s2;

	i = 0;
	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	while (*_s1 && *_s2 && i < n)
	{
		if (*_s1 != *_s2)
			return (*_s1 - *_s2);
		_s1++;
		_s2++;
		i++;
	}
	if (i != n)
		return (*_s1 - *_s2);
	return (0);
}
