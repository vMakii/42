/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:43:41 by mivogel           #+#    #+#             */
/*   Updated: 2024/10/04 15:57:03 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		n;
	int		i;
	int		j;
	t_list	*list;
	void	*tmp;

	n = 0;
	list = begin_list;
	while (list && ++n)
		list = list->next;
	i = 0;
	while (i < n - 1)
	{
		j = i;
		list = begin_list;
		while (list && list->next && j < n - 1)
		{
			tmp = list->data;
			list->data = list->next->data;
			list->next->data = tmp;
			list = list->next;
			j++;
		}
		i++;
	}
}
