/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/08 22:57:37 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_mapcpy(char **tab)
{
	int		i;
	char	**cpy;

	i = 0;
	while (tab[i])
		i++;
	cpy = malloc(sizeof(char *) * (i + 1));
	if (!cpy)
		return (NULL);
	cpy[i] = NULL;
	while (--i >= 0)
	{
		cpy[i] = ft_strdup(tab[i]);
		if (!cpy[i])
			return (NULL);
	}
	return (cpy);
}

t_coord	ft_getskull(char **tab)
{
	int	i;
	int	j;
	int	skull;

	i = -1;
	skull = 0;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'S')
				skull++;
		}
	}
	if (skull != 1)
	{
		ft_printf("Error: multiple skull(s)\n");
		return (ft_coord(-1, -1));
	}
	return (ft_getpos(tab, 'S'));
}

int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (ft_printf("Error: consecutive newline"), 0);
		i++;
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'S' && str[i] != '\n')
			return (ft_printf("Error: map contains invalid item(s)"), 0);
	}
	return (1);
}

t_map	ft_map(int fd)
{
	t_map	map;

	map.tab = ft_readmap(fd);
	if (!map.tab)
		exit(0);
	map.nbcoin = ft_countcoins(map.tab);
	map.height = ft_tablen(map.tab);
	map.width = ft_strlen(map.tab[0]);
	map.skull = ft_getskull(map.tab);
	map.player = ft_getpos(map.tab, 'P');
	map.coins = ft_getcoins_pos(map.tab, map.nbcoin);
	map.exit = ft_getpos(map.tab, 'E');
	return (map);
}

int	ft_parsing(t_map map)
{
	int		len;
	char	**cpy;

	len = ft_strlen(map.tab[0]) - 1;
	cpy = ft_mapcpy(map.tab);
	if (!ft_walls(map.tab, len) || !ft_contains(map.tab) || !ft_validexit(cpy)
		|| map.skull.x == -1)
		return (0);
	return (1);
}
