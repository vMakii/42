/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:35:02 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/24 15:55:18 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_array(char **tab)
{
	int	i;

	if (!tab)
		printf("(null)\n");
	else
	{
		i = 0;
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
}

void	print_data_map(t_data data)
{
	printf("-------------\nDATA.MAP\n");
	printf("> NO: %s\n", data.texture.north_texture);
	printf("> SO: %s\n", data.texture.south_texture);
	printf("> WE: %s\n", data.texture.west_texture);
	printf("> EA: %s\n", data.texture.east_texture);
	printf("> F: %d\n", data.texture.floor_color);
	printf("> C: %d\n", data.texture.ceiling_color);
	printf("> Map:\n");
	print_array(data.map.map);
	printf("-------------\n");
}
