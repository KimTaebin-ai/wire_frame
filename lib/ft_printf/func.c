/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:39:31 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/18 20:09:03 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_func(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	s_func(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (write(1, s, ft_strlen(s)) == -1 || ft_strlen(s) > INT_MAX)
		return (-1);
	return (ft_strlen(s));
}

int	p_func(va_list ap)
{
	void				*ptr;
	unsigned long long	p;
	char				*pitoa;
	int					len;

	ptr = va_arg(ap, void *);
	if (ptr == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	p = (unsigned long long)ptr;
	pitoa = ft_itoahex(p, HEX_CHARS_LOWER);
	len = ft_strlen(pitoa);
	write(1, "0x", 2);
	if (write(1, pitoa, len) == -1)
	{
		free(pitoa);
		return (-1);
	}
	free(pitoa);
	return (len + 2);
}

int	d_func(va_list ap)
{
	int		d;
	char	*ditoa;
	int		len;

	d = va_arg(ap, int);
	ditoa = ft_itoa(d);
	len = ft_strlen(ditoa);
	if (write(1, ditoa, len) == -1)
	{
		free(ditoa);
		return (-1);
	}
	free(ditoa);
	return (len);
}

int	u_func(va_list ap)
{
	unsigned int	u;
	char			*uitoa;
	int				len;

	u = va_arg(ap, unsigned int);
	uitoa = ft_itoa(u);
	if (!uitoa)
		return (-1);
	len = ft_strlen(uitoa);
	if (write(1, uitoa, len) == -1)
	{
		free(uitoa);
		return (-1);
	}
	free(uitoa);
	return (len);
}
