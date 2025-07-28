/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:01 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/27 11:15:42 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	raycast(t_data *data)
// {
// 	M_PI;
// 	//RAYCAST
// 	float theta; 
// 	int x = data->player.posX;
// 	int y = data->player.posY;
// 	int dx;
// 	int dy;
// 	int tileStepX; // direction of next tile
// 	int tileStepY; // direction of next tile
// 	float xStep = tan(theta);
// 	float yStep = 1/tan(theta);
// 	float xIntercept = x + dx + (-dy/tan(theta));
// 	float yIntercept = y + dy + dx/tan(theta);
// 	int hitVert;
// 	int hitHoriz;
// 	float p;	// distance from player to perpendicular plan of the intersection
// 				// in short p = deltaX * cos(beta) + deltaY * sin (beta);
// 	float deltaX = xIntercept - x;
// 	float deltaY = yIntercept - y;

// 	//SCALING
// 	float wallHeight

// 	while (yIntercept < y)
// 	{
// 		if (data->map.map[x][(int)yIntercept] == '1')
// 		{	
// 			hitVert = 1;
// 			break;
// 		}
// 		x += tileStepX;
// 		yIntercept += yStep;
// 	}
// 		while (xIntercept < x)
// 	{
// 		if (data->map.map[(int)xIntercept][y] == '1')
// 		{	
// 			hitHoriz = 1;
// 			break;
// 		}		y += tileStepY;
// 		xIntercept += xStep;
// 	}
// }

void draw_raycast(t_data *data, float angle)
{
	float rayDirX = cos(angle);
	float rayDirY = sin(angle);
	float deltaDistX = fabs(1 / rayDirX);
	float deltaDistY = fabs(1 / rayDirY);
	int stepX;
	int stepY;
	float sideDistX;
	float sideDistY;
	int hit = 0;
	int side;

	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (data->player.posX - (int)data->player.posX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = ((int)data->player.posX + 1.0 - data->player.posX) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (data->player.posY - (int)data->player.posY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = ((int)data->player.posY + 1.0 - data->player.posY) * deltaDistY;
	}

	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			data->player.posX += stepX;
			side = 0; // vertical wall
		}
		else
		{
			sideDistY += deltaDistY;
			data->player.posY += stepY;
			side = 1; // horizontal wall
		}
		
		if (data->map.map[(int)data->player.posY][(int)data->player.posX] == '1')
			hit = 1;
	}

	int lineHeight = (int)(data->frame.height / (side == 0 ? rayDirX : rayDirY));
	int drawStart = -lineHeight / 2 + data->frame.height / 2;
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = lineHeight / 2 + data->frame.height / 2;
	if (drawEnd >= data->frame.height)
		drawEnd = data->frame.height - 1;

	int color = (side == 0) ? COLOR_BLUE : COLOR_GREEN; // Different colors for walls

	for (int y = drawStart; y < drawEnd; y++)
	{
		img_pix_put(&data->frame, (int)data->player.posX, y, color);
	}
}

void raycasting(t_data *data)
{
	float angle;
	int screenWidth = data->frame.width;
	int screenHeight = data->frame.height;
	for (int x = 0; x < screenWidth; x++)
	{
		angle = data->player.angle + atan((x - screenWidth / 2) / (screenHeight / (2 * tan(M_PI / 6))));
		draw_raycast(data, angle);
	}
}

// Note: This is a simplified version of raycasting. In a complete implementation, you would also need to handle texture mapping, lighting, and other effects.
// This code assumes that the map is a 2D array of characters where '1' represents walls and '0' represents empty space.

// The function `draw_raycast` performs the raycasting for a single ray at a given angle, checking for wall intersections and drawing the resulting line on the frame.
// The `raycasting` function iterates over each pixel in the screen width, calculating the angle for each ray and calling `draw_raycast` to render it.

// The raycasting algorithm uses the DDA (Digital Differential Analyzer) method to traverse the grid of the map, checking for wall intersections and calculating the height of the wall to draw on the screen.
// The color of the walls is determined based on whether they are vertical or horizontal, which can be adjusted as needed.
// This code is a basic implementation and can be expanded with additional features such as texture mapping, lighting effects, and more complex player movement mechanics.

// Note: The code provided is a simplified version of raycasting and may require additional features such as texture mapping, lighting, and player movement mechanics to be fully functional in a game context.