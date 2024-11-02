/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:56:54 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/02 20:37:38 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pxl;
	int		i;

	i = img->bpp - 8;
	pxl = img->data + (y * img->size_line + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pxl++ = (color >> i) & 0xFF;
		else
			*pxl++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

static void	render_background(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			img_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_line(t_data *data)
{
	t_point	point;
	t_bres	*bres;
	t_img	*img;

	bres = &data->bres;
	img = &data->img;
	draw_horiz(data, &point, bres, img);
	draw_vert(data, &point, bres, img);
}

int	render(t_data *data, t_img *img)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(img, COLOR_BLACK);
	// rotate_project_scale(data);
	draw_line(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img_ptr, 0, 0);
	return (0);
}
