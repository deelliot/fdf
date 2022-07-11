/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memallocarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:08:41 by deelliot          #+#    #+#             */
/*   Updated: 2022/06/05 22:26:45 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a “fresh” 2D array.
The memory allocated is initialized to 0.
If the allocation fails, the function returns NULL.*/

void	**ft_memallocarray(size_t x, size_t y)
{
	void	**temp;
	size_t	i;

	i = 0;
	if (x == 0 || y == 0)
		return (NULL);
	temp = (void **)malloc(sizeof(*temp) * y);
	if (temp == NULL)
		return (NULL);
	while (i < y)
	{
		temp[i] = (void *)malloc(sizeof(*temp) * x);
		if (temp[i] == NULL)
			return (NULL);
		ft_memset(temp[i], '\0', x);
		i++;
	}
	return (temp);
}
