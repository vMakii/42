/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skull_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:16:41 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/24 13:03:12 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_skull(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < data->map.nbskull)
	{
		x = data->map.player.x - data->map.skulls[i].x;
		y = data->map.player.y - data->map.skulls[i].y;
		ft_move_skull_1(data, i, x, y);
		ft_move_skull_2(data, i, x, y);
		i++;
	}
}

void	ft_move_skull_1(t_data *data, int i, int x, int y)
{
	if (y == 0 && x > 0)
		return (ft_move_skull_down(data, i));
	else if (y == 0 && x < 0)
		return (ft_move_skull_up(data, i));
	else if (x == 0 && y > 0)
		return (ft_move_skull_right(data, i));
	else if (x == 0 && y < 0)
		return (ft_move_skull_left(data, i));
}

void	ft_move_skull_2(t_data *data, int i, int x, int y)
{
	if (x > 0 && y > 0 && x > y)
		return (ft_move_skull_down(data, i));
	else if (x > 0 && y > 0 && x <= y)
		return (ft_move_skull_right(data, i));
	else if (x > 0 && y < 0)
	{
		if (x > -y)
			return (ft_move_skull_down(data, i));
		else
			return (ft_move_skull_left(data, i));
	}
	else if (x < 0 && y > 0)
	{
		if (-x > y)
			return (ft_move_skull_up(data, i));
		else
			return (ft_move_skull_right(data, i));
	}
	else if (x < 0 && y < 0)
	{
		if (-x > -y)
			return (ft_move_skull_up(data, i));
		else
			return (ft_move_skull_left(data, i));
	}
}
