/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:25:02 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/05 12:11:46 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	ft_init_map(char *av)
{
	int		fd;
	t_map	map;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(0);
	}
	map = ft_map(fd);
	return (map);
}

int	ft_close(t_data *data)
{
	ft_free_map(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	ft_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_close(data);
	return (0);
}

void	*ft_load_img(t_data *data, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->sprite.height,
			&data->sprite.width);
	if (!img)
	{
		ft_printf("Error: mlx_xpm_file_to_image failed\n");
		ft_close(data);
	}
	return (img);
}

void	ft_img_outerwalls(t_data *data)
{
	data->sprite.walls.wall_l1 = ft_load_img(data, WALL_L1);
	data->sprite.walls.wall_l2 = ft_load_img(data, WALL_L2);
	data->sprite.walls.wall_l3 = ft_load_img(data, WALL_L3);
	data->sprite.walls.wall_r1 = ft_load_img(data, WALL_R1);
	data->sprite.walls.wall_r2 = ft_load_img(data, WALL_R2);
	data->sprite.walls.wall_r3 = ft_load_img(data, WALL_R3);
	data->sprite.walls.wall_t = ft_load_img(data, WALL_T);
	data->sprite.walls.wall_b = ft_load_img(data, WALL_B);
}

void	ft_img(t_data *data)
{
	ft_img_outerwalls(data);
}

void	ft_draw_outerwalls(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.tab[++i])
	{
		j = -1;
		while (data->map.tab[i][++j])
		{
			if (i == 0 && j == 0)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.walls.wall_l1, j * 32, i * 32);
			else if (i == 0 && j == data->map.width - 1)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.walls.wall_r1, j * 32, i * 32);
			else if (i == data->map.height - 1 && j == 0)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.walls.wall_l3, j * 32, i * 32);
			else if (i == data->map.height - 1 && j == data->map.width - 1)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.walls.wall_r3, j * 32, i * 32);
			else if (i == 0)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.walls.wall_t, j * 32, i * 32);
			else if (i == data->map.height - 1)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.walls.wall_b, j * 32, i * 32);
			else if (j == 0)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.walls.wall_l2, j * 32, i * 32);
			else if (j == data->map.width - 1)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.walls.wall_r2, j * 32, i * 32);
		}
	}
}

void	ft_draw(t_data *data)
{
	ft_draw_outerwalls(data);
	// int	x;
	// int	y;
	// x = 0;
	// while (data->map.tab[x])
	// {
	// 	y = 0;
	// 	while (data->map.tab[x][y])
	// 	{
	// 		if (data->map.tab[x][y] == '1')
	// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
	// 				data->sprite.img_wall, y * 32, x * 32);
	// 		else
	// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
	// 				data->sprite.img_floor, y * 32, x * 32);
	// 		y++;
	// 	}
	// 	x++;
	// }
}

void	ft_game(t_data *data)
{
	ft_img(data);
	ft_printf("img\n");
	ft_draw(data);
	ft_printf("draw\n");
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &ft_close,
		data);
	ft_printf("hook\n");
	mlx_key_hook(data->win_ptr, ft_key, data);
	ft_printf("key_hook\n");
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_printf("Usage Error: [./so_long *.ber]\n"), 1);
	data.map = ft_init_map(av[1]);
	if (!ft_parsing(data.map))
	{
		ft_free_map(data.map);
		return (0);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (ft_printf("Error: mlx initialization failed\n"), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "gburtin");
	ft_game(&data);
	return (0);
}
