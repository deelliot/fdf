/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_key_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:02:49 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/17 18:00:21 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_input(int key, t_map *map)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == IN \
	|| key == OUT)
		handle_translation(key, map);
	if (key == ZOOM_IN || key == ZOOM_OUT)
		handle_zoom(key, map);
	if (key == PROJECTION)
		handle_projection(map);
	if (key == X_CLOCK || key == X_ANTI || key == Y_CLOCK || key == Y_ANTI || \
		key == Z_CLOCK || key == Z_ANTI)
		handle_rotation(key, map);
	if (key == COLOUR)
		handle_colour(map);
	if (key == RESET)
		handle_reset(map);
	if (key == ESC)
		esc_program(map);
	return (0);
}

void	window_key(t_map *map)
{
	char	*str[9];
	int		i;

	str[0] = "MOVE:          W, S, A, D";
	str[1] = "ZOOM:          I and O";
	str[2] = "PROJECTION:    P";
	str[3] = "ROTATE X-AXIS: X and C";
	str[4] = "ROTATE Y-AXIS: Y and U";
	str[5] = "COLOUR:        SPACE";
	str[6] = "RESET:         ENTER";
	str[7] = "Z-AXIS:        ARROW KEYS";
	str[8] = "QUIT:          ESC";
	i = 0;
	while (i < 8)
	{
		mlx_string_put(map->mlx, map->win, 20, 20 + (i * 15), 0xFFFFFF, str[i]);
		i++;
	}
}
