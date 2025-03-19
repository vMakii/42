/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skull_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:16:41 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/19 14:04:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_skull(t_data *data)
{
	int	x;
	int	y;

	x = data->map.player.x - data->map.skull.x;
	y = data->map.player.y - data->map.skull.y;
	ft_move_skull_1(data, x, y);
	ft_move_skull_2(data, x, y);
}

void	ft_move_skull_1(t_data *data, int x, int y)
{
	if (y == 0 && x > 0)
		return (ft_move_skull_down(data));
	else if (y == 0 && x < 0)
		return (ft_move_skull_up(data));
	else if (x == 0 && y > 0)
		return (ft_move_skull_right(data));
	else if (x == 0 && y < 0)
		return (ft_move_skull_left(data));
}

void	ft_move_skull_2(t_data *data, int x, int y)
{
	if (x > 0 && y > 0 && x > y)
		return (ft_move_skull_down(data));
	else if (x > 0 && y > 0 && x <= y)
		return (ft_move_skull_right(data));
	else if (x > 0 && y < 0)
	{
		if (x > -y)
			return (ft_move_skull_down(data));
		else
			return (ft_move_skull_left(data));
	}
	else if (x < 0 && y > 0)
	{
		if (-x > y)
			return (ft_move_skull_up(data));
		else
			return (ft_move_skull_right(data));
	}
	else if (x < 0 && y < 0)
	{
		if (-x > -y)
			return (ft_move_skull_up(data));
		else
			return (ft_move_skull_left(data));
	}
}
