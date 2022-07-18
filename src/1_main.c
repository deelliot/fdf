/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:38:30 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/18 09:25:22 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		if (argc == 1)
			ft_putendl("Usage : ./fdf <filename>");
		else
			ft_putendl("Error: Too many arguments");
		return (0);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		handle_errors("unable to malloc for map struct", map);
	map = initialise_map(map);
	store_data(argv[1], map);
	initilise_camera_and_colour(map);
	mlx_key_hook(map->win, handle_input, map);
	window_key(map);
	plot_points(map);
	return (0);
}
