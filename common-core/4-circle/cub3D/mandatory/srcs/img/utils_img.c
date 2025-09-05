/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:34:21 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/07 11:57:46 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pix_index(t_image *img, int x, int y)
{
	return (y * img->size_line + x * (img->bpp / 8));
}

int	get_texture_color(t_image *texture, int x, int y, int type)
{
	if (type == WALL)
	{
		if (x < 0 || y < 0 || x >= WALL_TEX_WIDTH || y >= WALL_TEX_HEIGHT)
			return (0);
		return (*(int *)(texture->image->data + pix_index(texture, x, y)));
	}
	return (0);
}

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0)
		return ;
	pixel = img->data + pix_index(img, x, y);
	*(int *)pixel = color;
}
