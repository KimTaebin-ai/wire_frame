/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:58:18 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/04 18:09:34 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	parse_hex_color(const char *hex_str)
{
	int	color;

	color = 0;
	if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		hex_str += 2;
	while (*hex_str)
	{
		color = (color << 4) | hex_to_int(*hex_str);
		hex_str++;
	}
	return (color);
}

static int	parse_color(char *token)
{
	char	**insight;
	int		color;
	int		i;

	if (ft_strchr(token, ','))
	{
		insight = ft_split(token, ',');
		if (insight[1])
			color = parse_hex_color(insight[1]);
		else
			color = COLOR_WHITE;
		i = 0;
		while (insight[i])
		{
			free(insight[i]);
			i++;
		}
		free(insight);
	}
	else
		color = COLOR_WHITE;
	return (color);
}

static void	parse_line(t_data *data, char *line, int y)
{
	char	*ptr;
	char	*token;
	int		x;

	x = 0;
	ptr = line;
	while (*ptr != '\0' && x < data->map_width)
	{
		while (ft_isspace(*ptr))
			ptr++;
		if (*ptr != '\0')
		{
			token = ptr;
			data->map[y][x] = ft_atoi(token);
			data->colors[y][x] = parse_color(token);
			x++;
		}
		while (*ptr != '\0' && !ft_isspace(*ptr))
			ptr++;
	}
	if (x > data->map_width)
		data->map_width = x;
}

void	parse_fdf_file(t_data *data, const char *file)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_msg("error: open() failed\n", data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (y < data->map_height)
		{
			parse_line(data, line, y);
			free(line);
			line = get_next_line(fd);
			y++;
		}
		else
			error_msg("error height 1", data);
	}
	if (y != data->map_height)
		error_msg("error heignt", data);
	close(fd);
}
