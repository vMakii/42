/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:39:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/08 16:05:00 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_args(char **av)
{
	int		i;
	long	n;

	i = 1;
	while (av[i])
	{
		if (!ft_isnum(av[i]))
			return (0);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX || ft_strlen(av[i]) > 10)
			return (0);
		i++;
	}
	return (1);
}

void	ft_init(t_data *data, int ac, char **av)
{
	data->start_time = ft_get_time();
	data->dead = 0;
	data->dead_lock = malloc(sizeof(pthread_mutex_t));
	data->print_lock = malloc(sizeof(pthread_mutex_t));
	if (!data->dead_lock || !data->print_lock)
		return (ft_error("Malloc failed"));
	pthread_mutex_init(data->dead_lock, NULL);
	pthread_mutex_init(data->print_lock, NULL);
	data->num_philo = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->num_meals = ft_atol(av[5]);
	else
		data->num_meals = -1;
}

void	ft_init_forks(pthread_mutex_t *forks, int num_philo)
{
	int	i;

	i = -1;
	while (++i < num_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			return (ft_error("Mutex init failed"));
	}
}

void	ft_init_philos(t_data *data)
{
	pthread_mutex_t	*forks;
	int				i;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos || !forks)
		return (ft_error("Malloc failed"));
	ft_init_forks(forks, data->num_philo);
	while (++i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		printf("Philosopher %d created\n", data->philos[i].id);
		data->philos[i].num_meals = 0;
		data->philos[i].last_meal = data->start_time;
		if (i == 0)
			data->philos[i].left_fork = &forks[data->num_philo - 1];
		else
			data->philos[i].left_fork = &forks[i - 1];
		data->philos[i].right_fork = &forks[i];
		data->philos[i].data = data;
	}
	data->forks = forks;
}

void	ft_init_threads(t_data *data)
{
	pthread_t	admin;
	int			i;

	if (pthread_create(&admin, NULL, &ft_admin, data))
		return (ft_error("Thread creation failed"));
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &ft_routine,
				&data->philos[i]))
			return (ft_error("Thread creation failed"));
	}
	if (pthread_join(admin, NULL))
		return (ft_error("Thread join failed"));
	i = -1;
	while (++i < data->num_philo)
		if (pthread_join(data->philos[i].thread, NULL))
			return (ft_error("Thread join failed"));
}

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
