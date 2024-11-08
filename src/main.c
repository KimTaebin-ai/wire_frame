/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:36:42 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/06 20:33:40 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	table_memalloc(t_map *map)
{
	int	i;

	map->original_points = malloc(sizeof(t_vertex *) * map->rows);
	map->projected_points = malloc(sizeof(t_pixel *) * map->rows);
	if (!(map->projected_points) || !(map->original_points))
	{
		map_free(map);
		fail_safe(MALLOC_ERR);
	}
	i = -1;
	while (++i < map->rows)
	{
		map->original_points[i] = malloc(sizeof(t_vertex) * map->cols);
		map->projected_points[i] = malloc(sizeof(t_pixel) * map->cols);
		if (!(map->projected_points[i]) || !(map->original_points))
		{
			if (i + 1 < map->rows)
			{
				map->original_points[i + 1] = NULL;
				map->projected_points[i + 1] = NULL;
			}
			map_free(map);
			fail_safe(MALLOC_ERR);
		}
	}
}

void	map_init(t_map *map)
{
	map->iso_angle_x = 0.46373398 / 2;
	map->iso_angle_y = 0.46373398;
	map->rotation_x = 0;
	map->rotation_x = 0;
	map->rotation_z = 0;
	map->center_x = WIDTH / 2;
	map->center_y = HEIGHT / 2;
	map->zoom = 1;
	map->height_scale = 1;
	map->use_height_color = false;
	map->max_height = INT_MIN;
	map->min_height = INT_MAX;
	map->rows = 0;
	map->cols = 0;
	map->projected_points = NULL;
	map->original_points = NULL;
}

static t_map	*input_parse(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		fail_safe(FILE_OPEN_ERR);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		fail_safe(MALLOC_ERR);
	}
	map_init(map);
	map_size(fd, map);
	close(fd);
	table_memalloc(map);
	map->interval = ft_min(WIDTH / map->cols, HEIGHT / map->rows) / 4;
	map->interval = ft_max(2, map->interval);
	fd = open(filename, O_RDONLY);
	map_parse(fd, map);
	close(fd);
	apply_zclr(map);
	return (map);
}

static t_fdf	*fdf_init(char *filename)
{
	static t_fdf	fdf;

	fdf.map = input_parse(filename);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!fdf.mlx)
	{
		map_free(fdf.map);
		fail_safe(mlx_strerror(mlx_errno));
	}
	fdf.image = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	if (!fdf.image)
	{
		map_free(fdf.map);
		mlx_close_window(fdf.mlx);
		fail_safe(mlx_strerror(mlx_errno));
	}
	return (&fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2 || !fname_valid(argv[1]))
		fail_safe(USAGE_FORMAT);
	fdf = fdf_init(argv[1]);
	draw_image(fdf);
	if (mlx_image_to_window(fdf->mlx, fdf->image, 0, 0) == -1)
	{
		map_free(fdf->map);
		mlx_close_window(fdf->mlx);
		fail_safe(mlx_strerror(mlx_errno));
	}
	mlx_key_hook(fdf->mlx, &change_color, fdf);
	mlx_loop_hook(fdf->mlx, &hook_events, fdf);
	mlx_loop_hook(fdf->mlx, &hook_rotate, fdf);
	mlx_loop_hook(fdf->mlx, &hook_project, fdf);
	mlx_scroll_hook(fdf->mlx, &hook_scroll, fdf);
	mlx_loop_hook(fdf->mlx, &draw_image, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	map_free(fdf->map);
	return (0);
}
