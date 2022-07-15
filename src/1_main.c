/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:38:30 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/15 14:57:29 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
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
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		handle_errors("unable to open file", map);
	store_data(fd, map);
	initilise_camera_and_colour(map);
	mlx_key_hook(map->win, handle_input, map);
	window_key(map);
	plot_points(map);
	return (0);
}
