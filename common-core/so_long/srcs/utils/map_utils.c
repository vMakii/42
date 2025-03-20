/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:00:38 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/20 13:07:39 by mivogel          ###   ########.fr       */
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

char	**ft_readmap(int fd)
{
	char	*str;
	char	*line;
	char	**tab;

	str = ft_strdup("");
	if (!str)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nEmpty file\n");
		return (NULL);
	}
	while (line)
	{
		str = ft_strjoin_free(str, line);
		free(line);
		line = get_next_line(fd);
	}
	if (!ft_check_str(str))
		return (NULL);
	tab = ft_split(str, '\n');
	free(str);
	return (tab);
}
