/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:25:02 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/14 10:41:10 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_printf("Usage Error: [./so_long *.ber]\n"), 1);
	ft_memset(&data, 0, sizeof(t_data));
	data.map = ft_init_map(av[1]);
	if (!ft_parsing(data.map))
	{
		ft_free_map(data.map);
		return (0);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (ft_printf("Error: mlx initialization failed\n"), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width * 32,
			data.map.height * 32, "2D DUNGEON");
	data.mov = 0;
	data.mov_skull = 0;
	data.sprite.player.dir = 'R';
	data.sprite.skull.dir = 'R';
	ft_game(&data);
	return (0);
}
