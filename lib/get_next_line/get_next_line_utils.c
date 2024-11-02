/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 02:49:18 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/18 20:59:22 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*gnl_strdup(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(char) * gnl_strlen(s1) + 1);
	if (result == NULL)
		return (0);
	while (i < gnl_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sc;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = 0;
	i = 0;
	sc = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
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
	sc[i + j] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (sc);
}
