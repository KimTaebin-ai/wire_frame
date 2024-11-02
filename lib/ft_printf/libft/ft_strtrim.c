/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:38:06 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/03 22:14:24 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*sc;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_check(s1[start], set))
		start++;
	while (end > start && is_check(s1[end - 1], set))
		end--;
	sc = (char *)malloc(sizeof(char) * (end - start + 1));
	if (sc == NULL)
		return (0);
	while (end > start)
	{
		sc[i] = s1[start];
		i++;
		start++;
	}
	sc[i] = '\0';
	return (sc);
}
