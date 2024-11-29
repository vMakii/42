/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:38:55 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/29 10:18:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_args(int ac.char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
	}
}

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	if (ac < 2)
		return (1);
	if (!check_args(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = ft_init(ac, av);
}
