/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:34:04 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/14 11:28:28 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	size_t	i;
	va_list	args;

	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i++] == '%')
			len += 1;
		else
			len += ft_putchar(format[i]) // a modif
				i++;
	}
	return (len);
}
