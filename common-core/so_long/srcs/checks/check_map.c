/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/24 12:48:23 by mivogel          ###   ########.fr       */
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

t_coord	*ft_getskulls(char **tab, int nbskull)
{
	int		i;
	int		j;
	int		skull;
	t_coord	*skulls;

	if (nbskull == 0)
		return (NULL);
	i = -1;
	skull = 0;
	skulls = malloc(sizeof(t_coord) * nbskull);
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'S')
				skulls[skull++] = ft_coord(i, j);
		}
	}
	return (skulls);
}

int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (ft_printf("Error\nConsecutive newline\n"), 0);
		i++;
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'S' && str[i] != '\n')
			return (ft_printf("Error\nMap contains invalid item(s)\n"), 0);
	}
	return (1);
}

t_map	ft_map(int fd)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	map.tab = ft_readmap(fd);
	if (!map.tab)
		exit(0);
	map.nbcoin = ft_countitems(map.tab, 'C');
	map.nbskull = ft_countitems(map.tab, 'S');
	map.height = ft_tablen(map.tab);
	map.width = ft_strlen(map.tab[0]);
	map.player = ft_getpos(map.tab, 'P');
	map.coins = ft_getcoins_pos(map.tab, map.nbcoin);
	if (map.nbskull)
		map.skulls = ft_getskulls(map.tab, map.nbskull);
	map.exit = ft_getpos(map.tab, 'E');
	return (map);
}

int	ft_parsing(t_map map)
{
	int		len;
	char	**cpy;

	len = ft_strlen(map.tab[0]) - 1;
	cpy = ft_mapcpy(map.tab);
	if (map.width > 60 || map.height > 30)
	{
		ft_printf("Error\nMap too big\n");
		return (ft_freetab(cpy), 0);
	}
	if (!ft_walls(map.tab, len) || !ft_contains(map.tab) || !ft_validexit(cpy))
		return (ft_freetab(cpy), 0);
	ft_freetab(cpy);
	return (1);
}
