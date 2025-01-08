/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:04:36 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/08 12:32:45 by mivogel          ###   ########.fr       */
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

void	handler(int s)
{
	static int	msg = 0;

	if (!msg)
	{
		if (s == SIGUSR1)
		{
			ft_printf("OK !\n");
			msg = 1;
		}
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_printf("Format: [./client <SERVER PID> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		sa.sa_handler = handler;
		sa.sa_flags = SA_RESTART;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_signal(ft_atoi(av[1]), av[2]);
	}
	return (EXIT_SUCCESS);
}
