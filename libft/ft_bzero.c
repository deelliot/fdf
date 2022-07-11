/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:03:12 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/08 10:39:51 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The bzero() function writes n zeroed bytes to the string s. If n is zero,
bzero() does nothing.*/

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, '\0', n);
}
