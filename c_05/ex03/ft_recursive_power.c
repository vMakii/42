/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:30:59 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/07 17:13:01 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (res * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>
int main(){
	int n;
	n = ft_recursive_power(2,-2);
	printf("%d", n);
}*/
