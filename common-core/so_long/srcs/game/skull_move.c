/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skull_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:51:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/20 11:51:07 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_skull_up(t_data *data)
{
	if (data->map.tab[data->map.skull.x - 1][data->map.skull.y] == '1'
		|| data->map.tab[data->map.skull.x - 1][data->map.skull.y] == 'E'
		|| data->map.tab[data->map.skull.x - 1][data->map.skull.y] == 'C')
		return ;
	if (data->map.tab[data->map.skull.x - 1][data->map.skull.y] == 'P')
	{
		ft_printf("\e[1;31mYou lose!\e[0m\n");
		ft_close(data);
	}
	data->map.tab[data->map.skull.x][data->map.skull.y] = '0';
	data->map.skull.x--;
	data->map.tab[data->map.skull.x][data->map.skull.y] = 'S';
	data->mov_skull++;
}

void	ft_move_skull_down(t_data *data)
{
	if (data->map.tab[data->map.skull.x + 1][data->map.skull.y] == '1'
		|| data->map.tab[data->map.skull.x + 1][data->map.skull.y] == 'E'
		|| data->map.tab[data->map.skull.x + 1][data->map.skull.y] == 'C')
		return ;
	if (data->map.tab[data->map.skull.x + 1][data->map.skull.y] == 'P')
	{
		ft_printf("\e[1;31mYou lose!\e[0m\n");
		ft_close(data);
	}
	data->map.tab[data->map.skull.x][data->map.skull.y] = '0';
	data->map.skull.x++;
	data->map.tab[data->map.skull.x][data->map.skull.y] = 'S';
	data->mov_skull++;
}

void	ft_move_skull_left(t_data *data)
{
	if (data->map.tab[data->map.skull.x][data->map.skull.y - 1] == '1'
		|| data->map.tab[data->map.skull.x][data->map.skull.y - 1] == 'E'
		|| data->map.tab[data->map.skull.x][data->map.skull.y - 1] == 'C')
		return ;
	if (data->map.tab[data->map.skull.x][data->map.skull.y - 1] == 'P')
	{
		ft_printf("\e[1;31mYou lose!\e[0m\n");
		ft_close(data);
	}
	data->map.tab[data->map.skull.x][data->map.skull.y] = '0';
	data->map.skull.y--;
	data->sprite.skull.dir = 'L';
	data->map.tab[data->map.skull.x][data->map.skull.y] = 'S';
	data->mov_skull++;
}

void	ft_move_skull_right(t_data *data)
{
	if (data->map.tab[data->map.skull.x][data->map.skull.y + 1] == '1'
		|| data->map.tab[data->map.skull.x][data->map.skull.y + 1] == 'E'
		|| data->map.tab[data->map.skull.x][data->map.skull.y + 1] == 'C')
		return ;
	if (data->map.tab[data->map.skull.x][data->map.skull.y + 1] == 'P')
	{
		ft_printf("\e[1;31mYou lose!\e[0m\n");
		ft_close(data);
	}
	data->map.tab[data->map.skull.x][data->map.skull.y] = '0';
	data->map.skull.y++;
	data->sprite.skull.dir = 'R';
	data->map.tab[data->map.skull.x][data->map.skull.y] = 'S';
	data->mov_skull++;
}
