/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:38:23 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/06 23:03:45 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordlen(char const *s, char c)
{
	int	i;
	int	in_word;

	i = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			i++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (i);
}

int	ft_cpy(char **sp, char const *start, char const *s, int j)
{
	int	len;
	int	k;

	len = s - start;
	k = 0;
	sp[j] = (char *)malloc(sizeof(char) * (len + 1));
	if (sp[j] == NULL)
	{
		while (j-- > 0)
			free(sp[j]);
		free(sp);
		return (0);
	}
	while (k < len)
	{
		sp[j][k] = start[k];
		k++;
	}
	sp[j][k] = '\0';
	return (1);
}

char	**nom(char **sp, char const *s, char c)
{
	char const	*start;
	int			j;

	j = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		start = s;
		if (*s && (*s != c))
		{
			while (*s && (*s != c))
				s++;
			if (ft_cpy(sp, start, s, j) == 0)
				return (0);
			j++;
		}
	}
	sp[j] = 0;
	return (sp);
}

char	**ft_split(char const *s, char c)
{
	char	**sc;

	if (s == 0)
		return (0);
	sc = (char **)malloc(sizeof(char *) * (ft_wordlen(s, c) + 1));
	if (sc == NULL)
		return (0);
	return (nom(sc, s, c));
}
