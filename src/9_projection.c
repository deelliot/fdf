/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_projection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:48:25 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/14 22:31:24 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*	0 = top down
	1 = isometric
	2 = random
	3 = cabinet
*/

void	set_camera_point(t_map *map, double x, double y, double z)
{
	map->camera->point->x = x * map->scale;
	map->camera->point->y = y * map->scale;
	map->camera->point->z = z * map->scale;
}

void	set_camera_angle(t_map *map)
{
	if (map->projection == 0)
	{
		map->camera->alpha = 0.0;
		map->camera->beta = 0.0;
		map->camera->gamma = 0.0;
	}
	else if (map->projection == 1)
	{
		map->camera->alpha = 0.615472907;
		map->camera->beta = 0.785398;
		map->camera->gamma = 0;
	}
	else if (map->projection == 2)
	{
		map->camera->alpha = 0.923599;
		map->camera->beta = 0;
		map->camera->gamma = -0.7;
	}
	else
	{
		map->camera->alpha = 0.523598776;
		map->camera->beta = 0;
		map->camera->gamma = 0;
	}
}

double	**projection(double angle, t_map *map)
{
	double	**projection;

	projection = (double **)ft_memallocarray(3, 3);
	if (! projection)
		return (NULL);
	projection[0][0] = 1;
	projection[0][1] = 0;
	if (map->projection == 3)
		projection[0][2] = 0.5 * cos(angle);
	else
		projection[0][2] = 0;
	projection[1][0] = 0;
	projection[1][1] = 1;
	if (map->projection == 3)
		projection[1][2] = 0.5 * sin(angle);
	else
		projection[1][2] = 0;
	projection[2][0] = 0;
	projection[2][1] = 0;
	projection[2][2] = 0;
	return (projection);
}
