/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:21:32 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/17 13:48:34 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_freesplit(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}

static int	ft_getdouble(char *s, char **str, int index)
{
	int	i;

	i = 1;
	while (i < index)
	{
		if (!ft_strncmp(s, str[i], INT_MAX))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	while (av[i])
	{
		if (!ft_isnum(av[i]))
			return (0);
		if (ft_getdouble(av[i], av, i))
			return (0);
		if (ft_atoi(av[i]) < 0)
			return (0);
		if (ft_strncmp(av[i], "2147483647", 12) == 0)
			return (0);
		i++;
	}
	if (ac == 2)
		ft_freesplit(av);
	return (1);
}

void	ft_init(t_list **stack, int ac, char **av)
{
	t_list				*new;
	unsigned long long	content;
	int					i;

	i = 1;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	while (av[i])
	{
		content = ft_atoi(av[i]);
		new = ft_lstnew((void *)content);
		if (!new)
		{
			ft_lstclear(stack, NULL);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(stack, new);
		i++;
	}
	if (ac == 2)
		ft_freesplit(av);
}
