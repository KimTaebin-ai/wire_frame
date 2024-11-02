/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:36:46 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/18 20:15:21 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sizen_h(unsigned long long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_itoahex(unsigned long long n, const char *hex)
{
	int		size_n;
	char	*ia;

	size_n = sizen_h(n);
	ia = ft_calloc((size_n + 1), sizeof(char));
	if (ia == NULL)
		return (NULL);
	if (n == 0)
		ia[0] = '0';
	else
	{
		while (n)
		{
			ia[--size_n] = hex[n % 16];
			n /= 16;
		}
	}
	return (ia);
}
