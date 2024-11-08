/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:35:51 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/06 19:36:05 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	arr_free(void **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	map_free(t_map *map)
{
	if (!map)
		return ;
	if (map->projected_points)
		arr_free((void **)map->projected_points, map->rows);
	if (map->original_points)
		arr_free((void **)map->original_points, map->rows);
	free(map);
}

void	fail_safe(const char *message)
{
	if (errno == 0)
	{
		ft_putstr_fd("fdf: ", 2);
		ft_putendl_fd((char *)message, 2);
	}
	else
		perror("fdf");
	exit(1);
}

void	map_error(int fd, t_map *map, char *message)
{
	close(fd);
	map_free(map);
	fail_safe(message);
}
