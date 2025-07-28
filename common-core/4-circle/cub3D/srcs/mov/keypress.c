/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:44:24 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/27 18:22:55 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moving_angle(t_pos *player, float unit)
{
	player->angle += unit;
	if (player->angle < 0 || player->angle >= 2 * M_PI)
		player->angle += 0;
	player->dirX = cos(player->angle);
	player->dirY = sin(player->angle);
}

// void	update_player_status(t_data *data, t_action action)
// {
// 	if (action == MOVING)
// 		data->player_data.action = MOVING;
// 	else if (action == ATTACKING)
// 		data->player_data.action = ATTACKING;
// 	else
// 		data->player_data.action = IDLE; // Default
// }

void	moving_position(t_data *data, float dx, float dy)
{
	int	x;
	int	y;

	// update_player_status(data, MOVING);
	data->player_data.action = MOVING;
	x = (int)(data->player.posX + dx);
	y = (int)(data->player.posY + dy);
	if (data->map.map[y][x] != WALL)
	{
		data->player.posY += dy;
		data->player.posX += dx;
	}
}

void	player_move(t_data *data)
{
	float	unit;

	unit = 0.05;
	if (data->keys.key_w)
		moving_position(data, 0, -unit);
	if (data->keys.key_s)
		moving_position(data, 0, unit);
	if (data->keys.key_a)
		moving_position(data, -unit, 0);
	if (data->keys.key_d)
		moving_position(data, unit, 0);
	if (data->keys.key_left)
		moving_angle(&data->player, -unit);
	if (data->keys.key_right)
		moving_angle(&data->player, unit);
	if (data->keys.key_up)
		moving_position(data, unit * signof(data->player.dirX),
			unit * signof(data->player.dirY));
	if (data->keys.key_down)
		moving_position(data, -unit * signof(data->player.dirX),
			-unit * signof(data->player.dirY));
}

void attack(t_data *data)
{
	// update_player_status(data, ATTACKING);
	data->player_data.action = ATTACKING;
	printf("Player is attacking!\n");
	// Here you can add logic for attacking, like checking for enemies, etc.
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_success(data);
	if (keysym == XK_w )
		data->keys.key_w = 1;
	else if (keysym == XK_s)
		data->keys.key_s = 1;
	else if (keysym == XK_a)
		data->keys.key_a = 1;
	else if (keysym == XK_d)
		data->keys.key_d = 1;
	else if (keysym == XK_Left)
		data->keys.key_left = 1;
	else if (keysym == XK_Right)
		data->keys.key_right = 1;
	else if (keysym == XK_Up)
		data->keys.key_up = 1;
	else if (keysym == XK_Down)
		data->keys.key_down = 1; 
	if (keysym == XK_space)
		attack(data);
	return (0);
}
