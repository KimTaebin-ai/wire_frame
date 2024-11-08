/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:36:15 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/06 19:36:29 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_scroll(double xscale, double yscale, void *param)
{
	t_fdf	*fdf;

	(void)xscale;
	fdf = (t_fdf *)param;
	if (yscale > 0)
		fdf->map->zoom *= 1.02;
	else if (yscale < 0 && fdf->map->zoom * 0.98 > 0)
		fdf->map->zoom *= 0.98;
	xscale++;
}

void	hook_events(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_R))
		refresh_map(fdf->map);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->map->center_x += 7;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->map->center_x -= 7;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->map->center_y += 7;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->map->center_y -= 7;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
		hook_scroll(0, 1, param);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		hook_scroll(0, -1, param);
}

void	hook_rotate(void *param)
{
	t_fdf	*fdf;
	double	sign;

	fdf = (t_fdf *)param;
	sign = 0;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_COMMA))
		sign = -1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PERIOD))
		sign = 1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->map->height_scale += sign * 0.02;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		fdf->map->rotation_z += sign * 0.02;
}

static void	set_view_parameters(t_fdf *fdf, int view)
{
	fdf->map->rotation_z = 0;
	fdf->map->height_scale = 1;
	if (view == 1)
	{
		fdf->map->iso_angle_x = 0;
		fdf->map->iso_angle_y = -M_PI / 2;
		fdf->map->height_scale = 0;
	}
	else if (view == 2)
	{
		fdf->map->iso_angle_x = 0;
		fdf->map->iso_angle_y = 0;
	}
	else if (view == 3)
	{
		fdf->map->iso_angle_x = M_PI / 2;
		fdf->map->iso_angle_y = 0;
	}
	else if (view == 4)
	{
		fdf->map->iso_angle_x = 0.46373398 / 2;
		fdf->map->iso_angle_y = 0.46373398;
	}
}

void	hook_project(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		set_view_parameters(fdf, 1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		set_view_parameters(fdf, 2);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_3))
		set_view_parameters(fdf, 3);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_4))
		set_view_parameters(fdf, 4);
}
