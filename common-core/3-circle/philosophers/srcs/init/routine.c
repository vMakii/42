/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:34:31 by mivogel           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/08 16:37:16 by mivogel          ###   ########.fr       */
=======
/*   Updated: 2025/04/02 14:30:00 by mivogel          ###   ########.fr       */
>>>>>>> parent of 86718c3 (philo)
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2)
		ft_usleep(1);
	return (ptr);
}