/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:06:37 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/26 15:22:54 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker(t_list **a, t_list **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_op(a, b, line);
		free(tmp);
	}
	if (*b || !ft_is_sorted(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	if (ac < 2 || !ft_check(ac, av, &a, &b))
	{
		ft_printf("Error\n");
		return (0);
	}
	line = get_next_line(0);
	if (!line && !ft_is_sorted(a))
		ft_printf("KO\n");
	else if (!line && ft_is_sorted(a))
		ft_printf("OK\n");
	else
		checker(&a, &b, line);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
