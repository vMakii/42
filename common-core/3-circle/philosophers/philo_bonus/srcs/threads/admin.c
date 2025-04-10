/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:06:23 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/10 15:03:00 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	death_check(t_philo *philo)
{
	sem_wait(philo->meal_sem);
	if (ft_get_time() - philo->last_meal >= philo->data->time_to_die)
	{
		ft_print("died", philo->id, philo, KRED);
		sem_post(philo->meal_sem);
		return (1);
	}
	sem_post(philo->meal_sem);
	return (0);
}

static int	meals_check(t_philo *philo)
{
	int	n;

	if (philo->data->num_meals == -1)
		return (0);
	sem_wait(philo->meal_sem);
	n = philo->num_meals;
	sem_post(philo->meal_sem);
	if (n < philo->data->num_meals)
		return (0);
	return (1);
}

void	*ft_admin(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		if (death_check(philo) == 1 || meals_check(philo) == 1)
		{
			sem_wait(philo->data->dead_sem);
			philo->data->dead = 1;
			sem_post(philo->data->dead_sem);
			break ;
		}
	}
	return (ptr);
}
