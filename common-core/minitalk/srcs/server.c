/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:20:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/16 14:19:29 by mivogel          ###   ########.fr       */
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
		return (NULL);
	if (str)
		ft_strlcpy(new, str, len + 1);
	new[len++] = c;
	new[len] = '\0';
	free(str);
	return (new);
}

void	handler(int s)
{
	static int				bits;
	static unsigned char	c;
	static char				*str;

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
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
