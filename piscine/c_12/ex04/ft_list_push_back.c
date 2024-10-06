/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:47:04 by mivogel           #+#    #+#             */
/*   Updated: 2024/08/14 17:11:27 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*list;

	elem = ft_create_elem(data);
	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
	else
		*begin_list = elem;
}
