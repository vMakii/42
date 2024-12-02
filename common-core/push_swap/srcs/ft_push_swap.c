/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:38:55 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/02 14:15:12 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!(ft_strlen(av[i]) == ft_strlen(ft_itoa(ft_atoi(av[i])))))
			return (0);
		if (ft_getdouble(av[i], av, i))
			return (0);
		if (ft_atoi(av[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_init(t_list **stack, char **av)
{
	t_list				*new;
	unsigned long long	content;
	int					i;

	i = 1;
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
}

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;

	b = NULL;
	if (ac < 2)
		exit(EXIT_FAILURE);
	if (!check_args(av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	a = (t_list **)malloc(sizeof(t_list *));
	*a = NULL;
	ft_init(a, av);
	while (*a)
	{
		ft_printf("%d\n", (*a)->content);
		*a = (*a)->next;
	}
	exit(EXIT_SUCCESS);
}
