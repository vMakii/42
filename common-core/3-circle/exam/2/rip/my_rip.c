/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_rip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:54:38 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/08 11:39:57 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	find_n(char *s, int *n)
{
	int	i;
	int	open;
	int	close;

	i = 0;
	open = 0;
	close = 0;
	while (s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	*n = open + close;
}

int	isvalid(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '(')
			n++;
		if (str[i] == ')')
			n--;
		if (n < 0)
			return (0);
		i++;
	}
	return (n == 0);
}

void	rip(char *str, int i, int n, int lvl)
{
	char	tmp;

	if (isvalid(str) && n == lvl)
	{
		puts(str);
		return ;
	}
	while (str[i])
	{
		tmp = str[i];
		str[i] = ' ';
		lvl++;
		rip(str, i + 1, n, lvl);
		str[i] = tmp;
		lvl--;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (ac != 2)
		return (1);
	while (av[1][i])
	{
		if (av[1][i] != '(' && av[1][i] != ')')
			return (1);
		i++;
	}
	find_n(av[1], &n);
	if (n > 0)
		rip(av[1], 0, n, 0);
	return (0);
}
