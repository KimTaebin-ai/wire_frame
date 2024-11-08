/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:39:14 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/06 23:00:06 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fname_valid(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	filename += len - 4;
	return (ft_strncmp(filename, ".fdf", 4) == 0);
}

void	to_upper(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

void	image_reset(mlx_image_t *image)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			mlx_put_pixel(image, j, i, BACKGROUND);
			j++;
		}
		i++;
	}
}

void	refresh_map(t_map *map)
{
	map->iso_angle_x = 0.46373398 / 2;
	map->iso_angle_y = 0.46373398;
	map->rotation_x = 0;
	map->rotation_y = 0;
	map->rotation_z = 0;
	map->center_x = WIDTH / 2;
	map->center_y = HEIGHT / 2;
	map->zoom = 1;
	map->height_scale = 1;
	map->use_height_color = false;
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	neg;
	int	res;
	int	nbase;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	neg = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	nbase = ft_strlen(base);
	res = 0;
	while (str && *str && ft_strchr(base, *str))
	{
		res = res * nbase + (ft_strchr(base, *str) - base);
		str++;
	}
	return (res * neg);
}
