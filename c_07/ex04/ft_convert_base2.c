/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:26:30 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/14 14:37:47 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_check_base(char *base);
int	ft_check_i(char str, char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_strlen_b(int nb, char *base)
{
	unsigned int	count;
	unsigned int	n;

	count = 0;
	if (nb < 0)
	{
		n = -nb;
		count++;
	}
	else
		n = nb;
	while (n > 0)
	{
		count++;
		n /= ft_strlen(base);
	}
	return (count);
}

char	*ft_itoa(int nb, char *base)
{
	char	*str;
	int		sign;
	int		i;
	long	n;

	sign = 0;
	i = ft_strlen_b(nb, base);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	if (nb < 0)
	{
		n = -nb;
		sign++;
		str[0] = '-';
	}
	else
		n = nb;
	str[i] = '\0';
	while (i-- > sign)
	{
		str[i] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*s;

	if (ft_check_base(base_from) == 0)
		return (0);
	n = ft_atoi_base(nbr, base_from);
	if (ft_check_base(base_to) == 0)
		return (0);
	s = ft_itoa(n, base_to);
	return (s);
}
/*
#include <stdio.h>
int main(void)
{
	char *s = ft_convert_base("   \t -42", "0123456789", "01");
	printf("%s", s);
}*/
