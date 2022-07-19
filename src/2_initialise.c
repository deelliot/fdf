/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_initialise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:18:27 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/19 14:27:35 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	initialise_points(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		map->points.p[i] = (t_point *)malloc(sizeof(t_point));
		if (!map->points.p[i])
			handle_errors("unable to malloc for p array", map);
		i++;
	}
}

t_map	*initialise_map(t_map *map)
{
	map->map = NULL;
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
	initialise_points(map);
	return (map);
}

void	initilise_camera_and_colour(t_map *map)
{
	set_z_min_max(map);
	map->colour.colour_loop = 1;
	colour_codes(&map->colour);
	set_z_step(&map->colour);
	set_camera_angle(map);
	set_camera_point(map, 0, 0, 0);
}
