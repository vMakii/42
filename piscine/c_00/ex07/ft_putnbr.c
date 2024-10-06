/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:19:49 by mivogel           #+#    #+#             */
/*   Updated: 2024/06/28 14:08:48 by mivogel          ###   ########.fr       */
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
		ft_putnbr(-214748364);
		ft_putnbr(8);
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
