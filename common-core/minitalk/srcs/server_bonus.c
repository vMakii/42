/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:49:58 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/07 11:46:01 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_addchar(char *str, unsigned char c)
{
	int		len;
	char	*new;

	len = 0;
	if (str)
		len = ft_strlen(str);
	new = malloc(sizeof(char) * len + 2);
	if (!new)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	if (str)
		ft_strlcpy(new, str, len + 1);
	new[len++] = c;
	new[len] = '\0';
	free(str);
	return (new);
}

void	handler(int s, siginfo_t *info, void *content)
{
	static int				bits;
	static unsigned char	c;
	static char				*str;

	(void)content;
	if (!str)
		str = NULL;
	c |= (s == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		else
			str = ft_addchar(str, c);
		bits = 0;
		c = 0;
	}
	else
		c <<= 1;
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
