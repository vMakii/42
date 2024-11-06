/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:14:22 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/06 12:56:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (nb > 1)
	{
		res *= nb;
		nb--;
	}
	return (res);
}
// #include <stdio.h>
//
// int main(){
// 	int n;
// 	n = ft_iterative_factorial(13);
// 	printf("%d", n);
// }
