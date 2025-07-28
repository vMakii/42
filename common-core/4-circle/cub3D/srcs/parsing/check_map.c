/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:15:17 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/23 11:33:26 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_map_elem(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] != '1' && data->map.map[i][j] != '0'
				&& data->map.map[i][j] != 'N' && data->map.map[i][j] != 'S'
				&& data->map.map[i][j] != 'E' && data->map.map[i][j] != 'W'
				&& data->map.map[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_map_player(t_data *data)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
			{
				data->map.player[0] = i;
				data->map.player[1] = j;
				player++;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (false);
	return (true);
}

static bool	floodfill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[x] || !map[x][y] || map[x][y] == ' ')
	{
		map[x][y] = 'X';
		return (false);
	}
	if (x < 0 || y < 0 || !map[x] || !map[x][y] || map[x][y] == '1')
		return (true);
	if (map[x][y] == '0' || map[x][y] == 'N' || map[x][y] == 'S'
		|| map[x][y] == 'E' || map[x][y] == 'W')
	{
		map[x][y] = '1';
		return (floodfill(map, x + 1, y) && floodfill(map, x - 1, y)
			&& floodfill(map, x, y + 1) && floodfill(map, x, y - 1));
	}
	return (true);
}

bool	check_map_floodfill(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (!floodfill(map, i, j))
					return (ft_freetab(map), false);
			}
			j++;
		}
		i++;
	}
	return (ft_freetab(map), true);
}

bool	check_map(t_data *data)
{
	char	**cpy;

	if (!check_map_nl(data->map.str))
		return (false);
	if (!check_map_elem(data))
		return (false);
	if (!check_map_player(data))
		return (false);
	cpy = ft_tabcpy(data->map.map);
	if (!cpy)
		return (false);
	if (!check_map_floodfill(cpy))
		return (false);
	return (true);
}
