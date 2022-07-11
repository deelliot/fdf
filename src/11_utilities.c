/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:06:23 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/11 15:32:08 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_colour(t_map *map)
{
	if (map->colour->min_col)
		ft_memdel((void **)map->colour->min_col);
	if (map->colour->max_col)
		ft_memdel((void **)map->colour->max_col);
	if (map->colour->z_step)
		ft_memdel((void **)map->colour->z_step);
	if (map->colour->current)
		ft_memdel((void **)map->colour->current);
	if (map->colour->step)
		ft_memdel((void **)map->colour->step);
	free(map->colour);
}

void	handle_errors(char *str, t_map *map)
{
	if (map)
	{
		if (map->map)
			ft_memdelgrid((void **)map->map, map->col, map->row);
		if (map->mlx && map->win)
			mlx_destroy_window(map->mlx, map->win);
		if (map->points)
		{
			if (map->points->p)
				ft_memdelarray((void *)map->points->p, 3);
			free(map->points);
		}
		if (map->camera)
		{
			if (map->camera->point)
				ft_memdel((void **)map->camera->point);
			free(map->camera);
		}
		if (map->colour)
			free_colour(map);
		free(map);
	}
	ft_putendl(str);
	exit (1);
}

void	set_z_min_max(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->colour->z_min = map->map[0][0];
	map->colour->z_max = map->map[0][0];
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (map->colour->z_min > map->map[y][x])
				map->colour->z_min = map->map[y][x];
			if (map->colour->z_max < map->map[y][x])
				map->colour->z_max = map->map[y][x];
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
	point->x += camera->point->x;
	point->y += camera->point->y;
	point->z += camera->point->z;
}
