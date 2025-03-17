/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:49:58 by mivogel           #+#    #+#             */
/*   Updated: 2025/03/17 14:44:45 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// char	*ft_addchar(char *str, unsigned char c)
// {
// 	int		len;
// 	char	*new;

// 	len = 0;
// 	if (str)
// 		len = ft_strlen(str);
// 	new = malloc(sizeof(char) * (len + 2));
// 	if (!new)
// 		return (NULL);
// 	if (str)
// 	{
// 		ft_strlcpy(new, str, len + 1);
// 		free(str);
// 	}
// 	new[len] = c;
// 	new[len + 1] = '\0';
// 	return (new);
// }

void	handle_str(unsigned char c)
{
	static char		buffer[1000000000];
	static size_t	i = 0;

	if (c == '\0')
	{
		buffer[i] = '\0';
		ft_printf("%s\n", buffer);
		i = 0;
	}
	else
		buffer[i++] = c;
}

void	handler(int s, siginfo_t *info, void *content)
{
	static int				bits = 0;
	static unsigned char	c = 0;

	// static char				*str;
	(void)content;
	c = (c << 1) | (s == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		handle_str(c);
		// if (c == '\0')
		// {
		// 	if (str)
		// 		ft_printf("%s\n", str);
		// 	free(str);
		// 	str = NULL;
		// 	kill(info->si_pid, SIGUSR2);
		// }
		// else
		// 	str = ft_addchar(str, c);
		bits = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
