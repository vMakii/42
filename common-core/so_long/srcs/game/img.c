/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:54:04 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/12 23:00:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_load_img(t_data *data, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->sprite.height,
			&data->sprite.width);
	if (!img)
	{
		ft_printf("Error: mlx_xpm_file_to_image failed\n");
		ft_close(data);
	}
	return (img);
}

void	*get_wall_texture(t_data *data, int i, int j)
{
	if (i == 0 && j == 0)
		return (data->sprite.walls.wall_l1);
	else if (i == 0 && j == data->map.width - 1)
		return (data->sprite.walls.wall_r1);
	else if (i == data->map.height - 1 && j == 0)
		return (data->sprite.walls.wall_l3);
	else if (i == data->map.height - 1 && j == data->map.width - 1)
		return (data->sprite.walls.wall_r3);
	else if (i == 0)
		return (data->sprite.walls.wall_t);
	else if (i == data->map.height - 1)
		return (data->sprite.walls.wall_b);
	else if (j == 0)
		return (data->sprite.walls.wall_l2);
	else if (j == data->map.width - 1)
		return (data->sprite.walls.wall_r2);
	return (NULL);
}

void	ft_img_outerwalls(t_data *data)
{
	data->sprite.walls.wall_l1 = ft_load_img(data, WALL_L1);
	data->sprite.walls.wall_l2 = ft_load_img(data, WALL_L2);
	data->sprite.walls.wall_l3 = ft_load_img(data, WALL_L3);
	data->sprite.walls.wall_r1 = ft_load_img(data, WALL_R1);
	data->sprite.walls.wall_r2 = ft_load_img(data, WALL_R2);
	data->sprite.walls.wall_r3 = ft_load_img(data, WALL_R3);
	data->sprite.walls.wall_t = ft_load_img(data, WALL_T);
	data->sprite.walls.wall_b = ft_load_img(data, WALL_B);
}

void	ft_img_inner(t_data *data)
{
	data->sprite.walls.wall = ft_load_img(data, WALL);
	data->sprite.floor = ft_load_img(data, FLOOR);
	data->sprite.coin = ft_load_img(data, COIN);
	data->sprite.exit1 = ft_load_img(data, EXIT1);
	data->sprite.exit2 = ft_load_img(data, EXIT2);
	data->sprite.player.player_r1 = ft_load_img(data, PLAYER_R1);
	data->sprite.player.player_r2 = ft_load_img(data, PLAYER_R2);
	data->sprite.player.player_l1 = ft_load_img(data, PLAYER_L1);
	data->sprite.player.player_l2 = ft_load_img(data, PLAYER_L2);
	data->sprite.skull.skull_l1 = ft_load_img(data, SKULL_L1);
	data->sprite.skull.skull_l2 = ft_load_img(data, SKULL_L2);
	data->sprite.skull.skull_r1 = ft_load_img(data, SKULL_R1);
	data->sprite.skull.skull_r2 = ft_load_img(data, SKULL_R2);
}

void	ft_img(t_data *data)
{
	ft_img_outerwalls(data);
	ft_img_inner(data);
}
