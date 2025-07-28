/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:14:30 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/28 14:51:49 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	give_player_direction(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player.angle = 3 * M_PI_2 ;
		data->player.dirX = cos(data->player.angle);
		data->player.dirY = sin(data->player.angle);
	}
	else if (c == 'S')
	{
		data->player.angle = M_PI_2;
		data->player.dirX = cos(data->player.angle);
		data->player.dirY = sin(data->player.angle);
	}
	else if (c == 'W')
	{
		data->player.angle = M_PI;
		data->player.dirX = cos(data->player.angle);
		data->player.dirY = sin(data->player.angle);
	}
	else if (c == 'E')
	{
		data->player.angle = 0;
		data->player.dirX = cos(data->player.angle);
		data->player.dirY = sin(data->player.angle);
	}
}

void	get_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
			{
				data->player.posX = j + 0.5;
				data->player.posY = i + 0.5;
				give_player_direction(data, data->map.map[i][j]);
			}
			j++;
		}
		i++;
	}
}

bool	get_map(t_data *data)
{
	int	i;
	int	len;

	len = 6;
	while (data->map.tab[len])
		len++;
	len -= 5;
	data->map.map = gc_malloc(len * sizeof(char *), &data->gc_list);
	if (!data->map.map)
		return (false);
	i = 6;
	while (data->map.tab[i])
	{
		data->map.map[i - 6] = ft_strdup(data->map.tab[i]);
		if (!data->map.map[i - 6])
			return (false);
		gc_add_malloc(data->map.map[i - 6], &data->gc_list);
		i++;
	}
	data->map.map[i - 6] = NULL;
	get_player_position(data);
	return (true);
}
