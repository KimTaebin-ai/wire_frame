/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:06:55 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/18 20:31:53 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_CHARS_LOWER "0123456789abcdef"
# define HEX_CHARS_UPPER "0123456789ABCDEF"

int		ft_printf(const char *bs, ...);

int		c_func(va_list ap);
int		s_func(va_list ap);
int		s_func(va_list ap);
int		p_func(va_list ap);
int		d_func(va_list ap);
int		u_func(va_list ap);
int		sx_func(va_list ap);
int		lx_func(va_list ap);

char	*ft_itoahex(unsigned long long n, const char *hex);

#endif
