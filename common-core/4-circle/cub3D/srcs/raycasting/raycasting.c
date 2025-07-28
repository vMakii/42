/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:12:28 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/27 11:15:42 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

// #define RGB(r, g, b) ((r << 16) | (g << 8) | b)
#define COLOR_RED     0xFF0000
#define COLOR_GREEN   0x00FF00
#define COLOR_BLUE    0x0000FF
#define COLOR_WHITE   0xFFFFFF
#define COLOR_BLACK   0x000000
#define COLOR_YELLOW  0xFFFF00

static void verLine(t_data *data, int x, int y1, int y2, int color)
{
    int y;
    
    if (y1 > y2)
    {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }
    
    for (y = y1; y <= y2; y++)
    {
        if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
            mlx_pixel_put(data->mlx.ptr, data->mlx.win, x, y, color);
    }
}

void	raycasting(t_data *data)
{
	// data->player.posX = 22; //x and y start position
	// data->player.posY = 12;  
	// data->player.dirX = -1; //initial direction vector
	// data->player.dirY = 0; 

	float planeX = 0;  //the 2d raycaster version of camera plane
	float planeY = 0.66;

	float cameraX; //x-coordinate in camera space
	
	float rayDirX; // ray direction
	float rayDirY;

	int mapX; //which box of the map player is in
	int mapY;

	float sideDistX; //length of ray from current position to next x or y-side
	float sideDistY;

	float deltaDistX; //length of ray from one x or y-side to next x or y-side
	float deltaDistY;

	float perpWallDist;

	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;

	int hit = 0; //was there a wall hit?
	int side; //was a NS or a EW wall hit?

	for(int x = 0; x < WIN_WIDTH; x++)
	{
		//calculate ray position and direction
		cameraX = 2 * x / (float)WIN_WIDTH - 1; //x-coordinate in camera space
		rayDirX = data->player.dirX + planeX * cameraX;
		rayDirY = data->player.dirY + planeY * cameraX;
		//which box of the map we're in
		mapX = (int)data->player.posX;
		mapY = (int)data->player.posY;

		//length of ray from one x or y-side to next x or y-side
		//these are derived as:
		//deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
		//deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
		//which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
		//where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
		//unlike (dirX, dirY) is not 1, however this does not matter, only the
		//ratio between deltaDistX and deltaDistY matters, due to the way the DDA
		//stepping further below works. So the values can be computed as below.
		// Division through zero is prevented, even though technically that's not
		// needed in C++ with IEEE 754 floating point values.
		deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		hit = 0;
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->player.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->player.posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->player.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->player.posY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (data->map.map[mapX][mapY] > 0)
				hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		//choose wall color
		int color;
		switch(data->map.map[mapX][mapY])
		{
			case 1:  color = COLOR_BLUE;   break; //blue
			default: color = COLOR_YELLOW; break; //yellow
		}

		//give x and y sides different brightness	
		if(side == 1)
			color = color / 2;

		//draw the pixels of the stripe as a vertical line
		verLine(data, x, drawStart, drawEnd, color);
	}
}

// void	move()
// {
// 		//speed modifiers
// 	float moveSpeed = frameTime * 5.0; //the constant value is in squares/second
// 	float rotSpeed = frameTime * 3.0; //the constant value is in radians/second
// 	readKeys();
// 	//move forward if no wall in front of you
// 	if(keyDown(SDLK_UP))
// 	{
// 		if(worldMap[int(data->player.posX + data->player.dirX * moveSpeed)][int(data->player.posY)] == false) data->player.posX += data->player.dirX * moveSpeed;
// 		if(worldMap[int(data->player.posX)][int(data->player.posY + data->player.dirY * moveSpeed)] == false) data->player.posY += data->player.dirY * moveSpeed;
// 	}
// 	//move backwards if no wall behind you
// 	if(keyDown(SDLK_DOWN))
// 	{
// 		if(worldMap[int(data->player.posX - data->player.dirX * moveSpeed)][int(data->player.posY)] == false) data->player.posX -= data->player.dirX * moveSpeed;
// 		if(worldMap[int(data->player.posX)][int(data->player.posY - data->player.dirY * moveSpeed)] == false) data->player.posY -= data->player.dirY * moveSpeed;
// 	}
// 	//rotate to the right
// 	if(keyDown(SDLK_RIGHT))
// 	{
// 		//both camera direction and camera plane must be rotated
// 		float oldDirX = data->player.dirX;
// 		data->player.dirX = data->player.dirX * cos(-rotSpeed) - data->player.dirY * sin(-rotSpeed);
// 		data->player.dirY = oldDirX * sin(-rotSpeed) + data->player.dirY * cos(-rotSpeed);
// 		float oldPlaneX = planeX;
// 		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
// 		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
// 	}
// 	//rotate to the left
// 	if(keyDown(SDLK_LEFT))
// 	{
// 		//both camera direction and camera plane must be rotated
// 		float oldDirX = data->player.dirX;
// 		data->player.dirX = data->player.dirX * cos(rotSpeed) - data->player.dirY * sin(rotSpeed);
// 		data->player.dirY = oldDirX * sin(rotSpeed) + data->player.dirY * cos(rotSpeed);
// 		float oldPlaneX = planeX;
// 		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
// 		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
// 	}
// }

// void	timing(t_data *data)
// {
// 	//timing for input and FPS counter
// 	data->time.oldTime = data->time.time;
// 	data->time.time = getTicks();
// 	data->time.frameTime = (data->time.time - data->time.oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
// 	data->time.FPS = (1 / data->time.frameTime); //FPS counter
// }

// MAIN GAME LOOP FOR RENDERING:
// int main(int /*argc*/, char */*argv*/[])
// {
//   screen(screenWidth, screenHeight, 0, "Raycaster");
//   while(!done())
//   {
//		raycasting();
// 		move();
// 		timing(); //timing for input and FPS counter
// 		redraw(); //redraw screen
// 		cls(); //clear screen to black
//   }
// }