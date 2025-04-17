/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:34:31 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/18 00:11:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (1);
}

void	*ft_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (!(philo->id % 2))
	{
		usleep(50);
	}
	while (death_check(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (ptr);
}

void	ft_eat(t_philo *philo)
{
	if (philo->data->num_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print("has taken a fork", philo->id, philo, KCYN);
		ft_usleep(philo->data->time_to_die + 1);
		pthread_mutex_unlock(philo->left_fork);
	}
	else if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print("has taken a fork", philo->id, philo, KCYN);
		pthread_mutex_lock(philo->right_fork);
		ft_print("has taken a fork", philo->id, philo, KCYN);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print("has taken a fork", philo->id, philo, KCYN);
		pthread_mutex_lock(philo->left_fork);
		ft_print("has taken a fork", philo->id, philo, KCYN);
	}
	pthread_mutex_lock(&philo->meal_lock);
	ft_print("is eating", philo->id, philo, KGRN);
	philo->last_meal = ft_get_time();
	philo->num_meals++;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
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
