/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/10 14:59:49 by mivogel          ###   ########.fr       */
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

void	ft_init(t_data *data, int ac, char **av)
{
	data->start_time = ft_get_time();
	data->dead = 0;
	data->dead_sem = NULL;
	data->print_sem = NULL;
	data->forks = NULL;
	data->num_philo = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->num_meals = ft_atol(av[5]);
	else
		data->num_meals = -1;
}

void	ft_init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (ft_error("Malloc failed", data));
	while (++i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].num_meals = 0;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].meal_sem = NULL;
		data->philos[i].data = data;
	}
}

void	ft_init_semaphores(t_data *data)
{
	int	i;

	i = -1;
	sem_unlink("dead");
	sem_unlink("print");
	sem_unlink("forks");
	sem_unlink("meal");
	data->dead_sem = sem_open("dead", O_CREAT, 0600, 1);
	if (data->dead_sem == SEM_FAILED)
		ft_error("Semaphore creation failed", data);
	data->print_sem = sem_open("print", O_CREAT, 0600, 1);
	if (data->print_sem == SEM_FAILED)
		ft_error("Semaphore creation failed", data);
	data->forks = sem_open("forks", O_CREAT, 0600, data->num_philo);
	if (data->forks == SEM_FAILED)
		ft_error("Semaphore creation failed", data);
	while (++i < data->num_philo)
	{
		data->philos[i].meal_sem = sem_open("meal", O_CREAT, 0600, 1);
		if (data->philos[i].meal_sem == SEM_FAILED)
			ft_error("Semaphore creation failed", data);
	}
}

void	ft_start_processes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid < 0)
			ft_error("Fork failed", data);
		if (data->philos[i].pid == 0)
		{
			ft_routine(&data->philos[i]);
			exit(0);
		}
	}
	i = -1;
	while (++i < data->num_philo)
		waitpid(data->philos[i].pid, NULL, 0);
}
