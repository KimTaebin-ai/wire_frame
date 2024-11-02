/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:37:45 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/03 21:55:15 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sc;

	i = 0;
	j = 0;
	sc = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (sc == NULL)
		return (0);
	while (s1[i])
	{
		sc[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		sc[i + j] = s2[j];
		j++;
	}
	return (sc);
}
