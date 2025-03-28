/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:39:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/28 14:06:54 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ft_atoi(av[1]) > 200)
		return (0);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
		if (ft_atoi(av[i]) <= 0)
			return (0);
	}
	return (1);
}

void	ft_init(t_data *data, int ac, char **av)
{
	if (!check_args(av))
	{
		printf("Error: Invalid arguments\n");
		return ;
	}
	data->dead = 0;
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->num_meals = ft_atoi(av[5]);
	else
		data->num_meals = -1;
}

pthread_mutex_t	*ft_init_fork(void)
{
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t));
	if (!fork)
	{
		printf("Error: Malloc failed\n");
		return (NULL);
	}
	pthread_mutex_init(fork, NULL);
	return (fork);
}

void	ft_init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
	{
		printf("Error: Malloc failed\n");
		return ;
	}
	while (++i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		printf("Philosopher %d created\n", data->philos[i].id);
		data->philos[i].num_meals = 0;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 5 && ac != 6)
	{
		write(1, "Usage: ./philo <num_philo> <time_to_die> <time_to_eat>", 56);
		write(1, " <time_to_sleep> [num_meals]\n", 29);
		return (1);
	}
	ft_init(&data, ac, av);
	ft_init_philos(&data);
	ft_free(&data);
	return (0);
}
