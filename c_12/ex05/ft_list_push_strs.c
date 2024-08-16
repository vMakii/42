/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:45:05 by mivogel           #+#    #+#             */
/*   Updated: 2024/08/16 12:35:13 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	t_list	*elem;
	int		i;

	i = 0;
	begin_list = NULL;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		elem->next = begin_list;
		begin_list = elem;
		i++;
	}
	return (begin_list);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*begin;
	char	**strs;

	strs = malloc(sizeof(char*) * 5);
	strs[0] = "1";
	strs[1] = "2";
	strs[2] = "3";
	strs[3] = "4";
	strs[4] = "5";
	begin = ft_list_push_strs(5, strs);
	while (begin)
	{
		printf("%s\n", begin->data);
		begin = begin->next;
	}
}*/
