/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_initialise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:18:27 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/14 14:44:05 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*initialise_map(t_map *map)
{
	int	i;

	i = 0;
	map->list = NULL;
	map->col = 0;
	map->row = 0;
	map->mlx = mlx_init();
	if (!map->mlx)
		handle_errors("unable to initiate mlx", map);
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "FDF");
	if (!map->win)
		handle_errors("unable to create window", map);
	map->projection = 0;
	map->scale = 5;
	map->points = (t_algo *)malloc(sizeof(t_algo));
	if (!map->points)
		handle_errors("unable to malloc for points", map);
	while (i < 3)
	{
		map->points->p[i] = (t_point *)malloc(sizeof(t_point));
		if (!map->points->p[i])
			handle_errors("unable to malloc for p array", map);
		i++;
	}
	return (map);
}

void	initilise_camera_and_colour(t_map *map)
{
	map->camera = (t_cam *)malloc(sizeof(t_cam));
	if (!map->camera)
		handle_errors("unable to malloc for camera", map);
	map->camera->point = (t_point *)malloc(sizeof(t_point));
	if (!map->camera->point)
		handle_errors("unable to malloc for camera point", map);
	map->colour = (t_col *)malloc(sizeof(t_col));
	if (!map->colour)
		handle_errors("unable to malloc for colour struct", map);
	set_z_min_max(map);
	map->colour->colour_loop = 1;
	map->colour->z_step = (t_rgb *)malloc(sizeof(t_rgb));
	if (!map->colour->z_step)
		handle_errors("unable to malloc for z_step", map);
	map->colour->current = (t_rgb *)malloc(sizeof(t_rgb));
	if (!map->colour->current)
		handle_errors("unable to malloc for RGB colour->current", map);
	map->colour->step = (t_rgb *)malloc(sizeof(t_rgb));
	if (!map->colour->step)
		handle_errors("unable to malloc for RGB colour->step", map);
	colour_codes(map->colour, map);
	set_z_step(map->colour);
	set_camera_angle(map);
	set_camera_point(map, 0, 0, 0);
}
