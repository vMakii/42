/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:44:33 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/27 14:00:29 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			img_pix_put(&data->frame, j, i, data->texture.floor_color);
			j++;
		}
		i++;
	}
	i = WIN_HEIGHT / 2;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			img_pix_put(&data->frame, j, i, data->texture.ceiling_color);
			j++;
		}
		i++;
	}
}

void	render_player(t_data *data)
{
	if (data->player_data.action == MOVING)
	{
		upscale_img_to_frame(data, MOVING);
	}
	else if (data->player_data.action == ATTACKING)
	{
		upscale_img_to_frame(data, ATTACKING);
	}
	else
	{
		upscale_img_to_frame(data, IDLE);
	}
}

int	render_frame(t_data *data)
{
	if (data->mlx.ptr == NULL)
		return (1);
	data->frame.image = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->frame.data = mlx_get_data_addr((void *)data->frame.image,
			&data->frame.bpp, &data->frame.size_line,
			&data->frame.image->byte_order);
	render_background(data);
	// printf("%d\n", data->player_data.action);
	render_player(data);
	render_minimap(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->frame.image, 0,
		0);
	mlx_do_sync(data->mlx.ptr);
	mlx_destroy_image(data->mlx.ptr, data->frame.image);
	return (0);
}
