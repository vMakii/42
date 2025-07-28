/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:05:34 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/24 17:31:54 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab && tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }

static void	free_mlx(t_data *data)
{
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	if (data->mlx.ptr)
	{
		mlx_destroy_display(data->mlx.ptr);
		free(data->mlx.ptr);
	}
}

// static void	free_map(t_data *data)
// {
// 	if (data->map.str)
// 		free(data->map.str);
// 	if (data->map.tab)
// 		free_tab(data->map.tab);
// 	if (data->map.map)
// 		free_tab(data->map.map);
// 	if (data->map.north_texture)
// 		free(data->map.north_texture);
// 	if (data->map.south_texture)
// 		free(data->map.south_texture);
// 	if (data->map.west_texture)
// 		free(data->map.west_texture);
// 	if (data->map.east_texture)
// 		free(data->map.east_texture);
// }

void	free_all(t_data *data)
{
	destroy_img(data);
	if (data->gc_list)
		gc_free(&data->gc_list);
	free_mlx(data);
}
