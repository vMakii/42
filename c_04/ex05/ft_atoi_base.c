/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:19:22 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/08 19:35:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = ft_strlen(base);
	if (i <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_i(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != str)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (ft_check_base(base) == 1)
	{
		while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			i++;
		while (str[i] && (str[i] == '-' || str[i] == '+'))
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (str[i] && ft_check_i(str[i], base) < ft_strlen(base))
		{
			res = (res * ft_strlen(base)) + (ft_check_i(str[i], base));
			i++;
		}
	}
	return (sign * res);
}
/*
#include <stdio.h>

int main(){
	char str[] = "   ---+--+vn";
	char hexa[] = "poneyvif";
	int r = ft_atoi_base(str, hexa);
	printf("%d", r);
}*/
