/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:24:06 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/02 20:26:21 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_msg(char *msg, t_data *data)
{
	ft_putstr_fd(msg, 2);
	free(data->img.data);
	free(data->img.img_ptr);
	free(data->mlx_ptr);
	exit(EXIT_FAILURE);
}
