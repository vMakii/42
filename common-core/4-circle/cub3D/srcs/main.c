/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:26:37 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/27 14:02:52 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		frame_count = 0;

void	init_mlx(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		exit_failure(data, "Error\nMLX couldn't be initiated\n");
	// mlx_get_screen_size(data->mlx.ptr, &data->mlx.width, &data->mlx.height);
	// printf("Screen size: %d x %d\n", data->mlx.width, data->mlx.height);
	// data->mlx.height -= 70; // height correction for fullscreen
	data->mlx.win = mlx_new_window(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT,
			"cub3d");
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask, &exit_success,
		data);
}

void	init_game(t_data *data)
{
	init_img(data);
}

float get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

void fps_counter(t_data *data)
{
	// FPS COUNTER
	frame_count++;
	if (frame_count == 120)
		frame_count = 0;
	float current_time = get_time();
	data->time.frameTime = current_time - data->time.oldTime;
	data->time.oldTime = current_time;
	data->time.time = current_time;
	data->time.FPS = (int)(1.0 / data->time.frameTime);
	if (data->time.FPS == 0)
		data->time.FPS = 1; // Prevent division by zero
	// printf("FPS: %d\n", data->time.FPS);
	// END FPS COUNTER
	// voir comment lock a 60 fps
}

int	loop(t_data *data)
{
	fps_counter(data);
	player_move(data);
	render_frame(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	parsing(argc, argv, &data);
	print_data_map(data);
	init_mlx(&data);
	init_game(&data);
	mlx_hook(data.mlx.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.mlx.win, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		&data);
	mlx_loop_hook(data.mlx.ptr, &loop, &data);
	mlx_loop(data.mlx.ptr);
	exit_success(&data);
	return (0);
}
