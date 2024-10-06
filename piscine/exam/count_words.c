/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:24:49 by mivogel           #+#    #+#             */
/*   Updated: 2024/10/03 18:39:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_word(char str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z') || (str >= '0'
			&& str <= '9'))
		return (1);
	return (0);
}

int	count_word(char *str)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (is_word(str[i]))
		{
			cpt++;
			while (is_word(str[i]))
				i++;
		}
		else
			i++;
	}
	return (cpt);
}

int	main(int ac, char *av[])
{
	(void)ac;
	printf("%d", count_word(av[1]));
}
