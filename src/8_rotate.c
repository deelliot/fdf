/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:25:42 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/15 14:27:17 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	**rotate_x(double angle)
{
	double	**rot_x;

	rot_x = (double **)ft_memallocarray(3, 3);
	if (!rot_x)
		return (NULL);
	rot_x[0][0] = 1;
	rot_x[0][1] = 0;
	rot_x[0][2] = 0;
	rot_x[1][0] = 0;
	rot_x[1][1] = cos(angle);
	rot_x[1][2] = -sin(angle);
	rot_x[2][0] = 0;
	rot_x[2][1] = sin(angle);
	rot_x[2][2] = cos(angle);
	return (rot_x);
}

static double	**rotate_y(double angle)
{
	double	**rot_y;

	rot_y = (double **)ft_memallocarray(3, 3);
	if (!rot_y)
		return (NULL);
	rot_y[0][0] = cos(angle);
	rot_y[0][1] = 0;
	rot_y[0][2] = sin(angle);
	rot_y[1][0] = 0;
	rot_y[1][1] = 1;
	rot_y[1][2] = 0;
	rot_y[2][0] = -sin(angle);
	rot_y[2][1] = 0;
	rot_y[2][2] = cos(angle);
	return (rot_y);
}

static double	**rotate_z(double angle)
{
	double	**rot_z;

	rot_z = (double **)ft_memallocarray(3, 3);
	if (!rot_z)
		return (NULL);
	rot_z[0][0] = cos(angle);
	rot_z[0][1] = -sin(angle);
	rot_z[0][2] = 0;
	rot_z[1][0] = sin(angle);
	rot_z[1][1] = cos(angle);
	rot_z[1][2] = 0;
	rot_z[2][0] = 0;
	rot_z[2][1] = 0;
	rot_z[2][2] = 1;
	return (rot_z);
}

static void	matrix_multi(t_point *point, double **array, t_map *map)
{
	double	xt;
	double	yt;
	double	zt;

	if (!array)
		handle_errors("unable to malloc for matrix_multi array", map);
	xt = point->x;
	yt = point->y;
	zt = point->z;
	point->x = (xt * array[0][0]) + (yt * array[0][1]) + \
	(zt * array[0][2]);
	point->y = (xt * array[1][0]) + (yt * array[1][1]) + \
	(zt * array[1][2]);
	point->z = (xt * array[2][0]) + (yt * array[2][1]) + \
	(zt * array[2][2]);
}

void	rotate_point(t_map *map, t_algo *points)
{
	double	**proj;
	double	**rot_x;
	double	**rot_y;
	double	**rot_z;
	int		i;

	proj = projection(map->camera->alpha, map);
	rot_x = rotate_x(map->camera->alpha);
	rot_y = rotate_y(map->camera->beta);
	rot_z = rotate_z(map->camera->gamma);
	i = 0;
	while (i < 3)
	{
		translate_point(points->p[i], map->camera);
		matrix_multi(points->p[i], rot_z, map);
		matrix_multi(points->p[i], rot_x, map);
		matrix_multi(points->p[i], rot_y, map);
		matrix_multi(points->p[i], proj, map);
		offset_point(map, points->p[i]);
		i++;
	}
	ft_memdelarray((void **)proj, 3);
	ft_memdelarray((void **)rot_x, 3);
	ft_memdelarray((void **)rot_y, 3);
	ft_memdelarray((void **)rot_z, 3);
}
