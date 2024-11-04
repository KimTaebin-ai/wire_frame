/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:20:22 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/04 17:52:28 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 900
# define WIN_HEIGHT 600

# define COLOR_WHITE 0xFADADD
# define COLOR_BLACK 0x000000
# define COLOR_RED 0xFF0000

# define M_PI 3.14159265358979323846

# define FLT_MAX 3.402823466e+38F
# define FLT_MIN -3.402823466e+38F

# include <fcntl.h>
# include <get_next_line.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_point
{
	int			xp0;
	int			yp0;
	int			xp1;
	int			yp1;
}				t_point;

typedef struct s_bres
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_bres;

typedef struct s_coords
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_coords;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			**map;
	int			**colors;
	int			map_width;
	int			map_height;
	float		**x_prj;
	float		**y_prj;
	float		x_prj_max;
	float		y_prj_max;
	float		x_prj_min;
	float		y_prj_min;
	int			offset_x;
	int			offset_y;
	float		scale;
	float		rot_angle_x;
	float		rot_angle_y;
	float		rot_angle_z;
	t_img		img;
	t_coords	*coords;
	t_coords	*init_coords;
	t_bres		bres;
	t_point		point;
}				t_data;

int				ft_isspace(int c);
int				hex_to_int(char c);

void			error_msg(char *msg, t_data *data);

int				key_hook(int keycode, t_data *data);
int				handle_x(t_data *data);

void			get_map(t_data *data, const char *filename);
void			parse_fdf_file(t_data *data, const char *file);

void			allocate_color_z(t_data *data);
void			allocate_coords(t_data *data);

void			free_z(t_data *data);
void			free_color(t_data *data);
void			free_mlx(t_data *data);
void			free_data(t_data *data);
void			copy_coords(t_data *data);

int				render(t_data *data, t_img *img);

void			draw_horiz(t_data *data, t_point *point, t_bres *bres,
					t_img *img);
void			draw_vert(t_data *data, t_point *point, t_bres *bres,
					t_img *img);
void			img_pixel_put(t_img *img, int x, int y, int color);

void			rotate_project_scale(t_data *data);

void			calculate_scaling_and_offset(t_data *data);
void			project(t_data *data);

#endif