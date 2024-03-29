/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:53:20 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/25 10:51:24 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* screen height and width */
# define WIDTH 1080
# define HEIGHT 720

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>

/* key controls */
# define KEY_DOWN 2
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define PROJECTION 35
# define IN 126
# define OUT 125
# define Y_CLOCK 32
# define Y_ANTI 16
# define Z_CLOCK 124
# define Z_ANTI 123
# define X_CLOCK 8
# define X_ANTI 7
# define ZOOM_IN 34
# define ZOOM_OUT 31
# define COLOUR 49
# define RESET 36
# define INC_HEIGHT 4
# define DEC_HEIGHT 5

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	norm_z;
}				t_point;

typedef struct s_cam
{
	t_point	point;
	double	alpha;
	double	beta;
	double	gamma;
}				t_cam;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}				t_rgb;

typedef struct s_col
{
	double	z_min;
	double	z_max;
	int		colour_loop;
	t_rgb	min_col;
	t_rgb	max_col;
	t_rgb	z_step;
	t_rgb	current;
	t_rgb	step;
	int		colour;
}				t_col;

typedef struct s_algo
{
	t_point	*p[3];
	double	dx;
	double	dy;
	double	step;
}			t_algo;

typedef struct s_map
{
	int		**map;
	int		col;
	int		row;
	void	*mlx;
	void	*win;
	int		projection;
	double	scale;
	double	z_scale;
	int		x_offset;
	int		y_offset;
	t_algo	points;
	t_cam	camera;
	t_col	colour;
}			t_map;

void	handle_errors(t_map *map);
t_map	*initialise_map(t_map *map);
void	initilise_camera_and_colour(t_map *map);
void	store_data(char *argv, t_map *map);
void	centre_point(t_map *map);
void	set_z_min_max(t_map *map);
int		handle_input(int key, t_map *map);

/* camera functions */
void	translate_point(t_point *point, t_cam *camera);
void	set_camera_point(t_map *map, double x, double y, double z);
void	set_camera_angle(t_map *map);

/* key functions */
void	handle_translation(int key, t_map *map);
void	handle_zoom(int key, t_map *map);
void	handle_height(int key, t_map *map);
void	handle_projection(t_map *map);
void	handle_rotation(int key, t_map *map);
void	handle_colour(t_map *map);
void	handle_reset(t_map *map);
void	esc_program(t_map *map);
void	window_key(t_map *map);

/* projection function */
double	**projection(double angle, t_map *map);

/* colour functions */
void	colour_codes(t_col *colour);
void	set_z_step(t_col *colour);
void	set_colour_step(t_map *map, t_point *p0, t_point *p1, double step);
void	set_colour(t_col *colour);

/* trasform and draw functions */
void	centre_point(t_map *map);
void	offset_point(t_map *map, t_point *point);
void	rotate_point(t_map *map, t_algo *points);
void	plot_points(t_map *map);
void	draw_horizontal_line(t_map *map, t_algo *points);
void	draw_vertical_line(t_map *map, t_algo *points);

/* free function */
void	free_map(t_map *map);

#endif