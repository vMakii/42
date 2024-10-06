/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:43:23 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/14 12:48:01 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_ultimate_strlen(int size, char **strs, char *sep)
{
	int	i;
	int	len_total;

	i = 0;
	len_total = 0;
	while (i < size)
	{
		len_total += ft_strlen(strs[i]);
		if (i < size - 1)
			len_total += ft_strlen(sep);
		i++;
	}
	return (len_total);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*tab;

	i = 0;
	len = ft_ultimate_strlen(size, strs, sep);
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	*tab = 0;
	while (i < size)
	{
		ft_strcat(tab, strs[i]);
		if (i < size - 1)
			ft_strcat(tab, sep);
		i++;
	}
	return (tab);
}
/*
#include <stdio.h>
int	main(){
	int n = 4;
	char *a[] = {"1", "2551", "3", "4"};
	char *sep = "grrpaw";
	printf("%s", ft_strjoin(n, a, sep));
}*/
