/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:16:08 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/04 18:52:55 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->data->dead_lock);
	if (!philo->data->dead)
	{
		printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id
			+ 1, msg);
	}
	pthread_mutex_unlock(philo->data->dead_lock);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}
