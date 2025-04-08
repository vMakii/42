/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:34:31 by mivogel           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/08 16:22:41 by mivogel          ###   ########.fr       */
=======
/*   Updated: 2025/04/04 17:14:10 by mivogel          ###   ########.fr       */
>>>>>>> 7d70a6cf5c1e7c46528eb915674a0bda043d275b
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

<<<<<<< HEAD
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
=======
void	eat(void)

	void *ft_routine(void *ptr)
>>>>>>> 7d70a6cf5c1e7c46528eb915674a0bda043d275b
{
	t_philo *philo;

	philo = (t_philo *)ptr;
<<<<<<< HEAD
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
=======
	if (philo->id % 2)
		ft_usleep(1);
	while (1)
	{
		eat(philo);
		dream(philo);
		think(philo);
>>>>>>> 7d70a6cf5c1e7c46528eb915674a0bda043d275b
	}
	return (ptr);
}