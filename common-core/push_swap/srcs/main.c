/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:38:55 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/27 15:15:02 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_list **a, ta_list **b, const int size)
{
	if (!is_sorted(*a))
	{
		if (size == 2)
			ft_sa(a);
		else if (size == 3)
			ft_sort3(a);
		else if (size > 3)
			ft_sort(a, b);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;

	if (ac < 2 || !ft_check(ac, av, &a, &b))
		exit(EXIT_FAILURE);
	size = ft_lstsize(a);
	ft_getid(a, size);
	push_swap(&a, &b, size);
	ft_lstclear(&a);
	ft_lstclear(&b);
	exit(EXIT_SUCCES);
}
