/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:24:26 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/03 12:37:08 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (i = ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = ft_strlen(src);
	return (i);
}
/*
#include <stdio.h>

int main()
{
	char c[] = "Hello there";
	char buffer[sizeof(c)];
	int r;

	r = ft_strlcpy(buffer, c, 2);
	printf("%s, taille : %d\n", buffer, r);
}*/
