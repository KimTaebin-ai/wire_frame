/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 02:49:36 by taebkim           #+#    #+#             */
/*   Updated: 2024/10/18 20:54:31 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		gnl_strlen(const char *s);
char	*gnl_strdup(const char *s1);
int		gnl_check(char *storage);
char	*gnl_strjoin(char const *s1, char const *s2);

char	*create_line(int fd, char *buf, char *storage);
char	*extract_remainder(char *line);
char	*get_next_line(int fd);

#endif