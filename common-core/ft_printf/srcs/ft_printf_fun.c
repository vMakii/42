/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:23:50 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/14 15:18:06 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_strlen(str);
	free(str);
	return (len);
}
