/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:00:38 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/25 14:51:48 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countcoins(char **tab)
{
	int	n;
	int	i;
	int	j;

	i = 0;
	n = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

t_coord	ft_getpos(char **tab, char c)
{
	int		i;
	int		j;
	t_coord	coord;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
			{
				coord.x = i;
				coord.y = j;
			}
			j++;
		}
		i++;
	}
	return (coord);
}

t_coord	ft_coord(int i, int j)
{
	t_coord	new;

	new.x = i;
	new.y = j;
	return (new);
}

t_coord	*ft_getcoins_pos(char **tab, int nbcoin)
{
	int		i;
	int		j;
	int		n;
	t_coord	*coins;

	i = 0;
	n = 0;
	coins = malloc(sizeof(t_coord) * nbcoin);
	while (tab[i] && n <= nbcoin)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				coins[n++] = ft_coord(i, j);
			j++;
		}
		i++;
	}
	return (coins);
}

t_map	ft_map(int fd)
{
	t_map	map;

	map.tab = ft_readmap(fd);
	if (!map.tab)
		exit(0);
	map.nb = 0;
	map.mov = 0;
	map.nbcoin = ft_countcoins(map.tab);
	map.player = ft_getpos(map.tab, 'P');
	map.coins = ft_getcoins_pos(map.tab, map.nbcoin);
	map.exit = ft_getpos(map.tab, 'E');
	return (map);
}
