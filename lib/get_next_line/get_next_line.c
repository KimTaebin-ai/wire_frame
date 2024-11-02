/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 02:49:08 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/18 20:55:00 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_check(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*create_line(int fd, char *buf, char *storage)
{
	int	r_size;

	r_size = read(fd, buf, BUFFER_SIZE);
	while (r_size > 0)
	{
		buf[r_size] = '\0';
		if (!storage)
			storage = gnl_strdup(buf);
		else
			storage = gnl_strjoin(storage, buf);
		if (storage == NULL)
			return (NULL);
		if (gnl_check(storage) != -1)
			return (storage);
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	return (storage);
}

char	*extract_remainder(char *line)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	tmp = gnl_strdup(line + i + 1);
	if (tmp == NULL)
		return (NULL);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = create_line(fd, buf, storage);
	if (line == NULL)
		return (NULL);
	storage = extract_remainder(line);
	temp = gnl_strdup(line);
	free(line);
	line = NULL;
	return (temp);
}
