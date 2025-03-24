/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skull_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:51:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/24 13:10:42 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_skull_up(t_data *data, int i)
{
	if (data->map.tab[data->map.skulls[i].x - 1][data->map.skulls[i].y] == '1'
		|| data->map.tab[data->map.skulls[i].x
		- 1][data->map.skulls[i].y] == 'E'
		|| data->map.tab[data->map.skulls[i].x
		- 1][data->map.skulls[i].y] == 'C'
		|| data->map.tab[data->map.skulls[i].x
		- 1][data->map.skulls[i].y] == 'S')
		return ;
	if (data->map.tab[data->map.skulls[i].x - 1][data->map.skulls[i].y] == 'P')
	{
		ft_printf("\e[1;31mYou lose!\e[0m\n");
		ft_close(data);
	}
	data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y] = '0';
	data->map.skulls[i].x--;
	data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y] = 'S';
	data->mov_skull++;
}

void	ft_move_skull_down(t_data *data, int i)
{
	if (data->map.tab[data->map.skulls[i].x + 1][data->map.skulls[i].y] == '1'
		|| data->map.tab[data->map.skulls[i].x
		+ 1][data->map.skulls[i].y] == 'E'
		|| data->map.tab[data->map.skulls[i].x
		+ 1][data->map.skulls[i].y] == 'C'
		|| data->map.tab[data->map.skulls[i].x
		+ 1][data->map.skulls[i].y] == 'S')
		return ;
	if (data->map.tab[data->map.skulls[i].x + 1][data->map.skulls[i].y] == 'P')
	{
		ft_printf("\e[1;31mYou lose!\e[0m\n");
		ft_close(data);
	}
	data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y] = '0';
	data->map.skulls[i].x++;
	data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y] = 'S';
	data->mov_skull++;
}

void	ft_move_skull_left(t_data *data, int i)
{
	if (data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y - 1] == '1'
		|| data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y
		- 1] == 'E'
		|| data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y
		- 1] == 'C'
		|| data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y
		- 1] == 'S')
		return ;
	if (data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y - 1] == 'P')
	{
		ft_printf("\e[1;31mYou lose!\e[0m\n");
		ft_close(data);
	}
	data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y] = '0';
	data->map.skulls[i].y--;
	data->sprite.skull.dir = 'L';
	data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y] = 'S';
	data->mov_skull++;
}

void	ft_move_skull_right(t_data *data, int i)
{
	if (data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y + 1] == '1'
		|| data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y
		+ 1] == 'E'
		|| data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y
		+ 1] == 'C'
		|| data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y
		+ 1] == 'S')
		return ;
	if (data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y + 1] == 'P')
	{
		ft_printf("\e[1;31mYou lose!\e[0m\n");
		ft_close(data);
	}
	data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y] = '0';
	data->map.skulls[i].y++;
	data->sprite.skull.dir = 'R';
	data->map.tab[data->map.skulls[i].x][data->map.skulls[i].y] = 'S';
	data->mov_skull++;
}
