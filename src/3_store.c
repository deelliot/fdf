/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_store.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:36:11 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/15 17:10:57 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_transpose_array(char const *s, char **array, int i, size_t len)
{
	if (len > 0)
	{
		array[i] = ft_strsub(s - len, 0, len);
		if (array[i])
			return (1);
		else
			return (0);
	}
	return (1);
}

static char	**ft_del_array(char **array, int i)
{
	while (i--)
		free (array[i]);
	free (array);
	return (NULL);
}

static char	**ft_assign_array(char **array, char const *s, char c)
{
	char	*start;
	int		i;
	int		words;

	i = 0;
	words = ft_count_words(s, c);
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		start = (char *)s;
		while (*s != c && *s)
			s++;
		if (ft_transpose_array(s, array, i, s - start) == 0)
			return (ft_del_array(array, i));
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	array = (char **)malloc(sizeof(*array) * (words + 1));
	if (array)
		array = ft_assign_array(array, s, c);
	return (array);
}


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
	t_list	*temp_list;

	temp_list = map->list;
	map->map = (int **)ft_memallocarray(map->col, map->row);
	if (!map->map)
		handle_errors("unable to malloc for map array", map);
	y = 0;
	while (y < map->row)
	{
		x = 0;
		temp = ft_split(temp_list->content, ' ');
		if (!temp)
			handle_errors("unable to split string", map);
		while (x < map->col)
		{
			map->map[y][x] = ft_atoi(temp[x]);
			free (temp[x]);
			x++;
		}
		temp_list = temp_list->next;
		y++;
	}
	free (temp);
	ft_lstdel(&temp_list, del);
	map->list = NULL;
	centre_point(map);
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
		free(line);
	}
	store_map(map);
	close(fd);
}
