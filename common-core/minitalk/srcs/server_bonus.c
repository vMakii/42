/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:49:58 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/08 14:21:37 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int s, siginfo_t *info, void *content)
{
	static int				bits;
	static unsigned char	c;

	(void)content;
	c |= (s == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
		}
		ft_printf("%c", c);
		bits = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
	{
		c <<= 1;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
