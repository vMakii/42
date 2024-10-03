/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:46:53 by mivogel           #+#    #+#             */
/*   Updated: 2024/10/03 18:00:50 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	char	r;

	if (n < 10)
	{
		r = n + '0';
		write(1, &r, 1);
	}
	else
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
		{
			if (i % 5 == 0)
			{
				write(1, "fizzbuzz", 8);
				write(1, "\n", 1);
			}
			else
			{
				write(1, "fizz", 4);
				write(1, "\n", 1);
			}
		}
		else if (i % 5 == 0)
		{
			write(1, "buzz", 4);
			write(1, "\n", 1);
		}
		else
		{
			putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
