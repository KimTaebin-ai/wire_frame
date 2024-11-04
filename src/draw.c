/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:17:08 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/04 17:49:07 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_data *data)
{
	float	y_new;
	float	z_new;
	int		i;
	float	rad_x;

	i = 0;
	rad_x = (data->rot_angle_x) * M_PI / 180.0;
	while (i < data->map_height * data->map_width)
	{
		y_new = data->coords[i].y * cos(rad_x) - data->coords[i].z * sin(rad_x);
		z_new = data->coords[i].y * sin(rad_x) + data->coords[i].z * cos(rad_x);
		data->coords[i].y = y_new;
		data->coords[i].z = z_new;
		i++;
	}
}

static void	rotate_y(t_data *data)
{
	float	x_new;
	float	z_new;
	int		i;
	float	rad_y;

	i = 0;
	rad_y = (data->rot_angle_y) * M_PI / 180.0;
	while (i < data->map_height * data->map_width)
	{
		x_new = data->coords[i].x * cos(rad_y) + data->coords[i].z * sin(rad_y);
		z_new = -data->coords[i].x * sin(rad_y) + data->coords[i].z
			* cos(rad_y);
		data->coords[i].x = x_new;
		data->coords[i].z = z_new;
		i++;
	}
}

static void	rotate_z(t_data *data)
{
	float	x_new;
	float	y_new;
	int		i;
	float	rad_z;

	i = 0;
	rad_z = (data->rot_angle_z) * M_PI / 180.0;
	while (i < data->map_height * data->map_width)
	{
		x_new = data->coords[i].x * cos(rad_z) - data->coords[i].y * sin(rad_z);
		y_new = data->coords[i].x * sin(rad_z) + data->coords[i].y * cos(rad_z);
		data->coords[i].x = x_new;
		data->coords[i].y = y_new;
		i++;
	}
}

void	project(t_data *data)
{
	float	iso_x;
	float	iso_y;
	int		i;

	i = 0;
	rotate_x(data);
	rotate_y(data);
	rotate_z(data);
	while (i < data->map_height * data->map_width)
	{
		iso_x = (data->coords[i].x - data->coords[i].y) * cos((30) * M_PI
				/ 180.0);
		iso_y = (data->coords[i].x + data->coords[i].y) * sin((30) * M_PI
				/ 180.0) - data->coords[i].z;
		data->coords[i].x = iso_x;
		data->coords[i].y = iso_y;
		i++;
	}
}

void	rotate_project_scale(t_data *data)
{
	int	i;

	i = 0;
	calculate_scaling_and_offset(data);
	while (i < data->map_height * data->map_width)
	{
		data->coords[i].x = round(data->coords[i].x * data->scale
				+ data->offset_x);
		data->coords[i].y = round(data->coords[i].y * data->scale
				+ data->offset_y);
		img_pixel_put(&data->img, data->coords[i].x, data->coords[i].y,
			data->coords[i].color);
		i++;
	}
}
