/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:34:31 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/15 14:37:44 by mivogel          ###   ########.fr       */
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
	if (philo->id % 2 != 0)
	{
		ft_think(philo);
		ft_usleep(10);
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
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	ft_get_forks_in_order(philo->left_fork, philo->right_fork, &first, &second);
	pthread_mutex_lock(first);
	ft_print("has taken a fork", philo->id, philo, KCYN);
	if (philo->data->num_philo == 1)
	{
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(first);
		return ;
	}
	pthread_mutex_lock(second);
	ft_print("has taken a fork", philo->id, philo, KCYN);
	ft_print("is eating", philo->id, philo, KGRN);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = ft_get_time();
	philo->num_meals++;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
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
