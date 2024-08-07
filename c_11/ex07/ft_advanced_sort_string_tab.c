/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:33:59 by mivogel           #+#    #+#             */
/*   Updated: 2024/08/07 14:38:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	i = 0;
	size = ft_strlen(tab);
	while (i < size)
	{
		j = 1;
		while (j < size - 1)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				j = 0;
			}
			j++;
		}
		i++;
	}
}

// #include <stdio.h>
//
// int	main(int argc, char *argv[])
// {
// 	int	i;
// 	ft_advanced_sort_string_tab(argv, ft_strcmp);
// 	i = 0;
// 	while (++i < argc)
// 		printf("%s\n", argv[i]);
// }
