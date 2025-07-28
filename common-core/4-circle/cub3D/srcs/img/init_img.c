/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:25:26 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/27 12:52:18 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void load_img(t_data *data, t_sprite *sprite, char *path)
{
    ft_memset(sprite, 0, sizeof(t_sprite));
    sprite->img = mlx_xpm_file_to_image(data->mlx.ptr, path, &sprite->width, &sprite->height);
    if (!sprite->img)
        exit_failure(data, "Failed to load image");
    // sprite->img = gc_add_malloc(sprite->img, &data->gc_list);
}

void  destroy_img(t_data *data)
{
    if (data->sprite_list.north.img)
       mlx_destroy_image(data->mlx.ptr, data->sprite_list.north.img);
    if (data->sprite_list.south.img)
        mlx_destroy_image(data->mlx.ptr, data->sprite_list.south.img);
    if (data->sprite_list.east.img)
        mlx_destroy_image(data->mlx.ptr, data->sprite_list.east.img);
    if (data->sprite_list.west.img)
        mlx_destroy_image(data->mlx.ptr, data->sprite_list.west.img);
    if (data->sprite_list.player_left1.img)
        mlx_destroy_image(data->mlx.ptr, data->sprite_list.player_left1.img);
    if (data->sprite_list.player_left2.img)
        mlx_destroy_image(data->mlx.ptr, data->sprite_list.player_left2.img);
    if (data->sprite_list.player_right1.img)
        mlx_destroy_image(data->mlx.ptr, data->sprite_list.player_right1.img);
    if (data->sprite_list.player_right2.img)
        mlx_destroy_image(data->mlx.ptr, data->sprite_list.player_right2.img);
}

static void loader(t_data *data)
{
    load_img(data, &data->sprite_list.north, data->texture.north_texture);
    load_img(data, &data->sprite_list.south, data->texture.south_texture);
    load_img(data, &data->sprite_list.west, data->texture.west_texture);
    load_img(data, &data->sprite_list.east, data->texture.east_texture);
    load_img(data, &data->sprite_list.player_left1, "./assets/cub3d/xpm_output/fist_l1.xpm");
    load_img(data, &data->sprite_list.player_left2, "./assets/cub3d/xpm_output/fist_l2.xpm");
    load_img(data, &data->sprite_list.player_right1, "./assets/cub3d/xpm_output/fist_r1.xpm");
    load_img(data, &data->sprite_list.player_right2, "./assets/cub3d/xpm_output/fist_r2.xpm");
    load_img(data, &data->sprite_list.player_sword1, "./assets/cub3d/xpm_output/sword1.xpm");
}

// static void upscaler(t_data *data)
// {
//     upscale_img(data, &data->sprite_list.player_right1, 5);
//     upscale_img(data, &data->sprite_list.player_right2, 5);
//     upscale_img(data, &data->sprite_list.player_left1, 5);
//     upscale_img(data, &data->sprite_list.player_left2, 5);
//     upscale_img(data, &data->sprite_list.player_sword1, 5);
// }

void init_img(t_data *data)
{
    ft_memset(&data->sprite_list, 0, sizeof(t_sprite_list));
    loader(data);
    // upscaler(data);
}
