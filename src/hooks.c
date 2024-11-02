/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:49:47 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/02 20:28:30 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	close_window(t_data *data)
{
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->img.img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	free_data(data);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	int	i;

	i = 0;
	if (!data->init_coords || !data->coords)
		error_msg("Error: init_coords or coords is NULL", data);
	while (i < data->map_height * data->map_width)
	{
		data->coords[i] = data->init_coords[i];
		i++;
	}
	if (keycode == 53 || keycode == 65307)
		close_window(data);
	// TODO
	// 회전, 확대 등등 보너스용 함수 필요
	render(data, &data->img);
	return (0);
}

int	handle_x(t_data *data)
{
	close_window(data);
	return (0);
}
