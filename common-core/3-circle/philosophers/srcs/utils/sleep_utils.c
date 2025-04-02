/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:14:55 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/02 14:30:32 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 0)
		return (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (0);
}

void	ft_usleep(size_t time)
{
	size_t start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(100);
	return ;
}