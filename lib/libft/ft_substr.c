/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:37:06 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/03 23:24:06 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sc;

	i = 0;
	if (s == 0)
		return (0);
	size = ft_strlen(s);
	if (size < start)
		len = 0;
	else if (len > size - start)
		len = size - start;
	sc = (char *)malloc(sizeof(char) * (len + 1));
	if (sc == NULL)
		return (0);
	while (len--)
	{
		sc[i] = s[start];
		start++;
		i++;
	}
	sc[i] = '\0';
	return (sc);
}
