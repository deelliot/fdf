/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_colour.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:56:38 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/19 14:27:31 by deelliot         ###   ########.fr       */
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

static t_rgb	hex_to_rgb(int colour)
{
	t_rgb	col;

	col.r = (colour >> 16) & 0xFF;
	col.g = (colour >> 8) & 0xFF;
	col.b = colour & 0xFF;
	return (col);
}

void	colour_codes(t_col *colour)
{
	if (colour->colour_loop == 0)
	{
		colour->min_col = hex_to_rgb(0xFFFFFF);
		colour->max_col = hex_to_rgb(0xFF0000);
	}
	else if (colour->colour_loop == 1)
	{
		colour->min_col = hex_to_rgb(0xFFFF00);
		colour->max_col = hex_to_rgb(0x800080);
	}
	else if (colour->colour_loop == 2)
	{
		colour->min_col = hex_to_rgb(0xFFA500);
		colour->max_col = hex_to_rgb(0x0000FF);
	}
	else if (colour->colour_loop == 3)
	{
		colour->min_col = hex_to_rgb(0x3A3B3C);
		colour->max_col = hex_to_rgb(0xFFFFFF);
	}
	else
	{
		colour->min_col = hex_to_rgb(0x9C4F96);
		colour->max_col = hex_to_rgb(0x2AA8F2);
	}
}

void	set_z_step(t_col *colour)
{
	colour->z_step.r = (colour->max_col.r - colour->min_col.r) / 100;
	colour->z_step.g = (colour->max_col.g - colour->min_col.g) / 100;
	colour->z_step.b = (colour->max_col.b - colour->min_col.b) / 100;
}

void	set_colour_step(t_map *map, t_point *p0, t_point *p1, double step)
{
	t_rgb	start;
	t_rgb	end;

	start.r = map->colour.min_col.r + (p0->norm_z * map->colour.z_step.r);
	start.g = map->colour.min_col.g + (p0->norm_z * map->colour.z_step.g);
	start.b = map->colour.min_col.b + (p0->norm_z * map->colour.z_step.b);
	end.r = map->colour.min_col.r + (p1->norm_z * map->colour.z_step.r);
	end.g = map->colour.min_col.g + (p1->norm_z * map->colour.z_step.g);
	end.b = map->colour.min_col.b + (p1->norm_z * map->colour.z_step.b);
	map->colour.step.r = (end.r - start.r) / step;
	map->colour.step.g = (end.g - start.g) / step;
	map->colour.step.b = (end.b - start.b) / step;
	map->colour.colour = rgb_to_hex(start.r, start.g, start.b);
	map->colour.current = start;
	printf("colour = %d\n", map->colour.colour);
}

void	set_colour(t_col *colour)
{
	colour->current.r += colour->step.r;
	printf("colour current r %f += colour step r %f\n",colour->current.r, colour->step.r);
	colour->current.g += colour->step.g;
	colour->current.b += colour->step.b;
	colour->colour = rgb_to_hex(colour->current.r, colour->current.g, \
	colour->current.b);
	if (colour->colour <= 0)
		colour->colour = rgb_to_hex(colour->min_col.r, colour->min_col.g, \
		colour->min_col.b);
}
