/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_key_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:15:21 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/17 18:11:50 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_colour(t_map *map)
{
	if (map->colour->min_col)
		ft_memdel((void *)(&map->colour->min_col));
	if (map->colour->max_col)
		ft_memdel((void *)(&map->colour->max_col));
	map->colour->colour_loop += 1;
	if (map->colour->colour_loop == 5)
		map->colour->colour_loop = 0;
	mlx_clear_window(map->mlx, map->win);
	colour_codes(map->colour, map);
	set_z_step(map->colour);
	window_key(map);
	plot_points(map);
}

void	handle_reset(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	map->projection = 0;
	map->scale = 5;
	map->colour->colour_loop = 1;
	colour_codes(map->colour, map);
	set_z_step(map->colour);
	centre_point(map);
	set_camera_angle(map);
	set_camera_point(map, 0, 0, 0);
	window_key(map);
	plot_points(map);
}

void	esc_program(t_map *map)
{
	free_map (map);
	exit(1);
}
