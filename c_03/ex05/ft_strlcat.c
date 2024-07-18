/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:35:32 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/04 19:13:00 by mivogel          ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_dest;
	unsigned int	lsrc;

	len_dest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	if (size <= len_dest)
		return (size + lsrc);
	i = 0;
	while (i + len_dest + 1 < size && src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	len_dest = ft_strlen(dest);
	return (len_dest);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char c1[255] = "Bonjour";
	char c2[] = " je suis un test";
	int r = ft_strlcat(c1, c2, 2);
	printf("%s, taille : %d", c1, r);
}*/
