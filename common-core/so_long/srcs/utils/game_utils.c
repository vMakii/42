/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:59:58 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/12 23:00:32 by mivogel          ###   ########.fr       */
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

int	ft_wincond(t_data *data, int i, int j)
{
	if (data->map.tab[i][j] == 'E')
	{
		if (data->map.nbcoin == 0)
		{
			ft_printf("You win!\n");
			ft_close(data);
		}
		else
			return (1);
	}
	return (0);
}

int	ft_losecond(t_data *data, int i, int j)
{
	if (data->map.tab[i][j] == 'S')
	{
		ft_printf("You lose!\n");
		ft_close(data);
	}
	return (0);
}

void	ft_display_moves(t_data *data)
{
	char	*mov;

	mov = ft_itoa(data->mov);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 11, 14, 0x00FFFFFF, mov);
	free(mov);
}

void	ft_game(t_data *data)
{
	ft_img(data);
	ft_draw(data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &ft_close,
		data);
	mlx_key_hook(data->win_ptr, &ft_key, data);
	mlx_loop(data->mlx_ptr);
}
