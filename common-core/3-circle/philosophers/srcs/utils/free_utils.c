/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:37:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/28 14:59:59 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_data *data)
{
	// int i;

	// i = -1;
	// while (++i < data->num_philo)
	// {
	// 	pthread_mutex_destroy(data->philos[i].left_fork);
	// 	pthread_mutex_destroy(data->philos[i].right_fork);
	// 	free(data->philos[i].left_fork);
	// 	free(data->philos[i].right_fork);
	// }
	// pthread_mutex_destroy(data->dead_lock);
	free(data->dead_lock);
	free(data->philos);
}