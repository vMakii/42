/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:02:15 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/06 12:56:06 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
}
//
// #include <stdio.h>
//
// int main(){
// 	int n;
// 	n = ft_recursive_factorial(14);
// 	printf("%d", n);
// }
