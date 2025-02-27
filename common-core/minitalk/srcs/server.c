/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:20:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/27 14:32:32 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*str;

char	*ft_addchar(char *str, unsigned char c)
{
	int		len;
	char	*new;

	len = 0;
	if (str)
		len = ft_strlen(str);
	new = malloc(sizeof(char) * (len + 2));
	if (!new)
		return (NULL);
	if (str)
	{
		ft_strlcpy(new, str, len + 1);
		free(str);
	}
	new[len] = c;
	new[len + 1] = '\0';
	return (new);
}

void	handler(int s)
{
	static int				bits;
	static unsigned char	c;

	c = (c << 1) | (s == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
		{
			if (str)
			{
				ft_printf("%s\n", str);
				free(str);
				str = NULL;
			}
		}
		else
			str = ft_addchar(str, c);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(100);
	return (0);
}
