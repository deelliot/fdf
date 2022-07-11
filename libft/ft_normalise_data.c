/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalise_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:37:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/09 10:29:38 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* normalises data to between 0 - 100 */

double	normalise_data(double min, double max, double num)
{
	double	temp;

	temp = (num - min) / (max - min) * 100;
	return (temp);
}
