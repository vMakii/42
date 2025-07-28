/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upscale_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:34:31 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/25 15:25:00 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_get_pixel(void *img, int x, int y)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	return (*(int *)(data + (y * size_line + x * (bpp / 8))));
}

void	mlx_put_pixel(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	if (color == (int)0xFF000000)
		return ;
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	*(int *)(data + (y * size_line + x * (bpp / 8))) = color;
}

void	upscale_img_loop(t_img *frame, t_sprite *sprite, int scale, int dest_x,
		int dest_y)
{
	int	x;
	int	y;
	int	new_x;
	int	new_y;
	int	pixel_color;

	y = -1;
	while (++y < sprite->height)
	{
		x = -1;
		while (++x < sprite->width)
		{
			pixel_color = mlx_get_pixel(sprite->img, x, y);
			new_y = -1;
			while (++new_y < scale)
			{
				new_x = -1;
				while (++new_x < scale)
					mlx_put_pixel(frame, dest_x + x * scale + new_x, dest_y + y
						* scale + new_y, pixel_color);
			}
		}
	}
}

void	upscale_img(t_data *data, t_sprite *sprite, int scale, int dest_x,
		int dest_y)
{
	upscale_img_loop(&data->frame, sprite, scale, dest_x, dest_y);
}

void	upscale_img_to_frame(t_data *data, t_action action)
{
	if (action == MOVING)
	{
		if (frame_count < 60)
		{
			upscale_img(data, &data->sprite_list.player_right2, UPSCALING,
				WIN_WIDTH - (data->sprite_list.player_right2.width * UPSCALING),
				WIN_HEIGHT - (data->sprite_list.player_right2.height
					* UPSCALING));
			upscale_img(data, &data->sprite_list.player_left1, UPSCALING, 0,
				WIN_HEIGHT - (data->sprite_list.player_left1.height
					* UPSCALING));
		}
		else
		{
			upscale_img(data, &data->sprite_list.player_right1, UPSCALING,
				WIN_WIDTH - (data->sprite_list.player_right1.width * UPSCALING),
				WIN_HEIGHT - (data->sprite_list.player_right1.height
					* UPSCALING));
			upscale_img(data, &data->sprite_list.player_left2, UPSCALING, 0,
				WIN_HEIGHT - (data->sprite_list.player_left2.height
					* UPSCALING));
		}
	}
	else if (action == ATTACKING)
	{
		upscale_img(data, &data->sprite_list.player_sword1, UPSCALING, WIN_WIDTH
			- (data->sprite_list.player_sword1.width * UPSCALING), WIN_HEIGHT
			- (data->sprite_list.player_sword1.height * UPSCALING));
	}
	else // IDLE
	{
		upscale_img(data, &data->sprite_list.player_right1, UPSCALING, WIN_WIDTH
			- (data->sprite_list.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->sprite_list.player_right1.height * UPSCALING));
		upscale_img(data, &data->sprite_list.player_left1, UPSCALING, 0,
			WIN_HEIGHT - (data->sprite_list.player_left1.height * UPSCALING));
	}
}
