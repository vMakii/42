/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:35:42 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/10 12:06:35 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (ft_is_prime(nb) == 1)
		return (i);
	while (ft_is_prime(i) != 1)
		i++;
	return (i);
}
/*
#include <stdio.h>
int main(){
	int n;
	n = ft_find_next_prime(2147483630);
	printf("%d", n);
}*/
