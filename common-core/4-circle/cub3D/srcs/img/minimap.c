/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:51:44 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/28 14:28:02 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define _USE_MATH_DEFINES
#define _USE_MISC
#include <math.h>

void	init_ray(t_pos player, int *tileStepX, int *tileStepY)
{
	// printf("dirX ray: %0.2f\n",player.dirX);
	// printf("dirY ray: %0.2f\n",player.dirY);
	// *tileStepX = signof(player.dirX);
	// *tileStepY = signof(player.dirY);
	if (player.angle >= 0 && player.angle < M_PI_2)
	{
		*tileStepX = 1	;
		*tileStepY = 1;
	}
	else if (player.angle >= M_PI_2 && player.angle < M_PI)
	{
		*tileStepX = -1;
		*tileStepY = 1;
	}
	else if (player.angle >= M_PI && player.angle < 3 * M_PI_2)
	{
		*tileStepX = 1;
		*tileStepY = 1;
	}
	else if (player.angle >= 3 * M_PI_2 && player.angle < 2 * M_PI)
	{
		*tileStepX = 1;
		*tileStepY = -1;
	}
}

t_pos	raycast(t_data *data)
{
	//RAYCAST
	t_pos	ray;
	int x = (int)data->player.posX;
	int y = (int)data->player.posY;
	float dx = data->player.posX - (float)x;
	float dy = data->player.posY - (float)y;
	int tileStepX; // direction of next tile
	int tileStepY; // direction of next tile
	init_ray(data->player, &tileStepX, &tileStepY);
	float xStep = tanf(data->player.angle);
	float yStep = 1 / xStep;
	float xIntercept = x + dx + (float)tileStepX * dy / tanf(data->player.angle);
	float yIntercept = y + dy + (float)tileStepY * dx / tanf(data->player.angle);
	int hitVert = 0;
	int hitHoriz = 0;
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("dx = %0.1f\n", dx);
	printf("dy = %0.1f\n", dy);
	printf("tileStepX = %d\n", tileStepX);
	printf("tileStepY = %d\n", tileStepY);
	printf("angle = %0.2f\n", data->player.angle);
	printf("xStep = %0.1f\n", xStep);
	printf("yStep = %0.1f\n", yStep);
	printf("xIntercept = %0.1f\n", xIntercept);
	printf("yIntercept = %0.1f\n", yIntercept);
	while (!hitHoriz && !hitVert && yIntercept > 0 && xIntercept > 0 && y > 0 && x > 0)
	{

		while (!hitHoriz && x != yIntercept)
		{
			x += tileStepX;
			yIntercept += yStep;
			if (data->map.map[(int)yIntercept][x] == '1')
			{	
				hitVert = 1;
				break;
			}
		}
		while (!hitVert && y != xIntercept)
		{
			y += tileStepY;
			xIntercept += xStep;
			if (data->map.map[y][(int)xIntercept] == '1')
			{	
				hitHoriz = 1;
				break;
			}
		}
	}
	if (hitVert == 1)
	{
		ray.posX = x;
		ray.posY = yIntercept;
	}
	if (hitHoriz == 1)
	{
		ray.posX = xIntercept;
		ray.posY = y;
	}
	return (ray);
}

void	draw_ray(t_img * frame, t_pos player, t_pos ray)
{
	printf("ray x= %0.2f, y= %0.2f\n\n", ray.posX, ray.posY);
	draw_line(frame, player.posX * (MINIMAP_SCALE + 1), 
		player.posY * (MINIMAP_SCALE + 1),
		ray.posX * MINIMAP_SCALE, ray.posY * MINIMAP_SCALE, COLOR_RED);
}

// void	draw_cone(t_img *frame, t_pos player)
// {

// }

void	draw_player(t_data *data)
{
	t_rect	player_rect;
	// t_pos	ray;

	init_rect(&player_rect, 6);
	player_rect.x = data->player.posX * (MINIMAP_SCALE + 1) - player_rect.width / 2;
	player_rect.y = data->player.posY * (MINIMAP_SCALE + 1) - player_rect.height / 2;
	render_rect(&data->frame, player_rect, COLOR_RED);
	// ray = raycast(data);
	// draw_ray(&data->frame, data->player, ray);
	draw_line(&data->frame, data->player.posX * (MINIMAP_SCALE + 1),
		data->player.posY * (MINIMAP_SCALE + 1),
		data->player.posX * (MINIMAP_SCALE + 1) + data->player.dirX * MINIMAP_SCALE,
		data->player.posY * (MINIMAP_SCALE + 1) + data->player.dirY * MINIMAP_SCALE, COLOR_RED);
	// exit_failure(data, "END OF TEST");
}

void	render_minimap(t_data *data)
{
	int		x;
	int		y;
	t_rect	to_draw;

	y = 0;
	init_rect(&to_draw, MINIMAP_SCALE);
	while (data->map.map[y])
	{
		x = 0;
		to_draw.x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == '1')
				render_rect(&data->frame, to_draw, COLOR_BLUE);
			if (data->map.map[y][x] == FLOOR)
				render_rect(&data->frame, to_draw, COLOR_WHITE);
			if (data->map.map[y][x] == 'N' || data->map.map[y][x] == 'S'
				|| data->map.map[y][x] == 'W' || data->map.map[y][x] == 'E')
				render_rect(&data->frame, to_draw, COLOR_WHITE);
			to_draw.x += to_draw.width + 1;
			x++;
		}
		to_draw.y += to_draw.height + 1;
		y++;	
	}
	draw_player(data);
}
