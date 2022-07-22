/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_store.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:05:37 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/22 15:05:47 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	open_file(char *argv, t_map *map)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		handle_errors(map);
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
				handle_errors(map);
			map->row += 1;
		}
		else if (ret < 0)
			handle_errors(map);
		else
			break ;
		free (line);
	}
	close (fd);
}

static void	store(char *line, t_map *map, int y)
{
	char	**temp;
	int		x;

	temp = ft_strsplit(line, ' ');
	if (!temp)
		handle_errors(map);
	x = 0;
	while (temp[x])
	{
		if (ft_strcmp(temp[x], "") == 0)
			handle_errors(map);
		map->map[y][x] = ft_atoi(temp[x]);
		x++;
	}
	ft_memdelchararray(&temp);
}

static void	store_map(int fd, t_map *map)
{
	char	*line;
	int		y;

	map->map = (int **)ft_memallocarray(map->col, map->row);
	if (!map->map)
		handle_errors(map);
	y = 0;
	while (1)
	{
		if (get_next_line(fd, &line) == 1)
		{
			store(line, map, y);
			free (line);
			y++;
		}
		else if (get_next_line(fd, &line) < 0)
			handle_errors(map);
		else
			break ;
	}
	close (fd);
}

void	store_data(char *argv, t_map *map)
{
	get_rows_and_cols(open_file(argv, map), map);
	store_map(open_file(argv, map), map);
	centre_point(map);
}
