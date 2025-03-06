/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:25:02 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/06 14:48:33 by mivogel          ###   ########.fr       */
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

void	ft_img_inner(t_data *data)
{
	data->sprite.walls.wall = ft_load_img(data, WALL);
	data->sprite.floor = ft_load_img(data, FLOOR);
	data->sprite.coin = ft_load_img(data, COIN);
	data->sprite.exit1 = ft_load_img(data, EXIT1);
	data->sprite.exit2 = ft_load_img(data, EXIT2);
	data->sprite.player1 = ft_load_img(data, PLAYER1);
	data->sprite.player2 = ft_load_img(data, PLAYER2);
}

void	ft_img(t_data *data)
{
	ft_img_outerwalls(data);
	ft_img_inner(data);
}

void	*get_wall_texture(t_data *data, int i, int j)
{
	if (i == 0 && j == 0)
		return (data->sprite.walls.wall_l1);
	else if (i == 0 && j == data->map.width - 1)
		return (data->sprite.walls.wall_r1);
	else if (i == data->map.height - 1 && j == 0)
		return (data->sprite.walls.wall_l3);
	else if (i == data->map.height - 1 && j == data->map.width - 1)
		return (data->sprite.walls.wall_r3);
	else if (i == 0)
		return (data->sprite.walls.wall_t);
	else if (i == data->map.height - 1)
		return (data->sprite.walls.wall_b);
	else if (j == 0)
		return (data->sprite.walls.wall_l2);
	else if (j == data->map.width - 1)
		return (data->sprite.walls.wall_r2);
	return (NULL);
}

void	ft_draw_outerwalls(t_data *data)
{
	int		i;
	int		j;
	void	*wall_img;

	i = -1;
	while (data->map.tab[++i])
	{
		j = -1;
		while (data->map.tab[i][++j])
		{
			wall_img = get_wall_texture(data, i, j);
			if (wall_img)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall_img,
					j * 32, i * 32);
		}
	}
}

void	ft_draw_inner(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[++i])
	{
		j = 0;
		while (data->map.tab[i][++j])
		{
			if (data->map.tab[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.walls.wall, j * 32, i * 32);
			else if (data->map.tab[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.floor, j * 32, i * 32);
			else if (data->map.tab[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.coin, j * 32, i * 32);
			else if (data->map.tab[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.exit1, j * 32, i * 32);
			else if (data->map.tab[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprite.player1, j * 32, i * 32);
		}
	}
}

void	ft_draw(t_data *data)
{
	ft_draw_outerwalls(data);
	ft_draw_inner(data);
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
