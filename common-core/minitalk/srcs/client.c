/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:25:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/07 14:35:47 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *str)
{
	int				i;
	unsigned char	tmp;

	while (*str)
	{
		i = 8;
		tmp = *(str);
		while (i > 0)
		{
			i--;
			if (tmp >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Format: [./client <SERVER PID> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	else
		send_signal(ft_atoi(av[1]), av[2]);
	return (0);
}
