/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:34:27 by mivogel           #+#    #+#             */
/*   Updated: 2024/08/02 12:48:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * length);
	if (!res)
		return (0);
	while (i < length)
	{
		res[i] = (*f)(tab[i]);
		i++;
	}
	return (res);
}

// #include <unistd.h>
//
// int	plus_one(int i)
// {
// 	return (i + 1);
// }
//
// void	print_tab(int *ptr, int size)
// {
// 	int		i;
// 	char c;
//
// 	i = 0;
// 	while (i < size)
// 	{
// 		c = ptr[i] + '0';
// 		write(1, &c, 1);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }
//
// int	main(void)
// {
// 	int	tab[5];
//
// 	tab[0] = 1;
// 	tab[1] = 2;
// 	tab[2] = 3;
// 	tab[3] = 4;
// 	tab[4] = 5;
// 	print_tab(tab, 5);
// 	write(1, "\n", 1);
// 	int	*ptr = ft_map(tab, 5, &plus_one);
// 	print_tab(ptr, 5);
// }
