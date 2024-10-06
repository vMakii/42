/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:07:33 by mivogel           #+#    #+#             */
/*   Updated: 2024/10/04 15:10:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list, t_list *begin_list2)
{
	t_list	*t_list;

	if (begin_list == 0 || *begin_list == 0)
		*begin_list = begin_list2;
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = begin_list2;
	}
}
