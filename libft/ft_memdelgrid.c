/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdelgrid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:08:37 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/11 15:40:04 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdelgrid(void **array, size_t y, size_t x)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!array)
		return ;
	if (y == 0 || x == 0)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_memdel(&(array[y][x]));
			x++;
		}
		y++;
	}
	*array = NULL;
}
