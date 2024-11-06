/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:38:17 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/06 19:38:28 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_pov(t_map *map, t_pixel *new, t_coord coord)
{
	if (map->iso_angle_x == 0 && map->iso_angle_y == -M_PI / 2)
	{
		new->x = (int)(coord.x * map->zoom + map->center_x);
		new->y = (int)(coord.y * map->zoom + map->center_y);
	}
	else if (map->iso_angle_x == 0 && map->iso_angle_y == 0)
	{
		new->x = (int)(coord.x * map->zoom + map->center_x);
		new->y = (int)(-coord.z * map->zoom + map->center_y);
	}
	else if (map->iso_angle_x == M_PI / 2 && map->iso_angle_y == 0)
	{
		new->x = (int)(coord.y * map->zoom + map->center_x);
		new->y = (int)(-coord.z * map->zoom + map->center_y);
	}
	else
	{
		new->x = (int)((coord.x - coord.y) * cos(map->iso_angle_x) * map->zoom
				+ map->center_x);
		new->y = (int)((coord.x + coord.y) * sin(map->iso_angle_y) - coord.z);
		new->y = (int)(new->y * map->zoom + map->center_y);
	}
}

void	set_map_pov(t_map *map, t_vertex *previous, t_pixel *new, t_coord coord)
{
	map_pov(map, new, coord);
	if (map->use_height_color)
		new->rgba = previous->zcolor;
	else
		new->rgba = previous->mapcolor;
}
