/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:31:18 by deelliot          #+#    #+#             */
/*   Updated: 2022/07/11 15:40:14 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *list)
{
	t_list	*temp;

	temp = list;
	if (!list)
		return ;
	while (temp != NULL)
	{
		ft_putstr(temp->content);
		ft_putchar('\n');
		temp = temp->next;
	}
	ft_putchar('\n');
}
