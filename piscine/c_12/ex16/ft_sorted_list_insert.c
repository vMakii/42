/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:25:49 by mivogel           #+#    #+#             */
/*   Updated: 2024/10/05 22:30:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->data = data;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*e;

	if (!*begin_list || cmp(data, (*begin_list)->data) <= 0)
	{
		e = ft_create_elem(data);
		if (!(e))
			return ;
		e->next = *begin_list;
		*begin_list = e;
	}
	else
	{
		ft_sorted_list_insert(&(*begin_list)->next, data, cmp);
	}
}
