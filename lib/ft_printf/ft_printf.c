/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:06:47 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/18 20:31:24 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char *bs, va_list ap)
{
	if (*bs == 'c')
		return (c_func(ap));
	else if (*bs == 's')
		return (s_func(ap));
	else if (*bs == 'p')
		return (p_func(ap));
	else if (*bs == 'd' || *bs == 'i')
		return (d_func(ap));
	else if (*bs == 'u')
		return (u_func(ap));
	else if (*bs == 'x')
		return (sx_func(ap));
	else if (*bs == 'X')
		return (lx_func(ap));
	else if (*bs == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (-1);
}

int	count_bs(const char *bs, va_list ap)
{
	int	i;
	int	type_len;

	i = 0;
	while (*bs)
	{
		if (*bs == '%')
		{
			bs++;
			type_len = check_type(bs, ap);
			if (type_len == -1)
				return (-1);
			i += type_len;
		}
		else
		{
			if (write(1, bs, 1) == -1)
			{
				return (-1);
			}
			i++;
		}
		bs++;
	}
	return (i);
}

int	ft_printf(const char *bs, ...)
{
	va_list	argptr;
	int		bs_len;

	bs_len = 0;
	va_start(argptr, bs);
	bs_len = count_bs(bs, argptr);
	return (bs_len);
}
