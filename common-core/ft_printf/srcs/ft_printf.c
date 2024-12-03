/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:34:04 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/03 15:09:29 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_args(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putvoid(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_args(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
//
// #include <stdio.h>
//
// int	main(void)
// {
// 	int	d;
//
// 	d = 42;
// 	printf("printf:\n");
// 	printf("char: %c\n", 'a');
// 	printf("str : %s\n", (char *)NULL);
// 	printf("ptr : %p\n", (void *)0);
// 	printf("nbr : %d\n", printf(0));
// 	printf("unb : %u\n", d);
// 	printf("hex : %x\n", d);
// 	printf("heX : %X\n", d);
// 	printf("per : %%\n\n");
// 	ft_printf("ft_printf:\n");
// 	ft_printf("char: %c\n", 'a');
// 	ft_printf("str : %s\n", NULL);
// 	ft_printf("ptr : %p\n", 0);
// 	ft_printf("nbr : %d\n", ft_printf(0));
// 	ft_printf("unb : %u\n", d);
// 	ft_printf("hex : %x\n", d);
// 	ft_printf("heX : %X\n", d);
// 	ft_printf("per : %%\n");
// }
