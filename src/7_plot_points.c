/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_plot_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:41 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/25 10:51:30 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_p(int x, int y, t_map *map, t_point *point)
{
	point->x = x * map->scale;
	point->y = y * map->scale;
	point->z = map->map[y][x] * map->z_scale;
	point->norm_z = normalise_data(map->colour.z_min, map->colour.z_max, \
	map->map[y][x]);
}

void	plot_points(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			set_p(x, y, map, map->points.p[0]);
			if (x < (map->col - 1))
				set_p(x + 1, y, map, map->points.p[1]);
			if (y < (map->row - 1))
				set_p(x, y + 1, map, map->points.p[2]);
			rotate_point(map, &map->points);
			if (x < (map->col - 1))
				draw_horizontal_line(map, &map->points);
			if (y < (map->row - 1))
				draw_vertical_line(map, &map->points);
			x++;
		}
		y++;
	}
	mlx_loop(map->mlx);
}
