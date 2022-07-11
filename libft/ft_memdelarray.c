/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdelarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:03:20 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/11 15:38:28 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdelarray(void *array, size_t y)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	if (y == 0)
		return ;
	while (i < y)
	{
		ft_memdel(&(array[y]));
		y++;
	}
	array = NULL;
}
