/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:57:02 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/18 10:37:31 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_addr(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_addr(n / 16);
	if (n > 9)
		len += ft_putchar(n + '0');
	else
		len += ft_putchar(n - 10 + '0');
	return (len);
}

int	ft_putvoid(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_print_addr((unsigned long)ptr);
	return (len);
}
