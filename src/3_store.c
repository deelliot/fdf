/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_store.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:36:11 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/14 19:29:30 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	centre_point(t_map *map)
{
	map->x_offset = (WIDTH - (map->col * map->scale)) / 2;
	map->y_offset = (HEIGHT - map->row * (map->scale)) / 2;
}

static void	store_map(t_map *map)
{
	int		y;
	int		x;
	char	**temp;

	map->map = (int **)ft_memallocarray(map->col, map->row);
	if (!map->map)
		handle_errors("unable to malloc for map array", map);
	y = 0;
	while (y < map->row)
	{
		x = 0;
		temp = ft_strsplit(map->list->content, ' ');
		if (!temp)
			handle_errors("unable to split string", map);
		while (x < map->col)
		{
			map->map[y][x] = ft_atoi(temp[x]);
			x++;
		}
		map->list = map->list->next;
		y++;
	}
	centre_point(map);
	ft_lstdel(&map->list, del);
	free (temp);
}

void	store_data(int fd, t_map *map)
{
	int		ret;
	char	*line;
	int		size;
	t_list	*node;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			size = sizeof(char *) * ft_strlen(line);
			if (map->col == 0)
				map->col = ft_count_words(line, ' ');
			node = ft_lstnew(line, size);
			ft_lstadd_back(&map->list, node);
			map->row += 1;
		}
		else if (ret < 0)
			handle_errors("GNL error", map);
		else
			break ;
	}
	free(line);
	store_map(map);
	close(fd);
}
