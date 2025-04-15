/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:06:23 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/15 14:38:52 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	death_check(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (ft_get_time() - data->philos[i].last_meal >= data->time_to_die)
		{
			ft_print("died", data->philos[i].id, &data->philos[i], KRED);
			pthread_mutex_unlock(&data->philos[i].meal_lock);
			return (1);
		}
		pthread_mutex_unlock(&data->philos[i].meal_lock);
	}
	return (0);
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
		pthread_mutex_lock(&data->philos[i].meal_lock);
		n = data->philos[i].num_meals;
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		if (n < data->num_meals)
			return (0);
	}
	return (1);
}

void	*ft_admin(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	while (1)
	{
		if (death_check(data) == 1 || meals_check(data) == 1)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			break ;
		}
		usleep(100);
	}
	return (ptr);
}
