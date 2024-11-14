/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:00:24 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/14 13:03:41 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_node(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*node;

	content = f(lst->content);
	if (!content)
	{
		del(content);
		return (NULL);
	}
	node = ft_lstnew(content);
	if (!node)
	{
		del(content);
		return (NULL);
	}
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_create_node(lst, f, del);
	if (!head)
		return (NULL);
	tmp = head;
	while (lst->next)
	{
		tmp->next = ft_create_node(lst->next, f, del);
		if (!tmp->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
