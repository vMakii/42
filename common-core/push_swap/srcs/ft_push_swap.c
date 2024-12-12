/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:38:55 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/12 14:32:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_list **stack)
{
	ft_lstclear(stack, NULL);
	free(stack);
}

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (!ft_check_args(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	a = (t_list **)malloc(sizeof(t_list *));
	*a = NULL;
	ft_init(a, ac, av);
	if (ft_is_sorted(a))
	{
		ft_free_stack(a);
		exit(EXIT_SUCCESS);
	}
	b = (t_list **)malloc(sizeof(t_list *));
	*b = NULL;
	// ft_sort(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	exit(EXIT_SUCCESS);
}
