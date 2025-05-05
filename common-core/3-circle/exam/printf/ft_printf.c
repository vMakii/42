#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 1));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	len;

	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10);
	len += ft_putchar(nbr % 10 + '0');
	return (len);
}

int	ft_puthex(unsigned int nbr)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		len += ft_putnbr(nbr / 16);
	len += ft_putchar(base[nbr % 16]);
	return (len);
}

int	ft_handle_format(const char format, va_list args)
{
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
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
			len += ft_handle_format(format[i + 1], args);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	char *str = "bonjour";
// 	int nbr = 42;
// 	ft_printf("test : %s\n", str);
// 	ft_printf("test : %d\n", nbr);
// 	ft_printf("test : %x\n", nbr);
// }