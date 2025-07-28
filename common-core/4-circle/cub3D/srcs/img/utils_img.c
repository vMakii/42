/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:34:21 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/27 11:15:42 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	RGB(u_int8_t r, u_int8_t g, u_int8_t b) 
{
	return ((r << 16) | (g << 8) | b);
}

//find index of the pixel in the address of the image
int	pix_index(t_img *img, int x, int y)
{
	return (y * img->size_line + x * (img->bpp / 8));
}

//put a pixel at (x, y) coordinates of the image
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	if (x < 0 || y < 0 /*|| x >= img->width || y >= img->height*/)
		return;
	pixel = img->data + pix_index(img, x, y);
	*(int *)pixel = color;
}

void	init_rect(t_rect *rect, float size)
{
	rect->x = 0;
	rect->y = 0;
	rect->width = size;
	rect->height = size;
}

int render_rect(t_img *img, t_rect rect, int color)
{
	float	i;
	float	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}

void	draw_line(t_img *img, int x1, int y1, int x2, int y2, int color)
{
	//Bresenham’s Line Algorithm
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		img_pix_put(img, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break;
		int err2 = err * 2;
		if (err2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}
