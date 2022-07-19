/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:46:13 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/19 13:24:08 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_points(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (map->points.p[i])
			ft_memdel((void *)(&map->points.p[i]));
		i++;
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->map)
			ft_memdelarray((void **)map->map, map->row);
		if (map->mlx && map->win)
			mlx_destroy_window(map->mlx, map->win);
		free_points(map);
	}
}
