/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:04:14 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/12 15:57:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map map)
{
	ft_freetab(map.tab);
	free(map.coins);
}

void	ft_destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprite.walls.wall_l1);
	mlx_destroy_image(data->mlx_ptr, data->sprite.walls.wall_l2);
	mlx_destroy_image(data->mlx_ptr, data->sprite.walls.wall_l3);
	mlx_destroy_image(data->mlx_ptr, data->sprite.walls.wall_r1);
	mlx_destroy_image(data->mlx_ptr, data->sprite.walls.wall_r2);
	mlx_destroy_image(data->mlx_ptr, data->sprite.walls.wall_r3);
	mlx_destroy_image(data->mlx_ptr, data->sprite.walls.wall_t);
	mlx_destroy_image(data->mlx_ptr, data->sprite.walls.wall_b);
	mlx_destroy_image(data->mlx_ptr, data->sprite.walls.wall);
	mlx_destroy_image(data->mlx_ptr, data->sprite.floor);
	mlx_destroy_image(data->mlx_ptr, data->sprite.coin);
	mlx_destroy_image(data->mlx_ptr, data->sprite.exit1);
	mlx_destroy_image(data->mlx_ptr, data->sprite.exit2);
	mlx_destroy_image(data->mlx_ptr, data->sprite.player.player_r1);
	mlx_destroy_image(data->mlx_ptr, data->sprite.player.player_r2);
	mlx_destroy_image(data->mlx_ptr, data->sprite.player.player_l1);
	mlx_destroy_image(data->mlx_ptr, data->sprite.player.player_l2);
	mlx_destroy_image(data->mlx_ptr, data->sprite.skull.skull_l1);
	mlx_destroy_image(data->mlx_ptr, data->sprite.skull.skull_l2);
	mlx_destroy_image(data->mlx_ptr, data->sprite.skull.skull_r1);
	mlx_destroy_image(data->mlx_ptr, data->sprite.skull.skull_r2);
}

int	ft_close(t_data *data)
{
	ft_destroy_image(data);
	ft_free_map(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
