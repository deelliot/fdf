/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:38:30 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/22 14:57:48 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_putendlerror("Usage : ./fdf <filename>");
		return (0);
	}
	initialise_map(&map);
	store_data(argv[1], &map);
	initilise_camera_and_colour(&map);
	mlx_hook(map.win, KEY_DOWN, 0, handle_input, &map);
	window_key(&map);
	plot_points(&map);
	return (0);
}
