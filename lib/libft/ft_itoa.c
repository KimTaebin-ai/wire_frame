/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:38:37 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/04 18:45:36 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ilen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		i = 1;
		while (n)
		{
			n = n / 10;
			i++;
		}
	}
	else if (n > 0)
	{
		while (n)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				size_n;
	unsigned int	fn;
	char			*ia;

	size_n = ft_ilen(n);
	ia = (char *)malloc(sizeof(char) * size_n + 1);
	if (ia == NULL)
		return (0);
	ia[size_n] = '\0';
	if (n < 0)
	{
		ia[0] = '-';
		fn = n * (-1);
	}
	else
		fn = n;
	while (fn)
	{
		ia[size_n - 1] = (fn % 10) + '0';
		fn = fn / 10;
		size_n--;
	}
	if (n == 0)
		ia[0] = '0';
	return (ia);
}
