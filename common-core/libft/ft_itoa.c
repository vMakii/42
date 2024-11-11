/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:45:59 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/11 11:20:46 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_fill(int size, int sign, int n, char *str)
{
	while (size > sign)
	{
		str[size - 1] = n % 10 - '0';
		n /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*str;
	long	nb;

	size = ft_get_size(n);
	sign = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nb = -n;
		sign++;
		str[0] = '-';
	}
	else
		nb = n;
	str[size + 1] = '\0';
	ft_fill(size, sign, n, str);
	return (str);
}

#include <stdio.h>

int	main(void)
{
	int		n;
	char	*s;

	n = 2;
	s = ft_itoa(n);
	printf("%s", s);
}
