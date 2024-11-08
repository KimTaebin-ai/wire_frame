/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:37:18 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/06 19:38:53 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	rot_z_axis(double *x, double *y, double angle)
{
	double	temp_x;
	double	temp_y;

	temp_x = *x * cos(angle) - *y * sin(angle);
	temp_y = *x * sin(angle) + *y * cos(angle);
	*x = temp_x;
	*y = temp_y;
}
