/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:25:39 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/05 13:15:08 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i++ < ac)
	{
		j = 0;
		while (++j < ac - 1)
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
			{
				tmp = av[j];
				av[j] = av[j + 1];
				av[j + 1] = tmp;
				j = 0;
			}
		}
	}
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
	}
	return (0);
}
