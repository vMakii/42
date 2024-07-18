/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:51:32 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/07 18:58:07 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
/*
#include <stdio.h>

int main(){
	int tab[] = {9,8,7,2,5,3,3,2,9,0};
	int size = 10;
	ft_sort_int_tab(tab, size);
	for (int i=0; i<size;i++){
		printf("%d", tab[i]);
	}
}*/
