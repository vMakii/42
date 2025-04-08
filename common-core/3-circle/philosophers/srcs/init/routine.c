/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:34:31 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/08 16:37:16 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	death_check(t_philo *philo)
{
	pthread_mutex_lock(philo->data->dead_lock);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(philo->data->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->data->dead_lock);
	return (1);
}

void	*ft_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
	{
		ft_print("is thinking", philo->id, philo, KYEL);
		ft_usleep(10);
	}
	while (1)
	{
		if (death_check(philo) == 1)
			ft_eat(philo);
		else
			break ;
		if (death_check(philo) == 1)
			ft_think(philo);
		else
			break ;
	}
	return (ptr);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print("has taken a fork", philo->id, philo, KCYN);
	// if (philo->data->num_philo == 1)
	// {
	// 	pthread_mutex_unlock(philo->left_fork);
	// 	return ;
	// }
	pthread_mutex_lock(philo->right_fork);
	ft_print("has taken a fork", philo->id, philo, KCYN);
	ft_print("is eating", philo->id, philo, KBLU);
	philo->last_meal = ft_get_time();
	pthread_mutex_lock(philo->data->dead_lock);
	philo->num_meals++;
	pthread_mutex_unlock(philo->data->dead_lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (death_check(philo) == 1)
		ft_sleep(philo);
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