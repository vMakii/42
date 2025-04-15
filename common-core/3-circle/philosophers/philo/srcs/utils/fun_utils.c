/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:16:08 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/15 14:31:27 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print(char *str, int id, t_philo *philo, char *color)
{
	int	time;

	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead == 0)
	{
		time = ft_get_time() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->print_lock);
		printf("%s%d	%d %s%s\n", color, time, id, str, KEND);
		pthread_mutex_unlock(&philo->data->print_lock);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
}

void	ft_get_forks_in_order(pthread_mutex_t *left_fork,
		pthread_mutex_t *right_fork, pthread_mutex_t **first,
		pthread_mutex_t **second)
{
	if (left_fork < right_fork)
	{
		*first = left_fork;
		*second = right_fork;
	}
	else
	{
		*first = right_fork;
		*second = left_fork;
	}
}
