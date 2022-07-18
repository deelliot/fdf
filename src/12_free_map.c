/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:46:13 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/18 10:41:07 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_cam_and_colour(t_map *map)
{
	if (map->camera)
	{
		if (map->camera->point)
			ft_memdel((void *)(&map->camera->point));
		free (map->camera);
		map->camera = NULL;
	}
	if (map->colour)
	{
		if (map->colour->z_step)
			ft_memdel((void *)(&map->colour->z_step));
		if (map->colour->current)
			ft_memdel((void *)(&map->colour->current));
		if (map->colour->step)
			ft_memdel((void *)(&map->colour->step));
		if (map->colour->min_col)
			ft_memdel((void *)(&map->colour->min_col));
		if (map->colour->max_col)
			ft_memdel((void *)(&map->colour->max_col));
		free(map->colour);
		map->colour = NULL;
	}
}

void	free_points(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (map->points->p[i])
			ft_memdel((void *)(&map->points->p[i]));
		i++;
	}
	free (*map->points->p);
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->map)
			ft_memdelarray((void **)map->map, map->row);
		if (map->mlx && map->win)
			mlx_destroy_window(map->mlx, map->win);
		if (map->points)
		{
			free_points(map);
			free (map->points);
			map->points = NULL;
		}
		free_cam_and_colour(map);
		free(map);
	}
}
