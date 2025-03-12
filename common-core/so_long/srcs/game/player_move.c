/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:11:49 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/12 23:00:53 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_close(data);
	if (keycode == XK_w)
		ft_move_up(data);
	if (keycode == XK_s)
		ft_move_down(data);
	if (keycode == XK_a)
		ft_move_left(data);
	if (keycode == XK_d)
		ft_move_right(data);
	if (data->map.skull.x > 0 && data->map.skull.y > 0 && data->mov % 2 == 0)
		ft_move_skull(data);
	ft_draw(data);
	return (0);
}

void	ft_move_up(t_data *data)
{
	if (data->map.tab[data->map.player.x - 1][data->map.player.y] == '1')
		return ;
	if (data->map.tab[data->map.player.x - 1][data->map.player.y] == 'C')
		data->map.nbcoin--;
	if (ft_wincond(data, data->map.player.x - 1, data->map.player.y))
		return ;
	ft_losecond(data, data->map.player.x - 1, data->map.player.y);
	data->map.tab[data->map.player.x][data->map.player.y] = '0';
	data->map.player.x--;
	data->map.tab[data->map.player.x][data->map.player.y] = 'P';
	data->mov++;
}

void	ft_move_down(t_data *data)
{
	if (data->map.tab[data->map.player.x + 1][data->map.player.y] == '1')
		return ;
	if (data->map.tab[data->map.player.x + 1][data->map.player.y] == 'C')
		data->map.nbcoin--;
	if (ft_wincond(data, data->map.player.x + 1, data->map.player.y))
		return ;
	ft_losecond(data, data->map.player.x + 1, data->map.player.y);
	data->map.tab[data->map.player.x][data->map.player.y] = '0';
	data->map.player.x++;
	data->map.tab[data->map.player.x][data->map.player.y] = 'P';
	data->mov++;
}

void	ft_move_left(t_data *data)
{
	if (data->map.tab[data->map.player.x][data->map.player.y - 1] == '1')
		return ;
	if (data->map.tab[data->map.player.x][data->map.player.y - 1] == 'C')
		data->map.nbcoin--;
	if (ft_wincond(data, data->map.player.x, data->map.player.y - 1))
		return ;
	ft_losecond(data, data->map.player.x, data->map.player.y - 1);
	data->map.tab[data->map.player.x][data->map.player.y] = '0';
	data->map.player.y--;
	data->sprite.player.dir = 'L';
	data->map.tab[data->map.player.x][data->map.player.y] = 'P';
	data->mov++;
}

void	ft_move_right(t_data *data)
{
	if (data->map.tab[data->map.player.x][data->map.player.y + 1] == '1')
		return ;
	if (data->map.tab[data->map.player.x][data->map.player.y + 1] == 'C')
		data->map.nbcoin--;
	if (ft_wincond(data, data->map.player.x, data->map.player.y + 1))
		return ;
	ft_losecond(data, data->map.player.x, data->map.player.y + 1);
	data->map.tab[data->map.player.x][data->map.player.y] = '0';
	data->map.player.y++;
	data->sprite.player.dir = 'R';
	data->map.tab[data->map.player.x][data->map.player.y] = 'P';
	data->mov++;
}
