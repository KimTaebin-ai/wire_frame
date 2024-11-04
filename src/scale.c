/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:20:25 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/04 17:50:26 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calculate_bounding_box(t_data *data)
{
	int	i;

	i = 0;
	project(data);
	while (i < data->map_width * data->map_height)
	{
		if (data->coords[i].x < data->x_prj_min)
			data->x_prj_min = data->coords[i].x;
		if (data->coords[i].x > data->x_prj_max)
			data->x_prj_max = data->coords[i].x;
		if (data->coords[i].y < data->y_prj_min)
			data->y_prj_min = data->coords[i].y;
		if (data->coords[i].y > data->y_prj_max)
			data->y_prj_max = data->coords[i].y;
		i++;
	}
}

void	calc_neg(t_data *data)
{
	int	i;

	calculate_bounding_box(data);
	i = 0;
	while (i < data->map_width * data->map_height)
	{
		data->coords[i].x -= data->x_prj_min;
		data->coords[i].y -= data->y_prj_min;
		i++;
	}
}

void	calculate_scaling_and_offset(t_data *data)
{
	float	scale_x;
	float	scale_y;

	calc_neg(data);
	scale_x = (float)WIN_WIDTH / (float)(data->x_prj_max - data->x_prj_min);
	scale_y = (float)WIN_HEIGHT / (float)(data->y_prj_max - data->y_prj_min);
	data->scale = fmin(scale_x, scale_y);
	data->scale *= 0.9;
	data->offset_x = (WIN_WIDTH - ((data->x_prj_max - data->x_prj_min)
				* data->scale)) / 2;
	data->offset_y = (WIN_HEIGHT - ((data->y_prj_max - data->y_prj_min)
				* data->scale)) / 2;
}
