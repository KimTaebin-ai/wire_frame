/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:41:07 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/02 20:03:24 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_line_empty(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}

static int	process_line(const char *line)
{
	int			temp_width;
	int			in_token;
	const char	*ptr;

	temp_width = 0;
	in_token = 0;
	ptr = line;
	while (*ptr)
	{
		if (!ft_isspace(*ptr))
		{
			if (!in_token)
			{
				temp_width++;
				in_token = 1;
			}
		}
		else
			in_token = 0;
		ptr++;
	}
	return (temp_width);
}

static void	calc_map(t_data *data, int fd)
{
	int		temp_width;
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_line_empty(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		temp_width = process_line(line);
		if (data->map_width < temp_width)
			data->map_width = temp_width;
		data->map_height++;
		free(line);
		line = get_next_line(fd);
	}
}

void	get_map(t_data *data, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_msg("error: open() failed\n", data);
	calc_map(data, fd);
	if (data->map_height == 0 || data->map_width == 0)
		error_msg("error: invalid map\n", data);
	close(fd);
}
