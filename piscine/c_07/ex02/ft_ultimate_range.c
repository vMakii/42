/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:09:14 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/12 11:35:03 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (-1);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (i);
}
/*
#include <stdio.h>
int main(){
	int min = 8;
	int max = 5;
	int *tab;
	int n = ft_ultimate_range(&tab, min, max);
	int i = 0;
	while (i < max -min)
	{
		printf("%d, ", tab[i]);
		i++;
	}
	printf("\n%d", n);
	return 0;
}*/
