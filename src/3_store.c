/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_store.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:36:11 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/18 12:15:01 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	open_file(char *argv, t_map *map)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		handle_errors("unable to open file", map);
	return (fd);
}

static void	get_rows_and_cols(int fd, t_map *map)
{
	int		ret;
	char	*line;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			if (map->col == 0)
				map->col = ft_count_words(line, ' ');
			if (ft_count_words(line, ' ') != map->col)
				handle_errors("invalid map", map);
			map->row += 1;
		}
		else if (ret < 0)
			handle_errors("GNL error", map);
		else
			break ;
		free (line);
	}
	close (fd);
}

static void	store_map(int fd, t_map *map)
{
	char	*line;
	int		y;
	int		x;
	char	**temp;

	map->map = (int **)ft_memallocarray(map->col, map->row);
	if (!map->map)
		handle_errors("unable to malloc for map array", map);
	y = 0;
	while (get_next_line(fd, &line))
	{
		temp = ft_strsplit(line, ' ');
		x = 0;
		while (temp[x])
		{
			if (ft_strcmp(temp[x], "") == 0)
				handle_errors("error in file", map);
			map->map[y][x] = ft_atoi(temp[x]);
			x++;
		}
		ft_memdelchararray(&temp);
		free (line);
		y++;
	}
	close (fd);
}

void	centre_point(t_map *map)
{
	map->x_offset = (WIDTH - (map->col * map->scale)) / 2;
	map->y_offset = (HEIGHT - map->row * (map->scale)) / 2;
}

void	store_data(char *argv, t_map *map)
{
	get_rows_and_cols(open_file(argv, map), map);
	store_map(open_file(argv, map), map);
	centre_point(map);
}
