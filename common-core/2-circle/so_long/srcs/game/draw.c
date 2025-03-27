/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:09:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/12 22:59:00 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_outerwalls(t_data *data)
{
	int		i;
	int		j;
	void	*wall_img;

	i = -1;
	while (data->map.tab[++i])
	{
		j = -1;
		while (data->map.tab[i][++j])
		{
			wall_img = get_wall_texture(data, i, j);
			if (wall_img)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall_img,
					j * 32, i * 32);
		}
	}
}

void	ft_draw_inner(t_data *data, int i, int j)
{
	if (data->map.tab[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite.walls.wall, j * 32, i * 32);
	else if (data->map.tab[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite.floor, j * 32, i * 32);
	else if (data->map.tab[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.coin,
			j * 32, i * 32);
	else if (data->map.tab[i][j] == 'E')
	{
		if (data->map.nbcoin == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.exit2, j * 32, i * 32);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.exit1, j * 32, i * 32);
	}
	else if (data->map.tab[i][j] == 'P')
		ft_draw_player(data, i, j);
	else if (data->map.tab[i][j] == 'S')
		ft_draw_skull(data, i, j);
}

void	ft_draw_player(t_data *data, int i, int j)
{
	if (data->sprite.player.dir == 'R')
	{
		if (data->mov % 2 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.player.player_r1, j * 32, i * 32);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.player.player_r2, j * 32, i * 32);
	}
	else if (data->sprite.player.dir == 'L')
	{
		if (data->mov % 2 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.player.player_l1, j * 32, i * 32);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.player.player_l2, j * 32, i * 32);
	}
}

void	ft_draw_skull(t_data *data, int i, int j)
{
	if (data->sprite.skull.dir == 'R')
	{
		if (data->mov_skull % 2 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.skull.skull_r1, j * 32, i * 32);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.skull.skull_r2, j * 32, i * 32);
	}
	else if (data->sprite.skull.dir == 'L')
	{
		if (data->mov_skull % 2 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.skull.skull_l1, j * 32, i * 32);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprite.skull.skull_l2, j * 32, i * 32);
	}
}

void	ft_draw(t_data *data)
{
	int	i;
	int	j;

	ft_draw_outerwalls(data);
	i = 0;
	while (data->map.tab[++i + 1])
	{
		j = 0;
		while (data->map.tab[i][++j + 1])
		{
			ft_draw_inner(data, i, j);
		}
	}
	ft_display_moves(data);
}
