/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:37:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/10 15:04:02 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(char *str, t_data *data)
{
	printf("Error: %s\n", str);
	ft_free(data);
	exit(0);
}

void	ft_free(t_data *data)
{
	int	i;

	if (data->dead_sem)
		sem_close(data->dead_sem);
	if (data->print_sem)
		sem_close(data->print_sem);
	if (data->forks)
		sem_close(data->forks);
	if (data->philos)
	{
		i = -1;
		while (++i < data->num_philo)
		{
			sem_close(data->philos[i].meal_sem);
			kill(data->philos[i].pid, SIGKILL);
		}
		free(data->philos);
	}
}
