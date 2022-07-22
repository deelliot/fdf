/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:06:23 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/22 14:57:27 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_errors(t_map *map)
{
	if (map)
		free_map(map);
	ft_putendlerror("Error");
	exit (1);
}

void	set_z_min_max(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->colour.z_min = map->map[0][0];
	map->colour.z_max = map->map[0][0];
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (map->colour.z_min > map->map[y][x])
				map->colour.z_min = map->map[y][x];
			if (map->colour.z_max < map->map[y][x])
				map->colour.z_max = map->map[y][x];
			x++;
		}
		y++;
	}
}

void	offset_point(t_map *map, t_point *point)
{
	point->x += map->x_offset;
	point->y += map->y_offset;
}

void	translate_point(t_point *point, t_cam *camera)
{
	point->x += camera->point.x;
	point->y += camera->point.y;
	point->z += camera->point.z;
}

void	centre_point(t_map *map)
{
	map->x_offset = (WIDTH - (map->col * map->scale)) / 2;
	map->y_offset = (HEIGHT - map->row * (map->scale)) / 2;
}
