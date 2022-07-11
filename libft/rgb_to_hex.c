/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:32:43 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/09 10:29:08 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rgb_to_hex(int red, int green, int blue)
{
	int	colour;

	colour = (blue) + (green << 8) + (red << 16);
	return (colour);
}
