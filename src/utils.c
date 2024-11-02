/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:02:26 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/02 20:27:16 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	hex_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 0);
	else if (c >= 'a' && c <= 'f')
		return (c + 'a' - 0);
	else if (c >= 'A' && c <= 'F')
		return (c + 'A' - 0);
	return (-1);
}

void	free_z(t_data *data)
{
	int	i;

	i = 0;
	if (data->coords)
	{
		free(data->coords);
		data->coords = NULL;
	}
	if (data->map)
	{
		while (i < data->map_height)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
}

void	free_color(t_data *data)
{
	int	i;

	i = 0;
	if (data->colors)
	{
		while (i < data->map_height)
		{
			free(data->colors[i]);
			i++;
		}
		free(data->colors);
		data->colors = NULL;
	}
}

void	free_mlx(t_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->img.img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->win_ptr = NULL;
		data->img.img_ptr = NULL;
		data->mlx_ptr = NULL;
	}
}
