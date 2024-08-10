/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:14:34 by mivogel           #+#    #+#             */
/*   Updated: 2024/08/10 09:20:40 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = begin_list;
	while (elem->data)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}
