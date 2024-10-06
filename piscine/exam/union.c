/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:46:53 by mivogel           #+#    #+#             */
/*   Updated: 2024/10/03 18:46:55 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char c, char *str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_union(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!check(s1[i], s1, i))
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (check(s2[i], s2, i) && !(check(s2[i], s1, ft_strlen(s1))))
			write(1, &s2[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char *av[])
{
	int	i;

	if (ac == 3)
	{
		ft_union(av[1], av[2]);
	}
}
