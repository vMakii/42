/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:45:59 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/11 16:38:00 by mivogel          ###   ########.fr       */
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

static void	ft_fill(char *str, long nb, int len)
{
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	nb = (long)n;
	len = ft_get_size(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	ft_fill(str, nb, len);
	return (str);
}
