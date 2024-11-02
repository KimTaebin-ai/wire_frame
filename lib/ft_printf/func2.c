/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 02:00:08 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/15 15:00:23 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_func(va_list ap, const char *hex)
{
	unsigned int	x;
	char			*xitoa;
	int				len;
	int				write_result;

	x = va_arg(ap, unsigned int);
	xitoa = ft_itoahex(x, hex);
	if (xitoa == NULL)
		return (-1);
	len = ft_strlen(xitoa);
	write_result = write(1, xitoa, len);
	free(xitoa);
	if (write_result == -1)
		return (-1);
	return (len);
}

int	sx_func(va_list ap)
{
	return (x_func(ap, HEX_CHARS_LOWER));
}

int	lx_func(va_list ap)
{
	return (x_func(ap, HEX_CHARS_UPPER));
}
