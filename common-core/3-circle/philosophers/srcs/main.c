/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:39:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/09 13:53:24 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
	{
		write(1, "Usage: ./philo <num_philo> <time_to_die> <time_to_eat>", 56);
		write(1, " <time_to_sleep> [num_meals]\n", 29);
		return (1);
	}
	if (!check_args(av))
		return (ft_error("Invalid arguments"), 1);
	memset(&data, 0, sizeof(t_data));
	ft_init(&data, ac, av);
	ft_init_philos(&data);
	ft_init_threads(&data);
	ft_free(&data);
	return (0);
}
