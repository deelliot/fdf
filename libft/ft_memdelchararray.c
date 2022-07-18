/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdelchararray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:34:43 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/17 17:43:48 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdelchararray(char ***array)
{
	int		i;
	char	**temp;

	if (!array)
		return ;
	i = 0;
	temp = *array;
	while (temp[i])
	{
		free (temp[i]);
		temp[i] = NULL;
		i++;
	}
	free (temp);
	*array = NULL;
}
