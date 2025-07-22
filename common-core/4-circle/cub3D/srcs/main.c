/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:07:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/22 11:02:02 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_game(t_data *data, char *map_file)
{
	(void)data;
	ft_putstr_fd("Starting game loop with map: ", STDOUT_FILENO);
	ft_putstr_fd(map_file, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	// Game loop logic would go here
	// For now, we will just simulate a game loop with a print statement.
	ft_putstr_fd("Game loop running...\n", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_file>\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!ft_parsing(&data, av[1]))
		return (EXIT_FAILURE);
	ft_game(&data, av[1]);
	// ft_free();
	return (EXIT_SUCCESS);
}
