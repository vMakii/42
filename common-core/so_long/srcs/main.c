/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:25:02 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/21 11:11:16 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5 || file[i - 1] != 'r' || file[i - 2] != 'e' || file[i - 3] != 'b'
		|| file[i - 4] != '.' || (file[i - 5] == '/' && file[i - 4] == '.'))
	{
		ft_printf("Error\nWrong file extension\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_printf("Error\n[./so_long *.ber]\n"), 1);
	ft_check_file(av[1]);
	ft_memset(&data, 0, sizeof(t_data));
	data.map = ft_init_map(av[1]);
	if (!ft_parsing(data.map))
	{
		ft_free_map(data.map);
		return (0);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (ft_printf("Error\nmlx initialization failed\n"), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width * 32,
			data.map.height * 32, "2D DUNGEON");
	data.mov = 0;
	data.mov_skull = 0;
	data.sprite.player.dir = 'R';
	data.sprite.skull.dir = 'R';
	ft_game(&data);
	return (0);
}
