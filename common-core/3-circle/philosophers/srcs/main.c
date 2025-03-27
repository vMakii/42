/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:39:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/27 19:21:36 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_philos_init(t_data *data, int ac, char **av)
{
	data->num_philo = atoi(av[1]);
	data->time_to_die = atoi(av[2]);
	data->time_to_eat = atoi(av[3]);
	data->time_to_sleep = atoi(av[4]);
	if (ac == 6)
		data->num_meals = atoi(av[5]);
	else
		data->num_meals = -1;
}

int	main(int ac, char **av)
{
	t_data data;

	(void)av;
	if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philo <num_philo> <time_to_die> <time_to_eat> <time_to_sleep> [num_meals]\n");
		return (1);
	}
	ft_philos_init(&data, ac, av);
	return (0);
}