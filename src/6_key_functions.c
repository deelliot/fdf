/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_key_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:44:38 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/13 16:49:24 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_translation(int key, t_map *map)
{
	if (key == UP)
		map->camera->point->y -= 10;
	if (key == DOWN)
		map->camera->point->y += 10;
	if (key == LEFT)
		map->camera->point->x -= 10;
	if (key == RIGHT)
		map->camera->point->x += 10;
	if (key == IN)
		map->camera->point->z += 10;
	if (key == OUT)
		map->camera->point->z -= 10;
	mlx_clear_window(map->mlx, map->win);
	window_key(map);
	plot_points(map);
}

void	handle_zoom(int key, t_map *map)
{
	if (key == ZOOM_IN)
		map->scale += 5;
	if (key == ZOOM_OUT)
	{
		if (map->scale <= 1)
			map->scale = 1.5;
		map->scale -= 0.5;
	}
	mlx_clear_window(map->mlx, map->win);
	centre_point(map);
	window_key(map);
	plot_points(map);
}

void	handle_projection(t_map *map)
{
	map->projection += 1;
	if (map->projection == 4)
		map->projection = 0;
	if (map->projection == 2)
		set_camera_point(map, 0, 0, -10);
	else
		set_camera_point(map, 0, 0, 0);
	mlx_clear_window(map->mlx, map->win);
	centre_point(map);
	set_camera_angle(map);
	window_key(map);
	plot_points(map);
}

void	handle_rotation(int key, t_map *map)
{
	if (key == X_CLOCK)
		map->camera->alpha += 0.1;
	if (key == X_ANTI)
		map->camera->alpha -= 0.1;
	if (key == Y_CLOCK)
		map->camera->beta += 0.1;
	if (key == Y_ANTI)
		map->camera->beta -= 0.1;
	if (key == Z_CLOCK)
		map->camera->gamma += 0.1;
	if (key == Z_ANTI)
		map->camera->gamma -= 0.1;
	mlx_clear_window(map->mlx, map->win);
	window_key(map);
	plot_points(map);
}
