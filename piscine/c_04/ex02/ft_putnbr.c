/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:19:49 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/04 09:32:01 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			ft_putnbr(nb * (-1));
		}
		else
		{
			if (nb <= 9)
			{
				ft_putchar(nb + '0');
			}
			else
			{
				ft_putnbr(nb / 10);
				ft_putnbr(nb % 10);
			}
		}
	}
}
/*
int main(){
	int n = -2147483648;
	ft_putnbr(n);
	return 0;
}*/
