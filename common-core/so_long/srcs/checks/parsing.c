/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:38:27 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/08 21:31:05 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_walls(char **tab, int len)
{
	int	i;
	int	j;
	int	max_i;

	i = -1;
	max_i = 0;
	while (tab[++i])
	{
		j = -1;
		if (max_i < i)
			max_i = i;
		while (tab[i][++j])
		{
			if (len < j)
				return (ft_printf("Error: not rectangular\n"), 0);
			if (tab[0][j] != '1' || tab[i][0] != '1' || tab[i][len] != '1')
				return (ft_printf("Error: no outer wall\n"), 0);
		}
	}
	j = -1;
	while (tab[max_i][++j])
		if (tab[max_i][j] != '1')
			return (ft_printf("Error: no outer wall\n"), 0);
	return (1);
}

int	ft_contains(char **tab)
{
	int			i;
	int			j;
	static int	p = 0;
	static int	c = 0;
	static int	e = 0;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'P')
				p++;
			else if (tab[i][j] == 'C')
				c++;
			else if (tab[i][j] == 'E')
				e++;
		}
	}
	if (p != 1 || c < 1 || e != 1)
		return (ft_printf("Error: multiple or no key(s) element(s)\n"), 0);
	return (1);
}

static void	ft_floodfill(char **tab, int x, int y)
{
	if (tab[x][y] == '1' || tab[x][y] == 'V' || tab[x][y] == 'E')
		return ;
	tab[x][y] = 'V';
	ft_floodfill(tab, x - 1, y);
	ft_floodfill(tab, x + 1, y);
	ft_floodfill(tab, x, y - 1);
	ft_floodfill(tab, x, y + 1);
}

static int	validmap(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'C' || tab[i][j] == 'S')
				return (0);
		}
	}
	return (1);
}

int	ft_validexit(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'P')
				ft_floodfill(tab, i, j);
		}
	}
	if (!validmap(tab))
	{
		ft_freetab(tab);
		return (printf("Error: map not valid\n"), 0);
	}
	else
	{
		ft_freetab(tab);
		return (1);
	}
}
