/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:34:31 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/15 10:50:56 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	death_check(t_philo *philo)
{
	sem_wait(philo->data->dead_sem);
	if (philo->data->dead == 1)
	{
		sem_post(philo->data->dead_sem);
		return (0);
	}
	sem_post(philo->data->dead_sem);
	return (1);
}

void	ft_routine(t_philo *philo)
{
	pthread_t	admin;

	if (pthread_create(&admin, NULL, &ft_admin, philo))
		ft_error("Thread creation failed", philo->data);
	pthread_detach(admin);
	if (philo->id % 2 != 0)
	{
		ft_print("is thinking", philo->id, philo, KYEL);
		ft_usleep(1);
	}
	while (death_check(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->data->forks);
	ft_print("has taken a fork", philo->id, philo, KCYN);
	if (philo->data->num_philo == 1)
	{
		ft_usleep(philo->data->time_to_die);
		sem_post(philo->data->forks);
		return ;
	}
	sem_wait(philo->data->forks);
	ft_print("has taken a fork", philo->id, philo, KCYN);
	ft_print("is eating", philo->id, philo, KGRN);
	sem_wait(philo->meal_sem);
	philo->last_meal = ft_get_time();
	philo->num_meals++;
	sem_post(philo->meal_sem);
	ft_usleep(philo->data->time_to_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	ft_sleep(t_philo *philo)
{
	ft_print("is sleeping", philo->id, philo, KPUR);
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print("is thinking", philo->id, philo, KYEL);
}
