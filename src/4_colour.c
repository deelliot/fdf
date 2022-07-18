/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_colour.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:56:38 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/17 18:09:45 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
0 = white - red;
1 = yellow - purple;
2 = orange - blue;
3 = grey - white;
4 = rainbow
*/

static t_rgb	*hex_to_rgb(int colour, t_map *map)
{
	t_rgb	*col;

	col = (t_rgb *)malloc(sizeof(t_rgb));
	if (!col)
		handle_errors("unable to malloc for RGB col", map);
	col->r = (colour >> 16) & 0xFF;
	col->g = (colour >> 8) & 0xFF;
	col->b = colour & 0xFF;
	return (col);
}

void	colour_codes(t_col *colour, t_map *map)
{
	if (colour->colour_loop == 0)
	{
		colour->min_col = hex_to_rgb(0xFFFFFF, map);
		colour->max_col = hex_to_rgb(0xFF0000, map);
	}
	else if (colour->colour_loop == 1)
	{
		colour->min_col = hex_to_rgb(0xFFFF00, map);
		colour->max_col = hex_to_rgb(0x800080, map);
	}
	else if (colour->colour_loop == 2)
	{
		colour->min_col = hex_to_rgb(0xFFA500, map);
		colour->max_col = hex_to_rgb(0x0000FF, map);
	}
	else if (colour->colour_loop == 3)
	{
		colour->min_col = hex_to_rgb(0x3A3B3C, map);
		colour->max_col = hex_to_rgb(0xFFFFFF, map);
	}
	else
	{
		colour->min_col = hex_to_rgb(0x9C4F96, map);
		colour->max_col = hex_to_rgb(0x2AA8F2, map);
	}
}

void	set_z_step(t_col *colour)
{
	colour->z_step->r = (colour->max_col->r - colour->min_col->r) / 100;
	colour->z_step->g = (colour->max_col->g - colour->min_col->g) / 100;
	colour->z_step->b = (colour->max_col->b - colour->min_col->b) / 100;
}

void	set_colour_step(t_map *map, t_point *p0, t_point *p1, double step)
{
	t_rgb	*start;
	t_rgb	*end;

	start = map->colour->current;
	end = (t_rgb *)malloc(sizeof(t_rgb));
	if (!end)
		handle_errors("unable to malloc for RGB end", map);
	start->r = map->colour->min_col->r + (p0->norm_z * map->colour->z_step->r);
	start->g = map->colour->min_col->g + (p0->norm_z * map->colour->z_step->g);
	start->b = map->colour->min_col->b + (p0->norm_z * map->colour->z_step->b);
	end->r = map->colour->min_col->r + (p1->norm_z * map->colour->z_step->r);
	end->g = map->colour->min_col->g + (p1->norm_z * map->colour->z_step->g);
	end->b = map->colour->min_col->b + (p1->norm_z * map->colour->z_step->b);
	map->colour->step->r = (end->r - start->r) / step;
	map->colour->step->g = (end->g - start->g) / step;
	map->colour->step->b = (end->b - start->b) / step;
	map->colour->colour = rgb_to_hex(start->r, start->g, start->b);
	ft_memdel((void *)(&end));
}

void	set_colour(t_col *colour)
{
	colour->current->r += colour->step->r;
	colour->current->g += colour->step->g;
	colour->current->b += colour->step->b;
	colour->colour = rgb_to_hex(colour->current->r, colour->current->g, \
	colour->current->b);
}
