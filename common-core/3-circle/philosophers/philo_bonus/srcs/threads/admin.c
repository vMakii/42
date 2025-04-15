/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:06:23 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/15 11:25:08 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	death_check(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		sem_wait(data->philos[i].meal_sem);
		if (ft_get_time() - data->philos[i].last_meal >= data->time_to_die)
		{
			ft_print("died", data->philos[i].id, &data->philos[i], KRED);
			sem_post(data->philos[i].meal_sem);
			return (1);
		}
		sem_post(data->philos[i].meal_sem);
	}
	return (0);
	// sem_wait(philo->meal_sem);
	// if (ft_get_time() - philo->last_meal >= philo->data->time_to_die)
	// {
	// 	ft_print("died", philo->id, philo, KRED);
	// 	sem_post(philo->meal_sem);
	// 	return (1);
	// }
	// sem_post(philo->meal_sem);
	// return (0);
}

static int	meals_check(t_data *data)
{
	int	i;
	int	n;

	i = -1;
	if (data->num_meals == -1)
		return (0);
	while (++i < data->num_philo)
	{
		sem_wait(data->philos[i].meal_sem);
		n = data->philos[i].num_meals;
		sem_post(data->philos[i].meal_sem);
		if (n < data->num_meals)
			return (0);
	}
	return (1);
	// sem_wait(philo->meal_sem);
	// n = philo->num_meals;
	// sem_post(philo->meal_sem);
	// if (n < philo->data->num_meals)
	// 	return (0);
	// return (1);
}

// void	*ft_admin(void *ptr)
// {
// 	int		i;
// 	t_philo	*philo;

// 	i = -1;
// 	philo = (t_philo *)ptr;
// 	while (1)
// 	{
// 		if (death_check(philo) == 1 || meals_check(philo) == 1)
// 		{
// 			sem_wait(philo->data->dead_sem);
// 			philo->data->dead = 1;
// 			sem_post(philo->data->dead_sem);
// 			while (++i < philo->data->num_philo)
// 			{
// 				if (philo->data->philos[i].pid != philo->pid)
// 					kill(philo->data->philos[i].pid, SIGKILL);
// 			}
// 			break ;
// 		}
// 	}
// 	return (ptr);
// }

void	*ft_admin(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	while (1)
	{
		if (death_check(data) == 1 || meals_check(data) == 1)
		{
			sem_wait(data->dead_sem);
			data->dead = 1;
			sem_post(data->dead_sem);
			return (ptr);
		}
	}
	return (ptr);
}
