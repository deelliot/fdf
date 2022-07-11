/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_plot_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:41 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/11 10:16:46 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*create_p(int x, int y, int z, t_map *map)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		handle_errors("unable to malloc for point", map);
	point->x = x * map->scale;
	point->y = y * map->scale;
	point->z = z * map->scale;
	point->norm_z = normalise_data(map->colour->z_min, map->colour->z_max, z);
	return (point);
}

void	plot_points(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			map->points->p[0] = create_p(x, y, map->map[y][x], map);
			if (x < (map->col - 1))
				map->points->p[1] = create_p(x + 1, y, map->map[y][x + 1], map);
			if (y < (map->row - 1))
				map->points->p[2] = create_p(x, y + 1, map->map[y + 1][x], map);
			rotate_point(map, map->points);
			if (x < (map->col - 1))
				draw_horizontal_line(map, map->points);
			if (y < (map->row - 1))
				draw_vertical_line(map, map->points);
			x++;
		}
		y++;
	}
	mlx_loop(map->mlx);
}
