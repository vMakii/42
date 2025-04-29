/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:54:17 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/29 10:54:27 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(char **av)
{
	int		i;
	long	n;

	i = 1;
	while (av[i])
	{
		if (!ft_isnum(av[i]))
			return (0);
		n = ft_atol(av[i]);
		if (n < 0 || (i == 1 && n > 200) || (i > 1 && i < 4 && n < 60))
			return (0);
		if (n < INT_MIN || n > INT_MAX || ft_strlen(av[i]) > 10)
			return (0);
		i++;
	}
	return (1);
}

int	ft_init(t_data *data, int ac, char **av)
{
	data->start_time = ft_get_time();
	data->dead = 0;
	if (pthread_mutex_init(&data->dead_lock, NULL))
		return (ft_error("Mutex init failed"), 1);
	if (pthread_mutex_init(&data->print_lock, NULL))
		return (ft_error("Mutex init failed"), 1);
	data->num_philo = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->num_meals = ft_atol(av[5]);
	else
		data->num_meals = -1;
	return (0);
}

int	ft_init_forks(pthread_mutex_t *forks, int num_philo)
{
	int	i;

	i = -1;
	while (++i < num_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			return (ft_error("Mutex init failed"), 1);
	}
	return (0);
}

int	ft_init_philos(t_data *data)
{
	pthread_mutex_t	*forks;
	int				i;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos || !forks)
		return (ft_error("Malloc failed"), 1);
	if (ft_init_forks(forks, data->num_philo))
		return (1);
	while (++i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].num_meals = 0;
		data->philos[i].last_meal = data->start_time;
		if (pthread_mutex_init(&data->philos[i].meal_lock, NULL))
			return (ft_error("Mutex init failed"), 1);
		data->philos[i].left_fork = &forks[i];
		data->philos[i].right_fork = &forks[(i + 1) % data->num_philo];
		data->philos[i].data = data;
	}
	data->forks = forks;
	return (0);
}

int	ft_init_threads(t_data *data)
{
	pthread_t	admin;
	int			i;

	if (pthread_create(&admin, NULL, &ft_admin, data))
		return (ft_error("Thread creation failed"), 1);
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &ft_routine,
				&data->philos[i]))
			return (ft_error("Thread creation failed"), 1);
	}
	if (pthread_join(admin, NULL))
		return (ft_error("Thread join failed"), 1);
	i = -1;
	while (++i < data->num_philo)
		if (pthread_join(data->philos[i].thread, NULL))
			return (ft_error("Thread join failed"), 1);
	return (0);
}
