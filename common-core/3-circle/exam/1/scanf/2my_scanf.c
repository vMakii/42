// Assignment name  : ft_scanf
// Expected files   : ft_scanf.c
// Allowed functions: fgetc, ungetc, ferror, feof, isspace, isdigit, stdin, va_start, va_arg, va_copy, va_end
// --------------------------------------------------------------------------------

// Write a function named `ft_scanf` that will mimic the real scanf with the following constraints:

// - It will manage only the following conversions: s, d, and c
// - You don't have to handle the options *, m and '
// - You don't have to handle the maximum field width
// - You don't have to handle the types modifier characters (h, hh, l, etc.)
// - You don't have to handle the conversions beginning with %n$

// Your function must be declared as follows:

// int ft_scanf(const char *, ... );

// You will find in this directory a file containing a part of the code you will need, you just have to complete it.

// To test your program compare your results with the real scanf.

// Hint : You may need to read the man of scanf.

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

int	handle_d(FILE *file, va_list ap)
{
	int *buffer = va_arg(ap, int *);
	int c = fgetc(file);
	int res = 0;
	int sign = 1;
	int count = 0;

	if (c == EOF && ferror(file))
		return (0);
	
	while (c != EOF && isspace(c))
		c = fgetc(file);
	
	if (c == '-')
	{
		sign = -1;
		c = fgetc(file);
	}
	else if (c == '+')
		c = fgetc(file);
	
	if (!isdigit(c))
	{
		if (c != EOF)
			ungetc(c, file);
		return (0);
	}
	
	while (isdigit(c))
	{
		res = res * 10 + (c - '0');
		count++;
		c = fgetc(file);
	}
	
	if (c != EOF)
		ungetc(c, file);
	
	if (ferror(file))
		return (0);
	
	if (count == 0)
		return (0);
		
	*buffer = res * sign;
	return (1);
}

int	handle_s(FILE *file, va_list ap)
{
	char *buffer = va_arg(ap, char*);
	char c = fgetc(file);
	int i = 0;

	if (c == EOF && ferror(file))
		return (0);

	while (c != EOF && isspace(c))
		c = fgetc(file);
	
	if (c == EOF)
		return (0);
	
	while (c != EOF && !isspace(c))
	{
		buffer[i] = c;
		i++;
		c = fgetc(file);
	}
	
	buffer[i] = '\0';
	
	if (c != EOF)
		ungetc(c, file);
	
	if (ferror(file))
		return (0);
		
	if (i == 0)
		return (0);
		
	return (1);
}

int	handle_c(FILE *file, va_list ap)
{
	char *buffer = va_arg(ap, char*);
	char c = fgetc(file);

	if (c == EOF)
		return (0);
	
	if (ferror(file))
		return (0);
		
	*buffer = c;
	return (1);
}

int	verif_input(FILE *file, const char *format, va_list ap)
{
	int i = 0;
	int compteur = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++; // Passer le '%'
			if (format[i] == 'c')
			{
				if (handle_c(file, ap) == 0)
					break;
				compteur++;
			}
			else if (format[i] == 's')
			{
				if (handle_s(file, ap) == 0)
					break;
				compteur++;
			}
			else if (format[i] == 'd')
			{
				if (handle_d(file, ap) == 0)
					break;
				compteur++;
			}
			i++; // Passer le caractère de conversion
		}
		else if (isspace(format[i]))
		{
			// Ignorer les espaces dans le format en lisant tous les espaces de l'entrée
			int c = fgetc(file);
			while (c != EOF && isspace(c))
				c = fgetc(file);
			if (c != EOF)
				ungetc(c, file);
			i++;
		}
		else
		{
			int c = fgetc(file);
			if (c != format[i])
			{
				if (c != EOF)
					ungetc(c, file);
				break;
			}
			i++;
		}
	}
	if (ferror(file))
		return (EOF);
	return (compteur);
}

int	ft_scanf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int x = verif_input(stdin, format, ap);
	va_end(ap);
	return (x);
}