/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:04:36 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/17 12:14:37 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *str)
{
	int				i;
	int				len;
	unsigned char	tmp;

	len = ft_strlen(str) + 1;
	while (len)
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
		len--;
	}
}

void	handler(int s)
{
	static int	msg = 0;

	if (!msg)
	{
		if (s == SIGUSR1)
		{
			msg = 1;
		}
	}
}

int	ft_verifpid(char *str)
{
	int	i;

	i = ft_atoi(str);
	if (i < 0 || i > 4194304)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_printf("Usage: [./client <SERVER PID> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (!ft_verifpid(av[1]))
		{
			ft_printf("Invalid PID\n");
			exit(EXIT_FAILURE);
		}
		sa.sa_handler = handler;
		sa.sa_flags = SA_RESTART;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_signal(ft_atoi(av[1]), av[2]);
	}
	return (EXIT_SUCCESS);
}
