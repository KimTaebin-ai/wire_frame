/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:38:58 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/04 18:39:17 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*sc;

	if (s == 0)
		return (0);
	i = 0;
	sc = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (sc == NULL)
		return (0);
	while (i < ft_strlen(s))
	{
		sc[i] = f(i, s[i]);
		i++;
	}
	sc[i] = '\0';
	return (sc);
}
