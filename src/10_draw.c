/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:15:59 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/20 16:09:27 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	create_image(t_img *image)
// {
// 	image->mlx_img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
// 		if (!image->mlx_img)
// 			handle_errors("unable to create image", map);
// 	image->addr = mlx_get_data_addr(image->mlx_img, &image->bpp, \
// 	&image->line_len, &image->endian);
// 	printf("bpp: %d || line_len: %d || endian: %d\n",image->bpp, image->line_len, image->endian);
// }

// void	img_pix_put(t_img *image, int x, int y, int colour)
// {
// 	char *pixel;

// 	pixel = image->addr + ((y * image->line_len) + (x * (image->bpp / 8)));
// }

void	draw_horizontal_line(t_map *map, t_algo *points)
{
	double	x;
	double	y;
	int		i;

	points->dx = points->p[1]->x - points->p[0]->x;
	points->dy = points->p[1]->y - points->p[0]->y;
	if (ft_abs(points->dx) >= ft_abs(points->dy))
		points->step = ft_abs(points->dx);
	else
		points->step = ft_abs(points->dy);
	points->dx = points->dx / points->step;
	points->dy = points->dy / points->step;
	set_colour_step(map, points->p[0], points->p[1], points->step);
	x = points->p[0]->x;
	y = points->p[0]->y;
	i = 1;
	while (i <= points->step)
	{
		mlx_pixel_put(map->mlx, map->win, x, y, map->colour.colour);
		x += points->dx;
		y += points->dy;
		set_colour(&map->colour);
		i++;
	}
}

void	draw_vertical_line(t_map *map, t_algo *points)
{
	double	x;
	double	y;
	int		i;

	points->dx = points->p[2]->x - points->p[0]->x;
	points->dy = points->p[2]->y - points->p[0]->y;
	if (ft_abs(points->dx) >= ft_abs(points->dy))
		points->step = ft_abs(points->dx);
	else
		points->step = ft_abs(points->dy);
	points->dx = points->dx / points->step;
	points->dy = points->dy / points->step;
	set_colour_step(map, points->p[0], points->p[2], points->step);
	x = points->p[0]->x;
	y = points->p[0]->y;
	i = 1;
	while (i <= points->step)
	{
		mlx_pixel_put(map->mlx, map->win, x, y, map->colour.colour);
		x += points->dx;
		y += points->dy;
		set_colour(&map->colour);
		i++;
	}
}
