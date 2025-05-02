/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:21:32 by mivogel           #+#    #+#             */
/*   Updated: 2025/05/02 10:09:41 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	freesplit(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}

static int	getdouble(char *s, char **str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (!ft_strncmp(s, str[i], INT_MAX))
			return (1);
		i++;
	}
	return (0);
}

static int	isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	valid_input(char **av)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		if (!isnum(av[i]))
			return (0);
		if (getdouble(av[i], av, i))
			return (0);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX || ft_strlen(av[i]) > 12)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av++;
	if (!av || !valid_input(av))
	{
		if (ac == 2)
			freesplit(av);
		return (0);
	}
	*stack_a = ft_init(av);
	if (!*stack_a)
	{
		if (ac == 2)
			freesplit(av);
		return (0);
	}
	*stack_b = NULL;
	if (ac == 2)
		freesplit(av);
	return (1);
}
