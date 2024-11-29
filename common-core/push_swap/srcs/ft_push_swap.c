/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:38:55 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/29 12:09:04 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args(char **av)
{
	int	i;
	int	tmp;

	i = 1;
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		if (!tmp)
			;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (!check_args(av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	// a = ft_init(ac, av);
}
