/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:46:13 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/20 10:24:41 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map)
			ft_memdelarray((void **)map->map, map->row);
		if (map->mlx && map->win)
			mlx_destroy_window(map->mlx, map->win);
		while (i < 3)
		{
			if (map->points.p[i])
				ft_memdel((void *)(&map->points.p[i]));
			i++;
		}
	}
}
