/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:29:40 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/02 20:32:57 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bres_init(t_point *point, t_bres *bres)
{
	bres->dx = abs(point->xp1 - point->xp0);
	if (point->xp0 < point->xp1)
		bres->sx = 1;
	else
		bres->sx = -1;
	bres->dy = abs(point->yp1 - point->yp0);
	if (point->yp0 < point->yp1)
		bres->sy = 1;
	else
		bres->sy = -1;
	bres->err = bres->dx - bres->dy;
}

void	bres_draw(t_point *point, t_bres *bres, t_img *img, int color)
{
	while (1)
	{
		img_pixel_put(img, point->xp0, point->yp0, color);
		if (point->xp0 == point->xp1 && point->yp0 == point->yp1)
			break ;
		bres->e2 = 2 * bres->err;
		if (bres->e2 > -bres->dy)
		{
			bres->err -= bres->dy;
			point->xp0 += bres->sx;
		}
		if (bres->e2 < bres->dx)
		{
			bres->err += bres->dx;
			point->yp0 += bres->sy;
		}
	}
}

static void	bresenham(t_point *point, t_bres *bres, t_img *img, int color)
{
	bres_init(point, bres);
	bres_draw(point, bres, img, color);
}

void	draw_horiz(t_data *data, t_point *point, t_bres *bres, t_img *img)
{
	int	row;
	int	col;
	int	indx;

	row = 0;
	while (row < data->map_height)
	{
		col = 0;
		while (col < data->map_width - 1)
		{
			indx = row * data->map_width + col;
			point->xp0 = (int)data->coords[indx].x;
			point->yp0 = (int)data->coords[indx].y;
			point->xp1 = (int)data->coords[indx + 1].x;
			point->yp1 = (int)data->coords[indx + 1].y;
			bresenham(point, bres, img, data->coords[indx].color);
			col++;
		}
		row++;
	}
}

void	draw_vert(t_data *data, t_point *point, t_bres *bres, t_img *img)
{
	int	row;
	int	col;
	int	indx;

	col = 0;
	while (col < data->map_width)
	{
		row = 0;
		while (row < data->map_height - 1)
		{
			indx = row * data->map_width + col;
			point->xp0 = (int)data->coords[indx].x;
			point->yp0 = (int)data->coords[indx].y;
			point->xp1 = (int)data->coords[indx + data->map_width].x;
			point->yp1 = (int)data->coords[indx + data->map_width].y;
			bresenham(point, bres, img, data->coords[indx].color);
			row++;
		}
		col++;
	}
}
