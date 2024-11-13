/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:52:05 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/13 09:53:48 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head->next;
		(*del)(head->content);
		free(head);
		head = tmp;
	}
	*lst = NULL;
}
